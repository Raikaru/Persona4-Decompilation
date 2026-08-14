/* Original translation unit evtModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

extern s32 func_00452380();
extern void func_00452080();
extern u8 D_0063C958[];

/* Model event update state machine shared by the func_0029xxxx family:
   arg0 is an unused leading parameter; arg1 is the event record. */
typedef struct {
    f32 v[4];
} F32x4;

typedef struct {
    u16 id;      /* 0x00 */
    u16 id2;     /* 0x02 */
    u8 pad4[4];  /* 0x04 */
    f32 speed;   /* 0x08 */
    u8 padC[4];  /* 0x0C */
    f32 posX;    /* 0x10 */
    u8 pad14[4]; /* 0x14 */
    s32 target;  /* 0x18 */
    s32 timer;   /* 0x1C */
    s16 angX;    /* 0x20 */
    u8 pad22[2];
    s16 angY;    /* 0x24 */
    u8 pad26[2];
    s16 angZ;    /* 0x28 */
    u8 pad2A[6]; /* 0x2A */
    f32 timer2;  /* 0x30 */
    f32 dst[4];  /* 0x34 */
    s32 flags;   /* 0x44 */
    s16 counterA; /* 0x48 */
    s16 counterB; /* 0x4A */
} EvtModelRec;

extern u8 D_0063C948[];
extern s32 D_0063C930[];

/* GP-relative float globals (P4 gp = 0x7690F0). */
extern f32 fGpffff8218; /* gp -0x7de8 */
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern f32 fGpffff8478; /* gp -0x7b88 */
extern f32 fGpffff8504; /* gp -0x7afc */
extern f32 fGpffff8510; /* gp -0x7af0 */
extern f32 fGpffff8514; /* gp -0x7aec */
extern f32 D_00761260;  /* gp -0x7e90 */

