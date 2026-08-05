#!/usr/bin/env python3
"""Re-measure every preserved NON_MATCHING body and check its noted nd.

A note saying `nd N` is a claim about the current tree, and it is the least
verifiable thing in the repo: the body lives inside `#ifdef NON_MATCHING`, so
the normal gate never compiles it and nothing notices when the number stops
being true. Two ways that happened here:

  * func_003c3f20 was given its SIBLING's number. Four functions shared a shape,
    one was measured at nd 43, and the note was copied to the rest - but the one
    in a different translation unit actually scores nd 102.
  * func_0039a090's note claimed nd 17, which does not reproduce in any pragma
    environment tried. It was wrong when written.

Both are the same mistake: recording a number without measuring the function it
is attached to. This tool measures each one by splicing the preserved body over
its own INCLUDE_ASM and reading verify.py, restoring the file afterwards.

Only a note of the form `nd N` on the LAST line of the comment block, or
`nd N as committed`, is treated as the claim. Notes routinely quote other
numbers - alternatives tried, before/after pairs - and reading the last integer
in the prose flags a third of the tree as stale.

Usage:
  python tools/nd_audit.py            # every preserved body with a claim
  python tools/nd_audit.py --all      # print measured values for all of them
"""
import importlib.util
import json
import re
import subprocess
import sys
from pathlib import Path

_SPEC = importlib.util.spec_from_file_location(
    'p4_draft_probe', Path(__file__).resolve().parent / 'draft_probe.py')
dp = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(dp)

sys.path.insert(0, 'tools')
import verify

MARK = dp.MARK
# The claim: `nd N` in the closing sentence, optionally `nd N as committed`.
CLAIM = re.compile(r'\bnd\s+(\d+)(?:\s+as\s+committed)?\s*\.?\s*(?:\*/)?\s*$')


def claimed_nd(lines, marker):
    """The nd this note commits to, or None.

    Looks only at the note's last non-blank line, so a number quoted mid-prose
    as an alternative is not mistaken for the recorded residual.
    """
    for i in range(marker - 1, max(-1, marker - 25), -1):
        s = lines[i].strip()
        if not s:
            continue
        if not (s.startswith(('/*', '*', '//')) or s.endswith('*/')):
            return None
        m = CLAIM.search(s)
        if m:
            return int(m.group(1))
        if s.startswith('/*'):
            return None
    return None


def preserved_blocks(lines):
    """(marker, ifdef, else, endif) for each `#ifdef NON_MATCHING` body."""
    for i, line in enumerate(lines):
        if not MARK.match(line):
            continue
        j = i + 1
        while j < len(lines) and lines[j].strip().startswith(('/*', '*', '//', '#pragma')):
            j += 1
        if j >= len(lines) or lines[j].strip() != '#ifdef NON_MATCHING':
            continue
        try:
            els = next(k for k in range(j, len(lines)) if lines[k].strip() == '#else')
            end = next(k for k in range(els, len(lines)) if lines[k].strip() == '#endif')
        except StopIteration:
            continue
        yield i, j, els, end


def measure(path, lines, marker, ifd, els, end, addr, nl):
    """nd of the preserved body, compiled in place of its INCLUDE_ASM."""
    orig = path.read_bytes()
    new = list(lines)
    # everything between the marker and the #ifdef is load-bearing (pragmas)
    new[marker:end + 1] = [lines[marker]] + lines[marker + 1:ifd] + lines[ifd + 1:els]
    path.write_bytes(nl.join(new).encode())
    try:
        subprocess.run([sys.executable, 'tools/verify.py', '--json',
                        'build/nd_audit.json', str(path)],
                       capture_output=True, stdin=subprocess.DEVNULL)
        d = json.loads(Path('build/nd_audit.json').read_text())
        row = [r for r in d['results'] if r['name'] == f'func_{addr}']
        if not row:
            return ('NO_ROW', None)
        return (row[0]['status'], row[0].get('normalized_diff'))
    finally:
        path.write_bytes(orig)


def main():
    show_all = '--all' in sys.argv
    stale, checked = [], 0
    for path in sorted(Path('src').rglob('*.c')):
        if verify.is_third_party(str(path).replace('/', '\\')):
            continue
        txt = path.read_bytes().decode('utf-8', errors='replace')
        nl = '\r\n' if txt.count('\r\n') >= max(1, txt.count('\n') // 2) else '\n'
        lines = txt.replace('\r\n', '\n').split('\n')
        for marker, ifd, els, end in preserved_blocks(lines):
            claim = claimed_nd(lines, marker)
            if claim is None and not show_all:
                continue
            addr = MARK.match(lines[marker]).group(1).lower()
            checked += 1
            status, got = measure(path, lines, marker, ifd, els, end, addr, nl)
            drifted = claim is not None and got != claim
            if drifted or show_all:
                flag = '  <== DRIFTED' if drifted else ''
                print(f"  {addr} {path.name:24} noted={claim} measured={got} "
                      f"({status}){flag}")
            if drifted:
                stale.append({'addr': addr, 'file': str(path),
                              'claimed': claim, 'measured': got, 'status': status})
    Path('build/nd_audit_stale.json').write_text(json.dumps(stale, indent=1))
    print(f'\n{checked} preserved bodies checked; {len(stale)} whose noted nd has drifted')
    return 1 if stale else 0


if __name__ == '__main__':
    sys.exit(main())
