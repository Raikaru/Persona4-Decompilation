/* Original translation unit fclCombineMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
#include "datUnit_internal.h"

/* The fusion scan advances by 14 bytes and reads these base-table members. */
typedef struct FclFusionBaseEntry {
    u16 flags;
    u8 arcana;
    u8 level;
    u8 pad04[6];
    u16 inheritance;
    u8 pad0c[2];
} FclFusionBaseEntry;
typedef struct FclFusionGate {
    s32 flag;
    s16 persona;
    s16 flags;
} FclFusionGate;

extern s32 fclCombineRecipeMatchMask(u16 *, u16 *, s32, s16 *);
extern s32 datPersonaAddSkill(u8 *, u16);
extern s32 datPersonaFindSkillSlot(u8 *, u16);
extern s32 fclFusePair(u16 *output, u16 first, u16 second);
extern s32 fclFuseTriple();
extern u32 RpRandom();
extern s16 yListSlotIndexOf(s8 list, s16 id);
extern u8 *yListSlotEntry(s8 list, s16 index);
extern void memcpy(void *dst, void *src, u32 size);
extern void kAssertFail(void *file, s32 line);
extern void *memset(void *dst, s32 value, u32 size);
extern void datPersonaInitRecord(u8 *persona, u16 personaId);
extern u8 *iGpffffb3d4;
extern char D_00642F30[];
extern s32 fclFuseRecipeLookup(u16 *output, s32 recipeKind, u16 *ingredients, s32 ingredientCount);
extern u8 fclFuseTripleArcana(u8 *firstPersona, u8 *secondPersona, u8 *thirdPersona);
extern s32 fclFuseLowestCandidateAtLeast(u32 arcana, s32 minimumLevel, u16 *excluded);
extern s32 datGetFlag(s32 bit);
extern u8 D_006420A0[];
extern u8 D_00642F00[];
extern u8 D_00642F04[];
extern s8 func_002ac350(void);
extern s32 fclFuseLowestCandidateAtMost(u32 arcana, s32 maximumLevel, u16 *excluded);
extern u8 D_00642147[];
extern u8 D_00642387[];

extern s8 iGpffffa8d0[6];
extern u8 D_00642727[];
extern u8 D_00642967[];

static inline u8 fclTriangleUpperArcana(s32 first, s32 second)
{
    if (first == 0 || second == 0)
        kAssertFail(D_00642F30, 0x90);
    if (first < second)
        return *(second + (D_00642967 + first * 24));
    return *(first + (D_00642967 + second * 24));
}

