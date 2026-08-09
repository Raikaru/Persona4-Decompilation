.section .text
.set noat
.set noreorder
glabel func_004df0c8
    /* 3DF0C8 004DF0C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF0CC 004DF0CC 06008014 */  bnez       $4, .L004DF0E8
    /* 3DF0D0 004DF0D0 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF0D4 004DF0D4 7600043C */  lui        $4, %hi(D_007598F0)
    /* 3DF0D8 004DF0D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF0DC 004DF0DC F0988424 */  addiu      $4, $4, %lo(D_007598F0)
    /* 3DF0E0 004DF0E0 B0781308 */  j          func_004de2c0
    /* 3DF0E4 004DF0E4 1000BD27 */   addiu     $29, $29, 0x10
  .L004DF0E8:
    /* 3DF0E8 004DF0E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF0EC 004DF0EC C00185AC */  sw         $5, 0x1C0($4)
    /* 3DF0F0 004DF0F0 0800E003 */  jr         $31
    /* 3DF0F4 004DF0F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df0c8, 0x30
