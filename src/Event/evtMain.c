#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtMain.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u32 DAT_007645D8;
void func_00285260(void);
void func_002871a0();
u8 *func_00145270(s32 arg0);
extern void func_0046d730(const void *file, u32 line);
extern void *func_00457120(void);
void func_003e8180(void *, float);
void func_003e81c0(void *, float);
extern u8 D_0063C3B0[];
void func_0043f9c8(void *dst, s32 c, s32 n);
void func_00286350(void);
extern s32 D_008821E0[];
void func_0028ad90(void);
void func_0028b440(int, int);
void func_0028b5d0(int);
void func_0026bf20(void);
void func_00452080(s32 handle);
void func_0014a2f0(s32 arg0);
s32 func_002852a0(s32 arg0, s32 arg1);
s32 func_00285330(void);
extern void func_00440b68(char *fmt, ...);
extern char D_0063C628[];
extern void *DAT_008873EC[];
s32 func_00286430(u8 *arg0);
void func_00161460(u8, u8, u8);
void func_00161500(u8);
extern void func_0044ea90(void *msg, s32 id);
extern char D_00748340[];
extern void *D_008873F4[];
void func_00286d80(u32 *, u32 *);
s32 func_002853f0(s32 arg0);
extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 DAT_00764B38;
extern u8 DAT_00764B3C;
extern u8 DAT_00764B40;
extern u8 DAT_00764B44;
extern f32 D_00764B5C;
void func_0028bfb0(u32 node, s32 param_1, s32 *a, s32 *b);
u32 func_002909a0(u32 *object);
s32 func_00290de0(u32 *object);
s32 func_00122720(void);
extern u32 DAT_00713890;
extern void func_00113480(s16 a, s16 b, s16 c, s16 d);
void func_00113500(void);
extern void func_00269c20(u16, int);

// FUN_00286780
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00286780);

// FUN_00286C60
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00286c60);

// FUN_00286D80
void func_00286d80(u32 *param_1, u32 *param_2) {
    u32 *node = (u32 *)param_2[0x13];
    if (node == 0) {
        param_2[0x13] = (u32)param_1;
        param_2[0x14] = (u32)param_1;
        param_1[0x24] = 0;
        param_1[0x25] = 0;
    } else {
        while (node != 0) {
            if (func_002853f0(param_1[0]) < func_002853f0(node[0])) {
                if (node[0x25] == 0) {
                    param_2[0x13] = (u32)param_1;
                    node[0x25] = (u32)param_1;
                    param_1[0x25] = 0;
                    param_1[0x24] = (u32)node;
                } else {
                    *(u32 *)(node[0x25] + 0x90) = (u32)param_1;
                    param_1[0x25] = node[0x25];
                    param_1[0x24] = (u32)node;
                    node[0x25] = (u32)param_1;
                }
                goto tail;
            }
            node = (u32 *)node[0x24];
        }
    tail:
        if (node == 0) {
            *(u32 *)(param_2[0x14] + 0x90) = (u32)param_1;
            param_1[0x25] = param_2[0x14];
            param_1[0x24] = 0;
            param_2[0x14] = (u32)param_1;
        }
    }
    param_2[0x12] += 1;
}

// FUN_00286E90
void func_00286e90(int param_1, int param_2) {
    if (*(u32 *)(param_1 + 0x94) == 0) {
        *(u32 *)(param_2 + 0x4C) = *(u32 *)(param_1 + 0x90);
    } else {
        *(u32 *)(*(u32 *)(param_1 + 0x94) + 0x90) = *(u32 *)(param_1 + 0x90);
    }
    if (*(u32 *)(param_1 + 0x90) == 0) {
        *(u32 *)(param_2 + 0x50) = *(u32 *)(param_1 + 0x94);
    } else {
        *(u32 *)(*(u32 *)(param_1 + 0x90) + 0x94) = *(u32 *)(param_1 + 0x94);
    }
    *(u32 *)(param_1 + 0x94) = 0;
    *(u32 *)(param_1 + 0x90) = 0;
    *(u32 *)(param_2 + 0x48) -= 1;
}

