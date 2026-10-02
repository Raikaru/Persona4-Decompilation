from pathlib import Path
import sys,json,struct,re
sys.path.insert(0,'tools');import verify as V,fnalign as F,recovery_quality as Q
cfg=V.load_config();ret=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),V._read_json(V.FUNCTION_WINDOWS)['sha1'])
obj=V.ObjectFile(Path('build/community/origin-projection/production-candidate.o'));rows=[]
for name,address in [('func_00356250',0x356250),('func_0035e8b0',0x35e8b0),('func_00356a10',0x356a10)]:
 code,refs=obj.function(name);raw=ret.bytes_at(address,len(code));selected=[]
 for i in range(0,len(raw),4):
  w=struct.unpack_from('<I',raw,i)[0];op=w>>26;rs=(w>>21)&31;rt=(w>>16)&31;imm=w&65535
  if(name!='func_00356a10'and op==43 and rs!=29 and rt==0 and imm in(4,8))or(name=='func_00356a10'and op==49 and rs!=29 and imm in(4,8)):
   d=F.disassemble(raw[i:i+4],address+i);assert d;selected.append({'address':hex(address+i),'instruction':d,'word':raw[i:i+4].hex()})
 assert len(selected)==2
 rows.append({'function':name,'retail_address':hex(address),'bytes':len(code),'selected_offset_4_8_accesses':selected})
bodies=Q.function_bodies(Path('src/promoted/code1_0035.c'));text=bodies['func_00356a10'][1]
readbacks=[re.search(r'\b'+n+r' = \(?menu->origin\.[xy]\)?;',text).group(0)for n in ['originX','originY']]
report={'retail_accesses':rows,'matched_renderer_actual_readbacks':readbacks,'constructor_call_from_controller':bodies['func_0035e8b0'][1].count('func_00356250(arg2);'),'scope':'The two initializer paths and matched renderer origin reads; other menu fields and dispatch callbacks are excluded.'}
out=Path('build/community/origin-projection');(out/'producer-reader-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
