.section .text
.set noat
.set noreorder
glabel func_003e0c90
    /* 2E0C90 003E0C90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E0C94 003E0C94 02000224 */  addiu      $2, $0, 0x2
    /* 2E0C98 003E0C98 4000C210 */  beq        $6, $2, .L003E0D9C
    /* 2E0C9C 003E0C9C 0000BFFF */   sd        $31, 0x0($29)
    /* 2E0CA0 003E0CA0 01000224 */  addiu      $2, $0, 0x1
    /* 2E0CA4 003E0CA4 1E00C210 */  beq        $6, $2, .L003E0D20
    /* 2E0CA8 003E0CA8 00000000 */   nop
    /* 2E0CAC 003E0CAC 0300C010 */  beqz       $6, .L003E0CBC
    /* 2E0CB0 003E0CB0 00000000 */   nop
    /* 2E0CB4 003E0CB4 46000010 */  b          .L003E0DD0
    /* 2E0CB8 003E0CB8 1800A2AF */   sw        $2, 0x18($29)
  .L003E0CBC:
    /* 2E0CBC 003E0CBC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2E0CC0 003E0CC0 0200023C */  lui        $2, (0x20003 >> 16)
    /* 2E0CC4 003E0CC4 280083AC */  sw         $3, 0x28($4)
    /* 2E0CC8 003E0CC8 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 2E0CCC 003E0CCC 140083AC */  sw         $3, 0x14($4)
    /* 2E0CD0 003E0CD0 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2E0CD4 003E0CD4 000083AC */  sw         $3, 0x0($4)
    /* 2E0CD8 003E0CD8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2E0CDC 003E0CDC 100080AC */  sw         $0, 0x10($4)
    /* 2E0CE0 003E0CE0 03004234 */  ori        $2, $2, (0x20003 & 0xFFFF)
    /* 2E0CE4 003E0CE4 080080AC */  sw         $0, 0x8($4)
    /* 2E0CE8 003E0CE8 040080AC */  sw         $0, 0x4($4)
    /* 2E0CEC 003E0CEC 240080AC */  sw         $0, 0x24($4)
    /* 2E0CF0 003E0CF0 200080AC */  sw         $0, 0x20($4)
    /* 2E0CF4 003E0CF4 180080AC */  sw         $0, 0x18($4)
    /* 2E0CF8 003E0CF8 380080AC */  sw         $0, 0x38($4)
    /* 2E0CFC 003E0CFC 340080AC */  sw         $0, 0x34($4)
    /* 2E0D00 003E0D00 300080AC */  sw         $0, 0x30($4)
    /* 2E0D04 003E0D04 0C00838C */  lw         $3, 0xC($4)
    /* 2E0D08 003E0D08 25106200 */  or         $2, $3, $2
    /* 2E0D0C 003E0D0C 0C0082AC */  sw         $2, 0xC($4)
    /* 2E0D10 003E0D10 300082E4 */  swc1       $f2, 0x30($4)
    /* 2E0D14 003E0D14 340081E4 */  swc1       $f1, 0x34($4)
    /* 2E0D18 003E0D18 36000010 */  b          .L003E0DF4
    /* 2E0D1C 003E0D1C 380080E4 */   swc1      $f0, 0x38($4)
  .L003E0D20:
    /* 2E0D20 003E0D20 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2E0D24 003E0D24 100081C4 */  lwc1       $f1, 0x10($4)
    /* 2E0D28 003E0D28 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2E0D2C 003E0D2C 000082C4 */  lwc1       $f2, 0x0($4)
    /* 2E0D30 003E0D30 0800A6C4 */  lwc1       $f6, 0x8($5)
    /* 2E0D34 003E0D34 200083C4 */  lwc1       $f3, 0x20($4)
    /* 2E0D38 003E0D38 300080C4 */  lwc1       $f0, 0x30($4)
    /* 2E0D3C 003E0D3C 1A200146 */  mula.s     $f4, $f1
    /* 2E0D40 003E0D40 1E280246 */  madda.s    $f5, $f2
    /* 2E0D44 003E0D44 5C300346 */  madd.s     $f1, $f6, $f3
    /* 2E0D48 003E0D48 00000146 */  add.s      $f0, $f0, $f1
    /* 2E0D4C 003E0D4C 300080E4 */  swc1       $f0, 0x30($4)
    /* 2E0D50 003E0D50 140081C4 */  lwc1       $f1, 0x14($4)
    /* 2E0D54 003E0D54 040082C4 */  lwc1       $f2, 0x4($4)
    /* 2E0D58 003E0D58 240083C4 */  lwc1       $f3, 0x24($4)
    /* 2E0D5C 003E0D5C 340080C4 */  lwc1       $f0, 0x34($4)
    /* 2E0D60 003E0D60 1A200146 */  mula.s     $f4, $f1
    /* 2E0D64 003E0D64 1E280246 */  madda.s    $f5, $f2
    /* 2E0D68 003E0D68 5C300346 */  madd.s     $f1, $f6, $f3
    /* 2E0D6C 003E0D6C 00000146 */  add.s      $f0, $f0, $f1
    /* 2E0D70 003E0D70 340080E4 */  swc1       $f0, 0x34($4)
    /* 2E0D74 003E0D74 180081C4 */  lwc1       $f1, 0x18($4)
    /* 2E0D78 003E0D78 080082C4 */  lwc1       $f2, 0x8($4)
    /* 2E0D7C 003E0D7C 280083C4 */  lwc1       $f3, 0x28($4)
    /* 2E0D80 003E0D80 380080C4 */  lwc1       $f0, 0x38($4)
    /* 2E0D84 003E0D84 1A200146 */  mula.s     $f4, $f1
    /* 2E0D88 003E0D88 1E280246 */  madda.s    $f5, $f2
    /* 2E0D8C 003E0D8C 5C300346 */  madd.s     $f1, $f6, $f3
    /* 2E0D90 003E0D90 00000146 */  add.s      $f0, $f0, $f1
    /* 2E0D94 003E0D94 17000010 */  b          .L003E0DF4
    /* 2E0D98 003E0D98 380080E4 */   swc1      $f0, 0x38($4)
  .L003E0D9C:
    /* 2E0D9C 003E0D9C 300083C4 */  lwc1       $f3, 0x30($4)
    /* 2E0DA0 003E0DA0 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2E0DA4 003E0DA4 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 2E0DA8 003E0DA8 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2E0DAC 003E0DAC 00180046 */  add.s      $f0, $f3, $f0
    /* 2E0DB0 003E0DB0 300080E4 */  swc1       $f0, 0x30($4)
    /* 2E0DB4 003E0DB4 340080C4 */  lwc1       $f0, 0x34($4)
    /* 2E0DB8 003E0DB8 00000246 */  add.s      $f0, $f0, $f2
    /* 2E0DBC 003E0DBC 340080E4 */  swc1       $f0, 0x34($4)
    /* 2E0DC0 003E0DC0 380080C4 */  lwc1       $f0, 0x38($4)
    /* 2E0DC4 003E0DC4 00000146 */  add.s      $f0, $f0, $f1
    /* 2E0DC8 003E0DC8 0A000010 */  b          .L003E0DF4
    /* 2E0DCC 003E0DCC 380080E4 */   swc1      $f0, 0x38($4)
  .L003E0DD0:
    /* 2E0DD0 003E0DD0 7100053C */  lui        $5, %hi(D_0070B6F0)
    /* 2E0DD4 003E0DD4 0080023C */  lui        $2, (0x80000003 >> 16)
    /* 2E0DD8 003E0DD8 F0B6A524 */  addiu      $5, $5, %lo(D_0070B6F0)
    /* 2E0DDC 003E0DDC 647D0F0C */  jal        func_003df590
    /* 2E0DE0 003E0DE0 03004434 */   ori       $4, $2, (0x80000003 & 0xFFFF)
    /* 2E0DE4 003E0DE4 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2E0DE8 003E0DE8 347D0F0C */  jal        func_003df4d0
    /* 2E0DEC 003E0DEC 1800A427 */   addiu     $4, $29, 0x18
    /* 2E0DF0 003E0DF0 2D200000 */  daddu      $4, $0, $0
  .L003E0DF4:
    /* 2E0DF4 003E0DF4 0C00858C */  lw         $5, 0xC($4)
    /* 2E0DF8 003E0DF8 FDFF023C */  lui        $2, (0xFFFDFFFF >> 16)
    /* 2E0DFC 003E0DFC FFFF4334 */  ori        $3, $2, (0xFFFDFFFF & 0xFFFF)
    /* 2E0E00 003E0E00 2D108000 */  daddu      $2, $4, $0
    /* 2E0E04 003E0E04 2418A300 */  and        $3, $5, $3
    /* 2E0E08 003E0E08 0C0083AC */  sw         $3, 0xC($4)
    /* 2E0E0C 003E0E0C 0000BFDF */  ld         $31, 0x0($29)
    /* 2E0E10 003E0E10 0800E003 */  jr         $31
    /* 2E0E14 003E0E14 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E0E18 003E0E18 00000000 */  nop
    /* 2E0E1C 003E0E1C 00000000 */  nop
.size func_003e0c90, 0x190
