/* Consolidated Persona 4 source units. */
/* Original translation unit mdlSE.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90();
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007241D8;
extern void *func_00477c40(u32 arg0, u32 arg1, u32 arg2);
extern s32 iGpffffbb40;
extern u8 D_00922C10[];
extern u8 D_00922C14[];
extern u8 D_00922C16[];
extern void func_0043f810(void *dst, const void *src, u32 size);
extern s32 func_0045a570(s32 arg0, void *arg1, u32 arg2, void *arg3, u32 arg4, void *arg5, u32 arg6);
extern s32 func_004553c0(void *arg0);
extern void func_00454bd0(void *arg0);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern s32 func_0045a890(s16 arg0);
extern s32 func_003b7060(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0047df40(s32 arg0, s32 arg1);



// FUN_0047DEA0
void *func_0047dea0(s16 arg0, s16 arg1, s16 arg2)
{
    void *temp_2;

    func_0044ea90(&D_007241D8, 0x2B);
    temp_2 = jtbl_008873E8[0](0x28, 0x40000);
    func_0043f9c8(temp_2, 0, 0x28);
    *(s32 *)((u8 *)temp_2 + 8) = 1;
    *(s16 *)((u8 *)temp_2 + 0xC) = arg0;
    *(s16 *)((u8 *)temp_2 + 0xE) = arg1;
    *(s16 *)((u8 *)temp_2 + 0x10) = arg2;
    return temp_2;
}

/* Measured: 420 instruction bytes plus 12 retail zero-tail bytes, nd 0.
   CSE-off retains repeated slot addresses and index masks. Propagation-off
   preserves the shared sentinel and distinct eviction-loop lifetimes. */
// FUN_0047DF40
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0047df40(s32 type, s32 id)
{
    s32 selectedSlot;
    s32 scanIndex;
    u32 slotType;
    s32 slotIndex;
    u32 minimumTick;
    u8* slot;
    s32 byteOffset;
    u32 requestedType;
    u32 requestedId;

    selectedSlot = -1;
    scanIndex = 0;
    requestedType = type & 0xFFFF;
    requestedId = id & 0xFFFF;
    for (; (slotIndex = scanIndex & 0xFFFF) < 3U; scanIndex = (scanIndex + 1) & 0xFFFF)
    {
        slot = (u8*)D_00922C10 + (u16)scanIndex * 8;
        slotType = *(u16*)(slot + 4);
        if ((requestedType == slotType) && (requestedId == *(u16*)(slot + 6)))
        {
            selectedSlot = slotIndex;
            break;
        }
        else if (((s32)slotType < 0xC) &&
                 (func_00477c40(slotType, *(u16*)((u8*)D_00922C10 + (u16)scanIndex * 8 + 6), 0) == 0))
        {
            selectedSlot = slotIndex;
            break;
        }
    }
    /* All ones is both the unselected-slot sentinel and the initial unsigned minimum. */
    minimumTick = 0xFFFFFFFFU;
    if ((u32)selectedSlot == minimumTick)
    {
        u32 evictionSlot;
        s32 evictionIndex = 0;
        slot = (u8*)D_00922C10;
        for (; (evictionSlot = evictionIndex & 0xFFFF) < 3; evictionIndex = (evictionIndex + 1) & 0xFFFF)
        {
            u32 tick = *(u32*)(slot + ((evictionIndex & 0xFFFF) * 8));
            if (tick <= minimumTick)
            {
                minimumTick = tick;
                selectedSlot = evictionSlot;
            }
        }
    }
    byteOffset = selectedSlot * 8;
    iGpffffbb40 = (u32)iGpffffbb40 + 1;
    *(s32*)((s32)D_00922C10 + byteOffset) = iGpffffbb40;
    *(u16*)((s32)D_00922C14 + byteOffset) = type;
    *(u16*)((s32)D_00922C16 + byteOffset) = id;
    return selectedSlot + 3;
}
#pragma pop

