.section .text
.set noat
.set noreorder
glabel func_0012feb0
    /* 2FEB0 0012FEB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2FEB4 0012FEB4 2000BFFF */  sd         $31, 0x20($29)
    /* 2FEB8 0012FEB8 1000B17F */  sq         $17, 0x10($29)
    /* 2FEBC 0012FEBC 0000B07F */  sq         $16, 0x0($29)
    /* 2FEC0 0012FEC0 2D888000 */  daddu      $17, $4, $0
    /* 2FEC4 0012FEC4 20008384 */  lh         $3, 0x20($4)
    /* 2FEC8 0012FEC8 64006128 */  slti       $1, $3, 0x64
    /* 2FECC 0012FECC 03002010 */  beqz       $1, .L0012FEDC
    /* 2FED0 0012FED0 00000000 */   nop
    /* 2FED4 0012FED4 01006324 */  addiu      $3, $3, 0x1
    /* 2FED8 0012FED8 200023A6 */  sh         $3, 0x20($17)
  .L0012FEDC:
    /* 2FEDC 0012FEDC 2D800000 */  daddu      $16, $0, $0
    /* 2FEE0 0012FEE0 0B000010 */  b          .L0012FF10
    /* 2FEE4 0012FEE4 00000000 */   nop
  .L0012FEE8:
    /* 2FEE8 0012FEE8 40101000 */  sll        $2, $16, 1
    /* 2FEEC 0012FEEC 21105000 */  addu       $2, $2, $16
    /* 2FEF0 0012FEF0 00110200 */  sll        $2, $2, 4
    /* 2FEF4 0012FEF4 21102202 */  addu       $2, $17, $2
    /* 2FEF8 0012FEF8 20002586 */  lh         $5, 0x20($17)
    /* 2FEFC 0012FEFC B81A4424 */  addiu      $4, $2, 0x1AB8
    /* 2FF00 0012FF00 2D300000 */  daddu      $6, $0, $0
    /* 2FF04 0012FF04 EC0D050C */  jal        func_001437b0
    /* 2FF08 0012FF08 00000000 */   nop
    /* 2FF0C 0012FF0C 01001026 */  addiu      $16, $16, 0x1
  .L0012FF10:
    /* 2FF10 0012FF10 0200032A */  slti       $3, $16, 0x2
    /* 2FF14 0012FF14 F4FF6014 */  bnez       $3, .L0012FEE8
    /* 2FF18 0012FF18 00000000 */   nop
    /* 2FF1C 0012FF1C 2000BFDF */  ld         $31, 0x20($29)
    /* 2FF20 0012FF20 1000B17B */  lq         $17, 0x10($29)
    /* 2FF24 0012FF24 0000B07B */  lq         $16, 0x0($29)
    /* 2FF28 0012FF28 3000BD27 */  addiu      $29, $29, 0x30
    /* 2FF2C 0012FF2C 0800E003 */  jr         $31
    /* 2FF30 0012FF30 00000000 */   nop
    /* 2FF34 0012FF34 00000000 */  nop
    /* 2FF38 0012FF38 00000000 */  nop
    /* 2FF3C 0012FF3C 00000000 */  nop
.size func_0012feb0, 0x90
