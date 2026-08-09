.section .text
.set noat
.set noreorder
glabel func_004beba0
    /* 3BEBA0 004BEBA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEBA4 004BEBA4 2D188000 */  daddu      $3, $4, $0
    /* 3BEBA8 004BEBA8 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEBAC 004BEBAC 2D38A000 */  daddu      $7, $5, $0
    /* 3BEBB0 004BEBB0 5000628C */  lw         $2, 0x50($3)
    /* 3BEBB4 004BEBB4 06004014 */  bnez       $2, .L004BEBD0
    /* 3BEBB8 004BEBB8 30006524 */   addiu     $5, $3, 0x30
    /* 3BEBBC 004BEBBC 7500043C */  lui        $4, %hi(D_00756E18)
    /* 3BEBC0 004BEBC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEBC4 004BEBC4 186E8424 */  addiu      $4, $4, %lo(D_00756E18)
    /* 3BEBC8 004BEBC8 A8F51208 */  j          func_004bd6a0
    /* 3BEBCC 004BEBCC 1000BD27 */   addiu     $29, $29, 0x10
  .L004BEBD0:
    /* 3BEBD0 004BEBD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEBD4 004BEBD4 03000224 */  addiu      $2, $0, 0x3
    /* 3BEBD8 004BEBD8 480067AC */  sw         $7, 0x48($3)
    /* 3BEBDC 004BEBDC 4C0066AC */  sw         $6, 0x4C($3)
    /* 3BEBE0 004BEBE0 300062AC */  sw         $2, 0x30($3)
    /* 3BEBE4 004BEBE4 28FF1208 */  j          func_004bfca0
    /* 3BEBE8 004BEBE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEBEC 004BEBEC 00000000 */  nop
.size func_004beba0, 0x50
