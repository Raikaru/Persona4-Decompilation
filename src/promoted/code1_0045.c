#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
extern void func_0045dfd0(void *arg0, void *arg1, f32 farg0, s32 arg2, s32 arg3, s32 arg4);
extern void func_00446ed8(void *buf, const void *fmt, void *va);
extern void func_00450a50(PackedColor4 color, PackedVec2f position, f32 depth, void *characters);
extern s32 iGpffffb9e8;
struct RwCamera;
struct RwSphere;
enum RwFrustumTestResult {
    rwSPHEREOUTSIDE = 0,
    rwSPHEREBOUNDARY = 1,
    rwSPHEREINSIDE = 2,
    rwFRUSTUMTESTRESULTFORCEENUMSIZEINT = 0x7fffffff
};
extern enum RwFrustumTestResult RwCameraFrustumTestSphere(const struct RwCamera *camera,
                                           const struct RwSphere *sphere);
struct RwV3d;
struct RwMatrixTag;
extern struct RwV3d *func_003e42a0(struct RwV3d *out, const struct RwV3d *in,
                                  const struct RwMatrixTag *matrix);
typedef struct Code45CurrentEntities {
    const struct RwCamera *camera;
    void *world;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
} Code45CurrentEntities;
extern Code45CurrentEntities D_008872E0;
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern void RwMatrixUpdate(void *arg0);
extern void RwV3dNormalize(f32 *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern s64 D_00711858[];
extern f32 D_00711860[];
static inline f32 add_f32(f32 a, f32 b) {
    return a + b;
}
extern u8 *iGpffffb9e0;
extern void memset(void *dst, s32 value, s32 size);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} Code45Vec3;

typedef struct RwMatrixTag {
    Code45Vec3 right;
    u32 flags;
    Code45Vec3 up;
    u32 pad1;
    Code45Vec3 at;
    u32 pad2;
    Code45Vec3 pos;
    u32 pad3;
} Code45Matrix;

