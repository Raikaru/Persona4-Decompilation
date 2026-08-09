.section .text
.set noat
.set noreorder
glabel func_0041cb20
    /* 31CB20 0041CB20 00008E8C */  lw         $14, 0x0($4)
    /* 31CB24 0041CB24 1400858C */  lw         $5, 0x14($4)
    /* 31CB28 0041CB28 1800868C */  lw         $6, 0x18($4)
    /* 31CB2C 0041CB2C 10008C8C */  lw         $12, 0x10($4)
    /* 31CB30 0041CB30 04008D8C */  lw         $13, 0x4($4)
    /* 31CB34 0041CB34 E9CC0070 */  pnor       $25, $0, $0
    /* 31CB38 0041CB38 F6CB1970 */  psrlh      $25, $25, 15
    /* 31CB3C 0041CB3C 01000B24 */  addiu      $11, $0, 0x1
    /* 31CB40 0041CB40 40C00C00 */  sll        $24, $12, 1
    /* 31CB44 0041CB44 0000B805 */  mtsab      $13, 0x0
  .L0041CB48:
    /* 31CB48 0041CB48 0800878C */  lw         $7, 0x8($4)
    /* 31CB4C 0041CB4C 0000A8DC */  ld         $8, 0x0($5)
    /* 31CB50 0041CB50 0000C9DC */  ld         $9, 0x0($6)
    /* 31CB54 0041CB54 89432871 */  pcpyld     $8, $9, $8
    /* 31CB58 0041CB58 E8460871 */  qfsrv      $8, $8, $8
    /* 31CB5C 0041CB5C 00806B35 */  ori        $11, $11, 0x8000
    /* 31CB60 0041CB60 1600E010 */  beqz       $7, .L0041CBBC
    /* 31CB64 0041CB64 887E0870 */   pextlb    $15, $0, $8
  .L0041CB68:
    /* 31CB68 0041CB68 2128AC00 */  addu       $5, $5, $12
    /* 31CB6C 0041CB6C 2130CC00 */  addu       $6, $6, $12
    /* 31CB70 0041CB70 0000A8DC */  ld         $8, 0x0($5)
    /* 31CB74 0041CB74 0000C9DC */  ld         $9, 0x0($6)
    /* 31CB78 0041CB78 89432871 */  pcpyld     $8, $9, $8
    /* 31CB7C 0041CB7C E8460871 */  qfsrv      $8, $8, $8
    /* 31CB80 0041CB80 88560870 */  pextlb     $10, $0, $8
    /* 31CB84 0041CB84 FFFFE720 */  addi       $7, $7, -0x1 /* handwritten instruction */
    /* 31CB88 0041CB88 08494F71 */  paddh      $9, $10, $15
    /* 31CB8C 0041CB8C A97C4071 */  por        $15, $10, $0
    /* 31CB90 0041CB90 08513971 */  paddh      $10, $9, $25
    /* 31CB94 0041CB94 76500A70 */  psrlh      $10, $10, 1
    /* 31CB98 0041CB98 0000C879 */  lq         $8, 0x0($14)
    /* 31CB9C 0041CB9C 08514871 */  paddh      $10, $10, $8
    /* 31CBA0 0041CBA0 88494071 */  pcgth      $9, $10, $0
    /* 31CBA4 0041CBA4 F64B0970 */  psrlh      $9, $9, 15
    /* 31CBA8 0041CBA8 08514971 */  paddh      $10, $10, $9
    /* 31CBAC 0041CBAC 76500A70 */  psrlh      $10, $10, 1
    /* 31CBB0 0041CBB0 0000CA7D */  sq         $10, 0x0($14)
    /* 31CBB4 0041CBB4 ECFFE01C */  bgtz       $7, .L0041CB68
    /* 31CBB8 0041CBB8 2170D801 */   addu      $14, $14, $24
  .L0041CBBC:
    /* 31CBBC 0041CBBC F7530B70 */  psrah      $10, $11, 15
    /* 31CBC0 0041CBC0 4001A524 */  addiu      $5, $5, 0x140
    /* 31CBC4 0041CBC4 0C00878C */  lw         $7, 0xC($4)
    /* 31CBC8 0041CBC8 4001C624 */  addiu      $6, $6, 0x140
    /* 31CBCC 0041CBCC 24504701 */  and        $10, $10, $7
    /* 31CBD0 0041CBD0 E5FF4015 */  bnez       $10, .L0041CB68
    /* 31CBD4 0041CBD4 FF7F6B31 */   andi      $11, $11, 0x7FFF
    /* 31CBD8 0041CBD8 00008E8C */  lw         $14, 0x0($4)
    /* 31CBDC 0041CBDC 1400858C */  lw         $5, 0x14($4)
    /* 31CBE0 0041CBE0 1800868C */  lw         $6, 0x18($4)
    /* 31CBE4 0041CBE4 8000CE25 */  addiu      $14, $14, 0x80
    /* 31CBE8 0041CBE8 4000A524 */  addiu      $5, $5, 0x40
    /* 31CBEC 0041CBEC 4000C624 */  addiu      $6, $6, 0x40
    /* 31CBF0 0041CBF0 01006A31 */  andi       $10, $11, 0x1
    /* 31CBF4 0041CBF4 D4FF4015 */  bnez       $10, .L0041CB48
    /* 31CBF8 0041CBF8 FEFF6B31 */   andi      $11, $11, 0xFFFE
    /* 31CBFC 0041CBFC 0800E003 */  jr         $31
    /* 31CC00 0041CC00 00000000 */   nop
    /* 31CC04 0041CC04 00000000 */  nop
.size func_0041cb20, 0xe8
