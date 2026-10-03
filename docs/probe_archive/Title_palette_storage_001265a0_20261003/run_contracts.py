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
import test_title_palette_storage
import test_title_sprite_alpha_contract
import test_title_fade_contract
import test_title_gp_color_transport
import test_title_alpha_aliases
import test_title_rectangle_aliases
import test_title_color_families
import test_title_layer_contract
import test_title_color_storage
import test_title_overlay_contract
suite = unittest.TestSuite(unittest.defaultTestLoader.loadTestsFromModule(module)
                           for module in (test_title_palette_storage, test_title_sprite_alpha_contract,
                                          test_title_fade_contract,
                                          test_title_gp_color_transport,
                                          test_title_alpha_aliases,
                                          test_title_rectangle_aliases,
                                          test_title_color_families,
                                          test_title_layer_contract,
                                          test_title_color_storage,
                                          test_title_overlay_contract))
result = unittest.TextTestRunner(verbosity=2).run(suite)
if result.skipped:
    print('Runtime skips are unverified, not executed passes', file=sys.stderr)
sys.exit(not result.wasSuccessful() or bool(result.skipped))
