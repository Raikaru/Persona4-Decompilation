"""Throwaway: plan, apply and prune run-level inferred TU moves out of code1 buckets.

plan   -> build/tu_plan.json (pieces: src bucket, dest file, member addresses, lane)
apply  -> apply the pieces at the given plan indices (dest files, cut blocks, config lists).
prune  -> for each dest file: drop each replayed optimisation pragma that no function needs
          (owner verify per removal); keep the others with a measured comment naming the
          functions that break without them.

Rules:
- #pragma lines are never cut from a bucket, so the rest of the bucket keeps its pragma state.
- Each dest replays, in bucket order, every #pragma line that precedes a moved block, with the
  comment group directly above it (lint measured-comment rule), each line at most once.
- Prototypes the moved bodies call: if an include/ header declares them, the dest includes the
  header instead; otherwise the bucket's local prototype is kept.
"""
import glob
import json
import os
import re
import subprocess
import sys
from collections import Counter

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
os.chdir(REPO)

MARK = re.compile(r'^// FUN_([0-9A-Fa-f]{8})\b')
CLOSE = re.compile(r'^(\}\s*|INCLUDE_ASM\(.*)$')
PROTO = re.compile(r'^(?:extern\s+)?[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*;\s*$')
PRAGMA_OPT = re.compile(r'^\s*#\s*pragma\s+(opt_|schedule|no_branch_likely|optimization_level)')
LISTS = ['config/speed_units.txt', 'config/compiler_units.txt', 'config/gcc_units.txt']

LANE_RULES = [
    ('src/Battle/', 'AtlusReadA'), ('src/Main/Battle/', 'MainBattleTU'),
    ('src/Event/', 'AtlusReadB'), ('src/Script/', 'AtlusReadB'), ('src/cmm', 'AtlusReadB'),
    ('src/Camp/', 'AtlusReadB'), ('src/itfMes', 'AtlusReadB'), ('src/nmCmdList', 'AtlusReadB'),
    ('src/Graphics/', 'GraphicsTU'), ('src/rw/', 'GraphicsTU'),
    ('src/Kosaka/', 'KosakaTU'), ('src/Scene/', 'KosakaTU'), ('src/sequenceList', 'KosakaTU'),
    ('src/shd', 'KosakaTU'), ('src/k_footstep', 'KosakaTU'),
    ('src/Kernel/', 'SystemTU'), ('src/h_', 'SystemTU'), ('src/g_data', 'SystemTU'),
    ('src/datCalendar', 'SystemTU'), ('src/calendar', 'SystemTU'), ('src/dds3', 'SystemTU'),
    ('src/frFont', 'SystemTU'), ('src/Yajima/', 'SystemTU'), ('src/fade', 'SystemTU'),
    ('src/op_fade/', 'SystemTU'),
]


def lane_of_path(p):
    p = p.replace('\\', '/')
    for pre, lane in LANE_RULES:
        if p.startswith(pre):
            return lane
    if re.match(r'^src/Main/[^/]+\.c$', p):
        return 'SystemTU'
    return 'TUCensus'


def live_locations():
    """address -> repo-relative file holding its marker (live tree scan, not the stale map)."""
    loc = {}
    for f in sorted(glob.glob('src/**/*.c', recursive=True)):
        f = f.replace('\\', '/')
        if f.startswith(('src/generated/', 'src/cri/', 'src/sce/')):
            continue
        text = open(f, encoding='utf-8', errors='replace').read()
        for m in re.finditer(r'^// FUN_([0-9A-Fa-f]{8})\b', text, re.M):
            loc.setdefault(m.group(1).lower(), f)
    return loc


def header_index():
    """prototype name -> include/-relative header that declares it (internal headers first)."""
    idx = {}
    for h in sorted(glob.glob('include/**/*.h', recursive=True), key=lambda x: ('_internal' not in x, x)):
        rel = os.path.relpath(h, 'include').replace('\\', '/')
        for l in open(h, encoding='utf-8', errors='replace'):
            m = PROTO.match(l.rstrip('\n'))
            if m:
                idx.setdefault(m.group(1), rel)
    return idx


