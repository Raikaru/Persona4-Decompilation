/* Exact collision segment recovery in canonical src/btlTarget/btlTarget.c.
 * func_001ece50: 520/528 bytes, six fully resolved relocations, nd0;
 * eight remaining bytes are retail zero alignment words.
 * The old promoted-owner ASM marker was removed, not duplicated.
 * Making the existing orientation leaf private closes the ABI-clobber floor:
 * external/shared-public definition -> 560 bytes; private definition -> 520.
 * All twelve retail calls stay in this geometry owner: eight from the existing
 * func_001eca10 ASM body, four from the recovered segment helper. A full mapped
 * image scan found no literal 0x001ECDE0 address words.
 * func_001ecde0 stays signed -1/0/+1: exact 108/112 bytes. The margin provider
 * now takes actual two-float coordinate pairs: exact 336/336 bytes. The existing
 * 976-byte ASM caller and all its relocations remain exact with private linkage.
 * No fixed registers, duplicate helper, artificial local or altered provider
 * extent is used. No native/game execution of the geometry path is claimed.
 *
 * Pre-integration contracts below retain their original audit line references;
 * the ownership decision above supersedes the suggested external-leaf move.
 *
 * TARGET ABI AND OUTPUT
 * func_001ece50(f32 *first, f32 *second, f32 margin) -> s32 boolean.
 * a0=first, a1=second, f12=margin. The two coordinates are consecutive f32s
 * at +0 and +4 (world X/Z in the path callers, not the first two fields of a
 * 3D world position). Both are read-only by the target and its geometry helpers.
 * No coordinate output, no node update, no margin scaling inside this target.
 * Return 1 at the first accepted edge intersection or vertex-distance hit;
 * return 0 after the linked list is exhausted, including an initially empty list.
 * Direct writable output extent: zero. Both coordinate input extents: 8 bytes.
 * Inputs must remain readable for the duration of traversal; null inputs are
 * not handled if a node exists. An empty list does not dereference either input.
 *
 * DIRECT CALLERS (complete current ASM bodies read)
 * func_001eed10, 001EED6C:
 *   incoming a1/a2 become first/second; incoming f12 is multiplied by 0.5.
 *   target result nonzero selects pathfinding; zero emits the two endpoints into
 *   output+0..0xF, count 2 at output+0x400 and status 2 at output+0x404.
 *   Before its later call to func_001ee610 it stores both coordinate pairs at
 *   battleGlobal+0x7E4/+0x7E8 and +0x914/+0x918 (001EEDBC..001EEDD8).
 *   Caller at 00197160 supplies two explicitly initialized stack pairs:
 *   sp+0x48/+0x4C <- actor+4/+0xC; sp+0x40/+0x44 <- request+4/+0xC
 *   (0019711C..00197138), with f12=50.0. Thus target receives margin 25.0.
 * func_001ee610, 001EE664:
 *   first=battleGlobal+0x7E4, second=battleGlobal+0x914,
 *   margin=0.5*incoming f12. Zero takes direct two-point route.
 * func_001ee610, 001EE6CC:
 *   first=sp+0x4C8, second=currentPathNode+8, margin as above.
 *   The call is reached only when point count s2>0. The initial s2=0 iteration
 *   bypasses it and writes BOTH sp+0x4C8/+0x4CC from node+8/+0xC at
 *   001EE708..001EE714. Subsequent iterations retain/update both words.
 *   The second coordinate pair is only used while node!=NULL.
 *   Zero advances backward through node+0x2C; nonzero terminates that shortcut.
 *   Other uninitialized working locals in the wider ee610 algorithm do NOT
 *   supply target arguments; they are not a blocker for this target contract.
 * Literal asm/code1.s lookup found exactly these three direct jal sites.
 * This is a direct-call inventory, not proof excluding indirect entry.
 *
 * LIST, NODE, AND INITIALIZATION
 * battleGlobal is iGpffffb3ac. The target reads one pointer at +0x318 (global
 * extent through +0x31B). Each node must remain readable through +0x4CF,
 * with next at +0x4CC. Vertex coordinate offsets within a node are:
 *   v0 +0x008,+0x00C; v1 +0x138,+0x13C;
 *   v2 +0x268,+0x26C; v3 +0x398,+0x39C.
 * Only two f32s from each 0x130-byte record are read by the target/providers.
 * No synthetic record padding or 0x130-byte local arrays are needed.
 * Current func_001ee250 calls func_001ec790 BEFORE publishing node=actor+0x508.
 * The provider writes all eight coordinate words at actor offsets
 * 0x510/0x514, 0x640/0x644, 0x770/0x774, 0x8A0/0x8A4, respectively
 * (minX,minZ), (maxX,minZ), (maxX,maxZ), (minX,maxZ).
 * ee250 initializes actor+0x9D4 (node+0x4CC) from the old head or NULL, then
 * publishes the new head. Actor storage therefore includes at least 0x9D8 bytes
 * for this list contract. ee1c0 clears the head. ee430 unlinks without changing
 * coordinate words. ee490 refreshes all eight words via ec790 when needed.
 * No uninitialized corner or next pointer is introduced by these producers.
 * The target does not inspect the unrelated per-vertex graph payload fields.
 * A finite well-formed list is required for termination; no cycle guard exists.
 *
 * PATH AND COMPARISON CONTRACT
 * For each node, test first, then second. If either passes all four conditions,
 * skip this node, not return hit:
 *   minX < x && minZ < z && !(maxX <= x) && !(maxZ <= z).
 * For finite values this means strictly inside the rectangle; boundaries are
 * NOT skipped. Keep the negated <= forms: a NaN upper bound makes those tests
 * true, while lower-bound < tests are false on unordered operands. Replacing
 * negated <= with < or > changes those unordered paths.
 * For each remaining node, signed s32 i runs 0,1,2,3. The instruction addiu
 * narrows arithmetic to 32 bits, but the bounded counter never overflows. Only
 * next index (i+1)&3 is masked; there is NO u8/u16 loop-counter narrowing.
 * Edges in exact order: v0->v1, v1->v2, v2->v3, v3->v0.
 * For each edge E->N, call orientation(E,N,first), then orientation(E,N,second).
 * If unequal call orientation(first,second,E), then orientation(first,second,N).
 * Two unequal pairs produce immediate 1. The side test is inequality, NOT
 * opposite strict signs: zero versus nonzero counts as different. Collinear
 * all-zero orientations do not intersect under this test.
 * On every non-intersecting edge call margin(first,second,E,margin) once.
 * No margin call on an intersecting edge, no call for N separately, no endpoint
 * or broad-phase replacement. Four iterations eventually cover every vertex.
 * If the margin provider returns nonzero, return 1; otherwise continue.
 *
 * ORIENTATION PROVIDER / REGISTER PRESERVATION
 * Current src/btlTarget/btlTarget.c:183-196 and retail 001ECDE0..001ECE4F agree:
 *   cross=(second[0]-first[0])*(point[1]-first[1])
 *        -(second[1]-first[1])*(point[0]-first[0]);
 *   return 1 when !(cross<=0); otherwise return -(cross<0).
 * Returns signed -1,0,+1; unordered cross follows the +1 branch.
 * Reads only offsets 0,4 of all three arguments; no stores and no calls.
 * Retail modifies v0, f0..f4, FPU ACC/condition; it preserves v1,a0,a1,a2,a3,t0.
 * Hence target's v1 side result and a3/t0 endpoint pointers really survive
 * successive jal calls. This is compiler-known leaf preservation, not missing
 * arguments, hidden output, or undefined caller-saved state. Ordinary C locals
 * and sequenced full-expression calls express it legally without fixed registers.
 *
 * MARGIN PROVIDER / SIDE EFFECTS
 * Current ec8c0 has incorrectly oversized RwV3d* parameters; its actual accesses
 * are two-component only. Repair to f32* and [0]/[1] as declarations.h describes.
 * It initializes BOTH words of local delta[2]=first-second BEFORE passing
 * (out=delta,in=delta) to func_003e41e0. Normalizer reads exactly 8 bytes and
 * writes exactly 8 bytes on ALL return paths, including zero length. Its output
 * and input may alias. No third float is accessed. No invented zero-fill needed.
 * Then cross=(point-first) dot (delta[1],-delta[0]); project point onto the
 * first/second line. Projection must lie between both endpoint coordinates,
 * inclusive, and fabs(cross) < margin (strict). There is no positive-margin
 * check, margin clamping, or special degenerate-segment early return.
 * Retail projection acceptance for either axis P, A, B is exactly:
 *   (!(A < P) && B <= P) || (A <= P && !(B < P)).
 * That retains all c.lt/c.le senses; do not replace negated comparisons blindly.
 * The existing provider uses an equivalent finite-input rejection expression
 * with >, whose unordered branch behavior is not literally the retail chain.
 * The target must keep calling this provider, not inline an idealized distance.
 * Zero-length normalization computes/writes its zero result then calls
 * func_003df590(0x19) and func_003df4d0 on a two-word record {1,0x19}.
 * The latter conditionally writes the RenderWare error-state record rooted at
 * D_008872E0 plus the gp[-0x48A0] offset if its old words are {0,0x80000000}.
 * Consequently this target is NOT globally side-effect-free, despite not writing
 * geometry. The candidate preserves the provider invocation even at margin 0
 * and even when first==second. Do not optimize it away or add a zero-length guard.
 *
 * DELIVERY
 * body.c is the complete conventional-C insertion for func_001ece50, not a
 * wrapper. declarations.h carries the necessary exact prototypes and the narrow
 * Main-owned ec8c0 provider type repair. contracts.txt maps the ABI, all paths,
 * input extents, producer initialization, caller reachability, and side effects.
 * Repository files were not modified. No compiler probe, build, test, formatter,
 * linter, or validation command was run, as explicitly assigned. Retail objdump
 * was used solely to read target/provider machine code. Byte-exact compilation
 * is UNVERIFIED and belongs to Main.
 *
 * MAIN-OWNED INTEGRATION
 * 1. Replace the target INCLUDE_ASM with body.c; add the two extern declarations
 *    from declarations.h (iGpffffb3ac and f32/s32/u8 already exist in the owner).
 * 2. In src/btlTarget/btlTarget.c, migrate only ec8c0's three pointer types from
 *    RwV3d* to f32* and member accesses to [0]/[1]. This is the real two-float
 *    input contract, not a new vector layout. Other RwV3d code remains unchanged.
 *    If reshaping its conditions, preserve the retail projection chain given
 *    in contracts.txt; the existing > spelling does not preserve unordered
 *    branch senses, even though ordinary finite results agree.
 * 3. ecde0's s32 return is already correct. NEVER adopt the archived u8 result:
 *    -1 is a real full-width return and the target compares full GPR values.
 *    All three direct target callers are presently ASM and already have the
 *    recovered pointer/pointer/f32 argument order; no caller instruction repair.
 * 4. Exact matching may require compiler visibility of the existing ecde0 leaf
 *    body: retail keeps a0/a1, v1, a3, t0 alive over its jal calls. A plain external
 *    prototype cannot by itself tell a compiler which caller-saved GPRs survive.
 *    A clean ordinary-C option for Main to investigate is MOVING the existing
 *    ecde0 provider definition/marker out of btlTarget.c into this owner before
 *    ece50 (remove the original; do not duplicate or alias). This is a codegen
 *    consideration, not a legal-C or undefined-state blocker. No such move or
 *    experiment was attempted in this assignment.
 *
 * DIFFERENCES FROM THE HISTORICAL CANDIDATE
 * Read docs/probe_archive/RnE_001ece50_body.c only after the current target,
 * providers, and callers. That archive claimed a 532-byte/nd111 candidate and
 * used u8 orientation returns plus positive upper-bound '<' comparisons. Neither
 * claim/result was revalidated; neither defect was copied into this candidate.
 * The new body explicitly sequences calls and materializes intersects exactly
 * along the retail branch tree, uses true s32 orientation results, and preserves
 * !(upper<=coord) for unordered rectangle behavior. It computes wrapped next
 * before current edge, corresponding to the retail pointer construction order.
 * No unsafe arithmetic, synthetic initialization, fixed registers, assembly,
 * padding, aliases, or new object layout has been introduced.
 *
 * READ/AUDIT EVIDENCE
 * - Complete asm/nonmatchings/code1_001e/func_001ece50.s, all 150 lines,
 *   including padding at 001ED058/001ED05C. Retail orig/SLUS_217.82 disassembly
 *   0x001ECE50..0x001ED060 confirmed the executable sequence.
 * - Complete retail ecde0 0x001ECDE0..0x001ECE50 via objdump and asm/code1.s
 *   270004..270036; current btlTarget.c:183-196 provider body.
 * - Complete ec8c0 ASM (95 lines), current btlTarget.c:152-177, and complete
 *   normalizer func_003e41e0 ASM (58 lines). Its current owner remains ASM.
 * - Complete direct callers func_001eed10.s (289 lines), func_001ee610.s
 *   (429 lines), and the initialized incoming stack-pair source at retail
 *   0019711C..00197160 from asm/code1.s.
 * - Current complete list producer/removal/update bodies ee1c0, ee250, ee430,
 *   ee490 in promoted/code1_001e.c and ec790 in btlTarget.c.
 * - Normalizer's error-provider body 003df590 in promoted/code1_003d.c and
 *   complete 003df4d0 ASM (41 lines), to identify actual global write effects.
 * - Current owner declarations and nearby ed060 C loop style were reused.
 * - CSP and graph discovery were attempted first. The graph is dated Sep 4;
 *   coverage reports promoted owner metadata changed, ASM partially parsed,
 *   asm/code1.s excluded and retail orig/ excluded. Exact source/ASM fallback
 *   was therefore used. Coverage was checked for every referenced file except
 *   temporary delivery artifacts, which are intentionally outside the project.
 *
 * BOUNDED INITIALIZATION CONCLUSION
 * No genuine undefined incoming/local state was found in this target. All local
 * C values are initialized before use. The only target coordinate reads are
 * 8-byte caller pairs and initialized 8-byte vertex pairs. ec8c0's local delta
 * is exactly two initialized floats and its provider writes both words even on
 * zero length. Wider caller pathfinding defects are not inputs to this target
 * and must not be patched or cited as reasons to reject this recovery.
 */

