.section .text
.set noat
.set noreorder
glabel func_004f1fb0
    /* 3F1FB0 004F1FB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1FB4 004F1FB4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F1FB8 004F1FB8 0800BFFF */  sd         $31, 0x8($29)
    /* 3F1FBC 004F1FBC 28D5130C */  jal        func_004f54a0
    /* 3F1FC0 004F1FC0 00000000 */   nop
    /* 3F1FC4 004F1FC4 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F1FC8 004F1FC8 483A5024 */  addiu      $16, $2, %lo(D_00743A48)
    /* 3F1FCC 004F1FCC 0000028E */  lw         $2, 0x0($16)
    /* 3F1FD0 004F1FD0 06004050 */  beql       $2, $0, .L004F1FEC
    /* 3F1FD4 004F1FD4 0000B0DF */   ld        $16, 0x0($29)
    /* 3F1FD8 004F1FD8 1000428C */  lw         $2, 0x10($2)
    /* 3F1FDC 004F1FDC 09F84000 */  jalr       $2
    /* 3F1FE0 004F1FE0 00000000 */   nop
    /* 3F1FE4 004F1FE4 000000AE */  sw         $0, 0x0($16)
    /* 3F1FE8 004F1FE8 0000B0DF */  ld         $16, 0x0($29)
  .L004F1FEC:
    /* 3F1FEC 004F1FEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1FF0 004F1FF0 0800E003 */  jr         $31
    /* 3F1FF4 004F1FF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1fb0, 0x48
