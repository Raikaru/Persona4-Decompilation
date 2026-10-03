"""Execute live palette declarations/copy/select slices, stopping before model ABI."""
from pathlib import Path
import re, sys, tempfile, unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests'),str(ROOT/'docs/probe_archive/Title_palette_storage_001265a0_20261003')]
from measure_guarded import extract_guarded_body
from test_title_fade_contract import runtime, braced
from native32_support import RUNTIME_C, ENTRY_C
from recovery import ROWS

def parts():
 text=(ROOT/'src/promoted/code1_0012.c').read_text()
 body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
 palette=re.search(r'typedef struct \{ u32 words\[6\]; \} TitlePalette;',text)[0]
 check=re.search(r'typedef char TitlePaletteSizeCheck[^;]+;',text)[0]
 helper=braced(text,text.index('static inline void titlePaletteCopy('))
 blocks=[];declarations=[]
 for row in ROWS:
  ordinal,*_=row;index,selected=row[-2:]
  start=body.index(ordinal+'Palette = D_005E5530;')
  anchor='titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);'
  stop=body.index(anchor,start)+len(anchor)
  block=body[start:stop]
  for kind in ('Palette','Highlight','Base'):
   declarations.append(re.search(r'(?m)^    TitlePalette '+ordinal+kind+r';',body)[0].strip())
  base=ordinal+'Base.words['+index+']'
  assert body.count('('+base+' & ~0xFF) | 0xFF')==1
  blocks.append(dict(ordinal=ordinal,index=index,selected=selected,block=block,base='('+base+' & ~0xFF) | 0xFF'))
 assert body.count('titlePaletteCopy(')==10 and 'extern u8 *sp;' not in body and '+ sp)' not in body
 local_names=sorted({n for row in blocks for n in re.findall(r'\b(?:temp|var)_\w+\b',row['block'])})
 locals_='\n'.join(re.search(r'(?m)^    (?:s32|u32|f32|u8) \*?'+name+r';',body)[0].strip() for name in local_names)
 return palette,check,helper,declarations,locals_,blocks

