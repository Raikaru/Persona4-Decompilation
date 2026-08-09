.section .text
.set noat
.set noreorder
glabel func_004bda68
    /* 3BDA68 004BDA68 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BDA6C 004BDA6C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BDA70 004BDA70 2D88E000 */  daddu      $17, $7, $0
    /* 3BDA74 004BDA74 1000B2FF */  sd         $18, 0x10($29)
    /* 3BDA78 004BDA78 2D908000 */  daddu      $18, $4, $0
    /* 3BDA7C 004BDA7C 1800B3FF */  sd         $19, 0x18($29)
    /* 3BDA80 004BDA80 2D98A000 */  daddu      $19, $5, $0
    /* 3BDA84 004BDA84 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDA88 004BDA88 2D28C000 */  daddu      $5, $6, $0
    /* 3BDA8C 004BDA8C 0E00201A */  blez       $17, .L004BDAC8
    /* 3BDA90 004BDA90 2000BFFF */   sd        $31, 0x20($29)
    /* 3BDA94 004BDA94 08F7120C */  jal        func_004bdc20
    /* 3BDA98 004BDA98 00000000 */   nop
    /* 3BDA9C 004BDA9C 2D204002 */  daddu      $4, $18, $0
    /* 3BDAA0 004BDAA0 2D286002 */  daddu      $5, $19, $0
    /* 3BDAA4 004BDAA4 08F7120C */  jal        func_004bdc20
    /* 3BDAA8 004BDAA8 2D804000 */   daddu     $16, $2, $0
    /* 3BDAAC 004BDAAC 01002052 */  beql       $17, $0, .L004BDAB4
    /* 3BDAB0 004BDAB0 CD010000 */   break     0, 7
  .L004BDAB4:
    /* 3BDAB4 004BDAB4 23800202 */  subu       $16, $16, $2
    /* 3BDAB8 004BDAB8 1A001102 */  div        $0, $16, $17
    /* 3BDABC 004BDABC 12800000 */  mflo       $16
    /* 3BDAC0 004BDAC0 03000010 */  b          .L004BDAD0
    /* 3BDAC4 004BDAC4 2D100002 */   daddu     $2, $16, $0
  .L004BDAC8:
    /* 3BDAC8 004BDAC8 3100023C */  lui        $2, (0x316938 >> 16)
    /* 3BDACC 004BDACC 38694234 */  ori        $2, $2, (0x316938 & 0xFFFF)
  .L004BDAD0:
    /* 3BDAD0 004BDAD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDAD4 004BDAD4 0800B1DF */  ld         $17, 0x8($29)
    /* 3BDAD8 004BDAD8 1000B2DF */  ld         $18, 0x10($29)
    /* 3BDADC 004BDADC 1800B3DF */  ld         $19, 0x18($29)
    /* 3BDAE0 004BDAE0 2000BFDF */  ld         $31, 0x20($29)
    /* 3BDAE4 004BDAE4 0800E003 */  jr         $31
    /* 3BDAE8 004BDAE8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BDAEC 004BDAEC 00000000 */  nop
.size func_004bda68, 0x88
