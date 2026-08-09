.section .text
.set noat
.set noreorder
glabel func_00422c18
    /* 322C18 00422C18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322C1C 00422C1C 2D10A000 */  daddu      $2, $5, $0
    /* 322C20 00422C20 FFFFC630 */  andi       $6, $6, 0xFFFF
    /* 322C24 00422C24 0000A4AF */  sw         $4, 0x0($29)
    /* 322C28 00422C28 1000BFFF */  sd         $31, 0x10($29)
    /* 322C2C 00422C2C 2D28A003 */  daddu      $5, $29, $0
    /* 322C30 00422C30 0400A2AF */  sw         $2, 0x4($29)
    /* 322C34 00422C34 FAFF0424 */  addiu      $4, $0, -0x6
    /* 322C38 00422C38 0487100C */  jal        func_00421c10
    /* 322C3C 00422C3C 0800A6AF */   sw        $6, 0x8($29)
    /* 322C40 00422C40 1000BFDF */  ld         $31, 0x10($29)
    /* 322C44 00422C44 0800E003 */  jr         $31
    /* 322C48 00422C48 2000BD27 */   addiu     $29, $29, 0x20
    /* 322C4C 00422C4C 00000000 */  nop
.size func_00422c18, 0x38
