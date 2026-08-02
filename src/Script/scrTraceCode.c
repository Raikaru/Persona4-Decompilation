/* Source unit: src/Script/scrTraceCode_0029ad20.c */
#include "include_asm.h"
#include "type.h"

/* ------------------------------------------------------------------ */
/* Types                                                               */

typedef union
{
    s32 iVal;
    f32 fVal;
    char* strVal;
} ScrValues;

/* 16 bytes */
typedef struct
{
    u32 contentType;  // 0x00
    u32 unk_04;
    s32 elementCount; // 0x08
    u32 offset;       // 0x0c
} ScrContentEntry;

/* 32 bytes. Label or procedure */
typedef struct
{
    char name[24]; // 0x00
    u32 addr;      // 0x18
    s32 unk_1c;    // 0x1c
} ScrLblPrcd;

/* 4 bytes */
typedef union
{
    struct
    {
        s16 opCode;
        s16 sOperand;
    } opOperand16;

    s32 iOperand;
    f32 fOperand;
} ScrInstruction;

typedef struct
{
    char pad_00[0x14];
    s16 localIntNum; // 0x14
    s16 localFloatNum; // 0x16
} ScrHeader;

typedef struct ScrData
{
    char scrName[24];           // 0x00
    s32 pc;                     // 0x18
    s32 sp;                     // 0x1c
    s8 stackTypes[48];          // 0x20
    ScrValues stackValues[48];  // 0x50
    ScrHeader* scrHeader;           // 0x110
    ScrContentEntry* entries;       // 0x114
    ScrLblPrcd* proceduresContent;  // 0x118
    ScrLblPrcd* labelsContent;      // 0x11c
    ScrInstruction* instrContent;   // 0x120
    u8 pad_124[0x128 - 0x124];
    char* stringsContent;   // 0x128
    u8 pad_12c[0x134 - 0x12c];
    u32 timer;      // 0x134
    u32 cmdTimer;   // 0x138
    u8 pad_13c[0x140 - 0x13c];
    s32* localInt;    // 0x140
    f32* localFloat;  // 0x144
} ScrData;

typedef struct
{
    u32 (*func)(void);
    s32 paramCount;
} ScrCmdEntry;

/* 8 bytes; grouped command table (group = cmdIdx >> 12) */
typedef struct
{
    ScrCmdEntry* cmds; // 0x00
    s32 count;         // 0x04
} ScrCmdGroup;

typedef u32 (*CodeFunc)(ScrData* scr);

enum ScrOperation
{
    SCR_OPERATION_ADD,
    SCR_OPERATION_SUB,
    SCR_OPERATION_MUL,
    SCR_OPERATION_DIV,
    SCR_OPERATION_OR,
    SCR_OPERATION_AND,
    SCR_OPERATION_EQ,
    SCR_OPERATION_NEQ,
    SCR_OPERATION_S,
    SCR_OPERATION_L,
    SCR_OPERATION_SE,
    SCR_OPERATION_LE
};

enum
{
    SCR_STACK_TYPE_INTEGER, // 0
    SCR_STACK_TYPE_FLOAT,   // 1
    SCR_STACK_TYPE_ADDR = 4,
    SCR_STACK_TYPE_STRING   // 5
};

enum
{
    SCR_CONTENT_TYPE_PROCEDURE,
    SCR_CONTENT_TYPE_LABEL,
    SCR_CONTENT_TYPE_INSTR,
    SCR_CONTENT_TYPE_MSG,
    SCR_CONTENT_TYPE_STRINGS,
    SCR_CONTENT_TYPE_MAX
};

#define SCR_STACK_RET 47
#define SCR_CODEFUNC_MAX 35

#define CODEFUNC_STOP 0
#define CODEFUNC_NEXTINSTR 1
#define CODEFUNC_YIELD 2

#define SCRTRACE_STOP 2
#define SCRTRACE_YIELD 1

/* ------------------------------------------------------------------ */
/* Externs and asserts                                                 */