def fixture(mutation=None):
 palette,check,helper,decls,locals_,blocks=parts()
 if mutation and mutation.startswith('helper_'):
  old,new={'helper_short':('s32 count = 3;','s32 count = 2;'),
   'helper_wrong_source_stride':('src += 2;','src += 1;'),
   'helper_wrong_destination_stride':('dst += 2;','dst += 1;'),
   'helper_second_word':('s32 second = src[1];','s32 second = src[0];')}[mutation]
  assert helper.count(old)==1;helper=helper.replace(old,new)
 names=[re.search(r'TitlePalette (\w+);',d)[1] for d in decls]
 guards='\n'.join('struct { u32 before[4]; '+d+' u32 after[4]; } guard_'+n+';' for n,d in zip(names,decls))
 macros='\n'.join('#define '+n+' guard_'+n+'.'+n for n in names)
 pointers=','.join('&'+n for n in names)
 before=','.join('guard_'+n+'.before' for n in names);after=','.join('guard_'+n+'.after' for n in names)
 generated=[]
 for group,row in enumerate(blocks):
  ordinal,index,selected=row['ordinal'],row['index'],row['selected'];block=row['block'];base=row['base']
  # Instrument storage boundaries; these observer calls are NOT present in production.
  snap=ordinal+'Palette = D_005E5530;'
  block=block.replace(snap,snap+'\n observe_snapshot('+str(group)+');',1)
  high='titlePaletteCopy(&'+ordinal+'Highlight, &'+ordinal+'Palette);'
  block=block.replace(high,high+'\n observe_highlight('+str(group)+');',1)
  block=block.replace('titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);',
   'titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);\n observe_base('+str(group)+');',1)
  if mutation and mutation.startswith('site_'):
   _,number,kind=mutation.split('_')
   if int(number)==group:
    if kind=='copy':block=block.replace('titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);','(void)0;')
    elif kind=='highlight':block=block.replace(ordinal+'Highlight.words['+index+']',ordinal+'Highlight.words[('+index+' + 1) % 6]')
    elif kind=='base':base=base.replace('['+index+']','[('+index+' + 1) % 6]')
    elif kind=='snapshot':block=block.replace(ordinal+'Palette = D_005E5530;','(void)0;')
    elif kind=='global':block=block.replace('titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);','titlePaletteCopy(&'+ordinal+'Base, &D_005E5530);')
    elif kind=='alias':block=block.replace('titlePaletteCopy(&'+ordinal+'Base, &'+ordinal+'Palette);','titlePaletteCopy(&'+ordinal+'Palette, &'+ordinal+'Palette);')
  generated.append('case '+str(group)+': { '+block+'\n selected_boundary('+selected+', '+base+'); break; }')
 return RUNTIME_C+r'''
typedef unsigned char u8; typedef unsigned u32; typedef int s32; typedef float f32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
'''+palette+'\n'+check+'\n'+helper+'\n'+r'''
#define CHECK(x) do { if (!(x)) native32_failure(__LINE__,scenario,#x); } while (0)
static unsigned scenario, mode, selected_index, active_group;
static u32 expected[6], seen_highlight, expected_base, checks;
static u32 table[190];
#define D_005E5230 table[0]
static s32 D_005E538C, D_005E53B4;
static TitlePalette D_005E5530;
static TitlePalette *objects[15];
static void observe_snapshot(unsigned group) {
 CHECK(group==active_group); ++checks;
 CHECK(!memcmp(objects[group*3],expected,24));
 if(mode&1) for(unsigned i=0;i<6;++i) D_005E5530.words[i]^=0x13a7f05d;
}
static void observe_highlight(unsigned group) {
 CHECK(!memcmp(objects[group*3],expected,24));
 CHECK(!memcmp(objects[group*3+1],expected,24)); ++checks;
 if(mode&2) for(unsigned i=0;i<6;++i) objects[group*3+1]->words[i]^=0x87395abc;
 seen_highlight=objects[group*3+1]->words[selected_index];
}
static void observe_base(unsigned group) {
 CHECK(!memcmp(objects[group*3],expected,24));
 CHECK(!memcmp(objects[group*3+2],expected,24)); ++checks;
 CHECK(objects[group*3+1]->words[selected_index]==seen_highlight);
 expected_base=(expected[selected_index]&0xffffff00)|255;
}
static void selected_boundary(u32 highlight,u32 base) {
 CHECK(checks==3); CHECK(highlight==seen_highlight); CHECK(base==expected_base);
}
static void run_case(void) {
'''+guards+'\n'+macros+'\n'+locals_+'\n'+r'''
 TitlePalette *local_objects[15]={'''+pointers+r'''};
 u32 *before[15]={'''+before+r'''};
 u32 *after[15]={'''+after+r'''};
 for(unsigned i=0;i<15;++i) {
  objects[i]=local_objects[i];
  for(unsigned j=0;j<4;++j) before[i][j]=after[i][j]=0xd1570000+i*16+j;
  for(unsigned j=0;j<6;++j) objects[i]->words[j]=0xa4e9105c+i*256+j;
 }
 for(unsigned i=0;i<15;++i) for(unsigned j=0;j<i;++j) CHECK(objects[i]!=objects[j]);
 for(unsigned i=0;i<6;++i) D_005E5530.words[i]=expected[i];
 for(unsigned i=0;i<190;++i) table[i]=0;
 table[17]=selected_index; /* 40-byte record 1, palette field +28 */
 D_005E538C=D_005E53B4=selected_index;
 var_19=var_17_2=var_16=1; temp_f20=0.3125f;
 checks=0;
 switch(active_group) {
'''+ '\n'.join(generated)+r'''
 }
 for(unsigned i=0;i<15;++i) {
  for(unsigned j=0;j<4;++j) CHECK(before[i][j]==0xd1570000+i*16+j && after[i][j]==before[i][j]);
  if(i/3!=active_group) for(unsigned j=0;j<6;++j) CHECK(objects[i]->words[j]==0xa4e9105c+i*256+j);
 }
 CHECK(!memcmp(objects[active_group*3],expected,24));
 CHECK(!memcmp(objects[active_group*3+2],expected,24));
}
int main(void) {
 static const u32 retail[6]={0xffffffff,0xffff81ff,0xffc705ff,0xffff64ff,0xff0000ff,0xffd518ff};
 for(active_group=0;active_group<5;++active_group)
 for(selected_index=0;selected_index<6;++selected_index)
 for(mode=0;mode<4;++mode)
 for(unsigned pattern=0;pattern<1025;++pattern) {
  for(unsigned word=0;word<6;++word) {
   if(!pattern) expected[word]=retail[word];
   else { unsigned channel=(pattern-1)/256, byte=(pattern-1)%256;
    expected[word]=0x96c31547+word*0x112233;
    expected[word]=(expected[word]&~(255u<<(channel*8)))|(((byte+word*37)&255)<<(channel*8)); }
  }
  ++scenario;run_case();
 }
 native32_number(scenario);native32_text(" title palette storage cases passed\n");return 0;
}
'''+ENTRY_C

class TitlePaletteStorage(unittest.TestCase):
 def test_live_extraction(self):
  p=parts();self.assertEqual(len(p[-1]),5)
  for row in p[-1]:self.assertIn(row['base'],fixture())
  self.assertNotIn('func_00124bb0(',fixture())
 def execute(self,opt,mutation=None):
  with tempfile.TemporaryDirectory(prefix='p4_palette_') as tmp:
   path=Path(tmp);src=path/'test.c';src.write_text(fixture(mutation));rt=runtime()
   return rt.run(rt.compile(src,path/'test',opt))
 def test_all_complete_snapshots_copies_and_selections(self):
  for opt in ('-O0','-O2'):
   with self.subTest(opt=opt):
    result=self.execute(opt);self.assertEqual(result.returncode,0,result.stdout+result.stderr)
    self.assertEqual(result.stdout,'123000 title palette storage cases passed\n');print(opt,result.stdout.strip())
 def test_independent_negative_controls(self):
  mutations=['helper_short','helper_wrong_source_stride','helper_wrong_destination_stride','helper_second_word']
  mutations += ['site_'+str(i)+'_'+kind for i in range(5) for kind in ('copy','highlight','base','snapshot','global','alias')]
  for mutation in mutations:
   with self.subTest(mutation=mutation):
    result=self.execute('-O2',mutation);self.assertNotEqual(result.returncode,0,result.stdout+result.stderr)
    self.assertIn('scenario',result.stdout);print(mutation+': rejected: '+result.stdout.strip())
if __name__=='__main__':unittest.main()
