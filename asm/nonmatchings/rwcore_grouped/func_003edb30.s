.section .text
.set noat
.set noreorder
glabel func_003edb30
    /* 2EDB30 003EDB30 B0BBBD27 */  addiu      $29, $29, -0x4450
    /* 2EDB34 003EDB34 3000BFFF */  sd         $31, 0x30($29)
    /* 2EDB38 003EDB38 2000B27F */  sq         $18, 0x20($29)
    /* 2EDB3C 003EDB3C 1000B17F */  sq         $17, 0x10($29)
    /* 2EDB40 003EDB40 2D90A000 */  daddu      $18, $5, $0
    /* 2EDB44 003EDB44 0000B07F */  sq         $16, 0x0($29)
    /* 2EDB48 003EDB48 2D808000 */  daddu      $16, $4, $0
    /* 2EDB4C 003EDB4C 28C90F0C */  jal        func_003f24a0
    /* 2EDB50 003EDB50 4000A427 */   addiu     $4, $29, 0x40
    /* 2EDB54 003EDB54 03004014 */  bnez       $2, .L003EDB64
    /* 2EDB58 003EDB58 00000000 */   nop
    /* 2EDB5C 003EDB5C 2C000010 */  b          .L003EDC10
    /* 2EDB60 003EDB60 2D100000 */   daddu     $2, $0, $0
  .L003EDB64:
    /* 2EDB64 003EDB64 0000058E */  lw         $5, 0x0($16)
    /* 2EDB68 003EDB68 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2EDB6C 003EDB6C 00608244 */  mtc1       $2, $f12
    /* 2EDB70 003EDB70 F4C10F0C */  jal        func_003f07d0
    /* 2EDB74 003EDB74 4000A427 */   addiu     $4, $29, 0x40
    /* 2EDB78 003EDB78 01000224 */  addiu      $2, $0, 0x1
    /* 2EDB7C 003EDB7C 5040A427 */  addiu      $4, $29, 0x4050
    /* 2EDB80 003EDB80 14884202 */  dsllv      $17, $2, $18
    /* 2EDB84 003EDB84 4000A627 */  addiu      $6, $29, 0x40
    /* 2EDB88 003EDB88 3C281100 */  dsll32     $5, $17, 0
    /* 2EDB8C 003EDB8C F8C50F0C */  jal        func_003f17e0
    /* 2EDB90 003EDB90 3F280500 */   dsra32    $5, $5, 0
    /* 2EDB94 003EDB94 0000028E */  lw         $2, 0x0($16)
    /* 2EDB98 003EDB98 0400448C */  lw         $4, 0x4($2)
    /* 2EDB9C 003EDB9C 0800458C */  lw         $5, 0x8($2)
    /* 2EDBA0 003EDBA0 B0A80F0C */  jal        func_003ea2c0
    /* 2EDBA4 003EDBA4 2D304002 */   daddu     $6, $18, $0
    /* 2EDBA8 003EDBA8 2D904000 */  daddu      $18, $2, $0
    /* 2EDBAC 003EDBAC 17004012 */  beqz       $18, .L003EDC0C
    /* 2EDBB0 003EDBB0 00000000 */   nop
    /* 2EDBB4 003EDBB4 F8A80F0C */  jal        func_003ea3e0
    /* 2EDBB8 003EDBB8 2D204002 */   daddu     $4, $18, $0
    /* 2EDBBC 003EDBBC 1400448E */  lw         $4, 0x14($18)
    /* 2EDBC0 003EDBC0 2D380000 */  daddu      $7, $0, $0
    /* 2EDBC4 003EDBC4 1000458E */  lw         $5, 0x10($18)
    /* 2EDBC8 003EDBC8 0C00468E */  lw         $6, 0xC($18)
    /* 2EDBCC 003EDBCC 0000098E */  lw         $9, 0x0($16)
    /* 2EDBD0 003EDBD0 38C70F0C */  jal        func_003f1ce0
    /* 2EDBD4 003EDBD4 4000A827 */   addiu     $8, $29, 0x40
    /* 2EDBD8 003EDBD8 1800448E */  lw         $4, 0x18($18)
    /* 2EDBDC 003EDBDC B8101100 */  dsll       $2, $17, 2
    /* 2EDBE0 003EDBE0 3C300200 */  dsll32     $6, $2, 0
    /* 2EDBE4 003EDBE4 5040A527 */  addiu      $5, $29, 0x4050
    /* 2EDBE8 003EDBE8 04FE100C */  jal        func_0043f810
    /* 2EDBEC 003EDBEC 3F300600 */   dsra32    $6, $6, 0
    /* 2EDBF0 003EDBF0 DCA80F0C */  jal        func_003ea370
    /* 2EDBF4 003EDBF4 0000048E */   lw        $4, 0x0($16)
    /* 2EDBF8 003EDBF8 4000A427 */  addiu      $4, $29, 0x40
    /* 2EDBFC 003EDBFC B0C90F0C */  jal        func_003f26c0
    /* 2EDC00 003EDC00 000012AE */   sw        $18, 0x0($16)
    /* 2EDC04 003EDC04 02000010 */  b          .L003EDC10
    /* 2EDC08 003EDC08 01000224 */   addiu     $2, $0, 0x1
  .L003EDC0C:
    /* 2EDC0C 003EDC0C 2D100000 */  daddu      $2, $0, $0
  .L003EDC10:
    /* 2EDC10 003EDC10 3000BFDF */  ld         $31, 0x30($29)
    /* 2EDC14 003EDC14 2000B27B */  lq         $18, 0x20($29)
    /* 2EDC18 003EDC18 1000B17B */  lq         $17, 0x10($29)
    /* 2EDC1C 003EDC1C 0000B07B */  lq         $16, 0x0($29)
    /* 2EDC20 003EDC20 0800E003 */  jr         $31
    /* 2EDC24 003EDC24 5044BD27 */   addiu     $29, $29, 0x4450
    /* 2EDC28 003EDC28 00000000 */  nop
    /* 2EDC2C 003EDC2C 00000000 */  nop
.size func_003edb30, 0x100
