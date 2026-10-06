"""Give each strip branch an explicit cursor with its actual native lifetime.

The authenticated simplify replay ends with work(32), geometry(35), vertex
count(41), inlined cursor(67), strip vertex(69), and normalized vertex(172).
Ascending removal makes the inlined cursor claim s2 before the count. Native
code uses s2 for the count and s3 for each disjoint topology cursor. Expanding
the two real strip branches allows their advancing pointers to remain with
the other geometry pointers, before the retained vertex count. Every added
cursor is initialized and supplies all triangle writes of its own branch.
"""
from lab import Lab, SCRATCH, save
import re

lab = Lab('004b8350')
source = lab.original
helper_name = 'static inline void effAfterBuildStrip'
helper_start = source.rindex('#pragma push', 0, source.index(helper_name))
opening = source.index('{', source.index(helper_name))
helper_end = source.index('#pragma pop', opening) + len('#pragma pop\n')
closing = source.rindex('\n}', opening, helper_end)
helper_body = source[opening + 1:closing].strip('\n')
source = source[:helper_start] + source[helper_end:]
main_start = source.index('u8 *func_004b8350')
main_end = source.index('#else', main_start)
main = source[main_start:main_end]
declaration = '    struct RpTriangle *idx;\n'
assert main.count(declaration) == 1
main = main.replace(declaration, declaration +
                    '    struct RpTriangle *firstStripTriangle;\n'
                    '    struct RpTriangle *secondStripTriangle;\n', 1)
call = '        effAfterBuildStrip(arg0, obj, idx);'
assert main.count(call) == 2
for cursor in ('firstStripTriangle', 'secondStripTriangle'):
    expanded = re.sub(r'\bidx\b', cursor, helper_body)
    expanded = re.sub(r'\bi\b', 'stripIndex', expanded)
    expanded = re.sub(r'\bw\b', 'stripVertex', expanded)
    position = expanded.index('    func_003c2130')
    expanded = expanded[:position] + f'    {cursor} = idx;\n' + expanded[position:]
    replacement = '        {\n' + '\n'.join('        ' + line for line in expanded.splitlines()) + '\n        }'
    main = main.replace(call, replacement, 1)
source = source[:main_start] + main + source[main_end:]
assert 'effAfterBuildStrip' not in source
candidate = SCRATCH / 'phase-owned-strip-cursors-guarded.c'
candidate.write_text(source, encoding='utf-8')
result = lab.probe('phase-owned-strip-cursors', source=source)
save(SCRATCH / 'phase-owned-strip-cursors-result.json', result)
