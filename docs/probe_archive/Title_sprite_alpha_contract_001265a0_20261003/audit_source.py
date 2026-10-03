"""Reconstruct the complete bounded owner delta from the frozen fade checkpoint."""
from pathlib import Path
import hashlib,json,subprocess
BASE='29758b87c3234fa4f519127c1f61722ca1d087d8';owner=Path('src/promoted/code1_0012.c')
s=subprocess.check_output(['git','show',BASE+':'+str(owner)],text=True)
start=s.index('void func_001265a0(s32 arg1)');end=s.index('#else',start);body=s[start:end]
specs=[('var_5','temp_f1'),('var_5_10','temp_f1_8'),('var_5_11','temp_f2'),('var_5_12','temp_f1_9'),('var_5_13','temp_f1_10'),('var_5_14','temp_f21_2'),('var_5_15','temp_f21_2'),('var_5_18','temp_f1_15'),('var_5_19','temp_f1_16'),('var_5_20','temp_f1_17')]
def replace(old,new):
 global body
 assert body.count(old)==1,(old,body.count(old));body=body.replace(old,new,1)
for var,value in specs:
 replace(f'{var} = 0x4F000000 & 0xFF;',f'{var} = (u32)(s32){value} & 0xFF;')
 high='var_f0' if var=='var_5_14' else f'({value} - 2.1474836e9f)'
 replace(f'(M2C_BITWISE(s32, {high}) | 0x80000000)',f'((u32)(s32)({value} - 2.1474836e9f) | 0x80000000U)')
for old in ('    f32 var_f0;\n','                var_f0 = 2.1474836e9f;\n','                    var_f0 = temp_f21_2 - 2.1474836e9f;\n'):replace(old,'')
replace('temp_f20_5 = (f32)(s32)(sinf(((((fGpffff8094 * (f32) temp_16) / 225.0f)))));','temp_f20_5 = sinf((fGpffff8094 * (f32) temp_16) / 225.0f);')
replace('''                temp_f16 = (f32)(s32)(fGpffff8170 + (1.5f * temp_f20_5));
                temp_f21_2 = (f32)(s32)(255.0f * (1.0f - sinf(((((fGpffff8094 * (f32) var_2_21) / 90.0f))))));''','''                temp_f21_2 = sinf((fGpffff8094 * (f32) var_2_21) / 90.0f);
                /* Keep the first return across the second call; round multiply and add separately. */
                temp_f16 = 1.5f * temp_f20_5;
                temp_f16 = fGpffff8170 + temp_f16;
                temp_f21_2 = 255.0f * (1.0f - temp_f21_2);''')
replace('temp_10 = (s32) (M2C_BITWISE(s32, var_f0) << 16) >> 16;','''/* f2 holds this independent product across both alpha-conversion arms. */
                temp_10 = (s16)(s32)(137.0f * temp_f16);''')
s=s[:start]+body+s[end:]
start=s.index('/* Hole (-1): s64 temp_10');end=s.index('/* measured 2026-09-29:',start)
s=s[:start]+'''/* Historical count-only experiments used the wrong alpha-scratch value for
 * temp_10. Retail 0x1291FC keeps 137.0f * scale in f2 while f0 converts alpha;
 * 0x129268 then converts f2 and narrows its signed integer to 16 bits. The
 * guarded source now preserves that independent value flow, not just width.
 * The adjacent scale uses separate mul.s/add.s rounding. Other upstream
 * ACC placeholders remain outside this bounded sprite-alpha repair. */
'''+s[end:]
assert s==owner.read_text()
report={'baseline':BASE,'source_sha256':hashlib.sha256(owner.read_bytes()).hexdigest(),'complete_source_delta_reconstructed':True,'low_conversion_arms':10,'high_casts_made_explicit':10,'independent_two_sine_scale_pair_subgraph':True,'unrelated_source_unchanged':True}
Path('proof/source-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Exact owner delta reconstructed: ten conversions, two-sine/scale/signed16 lifetime and obsolete note only')
