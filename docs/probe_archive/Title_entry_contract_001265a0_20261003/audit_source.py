"""Whole-owner exact bounded transformation from the frozen model checkpoint."""
from pathlib import Path
import hashlib,json,subprocess
BASE='81708cc4e9e63e3b1eae30f466c069359a8dff70';OWNER='src/promoted/code1_0012.c'
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();new=Path(OWNER).read_text();expected=old
changes=[('void func_001265a0(s32 arg1) {','''/* The draw queue supplies node+0x1C, then the task stored at node+0x10.
 * Only the task reaches the word-returning work accessor; the first payload
 * is a real, unused callback input. See Title_entry_contract_001265a0_20261003. */
void func_001265a0(void *unusedDrawData, void *task) {'''),
('    extern u32 *func_00452560(s32);','    extern u32 func_00452560(void *task);'),
('    temp_20 = (u32 *)(func_00452560(arg1));','    temp_20 = (u32 *)func_00452560(task);'),
('    extern s32 func_001265a0(u8 *task);','    extern void func_001265a0(void *unusedDrawData, void *task);'),
('        *(s32 (**)(u8 *))(drawTask + 8) = func_001265a0;','        *(void (**)(void *, void *))(drawTask + 8) = func_001265a0;')]
for a,b in changes:assert expected.count(a)==1;expected=expected.replace(a,b)
assert expected==new
assert 'extern void *func_00452560();' in new
assert '// FUN_001265A0 NONMATCHING\n#ifdef NON_MATCHING' in new
assert 'INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);' in new
providers={}
for name in ('src/Kernel/sdkTask.c','src/sdkOt.c','src/promoted/code1_0046.c'):
 raw=Path(name).read_bytes();assert raw==subprocess.check_output(['git','show',BASE+':'+name]);providers[name]=hashlib.sha256(raw).hexdigest()
report={'base':BASE,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_five_substitution_transform':True,
 'callback_contract':'void (void *unusedDrawData, void *task)','getter_contract':'u32 (void *task)',
 'explicit_work_address_word_conversion':True,'global_old_style_accessor_declaration_unchanged':True,
 'other_matched_accessor_callers_unchanged':True,'guard_and_fallback_retained':True,
 'unchanged_provider_and_dispatcher_source_sha256':providers,'dispatcher_C_native_execution':False}
Path('proof/entry-source-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Exact bounded source repair; getter provider, node/dispatcher owners, other callers and fallback unchanged')
