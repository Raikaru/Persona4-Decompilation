#!/usr/bin/env python3
"""Run the Persona alpha family contracts with an optional existing i386 runner."""
from pathlib import Path
import argparse,subprocess,sys,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tests'))
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--runner',type=Path)
args=parser.parse_args()
if args.runner:
    runner=args.runner.resolve()
    if not runner.is_file():parser.error('Runner does not exist: '+str(runner))
    import native32_support
    def run(self,executable):
        return subprocess.run([str(runner),str(executable)],capture_output=True,text=True,timeout=150)
    native32_support.Native32Runtime.run=run
suite=unittest.defaultTestLoader.loadTestsFromNames([
    'test_persona_task_renderer','test_persona_alpha_contract','test_persona_camp_alpha_contract'])
result=unittest.TextTestRunner(verbosity=2).run(suite)
if args.runner and result.skipped:sys.exit('Configured runner did not execute every fixture')
sys.exit(not result.wasSuccessful())