def pre_start(lines, m):
    """First line of the pragma/comment group directly above marker line m. A block comment is
    taken whole (climbed to its opening line); if no opener is found it stays in the bucket."""
    start, i = m, m - 1
    while i >= 0:
        s = lines[i].strip()
        if not s:
            break
        if s.startswith('#pragma') or (s.startswith('//') and not MARK.match(lines[i])):
            start, i = i, i - 1
            continue
        if s.endswith('*/') or s.startswith(('/*', '*')):
            j = i
            while j >= 0 and '/*' not in lines[j]:
                if MARK.match(lines[j]) or CLOSE.match(lines[j].rstrip('\n')) or lines[j].strip().endswith((';', '{', '}')):
                    return start
                j -= 1
            if j < 0:
                return start
            start, i = j, j - 1
            continue
        break
    return start


def is_pre_line(line):
    """A pragma or comment line: the only lines that belong above a marker in a block."""
    s = line.strip()
    return bool(s) and (s.startswith(('#pragma', '/*', '*', '//')) or s.endswith('*/'))


def parse_blocks(lines):
    """Return (blocks, header_end). blocks[addr] = inclusive (start, end) line span.

    A block is its marker through its closing line (`}` or INCLUDE_ASM), plus the
    contiguous non-blank lines directly above the marker (pragmas, comments)."""
    marks = [i for i, l in enumerate(lines) if MARK.match(l)]
    blocks = {}
    header_end = None
    for k, m in enumerate(marks):
        nxt = marks[k + 1] if k + 1 < len(marks) else len(lines)
        close = None
        depth, opened = 0, False
        for j in range(m + 1, nxt):
            s = lines[j].rstrip('\n')
            if s.startswith('INCLUDE_ASM('):
                close = j
                break
            code = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//.*$', '', s)
            opened = opened or '{' in code
            depth += code.count('{') - code.count('}')
            if opened and depth == 0:
                close = j
                break
        if close is None:
            continue
        start = pre_start(lines, m)
        if header_end is None:
            header_end = start
        blocks[MARK.match(lines[m]).group(1).lower()] = dict(start=start, end=close)
    if header_end is None:
        header_end = len(lines)
    return blocks, header_end


def plan():
    M = json.load(open('build/tu_map.json'))
    loc = live_locations()
    groups = {}
    for a, r in M.items():
        if r.get('cls') != 'inferred_tu' or r.get('tu_stem') is None:
            continue
        if r.get('tu_stem') == 'mt_evtMisc':
            continue  # held for AtlusReadB
        key = ('run', r['run']) if r.get('run') is not None else ('g', r['tu_stem'], a)
        groups.setdefault(key, []).append((a, r))
    pieces = []
    for key, rows in groups.items():
        by_src = {}
        for a, r in rows:
            src = loc.get(a)
            if src is None or not (src.startswith('src/promoted/') or src.endswith('_grouped.c')):
                continue
            by_src.setdefault(src, []).append(a)
        for src, addrs in by_src.items():
            r0 = rows[0][1]
            pieces.append(dict(src=src, members=sorted(addrs), stem=r0['tu_stem'],
                               kind=('new' if r0.get('dest') else 'collision'),
                               dest_hint=r0.get('dest'), confidence=r0.get('confidence'),
                               run=key[1] if key[0] == 'run' else None))
    stems = {}
    for p in pieces:
        stems.setdefault(p['stem'], []).append(p)
    used = set()
    out, skipped = [], []
    for p in sorted(pieces, key=lambda q: int(q['members'][0], 16)):
        if p['kind'] == 'new':
            dest = p['dest_hint'].replace('\\', '/')
        else:
            cands = [c.replace('\\', '/') for c in glob.glob('src/**/' + p['stem'] + '.c', recursive=True)]
            cands = [c for c in cands if not c.startswith(('src/promoted/', 'src/generated/'))
                     and '_grouped' not in c and '_cw119' not in c]
            if not cands:
                p['reason'] = 'no-existing-stem'
                skipped.append(p)
                continue
            multi = len(stems[p['stem']]) > 1
            name = (f"{p['stem']}_inferred_{p['members'][0]}.c" if multi else f"{p['stem']}_inferred.c")
            dest = f"{os.path.dirname(sorted(cands)[0])}/{name}"
        if os.path.exists(dest) or dest in used:
            p['reason'] = 'dest-exists'
            skipped.append(p)
            continue
        used.add(dest)
        p['dest'] = dest
        p['lane'] = lane_of_path(dest)
        out.append(p)
    json.dump(dict(pieces=out, skipped=skipped), open('build/tu_plan.json', 'w'), indent=1)
    print('pieces', len(out), 'skipped', len(skipped), Counter(p.get('reason') for p in skipped))
    print('lanes', Counter(p['lane'] for p in out))
    print('functions', sum(len(p['members']) for p in out))


