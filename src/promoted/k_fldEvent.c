/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(s32);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern s32 D_007243EC;
extern s32 D_007243E8;
extern f32 D_007243DC;
extern s32 D_00724358;
extern char D_005F1798[];
extern char D_005F1828[];
extern char D_005F1848[];
extern u32 D_007EFA00[];
typedef struct { f32 x, y, z; } FldEventVec3;
extern FldEventVec3 D_005F1838;

void func_0044ea90(const void *, u32);
s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_00182390(void);
u8 *func_00145270(s32 arg0);
void func_00174be0(s32, s32);
s32 func_00171dc0(void);
s32 func_00175dc0(u8 *);
s32 func_0010a900(s32);
s32 func_0010ce10(s32, s32);
s16 func_00105ee0(s32);
s16 func_00106cd0(s16, s32);
s32 func_001747d0(u8 *);
s32 func_0014a160(void);
s32 func_0015a160(void);
s32 func_0014c850(f32, f32, void *);
u8 *func_001823c0(void);
s32 func_0015c1e0(s32);
void func_0014e740(s32, void *);
s32 func_00182310(s32);
void func_00168de0(s32, void *, f32);
void func_00168890(s32, s32 *);
s32 func_00155280(void);
void func_0018e030(s32, s32);
void func_002bd410(void);
void func_002bd3c0(void);
s32 func_0015a100(void);
s32 func_0015a130(void);
s32 func_0029db50(s32, s32, s32, s32);
s32 func_00452490(s32);
s32 *func_00162390(void);
s32 func_00231630(s32);
s32 func_00172e00(void);
s32 func_002319f0(s32);
f32 func_003e4180(void *);
s32 func_001452b0(s32);
s32 func_0018bbf0(s32);
s32 func_0014bff0(f32, void *, void *);
void func_0015ab20(s32, s32, s32);
void func_0046d730(const void *, u32);
void func_00167560(void);
s32 func_0015f600(void);
s16 func_00479c30(s32, s32);
s32 func_0016fe80(s32);
s32 func_0016ffd0(s32);
s32 func_0016fd00(s32);
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
void func_0016e540(s32, s32);
void func_0016e560(s32, s32);
void func_0017d100(u8 *);
void func_0017d0f0(s32, s32);
s32 func_00174e10(u8 *);
s32 func_0018bea0();
void func_0018bc20(s32);
void func_0018bed0(s32, s32);
void func_0018bdd0(s32);
void func_0047a0e0(s32, s32, f32);
void func_001560a0(s32, s32, s32, s32);

extern u32 D_005F17D0[];
extern u32 D_005F17D4[];
extern u32 D_007EFB64[];

extern f32 D_007615DC;

extern s32 D_007243E0;
extern s32 D_007243E4;
extern s32 D_00724504;
typedef struct { s32 x; } FldEventFlag;
extern FldEventFlag D_007EF9F8[];

extern u16 D_008C024E[];
extern s32 D_007243D0;
extern u8 D_007EF9B0[];

extern char D_005F1770[];
extern char D_005F1780[];
extern u32 D_007EFA04[];
extern u8 *func_0047a310(s32);
extern s32 func_00457c90(u8 *, char *);
extern s32 func_0014c4c0(u8 *, u8 *, f32);
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);

