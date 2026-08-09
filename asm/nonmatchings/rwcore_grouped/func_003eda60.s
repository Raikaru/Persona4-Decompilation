.section .text
.set noat
.set noreorder
glabel func_003eda60
    /* 2EDA60 003EDA60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2EDA64 003EDA64 6D000224 */  addiu      $2, $0, 0x6D
    /* 2EDA68 003EDA68 2000BFFF */  sd         $31, 0x20($29)
    /* 2EDA6C 003EDA6C 2D180000 */  daddu      $3, $0, $0
    /* 2EDA70 003EDA70 1000B17F */  sq         $17, 0x10($29)
    /* 2EDA74 003EDA74 0000B07F */  sq         $16, 0x0($29)
    /* 2EDA78 003EDA78 3C00A2A3 */  sb         $2, 0x3C($29)
    /* 2EDA7C 003EDA7C FF00C230 */  andi       $2, $6, 0xFF
    /* 2EDA80 003EDA80 05004018 */  blez       $2, .L003EDA98
    /* 2EDA84 003EDA84 2D80A000 */   daddu     $16, $5, $0
    /* 2EDA88 003EDA88 10004128 */  slti       $1, $2, 0x10
    /* 2EDA8C 003EDA8C 02002010 */  beqz       $1, .L003EDA98
    /* 2EDA90 003EDA90 00000000 */   nop
    /* 2EDA94 003EDA94 01000324 */  addiu      $3, $0, 0x1
  .L003EDA98:
    /* 2EDA98 003EDA98 07006010 */  beqz       $3, .L003EDAB8
    /* 2EDA9C 003EDA9C 00000000 */   nop
    /* 2EDAA0 003EDAA0 7500023C */  lui        $2, %hi(D_00752FD0)
    /* 2EDAA4 003EDAA4 FF00C330 */  andi       $3, $6, 0xFF
    /* 2EDAA8 003EDAA8 D02F4224 */  addiu      $2, $2, %lo(D_00752FD0)
    /* 2EDAAC 003EDAAC 21104300 */  addu       $2, $2, $3
    /* 2EDAB0 003EDAB0 02000010 */  b          .L003EDABC
    /* 2EDAB4 003EDAB4 00004380 */   lb        $3, 0x0($2)
  .L003EDAB8:
    /* 2EDAB8 003EDAB8 2D180000 */  daddu      $3, $0, $0
  .L003EDABC:
    /* 2EDABC 003EDABC 3D00A227 */  addiu      $2, $29, 0x3D
    /* 2EDAC0 003EDAC0 000043A0 */  sb         $3, 0x0($2)
    /* 2EDAC4 003EDAC4 3C160300 */  dsll32     $2, $3, 24
    /* 2EDAC8 003EDAC8 3F160200 */  dsra32     $2, $2, 24
    /* 2EDACC 003EDACC 03004014 */  bnez       $2, .L003EDADC
    /* 2EDAD0 003EDAD0 3E00A0A3 */   sb        $0, 0x3E($29)
  .L003EDAD4:
    /* 2EDAD4 003EDAD4 11000010 */  b          .L003EDB1C
    /* 2EDAD8 003EDAD8 01000224 */   addiu     $2, $0, 0x1
  .L003EDADC:
    /* 2EDADC 003EDADC 8800113C */  lui        $17, %hi(D_008873B4)
    /* 2EDAE0 003EDAE0 B4733126 */  addiu      $17, $17, %lo(D_008873B4)
    /* 2EDAE4 003EDAE4 0000228E */  lw         $2, 0x0($17)
    /* 2EDAE8 003EDAE8 09F84000 */  jalr       $2
    /* 2EDAEC 003EDAEC 3C00A527 */   addiu     $5, $29, 0x3C
    /* 2EDAF0 003EDAF0 F8FF0012 */  beqz       $16, .L003EDAD4
    /* 2EDAF4 003EDAF4 00000000 */   nop
    /* 2EDAF8 003EDAF8 00000282 */  lb         $2, 0x0($16)
    /* 2EDAFC 003EDAFC F5FF4010 */  beqz       $2, .L003EDAD4
    /* 2EDB00 003EDB00 00000000 */   nop
    /* 2EDB04 003EDB04 0000228E */  lw         $2, 0x0($17)
    /* 2EDB08 003EDB08 2D200002 */  daddu      $4, $16, $0
    /* 2EDB0C 003EDB0C 09F84000 */  jalr       $2
    /* 2EDB10 003EDB10 3C00A527 */   addiu     $5, $29, 0x3C
    /* 2EDB14 003EDB14 EFFF0010 */  b          .L003EDAD4
    /* 2EDB18 003EDB18 00000000 */   nop
  .L003EDB1C:
    /* 2EDB1C 003EDB1C 2000BFDF */  ld         $31, 0x20($29)
    /* 2EDB20 003EDB20 1000B17B */  lq         $17, 0x10($29)
    /* 2EDB24 003EDB24 0000B07B */  lq         $16, 0x0($29)
    /* 2EDB28 003EDB28 0800E003 */  jr         $31
    /* 2EDB2C 003EDB2C 4000BD27 */   addiu     $29, $29, 0x40
.size func_003eda60, 0xd0