def build_header(lines, header_end, body_text, hidx):
    """Bucket header minus top-level prototypes of functions the moved blocks do not call.
    Called prototypes that an include/ header declares become #include lines instead."""
    kept, includes = [], []
    hdr_defs = ''.join(l for l in lines[:header_end] if not PROTO.match(l))
    depth = 0
    for l in lines[:header_end]:
        m = None if l.lstrip().startswith('typedef') else PROTO.match(l)
        if m and depth == 0:
            name = m.group(1)
            if not re.search(r'\b' + re.escape(name) + r'\b', body_text + hdr_defs):
                continue  # prototype of a function these blocks do not call
            if name in hidx:
                if hidx[name] not in includes:
                    includes.append(hidx[name])
                continue
        depth += l.count('{') - l.count('}')
        kept.append(l)
    head = ''.join(f'#include "{h}"\n' for h in includes)
    if 'INCLUDE_ASM' in body_text and 'include_asm.h' not in ''.join(kept) + head:
        head = '#include "include_asm.h"\n' + head
    return head + ''.join(kept).rstrip('\n') + '\n\n'


IDENT = re.compile(r'\b[A-Za-z_]\w*\b')


def gap_decls(lines, blocks, header_text, body_text):
    """Declarations between blocks that the moved text uses (typedefs, struct/enum tags, #defines,
    prototypes, extern and static declarations), in original order, with the declarations they need.
    A non-static definition becomes a prototype, so the dest links without a duplicate symbol.
    Declarations whose names the dest header already has are skipped."""
    inblock = set()
    for b in blocks.values():
        inblock.update(range(b['start'], b['end'] + 1))
    items = []
    i, n = 0, len(lines)
    while i < n:
        s = lines[i].strip()
        if s.startswith('/*') and '*/' not in s:
            while i < n and '*/' not in lines[i]:
                i += 1
            i += 1
            continue
        if i in inblock or not s or s.startswith(('#pragma', '#include', '//', '/*', '*')) or MARK.match(lines[i]):
            i += 1
            continue
        j, depth = i, 0
        while j < n - 1 and j + 1 not in inblock:
            depth += re.sub(r'//.*$', '', lines[j]).count('{') - re.sub(r'//.*$', '', lines[j]).count('}')
            if s.startswith('#define'):
                if not lines[j].rstrip().endswith('\\'):
                    break
            elif depth <= 0 and lines[j].rstrip().endswith((';', '}')):
                break
            j += 1
        chunk = ''.join(lines[i:j + 1])
        i = j + 1
        head = chunk.split('{')[0]
        names, kept = set(), chunk
        if s.startswith('#define'):
            names = set(re.findall(r'#define\s+(\w+)', chunk))
        elif s.startswith('typedef'):
            names = set(re.findall(r'\b(?:struct|union|enum)\s+(\w+)', chunk))
            m = re.search(r'(\w+)\s*;\s*$', chunk.rstrip())
            if m:
                names.add(m.group(1))
        elif '(' in head and not re.search(r'\w\s*=', head):
            names = {m.group(1)} if (m := re.search(r'(\w+)\s*\(', head)) else set()
            if '{' in chunk and not s.startswith('static'):
                kept = head.rstrip() + ';\n'
        elif s.startswith(('extern', 'struct', 'union', 'enum')) and chunk.rstrip().endswith(';'):
            names = set(re.findall(r'\b(?:struct|union|enum)\s+(\w+)', chunk))
            m = re.search(r'(\w+)\s*(\[[^\]]*\])?\s*;\s*$', chunk.rstrip())
            if m:
                names.add(m.group(1))
        if not names and s.startswith(('extern', 'static')):
            m2 = re.search(r'(\w+)\s*(?:\[[^\]]*\]\s*)*[;=]', chunk)
            if m2:
                names.add(m2.group(1))
        if names and kept.strip() not in header_text:
            items.append((names, set(IDENT.findall(kept)), kept if kept.endswith('\n') else kept + '\n'))
    needed = set(IDENT.findall(body_text))
    chosen = [False] * len(items)
    changed = True
    while changed:
        changed = False
        for k, (names, uses, _) in enumerate(items):
            if not chosen[k] and names & needed:
                chosen[k] = True
                needed |= uses
                changed = True
    return ''.join(txt for (_, _, txt), c in zip(items, chosen) if c)