typedef struct RwSphere {
    Code45Vec3 center;
    f32 radius;
} Code45Sphere;
typedef struct {
    u8 red, green, blue, alpha;
} Code45RGBA;
extern u32 K_Clump_MatUsrDataHasData(const RpMaterial *material, const char *name);
extern s32 func_0045ce40(f32 *out, u8 *colors, s32 *pos, f32 z);
typedef struct Code45RenderState {
    s32 state;
    s32 val;
} Code45RenderState;
extern Code45RenderState D_00712490[6];
extern s32 iGpffffac74;
extern s32 iGpffffad88;
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern void func_003e18c0(void *object, void *callback, s32 userdata);
extern void func_003ca270(void *object, void *callback, void *userdata);
extern void func_003c21e0();
extern void func_004526f0(u8 *arg0, s32 arg1);
extern void func_00452870(void *arg0);
extern void func_00452db0(s32 arg0);
extern void func_004530b0(s32 arg0);
extern u8 D_008C02E0[];
extern s16 D_008C0336[];
extern s16 D_008C0338[];
extern s16 D_008C033C[];
extern s16 D_008C0340[];
extern s16 D_008C0342[];
extern u8 D_008C0346[];
extern u8 D_008C0347[];
extern u8 D_008C0348[];
extern u8 D_008C0349[];
extern void func_004533d0(void);
extern void func_00453310(s32 arg0, u16 arg1, s32 arg2);
extern void func_00453250(s32 arg0, u16 arg1, s32 arg2);
extern u8 *func_004587d0(u8 *arg0, u8 *arg1);
extern void H_Cdvd_BuildPathUppercase(s32 arg0, void *arg1);
extern void memcpy(void *dst, void *src, s32 size);
extern void strcat(void *arg0, void *arg1);
extern void func_00456400(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
extern void *FldRc_ScaleGeometryColors(void *arg0, void *arg1);
extern u8 *func_00458ce0(u8 *material, u8 *data);
extern void *FldRc_SetGeometryVector(void *arg0, void *arg1);
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern void func_004244c8();
extern u8 D_00711720[];
extern s32 func_003bcfa0(RpMaterial *material, char *name, s32 format, s32 numElements);
extern void func_003bd0d0(u8 *userData, s32 index, s32 value);
extern s32 D_00711870_abs[];
extern s32 D_00711890_abs[];
extern f32 func_003bd090(u8 *userData, s32 index);
extern void func_003bd0f0(u8 *userData, s32 index, f32 value);
extern void func_00430e28(void);
extern void func_00430f80();
extern void func_0043bb70();
extern void func_0043c008(s32 arg0);
extern void func_0043c010(s32 arg0);
extern void func_0043c0c0();
extern s32 func_0043bcb8();
extern u8 D_008E4090[];
extern u8 D_008E4230[];
extern s32 D_008E4018_abs[];
extern s32 D_008E40B4_abs[];
extern s32 D_008E40F8_abs[];
extern s32 D_008E413C_abs[];
extern s32 D_008E4180_abs[];
extern s32 D_008E41C4_abs[];
extern s32 D_008E4208_abs[];
extern s32 strlen(void *arg0);
extern s32 func_00426cf0(void *arg0, s32 arg1, s32 arg2);
extern s32 func_004270f8(s32 arg0, s32 arg1, s32 arg2);
extern void func_00426f80(s32 arg0);
extern void func_00428f08(void *arg0, s32 arg1);
extern s32 func_003dd900(s32 arg0);
extern s32 func_003dd290(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void func_00440b68();
extern u8 D_007117C8[];
extern u8 D_007117E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void H_Cdvd_FileContextSlot(void);
extern void H_Cdvd_FileContextFree(void);
extern void H_Cdvd_SlotRead(void);
extern void H_Cdvd_SlotWrite(void);
extern void adminiSeqExitTest(void);
extern void H_Cdvd_SlotSeek(void);
extern s32 H_Cdvd_ProbeFile(s32 arg0);
extern u8 *func_00456c30(void);
extern u8 *func_003c9eb0(void *arg0);
extern u8 *func_003c3d20(s32 arg0);
extern void func_003c38b0(void *arg0, void *arg1);
extern void func_003cbe80(void *arg0, void *arg1);
extern u8 *func_003e9320(void);
extern void func_003e9df0(void *arg0);
extern void func_003efd20(void *arg0, void *arg1);
extern void func_003c3cc0(void *arg0);
extern s32 func_003e89c0(void);
extern void func_003e8970(void *arg0, s32 arg1);
extern u8 *kwlnCameraCreate(u32 arg0, u32 arg1, u32 arg2);
extern void func_003e81c0(void *arg0, f32 arg1);
extern void func_003e8180(void *arg0, f32 arg1);
extern void func_003cbc10(void *arg0, void *arg1);
extern void func_003e9d50(void *arg0, void *arg1, s32 arg2, f32 arg3);
extern void kwlnCameraResizeView(void *arg0, void *arg1, f32 arg2, f32 arg3);
extern s32 func_00410360(void);
extern u8 D_00711800[];
extern u8 D_00711810[];
extern u8 D_00711820[];
extern u8 D_00711830[];
extern u8 D_00756500[];
extern u8 D_00756510[];
extern f32 fGpffff802c;
extern f32 fGpffff8030;
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern u8 *iGpffffba74;
extern u8 *iGpffffba78;
extern u8 *iGpffffba7c;
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern s32 iGpffffba10;
extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
extern u8 D_008C02EC[];
extern u8 D_008C02EE[];
extern u8 D_008C02F0[];
extern u8 D_008C02F6[];
extern u8 D_008C02F8[];
extern u8 D_008C02FA[];
extern u8 D_008C02FC[];
extern u8 D_008C02FD[];
extern u8 D_008C02FE[];
extern u8 D_008C02FF[];
extern u8 D_008C0318[];
extern u8 D_008C02F2[];
extern u8 D_008C0300[];
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];

extern void func_0042eae0(s32 arg0);
extern void sceCdMmode(s32 arg0);
extern void func_0042efe0(s32 arg0);
extern void func_00468a10(s32 arg0);
extern u8 D_008C8780[];
extern u8 D_008D1B80[];
extern u8 D_008D1B84[];
extern u8 D_008D1B88[];
extern u8 D_008D1C90[];
extern u8 D_008D1C98[];
extern u8 D_008D1CD4[];


typedef struct {
    f32 x;
    f32 y;
} Code45Vec2;

typedef struct {
    f32 u;
    f32 v;
} Code45TexCoords;


/* Providers and external symbols */
extern s32 iGpffffb9d4;
extern Code45Vec2 iGpffffac48;
extern Code45Vec2 iGpffffac50;
extern s8 iGpffffb9d8;
extern f32 D_008872F8;
extern u8 D_008BE320[][256];


/* RwDevice's near-screen depth and callback slots are one real object.
 * The complete Sky immediate-mode vertex has a 64-byte stride. */
typedef struct Code45RenderDevice {
    f32 gamma;
    s32 (*system)(s32, void *, void *, s32);
    f32 nearDepth;
    f32 farDepth;
    s32 (*setState)(s32, void *);
    s32 (*getState)(s32, void *);
    u32 renderCallbackAddresses[8];
} Code45RenderDevice;
extern Code45RenderDevice D_008872F0;

typedef struct Code45Im2DVertex {
    f32 position[3];
    f32 cameraZ;
    f32 uv[2];
    f32 reciprocal;
    f32 pad1;
    f32 color[4];
    f32 normal[3];
    f32 pad2;
} Code45Im2DVertex;

#pragma push
#pragma opt_loop_invariants on
static inline s32 overlayAtlasColumn(s32 value)
{
    return value % 16;
}


#pragma pop
#pragma push
#pragma opt_loop_invariants on
/* Character codes are normalized as bytes; the atlas column retains
 * the signed remainder operation used by the original renderer. */
static inline s32 fontAtlasColumn(s32 value)
{
    return value % 16;
}

#pragma pop
#pragma optimization_level 1
#pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2



#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop
// FUN_00453250
void func_00453250(s32 arg0, u16 arg1, s32 arg2) {
    s32 bits;
    s32 off;
    u16 *word;
    u8 *timer;

    off = arg0 * 0x4A;
    bits = arg1 & 0xFFFF;
    if (bits & *(u16 *)(D_008C02EE + off)) {
        *(u8 *)(D_008C0300 + off + arg2) = 7;
        return;
    }
    if (bits & *(u16 *)(D_008C02EC + off)) {
        timer = D_008C0300 + off;
        timer = timer + arg2;
        *timer -= 1;
        if (*timer == 0) {
            word = (u16 *)(D_008C02F2 + off);
            *word |= arg1;
            *timer = 3;
        }
    }
}
// FUN_00453310
void func_00453310(s32 arg0, u16 arg1, s32 arg2) {
    s32 off;
    s32 bits;
    u16 *word;
    u8 *timer;

    off = arg0 * 0x4A;
    bits = arg1 & 0xFFFF;
    if (bits & *(u16 *)(D_008C0316 + off)) {
        *(u8 *)(D_008C031E + off + arg2) = 7;
        return;
    }
    if (bits & *(u16 *)(D_008C0314 + off)) {
        timer = D_008C031E + off;
        timer = timer + arg2;
        *timer -= 1;
        if (*timer == 0) {
            word = (u16 *)(D_008C031A + off);
            *word |= arg1;
            *timer = 3;
        }
    }
}
// FUN_004533D0
void func_004533d0(void)
{
    s16 remaining;
    s16 phase;
    s16 pending;

    phase = iGpffffba1c;
    switch (phase) {
    case 0:
        iGpffffba34 = 0;
        iGpffffba2c = 0;
        iGpffffba20 = 0;
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        iGpffffba1c = (s16)(phase + 1);
        return;
    case 1:
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        return;
    case 2:
        if (iGpffffba34 == 0) {
            iGpffffba1c = 1;
            return;
        }
        remaining = iGpffffba30;
        if (remaining == 0) {
            if (iGpffffba24 == 0) {
                pending = iGpffffba20;
                D_008C030C[0] = pending & 1;
                D_008C030E[0] = pending & 0xFF;
                iGpffffba30 = iGpffffba2c;
                iGpffffba24 = 1;
            } else {
                D_008C030C[0] = 0;
                D_008C030E[0] = 0;
                iGpffffba30 = iGpffffba28;
                iGpffffba24 = 0;
            }
        } else {
            iGpffffba30 = (s16)(remaining - 1);
        }
        iGpffffba34 -= 1;
        return;
    }
}
// FUN_004534F0
void func_004534f0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (func_004535b0() == 0) {
        return;
    }
    iGpffffba34 = arg0;
    iGpffffba30 = 0;
    iGpffffba2c = arg2;
    iGpffffba28 = arg3;
    iGpffffba20 = arg1;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}

// FUN_004535B0
s32 func_004535b0(void)
{
    return iGpffffac74;
}

// FUN_004543D0
s32 func_004543d0(u8 *arg0) {
    s32 f14;
    s32 next28;
    s32 f28;
    s32 reload20;
    s32 f20;
    s32 reload14;
    s32 clamped;

    f14 = *(s32 *)(arg0 + 0x14);
    f20 = *(s32 *)(arg0 + 0x20);
    clamped = f14;
    if (f20 < f14) {
        clamped = f20;
    }
    f28 = *(s32 *)(arg0 + 0x28);
    if ((f28 + f14) >= f20) {
        goto zero;
    }
    next28 = f28 + *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = next28;
    reload14 = *(s32 *)(arg0 + 0x14);
    reload20 = *(s32 *)(arg0 + 0x20);
    if (reload20 >= (next28 + reload14)) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = reload20 - reload14;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = f20 - clamped;
    *(s32 *)(arg0 + 0x24) = clamped - 1;
    return 0;
one:
    return 1;
}
// FUN_00454460
/* The three exits are laid out with explicit gotos because retail places the
   `return 0` block and the `return 1` block out of line, in that order, after
   the main body. The natural nested-if / result-variable spellings all merge
   them into one epilogue and come out two words short (nd 24). */
s32 func_00454460(u8 *arg0) {
    s32 v;
    s32 t;

    v = *(s32 *)(arg0 + 0x28);
    if (v <= 0) {
        goto zero;
    }
    t = v - *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = t;
    if (t >= 0) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = 0;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 0;
one:
    return 1;
}

