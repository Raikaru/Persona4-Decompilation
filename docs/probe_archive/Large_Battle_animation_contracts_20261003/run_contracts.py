"""Run focused contracts natively, or with --runner /path/to/qemu-i386."""
from pathlib import Path
import argparse
import shutil
import sys
import unittest
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'tests'))
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--runner', help='existing i386 Linux executable runner')
args = parser.parse_args()
if args.runner:
    import native32_support as native
    compiler, linker, runner = shutil.which('clang'), shutil.which('ld'), shutil.which(args.runner)
    if not all((compiler, linker, runner)):
        parser.error('Clang, GNU ld and the requested runner must already be available')
    runtime = native.Native32Runtime(compiler, (linker,), (runner,), False)
    native.native32_runtime = lambda: runtime
import test_large_battle_animation_contracts
import test_btl_motion_override_contract
import test_btl_opening_identifier_contracts
suite = unittest.TestSuite(unittest.defaultTestLoader.loadTestsFromModule(module)
                           for module in (test_large_battle_animation_contracts,
                                          test_btl_motion_override_contract,
                                          test_btl_opening_identifier_contracts))
result = unittest.TextTestRunner(verbosity=2).run(suite)
if result.skipped:
    print('Runtime skips are unverified, not executed passes', file=sys.stderr)
sys.exit(not result.wasSuccessful() or bool(result.skipped))
