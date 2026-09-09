/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Main current-owner compiler replay: 840/832 bytes, nd624, twenty-six object relocations; nd includes eight overrun bytes.
 * nd counts relocation-masked differing executable bytes, including overruns.
 * No native behavioral verification was run for this unpromoted candidate.
 * One initial compiler replay only; no source-layout sweep.
 * Production remains the original ASM fallback, including unchanged providers.
 *
 * Agent reconstruction evidence follows (its no-compilation statement describes
 * agent work before Main performed the compiler replay recorded above).
 * Target: func_0020f730, retail 0x0020F730..0x0020FA6F (0x340 bytes).
 * Deliverable: body.c is a complete ordinary-C candidate, not compiled or measured.
 * No production/shared files were changed. All validation was intentionally skipped as assigned.
 * 
 * ABI / input representation
 * - Entry 0x20F760..76C preserves a0=context, a1=panel pointer, a2=one packed 32-bit color, a3=signed segment index. No floating input or fifth argument exists.
 * - Existing owner Color4 is four consecutive u8 fields c0,c1,c2,c3 (src/promoted/code1_0020.c lines 125-130). body.c uses that true four-byte aggregate by value, not a pointer, u64, or invented extra arguments.
 * - Caller func_0020fa70 at 0x20FE5C..6C passes context and panel unchanged, loads one word from its four initialized color bytes at sp+0x8C into a2, and passes loop index in a3. The caller visits 1..11 inclusive. It initializes the packed color as {0x66,0x82,0xFF,0x33} or {0xFF,0x66,0x6E,0x33}; byte order is little-endian.
 * - Target spills that word at sp+0x9C and reads +0/+1/+2/+3 with lbu. c0/c1/c2 are RGB; c3 is alpha because renderer stores 255-(alpha&255) at context+0x7D.
 * - Panel fields actually accessed here are f32 at +8, sampled before renderer calls, and signed s16 at +2, sampled AFTER the first draw. No claimed complete panel struct or invented padding; u8 * plus grounded typed accesses follows the owner convention.
 * - Return is void: no return-value contract is consumed by the caller.
 * 
 * Initialized aggregates / storage proof
 * - config/slus21782.yaml maps image.bin offset zero to VRAM 0x100000. Direct binary extraction at address-0x100000 produced:
 *   0x626C40: 0000c4c2 0000b8c2 0000c442 0000b842
 *             f32 {-98,-92,98,92}, represented as corners[2][2].
 *   0x626C50: 00007041 00005842 0000d841 0000c841 00006442 00006041
 *             f32 {15,54,27,25,57,14}, represented as offsets[3][2].
 *   0x626C70: 31000000 36000000 39000000 3c000000
 *             s32 {49,54,57,60}, represented as sprites[4].
 * - The first aggregate occupies precisely sp+D0..DF: four lwc1/swc1 copies, later indexed at D0+8*flipX and D4+8*flipY.
 * - The six-word aggregate occupies precisely sp+B0..C7: retail 0x20F7B0..D0 performs three iterations, loading/storing TWO words each, advancing source and destination by eight. Accesses later are B0+8*part and B4+8*part. C8..CF is not invented array storage or padding. An ordinary initialized 3x2 float array represents the actual copy loop without a fake memcpy provider or integer/float alias punning.
 * - The four sprite words occupy sp+A0..AF. Though copied using FP loads/stores, retail reads selected values with lw at 0x20F8D8 and subtracts part as an integer. They are NOT tiny floating values.
 * - All three aggregate initializations precede the arg3==0 branch, exactly as retail; no pointers to these local arrays escape.
 * 
 * Scale constant
 * - Read orig/SLUS_217.82 ELF32 .reginfo (SHT_MIPS_REGINFO 0x70000006): gp=0x007690F0.
 * - Retail gp-0x7DF0 is therefore 0x00761300. image.bin has bytes b0 72 88 3f there: binary32 1.065999984741211 (0x3F8872B0).
 * - Candidate retains an external float load named fGpffff8210, not an immediate literal that would wrongly erase reloads. This follows existing fGpffff815c=0x0076124C mapping in config/symbols_recovered.txt. declarations.c records the new necessary symbol mapping.
 * 
 * Control flow / arithmetic
 * - Zero index: no context access or rendering after aggregate initialization.
 * - half=index/6; flipX=1-((index/3+half)&1); flipY=1-half. Signed divisions/remainders are intentional.
 * - Sign conversion is integer +1 for zero flip and -1 otherwise, followed by f32 conversion, matching cvt.s.w rather than an invented float ABI.
 * - part=index%3 if index%6<3, otherwise ~(index%3)+3. sprite=sprites[flipX|(flipY<<1)]-part. Caller-established 1..11 makes both flip flags 0/1 and part 0..2. The target itself does not add bounds guards, so the candidate does not either.
 * - Snapshot scaleY=globalScale*panel.scale before all calls.
 * - Width query first. Compute float(flipX)*returnedWidth; reload globalScale AFTER width query; divide the product by that reload; add offsets[part][0]; multiply by converted X sign; multiply by reloaded scale. No division-to-multiply rewrite or reassociation.
 * - Height query second. Compute float(flipY)*returnedHeight, divide by earlier scaleY, add offsets[part][1], multiply by converted Y sign, then multiply by scaleY.
 * - Origin X is (0.0f+float(0x117)) + newly reloaded globalScale*corners[flipX][0]; Y is (0.0f+229.0f) + scaleY*corners[flipY][1]. Retail explicitly uses adda.s to seed ACC with zero+base and madd.s for the product addition. Candidate preserves these additive/multiplicative expression trees; whether the compiler selects the identical accumulator instructions is unmeasured.
 * - Set origin, draw once with packed alpha, then reload panel signed +2 and draw again with alpha 255 if index<threshold. No outer render loop belongs in this function; it is in func_0020fa70. The only retail loop inside this window is the six-word initialization copy.
 * 
 * Providers / side effects / necessary owner corrections
 * - func_00201950 and func_00201990 each take (u8 *context,s32 bank,s32 sprite) in a0/a1/a2. Retail selects context[bank*4+0x2C], stores it at context+0x6C, stores sprite at +0x70, and calls respectively func_0046b260 or func_0046b2f0(context+0x6C). They preserve the returned f0 all the way out; target immediately consumes it as binary32.
 * - Current promoted owner incorrectly defines those two as void with bare calls. declarations.c specifies the essential f32 return types and `return` of their existing lower calls. This is required for a truthful candidate, not a block-scope false signature or unrelated ABI repair. Existing src/Kernel/sdkSpr.c lines 261-310 already defines both lower providers as f32, deriving dimensions from sprite metadata and optional dimension/scaling overrides. No new dimension helper or bypass of the real provider is proposed.
 * - func_002012d0(u8 *,f32,f32) uses a0,f12,f13; converts the coordinates to integer origin at context+4/+8 and clears context+C/+10. Its existing owner definition is truthful.
 * - func_00201650(u8 *,s32,s32,f32,f32,s32,s32,s32,s32) uses a0/a1/a2,f12/f13,a3/t0/t1/t2. Existing owner definition is truthful: sets RGB at +94/+95/+96, inverse alpha at +7D, invokes func_00201410, then resets RGB to 255 and inverse alpha to zero. No s64 color redeclarations are needed.
 * - func_00201410 selects the sprite, transforms coordinates from current renderer state, sets optional scaling fields, invokes func_0046b380, and clears scaling fields on its scaled path. Calls are retained in order with full opaque effects. No callback function pointer is an input to this target and none is fabricated. Do not mark providers pure/const or hoist panel threshold/global-scale reads across them: callbacks or aliased state reachable in renderer calls must retain their observable effects.
 * 
 * Uncertainty / blocker status
 * - No semantic representability blocker found for the actual caller's index range. Complete initializers, storage bounds, argument registers, effects, and arithmetic order are grounded.
 * - Initial array layout, compiler-generated aggregate-copy loop, register allocation, and accumulator instruction selection remain unmeasured; no MATCH claim is made. Main must perform central compilation/measurement and integrate the two essential return corrections before trying this candidate.
 * - Graph lookup and coverage checks found stale promoted-source metadata and partial assembly parsing. All substantive claims above use direct current-source/retail reads, plus raw image/ELF extraction; no graph absence was treated as proof.
 */

