"""Exact bounded palette-only source transformation from the frozen checkpoint."""
import re
BASE='bed91675c50af703b974bd44ede3234eef532590'
OWNER='src/promoted/code1_0012.c'
ROWS=[
 ('first','sp130','sp140','sp450','sp430','var_6','var_6_2','var_5_2','var_5_3','var_4_3','var_4_4','temp_9','temp_8'),
 ('second','sp110','sp120','sp1B0','sp190','var_6_4','var_6_5','var_5_4','var_5_5','var_4_5','var_4_6','temp_9_4','temp_8_2'),
 ('third','spF0','sp100','sp410','sp3F0','var_6_7','var_6_8','var_5_6','var_5_7','var_4_10','var_4_11','temp_8_3','temp_7_3'),
 ('fourth','spD0','spE0','sp3D0','sp3B0','var_6_10','var_6_11','var_5_8','var_5_9','var_4_12','var_4_13','temp_8_5','temp_7_4'),
 ('fifth','spB0','spC0','sp170','sp150','var_6_13','var_6_14','var_5_16','var_5_17','var_4_14','var_4_15','temp_9_7','temp_8_7')]
def transform(text):
 before,body=text.split('void func_001265a0(s32 arg1) {',1)
 body,after=body.split('\n#else\nINCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);',1)
 body=body.replace('    extern s128 D_005E5530;\n    extern s64 D_005E5540;', '    extern TitlePalette D_005E5530;')
 body=body.replace('    extern u8 *sp;\n','')
 dead=[]
 for ordinal,source,tail,high,base,c1,c2,d1,d2,n1,n2,index,selected in ROWS:
  names={source:ordinal+'Palette',high:ordinal+'Highlight',base:ordinal+'Base'}
  body=body.replace('    s64 '+tail+';\n','')
  for old,new in names.items():
   body,count=re.subn(r'    (?:s128|M2C_UNK) '+old+r';', '    TitlePalette '+new+';',body);assert count==1
  for cursor,dest,countvar,destination in [(c1,d1,n1,high),(c2,d2,n2,base)]:
   pat=r'(?m)^( +)'+cursor+r' = \(s128 \*\)\(&'+source+r'\);\n.*?\} while \('+countvar+r' > 0\);'
   m=re.search(pat,body,re.S);assert m,(cursor,source)
   snippet=m[0];indent=m[1]
   assert snippet.count('do {')==1
   dead+=re.findall(r'\b(temp_\w+) = \(s32\)\(M2C_FIELD\('+cursor+r',',snippet)
   replacement=(indent+names[source]+' = D_005E5530;\n' if cursor==c1 else '')+indent+'titlePaletteCopy(&'+names[destination]+', &'+names[source]+');'
   body=body[:m.start()]+replacement+body[m.end():]
   dead += [cursor,dest,countvar]
  for old in [high,base]:
   pat=r'M2C_FIELD\(\('+index+r' \+ sp\), (?:u32|s32) \*, 0x'+old[2:]+r'\)'
   body,count=re.subn(pat,names[old]+'.words['+index+']',body);assert count==1,(old,count)
  # The former byte offset now indexes complete words in an actual local palette.
  pat=r'(?m)^( +'+index+r' = )([^;]+) \* 4(\);|;)'
  m=re.search(pat,body);assert m,index
  body=body[:m.start()]+m[1]+m[2]+m[3]+body[m.end():]
 for name in dead:
  assert len(re.findall(r'\b'+name+r'\b',body))==1,name
  body,count=re.subn(r'(?m)^    (?:s128|M2C_UNK|s32) \*?'+name+r';\n','',body);assert count==1,name
 # Document the intentionally bounded endpoint beside the first snapshot.
 anchor='                                firstPalette = D_005E5530;'
 body=body.replace(anchor,'                                /* Six packed colors form one snapshot and two independent copies.\n                                 * The model-draw ABI/ACC expressions below remain unrecovered. */\n'+anchor,1)
 return before+'void func_001265a0(s32 arg1) {'+body+'\n#else\nINCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);'+after