extern u8 *iGpffffb3ac;
extern f32 func_003e41e0(f32 *out, f32 *in);
extern f32 fabsf(f32 value);

#pragma opt_propagation off
s32 func_001ec8c0(f32* first, f32* second, f32* point, f32 threshold)
{
    f32 delta[2];
    f32 pointDeltaX;
    f32 pointDeltaY;
    f32 cross;
    f32 projectedX;
    f32 projectedY;

    delta[0] = first[0] - second[0];
    delta[1] = first[1] - second[1];
    func_003e41e0(delta, delta);
    pointDeltaX = point[0] - first[0];
    pointDeltaY = point[1] - first[1];
    cross = pointDeltaX * delta[1] + pointDeltaY * -delta[0];
    projectedX = point[0] - cross * delta[1];
    projectedY = point[1] - cross * -delta[0];
    if (((first[0] < projectedX || second[0] > projectedX) &&
         (first[0] > projectedX || second[0] < projectedX)) ||
        ((first[1] < projectedY || second[1] > projectedY) &&
         (first[1] > projectedY || second[1] < projectedY)))
    {
        return 0;
    }
    return fabsf(cross) < threshold;
}

#pragma opt_propagation on

static s32 func_001ecde0(const f32* param_1, const f32* param_2, const f32* param_3)
{
    f32 cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
                (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);

    if (cross <= 0.0f)
    {
        goto nonpositive;
    }
    return 1;

nonpositive:
    return -(cross < 0.0f);
}

