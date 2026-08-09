.section .text
.set noat
.set noreorder
glabel func_0050cba0
    /* 40CBA0 0050CBA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40CBA4 0050CBA4 0000B0FF */  sd         $16, 0x0($29)
    /* 40CBA8 0050CBA8 2D80A000 */  daddu      $16, $5, $0
    /* 40CBAC 0050CBAC 0800B1FF */  sd         $17, 0x8($29)
    /* 40CBB0 0050CBB0 2D888000 */  daddu      $17, $4, $0
    /* 40CBB4 0050CBB4 08000424 */  addiu      $4, $0, 0x8
    /* 40CBB8 0050CBB8 1000B2FF */  sd         $18, 0x10($29)
    /* 40CBBC 0050CBBC 1800BFFF */  sd         $31, 0x18($29)
    /* 40CBC0 0050CBC0 D463100C */  jal        func_00418f50
    /* 40CBC4 0050CBC4 2D90C000 */   daddu     $18, $6, $0
    /* 40CBC8 0050CBC8 0F000426 */  addiu      $4, $16, 0xF
    /* 40CBCC 0050CBCC 0000032A */  slti       $3, $16, 0x0
    /* 40CBD0 0050CBD0 800051AC */  sw         $17, 0x80($2)
    /* 40CBD4 0050CBD4 0B808300 */  movn       $16, $4, $3
    /* 40CBD8 0050CBD8 2D204000 */  daddu      $4, $2, $0
    /* 40CBDC 0050CBDC 2D284002 */  daddu      $5, $18, $0
    /* 40CBE0 0050CBE0 0865100C */  jal        func_00419420
    /* 40CBE4 0050CBE4 03311000 */   sra       $6, $16, 4
    /* 40CBE8 0050CBE8 2D100000 */  daddu      $2, $0, $0
    /* 40CBEC 0050CBEC 0000B0DF */  ld         $16, 0x0($29)
    /* 40CBF0 0050CBF0 0800B1DF */  ld         $17, 0x8($29)
    /* 40CBF4 0050CBF4 1000B2DF */  ld         $18, 0x10($29)
    /* 40CBF8 0050CBF8 1800BFDF */  ld         $31, 0x18($29)
    /* 40CBFC 0050CBFC 0800E003 */  jr         $31
    /* 40CC00 0050CC00 2000BD27 */   addiu     $29, $29, 0x20
    /* 40CC04 0050CC04 00000000 */  nop
.size func_0050cba0, 0x68