/* New owner-local data declaration. Retail gp is 0x007690F0; the load at
 * gp - 0x7DF0 addresses 0x00761300. Add the equivalent recovered-symbol
 * mapping if the normal symbol-recovery step does not already create it:
 * fGpffff8210 = 0x00761300; // type:data
 */
extern f32 fGpffff8210;

/* Correct the existing owner definitions to these result types, and replace
 * their final bare calls with `return func_0046b260(arg0 + 0x6C);` and
 * `return func_0046b2f0(arg0 + 0x6C);`, respectively. All existing argument
 * types and the two context stores remain unchanged. Do not add conflicting
 * block-scope declarations while retaining the incorrect void definitions.
 */
f32 func_00201950(u8 *arg0, s32 arg1, s32 arg2);
f32 func_00201990(u8 *arg0, s32 arg1, s32 arg2);

/* Existing Color4 at owner lines 125-130 is already exactly four u8 members
 * c0/c1/c2/c3 and needs no changes. Existing func_002012d0 and func_00201650
 * definitions already have the truthful signatures used by body.c.
 */

// FUN_0020F730
void func_0020f730(u8 *arg0, u8 *arg1, Color4 arg2, s32 arg3)
{
    f32 corners[2][2] = {
        {-98.0f, -92.0f},
        {98.0f, 92.0f}
    };
    f32 offsets[3][2] = {
        {15.0f, 54.0f},
        {27.0f, 25.0f},
        {57.0f, 14.0f}
    };
    s32 sprites[4] = {49, 54, 57, 60};
    f32 scaleY;
    f32 drawY;
    f32 drawX;
    f32 dimension;
    f32 scaleX;
    s32 flipY;
    s32 flipX;
    s32 sprite;
    s32 part;
    s32 half;
    s32 sign;
    s32 green;
    s32 blue;

    if (arg3 != 0) {
        scaleY = fGpffff8210 * *(f32 *)(arg1 + 8);
        half = arg3 / 6;
        flipX = 1 - (((arg3 / 3) + half) & 1);
        flipY = 1 - half;
        sign = 1;
        if (flipX != 0) {
            sign = -1;
        }
        drawX = (f32)sign;
        if (flipY == 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        drawY = (f32)sign;
        if (arg3 % 6 < 3) {
            part = arg3 % 3;
        } else {
            part = ~(arg3 % 3) + 3;
        }
        sprite = sprites[flipX | (flipY << 1)] - part;
        dimension = func_00201950(arg0, 10, sprite);
        dimension = (f32)flipX * dimension;
        scaleX = fGpffff8210;
        drawX = scaleX * (drawX * (offsets[part][0] + dimension / scaleX));
        dimension = func_00201990(arg0, 10, sprite);
        dimension = (f32)flipY * dimension;
        drawY = scaleY * (drawY * (offsets[part][1] + dimension / scaleY));
        func_002012d0(arg0,
                     (0.0f + (f32)0x117) + fGpffff8210 * corners[flipX][0],
                     (0.0f + 229.0f) + scaleY * corners[flipY][1]);
        blue = arg2.c2;
        green = arg2.c1;
        func_00201650(arg0, 10, sprite, drawX, drawY,
                      arg2.c0, green, blue, arg2.c3);
        if (arg3 < *(s16 *)(arg1 + 2)) {
            func_00201650(arg0, 10, sprite, drawX, drawY,
                          arg2.c0, green, blue, 255);
        }
    }
}
