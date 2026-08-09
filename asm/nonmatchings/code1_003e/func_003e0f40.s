.section .text
.set noat
.set noreorder
glabel func_003e0f40
    /* 2E0F40 003E0F40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2E0F44 003E0F44 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E0F48 003E0F48 0000BFFF */  sd         $31, 0x0($29)
    /* 2E0F4C 003E0F4C 2D288000 */  daddu      $5, $4, $0
    /* 2E0F50 003E0F50 68B7848F */  lw         $4, -0x4898($28)
    /* 2E0F54 003E0F54 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E0F58 003E0F58 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2E0F5C 003E0F5C FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2E0F60 003E0F60 21186400 */  addu       $3, $3, $4
    /* 2E0F64 003E0F64 09F84000 */  jalr       $2
    /* 2E0F68 003E0F68 0000648C */   lw        $4, 0x0($3)
    /* 2E0F6C 003E0F6C 0000BFDF */  ld         $31, 0x0($29)
    /* 2E0F70 003E0F70 01000224 */  addiu      $2, $0, 0x1
    /* 2E0F74 003E0F74 0800E003 */  jr         $31
    /* 2E0F78 003E0F78 1000BD27 */   addiu     $29, $29, 0x10
    /* 2E0F7C 003E0F7C 00000000 */  nop
.size func_003e0f40, 0x40
