.section .text
.set noat
.set noreorder
glabel func_0022cc90
    /* 12CC90 0022CC90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 12CC94 0022CC94 2000BFFF */  sd         $31, 0x20($29)
    /* 12CC98 0022CC98 1000B17F */  sq         $17, 0x10($29)
    /* 12CC9C 0022CC9C 0000B07F */  sq         $16, 0x0($29)
    /* 12CCA0 0022CCA0 68BE070C */  jal        func_001ef9a0
    /* 12CCA4 0022CCA4 00000000 */   nop
    /* 12CCA8 0022CCA8 14020324 */  addiu      $3, $0, 0x214
    /* 12CCAC 0022CCAC 03004310 */  beq        $2, $3, .L0022CCBC
    /* 12CCB0 0022CCB0 00000000 */   nop
    /* 12CCB4 0022CCB4 0E000010 */  b          .L0022CCF0
    /* 12CCB8 0022CCB8 00000000 */   nop
  .L0022CCBC:
    /* 12CCBC 0022CCBC F02D040C */  jal        func_0010b7c0
    /* 12CCC0 0022CCC0 00000000 */   nop
    /* 12CCC4 0022CCC4 01000424 */  addiu      $4, $0, 0x1
    /* 12CCC8 0022CCC8 042C040C */  jal        func_0010b010
    /* 12CCCC 0022CCCC 00000000 */   nop
    /* 12CCD0 0022CCD0 01000424 */  addiu      $4, $0, 0x1
    /* 12CCD4 0022CCD4 C02C040C */  jal        func_0010b300
    /* 12CCD8 0022CCD8 00000000 */   nop
    /* 12CCDC 0022CCDC 01000424 */  addiu      $4, $0, 0x1
    /* 12CCE0 0022CCE0 2D280000 */  daddu      $5, $0, $0
    /* 12CCE4 0022CCE4 2D308000 */  daddu      $6, $4, $0
    /* 12CCE8 0022CCE8 501B040C */  jal        func_00106d40
    /* 12CCEC 0022CCEC 00000000 */   nop
  .L0022CCF0:
    /* 12CCF0 0022CCF0 2D800000 */  daddu      $16, $0, $0
    /* 12CCF4 0022CCF4 12000010 */  b          .L0022CD40
    /* 12CCF8 0022CCF8 00000000 */   nop
  .L0022CCFC:
    /* 12CCFC 0022CCFC ACB3858F */  lw         $5, -0x4C54($28)
    /* 12CD00 0022CD00 80180400 */  sll        $3, $4, 2
    /* 12CD04 0022CD04 2118A300 */  addu       $3, $5, $3
    /* 12CD08 0022CD08 E00B648C */  lw         $4, 0xBE0($3)
    /* 12CD0C 0022CD0C 09008010 */  beqz       $4, .L0022CD34
    /* 12CD10 0022CD10 00000000 */   nop
    /* 12CD14 0022CD14 3C141000 */  dsll32     $2, $16, 16
    /* 12CD18 0022CD18 3F140200 */  dsra32     $2, $2, 16
    /* 12CD1C 0022CD1C 80880200 */  sll        $17, $2, 2
    /* 12CD20 0022CD20 804F070C */  jal        func_001d3e00
    /* 12CD24 0022CD24 00000000 */   nop
    /* 12CD28 0022CD28 ACB3838F */  lw         $3, -0x4C54($28)
    /* 12CD2C 0022CD2C 21187100 */  addu       $3, $3, $17
    /* 12CD30 0022CD30 E00B60AC */  sw         $0, 0xBE0($3)
  .L0022CD34:
    /* 12CD34 0022CD34 01000326 */  addiu      $3, $16, 0x1
    /* 12CD38 0022CD38 3C840300 */  dsll32     $16, $3, 16
    /* 12CD3C 0022CD3C 3F841000 */  dsra32     $16, $16, 16
  .L0022CD40:
    /* 12CD40 0022CD40 3C241000 */  dsll32     $4, $16, 16
    /* 12CD44 0022CD44 3F240400 */  dsra32     $4, $4, 16
    /* 12CD48 0022CD48 08008328 */  slti       $3, $4, 0x8
    /* 12CD4C 0022CD4C EBFF6014 */  bnez       $3, .L0022CCFC
    /* 12CD50 0022CD50 00000000 */   nop
    /* 12CD54 0022CD54 ACB3838F */  lw         $3, -0x4C54($28)
    /* 12CD58 0022CD58 940B648C */  lw         $4, 0xB94($3)
    /* 12CD5C 0022CD5C 05008010 */  beqz       $4, .L0022CD74
    /* 12CD60 0022CD60 00000000 */   nop
    /* 12CD64 0022CD64 F452110C */  jal        func_00454bd0
    /* 12CD68 0022CD68 00000000 */   nop
    /* 12CD6C 0022CD6C ACB3838F */  lw         $3, -0x4C54($28)
    /* 12CD70 0022CD70 940B60AC */  sw         $0, 0xB94($3)
  .L0022CD74:
    /* 12CD74 0022CD74 ACB3838F */  lw         $3, -0x4C54($28)
    /* 12CD78 0022CD78 900B648C */  lw         $4, 0xB90($3)
    /* 12CD7C 0022CD7C 05008010 */  beqz       $4, .L0022CD94
    /* 12CD80 0022CD80 00000000 */   nop
    /* 12CD84 0022CD84 F452110C */  jal        func_00454bd0
    /* 12CD88 0022CD88 00000000 */   nop
    /* 12CD8C 0022CD8C ACB3838F */  lw         $3, -0x4C54($28)
    /* 12CD90 0022CD90 900B60AC */  sw         $0, 0xB90($3)
  .L0022CD94:
    /* 12CD94 0022CD94 2000BFDF */  ld         $31, 0x20($29)
    /* 12CD98 0022CD98 1000B17B */  lq         $17, 0x10($29)
    /* 12CD9C 0022CD9C 0000B07B */  lq         $16, 0x0($29)
    /* 12CDA0 0022CDA0 3000BD27 */  addiu      $29, $29, 0x30
    /* 12CDA4 0022CDA4 0800E003 */  jr         $31
    /* 12CDA8 0022CDA8 00000000 */   nop
    /* 12CDAC 0022CDAC 00000000 */  nop
.size func_0022cc90, 0x120
