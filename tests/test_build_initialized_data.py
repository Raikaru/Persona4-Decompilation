"""Native ELF cases for data objects reached through actual pointer tables."""
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import build
import gnu_link
from elf_text_runs import Section, Symbol, serialize


def words(*values):
    return struct.pack('<' + 'I' * len(values), *values)


def fixture(directory, *, pointer_kind=2, duplicate=False, bad_offset=False,
            unanchored=False, conflict=False, code_conflict=False, cycle=False,
            wrong_literal=False, wrong_pointer=False, short_target=False,
            overlap=False, rela=False, executable=False):
    body = words(0x3c040000, 0x24840000, 0x3c050000, 0x24a50000, 0x03e00008, 0)
    actual = words(0x3c040010, 0x24841000, 0x3c050010, 0x24a51080, 0x03e00008, 0)
    code_refs = [(0, 1, 5), (4, 1, 6), (8, 4, 5), (12, 4, 6)]
    if conflict or code_conflict:
        body = body[:-8] + words(0x3c060000, 0x24c60000, 0x03e00008, 0)
        target_index = 1 if code_conflict else 2
        # A direct reference to the interior symbol is four bytes away from
        # the pointer-derived address; conflicting evidence must fail closed.
        direct = 0x101004 if code_conflict else 0x102006
        actual = actual[:-8] + words(0x3c060000 | ((direct + 0x8000) >> 16),
                                    0x24c60000 | (direct & 0xffff), 0x03e00008, 0)
        code_refs.extend([(16, target_index, 5), (20, target_index, 6)])
    sections = [Section('', 0, align=0), Section('.symtab', 2, align=4, entsize=16, link=2),
                Section('.strtab', 3), Section('.shstrtab', 3),
                Section('.text', 1, 6, data=body, size=len(body), align=4),
                Section('.data', 1, 7 if executable else 3,
                        data=words(1, 0x12345678, 0, 0), size=16, align=4),
                Section('.data', 1, 3, data=b'ABfilename\0\0', size=12, align=4),
                Section('.data', 1, 3, data=words(0), size=4, align=4),
                Section('.data', 1, 3, data=b'tail\0\0\0\0', size=8, align=4),
                Section('.sdata', 1, 3, data=b'root\0\0\0\0', size=8, align=4)]
    symbols = [Symbol('', 0, 0, 0, 0, 0), Symbol('table', 0, 16, 1, 0, 5),
               Symbol('filename', 2, 8, 1, 0, 6), Symbol('box', 0, 4, 1, 0, 7),
               Symbol('tail', 0, 8, 1, 0, 8), Symbol('root', 0, 8, 1, 0, 9),
               Symbol('unit', 0, len(body), 0x12, 0, 4), Symbol('callback', 0, 0, 0x12, 0, 0)]

    def relocation_section(name, target, rows, explicit_addend=False):
        payload = b''.join(words(offset, (symbol << 8) | kind, 0) if explicit_addend
                           else words(offset, (symbol << 8) | kind)
                           for offset, symbol, kind in rows)
        return Section(name, 4 if explicit_addend else 9, data=payload, size=len(payload),
                       align=4, entsize=12 if explicit_addend else 8, link=1, info=target)

    if unanchored:
        code_refs = [(offset, symbol, kind) for offset, symbol, kind in code_refs if symbol != 1]
    sections.append(relocation_section('.rel.text', 4, code_refs))
    table_refs = [(1 if bad_offset else 0, 2, pointer_kind), (8, 3, 2), (12, 7, 2)]
    if duplicate:
        table_refs.append((0, 2, 2))
    sections.append(relocation_section('.rel.data', 5, table_refs, rela))
    sections.append(relocation_section('.rel.data', 7, [(0, 1 if cycle else 5, 2)]))
    path = Path(directory) / 'owner.o'
    path.write_bytes(serialize(b'\x7fELF\x01\x01\x01' + bytes(9), 0x20924001,
                              sections, symbols, 1, 2, 3))
    obj = build.V.ObjectFile(path)
    box_address = 0x101008 if overlap else 0x102100
    memory = {0x100000: actual,
              0x101000: words(0x102003, 0x12345679 if wrong_literal else 0x12345678,
                             box_address, 0x100104 if wrong_pointer else 0x100100),
              0x101080: b'tail\0\0\0\0', 0x102000: b'ABfilename\0\0',
              box_address: words(0x101000 if cycle else 0x103000), 0x103000: b'root\0\0\0\0'}
    if short_target:
        memory[0x102000] = memory[0x102000][:-1]
    retail = mock.Mock()
    retail.bytes_at.side_effect = lambda address, size: memory[address][:size]
    real = [{'name': 'unit', 'addr': 0x100000}]
    return path, obj, real, retail


def plan(obj, real, retail, **options):
    return build.plan_data_sections(obj, real, retail, 0, {'callback'},
                                   symbol_addresses={'callback': 0x100100}, **options)


