/* Source unit: src/Script/scrTraceCode_0029ad20.c */
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "scr_data_internal.h"

/* ------------------------------------------------------------------ */
/* Types                                                               */


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

/* Count-column alias: each next count follows one command-list pointer. */
typedef struct ScrCmdGroupCount {
    s32 count;
    ScrCmdEntry *nextCommands;
} ScrCmdGroupCount;

typedef u32 (*CodeFunc)(ScrScriptWork* scr);

/* Opcode indices into D_0063E2B0 (sCodeFuncTable). Verified against docs/dispatch_tables.md. */
enum ScrOpcode
{
    SCR_OPCODE_PUSH_IMM_INT,          /* scrOpPushImmInt */
    SCR_OPCODE_PUSH_IMM_FLOAT,        /* scrOpPushImmFloat */
    SCR_OPCODE_PUSH_GLOBAL_INT,       /* scrOpPushGlobalInt */
    SCR_OPCODE_PUSH_GLOBAL_FLOAT,     /* scrOpPushGlobalFloat */
    SCR_OPCODE_PUSH_RETURN,           /* scrOpPushReturn */
    SCR_OPCODE_POP_GLOBAL_INT,        /* scrOpPopGlobalInt */
    SCR_OPCODE_POP_GLOBAL_FLOAT,      /* scrOpPopGlobalFloat */
    SCR_OPCODE_NOP,                   /* scrOpNop */
    SCR_OPCODE_CALL_COMMAND,          /* scrOpCallCommand (COMM) */
    SCR_OPCODE_RETURN,                /* scrOpReturn */
    SCR_OPCODE_JUMP_PROCEDURE,        /* scrOpJumpProcedure */
    SCR_OPCODE_CALL_PROCEDURE,        /* scrOpCallProcedure */
    SCR_OPCODE_UNSUPPORTED,           /* scrOpUnsupported */
    SCR_OPCODE_JUMP_LABEL,            /* scrOpJumpLabel */
    SCR_OPCODE_ADD,                   /* CodeFunc_Add */
    SCR_OPCODE_SUB,                   /* CodeFunc_Sub */
    SCR_OPCODE_MUL,                   /* CodeFunc_Mul */
    SCR_OPCODE_DIV,                   /* CodeFunc_Div */
    SCR_OPCODE_NEG,                   /* CodeFunc_Neg */
    SCR_OPCODE_NOT,                   /* CodeFunc_Not */
    SCR_OPCODE_OR,                    /* CodeFunc_Or */
    SCR_OPCODE_AND,                   /* CodeFunc_And */
    SCR_OPCODE_EQ,                    /* CodeFunc_Eq */
    SCR_OPCODE_NEQ,                   /* CodeFunc_Neq */
    SCR_OPCODE_S,                     /* CodeFunc_S */
    SCR_OPCODE_L,                     /* CodeFunc_L */
    SCR_OPCODE_SE,                    /* CodeFunc_SE */
    SCR_OPCODE_LE,                    /* CodeFunc_LE */
    SCR_OPCODE_JUMP_IF_FALSE,         /* CodeFunc_JumpIfFalse */
    SCR_OPCODE_PUSH_IMM_SHORT,        /* scrOpPushImmShort */
    SCR_OPCODE_PUSH_LOCAL_INT,        /* scrOpPushLocalInt */
    SCR_OPCODE_PUSH_LOCAL_FLOAT,      /* scrOpPushLocalFloat */
    SCR_OPCODE_POP_LOCAL_INT,         /* scrOpPopLocalInt */
    SCR_OPCODE_POP_LOCAL_FLOAT,       /* scrOpPopLocalFloat */
    SCR_OPCODE_PUSH_STRING,           /* scrOpPushString */
    SCR_OPCODE_COUNT                  /* SCR_CODEFUNC_MAX */
};

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


#define SCR_STACK_RET 47
#define SCR_CODEFUNC_MAX 35