// FUN_00171610
s32 func_00171610(u8 *arg0)
{
    s32 *h;
    u8 *p;
    u8 *q;
    s32 cx;
    s32 cy;
    s32 flag;
    s32 t21;
    s32 t22;
    s32 cx2;
    s32 cy2;
    s32 flag2;
    s32 t20;
    s32 t19;
    s32 t;
    u8 *o;
    u8 *o2;
    FldEventVec3 vec;

    h = *(s32 **)(arg0 + 0x38);
    p = (u8 *)func_001452b0(0xA);
    if (func_0014a200() == 0 && func_0014a270() == 0) {
        return 0;
    }
    t = D_007EF9F8[0].x != 0;
    if (t != 0) {
        t = D_007EFA04[0] != 0;
    }
    if (t == 0) {
        return 0;
    }
    o = (u8 *)func_0047a2f0(D_007EFA00[0]);
    vec = *(FldEventVec3 *)(o + 0x30);
    while (p != 0) {
        if ((*(s32 *)(p + 0x28) & 2) != 0 &&
            func_00457c90((u8 *)func_0047a310(*(s32 *)(p + 0x144)),
                          D_005F1770) != 0) {
            cx = (s32)((600.0f + *(f32 *)((u8 *)func_0047a2f0(*(s32 *)(p + 0x144)) +
                                          0x30)) /
                       1200.0f);
            cy = (s32)((600.0f + *(f32 *)((u8 *)func_0047a2f0(*(s32 *)(p + 0x144)) +
                                          0x38)) /
                       1200.0f);
            flag = 0;
            t21 = cy << 8;
            t22 = cx * 0x10;
            if (*(u8 *)((u8 *)func_00155280() + t21 + t22 + 0x5F) & 0xF) {
                flag = 1;
            }
            if (flag == 1 &&
                !(*(u8 *)((u8 *)func_00155280() + t21 + t22 + 0x5F) & 0xF0)) {
                o2 = (u8 *)func_0047a2f0(D_007EFA00[0]);
                if (func_0014bff0(120.0f, o2,
                                 (u8 *)func_0047a2f0(*(s32 *)(p + 0x144)) + 0x30) !=
                        0 &&
                    func_0014c4c0((u8 *)&vec,
                                  (u8 *)func_0047a2f0(*(s32 *)(p + 0x144)) + 0x30,
                                  250.0f) == 1) {
                    h[5] = 1;
                    if ((D_008C024E[0] & 0x40) != 0) {
                        D_007243EC = (s32)p;
                        D_007243E4 = cx;
                        D_007243E0 = cy;
                        goto found;
                    }
                }
            }
        }
        p = *(u8 **)(p + 0x138);
    }
    D_007243EC = 0;
    D_007243E4 = 0;
    D_007243E0 = 0;
    return 0;
found:
    q = (u8 *)func_001452b0(0xA);
    while (q != 0) {
        if (func_00457c90((u8 *)func_0047a310(*(s32 *)(q + 0x144)),
                          D_005F1780) != 0) {
            cx2 = (s32)((600.0f +
                         *(f32 *)((u8 *)func_0047a2f0(*(s32 *)(q + 0x144)) + 0x30)) /
                         1200.0f);
            cy2 = (s32)((600.0f +
                         *(f32 *)((u8 *)func_0047a2f0(*(s32 *)(q + 0x144)) + 0x38)) /
                         1200.0f);
            flag2 = 0;
            t20 = cy2 << 8;
            t19 = cx2 * 0x10;
            if (*(u8 *)((u8 *)func_00155280() + t20 + t19 + 0x5F) & 0xF) {
                flag2 = 1;
            }
            if (flag2 == 1 &&
                !(*(u8 *)((u8 *)func_00155280() + t20 + t19 + 0x5F) & 0xF0)) {
                o = (u8 *)func_0047a2f0(D_007EFA00[0]);
                if (func_0014bff0(120.0f, o,
                                 (u8 *)func_0047a2f0(*(s32 *)(q + 0x144)) + 0x30) !=
                        0 &&
                    func_0014c4c0((u8 *)&vec,
                                  (u8 *)func_0047a2f0(*(s32 *)(q + 0x144)) + 0x30,
                                  250.0f) == 1) {
                    h[5] = 1;
                    D_007243E8 = (s32)q;
                    h[1] = 0;
                    return 1;
                }
            }
        }
        q = *(u8 **)(q + 0x138);
    }
    func_0046d730(D_005F1798, 0x2F3);
    return 0;
}
// FUN_00171A80
s32 func_00171a80(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    switch (h[1]) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        r = func_00155280();
        func_0018e030(*(s32 *)(r + 0x1C), 1);
        h[4] = func_0029db50(0xF, func_0015a100(), func_0015a130(), 3);
        func_00182310(1);
        h[1]++;
        break;
    case 1:
        if (func_00452490(h[4]) != 1) {
            r = func_00155280();
            func_0018e030(*(s32 *)(r + 0x1C), 0);
            func_00182310(0);
            D_007243EC = 0;
            D_007243E8 = 0;
            D_007243E4 = 0;
            D_007243E0 = 0;
            h[4] = 0;
            h[1]++;
        }
        break;
    case 2:
        return 0;
    }
    return 1;
}
// FUN_00171BD0
s32 func_00171bd0(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    r = func_0014c850(250.0f, 90.0f, D_007EF9B0);
    if (r == 0) {
        goto fail;
    }
    if (*(s32 *)(r + 8) != 0) {
        goto fail;
    }
    D_007243D0 = r;
    h[5] = 1;
    if ((D_008C024E[0] & 0x40) == 0) {
        goto fail;
    }
    h[1] = 0;
    return 1;
fail:
    return 0;
}
// FUN_00171C60
s32 func_00171c60(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    switch (h[1]) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        r = func_00155280();
        func_0018e030(*(s32 *)(r + 0x1C), 1);
        h[4] = func_0029db50(0xF, func_0015a100(), func_0015a130(), 2);
        func_00182310(1);
        h[1]++;
        break;
    case 1:
        r = func_00155280();
        if (*(s32 *)(r + 0x1C) != 0) {
            r = func_00155280();
            func_0018e030(*(s32 *)(r + 0x1C), 1);
        }
        if (func_00452490(h[4]) != 1) {
            r = func_00155280();
            func_0018e030(*(s32 *)(r + 0x1C), 0);
            func_00182310(0);
            h[1]++;
        }
        break;
    case 2:
        return 0;
    }
    return 1;
}
// FUN_00171DC0
s32 func_00171dc0(void)
{
    s32 p;
    s32 found;
    f32 f20;
    f32 vec[3];
    f32 r;
    void *g;
    s32 *t2;

    p = func_001452b0(3);
    found = 0;
    while (p != 0) {
        if ((*(s32 *)(p + 0x28) & 0x10000000) != 0 &&
            (*(s32 *)(p + 0x28) & 2) != 0) {
            if (func_0018bbf0(*(s32 *)(p + 0x294)) == 1) {
                g = (void *)func_0047a2f0(D_007EFA00[0]);
                t2 = (s32 *)func_0047a2f0(*(s32 *)(p + 0x164));
                if (func_0014bff0(120.0f, g, t2 + 0xC) == 1) {
                    f20 = *(f32 *)(func_0047a2f0(*(s32 *)(p + 0x164)) + 0x30);
                    vec[0] = f20 - *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x30);
                    f20 = *(f32 *)(func_0047a2f0(*(s32 *)(p + 0x164)) + 0x34);
                    vec[1] = f20 - *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x34);
                    f20 = *(f32 *)(func_0047a2f0(*(s32 *)(p + 0x164)) + 0x38);
                    vec[2] = f20 - *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x38);
                    r = func_003e4180(vec);
                    if (r < 150.0f && r < D_007615DC) {
                        found = p;
                    }
                }
            }
        }
        p = *(s32 *)(p + 0x138);
    }
    return found;
}
// FUN_00171F60
s32 func_00171f60(s32 arg0)
{
    s32 *h;
    s32 r;
    s32 *p;

    h = *(s32 **)(arg0 + 0x38);
    r = func_00171dc0();
    h[8] = r;
    if (r == 0) {
        goto fail;
    }
    h[5] = 1;
    p = (s32 *)h[8];
    if (p[0x8D] == 0) {
        goto fail;
    }
    if ((D_008C024E[0] & 0x40) == 0) {
        goto fail;
    }
    if (h[9] != 0) {
        goto fail;
    }
    h[1] = 0;
    return 1;
fail:
    return 0;
}
// FUN_00171FE0
s32 func_00171fe0(u8 *arg0)
{
    u8 *h;
    u8 *s;
    u8 *s2;
    u8 *tmp;
    s32 v;
    s32 t;
    s32 t2;
    s32 i;

    h = *(u8 **)(arg0 + 0x38);
    i = 0;
    s = *(u8 **)(h + 0x20);
    if (*(s32 *)(s + 0x234) == 1) {
        if (!(*(s32 *)(*(u8 **)(s + 0x280) + 0x1C) & 1)) {
            i = 1;
        }
    } else if (*(s32 *)(s + 0x234) == 2) {
        if (!(*(s32 *)(*(u8 **)(s + 0x284) + 0x80) & 1)) {
            i = 1;
        }
    } else if (*(s32 *)(s + 0x234) == 3) {
        i = 1;
    }
    switch (*(s32 *)(h + 4)) {
    case 0:
        v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
        if (v != 0 && i == 1) {
            if (func_0018bea0(v, s) == 1) {
                goto ret1;
            }
            func_0018bc20(*(s32 *)(*(u8 **)(h + 0x20) + 0x294));
        }
        func_00182310(1);
        (*(s32 *)(h + 4))++;
    case 1:
        v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
        if (v == 0 || i != 1 || func_0018bea0(v) != 1) {
            func_0018bed0(*(s32 *)(*(u8 **)(h + 0x20) + 0x294), 1);
            s2 = *(u8 **)(h + 0x20);
            if (*(s32 *)(s2 + 0x234) == 1) {
                t = *(s32 *)(*(u8 **)(s2 + 0x280) + 0xC);
                if (t != -1) {
                    tmp = (u8 *)func_00155280();
                    t2 = *(s32 *)(func_00155280() + 0x18E4);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(tmp + 0x18E0), t2, t);
                } else {
                    func_0046d730(D_005F1798, 0x3F6);
                }
            } else if (*(s32 *)(s2 + 0x234) == 2) {
                t = *(s32 *)(*(u8 **)(s2 + 0x284) + 0x74);
                if (t != -1) {
                    t2 = *(s32 *)(s2 + 0x28C);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(s2 + 0x288), t2, t);
                } else {
                    func_0046d730(D_005F1798, 0x407);
                }
            } else if (*(s32 *)(s2 + 0x234) == 3) {
                if (*(s32 *)(s2 + 0x288) != 0) {
                    func_002bd410();
                    func_002bd3c0();
                    func_0018e030(*(s32 *)(func_00155280() + 0x1C), 1);
                    t2 = *(s32 *)(*(u8 **)(h + 0x20) + 0x28C);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(*(u8 **)(h + 0x20) + 0x288), t2, 1);
                } else {
                    func_0046d730(D_005F1798, 0x41D);
                }
            }
            (*(s32 *)(h + 4))++;
        }
        goto ret1;
    case 2:
        if (func_00452490(*(s32 *)(h + 0x10)) != 1) {
            v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
            if (v != 0 && i == 1) {
                func_0018bdd0(v);
            }
            func_0018bed0(*(s32 *)(*(u8 **)(h + 0x20) + 0x294), 0);
            func_0018e030(*(s32 *)(func_00155280() + 0x1C), 0);
            func_00182310(0);
            (*(s32 *)(h + 4))++;
        }
        goto ret1;
    case 3:
        *(s32 *)(h + 0x24) = 0xA;
        *(s32 *)(h + 0x10) = 0;
        return 0;
    }
