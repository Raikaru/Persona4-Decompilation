/* Source unit: src/Battle/btlFormation_001d1eb0.c */
#include "include_asm.h"
#include "type.h"

typedef int (*code)(...);

typedef void (*BtlPacketInitFunc)(void* work);
typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketInitFunc initFunc;
    BtlPacketUpdateFunc updateFunc;
    BtlPacketUpdateFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_001d1cc0(int* param_1);
extern u32 func_001d1f30(u32 *work);
extern void func_001d2e00(u32 *work);
extern u32 func_001d2e20(u8 *param_1);
extern void func_001d2fe0(u32 *work);
extern u32 func_001d3090(u32 *work);
extern u32 func_001d35a0(u16 *param_1);
extern u32 func_001d3760(u16 *param_1);
extern u32 func_001d3950(u8 **param_1);
extern u32 func_001d3ba0(void);
extern u32 func_001d6ce0(u32 param_1);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 D_00609498[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *D_0076449C;
extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00194ee0(void *arg0, void *arg1);
extern void func_00194f10(void *arg0, void *arg1);
extern s32 func_00196b50(void *arg0);
extern void func_00196b70(void *arg0);
extern void func_00196ba0(void *arg0);
extern void func_0019dea0(void *arg0);
extern void func_001ee490(void *arg0);
extern u8 *func_001b1510(void);
extern void func_001d1680(s32 arg0, s32 arg1);
extern s32 func_00232710(u32 arg0, u32 arg1);
extern s32 func_002428f0(u32 arg0, u32 arg1);
extern void func_003e40b0(f32 *arg0, f32 *arg1);

typedef struct BtlFormationState
{
    u8 padding[0x630];
    u16 flags;
    u16 counter;
    u32 value;
} BtlFormationState;

extern void func_001d3ff0(int state);
extern void (*DAT_008873EC[])(...);

extern u64 memcpy();
extern u32 func_00485c80(u32 param_1);
extern u32 func_00484bb0(u32 param_1);

extern u64 func_00485b20(u32 param_1);

extern void func_001d3ea0(int destination, u32 source);

typedef struct BtlFormationWork
{
    u32 state;
    u32 list;
    u32 argument5;
    u8 padding0c[4];
    s32 sentinel;
    u8 random;
    u8 padding15[3];
    u32 argument3;
    u32 argument4;
    u8 padding20[0x34];
    u16 count;
    u16 padding56;
    u32 items;
} BtlFormationWork;

// P3 counterpart fGpffff8398 (gp -0x7C68); P4 retail uses gp -0x7CAC,
// i.e. absolute 0x007690f0 - 0x7cac = 0x00761444.
extern float fGpffff8354;
// P3 counterpart fGpffff839c (gp -0x7C64); P4 retail uses gp -0x7EE4,
// i.e. absolute 0x007690f0 - 0x7ee4 = 0x0076120c.
extern float fGpffff811c;
extern u32 strlen();
extern u32 strcpy();
extern void func_001d5ca0(u32 *param_1);
extern u32 func_001d5d60(u32 *param_1);

typedef u8 bool;

#define true 1
#define false 0

extern bool func_001d4120(int param_1);
extern u32 func_001d4190(int param_1, u16 param_2);

extern u32 func_001d6de0(int param_1, u16 *param_2);
extern void func_001d3e00(u32 param_1);
extern void func_001d5f60(u32 *param_1);
extern u32 func_001d6010(u32 *param_1);

extern bool func_001d6170(u32 *param_1);
extern void func_001d61e0(u32 *param_1);

extern u8* DAT_0076449c;
extern char D_00609570[];
extern u8 *func_001d41b0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern char D_00609588[];
extern u8 D_00763388;

void sprintf(u64 context, const char* format, ...);

void func_001fc2e0(u32 first, u32 second, u32 third);
u32 func_002027b0(void);



// FUN_001D1EB0
void func_001d1eb0(u32 param_1, u32 param_2, float param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb00, 0x10);
    *(code **)(packet + 0x6c) = (code *)func_001d1cc0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    *(float *)(work + 2) = param_3;
    *(u16 *)(work + 3) = param_4;
}



// FUN_001D1F30
INCLUDE_ASM("asm/nonmatchings/btlFormation", func_001d1f30);
// FUN_001D2D90
void func_001d2d90(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb01, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d1f30;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
}



