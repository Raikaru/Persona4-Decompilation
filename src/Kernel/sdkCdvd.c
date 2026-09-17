/* Original translation unit sdkCdvd.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 D_008C0680[];
extern u8 D_008C0780[];
extern u8 D_008C0880[];
extern u8 D_005BC790[];
void func_00454d20(void* a0, void* a1);
void func_00454e10(void* a0, void* a1, void* a2);
s32 func_004c74f8(void* a0, void* a1, void* a2, void* a3);
void func_0043f810(void* dst, void* src, u32 size);
typedef void *ADXF;

typedef struct HCdvd {
    struct HCdvd *prev;          /* 0x000 */
    struct HCdvd *next;          /* 0x004 */
    s32 hasExternalMemory;       /* 0x008 */
    s32 readState;               /* 0x00C */
    char path[0x100];            /* 0x010 */
    void *fileMemory;            /* 0x110 */
    void *unalignedFileMemory;   /* 0x114 */
    s32 fileSize;                /* 0x118 */
    s32 unk11C;                  /* 0x11C */
    s32 unk120;                  /* 0x120 */
    s32 readByteSize;            /* 0x124 */
    u8 unk128[0x2C];             /* 0x128 */
    ADXF adxf;                   /* 0x154 */
    char fileName[0x100];        /* 0x158 */
    u8 dir[0x102];               /* 0x258 */
    s16 refCount;                /* 0x35A */
    s16 pendingDestroyCount;     /* 0x35C */
    s16 readPollCount;           /* 0x35E */
} HCdvd;                         /* 0x360 */

typedef struct HCdvdCache {
    s32 isValid;                 /* 0x00 */
    s32 *requestData;            /* 0x04 */
    u8 data[0x8C];               /* 0x08 */
} HCdvdCache;                    /* 0x94 */

