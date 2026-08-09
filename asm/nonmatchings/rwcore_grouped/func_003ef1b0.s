.section .text
.set noat
.set noreorder
glabel func_003ef1b0
    /* 2EF1B0 003EF1B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EF1B4 003EF1B4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF1B8 003EF1B8 1000BFFF */  sd         $31, 0x10($29)
    /* 2EF1BC 003EF1BC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF1C0 003EF1C0 0000B07F */  sq         $16, 0x0($29)
    /* 2EF1C4 003EF1C4 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF1C8 003EF1C8 2D808000 */  daddu      $16, $4, $0
    /* 2EF1CC 003EF1CC 21104300 */  addu       $2, $2, $3
    /* 2EF1D0 003EF1D0 10004324 */  addiu      $3, $2, 0x10
    /* 2EF1D4 003EF1D4 1000428C */  lw         $2, 0x10($2)
    /* 2EF1D8 003EF1D8 1B005010 */  beq        $2, $16, .L003EF248
    /* 2EF1DC 003EF1DC 00000000 */   nop
  .L003EF1E0:
    /* 2EF1E0 003EF1E0 3F00053C */  lui        $5, %hi(func_003ef3a0)
    /* 2EF1E4 003EF1E4 2D200002 */  daddu      $4, $16, $0
    /* 2EF1E8 003EF1E8 A0F3A524 */  addiu      $5, $5, %lo(func_003ef3a0)
    /* 2EF1EC 003EF1EC 98BC0F0C */  jal        func_003ef260
    /* 2EF1F0 003EF1F0 2D300000 */   daddu     $6, $0, $0
    /* 2EF1F4 003EF1F4 7100043C */  lui        $4, %hi(D_0070B820)
    /* 2EF1F8 003EF1F8 2D280002 */  daddu      $5, $16, $0
    /* 2EF1FC 003EF1FC 088F0F0C */  jal        func_003e3c20
    /* 2EF200 003EF200 20B88424 */   addiu     $4, $4, %lo(D_0070B820)
    /* 2EF204 003EF204 1000068E */  lw         $6, 0x10($16)
    /* 2EF208 003EF208 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF20C 003EF20C 1400048E */  lw         $4, 0x14($16)
    /* 2EF210 003EF210 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF214 003EF214 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EF218 003EF218 000086AC */  sw         $6, 0x0($4)
    /* 2EF21C 003EF21C 1400068E */  lw         $6, 0x14($16)
    /* 2EF220 003EF220 1000048E */  lw         $4, 0x10($16)
    /* 2EF224 003EF224 040086AC */  sw         $6, 0x4($4)
    /* 2EF228 003EF228 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EF22C 003EF22C FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EF230 003EF230 21186400 */  addu       $3, $3, $4
    /* 2EF234 003EF234 0C00648C */  lw         $4, 0xC($3)
    /* 2EF238 003EF238 09F84000 */  jalr       $2
    /* 2EF23C 003EF23C 2D280002 */   daddu     $5, $16, $0
    /* 2EF240 003EF240 03000010 */  b          .L003EF250
    /* 2EF244 003EF244 01000224 */   addiu     $2, $0, 0x1
  .L003EF248:
    /* 2EF248 003EF248 E5FF0010 */  b          .L003EF1E0
    /* 2EF24C 003EF24C 000060AC */   sw        $0, 0x0($3)
  .L003EF250:
    /* 2EF250 003EF250 1000BFDF */  ld         $31, 0x10($29)
    /* 2EF254 003EF254 0000B07B */  lq         $16, 0x0($29)
    /* 2EF258 003EF258 0800E003 */  jr         $31
    /* 2EF25C 003EF25C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003ef1b0, 0xb0
