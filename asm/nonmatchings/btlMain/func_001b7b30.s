.section .text
.set noat
.set noreorder
glabel func_001b7b30
    /* B7B30 001B7B30 C0FFBD27 */  addiu      $29, $29, -0x40
    /* B7B34 001B7B34 2000BFFF */  sd         $31, 0x20($29)
    /* B7B38 001B7B38 1000B07F */  sq         $16, 0x10($29)
    /* B7B3C 001B7B3C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* B7B40 001B7B40 0000B4E7 */  swc1       $f20, 0x0($29)
    /* B7B44 001B7B44 2D808000 */  daddu      $16, $4, $0
    /* B7B48 001B7B48 ACB3828F */  lw         $2, -0x4C54($28)
    /* B7B4C 001B7B4C 0C00438C */  lw         $3, 0xC($2)
    /* B7B50 001B7B50 02006230 */  andi       $2, $3, 0x2
    /* B7B54 001B7B54 04004014 */  bnez       $2, .L001B7B68
    /* B7B58 001B7B58 00000000 */   nop
    /* B7B5C 001B7B5C 01000224 */  addiu      $2, $0, 0x1
    /* B7B60 001B7B60 A7000010 */  b          .L001B7E00
    /* B7B64 001B7B64 00000000 */   nop
  .L001B7B68:
    /* B7B68 001B7B68 0002023C */  lui        $2, (0x2000000 >> 16)
    /* B7B6C 001B7B6C 24106200 */  and        $2, $3, $2
    /* B7B70 001B7B70 04004014 */  bnez       $2, .L001B7B84
    /* B7B74 001B7B74 00000000 */   nop
    /* B7B78 001B7B78 01000224 */  addiu      $2, $0, 0x1
    /* B7B7C 001B7B7C A0000010 */  b          .L001B7E00
    /* B7B80 001B7B80 00000000 */   nop
  .L001B7B84:
    /* B7B84 001B7B84 2400028E */  lw         $2, 0x24($16)
    /* B7B88 001B7B88 15004014 */  bnez       $2, .L001B7BE0
    /* B7B8C 001B7B8C 00000000 */   nop
    /* B7B90 001B7B90 2827050C */  jal        func_00149ca0
    /* B7B94 001B7B94 00000000 */   nop
    /* B7B98 001B7B98 000043C4 */  lwc1       $f3, 0x0($2)
    /* B7B9C 001B7B9C 040042C4 */  lwc1       $f2, 0x4($2)
    /* B7BA0 001B7BA0 080041C4 */  lwc1       $f1, 0x8($2)
    /* B7BA4 001B7BA4 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* B7BA8 001B7BA8 000003E6 */  swc1       $f3, 0x0($16)
    /* B7BAC 001B7BAC 040002E6 */  swc1       $f2, 0x4($16)
    /* B7BB0 001B7BB0 080001E6 */  swc1       $f1, 0x8($16)
    /* B7BB4 001B7BB4 0C0000E6 */  swc1       $f0, 0xC($16)
    /* B7BB8 001B7BB8 3827050C */  jal        func_00149ce0
    /* B7BBC 001B7BBC 00000000 */   nop
    /* B7BC0 001B7BC0 000043C4 */  lwc1       $f3, 0x0($2)
    /* B7BC4 001B7BC4 040042C4 */  lwc1       $f2, 0x4($2)
    /* B7BC8 001B7BC8 080041C4 */  lwc1       $f1, 0x8($2)
    /* B7BCC 001B7BCC 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* B7BD0 001B7BD0 100003E6 */  swc1       $f3, 0x10($16)
    /* B7BD4 001B7BD4 140002E6 */  swc1       $f2, 0x14($16)
    /* B7BD8 001B7BD8 180001E6 */  swc1       $f1, 0x18($16)
    /* B7BDC 001B7BDC 1C0000E6 */  swc1       $f0, 0x1C($16)
  .L001B7BE0:
    /* B7BE0 001B7BE0 2000048E */  lw         $4, 0x20($16)
    /* B7BE4 001B7BE4 2400028E */  lw         $2, 0x24($16)
    /* B7BE8 001B7BE8 2B084400 */  sltu       $1, $2, $4
    /* B7BEC 001B7BEC 67002010 */  beqz       $1, .L001B7D8C
    /* B7BF0 001B7BF0 00000000 */   nop
    /* B7BF4 001B7BF4 06004004 */  bltz       $2, .L001B7C10
    /* B7BF8 001B7BF8 00000000 */   nop
    /* B7BFC 001B7BFC 00008244 */  mtc1       $2, $f0
    /* B7C00 001B7C00 00000000 */  nop
    /* B7C04 001B7C04 60008046 */  cvt.s.w    $f1, $f0
    /* B7C08 001B7C08 08000010 */  b          .L001B7C2C
    /* B7C0C 001B7C0C 00000000 */   nop
  .L001B7C10:
    /* B7C10 001B7C10 42180200 */  srl        $3, $2, 1
    /* B7C14 001B7C14 01004230 */  andi       $2, $2, 0x1
    /* B7C18 001B7C18 25186200 */  or         $3, $3, $2
    /* B7C1C 001B7C1C 00008344 */  mtc1       $3, $f0
    /* B7C20 001B7C20 00000000 */  nop
    /* B7C24 001B7C24 60008046 */  cvt.s.w    $f1, $f0
    /* B7C28 001B7C28 40080146 */  add.s      $f1, $f1, $f1
  .L001B7C2C:
    /* B7C2C 001B7C2C 06008004 */  bltz       $4, .L001B7C48
    /* B7C30 001B7C30 00000000 */   nop
    /* B7C34 001B7C34 00008444 */  mtc1       $4, $f0
    /* B7C38 001B7C38 00000000 */  nop
    /* B7C3C 001B7C3C 20008046 */  cvt.s.w    $f0, $f0
    /* B7C40 001B7C40 08000010 */  b          .L001B7C64
    /* B7C44 001B7C44 00000000 */   nop
  .L001B7C48:
    /* B7C48 001B7C48 42180400 */  srl        $3, $4, 1
    /* B7C4C 001B7C4C 01008230 */  andi       $2, $4, 0x1
    /* B7C50 001B7C50 25186200 */  or         $3, $3, $2
    /* B7C54 001B7C54 00008344 */  mtc1       $3, $f0
    /* B7C58 001B7C58 00000000 */  nop
    /* B7C5C 001B7C5C 20008046 */  cvt.s.w    $f0, $f0
    /* B7C60 001B7C60 00000046 */  add.s      $f0, $f0, $f0
  .L001B7C64:
    /* B7C64 001B7C64 00000000 */  nop
    /* B7C68 001B7C68 00000000 */  nop
    /* B7C6C 001B7C6C 430D0046 */  div.s      $f21, $f1, $f0
    /* B7C70 001B7C70 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* B7C74 001B7C74 00008244 */  mtc1       $2, $f0
    /* B7C78 001B7C78 00000000 */  nop
    /* B7C7C 001B7C7C 01051546 */  sub.s      $f20, $f0, $f21
    /* B7C80 001B7C80 000000C6 */  lwc1       $f0, 0x0($16)
    /* B7C84 001B7C84 C2011446 */  mul.s      $f7, $f0, $f20
    /* B7C88 001B7C88 040000C6 */  lwc1       $f0, 0x4($16)
    /* B7C8C 001B7C8C 82011446 */  mul.s      $f6, $f0, $f20
    /* B7C90 001B7C90 080000C6 */  lwc1       $f0, 0x8($16)
    /* B7C94 001B7C94 42011446 */  mul.s      $f5, $f0, $f20
    /* B7C98 001B7C98 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* B7C9C 001B7C9C 1A001446 */  mula.s     $f0, $f20
    /* B7CA0 001B7CA0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B7CA4 001B7CA4 BC0140C4 */  lwc1       $f0, 0x1BC($2)
    /* B7CA8 001B7CA8 02011546 */  mul.s      $f4, $f0, $f21
    /* B7CAC 001B7CAC C00140C4 */  lwc1       $f0, 0x1C0($2)
    /* B7CB0 001B7CB0 C2001546 */  mul.s      $f3, $f0, $f21
    /* B7CB4 001B7CB4 C40140C4 */  lwc1       $f0, 0x1C4($2)
    /* B7CB8 001B7CB8 82001546 */  mul.s      $f2, $f0, $f21
    /* B7CBC 001B7CBC C80141C4 */  lwc1       $f1, 0x1C8($2)
    /* B7CC0 001B7CC0 00380446 */  add.s      $f0, $f7, $f4
    /* B7CC4 001B7CC4 3000A0E7 */  swc1       $f0, 0x30($29)
    /* B7CC8 001B7CC8 00300346 */  add.s      $f0, $f6, $f3
    /* B7CCC 001B7CCC 3400A0E7 */  swc1       $f0, 0x34($29)
    /* B7CD0 001B7CD0 00280246 */  add.s      $f0, $f5, $f2
    /* B7CD4 001B7CD4 3800A0E7 */  swc1       $f0, 0x38($29)
    /* B7CD8 001B7CD8 1C081546 */  madd.s     $f0, $f1, $f21
    /* B7CDC 001B7CDC 3C00A0E7 */  swc1       $f0, 0x3C($29)
    /* B7CE0 001B7CE0 2827050C */  jal        func_00149ca0
    /* B7CE4 001B7CE4 00000000 */   nop
    /* B7CE8 001B7CE8 3000A3C7 */  lwc1       $f3, 0x30($29)
    /* B7CEC 001B7CEC 3400A2C7 */  lwc1       $f2, 0x34($29)
    /* B7CF0 001B7CF0 3800A1C7 */  lwc1       $f1, 0x38($29)
    /* B7CF4 001B7CF4 3C00A0C7 */  lwc1       $f0, 0x3C($29)
    /* B7CF8 001B7CF8 000043E4 */  swc1       $f3, 0x0($2)
    /* B7CFC 001B7CFC 040042E4 */  swc1       $f2, 0x4($2)
    /* B7D00 001B7D00 080041E4 */  swc1       $f1, 0x8($2)
    /* B7D04 001B7D04 0C0040E4 */  swc1       $f0, 0xC($2)
    /* B7D08 001B7D08 ACB3828F */  lw         $2, -0x4C54($28)
    /* B7D0C 001B7D0C 100001C6 */  lwc1       $f1, 0x10($16)
    /* B7D10 001B7D10 CC0140C4 */  lwc1       $f0, 0x1CC($2)
    /* B7D14 001B7D14 1A001546 */  mula.s     $f0, $f21
    /* B7D18 001B7D18 1C081446 */  madd.s     $f0, $f1, $f20
    /* B7D1C 001B7D1C 3000A0E7 */  swc1       $f0, 0x30($29)
    /* B7D20 001B7D20 140001C6 */  lwc1       $f1, 0x14($16)
    /* B7D24 001B7D24 D00140C4 */  lwc1       $f0, 0x1D0($2)
    /* B7D28 001B7D28 1A001546 */  mula.s     $f0, $f21
    /* B7D2C 001B7D2C 1C081446 */  madd.s     $f0, $f1, $f20
    /* B7D30 001B7D30 3400A0E7 */  swc1       $f0, 0x34($29)
    /* B7D34 001B7D34 180001C6 */  lwc1       $f1, 0x18($16)
    /* B7D38 001B7D38 D40140C4 */  lwc1       $f0, 0x1D4($2)
    /* B7D3C 001B7D3C 1A001546 */  mula.s     $f0, $f21
    /* B7D40 001B7D40 1C081446 */  madd.s     $f0, $f1, $f20
    /* B7D44 001B7D44 3800A0E7 */  swc1       $f0, 0x38($29)
    /* B7D48 001B7D48 1C0001C6 */  lwc1       $f1, 0x1C($16)
    /* B7D4C 001B7D4C D80140C4 */  lwc1       $f0, 0x1D8($2)
    /* B7D50 001B7D50 1A001546 */  mula.s     $f0, $f21
    /* B7D54 001B7D54 1C081446 */  madd.s     $f0, $f1, $f20
    /* B7D58 001B7D58 3C00A0E7 */  swc1       $f0, 0x3C($29)
    /* B7D5C 001B7D5C 3827050C */  jal        func_00149ce0
    /* B7D60 001B7D60 00000000 */   nop
    /* B7D64 001B7D64 3000A3C7 */  lwc1       $f3, 0x30($29)
    /* B7D68 001B7D68 3400A2C7 */  lwc1       $f2, 0x34($29)
    /* B7D6C 001B7D6C 3800A1C7 */  lwc1       $f1, 0x38($29)
    /* B7D70 001B7D70 3C00A0C7 */  lwc1       $f0, 0x3C($29)
    /* B7D74 001B7D74 000043E4 */  swc1       $f3, 0x0($2)
    /* B7D78 001B7D78 040042E4 */  swc1       $f2, 0x4($2)
    /* B7D7C 001B7D7C 080041E4 */  swc1       $f1, 0x8($2)
    /* B7D80 001B7D80 0C0040E4 */  swc1       $f0, 0xC($2)
    /* B7D84 001B7D84 1A000010 */  b          .L001B7DF0
    /* B7D88 001B7D88 00000000 */   nop
  .L001B7D8C:
    /* B7D8C 001B7D8C ACB3908F */  lw         $16, -0x4C54($28)
    /* B7D90 001B7D90 2827050C */  jal        func_00149ca0
    /* B7D94 001B7D94 00000000 */   nop
    /* B7D98 001B7D98 BC0103C6 */  lwc1       $f3, 0x1BC($16)
    /* B7D9C 001B7D9C C00102C6 */  lwc1       $f2, 0x1C0($16)
    /* B7DA0 001B7DA0 C40101C6 */  lwc1       $f1, 0x1C4($16)
    /* B7DA4 001B7DA4 C80100C6 */  lwc1       $f0, 0x1C8($16)
    /* B7DA8 001B7DA8 000043E4 */  swc1       $f3, 0x0($2)
    /* B7DAC 001B7DAC 040042E4 */  swc1       $f2, 0x4($2)
    /* B7DB0 001B7DB0 080041E4 */  swc1       $f1, 0x8($2)
    /* B7DB4 001B7DB4 0C0040E4 */  swc1       $f0, 0xC($2)
    /* B7DB8 001B7DB8 ACB3908F */  lw         $16, -0x4C54($28)
    /* B7DBC 001B7DBC 3827050C */  jal        func_00149ce0
    /* B7DC0 001B7DC0 00000000 */   nop
    /* B7DC4 001B7DC4 CC0103C6 */  lwc1       $f3, 0x1CC($16)
    /* B7DC8 001B7DC8 D00102C6 */  lwc1       $f2, 0x1D0($16)
    /* B7DCC 001B7DCC D40101C6 */  lwc1       $f1, 0x1D4($16)
    /* B7DD0 001B7DD0 D80100C6 */  lwc1       $f0, 0x1D8($16)
    /* B7DD4 001B7DD4 000043E4 */  swc1       $f3, 0x0($2)
    /* B7DD8 001B7DD8 040042E4 */  swc1       $f2, 0x4($2)
    /* B7DDC 001B7DDC 080041E4 */  swc1       $f1, 0x8($2)
    /* B7DE0 001B7DE0 0C0040E4 */  swc1       $f0, 0xC($2)
    /* B7DE4 001B7DE4 01000224 */  addiu      $2, $0, 0x1
    /* B7DE8 001B7DE8 05000010 */  b          .L001B7E00
    /* B7DEC 001B7DEC 00000000 */   nop
  .L001B7DF0:
    /* B7DF0 001B7DF0 2400028E */  lw         $2, 0x24($16)
    /* B7DF4 001B7DF4 01004224 */  addiu      $2, $2, 0x1
    /* B7DF8 001B7DF8 240002AE */  sw         $2, 0x24($16)
    /* B7DFC 001B7DFC 2D100000 */  daddu      $2, $0, $0
  .L001B7E00:
    /* B7E00 001B7E00 2000BFDF */  ld         $31, 0x20($29)
    /* B7E04 001B7E04 1000B07B */  lq         $16, 0x10($29)
    /* B7E08 001B7E08 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* B7E0C 001B7E0C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* B7E10 001B7E10 4000BD27 */  addiu      $29, $29, 0x40
    /* B7E14 001B7E14 0800E003 */  jr         $31
    /* B7E18 001B7E18 00000000 */   nop
    /* B7E1C 001B7E1C 00000000 */  nop
.size func_001b7b30, 0x2f0