// FUN_00286F00
void *func_00286f00(int param_1, int param_2) {
    void *r;
    func_0044ea90(D_00748340, 0x52);
    r = ((void *(*)(int, int, int))D_008873F4[0])(1, 0x98, 0x40000);
    func_002852a0(7, 0x98);
    if (r == 0) {
        return NULL;
    }
    func_0043f9c8(r, 0, 0x98);
    *(u32 *)((u8 *)r + 0) = param_1;
    *(u32 *)((u8 *)r + 8) = -1;
    *(u16 *)((u8 *)r + 0xC) = 0;
    *(u32 *)((u8 *)r + 0x60) = 0;
    switch (param_1) {
    case 0x30:
        *(s8 *)((u8 *)r + 0x1E) = -1;
        break;
    }
    func_00286d80((u32 *)r, (u32 *)param_2);
    return r;
}

// FUN_00286FF0
void func_00286ff0(int param_1, int param_2, int param_3) {
    u8 *r;
    if (param_1 != 0) {
        *(u16 *)(param_1 + 0xC) = param_2;
        r = func_00145270(*(u16 *)(param_1 + 0xC));
        if (r != 0) {
            *(u32 *)(param_1 + 0x54) = *(u32 *)(r + 0x28);
        } else {
            *(u32 *)(param_1 + 0x54) = 0;
        }
        *(u32 *)(param_1 + 0x34) = param_3;
    }
}

// FUN_00287060
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287060);

// FUN_002871A0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002871a0);

// FUN_00287310
void func_00287310(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x5D4) == 1) {
        func_002871a0(0, *(u8 **)(arg0 + 0x14), arg0);
        return;
    }
    func_002871a0(1, *(u8 **)(arg0 + 0x14), arg0);
}

// FUN_00287360
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287360);

// FUN_00287AD0
/* measured: without opt_loop_invariants, MWCC rematerializes the 0x22 loop
 * constant inside the loop body; retail hoists it to the preheader. */
#pragma opt_loop_invariants on
void func_00287ad0(int param_1, int param_2) {
    s32 a = 0;
    s32 b = 0;
    u32 node = *(u32 *)(param_2 + 0x4C);
    while (node != 0) {
        if (*(u32 *)node == 0x22) {
            break;
        }
        node = *(u32 *)(node + 0x90);
    }
    if (node != 0) {
        func_0028bfb0(node, param_1, &a, &b);
        if (a != 0 && *(u16 *)a == param_1) {
            switch (*(s8 *)(a + 0x10)) {
            case 0:
                if (func_002909a0((u32 *)(param_2 + 0x678)) != 0 && func_00290de0((u32 *)(param_2 + 0x678)) == 0) {
                    *(u32 *)param_2 |= 0x20;
                    func_00440b68((char *)&DAT_00713890);
                }
                break;
            case 1:
                if (func_00122720() != 0) {
                    *(u32 *)param_2 |= 0x2000;
                }
                break;
            }
        }
    }
}
/* measured: see annotation above (func_00287ad0). */
#pragma opt_loop_invariants off

// FUN_00287CC0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287cc0);
// FUN_00287D90
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287d90);

// FUN_00288020
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288020);

// FUN_00288170
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288170);

// FUN_00288AF0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288af0);

// FUN_00288F20
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288f20);

// FUN_002890B0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002890b0);

// FUN_002891D0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002891d0);

// FUN_002894B0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002894b0);

// FUN_00289780
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00289780);

// FUN_002898B0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002898b0);

// FUN_00289B10
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00289b10);

// FUN_00289C90
s32 func_00289c90(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_00161460(((u8 *)param_5)[0x10], ((u8 *)param_5)[0x11], ((u8 *)param_5)[0x13]);
        func_00161500(((u8 *)param_5)[0x12]);
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289D70
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00289d70);

