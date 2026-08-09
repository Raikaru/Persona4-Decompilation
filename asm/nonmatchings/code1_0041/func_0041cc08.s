.section .text
.set noat
.set noreorder
glabel func_0041cc08
    /* 31CC08 0041CC08 00008E8C */  lw         $14, 0x0($4)
    /* 31CC0C 0041CC0C 1400858C */  lw         $5, 0x14($4)
    /* 31CC10 0041CC10 1800868C */  lw         $6, 0x18($4)
    /* 31CC14 0041CC14 1000898C */  lw         $9, 0x10($4)
    /* 31CC18 0041CC18 04008D8C */  lw         $13, 0x4($4)
    /* 31CC1C 0041CC1C 0800878C */  lw         $7, 0x8($4)
    /* 31CC20 0041CC20 E9CC0070 */  pnor       $25, $0, $0
    /* 31CC24 0041CC24 F6CB1970 */  psrlh      $25, $25, 15
    /* 31CC28 0041CC28 01001824 */  addiu      $24, $0, 0x1
    /* 31CC2C 0041CC2C 40400900 */  sll        $8, $9, 1
    /* 31CC30 0041CC30 FFFF0B24 */  addiu      $11, $0, -0x1
  .L0041CC34:
    /* 31CC34 0041CC34 0000AA78 */  lq         $10, 0x0($5)
    /* 31CC38 0041CC38 0000CF78 */  lq         $15, 0x0($6)
    /* 31CC3C 0041CC3C 0000B805 */  mtsab      $13, 0x0
    /* 31CC40 0041CC40 E816EA71 */  qfsrv      $2, $15, $10
    /* 31CC44 0041CC44 E81E4F71 */  qfsrv      $3, $10, $15
    /* 31CC48 0041CC48 88560270 */  pextlb     $10, $0, $2
    /* 31CC4C 0041CC4C FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CC50 0041CC50 A87E0270 */  pextub     $15, $0, $2
    /* 31CC54 0041CC54 00001807 */  mtsab      $24, 0x0
    /* 31CC58 0041CC58 E81E6270 */  qfsrv      $3, $3, $2
    /* 31CC5C 0041CC5C 88160370 */  pextlb     $2, $0, $3
    /* 31CC60 0041CC60 A81E0370 */  pextub     $3, $0, $3
    /* 31CC64 0041CC64 08514271 */  paddh      $10, $10, $2
    /* 31CC68 0041CC68 0879E371 */  paddh      $15, $15, $3
    /* 31CC6C 0041CC6C 08115971 */  paddh      $2, $10, $25
    /* 31CC70 0041CC70 0819F971 */  paddh      $3, $15, $25
    /* 31CC74 0041CC74 76100270 */  psrlh      $2, $2, 1
    /* 31CC78 0041CC78 76180370 */  psrlh      $3, $3, 1
    /* 31CC7C 0041CC7C 0000CA79 */  lq         $10, 0x0($14)
    /* 31CC80 0041CC80 1000CF79 */  lq         $15, 0x10($14)
    /* 31CC84 0041CC84 08114A70 */  paddh      $2, $2, $10
    /* 31CC88 0041CC88 08196F70 */  paddh      $3, $3, $15
    /* 31CC8C 0041CC8C 08515970 */  paddh      $10, $2, $25
    /* 31CC90 0041CC90 76100A70 */  psrlh      $2, $10, 1
    /* 31CC94 0041CC94 88516070 */  pcgth      $10, $3, $0
    /* 31CC98 0041CC98 F6530A70 */  psrlh      $10, $10, 15
    /* 31CC9C 0041CC9C 08516A70 */  paddh      $10, $3, $10
    /* 31CCA0 0041CCA0 76180A70 */  psrlh      $3, $10, 1
    /* 31CCA4 0041CCA4 0000C27D */  sq         $2, 0x0($14)
    /* 31CCA8 0041CCA8 1000C37D */  sq         $3, 0x10($14)
    /* 31CCAC 0041CCAC 2128A900 */  addu       $5, $5, $9
    /* 31CCB0 0041CCB0 2130C900 */  addu       $6, $6, $9
    /* 31CCB4 0041CCB4 DFFFE01C */  bgtz       $7, .L0041CC34
    /* 31CCB8 0041CCB8 2170C801 */   addu      $14, $14, $8
    /* 31CCBC 0041CCBC 8000A524 */  addiu      $5, $5, 0x80
    /* 31CCC0 0041CCC0 8000C624 */  addiu      $6, $6, 0x80
    /* 31CCC4 0041CCC4 0C00878C */  lw         $7, 0xC($4)
    /* 31CCC8 0041CCC8 24606701 */  and        $12, $11, $7
    /* 31CCCC 0041CCCC D9FF8015 */  bnez       $12, .L0041CC34
    /* 31CCD0 0041CCD0 2D580000 */   daddu     $11, $0, $0
    /* 31CCD4 0041CCD4 0800E003 */  jr         $31
    /* 31CCD8 0041CCD8 00000000 */   nop
    /* 31CCDC 0041CCDC 00000000 */  nop
.size func_0041cc08, 0xd8