s32 func_001ece50(f32 *first, f32 *second, f32 margin)
{
    u8 *node;
    s32 i;

    for (node = *(u8 **)(iGpffffb3ac + 0x318);
         node != NULL;
         node = *(u8 **)(node + 0x4CC)) {
        if ((*(f32 *)(node + 8) < first[0]) &&
            (*(f32 *)(node + 0xC) < first[1]) &&
            !(*(f32 *)(node + 0x268) <= first[0]) &&
            !(*(f32 *)(node + 0x26C) <= first[1])) {
            continue;
        }
        if ((*(f32 *)(node + 8) < second[0]) &&
            (*(f32 *)(node + 0xC) < second[1]) &&
            !(*(f32 *)(node + 0x268) <= second[0]) &&
            !(*(f32 *)(node + 0x26C) <= second[1])) {
            continue;
        }
        for (i = 0; i < 4; i++) {
            s32 wrap = (i + 1) & 3;
            f32 *next = (f32 *)(node + wrap * 0x130 + 8);
            f32 *edge = (f32 *)(node + i * 0x130 + 8);
            s32 intersects;
            s32 side_a = func_001ecde0(edge, next, first);
            s32 side_b = func_001ecde0(edge, next, second);

            if (side_a != side_b) {
                side_a = func_001ecde0(first, second, edge);
                side_b = func_001ecde0(first, second, next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                return 1;
            }
            if (func_001ec8c0(first, second, edge, margin) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

