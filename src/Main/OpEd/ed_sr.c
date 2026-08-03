#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit ed_sr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

/* GP-owned work record shared across the opening/ending TU. */
extern s32 *iGpffffb5b8;
extern u8 iGpffffa9f0;
extern u8 iGpffffa9f8;

/* Shared end-scene helpers (defined in sibling TUs of the same ed_* unit). */
extern void func_0046d730(void *file, s32 line);
extern void func_0044ea90(const void *msg, s32 id);
extern void func_0038ddf0(void);
extern void func_0038f010(void);
extern void func_0038f0b0(void);
extern void func_0038de90(void);
extern u32 func_0038df10(void);
extern void func_0038df60(void);
extern void func_0038e4b0(void);
extern void func_0038f620(void);
extern void func_0038f680(void);
extern void func_0038f7f0(void);
extern u32 func_0038f880(void);
extern void func_0038f600(u8 *arg0);
extern void func_0038dd90(u8 *arg0);

/* Window / effect / scripting helpers. */
extern u8 *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern s32 func_00106330(s32 id);
extern s32 func_00122720(void);
extern s32 func_001227a0(void);
extern void func_00122520(s32 a, s32 b);
extern s32 func_00452380(void *path);
extern s32 func_00452490(s32 handle);
extern void func_00452570(void *a, void *b);
extern s32 func_0045a3e0(s32 a, s32 b);
extern void func_004598e0(s32 fadeDuration);
extern s32 func_0046a1f0(s32 a, s64 b, void *c);
extern s32 func_0046a2c0(void);
extern s32 func_0029d020(void);

/* Data / jumptable globals. */
extern char D_007964C0[];
extern char D_00796340[];
extern char D_0064F230[];
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Window callbacks (defined below in this file / in this TU). */
s32 func_00451fc0(s32 arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                  void (*init)(u8 *), void (*close)(u8 *), u8 *work);
s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);

// FUN_0038EE40
void func_0038ee40(void) {
    s32 v;
    u8 *p;

    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    p = (u8 *)iGpffffb5b8;
    if (!(~*(s32 *)p & 1)) {
        v = *(s32 *)(p + 0x124C);
        switch (v) {
        case 0:
            if (func_0038f880() == 0) {
                *(s32 *)(p + 0x124C) = 1;
            }
            break;
        case 1:
            func_0038f010();
            break;
        case 2:
            *(s32 *)(p + 0x1254) += 1;
            if (func_00106330(0x1472) != 0) {
                if (func_0046a2c0() == 0xCC6) {
                    func_0038de90();
                }
            } else if (*(s32 *)(p + 0x1254) == 1) {
                func_0038de90();
                func_0045a3e0(0x23, 1);
            }
            if ((func_0038df10() == 0) && (func_00452490(*(s32 *)(p + 0x1250)) == 0)) {
                func_00122520(func_001227a0(), 0xA);
                *(s32 *)(p + 0x124C) = 3;
                if (func_00106330(0x1472) == 0) {
                    func_004598e0(0x3C);
                }
            }
            break;
        case 3:
            if (func_00122720() != 0) {
                *(s32 *)p &= ~1;
            }
            break;
        }
        func_0038f680();
        func_0038df60();
    }
}

// FUN_0038F010
void func_0038f010(void) {
    s32 *p;
    s16 v;

    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    p = iGpffffb5b8;
    if (func_00106330(0x1472) != 0) {
        v = 0x11;
    } else {
        v = 0;
    }
    if (v != 0) {
        *(s32 *)((u8 *)p + 0x1250) = func_0046a1f0(*(s32 *)((u8 *)p + 4), v, &D_00796340);
    }
    *(s32 *)((u8 *)p + 0x1254) = 0;
    *(s32 *)((u8 *)p + 0x124C) = 2;
}

// FUN_0038F0B0
/* measured: typed D_00887300 base local with opt_propagation off keeps
   retail's single lui/addiu hoist into $16 (same fix as cmpMain func_0012cd90). */
#pragma opt_propagation off
void func_0038f0b0(void) {
    void (**base)(s32, s32);
    s32 sp2C;

    D_00887304[0](0xE, &sp2C);
    base = D_00887300;
    base[0](0xE, 0);
    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    if (!(~*iGpffffb5b8 & 1)) {
        func_0038e4b0();
    }
    base[0](0xE, sp2C);
}
#pragma opt_propagation on

// FUN_0038F160
s32 func_0038f160(void) {
    func_0038ee40();
    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    if (*iGpffffb5b8 & 1) {
        return 0;
    }
    return -1;
}

// FUN_0038F1C0
s32 func_0038f1c0(u8 *arg0) {
    u8 *work;
    s32 v;

    v = *(s32 *)(arg0 + 0x38);
    work = func_00460990();
    *(s32 *)(work + 0x8) = (s32)func_0038f0b0;
    *(s32 *)(work + 0x10) = v;
    func_00460ac0(&D_007964C0, work);
    return 0;
}

// FUN_0038F220
void func_0038f220(u8 *arg0) {
    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    func_0038ddf0();
    func_0038f620();
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0038F290
s32 func_0038f290(void) {
    s32 state;
    u8 *w;
    u8 *p;
    s32 r;

    r = func_0029d020();
    if (r == 0xA) {
        func_0044ea90(&iGpffffa9f0, 0x112);
        w = (u8 *)jtbl_008873E8[0](0x1258, 0x40000);
        state = func_00451fc0(0, &iGpffffa9f8, 0xF, 0, 0,
                              (void (*)(u8 *))func_0038f160,
                              (void (*)(u8 *))func_0038f220, w);
        *(s32 *)(w + 8) = func_00451de0(&D_0064F230, 0x97, 1, 2,
                                        (void *)func_0038f1c0, 0, 0);
        func_00452570((void *)state, (void *)*(s32 *)(w + 8));
        *(s32 *)(w + 0) = 0;
        func_0038f600(w + 0xC);
        func_0038dd90(w + 0x1C);
        *(s32 *)(w + 4) = state;
        iGpffffb5b8 = (s32 *)w;
        if (w == NULL) {
            func_0046d730(&iGpffffa9f0, 0x64);
        }
        p = (u8 *)iGpffffb5b8;
        func_0038f7f0();
        *(s32 *)(p + 0x124C) = 0;
        *(s32 *)p |= 1;
    } else if ((r > 0xA) && (func_00452380(&iGpffffa9f8) == 0)) {
        return 1;
    }
    return 0;
}
