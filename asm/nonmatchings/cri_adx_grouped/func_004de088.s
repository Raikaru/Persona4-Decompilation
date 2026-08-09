.section .text
.set noat
.set noreorder
glabel func_004de088
    /* 3DE088 004DE088 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DE08C 004DE08C 7300023C */  lui        $2, %hi(D_00729A40)
    /* 3DE090 004DE090 1800BFFF */  sd         $31, 0x18($29)
    /* 3DE094 004DE094 0000B0FF */  sd         $16, 0x0($29)
    /* 3DE098 004DE098 0F001024 */  addiu      $16, $0, 0xF
    /* 3DE09C 004DE09C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DE0A0 004DE0A0 409A5124 */  addiu      $17, $2, %lo(D_00729A40)
    /* 3DE0A4 004DE0A4 1000B2FF */  sd         $18, 0x10($29)
    /* 3DE0A8 004DE0A8 01001224 */  addiu      $18, $0, 0x1
    /* 3DE0AC 004DE0AC 0000248E */  lw         $4, 0x0($17)
  .L004DE0B0:
    /* 3DE0B0 004DE0B0 06008010 */  beqz       $4, .L004DE0CC
    /* 3DE0B4 004DE0B4 04003126 */   addiu     $17, $17, 0x4
    /* 3DE0B8 004DE0B8 04008280 */  lb         $2, 0x4($4)
    /* 3DE0BC 004DE0BC 04005254 */  bnel       $2, $18, .L004DE0D0
    /* 3DE0C0 004DE0C0 FFFF1026 */   addiu     $16, $16, -0x1
    /* 3DE0C4 004DE0C4 1278130C */  jal        func_004de048
    /* 3DE0C8 004DE0C8 00000000 */   nop
  .L004DE0CC:
    /* 3DE0CC 004DE0CC FFFF1026 */  addiu      $16, $16, -0x1
  .L004DE0D0:
    /* 3DE0D0 004DE0D0 F7FF0306 */  bgezl      $16, .L004DE0B0
    /* 3DE0D4 004DE0D4 0000248E */   lw        $4, 0x0($17)
    /* 3DE0D8 004DE0D8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DE0DC 004DE0DC 0800B1DF */  ld         $17, 0x8($29)
    /* 3DE0E0 004DE0E0 1000B2DF */  ld         $18, 0x10($29)
    /* 3DE0E4 004DE0E4 1800BFDF */  ld         $31, 0x18($29)
    /* 3DE0E8 004DE0E8 0800E003 */  jr         $31
    /* 3DE0EC 004DE0EC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004de088, 0x68
