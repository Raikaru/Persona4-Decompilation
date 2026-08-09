.section .text
.set noat
.set noreorder
glabel func_001eaec0
    /* EAEC0 001EAEC0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* EAEC4 001EAEC4 5000BFFF */  sd         $31, 0x50($29)
    /* EAEC8 001EAEC8 4000B47F */  sq         $20, 0x40($29)
    /* EAECC 001EAECC 3000B37F */  sq         $19, 0x30($29)
    /* EAED0 001EAED0 2000B27F */  sq         $18, 0x20($29)
    /* EAED4 001EAED4 1000B17F */  sq         $17, 0x10($29)
    /* EAED8 001EAED8 0000B07F */  sq         $16, 0x0($29)
    /* EAEDC 001EAEDC 2D200000 */  daddu      $4, $0, $0
    /* EAEE0 001EAEE0 00730A0C */  jal        func_0029cc00
    /* EAEE4 001EAEE4 00000000 */   nop
    /* EAEE8 001EAEE8 2DA04000 */  daddu      $20, $2, $0
    /* EAEEC 001EAEEC 01000424 */  addiu      $4, $0, 0x1
    /* EAEF0 001EAEF0 00730A0C */  jal        func_0029cc00
    /* EAEF4 001EAEF4 00000000 */   nop
    /* EAEF8 001EAEF8 2D984000 */  daddu      $19, $2, $0
    /* EAEFC 001EAEFC 02000424 */  addiu      $4, $0, 0x2
    /* EAF00 001EAF00 00730A0C */  jal        func_0029cc00
    /* EAF04 001EAF04 00000000 */   nop
    /* EAF08 001EAF08 2D904000 */  daddu      $18, $2, $0
    /* EAF0C 001EAF0C 03000424 */  addiu      $4, $0, 0x3
    /* EAF10 001EAF10 00730A0C */  jal        func_0029cc00
    /* EAF14 001EAF14 00000000 */   nop
    /* EAF18 001EAF18 2D884000 */  daddu      $17, $2, $0
    /* EAF1C 001EAF1C 04000424 */  addiu      $4, $0, 0x4
    /* EAF20 001EAF20 00730A0C */  jal        func_0029cc00
    /* EAF24 001EAF24 00000000 */   nop
    /* EAF28 001EAF28 2D804000 */  daddu      $16, $2, $0
    /* EAF2C 001EAF2C FFFF6432 */  andi       $4, $19, 0xFFFF
    /* EAF30 001EAF30 04008016 */  bnez       $20, .L001EAF44
    /* EAF34 001EAF34 00000000 */   nop
    /* EAF38 001EAF38 01000224 */  addiu      $2, $0, 0x1
    /* EAF3C 001EAF3C 02000010 */  b          .L001EAF48
    /* EAF40 001EAF40 00000000 */   nop
  .L001EAF44:
    /* EAF44 001EAF44 02000224 */  addiu      $2, $0, 0x2
  .L001EAF48:
    /* EAF48 001EAF48 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* EAF4C 001EAF4C 0800063C */  lui        $6, (0x80000 >> 16)
    /* EAF50 001EAF50 A064070C */  jal        func_001d9280
    /* EAF54 001EAF54 00000000 */   nop
    /* EAF58 001EAF58 0A004010 */  beqz       $2, .L001EAF84
    /* EAF5C 001EAF5C 00000000 */   nop
    /* EAF60 001EAF60 3C2C1200 */  dsll32     $5, $18, 16
    /* EAF64 001EAF64 3F2C0500 */  dsra32     $5, $5, 16
    /* EAF68 001EAF68 FFFF2632 */  andi       $6, $17, 0xFFFF
    /* EAF6C 001EAF6C 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* EAF70 001EAF70 00608344 */  mtc1       $3, $f12
    /* EAF74 001EAF74 FFFF0732 */  andi       $7, $16, 0xFFFF
    /* EAF78 001EAF78 3000448C */  lw         $4, 0x30($2)
    /* EAF7C 001EAF7C 4862060C */  jal        func_00198920
    /* EAF80 001EAF80 00000000 */   nop
  .L001EAF84:
    /* EAF84 001EAF84 01000224 */  addiu      $2, $0, 0x1
    /* EAF88 001EAF88 5000BFDF */  ld         $31, 0x50($29)
    /* EAF8C 001EAF8C 4000B47B */  lq         $20, 0x40($29)
    /* EAF90 001EAF90 3000B37B */  lq         $19, 0x30($29)
    /* EAF94 001EAF94 2000B27B */  lq         $18, 0x20($29)
    /* EAF98 001EAF98 1000B17B */  lq         $17, 0x10($29)
    /* EAF9C 001EAF9C 0000B07B */  lq         $16, 0x0($29)
    /* EAFA0 001EAFA0 6000BD27 */  addiu      $29, $29, 0x60
    /* EAFA4 001EAFA4 0800E003 */  jr         $31
    /* EAFA8 001EAFA8 00000000 */   nop
    /* EAFAC 001EAFAC 00000000 */  nop
.size func_001eaec0, 0xf0
