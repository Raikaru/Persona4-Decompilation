/* Measured 2026-09-09, canonical current-owner probe: 724/736 bytes,
 * normalized_diff 4, 16 resolved relocations and twelve zero-tail bytes.
 * The remaining bytes are the first branch's glyph stack offsets:
 * +0x190/+0x198/+0x19C/+0x1AC use sp+0x6C..6E rather than sp+0x68..6A.
 * Both branch-local arrays below contain exactly two glyph bytes and NUL.
 * A shared glyph[3] ties all instructions but leaves eight offset bytes.
 * glyph[8] reached nd0 only as a diagnostic: five extra capacity bytes lack
 * a source contract, so that shape was rejected and production remains ASM.
 *
 * Retain the existing func_0026f1e0_add byte-address helper. The first stream
 * sum is pointer-shaped; later sums use unsigned 32-bit arithmetic. The
 * loaded signed item word is held as s64 across the real s64 classifier
 * calls. Its earlier table-index role is explicitly u16, preserving the
 * full decoded index without a synthetic 64-to-32 normalization sequence.
 * Keep the first zero-extended-halfword versus signed -1 comparison literal;
 * it is NOT the second operand's genuine 0xFFFF sentinel.
 *
 * Prerequisites for replay in src/promoted/code1_0026.c, NOT integrated:
 * - replace the old mode getter with extern u32 func_002746a0(void);
 * - replace the text-index provider with void func_002739e0(u8, u8 *);
 * - remove the stale getter argument at all four existing owner calls;
 * - add the two canonical declarations below and cast the five existing
 *   signed sp20 arrays to u8 * at their func_00273cc0 call sites.
 * These existing callers would require separate verification before any
 * production cutover. No partial declaration migration was made.
 *
 * Further measured controls: wide snapshot and declaration movement tie
 * the shared nd8 floor; unsigned glyph gives nd10; branch lifetime controls
 * tie nd4; real aggregate initializers give 748 bytes/nd232/22 relocations.
 * No fake frame object, padding, undefined input or provider narrowing.
 */