ret1:
    return 1;
}
/* measured: separate unsigned counters plus opt_loop_invariants reproduce the
   retail compaction-loop register allocation and hoisted -1 sentinel (MATCH). */
// FUN_00172360
s32 func_00172360(u8 *arg0)
{
    u8 *h;
    u32 count;
    u8 *entry;
    u8 *out;
    s32 *scan;
    s32 ids[3];
    FldEventVec3 pos;
    s32 id;
    s32 index;
    u32 scan_i;
    u32 i;
    s32 ambience;

    h = *(u8 **)(arg0 + 0x38);
    *(u16 *)(h + 0x2C) = func_0014be50(
        (u8 *)func_0047a2f0(
            *(s32 *)(*(u8 **)(h + 0x18) + 0x164)) + 0x30,
        &out);
    id = *(u16 *)(h + 0x2C);
    if (id != 0xFFFF) {
        index = id & 0x3FF;
        if (index >= 0x3FE) {
            return 0;
        }
        if ((u32)index >=
            *(u32 *)((u8 *)func_00155280() + 0x18D8)) {
            func_0046d730(D_005F1798, 0x454);
        }

        id = *(u16 *)(h + 0x2C);
        entry = *(u8 **)((u8 *)func_00155280() + 0x18DC) +
                (id & 0x3FF) * 0x2C;
        if ((entry[0xD] == 1 || entry[0xD] == 3) &&
            *(u16 *)(h + 0x2E) == id) {
            return 0;
        }

        /* measured: hoists the compaction-loop -1 sentinel into $v1 like retail. */
#pragma opt_loop_invariants on
        scan = (s32 *)entry;
        scan_i = 0;
        count = 0;
        while (scan_i < 3) {
            if ((ambience = *scan) != -1) {
                ids[count] = ambience;
                count++;
            }
            scan_i++;
            scan++;
        }
        i = 0;
        while (i < count) {
            if (func_00106330(ids[i]) == 0) {
                return 0;
            }
            i++;
        }

        ambience = *(u16 *)(entry + 0xE);
        if (*(s32 *)(h + 0x130) != ambience) {
            *(s32 *)(h + 0x130) = ambience;
            if (ambience != 0) {
                func_0018a010(ambience);
            } else {
                func_0018a010(-1);
            }
        }

        if (entry[0xC] == 1) {
            switch (*(s32 *)(entry + 0x20)) {
            case 0:
                pos = *(FldEventVec3 *)(out + 0x144);
                break;
            case 1:
                pos.x = *(f32 *)(out + 0x15C) + *(f32 *)(out + 0x168);
                pos.y = *(f32 *)(out + 0x160) + *(f32 *)(out + 0x16C);
                pos.z = *(f32 *)(out + 0x164) + *(f32 *)(out + 0x170);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 2:
                pos.x = *(f32 *)(out + 0x15C) + *(f32 *)(out + 0x174);
                pos.y = *(f32 *)(out + 0x160) + *(f32 *)(out + 0x178);
                pos.z = *(f32 *)(out + 0x164) + *(f32 *)(out + 0x17C);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 3:
                pos.x = *(f32 *)(out + 0x174) + *(f32 *)(out + 0x180);
                pos.y = *(f32 *)(out + 0x178) + *(f32 *)(out + 0x184);
                pos.z = *(f32 *)(out + 0x17C) + *(f32 *)(out + 0x188);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 4:
                pos.x = *(f32 *)(out + 0x168) + *(f32 *)(out + 0x180);
                pos.y = *(f32 *)(out + 0x16C) + *(f32 *)(out + 0x184);
                pos.z = *(f32 *)(out + 0x170) + *(f32 *)(out + 0x188);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            }
            if (func_0014bff0(120.0f,
                              (u8 *)func_0047a2f0(D_007EFA00[0]),
                              &pos) == 0) {
                return 0;
            }
        }

        *(s32 *)(h + 0x14) = 1;
        if (entry[0xD] == 0 || entry[0xD] == 1 ||
            (D_008C024E[0] & 0x40) != 0) {
            *(u16 *)(h + 0x2E) = *(u16 *)(h + 0x2C);
            *(s32 *)(h + 4) = 0;
            return 1;
        }
    } else {
        if (*(s32 *)(h + 0x130) != 0) {
            *(s32 *)(h + 0x130) = 0;
            func_0018a010(-1);
        }
        *(u16 *)(h + 0x2E) = 0xFFFF;
    }
    return 0;
}
/* measured: restore loop-invariant optimization after func_00172360. */
#pragma opt_loop_invariants off
/* measured: retail loads the 0x18DC map base before the index multiply, keeps
   the loop head and bottom-test loads of h[0x1C] separate, and shares one
   return-1 block; mwcc b210 inverts the base/index order, CSEs the loop loads,
   and splits the return blocks. Tried base locals, break-to-shared-return, and
   3 declaration orders, best nd 152. Load-sinking/coalescing floor. */
