#!/usr/bin/env python3
"""Check or refresh only seven independently recovered data bindings."""
from pathlib import Path
import argparse
import re

ROOT = Path(__file__).resolve().parents[2]
EXPECTED = {
    'fGpffff841c': 0x0076150c,
    'D_00763130': 0x00763130,
    'D_00763138': 0x00763138,
    'D_0076313C': 0x0076313c,
    'D_00763140': 0x00763140,
    'D_00763148': 0x00763148,
    'D_00764498': 0x00764498,
}
ENTRY = re.compile(r'^([A-Za-z_.$][\w.$]*) = (0x[0-9a-fA-F]{8}); // type:data$')
SELECTED = re.compile(r'^\s*(' + '|'.join(re.escape(name) for name in EXPECTED) + r')\b')

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--generated', type=Path, required=True,
                        help='Complete output from tools/recover_symbols.py --print')
    parser.add_argument('--write', action='store_true',
                        help='Insert only missing reviewed rows; preserve all existing rows')
    args = parser.parse_args()
    generated = {}
    for line in args.generated.read_text(encoding='utf-8').splitlines():
        match = ENTRY.fullmatch(line)
        if SELECTED.match(line) and not match:
            raise SystemExit('Noncanonical selected symbol in generated input')
        if match and match[1] in EXPECTED:
            if match[1] in generated:
                raise SystemExit('Duplicate generated symbol: ' + match[1])
            generated[match[1]] = int(match[2], 16)
    if generated != EXPECTED:
        raise SystemExit('Generator did not independently recover the seven expected bindings')
    path = ROOT / 'config/symbols_recovered.txt'
    original = path.read_bytes()
    lines = original.decode('utf-8').splitlines(keepends=True)
    newline = '\r\n' if lines and lines[0].endswith('\r\n') else '\n'
    for line in lines:
        text = line.rstrip('\r\n')
        if SELECTED.match(text) and not ENTRY.fullmatch(text):
            raise SystemExit('Noncanonical selected symbol in existing table')
    added = []
    for name, address in sorted(EXPECTED.items(), key=lambda item: (item[1], item[0])):
        matches = [line for line in lines if re.match(r'^' + re.escape(name) + r'\s*=', line)]
        desired_text = f'{name} = {address:#010x}; // type:data'
        desired = desired_text + newline
        if matches:
            if len(matches) != 1 or matches[0].rstrip('\r\n') != desired_text:
                raise SystemExit('Existing binding differs: ' + name)
            continue
        if not args.write:
            raise SystemExit('Missing recovered binding: ' + name)
        index = len(lines)
        for i, line in enumerate(lines):
            match = ENTRY.fullmatch(line.rstrip('\r\n'))
            if match and (int(match[2], 16), match[1]) > (address, name):
                index = i
                break
        if index == len(lines) and lines and not lines[-1].endswith('\n'):
            raise SystemExit('Cannot append after an unterminated final table line')
        lines.insert(index, desired)
        added.append(desired)
    if args.write:
        remaining = list(lines)
        for line in added:
            remaining.remove(line)
        if ''.join(remaining).encode('utf-8') != original:
            raise SystemExit('Unrelated table bytes changed')
        path.write_bytes(''.join(lines).encode('utf-8'))
    print(f'Verified all seven generated bindings; inserted {len(added)} rows')

if __name__ == '__main__':
    main()
