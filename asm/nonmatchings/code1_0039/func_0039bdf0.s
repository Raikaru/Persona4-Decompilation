.section .text
.set noat
.set noreorder
glabel func_0039bdf0
    /* 29BDF0 0039BDF0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 29BDF4 0039BDF4 3000BFFF */  sd         $31, 0x30($29)
    /* 29BDF8 0039BDF8 2000B27F */  sq         $18, 0x20($29)
    /* 29BDFC 0039BDFC 1000B17F */  sq         $17, 0x10($29)
    /* 29BE00 0039BE00 2D908000 */  daddu      $18, $4, $0
    /* 29BE04 0039BE04 7445100C */  jal        func_004115d0
    /* 29BE08 0039BE08 0000B07F */   sq        $16, 0x0($29)
    /* 29BE0C 0039BE0C 0000438E */  lw         $3, 0x0($18)
    /* 29BE10 0039BE10 2D884000 */  daddu      $17, $2, $0
    /* 29BE14 0039BE14 2D202002 */  daddu      $4, $17, $0
    /* 29BE18 0039BE18 2C0043AC */  sw         $3, 0x2C($2)
    /* 29BE1C 0039BE1C 0400438E */  lw         $3, 0x4($18)
    /* 29BE20 0039BE20 284B100C */  jal        func_00412ca0
    /* 29BE24 0039BE24 300043AC */   sw        $3, 0x30($2)
    /* 29BE28 0039BE28 9C3E0F0C */  jal        func_003cfa70
    /* 29BE2C 0039BE2C 2D804000 */   daddu     $16, $2, $0
    /* 29BE30 0039BE30 2D200002 */  daddu      $4, $16, $0
    /* 29BE34 0039BE34 2D280000 */  daddu      $5, $0, $0
    /* 29BE38 0039BE38 2D804000 */  daddu      $16, $2, $0
    /* 29BE3C 0039BE3C 2D380000 */  daddu      $7, $0, $0
    /* 29BE40 0039BE40 EC4B100C */  jal        func_00412fb0
    /* 29BE44 0039BE44 2D300002 */   daddu     $6, $16, $0
    /* 29BE48 0039BE48 7849100C */  jal        func_004125e0
    /* 29BE4C 0039BE4C 2D204000 */   daddu     $4, $2, $0
    /* 29BE50 0039BE50 0000058E */  lw         $5, 0x0($16)
    /* 29BE54 0039BE54 2D204000 */  daddu      $4, $2, $0
    /* 29BE58 0039BE58 2D300000 */  daddu      $6, $0, $0
    /* 29BE5C 0039BE5C A44B100C */  jal        func_00412e90
    /* 29BE60 0039BE60 2D380000 */   daddu     $7, $0, $0
    /* 29BE64 0039BE64 0800468E */  lw         $6, 0x8($18)
    /* 29BE68 0039BE68 2D204000 */  daddu      $4, $2, $0
    /* 29BE6C 0039BE6C 6C3E0F0C */  jal        func_003cf9b0
    /* 29BE70 0039BE70 01000524 */   addiu     $5, $0, 0x1
    /* 29BE74 0039BE74 0C00468E */  lw         $6, 0xC($18)
    /* 29BE78 0039BE78 2D204000 */  daddu      $4, $2, $0
    /* 29BE7C 0039BE7C 6C3E0F0C */  jal        func_003cf9b0
    /* 29BE80 0039BE80 02000524 */   addiu     $5, $0, 0x2
    /* 29BE84 0039BE84 1000458E */  lw         $5, 0x10($18)
    /* 29BE88 0039BE88 8C3E0F0C */  jal        func_003cfa30
    /* 29BE8C 0039BE8C 2D204000 */   daddu     $4, $2, $0
    /* 29BE90 0039BE90 2D102002 */  daddu      $2, $17, $0
    /* 29BE94 0039BE94 3000BFDF */  ld         $31, 0x30($29)
    /* 29BE98 0039BE98 2000B27B */  lq         $18, 0x20($29)
    /* 29BE9C 0039BE9C 1000B17B */  lq         $17, 0x10($29)
    /* 29BEA0 0039BEA0 0000B07B */  lq         $16, 0x0($29)
    /* 29BEA4 0039BEA4 0800E003 */  jr         $31
    /* 29BEA8 0039BEA8 4000BD27 */   addiu     $29, $29, 0x40
    /* 29BEAC 0039BEAC 00000000 */  nop
.size func_0039bdf0, 0xc0