/* measured: archived candidate object_size=944 bytes, retail_window=944 bytes,
   normalized_diff=577; first differing offsets 0,4,8,10,12,14,16,18,20,22,24,26,27,28,30,31.
   Corrected declarations in archived body: func_001452b0(s32) -> u8 *,
   func_00452490(void *), func_0018e030(u8 *, s32),
   func_0029db50(s32, s32, s32, s32), func_00182310(s32),
   func_001560a0(u8 *, s16, s16, s16), func_0047a0e0(u8 *, s32, f32). */
// FUN_001727F0
INCLUDE_ASM("asm/nonmatchings/k_fldEvent", func_001727f0);
// FUN_00172BA0
s32 func_00172ba0(void)
{
    s32 vals[4];
    s32 i;

    if (func_0010ce10(func_0010a900(1), 0x205) != -1) {
        return 1;
    }
    vals[0] = 1;
    for (i = 0; i < 3; i++) {
        vals[i + 1] = func_00105ee0(i);
    }
    for (i = 0; i < 4; i++) {
        if (vals[i] != 0 && func_00106cd0(vals[i], 2) == 0x270) {
            return 1;
        }
    }
    return 0;
}

// FUN_00172CB0
s32 func_00172cb0(u8 *arg0)
{
    s32 *h;
    FldEventVec3 vec;
    u8 *t;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    if (func_0014a160() == 1) {
        r = *(s32 *)func_001823c0();
        if (r != 0) {
            t = (u8 *)func_0047a2f0(D_007EFA00[0]);
            vec = *(FldEventVec3 *)(t + 0x30);
            vec.y += 100.0f;
            func_0014e740(func_0015c1e0(0), &vec);
            func_00182310(1);
            h[1] = 2;
            return 1;
        }
    }
    return 0;
}