/* Ordered pointer slots and arcana snapshots preserve retail tie-breaking. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00311EA0
u8 fclFuseTripleArcana(u8 *firstPersona, u8 *secondPersona, u8 *thirdPersona)
{
    s8 pairs[3][2];
    u8 *personas[4];
    u8 *clear;
    s32 remaining;
    s8 *source;
    s8 *destination;
    s32 copies;
    s8 firstByte;
    s8 secondByte;
    s16 pairIndex;
    u8 *base;
    s8 *pair;
    u8 **leftSlot;
    u8 **rightSlot;
    u8 *right;
    u8 *left;
    s32 leftLevel;
    s32 rightLevel;
    s32 firstArcana;
    u8 secondArcana;
    u8 thirdArcana;
    s32 result;
    s32 secondKey;
    s32 thirdKey;
    u8 resultByte;

    clear = (u8 *)personas;
    remaining = sizeof(personas);
    if (clear != NULL) {
        do {
            *clear++ = 0;
            remaining--;
        } while (remaining != 0);
    }
    personas[0] = firstPersona;
    personas[1] = secondPersona;
    personas[2] = thirdPersona;
    source = iGpffffa8d0;
    destination = (s8 *)&pairs;
    copies = 3;
    do {
        firstByte = source[0];
        secondByte = source[1];
        source += 2;
        copies--;
        destination[0] = firstByte;
        destination[1] = secondByte;
        destination += 2;
    } while (copies > 0);
    if (firstPersona == NULL || secondPersona == NULL || thirdPersona == NULL)
        kAssertFail(D_00642F30, 0x156);
    pairIndex = 0;
    base = iGpffffb3d4;
    while (pairIndex < 3) {
        pair = pairs[pairIndex];
        rightSlot = &personas[pair[1]];
        right = *rightSlot;
        rightLevel = ((DatPersonaRecord *)right)->level;
        leftSlot = &personas[pair[0]];
        left = *leftSlot;
        leftLevel = ((DatPersonaRecord *)left)->level;
        if (leftLevel < rightLevel ||
            (leftLevel == rightLevel &&
             *((u8 *)((u32)base + ((DatPersonaRecord *)left)->id * 14) + 2) > *((u8 *)((u32)base + ((DatPersonaRecord *)right)->id * 14) + 2))) {
            pair = pairs[pairIndex];
            leftSlot = &personas[pair[0]];
            personas[3] = left;
            rightSlot = &personas[pair[1]];
            *leftSlot = *rightSlot;
            *rightSlot = personas[3];
        }
        pairIndex++;
    }
    base = iGpffffb3d4 + 2;
    firstArcana = base[((DatPersonaRecord *)personas[0])->id * 14];
    secondArcana = base[((DatPersonaRecord *)personas[1])->id * 14];
    thirdArcana = base[((DatPersonaRecord *)personas[2])->id * 14];
    if (firstArcana == 0 || secondArcana == 0 || thirdArcana == 0)
        kAssertFail(D_00642F30, 0x167);
    secondKey = secondArcana;
    if (secondKey == 0 || thirdArcana == 0)
        kAssertFail(D_00642F30, 0x90);
    thirdKey = thirdArcana;
    if (secondKey < thirdKey)
        resultByte = *(thirdKey + (D_00642727 + secondKey * 24));
    else
        resultByte = *(secondKey + (D_00642727 + thirdKey * 24));
    result = resultByte;
    if (result == 0)
        return 0;
    return fclTriangleUpperArcana(firstArcana, result);
}
#pragma pop

/* Measured: 640/640 bytes and all 16 relocations match retail.
 * Ordinary s32 counters produce the quadword spill; persona/skill inputs
 * use the same halfword contracts as their providers and other callers. */
/* Search the selected 0x20-byte recipe rows, enforce flag gates, and copy up to four bonus skills.
 * Recipe table aliases and halfword skill cursors retain their external byte layout. */
// FUN_00312220
s32 fclFuseRecipeLookup(u16 *output, s32 recipeKind, u16 *ingredients, s32 ingredientCount) {
    s32 count;
    s16 matched;
    s32 row;
    s32 threshold;
    u16 *entry;
    s32 key;
    s32 allowed;
    s32 result;
    s32 gate;
    u32 flagIndex;
    s32 skillIndex;
    u8 *flag;
    s16 bits;
    u16 *skill;
    if (output == NULL || ingredients == NULL || recipeKind >= 5)
        kAssertFail(D_00642F30, 0x17B);
    entry = *(u16 **)(D_00642F00 + recipeKind * 8);
    count = *(s32 *)(D_00642F04 + recipeKind * 8);
    row = 0;
    threshold = (s16)(recipeKind + 2);
    while (row < count) {
        matched = 0;
        result = fclCombineRecipeMatchMask(entry, ingredients, ingredientCount, &matched);
        result = matched >= threshold ? result : 0;
        if (result != 0) {
            key = *entry;
            allowed = 1;
            for (flagIndex = 0; flagIndex < 0x17U; flagIndex++) {
                flag = D_006420A0 + flagIndex * 8;
                if (key == ((FclFusionGate *)flag)->persona) {
                    bits = ((FclFusionGate *)flag)->flags;
                    if (bits & 1) {
                        if (datGetFlag(((FclFusionGate *)flag)->flag) == 0) {
                            gate = 0;
                            goto flag_done;
                        }
                    } else if (bits & 2) {
                        allowed = 0;
                        if (datGetFlag(((FclFusionGate *)flag)->flag) == 1) {
                            gate = 1;
                            goto flag_done;
                        }
                    }
                }
            }
            gate = allowed;
flag_done:
            if (gate) {
                datPersonaInitRecord((u8 *)output, *entry);
                for (skillIndex = 0; skillIndex < 4; skillIndex++) {
                    skill = (u16 *)((u8 *)&entry[skillIndex] + 24);
                    if (*skill != 0 && datPersonaFindSkillSlot((u8 *)output, *skill) == -1 &&
                        datPersonaAddSkill((u8 *)output, *skill) == 0) break;
                }
                return iGpffffb3d4[output[1] * 14 + 2];
            }
        }
        entry += 16;
        row++;
    }
    return 0;
}

