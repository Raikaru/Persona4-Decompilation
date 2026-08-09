.section .text
.set noat
.set noreorder
glabel func_002e0a60
    /* 1E0A60 002E0A60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1E0A64 002E0A64 2000BFFF */  sd         $31, 0x20($29)
    /* 1E0A68 002E0A68 1000B17F */  sq         $17, 0x10($29)
    /* 1E0A6C 002E0A6C 0000B07F */  sq         $16, 0x0($29)
    /* 1E0A70 002E0A70 2D808000 */  daddu      $16, $4, $0
    /* 1E0A74 002E0A74 3800868C */  lw         $6, 0x38($4)
    /* 1E0A78 002E0A78 F800C284 */  lh         $2, 0xF8($6)
    /* 1E0A7C 002E0A7C C0180200 */  sll        $3, $2, 3
    /* 1E0A80 002E0A80 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1E0A84 002E0A84 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1E0A88 002E0A88 21184300 */  addu       $3, $2, $3
    /* 1E0A8C 002E0A8C 0400C284 */  lh         $2, 0x4($6)
    /* 1E0A90 002E0A90 01004234 */  ori        $2, $2, 0x1
    /* 1E0A94 002E0A94 0400C2A4 */  sh         $2, 0x4($6)
    /* 1E0A98 002E0A98 3800828C */  lw         $2, 0x38($4)
    /* 1E0A9C 002E0A9C 08004CE4 */  swc1       $f12, 0x8($2)
    /* 1E0AA0 002E0AA0 3800828C */  lw         $2, 0x38($4)
    /* 1E0AA4 002E0AA4 FC0045AC */  sw         $5, 0xFC($2)
    /* 1E0AA8 002E0AA8 3800918C */  lw         $17, 0x38($4)
    /* 1E0AAC 002E0AAC 3800A427 */  addiu      $4, $29, 0x38
    /* 1E0AB0 002E0AB0 00006CC4 */  lwc1       $f12, 0x0($3)
    /* 1E0AB4 002E0AB4 04006DC4 */  lwc1       $f13, 0x4($3)
    /* 1E0AB8 002E0AB8 5CCA0A0C */  jal        func_002b2970
    /* 1E0ABC 002E0ABC 00000000 */   nop
    /* 1E0AC0 002E0AC0 3800A1C7 */  lwc1       $f1, 0x38($29)
    /* 1E0AC4 002E0AC4 3C00A0C7 */  lwc1       $f0, 0x3C($29)
    /* 1E0AC8 002E0AC8 2C0021E6 */  swc1       $f1, 0x2C($17)
    /* 1E0ACC 002E0ACC 300020E6 */  swc1       $f0, 0x30($17)
    /* 1E0AD0 002E0AD0 3800048E */  lw         $4, 0x38($16)
    /* 1E0AD4 002E0AD4 FF000324 */  addiu      $3, $0, 0xFF
    /* 1E0AD8 002E0AD8 620083A0 */  sb         $3, 0x62($4)
    /* 1E0ADC 002E0ADC 3800048E */  lw         $4, 0x38($16)
    /* 1E0AE0 002E0AE0 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1E0AE4 002E0AE4 A00083AC */  sw         $3, 0xA0($4)
    /* 1E0AE8 002E0AE8 940083AC */  sw         $3, 0x94($4)
    /* 1E0AEC 002E0AEC 3800038E */  lw         $3, 0x38($16)
    /* 1E0AF0 002E0AF0 CF0060A0 */  sb         $0, 0xCF($3)
    /* 1E0AF4 002E0AF4 A70060A0 */  sb         $0, 0xA7($3)
    /* 1E0AF8 002E0AF8 670060A0 */  sb         $0, 0x67($3)
    /* 1E0AFC 002E0AFC 3B0060A0 */  sb         $0, 0x3B($3)
    /* 1E0B00 002E0B00 2000BFDF */  ld         $31, 0x20($29)
    /* 1E0B04 002E0B04 1000B17B */  lq         $17, 0x10($29)
    /* 1E0B08 002E0B08 0000B07B */  lq         $16, 0x0($29)
    /* 1E0B0C 002E0B0C 4000BD27 */  addiu      $29, $29, 0x40
    /* 1E0B10 002E0B10 0800E003 */  jr         $31
    /* 1E0B14 002E0B14 00000000 */   nop
    /* 1E0B18 002E0B18 00000000 */  nop
    /* 1E0B1C 002E0B1C 00000000 */  nop
.size func_002e0a60, 0xc0
