.section .text
.set noat
.set noreorder
glabel func_001ade10
    /* ADE10 001ADE10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* ADE14 001ADE14 1000BFFF */  sd         $31, 0x10($29)
    /* ADE18 001ADE18 0000B07F */  sq         $16, 0x0($29)
    /* ADE1C 001ADE1C 2D808000 */  daddu      $16, $4, $0
    /* ADE20 001ADE20 000084DC */  ld         $4, 0x0($4)
    /* ADE24 001ADE24 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* ADE28 001ADE28 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* ADE2C 001ADE2C 3C180200 */  dsll32     $3, $2, 0
    /* ADE30 001ADE30 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* ADE34 001ADE34 38140200 */  dsll       $2, $2, 16
    /* ADE38 001ADE38 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* ADE3C 001ADE3C 25284300 */  or         $5, $2, $3
    /* ADE40 001ADE40 FC4E060C */  jal        func_00193bf0
    /* ADE44 001ADE44 00000000 */   nop
    /* ADE48 001ADE48 0C004014 */  bnez       $2, .L001ADE7C
    /* ADE4C 001ADE4C 00000000 */   nop
    /* ADE50 001ADE50 3000028E */  lw         $2, 0x30($16)
    /* ADE54 001ADE54 A2004290 */  lbu        $2, 0xA2($2)
    /* ADE58 001ADE58 04004014 */  bnez       $2, .L001ADE6C
    /* ADE5C 001ADE5C 00000000 */   nop
    /* ADE60 001ADE60 18000296 */  lhu        $2, 0x18($16)
    /* ADE64 001ADE64 FFFB4230 */  andi       $2, $2, 0xFBFF
    /* ADE68 001ADE68 180002A6 */  sh         $2, 0x18($16)
  .L001ADE6C:
    /* ADE6C 001ADE6C 2D200002 */  daddu      $4, $16, $0
    /* ADE70 001ADE70 14000596 */  lhu        $5, 0x14($16)
    /* ADE74 001ADE74 00C2060C */  jal        func_001b0800
    /* ADE78 001ADE78 00000000 */   nop
  .L001ADE7C:
    /* ADE7C 001ADE7C 1000BFDF */  ld         $31, 0x10($29)
    /* ADE80 001ADE80 0000B07B */  lq         $16, 0x0($29)
    /* ADE84 001ADE84 2000BD27 */  addiu      $29, $29, 0x20
    /* ADE88 001ADE88 0800E003 */  jr         $31
    /* ADE8C 001ADE8C 00000000 */   nop
    /* ADE90 001ADE90 0800E003 */  jr         $31
    /* ADE94 001ADE94 00000000 */   nop
    /* ADE98 001ADE98 00000000 */  nop
    /* ADE9C 001ADE9C 00000000 */  nop
.size func_001ade10, 0x90
