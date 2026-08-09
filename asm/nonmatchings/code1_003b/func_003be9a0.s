.section .text
.set noat
.set noreorder
glabel func_003be9a0
    /* 2BE9A0 003BE9A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BE9A4 003BE9A4 1000BFFF */  sd         $31, 0x10($29)
    /* 2BE9A8 003BE9A8 0000B07F */  sq         $16, 0x0($29)
    /* 2BE9AC 003BE9AC 4C00828C */  lw         $2, 0x4C($4)
    /* 2BE9B0 003BE9B0 02004230 */  andi       $2, $2, 0x2
    /* 2BE9B4 003BE9B4 06004014 */  bnez       $2, .L003BE9D0
    /* 2BE9B8 003BE9B8 2D808000 */   daddu     $16, $4, $0
    /* 2BE9BC 003BE9BC 03000392 */  lbu        $3, 0x3($16)
  .L003BE9C0:
    /* 2BE9C0 003BE9C0 2D100002 */  daddu      $2, $16, $0
    /* 2BE9C4 003BE9C4 01006334 */  ori        $3, $3, 0x1
    /* 2BE9C8 003BE9C8 05000010 */  b          .L003BE9E0
    /* 2BE9CC 003BE9CC 030003A2 */   sb        $3, 0x3($16)
  .L003BE9D0:
    /* 2BE9D0 003BE9D0 4CFE0E0C */  jal        func_003bf930
    /* 2BE9D4 003BE9D4 00000000 */   nop
    /* 2BE9D8 003BE9D8 F9FF0010 */  b          .L003BE9C0
    /* 2BE9DC 003BE9DC 03000392 */   lbu       $3, 0x3($16)
  .L003BE9E0:
    /* 2BE9E0 003BE9E0 1000BFDF */  ld         $31, 0x10($29)
    /* 2BE9E4 003BE9E4 0000B07B */  lq         $16, 0x0($29)
    /* 2BE9E8 003BE9E8 0800E003 */  jr         $31
    /* 2BE9EC 003BE9EC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003be9a0, 0x50
