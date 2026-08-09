.section .text
.set noat
.set noreorder
glabel func_0021eb60
    /* 11EB60 0021EB60 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 11EB64 0021EB64 5000BFFF */  sd         $31, 0x50($29)
    /* 11EB68 0021EB68 4000B47F */  sq         $20, 0x40($29)
    /* 11EB6C 0021EB6C 3000B37F */  sq         $19, 0x30($29)
    /* 11EB70 0021EB70 2000B27F */  sq         $18, 0x20($29)
    /* 11EB74 0021EB74 1000B17F */  sq         $17, 0x10($29)
    /* 11EB78 0021EB78 0000B07F */  sq         $16, 0x0($29)
    /* 11EB7C 0021EB7C 2D988000 */  daddu      $19, $4, $0
    /* 11EB80 0021EB80 BC2D040C */  jal        func_0010b6f0
    /* 11EB84 0021EB84 00000000 */   nop
    /* 11EB88 0021EB88 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* 11EB8C 0021EB8C 2D880000 */  daddu      $17, $0, $0
    /* 11EB90 0021EB90 1D000010 */  b          .L0021EC08
    /* 11EB94 0021EB94 00000000 */   nop
  .L0021EB98:
    /* 11EB98 0021EB98 80181100 */  sll        $3, $17, 2
    /* 11EB9C 0021EB9C 21186302 */  addu       $3, $19, $3
    /* 11EBA0 0021EBA0 0800748C */  lw         $20, 0x8($3)
    /* 11EBA4 0021EBA4 17008012 */  beqz       $20, .L0021EC04
    /* 11EBA8 0021EBA8 00000000 */   nop
    /* 11EBAC 0021EBAC 3C241100 */  dsll32     $4, $17, 16
    /* 11EBB0 0021EBB0 3F240400 */  dsra32     $4, $4, 16
    /* 11EBB4 0021EBB4 382B040C */  jal        func_0010ace0
    /* 11EBB8 0021EBB8 00000000 */   nop
    /* 11EBBC 0021EBBC 2D904000 */  daddu      $18, $2, $0
    /* 11EBC0 0021EBC0 2D204002 */  daddu      $4, $18, $0
    /* 11EBC4 0021EBC4 2D288002 */  daddu      $5, $20, $0
    /* 11EBC8 0021EBC8 6032040C */  jal        func_0010c980
    /* 11EBCC 0021EBCC 00000000 */   nop
    /* 11EBD0 0021EBD0 2D204002 */  daddu      $4, $18, $0
    /* 11EBD4 0021EBD4 BC31040C */  jal        func_0010c6f0
    /* 11EBD8 0021EBD8 00000000 */   nop
    /* 11EBDC 0021EBDC 09004010 */  beqz       $2, .L0021EC04
    /* 11EBE0 0021EBE0 00000000 */   nop
    /* 11EBE4 0021EBE4 00111100 */  sll        $2, $17, 4
    /* 11EBE8 0021EBE8 21105100 */  addu       $2, $2, $17
    /* 11EBEC 0021EBEC C0100200 */  sll        $2, $2, 3
    /* 11EBF0 0021EBF0 21106202 */  addu       $2, $19, $2
    /* 11EBF4 0021EBF4 2D204002 */  daddu      $4, $18, $0
    /* 11EBF8 0021EBF8 38004524 */  addiu      $5, $2, 0x38
    /* 11EBFC 0021EBFC 6831040C */  jal        func_0010c5a0
    /* 11EC00 0021EC00 00000000 */   nop
  .L0021EC04:
    /* 11EC04 0021EC04 01003126 */  addiu      $17, $17, 0x1
  .L0021EC08:
    /* 11EC08 0021EC08 2A183002 */  slt        $3, $17, $16
    /* 11EC0C 0021EC0C E2FF6014 */  bnez       $3, .L0021EB98
    /* 11EC10 0021EC10 00000000 */   nop
    /* 11EC14 0021EC14 5000BFDF */  ld         $31, 0x50($29)
    /* 11EC18 0021EC18 4000B47B */  lq         $20, 0x40($29)
    /* 11EC1C 0021EC1C 3000B37B */  lq         $19, 0x30($29)
    /* 11EC20 0021EC20 2000B27B */  lq         $18, 0x20($29)
    /* 11EC24 0021EC24 1000B17B */  lq         $17, 0x10($29)
    /* 11EC28 0021EC28 0000B07B */  lq         $16, 0x0($29)
    /* 11EC2C 0021EC2C 6000BD27 */  addiu      $29, $29, 0x60
    /* 11EC30 0021EC30 0800E003 */  jr         $31
    /* 11EC34 0021EC34 00000000 */   nop
    /* 11EC38 0021EC38 00000000 */  nop
    /* 11EC3C 0021EC3C 00000000 */  nop
.size func_0021eb60, 0xe0