// FUN_00172D80
s32 func_00172d80(u8 *arg0)
{
    s32 *h;

    h = *(s32 **)(arg0 + 0x38);
    if (func_0014a160() == 1) {
        if (func_0015a160() != 0x9F) {
            if ((D_008C024E[0] & 0x40) != 0) {
                h[0xD] = 0;
                h[0xE] = 0;
                h[1] = 0;
                return 1;
            }
        }
    }
    return 0;
}

// FUN_00172E00
INCLUDE_ASM("asm/nonmatchings/k_fldEvent", func_00172e00);
// FUN_00174680
s32 func_00174680(s32 arg0, s32 arg1, s32 arg2)
{
    s32 *h;
    s32 *s16;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    r = 1;
    if (h[0x43] == 0) {
        h[0x45] = h[1];
        h[0x44] = h[4];
        h[1] = 3;
        s16 = func_00162390();
        s16[0x12] = func_00231630(arg1);
        s16[0x13] = D_00724504 + ((arg1 & 0xFFFF) * 24);
        *(u16 *)((u8 *)s16 + 0x728) = 0;
        h[0x11] = (s32)s16;
        *(u16 *)((u8 *)h + 0x118) = arg2;
        h[0x43] = r;
        goto done;
    }
    s16 = (s32 *)func_00172e00();
    if (s16 != 0) {
        goto done;
    }
    if (D_007EF9F8[0].x == 0) {
        r = 0;
    } else {
        if (func_002319f0(D_007EF9F8[0].x) == r) {
            r = (s32)s16 | 0x80000000;
        } else {
            r = 0;
            if (*(u16 *)((u8 *)h + 0x11A) != 0) {
                r |= 0x40000000;
            }
        }
    }
    h[1] = h[0x45];
    h[4] = h[0x44];
    h[0x43] = 0;
done:
    return r;
}
// FUN_001747D0
s32 func_001747d0(u8 *arg0)
{
    u8 *h;
    s32 t;
    s32 i;
    s32 v;

    h = *(u8 **)(arg0 + 0x38);
    *(s32 *)(h + 0x14) = 0;
    t = *(s32 *)(h + 0x24);
    if (t > 0) {
        *(s32 *)(h + 0x24) = t - 1;
    }
    func_00167560();
    if (*(s32 *)(h + 0x154) == 0) {
        *(s32 *)(h + 0x154) = func_0015f600();
    }
    switch (*(s32 *)h) {
    case 0:
        for (i = 0; i < ((*(s32 *)(h + 8) != 0) ? 1 : 0xB); i++) {
            if (((s32 (*)(u8 *))D_005F17D0[i * 2])(arg0) == 1) {
                *(s32 *)(h + 0xC) = i;
                break;
            }
        }
        if (*(s32 *)(h + 0xC) > -1) {
            v = (s16)func_00479c30(D_007EFA00[0], 0);
            if (v == func_0016fe80(1) || v == func_0016ffd0(1)) {
                func_00479940((u8*)D_007EFA00[0], 0, (s16)func_0016fd00(1), 4, 1);
            }
            if (*(s32 *)(func_00155280() + 4) != 0) {
                func_0016e540(*(s32 *)(func_00155280() + 4), 2);
            }
            *(s32 *)(h + 0x134) = 0;
            *(s32 *)(h + 0x14) = 0;
            *(s32 *)h = 1;
        } else {
            func_00174e10(arg0);
            break;
        }
    case 1:
        if (((s32 (*)(u8 *))D_005F17D4[*(s32 *)(h + 0xC) * 2])(arg0) != 1) {
            if (*(s32 *)(func_00155280() + 4) != 0) {
                func_0016e560(*(s32 *)(func_00155280() + 4), 2);
            }
            *(s32 *)(h + 0xC) = -1;
            *(s32 *)h = 0;
        }
        break;
    case 2:
        break;
    }
    if (*(s32 *)(h + 0x14) == 1) {
        func_0047a2f0(D_007EFA00[0]);
        if (D_007EFB64[0] != 0) {
            func_0017d100((u8 *)D_007EFB64[0]);
            func_0017d0f0(D_007EFB64[0], 1);
        }
    } else if (D_007EFB64[0] != 0) {
        func_0017d0f0(D_007EFB64[0], 0);
    }
    return 0;
}

