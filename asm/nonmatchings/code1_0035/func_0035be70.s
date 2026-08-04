.section .text
.set noat
.set noreorder
glabel func_0035be70
    /* 25BE70 0035BE70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 25BE74 0035BE74 1000BFFF */  sd         $31, 0x10($29)
    /* 25BE78 0035BE78 0000B07F */  sq         $16, 0x0($29)
    /* 25BE7C 0035BE7C 3800908C */  lw         $16, 0x38($4)
    /* 25BE80 0035BE80 2C00028E */  lw         $2, 0x2C($16)
    /* 25BE84 0035BE84 08004014 */  bnez       $2, .L0035BEA8
    /* 25BE88 0035BE88 00000000 */   nop
    /* 25BE8C 0035BE8C 20000296 */  lhu        $2, 0x20($16)
    /* 25BE90 0035BE90 05004010 */  beqz       $2, .L0035BEA8
    /* 25BE94 0035BE94 00000000 */   nop
    /* 25BE98 0035BE98 30000426 */  addiu      $4, $16, 0x30
    /* 25BE9C 0035BE9C 0C520D0C */  jal        func_00354830
    /* 25BEA0 0035BEA0 00000000 */   nop
    /* 25BEA4 0035BEA4 2C0002AE */  sw         $2, 0x2C($16)
  .L0035BEA8:
    /* 25BEA8 0035BEA8 2D100000 */  daddu      $2, $0, $0
    /* 25BEAC 0035BEAC 1000BFDF */  ld         $31, 0x10($29)
    /* 25BEB0 0035BEB0 0000B07B */  lq         $16, 0x0($29)
    /* 25BEB4 0035BEB4 2000BD27 */  addiu      $29, $29, 0x20
    /* 25BEB8 0035BEB8 0800E003 */  jr         $31
    /* 25BEBC 0035BEBC 00000000 */   nop
.size func_0035be70, 0x50