extern s32 func_00291a60(u32 id);
extern void *func_00145270(u32 id);
extern void func_00269340(s32 id, void *param, s32 a, s32 b);
extern void func_00269820(void *res, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern void func_0026bda0(s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern u8 *func_002e1db0(s32 a, s32 b, s32 c, s32 d);
extern void func_002e1ef0(void *a);
extern u8 *func_002e2170(void *a, s32 b, s32 c);
extern void func_002e2240(void *a, void *b, void *c);
extern void func_003e40b0(void *a, void *b);
extern void func_0043f810(void *dst, void *src, s32 size);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern s32 func_0044b310(s32 a);
extern f32 func_0044b920(f32 a);
extern s32 func_0044dcd8(f32 a);
extern f32 func_0044e7d8(s32 a);
extern s32 func_00451de0(void *a, s32 b, s32 c, s32 d, s32 (*e)(void), void (*f)(void), void *g);
extern u8 **func_00452560();
extern void func_0046d730(void *file, s32 line);
extern void *func_0047a2f0(s32 a);
extern void func_0047a890(s32 a, f32 b);
extern void func_0047a900(s32 a, void *b);
extern void func_0047a950(s32 a, f32 b, f32 c);
extern u8 *func_0047a980(s32 a);
extern void func_0047a990(s32 a);
extern s32 func_0047a9d0(s32 a);
extern f32 func_004bd4a0(void *a, f32 *b);

// FUN_00291B60 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/evtModel", func_00291b60);

// FUN_00291FA0
INCLUDE_ASM("asm/nonmatchings/evtModel", func_00291fa0);

// FUN_00292BB0
s32 func_00292bb0(s32 arg0, u8 *arg1) {
    EvtModelRec *rec = (EvtModelRec *)arg1;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } F32x3;
    u8 sp[0x30];
    f32 temp_f20;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f12_2;
    s32 handle1;
    s32 handle2;
    s32 var_2;
    u32 var_3;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;

    temp_f20 = rec->speed;
    handle1 = func_00291a60(rec->id);
    handle2 = func_00291a60(rec->id2);
    if (handle1 == 0) {
        return 1;
    }
    if (handle2 == 0) {
        return 1;
    }
    var_3 = (u32)rec->timer2;
    if (var_3 == 0) {
        temp_2 = (u8 *)func_0047a2f0(handle1);
        *(F32x3 *)(sp + 0x20) = *(F32x3 *)(temp_2 + 0x30);
        temp_2_2 = (u8 *)func_0047a2f0(handle2);
        *(F32x3 *)(sp + 0x10) = *(F32x3 *)(temp_2_2 + 0x30);
        temp_f2 = *(f32 *)(sp + 0x10) - *(f32 *)(sp + 0x20);
        *(f32 *)(sp + 0x20) = temp_f2;
        *(f32 *)(sp + 0x28) = *(f32 *)(sp + 0x18) - *(f32 *)(sp + 0x28);
        *(u32 *)(sp + 0x24) = 0;
        if (temp_f2 == *(f32 *)(sp + 0x28)) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
        if ((f32)var_2 == 0.0f) {
            *(f32 *)(sp + 0x28) = 1.0f;
        }
        func_003e40b0(sp + 0x20, sp + 0x20);
        func_0047a900(handle1, sp + 0x20);
        var_f12 = fGpffff8218 * temp_f20;
        if (!(var_f12 <= 1.0f)) {
            var_f12 = 1.0f;
        } else if (var_f12 < 0.0f) {
            var_f12 = 0.0f;
        }
        func_0047a890(handle1, var_f12);
        rec->timer2 += 1.0f;
    } else {
        if (func_0047a9d0(handle1) == 0) {
            return 1;
        }
        temp_2_3 = (u8 *)func_0047a2f0(handle1);
        *(F32x3 *)(sp + 0x20) = *(F32x3 *)(temp_2_3 + 0x30);
        temp_2_4 = (u8 *)func_0047a2f0(handle2);
        *(F32x3 *)(sp + 0x00) = *(F32x3 *)(temp_2_4 + 0x30);
        *(f32 *)(sp + 0x20) = *(f32 *)(sp + 0x00) - *(f32 *)(sp + 0x20);
        *(f32 *)(sp + 0x28) = *(f32 *)(sp + 0x08) - *(f32 *)(sp + 0x28);
        *(u32 *)(sp + 0x24) = 0;
        func_003e40b0(sp + 0x20, sp + 0x20);
        func_0047a900(handle1, sp + 0x20);
        var_f12_2 = fGpffff8218 * temp_f20;
        if (!(var_f12_2 <= 1.0f)) {
            var_f12_2 = 1.0f;
        } else if (var_f12_2 < 0.0f) {
            var_f12_2 = 0.0f;
        }
        func_0047a890(handle1, var_f12_2);
    }
    temp_2_5 = (u8 *)func_0047a980(handle1);
    *(F32x4 *)(arg1 + 0x34) = *(F32x4 *)temp_2_5;
    return 0;
}

// FUN_00292EF0
#pragma push
#pragma opt_rebuildconditionals off
s32 func_00292ef0(s32 arg0, u8 *arg1) {
    EvtModelRec *rec = (EvtModelRec *)arg1;
    u8 sp[0xC];
    u32 id;
    s32 handle;
    s32 var_3;

    id = rec->id;
    handle = func_00291a60(id);
    if (handle == 0) {
        return 1;
    }
    if (2.1474836e9f <= rec->timer2) {
        goto big;
    }
    var_3 = (s32)rec->timer2;
    goto done;
big:
    var_3 = (s32)(rec->timer2 - 2.1474836e9f) | 0x80000000;
done:
    if (var_3 == 0) {
        func_00269820(func_00145270(id), 0, 1, 5, 0, 0, 1.0f);
    } else if (var_3 == 5) {
        *(s32 *)(sp + 0) = 0;
        *(f32 *)(sp + 4) = rec->posX;
        *(s32 *)(sp + 8) = 0;
        func_00269340(id, sp, rec->target, 0);
        if (rec->flags & 2) {
            func_0026bda0(id, 2, (rec->timer + 1) & 0xFF, rec->angX, rec->angY, rec->angZ);
        }
    } else if (var_3 == 25) {
        func_00269820(func_00145270(id), 0, 0, 5, 1, 0, 1.0f);
        return 1;
    }
    rec->timer2 += 1.0f;
    *(F32x4 *)(arg1 + 0x34) = *(F32x4 *)func_0047a980(handle);
    return 0;
}
#pragma pop

// FUN_002930E0
s32 func_002930e0(void) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    u8 *entry;
    s32 (*cb)(u8 **, u8 *);

    list = (u8 **)func_00452560();
    head = (u8 *)*list;
    node = (u8 *)((u8 **)head)[1];
    while (node != NULL) {
        next = (u8 *)((u8 **)node)[4];
        entry = (u8 *)((u8 **)node)[5];
        cb = (s32 (*)(u8 **, u8 *))*(s32 **)(entry + 0x2C);
        if ((cb != NULL) && (cb(list, entry) != 0)) {
            func_002e2240(head, head + 4, node);
        }
        node = next;
    }
    if (*(u16 *)(head + 0x10) != 0) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}

// FUN_002931A0
void func_002931a0(void) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    s32 handle;

    list = (u8 **)func_00452560();
    head = (u8 *)*list;
    if (head != NULL) {
        node = (u8 *)((u8 **)head)[1];
        while (node != NULL) {
            next = (u8 *)((u8 **)node)[4];
            handle = func_00291a60(*(u16 *)((u8 **)node)[5]);
            if (handle != 0) {
                func_0047a890(handle, fGpffff8218);
                func_0047a990(handle);
            }
            func_002e2240(head, head + 4, node);
            node = next;
        }
    }
    func_002e1ef0(*list);
}

// FUN_00293270
void func_00293270(void) {
    s32 handle = func_00452380(D_0063C958);

    if (handle != 0) {
        func_00452080(handle);
    }
}