/* measured: nd 160. Modulo fixed (divu not __moddi3) and object size is right
   (840-844B vs 848B window), but the saved-register allocation is rotated:
   retail keeps arg0 in $s1, arg2 in $s0, (s16)arg1 in $s5, temp_20 in $s4,
   temp_19 in $s3, count in $s2; mwcc b210 keeps arg0 in $s2, arg2 in $s1,
   (s16)arg1 in $s0, temp_20 in $s5, temp_19 in $s4, count in $s3. Tried the
   temp_20 operand order both ways (arg1*0xC first vs arg2*0x60 first) and the
   m2c declaration order -- arg0 stays in $s2. Saved-register rotation floor. */
// FUN_0047E0F0
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e0f0);


// FUN_0047E440
s64 func_0047e440(void) {
    return 0;
}


/* measured: the record advance is a signed `(size + 0x3F) / 64 * 64`
   (retail addiu $v1 / sra $v0 / bgez fix-up); hand-written shifts with an
   explicit negative branch were the archived nd 5 "register-class" residual. */
// FUN_0047E450
void func_0047e450(void **arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4)
{
    s32 arg3_p = arg3;
    void ** arg0_p = arg0;
    s32 sp16C;
    u8 sp70[0x100];
    void *sp180[3];
    u32 sp170[3];
    void *temp_16;
    void *temp_2;
    void *temp_2_2;
    void *temp_2_3;
    void *temp_4_2;
    void *temp_4_3;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_5;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_4_4;
    s32 var_16;
    s32 var_17;
    s32 var_2;

    var_17 = arg3_p;
    temp_5 = *arg0;
    if ((temp_5 == NULL) || ((*(u16 *)((u8 *)temp_5 + 0x12) & 1) == 0)) {
        temp_4 = (u16)arg1;
        switch (temp_4) {
        case 1:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2, 0, 0x28);
                *(s32 *)((u8 *)temp_2 + 8) = 1;
                *(s16 *)((u8 *)temp_2 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2 + 0x10) = 1;
                *arg0 = temp_2;
            }
            temp_16 = *arg0_p;
            func_0044ea90(&D_007241D8, 0x49);
            temp_2_2 = jtbl_008873E8[0](arg4, 0x40000);
            *(void **)((u8 *)temp_16 + 0) = temp_2_2;
            func_0043f810(temp_2_2, (void *)var_17, arg4);
            temp_4_2 = *arg0_p;
            *(u16 *)((u8 *)temp_4_2 + 0x12) &= 0xFFFD;
            temp_4_3 = *arg0_p;
            *(u16 *)((u8 *)temp_4_3 + 0x12) |= 1;
            return;
        case 2:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2_3 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2_3, 0, 0x28);
                *(s32 *)((u8 *)temp_2_3 + 8) = 1;
                *(s16 *)((u8 *)temp_2_3 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2_3 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2_3 + 0x10) = 2;
                *arg0 = temp_2_3;
            }
            *(s32 *)((u8 *)(*arg0_p) + 0x14) = 0;
            *(s32 *)((u8 *)(*arg0_p) + 4) = func_0047df40(arg1, arg2);
            var_16 = 0;
            while (var_16 < 3) {
                func_0043f810(sp70, (void *)var_17, 0x100);
                temp_4_4 = var_17 + 0x100;
                sp180[var_16] = (void *)temp_4_4;
                sp16C = *(s32 *)(sp70 + 0xFC);
                sp170[var_16] = sp16C;
                var_17 = temp_4_4 + ((sp16C + 0x3F) / 64) * 64;
                var_16 += 1;
            }
            func_0045a570((s16)*(s32 *)((u8 *)(*arg0) + 4), sp180[0], sp170[0], sp180[1], sp170[1], sp180[2], sp170[2]);
            temp_4_5 = *arg0_p;
            *(u16 *)((u8 *)temp_4_5 + 0x12) |= 8;
            temp_4_6 = *arg0_p;
            *(u16 *)((u8 *)temp_4_6 + 0x12) |= 2;
            break;
        }
    }
}