def pragma_group_start(lines, k, pos):
    """First line of the group above pragma line k: pragma lines, one blank, and the comment
    directly above them (a measured comment stays with its pragma)."""
    j = k
    while j - 1 >= pos and (lines[j - 1].strip().startswith('#pragma') or (
            not lines[j - 1].strip() and j - 2 >= pos and lines[j - 2].strip().endswith('*/'))):
        j -= 1
    if j - 1 >= pos and lines[j - 1].strip().endswith('*/') and not MARK.match(lines[j - 1]):
        c = j - 1
        while c >= pos and '/*' not in lines[c]:
            if MARK.match(lines[c]) or CLOSE.match(lines[c].rstrip('\n')) or lines[c].strip().endswith((';', '{', '}')):
                c = pos - 1
                break
            c -= 1
        if c >= pos:
            j = c
    return j


def block_sig(lines, b):
    """(name, signature) of the function defined in block b, or (None, None) if it has no single-line
    definition header. The signature is the header without its body brace, for an extern."""
    for i in range(b['start'], b['end'] + 1):
        s = lines[i].rstrip('\n')
        if not s or s[0] in ' \t/*#}{':
            continue
        if '(' not in s or ';' in s.split('(')[0] or s.startswith('static'):
            continue
        head = s.split('{')[0].rstrip()
        if not head.endswith(')'):
            return None, None
        return re.search(r'(\w+)\s*\(', head).group(1), head
    return None, None


def apply(pieces):
    touched = set()
    hidx = header_index()
    by_src = {}
    for p in pieces:
        by_src.setdefault(p['src'], []).append(p)
    for src, ps in by_src.items():
        lines = open(src, encoding='utf-8', newline='').read().splitlines(keepends=True)
        blocks, header_end = parse_blocks(lines)
        cut = set()
        for p in ps:
            body = []
            emitted = set()
            pos = header_end
            for a in sorted(p['members'], key=lambda x: int(x, 16)):
                b = blocks.get(a)
                if b is None:
                    raise SystemExit(f'block {a} not found in {src}')
                for k in range(pos, b['start']):
                    if not lines[k].strip().startswith('#pragma') or k in emitted:
                        continue
                    for idx in range(pragma_group_start(lines, k, pos), k + 1):
                        if idx in emitted or MARK.match(lines[idx]):
                            continue
                        emitted.add(idx)
                        body.append(lines[idx] if lines[idx].endswith('\n') else lines[idx] + '\n')
                body.append(''.join(lines[b['start']:b['end'] + 1]) + '\n')
                cut.update(i for i in range(b['start'], b['end'] + 1)
                           if not lines[i].lstrip().startswith('#pragma'))
                pos = b['end'] + 1
            body_text = ''.join(body)
            text = build_header(lines, header_end, body_text, {})  # includes come from tu_hfix3, per file
            text += f'/* Source unit: {src} */\n'
            text += (f"/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in "
                     f"{src}; members {p['members'][0]}-{p['members'][-1]} */\n\n")
            own = set(p['members'])
            for a, b in blocks.items():
                name, sig = block_sig(lines, b)
                if a not in own and name and name not in hidx and re.search(r'\b' + name + r'\b', body_text):
                    text += 'extern ' + sig + ';\n'
            text += gap_decls(lines, blocks, text, text + body_text)
            text += body_text
            os.makedirs(os.path.dirname(p['dest']), exist_ok=True)
            with open(p['dest'], 'w', encoding='utf-8', newline='') as fh:
                fh.write(text)
            touched.add(p['dest'])
            for lf in LISTS:
                ll = open(lf, encoding='utf-8').read().splitlines(keepends=True)
                out, changed = [], False
                for l in ll:
                    out.append(l)
                    toks = l.split()
                    if toks and toks[0] == src:
                        out.append(l.replace(src, p['dest'], 1))
                        changed = True
                if changed:
                    open(lf, 'w', encoding='utf-8', newline='').write(''.join(out))
                    touched.add(lf)
        keep = [l for i, l in enumerate(lines) if i not in cut]
        kept_body = keep[header_end:]
        protos = []
        for a in sorted({m for p in ps for m in p['members']}):
            name, sig = block_sig(lines, blocks[a])
            if name is None or not any(re.search(r'\b' + name + r'\b', l) for l in kept_body):
                continue
            decl = re.compile(r'^\s*(extern\s+)?\w[\w \t\*]*?\b' + name + r'\s*\(.*\)\s*;\s*$')
            if any(decl.match(l) and 'return' not in l for l in keep):
                continue
            protos.append('extern ' + sig + ';\n')
        keep[header_end:header_end] = protos
        with open(src, 'w', encoding='utf-8', newline='') as fh:
            fh.write(''.join(keep))
        touched.add(src)
    return sorted(touched)


