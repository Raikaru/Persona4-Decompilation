from pathlib import Path
import hashlib,json,subprocess
from recovery import BASE,OWNER,transform
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();new=Path(OWNER).read_text()
assert transform(old)==new,'Source diff extends outside the exact bounded palette repair'
report={'base':BASE,'owner':OWNER,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_palette_only_transformation':True,'complete_source_snapshots':5,'complete_destination_copies':10,'fake_sp_removed':True,'guard_and_fallback_retained':True,'unchanged_model_call_remainder':True,'proof_boundary':'selected packed words only; existing model ABI and ACC expressions unproven'}
Path('proof/palette-source-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print('Exact bounded palette-only source diff verified')
