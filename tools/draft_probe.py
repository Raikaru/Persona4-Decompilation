#!/usr/bin/env python3
"""Score every m2c draft in src/generated against its retail window.

There are drafts for most un-decompiled functions, but applying them in bulk does
not work: an earlier attempt spliced 30 at once and produced 242 compile errors,
because a draft freely references symbols its destination file never declares.
Measuring ONE at a time and keeping only what compiles turns that failure mode into
a filter, and gives a worklist ranked by how close each draft already is.

The draft is never committed by this tool. It restores every file it touches, and a
draft that scores well is a starting point for a hand reconstruction, not an answer:
m2c gets pointer arithmetic wrong in ways that still compile (`s32 *p; p += 0x10`
advances 64 bytes where retail advances 16).

Usage:
  python tools/draft_probe.py targets.json          # [{file, addr, name, win}]
  python tools/draft_probe.py targets.json 30       # only the first 30
"""
import json
import re
import subprocess
import sys
from pathlib import Path

REPO = Path('.')
MARK = re.compile(r'^\s*//\s*FUN_([0-9A-Fa-f]{8})\b')
M2C_CALL = 'M2C_FIELD('
BAD = ('M2C_UNK', 'M2C_ERROR', 'M2C_MEMCPY', '?')


def find_draft(name):
    """Return the draft's full function DEFINITION, or None.

    Must not match a forward declaration. `s32 func_001077f0();` matches the same
    name pattern, and walking braces from there silently captures the NEXT
    function's body - measuring one function's draft against another's window, which
    looks like a plausible bad score instead of an error.
    """
    pat = re.compile(r'^[A-Za-z_][\w \*]*\b' + re.escape(name) + r'\s*\(')
    for g in sorted(Path('src/generated').rglob('*.c')):
        lines = g.read_text(errors='replace').split('\n')
        for i, l in enumerate(lines):
            if not pat.match(l):
                continue
            # walk to the end of the signature, then demand '{' before any ';'
            depth, j, sig_done = 0, i, False
            while j < len(lines) and not sig_done:
                for ch in lines[j]:
                    if ch == '(':
                        depth += 1
                    elif ch == ')':
                        depth -= 1
                        if depth == 0:
                            sig_done = True
                    elif depth == 0 and sig_done:
                        break
                if not sig_done:
                    j += 1
            tail = lines[j].split(')')[-1] if j < len(lines) else ''
            k = j
            while k < len(lines) and not tail.strip():
                k += 1
                tail = lines[k] if k < len(lines) else ''
            if ';' in tail.split('{')[0]:
                continue                      # a declaration, not a definition
            depth, m, started = 0, i, False
            while m < len(lines):
                depth += lines[m].count('{') - lines[m].count('}')
                if '{' in lines[m]:
                    started = True
                if started and depth == 0:
                    return '\n'.join(lines[i:m + 1])
                m += 1
    return None


def _split_args(s):
    """Split a comma-separated argument list, respecting nesting.

    A regex cannot do this: `M2C_FIELD(M2C_FIELD(p, u8 **, 4), s32 *, 8)` has commas
    inside the first argument, and a naive `[^,]+?` silently pairs the wrong type
    with the wrong base. The result still compiles, which is the dangerous part.
    """
    args, depth, cur = [], 0, ''
    for ch in s:
        if ch in '([':
            depth += 1
        elif ch in ')]':
            depth -= 1
        if ch == ',' and depth == 0:
            args.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        args.append(cur.strip())
    return args


def clean(text):
    """Mechanical m2c-ism removal. Returns None when the draft is unusable.

    Expands innermost-first so a nested field is already plain C by the time its
    parent is rewritten.
    """
    while True:
        i = text.rfind(M2C_CALL)          # rfind: innermost/last occurrence first
        if i < 0:
            break
        j, depth = i + len(M2C_CALL) - 1, 0
        for k in range(j, len(text)):
            if text[k] == '(':
                depth += 1
            elif text[k] == ')':
                depth -= 1
                if depth == 0:
                    j = k
                    break
        else:
            return None                   # unbalanced: refuse rather than mangle
        args = _split_args(text[i + len(M2C_CALL):j])
        if len(args) != 3:
            return None
        base, typ, off = args
        text = text[:i] + f'*({typ})((u8 *)({base}) + {off})' + text[j + 1:]
    if any(b in text for b in BAD):
        return None
    return text


def splice_and_measure(cfile, addr, body, report='build/draft_try.json'):
    p = Path(cfile)
    orig = p.read_bytes()
    txt = orig.decode('utf-8', errors='replace')
    nl = '\r\n' if txt.count('\r\n') >= max(1, txt.count('\n') // 2) else '\n'
    L = txt.replace('\r\n', '\n').split('\n')
    try:
        mi = next(k for k, l in enumerate(L)
                  if MARK.match(l) and MARK.match(l).group(1).lower() == addr)
        inc = next(k for k in range(mi, len(L)) if 'INCLUDE_ASM' in L[k])
    except StopIteration:
        return ('NO_MARKER', None, None, 0)
    L[mi:inc + 1] = [re.sub(r'\s+NONMATCHING\b.*$', '', L[mi])] + body.split('\n')
    p.write_bytes(nl.join(L).encode())
    try:
        subprocess.run([sys.executable, 'tools/verify.py', '--json', report, cfile],
                       capture_output=True, stdin=subprocess.DEVNULL)
        d = json.loads(Path(report).read_text())
        row = [r for r in d['results'] if r['name'] == f'func_{addr}']
        if not row:
            return ('NO_ROW', None, None, 0)
        coll = [r['name'] for r in d['results']
                if r['status'] in ('MISMATCH', 'COMPILE_ERROR') and r['name'] != f'func_{addr}']
        return (row[0]['status'], row[0].get('normalized_diff'),
                row[0].get('object_size'), len(coll))
    finally:
        p.write_bytes(orig)


def main():
    targets = json.loads(Path(sys.argv[1]).read_text())
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else len(targets)
    out = []
    for t in targets[:limit]:
        draft = find_draft(t['name'])
        if not draft:
            continue
        body = clean(draft)
        if not body:
            print(f"  {t['addr']} {t['name']:20} draft has M2C placeholders, skipped")
            continue
        st, nd, obj, coll = splice_and_measure(t['file'], t['addr'], body)
        flag = '  <== MATCH' if st == 'MATCH' and coll == 0 else ''
        print(f"  {t['addr']} {t['name']:20} {st:14} nd={nd} obj={obj}/{t['win']} coll={coll}{flag}")
        out.append({**t, 'status': st, 'nd': nd, 'obj': obj, 'coll': coll})
    Path('C:/tmp/p4_draft_out.json').write_text(json.dumps(out, indent=1))
    good = [r for r in out if r['status'] == 'MATCH' and r['coll'] == 0]
    close = [r for r in out if r['nd'] is not None and r['nd'] <= 30 and r['coll'] == 0]
    print(f"\n{len(good)} match(es); {len(close)} within nd 30")


if __name__ == '__main__':
    main()
