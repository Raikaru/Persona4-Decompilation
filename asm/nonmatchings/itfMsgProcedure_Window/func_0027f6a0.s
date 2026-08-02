.section .text
.set noat
.set noreorder
glabel func_0027f6a0
    /* 17F6A0 0027F6A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17F6A4 0027F6A4 1000BFFF */  sd         $31, 0x10($29)
    /* 17F6A8 0027F6A8 0000B07F */  sq         $16, 0x0($29)
    /* 17F6AC 0027F6AC E0B49027 */  addiu      $16, $28, -0x4B20
    /* 17F6B0 0027F6B0 78A78427 */  addiu      $4, $28, -0x5888
    /* 17F6B4 0027F6B4 E048110C */  jal        func_00452380
    /* 17F6B8 0027F6B8 00000000 */   nop
    /* 17F6BC 0027F6BC 04004010 */  beqz       $2, .L0027F6D0
    /* 17F6C0 0027F6C0 00000000 */   nop
    /* 17F6C4 0027F6C4 02000386 */  lh         $3, 0x2($16)
    /* 17F6C8 0027F6C8 01006334 */  ori        $3, $3, 0x1
    /* 17F6CC 0027F6CC 020003A6 */  sh         $3, 0x2($16)
  .L0027F6D0:
    /* 17F6D0 0027F6D0 1000BFDF */  ld         $31, 0x10($29)
    /* 17F6D4 0027F6D4 0000B07B */  lq         $16, 0x0($29)
    /* 17F6D8 0027F6D8 2000BD27 */  addiu      $29, $29, 0x20
    /* 17F6DC 0027F6DC 0800E003 */  jr         $31
    /* 17F6E0 0027F6E0 00000000 */   nop
    /* 17F6E4 0027F6E4 00000000 */  nop
    /* 17F6E8 0027F6E8 00000000 */  nop
    /* 17F6EC 0027F6EC 00000000 */  nop
.size func_0027f6a0, 0x50
