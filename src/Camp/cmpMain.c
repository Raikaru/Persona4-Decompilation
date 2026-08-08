/* Original translation unit cmpMain.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_0044ea90(void *file, s32 line);
void func_0046d730(void *arg0, s32 arg1);
void func_0045af60(s32 a, s32 b, s32 c, s32 d);
void func_00460ac0(void *param, void *work);
s32 func_0034bb20(s32 arg0);
void func_0034c260(s32 arg0);
void func_00353fb0(void);
void func_00355550(s32 a, u8 *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00453960(void *arg0);
void func_0043f9c8(void *dst, s32 value, u32 size);
s32 func_00451fc0(s32 arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                  void (*init)(u8 *), void (*close)(u8 *), u8 *work);
s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
void func_00440b68();
void func_0012d140(void);
u8 *func_00454a60(u8 *param, s32 mode);
s32 func_004553c0(u8 *ptr);
void func_00454bd0(u8 *ptr);
s32 func_0046b000(u32 param);
s32 func_0046a750(s32 param);

/* Camp-family helpers declared locally; the retail TUs are separate objects. */
void func_0012d410(u8 *arg0);
s32 func_0012e250(u8 *arg0);
void func_0012dea0(u8 *arg0, s32 arg1);
s32 func_0012e1d0(u8 *arg0);
void func_0012e150(u8 *arg0);
void func_0012db80(u8 *arg0, s32 arg1);
s32 func_0013bcf0(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_0013ea20(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_0013caa0(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_0013d8b0(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_00142f20(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_003627b0(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_0035e8b0(u8 *arg0, s32 *arg1, u8 *arg2);
s32 func_0012d630(u8 *arg0);
s32 func_0012e900(u8 *arg0);
s32 func_00138b20(u8 *arg0);
s32 func_00356870(u8 *arg0);
s32 func_00131910(u8 *arg0);
s32 func_00135cf0(u8 *arg0);
s32 func_0013ffd0(u8 *arg0);
s32 func_0035fc90(u8 *arg0);
void func_00130580(u8 *arg0);
void func_0013ab30(u8 *arg0);
void func_00134ab0(u8 *arg0);
void func_001377e0(u8 *arg0);
void func_001422b0(u8 *arg0);
void func_00361a30(u8 *arg0);
void func_00359720(u8 *arg0);

extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern u16 D_008C024E[];
extern u8 D_00793E80[];
extern u8 D_005E5890[];
extern u8 D_005E58A0[];
extern u8 D_005E58B0[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_005E5810[];
extern u8 D_005E5870[];
extern u8 D_005E5880[];

/* gp - 0x4E14 = 0x007642DC. */
extern u8 *iGpffffb1ec;
/* gp - 0x6348 = string table pointer source. */
extern u8 iGpffff9cb8;
/* gp - 0x6350 / -0x634C = string pointers. */
extern u8 *iGpffff9cb0;
extern u8 *iGpffff9cb4;
/* gp - 0x6340 = string buffer. */
extern u8 iGpffff9cc0;

// FUN_0012C510
s32 func_0012c510(void) {
    u8 *p;
    u32 state;
    s32 r;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 idx;
    u32 mid;
    u8 sp20[0x30];

    p = iGpffffb1ec;
    *(s32 *)(p + 0x970C) = 0;
    *(s32 *)(p + 0x9710) = 0;
    func_00460ac0((u8 *)D_00793E80 + *(u16 *)(p + 0x973C) * 0x30, p + 0x970C);
    state = *(u32 *)p;
    switch (state) {
    case 0:
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x20) = 0;
        *(u8 *)(p + 0x18) = 0xFF;
        *(s32 *)(p + 0x28) = 0;
        *(s32 *)p = 1;
        func_0045af60(0, 2, 0, 3);
        break;
    case 1:
        *(s32 *)(p + 0x10) = 1;
        *(s32 *)p = 2;
        func_0012d410(p + 0x18);
        func_0034bb20(1);
        break;
    case 2:
        *(s32 *)(p + 0x10) = 1;
        if ((func_0012e250(p + 0x18) != 0) && (*(s32 *)(p + 0x10) == 1)) {
            if (D_008C024E[0] & 0x40) {
                *(s32 *)(p + 4) = 0;
                *(s32 *)p = 3;
                idx = *(s32 *)(p + 0x28) * 4;
                mid = idx + (u32)p;
                switch (*(u32 *)(mid + 0x34)) {
                case 1:
                    *(s32 *)(p + 8) = 4;
                    break;
                case 0:
                    *(s32 *)(p + 8) = 5;
                    func_00355550(0, iGpffff9cb0, 0x14, 8, 1, 2, 0xC7, 0xB1);
                    break;
                case 2:
                    *(s32 *)(p + 8) = 6;
                    break;
                case 3:
                    *(s32 *)(p + 8) = 7;
                    break;
                case 4:
                    *(s32 *)(p + 8) = 8;
                    break;
                case 5:
                    *(s32 *)(p + 8) = 9;
                    func_00355550(0, iGpffff9cb4, 0x14, 8, 1, 2, 0xC7, 0xB1);
                    break;
                case 6:
                    *(s32 *)(p + 8) = 0xA;
                    break;
                default:
                    func_0046d730(D_005E5890, 0xFD);
                    break;
                }
                func_0012dea0(p + 0x18, 3);
                func_0034bb20(2);
                func_0045af60(0, 2, 0, 3);
            } else if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x10)) {
                func_0012dea0(p + 0x18, 3);
                *(s32 *)p = 3;
                *(s32 *)(p + 8) = 0xD;
                *(s32 *)(p + 0x14) = 0;
                func_0034bb20(2);
                func_0045af60(0, 2, 0, 4);
            } else {
                func_00453670(&sp20, *(s32 *)(p + 0x50), *(s32 *)(p + 0x50),
                              *(s32 *)(p + 0x28), 0);
                func_004538e0(&sp20, 0x4000, 0x1000, 0, 0);
                if (func_00453960(&sp20) != 0) {
                    func_0012db80(p + 0x18, *(s32 *)((u8 *)&sp20 + 0x24));
                }
            }
        }
        break;
    case 13:
        if ((func_0012e1d0(p + 0x18) != 0) && (*(s32 *)(p + 0x14) != 0)) {
            return -1;
        }
        break;
    case 3:
        r = *(s32 *)(p + 8);
        if ((r < 4) || (r > 0xD)) {
            func_0046d730(D_005E5890, 0x133);
        }
        if (func_0012e1d0(p + 0x18) != 0) {
            func_0012e150(p + 0x18);
            *(s32 *)p = *(s32 *)(p + 8);
        }
        break;
    case 4:
        r = func_0013bcf0(p + 4, &sp6C, p + 0x2BC);
        switch (r) {
        case 0:
            if (sp6C != 0) {
                *(s32 *)(p + 0x10) = 2;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 5:
        r = func_0013ea20(p + 4, &sp68, p + 0x1EA4);
        switch (r) {
        case 0:
            if (sp68 != 0) {
                *(s32 *)(p + 0x10) = 4;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 6:
        r = func_0013caa0(p + 4, &sp64, p + 0x31DC);
        switch (r) {
        case 0:
            if (sp64 != 0) {
                *(s32 *)(p + 0x10) = 0x10;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 7:
        r = func_0013d8b0(p + 4, &sp60, p + 0x5A8C);
        switch (r) {
        case 0:
            if (sp60 != 0) {
                *(s32 *)(p + 0x10) = 0x20;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 8:
        r = func_00142f20(p + 4, &sp5C, p + 0x7750);
        switch (r) {
        case 0:
            if (sp5C != 0) {
                *(s32 *)(p + 0x10) = 0x40;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 10:
        r = func_003627b0(p + 4, &sp58, p + 0x9000);
        switch (r) {
        case 0:
            if (sp58 != 0) {
                *(s32 *)(p + 0x10) = 0x80;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    case 9:
        r = func_0035e8b0(p + 4, &sp54, p + 0x4774);
        switch (r) {
        case 0:
            if (sp54 != 0) {
                *(s32 *)(p + 0x10) = 8;
            }
            break;
        case 1:
            *(s32 *)(p + 4) = 0;
            *(s32 *)p = 1;
            break;
        case 2:
            *(s32 *)(p + 0x10) = 0;
            return -1;
        }
        break;
    }
    return 0;
}

// FUN_0012CC50
void func_0012cc50(u8 *arg0) {
    u8 *p;
    u32 state;

    p = *(u8 **)(arg0 + 0x38);
    func_0034bb20(0);
    func_0034c260(0);
    state = *(u32 *)p;
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_0012e150(p + 0x18);
        break;
    case 4:
        func_00130580(p + 0x2BC);
        break;
    case 5:
        func_0013ab30(p + 0x1EA4);
        break;
    case 6:
        func_00134ab0(p + 0x31DC);
        break;
    case 7:
        func_001377e0(p + 0x5A8C);
        break;
    case 8:
        func_001422b0(p + 0x7750);
        break;
    case 10:
        func_00361a30(p + 0x9000);
        break;
    case 9:
        func_00359720(p + 0x4774);
        break;
    case 13:
        /* Retail's jump-table entry 13 targets the post-switch tail directly, so
           this case is EMPTY and must stay a separate label: folding it into the
           assert group below makes entry 13 point at the assert instead, which
           every per-function check still passes -- the instructions are identical
           and only the table DATA differs, so it surfaces solely as a one-word
           image mismatch at link time. */
        break;
    case 11:
    case 12:
    default:
        func_0046d730(D_005E5890, 0x223);
        break;
    }
    func_00353fb0();
    jtbl_008873EC[0](p);
    iGpffffb1ec = 0;
}

/* measured: typed D_00887300 base local without opt_propagation off folds
   the array address into per-call lui/lw; off keeps retail's single
   lui/addiu hoist into $16 (same fix as mdlManager func_00476c70). */
#pragma opt_propagation off

// FUN_0012CD90
void func_0012cd90(void) {
    void (**base)(s32, s32);
    s32 sp4C;
    s32 result;
    u8 *p;

    result = 1;
    p = iGpffffb1ec;
    if (p != NULL) {
        D_00887304[0](0xE, &sp4C);
        base = D_00887300;
        base[0](0xE, 0);
        if (*(s32 *)(p + 0x10) & 1) {
            result = func_0012d630(p + 0x18);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~1;
            }
        }
        if (*(s32 *)(p + 0x10) & 2) {
            result = func_0012e900(p + 0x2BC);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~2;
            }
        }
        if (*(s32 *)(p + 0x10) & 4) {
            result = func_00138b20(p + 0x1EA4);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~4;
            }
        }
        if (*(s32 *)(p + 0x10) & 8) {
            result = func_00356870(p + 0x4774);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~8;
            }
        }
        if (*(s32 *)(p + 0x10) & 0x10) {
            result = func_00131910(p + 0x31DC);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~0x10;
            }
        }
        if (*(s32 *)(p + 0x10) & 0x20) {
            result = func_00135cf0(p + 0x5A8C);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~0x20;
            }
        }
        if (*(s32 *)(p + 0x10) & 0x40) {
            result = func_0013ffd0(p + 0x7750);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~0x40;
            }
        }
        if (*(s32 *)(p + 0x10) & 0x80) {
            result = func_0035fc90(p + 0x9000);
            if (result != 0) {
                *(s32 *)(p + 0x10) &= ~0x80;
            }
        }
        if ((*(s32 *)p == 0xD) && (result != 0)) {
            *(s32 *)(p + 0x14) = 1;
        }
        base[0](0xE, sp4C);
    }
}
/* measured: closes the opt_propagation bracket for func_0012cd90. */
#pragma opt_propagation on

// FUN_0012D000
s32 func_0012d000(s32 arg0, s16 arg1) {
    s32 r;
    u8 *p;

    func_0044ea90(D_005E5890, 0x27E);
    p = (u8 *)D_008873F4[0](1, 0x9740, 0x40000);
    if (iGpffffb1ec != 0) {
        func_0046d730(D_005E5890, 0x27F);
    }
    iGpffffb1ec = p;
    if (p == NULL) {
        return 0;
    }
    *(u16 *)(p + 0xC) = arg1;
    r = func_00451fc0(arg0, &iGpffff9cb8, 0xC7, 0, 0,
                      (void (*)(u8 *))func_0012c510, (void (*)(u8 *))func_0012cc50, p);
    func_0034bb20(0);
    func_0034c260(1);
    func_0043f9c8(p + 0x970C, 0, 0x30);
    *(s32 *)(p + 0x9714) = (s32)func_0012cd90;
    *(s32 *)(p + 0x971C) = 0;
    func_0012d140();
    return r;
}

// FUN_0012D140
void func_0012d140(void) {
    *(u16 *)(iGpffffb1ec + 0x973C) = 0xB1;
}

// FUN_0012D160
void func_0012d160(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* Declared here because func_00451de0 below takes this function's address as a
   callback. */
s32 func_0012d190(u8 *arg0);

// FUN_0012D190
s32 func_0012d190(u8 *arg0) {
    s32 i;
    s32 j;
    s32 r;
    u8 *p;
    u8 *q;
    u8 *dst;

    p = *(u8 **)(arg0 + 0x38);
    switch (*(u16 *)p) {
    case 0:
        goto state0;
    case 1:
        goto state1;
    case 2:
        goto state2;
    default:
        goto fail;
    }

state0:
    func_00440b68(&iGpffff9cc0, D_005E5890, 0x2F8);
    *(u8 **)(p + 0x34) = func_00454a60(D_005E58A0, 1);
    if (*(u8 **)(p + 0x34) == NULL) {
        func_0046d730(D_005E5890, 0x2F9);
    }
    *(u16 *)p += 1;

state1:
    if (func_004553c0(*(u8 **)(p + 0x34)) != 0) {
        for (i = 0; i < 6; i++) {
            q = p + i * 4;
            dst = q + 0x1C;
            *(s32 *)dst = func_0046b000(*(u32 *)(q + 4));
            if (*(s32 *)dst == 0) {
                func_0046d730(D_005E5890, 0x30C);
            }
        }
        *(u16 *)p += 1;
    } else {
        goto fail;
    }

state2:
    for (j = 0; j < 6; j++) {
        if (func_0046a750(*(s32 *)(p + j * 4 + 0x1C)) != 0) {
        } else {
            r = 0;
            goto done;
        }
    }
    func_00454bd0(*(u8 **)(p + 0x34));
    *(u8 **)(p + 0x34) = NULL;
    r = -1;
    goto done;

fail:
    r = 0;

done:
    return r;
}
// FUN_0012D320
s32 func_0012d320(void) {
    s32 r;
    u8 *p;

    func_0044ea90(D_005E5890, 0x32C);
    p = (u8 *)D_008873F4[0](1, 0x38, 0x40000);
    if (p == NULL) {
        return 0;
    }
    r = func_00451de0(D_005E58B0, 0xF, 0, 0, (void *)func_0012d190,
                      (void *)func_0012d160, p);
    *(u16 *)p = 0;
    *(u8 **)(p + 4) = D_005E5830;
    *(u8 **)(p + 8) = D_005E5850;
    *(u8 **)(p + 0xC) = D_005E57F0;
    *(u8 **)(p + 0x10) = D_005E5810;
    *(u8 **)(p + 0x14) = D_005E5870;
    *(u8 **)(p + 0x18) = D_005E5880;
    return r;
}
