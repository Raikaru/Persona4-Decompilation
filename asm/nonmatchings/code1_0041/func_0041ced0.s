.section .text
.set noat
.set noreorder
glabel func_0041ced0
    /* 31CED0 0041CED0 00008E8C */  lw         $14, 0x0($4)
    /* 31CED4 0041CED4 1400858C */  lw         $5, 0x14($4)
    /* 31CED8 0041CED8 1800868C */  lw         $6, 0x18($4)
    /* 31CEDC 0041CEDC 10008C8C */  lw         $12, 0x10($4)
    /* 31CEE0 0041CEE0 04008D8C */  lw         $13, 0x4($4)
    /* 31CEE4 0041CEE4 E9CC0070 */  pnor       $25, $0, $0
    /* 31CEE8 0041CEE8 F6CB1970 */  psrlh      $25, $25, 15
    /* 31CEEC 0041CEEC 74C81970 */  psllh      $25, $25, 1
    /* 31CEF0 0041CEF0 01001824 */  addiu      $24, $0, 0x1
    /* 31CEF4 0041CEF4 01000B24 */  addiu      $11, $0, 0x1
  .L0041CEF8:
    /* 31CEF8 0041CEF8 0800878C */  lw         $7, 0x8($4)
    /* 31CEFC 0041CEFC 0000A8DC */  ld         $8, 0x0($5)
    /* 31CF00 0041CF00 0000C9DC */  ld         $9, 0x0($6)
    /* 31CF04 0041CF04 89432871 */  pcpyld     $8, $9, $8
    /* 31CF08 0041CF08 0000B805 */  mtsab      $13, 0x0
    /* 31CF0C 0041CF0C E8460871 */  qfsrv      $8, $8, $8
    /* 31CF10 0041CF10 884E0870 */  pextlb     $9, $0, $8
    /* 31CF14 0041CF14 2128AC00 */  addu       $5, $5, $12
    /* 31CF18 0041CF18 00806B35 */  ori        $11, $11, 0x8000
    /* 31CF1C 0041CF1C 00001807 */  mtsab      $24, 0x0
    /* 31CF20 0041CF20 E8560870 */  qfsrv      $10, $0, $8
    /* 31CF24 0041CF24 88460A70 */  pextlb     $8, $0, $10
    /* 31CF28 0041CF28 1C00E010 */  beqz       $7, .L0041CF9C
    /* 31CF2C 0041CF2C 08792871 */   paddh     $15, $9, $8
  .L0041CF30:
    /* 31CF30 0041CF30 2130CC00 */  addu       $6, $6, $12
    /* 31CF34 0041CF34 0000A8DC */  ld         $8, 0x0($5)
    /* 31CF38 0041CF38 0000C9DC */  ld         $9, 0x0($6)
    /* 31CF3C 0041CF3C 89432871 */  pcpyld     $8, $9, $8
    /* 31CF40 0041CF40 0000B805 */  mtsab      $13, 0x0
    /* 31CF44 0041CF44 E8460871 */  qfsrv      $8, $8, $8
    /* 31CF48 0041CF48 884E0870 */  pextlb     $9, $0, $8
    /* 31CF4C 0041CF4C FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CF50 0041CF50 2128AC00 */  addu       $5, $5, $12
    /* 31CF54 0041CF54 00001807 */  mtsab      $24, 0x0
    /* 31CF58 0041CF58 E8560870 */  qfsrv      $10, $0, $8
    /* 31CF5C 0041CF5C 88460A70 */  pextlb     $8, $0, $10
    /* 31CF60 0041CF60 08512871 */  paddh      $10, $9, $8
    /* 31CF64 0041CF64 08494F71 */  paddh      $9, $10, $15
    /* 31CF68 0041CF68 A97C4071 */  por        $15, $10, $0
    /* 31CF6C 0041CF6C 08513971 */  paddh      $10, $9, $25
    /* 31CF70 0041CF70 B6500A70 */  psrlh      $10, $10, 2
    /* 31CF74 0041CF74 0000C879 */  lq         $8, 0x0($14)
    /* 31CF78 0041CF78 08514871 */  paddh      $10, $10, $8
    /* 31CF7C 0041CF7C 88494071 */  pcgth      $9, $10, $0
    /* 31CF80 0041CF80 F64B0970 */  psrlh      $9, $9, 15
    /* 31CF84 0041CF84 08514971 */  paddh      $10, $10, $9
    /* 31CF88 0041CF88 40400C00 */  sll        $8, $12, 1
    /* 31CF8C 0041CF8C 76500A70 */  psrlh      $10, $10, 1
    /* 31CF90 0041CF90 0000CA7D */  sq         $10, 0x0($14)
    /* 31CF94 0041CF94 E6FFE01C */  bgtz       $7, .L0041CF30
    /* 31CF98 0041CF98 2170C801 */   addu      $14, $14, $8
  .L0041CF9C:
    /* 31CF9C 0041CF9C F7530B70 */  psrah      $10, $11, 15
    /* 31CFA0 0041CFA0 4001A524 */  addiu      $5, $5, 0x140
    /* 31CFA4 0041CFA4 0C00878C */  lw         $7, 0xC($4)
    /* 31CFA8 0041CFA8 4001C624 */  addiu      $6, $6, 0x140
    /* 31CFAC 0041CFAC 24504701 */  and        $10, $10, $7
    /* 31CFB0 0041CFB0 DFFF4015 */  bnez       $10, .L0041CF30
    /* 31CFB4 0041CFB4 FF7F6B31 */   andi      $11, $11, 0x7FFF
    /* 31CFB8 0041CFB8 00008E8C */  lw         $14, 0x0($4)
    /* 31CFBC 0041CFBC 1400858C */  lw         $5, 0x14($4)
    /* 31CFC0 0041CFC0 1800868C */  lw         $6, 0x18($4)
    /* 31CFC4 0041CFC4 8000CE25 */  addiu      $14, $14, 0x80
    /* 31CFC8 0041CFC8 4000A524 */  addiu      $5, $5, 0x40
    /* 31CFCC 0041CFCC 4000C624 */  addiu      $6, $6, 0x40
    /* 31CFD0 0041CFD0 01006A31 */  andi       $10, $11, 0x1
    /* 31CFD4 0041CFD4 C8FF4015 */  bnez       $10, .L0041CEF8
    /* 31CFD8 0041CFD8 FEFF6B31 */   andi      $11, $11, 0xFFFE
    /* 31CFDC 0041CFDC 0800E003 */  jr         $31
    /* 31CFE0 0041CFE0 00000000 */   nop
    /* 31CFE4 0041CFE4 00000000 */  nop
.size func_0041ced0, 0x118