extern char D_0063E068[];  /* file name */
extern char D_0063E080[];  /* generic stack assert message */
extern char D_0063E0A0[];  /* PopInt invalid stack type */
extern char D_0063E0D0[];  /* PopFloat invalid stack type (RET) */
extern char D_0063E100[];  /* PopFloat invalid stack type (?) */
extern char D_0063E130[];  /* PopLIX operand range message */
extern char D_0063E160[];  /* Run abort message */
extern char D_0063E190[];  /* Minus invalid stack type (RET) */
extern char D_0063E1C0[];  /* Minus invalid stack type (?) */
extern char D_0063E1F0[];  /* Not invalid stack type (RET) */
extern char D_0063E220[];  /* Not invalid stack type (?) */
extern char D_0063E250[];  /* IF invalid stack type (RET) */
extern char D_0063E280[];  /* IF invalid stack type (?) */
extern char D_0063E340[];  /* scrGetIntPara invalid stack type */
extern char D_0063E370[];  /* scrGetFloatPara invalid stack type */
extern char D_0063E3A0[];  /* scrGetStrPara invalid stack type */

extern s32 D_00882AD0[]; /* VM memory, int view */
extern f32 D_008826D0[]; /* VM memory, float view */

extern ScrCmdGroup D_00748530[];  /* grouped command table */
extern s32 D_00748534[][2];       /* grouped command table, count view (base + 4) */

extern CodeFunc D_0063E2B0[]; /* sCodeFuncTable */

void func_0046d700(const char* file, s32 line, const char* msg, s32 value);
void func_0046d730(const char* file, s32 line);
void func_0046d740(const char* msg, const char* file, s32 line);

#define K_ASSERT(condition, line) \
    if (!(condition)) { func_0046d730(D_0063E068, (line)); }
#define K_ASSERT_MSG(condition, line, msg, value) \
    if (!(condition)) { func_0046d700(D_0063E068, (line), (msg), (value)); }
#define K_ABORT(msg, line) \
    func_0046d740((msg), D_0063E068, (line))

/* ------------------------------------------------------------------ */
/* Statics                                                             */

static ScrData* sCurrScript; // 00764600. Current script being executed

static s32 sOpRightType; // 007645fc
static s32 sOpLeftType;  // 007645f8
static f32 sOpFRes;      // 007645f4
static f32 sOpRightFVal; // 007645f0
static f32 sOpLeftFVal;  // 007645ec
static s32 sOpIRes;      // 007645e8
static s32 sOpRightIVal; // 007645e4
static s32 sOpLeftIVal;  // 007645e0

/* ------------------------------------------------------------------ */
/* Stack helpers                                                       */

static inline void PushInt(ScrData* scr, s32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 73, D_0063E080, scr->sp);

    scr->stackTypes[scr->sp] = SCR_STACK_TYPE_INTEGER;
    scr->stackValues[scr->sp].iVal = val;
    scr->sp++;
}

static inline void PushFloat(ScrData* scr, f32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 85, D_0063E080, scr->sp);

    scr->stackTypes[scr->sp] = SCR_STACK_TYPE_FLOAT;
    scr->stackValues[scr->sp].fVal = val;
    scr->sp++;
}

static inline void PushString(ScrData* scr, char* str)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 99, D_0063E080, scr->sp);

    scr->stackTypes[scr->sp] = SCR_STACK_TYPE_STRING;
    scr->stackValues[scr->sp].strVal = str;
    scr->sp++;
}

static inline void PushPC(ScrData* scr, s32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 141, D_0063E080, scr->sp);

    scr->stackTypes[scr->sp] = SCR_STACK_TYPE_ADDR;
    scr->stackValues[scr->sp].iVal = val;
    scr->sp++;
}

static inline s32 PopInt(ScrData* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 152);

    sp = --scr->sp;

    switch (scr->stackTypes[sp])
    {
        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case SCR_STACK_TYPE_ADDR:    return scr->stackValues[sp].iVal;
        case SCR_STACK_TYPE_FLOAT:   return (s32)scr->stackValues[sp].fVal;

        case 2: return D_00882AD0[scr->stackValues[sp].iVal];
        case 3:
            f = &D_008826D0[scr->stackValues[sp].iVal];
            return (s32)*f;
    }

    K_ABORT(D_0063E0A0, 165);

    return 0;
}

