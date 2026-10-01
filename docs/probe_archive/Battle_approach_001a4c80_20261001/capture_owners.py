"""Capture nine complete configured owners, without linking.

Usage: python capture_owners.py CHECKOUT OUTPUT
Use an unmodified checkout of the recorded baseline, then the publication tree.
Compiler, assembler and retail inputs must already be configured.
"""
import sys,json,hashlib
from pathlib import Path
root=Path(sys.argv[1]);out=Path(sys.argv[2]);out.mkdir(parents=True,exist_ok=True);sys.path.insert(0,str(root/'tools'))
import verify as V
owners=['src/promoted/code1_001a.c','src/promoted/code1_0019.c','src/promoted/code1_001f.c','src/promoted/code1_0022.c','src/promoted/code1_001b.c','src/promoted/code1_001c.c','src/Battle/btlCamera.c','src/Battle/btlUnit.c','src/Battle/btlFormation.c']
for owner in owners:
 source=root/owner;obj,log=V.compile_object(source,V.load_config(),out)
 (out/(Path(owner).stem+'.log')).write_text(log)
 assert obj is not None,(owner,log)
 (out/(Path(owner).stem+'.o')).write_bytes(obj.data)
 print(owner,len(V.scan_markers(source)),flush=True)
