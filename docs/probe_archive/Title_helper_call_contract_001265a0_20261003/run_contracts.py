"""Run all 44 Title tests on real 32-bit pointers, failing on any skipped test."""
from pathlib import Path
import argparse,shutil,sys,unittest
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tests'))
p=argparse.ArgumentParser(description=__doc__);p.add_argument('--runner');args=p.parse_args()
if args.runner:
 import native32_support as native
 compiler,linker,runner=shutil.which('clang'),shutil.which('ld'),shutil.which(args.runner)
 if not all((compiler,linker,runner)):p.error('Clang, GNU ld and requested i386 runner must exist')
 rt=native.Native32Runtime(compiler,(linker,),(runner,),False)
 native.native32_runtime=lambda:rt
suite=unittest.defaultTestLoader.discover(str(ROOT/'tests'),pattern='test_title_*.py')
r=unittest.TextTestRunner(verbosity=2).run(suite)
assert r.testsRun==44,r.testsRun
sys.exit(not r.wasSuccessful() or bool(r.skipped))
