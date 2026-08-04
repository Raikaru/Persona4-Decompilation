.section .text
.set noat
.set noreorder
glabel func_0016ea40
    /* 6EA40 0016EA40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 6EA44 0016EA44 1000BFFF */  sd         $31, 0x10($29)
    /* 6EA48 0016EA48 0000B07F */  sq         $16, 0x0($29)
    /* 6EA4C 0016EA4C 3800908C */  lw         $16, 0x38($4)
    /* 6EA50 0016EA50 FFFFA430 */  andi       $4, $5, 0xFFFF
    /* 6EA54 0016EA54 0F00033C */  lui        $3, (0xFFC00 >> 16)
    /* 6EA58 0016EA58 00FC6334 */  ori        $3, $3, (0xFFC00 & 0xFFFF)
    /* 6EA5C 0016EA5C 24188300 */  and        $3, $4, $3
    /* 6EA60 0016EA60 83220300 */  sra        $4, $3, 10
    /* 6EA64 0016EA64 01000324 */  addiu      $3, $0, 0x1
    /* 6EA68 0016EA68 05008314 */  bne        $4, $3, .L0016EA80
    /* 6EA6C 0016EA6C 00000000 */   nop
    /* 6EA70 0016EA70 2D20A000 */  daddu      $4, $5, $0
    /* 6EA74 0016EA74 9C14050C */  jal        func_00145270
    /* 6EA78 0016EA78 00000000 */   nop
    /* 6EA7C 0016EA7C 880202AE */  sw         $2, 0x288($16)
  .L0016EA80:
    /* 6EA80 0016EA80 1000BFDF */  ld         $31, 0x10($29)
    /* 6EA84 0016EA84 0000B07B */  lq         $16, 0x0($29)
    /* 6EA88 0016EA88 2000BD27 */  addiu      $29, $29, 0x20
    /* 6EA8C 0016EA8C 0800E003 */  jr         $31
    /* 6EA90 0016EA90 00000000 */   nop
    /* 6EA94 0016EA94 00000000 */  nop
    /* 6EA98 0016EA98 00000000 */  nop
    /* 6EA9C 0016EA9C 00000000 */  nop
.size func_0016ea40, 0x60
