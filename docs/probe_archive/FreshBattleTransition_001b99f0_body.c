/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Main current-owner compiler replay: 1008/1008 bytes, nd259, five object relocations.
 * nd counts relocation-masked differing executable bytes, including overruns.
 * No native behavioral verification was run for this unpromoted candidate.
 * One initial compiler replay only; no source-layout sweep.
 * Production remains the original ASM fallback, including unchanged providers.
 *
 * Agent reconstruction evidence follows (its no-compilation statement describes
 * agent work before Main performed the compiler replay recorded above).
 * Target: func_001b99f0, retail [0x001b99f0,0x001b9de0), 0x3f0 bytes.
 * Artifacts: body.c is the full callback; declarations.c contains the required
 * owner-local declaration relocation and two additions. Production is untouched.
 * No compilation, build, test, formatter, linter, or layout sweep was performed,
 * as explicitly required by the assignment. Matching is unmeasured.
 * 
 * ABI / real storage
 * - btlMain.c:17-25 defines BtlPacketFunc as u32 (*)(void*), with updateFunc
 *   at packet+0x6c and workData at packet+0x78. The existing constructor
 *   func_001b9de0, btlMain.c:700-713, allocates type 0x606 with 0x10 work bytes,
 *   installs this function as updateFunc, and initializes work+0, +4, +8, +0xc.
 * - Entry at 1b9a18 saves incoming a0 as the work address; 1b9a20 reads its
 *   first word as an external action pointer. The work is not a BtlPacket,
 *   BtlUnit, or a stack allocation. Callback signature remains u32(void*).
 * - Work layout: +0 action pointer (4 bytes), +4 total frames (u32), +8 current
 *   frame (u32), +0xc resource index (u16). No field is fabricated for +0xe.
 *   Only work+8 is written by this callback. The highest work byte read is
 *   +0xd, safely within the constructor's 16-byte allocation.
 * - Allocator source, promoted/code1_0019.c:1067-1105, allocates workSize+0x90,
 *   clears that extent, and sets packet+0x78 to allocation+0x90 for positive
 *   workSize. No local packet copy or manufactured return is necessary.
 * - Existing BtlAction declaration in Battle/btlAction.c:28-44 identifies its
 *   unit pointer at +0x30. It does not define the target tail. This proposal
 *   follows the owner's existing raw-offset idiom rather than inventing a
 *   complete action or unit structure. Retail reads targetCount u16 at +0x6a,
 *   action-pointer entries at +0x38 + 4*index, and each target's unit at +0x30.
 * - BtlUnit source declaration in Battle/btlUnit.c:59-80 identifies color at
 *   +0x30, flags2 at +0x98, and flags3 at +0x9c. It deliberately stops before
 *   the linked-list/resource tail; that is not a bound on real unit storage.
 *   This target demonstrably reads a u16 resource/state field at +0x9fe and
 *   a next-unit pointer at +0xa6c. Existing neighbor func_001b9e50 independently
 *   traverses these exact same fields (btlMain.c:765-783). No new unit padding
 *   or guessed enclosing size is introduced.
 * - The global at gp-0x4c48 is iGpffffb3b8 (existing u8* declarations in
 *   btlAICommand.c:96 and promoted/code1_001f.c:64). It is indexed by the
 *   zero-extended work resource index at stride 0x28, reading byte +0x11.
 *   The global at gp-0x4c54 is the owner's existing iGpffffb3ac.
 * 
 * Real providers
 * - func_001f0ff0 is defined at promoted/code1_001f.c:693-699 as s32(u32).
 *   It reads action+0x6e and calls func_001d7f10(action,0,index,0), returning
 *   whether its low 16 bits are zero. The proposal declares exactly this
 *   existing ABI and casts the already-real 32-bit action pointer to u32.
 *   No invented extra argument, hidden return, or prototype rewrite is used.
 * - FUN_00194F60 is btlUnitSetColor at Battle/btlUnit.c:1099-1104:
 *   void(BtlUnit*, RwRGBA), with four u8 channels passed by value. It stores
 *   cols[0] and sets flags2 bit 2. The existing btlMain.c:717-725 declaration
 *   already gives func_00194f60 this ABI; only its position must move above
 *   the new body. The retail call loads a0=unit and a1=the packed four-byte
 *   color (1b9d6c-1b9d78). The ONLY addressable local storage needed is one
 *   fully initialized four-byte RwRGBA, not a packet or synthetic scratch.
 * 
 * Complete control-flow and state map
 * 1. 1b9a18-1b9aa4: result starts at 1. Immediate completion if global+0x10
 *    has bit 3, indexed resource byte equals 0x10, or targetCount < 2 while
 *    the acting unit's +0xa2 category is nonzero. These exits neither call
 *    the predicate/color setter nor increment currentFrame.
 * 2. 1b9aa8-1b9b38: call predicate once. If nonzero, affectedMask is the low
 *    16 bits of 1 << actor category, protectedMask=0. Otherwise affectedMask=3
 *    and protectedMask ORs the low-16-bit category bit of every target unit.
 *    The loop counter is u16 and wraps as retail masks do; targetCount is
 *    loaded once for that loop. The action target entries are pointers to
 *    actions, not directly to units: both pointer dereferences are retained.
 * 3. 1b9b38-1b9bb0: if actor category=0, scan targets for any nonzero category.
 *    Start allTargetsOnSideZero=1, clear it and break on the first nonzero.
 *    If still set, return 1 with no timer increment or color update. Zero
 *    targets therefore also complete immediately for actor category=0.
 *    This second loop reloads the count and re-walks targets rather than
 *    substituting protectedMask: that preserves retail's actual condition.
 * 4. 1b9bb4-1b9cc0: unsigned current < total selects
 *      alpha = (u8)(255.0f * (1.0f - (f32)current / (f32)total)), result=0.
 *    Otherwise alpha=0 and result remains 1. Unsigned conversion is required:
 *    retail contains the unsigned-u32-to-f32 paths for both operands and
 *    unsigned conversion of the resulting color byte. Division is not reached
 *    for total=0. No float-to-signed-int shortcut or integer interpolation.
 * 5. 1b9cc0-1b9d9c: exactly two lists; reload the global base and fetch each
 *    head at global+0x178+8*listIndex. Walk until NULL, taking next from +0xa6c.
 *    Skip if u16 +0x9fe=0, category not included in affectedMask, or flags3
 *    bit 0 set. For selected units copy RGB only from +0x30,+0x31,+0x32.
 *    Set alpha to the fade alpha only when unit != actor and its category is
 *    absent from protectedMask; otherwise set alpha=255. Invoke color setter
 *    once per selected unit even if the resulting color is unchanged.
 * 6. 1b9da0-1b9dac: reload currentFrame from work+8, increment modulo 2^32,
 *    store, and return result. This happens even on the terminal alpha-zero
 *    iteration (current >= total). Early exits in steps 1 and 3 do not increment.
 * 
 * Reload / alias behavior retained
 * - Action pointer is captured once before all gates and predicate call.
 * - Actor unit/category is freshly loaded after the predicate and again for
 *   the side-zero test. The actor pointer is read afresh for every color choice.
 * - Each target pass obtains its own targetCount snapshot. Masks remain snapshots
 *   across the color setter calls, as retail saves them in preserved registers.
 * - The current unit's next link is loaded after color setter, not prefetched.
 *   The next list head reloads iGpffffb3ac after prior list calls.
 * - Work currentFrame is reloaded after all setters, rather than writing the
 *   previously captured current+1. Raw offset accesses preserve the existing
 *   owner's alias model; no restrict, const-derived snapshots, or pragmas added.
 * 
 * Bounds / uncertainties
 * - Retail trusts the action pointer, actor pointer, targetCount and target
 *   pointers, resource index and global allocation, and list node extents.
 *   This function contains no bounds checks for these external data structures;
 *   none have been invented. No claim is made about a maximum target capacity
 *   or resource-table length that the available declarations do not establish.
 * - Categories are used as shift counts for 32-bit category bits, then truncated
 *   to u16, exactly the conventional source expression implied by sllv/andi.
 *   Valid game category values are required to be <32 for defined C shifts;
 *   retail's hardware masks invalid counts. No unsupported extra category
 *   validation or special-case input behavior has been added.
 * - The semantic meaning/name of +0x9fe is not proven; evidence identifies only
 *   the nonzero resource/state gate. The body intentionally retains raw access.
 * - Existing constructor is declared void despite generated action consumers
 *   using its result as a packet. This proposal does not alter that separate
 *   constructor ABI issue, add a forwarding shim, or manufacture a return.
 * - Graph coverage was checked for all consulted source owners. btlMain.c,
 *   btlUnit.c and promoted/code1_001f.c were marked metadata_changed and direct
 *   source was used; retail ASM is parse_partial and was read in full. Generated
 *   action context is supplementary only, not a provider-signature authority.
 */

