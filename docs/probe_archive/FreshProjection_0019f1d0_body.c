/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Main current-owner compiler replay: 1004/1056 bytes, nd321, one object relocation; 52 retail-window bytes uncovered.
 * nd counts relocation-masked differing executable bytes, including overruns.
 * No native behavioral verification was run for this unpromoted candidate.
 * One initial compiler replay only; no source-layout sweep.
 * Production remains the original ASM fallback, including unchanged providers.
 *
 * Agent reconstruction evidence follows (its no-compilation statement describes
 * agent work before Main performed the compiler replay recorded above).
 * Target: func_0019f1d0, retail 0x0019F1D0..0x0019F5EF, 0x420 bytes.
 * Deliverable: body.c is a complete proposed owner replacement, not integrated or compiled.
 * Only required declaration: extern u8 *iGpffffb3c4; supplied in declarations.c.
 * No production files modified. No builds, compilation, tests, formatting, layout sweeps, or validation commands run, as assigned.
 * 
 * ABI AND REAL CONTEXT
 * - The true contract is void func_0019f1d0(u8 *unit). Incoming a0 is the only input. There are no calls, stack slots, return-value writes, or callee-saved-register changes.
 * - Owner src/promoted/code1_0019.c:278 already declares precisely this signature. Retail caller asm/nonmatchings/code1_0019/func_0019f5f0.s at 0019F780..0019F788 sets only a0 to its allocated BtlUnit; it ignores any return. The apparent a2/param_3 in generated/ghidra candidates is not an input (see dominance proof below).
 * - Owner func_0019f5f0:3750..3755 stores its DatUnit/resource pointer at BtlUnit+0xA64, calls func_0019ea60 to populate identity/model dimensions/scale, and calls this target for genus 1 unless battle flags contain 0x200000.
 * - Owner func_0019d210:2875..2888 allocates/clears 0xA70 bytes, stores genus at +0xA2, stores a monotonically assigned unit serial at +0xA8, and initializes dimensions at +0x8C/+0x90. Thus +0xA8 & 3 cycles scale choices by unit identity; it is not an extra incoming argument.
 * - Owner func_0019ea60:3500..3533 writes the DatUnit ID at resource+2, sets scale from unsigned model-table scale / 100.0f, and sets dimensions from unsigned table halfwords +6/+8 into unit+0x8C/+0x90.
 * - src/Battle/btlUnit.c:59..80 identifies +0x2C as scale, +0x90 as sphereRadius, +0x98 as flags2 (bit 4 is BTLUNIT_FLAG2_DIRTY), and +0x8C as unk_8c. The producer uses +0x8C to set sphereCenter.y to half of it, so the local descriptive name height is supported, but no shared member is renamed.
 * - Existing BtlUnit definitions are TU-local partial views: btlUnit.c does not expose genus, serial, or resource, while btlUnit_functions.c:101..113 exposes genus but not these scale/dimension/resource fields. Copying/expanding a partial type would add unnecessary padding guesses. The body retains this owner's existing u8* ABI and offset-access convention, with no invented storage/type layout.
 * - src/promoted/datUnit.c:14..24 establishes DatUnit.id at +2. Its DatEnemyUnitInit at :47..57 has flags at +0 and stride 0x3C; :76 declares iGpffffb3c4 as u8*, and :257..265 independently accesses that table by ID*0x3C. Address comment there maps the pointer to gp-0x4C3C, matching the target lw.
 * 
 * ALL CONTROL-FLOW AND FLOAT OPERATIONS
 * - 0019F1D0..0019F210: if genus byte is 1 and resource pointer is nonnull, read its unsigned 16-bit ID, multiply by 60, read table entry flags as u16, and return without writes on flag 0x8000. No resource/table dereference occurs for other genera or null resource.
 * - 0019F214..0019F234: f3=original scale; f9=float(s32(radius*scale)); f8=float(s32(height*scale)). Both multiplications are single precision, each followed by signed integer round-trip. The generated M2C candidate incorrectly casts scale and omits both product round-trips. The body follows assembly instead.
 * - 0019F244..0019F29C: reject !(radius<=200), !(height<=400), radius<50, or height<100, in that order. Negated <= expressions are intentional, not interchangeable with > on unordered operands.
 * - 0019F2A0..0019F360: height<=200 selects band 0 for radius<=75, 1 for radius<=125, otherwise 2 with the retail radius<=200 test retained. 200<height<=300 selects band 1 for radius<=125, otherwise 2 with the same retained test. height>300 selects band 2.
 * - DEFINITION/DOMINANCE PROOF: reaching band classification implies the ordered comparison radius<=200 was true, and radius/height are each in the positive accepted intervals. Therefore both retained final radius<=200 tests MUST be true when reached. Every reachable path assigns band, and band can only be 0, 1, or 2. No incoming a2, uninitialized-value read, or fabricated default is needed. This is why the source can retain the redundant retail branches without importing the decompiler's false parameter.
 * - 0019F364..0019F414 switches the unsigned-halfword band. minRadius/minHeight/maxRadius/maxHeight tuples are respectively (50,100,74,199), (76,201,124,299), (126,301,199,399). Every reachable band is covered and therefore every bound is defined; no default/incoming floating register is used. The 299/301/399 constants are exact integer-to-float results in retail, equal to the exact f32 literals supplied.
 * - 0019F418..0019F498: upper=(maxRadius<=radius ? 1 : maxRadius/radius); upperHeight analogously; if !(upper<upperHeight), replace upper by upperHeight. The exact comparison polarity is retained, rather than substituting a host min function.
 * - 0019F498..0019F500: lower=minRadius/radius only for minRadius<radius, otherwise -1; lowerHeight analogously. Strict comparison at each boundary is preserved.
 * - 0019F500..0019F548: if neither lower nor lowerHeight is <=0, choose lowerHeight when lower<=lowerHeight; otherwise lower=1. Negated <= checks preserve retail unordered behavior rather than spelling these as positive > tests.
 * - 0019F548..0019F5C4: load the serial word at unit+0xA8 and mask by 3. Cases 0/1/2/3 choose upper/midpoint/lower/1. Mask proves switch exhaustive and factor defined. Mode 1 has sub.s(upper,lower), adda.s(+0,lower), madd.s(0.5,difference). Source explicitly keeps the accumulator add as (0.0f+lower) and the multiplication as 0.5f*(upper-lower); do not replace with (upper+lower)*0.5, reorder the subtraction, or remove the +0 casually. Target compiler contraction into EE adda/madd remains centrally unmeasured.
 * - 0019F5C8..0019F5D8: multiply selected factor by the ORIGINAL cached scale and write +0x2C; only afterward reload flags2 from +0x98, OR bit 4, and store. Mode 3 still performs the scale store and dirty-bit update. All early returns do neither.
 * - 0019F5DC..0019F5EF: void return, followed by alignment padding only.
 * 
 * STORAGE, ALIAS, AND PRECISION NOTES
 * - Resource and table are read-only here. No output escapes other than the scale float and flags2 word. No local arrays, backing objects, persistent state, helper shims, or allocation.
 * - Source read order follows retail: genus, optional resource/id/table flag, scale, radius, height, serial, scale store, flags reload/store. There is no call that could invalidate the cached scale/dimensions; flags2 is deliberately read after the scale write rather than cached before it.
 * - The natural caller populates dimensions from u16 and scale from u16/100, so products are finite nonnegative and below 2^31. Signed round-trip C casts describe that real domain and the expected PS2 compiler conversion. Arbitrary NaN/out-of-s32 float-to-int conversions are not portable ISO-C operations; do not claim host IEEE/fenv emulation for malformed fabricated units. All subsequent ordered/unordered comparison polarities are nevertheless preserved exactly.
 * - No genuine semantic blocker was found. The only remaining uncertainty is target compiler instruction selection/register allocation/matching, intentionally left for Main's central measurement. This is not a measured MATCH claim.
 * 
 * SOURCE EVIDENCE QUALITY
 * Graph was queried first for symbols/callers; coverage metadata was checked for every cited source/assembly path. Owner/btlUnit source metadata is changed and generated/assembly coverage partial, so current direct source and complete retail assembly were read instead of trusting graph line ranges. docs/ghidra_headstart/src/promoted/code1_0019.c:1743..1858 and src/generated/code1_0019.c:7639..7729 were compared as non-authoritative leads: their false extra parameters, unset locals, comparison rewrites, and incomplete float operations were rejected in favor of the retail instructions.
 */

