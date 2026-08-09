.section .text
.set noat
.set noreorder
glabel func_004d6c08
    /* 3D6C08 004D6C08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6C0C 004D6C0C 06008014 */  bnez       $4, .L004D6C28
    /* 3D6C10 004D6C10 0000BFFF */   sd        $31, 0x0($29)
    /* 3D6C14 004D6C14 7600043C */  lui        $4, %hi(D_007592E8)
    /* 3D6C18 004D6C18 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6C1C 004D6C1C E8928424 */  addiu      $4, $4, %lo(D_007592E8)
    /* 3D6C20 004D6C20 A61A1308 */  j          func_004c6a98
    /* 3D6C24 004D6C24 1000BD27 */   addiu     $29, $29, 0x10
  .L004D6C28:
    /* 3D6C28 004D6C28 0400848C */  lw         $4, 0x4($4)
    /* 3D6C2C 004D6C2C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6C30 004D6C30 0E3B1308 */  j          func_004cec38
    /* 3D6C34 004D6C34 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6c08, 0x30