// FUN_004544B0
void func_004544b0(void)
{
    s32 index;
    u8 *table;

    func_0042eae0(0);
    sceCdMmode(2);
    func_0042efe0(0);
    *(u8 **)D_008D1B80 = NULL;
    *(u8 **)D_008D1B84 = NULL;
    *(s32 *)D_008D1C90 = 0;
    *(s32 *)D_008D1C98 = 0;
    *(s32 *)D_008D1B88 = 0;
    index = 0;
    table = D_008C8780;
    while (index < 0x100) {
        *(s32 *)(table + (index * 0x94)) = 0;
        index += 1;
    }
    *(s32 *)D_008D1CD4 = 0;
    func_00468a10(index);
}



/* measured: MWCC b210 -O2, 348B / 352B window; executable bytes exact.
 * Literal separators with loop-invariant motion and propagation disabled
 * recover the retail register allocation; the final word is zero alignment. */
// FUN_00456530
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_00456530(u8 *basePath, u8 *archive, s32 singleEntry) {
    s32 recordLength;
    u8 directory[0x100];
    u8 fileName[0x100];
    u8 entryPath[0x100];
    s32 dataOffset;
    u8 *cursor;
    s8 character;
    s32 alignedLength;
    s32 biasedLength;
    s32 offset;
    s32 blocks;
    s32 scan;

    H_Cdvd_BuildPathUppercase((s32)basePath, directory);
    offset = 0;
next_entry:
    memcpy(entryPath, directory, 0xFC);
    memcpy(fileName, archive + offset, 0xFC);
    if (*(s8 *)fileName != 0) {
        memcpy(&recordLength, archive + (offset + 0xFC), 4);
        dataOffset = offset + 0x100;
        strcat(entryPath, fileName);
        scan = 0;
        {
            s8 reloadedCharacter;
            while (scan < 0xFF) {
                cursor = entryPath + scan;
                character = *(s8 *)cursor;
                if ((character >= 'a') && (character <= 'z')) {
                    *cursor = (u8)(character - 0x20);
                }
                reloadedCharacter = *(s8 *)cursor;
                if (reloadedCharacter != 0) {
                    if (reloadedCharacter == '/') {
                        *cursor = '\\';
                    }
                    scan += 1;
                } else {
                    break;
                }
            }
        }
        func_00456400(archive, archive + dataOffset, recordLength, entryPath);
        biasedLength = (s32)((u32)recordLength + 0x3FU);
        blocks = biasedLength / 64;
        alignedLength = blocks * 64;
        recordLength = alignedLength;
        offset = (s32)((u32)dataOffset + (u32)alignedLength);
        if (singleEntry != 1) {
            goto next_entry;
        }
    }
}
#pragma pop
// FUN_004566C0
s32 func_004566c0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    u8 sp50[0x100];
    s32 bit0;
    s32 handle;
    s32 flags;
    s32 bit1;

    flags = 0;
    func_004244c8(D_00711720, arg2);
    strcpy((char *)sp50, (const char *)&iGpffffad88);
    strcat(&sp50, arg2 + strlen(&sp50));
    if (arg2 == 0) {
        return 2;
    }
    bit0 = arg3 & 1;
    if ((bit0 != 0) && (bit1 = arg3 & 2, (bit1 != 0))) {
        flags |= 3;
    } else {
        if (bit0 != 0) {
            flags |= 1;
        }
        bit1 = arg3 & 2;
        if (bit1 != 0) {
            flags |= 2;
        }
    }
    if (arg3 & 4) {
        flags |= 0x200;
    }
    if ((bit1 != 0) && !(arg3 & 8)) {
        flags |= 0x400;
    }
    *(s32 *)(arg1 + 0x30) = 0;
    *(s64 *)(arg1 + 0x10) = 0;
    handle = func_00426cf0(&sp50, flags, 0x1FF);
    *(s32 *)(arg1 + 0x74) = handle;
    if (handle < 0) {
        return 3;
    }
    *(s64 *)(arg1 + 0) = (s64)func_004270f8(handle, 0, 2);
    func_004270f8(*(s32 *)(arg1 + 0x74), 0, 0);
    *(s32 *)(arg1 + 0x3C) = 1;
    return 1;
}
// FUN_00456840
void func_00456840(u8 *arg0) {
    func_004244c8(D_00711738);
    *(s32 *)(arg0 + 0x38) = 1;
    func_00426f80(*(s32 *)(arg0 + 0x74));
    func_00428f08(&iGpffffad88, 0);
}