// FUN_001D2E00
void func_001d2e00(u32 *work)
{
    *(u16 *)(work[0] + 0xa0) = *(u16 *)(work[0] + 0xa0) + 1;
}
// FUN_001D2E20
INCLUDE_ASM("asm/nonmatchings/btlFormation", func_001d2e20);
// FUN_001D2FE0
void func_001d2fe0(u32 *work)
{
    *(u16 *)(work[0] + 0xa0) = *(u16 *)(work[0] + 0xa0) - 1;
}
// FUN_001D3000
void func_001d3000(u32 param_1, u32 param_2, u32 param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb02, 0x10);
    *(code **)(packet + 0x68) = (code *)func_001d2e00;
    *(code **)(packet + 0x6c) = (code *)func_001d2e20;
    *(code **)(packet + 0x70) = (code *)func_001d2fe0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
}



// FUN_001D3090
u32 func_001d3090(u32 *work)
{
    typedef struct RtQuat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RtQuat;

    extern void func_00195590(void *arg0, void *arg1);
    extern f32 func_00196bd0(void *arg0, void *arg1, s32 arg2);
    extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *rot);
    extern f32 D_0060A0E0[3];
    extern f32 D_0060A0F0[3];

    u16 sel;
    RtQuat rotation;
    f32 diff[3];
    f32 dest[3];
    f32 scale;

    sel = *(u16 *)(work + 2);
    switch (sel) {
    case 0:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= 100.0f;
        diff[1] *= 100.0f;
        diff[2] *= 100.0f;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    case 1:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= 150.0f;
        diff[1] *= 150.0f;
        diff[2] *= 150.0f;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    case 2:
        func_00194ee0((void *)work[0], (u8 *)work[1] + 4);
        func_00194f10((void *)work[0], (u8 *)work[1] + 0x1c);
        break;
    case 3:
        rotation = *(RtQuat *)((u8 *)work[1] + 0x1c);
        if ((*(u32 *)(D_0076449C + 0xc) & 0x200000) == 0) {
            func_003dc740(&rotation, D_0060A0E0, 2, 90.0f);
        } else {
            func_003dc740(&rotation, D_0060A0E0, 2, 130.0f);
        }
        func_003dcb40(diff, D_0060A0F0, 1, &rotation);
        diff[0] *= 250.0f;
        diff[1] *= 250.0f;
        diff[2] *= 250.0f;
        dest[0] = *(f32 *)((u8 *)work[0] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[0] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[0] + 0xc) + diff[2];
        func_00194ee0((void *)work[1], dest);
        break;
    case 4:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        scale = func_00196bd0((void *)work[0], (void *)work[1], 7);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= scale;
        diff[1] *= scale;
        diff[2] *= scale;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    }
    return 1;
}
// FUN_001D3530
void func_001d3530(u32 param_1, u32 param_2, u16 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb03, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d3090;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    *(u16 *)(work + 2) = param_3;
}
// FUN_001D35A0
u32 func_001d35a0(u16 *arg0)
{
    u8 sp80[0x10];
    u8 sp70[0x10];
    s32 temp_16;
    s32 temp_17;
    s32 temp_21;
    u32 temp_18;
    u16 temp_2;
    u8 *var_20;
    u32 var_19;

    temp_18 = arg0[0];
    temp_2 = arg0[1];
    var_19 = 0;
    temp_17 = temp_2 & 0x8000;
    temp_16 = temp_2 & 1;
    temp_21 = temp_2 & 2;
    while (var_19 < 4) {
        if ((temp_18 & (1 << var_19)) != 0) {
            var_20 = *(u8 **)(D_0076449C + var_19 * 8 + 0x178);
            while (var_20 != NULL) {
                if (((*(u32 *)(var_20 + 0x9c) & 4) != 0) &&
                    ((temp_17 == 0) || (func_00196b50(var_20) == 0))) {
                    func_00194ff0(var_20, sp80, sp70, NULL);
                    if (temp_16 != 0) {
                        func_00194ee0(var_20, sp80);
                        func_00196b70(var_20);
                        func_001ee490(var_20);
                    }
                    if (temp_21 != 0) {
                        func_00194f10(var_20, sp70);
                        func_00196ba0(var_20);
                        func_0019dea0(var_20);
                    }
                }
                var_20 = *(u8 **)(var_20 + 0xa6c);
            }
        }
        var_19++;
    }
    return 1;
}
// FUN_001D3700
void func_001d3700(u16 param_1, u16 param_2)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb04, 4);
    *(code **)(packet + 0x6c) = (code *)func_001d35a0;
    work = *(u32 **)(packet + 0x78);
    *(u16 *)(work + 0) = param_1;
    *(u16 *)((u8 *)work + 2) = param_2;
}
// FUN_001D3760
u32 func_001d3760(u16 *arg0)
{
    f32 sp60[4];
    f32 sp50[4];
    f32 sp40[4];
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f20;
    u8 *temp_16;
    u8 *var_17;

    temp_16 = func_001b1510();
    func_001d1680(!(*arg0 & 2), 0);
    if ((*arg0 & 1) != 0) {
        var_17 = *(u8 **)(D_0076449C + 0x178);
        while (var_17 != NULL) {
            if ((func_00232710(*(u32 *)(var_17 + 0xa64), 0x180017) == 0) &&
                (func_002428f0(*(u32 *)(var_17 + 0xa64), 0) == 0)) {
                if (*(u8 **)(temp_16 + 0x30) == var_17) {
                    var_f20 = 250.0f;
                } else {
                    var_f20 = 350.0f;
                }
                func_00194ff0(var_17, sp60, NULL, sp50);
                sp50[1] = sp60[1];
                sp40[0] = sp60[0] - sp50[0];
                sp40[1] = sp60[1] - sp60[1];
                sp40[2] = sp60[2] - sp50[2];
                func_003e40b0(&sp40[0], &sp40[0]);
                temp_f3 = sp40[0] * var_f20;
                sp40[0] = temp_f3;
                temp_f2 = sp40[1] * var_f20;
                sp40[1] = temp_f2;
                temp_f1 = sp40[2] * var_f20;
                sp40[2] = temp_f1;
                sp60[0] += temp_f3;
                sp60[1] += temp_f2;
                sp60[2] += temp_f1;
                func_00194ee0(var_17, sp60);
            }
            var_17 = *(u8 **)(var_17 + 0xa6c);
        }
    }
    return 1;
}
// FUN_001D3900
void func_001d3900(u16 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb05, 2);
    *(code **)(packet + 0x6c) = (code *)func_001d3760;
    work = *(u32 **)(packet + 0x78);
    *(u16 *)(work + 0) = param_1;
}
// FUN_001D3950
INCLUDE_ASM("asm/nonmatchings/btlFormation", func_001d3950);
// FUN_001D3B50
void func_001d3b50(u32 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb06, 4);
    *(code **)(packet + 0x6c) = (code *)func_001d3950;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
}
// FUN_001D3BA0
u32 func_001d3ba0(void)
{
    typedef struct FormationVectors {
        f32 offsets[3];
        u32 gap0;
        f32 transformed[3];
        u32 gap1;
        u8 padding[32];
        f32 base[3];
        u32 gap2;
        f32 result[3];
        u32 gap3;
    } FormationVectors;
    FormationVectors vectors;
    u16 index;
    u8 *node;
    f32 *offset;
    extern u8 D_00609470[];
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *rot);

    node = *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30);
    func_00194ff0(node, vectors.base, vectors.offsets, NULL);
    func_00196b70(node);
    func_00196ba0(node);
    func_00194ee0(node, vectors.base);
    func_00194f10(node, vectors.offsets);
    func_003dcb40(vectors.transformed, D_00609470, 3, vectors.offsets);
    index = 0;
    while (index < *(u16 *)(D_0076449C + 0xc58)) {
        {
            u32 current;

            current = index;
            node = *(u8 **)(*(u8 **)(D_0076449C + current * 4 + 0xc48) + 0x30);
            offset = &vectors.transformed[current * 3];
        }
        vectors.result[0] = vectors.base[0] + offset[0];
        vectors.result[1] = vectors.base[1] + offset[1];
        vectors.result[2] = vectors.base[2] + offset[2];
        func_00196b70(node);
        func_00196ba0(node);
        func_00194ee0(node, vectors.result);
        func_00194f10(node, vectors.offsets);
        index++;
    }
    return 1;
}
// FUN_001D3D00
void func_001d3d00(u32 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb07, 4);
    *(code **)(packet + 0x6c) = (code *)func_001d3ba0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
}
// FUN_001D3D50
void func_001d3d50(u32 param_1)
{
    BtlFormationState *state;

    func_0044ea90(&D_00609498, 0x3A);
    state = (BtlFormationState *)jtbl_008873E8[0](0x638, 0x40000);
    switch (param_1 & 0xffff) {
    case 0:
        state->flags = 0;
        break;
    case 1:
        state->flags = 0;
        break;
    case 2:
        state->flags = 8;
        break;
    }
    state->counter = 1;
    state->value = 0;
}
// FUN_001D3E00
void func_001d3e00(u32 param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter--;
    if (((state->flags & 8) != 0) && (state->counter == 1)) {
        func_001d3ff0((int)state);
    }
    if (state->counter == 0) {
        if ((state->flags & 2) != 0) {
            func_001d3ff0((int)state);
        }
        (*DAT_008873EC)(state);
    }
}



