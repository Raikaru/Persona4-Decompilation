/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0029AD20)
/* Source unit: src/Script/scrTraceCode_0029ad20.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

// FUN_0029AD20
u32 func_0029AD20(ScrData* scr)
{
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029AD20 */

#if defined(P4_UNIT_0029BEB0)
/* Source unit: src/Script/scrTraceCode_0029beb0.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029BEB0
u32 func_0029BEB0(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_ADD);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029BEB0 */

#if defined(P4_UNIT_0029BEF0)
/* Source unit: src/Script/scrTraceCode_0029bef0.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029BEF0
u32 func_0029BEF0(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SUB);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029BEF0 */

#if defined(P4_UNIT_0029BF30)
/* Source unit: src/Script/scrTraceCode_0029bf30.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029BF30
u32 func_0029BF30(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_MUL);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029BF30 */

#if defined(P4_UNIT_0029BF70)
/* Source unit: src/Script/scrTraceCode_0029bf70.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029BF70
u32 func_0029BF70(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_DIV);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029BF70 */

#if defined(P4_UNIT_0029C550)
/* Source unit: src/Script/scrTraceCode_0029c550.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C550
u32 func_0029C550(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_OR);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C550 */

#if defined(P4_UNIT_0029C590)
/* Source unit: src/Script/scrTraceCode_0029c590.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C590
u32 func_0029C590(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_AND);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C590 */

#if defined(P4_UNIT_0029C5D0)
/* Source unit: src/Script/scrTraceCode_0029c5d0.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C5D0
u32 func_0029C5D0(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_EQ);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C5D0 */

#if defined(P4_UNIT_0029C610)
/* Source unit: src/Script/scrTraceCode_0029c610.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C610
u32 func_0029C610(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_NEQ);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C610 */

#if defined(P4_UNIT_0029C650)
/* Source unit: src/Script/scrTraceCode_0029c650.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C650
u32 func_0029C650(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_S);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C650 */

#if defined(P4_UNIT_0029C690)
/* Source unit: src/Script/scrTraceCode_0029c690.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C690
u32 func_0029C690(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_L);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C690 */

#if defined(P4_UNIT_0029C6D0)
/* Source unit: src/Script/scrTraceCode_0029c6d0.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C6D0
u32 func_0029C6D0(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SE);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C6D0 */

#if defined(P4_UNIT_0029C710)
/* Source unit: src/Script/scrTraceCode_0029c710.c */
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

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

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029C710
u32 func_0029C710(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_LE);
    scr->pc++;

    return 1;
}
#endif /* P4_UNIT_0029C710 */
