"""Rebuild the exact bounded source transformation from the frozen entry base."""
from pathlib import Path
import hashlib,json,subprocess
BASE='9bb8b6ad0fafafca04007d67acadff673449bdfa'
OWNER='src/promoted/code1_0012.c'
CHANGES=[(2426, 2426, [], ['#include "btl_shuffle_draw_internal.h"\n']),
 (2442, 2444, ['    extern s32 RwMatrixRotate();\n', '    extern s32 RwMatrixTranslate();\n'], []),
 (2457, 2458, ['    extern s32 func_0047a1c0();\n'], []),
 (2471,
  2475,
  ['    extern s64 D_005E5628;\n',
   '    extern f32 D_005E5630;\n',
   '    extern s64 D_005E5638;\n',
   '    extern f32 D_005E5640;\n'],
  ['    extern BtlShuffleVec3 D_005E5628;\n', '    extern BtlShuffleVec3 D_005E5638;\n']),
 (2565,
  2572,
  ['    f32 sp5D0;\n',
   '    s64 sp5C8;\n',
   '    f32 sp5C0;\n',
   '    s64 sp5B8;\n',
   '    s32 sp5B0;\n',
   '    s32 sp5AC;\n',
   '    f32 sp5A8;\n'],
  ['    BtlShuffleVec3 titleYawAxis;\n',
   '    BtlShuffleVec3 titlePitchAxis;\n',
   '    BtlShuffleVec3 titleTranslation;\n']),
 (2573,
  2574,
  ['    s32 sp550;\n'],
  ['    BtlShuffleMatrix titleMatrix __attribute__((aligned(16)));\n']),
 (2867,
  2871,
  ['    sp5C8 = D_005E5628;\n',
   '    sp5D0 = D_005E5630;\n',
   '    sp5B8 = D_005E5638;\n',
   '    sp5C0 = D_005E5640;\n'],
  ['    titleYawAxis = D_005E5628;\n', '    titlePitchAxis = D_005E5638;\n']),
 (3858,
  3865,
  ['            RwMatrixRotate(&sp550, &sp5C8, 0, temp_f23);\n',
   '            RwMatrixRotate(&sp550, &sp5B8, 2, temp_f24);\n',
   '            sp5A8 = 0.0f;\n',
   '            sp5AC = 0xC2B40000;\n',
   '            sp5B0 = 0;\n',
   '            RwMatrixTranslate(&sp550, &sp5A8, 1);\n',
   '            func_0047a1c0(var_16_2, &sp550, 0);\n'],
  ['            /* Replace writes the matrix fields and flags before concatenation.\n',
   '             * Provider padding remains unspecified; do not synthesize values. */\n',
   '            RwMatrixRotate(&titleMatrix, &titleYawAxis, temp_f23, 0);\n',
   '            RwMatrixRotate(&titleMatrix, &titlePitchAxis, temp_f24, 2);\n',
   '            titleTranslation.x = 0.0f;\n',
   '            titleTranslation.y = -90.0f;\n',
   '            titleTranslation.z = 0.0f;\n',
   '            RwMatrixTranslate(&titleMatrix, &titleTranslation, 1);\n',
   '            func_0047a1c0(var_16_2, &titleMatrix, 0);\n'])]
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();lines=old.splitlines(keepends=True)
for first,last,before,after in reversed(CHANGES):
 assert lines[first:last]==before
 lines[first:last]=after
new=Path(OWNER).read_text();assert ''.join(lines)==new
assert '#include "btl_shuffle_draw_internal.h"' in new
assert 'titleTranslation.y = -90.0f;' in new
assert 'BtlShuffleMatrix titleMatrix __attribute__((aligned(16)));' in new
unchanged=[]
for path in ('include/btl_shuffle_draw_internal.h','include/rw/plcore/bamatrix.h','include/rw/ps2/ostypes.h','src/promoted/code1_003e.c','src/renderware/plcore/bamatrix.c','src/Graphics/Model/mdlManager.c'):
 content=Path(path).read_bytes();assert content==subprocess.check_output(['git','show',BASE+':'+path]);unchanged.append({'path':path,'sha256':hashlib.sha256(content).hexdigest()})
r={'base':BASE,'owner':OWNER,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_source_transform':True,'changed_line_blocks':len(CHANGES),'canonical_rotate_translate_model_declarations_reused':True,'existing_complete_vector_and_matrix_types_reused':True,'actual_matrix_alignment':16,'no_new_matrix_initialization':True,'provider_and_type_sources_unchanged':unchanged,'limits':'No table read/index, speed-call ABI, ACC expression, dispatcher or provider body changed. No full Title execution or new exact-C credit.'}
Path('proof/matrix-source-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Exact bounded source transformation verified; all provider and existing layout sources unchanged')