/* Original reconstruction evidence (agent hypotheses are superseded by
 * the measured results above; its body.c/declarations.c are scratch names).
Target and artifacts
- body.c replaces only src/promoted/code1_0026.c:1621-1622. declarations.c contains canonical provider declaration replacements/additions. It uses the already-present byte-address helper func_0026f1e0_add, not a new abstraction. No alternative source form is supplied.
- No production files were changed. No compiler, build, test, lint, runtime, or formatter validation was run. All emission effects, including register allocation, stack placement, redundant masks/branches and matching size, are UNMEASURED HYPOTHESES. This is a complete source reconstruction, not a claim of an exact compiler match.

Instruction-grounded decoding
- Read the complete asm/nonmatchings/code1_0026/func_0026f2c0.s:1-203, including all 0x2E0 bytes: executable return delay slot ends at 0x26F590; 0x26F594..59C are alignment zero words.
- The two actual incoming values are command in a0 and context in a1. a0 is unused. No third argument or hidden input is consumed. Context +0x10 is the 32-bit script-data address, +0x18 is a signed 32-bit byte position. The function recomputes their sum for each two-byte operand and does not update position.
- Each pair (b0,b1) decodes to ((b0-1)&255) | (((b1==255 ? 0 : (b1-1)&255)&255)<<8). The packed value is sign-extended from s16 and then ANDed with 65535: all three retained operands are zero-extended 16-bit values, not signed item IDs at this stage. Zero input bytes wrap to 255; no malformed-stream guards were introduced.
- First operand is tested at 0x26F428..430 as (first & 0xFFFF) versus signed -1 loaded by addiu. Equality is impossible, INCLUDING first==65535. Retail therefore writes the low byte to context+0xD whenever the selected slot is nonnull. body.c preserves the comparison literally; substituting first!=0xFFFF would change behavior. An optimizing compiler may remove this provably true condition (UNMEASURED HYPOTHESIS); no undefined values or artificial widening were added to retain its instructions.
- Second operand genuinely compares against 0xFFFF loaded by ori at 0x26F440. This distinct sentinel selects the item-ID path. Third operand selects D_008815B0 with full unsigned 16-bit index and four-byte stride, not a byte index. The non-sentinel text-provider call later deliberately narrows that index to u8.
- Return is explicitly zero on the mode early exit, null slot and both rendering branches. Every local that is read is initialized on its path. There is no undefined incoming-result path to emulate.

Branches, storage and lifetimes
- Mode != 0 exits only AFTER all six operand bytes have been read. A null shared-table slot returns zero without changing context+0xD.
- For a nonnull slot, save context+0xD with lbu and restore via sb AFTER the final provider call in each branch. No style restore occurs between provider calls.
- Non-sentinel second operand: form {0x83, (second+0xC7)&255, 0}; call 273f70(context), 273cc0(glyph,context), 273f70(context), 2739e0((u8)third,context); restore saved byte. The local is exactly a two-byte glyph and one NUL: u8 glyph[3]. No stack[8], padding, frame-shaped struct, or unused storage is justified.
- Sentinel branch: reload the slot after the context byte write, dereference its first aligned s32 into third, call 26e360(third), select force-character 1 for 0..6,9,11 and 0 for everything else, and if selected set context+0xD=4. Call 26e360(third) AGAIN to produce glyph byte 1; do not cache its first result. Then 273f70, 273cc0(glyph), 273f70, 1067f0((s16)third), 273cc0(returned-address), restore. The loaded item word is retained across calls; the pointed-to item word is NOT reloaded after callbacks.
- Verified jump destinations directly from image.bin, with virtual address mapping vaddr-0x100000 established by config/slus21782.yaml:19-32: jtbl_007480A0 has 12 words, E0,E0,E0,E0,E0,E0,E0,EC,EC,E0,EC,E0 (addresses 0x26F4E0/0x26F4EC). This confirms all case labels, including 9 and 11 and defaults 7,8,10 and out-of-range.
- No provider is given a cached context field/list pointer. 2739e0 re-reads the shared table on its own entry after the preceding three calls; body.c passes only the narrowed index, preserving that reload. In particular, replacing it with 273cc0(cached_slot,context) is wrong.

Current canonical providers (not inferred just from unused registers)
- src/frFont.c:2583-2586 defines u32 func_002746a0(void), returning D_00764594. asm/code1.s:424067-424071 corroborates a single lw and return. The low-byte decode value merely remains in a0 at the retail jal; it is NOT an argument. No ignored parameter was invented.
- src/frFont.c:1968-2098 defines void func_002739e0(u8 index,u8 *context), obtains text=(u8*)D_008815B0[index], synchronously consumes the string, and reloads mutable context attributes and linked nodes around provider calls. No return value is consumed.
- src/frFont.c:2115-2251 defines void func_00273cc0(u8 *,u8 *). It consumes a NUL-terminated byte string synchronously and creates/links glyph nodes, with per-call reloads of context+0xC,+0xD,+0xE,+0xF,+0x14. Null text is a supported no-op; the command passes the item-name provider's return directly, including zero.
- src/frFont.c:2260-2349 defines void func_00273f70(u8 *). It can allocate/link a node, rewrite context+0x14, clear +0x1C and +0x1D, apply signed halfword +0x1E and pending coordinates. These effects must survive; only +0xD is explicitly restored by this handler.
- src/promoted/code1_0026.c:927-966 defines s32 func_0026e360(s64). It narrows to s16 for func_00106880 and maps the first matching flag to 0..6,9,11,13,14,12, default 13. asm/code1.s:416657-416756 corroborates the complete provider. A loaded s32 item is sign-extended when supplied to its existing s64 parameter; do not narrow its declaration to manipulate emission.
- src/g_data/g_data.c:1152-1155 defines u32 func_001067f0(s16), returning D_005E2200[arg0], a 32-bit address word. Use that exact signature and cast the result to u8*, rather than falsely declaring a pointer return. asm/code1.s:7705-7714 confirms signed-halfword indexing and a word load. The metadata accessor at src/g_data/g_data.c:1170-1173 indexes 68-byte records and reads flags at +4.

Caller and extent contracts
- src/frFont.c:128-133 declares the script data pointer at +0x10 and s32 pos at +0x18. src/frFont.c:2528-2562 constructs a real 0x20-byte context; byte +0xD is the character/font selector, interpreted as s8 by font providers, +0x14 is the mutable node pointer, +0x1C/+0x1D are state flags, +0x1E is a signed height as consumed by 273f70.
- src/frFont.c:2404-2427 dispatches handlers with (command,script), after consuming the opcode, then advances position by (((command&0xF00)>>8)-1)*2 after return. The filtered dispatcher at 2624-2640 uses the same two-argument ABI and increment. This handler does not advance the stream itself.
- Direct retail data extraction: D_0063BA00 group 2 points to 0x63B970 with recorded count 8; entry 5 contains 0x26F2C0. Thus low command byte 0x45 selects this handler; the three-operand encoding is 0xF445 (six operand bytes). Other high nibbles still reach the same handler if provided, but the dispatcher then advances a different operand extent; do not manufacture a guard.
- src/frFont.c:353-359 initializes exactly 32 four-byte D_008815B0 slots. src/promoted/code1_0027.c:713-716 is the unchecked slot setter. This is evidence for a 32-slot valid-input contract, NOT for widening the table to 65536 because the handler retains 16 index bits. No new fixed array declaration is added.
- Valid inputs require a live writable 0x20-byte context, aligned word fields, a readable six-byte operand window even when mode is nonzero, and a data+position address within the actual script object (the reused byte helper expresses real byte arithmetic, without signed-integer-add overflow). The shared slot index must designate valid storage; ordinary subsystem use supplies 0..31. Non-sentinel nonnull slots must provide the provider's valid NUL-terminated text. Sentinel nonnull slots must hold an aligned readable item word whose signed-low-16 value is valid for both item metadata and name tables. Provider allocation/state invariants must hold. No missing-data guards or fallback strings have been invented.

Separate integration edits, not applied
- declarations.c REPLACES current owner line145's extern s32 func_002746a0() with canonical u32(void), and line151's extern void func_002739e0(s32,u8*) with canonical void(u8,u8*). Add the two new declarations before the target. Existing 273f70 declaration, D_008815B0 declaration and earlier 26e360 definition remain.
- The full no-argument mode prototype requires removing the stale temp_4 argument from four EXISTING owner calls, separately: func_0026ef60 current line1490, func_0026f0a0 line1566, func_0026f1e0 line1612, func_0026fff0 line1846. Change only func_002746a0(temp_4) to func_002746a0(); the byte decode computations remain. Main must measure these existing owner matches before integration. Do not preserve fake inputs by using an unspecified or fabricated parameter list.

Coverage qualifications
- Graph search returned no Function node for this fallback, not absent code. Index generation is 2026-09-04. Coverage reports current owner/font/g_data metadata changed, target ASM parse_partial at relocations/size, asm/code1.s and image.bin excluded. Config/type header metadata match; fr_font_internal.h and archive not tracked. All material conclusions above are grounded in current source, complete target ASM, provider ASM or direct retail data extraction, not graph completeness. The old W45c26 archive was consulted as a non-authoritative comparison only: its first!=0xFFFF test and stack[8] were specifically rejected.

*/

