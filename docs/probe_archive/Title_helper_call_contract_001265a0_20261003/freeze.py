"""Verify committed manifest bytes; write exact commit/tree/source identity locally."""
from pathlib import Path
import hashlib,json,subprocess
A=Path(__file__).resolve().parent;ROOT=Path.cwd().resolve()
def git(*args):return subprocess.check_output(['git',*args])
assert not git('diff','HEAD','--name-only'),'Tracked edits remain'
manifest=json.loads((A/'manifest.json').read_text())
for name,digest in manifest.items():
 assert not Path(name).is_absolute() and '..' not in Path(name).parts
 assert hashlib.sha256((ROOT/name).read_bytes()).hexdigest()==digest,name
 assert git('show','HEAD:'+name)==(ROOT/name).read_bytes(),name
assert git('show','HEAD:'+str((A/'manifest.json').relative_to(ROOT)))==(A/'manifest.json').read_bytes()
r={'commit':git('rev-parse','HEAD').decode().strip(),'tree':git('rev-parse','HEAD^{tree}').decode().strip(),'source_sha256':manifest['src/promoted/code1_0012.c'],'manifest_sha256':hashlib.sha256((A/'manifest.json').read_bytes()).hexdigest(),'all_manifest_files_committed_and_verified':True,'local_intermediates':'untracked proof/; excluded from source-only commit'}
Path('proof/helper-frozen-checkpoint.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