// FUN_001D3EA0
void func_001d3ea0(int destination, u32 source)
{
    u16 outer;
    u16 index;
    s32 count;
    u8* entry;
    int block;
    u8* referencedEntry;
    u32 packed;
    u32 resource;
    u32 continueLoop;

    memcpy(destination, source, 0x630);
    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = destination + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        for (index = 0; index < count; index++) {
            if (entry[0] != 0xfe) {
                if (entry[0] == 0xff) {
                    packed = *(u32 *)(entry + 4);
                    referencedEntry = (u8 *)(destination + (packed >> 5) * 0x314 +
                                             (packed & 0x1f) * 0x18 + 0x1c);
                    resource = func_00485c80(*(u32 *)(referencedEntry + 4));
                    entry[0] = referencedEntry[0];
                } else {
                    resource = func_00484bb0(source + *(u32 *)(entry + 4));
                }
                *(u32 *)(entry + 4) = resource;
            }
            entry += 0x18;
        }
        outer++;
    }
    *(u16 *)(destination + 0x630) |= 2;
}



// FUN_001D3FF0
void func_001d3ff0(int state)
{
    u16 outer;
    u16 index;
    int count;
    u8 *entry;
    int block;
    u32 continueLoop;

    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = state + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        index = 0;
        while (index < count) {
            if (*entry != 0xfe && *entry != 0xfd) {
                func_00485b20(*(u32 *)(entry + 4));
            }
            entry += 0x18;
            index++;
        }
        outer++;
    }
    *(u16 *)(state + 0x630) &= 0xfffd;
}