class InitializedDataTests(unittest.TestCase):
    def test_pointer_tables_recover_real_local_offsets_addends_and_a_second_hop(self):
        with tempfile.TemporaryDirectory() as temporary:
            _path, obj, real, retail = fixture(temporary)
            self.assertEqual(build.recover_section_bases(obj, real, retail, 0), {5: 0x101000, 8: 0x101080})
            self.assertEqual(build.recover_pointer_data_bases(obj, real, retail, 0),
                             {5: 0x101000, 8: 0x101080, 6: 0x102000, 7: 0x102100, 9: 0x103000})
            self.assertEqual(plan(obj, real, retail), (False, {}))
            self.assertEqual(plan(obj, real, retail, independent_bss=True), (False, {}))
            self.assertEqual(plan(obj, real, retail, independent_initialized=True),
                             (True, {'.data.p4_5': (0x101000, 16), '.data.p4_6': (0x102000, 12),
                                     '.data.p4_7': (0x102100, 4), '.data.p4_8': (0x101080, 8),
                                     '.sdata': (0x103000, 8)}))

    def test_unanchored_cycles_contradictions_and_nonretail_payloads_are_rejected(self):
        cases = [{'unanchored': True, 'cycle': True}, {'conflict': True}, {'code_conflict': True},
                 {'wrong_literal': True}, {'wrong_pointer': True}, {'short_target': True},
                 {'overlap': True}, {'executable': True}]
        with tempfile.TemporaryDirectory() as temporary:
            for options in cases:
                with self.subTest(options=options):
                    _path, obj, real, retail = fixture(temporary, **options)
                    self.assertEqual(plan(obj, real, retail, independent_initialized=True), (False, {}))

    def test_a_cycle_with_a_real_code_anchor_can_be_proven(self):
        with tempfile.TemporaryDirectory() as temporary:
            _path, obj, real, retail = fixture(temporary, cycle=True)
            bases = build.recover_pointer_data_bases(obj, real, retail, 0)
            self.assertEqual(bases[7], 0x102100)
            # The unrelated unreferenced leaf is deliberately not invented.
            self.assertNotIn(9, bases)
            self.assertEqual(plan(obj, real, retail, independent_initialized=True), (False, {}))

    def test_unknown_external_and_malformed_relocation_shapes_are_rejected(self):
        cases = [{'pointer_kind': 5}, {'duplicate': True}, {'bad_offset': True}, {'rela': True}]
        with tempfile.TemporaryDirectory() as temporary:
            for options in cases:
                with self.subTest(options=options):
                    _path, obj, real, retail = fixture(temporary, **options)
                    self.assertIsNone(build.recover_pointer_data_bases(obj, real, retail, 0))
            _path, obj, real, retail = fixture(temporary)
            self.assertEqual(build.plan_data_sections(obj, real, retail, 0, set(),
                              independent_initialized=True), (False, {}))

    def test_prepared_native_input_preserves_pointers_and_places_every_allocated_byte(self):
        with tempfile.TemporaryDirectory() as temporary:
            path, obj, real, retail = fixture(temporary)
            accepted, sections = plan(obj, real, retail, independent_initialized=True)
            self.assertTrue(accepted)
            owner = {'ranges': [(0x100000, 0x100020)], 'funcs': real, 'sections': sections,
                     'initialized_data_fingerprints': {name: build.initialized_data_fingerprint(
                         obj, obj.sh[int(name.rsplit('_', 1)[1], 16)])
                         for name in sections if '.p4_' in name}}
            objects, entries = build.prepare_link_objects(path, owner, 'gnu')
            after = build.V.ObjectFile(path)
            self.assertEqual(after.symbols, obj.symbols)
            self.assertEqual(after.function('unit'), obj.function('unit'))
            for index in (5, 7):
                self.assertEqual(build.section_relocs(after, index), build.section_relocs(obj, index))
                self.assertEqual(after.data[after.sh[index]['offset']:after.sh[index]['offset'] + after.sh[index]['size']],
                                 obj.data[obj.sh[index]['offset']:obj.sh[index]['offset'] + obj.sh[index]['size']])
            validated = gnu_link.validate_inputs(entries, objects, 0x100000, 0x10000)
            self.assertEqual(validated.functions, [('unit', 0x100000, 24)])
            self.assertEqual(len(entries), 6)

    def test_changed_payload_or_pointer_target_after_eligibility_is_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            for variant in ('bytes', 'relocation'):
                with self.subTest(variant=variant):
                    path, obj, real, retail = fixture(temporary)
                    accepted, sections = plan(obj, real, retail, independent_initialized=True)
                    self.assertTrue(accepted)
                    owner = {'ranges': [(0x100000, 0x100020)], 'funcs': real, 'sections': sections,
                             'initialized_data_fingerprints': {name: build.initialized_data_fingerprint(
                                 obj, obj.sh[int(name.rsplit('_', 1)[1], 16)])
                                 for name in sections if '.p4_' in name}}
                    changed = bytearray(path.read_bytes())
                    if variant == 'bytes':
                        changed[obj.sh[5]['offset'] + 4] ^= 1
                    else:
                        relocation = next(section for section in obj.sh
                                          if section['type'] == 9 and section.get('info') == 5)
                        struct.pack_into('<I', changed, relocation['offset'] + 4, (3 << 8) | 2)
                    path.write_bytes(changed)
                    with self.assertRaisesRegex(ValueError, 'payload or relocations changed'):
                        build.prepare_link_objects(path, owner, 'gnu')


if __name__ == '__main__':
    unittest.main()