// FUN_0026F2C0
extern void func_00273cc0(u8 *, u8 *);
extern u32 func_001067f0(s16);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0026f2c0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s64 third;
    s32 *slot;
    u8 previous_character;
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;
    s32 character_code;

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = func_0026f1e0_add((u8 *)stream_base, (u32)stream_offset);
    low = (stream[0] - 1) & 0xFF;
    high_byte = stream[1];
    if (high_byte == 0xFF) {
        high_first = 0;
    } else {
        high_first = (high_byte - 1) & 0xFF;
    }
    first = (u16)(s16)(((high_first & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[2] - 1) & 0xFF;
    high_byte = stream[3];
    if (high_byte == 0xFF) {
        high_second = 0;
    } else {
        high_second = (high_byte - 1) & 0xFF;
    }
    second = (u16)(s16)(((high_second & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[4] - 1) & 0xFF;
    high_byte = stream[5];
    if (high_byte == 0xFF) {
        high_third = 0;
    } else {
        high_third = (high_byte - 1) & 0xFF;
    }
    third = (u16)(s16)(((high_third & 0xFF) << 8) | (low & 0xFF));

    if (func_002746a0() != 0) {
        return 0;
    }
    slot = &D_008815B0[(u16)third];
    if (*slot != 0) {
        previous_character = arg1[0xD];
        /* Retail compares a zero-extended halfword with signed -1. */
        if ((first & 0xFFFF) != -1) {
            arg1[0xD] = first;
        }
        character_code = second & 0xFFFF;
        if (character_code != 0xFFFF) {
            s8 glyph[3];
            glyph[0] = -0x7D;
            glyph[1] = character_code + 0xC7;
            glyph[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)glyph, arg1);
            func_00273f70(arg1);
            func_002739e0((u8)third, arg1);
            arg1[0xD] = previous_character;
        } else {
            s8 glyph[3];
            third = *(s32 *)*slot;
            switch (func_0026e360(third)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 9:
            case 11:
                force_character = 1;
                break;
            default:
                force_character = 0;
                break;
            }
            if (force_character != 0) {
                arg1[0xD] = 4;
            }
            glyph[0] = -0x7D;
            glyph[1] = func_0026e360(third) + 0xC7;
            glyph[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)glyph, arg1);
            func_00273f70(arg1);
            func_00273cc0((u8 *)func_001067f0((s16)third), arg1);
            arg1[0xD] = previous_character;
        }
    }
    return 0;
}

#pragma pop