// FUN_001D40D0
void func_001d40d0(int param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter++;
    if (((state->flags & 8) != 0) && (state->counter == 2)) {
        func_001d3ea0(param_1, state->value);
    }
}



// FUN_001D4140
u32 func_001d4140(int param_1, u16 param_2)
{
    u32 result;

    switch (param_2) {
    case 0:
        result = *(u32 *)(param_1 + 8);
        break;
    case 1:
        result = *(u32 *)(param_1 + 0x328);
        break;
    default:
        result = 0;
        break;
    }
    return result;
}



// FUN_001D42E0
void func_001d42e0(BtlFormationWork *work)
{
    s32 count;
    u16 index;
    u32 *items;

    count = work->count;
    items = (u32 *)(uintptr_t)work->items;
    index = 0;
    while (index < count) {
        if (*items != 0) {
            func_00485b20(*items);
        }
        items++;
        index++;
    }
    (*DAT_008873EC)(work);
}



// FUN_001D4380
float func_001d4380(int param_1)
{
    float fVar1 = 0;

    fVar1 = fGpffff8354 * ((*(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x2c) +
            *(float *)(param_1 + 0x8c) * *(float *)(param_1 + 0x2c) * 0.5f) * 0.5f);
    if (fVar1 > 2.5f) {
        fVar1 = 2.5f;
    }
    else if (fVar1 < fGpffff811c) {
        fVar1 = fGpffff811c;
    }
    return fVar1;
}



// FUN_001D5EB0
u32 func_001d5eb0(u32 param_1, u32 param_2, u16 param_3)
{
    typedef struct FormationStringWork {
        u32 value;
        u32 unused;
        char *text;
        u16 field;
        u16 padding;
    } FormationStringWork;
    BtlPacket *packet;
    FormationStringWork *work;

    packet = func_00194470(0x400, strlen(param_2) + sizeof(FormationStringWork));
    packet->flags &= 0xfe;
    packet->initFunc = (BtlPacketInitFunc)func_001d5ca0;
    packet->updateFunc = (BtlPacketUpdateFunc)func_001d5d60;
    work = packet->workData;
    work->value = param_1;
    work->text = (char *)(work + 1);
    work->field = param_3;
    strcpy(work->text, param_2);
    return (u32)packet;
}



