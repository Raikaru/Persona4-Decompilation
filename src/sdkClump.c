/* Original translation unit sdkClump.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_atomic_layout_internal.h"

/* Allocation sizes are 0x28 for an atomic entry and 0x2C for its list owner. */
typedef struct SdkClumpEntry {
    u8 *atomic;
    s32 hasSpecialData;
    s32 unk8[4]; /* Initialized to four 1.0f bit patterns; component meaning is unproven. */
    s32 category;
    u8 pad1C[8];
    u8 *next;
} SdkClumpEntry;

typedef struct SdkClump {
    s32 count;
    s32 specialCount;
    u8 *defaultEntries;
    u8 *categoryFive;
    u8 *categorySix;
    u8 *categoryTwo;
    u8 *categorySeven;
    u8 *categoryEight;
    u8 *categoryNine;
    u8 *categoryThree;
    u8 *categoryFour;
} SdkClump;

typedef struct SdkClumpMaterialInfo {
    s32 category;
    s32 hasSpecialData;
    s32 unk8;
} SdkClumpMaterialInfo;

extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00712518[];
extern u32 D_00712530[];
extern u8 D_00712558[];
extern u8 D_00712568[];
extern s32 K_Clump_MatUsrDataGetInt(void *material, const char *name);
extern u32 K_Clump_MatUsrDataHasData(void *material, const char *name);
extern void memset(void *dst, s32 value, u32 size);
extern s32 func_003c21e0(void *, s32 (*cb)(s32, void *), void *);
extern void sdkClumpAddAtomicCategory(u8 *, u32 , u8 *, s32 );
extern void hMaestroFreeListSet(void *);
extern s32 sdkClumpCollectMaterialFlags(s32 , void *);


/* Classify an atomic from its materials and insert it into the clump lists. */
// FUN_00462A60
void *sdkClumpCollectAtomic(void *atomic, void *clump) {
    u8 materialInfo[0xC];
    s32 geometryAddress;

    memset(materialInfo, 0, 0xC);
    geometryAddress = (s32)((struct RpAtomic *)atomic)->geometry;
    if (geometryAddress != 0) {
        func_003c21e0((void *)geometryAddress, sdkClumpCollectMaterialFlags, materialInfo);
        /* measured: typing category swaps the two callback argument loads (8 differing bytes). */
        sdkClumpAddAtomicCategory(clump, *(u32 *)(materialInfo + 0), atomic, ((SdkClumpMaterialInfo *)materialInfo)->hasSpecialData);
    }
    return atomic;
}


/* measured: direct table references plus opt_loop_invariants reproduce both
   retail table-base preheaders and both loop bodies exactly (nd 15 -> 0).
   Committed at nd 0. */
/* measured: opt_loop_invariants probe for the retail base preheader. */
#pragma opt_loop_invariants on
/* Keeps the highest table-ranked material category and records the optional user-data flag. */
// FUN_00462960
s32 sdkClumpCollectMaterialFlags(s32 materialAddress, void *materialInfo) {
    s32 category;
    s32 categoryRank;
    s32 currentRank;

    category = K_Clump_MatUsrDataGetInt((void *)materialAddress, (const char *)D_00712558);
    currentRank = 0;
    while (currentRank < 0xA) {
        if (((SdkClumpMaterialInfo *)materialInfo)->category == (s32)D_00712530[currentRank]) {
            break;
        }
        currentRank++;
    }
    categoryRank = 0;
    while (categoryRank < 0xA) {
        if (category == (s32)D_00712530[categoryRank]) {
            break;
        }
        categoryRank++;
    }
    if (currentRank < categoryRank) {
        ((SdkClumpMaterialInfo *)materialInfo)->category = (s32)D_00712530[categoryRank];
    }
    if (K_Clump_MatUsrDataHasData((void *)materialAddress, (const char *)D_00712568) == 1) {
        ((SdkClumpMaterialInfo *)materialInfo)->hasSpecialData = 1;
    }
    return materialAddress;
}
/* measured: closes the opt_loop_invariants probe. */
#pragma opt_loop_invariants off


