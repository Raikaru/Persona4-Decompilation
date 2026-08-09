.section .text
.set noat
.set noreorder
glabel func_00422be0
    /* 322BE0 00422BE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322BE4 00422BE4 2D10A000 */  daddu      $2, $5, $0
    /* 322BE8 00422BE8 FFFFC630 */  andi       $6, $6, 0xFFFF
    /* 322BEC 00422BEC 0000A4AF */  sw         $4, 0x0($29)
    /* 322BF0 00422BF0 1000BFFF */  sd         $31, 0x10($29)
    /* 322BF4 00422BF4 2D28A003 */  daddu      $5, $29, $0
    /* 322BF8 00422BF8 0400A2AF */  sw         $2, 0x4($29)
    /* 322BFC 00422BFC FBFF0424 */  addiu      $4, $0, -0x5
    /* 322C00 00422C00 0487100C */  jal        func_00421c10
    /* 322C04 00422C04 0800A6AF */   sw        $6, 0x8($29)
    /* 322C08 00422C08 1000BFDF */  ld         $31, 0x10($29)
    /* 322C0C 00422C0C 0800E003 */  jr         $31
    /* 322C10 00422C10 2000BD27 */   addiu     $29, $29, 0x20
    /* 322C14 00422C14 00000000 */  nop
.size func_00422be0, 0x38
