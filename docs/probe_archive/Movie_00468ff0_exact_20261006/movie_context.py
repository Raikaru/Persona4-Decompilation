from pathlib import Path
import hashlib
import sys
ROOT = next(p for p in Path(__file__).resolve().parents if (p / 'tools/verify.py').is_file())
OUT = Path(__file__).resolve().parent
OWNER = ROOT / 'src/promoted/code1_0046.c'
NAME = 'func_00468ff0'
ADDR = 0x468ff0
sys.path.insert(0, str(ROOT / 'tools'))
import verify as V
CFG = V.load_config()
WINDOWS = V._read_json(V.FUNCTION_WINDOWS)
RETAIL = V.RetailElf(CFG['retail_elf'], V._read_json(V.TARGET), WINDOWS['sha1'])
TARGET = RETAIL.bytes_at(ADDR, WINDOWS['windows']['00468ff0'])
def sha(data):
    return hashlib.sha256(data).hexdigest()