def verify_rows(path):
    """function name -> status for the rows of one file, from the owner verify."""
    tmp = 'build/tu_prune_verify.json'
    subprocess.run(['sh', 'build/py', 'tools/verify.py', path, '--json', tmp],
                   capture_output=True, text=True)
    rows = json.load(open(tmp))['results']
    want = path.replace('/', '\\')
    return {r['name']: r['status'] for r in rows if r['file'].replace('/', '\\') == want}


def prune(path):
    """Drop each replayed optimisation pragma whose removal breaks nothing; keep the rest with
    a measured comment naming the functions that break without them."""
    base = verify_rows(path)
    lines = open(path, encoding='utf-8', newline='').read().splitlines(keepends=True)
    removed = kept = 0
    pos = 0
    while True:
        idx = next((i for i in range(pos, len(lines)) if PRAGMA_OPT.match(lines[i])), None)
        if idx is None:
            break
        trial = lines[:idx] + lines[idx + 1:]
        open(path, 'w', encoding='utf-8', newline='').write(''.join(trial))
        now = verify_rows(path)
        broken = sorted(n for n, s in base.items() if s == 'MATCH' and now.get(n) != 'MATCH')
        if not broken:
            lines = trial
            removed += 1
            continue
        worst = Counter(now.get(n) for n in broken).most_common(1)[0][0]
        note = f"/* measured: {', '.join(broken)} MATCH -> {worst} without this pragma. */\n"
        lines = lines[:idx] + [note] + lines[idx:]
        open(path, 'w', encoding='utf-8', newline='').write(''.join(lines))
        kept += 1
        pos = idx + 2
    print(f'{path}: removed {removed} kept {kept}')


if __name__ == '__main__':
    if sys.argv[1] == 'plan':
        plan()
    elif sys.argv[1] == 'apply':
        plan_all = json.load(open('build/tu_plan.json'))['pieces']
        sel = [plan_all[int(i)] for i in sys.argv[2].split(',')]
        print('\n'.join(apply(sel)))
    elif sys.argv[1] == 'prune':
        for f in sys.argv[2:]:
            prune(f)


def headerize(path, hidx):
    """Replace a dest file's local top-level prototypes with includes of the owner header."""
    lines = open(path, encoding='utf-8', newline='').read().splitlines(keepends=True)
    end = next((i for i, l in enumerate(lines) if l.startswith('/* Inferred unit:')), len(lines))
    kept, includes, depth = [], [], 0
    for i, l in enumerate(lines):
        m = None if (i >= end or l.lstrip().startswith('typedef')) else PROTO.match(l.rstrip('\n'))
        if m and depth == 0 and m.group(1) in hidx:
            if hidx[m.group(1)] not in includes:
                includes.append(hidx[m.group(1)])
            continue
        if i < end:
            depth += l.count('{') - l.count('}')
        kept.append(l)
    head = ''.join(f'#include "{h}"\n' for h in includes if f'#include "{h}"\n' not in kept)
    open(path, 'w', encoding='utf-8', newline='').write(head + ''.join(kept))
    print(f'{path}: includes {includes}')
