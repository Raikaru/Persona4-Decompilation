.section .text
.set noat
.set noreorder
glabel func_00422b88
    /* 322B88 00422B88 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 322B8C 00422B8C FF008430 */  andi       $4, $4, 0xFF
    /* 322B90 00422B90 0400A5AF */  sw         $5, 0x4($29)
    /* 322B94 00422B94 0000A4AF */  sw         $4, 0x0($29)
    /* 322B98 00422B98 2D28A003 */  daddu      $5, $29, $0
    /* 322B9C 00422B9C 2000BFFF */  sd         $31, 0x20($29)
    /* 322BA0 00422BA0 20000424 */  addiu      $4, $0, 0x20
    /* 322BA4 00422BA4 0487100C */  jal        func_00421c10
    /* 322BA8 00422BA8 0800A6AF */   sw        $6, 0x8($29)
    /* 322BAC 00422BAC 2000BFDF */  ld         $31, 0x20($29)
    /* 322BB0 00422BB0 0800E003 */  jr         $31
    /* 322BB4 00422BB4 3000BD27 */   addiu     $29, $29, 0x30
.size func_00422b88, 0x30