// FUN_00289EC0
s32 func_00289ec0(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_003e8180(func_00457120(), *(float *)((u8 *)param_5 + 0x10));
        func_003e81c0(func_00457120(), *(float *)((u8 *)param_5 + 0x14));
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289FB0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00289fb0);

// FUN_0028A100
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028a100);

// FUN_0028A2A0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028a2a0);

// FUN_0028A3B0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028a3b0);

// FUN_0028A560
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028a560);

// FUN_0028A6A0
s32 func_0028a6a0(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    s16 v18;
    s8 t;
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        t = *(s8 *)((u8 *)param_5 + 0x10);
        if (t == 0) {
            v18 = *(s16 *)((u8 *)param_5 + 0x18);
            if (v18 == 0) {
                func_00113480(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), *(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x1A));
            } else {
                func_00113480(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), v18, *(s16 *)((u8 *)param_5 + 0x1A));
            }
        } else if (t == 1) {
            func_00113500();
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_0028A7C0
s32 func_0028a7c0(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A850
s32 func_0028a850(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A8E0
s32 func_0028a8e0(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A970
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028a970);

// FUN_0028AAF0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028aaf0);

// FUN_0028AD90
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028ad90);

// FUN_0028AFE0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028afe0);

// FUN_0028B160
void func_0028b160(int param_1) {
    u32 f77c;
    func_0028ad90();
    func_0028b440(param_1, 0);
    func_0028b5d0(param_1);
    func_0026bf20();
    if ((*(u32 *)param_1 & 0x40000000) == 0) {
        f77c = *(u32 *)(param_1 + 0x77C);
        if (f77c != 0) {
            func_00452080(f77c);
            *(u32 *)(param_1 + 0x77C) = 0;
        }
    }
    func_0014a2f0(0);
    ((void (*)(int))DAT_008873EC[0])(param_1);
    func_002852a0(0, -0x7B0);
    func_00285330();
    func_00440b68(D_0063C628);
}

// FUN_0028B230
void func_0028b230(int param_1) {
    *(u32 *)(param_1 + 0x774) = 0;
    func_00285260();
}

// FUN_0028B260
u32 func_0028b260(void) { return DAT_007645D8 != 0; }

// FUN_0028B2A0
void *func_0028b2a0(int param_1, int param_2) {
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        func_0046d730(D_0063C3B0, 0x10B7);
    }
    return (void *)(param_1 + param_2 * 20 + 0x68);
}

// FUN_0028B320
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028b320);

// FUN_0028B440
void func_0028b440(int param_1, int param_2) {
    int p;
    f32 v;
    void *cam;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        func_0046d730(D_0063C3B0, 0x10B7);
    }
    p = param_1 + param_2 * 20 + 0x68;
    if (*(u32 *)p & 1) {
        DAT_00764B38 = 1;
    } else {
        DAT_00764B38 = 0;
    }
    DAT_00764B3C = (u8)(*(u32 *)(p + 4) >> 16);
    DAT_00764B40 = (u8)(*(u32 *)(p + 4) >> 8);
    DAT_00764B44 = (u8)*(u32 *)(p + 4);
    func_00457140((*(u32 *)(p + 8) >> 16) & 0xFF, (*(u32 *)(p + 8) >> 8) & 0xFF, *(u32 *)(p + 8) & 0xFF, 0);
    v = *(f32 *)(p + 0xC);
    cam = func_00457120();
    *(f32 *)((u8 *)cam + 0x88) = v;
    cam = func_00457120();
    D_00764B5C = *(f32 *)(p + 0x10);
}

// FUN_0028B550
void func_0028b550(int param_1) {
    f32 *p;
    void *cam;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    func_0043f9c8(p, 0, 8);
    cam = func_00457120();
    p[0] = *(f32 *)((u8 *)cam + 0x80);
    cam = func_00457120();
    p[1] = *(f32 *)((u8 *)cam + 0x84);
}

// FUN_0028B5D0
void func_0028b5d0(int param_1) {
    f32 *p;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    func_003e8180(func_00457120(), p[0]);
    func_003e81c0(func_00457120(), p[1]);
}
