.section .text
.set noat
.set noreorder
glabel func_0022a6b0
    /* 12A6B0 0022A6B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12A6B4 0022A6B4 0000BFFF */  sd         $31, 0x0($29)
    /* 12A6B8 0022A6B8 000084DC */  ld         $4, 0x0($4)
    /* 12A6BC 0022A6BC FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* 12A6C0 0022A6C0 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* 12A6C4 0022A6C4 3C180200 */  dsll32     $3, $2, 0
    /* 12A6C8 0022A6C8 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 12A6CC 0022A6CC 38140200 */  dsll       $2, $2, 16
    /* 12A6D0 0022A6D0 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* 12A6D4 0022A6D4 25284300 */  or         $5, $2, $3
    /* 12A6D8 0022A6D8 FC4E060C */  jal        func_00193bf0
    /* 12A6DC 0022A6DC 00000000 */   nop
    /* 12A6E0 0022A6E0 0E004014 */  bnez       $2, .L0022A71C
    /* 12A6E4 0022A6E4 00000000 */   nop
    /* 12A6E8 0022A6E8 FF150424 */  addiu      $4, $0, 0x15FF
    /* 12A6EC 0022A6EC 01000524 */  addiu      $5, $0, 0x1
    /* 12A6F0 0022A6F0 E418040C */  jal        func_00106390
    /* 12A6F4 0022A6F4 00000000 */   nop
    /* 12A6F8 0022A6F8 ACB3848F */  lw         $4, -0x4C54($28)
    /* 12A6FC 0022A6FC 0C00838C */  lw         $3, 0xC($4)
    /* 12A700 0022A700 F7FF023C */  lui        $2, (0xFFF7FFFF >> 16)
    /* 12A704 0022A704 FFFF4234 */  ori        $2, $2, (0xFFF7FFFF & 0xFFFF)
    /* 12A708 0022A708 24106200 */  and        $2, $3, $2
    /* 12A70C 0022A70C 0C0082AC */  sw         $2, 0xC($4)
    /* 12A710 0022A710 2D100000 */  daddu      $2, $0, $0
    /* 12A714 0022A714 02000010 */  b          .L0022A720
    /* 12A718 0022A718 00000000 */   nop
  .L0022A71C:
    /* 12A71C 0022A71C 01000224 */  addiu      $2, $0, 0x1
  .L0022A720:
    /* 12A720 0022A720 0000BFDF */  ld         $31, 0x0($29)
    /* 12A724 0022A724 1000BD27 */  addiu      $29, $29, 0x10
    /* 12A728 0022A728 0800E003 */  jr         $31
    /* 12A72C 0022A72C 00000000 */   nop
.size func_0022a6b0, 0x80