// FUN_00456C30
u8 *func_00456c30(void)
{
    func_004244c8(D_007117B0);
    return (u8 *)&iGpffffad88;
}
/* measured probe: opt_propagation off preserves allocator-table liveness for 00456c60. */
#pragma opt_propagation off
// FUN_00456C60
u8 *func_00456c60(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    void *(*(*alloc_table))(size_t, size_t, u32);
    u8 *record;
    u8 *entries;
    u8 *entry;

    if (func_003dd900(arg4) != 0) {
        return NULL;
    }
    chkmemAllocSiteTag(D_007117C8, 0x106);
    alloc_table = D_008873F4;
    record = (*alloc_table)(1, 0x5C, 0x40000);
    *(void **)(record + 0x14) = (void *)H_Cdvd_FileContextSlot;
    *(void **)(record + 0x18) = (void *)H_Cdvd_FileContextFree;
    *(void **)(record + 0x28) = (void *)func_004566c0;
    *(void **)(record + 0x2C) = (void *)func_00456840;
    *(void **)(record + 0x30) = (void *)H_Cdvd_SlotRead;
    *(void **)(record + 0x34) = (void *)H_Cdvd_SlotWrite;
    *(void **)(record + 0x44) = (void *)adminiSeqExitTest;
    *(void **)(record + 0x38) = (void *)H_Cdvd_SlotSeek;
    *(void **)(record + 0x4C) = (void *)H_Cdvd_ProbeFile;
    *(void **)(record + 0x1C) = (void *)func_00456c30;
    chkmemAllocSiteTag(D_007117C8, 0x116);
    entries = (*alloc_table)(arg0, 0x90, 0x40000);
    *(u8 **)(record + 0x58) = entries;
    index = 0;
    goto loop_00456c60_check;
loop_00456c60_body:
    entry = entries + (index * 0x90);
    *(u8 **)(entry + 0x50) = record;
    *(s32 *)(entry + 0x68) = (s32)(arg1 + (index * arg2));
    *(s32 *)(entry + 0x6C) = arg2;
    index += 1;
loop_00456c60_check:
    if (index < arg0) {
        goto loop_00456c60_body;
    }
    if (func_003dd290(record, arg0, arg4, arg3) != 1) {
        func_00440b68(D_007117E0, index);
    }
    return record;
}
/* measured probe: close opt_propagation scope after func_00456c60. */
#pragma opt_propagation on
// FUN_00456E40
void func_00456e40(void) {
    struct {
        u8 sp40[0x10];
        u8 sp50[8];
        u8 pad[0x18];
        u8 sp70[0x18];
    } work;
    u8 *slot;
    u8 *parent;
    u8 *obj;

    *(s32 *)(work.sp70 + 0x14) = 0xC3160000;
    *(s32 *)(work.sp70 + 0x10) = 0xC3160000;
    *(s32 *)(work.sp70 + 0xC) = 0xC3160000;
    *(s32 *)(work.sp70 + 8) = 0x43160000;
    *(s32 *)(work.sp70 + 4) = 0x43160000;
    *(s32 *)(work.sp70 + 0) = 0x43160000;
    obj = func_003c9eb0(work.sp70);
    iGpffffba70 = (s32)obj;
    if ((parent = func_003c3d20(2)) != NULL) {
        func_003c38b0(parent, D_00711800);
        func_003cbe80(obj, parent);
    }
    iGpffffba74 = parent;
    parent = (u8 *)iGpffffba70;
    if ((slot = func_003c3d20(1)) != NULL) {
        if ((obj = func_003e9320()) != NULL) {
            *(s8 *)(slot + 2) = 1;
            func_003e9df0(obj);
            func_003efd20(slot, obj);
            func_003c38b0(slot, D_00711810);
            func_003cbe80(parent, slot);
        } else {
            func_003c3cc0(slot);
            goto loop_00456e40_second_done;
        }
    } else {
loop_00456e40_second_done:
        slot = NULL;
    }
    iGpffffba78 = slot;
    parent = (u8 *)iGpffffba70;
    if ((slot = func_003c3d20(1)) != NULL) {
        if ((obj = func_003e9320()) != NULL) {
            *(s8 *)(slot + 2) = 1;
            func_003e9d50(obj, D_00756500, 0, 25.0f);
            func_003e9d50(obj, D_00756510, 2, 170.0f);
            func_003efd20(slot, obj);
            func_003c38b0(slot, D_00711820);
            func_003cbe80(parent, slot);
        } else {
            func_003c3cc0(slot);
            goto loop_00456e40_third_done;
        }
    } else {
loop_00456e40_third_done:
        slot = NULL;
    }
    iGpffffba7c = slot;
    parent = (u8 *)iGpffffba70;
    func_003e8970(work.sp50, func_003e89c0());
    if ((obj = kwlnCameraCreate(*(s32 *)work.sp50, *(s32 *)(work.sp50 + 4), 1)) != NULL) {
        func_003e81c0(obj, 25600.0f);
        func_003e8180(obj, 20.0f);
        func_003cbc10(parent, obj);
        *(s32 *)(work.sp40 + 0) = 0;
        *(s32 *)(work.sp40 + 4) = 0;
        *(s32 *)(work.sp40 + 8) = *(s32 *)work.sp50;
        *(s32 *)(work.sp40 + 0xC) = *(s32 *)(work.sp50 + 4);
        kwlnCameraResizeView(obj, work.sp40, 0.5f, fGpffff802c);
        *(f32 *)(obj + 0x88) = fGpffff8030;
    }
    iGpffffba80 = (s32)obj;
    func_00440b68(D_00711830, func_00410360(),
                  *(s32 *)(*(u8 **)(obj + 0x60) + 0x14),
                  *(s32 *)(*(u8 **)(obj + 0x64) + 0x14));
}
// FUN_00457120
s32 func_00457120(void)
{
    return iGpffffba80;
}

// FUN_00457130
s8 *func_00457130(void)
{
    return &iGpffffba88;
}
// FUN_00457140
void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    iGpffffba88 = arg0;
    iGpffffba89 = arg1;
    iGpffffba8a = arg2;
    iGpffffba8b = arg3;
}
// FUN_00457160
s8 *func_00457160(void)
{
    return (s8 *)&iGpffffba84;
}
// FUN_00457170
void func_00457170(s8 arg0, s8 arg1, s8 arg2, s8 arg3)
{
    iGpffffba84 = arg0;
    iGpffffba85 = arg1;
    iGpffffba86 = arg2;
    iGpffffba87 = arg3;
}
// FUN_00457190
s32 func_00457190(void)
{
    return iGpffffba70;
}

// FUN_004571A0
u8 *func_004571a0(void)
{
    return iGpffffba74;
}

// FUN_004571B0
u8 *func_004571b0(void)
{
    return iGpffffba78;
}

// FUN_004571C0
u8 *func_004571c0(void)
{
    return iGpffffba7c;
}

/* measured: opt_propagation off preserves the retail global-load destination register. */
#pragma opt_propagation off
// FUN_00457630
void func_00457630(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct {
        s64 qword;
        f32 value;
    } local;
    s64 source_qword;
    f32 source_value;
    f32 *fallback;
    u8 *record;
    u8 *basis;
    f32 *refVec;
    u8 *fwd;
    u8 *up;
    f32 first_a;
    f32 first_c;

    fallback = (f32 *)&local;
    source_qword = D_00711858[0];
    source_value = D_00711860[0];
    local.qword = source_qword;
    local.value = source_value;
    if (arg3 == NULL) {
        refVec = fallback;
    } else {
        refVec = arg3;
    }
    record = *(u8 **)(arg0 + 4);
    basis = record + 0x10;
    *(Code45Vec3 *)(record + 0x40) = *(Code45Vec3 *)arg1;
    *(f32 *)(record + 0x30) = *(f32 *)(arg2 + 0) - *(f32 *)(record + 0x40);
    *(f32 *)(record + 0x34) = *(f32 *)(arg2 + 4) - *(f32 *)(record + 0x44);
    *(f32 *)(record + 0x38) = *(f32 *)(arg2 + 8) - *(f32 *)(record + 0x48);
    fwd = basis + 0x20;
    RwV3dNormalize((f32 *)fwd, (f32 *)fwd);
    *(f32 *)(basis + 0) =
        *(f32 *)(basis + 0x24) * refVec[2] -
        *(f32 *)(basis + 0x28) * refVec[1];
    *(f32 *)(basis + 4) =
        *(f32 *)(basis + 0x28) * refVec[0] -
        *(f32 *)(basis + 0x20) * refVec[2];
    first_a = *(f32 *)(basis + 0x24);
    first_c = *(f32 *)(basis + 0x20);
    *(f32 *)(basis + 8) =
        first_c * refVec[1] -
        first_a * refVec[0];
    RwV3dNormalize((f32 *)basis, (f32 *)basis);
    *(f32 *)(basis + 0x10) =
        *(f32 *)(basis + 0x24) * *(f32 *)(basis + 8) -
        *(f32 *)(basis + 0x28) * *(f32 *)(basis + 4);
    *(f32 *)(basis + 0x14) =
        *(f32 *)(basis + 0x28) * *(f32 *)(basis + 0) -
        *(f32 *)(basis + 0x20) * *(f32 *)(basis + 8);
    *(f32 *)(basis + 0x18) =
        *(f32 *)(basis + 0x20) * *(f32 *)(basis + 4) -
        *(f32 *)(basis + 0x24) * *(f32 *)(basis + 0);
    up = basis + 0x10;
    RwV3dNormalize((f32 *)up, (f32 *)up);
    RwMatrixUpdate(basis);
    func_003e9680(record);
}
/* measured: close propagation-off probe for func_00457630. */
#pragma opt_propagation on
/* Adds the material's colour user-data entry (key D_00711870) when it is missing, storing the packed RGBA word from the material. An existing entry is left unchanged. */
// FUN_004585C0
void K_Clump_EnsureMatColorUsrData(u8 *arg0) {
    s32 index;
    s32 found;
    s32 value;

    found = 0;
    index = 0;
    goto loop_004585c0_test;
loop_004585c0_body:
    value = (s32)func_003bd000((const RpMaterial *)arg0, index);
    func_003bd040((RpUserDataArray *)value);
    if (strcmp(func_003bd040((RpUserDataArray *)value), (const char *)D_00711870_abs) == 0) {
        found = 1;
        goto loop_004585c0_done;
    }
    index += 1;
loop_004585c0_test:
    if (index < func_003bcfb0((const RpMaterial *)arg0)) {
        goto loop_004585c0_body;
    }
loop_004585c0_done:
    if (found == 0) {
        func_003bd0d0(
            (u8 *)func_003bd000(
                (const RpMaterial *)arg0,
                func_003bcfa0(
                    (RpMaterial *)arg0,
                    (char *)D_00711870_abs,
                    (value = (s32)(
                        *(u8 *)(arg0 + 6) |
                        (*(u8 *)(arg0 + 5) << 8 |
                            (*(u8 *)(arg0 + 7) << 0x18 |
                                (*(u8 *)(arg0 + 4) << 0x10)))), 1),
                    1)),
            0,
            value);
    }
}
// FUN_004586F0
void func_004586f0(u8 *arg0, u8 *arg1) {
    s32 userData;
    s32 index;

    index = 0;
    goto loop_004586f0_test;
loop_004586f0_body:
    userData = (s32)func_003bd000((const RpMaterial *)arg0, index);
    if (strcmp(func_003bd040((RpUserDataArray *)userData), (const char *)D_00711870_abs) != 0) {
        index += 1;
        goto loop_004586f0_test;
    }
    goto loop_004586f0_done;
loop_004586f0_test:
    if (index < func_003bcfb0((const RpMaterial *)arg0)) {
        goto loop_004586f0_body;
    }
loop_004586f0_done:
    func_003bd0d0(
        (u8 *)userData,
        0,
        *(u8 *)(arg1 + 2) |
        (*(u8 *)(arg1 + 1) << 8 |
            (*(u8 *)(arg1 + 3) << 0x18 |
                (*(u8 *)(arg1 + 0) << 0x10))));
}
// FUN_004587D0
/* Measured: 1136/1136 bytes, 23 resolved relocations, no alignment tail.
   Separate userdata lifetimes and index-before-color declarations preserve
   register allocation; unsigned >255 clamps retain the retail branch form. */