/* measured: 840B/window 848B; only two zero-padding words remain.
   Inlining the shared copy operation separates its local lifetimes from
   the callback and reproduces the retail saved-register allocation.
   Bank sizes stay unsigned for the consumer's argument-load ordering. */
static inline void copyLoadedRequest(void **owner, s32 requestOffset)
{
    void *node;
    void *request;
    void *source;
    void *memory;
    u32 fileSize;

    node = *owner;
    request = *(void **)((u8 *)node + requestOffset);
    fileSize = *(u32 *)((u8 *)request + 0x118);
    source = *(void **)((u8 *)request + 0x110);
    func_0044ea90(&D_007241D8, 0x49);
    memory = jtbl_008873E8[0](fileSize, 0x40000);
    *(void **)node = memory;
    func_0043f810(memory, source, fileSize);
}

// FUN_0047E6F0
s32 func_0047e6f0(void **owner)
{
    void *current;
    void *request;
    void *record0;
    void *record1;
    void *record2;
    u32 size0;
    u32 size1;
    u32 size2;
    u16 flags;
    u16 mode;

    current = *owner;
    if (current == NULL) {
        return 1;
    }
    flags = *(u16 *)((u8 *)current + 0x12);
    if ((flags & 1) != 0) {
        return 1;
    }
    if ((flags & 2) == 0) {
        return 1;
    }
    mode = *(u16 *)((u8 *)current + 0xC);
    switch (mode) {
    case 1:
        if (func_004553c0(*(void **)((u8 *)current + 0x14)) != 0) {
            copyLoadedRequest(owner, 0x14);
            request = *(void **)((u8 *)*owner + 0x14);
            if (request != NULL) {
                func_00454bd0(request);
                *(void **)((u8 *)*owner + 0x14) = NULL;
            }
            *(u16 *)((u8 *)*owner + 0x12) |= 1;
            *(u16 *)((u8 *)*owner + 0x12) &= 0xFFFD;
            return 1;
        }
        break;
    case 2:
        request = *(void **)((u8 *)current + 0x18);
        if (request != NULL) {
            if (func_004553c0(request) == 0) {
                return 0;
            }
            copyLoadedRequest(owner, 0x18);
            func_00454bd0(*(void **)((u8 *)*owner + 0x18));
            *(void **)((u8 *)*owner + 0x18) = NULL;
        }
        current = *owner;
        if ((*(u16 *)((u8 *)current + 0x12) & 8) == 0) {
            if (func_004553c0(*(void **)((u8 *)current + 0x14)) == 0) {
                return 0;
            }
            record0 = (void *)func_00455ea0(*(void **)((u8 *)*owner + 0x14), 0, (s32 *)&size0);
            record1 = (void *)func_00455ea0(*(void **)((u8 *)*owner + 0x14), 1, (s32 *)&size1);
            record2 = (void *)func_00455ea0(*(void **)((u8 *)*owner + 0x14), 2, (s32 *)&size2);
            func_0045a570(*(s16 *)((u8 *)*owner + 4), record0, size0, record1, size1, record2, size2);
            *(u16 *)((u8 *)*owner + 0x12) |= 8;
            break;
        }
        if (func_0045a890(*(s16 *)((u8 *)current + 4)) == 0) {
            return 0;
        }
        request = *(void **)((u8 *)*owner + 0x14);
        if (request != NULL) {
            func_00454bd0(request);
            *(void **)((u8 *)*owner + 0x14) = NULL;
        }
        *(u16 *)((u8 *)*owner + 0x12) |= 1;
        *(u16 *)((u8 *)*owner + 0x12) &= 0xFFFD;
        *(u16 *)((u8 *)*owner + 0x12) |= 4;
        *(u16 *)((u8 *)*owner + 0x12) &= 0xFFF7;
        return 1;
    default:
        return 1;
    }
    return 0;
}
