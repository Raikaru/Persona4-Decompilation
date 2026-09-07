/* MATCH in production: MWCC b210 -O2, 348B / 352B retail window.
 * Raw fndiff counts only the absent zero alignment word. Literal separators
 * with opt_loop_invariants on and opt_propagation off close the eleven
 * remaining register-allocation words. No shared helper ABI changes.
 * Signed division preserves retail rounding; bias and next-offset additions
 * wrap explicitly, and multiplication avoids a negative signed left shift.
 * The production body passes 3,082 freestanding native32 UBSan-trap cases:
 * empty/multiple entries, single-entry precedence, 64-byte boundaries,
 * signed path bytes, 255-character paths, payload ownership and high-bit
 * serialized sizes. Registration is a checked hook, not retail execution. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_00456530(u8 *basePath, u8 *archive, s32 singleEntry) {
    s32 recordLength;
    u8 directory[0x100];
    u8 fileName[0x100];
    u8 entryPath[0x100];
    s32 dataOffset;
    u8 *cursor;
    s8 character;
    s32 alignedLength;
    s32 biasedLength;
    s32 offset;
    s32 blocks;
    s32 scan;

    func_00454d20((s32)basePath, directory);
    offset = 0;
next_entry:
    func_0043f810(entryPath, directory, 0xFC);
    func_0043f810(fileName, archive + offset, 0xFC);
    if (*(s8 *)fileName != 0) {
        func_0043f810(&recordLength, archive + (offset + 0xFC), 4);
        dataOffset = offset + 0x100;
        func_00442428(entryPath, fileName);
        scan = 0;
        {
            s8 reloadedCharacter;
            while (scan < 0xFF) {
                cursor = entryPath + scan;
                character = *(s8 *)cursor;
                if ((character >= 'a') && (character <= 'z')) {
                    *cursor = (u8)(character - 0x20);
                }
                reloadedCharacter = *(s8 *)cursor;
                if (reloadedCharacter != 0) {
                    if (reloadedCharacter == '/') {
                        *cursor = '\\';
                    }
                    scan += 1;
                } else {
                    break;
                }
            }
        }
        func_00456400(archive, archive + dataOffset, recordLength, entryPath);
        biasedLength = (s32)((u32)recordLength + 0x3FU);
        blocks = biasedLength / 64;
        alignedLength = blocks * 64;
        recordLength = alignedLength;
        offset = (s32)((u32)dataOffset + (u32)alignedLength);
        if (singleEntry != 1) {
            goto next_entry;
        }
    }
}
#pragma pop
