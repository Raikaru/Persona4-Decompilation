.section .text
.set noat
.set noreorder
glabel func_0039b680
    /* 29B680 0039B680 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 29B684 0039B684 1000BFFF */  sd         $31, 0x10($29)
    /* 29B688 0039B688 0000B07F */  sq         $16, 0x0($29)
    /* 29B68C 0039B68C 2D808000 */  daddu      $16, $4, $0
    /* 29B690 0039B690 8800043C */  lui        $4, %hi(D_00884ACC)
    /* 29B694 0039B694 CC4A8424 */  addiu      $4, $4, %lo(D_00884ACC)
    /* 29B698 0039B698 0000828C */  lw         $2, 0x0($4)
    /* 29B69C 0039B69C 05004010 */  beqz       $2, .L0039B6B4
    /* 29B6A0 0039B6A0 00000000 */   nop
  .L0039B6A4:
    /* 29B6A4 0039B6A4 346E0E0C */  jal        func_0039b8d0
    /* 29B6A8 0039B6A8 2D280002 */   daddu     $5, $16, $0
    /* 29B6AC 0039B6AC 06000010 */  b          .L0039B6C8
    /* 29B6B0 0039B6B0 2D100002 */   daddu     $2, $16, $0
  .L0039B6B4:
    /* 29B6B4 0039B6B4 8800023C */  lui        $2, %hi(D_00884ADC)
    /* 29B6B8 0039B6B8 F06D0E0C */  jal        func_0039b7c0
    /* 29B6BC 0039B6BC DC4A458C */   lw        $5, %lo(D_00884ADC)($2)
    /* 29B6C0 0039B6C0 F8FF0010 */  b          .L0039B6A4
    /* 29B6C4 0039B6C4 2D204000 */   daddu     $4, $2, $0
  .L0039B6C8:
    /* 29B6C8 0039B6C8 1000BFDF */  ld         $31, 0x10($29)
    /* 29B6CC 0039B6CC 0000B07B */  lq         $16, 0x0($29)
    /* 29B6D0 0039B6D0 0800E003 */  jr         $31
    /* 29B6D4 0039B6D4 2000BD27 */   addiu     $29, $29, 0x20
    /* 29B6D8 0039B6D8 00000000 */  nop
    /* 29B6DC 0039B6DC 00000000 */  nop
.size func_0039b680, 0x60
