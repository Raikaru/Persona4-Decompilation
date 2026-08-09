.section .text
.set noat
.set noreorder
glabel func_0041cce0
    /* 31CCE0 0041CCE0 00008E8C */  lw         $14, 0x0($4)
    /* 31CCE4 0041CCE4 1400858C */  lw         $5, 0x14($4)
    /* 31CCE8 0041CCE8 1800868C */  lw         $6, 0x18($4)
    /* 31CCEC 0041CCEC 1000838C */  lw         $3, 0x10($4)
    /* 31CCF0 0041CCF0 04008D8C */  lw         $13, 0x4($4)
    /* 31CCF4 0041CCF4 E9CC0070 */  pnor       $25, $0, $0
    /* 31CCF8 0041CCF8 F6CB1970 */  psrlh      $25, $25, 15
    /* 31CCFC 0041CCFC 01001824 */  addiu      $24, $0, 0x1
    /* 31CD00 0041CD00 FFFF0C24 */  addiu      $12, $0, -0x1
    /* 31CD04 0041CD04 40100300 */  sll        $2, $3, 1
  .L0041CD08:
    /* 31CD08 0041CD08 0800878C */  lw         $7, 0x8($4)
    /* 31CD0C 0041CD0C FFFF0B24 */  addiu      $11, $0, -0x1
  .L0041CD10:
    /* 31CD10 0041CD10 0000A8DC */  ld         $8, 0x0($5)
    /* 31CD14 0041CD14 0000C9DC */  ld         $9, 0x0($6)
    /* 31CD18 0041CD18 89432871 */  pcpyld     $8, $9, $8
    /* 31CD1C 0041CD1C 0000B805 */  mtsab      $13, 0x0
    /* 31CD20 0041CD20 E8460871 */  qfsrv      $8, $8, $8
    /* 31CD24 0041CD24 884E0870 */  pextlb     $9, $0, $8
    /* 31CD28 0041CD28 FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CD2C 0041CD2C 2128A300 */  addu       $5, $5, $3
    /* 31CD30 0041CD30 2130C300 */  addu       $6, $6, $3
    /* 31CD34 0041CD34 00001807 */  mtsab      $24, 0x0
    /* 31CD38 0041CD38 E8560870 */  qfsrv      $10, $0, $8
    /* 31CD3C 0041CD3C 88460A70 */  pextlb     $8, $0, $10
    /* 31CD40 0041CD40 08512871 */  paddh      $10, $9, $8
    /* 31CD44 0041CD44 08515971 */  paddh      $10, $10, $25
    /* 31CD48 0041CD48 76500A70 */  psrlh      $10, $10, 1
    /* 31CD4C 0041CD4C 0000C879 */  lq         $8, 0x0($14)
    /* 31CD50 0041CD50 08514871 */  paddh      $10, $10, $8
    /* 31CD54 0041CD54 88494071 */  pcgth      $9, $10, $0
    /* 31CD58 0041CD58 F64B0970 */  psrlh      $9, $9, 15
    /* 31CD5C 0041CD5C 08514971 */  paddh      $10, $10, $9
    /* 31CD60 0041CD60 76500A70 */  psrlh      $10, $10, 1
    /* 31CD64 0041CD64 0000CA7D */  sq         $10, 0x0($14)
    /* 31CD68 0041CD68 E9FFE01C */  bgtz       $7, .L0041CD10
    /* 31CD6C 0041CD6C 2170C201 */   addu      $14, $14, $2
    /* 31CD70 0041CD70 4001A524 */  addiu      $5, $5, 0x140
    /* 31CD74 0041CD74 4001C624 */  addiu      $6, $6, 0x140
    /* 31CD78 0041CD78 0C00878C */  lw         $7, 0xC($4)
    /* 31CD7C 0041CD7C 24506701 */  and        $10, $11, $7
    /* 31CD80 0041CD80 E3FF4015 */  bnez       $10, .L0041CD10
    /* 31CD84 0041CD84 2D580000 */   daddu     $11, $0, $0
    /* 31CD88 0041CD88 00008E8C */  lw         $14, 0x0($4)
    /* 31CD8C 0041CD8C 1400858C */  lw         $5, 0x14($4)
    /* 31CD90 0041CD90 1800868C */  lw         $6, 0x18($4)
    /* 31CD94 0041CD94 8000CE25 */  addiu      $14, $14, 0x80
    /* 31CD98 0041CD98 4000A524 */  addiu      $5, $5, 0x40
    /* 31CD9C 0041CD9C 4000C624 */  addiu      $6, $6, 0x40
    /* 31CDA0 0041CDA0 D9FF8015 */  bnez       $12, .L0041CD08
    /* 31CDA4 0041CDA4 2D600000 */   daddu     $12, $0, $0
    /* 31CDA8 0041CDA8 0800E003 */  jr         $31
    /* 31CDAC 0041CDAC 00000000 */   nop
.size func_0041cce0, 0xd0
