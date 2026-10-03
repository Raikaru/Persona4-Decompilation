"""Live record selections/field reads and actual speed provider, safe 32-bit domains.

Full slices use rows 0..18 and model words 0..15 (15 rejects). Conversion-only
slices cover negative and precision-sensitive words without pointer formation.
The validator and unrelated callbacks are typed recorders; no renderer is run.
"""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_title_fade_contract import runtime,braced
from native32_support import RUNTIME_C,ENTRY_C
RECORD_WORDS=[[0, 1138425856, 1123942400, 1109917696, 1118699520, 0, 1065353216, 0, 0, 0], [6, 1125507072, 1167667008, 3235479552, 1129219072, 1073741824, 1074496795, 3, 0, 1065353216], [5, 1133160448, 1160119360, 3214802944, 1127581696, 1084227584, 1074832335, 2, 20, 1065353216], [2, 1099882496, 1146502656, 0, 1128809472, 1088421888, 1076971430, 1, 40, 1065353216], [3, 3281672192, 1142505472, 1091567616, 1145431808, 1065353216, 1076635885, 2, 50, 1065353216], [1, 1138713600, 1139344384, 3236626432, 1142764800, 1082130432, 1075167879, 1, 60, 1065353216], [4, 1125183488, 1116575744, 0, 1126083584, 1082130432, 1077013373, 5, 80, 1065353216], [7, 1133918208, 3228041216, 0, 1148468224, 0, 1073867649, 0, 85, 1065353216], [0, 3281611776, 1174586464, 0, 1127481344, 0, 1076677837, 0, 0, 1065353216], [0, 3268513792, 1138093056, 3232727040, 1127481344, 1088421888, 1076677837, 0, 0, 1065353216], [0, 3268513792, 1138093056, 3232727040, 1129169920, 1088421888, 1076677837, 0, 0, 1065353216], [0, 1138425856, 1123942400, 1109917696, 1118699520, 0, 1065353216, 0, 0, 1039516303], [1, 1138425856, 1123942400, 1109917696, 1118699520, 0, 1065353216, 0, 0, 1039516303], [2, 1137049600, 1115422720, 1104674816, 1118961664, 0, 1060320034, 0, 0, 1039516303], [3, 1137016832, 1119354880, 1102577664, 1117519872, 0, 1061997756, 0, 0, 1039516303], [4, 1136328704, 1120272384, 1105199104, 1118044160, 0, 1061997756, 0, 0, 1039516303], [5, 1136721920, 1122762752, 1107820544, 1118437376, 0, 1061997756, 0, 0, 1039516303], [6, 1136263168, 1112276992, 1106771968, 1120272384, 0, 1058642313, 0, 0, 1039516303], [7, 1137770496, 1101529088, 1093664768, 1139802112, 0, 1056964574, 0, 0, 1056964608]]

def parts():
 text=(ROOT/'src/promoted/code1_0012.c').read_text();body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
 assert 'extern u8 D_005E5230[];' in body
 for name in ('D_005E523C','D_005E5240','D_005E5248','D_005E5254'):assert 'extern u8 '+name+'[];' in body
 start=body.index('        if (M2C_FIELD(temp_20, s32 *, 0xC) == 0)',body.index('    case 8:'))
 end=body.index('            /* Replace writes the matrix fields',start)
 block=body[start:end]+'        }\n'
 signature=re.search(r'extern void func_0047a0e0\([^;]+;',body)[0]
 provider_text=(ROOT/'src/Graphics/Model/mdlManager.c').read_text()
 provider=braced(provider_text,provider_text.index('void func_0047a0e0(u8 *arg0, s32 arg1, f32 fparg0)'))
 earlier=re.search(r'(?m)^ +func_0047a0e0\(var_4_8,.*;',body)[0].strip()
 zero=[]
 for var in ('var_4_7','var_4_9'):
  stop=body.index('                        if ('+var+' != NULL)')
  begin=body.rindex('                        if (*(s32 *)D_005E5230 >= 0xF)',0,stop)
  zero.append(body[begin:stop])
 reads=[re.search(r'(?m)^ +'+name+r' = .*;',body)[0].strip() for name in ('temp_f0_7','temp_f0_9')]
 predicates=[re.search(r'if \(M2C_BITWISE\(s32, '+name+r'\) >= 0xF\)',body)[0][4:-1] for name in ('temp_f0_7','temp_f0_9')]
 return block,signature,provider,earlier,zero,reads,predicates

