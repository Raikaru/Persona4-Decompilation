.section .text
.set noat
.set noreorder
glabel func_0043fc10
    /* 33FC10 0043FC10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 33FC14 0043FC14 1400AA24 */  addiu      $10, $5, 0x14
    /* 33FC18 0043FC18 0800B1FF */  sd         $17, 0x8($29)
    /* 33FC1C 0043FC1C 2D480000 */  daddu      $9, $0, $0
    /* 33FC20 0043FC20 1800B3FF */  sd         $19, 0x18($29)
    /* 33FC24 0043FC24 2000B4FF */  sd         $20, 0x20($29)
    /* 33FC28 0043FC28 2D88E000 */  daddu      $17, $7, $0
    /* 33FC2C 0043FC2C 0000B0FF */  sd         $16, 0x0($29)
    /* 33FC30 0043FC30 2D98A000 */  daddu      $19, $5, $0
    /* 33FC34 0043FC34 1000B2FF */  sd         $18, 0x10($29)
    /* 33FC38 0043FC38 2DA08000 */  daddu      $20, $4, $0
    /* 33FC3C 0043FC3C 2800BFFF */  sd         $31, 0x28($29)
    /* 33FC40 0043FC40 1000B28C */  lw         $18, 0x10($5)
  .L0043FC44:
    /* 33FC44 0043FC44 00004D8D */  lw         $13, 0x0($10)
    /* 33FC48 0043FC48 01002925 */  addiu      $9, $9, 0x1
    /* 33FC4C 0043FC4C 2A583201 */  slt        $11, $9, $18
    /* 33FC50 0043FC50 FFFFAF31 */  andi       $15, $13, 0xFFFF
    /* 33FC54 0043FC54 1878E601 */  mult       $15, $15, $6
    /* 33FC58 0043FC58 026C0D00 */  srl        $13, $13, 16
    /* 33FC5C 0043FC5C 1868A671 */  mult1      $13, $13, $6
    /* 33FC60 0043FC60 2178F101 */  addu       $15, $15, $17
    /* 33FC64 0043FC64 02640F00 */  srl        $12, $15, 16
    /* 33FC68 0043FC68 2168AC01 */  addu       $13, $13, $12
    /* 33FC6C 0043FC6C FFFFEF31 */  andi       $15, $15, 0xFFFF
    /* 33FC70 0043FC70 00740D00 */  sll        $14, $13, 16
    /* 33FC74 0043FC74 028C0D00 */  srl        $17, $13, 16
    /* 33FC78 0043FC78 2170CF01 */  addu       $14, $14, $15
    /* 33FC7C 0043FC7C 00004EAD */  sw         $14, 0x0($10)
    /* 33FC80 0043FC80 F0FF6015 */  bnez       $11, .L0043FC44
    /* 33FC84 0043FC84 04004A25 */   addiu     $10, $10, 0x4
    /* 33FC88 0043FC88 1A002012 */  beqz       $17, .L0043FCF4
    /* 33FC8C 0043FC8C 2D106002 */   daddu     $2, $19, $0
    /* 33FC90 0043FC90 08006F8E */  lw         $15, 0x8($19)
    /* 33FC94 0043FC94 2A784F02 */  slt        $15, $18, $15
    /* 33FC98 0043FC98 1100E015 */  bnez       $15, .L0043FCE0
    /* 33FC9C 0043FC9C 80781200 */   sll       $15, $18, 2
    /* 33FCA0 0043FCA0 0400658E */  lw         $5, 0x4($19)
    /* 33FCA4 0043FCA4 2D208002 */  daddu      $4, $20, $0
    /* 33FCA8 0043FCA8 CEFE100C */  jal        func_0043fb38
    /* 33FCAC 0043FCAC 0100A524 */   addiu     $5, $5, 0x1
    /* 33FCB0 0043FCB0 1000668E */  lw         $6, 0x10($19)
    /* 33FCB4 0043FCB4 0C006526 */  addiu      $5, $19, 0xC
    /* 33FCB8 0043FCB8 2D804000 */  daddu      $16, $2, $0
    /* 33FCBC 0043FCBC 0C004424 */  addiu      $4, $2, 0xC
    /* 33FCC0 0043FCC0 80300600 */  sll        $6, $6, 2
    /* 33FCC4 0043FCC4 04FE100C */  jal        func_0043f810
    /* 33FCC8 0043FCC8 0800C624 */   addiu     $6, $6, 0x8
    /* 33FCCC 0043FCCC 2D286002 */  daddu      $5, $19, $0
    /* 33FCD0 0043FCD0 F8FE100C */  jal        func_0043fbe0
    /* 33FCD4 0043FCD4 2D208002 */   daddu     $4, $20, $0
    /* 33FCD8 0043FCD8 2D980002 */  daddu      $19, $16, $0
    /* 33FCDC 0043FCDC 80781200 */  sll        $15, $18, 2
  .L0043FCE0:
    /* 33FCE0 0043FCE0 2178F301 */  addu       $15, $15, $19
    /* 33FCE4 0043FCE4 01005226 */  addiu      $18, $18, 0x1
    /* 33FCE8 0043FCE8 1400F1AD */  sw         $17, 0x14($15)
    /* 33FCEC 0043FCEC 100072AE */  sw         $18, 0x10($19)
    /* 33FCF0 0043FCF0 2D106002 */  daddu      $2, $19, $0
  .L0043FCF4:
    /* 33FCF4 0043FCF4 0000B0DF */  ld         $16, 0x0($29)
    /* 33FCF8 0043FCF8 0800B1DF */  ld         $17, 0x8($29)
    /* 33FCFC 0043FCFC 1000B2DF */  ld         $18, 0x10($29)
    /* 33FD00 0043FD00 1800B3DF */  ld         $19, 0x18($29)
    /* 33FD04 0043FD04 2000B4DF */  ld         $20, 0x20($29)
    /* 33FD08 0043FD08 2800BFDF */  ld         $31, 0x28($29)
    /* 33FD0C 0043FD0C 0800E003 */  jr         $31
    /* 33FD10 0043FD10 3000BD27 */   addiu     $29, $29, 0x30
    /* 33FD14 0043FD14 00000000 */  nop
.size func_0043fc10, 0x108