// FUN_00174AA0
void func_00174aa0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}

// FUN_00174AD0
s32 func_00174ad0(s32 arg0)
{
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_2_2;

    func_0044ea90(D_005F1798, 0x990);
    temp_2 = D_008873F4[0](1, 0x160, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    arg0 = func_00451fc0(arg0, D_005F1828, 0xF, 0, 0,
                         (void (*)(u8 *))func_001747d0,
                         func_00174aa0, temp_2);
    func_00182390();
    *(s32 *)(temp_2 + 0xC) = -1;
    temp_18 = temp_2 + 0x18;
    *(u8 **)temp_18 = func_00145270(0x400);
    func_00174be0(arg0, D_00724358);
    *(u16 *)(temp_2 + 0x2E) = 0xFFFF;
    temp_2_2 = *(u8 **)temp_18;
    *(s32 *)(temp_2 + 0x13C) = func_00175ea0(arg0, *(s32 *)(temp_2_2 + 0x220),
                                              *(s32 *)(temp_2_2 + 0x164));
    return arg0;
}
// FUN_00174BE0
void func_00174be0(s32 arg0, s32 arg1)
{
    if (arg0 != 0) {
        *(s32 *)(*(s32 *)(arg0 + 0x38) + 8) = arg1;
    }
}
// FUN_00174C00
s32 func_00174c00(void)
{
    return D_007243EC;
}
// FUN_00174C10
s32 func_00174c10(void)
{
    return D_007243E8;
}
// FUN_00174C20
void func_00174c20(void)
{
    s32 temp_18;
    s32 temp_18_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_3;
    u8 *temp_3_2;

    var_17 = D_007243E4;
    var_16 = D_007243E0;
    temp_18 =
        (u8)((*(u8 *)((u8 *)func_00155280() + (var_16 << 8) + (var_17 * 0x10) +
                      0x5F) <<
              4) &
             0xF0);
    temp_3 = (u8 *)func_00155280() + (var_16 << 8) + (var_17 * 0x10);
    temp_3[0x5F] = temp_3[0x5F] | temp_18;
    func_0015ab20(func_0015a160(), var_17, var_16);
    if (*(u8 *)((u8 *)func_00155280() + (var_16 << 8) + (var_17 * 0x10) +
                0x5F) &
        1) {
        var_16 -= 1;
    } else if (*(u8 *)((u8 *)func_00155280() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               2) {
        var_17 -= 1;
    } else if (*(u8 *)((u8 *)func_00155280() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               4) {
        var_16 += 1;
    } else if (*(u8 *)((u8 *)func_00155280() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               8) {
        var_17 += 1;
    }
    if (*(u8 *)((u8 *)func_00155280() + (var_16 << 8) + (var_17 * 0x10) +
                0x5F) &
        0xF) {
        ;
    } else {
        func_0046d730(D_005F1798, 0x9DD);
    }
    temp_18_2 =
        (u8)((*(u8 *)((u8 *)func_00155280() + (var_16 * 0x100) +
                      (var_17 << 4) + 0x5F) <<
              4) &
             0xF0);
    temp_3_2 = (u8 *)func_00155280() + (var_16 * 0x100) + (var_17 << 4);
    temp_3_2[0x5F] = temp_3_2[0x5F] | temp_18_2;
    func_0015ab20(func_0015a160(), var_17, var_16);
}
// FUN_00174E10
INCLUDE_ASM("asm/nonmatchings/k_fldEvent", func_00174e10);
// FUN_00175DB0
f32 func_00175db0(void)
{
    return D_007243DC;
}
// FUN_00175DC0
s32 func_00175dc0(u8 *arg0)
{
    s32 *h;
    FldEventVec3 vec;

    h = *(s32 **)(arg0 + 0x38);
    vec = D_005F1838;
    switch (h[0x10]) {
    case 0:
        break;
    case 1:
        h[0x16]++;
        func_00168de0(h[0x11], &vec, *(f32 *)(h + 0x15));
        if (h[0x16] < h[0x17]) {
            goto end;
        }
        func_00168890(h[0x11], h);
        h[0x10] = 0;
        break;
    }
end:
    return 0;
}




// FUN_00175E70
void func_00175e70(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}

// FUN_00175EA0
s32 func_00175ea0(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;
    s32 ret;

    func_0044ea90(D_005F1798, 0xB7F);
    temp_2 = D_008873F4[0](1, 0x60, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005F1848, 0xF, 0, 0,
                        (void (*)(u8 *))func_00175dc0, func_00175e70, temp_2);
    *(s32 *)(temp_2 + 0x44) = arg1;
    *(s32 *)(temp_2 + 0x48) = arg2;
    return ret;
}