def fixture(mutation=None):
 block,sig,provider,earlier,zero,reads,predicates=parts()
 mutations={
 'first_byte':('temp_f0_7 = (f32)*(s32 *)','temp_f0_7 = (f32)*(u8 *)'),
 'second_byte':('temp_f0_9 = (f32)*(s32 *)','temp_f0_9 = (f32)*(u8 *)'),
 'unsigned_model':('*(s32 *)(D_005E5230 + M2C_FIELD','*(u32 *)(D_005E5230 + M2C_FIELD'),
 'stride160':('u32 *, 0x84) * 0x28','u32 *, 0x84) * 0xA0'),
 'double_slot_scale':('M2C_BITWISE(s32, temp_f0_9)]','M2C_BITWISE(s32, temp_f0_9) * 4]'),
 'reject14':('temp_f0_9) >= 0xF','temp_f0_9) >= 0xE'),
 'lower_clamp':('temp_f0_7) >= 0xF','temp_f0_7) < 0 || M2C_BITWISE(s32, temp_f0_7) >= 0xF'),
 'only_validator_one':('u8 **, 0x44)) != 0','u8 **, 0x44)) == 1'),
 'no_reload':('var_16_2 = (u8 *)(M2C_FIELD(temp_2_25, u8 **, 0x44));','var_16_2 = initialPointer;'),
 'validator_pointer':('var_16_2 = (u8 *)(M2C_FIELD(temp_2_25, u8 **, 0x44));','var_16_2 = (u8 *)validatorResult;'),
 'first_gate':('s32 *, 0xC) == 0','s32 *, 0xC) != 0'),
 'counter_saturation':('temp_2_24 < 0x258','temp_2_24 <= 0x258'),
 'pitch_byte':('temp_f24 = *(f32 *)','temp_f24 = (f32)*(u8 *)'),
 'yaw_byte':('temp_f23 = *(f32 *)','temp_f23 = (f32)*(u8 *)'),
 'scale_byte':('temp_f21_3 = *(f32 *)','temp_f21_3 = (f32)*(u8 *)'),
 'swap_fields':('temp_f24 = *(f32 *)(D_005E523C','temp_f24 = *(f32 *)(D_005E5240'),
 'speed_byte':('*(f32 *)(D_005E5254','(f32)*(u8 *)(D_005E5254'),
 'speed_layer':('func_0047a0e0(var_16_2, 0,','func_0047a0e0(var_16_2, 1,'),
 'earlier_speed':('func_0047a0e0(var_4_8, 0, fGpffff8110);','func_0047a0e0(var_4_8, 0, 0.0f);'),
 'missing_mirror':('*(f32 *)(arg0 + 0x244) = fparg0;','(void)fparg0;'),
 'missing_mask':('arg1 & 0xFFFF','arg1'),
 'signed_row_bound':('temp_17_2 >= 0x13U','(s32)temp_17_2 >= 0x13'),
 'zero_bad_slot':('&temp_20[*(s32 *)D_005E5230]','&temp_20[*(s32 *)D_005E5230 * 4]'),
 }
 pieces=[block,earlier,*zero,*reads,*predicates,provider]
 if mutation in mutations:
  x,y=mutations[mutation];assert any(x in p for p in pieces);pieces=[p.replace(x,y) for p in pieces]
 block,earlier,zero0,zero1,read0,read1,pred0,pred1,provider=pieces
 bound=re.search(r'if \((?:\(s32\))?temp_17_2 >= 0x13U?\)',block)[0][4:-1]
 provider=provider.replace('void func_0047a0e0(', 'void actual_speed(')
 if mutation=='roundtrip_removed':
  read0=read0.replace('(f32)*','*');read1=read1.replace('(f32)*','*')
  convtype='s32'
 else:convtype='f32'
 record_init='{'+','.join('{'+','.join(hex(v)+'u' for v in row)+'}' for row in RECORD_WORDS)+'}'
 prefix=RUNTIME_C+r'''
typedef unsigned char u8;typedef unsigned u32;typedef int s32;typedef float f32;
#define NULL ((void*)0)
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((u8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define CHECK(x) do { if(!(x)) native32_failure(__LINE__,scenario,#x); } while(0)
static unsigned scenario;
static const u32 retailRows[19][10]=@RECORDS@;
static u32 rows[19][10];
#define D_005E5230 ((u8*)rows)
#define D_005E523C ((u8*)rows+12)
#define D_005E5240 ((u8*)rows+16)
#define D_005E5248 ((u8*)rows+24)
#define D_005E5254 ((u8*)rows+36)
static u8 D_005E5548[4];
static u32 model[32][200],work[128];
static u32 bigStorage[2690000];
static unsigned phase,validations,animations,colors,speeds,slot,secondRow,secondModel;
static int mutateSlot,validatorResult;
static u8 *initialPointer,*reloadedPointer,*selectedPointer;
static f32 fGpffff9c8c=0.5f;
static u32 bits(f32 v){u32 u;memcpy(&u,&v,4);return u;}
static f32 float_word(u32 u){f32 f;memcpy(&f,&u,4);return f;}
static s32 func_004782b0(u8 *p){
 CHECK(p==initialPointer);++validations;
 if(mutateSlot)work[17+slot]=(u32)reloadedPointer;
 return validatorResult;
}
static void func_00479940(u8 *p,s32 a,s32 b,s32 c,s32 d){
 CHECK(phase==0);CHECK(p==(mutateSlot?reloadedPointer:initialPointer));
 CHECK(a==0&&b==2&&c==0&&d==1);++animations;
}
static void func_0045c870(u8 *p,s32 enable){
 CHECK(bits(*(f32*)p)==bits(fGpffff9c8c));CHECK(enable==1);++colors;phase=1;
 work[0x84/4]=secondRow;rows[secondRow][0]=secondModel;slot=secondModel;
 initialPointer=(u8*)model[slot];reloadedPointer=(u8*)model[(slot+17)%32];work[17+slot]=(u32)initialPointer;
}
static void func_0046d730(u8 *p,s32 line){CHECK(0);}
'''
 wrapper=r'''
static int providerOnly;
void func_0047a0e0(u8 *p,s32 layer,f32 speed){
 ++speeds;CHECK(layer==0);
 if(!providerOnly){CHECK(phase==1);CHECK(p==(mutateSlot?reloadedPointer:initialPointer));CHECK(bits(speed)==rows[secondRow][9]);}
 actual_speed(p,layer,speed);
}
static void selected(u32 *temp_20){
 f32 temp_f0_7,temp_f0_8,temp_f0_9,temp_f24,temp_f23,temp_f21_3,sp68C;
 union {f32 value;u32 word;} sp6BC;
 u32 *temp_2_23,*temp_2_25;u8 *var_4_16,*var_16_2;
 s32 temp_2_24,temp_3_19,temp_2_26,temp_3_20,temp_3_21;u32 temp_17_2;
 @BLOCK@
 selectedPointer=var_16_2;
 if(var_16_2){CHECK(bits(temp_f24)==rows[secondRow][3]);CHECK(bits(temp_f23)==rows[secondRow][4]);CHECK(bits(temp_f21_3)==rows[secondRow][6]);}
}
static void earlier(u8 *var_4_8,f32 fGpffff8110){@EARLIER@}
static void conversion(u32 *temp_20,s32 input,s32 expected){
 @CONVTYPE@ temp_f0_7,temp_f0_9;
 rows[work[0x84/4]][0]=(u32)input;
 @READ0@ @READ1@
 CHECK(M2C_BITWISE(s32,temp_f0_7)==expected);CHECK(M2C_BITWISE(s32,temp_f0_9)==expected);
 CHECK((@PRED0@)==(expected>=15));CHECK((@PRED1@)==(expected>=15));
}
static u8 *zero0(u32 *temp_20){u32 *temp_2_11;u8 *var_4_7;@ZERO0@ return var_4_7;}
static u8 *zero1(u32 *temp_20){u32 *temp_2_12;u8 *var_4_9;@ZERO1@ return var_4_9;}
static s32 bound(u32 temp_17_2){return @BOUND@;}
int main(void){
 CHECK(!bound(18));CHECK(bound(19));CHECK(bound(0xffffffffu));
 const s32 inputs[]={0,1,14,15,256,-1,-256,16777217,-16777217,2147483520,(-2147483647-1)};
 const s32 expected[]={0,1,14,15,256,-1,-256,16777216,-16777216,2147483520,(-2147483647-1)};
 const s32 results[]={0,1,2,-1};const s32 counts[]={0,1,599,600,601};
 /* Conversion/predicate only: never forms a negative/large model slot. */
 memcpy(rows,retailRows,sizeof(rows));
 for(unsigned row=0;row<19;++row)for(unsigned i=0;i<11;++i){++scenario;work[0x84/4]=row;conversion(work,inputs[i],expected[i]);}
 /* Full actual-record and synthetic valid-index paths. */
 for(unsigned row=0;row<19;++row)for(unsigned index=0;index<17;++index)
 for(unsigned vr=0;vr<4;++vr)for(unsigned change=0;change<2;++change)for(unsigned ct=0;ct<5;++ct){
  ++scenario;memcpy(rows,retailRows,sizeof(rows));memset(work,0,sizeof(work));memset(model,0x5a,sizeof(model));
  for(unsigned j=0;j<15;++j)work[17+j]=(u32)model[j];
  unsigned firstModel=index==16?rows[row][0]:index;
  rows[row][0]=firstModel;work[0x84/4]=row;work[3]=counts[ct];
  secondRow=(row+1)%19;secondModel=index==16?rows[secondRow][0]:(index+1)%16;
  mutateSlot=change;validatorResult=results[vr];phase=validations=animations=colors=speeds=0;
  slot=firstModel;initialPointer=(u8*)model[slot];reloadedPointer=(u8*)model[(slot+17)%32];
  selected(work);
  unsigned firstAccepted=counts[ct]==0&&firstModel<15;
  unsigned secondAccepted=secondModel<15;
  CHECK(validations==firstAccepted+secondAccepted);CHECK(animations==(firstAccepted&&validatorResult));CHECK(colors==1);
  CHECK(work[3]==(u32)(counts[ct]<600?counts[ct]+1:counts[ct]));
  CHECK(speeds==(secondAccepted&&validatorResult));
  u8 *expectedPointer=secondAccepted&&validatorResult?(mutateSlot?reloadedPointer:initialPointer):NULL;
  CHECK(selectedPointer==expectedPointer);
  if(expectedPointer){CHECK(*(u32*)(expectedPointer+244)==rows[secondRow][9]);CHECK(*(u32*)(expectedPointer+580)==rows[secondRow][9]);CHECK(*(u32*)(expectedPointer+216)==((0x5a5a5a5au&~8u)|0x10|0x100000|0x40000));}
 }
 /* Both direct row-zero blocks retain direct signed words and reloads. */
 for(unsigned which=0;which<2;++which)for(unsigned index=0;index<16;++index)for(unsigned vr=0;vr<4;++vr)for(unsigned change=0;change<2;++change){
  ++scenario;rows[0][0]=index;slot=index;validatorResult=results[vr];mutateSlot=change;validations=0;
  initialPointer=(u8*)model[index];reloadedPointer=(u8*)model[index+16];work[17+index]=(u32)initialPointer;
  u8 *p=which?zero1(work):zero0(work);CHECK(validations==(index<15));CHECK(p==(index<15&&validatorResult?(change?reloadedPointer:initialPointer):NULL));
 }
 /* Direct-path source audit rejects adding a round trip even though all valid
  * nonnegative slots are exactly representable. Do not use unsafe pointers. */
 providerOnly=1;
 const u32 values[]={0,0x80000000u,0x3f800000,0xbf800000u,0x3df5c28f,0x3f000000,0xc0d98000u,0x3effffde,0x7f7fffff,0xff7fffffu};
 for(unsigned i=0;i<10;++i){++scenario;speeds=0;earlier((u8*)model[0],float_word(values[i]));CHECK(speeds==1);CHECK(model[0][61]==values[i]);CHECK(model[0][145]==values[i]);}
 const s32 layers[]={0,1,2,65535,65536,-1,-65536};
 for(unsigned l=0;l<7;++l)for(unsigned f=0;f<10;++f){
  ++scenario;unsigned off=((unsigned)layers[l]&65535u)*164+244;
  bigStorage[off/4]=0x12345678;bigStorage[580/4]=0x9abcdef0;
  actual_speed((u8*)bigStorage,layers[l],float_word(values[f]));
  CHECK(bigStorage[off/4]==values[f]);CHECK(bigStorage[580/4]==(((unsigned)layers[l]&65535u)==0?values[f]:0x9abcdef0));
 }
 native32_number(scenario);native32_text(" title layout selection/read/provider cases passed\n");return 0;
}
'''
 result=prefix.replace('@RECORDS@',record_init)+sig+'\n'+provider+wrapper+ENTRY_C
 for name,value in dict(BOUND=bound,BLOCK=block,EARLIER=earlier,CONVTYPE=convtype,READ0=read0,READ1=read1,PRED0=pred0,PRED1=pred1,ZERO0=zero0,ZERO1=zero1).items():result=result.replace('@'+name+'@',value)
 return result

