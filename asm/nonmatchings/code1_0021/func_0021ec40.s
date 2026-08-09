.section .text
.set noat
.set noreorder
glabel func_0021ec40
    /* 11EC40 0021EC40 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 11EC44 0021EC44 4000BFFF */  sd         $31, 0x40($29)
    /* 11EC48 0021EC48 3000B37F */  sq         $19, 0x30($29)
    /* 11EC4C 0021EC4C 2000B27F */  sq         $18, 0x20($29)
    /* 11EC50 0021EC50 1000B17F */  sq         $17, 0x10($29)
    /* 11EC54 0021EC54 0000B07F */  sq         $16, 0x0($29)
    /* 11EC58 0021EC58 2D908000 */  daddu      $18, $4, $0
    /* 11EC5C 0021EC5C 2D800000 */  daddu      $16, $0, $0
    /* 11EC60 0021EC60 1E000010 */  b          .L0021ECDC
    /* 11EC64 0021EC64 00000000 */   nop
  .L0021EC68:
    /* 11EC68 0021EC68 80181000 */  sll        $3, $16, 2
    /* 11EC6C 0021EC6C 21184302 */  addu       $3, $18, $3
    /* 11EC70 0021EC70 A406738C */  lw         $19, 0x6A4($3)
    /* 11EC74 0021EC74 18006012 */  beqz       $19, .L0021ECD8
    /* 11EC78 0021EC78 00000000 */   nop
    /* 11EC7C 0021EC7C 40101000 */  sll        $2, $16, 1
    /* 11EC80 0021EC80 21104202 */  addu       $2, $18, $2
    /* 11EC84 0021EC84 9A064494 */  lhu        $4, 0x69A($2)
    /* 11EC88 0021EC88 402A040C */  jal        func_0010a900
    /* 11EC8C 0021EC8C 00000000 */   nop
    /* 11EC90 0021EC90 2D884000 */  daddu      $17, $2, $0
    /* 11EC94 0021EC94 2D202002 */  daddu      $4, $17, $0
    /* 11EC98 0021EC98 2D286002 */  daddu      $5, $19, $0
    /* 11EC9C 0021EC9C 6032040C */  jal        func_0010c980
    /* 11ECA0 0021ECA0 00000000 */   nop
    /* 11ECA4 0021ECA4 2D202002 */  daddu      $4, $17, $0
    /* 11ECA8 0021ECA8 BC31040C */  jal        func_0010c6f0
    /* 11ECAC 0021ECAC 00000000 */   nop
    /* 11ECB0 0021ECB0 09004010 */  beqz       $2, .L0021ECD8
    /* 11ECB4 0021ECB4 00000000 */   nop
    /* 11ECB8 0021ECB8 00111000 */  sll        $2, $16, 4
    /* 11ECBC 0021ECBC 21105000 */  addu       $2, $2, $16
    /* 11ECC0 0021ECC0 C0100200 */  sll        $2, $2, 3
    /* 11ECC4 0021ECC4 21104202 */  addu       $2, $18, $2
    /* 11ECC8 0021ECC8 2D202002 */  daddu      $4, $17, $0
    /* 11ECCC 0021ECCC B4064524 */  addiu      $5, $2, 0x6B4
    /* 11ECD0 0021ECD0 6831040C */  jal        func_0010c5a0
    /* 11ECD4 0021ECD4 00000000 */   nop
  .L0021ECD8:
    /* 11ECD8 0021ECD8 01001026 */  addiu      $16, $16, 0x1
  .L0021ECDC:
    /* 11ECDC 0021ECDC 0400032A */  slti       $3, $16, 0x4
    /* 11ECE0 0021ECE0 E1FF6014 */  bnez       $3, .L0021EC68
    /* 11ECE4 0021ECE4 00000000 */   nop
    /* 11ECE8 0021ECE8 4000BFDF */  ld         $31, 0x40($29)
    /* 11ECEC 0021ECEC 3000B37B */  lq         $19, 0x30($29)
    /* 11ECF0 0021ECF0 2000B27B */  lq         $18, 0x20($29)
    /* 11ECF4 0021ECF4 1000B17B */  lq         $17, 0x10($29)
    /* 11ECF8 0021ECF8 0000B07B */  lq         $16, 0x0($29)
    /* 11ECFC 0021ECFC 5000BD27 */  addiu      $29, $29, 0x50
    /* 11ED00 0021ED00 0800E003 */  jr         $31
    /* 11ED04 0021ED04 00000000 */   nop
    /* 11ED08 0021ED08 00000000 */  nop
    /* 11ED0C 0021ED0C 00000000 */  nop
.size func_0021ec40, 0xd0