static inline u8 fclNormalPairArcana(s32 first, s32 second)
{
    if (first == 0 || second == 0)
        kAssertFail(D_00642F30, 0x90);
    if (first < second)
        return *(second + (D_00642147 + first * 24));
    return *(first + (D_00642147 + second * 24));
}

static inline u8 fclAlternatePairArcana(s32 first, s32 second)
{
    if (first == 0 || second == 0)
        kAssertFail(D_00642F30, 0x90);
    if (first < second)
        return *(second + (D_00642387 + first * 24));
    return *(first + (D_00642387 + second * 24));
}

/* Measured: 828/832 bytes, 26 resolved relocations, four zero tail bytes.
 * Promoted lookup inputs avoid an extra saved register; byte-return helpers
 * preserve retail narrowing. All ten neighboring owner images remain exact. */
// Fcl fusion: fuses personas 'first' and 'second' into 'output' (1), returns 2 for an excluded pair, 0 when no result.
// FUN_003124A0
s32 fclFusePair(u16 *output, u16 first, u16 second)
{
    u16 pair[2];
    u16 excluded[12];
    s32 secondIndex;
    u8 *base;
    u8 *arcana;
    u8 *levels;
    u8 firstArcana;
    u8 secondArcana;
    u32 result;
    s32 level;
    u16 persona;

    pair[0] = first;
    pair[1] = second;
    if (output == NULL || first == 0 || second == 0)
        kAssertFail(D_00642F30, 0x1A1);
    if (fclFuseRecipeLookup(output, 0, pair, 2) & 0xFF)
        return 2;
    secondIndex = second * 14;
    arcana = iGpffffb3d4 + 2;
    secondArcana = arcana[secondIndex];
    firstArcana = arcana[first * 14];
    if (func_002ac350() == 0)
        result = fclNormalPairArcana(firstArcana, secondArcana);
    else
        result = fclAlternatePairArcana(firstArcana, secondArcana);
    if ((u8)result == 0) {
        memset(output, 0, 0x30);
        return 0;
    }
    memset(excluded, 0, 0x18);
    excluded[0] = first;
    excluded[1] = second;
    base = iGpffffb3d4;
    levels = base + 3;
    level = ((levels[first * 14] + levels[secondIndex]) / 2 + 1) & 0xFF;
    arcana = base + 2;
    if ((u8)result == arcana[first * 14] && (u8)result == arcana[secondIndex]) {
        persona = fclFuseLowestCandidateAtMost(result, level, excluded);
        if (persona == 0) return 0;
    } else {
        persona = fclFuseLowestCandidateAtLeast(result, level, excluded);
        if (persona == 0) return 0;
    }
    datPersonaInitRecord((u8 *)output, persona);
    return 1;
}

