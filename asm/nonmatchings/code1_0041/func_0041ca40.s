.section .text
.set noat
.set noreorder
glabel func_0041ca40
    /* 31CA40 0041CA40 00008E8C */  lw         $14, 0x0($4)
    /* 31CA44 0041CA44 1400858C */  lw         $5, 0x14($4)
    /* 31CA48 0041CA48 1800868C */  lw         $6, 0x18($4)
    /* 31CA4C 0041CA4C 10008C8C */  lw         $12, 0x10($4)
    /* 31CA50 0041CA50 04008D8C */  lw         $13, 0x4($4)
    /* 31CA54 0041CA54 0800878C */  lw         $7, 0x8($4)
    /* 31CA58 0041CA58 E9CC0070 */  pnor       $25, $0, $0
    /* 31CA5C 0041CA5C F6CB1970 */  psrlh      $25, $25, 15
    /* 31CA60 0041CA60 0000A878 */  lq         $8, 0x0($5)
    /* 31CA64 0041CA64 0000C978 */  lq         $9, 0x0($6)
    /* 31CA68 0041CA68 0000B805 */  mtsab      $13, 0x0
    /* 31CA6C 0041CA6C E8562871 */  qfsrv      $10, $9, $8
    /* 31CA70 0041CA70 40C00C00 */  sll        $24, $12, 1
    /* 31CA74 0041CA74 88460A70 */  pextlb     $8, $0, $10
    /* 31CA78 0041CA78 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 31CA7C 0041CA7C 1F00E010 */  beqz       $7, .L0041CAFC
    /* 31CA80 0041CA80 A84E0A70 */   pextub    $9, $0, $10
  .L0041CA84:
    /* 31CA84 0041CA84 2128AC00 */  addu       $5, $5, $12
    /* 31CA88 0041CA88 2130CC00 */  addu       $6, $6, $12
    /* 31CA8C 0041CA8C 0000AA78 */  lq         $10, 0x0($5)
    /* 31CA90 0041CA90 0000CF78 */  lq         $15, 0x0($6)
    /* 31CA94 0041CA94 E816EA71 */  qfsrv      $2, $15, $10
    /* 31CA98 0041CA98 88560270 */  pextlb     $10, $0, $2
    /* 31CA9C 0041CA9C FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CAA0 0041CAA0 A87E0270 */  pextub     $15, $0, $2
    /* 31CAA4 0041CAA4 08110A71 */  paddh      $2, $8, $10
    /* 31CAA8 0041CAA8 08192F71 */  paddh      $3, $9, $15
    /* 31CAAC 0041CAAC A9444071 */  por        $8, $10, $0
    /* 31CAB0 0041CAB0 A94CE071 */  por        $9, $15, $0
    /* 31CAB4 0041CAB4 08115970 */  paddh      $2, $2, $25
    /* 31CAB8 0041CAB8 08197970 */  paddh      $3, $3, $25
    /* 31CABC 0041CABC 76100270 */  psrlh      $2, $2, 1
    /* 31CAC0 0041CAC0 76180370 */  psrlh      $3, $3, 1
    /* 31CAC4 0041CAC4 0000CA79 */  lq         $10, 0x0($14)
    /* 31CAC8 0041CAC8 1000CF79 */  lq         $15, 0x10($14)
    /* 31CACC 0041CACC 08114A70 */  paddh      $2, $2, $10
    /* 31CAD0 0041CAD0 08196F70 */  paddh      $3, $3, $15
    /* 31CAD4 0041CAD4 08515970 */  paddh      $10, $2, $25
    /* 31CAD8 0041CAD8 76100A70 */  psrlh      $2, $10, 1
    /* 31CADC 0041CADC 88516070 */  pcgth      $10, $3, $0
    /* 31CAE0 0041CAE0 F6530A70 */  psrlh      $10, $10, 15
    /* 31CAE4 0041CAE4 08516A70 */  paddh      $10, $3, $10
    /* 31CAE8 0041CAE8 76180A70 */  psrlh      $3, $10, 1
    /* 31CAEC 0041CAEC 0000C27D */  sq         $2, 0x0($14)
    /* 31CAF0 0041CAF0 1000C37D */  sq         $3, 0x10($14)
    /* 31CAF4 0041CAF4 E3FFE01C */  bgtz       $7, .L0041CA84
    /* 31CAF8 0041CAF8 2170D801 */   addu      $14, $14, $24
  .L0041CAFC:
    /* 31CAFC 0041CAFC 8000A524 */  addiu      $5, $5, 0x80
    /* 31CB00 0041CB00 8000C624 */  addiu      $6, $6, 0x80
    /* 31CB04 0041CB04 0C00878C */  lw         $7, 0xC($4)
    /* 31CB08 0041CB08 24506701 */  and        $10, $11, $7
    /* 31CB0C 0041CB0C DDFF4015 */  bnez       $10, .L0041CA84
    /* 31CB10 0041CB10 2D580000 */   daddu     $11, $0, $0
    /* 31CB14 0041CB14 0800E003 */  jr         $31
    /* 31CB18 0041CB18 00000000 */   nop
    /* 31CB1C 0041CB1C 00000000 */  nop
.size func_0041ca40, 0xe0