class TitleLayout(unittest.TestCase):
 def run_fixture(self,opt,mutation=None):
  with tempfile.TemporaryDirectory(prefix='p4_title_layout_') as tmp:
   p=Path(tmp);src=p/'test.c';src.write_text(fixture(mutation));rt=runtime();return rt.run(rt.compile(src,p/'test',opt))
 def test_live_source_contract(self):
  block,sig,provider,earlier,zero,reads,preds=parts()
  self.assertEqual(sig,'extern void func_0047a0e0(u8 *model, s32 layer, f32 speed);')
  self.assertEqual(earlier,'func_0047a0e0(var_4_8, 0, fGpffff8110);')
  self.assertIn('s32 arg1, f32 fparg0',provider);self.assertIn('arg1 & 0xFFFF',provider)
  for z in zero:self.assertNotIn('(f32)',z);self.assertIn('*(s32 *)D_005E5230',z)
  for read in reads:self.assertIn('(f32)*(s32 *)',read)
 def test_native_boundaries(self):
  for opt in ('-O0','-O2'):
   with self.subTest(opt=opt):
    r=self.run_fixture(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);print(opt,r.stdout.strip())
 def test_negative_controls(self):
  names=('first_byte','second_byte','unsigned_model','stride160','roundtrip_removed','double_slot_scale','reject14','lower_clamp','only_validator_one','no_reload','validator_pointer','first_gate','counter_saturation','pitch_byte','yaw_byte','scale_byte','swap_fields','speed_byte','speed_layer','earlier_speed','missing_mirror','missing_mask','zero_bad_slot','signed_row_bound')
  for opt in ('-O0','-O2'):
   for name in names:
    with self.subTest(opt=opt,mutation=name):
     r=self.run_fixture(opt,name);self.assertNotEqual(r.returncode,0,r.stdout+r.stderr);print(opt,name,'rejected:',r.returncode,r.stdout.strip())
if __name__=='__main__':unittest.main()