/* Fuse three roster personas using their arcana and average base level plus five. */
// FUN_003127E0
s32 fclFuseTriple(u16 *output, u8 *firstPersona, u8 *secondPersona, u8 *thirdPersona) {
    u16 ingredients[3];
    u8 excluded[0x18];
    s32 arcana;
    u16 personaId;
    u8 *levels;

    ingredients[0] = ((DatPersonaRecord *)firstPersona)->id;
    ingredients[1] = ((DatPersonaRecord *)secondPersona)->id;
    ingredients[2] = ((DatPersonaRecord *)thirdPersona)->id;
    if (output == NULL || firstPersona == NULL || secondPersona == NULL || thirdPersona == NULL) {
        kAssertFail(D_00642F30, 0x1CC);
    }
    if (fclFuseRecipeLookup(output, 1, ingredients, 3) & 0xFF) {
        return 2;
    }
    arcana = fclFuseTripleArcana(firstPersona, secondPersona, thirdPersona) & 0xFF;
    if (arcana == 0) {
        memset(output, 0, 0x30);
        return 0;
    }
    memset(excluded, 0, 0x18);
    *(u16 *)&excluded[0] = ((DatPersonaRecord *)firstPersona)->id;
    *(u16 *)&excluded[2] = ((DatPersonaRecord *)secondPersona)->id;
    *(u16 *)&excluded[4] = ((DatPersonaRecord *)thirdPersona)->id;
    levels = iGpffffb3d4 + 3;
    personaId = fclFuseLowestCandidateAtLeast(arcana, (((s32)levels[((DatPersonaRecord *)firstPersona)->id * 0xE] + (s32)levels[((DatPersonaRecord *)secondPersona)->id * 0xE] + (s32)levels[((DatPersonaRecord *)thirdPersona)->id * 0xE]) / 3 + 5) & 0xFF, (u16 *)excluded) & 0xFFFF;
    if (personaId == 0) {
        return 0;
    }
    datPersonaInitRecord((u8 *)output, personaId);
    return 1;
}