/* Allocates a 0x28-byte atomic entry and links it into the selected category bucket. */
// FUN_00462780
void sdkClumpAddAtomicCategory(u8 *clump, u32 category, u8 *atomic, s32 hasSpecialData) {
    u8 *entry;

    chkmemAllocSiteTag(D_00712518, 0x22);
    entry = D_008873F4[0](1, 0x28, 0x40000);
    ((SdkClumpEntry *)entry)->atomic = atomic;
    if (hasSpecialData == 1) {
        ((SdkClump *)clump)->specialCount = ((SdkClump *)clump)->specialCount + 1;
        ((SdkClumpEntry *)entry)->hasSpecialData = 1;
    }
    ((SdkClumpEntry *)entry)->unk8[0] = 0x3F800000;
    ((SdkClumpEntry *)entry)->unk8[1] = 0x3F800000;
    ((SdkClumpEntry *)entry)->unk8[2] = 0x3F800000;
    ((SdkClumpEntry *)entry)->unk8[3] = 0x3F800000;
    switch (category) {
    case 0:
    case 1:
        ((SdkClumpEntry *)entry)->category = 1;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->defaultEntries;
        ((SdkClump *)clump)->defaultEntries = entry;
        break;
    case 2:
        ((SdkClumpEntry *)entry)->category = 2;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryTwo;
        ((SdkClump *)clump)->categoryTwo = entry;
        break;
    case 3:
        ((SdkClumpEntry *)entry)->category = 3;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryThree;
        ((SdkClump *)clump)->categoryThree = entry;
        break;
    case 4:
        ((SdkClumpEntry *)entry)->category = 4;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryFour;
        ((SdkClump *)clump)->categoryFour = entry;
        break;
    case 5:
        ((SdkClumpEntry *)entry)->category = 5;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryFive;
        ((SdkClump *)clump)->categoryFive = entry;
        break;
    case 6:
        ((SdkClumpEntry *)entry)->category = 6;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categorySix;
        ((SdkClump *)clump)->categorySix = entry;
        break;
    case 7:
        ((SdkClumpEntry *)entry)->category = 7;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categorySeven;
        ((SdkClump *)clump)->categorySeven = entry;
        break;
    case 8:
        ((SdkClumpEntry *)entry)->category = 8;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryEight;
        ((SdkClump *)clump)->categoryEight = entry;
        break;
    case 9:
        ((SdkClumpEntry *)entry)->category = 9;
        ((SdkClumpEntry *)entry)->next = ((SdkClump *)clump)->categoryNine;
        ((SdkClump *)clump)->categoryNine = entry;
        break;
    }
    ((SdkClump *)clump)->count = ((SdkClump *)clump)->count + 1;
}


/* Builds category lists from every atomic and discards an unneeded list owner. */
// FUN_00462AE0
void *sdkClumpCreateBuckets(void *sourceClump) {
    void *clump;

    chkmemAllocSiteTag(D_00712518, 0xAE);
    clump = D_008873F4[0](1, 0x2C, 0x40000);
    RpClumpForAllAtomics(sourceClump, sdkClumpCollectAtomic, clump);
    if ((((SdkClump *)clump)->specialCount == 0) && ((((SdkClump *)clump)->count == 0) || ((((SdkClump *)clump)->categorySix == 0) && (((SdkClump *)clump)->categoryFive == 0) && (((SdkClump *)clump)->categoryTwo == 0) && (((SdkClump *)clump)->categoryThree == 0) && (((SdkClump *)clump)->categoryFour == 0) && (((SdkClump *)clump)->categorySeven == 0) && (((SdkClump *)clump)->categoryEight == 0) && (((SdkClump *)clump)->categoryNine == 0)))) {
        hMaestroFreeListSet(clump);
        clump = NULL;
    }
    return clump;
}