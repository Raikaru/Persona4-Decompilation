.section .text
.set noat
.set noreorder
glabel func_004df1a0
    /* 3DF1A0 004DF1A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF1A4 004DF1A4 06008014 */  bnez       $4, .L004DF1C0
    /* 3DF1A8 004DF1A8 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF1AC 004DF1AC 7600043C */  lui        $4, %hi(D_00759980)
    /* 3DF1B0 004DF1B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF1B4 004DF1B4 80998424 */  addiu      $4, $4, %lo(D_00759980)
    /* 3DF1B8 004DF1B8 B0781308 */  j          func_004de2c0
    /* 3DF1BC 004DF1BC 1000BD27 */   addiu     $29, $29, 0x10
  .L004DF1C0:
    /* 3DF1C0 004DF1C0 0300A010 */  beqz       $5, .L004DF1D0
    /* 3DF1C4 004DF1C4 00000000 */   nop
    /* 3DF1C8 004DF1C8 C401828C */  lw         $2, 0x1C4($4)
    /* 3DF1CC 004DF1CC 0000A2AC */  sw         $2, 0x0($5)
  .L004DF1D0:
    /* 3DF1D0 004DF1D0 0500C010 */  beqz       $6, .L004DF1E8
    /* 3DF1D4 004DF1D4 0000BFDF */   ld        $31, 0x0($29)
    /* 3DF1D8 004DF1D8 C401838C */  lw         $3, 0x1C4($4)
    /* 3DF1DC 004DF1DC C801828C */  lw         $2, 0x1C8($4)
    /* 3DF1E0 004DF1E0 23104300 */  subu       $2, $2, $3
    /* 3DF1E4 004DF1E4 0000C2AC */  sw         $2, 0x0($6)
  .L004DF1E8:
    /* 3DF1E8 004DF1E8 0800E003 */  jr         $31
    /* 3DF1EC 004DF1EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df1a0, 0x50
