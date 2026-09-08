/* Complete ordinary-C geometry graph caller; production remains ASM.
 * func_001eca10: 964 executable bytes in the 976-byte retail window;
 * final twelve retail bytes are zero alignment. All eleven relocations
 * resolve, with 23 normalized byte differences confined to GPR allocation.
 * No executable instruction is missing. This is a source-shaping floor,
 * not a claim that a defined C match is impossible.
 *
 * Separate routing-coordinate pointers and the original-corner identity
 * pointer recover the actual lifetimes. A scalar coordinate snapshot keeps
 * each subtraction's operand load order. Node/flag declaration order closes
 * the argument and first-loop register cycle. Remaining differences exchange
 * first-loop corner/link registers and second-loop index/next-corner registers.
 * Scope/declaration/identity-type/pointer-reuse/goto variants did not close it.
 * Propagation off: 956/976, nd623. CSE off: 1008/976, nd498 (overrun).
 *
 * IMPORTANT: keep the existing private orientation DEFINITION AFTER this
 * caller, but declare it before this candidate. Putting the definition first
 * changes clobber knowledge and yields 920/976, nd664. The later exact segment
 * caller func_001ece50 must remain AFTER that definition. This measurement
 * supersedes the pre-integration recommendation to move the leaf first.
 * Do not duplicate/export the leaf or introduce explicit register bindings.
 * No native/game execution of this geometry candidate is claimed.
 *
 * Pre-integration audit (line references refer to the inspected snapshot):
 *
 * func_001eca10 recovery contract
 * ==============================
 * Authority: all 268 lines of asm/nonmatchings/btlTarget/func_001eca10.s, all 231 lines of func_001ed3a0.s, all 744 lines of func_001ed700.s, all 289 lines of func_001eed10.s, current canonical C geometry owner, and loaded retail ELF words. No compiler, build, test, formatter or linter was run. No repository files were changed.
 *
 * INPUT AND RETURN
 * s32 func_001eca10(u8 *first, u8 *second).
 * These are graph-record addresses, NOT addresses of standalone coordinate pairs. Each record has its original corner pair at +0/+4 and its routing position pair at +8/+C. This function compares the record address for identity and reads only its routing pair, exactly bytes [8,16). Its minimum readable extent is therefore 16 bytes, aligned for f32. It does not read the original pair of either input merely because it is an input, and does not read/write a neighbor array through either input.
 * Return is precisely integer 0 or 1: s4 starts at zero, changes only to one, and is copied into v0 at 001ECD9C. Nonzero tells the caller not to add the candidate adjacency edge. There is no floating return, count return, output pointer, or hidden output. It is legal for inputs to alias one another or graph corners; retail only uses self-identity checks described below.
 *
 * TARGET READ/WRITE EXTENTS
 * Battle global: only pointer at +0x318 is read. A linked obstacle node is unit+0x508, spans at least 0x4D0 bytes, and contains four embedded records beginning at node+8+i*0x130, i=0..3. Per stride base V=node+i*0x130, target reads corner V+8/+C, routing midpoint V+0x10/+0x14, linked original-corner pointer V+0x18, and active length V+0x1C. It dereferences the linked pointer only for its first two f32s. It additionally reads node+0x268/+0x26C (corner 2) and node+0x4CC (next node). No target read passes node+0x4CF. No writable graph/neighbor fields exist in this target: every store outside prologue/epilogue is to the local delta pair.
 * The actual unit allocation is 0xA70 bytes, zero-filled in full: 0019D238 allocation size, 0019D254..0019D260 memset(unit,0,0xA70). Therefore [unit+0x508,unit+0x9D8) includes the whole obstacle node. The fourth graph record ends at unit+0x9D0; prev/next at unit+0x9D0/+0x9D4 follow it. No invented array/object extent is needed.
 * Global allocation is 0xE88 bytes and is fully zero-filled at 00192BC0..00192BE8. Four extra graph records start global+0x31C+i*0x130 and finish exactly at global+0x7DC. The start record is [global+0x7DC,global+0x90C); destination is [global+0x90C,global+0xA3C). Thus all caller inputs have a real 0x130-byte backing record, much larger than target's 16-byte minimum. Start/destination original corner pairs need not be initialized by the route call because target uses only their +8/+C routing coordinates.
 *
 * REAL STACK OBJECT
 * Only f32 delta[2] is required. Stores at ECAB8/ECACC initialize both elements before length call ECAD4. On the path reaching the second length call, stores ECB00/ECB10 overwrite both elements before ECB18. Every other path skips the corresponding read/call altogether. The length provider reads exactly +0 and +4, performs sqrt(y*y+x*x), writes no caller memory, and retains no pointer. No delta element is read on a path that skips initialization. Retail frame size 0xB0 includes s0..fp register saves at +0..+0x8F, ra at +0x90, ABI/alignment space and the real pair at +0xA8/+0xAC. No 0xB0-byte C object or padding array is justified. Retail live code reaches return delay slot at 0x1ECDD0 (964 bytes); the final 12 bytes through 0x1ECDDF are trailing NOPs.
 *
 * ALL EIGHT ORIENTATION CALLS
 * Provider is the existing PRIVATE static func_001ecde0(const f32*,const f32*,const f32*), reading precisely two f32s per pointer, returning -1/0/+1, unordered cross => +1, retaining/writing nothing.
 * First loop, with E=node+i*0x130+8, L=*(f32**)(node+i*0x130+0x18), A=(f32*)(first+8), B=(f32*)(second+8):
 *   ECB64 orientation(E,L,A); ECB7C orientation(E,L,B).
 *   Only when those returns differ: ECB98 orientation(A,B,E); ECBB0 orientation(A,B,L).
 *   Intersects iff the second pair also differs. This is not a product/sign-strictness test: zero versus positive/negative is a difference.
 * Second loop, E=node+i*0x130+8, N=node+((i+1)&3)*0x130+8:
 *   ECCEC orientation(E,N,A); ECD04 orientation(E,N,B).
 *   Only when those returns differ: ECD20 orientation(A,B,E); ECD38 orientation(A,B,N).
 *   Same nested integer inequality rule.
 *
 * COMPLETE BRANCH ORDER
 * Traverse head while node != NULL and blocked == 0. First inspect all four generated links, skipping length<=0 (NOT rewritten as !(length>0), preserving unordered behavior), edge identity with first/second, or either midpoint-to-input length<1.0. If a generated link intersects, set blocked and break. Even on that path the node+0x4CC load occurs before the outer termination check.
 * If still unblocked, test whether first's routing pair lies strictly inside the rectangle between corner 0 and corner 2; if so skip rectangle-edge tests for this node, NOT mark blocked. Then do the same for second. Exact predicates are lowerX<x && lowerY<y && !(upperX<=x) && !(upperY<=y), preserving retail unordered branch senses.
 * Only if neither interior skip applies, test four wrapped rectangle edges; no identity or midpoint-distance tests apply to that loop. On intersection set blocked, break, advance node, then terminate at outer condition. Exhaustion or empty list returns zero.
 *
 * COMPLETE ACTUAL CALLER CHAIN
 * Loaded retail ELF segment: file offset 0x80, VA 0x100000, filesz 8620544. Full aligned-word scan found target JALs only at 001ED440, 001ED52C, 001ED5DC, 001ED654, all in func_001ed3a0. No literal target address words. Separate full scan for LUI+ADDIU/ORI within the following 24 instructions found no materializations (this bounded pattern scan is not a proof against arbitrary computed-address calls).
 * func_001ed3a0's first parameter is its incoming record. The four call classes supply as second parameter: each enabled linked-node record; each enabled global auxiliary record; global+0x7DC start; global+0x90C destination. Each skips record identity before target call. Linked candidates also pass clearance >= incoming f12. Target returning nonzero skips that adjacency insertion.
 * func_001ed3a0 has four direct call sites only, all in func_001ed700: EE0B0 linked-node records enabled and clearance-qualified, EE128 enabled global auxiliary records, EE158 start, EE16C destination. No literal addresses or nearby materializations were found for either function.
 * func_001ed700 has only one direct caller, func_001eed10 at EEDE0. Before it, EEDBC..EEDD8 copies both floats of the supplied start and destination into global+0x7E4/+0x7E8 and global+0x914/+0x918. This is precisely +8/+C of the two special records.
 * func_001eed10 has only one direct caller, func_00196d00 at 00197160. At 0019711C..00197138 it fills two distinct two-float locals from unit position +4/+C and movement packet destination +4/+C. It passes unit+0xEC as route output, those two initialized pairs, and margin 50.0f. Flag 0x80 selects a different path and bypasses func_001eed10. Therefore target never receives those tiny stack pairs directly: they are copied into the two full global records before the graph builder calls target.
 *
 * INITIALIZATION AND REACHABILITY
 * 00192B90 allocates and clears global before calling func_001ee1c0 at 00192C50. That initializer nulls list head, sets special-record length flags to -1, and seeds global original corners.
 * Only list insertion provider func_001ee250 writes a new non-removal head. It gets a real world sphere center via btlUnitGetSphereWorldCenter (00195850; writes all x/y/z), quantizes x/z, and calls existing func_001ec790. That provider fills every original corner pair at unit+0x510/+0x514, +0x640/+0x644, +0x770/+0x774, +0x8A0/+0x8A4. It then writes node center shorts, radius, membership bit 4 in unit+0x9C, initializes node.prev=0 and node.next=head or NULL, updates old-head.prev, and publishes unit+0x508 as head. Retail callers are 0019B1E0 (load packet flags+8 bit 0x40) and 001B24B0 (battle placement unit-list traversal). The list itself has no separate node allocation or count field.
 * func_001ee430 removes only when membership bit4 is set, clears that bit, repairs next.prev / prev.next or head, and is called by individual-unit destroy 0019D5B8 and bulk destroy 0019D6C4 before either frees the unit allocation. Target/provider calls are synchronous; target neither allocates nor frees nor retains anything.
 * func_001ed700 first gathers its four extrema/radius locals only from a nonempty obstacle list. A direct call with an empty list would leave those locals undefined, BUT its sole caller func_001eed10 first calls func_001ece50 and reaches func_001ed700 only when that returns nonzero. The current func_001ece50 returns zero on an empty head and neither mutates the list nor calls a list-mutating provider. Therefore the actual single-threaded dispatch excludes this apparent uninitialized-local case. Do not add invented initializers to explain it.
 * The builder initializes all four global auxiliary original corners before generated-link construction. For each linked-node vertex it starts selected=NULL and bestDistance=7000; it updates selection only after a strict smaller-distance test and provider rejection tests. Both normalized-direction floats, selected-corner pointer, selected radius and center are assigned on that selection path. Only selected!=NULL executes midpoint/linked-pointer/length/clearance stores (EDDC4, EDDD0, EDDD4, EDDD8, EDE54). Otherwise length=-1 (EDE64). Thus every length-enabled vertex has fully initialized midpoint and a linked pointer to a real original corner before ANY target call. All linked-node vertices are processed before adjacency generation starts at EE04C.
 * The four global auxiliary records similarly get either midpoint/link/positive length/clearance stores (EDFD4..EE010) or length=-1. Their pointer reads during selection are defined by initial zero-fill even when a previous selection failed. Stale links are not dereferenced by this target when length<=0. Active linked pointers always point into a current obstacle node or one of the four global auxiliary records; target reads only the original pair there.
 * The construction helper func_001ed060 uses original corners, not routing midpoints, checks candidate reciprocal link by pointer equality, then rectangle crossings and prior generated-link crossings, and has its own leaf func_001ed330. That other leaf returns +/-1 with zero assigned +1; it is NOT a substitute for target's private zero-preserving leaf. Both helpers read two-float pairs. func_003e41e0 reads both input components and writes both output components on every return path, including zero-length/error-report path; no phantom third component is justified.
 *
 * ADJACENCY AND SEARCH FIELDS (OWNED BY CALLERS, NOT TARGET)
 * Graph record relative layout proven by retail accesses and 0x130 spacing:
 *  +00/+04 original corner; +08/+0C routing point; +10 selected original-corner link;
 *  +14 generated-link length/disabled flag; +18 clearance;
 *  +1C accumulated path cost; +20 estimated total cost;
 *  +24 open-list link; +28 closed-list link; +2C predecessor;
 *  +30..+AC 32 neighbor-pointer slots; +B0..+12C 32 edge-distance slots.
 * The obstacle's prev/next are outside those four records, node+0x4C8/+0x4CC.
 * 001ED3A0 initializes local u16 neighbor count to zero, writes neighbor[k] and distance[k] only after target returns zero, then increments. It writes neighbor[count]=NULL at ED6C4 and returns the count. It does NOT read an old count or require caller preinitialization of a count. Its disabled-record caller paths explicitly write neighbor[0]=NULL (EE0C0 and EE138). Trailing slots beyond the sentinel need not be cleared.
 * Physical safe adjacency capacity is 31 accepted neighbors plus NULL in slot31; distance storage has 32 entries. The retail builder has no count<31 guard: the pointer terminator at count32 aliases distance[0], and larger counts exceed the record. With N list nodes, its raw candidate population is <=4N+6, minus identity and all filtering. This is a real caller-side capacity precondition, NOT evidence for an oversized target input array. I do not claim a universal geometry/population proof that accepted count<=31: the inspected allocation/list insertion code is dynamically allocated and carries no such cap. No reachable overflow was demonstrated, and this does not create a C undefined local or required write in the target candidate. The target's own entire input/capacity proof is independent: read-only 16-byte inputs, two-float pointed corners, four finite-stride records inside real storage, no neighbor-array reads/writes. Preserve this distinction rather than claiming the whole unrecovered route subsystem has been proven memory safe.
 * After graph construction, func_001eed10 requires neighbor[0] nonnull for both start and destination. It clears global open/closed heads, initializes start costs and predecessor, then uses the sentinel-terminated adjacency array. On discovery/revisit it writes next-record +1C/+20 costs, +2C predecessor, +24 open-list link; on closing it writes +28 and the global closed head. These writes explain the record lifetime but are not outputs of func_001eca10. Their initialization is controlled by graph adjacency and list membership; target needs none of the search-state fields.
 *
 * Deliverables
 *   body.c: complete ordinary-C insertion, every target branch, no fake frame objects.
 *   declarations.h: one external two-float length declaration and target prototype.
 *   contracts.txt: instruction-address evidence, caller chain, construction/dispatch, input/output/lifetime/capacity distinctions.
 *
 * Integration
 *   Replace the canonical func_001eca10 INCLUDE_ASM only.
 *   Move the EXISTING static func_001ecde0 definition before it. Do not duplicate, export, or substitute func_001ed330. Keep its compiler-known clobber behavior.
 *   Reuse existing iGpffffb3ac/type.h declarations. Add func_003e41b0 const-f32-pointer declaration.
 *   No compiler source-shaping pragmas were introduced or measured. Main owns source shaping and exact verification. This is a complete semantic recovery candidate, NOT a claim of verified byte match.
 *   Keep the explicit nested integer-inequality intersection construction: this matches the current exact func_001ece50 owner's style and retail materialized 0/1 temporary branches.
 *   Keep the generated-link loop before interior checks, the two-float midpoint exclusions, and the final node advancement even when blocked was found.
 *   Keep !upper<=value rather than replacing it with upper>value; preserve all unordered branch behavior.
 *
 * Authoritative evidence read
 *   Canonical src/btlTarget/btlTarget.c: existing func_001ec790, func_001ec8c0, private func_001ecde0, exact func_001ece50 bodies.
 *   Full ASM: func_001eca10 (268 lines), func_001ed3a0 (231), func_001ed700 (744), func_001eed10 (289), func_001ee1c0 (41), func_001ee250 (132), func_001ee430 (32), func_001ed060 (204), func_003e41b0 (17), func_003e41e0 (58), func_0019d210 (118), func_00192b90 (87), func_0019d550 (85), func_0019d670 (90).
 *   Full retail-ASM providers recovered by actual label/address, not invented missing nonmatching paths: func_001ed330, btlUnitGetSphereWorldCenter (func_00195850), memset (func_0043f9c8).
 *   Actual outer caller sections: func_00196d00 001970DC..001971B8; func_0019ae20 0019B1C8..0019B1E4; func_001b2380 001B2380..001B256C.
 *   Full asm/code1.s literal/disassembly scan located all direct calls and global+0x318 list writers. Graph/CSP discovery preceded authoritative reads.
 *   Full loaded ELF-segment aligned-word scans were repeated after Main requested gg_* Python globals. Results unchanged: eca10 four JAL sites, ed3a0 four, ed700 one, eed10 one, ee250 two, ee430 two; no literal address words for those six. Full nearby-LUI pattern scans found zero materializations. Nearby-pattern completeness is bounded to 24 subsequent instructions, not a claim against arbitrary computed control flow.
 *
 * Index coverage
 *   list_projects selected home-raikaru-Projects-Persona-3-Decomp-source-Persona4-Decompilation.
 *   CSP located target, caller and insertion owners; graph trace through the indexed Ghidra target found ed3a0 -> ed700 -> eed10, then the full retail scan extended to 196d00 and enumerated actual call sites.
 *   Explicit check_index_coverage calls covered every cited per-function ASM file and canonical source. ASM paths are partial (floating instructions/size directives); canonical source metadata_changed. asm/code1.s and orig/SLUS_217.82 are excluded/not_tracked. These limitations were handled with actual source/full-retail reads, not graph-negative claims. The broad code1_001e scope reports known gaps and pagination; no completeness claim is based on that scope result.
 *
 * Important negative-result boundaries
 *   No genuine undefined-local blocker was found in func_001eca10.
 *   Apparent empty-list undefined extrema in ed700 are unreachable through its sole actual caller because ece50 returns zero for an empty list and dispatch bypasses ed700.
 *   The target never accesses adjacency storage; real backing records and target read extents are proved. Adjacency count<=31 is an upstream precondition, not a demonstrated universal population invariant. The caller has no capacity guard; contracts.txt states the exact slots, terminator and raw candidate bound, rather than fabricating an oversized object or claiming route-wide safety.
 *   No runtime execution, compiler probes, build, tests, formatting or lint were performed, as explicitly assigned. No repository file was modified. Only dedicated /tmp/P4FreshGeometryGraph artifacts were written.
 */

