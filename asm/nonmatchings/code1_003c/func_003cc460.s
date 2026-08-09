.section .text
.set noat
.set noreorder
glabel func_003cc460
    /* 2CC460 003CC460 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CC464 003CC464 2D200000 */  daddu      $4, $0, $0
    /* 2CC468 003CC468 0000BFFF */  sd         $31, 0x0($29)
    /* 2CC46C 003CC46C AC42100C */  jal        func_00410ab0
    /* 2CC470 003CC470 02000524 */   addiu     $5, $0, 0x2
    /* 2CC474 003CC474 2D200000 */  daddu      $4, $0, $0
    /* 2CC478 003CC478 AC42100C */  jal        func_00410ab0
    /* 2CC47C 003CC47C 01000524 */   addiu     $5, $0, 0x1
    /* 2CC480 003CC480 2D200000 */  daddu      $4, $0, $0
    /* 2CC484 003CC484 AC42100C */  jal        func_00410ab0
    /* 2CC488 003CC488 04000524 */   addiu     $5, $0, 0x4
    /* 2CC48C 003CC48C 2D200000 */  daddu      $4, $0, $0
    /* 2CC490 003CC490 AC42100C */  jal        func_00410ab0
    /* 2CC494 003CC494 05000524 */   addiu     $5, $0, 0x5
    /* 2CC498 003CC498 2D200000 */  daddu      $4, $0, $0
    /* 2CC49C 003CC49C AC42100C */  jal        func_00410ab0
    /* 2CC4A0 003CC4A0 03000524 */   addiu     $5, $0, 0x3
    /* 2CC4A4 003CC4A4 9042100C */  jal        func_00410a40
    /* 2CC4A8 003CC4A8 2D200000 */   daddu     $4, $0, $0
    /* 2CC4AC 003CC4AC B0B9838F */  lw         $3, -0x4650($28)
    /* 2CC4B0 003CC4B0 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CC4B4 003CC4B4 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CC4B8 003CC4B8 21104300 */  addu       $2, $2, $3
    /* 2CC4BC 003CC4BC 3C0040AC */  sw         $0, 0x3C($2)
    /* 2CC4C0 003CC4C0 380040AC */  sw         $0, 0x38($2)
    /* 2CC4C4 003CC4C4 300040AC */  sw         $0, 0x30($2)
    /* 2CC4C8 003CC4C8 2C0040AC */  sw         $0, 0x2C($2)
    /* 2CC4CC 003CC4CC 240040AC */  sw         $0, 0x24($2)
    /* 2CC4D0 003CC4D0 280040AC */  sw         $0, 0x28($2)
    /* 2CC4D4 003CC4D4 200040AC */  sw         $0, 0x20($2)
    /* 2CC4D8 003CC4D8 9C45100C */  jal        func_00411670
    /* 2CC4DC 003CC4DC 1C00448C */   lw        $4, 0x1C($2)
    /* 2CC4E0 003CC4E0 B0B9848F */  lw         $4, -0x4650($28)
    /* 2CC4E4 003CC4E4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CC4E8 003CC4E8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CC4EC 003CC4EC 21186400 */  addu       $3, $3, $4
    /* 2CC4F0 003CC4F0 1C0060AC */  sw         $0, 0x1C($3)
    /* 2CC4F4 003CC4F4 0000BFDF */  ld         $31, 0x0($29)
    /* 2CC4F8 003CC4F8 0800E003 */  jr         $31
    /* 2CC4FC 003CC4FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_003cc460, 0xa0
