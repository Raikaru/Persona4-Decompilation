.section .text
.set noat
.set noreorder
glabel func_0041cdb0
    /* 31CDB0 0041CDB0 00008E8C */  lw         $14, 0x0($4)
    /* 31CDB4 0041CDB4 1400858C */  lw         $5, 0x14($4)
    /* 31CDB8 0041CDB8 1800868C */  lw         $6, 0x18($4)
    /* 31CDBC 0041CDBC 1000988C */  lw         $24, 0x10($4)
    /* 31CDC0 0041CDC0 04008D8C */  lw         $13, 0x4($4)
    /* 31CDC4 0041CDC4 0800878C */  lw         $7, 0x8($4)
    /* 31CDC8 0041CDC8 E9CC0070 */  pnor       $25, $0, $0
    /* 31CDCC 0041CDCC F6CB1970 */  psrlh      $25, $25, 15
    /* 31CDD0 0041CDD0 74C81970 */  psllh      $25, $25, 1
    /* 31CDD4 0041CDD4 01000C24 */  addiu      $12, $0, 0x1
    /* 31CDD8 0041CDD8 0000A878 */  lq         $8, 0x0($5)
    /* 31CDDC 0041CDDC 0000C978 */  lq         $9, 0x0($6)
    /* 31CDE0 0041CDE0 0000B805 */  mtsab      $13, 0x0
    /* 31CDE4 0041CDE4 E8562871 */  qfsrv      $10, $9, $8
    /* 31CDE8 0041CDE8 E87E0971 */  qfsrv      $15, $8, $9
    /* 31CDEC 0041CDEC 88460A70 */  pextlb     $8, $0, $10
    /* 31CDF0 0041CDF0 A84E0A70 */  pextub     $9, $0, $10
    /* 31CDF4 0041CDF4 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 31CDF8 0041CDF8 00009805 */  mtsab      $12, 0x0
    /* 31CDFC 0041CDFC E87EEA71 */  qfsrv      $15, $15, $10
    /* 31CE00 0041CE00 88560F70 */  pextlb     $10, $0, $15
    /* 31CE04 0041CE04 A87E0F70 */  pextub     $15, $0, $15
    /* 31CE08 0041CE08 08410A71 */  paddh      $8, $8, $10
    /* 31CE0C 0041CE0C 2800E010 */  beqz       $7, .L0041CEB0
    /* 31CE10 0041CE10 08492F71 */   paddh     $9, $9, $15
  .L0041CE14:
    /* 31CE14 0041CE14 2128B800 */  addu       $5, $5, $24
    /* 31CE18 0041CE18 2130D800 */  addu       $6, $6, $24
    /* 31CE1C 0041CE1C 0000AA78 */  lq         $10, 0x0($5)
    /* 31CE20 0041CE20 0000CF78 */  lq         $15, 0x0($6)
    /* 31CE24 0041CE24 0000B805 */  mtsab      $13, 0x0
    /* 31CE28 0041CE28 E816EA71 */  qfsrv      $2, $15, $10
    /* 31CE2C 0041CE2C E81E4F71 */  qfsrv      $3, $10, $15
    /* 31CE30 0041CE30 88560270 */  pextlb     $10, $0, $2
    /* 31CE34 0041CE34 FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CE38 0041CE38 A87E0270 */  pextub     $15, $0, $2
    /* 31CE3C 0041CE3C 00009805 */  mtsab      $12, 0x0
    /* 31CE40 0041CE40 E81E6270 */  qfsrv      $3, $3, $2
    /* 31CE44 0041CE44 88160370 */  pextlb     $2, $0, $3
    /* 31CE48 0041CE48 A81E0370 */  pextub     $3, $0, $3
    /* 31CE4C 0041CE4C 08514271 */  paddh      $10, $10, $2
    /* 31CE50 0041CE50 0879E371 */  paddh      $15, $15, $3
    /* 31CE54 0041CE54 08110A71 */  paddh      $2, $8, $10
    /* 31CE58 0041CE58 08192F71 */  paddh      $3, $9, $15
    /* 31CE5C 0041CE5C A9444071 */  por        $8, $10, $0
    /* 31CE60 0041CE60 A94CE071 */  por        $9, $15, $0
    /* 31CE64 0041CE64 08115970 */  paddh      $2, $2, $25
    /* 31CE68 0041CE68 08197970 */  paddh      $3, $3, $25
    /* 31CE6C 0041CE6C B6100270 */  psrlh      $2, $2, 2
    /* 31CE70 0041CE70 B6180370 */  psrlh      $3, $3, 2
    /* 31CE74 0041CE74 0000CA79 */  lq         $10, 0x0($14)
    /* 31CE78 0041CE78 1000CF79 */  lq         $15, 0x10($14)
    /* 31CE7C 0041CE7C 08114A70 */  paddh      $2, $2, $10
    /* 31CE80 0041CE80 08196F70 */  paddh      $3, $3, $15
    /* 31CE84 0041CE84 E9CC0070 */  pnor       $25, $0, $0
    /* 31CE88 0041CE88 F6CB1970 */  psrlh      $25, $25, 15
    /* 31CE8C 0041CE8C 08515970 */  paddh      $10, $2, $25
    /* 31CE90 0041CE90 76100A70 */  psrlh      $2, $10, 1
    /* 31CE94 0041CE94 08517970 */  paddh      $10, $3, $25
    /* 31CE98 0041CE98 76180A70 */  psrlh      $3, $10, 1
    /* 31CE9C 0041CE9C 0000C27D */  sq         $2, 0x0($14)
    /* 31CEA0 0041CEA0 40501800 */  sll        $10, $24, 1
    /* 31CEA4 0041CEA4 1000C37D */  sq         $3, 0x10($14)
    /* 31CEA8 0041CEA8 DAFFE01C */  bgtz       $7, .L0041CE14
    /* 31CEAC 0041CEAC 2170CA01 */   addu      $14, $14, $10
  .L0041CEB0:
    /* 31CEB0 0041CEB0 8000A524 */  addiu      $5, $5, 0x80
    /* 31CEB4 0041CEB4 8000C624 */  addiu      $6, $6, 0x80
    /* 31CEB8 0041CEB8 0C00878C */  lw         $7, 0xC($4)
    /* 31CEBC 0041CEBC 24506701 */  and        $10, $11, $7
    /* 31CEC0 0041CEC0 D4FF4015 */  bnez       $10, .L0041CE14
    /* 31CEC4 0041CEC4 2D580000 */   daddu     $11, $0, $0
    /* 31CEC8 0041CEC8 0800E003 */  jr         $31
    /* 31CECC 0041CECC 00000000 */   nop
.size func_0041cdb0, 0x120
