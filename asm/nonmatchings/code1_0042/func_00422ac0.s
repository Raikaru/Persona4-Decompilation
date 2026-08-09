.section .text
.set noat
.set noreorder
glabel func_00422ac0
    /* 322AC0 00422AC0 8900023C */  lui        $2, %hi(D_0088D790)
    /* 322AC4 00422AC4 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322AC8 00422AC8 0020033C */  lui        $3, (0x20000000 >> 16)
    /* 322ACC 00422ACC 90D74224 */  addiu      $2, $2, %lo(D_0088D790)
    /* 322AD0 00422AD0 FFFF8430 */  andi       $4, $4, 0xFFFF
    /* 322AD4 00422AD4 25104300 */  or         $2, $2, $3
    /* 322AD8 00422AD8 0400A5AF */  sw         $5, 0x4($29)
    /* 322ADC 00422ADC 0000A4AF */  sw         $4, 0x0($29)
    /* 322AE0 00422AE0 2D28A003 */  daddu      $5, $29, $0
    /* 322AE4 00422AE4 1000BFFF */  sd         $31, 0x10($29)
    /* 322AE8 00422AE8 01000424 */  addiu      $4, $0, 0x1
    /* 322AEC 00422AEC 0800A6AF */  sw         $6, 0x8($29)
    /* 322AF0 00422AF0 0487100C */  jal        func_00421c10
    /* 322AF4 00422AF4 0C00A2AF */   sw        $2, 0xC($29)
    /* 322AF8 00422AF8 1000BFDF */  ld         $31, 0x10($29)
    /* 322AFC 00422AFC 0800E003 */  jr         $31
    /* 322B00 00422B00 2000BD27 */   addiu     $29, $29, 0x20
    /* 322B04 00422B04 00000000 */  nop
.size func_00422ac0, 0x48