/* Move the existing btlMain.c BtlUnit/RwRGBA declarations and
 * func_00194f60 prototype (currently immediately before func_001b9e50)
 * before func_001b99f0; do not retain duplicate declarations below it. */
typedef struct BtlUnit BtlUnit;
typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;
extern void func_00194f60(BtlUnit* unit, RwRGBA col);

/* New owner-local declarations. The pointer global has the same declaration
 * in btlAICommand.c and promoted/code1_001f.c. The predicate's signature is
 * copied from its real provider at promoted/code1_001f.c:694. */
extern u8* iGpffffb3b8;
extern s32 func_001f0ff0(u32 arg0);

// FUN_001B99F0
u32 func_001b99f0(void* work)
{
    RwRGBA color;
    BtlUnit* unit;
    u8* action;
    u8* workBytes;
    u16 resourceIndex;
    u16 affectedMask;
    u16 protectedMask;
    u16 unitMask;
    u16 targetIndex;
    u16 listIndex;
    s32 targetCount;
    s32 allTargetsOnSideZero;
    u32 result;
    u32 total;
    u32 current;
    u8 alpha;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;

    workBytes = (u8*)work;
    result = 1;
    action = *(u8**)workBytes;
    resourceIndex = *(u16*)(workBytes + 0xC);
    if ((*(u32*)(iGpffffb3ac + 0x10) & 8) != 0)
    {
        return 1;
    }
    if (*(u8*)(iGpffffb3b8 + (u32)resourceIndex * 0x28 + 0x11) == 0x10)
    {
        return 1;
    }
    if (*(u16*)(action + 0x6A) < 2 &&
        *(u8*)(*(u8**)(action + 0x30) + 0xA2) != 0)
    {
        return 1;
    }

    if (func_001f0ff0((u32)action) != 0)
    {
        affectedMask = (u16)(1U << *(u8*)(*(u8**)(action + 0x30) + 0xA2));
        protectedMask = 0;
    }
    else
    {
        affectedMask = 3;
        protectedMask = 0;
        targetIndex = 0;
        targetCount = *(u16*)(action + 0x6A);
        for (; targetIndex < targetCount; targetIndex = (u16)(targetIndex + 1))
        {
            protectedMask |= (u16)(1U << *(u8*)(
                *(u8**)(*(u8**)(action + (u32)targetIndex * 4 + 0x38) + 0x30) + 0xA2));
        }
    }

    if (*(u8*)(*(u8**)(action + 0x30) + 0xA2) == 0)
    {
        allTargetsOnSideZero = 1;
        targetIndex = 0;
        targetCount = *(u16*)(action + 0x6A);
        for (; targetIndex < targetCount; targetIndex = (u16)(targetIndex + 1))
        {
            if (*(u8*)(*(u8**)(*(u8**)(action + (u32)targetIndex * 4 + 0x38) + 0x30) + 0xA2) != 0)
            {
                allTargetsOnSideZero = 0;
                break;
            }
        }
        if (allTargetsOnSideZero != 0)
        {
            return 1;
        }
    }

    total = *(u32*)(workBytes + 4);
    current = *(u32*)(workBytes + 8);
    if (current < total)
    {
        currentFloat = (f32)current;
        totalFloat = (f32)total;
        ratio = currentFloat / totalFloat;
        alpha = (u8)(255.0f * (1.0f - ratio));
        result = 0;
    }
    else
    {
        alpha = 0;
    }

    listIndex = 0;
    for (; listIndex < 2; listIndex = (u16)(listIndex + 1))
    {
        unit = *(BtlUnit**)(iGpffffb3ac + (u32)listIndex * 8 + 0x178);
        while (unit != NULL)
        {
            if (*(u16*)((u8*)unit + 0x9FE) != 0)
            {
                unitMask = (u16)(1U << *(u8*)((u8*)unit + 0xA2));
                if ((affectedMask & unitMask) != 0 &&
                    (*(u32*)((u8*)unit + 0x9C) & 1) == 0)
                {
                    color.red = *(u8*)((u8*)unit + 0x30);
                    color.green = *(u8*)((u8*)unit + 0x31);
                    color.blue = *(u8*)((u8*)unit + 0x32);
                    if (unit != *(BtlUnit**)(action + 0x30) &&
                        (protectedMask & unitMask) == 0)
                    {
                        color.alpha = alpha;
                    }
                    else
                    {
                        color.alpha = 0xFF;
                    }
                    func_00194f60(unit, color);
                }
            }
            unit = *(BtlUnit**)((u8*)unit + 0xA6C);
        }
    }

    *(u32*)(workBytes + 8) = *(u32*)(workBytes + 8) + 1;
    return result;
}