extern HCdvdCache D_008C8780[];
extern u8 D_008C8784[];
extern u8 D_008C8808[];
extern u8 D_008C880C[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_00710870[];
void func_0046d740(const void* file, const void* file2, u32 line);
void func_0044ea90(const void* file, s32 line);
void func_00455100(void* a0, void* a1);
s32 func_004426e8(void* a0, void* a1);
void func_004504f0(void* a0, void* a1);
void func_00440b68();
s16 func_0044ec40(void);
void func_00454f50(void* a0, void* a1, void* a2);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_008D1B80[];
extern u8* D_008D1B84[];
extern char D_00710900[];
extern char D_00710910[];

/* Measured: 1052/1056 bytes, 46 resolved relocations, four zero tail bytes.
 * Typed cache indexing gives the retail request/base hoist order; an explicit
 * base initializer leaves three words different. The compound refCount -=
 * preserves the RHS-first loads and store before the signed comparison. */
// FUN_00454640
#pragma push
#pragma opt_loop_invariants on
void func_00454640(void)
{
    extern void func_00468a50(void);
    extern void func_00468d10(void);
    extern void func_00455230(void *arg0);
    extern void func_00455b70(void *arg0);
    extern ADXF func_004c85a0(void *name, s32 mode);
    extern void func_004c8a60(ADXF handle);
    extern s32 func_004c9010(ADXF handle, s32 count, void *buffer);
    extern s32 func_004c95f8(ADXF handle);
    extern s32 func_004c9670(ADXF handle);
    extern s32 func_004c9820(ADXF handle);
    extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
    extern void (*jtbl_008873EC[])(void *ptr);
    extern char D_00710880[];
    extern char D_007108A0[];
    extern char D_007108C0[];
    extern char D_007108E0[];
    HCdvd *node;
    HCdvd *next;
    HCdvd *prev;
    HCdvd *link;
    HCdvdCache *slot;
    ADXF handle;
    s32 offset;
    s32 buffer;
    s32 blocks;
    s32 aligned;
    s32 spare;
    s32 state;
    s16 i;

    func_00468a50();
    func_00468d10();
    node = (HCdvd *)D_008D1B84[0];
    if (node == NULL) {
        return;
    }
loop:
    if (node->readState != 4) {
        switch (node->readState) {
        case 0:
            node->readPollCount = 0;
            func_00455230(node->dir);
            node->adxf = func_004c85a0(node->fileName, 0);
            handle = node->adxf;
            if (handle == NULL) {
                goto tail;
            }
            offset = func_004c9670(handle);
            node->readByteSize = offset;
            node->fileSize = offset;
            node->readState = 1;
        case 1:
            if (node->fileMemory == NULL) {
                func_0044ea90(D_00710870, 0xFA);
                buffer = (s32)(*jtbl_008873E8)(
                    ((u32)func_004c95f8(node->adxf) << 0xB) + 0x40U, 0x40000);
                node->unalignedFileMemory = (void *)buffer;
                if (buffer == 0) {
                    func_0046d740(D_00710880, D_00710870, 0xFF);
                    return;
                }
                aligned = buffer / 0x40 * 0x40;
                spare = buffer % 0x40;
                if (spare != 0) {
                    aligned = (s32)((u32)aligned + 0x40U);
                }
                node->fileMemory = (void *)aligned;
            }
            blocks = func_004c9010(node->adxf,
                                   func_004c95f8(node->adxf),
                                   node->fileMemory);
            if (blocks != func_004c95f8(node->adxf)) {
                func_004c8a60(node->adxf);
                node->adxf = NULL;
                if (node->hasExternalMemory == 0) {
                    (*jtbl_008873EC)(node->unalignedFileMemory);
                    node->fileMemory = NULL;
                    node->unalignedFileMemory = NULL;
                }
                node->readState = 0;
                goto tail;
            }
            node->readState = 2;
        case 2:
            node->readPollCount = (s16)(node->readPollCount + 1);
            state = func_004c9820(node->adxf);
            if (state == 3) {
                node->readState = 3;
                goto do_state3;
            }
            {
                if (state == 4) {
                    func_00440b68(D_007108A0);
                    func_004c8a60(node->adxf);
                    node->adxf = NULL;
                    node->readState = 0;
                    if (node->hasExternalMemory == 0) {
                        (*jtbl_008873EC)(node->unalignedFileMemory);
                        node->fileMemory = NULL;
                        node->unalignedFileMemory = NULL;
                    }
                    return;
                }
                goto tail;
            }
do_state3:
        case 3:
            func_00455b70(&node->hasExternalMemory);
            node->readState = 4;
            func_004c8a60(node->adxf);
            node->adxf = NULL;
            func_00440b68(D_007108C0, node->path);
            goto tail;
        }
        goto tail;
    }
tail:
    if (node->readState == 4) {
        next = node->next;
        node->refCount -= node->pendingDestroyCount;
        if (node->refCount < 0) {
            func_00440b68(D_007108E0);
        }
        node->pendingDestroyCount = 0;
        if (node->refCount <= 0) {
            prev = node->prev;
            link = node->next;
            prev->next = link;
            if (link != NULL) {
                link->prev = prev;
            }
            if (node->fileMemory != NULL && node->hasExternalMemory == 0) {
                (*jtbl_008873EC)(node->unalignedFileMemory);
                node->fileMemory = NULL;
                node->unalignedFileMemory = NULL;
            }
            for (i = 0; i < 0x100; i++) {
                slot = &D_008C8780[i];
                if (slot->isValid != 0 && slot->requestData == &node->hasExternalMemory) {
                    slot->isValid = 0;
                }
            }
            handle = node->adxf;
            if (handle != NULL) {
                func_004c8a60(handle);
                node->adxf = NULL;
            }
            (*jtbl_008873EC)(node);
        }
        node = next;
        if (next != NULL) {
            goto loop;
        }
    }
}
#pragma pop

// FUN_00454A60
u8* func_00454a60(u8* arg0, s32 arg1) {
    u8 buf[0x100];
    u8* node;
    u8* newnode;

    func_004504f0(D_00710900, arg0);
    node = D_008D1B80;
    func_00454d20(arg0, buf);
    func_00440b68(D_00710910, arg0);
    if (D_008D1B84[0] != NULL) {
        while (1) {
            if (func_004426e8(buf, node + 0x10) == 0) {
                *(s16*)(node + 0x35A) = (s16)(*(s16*)(node + 0x35A) + 1);
                return node;
            }
            if (*(u8**)(node + 4) == NULL) {
                break;
            }
            node = *(u8**)(node + 4);
        }
    }
    func_0044ea90(D_00710870, 0x198);
    newnode = D_008873F4[0](1, 0x364, 0x40000);
    func_00454d20(arg0, newnode + 0x10);
    func_00454f50(newnode + 0x10, newnode + 0x158, newnode + 0x258);
    *(s32*)(newnode + 0xC) = 0;
    *(u8**)(node + 4) = newnode;
    *(u8**)(newnode + 0) = node;
    *(s32*)(newnode + 4) = 0;
    *(s32*)(newnode + 0x110) = 0;
    *(s32*)(newnode + 8) = 0;
    *(s32*)(newnode + 0x150) = arg1;
    *(s16*)(newnode + 0x35A) = 1;
    *(s32*)(newnode + 0x154) = 0;
    *(s16*)(newnode + 0x362) = func_0044ec40();
    return newnode;
}

// FUN_00455510
void func_00455510(void) {
}

/* measured: long128 local with s64 position; reload the just-stored s32
   fileOffset into out.position so the compiler's lw sign-extend feeds the
   sd/lq/sq without a separate dsll32/dsrl32 pair. u32 arithmetic for sltu. */
// FUN_004555D0
void func_004555d0(void* resultData, void* slotData, s32 amount, s32 mode)
{
    typedef signed __int128 long128;
    struct HCdvdStreamData
    {
        u8 reserved[0x88];
        u8* fileMemory;
        s32 fileSize;
        s32 fileOffset;
    } *data;
    struct HCdvdStreamPosition
    {
        s64 position;
        u32 unused0;
        u32 unused1;
    } out;

    data = (struct HCdvdStreamData*)((u8*)slotData + 0x70);
    if (mode == 1) {
        u32 newOffset;
        newOffset = (u32)data->fileOffset + (u32)amount;
        if ((u32)data->fileSize < newOffset) {
            newOffset = (u32)data->fileSize;
        }
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else if (mode == 2) {
        u32 newOffset;
        if ((u32)data->fileSize < (u32)amount) {
            amount = data->fileSize;
        }
        newOffset = (u32)data->fileOffset + (u32)amount;
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else if (mode == 3) {
        u32 newOffset;
        newOffset = (u32)data->fileSize + (u32)amount;
        if ((u32)data->fileSize < newOffset) {
            newOffset = (u32)data->fileSize - 1;
        }
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else {
        out.position = 1;
        *(long128*)resultData = *(long128*)&out;
    }
}

s32 func_003dd900(s32 a0);
void func_0044ea90(const void* file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_004556b0(void);
extern void func_004556f0(void);
extern void func_004553e0(void);
extern void func_00455520(void);
extern void func_004555b0(void);
extern void func_00455720(void);
extern char D_00711658[];
s32 func_003dd290(void* a0, s32 a1, s32 a2, s32 a3);
void func_003dd760(s32 a0);
void* func_003dea20(s32 a0, void* a1, s32 a2, void* a3, void* a4);
s32 func_003dd830(void* a0);
void func_003ddde0(void* a0);
void* func_00456c60(s32 a0, void* a1, s32 a2, void* a3, void* a4);
extern void (*D_008873AC[])(void*, void*);
extern char D_00711670[];
extern char D_00711690[];
extern char D_007116B0[];
extern u8 D_008C5F80[];
extern u8 D_008C3780[];
extern u8 D_008C0F80[];
extern u8 iGpffffba40;
extern u8 iGpffffba38;
extern u8 iGpffffad60;
extern u8 iGpffffad58;
extern u8 iGpffffad68;
extern u8 iGpffffad70;
extern u8 iGpffffad78;
extern u8 iGpffffad80;
extern s32 iGpffffbaa0;

// FUN_004557E0
/* measured: D_008873F4 is a function-pointer table; retail hoists the TABLE
   ADDRESS into $s0 (lui/addiu) and loads the function pointer per call
   (lw $v0,($s0); jalr $v0). Achieved with an integer-cast base local
   (u32 base = (u32)D_008873F4), and arg3/arg4 declared s32 (not u8*) — the
   pointer arg types mis-coloured obj/arg4 ($s1/$s2 swap, nd 8). */
u8* func_004557e0(s32 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8* obj;
    u32 base;
    u8* sub;
    s32 i;

    if (func_003dd900(arg4) != 0) {
        return NULL;
    }
    func_0044ea90(D_00710870, 0x425);
    base = (u32)D_008873F4;
    obj = ((u8* (*)(s32, s32, s32))*(u32*)base)(1, 0x5C, 0x40000);
    *(void**)(obj + 0x14) = &func_004556b0;
    *(void**)(obj + 0x18) = &func_004556f0;
    *(void**)(obj + 0x28) = &func_004553e0;
    *(void**)(obj + 0x2C) = &func_00455510;
    *(void**)(obj + 0x30) = &func_00455520;
    *(void**)(obj + 0x44) = &func_004555b0;
    *(void**)(obj + 0x38) = &func_004555d0;
    *(void**)(obj + 0x4C) = &func_00455720;
    func_0044ea90(D_00710870, 0x430);
    sub = ((u8* (*)(s32, s32, s32))*(u32*)base)(arg0, 0x110, 0x40000);
    *(void**)(obj + 0x58) = sub;
    for (i = 0; i < arg0; i++) {
        *(void**)(sub + i * 0x110 + 0x50) = obj;
        *(u8**)(sub + i * 0x110 + 0x68) = arg1 + i * arg2;
        *(s32*)(sub + i * 0x110 + 0x6C) = arg2;
    }
    if (func_003dd290(obj, arg0, arg4, arg3) != 1) {
        func_0046d740(D_00711658, D_00710870, 0x441);
    }
    return obj;
}

/* measured: opt_propagation off keeps the D_008873AC table address hoisted in
   $s0 across the first four calls and the final pair after $s0 is reused for
   the func_004557e0 result; the outer NULL check is written as an
   assignment-in-condition with an explicit `else { return; }` to place the
   shared return block at .L00455A4C; a block-scope extern of func_004557e0
   with u8* 4th/5th parameters makes the call materialise a0,a1,a2,a3,t0
   left-to-right, while the function still sees the address bits as s32. */
#pragma opt_propagation off
// FUN_004559B0
void func_004559b0(void) {
    void (**base)(void*, void*);
    u8* tmp1;
    u8* tmp2;

    func_003dd760(-1);
    base = D_008873AC;
    base[0](&iGpffffba40, &iGpffffad60);
    base[0](&iGpffffba38, &iGpffffad68);
    if ((tmp1 = func_003dea20(5, D_008C5F80, 0x800, &iGpffffba40, &iGpffffba38)) != NULL) {
        if (func_003dd830(tmp1) == 0) {
            func_00440b68(D_00711670);
            return;
        }
    } else {
        return;
    }
    base[0](&iGpffffba40, &iGpffffad58);
    base[0](&iGpffffba38, &iGpffffad70);
    {
        extern u8* func_004557e0(s32, u8*, s32, u8*, u8*);
        tmp2 = func_004557e0(5, D_008C3780, 0x800, &iGpffffba40, &iGpffffba38);
    }
    if (func_003dd830(tmp2) == 0) {
        func_00440b68(D_00711690);
    } else {
        func_003ddde0(tmp2);
    }
    base = D_008873AC;
    base[0](&iGpffffba40, &iGpffffad78);
    base[0](&iGpffffba38, &iGpffffad80);
    if (func_003dd830(func_00456c60(5, D_008C0F80, 0x800, &iGpffffba40, &iGpffffba38)) == 0) {
        func_00440b68(D_007116B0);
    }
    iGpffffbaa0 = 1;
}
/* measured: restores default propagation after func_004559b0. */
#pragma opt_propagation on

extern u8 D_008C8784[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_007116F0[];
extern char D_00710870[];
void func_0046d740(const void* file, const void* file2, u32 line);

// FUN_00455D70
void func_00455d70(u8* arg0, u8* arg1, u8* arg2, u8* arg3) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (*(s32*)((u8*)D_008C8780 + i * 0x94) == 0) {
            *(s32*)((u8*)D_008C8780 + i * 0x94) = 1;
            *(s32*)(D_008C8784 + i * 0x94) = (s32)arg0;
            *(s32*)(D_008C8808 + i * 0x94) = (s32)arg1;
            *(s32*)(D_008C880C + i * 0x94) = (s32)arg2;
            *(s32*)(D_008C8810 + i * 0x94) = 0;
            func_0043f810((u8*)D_008C8780 + i * 0x94 + 8, arg3, 0x80);
            return;
        }
        if (i == 0xFF) {
            func_0046d740(D_007116D0, D_00710870, 0x4E7);
        }
    }
}

/* measured: the rounded advance is a signed `/ 64 * 64` (retail sra + bgez
   fix-up), and it must be a SECOND `+=` after `entry += 0x100`: one combined
   expression colours the base into $v1 and the fix-up into $v0, the split
   keeps entry+0x100 in $a0 and size+0x3f in $v1 as retail. */
// FUN_00455EA0
u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 header[0x100];
    s32 out_local;
    s32 i;
    u8 *entry;

    if (arg2 == NULL) {
        arg2 = &out_local;
    }
    entry = *(u8 **)(arg0 + 0x110);
    for (i = 0; i < arg1; i++) {
        func_0043f810(header, entry, 0x100);
        entry += 0x100;
        entry += ((*(s32 *)(header + 0xFC) + 0x3F) / 64) * 64;
    }
    func_0043f810(header, entry, 0x100);
    *arg2 = *(s32 *)(header + 0xFC);
    return entry + 0x100;
}
// FUN_00455F70
s32 func_00455f70(s32 arg0, s32* arg1) {
    u8 buf1[0x100];
    u8 buf2[0x100];
    u8 buf3[0x100];
    s32 out_slot;
    s32 i;

    if (arg1 == NULL) {
        arg1 = &out_slot;
    }
    if (arg0 == 1) {
        return 0;
    }
    func_00454d20((void*)arg0, buf1);
    func_00455100(buf1, buf2);
    for (i = 0; i < 0x100; i++) {
        if (*(s32*)((u8*)D_008C8780 + i * 0x94) != 0) {
            func_00455100((u8*)D_008C8780 + i * 0x94 + 8, buf3);
            if (func_004426e8(buf3, buf2) == 0) {
                *arg1 = *(s32*)(D_008C880C + i * 0x94);
                return *(s32*)(D_008C8808 + i * 0x94);
            }
        }
    }
    return 0;
}

// FUN_00456250
s32 func_00456250(s32 arg0, void* arg1, s32 arg2, void* arg3) {
    func_00454d20(arg1, D_008C0680);
    func_00454e10(D_008C0680, D_008C0780, D_008C0880);
    func_004c74f8((void*)arg0, D_008C0780, D_005BC790, arg3);
    return 0;
}

// FUN_00456400
void func_00456400(s32 arg0, s32 arg1, s32 arg2, u8* arg3) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (*(s32*)((u8*)D_008C8780 + i * 0x94) == 0) {
            *(s32*)((u8*)D_008C8780 + i * 0x94) = 1;
            *(s32*)(D_008C8784 + i * 0x94) = arg0;
            *(s32*)(D_008C8808 + i * 0x94) = arg1;
            *(s32*)(D_008C880C + i * 0x94) = arg2;
            *(s32*)(D_008C8810 + i * 0x94) = 0;
            func_0043f810((u8*)D_008C8780 + i * 0x94 + 8, arg3, 0x80);
            return;
        }
        if (i == 0xFF) {
            func_0046d740(D_007116F0, D_00710870, 0x5FF);
        }
    }
}