// FUN_001D5F60
void func_001d5f60(u32 *work)
{
    s16 mode;

    work[6] = 0;
    func_001d40d0(work[0]);
    *(u16 *)(work[1] + 0xa0) = *(u16 *)(work[1] + 0xa0) + 1;
    *(u16 *)(work[2] + 0xa0) = *(u16 *)(work[2] + 0xa0) + 1;
    mode = *(s16 *)((u8 *)work + 0xc);
    switch (mode) {
    case 0:
        work[5] = *(u32 *)(work[1] + 0xa08);
        break;
    case 1:
        work[5] = *(u32 *)(work[2] + 0xa08);
        break;
    }
    work[4] = func_001d6ce0(work[5]);
}
// FUN_001D6010
/* measured: opt_propagation off preserves func_001d6010's index-before-value argument-load order (MATCH nd0). */
#pragma opt_propagation off
u32 func_001d6010(u32 *param_1)
{
    s16 sVar1;
    u16 *puVar2;
    int iVar3;
    u16 functionIndex;
    u32 unaff_s2_lo;
    u32 unaff_s1_lo;

    if (!func_001d4120(param_1[0])) {
        return 0;
    }
    puVar2 = (u16 *)param_1[4];
    if ((*(u32 *)(puVar2 + 2) & 0xff000000) == 0) {
        return 1;
    }
    functionIndex = *(u16 *)(param_1 + 3);
    iVar3 = func_001d4140(param_1[functionIndex & 0], functionIndex);
    if ((*puVar2 & 0x40) == 0) {
        if ((int)param_1[6] >= iVar3 * 2 - 0xd) {
            *puVar2 = *puVar2 | 0x100;
            return 0;
        }
        if (param_1[6] == 0) {
            u32 flags = param_1[7];

            if ((flags & 0xc00) != 0xc00) {
                sVar1 = *(short *)(param_1 + 3);
                switch (sVar1) {
                case 0:
                    unaff_s2_lo = param_1[1];
                    unaff_s1_lo = param_1[2];
                    break;
                case 1:
                    unaff_s2_lo = param_1[2];
                    unaff_s1_lo = param_1[1];
                    break;
                }
                *(u32 *)(puVar2 + 8) =
                    (u32)func_001d41b0((u8 *)param_1[0], sVar1 & 0xffff,
                                       unaff_s2_lo, unaff_s1_lo, flags);
                *puVar2 = *puVar2 | 0x30;
            }
        }
        param_1[6] = param_1[6] + 2;
    }
    return 0;
}
/* measured: opt_propagation on closes the func_001d6010 bracket. */
#pragma opt_propagation on
// measured: #pragma opt_propagation off preserves retail's index-before-value argument-load order; plain C without it emits the two loads in the opposite order. Object 112B, retail window 112B, normalized_diff 0.
// Committed at nd 0.
// FUN_001D6170
/* measured: opt_propagation off probe for 6170 argument loads. */
#pragma opt_propagation off
bool func_001d6170(u32 *param_1)
{
    int iVar2;
    u16 index;
    u32 value;

    if (!func_001d4120(*param_1)) {
        return false;
    }
    iVar2 = (index = *(u16 *)(param_1 + 3),
             value = *(u32 *)((u8 *)param_1 + ((u32)index & 0)),
             func_001d4190(value, index));
    iVar2 <<= 1;
    if (iVar2 < 1) {
        iVar2 = 2;
    }
    return iVar2 <= (int)param_1[6];
}
/* measured: closes opt_propagation off probe for func_001d6170. */
#pragma opt_propagation on



// FUN_001D61E0
void func_001d61e0(u32 *param_1)
{
    func_001d6de0(param_1[5], (u16 *)param_1[4]);
    func_001d3e00(*(int *)param_1);
    *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + -1;
    *(u16 *)(param_1[2] + 0xa0) = *(u16 *)(param_1[2] + 0xa0) + -1;
}



// FUN_001D6240
void func_001d6240(u32 param_1, u32 param_2, u32 param_3, u16 param_4, u32 param_5)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0x301, 0x20);
    *(u8 *)(packet + 0x47) = *(u8 *)(packet + 0x47) & 0xef;
    *(code *)(packet + 0x68) = (code)func_001d5f60;
    *(code *)(packet + 0x6c) = (code)func_001d6010;
    *(code *)(packet + 0x74) = (code)func_001d6170;
    *(code *)(packet + 0x70) = (code)func_001d61e0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
    work[7] = param_5;
}



// FUN_001D69F0
void func_001d69f0(u16 value, u64 context)
{
    if ((*(u32*)(DAT_0076449c + 0x14) & 1) != 0)
    {
        sprintf(context, D_00609570);
    }
    else
    {
        sprintf(context, D_00609588, &D_00763388, value);
    }
}



// FUN_001D7BB0
u32 func_001d7bb0(u32* args)
{
    func_001fc2e0(args[0], args[1], args[2]);
    return 1;
}



// FUN_002027E0
void func_002027e0(void)
{
    s32 task;

    task = (s32)func_00194470(0x50d, 0);
    *(u32*)(task + 0x6c) = (u32)func_002027b0;
}
