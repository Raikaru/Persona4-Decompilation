import sys, os, glob
sys.path.insert(0, 'build')
import tu_move as T
hidx = {}
for h in sorted(glob.glob('include/**/*.h', recursive=True), key=lambda x: ('_internal' not in x, x)):
    rel = os.path.relpath(h, 'include').replace('\\', '/')
    if rel.startswith(('rw/', 'cri/', 'sce/', 'middleware/')) or 'recvx' in rel:
        continue
    for l in open(h, encoding='utf-8', errors='replace'):
        m = T.PROTO.match(l.rstrip('\n'))
        if m:
            hidx.setdefault(m.group(1), rel)
for f in sys.argv[1:]:
    orig = open(f, encoding='utf-8', newline='').read()
    base = T.verify_rows(f)
    if not base or any(s != 'MATCH' for s in base.values()):
        print(f, 'base not all MATCH; left as is'); continue
    T.headerize(f, hidx)
    now = T.verify_rows(f)
    if now and all(now.get(n) == 'MATCH' for n in base):
        print(f, 'kept includes')
    else:
        open(f, 'w', encoding='utf-8', newline='').write(orig)
        print(f, 'REVERTED to local prototypes', {n: s for n, s in now.items() if s != 'MATCH'})