// FUN_002932B0
void func_002932b0(s32 arg0) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    s32 handle;
    u32 outer;
    u32 masked;

    outer = func_00452380(D_0063C958);
    if (outer != 0) {
        list = (u8 **)func_00452560(outer);
        head = (u8 *)*list;
        if (head != NULL) {
            node = (u8 *)((u8 **)head)[1];
            masked = (u16)arg0;
            while (node != NULL) {
                next = (u8 *)((u8 **)node)[4];
                if (*(u16 *)((u8 **)node)[5] == masked) {
                    handle = func_00291a60(*(u16 *)((u8 **)node)[5]);
                    if (handle != 0) {
                        func_0047a890(handle, fGpffff8218);
                        func_0047a990(handle);
                    }
                    func_002e2240(head, head + 4, node);
                }
                node = next;
            }
        }
    }
}

// FUN_002933A0
void func_002933a0(s16 arg0, s32 arg1, f32 fparg0) {
    u8 sp[0x2C];
    u32 var_2;
    u8 **temp_10;
    u8 **temp_17;
    u8 *temp_2;
    u8 *temp_19;
    u8 *temp_18;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_16;
    u8 *var_6;
    u32 masked;

    var_2 = func_00452380(D_0063C958);
    if (var_2 == 0) {
        temp_2 = (u8 *)func_002e1db0(4, 0, 0, 0);
        temp_10 = *(u8 ***)(temp_2 + 0x24);
        *temp_10 = temp_2;
        var_2 = func_00451de0(D_0063C958, 0xF, 0, 0, func_002930e0, func_002931a0, temp_10);
    }
    temp_17 = (u8 **)func_00452560(var_2);
    func_0043f9c8(sp, 0, 0x2C);
    *(s16 *)(sp + 0) = arg0;
    *(s32 *)(sp + 4) = arg1;
    *(f32 *)(sp + 8) = fparg0;
    if (temp_17 == NULL) {
        func_0046d730(D_0063C948, 0x32C);
    }
    temp_19 = (u8 *)*temp_17;
    if (temp_19 != NULL) {
        var_6 = (u8 *)((u8 **)temp_19)[1];
        masked = (u16)arg0;
        while (var_6 != NULL) {
            temp_18 = (u8 *)((u8 **)var_6)[4];
            temp_3 = (u8 *)((u8 **)var_6)[5];
            if ((*(u16 *)temp_3 == masked) && (*(s32 *)(temp_3 + 4) == 3)) {
                func_002e2240(temp_19, temp_19 + 4, var_6);
            }
            var_6 = temp_18;
        }
    }
    temp_4 = (u8 *)*temp_17;
    temp_16 = (u8 *)((u8 **)func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0x4C))[5];
    func_0043f810(temp_16, sp, 0x2C);
    *(s32 *)(temp_16 + 0x2C) = D_0063C930[*(s32 *)(sp + 4)];
}

// FUN_00293550
void func_00293550(s16 arg0, s16 arg1, s32 arg2, f32 fparg0) {
    u8 sp[0x2C];
    u32 var_2;
    u8 **temp_10;
    u8 **temp_17;
    u8 *temp_2;
    u8 *temp_19;
    u8 *temp_18;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_16;
    u8 *var_6;
    u32 masked;

    var_2 = func_00452380(D_0063C958);
    if (var_2 == 0) {
        temp_2 = (u8 *)func_002e1db0(4, 0, 0, 0);
        temp_10 = *(u8 ***)(temp_2 + 0x24);
        *temp_10 = temp_2;
        var_2 = func_00451de0(D_0063C958, 0xF, 0, 0, func_002930e0, func_002931a0, temp_10);
    }
    temp_17 = (u8 **)func_00452560(var_2);
    func_0043f9c8(sp, 0, 0x2C);
    *(s16 *)(sp + 0) = arg0;
    *(s16 *)(sp + 2) = arg1;
    *(s32 *)(sp + 4) = arg2;
    *(f32 *)(sp + 8) = fparg0;
    if (temp_17 == NULL) {
        func_0046d730(D_0063C948, 0x32C);
    }
    temp_19 = (u8 *)*temp_17;
    if (temp_19 != NULL) {
        var_6 = (u8 *)((u8 **)temp_19)[1];
        masked = (u16)arg0;
        while (var_6 != NULL) {
            temp_18 = (u8 *)((u8 **)var_6)[4];
            temp_3 = (u8 *)((u8 **)var_6)[5];
            if ((*(u16 *)temp_3 == masked) && (*(s32 *)(temp_3 + 4) == 3)) {
                func_002e2240(temp_19, temp_19 + 4, var_6);
            }
            var_6 = temp_18;
        }
    }
    temp_4 = (u8 *)*temp_17;
    temp_16 = (u8 *)((u8 **)func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0x4C))[5];
    func_0043f810(temp_16, sp, 0x2C);
    *(s32 *)(temp_16 + 0x2C) = D_0063C930[*(s32 *)(sp + 4)];
}