u8 *func_004587d0(u8 *material, u8 *data)
{
    f32 *scale = (f32 *)data;
    s32 i;
    s32 found;

    if (K_Clump_MatUsrDataHasData((RpMaterial *)material, (const char *)D_00711870_abs) == 0)
    {
        u32 packedColor;
        s32 index;

        packedColor = ((u32)*(u8 *)(material + 7) << 24) |
                      (*(u8 *)(material + 4) << 16) |
                      (*(u8 *)(material + 5) << 8) |
                      *(u8 *)(material + 6);

        index = func_003bcfa0((RpMaterial *)material, (char *)D_00711870_abs, rpINTUSERDATA, 1);
        func_003bd0d0((u8 *)func_003bd000((RpMaterial *)material, index), 0, (s32)packedColor);
    }

    found = 0;
    for (i = 0; i < func_003bcfb0((RpMaterial *)material); i++)
    {
        RpUserDataArray *userData;
        userData = func_003bd000((RpMaterial *)material, i);
        func_003bd040(userData);
        if (strcmp(func_003bd040(userData), (const char *)D_00711870_abs) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        s32 j;
        u32 colorValue = 0;
        u32 red;
        u32 green;
        u32 blue;
        u32 alpha;
        Code45RGBA color;

        for (j = 0; j < func_003bcfb0((RpMaterial *)material); j++)
        {
            RpUserDataArray *userData;
            userData = func_003bd000((RpMaterial *)material, j);
            if (strcmp(func_003bd040(userData), (const char *)D_00711870_abs) == 0 &&
                func_003bd050(userData) == rpINTUSERDATA)
            {
                colorValue = (u32)func_003bd070(userData, 0);
                break;
            }
        }

        red = (u32)((f32)((colorValue >> 16) & 0xFF) * scale[0]);
        green = (u32)((f32)((colorValue >> 8) & 0xFF) * scale[1]);
        blue = (u32)((f32)(colorValue & 0xFF) * scale[2]);
        alpha = (u32)((f32)((colorValue >> 24) & 0xFF) * scale[3]);

        if (red > 0xFF)
        {
            red = 0xFF;
        }
        color.red = red;

        if (green > 0xFF)
        {
            green = 0xFF;
        }
        color.green = green;

        if (blue > 0xFF)
        {
            blue = 0xFF;
        }
        color.blue = blue;

        if (alpha > 0xFF)
        {
            alpha = 0xFF;
        }
        color.alpha = alpha;

        *(Code45RGBA *)(material + 4) = color;
    }

    return material;
}
// FUN_00458CE0
/* measured: opt_scalarize off keeps the prop triple in stack spill slots with direct sp-relative accesses. */
#pragma push
#pragma opt_scalarize off
u8 *func_00458ce0(u8 *material, u8 *data) {
    Code45Vec3 prop;
    s32 created;
    s32 i;
    s32 current;
    f32 *materialColor;
    if (K_Clump_MatUsrDataHasData((const RpMaterial *)material, (const char *)D_00711890_abs) == 0) {
        materialColor = (f32 *)(material + 0xC);
        created = (s32)func_003bd000((const RpMaterial *)material, func_003bcfa0((RpMaterial *)material, (char *)D_00711890_abs, 2, 3));
        func_003bd0f0((u8 *)created, 0, materialColor[0]);
        func_003bd0f0((u8 *)created, 1, materialColor[1]);
        func_003bd0f0((u8 *)created, 2, materialColor[2]);
    }
    i = 0;
    goto loop_test;
loop_body:
    current = (s32)func_003bd000((const RpMaterial *)material, i);
    if (strcmp(func_003bd040((RpUserDataArray *)current), (const char *)D_00711890_abs) == 0) {
        goto loop_done;
    }
    i += 1;
loop_test:
    if (i < func_003bcfb0((const RpMaterial *)material)) {
        goto loop_body;
    }
loop_done:
    if (current != 0) {
        prop.x = func_003bd090((u8 *)current, 0);
        prop.y = func_003bd090((u8 *)current, 1);
        prop.z = func_003bd090((u8 *)current, 2);
        prop.x = prop.x * *(f32 *)(data + 0);
        prop.y = prop.y * *(f32 *)(data + 4);
        prop.z = prop.z * *(f32 *)(data + 8);
        if (!(prop.x <= 1.0f)) {
            prop.x = 1.0f;
        }
        if (!(prop.y <= 1.0f)) {
            prop.y = 1.0f;
        }
        if (!(prop.z <= 1.0f)) {
            prop.z = 1.0f;
        }
        *(Code45Vec3 *)(material + 0xC) = prop;
    }
    return material;
}
#pragma pop
// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}



// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}

/* The slot loop indexes the global array directly with an s16 counter (the
   dsll32/dsra32 pairs are that counter's sign extension); the second loop is
   a separate s16 counter zeroed BEFORE the D_008E4018 store, which is what
   gives it $v1 and leaves the first counter's $a1 alone. */
/* measured: opt_loop_invariants on hoists the array base into $v1 ahead of
   the loop as retail; a named base local is coloured $a0 (archived nd 8). */
#pragma opt_loop_invariants on
// FUN_0045B430
void func_0045b430(void) {
    s16 i;
    s16 j;

    func_00430e28();
    func_0043c008(0);
    func_0043c010(0x20);
    func_0043bb70(D_008E4230, 0x20, 0);
    func_0043c0c0(0, 0x8F, 0);
    func_0043c0c0(3, 0x83, 0x105, 0x3C, 0);
    func_0043c0c0(3, 0x84, 0x3C, 0x3C);
    func_0043c0c0(3, 0x82, 1);
    func_00430f80(1, 0x8010, 0x800, 0xFC0);
    func_00430f80(1, 0x8010, 0x801, 0xFCC);
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 6; i++) {
        *(s16 *)(D_008E4090 + i * 0x44 + 0) = 0;
        *(s32 *)(D_008E4090 + i * 0x44 + 4) = 0;
        *(s32 *)(D_008E4090 + i * 0x44 + 0x18) = 0;
        *(s16 *)(D_008E4090 + i * 0x44 + 0xA) = i;
    }
    j = 0;
    D_008E4018_abs[0] = 0;
    for (; j < 0x10; j++) {
    }
    D_008E40B4_abs[0] = func_0043bcb8(0x64000);
    D_008E40F8_abs[0] = func_0043bcb8(0xE1000);
    D_008E413C_abs[0] = func_0043bcb8(0x19000);
    D_008E4180_abs[0] = func_0043bcb8(0x19000);
    D_008E41C4_abs[0] = func_0043bcb8(0x19000);
    D_008E4208_abs[0] = func_0043bcb8(0x19000);
}
/* measured: closes the hoisting scope after func_0045b430. */
#pragma opt_loop_invariants off
// FUN_0045C870
void func_0045c870(u8 *colors, s32 enabled)
{
    struct {
        s32 saved[6];
        u8 pad1[8];
        f32 out[64];
    } work;
    f32 depth;
    s32 state;
    f32 inv;
    s32 *p;
    u32 i;
    u32 j;

    if (enabled != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)&work.saved[i]);
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    depth = D_008872F8_abs[0];
    state = func_00457120();
    inv = 1.0f / *(f32 *)((u8 *)state + 0x80);

    work.out[0] = 0.0f;
    work.out[1] = 0.0f;
    work.out[2] = depth;
    work.out[8] = (f32)colors[0];
    work.out[9] = (f32)colors[1];
    work.out[10] = (f32)colors[2];
    work.out[11] = (f32)colors[3];
    work.out[6] = inv;
    work.out[16] = 0.0f;
    work.out[17] = 448.0f;
    work.out[18] = depth;
    work.out[24] = (f32)colors[0];
    work.out[25] = (f32)colors[1];
    work.out[26] = (f32)colors[2];
    work.out[27] = (f32)colors[3];
    work.out[22] = inv;
    work.out[32] = 640.0f;
    work.out[33] = 0.0f;
    work.out[34] = depth;
    work.out[40] = (f32)colors[0];
    work.out[41] = (f32)colors[1];
    work.out[42] = (f32)colors[2];
    work.out[43] = (f32)colors[3];
    work.out[38] = inv;
    work.out[48] = 640.0f;
    work.out[49] = 448.0f;
    work.out[50] = depth;
    work.out[56] = (f32)colors[0];
    work.out[57] = (f32)colors[1];
    work.out[58] = (f32)colors[2];
    work.out[59] = (f32)colors[3];
    work.out[54] = inv;
    D_00887310[0](4, work.out, 4);
    if (enabled != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], work.saved[j]);
        }
    }
    return;
}
// FUN_0045CE40
s32 func_0045ce40(f32 *out, u8 *colors, s32 *pos, f32 z)
{
    f32 *v7;
    s32 result;
    f32 inv;

    v7 = out;
    result = func_00457120();
    inv = 1.0f / *(f32 *)((u8 *)result + 0x80);
    z = D_008872F8_abs[0] - z;
    v7[0] = (f32)pos[0];
    v7[1] = (f32)pos[1];
    v7[2] = z;
    v7[8] = (f32)colors[0];
    v7[9] = (f32)colors[1];
    v7[10] = (f32)colors[2];
    v7[11] = (f32)colors[3];
    v7[6] = inv;
    v7[16] = (f32)(pos[0] + pos[2]);
    v7[17] = (f32)pos[1];
    v7[18] = z;
    v7[24] = (f32)colors[0];
    v7[25] = (f32)colors[1];
    v7[26] = (f32)colors[2];
    v7[27] = (f32)colors[3];
    v7[22] = inv;
    v7[32] = (f32)pos[0];
    v7[33] = (f32)(pos[1] + pos[3]);
    v7[34] = z;
    v7[40] = (f32)colors[0];
    v7[41] = (f32)colors[1];
    v7[42] = (f32)colors[2];
    v7[43] = (f32)colors[3];
    v7[38] = inv;
    v7[48] = (f32)(pos[0] + pos[2]);
    v7[49] = (f32)(pos[1] + pos[3]);
    v7[50] = z;
    v7[56] = (f32)colors[0];
    v7[57] = (f32)colors[1];
    v7[58] = (f32)colors[2];
    v7[59] = (f32)colors[3];
    v7[54] = inv;
    return result;
}
/* Native b210 O2: 880/880 bytes; all six code relocations resolve exactly.
 * Reusing the local corner and the two integer origins preserves the actual
 * fused multiply-accumulate expressions, including their zero accumulator
 * seed. See docs/probe_archive/Primitive_corners_0045d370_20260924.md. */
