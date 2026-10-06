"""Replay native initialization and ABI witnesses without modifying source."""
from __future__ import annotations
import hashlib
import struct

from movie_context import RETAIL, WINDOWS


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def native_words(address, count):
    return list(struct.unpack('<' + 'I' * count, RETAIL.bytes_at(address, count * 4)))


def stores(address, size, base_register):
    """Enumerate direct word/doubleword stores to an already reviewed output base."""
    result = []
    for index, word in enumerate(native_words(address, size // 4)):
        opcode, base = word >> 26, (word >> 21) & 31
        if base != base_register or opcode not in (43, 63):
            continue
        offset = (word & 0x7fff) - (word & 0x8000)
        result.append({'instruction': f'{address + index * 4:08x}',
                       'offset': offset, 'size': 4 if opcode == 43 else 8})
    return result


def check():
    table_address = 0x0070c220
    device = native_words(table_address, 14)
    assert device[:6] == [0x3f800000, 0x004010c0, 0x477fff00, 0,
                          0x003f5070, 0x003f5d90]
    # The registered handler saves a1 as the real output pointer in s0.
    assert native_words(0x003f5d9c, 1) == [0x00a0802d]
    comparison = native_words(0x003f5de8, 3)
    assert comparison == [0x2402000e, 0x10820111, 0]
    branch = comparison[1]
    assert 0x003f5dec + 4 + ((branch & 0x7fff) - (branch & 0x8000)) * 4 == 0x003f6234
    fog = native_words(0x003f6234, 5)
    assert fog == [0xdf82abe8, 0x30420020, 0x0002102b, 0x10000069, 0xae020000]
    assert native_words(0x003f63e8, 1) == [0x24020001]
    # Device registration copies seven eight-byte pairs from this exact table.
    registration = native_words(0x004011a4, 11)
    assert registration == [0x0c100514, 0, 0x24050007, 0x8c440000,
                            0x24a5ffff, 0x8c430004, 0xae240000,
                            0x24420008, 0xae230004, 0x1ca0fff9,
                            0x26310008]
    # On the successful frame path, s1 in 0050a3c0 is the output object.
    assert native_words(0x0050a3c8, 1) == [0x00c0882d]
    main_stores = stores(0x0050a49c, 0x0050a594 - 0x0050a49c, 17)
    coverage = set()
    for row in main_stores:
        coverage.update(range(row['offset'], row['offset'] + row['size']))
    assert coverage == set(range(0, 4)) | set(range(8, 0x44)) | set(range(0x4c, 0x88))
    assert native_words(0x0050a2e8, 1) == [0xae420004]
    # Every returning branch of the reviewed picture-user helper stores both
    # words; the alternate paths are visible at 0050a5dc..0050a614.
    picture = stores(0x0050a5dc, 0x0050a618 - 0x0050a5dc, 18)
    assert {r['offset'] for r in picture} == {0x44, 0x48}
    assert native_words(0x0050a5a8, 1) == [0x00c0902d]
    # The supplemental helper first initializes its two outputs and both local
    # result words before any conditional parser call, then may replace them.
    assert native_words(0x0050a818, 1) == [0x00c0802d]
    assert native_words(0x0050a820, 1) == [0xafa00000]
    assert native_words(0x0050a830, 1) == [0xafa00004]
    assert native_words(0x0050a838, 1) == [0xae000088]
    assert native_words(0x0050a840, 1) == [0xae00008c]
    coverage.update(range(4, 8))
    coverage.update(range(0x44, 0x4c))
    coverage.update(range(0x88, 0x90))
    assert coverage == set(range(0x90))
    # The null-display fast path writes buffer=0. The recovered caller only
    # reads/copies the remaining frame members when this field is nonzero.
    assert native_words(0x0050a24c, 1) == [0xae400000]
    functions = ['003f5d90', '004010c0', '00401450', '004623a0',
                 '00468fa0', '0046a110', '0046a1f0', '0050a1c0',
                 '0050a3c0', '0050a5a0', '0050a810']
    return {
        'engine_storage': '008872e0', 'engine_device_offset': 0x10,
        'device_table_address': f'{table_address:08x}',
        'device_table_sha256': digest(RETAIL.bytes_at(table_address, 56)),
        'native_getter': '003f5d90', 'fog_state': 14,
        'fog_result': 'A 32-bit 0/1 output is always stored at 003f6244 before success return.',
        'frame_size': 0x90, 'frame_direct_stores': main_stores,
        'frame_picture_helper_stores': picture,
        'frame_initialized_byte_count': len(coverage),
        'scope': 'Native instruction and reviewed control-flow witnesses for valid task/player interfaces; not a claim about arbitrary corrupted work or external decoder state.',
        'source_contracts': {
            'work': '0046a110 and 0046a1f0 allocate H_Calloc(1,0x220); 00468fa0 stores callback/work; 004623a0 supplies work in a1.',
            'frame': '0050a3c0 fills all copied words/doublewords, with 0050a5a0 for offsets44/48, 0050a810 for88/8c and caller0050a1c0 for04. Null-buffer paths are not copied.',
            'vertex': 'The 0x40-byte, quadword-aligned nested layout is the actual sky2 RwSky2DVertex, not a smaller Im2D variant. The calloc work initializes padding/unconsumed members.',
            'rgba': 'RwIm2DVertexSetIntRGBA casts each channel directly to RwReal; fade-in alpha is a produced unsigned byte.',
            'globals': 'ourGlobals is the SDK RwUInt32[4096] backing store under RWGLOBALSIZE; the typed prefix matches camera/world, four halfwords, then the real RwDevice.',
            'decoder_address': 'Native work+1e0 is an unsigned address word used by %08x, copied to the pointer parameter/payload and explicitly converted for frees; all values are 32 bits.',
            'locals': 'Both debug-position float members, both screen extents, every selected alpha value and the saved fog output have producers on every path that reads them.'
        },
        'native_function_sha256': {name: digest(RETAIL.bytes_at(int(name, 16), WINDOWS['windows'][name]))
                                   for name in functions}
    }


if __name__ == '__main__':
    import json
    print(json.dumps(check(), indent=2))
