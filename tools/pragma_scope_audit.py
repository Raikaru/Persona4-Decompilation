"""Find pragmas left active past their intended scope.

Raw on/off counts are meaningless because `#pragma push`/`pop` save and restore
the whole pragma state. What matters is whether a file ends with any pragma
still flipped away from the -O2 baseline, and which functions sit under a flip
that never closes -- that is the shape of the wave-24 defect, where an
`opt_propagation off` stayed open across ~14 downstream functions and silently
changed their codegen.
"""
import pathlib, re, sys

KW = ["opt_propagation", "opt_common_subs", "opt_loop_invariants", "schedule",
      "no_branch_likely", "opt_rebuildconditionals"]
SKIP = ("generated", "cri", "rw", "sce")
PRAGMA = re.compile(r'^\s*#pragma\s+(\w+)\s*(on|off)?\s*$')
MARKER = re.compile(r'^\s*//\s*FUN_([0-9A-Fa-f]{8})')

bad = []
for p in sorted(pathlib.Path('src').rglob('*.c')):
    if any(s in p.parts for s in SKIP):
        continue
    state = {k: None for k in KW}       # None = compiler default
    stack = []
    exposed = {}                        # marker -> list of (kw, state)
    for i, line in enumerate(p.read_text(encoding='utf-8', errors='replace').splitlines(), 1):
        m = MARKER.match(line)
        if m:
            live = [(k, v) for k, v in state.items() if v == "off"]
            if live:
                exposed.setdefault(m.group(1), []).append((i, live))
            continue
        m = PRAGMA.match(line)
        if not m:
            continue
        name, val = m.group(1), m.group(2)
        if name == "push":
            stack.append(dict(state))
        elif name == "pop":
            if stack:
                state = stack.pop()
        elif name in state and val:
            state[name] = val
    leaked = [(k, v) for k, v in state.items() if v is not None]
    if leaked or stack:
        bad.append((p, leaked, len(stack), exposed))

print(f"files ending with pragma state off baseline: {len(bad)}\n")
for p, leaked, depth, exposed in bad:
    print(f"{p}")
    if leaked:
        print(f"    EOF state: {', '.join(f'{k}={v}' for k, v in leaked)}")
    if depth:
        print(f"    unclosed #pragma push depth: {depth}")
    off_funcs = {fn for fn, rows in exposed.items() for _, live in rows for k, v in live}
    if off_funcs:
        print(f"    functions compiled under an open 'off': {len(off_funcs)}")
        for fn in sorted(off_funcs)[:6]:
            kws = sorted({k for _, live in exposed[fn] for k, v in live})
            print(f"      FUN_{fn}: {', '.join(kws)}")
        if len(off_funcs) > 6:
            print(f"      ... and {len(off_funcs) - 6} more")
    print()