static inline f32 PopFloat(ScrData* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 176);

    sp = --scr->sp;

    switch (scr->stackTypes[sp])
    {
        case SCR_STACK_TYPE_INTEGER: return (f32)scr->stackValues[sp].iVal;

        case SCR_STACK_TYPE_ADDR:
            K_ABORT(D_0063E0D0, 182);
            return 0.0f;

        case SCR_STACK_TYPE_FLOAT: return scr->stackValues[sp].fVal;

        case 2: return (f32)D_00882AD0[scr->stackValues[sp].iVal];
        case 3:
            f = &D_008826D0[scr->stackValues[sp].iVal];
            return *f;
    }

    K_ABORT(D_0063E100, 191);

    return 0.0f;
}

// FUN_0029A050. Push an immediate int value
u32 func_0029a050(ScrData* scr)
{
    PushInt(scr, scr->instrContent[++scr->pc].iOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A100. Push an immediate short value
u32 func_0029a100(ScrData* scr)
{
    PushInt(scr, scr->instrContent[scr->pc].opOperand16.sOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A1B0. Push an immediate float value
u32 func_0029a1b0(ScrData* scr)
{
    PushFloat(scr, scr->instrContent[++scr->pc].fOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A260. Push an int from the VM memory
u32 func_0029a260(ScrData* scr)
{
    PushInt(scr, D_00882AD0[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A320. Push a float from the VM memory
u32 func_0029a320(ScrData* scr)
{
    f32* f;

    f = &D_008826D0[scr->instrContent[scr->pc].opOperand16.sOperand];
    PushFloat(scr, *f);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A3E0. Push an int from the local ints
u32 func_0029a3e0(ScrData* scr)
{
    PushInt(scr, scr->localInt[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A4A0. Push a float from the local floats
u32 func_0029a4a0(ScrData* scr)
{
    PushFloat(scr, scr->localFloat[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A560. Push a string
u32 func_0029a560(ScrData* scr)
{
    char* str;

    str = scr->stringsContent;
    str += scr->instrContent[scr->pc].opOperand16.sOperand;
    PushString(scr, str);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A610. Push return value
u32 func_0029a610(ScrData* scr)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 298, D_0063E080, scr->sp);

    scr->stackTypes[scr->sp] = scr->stackTypes[SCR_STACK_RET];
    scr->stackValues[scr->sp] = scr->stackValues[SCR_STACK_RET];
    scr->sp++;

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A6A0. Pop an int into the VM memory
u32 func_0029a6a0(ScrData* scr)
{
    D_00882AD0[scr->instrContent[scr->pc].opOperand16.sOperand] = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A820. Pop a float into the VM memory
u32 func_0029a820(ScrData* scr)
{
    f32 val;
    f32* f;

    val = PopFloat(scr);
    f = &D_008826D0[scr->instrContent[scr->pc].opOperand16.sOperand];
    *f = val;

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A9C0. Pop an int into a local int
u32 func_0029a9c0(ScrData* scr)
{
    K_ASSERT_MSG(scr->instrContent[scr->pc].opOperand16.sOperand < scr->scrHeader->localIntNum, 336, D_0063E130, scr->instrContent[scr->pc].opOperand16.sOperand);

    scr->localInt[scr->instrContent[scr->pc].opOperand16.sOperand] = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029AB80. Pop a float into a local float
u32 func_0029ab80(ScrData* scr)
{
    scr->localFloat[scr->instrContent[scr->pc].opOperand16.sOperand] = PopFloat(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}




// FUN_0029AD20
u32 func_0029AD20(ScrData* scr)
{
    scr->pc++;

    return 1;
}

/* FUN_0029AD40 (CodeFunc_Comm) NOT converted: retail allocates
   cmdIdx-masked/group*8/cmds/idx*8 into $s1-$s4 with the mask in place
   and an sltu bool test, which b210 never reproduces from any spelling of
   the grouped-table access (20+ variants probed); the instruction stream
   is identical, only registers differ. */
// FUN_0029AD40. Call a native function
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029ad40);

// FUN_0029AE90
u32 func_0029ae90(ScrData* scr)
{
    if (scr->sp == 0)
    {
        return CODEFUNC_STOP;
    }

    K_ASSERT(scr->stackTypes[scr->sp - 1] == SCR_STACK_TYPE_ADDR, 471);

    scr->pc = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B020. Jump to a procedure
u32 func_0029b020(ScrData* scr)
{
    s16 prcdIdx;

    prcdIdx = scr->instrContent[scr->pc].opOperand16.sOperand;
    scr->pc = scr->proceduresContent[prcdIdx].addr;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B060. Call a procedure + push PC
u32 func_0029b060(ScrData* scr)
{
    PushPC(scr, scr->pc);
    scr->pc = scr->proceduresContent[scr->instrContent[scr->pc].opOperand16.sOperand].addr;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B120
u32 func_0029b120(ScrData* scr)
{
    K_ABORT(D_0063E160, 506);

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B170. Jump to a label
u32 func_0029b170(ScrData* scr)
{
    s16 lblIdx;

    lblIdx = scr->instrContent[scr->pc].opOperand16.sOperand;
    scr->pc = scr->labelsContent[lblIdx].addr;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B1B0
void func_0029b1b0(ScrData* scr, u32 type)
{
    s32 sp;

    K_ASSERT(scr->sp >= 2, 531);

    sp = scr->sp;
    sOpLeftType = scr->stackTypes[sp - 1];
    sOpRightType = scr->stackTypes[sp - 2];

    // int
    if ((sOpLeftType == SCR_STACK_TYPE_INTEGER || sOpLeftType == 2) &&
       ((sOpRightType == SCR_STACK_TYPE_INTEGER || sOpRightType == 2)))
    {
        sOpLeftIVal = PopInt(scr);
        sOpRightIVal = PopInt(scr);

        switch (type)
        {
            case SCR_OPERATION_ADD: sOpIRes = sOpLeftIVal + sOpRightIVal; break;
            case SCR_OPERATION_SUB: sOpIRes = sOpLeftIVal - sOpRightIVal; break;
            case SCR_OPERATION_MUL: sOpIRes = sOpLeftIVal * sOpRightIVal; break;
            case SCR_OPERATION_DIV:
                K_ASSERT(sOpRightIVal != 0, 550);
                sOpIRes = sOpLeftIVal / sOpRightIVal;
                break;

            case SCR_OPERATION_OR:
                if (sOpLeftIVal != 0 || sOpRightIVal != 0)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_AND:
                if (sOpLeftIVal != 0 && sOpRightIVal != 0)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_EQ:
                if (sOpLeftIVal == sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_NEQ:
                if (sOpLeftIVal != sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_S:
                if (sOpLeftIVal < sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_L:
                if (sOpLeftIVal > sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_SE:
                if (sOpLeftIVal <= sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
                break;

            case SCR_OPERATION_LE:
                if (sOpLeftIVal >= sOpRightIVal)
                {
                    sOpIRes = 1;
                }
                else
                {
                    sOpIRes = 0;
                }
        }

        PushInt(scr, sOpIRes);
        return;
    }

    // float

    sOpLeftFVal = PopFloat(scr);
    sOpRightFVal = PopFloat(scr);

    switch (type)
    {
        case SCR_OPERATION_ADD: sOpFRes = sOpLeftFVal + sOpRightFVal; break;
        case SCR_OPERATION_SUB: sOpFRes = sOpLeftFVal - sOpRightFVal; break;
        case SCR_OPERATION_MUL: sOpFRes = sOpLeftFVal * sOpRightFVal; break;
        case SCR_OPERATION_DIV:
            K_ASSERT(sOpRightFVal != 0.0f, 617);
            sOpFRes = sOpLeftFVal / sOpRightFVal;
            break;

        case SCR_OPERATION_OR:
            if (sOpLeftFVal != 0.0f || sOpRightFVal != 0.0f)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_AND:
            if (sOpLeftFVal != 0.0f && sOpRightFVal != 0.0f)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_EQ:
            if (sOpLeftFVal == sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_NEQ:
            if (sOpLeftFVal != sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_S:
            if (sOpLeftFVal < sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_L:
            if (sOpLeftFVal > sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_SE:
            if (sOpLeftFVal <= sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;

        case SCR_OPERATION_LE:
            if (sOpLeftFVal >= sOpRightFVal)
            {
                sOpIRes = 1;
            }
            else
            {
                sOpIRes = 0;
            }

            PushInt(scr, sOpIRes);
            return;
    }

    PushFloat(scr, sOpFRes);
}




// FUN_0029BEB0
u32 CodeFunc_Add(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_ADD);
    scr->pc++;

    return 1;
}



// FUN_0029BEF0
u32 CodeFunc_Sub(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SUB);
    scr->pc++;

    return 1;
}



// FUN_0029BF30
u32 func_0029BF30(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_MUL);
    scr->pc++;

    return 1;
}



// FUN_0029BF70
u32 CodeFunc_Div(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_DIV);
    scr->pc++;

    return 1;
}

// FUN_0029BFB0
u32 func_0029bfb0(ScrData* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 732);

    sp = scr->sp;
    switch (scr->stackTypes[sp - 1])
    {
        case SCR_STACK_TYPE_INTEGER:
            scr->stackValues[sp - 1].iVal = -scr->stackValues[sp - 1].iVal;
            break;

        case SCR_STACK_TYPE_ADDR:
            K_ABORT(D_0063E190, 738);
            break;

        case SCR_STACK_TYPE_FLOAT:
            scr->stackValues[sp - 1].fVal = -scr->stackValues[sp - 1].fVal;
            break;

        case 2:
            D_00882AD0[scr->stackValues[sp - 1].iVal] = -D_00882AD0[scr->stackValues[sp - 1].iVal];
            break;

        case 3:
            f = &D_008826D0[scr->stackValues[sp - 1].iVal];
            *f = -(*f);
            break;

        default:
            K_ABORT(D_0063E1C0, 752);
    }

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029C130
u32 func_0029c130(ScrData* scr)
{
    u32 res;

    K_ASSERT(scr->sp > 0, 767);

    switch (scr->stackTypes[scr->sp - 1])
    {
        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case 2:
            res = PopInt(scr) == 0;
            PushInt(scr, res);
            break;

        case SCR_STACK_TYPE_FLOAT: // fallthrough
        case 3:
            res = PopFloat(scr) == 0.0f;
            PushInt(scr, res);
            break;

        case SCR_STACK_TYPE_ADDR:
            K_ABORT(D_0063E1F0, 786);
            break;

        default:
            K_ABORT(D_0063E220, 789);
    }

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}




// FUN_0029C550
u32 CodeFunc_Or(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_OR);
    scr->pc++;

    return 1;
}



// FUN_0029C590
u32 CodeFunc_And(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_AND);
    scr->pc++;

    return 1;
}



// FUN_0029C5D0
u32 CodeFunc_Eq(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_EQ);
    scr->pc++;

    return 1;
}



// FUN_0029C610
u32 CodeFunc_Neq(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_NEQ);
    scr->pc++;

    return 1;
}



// FUN_0029C650
u32 CodeFunc_S(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_S);
    scr->pc++;

    return 1;
}



// FUN_0029C690
u32 CodeFunc_L(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_L);
    scr->pc++;

    return 1;
}



// FUN_0029C6D0
u32 CodeFunc_SE(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SE);
    scr->pc++;

    return 1;
}



// FUN_0029C710
u32 CodeFunc_LE(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_LE);
    scr->pc++;

    return 1;
}

// FUN_0029C750
u32 func_0029c750(ScrData* scr)
{
    u32 res;

    K_ASSERT(scr->sp > 0, 894);

    switch (scr->stackTypes[scr->sp - 1])
    {
        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case 2:
            res = PopInt(scr);
            break;

        case SCR_STACK_TYPE_FLOAT: // fallthrough
        case 3:
            if (PopFloat(scr) == 0.0f)
            {
                res = 0;
            }
            else
            {
                res = 1;
            }
            break;

        case SCR_STACK_TYPE_ADDR:
            K_ABORT(D_0063E250, 908);
            res = 0;
            break;

        default:
            K_ABORT(D_0063E280, 912);
            res = 0;
    }

    if (res)
    {
        scr->pc++;
    }
    else
    {
        scr->pc = scr->labelsContent[scr->instrContent[scr->pc].opOperand16.sOperand].addr;
    }

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029CB00
u32 func_0029cb00(ScrData* scr)
{
    s16 opCode;
    u32 codeFuncRet;

    while (1)
    {
        opCode = scr->instrContent[scr->pc].opOperand16.opCode;
        K_ASSERT(opCode >= 0, 987);
        K_ASSERT(opCode < SCR_CODEFUNC_MAX, 988);

        codeFuncRet = D_0063E2B0[opCode](scr);

        if (codeFuncRet == CODEFUNC_STOP)
        {
            scr->cmdTimer = 0;

            return SCRTRACE_STOP;
        }

        if (codeFuncRet != CODEFUNC_YIELD)
        {
            if (codeFuncRet == CODEFUNC_NEXTINSTR)
            {
                scr->cmdTimer = 0;
                continue;
            }
        }
        else
        {
            scr->cmdTimer++;
            scr->timer++;

            return SCRTRACE_YIELD;
        }
    }
}

// FUN_0029CC00
s32 func_0029cc00(s32 paramIdx)
{
    s32 paramSP;
    f32* f;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1041);

    switch (sCurrScript->stackTypes[paramSP])
    {
        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case SCR_STACK_TYPE_ADDR:    return sCurrScript->stackValues[paramSP].iVal;
        case SCR_STACK_TYPE_FLOAT:   return (s32)sCurrScript->stackValues[paramSP].fVal;

        case 2: return D_00882AD0[sCurrScript->stackValues[paramSP].iVal];
        case 3:
            f = &D_008826D0[sCurrScript->stackValues[paramSP].iVal];
            return (s32)*f;
    }

    K_ABORT(D_0063E340, 1054);

    return 0;
}

// FUN_0029CD50
f32 func_0029cd50(s32 paramIdx)
{
    s32 paramSP;
    f32* f;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1073);

    switch (sCurrScript->stackTypes[paramSP])
    {
        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case SCR_STACK_TYPE_ADDR:    return (f32)sCurrScript->stackValues[paramSP].iVal;
        case SCR_STACK_TYPE_FLOAT:   return sCurrScript->stackValues[paramSP].fVal;

        case 2: return (f32)D_00882AD0[sCurrScript->stackValues[paramSP].iVal];
        case 3:
            f = &D_008826D0[sCurrScript->stackValues[paramSP].iVal];
            return *f;
    }

    K_ABORT(D_0063E370, 1086);

    return 0.0f;
}

// FUN_0029CE90
char* func_0029ce90(s32 paramIdx)
{
    s32 paramSP;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1103);

    switch (sCurrScript->stackTypes[paramSP])
    {
        case SCR_STACK_TYPE_STRING:
            return sCurrScript->stackValues[paramSP].strVal;

        case SCR_STACK_TYPE_INTEGER: // fallthrough
        case SCR_STACK_TYPE_FLOAT:   // fallthrough
        case 2:                      // fallthrough
        case 3:                      // fallthrough
        case SCR_STACK_TYPE_ADDR:    // fallthrough
        default:
            K_ABORT(D_0063E3A0, 1114);
            return NULL;
    }
}

// FUN_0029CF50. Set 'retType' of the current script to int and set 'iVal' to 'retVal'
void func_0029cf50(s32 retVal)
{
    sCurrScript->stackTypes[SCR_STACK_RET] = SCR_STACK_TYPE_INTEGER;
    sCurrScript->stackValues[SCR_STACK_RET].iVal = retVal;
}

// FUN_0029CF70. Set 'retType' of the current script to float and set 'fVal' to 'retVal'
void func_0029cf70(f32 retVal)
{
    sCurrScript->stackTypes[SCR_STACK_RET] = SCR_STACK_TYPE_FLOAT;
    sCurrScript->stackValues[SCR_STACK_RET].fVal = retVal;
}

// FUN_0029CF90
u32 func_0029cf90(s32 lblIdx)
{
    K_ASSERT(lblIdx >= 0, 1165);
    K_ASSERT(lblIdx < sCurrScript->entries[SCR_CONTENT_TYPE_LABEL].elementCount, 1166);

    return sCurrScript->labelsContent[lblIdx].addr;
}
