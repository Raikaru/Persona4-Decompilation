/* Original translation unit sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"

/* Allocated as 0x18 bytes; Request copies the optional payload and tracks
 * the old/current sequence IDs separately during delayed transitions. */
typedef struct SequenceWork
{
    s32 flags;
    s32 current;
    s32 previous;
    s32 delay;
    s32 unk10;
    u8 *payload;
} SequenceWork;

extern void kAssertFail(u8 *file, s32 line);
extern void chkmemAllocSiteTag(u8 *file, s32 line);

extern s32 FldShadowAnim_Update(u8 *task);
extern void memcpy(void *dst, const void *src, s32 size);
extern u8 D_005DCC64[];
extern u8 D_005DCC68[];
extern u8 D_005DCC6C[];
extern void FldShadowAnim_Destroy(u8 *task);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005DCB28[];
extern u8 D_005DCB40[];
extern u8 *iGpffffb1a8;


// FUN_001028C0
/* Create the sequence task with both current and previous sequence IDs initially invalid. */
s32 sequenceCreate(void)
{
    u8 *mem;
    s32 handle;

    if (iGpffffb1a8 != 0) {
        kAssertFail(D_005DCB28, 0x7B);
    }
    chkmemAllocSiteTag(D_005DCB28, 0x7D);
    mem = D_008873F4[0](1, 0x18, 0x40000);
    handle = (s32)kwlnTaskCreate((const void *)(D_005DCB40), 0xF, 0, 0, FldShadowAnim_Update, FldShadowAnim_Destroy, (u8 *)(mem));
    ((SequenceWork *)mem)->current = -1;
    ((SequenceWork *)mem)->previous = -1;
    iGpffffb1a8 = (u8 *)(u32)handle;
}
// FUN_001029A0
/* Typed SequenceWork accesses add address temporaries under b210 (508/496 bytes); retain the proven six-word work layout for MATCH. */
/* Request a sequence change, stopping the old sequence first. Callback symbols are separately linked interior aliases in a 0x50-byte table; keep their byte-relative function-pointer loads. */
void sequenceRequest(s32 sequenceId, s32 parameters, s32 parameterSize, s32 delay)
{
    u8 *work;
    u8 *work2;
    s32 type;
    u8 *temp;

    work = *(u8 **)((u8 *)iGpffffb1a8 + 0x38);
    if (sequenceId < 0) {
        kAssertFail(D_005DCB28, 0xFE);
    }
    if ((*(s32 *)work & 1) != 0) {
        kAssertFail(D_005DCB28, 0xFF);
    }
    *(s32 *)(work + 8) = *(s32 *)(work + 4);
    work2 = *(u8 **)((u8 *)iGpffffb1a8 + 0x38);
    type = *(s32 *)(work2 + 4);
    if (type >= 0) {
        if ((*(s32 (**)(void))((u8 *)D_005DCC68 + type * 0x50))() == 1) {
            (*(s32 (**)(void))((u8 *)D_005DCC6C + *(s32 *)(work2 + 4) * 0x50))();
        }
        *(s32 *)(work2 + 4) = -1;
        *(s32 *)(work2 + 0x10) = 0;
    }
    *(s32 *)(work + 4) = sequenceId;
    if (delay != 0) {
        *(s32 *)work |= 1;
        if (parameterSize != 0) {
            chkmemAllocSiteTag(D_005DCB28, 0x10A);
            temp = D_008873F4[0](1, parameterSize, 0x40000);
            *(u8 **)(work + 0x14) = temp;
            memcpy(temp, (const void *)parameters, parameterSize);
        } else {
            *(u8 **)(work + 0x14) = NULL;
        }
        *(s32 *)(work + 0xC) = delay;
        return;
    }
    *(s32 *)work &= ~1;
    *(s32 *)(work + 0xC) = 0;
    *(u8 **)(work + 0x14) = NULL;
    (*(void (**)(s32))((u8 *)D_005DCC64 + *(s32 *)(work + 4) * 0x50)) (parameters);
}




