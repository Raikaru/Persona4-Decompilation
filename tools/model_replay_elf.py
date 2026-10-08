"""Reviewed MIPS relocation resolver used by the Model00471370 replay.

The refs/resolve function bodies are unchanged from the independently reviewed
2026-10-07 source replay. Runtime symbol values, verifier and gp are supplied
by the driver; no private bytes or duplicate symbol table is stored here.
"""
from collections import defaultdict
import struct

def refs(obj,index):
 out=[]
 for s in obj.sections:
  if s['type']!=9 or s['info']!=index:continue
  for p in range(s['offset'],s['offset']+s['size'],s['entsize'] or 8):
   off,info=struct.unpack_from('<II',obj.data,p);sym=obj.symtabs[s['link']][info>>8]
   out.append(dict(offset=off,r_type=info&255,symbol=sym['name'],target_section=sym['shndx'],target_value=sym['value']))
 return out

def resolve(obj,raw,rs,bases,overrides=None):
 vals=dict(values);vals.update(overrides or {});out=bytearray(raw);pending=defaultdict(list);rows=[]
 byname={s['name']:s for s in obj.symbols if s['name']}
 for r in rs:
  off,kind,name=r['offset'],r['r_type'],r.get('symbol') or '';sym=byname.get(name)
  address=V.resolve_symbol(name,gp,vals)
  if address is None and sym and sym['shndx'] in bases:address=bases[sym['shndx']]+sym['value']
  if address is None and r.get('target_section') in bases:address=bases[r['target_section']]+r.get('target_value',0)
  row=dict(r,address=address);rows.append(row)
  if address is None:row['error']='unresolved';continue
  w=struct.unpack_from('<I',raw,off)[0];signed=(w&32767)-(w&32768);key=(name,address,r.get('target_section') if not name else None)
  if kind==4:
   add=(w&0x3ffffff)<<2;val=address+add
   if val%4 or val>>28:row['error']='J26 out of range';continue
   word=w&0xfc000000|(val>>2)&0x3ffffff
  elif kind==5:pending[key].append((off,w,row));continue
  elif kind==6:
   highs=pending.pop(key,[])
   if not highs:row['error']='unpaired LO16';continue
   for hi,hw,hr in highs:
    add=((hw&65535)<<16)+signed;val=address+add
    struct.pack_into('<I',out,hi,hw&0xffff0000|((val+32768)>>16)&65535);hr.update(addend=add,resolved=val)
   word=w&0xffff0000|val&65535
  elif kind in (7,8):
   add=signed;val=address+add;disp=val-gp
   if not -32768<=disp<32768:row['error']='GP out of range';continue
   word=w&0xffff0000|disp&65535
  elif kind==2:add=w;val=address+add;word=val&0xffffffff
  else:row['error']='unsupported relocation';continue
  struct.pack_into('<I',out,off,word);row.update(addend=add,resolved=val)
 for group in pending.values():
  for _,_,r in group:r['error']='unpaired HI16'
 return bytes(out),rows
