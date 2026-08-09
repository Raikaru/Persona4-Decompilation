.section .text
.set noat
.set noreorder
glabel func_004e8d98
    /* 3E8D98 004E8D98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E8D9C 004E8D9C 2D288000 */  daddu      $5, $4, $0
    /* 3E8DA0 004E8DA0 07008014 */  bnez       $4, .L004E8DC0
    /* 3E8DA4 004E8DA4 0000BFFF */   sd        $31, 0x0($29)
    /* 3E8DA8 004E8DA8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E8DAC 004E8DAC 7300023C */  lui        $2, %hi(D_00734388)
    /* 3E8DB0 004E8DB0 884340A0 */  sb         $0, %lo(D_00734388)($2)
    /* 3E8DB4 004E8DB4 0800E003 */  jr         $31
    /* 3E8DB8 004E8DB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E8DBC 004E8DBC 00000000 */  nop
  .L004E8DC0:
    /* 3E8DC0 004E8DC0 00008480 */  lb         $4, 0x0($4)
    /* 3E8DC4 004E8DC4 2F000224 */  addiu      $2, $0, 0x2F
    /* 3E8DC8 004E8DC8 0D008210 */  beq        $4, $2, .L004E8E00
    /* 3E8DCC 004E8DCC 5C000224 */   addiu     $2, $0, 0x5C
    /* 3E8DD0 004E8DD0 0B008210 */  beq        $4, $2, .L004E8E00
    /* 3E8DD4 004E8DD4 7300043C */   lui       $4, %hi(D_00734388)
    /* 3E8DD8 004E8DD8 7600023C */  lui        $2, %hi(D_0075B770)
    /* 3E8DDC 004E8DDC 70B74824 */  addiu      $8, $2, %lo(D_0075B770)
    /* 3E8DE0 004E8DE0 88438724 */  addiu      $7, $4, %lo(D_00734388)
    /* 3E8DE4 004E8DE4 00000381 */  lb         $3, 0x0($8)
    /* 3E8DE8 004E8DE8 01000681 */  lb         $6, 0x1($8)
    /* 3E8DEC 004E8DEC 0000E3A0 */  sb         $3, 0x0($7)
    /* 3E8DF0 004E8DF0 0100E6A0 */  sb         $6, 0x1($7)
    /* 3E8DF4 004E8DF4 05000010 */  b          .L004E8E0C
    /* 3E8DF8 004E8DF8 0000BFDF */   ld        $31, 0x0($29)
    /* 3E8DFC 004E8DFC 00000000 */  nop
  .L004E8E00:
    /* 3E8E00 004E8E00 7300043C */  lui        $4, %hi(D_00734388)
    /* 3E8E04 004E8E04 884380A0 */  sb         $0, %lo(D_00734388)($4)
    /* 3E8E08 004E8E08 0000BFDF */  ld         $31, 0x0($29)
  .L004E8E0C:
    /* 3E8E0C 004E8E0C 88438424 */  addiu      $4, $4, %lo(D_00734388)
    /* 3E8E10 004E8E10 0C0A1108 */  j          func_00442830
    /* 3E8E14 004E8E14 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e8d98, 0x80
