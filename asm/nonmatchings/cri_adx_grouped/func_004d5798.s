.section .text
.set noat
.set noreorder
glabel func_004d5798
    /* 3D5798 004D5798 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D579C 004D579C 06008014 */  bnez       $4, .L004D57B8
    /* 3D57A0 004D57A0 0000BFFF */   sd        $31, 0x0($29)
    /* 3D57A4 004D57A4 7600043C */  lui        $4, %hi(D_00758FA8)
    /* 3D57A8 004D57A8 A61A130C */  jal        func_004c6a98
    /* 3D57AC 004D57AC A88F8424 */   addiu     $4, $4, %lo(D_00758FA8)
    /* 3D57B0 004D57B0 0E000010 */  b          .L004D57EC
    /* 3D57B4 004D57B4 FFFF0224 */   addiu     $2, $0, -0x1
  .L004D57B8:
    /* 3D57B8 004D57B8 1400838C */  lw         $3, 0x14($4)
    /* 3D57BC 004D57BC 0A006010 */  beqz       $3, .L004D57E8
    /* 3D57C0 004D57C0 2D206000 */   daddu     $4, $3, $0
    /* 3D57C4 004D57C4 0000638C */  lw         $3, 0x0($3)
    /* 3D57C8 004D57C8 2400628C */  lw         $2, 0x24($3)
    /* 3D57CC 004D57CC 09F84000 */  jalr       $2
    /* 3D57D0 004D57D0 01000524 */   addiu     $5, $0, 0x1
    /* 3D57D4 004D57D4 FF074424 */  addiu      $4, $2, 0x7FF
    /* 3D57D8 004D57D8 00004328 */  slti       $3, $2, 0x0
    /* 3D57DC 004D57DC 0B108300 */  movn       $2, $4, $3
    /* 3D57E0 004D57E0 02000010 */  b          .L004D57EC
    /* 3D57E4 004D57E4 C3120200 */   sra       $2, $2, 11
  .L004D57E8:
    /* 3D57E8 004D57E8 2D100000 */  daddu      $2, $0, $0
  .L004D57EC:
    /* 3D57EC 004D57EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D57F0 004D57F0 0800E003 */  jr         $31
    /* 3D57F4 004D57F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5798, 0x60