// FUN_0045D370
#pragma push
#pragma opt_loop_invariants on
void func_0045d370(void *output, void *colorData, void *rectangle, f32 depth,
                  s32 offsetX, s32 offsetY, f32 angle, f32 scaleX, f32 scaleY)
{
    typedef struct { f32 x, y; } QuadPoint;
    QuadPoint corners[4];
    f32 inv;
    f32 sine;
    f32 cosine;
    f32 negSine;
    QuadPoint offset;
    f32 radians;
    s32 centerX;
    s32 centerY;
    f32 displacement;
    u32 i;
    f32 *out;
    u8 *colors;
    s32 *pos;

    out = (f32 *)output;
    colors = (u8 *)colorData;
    pos = (s32 *)rectangle;
    inv = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    depth = D_008872F8_abs[0] - depth;
    pos[2] = (s32)((f32)pos[2] * scaleX);
    pos[3] = (s32)((f32)pos[3] * scaleY);
    radians = fGpffff8200 * angle;
    sine = sinf(radians);
    cosine = cosf(radians);
    /* Traverse the four local corners. Preserve the first point
     * displacement before converting its shared integer origin. */
    offset.x = (f32)(-(s16)offsetX);
    offset.y = (f32)(-(s16)offsetY);
    centerX = pos[0] + (s16)offsetX;
    displacement = 0.0f + offset.y * sine + offset.x * cosine;
    corners[0].x = (f32)centerX + displacement;
    negSine = -sine;
    centerY = pos[1] + (s16)offsetY;
    displacement = 0.0f + offset.y * cosine + offset.x * negSine;
    corners[0].y = (f32)centerY + displacement;
    offset.x = (f32)(pos[2] - (s16)offsetX);
    corners[1].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[1].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    offset.x = (f32)(-(s16)offsetX);
    offset.y = (f32)(pos[3] - (s16)offsetY);
    corners[2].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[2].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    offset.x = (f32)(pos[2] - (s16)offsetX);
    corners[3].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[3].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    for (i = 0; i < 4; i++) {
        QuadPoint *point;
        f32 *dst;
        point = &corners[i];
        dst = (f32 *)((u8 *)out + i * 64);
        dst[0] = point->x;
        dst[1] = point->y;
        dst[2] = depth;
        dst[8] = (f32)(u32)colors[0];
        dst[9] = (f32)(u32)colors[1];
        dst[10] = (f32)(u32)colors[2];
        dst[11] = (f32)(u32)colors[3];
        dst[6] = inv;
    }
}
#pragma pop
// FUN_0045D6E0
void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2)
{
    struct {
        s32 saved[6];
        /* Four 64-byte Sky vertices; the SDK overlay requires quadword alignment. */
        f32 out[64] __attribute__((aligned(16)));
        Code45Float4 pos;
    } work;
    u32 i;
    u32 j;
    Code45RenderState *p;

    work.pos = *(Code45Float4 *)arg1;
    if (arg2 != 0) {
        for (i = 0; i < 6; i++) {
            p = &D_00712490[i];
            D_00887304[0](p->state, (void *)&work.saved[i]);
            D_00887300[0](p->state, p->val);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    memset(work.out, 0, 0x100);
    func_0045ce40(work.out, arg0, (s32 *)&work.pos, fparg0);
    D_00887310[0](4, work.out, 4);
    if (arg2 != 0) {
        for (j = 0; j < 6; j++) {
            p = &D_00712490[j];
            D_00887300[0](p->state, work.saved[j]);
        }
    }
}
// FUN_0045D890
void func_0045d890(void *unused, u8 *arg1)
{
    struct {
        PrimitiveRectangleSignedWords pos;
        s32 saved[6];
        u8 pad1[8];
        f32 out[64];
    } work;
    PrimitiveRectanglePacket *packet;
    f32 scale;
    s32 enabled;
    Code45RenderState *p;
    u32 i;
    u32 j;

    packet = (PrimitiveRectanglePacket *)arg1;
    work.pos = packet->rectangle.signedWords;
    scale = packet->depth;
    enabled = packet->saveState;
    if (enabled != 0) {
        for (i = 0; i < 6; i++) {
            p = &D_00712490[i];
            D_00887304[0](p->state, (void *)&work.saved[i]);
            D_00887300[0](p->state, p->val);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    func_0045ce40(work.out, packet->color.rgba, work.pos.word, scale);
    D_00887310[0](4, work.out, 4);
    if (enabled != 0) {
        for (j = 0; j < 6; j++) {
            p = &D_00712490[j];
            D_00887300[0](p->state, work.saved[j]);
        }
    }
    D_008873EC[0](arg1);
}
/* STEP 4 (2026-09-20): this MATCH rests on a banned construct. `volatile u8 *arg0` */
/* is compiler-steering (H001): arg0 is a plain color buffer, not hardware, and the */
/* qualifier exists only to defeat b210 CSE. Re-measured 2026-09-20 in isolated */
/* probe copies (production never written for probes): baseline volatile + prop off */
/* probe_variants 0 words, fndiff 0 (obj 148B/window 160B, 12B zero tail); plain u8 * */
/* + prop off only: probe 22 words, fnalign 9 edits (retail 36 vs object 29 instrs, */
/* 8 lbu in two reload groups deleted, call tail exact) -- plain CSEs the reloads; */
/* plain + prop off + common_subs off (function-scoped): probe 1 word, fnalign 1 edit */
/* (retail move $a3,$a2 vs object addiu $a3,$zero,3; 37/37 instrs) -- reloads return */
/* but the 3,3 pair un-CSEs from retail li $a2,3 / move $a3,$a2; narrower scope */
/* (common off before fn, on inside before call): probe 22 words, fnalign 9 edits */
/* identical to plain -- pragma is function-granular, cannot split loads from call; */
/* reordered 3,3 (s32 n=3 as n,n / 3,n / n,3; s32 a=3,b=a as a,b): probe 27/28/28/28 */
/* words, copy-through fnalign 11 edits with addiu hoisted to prologue and $t1 lost. */
/* Callers: owner_of.py -> src/promoted/code1_0045.c; grep src+include finds no other */
/* volatile declaration (src/Kernel/mc.c declares void *,void *,s32,f32, not edited). */
/* opt_propagation off keeps the colors pointer in $t1; it is not the banned part. */
/* Honest plain-C best is the 1-word common-off body, still MISMATCH. */
#pragma opt_propagation off
// FUN_0045ED60
void func_0045ed60(volatile u8 *arg0, void *arg1, s32 arg2, f32 fparg0) {
    u8 colors[12];
    u8 *ptr = colors;
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[0] = color0;
    colors[1] = color1;
    colors[2] = color2;
    colors[3] = color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[4] = color0;
    colors[5] = color1;
    colors[6] = color2;
    colors[7] = color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[8] = color0;
    colors[9] = color1;
    colors[10] = color2;
    colors[11] = color3;
    func_0045dfd0(ptr, arg1, fparg0, 3, 3, arg2);
}
/* measured: restores propagation after func_0045ed60. */
#pragma opt_propagation on
// FUN_0045EE00
void func_0045ee00(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, f32 fparg0, f32 fparg1, u8 *arg4) {
    u8 colors[12];
    f32 coords[6];
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f22_3;
    f32 temp_f21;
    f32 temp_f0;
    temp_f23 = fGpffff8200 * fparg0;
    temp_f22 = sinf(temp_f23);
    temp_f0 = cosf(temp_f23);
    arg3 = -arg3;
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[0] = (f32)arg0 + (zero * temp_f0 + scale * temp_f22);
        coords[1] = (f32)arg1 + (zero * -temp_f22 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[0] = color0;
    colors[1] = color1;
    colors[2] = color2;
    colors[3] = color3;

    {
        f32 offset;
        offset = 120.0f;
        fparg0 = add_f32(offset, fparg0);
    }
    if (!(fparg0 < 360.0f)) {
        fparg0 -= 360.0f;
    }
    temp_f23 = fGpffff8200 * fparg0;
    temp_f22 = sinf(temp_f23);
    temp_f0 = cosf(temp_f23);
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[2] = (f32)arg0 + (zero * temp_f0 + scale * temp_f22);
        coords[3] = (f32)arg1 + (zero * -temp_f22 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[4] = color0;
    colors[5] = color1;
    colors[6] = color2;
    colors[7] = color3;

    {
        f32 offset;
        offset = 120.0f;
        fparg0 = add_f32(offset, fparg0);
    }
    if (!(fparg0 < 360.0f)) {
        fparg0 -= 360.0f;
    }
    temp_f22_3 = fGpffff8200 * fparg0;
    temp_f21 = sinf(temp_f22_3);
    temp_f0 = cosf(temp_f22_3);
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[4] = (f32)arg0 + (zero * temp_f0 + scale * temp_f21);
        coords[5] = (f32)arg1 + (zero * -temp_f21 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[8] = color0;
    colors[9] = color1;
    colors[10] = color2;
    colors[11] = color3;
    func_0045dfd0(colors, coords, fparg1, 3, 3, (s32)arg4);
}
/* Draw a closed, twenty-segment ring after a sphere/frustum test. The
 * optional matrix supplies orientation; its translation becomes center.
 * Native b210 -O2: 1504/1504 bytes, 31 fully resolved relocations, no tail.
 * Source value/scoping order preserves the measured projection operations;
 * no per-function optimization overrides or arithmetic assembly are needed.
 * See docs/probe_archive/Projected_ring_0045fbe0_20260924.md. */
// FUN_0045FBE0
void primCircleLine3D(const Code45Vec3 *center, f32 radius, u8 *inputColors, f32 *inputMatrix, s32 inputPreserveState)
{
    typedef union RingMatrix {
        Code45Matrix fields;
        s32 pairs[8][2];
    } RingMatrix;
    Code45Vec3 localPoint;
    Code45Vec3 worldPoint;
    Code45Vec3 cameraPoint;
    Code45Im2DVertex vertices[21];
    s32 savedStates[6];
    RingMatrix matrix;
    Code45Sphere sphere;
    u8 *colors;
    f32 *sourceMatrix;
    s32 preserveState;
    f32 angle;
    f32 farDepth;
    f32 nearPlane;
    f32 farPlane;
    f32 depthScale;
    u32 stateIndex;
    u32 restoreIndex;
    Code45Im2DVertex *vertex;

    colors = inputColors;
    sourceMatrix = inputMatrix;
    preserveState = inputPreserveState;
    sphere.radius = radius;
    sphere.center.x = center->x;
    sphere.center.y = center->y;
    sphere.center.z = center->z;
    if (RwCameraFrustumTestSphere(D_008872E0.camera, &sphere) != 0) {
        const void *view;
        farDepth = D_008872FC_abs[0];
        depthScale = D_008872F8_abs[0];
        farPlane = *(f32 *)((u8 *)(u32)func_00457120() + 0x84);
        nearPlane = *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
        view = (u8 *)(u32)func_00457120() + 0x20;
        if (sourceMatrix != NULL) {
            const s32 (*source)[2];
            s32 (*destination)[2];
            s32 remaining;
            source = (const s32 (*)[2])sourceMatrix;
            destination = matrix.pairs;
            remaining = 8;
            do {
                s32 first = (*source)[0];
                s32 second = (*source)[1];
                source++;
                remaining--;
                (*destination)[0] = first;
                (*destination)[1] = second;
                destination++;
            } while (remaining > 0);
        } else {
            matrix.fields.at.z = 1.0f;
            matrix.fields.up.y = 1.0f;
            matrix.fields.right.x = 1.0f;
            matrix.fields.up.x = 0.0f;
            matrix.fields.right.z = 0.0f;
            matrix.fields.right.y = 0.0f;
            matrix.fields.at.y = 0.0f;
            matrix.fields.at.x = 0.0f;
            matrix.fields.up.z = 0.0f;
            matrix.fields.pos.z = 0.0f;
            matrix.fields.pos.y = 0.0f;
            matrix.fields.pos.x = 0.0f;
            /* Retail expands RwMatrixSetIdentityMacro here, including its
             * read/OR/write of flags without a preceding local initialization.
             * Preserve that original defect; do not invent a flags-zero store. */
            matrix.fields.flags |= 0x20003;
        }
        matrix.fields.pos = *center;
        if (preserveState != 0) {
            for (stateIndex = 0; stateIndex < 6; stateIndex++) {
                const Code45RenderState *state = &D_00712490[stateIndex];
                D_00887304[0](state->state, &savedStates[stateIndex]);
                D_00887300[0](state->state, state->val);
            }
            D_00887300[0](1, 0);
            RpSkyRenderStateSet(2, 0x48);
            RpSkyRenderStateSet(3, 0x71801);
        }
        {
            u32 vertexIndex;
            vertex = vertices;
            angle = 0.0f;
            localPoint.y = 0.0f;
            vertexIndex = 0;
            /* Convert the saved screen-near value to the projection slope. */
            depthScale = (depthScale - farDepth) / (nearPlane - farPlane);
            while (vertexIndex < 20) {
                f32 screenDepth;
                f32 ratio;
                f32 distance;
                f32 scaledDistance;
                localPoint.x = radius * cosf(angle);
                localPoint.z = radius * sinf(angle);
                func_003e42a0(&worldPoint, &localPoint, &matrix.fields);
                func_003e42a0(&cameraPoint, &worldPoint, (const Code45Matrix *)view);
                ratio = nearPlane / cameraPoint.z;
                distance = cameraPoint.z - farPlane;
                scaledDistance = distance * depthScale;
                screenDepth = farDepth + ratio * scaledDistance;
                cameraPoint.x = 640.0f * (cameraPoint.x / cameraPoint.z);
                cameraPoint.y = 448.0f * (cameraPoint.y / cameraPoint.z);
                vertex->position[0] = cameraPoint.x;
                vertex->position[1] = cameraPoint.y;
                vertex->position[2] = screenDepth;
                vertex->reciprocal = 1.0f / screenDepth;
                vertex->color[0] = (f32)(u32)colors[0];
                vertex->color[1] = (f32)(u32)colors[1];
                vertex->color[2] = (f32)(u32)colors[2];
                vertex->color[3] = (f32)(u32)colors[3];
                vertex++;
                angle += fGpffff81f0;
                vertexIndex++;
            }
            vertex->position[0] = vertices[0].position[0];
            vertex->position[1] = vertices[0].position[1];
            vertex->position[2] = vertices[0].position[2];
            vertex->reciprocal = vertices[0].reciprocal;
            vertex->color[0] = (f32)(u32)colors[0];
            vertex->color[1] = (f32)(u32)colors[1];
            vertex->color[2] = (f32)(u32)colors[2];
            vertex->color[3] = (f32)(u32)colors[3];
            D_00887310[0](2, vertices, 21);
        }
        if (preserveState != 0) {
            for (restoreIndex = 0; restoreIndex < 6; restoreIndex++) {
                const Code45RenderState *state = &D_00712490[restoreIndex];
                D_00887300[0](state->state, savedStates[restoreIndex]);
            }
        }
    }
}
