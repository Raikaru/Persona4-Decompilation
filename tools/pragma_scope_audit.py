#!/usr/bin/env python3
"""Report which pragma scope each function is actually compiled under.

A `#pragma` in MWCCPS2 runs to the matching `off`/reset, not to the end of the
function that needed it. So a pragma opened for one function and closed several
functions later silently changes the compiler for everything in between - and an
unmatched function in that span is being measured against the wrong compiler.
That is not a theoretical risk: `#pragma optimization_level 3` in code1_0039.c
covers 89 lines and five unmatched functions, all of which were being probed at
-O3. Scoping -O2 back over one of them moved it from nd 38 to nd 17 with no
source change at all.

Nothing else in the gate can see this. decomp_lint checks that each pragma is
justified and balanced within its file; pragma_audit checks that the spelling is
one b210 recognises. Neither asks which functions a scope reaches.

Comment stripping is delegated to decomp_lint.Source, because floor notes in
this tree quote pragmas at the start of a line inside `/* ... */` and a naive
line regex reads those as real directives.

Usage:
  python tools/pragma_scope_audit.py build/verify.json
  python tools/pragma_scope_audit.py build/verify.json --all   # matched too
"""
import importlib.util
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, 'tools')
import verify

_SPEC = importlib.util.spec_from_file_location(
    'p4_decomp_lint', Path(__file__).resolve().parent / 'decomp_lint.py')
lint = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(lint)

MARK = re.compile(r'^\s*//\s*FUN_([0-9A-Fa-f]{8})\b')
PRAGMA = re.compile(r'^\s*#pragma\s+(\w+)\s+(\w+)')

# The compiler state the build sets up before any file-local pragma. A function
# under exactly these values is being compiled the way the campaign assumes.
DEFAULTS = {
    'optimization_level': '2',
    'schedule': 'off',
    'no_branch_likely': 'off',
    'opt_loop_invariants': 'off',
    'opt_common_subs': 'on',
    'opt_propagation': 'on',
    'opt_dead_code': 'on',
    'opt_strength_reduction': 'on',
    'peephole': 'on',
}


def scopes_for(src):
    """Map each marker's function address to the non-default pragma state.

    Pragmas are read from the comment-stripped text so a floor note quoting
    `#pragma ...` inside `/* ... */` is not mistaken for a directive - but the
    MARKERS themselves are comments, so they have to be read from the raw
    lines. Reading both from src.code finds zero markers and reports a clean
    tree, which is exactly the wrong answer.

    Pragmas inside `#ifdef NON_MATCHING` are preprocessed out of the real build
    and cannot leak, so they are skipped. Counting them inflates the report
    badly: most of the brackets around preserved bodies live there.
    """
    skip = non_matching(src)
    state = dict(DEFAULTS)
    out = {}
    for i, stripped in enumerate(src.code):
        m = PRAGMA.match(stripped)
        if m and m.group(1) in state:
            if i not in skip:
                state[m.group(1)] = m.group(2)
            continue
        m = MARK.match(src.lines[i])
        if m:
            active = {k: v for k, v in state.items() if v != DEFAULTS[k]}
            out[m.group(1).lower()] = (i + 1, active)
    return out


def non_matching(src):
    """Line indices the preprocessor drops: the `#ifdef NON_MATCHING` arm.

    decomp_lint has its own version for a different purpose; this one only
    needs the reference arm, from the `#ifdef` through the `#else`.
    """
    skip = set()
    depth = 0
    for i, line in enumerate(src.lines):
        s = line.strip()
        if s.startswith('#ifdef NON_MATCHING'):
            depth += 1
        if depth:
            skip.add(i)
        if s == '#else' and depth:
            depth -= 1
    return skip


def split_pairs(src):
    """Pragmas whose open and close land on opposite sides of a NON_MATCHING arm.

    `#pragma schedule off` inside the reference arm with the matching `on` after
    the `#endif` is balanced in the TEXT, so decomp_lint's P001 sees nothing -
    but the build only ever reads the `on`, which then runs to end of file.
    """
    skip = non_matching(src)
    counts = {}
    for i, stripped in enumerate(src.code):
        m = PRAGMA.match(stripped)
        if not m or m.group(1) not in DEFAULTS:
            continue
        inside = i in skip
        c = counts.setdefault(m.group(1), {'in': 0, 'out': 0, 'line': i + 1})
        c['in' if inside else 'out'] += 1
    return {k: v for k, v in counts.items() if v['in'] and v['out'] % 2}


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    show_all = '--all' in sys.argv
    report = json.loads(Path(args[0]).read_text())
    status = {}
    for r in report['results']:
        if r['name'].startswith('func_'):
            status[r['name'][len('func_'):].lower()] = (r['status'], r['file'])

    rows = []
    splits = []
    for path in sorted(Path('src').rglob('*.c')):
        rel = str(path).replace('/', '\\')
        if verify.is_third_party(rel):
            continue
        src = lint.Source(path, path.read_bytes())
        for knob, info in split_pairs(src).items():
            splits.append({'file': rel, 'knob': knob, 'line': info['line'],
                           'inside': info['in'], 'outside': info['out']})
        for addr, (line, active) in scopes_for(src).items():
            if not active:
                continue
            st, _ = status.get(addr, ('UNSCANNED', ''))
            if st != 'ASM' and not show_all:
                continue
            rows.append({'addr': addr, 'file': rel, 'line': line,
                         'status': st, 'active': active})

    rows.sort(key=lambda r: (r['file'], r['line']))
    print(f'functions compiled under a non-default pragma scope: {len(rows)}')
    for r in rows[:40]:
        knobs = ', '.join(f'{k} {v}' for k, v in sorted(r['active'].items()))
        print(f"  {r['addr']} {r['status']:10} {r['file'].split(chr(92))[-1]}:"
              f"{r['line']:<5} {knobs}")
    if splits:
        print(f'\npragma pairs split across a NON_MATCHING arm: {len(splits)}')
        print('  (balanced in the text, so P001 is silent - but the build only')
        print('   reads the outside half, which then runs to end of file)')
        for s in splits:
            print(f"  {s['file'].split(chr(92))[-1]}:{s['line']:<5} {s['knob']}"
                  f"  {s['inside']} inside / {s['outside']} outside")
    Path('build/pragma_scopes.json').write_text(
        json.dumps({'scopes': rows, 'split_pairs': splits}, indent=1))
    print('wrote build/pragma_scopes.json')


if __name__ == '__main__':
    main()
