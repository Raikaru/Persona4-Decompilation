.section .text
.set noat
.set noreorder
glabel func_0050cc78
    /* 40CC78 0050CC78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40CC7C 0050CC7C 0000B0FF */  sd         $16, 0x0($29)
    /* 40CC80 0050CC80 2D80A000 */  daddu      $16, $5, $0
    /* 40CC84 0050CC84 1000B2FF */  sd         $18, 0x10($29)
    /* 40CC88 0050CC88 2D908000 */  daddu      $18, $4, $0
    /* 40CC8C 0050CC8C 09000424 */  addiu      $4, $0, 0x9
    /* 40CC90 0050CC90 0800B1FF */  sd         $17, 0x8($29)
    /* 40CC94 0050CC94 1800BFFF */  sd         $31, 0x18($29)
    /* 40CC98 0050CC98 D463100C */  jal        func_00418f50
    /* 40CC9C 0050CC9C 2D88C000 */   daddu     $17, $6, $0
    /* 40CCA0 0050CCA0 0F000426 */  addiu      $4, $16, 0xF
    /* 40CCA4 0050CCA4 0000032A */  slti       $3, $16, 0x0
    /* 40CCA8 0050CCA8 800051AC */  sw         $17, 0x80($2)
    /* 40CCAC 0050CCAC 0B808300 */  movn       $16, $4, $3
    /* 40CCB0 0050CCB0 2D204000 */  daddu      $4, $2, $0
    /* 40CCB4 0050CCB4 2D284002 */  daddu      $5, $18, $0
    /* 40CCB8 0050CCB8 BA64100C */  jal        func_004192e8
    /* 40CCBC 0050CCBC 03311000 */   sra       $6, $16, 4
    /* 40CCC0 0050CCC0 2D100000 */  daddu      $2, $0, $0
    /* 40CCC4 0050CCC4 0000B0DF */  ld         $16, 0x0($29)
    /* 40CCC8 0050CCC8 0800B1DF */  ld         $17, 0x8($29)
    /* 40CCCC 0050CCCC 1000B2DF */  ld         $18, 0x10($29)
    /* 40CCD0 0050CCD0 1800BFDF */  ld         $31, 0x18($29)
    /* 40CCD4 0050CCD4 0800E003 */  jr         $31
    /* 40CCD8 0050CCD8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40CCDC 0050CCDC 00000000 */  nop
.size func_0050cc78, 0x68
