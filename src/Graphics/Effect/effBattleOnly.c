#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

void kAssertFail(u8 *file, s32 line);
void chkmemAllocSiteTag(u8 *file, s32 line);
void *memcpy(void *dst, const void *src, s32 size);

extern u8 D_007146A0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

typedef struct EffBattleEntry
{
    void (*postCreate)(void *obj);       // 0x00
    s32 (*setup)(void *obj, u16 id, s32 a, s32 b); // 0x04
    u8 pad[0x10];                        // 0x08
    s32 size;                            // 0x18
} EffBattleEntry;                        // 0x1C

typedef struct EffBattleWork
{
    u8 zero[0x20];  // 0x00
    f32 alpha;      // 0x20
    u32 color;      // 0x24
    s32 count;      // 0x28
    s32 id;         // 0x2C
    s32 setupResult;// 0x30
    u8 pad[4];      // 0x34
    u8 *data;       // 0x38
    u8 pad3C[4];    // 0x3C
} EffBattleWork;    // 0x40

/* Per-type effect hook table and battle-effect-active callback, set by startup code; defined here
 * so the linker places them correctly. */
s32 (*D_00764C94)(void);     // 0x00764c94
EffBattleEntry *D_00764C90;  // 0x00764c90

u8 *EffBattleAllocWork(s32 id, s32 initialData);


/* The id is s32 because retail masks it to 16 bits separately for the range check and the table
 * index; the two spellings must stay different. Allocates a battle effect work block sized from the
 * per-id table, stores the id, and copies initialData's data into it. */
// FUN_004B50F0
u8 *EffBattleAllocWork(s32 id, s32 initialData)
{
    EffBattleWork *work;
    s32 size;

    if ((u16)id >= 0xD) {
        kAssertFail(D_007146A0, 0x1B);
    } else {
    }
    size = D_00764C90[(id & 0xFFFF)].size;
    chkmemAllocSiteTag(D_007146A0, 0x1F);
    work = (EffBattleWork *)(*jtbl_008873E8)(size + 0x40, 0x40000);
    if (work == NULL) {
        kAssertFail(D_007146A0, 0x20);
    }
    work->data = (u8 *)work + 0x40;
    work->count = 0;
    work->id = (id & 0xFFFF);
    work->color = 0x80808080;
    work->alpha = 1.0f;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(work) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(work) : "memory");
    memcpy(work->data, (const void *)initialData, size);
    return (u8 *)work;
}


/* The table base is reloaded before adding the entry offset for the post callback, matching
 * retail's address computation order. Creates a battle effect from a source: loads its texture,
 * then when the test callback passes calls the per-id setup and post callbacks from the table. */
// FUN_004B5200
void *EffBattleCreate(void *source)
{
    u8 *tex;
    s32 secondaryData;
    s32 setupParameter;
    s32 entryOffset;
    u16 secondaryId;
    u16 id;
    u8 *work;
    u8 *base;

    tex = mdlEffectResolveRelPtrA(source);
    if (tex == NULL) {
        kAssertFail(D_007146A0, 0x58);
    }
    secondaryData = (s32)mdlEffectResolveRelPtrB(source);
    secondaryId = ((EffSourceDescriptor *)source)->kind;
    setupParameter = (s32)((EffSourceDescriptor *)source)->clumpInput;
    id = ((EffSourceDescriptor *)source)->id;
    work = EffBattleAllocWork(id, (s32)tex);
    if ((*D_00764C94)() != 0) {
        entryOffset = (id & 0xFFFF) * 0x1C;
        /* Kept as a byte cursor; typed table indexing changes the callback-load sequence. */
        base = (u8 *)D_00764C90;
        base += 4;
        base += entryOffset;
        {
            s32 (*setup)(void *, u16, s32, s32) =
                *(s32 (**)(void *, u16, s32, s32))base;
            if (setup != NULL) {
                ((EffBattleWork *)work)->setupResult = setup(tex, secondaryId, secondaryData, setupParameter);
            }
        }
        base = (u8 *)D_00764C90;
        base += entryOffset;
        {
            void (*post)(void *) =
                *(void (**)(void *))base;
            if (post != NULL) {
                post(work);
            }
        }
    }
    if (work == NULL) {
        kAssertFail(D_007146A0, 0x5D);
    }
    return work;
}