/* Script return codes, one set for the whole interpreter (used by scrRunCodeLoop and scrOpCallCommand).
 * CODEFUNC_*: returned by a codefunc (an entry of D_0063E2B0) to scrRunCodeLoop.
 *   CODEFUNC_STOP (0): end of script, from scrOpReturn with an empty stack. Has a return site.
 *   CODEFUNC_NEXTINSTR (1): advance to the next instruction. Most codefuncs return it.
 *   CODEFUNC_YIELD (2): the command has not finished, from scrOpCallCommand when the command returns 0.
 *   Any other value re-dispatches the same instruction.
 * SCRTRACE_*: returned by scrRunCodeLoop to scrScriptProcess.
 *   SCRTRACE_YIELD (1): from CODEFUNC_YIELD.
 *   SCRTRACE_STOP (2): from CODEFUNC_STOP.
 *   Value 0 is never returned by scrRunCodeLoop, so scrScriptProcess's case 0 and default are unreachable (case 0 is kept for the matched assert).
 * All three CODEFUNC_* codes have a return site. */
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
extern ScrCmdGroupCount D_00748534[];

extern CodeFunc D_0063E2B0[]; /* sCodeFuncTable */

void kAssertFailMsg(const char* file, s32 line, const char* msg, s32 value);
void kAssertFail(const char* file, s32 line);
void kAssertFailAt(const void *msg, const void *file, u32 line);

#define K_ASSERT(condition, line) \
    if (!(condition)) { kAssertFail(D_0063E068, (line)); }
#define K_ASSERT_MSG(condition, line, msg, value) \
    if (!(condition)) { kAssertFailMsg(D_0063E068, (line), (msg), (value)); }
#define K_ABORT(msg, line) \
    kAssertFailAt((msg), D_0063E068, (line))

/* ------------------------------------------------------------------ */
/* Statics                                                             */

static ScrScriptWork* sCurrScript; // 00764600. Current script being executed

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

static inline void PushInt(ScrScriptWork* scr, s32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 73, D_0063E080, scr->sp);

    scr->valueTypes[scr->sp] = SCR_STACK_TYPE_INTEGER;
    scr->stackValues[scr->sp].iVal = val;
    scr->sp++;
}

static inline void PushFloat(ScrScriptWork* scr, f32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 85, D_0063E080, scr->sp);

    scr->valueTypes[scr->sp] = SCR_STACK_TYPE_FLOAT;
    scr->stackValues[scr->sp].fVal = val;
    scr->sp++;
}

static inline void PushString(ScrScriptWork* scr, char* str)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 99, D_0063E080, scr->sp);

    scr->valueTypes[scr->sp] = SCR_STACK_TYPE_STRING;
    scr->stackValues[scr->sp].strVal = str;
    scr->sp++;
}

static inline void PushPC(ScrScriptWork* scr, s32 val)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 141, D_0063E080, scr->sp);

    scr->valueTypes[scr->sp] = SCR_STACK_TYPE_ADDR;
    scr->stackValues[scr->sp].iVal = val;
    scr->sp++;
}

static inline s32 PopInt(ScrScriptWork* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 152);

    sp = --scr->sp;

    switch (scr->valueTypes[sp])
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