extern u8 *iGpffffb3ac;
extern f32 func_003e41b0(const f32 *vector);
static s32 func_001ecde0(const f32 *first, const f32 *second, const f32 *point);

s32 func_001eca10(u8 *first, u8 *second)
{
    u8 *node;
    s32 blocked;
    s32 i;
    s32 j;
    f32 delta[2];
    f32 coordinate;

    blocked = 0;
    for (node = *(u8 **)(iGpffffb3ac + 0x318);
         node != NULL && blocked == 0;
         node = *(u8 **)(node + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            u8 *vertex = node + i * 0x130;
            f32 *corner;
            f32 *midpointX;
            f32 *midpointY;
            f32 *edge;
            f32 *next;
            s32 side_a;
            s32 side_b;
            s32 intersects;

            if (*(f32 *)(vertex + 0x1C) <= 0.0f) {
                continue;
            }
            corner = (f32 *)(vertex + 8);
            if ((u8 *)corner == first || (u8 *)corner == second) {
                continue;
            }
            midpointX = (f32 *)(vertex + 0x10);
            coordinate = *midpointX;
            delta[0] = coordinate - *(f32 *)(first + 8);
            midpointY = (f32 *)(vertex + 0x14);
            coordinate = *midpointY;
            delta[1] = coordinate - *(f32 *)(first + 0xC);
            if (func_003e41b0(delta) < 1.0f) {
                continue;
            }
            coordinate = *midpointX;
            delta[0] = coordinate - *(f32 *)(second + 8);
            coordinate = *midpointY;
            delta[1] = coordinate - *(f32 *)(second + 0xC);
            if (func_003e41b0(delta) < 1.0f) {
                continue;
            }
            next = *(f32 **)(node + i * 0x130 + 0x18);
            edge = (f32 *)(node + i * 0x130 + 8);
            side_a = func_001ecde0(edge, next, (f32 *)(first + 8));
            side_b = func_001ecde0(edge, next, (f32 *)(second + 8));
            if (side_a != side_b) {
                side_a = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), corner);
                side_b = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                blocked = 1;
                break;
            }
        }
        if (blocked != 0) {
            continue;
        }
        if ((*(f32 *)(node + 8) < *(f32 *)(first + 8)) &&
            (*(f32 *)(node + 0xC) < *(f32 *)(first + 0xC)) &&
            !(*(f32 *)(node + 0x268) <= *(f32 *)(first + 8)) &&
            !(*(f32 *)(node + 0x26C) <= *(f32 *)(first + 0xC))) {
            continue;
        }
        if ((*(f32 *)(node + 8) < *(f32 *)(second + 8)) &&
            (*(f32 *)(node + 0xC) < *(f32 *)(second + 0xC)) &&
            !(*(f32 *)(node + 0x268) <= *(f32 *)(second + 8)) &&
            !(*(f32 *)(node + 0x26C) <= *(f32 *)(second + 0xC))) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            s32 wrap = (j + 1) & 3;
            f32 *next = (f32 *)(node + wrap * 0x130 + 8);
            f32 *edge = (f32 *)(node + j * 0x130 + 8);
            s32 intersects;
            s32 side_a = func_001ecde0(edge, next, (f32 *)(first + 8));
            s32 side_b = func_001ecde0(edge, next, (f32 *)(second + 8));

            if (side_a != side_b) {
                side_a = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), edge);
                side_b = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                blocked = 1;
                break;
            }
        }
    }
    return blocked;
}