/* Copy the non-special partner when exactly one input is in the four-entry special list. */
// FUN_003129B0
s32 fclFuseSpecialPartner(u8 *output, s32 first, s32 second) {
    s16 specialPartners[4];
    s16 i;
    s16 j;
    s32 firstId;
    s32 secondId;

    specialPartners[0] = 0xD;
    specialPartners[1] = 0x35;
    specialPartners[2] = 0x49;
    specialPartners[3] = 0x66;
    i = 0;
    firstId = first & 0xFFFF;
    secondId = second & 0xFFFF;
    while (i < 4) {
        if (firstId == specialPartners[i]) {
            j = 0;
            while (j < 4) {
                if (secondId == specialPartners[j]) {
                    return 0;
                }
                j++;
            }
        }
        i++;
    }
    j = 0;
    while (j < 4) {
        if (firstId == specialPartners[j]) {
            memcpy(output, yListSlotEntry(0, yListSlotIndexOf(0, (s16)second)), 0x30);
            return 1;
        }
        if (secondId == specialPartners[j]) {
            memcpy(output, yListSlotEntry(0, yListSlotIndexOf(0, (s16)first)), 0x30);
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_00312B60
s32 fclFusePairByte(s32 output, s32 first, s32 second) {
    return fclFusePair((u16 *)output, first & 0xFFFF, second & 0xFFFF) & 0xFF;
}

// FUN_00312B90
s32 fclFuseTripleByte(u16 *output, u8 *first, u8 *second, u8 *third) {
    return fclFuseTriple(output, first, second, third) & 0xFF;
}

// Fcl rare chance roll: returns 1 with a 1/64 chance for kind 2 and 1/32 for kind 3, else 0.
// FUN_00312BC0
#pragma opt_rebuildconditionals off
/* measured: without this, mwcc b210 booleanizes `if (roll < 0x40) return 1; return 0;`
   into slti $v0 + unconditional branch (return value = condition); retail keeps
   beqz $at -> shared return-0 + addiu $v0,1. Both branch orientations and the
   if/else forms tried (nd 24); with the pragma the switch body matches exactly. */
s32 fclRollRareChance(s8 kind) {
    s32 roll;
    switch (kind) {
    case 2:
        roll = (s32)(RpRandom() & 0x3F) << 6;
        if (roll < 0x40) {
            return 1;
        }
        break;
    case 3:
        roll = (s32)(RpRandom() & 0x1F) << 5;
        if (roll < 0x20) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
#pragma opt_rebuildconditionals on

typedef struct {
    s8 minCount;
    s8 picks;
} FclSkillPickTier;

/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u32 datPersonaCountSkills(void *persona);
extern u8 *yListAllocIndexTable(void);
extern void fclListAddUnique(u8 *list, s16 itemId);
extern void fclListRemoveId(u8 *list, s16 itemId);
extern void fclFreeWorkBlock(u8 *work);
extern void func_00440b68(const void *message);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *iGpffffb3b4;
extern FclSkillPickTier D_00641C20[];
extern s16 D_00641C40[][19];
extern s8 D_00641E60[];
extern char D_00642F50[];

/* Select the highest pool-size tier whose minimum has been reached. */
static inline s32 fclSkillPickCount(s16 count)
{
    s32 step;

    for (step = 8; step >= 0; step--) {
        if (D_00641C20[step].minCount <= count) {
            return D_00641C20[step].picks;
        }
    }
    return 0;
}

/* Scale the persona inheritance-table weight by the skill's signed rate. */
static inline s32 fclSkillWeight(u16 *persona, s32 id)
{
    s32 arcana;
    s32 base;
    s8 rate;

    if (persona == NULL) {
        kAssertFail(D_00642F30, 0x327);
    }
    arcana = (s8)iGpffffb3b4[id * 2];
    if (arcana == -1) {
        arcana = 0x12;
    }
    base = D_00641C40[((FclFusionBaseEntry *)(iGpffffb3d4 + persona[1] * 0xE))->inheritance][arcana];
    rate = D_00641E60[id];
    if (rate == 0) {
        return 0;
    }
    return base * 10 / rate;
}

/* Fusion skill picker: pools the deck skills the persona lacks, looks up how
   many to grant from the pool-size tier table, then draws that many weighted
   picks into free skill slots. Shaping that matters: the per-pick weight is
   stored first and then re-read for the running total, the pick loop bound is
   the byte view of the pool count captured after the roll, the pool entries
   and deck cells are passed through their signed-halfword views, and the tier
   test reads table <= count.
   measured: without `opt_loop_invariants on` the body grows to 1164 bytes
   (250 differing words); retail hoists the deck-count sign extension and the
   tier-table base out of their loops. */
/* The pool count at +0x60 is read as both s16 and its low byte; retain those
   storage views to preserve the narrowing described above. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00312C60
s8 fclFuseRollPersona(u16 *persona, u8 *deck, s32 deckCount)
{
    u8 *pool;
    s32 *weights;
    s32 remaining;
    s32 total;
    s8 taken;
    s32 roll;
    u8 n;
    s16 k;
    s16 i;
    u8 *row;
    s16 scan;
    s32 running;
    u16 *cell;
    s32 id;
    s16 j;
    s16 freeSlots;
    s16 pick;

    taken = 0;
    if (persona == NULL) {
        kAssertFail(D_00642F30, 0x3AF);
    }
    pool = yListAllocIndexTable();
    for (i = 0; i < (s8)deckCount; i++) {
        j = 0;
        row = deck + i * 0x30;
        for (; j < 8; j++) {
            cell = (u16 *)(row + j * 2 + 0xC);
            if (*cell != 0 && datPersonaFindSkillSlot((u8 *)persona, *cell) == -1) {
                fclListAddUnique(pool, (s16)*cell);
            }
        }
    }
    remaining = fclSkillPickCount(*(s16 *)(pool + 0x60));
    freeSlots = 8 - datPersonaCountSkills(persona);
    if (freeSlots == 0) {
        func_00440b68(D_00642F50);
        fclFreeWorkBlock(pool);
        return 0;
    }
    if (freeSlots < remaining) {
        remaining = freeSlots;
    }
    chkmemAllocSiteTag(D_00642F30, 0x3CC);
    weights = (*jtbl_008873E8)(*(s16 *)(pool + 0x60) * 4, 0x40000);
    while (remaining != 0) {
        total = 0;
        for (k = 0; k < *(s16 *)(pool + 0x60); k++) {
            id = ((s16 *)pool)[k];
            weights[k] = fclSkillWeight(persona, id);
            total += weights[k];
        }
        if (total == 0) {
            break;
        }
        running = 0;
        roll = RpRandom() % total;
        n = pool[0x60];
        for (pick = 0; pick < n; pick++) {
            running += weights[pick];
            if (roll < running) {
                for (scan = 0; scan < 8; scan++) {
                    if (persona[scan + 6] == 0) {
                        taken |= (s8)(1 << scan);
                        break;
                    }
                }
                datPersonaAddSkill((u8 *)persona, ((s16 *)pool)[pick]);
                fclListRemoveId(pool, ((s16 *)pool)[pick]);
                remaining--;
                break;
            }
        }
    }
    (*jtbl_008873EC)(weights);
    fclFreeWorkBlock(pool);
    return taken;
}
#pragma pop

/* measured: retail sq's requested arcana & 0xFF into the arcana snapshot (0xA0) and lq's it back in the
   0xC0 i-loop, comparing via raw bne (lq $2,0xA0 / bne $2,$3). The old
   "u_long128 aliased scalar read-back" probe (720B window, nd528, "no legal
   C data-size spelling") was WRONG about the type: `typedef signed __int128
   s128;` (declared locally, see docs/matching.md's corrected "128-bit lq/sq
   aggregate copy" entry and effBlurFilter.c/evtPolygonMovie.c/shdSprite.c
   for the proven pattern) genuinely lowers to lq/sq and reproduces retail's
   exact -0xB0 frame and register coloring for the store/reload; a narrowing
   (s64) cast on the reload is required for the actual bne compare (s128
   itself has no legal == in b210 -- "illegal data size" -- matching that
   retail's bne is not a real 128-bit compare either). Two focused sessions
   with this real type got the residual down from nd528/541 to nd163 (712B
   vs 720B, 63 differing words in the tail/bottom-loop control-flow and
   CSE layout) but not to an exact MATCH. Still a floor for now, but NOT a
   type-spelling floor -- the residual is ordinary register-allocation/
   control-flow shape, the same category as any other near-miss. Worth
   another attempt with fresh eyes on the bottom-loop layout specifically. */
/* Select the lowest eligible level at or above the threshold, with the original highest-level fallback.
 * Byte-offset base-table accesses preserve measured alias/load ordering; entries are 14 bytes.
 * The inherited XOR-zero assignments and 128-bit snapshot are retained matching-required source shapes. */
// FUN_003130E0
s32 fclFuseLowestCandidateAtLeast(u32 arcana, s32 minimumLevel, u16 *excluded) {
    typedef signed __int128 s128;
    extern u8 *DAT_007644c4;
    u16 *input;
    s128 requestedArcana;
    s16 gateFlags;
    s32 candidateId;
    s32 candidateOffset;
    s32 levelThreshold;
    s32 highestId;
    s32 fallbackId;
    s32 tableAddress;
    s32 selectedId;
    s32 candidateIndex;
    s32 selected;
    s32 highest;
    s32 defaultAllowed;
    s32 candidateAllowed;
    s32 isExcluded;
    s32 gatePassed;
    s32 excludedIndex;
    u16 candidateFlags;
    u32 gateIndex;
    u8 candidateLevel;
    u8 *candidate;
    u8 *gateEntry;

    selected = 0;
    highest = 0;
    candidateIndex = 0;
    input = excluded;
    requestedArcana = arcana & 0xFF;
    levelThreshold = minimumLevel & 0xFF;
    for (; (candidateIndex & 0xFFFF) < 0xC0;
         candidateIndex = (candidateIndex + 1) & 0xFFFF) {
        candidateId = candidateIndex & 0xFFFF;
        candidate = iGpffffb3d4;
        candidateOffset = (u16)candidateIndex * 0xE;
        candidate += candidateOffset;
        if ((s64)requestedArcana == ((FclFusionBaseEntry *)candidate)->arcana) {
            candidateFlags = ((FclFusionBaseEntry *)candidate)->flags;
            if (candidateFlags & 1) {
                candidateAllowed = 0;
            } else if (candidateFlags & 2) {
                candidateAllowed = 0;
            } else {
                candidateAllowed = 1;
            }
            if (candidateAllowed != 0) {
                defaultAllowed = 1;
                for (gateIndex = 0; gateIndex < 0x17U; gateIndex++) {
                    gateEntry = D_006420A0 + (gateIndex * 8);
                    if (candidateId != ((FclFusionGate *)gateEntry)->persona) {
                        continue;
                    }
                    gateFlags = ((FclFusionGate *)gateEntry)->flags;
                    if (gateFlags & 1) {
                        if (datGetFlag(((FclFusionGate *)gateEntry)->flag) != 0) {
                            continue;
                        }
                        gatePassed = 0;
                        goto block_16;
                    } else if (gateFlags & 2) {
                        defaultAllowed = 0;
                        if (datGetFlag(((FclFusionGate *)gateEntry)->flag) != 1) {
                            continue;
                        }
                        gatePassed = 1;
                        goto block_16;
                    }
                }
                gatePassed = defaultAllowed;
block_16:
                if (gatePassed != 0) {
                    highestId = highest & 0xFFFF;
                    if ((highestId == 0) ||
                        ((tableAddress = (s32)iGpffffb3d4,
                          (s32)*(u8 *)(tableAddress + (highestId * 0xE) + 3) <
                          (s32)*(u8 *)(tableAddress + candidateOffset + 3)) != 0)) {
                        candidateId = candidateId ^ 0;
                        highest = (u32)(u16)candidateIndex;
                    }
                    candidateLevel = *(u8 *)(iGpffffb3d4 + candidateOffset + 3);
                    if ((s32)candidateLevel >= levelThreshold) {
                        excludedIndex = 0;
                        goto loop_28_cond;
loop_28_body:
                        if (candidateId == input[excludedIndex]) {
                            isExcluded = 1;
                            goto loop_28_done;
                        }
                        excludedIndex += 1;
loop_28_cond:
                        if (excludedIndex < 0xC) {
                            goto loop_28_body;
                        }
                        isExcluded = 0;
loop_28_done:
                        if ((isExcluded == 0) &&
                            ((selectedId = selected & 0xFFFF,
                              (selectedId == 0)) ||
                             ((tableAddress = (s32)DAT_007644c4,
                               (s32)candidateLevel <
                               (s32)*(u8 *)(tableAddress + (selectedId * 0xE) + 3)) != 0))) {
                            candidateId = candidateId ^ 0;
                            selected = (u32)(u16)candidateIndex;
                        }
                    }
                }
            }
        }
    }
    if (!(highest & 0xFFFF)) {
        return 0;
    }
    if (!(selected & 0xFFFF)) {
        tableAddress = (s32)iGpffffb3d4;
        fallbackId = highest & 0xFFFF;
        candidate = (u8 *)(fallbackId * 0xE);
        candidate += tableAddress;
        if ((s32)((FclFusionBaseEntry *)candidate)->level < levelThreshold) {
            selected = fallbackId;
        }
    }
    return selected;
}

/* measured: identical 128-bit-slot pattern to fclFuseLowestCandidateAtLeast (retail sq's
   arcana&0xFF into the arcana snapshot at 0xA0 and lq's it back in the 0xC0 i-loop, raw bne
   compare; 736B retail window). The corrected technique from docs/matching.md's
   "128-bit lq/sq aggregate copy" entry closes this target: local
   `typedef signed __int128 s128;`, a narrowing (s64) reload compare, and
   source-shaped continue/masked-u16 updates produce an exact MATCH
   (724B object, relocation-normalized diff 0). */
/* Select the highest eligible level at or below the threshold, excluding the twelve supplied IDs.
 * Byte-offset base-table accesses preserve measured alias/load ordering; entries are 14 bytes.
 * The inherited XOR-zero assignments and 128-bit snapshot are retained matching-required source shapes. */
// FUN_003133B0
s32 fclFuseLowestCandidateAtMost(u32 arcana, s32 maximumLevel, u16 *excluded) {
    typedef signed __int128 s128;
    extern u8 *DAT_007644c4;
    u16 *input;
    s128 requestedArcana;
    s16 gateFlags;
    s32 candidateId;
    s32 candidateOffset;
    s32 levelThreshold;
    s32 highestId;
    s32 fallbackId;
    s32 tableAddress;
    s32 selectedId;
    s32 candidateIndex;
    s32 selected;
    s32 highest;
    s32 defaultAllowed;
    s32 candidateAllowed;
    s32 isExcluded;
    s32 gatePassed;
    s32 excludedIndex;
    u16 candidateFlags;
    u32 gateIndex;
    u8 candidateLevel;
    u8 *candidate;
    u8 *gateEntry;

    selected = 0;
    highest = 0;
    candidateIndex = 0;
    input = excluded;
    requestedArcana = arcana & 0xFF;
    levelThreshold = maximumLevel & 0xFF;
    for (; (candidateIndex & 0xFFFF) < 0xC0;
         candidateIndex = (candidateIndex + 1) & 0xFFFF) {
        candidateId = candidateIndex & 0xFFFF;
        candidate = iGpffffb3d4;
        candidateOffset = (u16)candidateIndex * 0xE;
        candidate += candidateOffset;
        if ((s64)requestedArcana == ((FclFusionBaseEntry *)candidate)->arcana) {
            candidateFlags = ((FclFusionBaseEntry *)candidate)->flags;
            if (candidateFlags & 1) {
                candidateAllowed = 0;
            } else if (candidateFlags & 2) {
                candidateAllowed = 0;
            } else {
                candidateAllowed = 1;
            }
            if (candidateAllowed != 0) {
                defaultAllowed = 1;
                for (gateIndex = 0; gateIndex < 0x17U; gateIndex++) {
                    gateEntry = D_006420A0 + (gateIndex * 8);
                    if (candidateId != ((FclFusionGate *)gateEntry)->persona) {
                        continue;
                    }
                    gateFlags = ((FclFusionGate *)gateEntry)->flags;
                    if (gateFlags & 1) {
                        if (datGetFlag(((FclFusionGate *)gateEntry)->flag) != 0) {
                            continue;
                        }
                        gatePassed = 0;
                        goto block_16;
                    } else if (gateFlags & 2) {
                        defaultAllowed = 0;
                        if (datGetFlag(((FclFusionGate *)gateEntry)->flag) != 1) {
                            continue;
                        }
                        gatePassed = 1;
                        goto block_16;
                    }
                }
                gatePassed = defaultAllowed;
block_16:
                if (gatePassed != 0) {
                    highestId = highest & 0xFFFF;
                    if ((highestId == 0) ||
                        ((tableAddress = (s32)iGpffffb3d4,
                          (s32)*(u8 *)(tableAddress + (highestId * 0xE) + 3) <
                          (s32)*(u8 *)(tableAddress + candidateOffset + 3)) != 0)) {
                        candidateId = candidateId ^ 0;
                        highest = (u32)(u16)candidateIndex;
                    }
                    candidateLevel = *(u8 *)(iGpffffb3d4 + candidateOffset + 3);
                    if ((s32)candidateLevel > levelThreshold) {
                        continue;
                    }
                    excludedIndex = 0;
                    goto loop_28_cond;
loop_28_body:
                    if (candidateId == input[excludedIndex]) {
                        isExcluded = 1;
                        goto loop_28_done;
                    }
                    excludedIndex += 1;
loop_28_cond:
                    if (excludedIndex < 0xC) {
                        goto loop_28_body;
                    }
                    isExcluded = 0;
loop_28_done:
                    if ((isExcluded == 0) &&
                        ((selectedId = selected & 0xFFFF,
                          (selectedId == 0)) ||
                         ((tableAddress = (s32)DAT_007644c4,
                           (s32)*(u8 *)(tableAddress +
                                        (selectedId * 0xE) + 3) <
                           (s32)candidateLevel)))) {
                        candidateId = candidateId ^ 0;
                        selected = (u32)(u16)candidateIndex;
                    }
                }
            }
        }
    }
    if (highest == 0) {
        kAssertFail(D_00642F30, 0x43A);
    }
    if (!(selected & 0xFFFF)) {
        tableAddress = (s32)DAT_007644c4;
        fallbackId = highest & 0xFFFF;
        candidate = (u8 *)(fallbackId * 0xE);
        candidate += tableAddress;
        if ((s32)((FclFusionBaseEntry *)candidate)->level < levelThreshold) {
            selected = fallbackId;
        }
    }
    return selected;
}

