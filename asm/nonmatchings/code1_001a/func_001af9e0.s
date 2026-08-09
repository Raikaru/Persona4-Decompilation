.section .text
.set noat
.set noreorder
glabel func_001af9e0
    /* AF9E0 001AF9E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AF9E4 001AF9E4 1000BFFF */  sd         $31, 0x10($29)
    /* AF9E8 001AF9E8 0000B07F */  sq         $16, 0x0($29)
    /* AF9EC 001AF9EC 2D808000 */  daddu      $16, $4, $0
    /* AF9F0 001AF9F0 000084DC */  ld         $4, 0x0($4)
    /* AF9F4 001AF9F4 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* AF9F8 001AF9F8 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* AF9FC 001AF9FC 3C180200 */  dsll32     $3, $2, 0
    /* AFA00 001AFA00 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* AFA04 001AFA04 38140200 */  dsll       $2, $2, 16
    /* AFA08 001AFA08 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* AFA0C 001AFA0C 25284300 */  or         $5, $2, $3
    /* AFA10 001AFA10 FC4E060C */  jal        func_00193bf0
    /* AFA14 001AFA14 00000000 */   nop
    /* AFA18 001AFA18 05004014 */  bnez       $2, .L001AFA30
    /* AFA1C 001AFA1C 00000000 */   nop
    /* AFA20 001AFA20 2D200002 */  daddu      $4, $16, $0
    /* AFA24 001AFA24 21000524 */  addiu      $5, $0, 0x21
    /* AFA28 001AFA28 00C2060C */  jal        func_001b0800
    /* AFA2C 001AFA2C 00000000 */   nop
  .L001AFA30:
    /* AFA30 001AFA30 1000BFDF */  ld         $31, 0x10($29)
    /* AFA34 001AFA34 0000B07B */  lq         $16, 0x0($29)
    /* AFA38 001AFA38 2000BD27 */  addiu      $29, $29, 0x20
    /* AFA3C 001AFA3C 0800E003 */  jr         $31
    /* AFA40 001AFA40 00000000 */   nop
    /* AFA44 001AFA44 00000000 */  nop
    /* AFA48 001AFA48 00000000 */  nop
    /* AFA4C 001AFA4C 00000000 */  nop
.size func_001af9e0, 0x70
