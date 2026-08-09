.section .text
.set noat
.set noreorder
glabel func_004d6b10
    /* 3D6B10 004D6B10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D6B14 004D6B14 7200023C */  lui        $2, %hi(D_007188B0)
    /* 3D6B18 004D6B18 7200033C */  lui        $3, %hi(D_007188C0)
    /* 3D6B1C 004D6B1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6B20 004D6B20 2000BFFF */  sd         $31, 0x20($29)
    /* 3D6B24 004D6B24 B08844AC */  sw         $4, %lo(D_007188B0)($2)
    /* 3D6B28 004D6B28 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6B2C 004D6B2C C0887124 */  addiu      $17, $3, %lo(D_007188C0)
    /* 3D6B30 004D6B30 1000B2FF */  sd         $18, 0x10($29)
    /* 3D6B34 004D6B34 0F001224 */  addiu      $18, $0, 0xF
    /* 3D6B38 004D6B38 1800B3FF */  sd         $19, 0x18($29)
    /* 3D6B3C 004D6B3C 01001324 */  addiu      $19, $0, 0x1
  .L004D6B40:
    /* 3D6B40 004D6B40 00002282 */  lb         $2, 0x0($17)
    /* 3D6B44 004D6B44 17005354 */  bnel       $2, $19, .L004D6BA4
    /* 3D6B48 004D6B48 FFFF5226 */   addiu     $18, $18, -0x1
    /* 3D6B4C 004D6B4C 03002282 */  lb         $2, 0x3($17)
    /* 3D6B50 004D6B50 0E004018 */  blez       $2, .L004D6B8C
    /* 3D6B54 004D6B54 2D800000 */   daddu     $16, $0, $0
    /* 3D6B58 004D6B58 2D280002 */  daddu      $5, $16, $0
    /* 3D6B5C 004D6B5C 00000000 */  nop
  .L004D6B60:
    /* 3D6B60 004D6B60 E853130C */  jal        func_004d4fa0
    /* 3D6B64 004D6B64 2D202002 */   daddu     $4, $17, $0
    /* 3D6B68 004D6B68 2D202002 */  daddu      $4, $17, $0
    /* 3D6B6C 004D6B6C 2D280002 */  daddu      $5, $16, $0
    /* 3D6B70 004D6B70 01001026 */  addiu      $16, $16, 0x1
    /* 3D6B74 004D6B74 9053130C */  jal        func_004d4e40
    /* 3D6B78 004D6B78 2D304000 */   daddu     $6, $2, $0
    /* 3D6B7C 004D6B7C 03002282 */  lb         $2, 0x3($17)
    /* 3D6B80 004D6B80 2A100202 */  slt        $2, $16, $2
    /* 3D6B84 004D6B84 F6FF4014 */  bnez       $2, .L004D6B60
    /* 3D6B88 004D6B88 2D280002 */   daddu     $5, $16, $0
  .L004D6B8C:
    /* 3D6B8C 004D6B8C 3854130C */  jal        func_004d50e0
    /* 3D6B90 004D6B90 2D202002 */   daddu     $4, $17, $0
    /* 3D6B94 004D6B94 2D202002 */  daddu      $4, $17, $0
    /* 3D6B98 004D6B98 0854130C */  jal        func_004d5020
    /* 3D6B9C 004D6B9C 2D284000 */   daddu     $5, $2, $0
    /* 3D6BA0 004D6BA0 FFFF5226 */  addiu      $18, $18, -0x1
  .L004D6BA4:
    /* 3D6BA4 004D6BA4 E6FF4106 */  bgez       $18, .L004D6B40
    /* 3D6BA8 004D6BA8 C8003126 */   addiu     $17, $17, 0xC8
    /* 3D6BAC 004D6BAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6BB0 004D6BB0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6BB4 004D6BB4 1000B2DF */  ld         $18, 0x10($29)
    /* 3D6BB8 004D6BB8 1800B3DF */  ld         $19, 0x18($29)
    /* 3D6BBC 004D6BBC 2000BFDF */  ld         $31, 0x20($29)
    /* 3D6BC0 004D6BC0 0800E003 */  jr         $31
    /* 3D6BC4 004D6BC4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004d6b10, 0xb8