/* Add to src/promoted/code1_0019.c owner declarations.
 * datUnit.c already declares this same gp-relative enemy-table pointer.
 * No public signature or shared type changes are required.
 */
extern u8 *iGpffffb3c4;

// FUN_0019F1D0
void func_0019f1d0(u8 *unit)
{
    u8 *resource;
    f32 scale;
    f32 radius;
    f32 height;
    u16 band;
    f32 minRadius;
    f32 minHeight;
    f32 maxRadius;
    f32 maxHeight;
    f32 upper;
    f32 upperHeight;
    f32 lower;
    f32 lowerHeight;
    f32 factor;

    if (*(u8 *)(unit + 0xA2) == 1) {
        resource = *(u8 **)(unit + 0xA64);
        if (resource != NULL &&
            (*(u16 *)(iGpffffb3c4 + *(u16 *)(resource + 2) * 0x3C) & 0x8000)) {
            return;
        }
    }

    scale = *(f32 *)(unit + 0x2C);
    radius = (f32)(s32)(*(f32 *)(unit + 0x90) * scale);
    height = (f32)(s32)(*(f32 *)(unit + 0x8C) * scale);
    if (!(radius <= 200.0f) || !(height <= 400.0f) ||
        radius < 50.0f || height < 100.0f) {
        return;
    }

    if (height <= 200.0f) {
        if (radius <= 75.0f) {
            band = 0;
        } else if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= 200.0f) {
            band = 2;
        }
    } else if (height <= 300.0f) {
        if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= 200.0f) {
            band = 2;
        }
    } else {
        band = 2;
    }

    switch (band) {
    case 0:
        minRadius = 50.0f;
        minHeight = 100.0f;
        maxRadius = 74.0f;
        maxHeight = 199.0f;
        break;
    case 1:
        minRadius = 76.0f;
        minHeight = 201.0f;
        maxRadius = 124.0f;
        maxHeight = 299.0f;
        break;
    case 2:
        minRadius = 126.0f;
        minHeight = 301.0f;
        maxRadius = 199.0f;
        maxHeight = 399.0f;
        break;
    }

    if (!(maxRadius <= radius)) {
        upper = maxRadius / radius;
    } else {
        upper = 1.0f;
    }
    if (!(maxHeight <= height)) {
        upperHeight = maxHeight / height;
    } else {
        upperHeight = 1.0f;
    }
    if (!(upper < upperHeight)) {
        upper = upperHeight;
    }

    if (minRadius < radius) {
        lower = minRadius / radius;
    } else {
        lower = -1.0f;
    }
    if (minHeight < height) {
        lowerHeight = minHeight / height;
    } else {
        lowerHeight = -1.0f;
    }
    if (!(lower <= 0.0f) && !(lowerHeight <= 0.0f)) {
        if (lower <= lowerHeight) {
            lower = lowerHeight;
        }
    } else {
        lower = 1.0f;
    }

    switch (*(u32 *)(unit + 0xA8) & 3) {
    case 0:
        factor = upper;
        break;
    case 1:
        factor = (0.0f + lower) + 0.5f * (upper - lower);
        break;
    case 2:
        factor = lower;
        break;
    case 3:
        factor = 1.0f;
        break;
    }
    *(f32 *)(unit + 0x2C) = factor * scale;
    *(u32 *)(unit + 0x98) |= 4;
}
