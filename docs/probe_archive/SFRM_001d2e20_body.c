/* Earlier IDA-backed baseline: 440B / 448B, 92 relocation-masked
 * differing words. Retail has 444 instruction bytes and one zero-tail word.
 * Its retained mode copy and scalar register allocation remain different.
 * IDA: docs/ida_headstart/src/Battle/btlFormation.c:402-440.
 *
 * Ascending case labels recover retail's 3,1,2,0 comparison order.
 * The category helper's canonical return is s32, not the old archive's s64;
 * its mode and the predicate's mode really are s64. The work view preserves
 * the three pointers and signed halfword at 0xC. Snapshots precede callbacks;
 * only the second unit reference is reloaded after the predicate.
 *
 * Source and retail confirm category results are bounded to 0..3 and the
 * predicate cannot return true when the second reference was initially null.
 * Native32 lifecycle smoke passes 10752 cases with the real category/predicate
 * and transform/count helpers. The numerical placement solver remains a
 * recording boundary; no retail MIPS execution or promotion is claimed.
 *
 * Rejected probes: branch-group/label orders, if chains, promoted/raw mode
 * lifetimes, snapshot order, canonical declarations, presence normalization,
 * scoped propagation/lifetime/dead-assignment/CSE/level controls and register
 * storage classes. The 448B presence64/level1/CSE-off variants score 87/88/89
 * respectively but introduce other instructions; size agreement is not a
 * match. Full output-helper types and the typed work view retain 440B/92.
 * The owning constructor is func_001d3000: packet 0xb02 with 16-byte work,
 * not adjacent func_001d2d90's 12-byte payload. Position is three floats;
 * rotation is four. This genuine Vec3 retains 440B/92 masked words
 * (100 fully resolved, zero-padded differing words), with 33 neighbors intact.
 */
/* Fresh canonical-owner replay, 2026-09-09: this transient-mode/saved-mode
 * source reaches 440/448 bytes, nd252 byte differences, ten resolved
 * relocations. The earlier body above replays at nd254; reusing the retained
 * full-width mode as selector gives nd266, also440 bytes. A word transient
 * and full-width argument-time snapshot tie nd252; the narrow argument-time
 * assignment gives448/nd264, not a match. None restores the required retail
 * mode-copy instruction and register allocation. Production remains ASM.
 *
 * mode is the real signed-halfword transient for the first load and later
 * second-category selector; saved_mode retains the original s64 provider
 * input. First category, node, first unit and presence remain snapshots.
 * Only a true predicate reloads the second reference and its unit.
 * Real category returns are0..3, so one solver group initializes the three
 * position and four rotation floats on every supported returning path.
 * The predicate cannot return true with initially-zero presence. These
 * facts do not validate bad pointers, other negative mode indices, or a
 * subsequently invalidated second reference; no guards were invented.
 * The historical smoke and neighbor verification above were not rerun for
 * these scratch-only source-shape measurements.
 */
// FUN_001D2E20
u32 func_001d2e20(u8* param_1)
{
    typedef struct FormationUnitRef
    {
        u8 prefix[0x30];
        u8* unit;
    } FormationUnitRef;
    typedef struct FormationDispatchWork
    {
        u8* node;
        FormationUnitRef* first;
        FormationUnitRef* second;
        s16 mode;
    } FormationDispatchWork;
    FormationDispatchWork* work = (FormationDispatchWork*)param_1;
    f32 output[3];
    f32 auxiliary[4];
    s16 mode;
    s64 saved_mode;
    s32 has_unit;
    s32 category;
    u8* unit;
    u8* node;
    extern s32 func_00199d00(s32 unused, u8* unit, s64 mode, s32 has_unit);
    extern s32 func_001f1210(u8* node, s64 mode, s32 has_unit);
    extern void func_001951f0(u8* node, u8* unit, u8* other, s32 category,
                              f32* position, f32* rotation, s32 mode);

    node = work->node;
    unit = work->first->unit;
    mode = work->mode;
    has_unit = work->second != 0;
    saved_mode = mode;
    category = (s16)func_00199d00((s32)node, unit, saved_mode, has_unit);
    if (func_001f1210(node, saved_mode, has_unit) == 0)
    {
        mode = (s16)func_00199d00((s32)node, unit, saved_mode, has_unit);
        switch (mode)
        {
        case 0:
        case 2:
            func_001951f0(node, unit, NULL, category, output, auxiliary, 0);
            break;
        case 1:
        case 3:
            func_001951f0(node, unit, NULL, category, output, auxiliary, 1);
            break;
        }
        func_00194f10(node, auxiliary);
        func_00194ee0(node, output);
    }
    else
    {
        func_001951f0(node, unit, work->second->unit, category, output, auxiliary, 2);
        func_00194f10(node, auxiliary);
        func_00194ee0(node, output);
    }
    return 1;
}