static inline f32 PopFloat(ScrScriptWork* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 176);

    sp = --scr->sp;

    switch (scr->valueTypes[sp])
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
u32 scrOpPushImmInt(ScrScriptWork* scr)
{
    PushInt(scr, scr->instrContent[++scr->pc].iOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A100. Push an immediate short value
u32 scrOpPushImmShort(ScrScriptWork* scr)
{
    PushInt(scr, scr->instrContent[scr->pc].opOperand16.sOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A1B0. Push an immediate float value
u32 scrOpPushImmFloat(ScrScriptWork* scr)
{
    PushFloat(scr, scr->instrContent[++scr->pc].fOperand);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A260. Push an int from the VM memory
u32 scrOpPushGlobalInt(ScrScriptWork* scr)
{
    PushInt(scr, D_00882AD0[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A320. Push a float from the VM memory
u32 scrOpPushGlobalFloat(ScrScriptWork* scr)
{
    f32* f;

    f = &D_008826D0[scr->instrContent[scr->pc].opOperand16.sOperand];
    PushFloat(scr, *f);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A3E0. Push an int from the local ints
u32 scrOpPushLocalInt(ScrScriptWork* scr)
{
    PushInt(scr, scr->localInt[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A4A0. Push a float from the local floats
u32 scrOpPushLocalFloat(ScrScriptWork* scr)
{
    PushFloat(scr, scr->localFloat[scr->instrContent[scr->pc].opOperand16.sOperand]);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A560. Push a string
u32 scrOpPushString(ScrScriptWork* scr)
{
    char* str;

    str = scr->stringsContent;
    str += scr->instrContent[scr->pc].opOperand16.sOperand;
    PushString(scr, str);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A610. Push return value
u32 scrOpPushReturn(ScrScriptWork* scr)
{
    K_ASSERT_MSG(scr->sp < SCR_STACK_RET, 298, D_0063E080, scr->sp);

    scr->valueTypes[scr->sp] = scr->valueTypes[SCR_STACK_RET];
    scr->stackValues[scr->sp] = scr->stackValues[SCR_STACK_RET];
    scr->sp++;

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A6A0. Pop an int into the VM memory
u32 scrOpPopGlobalInt(ScrScriptWork* scr)
{
    D_00882AD0[scr->instrContent[scr->pc].opOperand16.sOperand] = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029A820. Pop a float into the VM memory
u32 scrOpPopGlobalFloat(ScrScriptWork* scr)
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
u32 scrOpPopLocalInt(ScrScriptWork* scr)
{
    K_ASSERT_MSG(scr->instrContent[scr->pc].opOperand16.sOperand < scr->scrHeader->localIntNum, 336, D_0063E130, scr->instrContent[scr->pc].opOperand16.sOperand);

    scr->localInt[scr->instrContent[scr->pc].opOperand16.sOperand] = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029AB80. Pop a float into a local float
u32 scrOpPopLocalFloat(ScrScriptWork* scr)
{
    scr->localFloat[scr->instrContent[scr->pc].opOperand16.sOperand] = PopFloat(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}




/* Advance the program counter without changing the interpreter stack. */
// FUN_0029AD20
u32 scrOpNop(ScrScriptWork* scr)
{
    scr->pc++;

    return 1;
}

/* measured: opt_common_subs off is required for the exact object. */
#pragma opt_common_subs off
/* measured: optimization_level 1 is required for the exact object. Saved-local
   declaration order, the reversed range-guard operands, and the integer-domain
   second command-pointer sum reproduce retail register coloring and operand order. */
#pragma optimization_level 1
// FUN_0029AD40
// Command call (ScrOperation call-command codefunc). The operand packs a command id:
//   bits 12..19 select the group in D_00748530 (ScrCmdGroup, 8 bytes; byte offset = group << 3),
//   bits 0..11 select the command in that group (ScrCmdEntry, 8 bytes; byte offset = index << 3).
// The command runs with sCurrScript = ctx. If it returns 0 the codefunc returns CODEFUNC_YIELD
// and the same instruction runs again. Otherwise the command's paramCount arguments are popped,
// and pc advances unless the command already moved it. Returns CODEFUNC_NEXTINSTR.
u32 scrOpCallCommand(u8 *context)
{
    ScrScriptWork *ctx;
    s32 groupOffset;   /* byte offset of the group entry: ((cmdId >> 12) & 0xFF) << 3 */
    s32 cmdId;         /* packed id; the low 12 bits become the command index */
    s32 result;
    s32 cmdOffset;     /* byte offset of the command entry: index << 3 */
    ScrCmdEntry *cmds;
    ScrCmdEntry *entry;
    s32 prevPc;
    s32 currPc;
    s32 hasFunc;

    ctx = (ScrScriptWork *)context;
    cmdId = ctx->instrContent[ctx->pc].opOperand16.sOperand;
    K_ASSERT(cmdId >= 0, 0x175);
    groupOffset = ((cmdId >> 12) & 0xFF) << 3;
    cmdId &= 0xFFF;
    /* Linker interior alias: the count field (+4) of D_00748530[group]; preserve its zero-displacement load. */
    K_ASSERT(((ScrCmdGroupCount *)((u8 *)D_00748534 + groupOffset))->count > cmdId, 0x176);
    cmdOffset = cmdId << 3;
    cmds = ((ScrCmdGroup *)((u8 *)D_00748530 + groupOffset))->cmds;
    entry = (ScrCmdEntry *)((u8 *)cmds + cmdOffset);
    hasFunc = (entry->func != 0);
    K_ASSERT(hasFunc != 0, 0x177);
    prevPc = ctx->pc;
    sCurrScript = ctx;
    result = entry->func();
    if (result == 0) {
        return CODEFUNC_YIELD;
    }
    /* integer-domain sum: keeps the second command-pointer computation of the retail object */
    entry = (ScrCmdEntry *)((u8 *)((u32)cmdOffset + (u32)cmds));
    ctx->sp -= entry->paramCount;
    currPc = ctx->pc;
    if (prevPc == currPc) {
        currPc++;
        ctx->pc = currPc;
    }
    return CODEFUNC_NEXTINSTR;
}
/* measured: restores the default optimization level after the exact object. */
#pragma optimization_level 2
/* measured: restores common-subexpression optimization after the exact object. */
#pragma opt_common_subs on



// FUN_0029AE90
u32 scrOpReturn(ScrScriptWork* scr)
{
    if (scr->sp == 0)
    {
        return CODEFUNC_STOP;
    }

    K_ASSERT(scr->valueTypes[scr->sp - 1] == SCR_STACK_TYPE_ADDR, 471);

    scr->pc = PopInt(scr);
    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B020. Jump to a procedure
u32 scrOpJumpProcedure(ScrScriptWork* scr)
{
    s16 prcdIdx;

    prcdIdx = scr->instrContent[scr->pc].opOperand16.sOperand;
    scr->pc = scr->proceduresContent[prcdIdx].addr;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B060. Call a procedure + push PC
u32 scrOpCallProcedure(ScrScriptWork* scr)
{
    PushPC(scr, scr->pc);
    scr->pc = scr->proceduresContent[scr->instrContent[scr->pc].opOperand16.sOperand].addr;

    return CODEFUNC_NEXTINSTR;
}

/* Report an unsupported instruction through the script abort diagnostic, then advance if it returns. */
// FUN_0029B120
u32 scrOpUnsupported(ScrScriptWork* scr)
{
    K_ABORT(D_0063E160, 506);

    scr->pc++;

    return CODEFUNC_NEXTINSTR;
}

// FUN_0029B170. Jump to a label
u32 scrOpJumpLabel(ScrScriptWork* scr)
{
    s16 lblIdx;

    lblIdx = scr->instrContent[scr->pc].opOperand16.sOperand;
    scr->pc = scr->labelsContent[lblIdx].addr;

    return CODEFUNC_NEXTINSTR;
}

// Shared binary operator: pops the two operands, promotes them to int or float by their stack types, and pushes the result for operation type (add, sub, mul, div, comparisons, and/or).
// FUN_0029B1B0
void scrBinaryOp(ScrScriptWork* scr, u32 type)
{
    s32 sp;

    K_ASSERT(scr->sp >= 2, 531);

    sp = scr->sp;
    sOpLeftType = scr->valueTypes[sp - 1];
    sOpRightType = scr->valueTypes[sp - 2];

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




/* Pop two numeric operands, push their sum with integer/float promotion, and advance execution. */
// FUN_0029BEB0
u32 CodeFunc_Add(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_ADD);
    scr->pc++;

    return 1;
}



/* Pop the left operand first, subtract the next numeric operand, and push the promoted result. */
// FUN_0029BEF0
u32 CodeFunc_Sub(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_SUB);
    scr->pc++;

    return 1;
}



// Multiplies the top two stack values (CodeFunc_Mul).
// FUN_0029BF30
u32 CodeFunc_Mul(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_MUL);
    scr->pc++;

    return 1;
}



/* Divide the first popped numeric operand by the second; the shared operator asserts a nonzero divisor. */
// FUN_0029BF70
u32 CodeFunc_Div(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_DIV);
    scr->pc++;

    return 1;
}

// Negates the top stack value in place, by its type (int, float, or the global int/float tables) (CodeFunc_Neg).
// FUN_0029BFB0
u32 CodeFunc_Neg(ScrScriptWork* scr)
{
    s32 sp;
    f32* f;

    K_ASSERT(scr->sp > 0, 732);

    sp = scr->sp;
    switch (scr->valueTypes[sp - 1])
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

// Replaces the top stack value with 1 when it is zero, else 0 (CodeFunc_Not).
// FUN_0029C130
u32 CodeFunc_Not(ScrScriptWork* scr)
{
    u32 res;

    K_ASSERT(scr->sp > 0, 767);

    switch (scr->valueTypes[scr->sp - 1])
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




/* Consume both numeric operands and push integer truth for logical OR, without short-circuiting their pops. */
// FUN_0029C550
u32 CodeFunc_Or(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_OR);
    scr->pc++;

    return 1;
}



/* Consume both numeric operands and push integer truth for logical AND, without short-circuiting their pops. */
// FUN_0029C590
u32 CodeFunc_And(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_AND);
    scr->pc++;

    return 1;
}



/* Compare the two popped numeric operands for equality and push integer truth before advancing execution. */
// FUN_0029C5D0
u32 CodeFunc_Eq(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_EQ);
    scr->pc++;

    return 1;
}



/* Compare the two popped numeric operands for inequality and push integer truth before advancing execution. */
// FUN_0029C610
u32 CodeFunc_Neq(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_NEQ);
    scr->pc++;

    return 1;
}



/* Push integer truth when the first popped numeric operand is less than the second, then advance. */
// FUN_0029C650
u32 CodeFunc_S(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_S);
    scr->pc++;

    return 1;
}



/* Push integer truth when the first popped numeric operand is greater than the second, then advance. */
// FUN_0029C690
u32 CodeFunc_L(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_L);
    scr->pc++;

    return 1;
}



/* Push integer truth when the first popped numeric operand is at most the second, then advance. */
// FUN_0029C6D0
u32 CodeFunc_SE(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_SE);
    scr->pc++;

    return 1;
}



/* Push integer truth when the first popped numeric operand is at least the second, then advance. */
// FUN_0029C710
u32 CodeFunc_LE(ScrScriptWork* scr)
{
    scrBinaryOp(scr, SCR_OPERATION_LE);
    scr->pc++;

    return 1;
}

// Pops the top value; when it is zero, jumps to the label named by the instruction operand, else falls through (CodeFunc_JumpIfFalse) [inferred].
// FUN_0029C750
u32 CodeFunc_JumpIfFalse(ScrScriptWork* scr)
{
    u32 res;

    K_ASSERT(scr->sp > 0, 894);

    switch (scr->valueTypes[scr->sp - 1])
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

// Interpreter loop (scrRunCodeLoop): dispatches the codefunc of the current instruction.
// CODEFUNC_NEXTINSTR clears cmdTimer and dispatches the next instruction. CODEFUNC_STOP clears
// cmdTimer and returns SCRTRACE_STOP. CODEFUNC_YIELD bumps cmdTimer and timer and returns
// SCRTRACE_YIELD. Any other return value re-dispatches the same instruction.
// FUN_0029CB00
u32 scrRunCodeLoop(ScrScriptWork* scr)
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

// Script parameter: reads paramIdx as an integer (float, address and table values are converted).
// FUN_0029CC00
s32 scrGetParamInt(s32 paramIdx)
{
    s32 paramSP;
    f32* f;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1041);

    switch (sCurrScript->valueTypes[paramSP])
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

// Script parameter: reads paramIdx as a float.
// FUN_0029CD50
f32 scrGetParamFloat(s32 paramIdx)
{
    s32 paramSP;
    f32* f;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1073);

    switch (sCurrScript->valueTypes[paramSP])
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

// Script parameter: returns the string at paramIdx; aborts on any other stack type.
// FUN_0029CE90
char* scrGetParamString(s32 paramIdx)
{
    s32 paramSP;

    paramSP = sCurrScript->sp - (paramIdx + 1);
    K_ASSERT((paramIdx + 1) <= sCurrScript->sp, 1103);

    switch (sCurrScript->valueTypes[paramSP])
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

// Script return slot: stores an integer result and sets the int return type.
// FUN_0029CF50. Set 'retType' of the current script to int and set 'iVal' to 'retVal'
void scrSetReturnInt(s32 retVal)
{
    sCurrScript->valueTypes[SCR_STACK_RET] = SCR_STACK_TYPE_INTEGER;
    sCurrScript->stackValues[SCR_STACK_RET].iVal = retVal;
}

// Script return slot: stores a float result and sets the float return type.
// FUN_0029CF70. Set 'retType' of the current script to float and set 'fVal' to 'retVal'
void scrSetReturnFloat(f32 retVal)
{
    sCurrScript->valueTypes[SCR_STACK_RET] = SCR_STACK_TYPE_FLOAT;
    sCurrScript->stackValues[SCR_STACK_RET].fVal = retVal;
}

// Script label table: returns the code address of label lblIdx (P3FES twin: scrGetLabelAddr).
// FUN_0029CF90
u32 scrGetLabelAddr(s32 lblIdx)
{
    K_ASSERT(lblIdx >= 0, 1165);
    K_ASSERT(lblIdx < sCurrScript->contentEntries[SCR_CONTENT_TYPE_LABEL].elementCount, 1166);

    return sCurrScript->labelsContent[lblIdx].addr;
}
