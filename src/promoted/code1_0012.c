#include "include_asm.h"
#include "type.h"

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void func_00264d90();
extern s32 D_00796670[];

extern void func_00267570();

extern u8 *D_007242CC;
extern s32 iGpffffb1e0;
extern s32 iGpffffb1cc;
extern u8 *func_00460990(void);
extern void func_00460ac0(char *name, u8 *task);
extern void func_001221a0(void);
extern void func_00122a40(void);
extern char D_00796340[];
extern char D_00795F50[];
extern s32 func_001060b0(void);
extern s32 func_001060c0(void);
extern s32 func_00110850(s16 arg0, s16 arg1);
extern s32 func_0015a160(void);
extern s32 func_0028b650(void);

extern s32 func_004522d0(s32 arg0);


typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;



extern void func_003ef3a0(void *arg0);

// FUN_00121170
void func_00121170(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}



// FUN_001211A0
s32 func_001211a0(void)
{
    return 0;
}

// FUN_00121B20
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121b20);

// FUN_001223D0
s32 func_001223d0(void) {
    u8 *p;
    s32 x;

    p = func_00460990();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    *(void **)(p + 8) = (void *)func_001221a0;
    *(s32 *)(p + 0x10) = x;
    func_00460ac0(D_00796340, p);
    return 0;
}

// FUN_00122720
/* The case values come from decoding the jump table at 0x007466C0 with
   tools/jtbl.py: entry 0 returns 1, entries 1/2/4/5 share one body returning
   0, entry 3 returns 2, and anything >= 6 falls through to the default 1.
   The labels are declared in that object order because b210 lays case bodies
   out in declaration order. */
s32 func_00122720(void) {
    s32 *state;

    state = (s32 *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state[0]) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 4:
    case 5:
        return 0;
    case 3:
        return 2;
    }
    return 1;
}

// FUN_00122820
void func_00122820(s32 arg0, s32 arg1)
{
    func_00264d90(0, arg0, arg1, D_00796670);
}



// FUN_00122860
void func_00122860(s32 arg0, s32 arg1)
{
    func_00267570(0, arg0, arg1, D_00796670);
}



// FUN_00122A10
void func_00122a10(void *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    D_007242CC = 0;
}



// FUN_001236E0
s32 func_001236e0(void) {
    u8 *p;
    u8 *q;

    p = func_00460990();
    q = D_007242CC;
    *(void **)(p + 8) = (void *)func_00122a40;
    *(u8 **)(p + 0x10) = q;
    func_00460ac0(D_00795F50, p);
    return 0;
}

// FUN_00123810
s16 func_00123810(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 6);
    }
    return var_2;
}



// FUN_00123830
s16 func_00123830(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 4);
    }
    return var_2;
}



/* measured: same instructions and the same 104-byte object as retail; the
   only residual is that retail stores the masked value to +6 and loads the
   +4 field BEFORE sign-extending the second argument, while b210 materialises
   the dsll32/dsra32 pair first (3 words, nd 14). Measured identical at nd 14:
   naming the first argument in a local, naming the (s16) cast in a local, and
   both; schedule on is much worse (nd 42, obj 92). Call-argument setup order
   floor. Committed at nd 14. */
// FUN_00123850 NONMATCHING
#ifdef NON_MATCHING
void func_00123850(void) {
    u8 *p;
    s32 t;

    p = D_007242CC;
    if (p != NULL) {
        *(s16 *)(p + 4) = (s16)func_001060b0();
        t = func_001060c0() & 0xFF;
        *(s16 *)(p + 6) = (s16)t;
        *(s16 *)(p + 8) = (s8)func_00110850(*(s16 *)(p + 4), (s16)t);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123850);
#endif

// FUN_00123A10
void func_00123a10(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        *(s32 *)(p + 0x18) = 1;
        if (func_0015a160() != 0) {
            goto set1;
        }
        if (func_0028b650() != 0) {
            goto set1;
        }
        *(s32 *)(p + 0x1C) = 0;
        return;
set1:
        *(s32 *)(p + 0x1C) = 1;
    }
}

// FUN_00123A80
void func_00123a80(void)
{
    u8 *temp_3;

    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        *(s32 *)(temp_3 + 0x14) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
    }
}



// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00123E30
s32 func_00123e30(void)
{
    if (func_004522d0(iGpffffb1e0) == 3) {
        iGpffffb1e0 = 0;
        return 1;
    }
    return 0;
}

// FUN_0012B810
s32 func_0012b810(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(func_00452560(arg0));
    if (temp_2->field_18 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_18;
}



// FUN_0012B940
void func_0012b940(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_003ef3a0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(func_00452560(arg0));
    if (temp_2->field_4 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_4;
}
