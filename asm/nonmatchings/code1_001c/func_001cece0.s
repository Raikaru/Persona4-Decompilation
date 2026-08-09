.section .text
.set noat
.set noreorder
glabel func_001cece0
    /* CECE0 001CECE0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* CECE4 001CECE4 3000BFFF */  sd         $31, 0x30($29)
    /* CECE8 001CECE8 2000B17F */  sq         $17, 0x20($29)
    /* CECEC 001CECEC 1000B07F */  sq         $16, 0x10($29)
    /* CECF0 001CECF0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CECF4 001CECF4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CECF8 001CECF8 2D808000 */  daddu      $16, $4, $0
    /* CECFC 001CECFC E000828C */  lw         $2, 0xE0($4)
    /* CED00 001CED00 3000518C */  lw         $17, 0x30($2)
    /* CED04 001CED04 4000A427 */  addiu      $4, $29, 0x40
    /* CED08 001CED08 9C000526 */  addiu      $5, $16, 0x9C
    /* CED0C 001CED0C 58F5060C */  jal        func_001bd560
    /* CED10 001CED10 00000000 */   nop
    /* CED14 001CED14 03000424 */  addiu      $4, $0, 0x3
    /* CED18 001CED18 01000524 */  addiu      $5, $0, 0x1
    /* CED1C 001CED1C A000A627 */  addiu      $6, $29, 0xA0
    /* CED20 001CED20 2D380000 */  daddu      $7, $0, $0
    /* CED24 001CED24 2D400000 */  daddu      $8, $0, $0
    /* CED28 001CED28 2D48A000 */  daddu      $9, $5, $0
    /* CED2C 001CED2C 1058060C */  jal        func_00196040
    /* CED30 001CED30 00000000 */   nop
    /* CED34 001CED34 06050046 */  mov.s      $f20, $f0
    /* CED38 001CED38 A400A0AF */  sw         $0, 0xA4($29)
    /* CED3C 001CED3C 2D202002 */  daddu      $4, $17, $0
    /* CED40 001CED40 9000A527 */  addiu      $5, $29, 0x90
    /* CED44 001CED44 3C56060C */  jal        func_001958f0
    /* CED48 001CED48 00000000 */   nop
    /* CED4C 001CED4C 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CED50 001CED50 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CED54 001CED54 C2080046 */  mul.s      $f3, $f1, $f0
    /* CED58 001CED58 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CED5C 001CED5C 00108244 */  mtc1       $2, $f2
    /* CED60 001CED60 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* CED64 001CED64 00008044 */  mtc1       $0, $f0
    /* CED68 001CED68 00000000 */  nop
    /* CED6C 001CED6C 18000146 */  adda.s     $f0, $f1
    /* CED70 001CED70 1C100346 */  madd.s     $f0, $f2, $f3
    /* CED74 001CED74 9400A0E7 */  swc1       $f0, 0x94($29)
    /* CED78 001CED78 6800A427 */  addiu      $4, $29, 0x68
    /* CED7C 001CED7C 9000A527 */  addiu      $5, $29, 0x90
    /* CED80 001CED80 A000A627 */  addiu      $6, $29, 0xA0
    /* CED84 001CED84 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CED88 001CED88 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CED8C 001CED8C E0F5060C */  jal        func_001bd780
    /* CED90 001CED90 00000000 */   nop
    /* CED94 001CED94 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CED98 001CED98 00088244 */  mtc1       $2, $f1
    /* CED9C 001CED9C B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CEDA0 001CEDA0 42080046 */  mul.s      $f1, $f1, $f0
    /* CEDA4 001CEDA4 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CEDA8 001CEDA8 02030146 */  mul.s      $f12, $f0, $f1
    /* CEDAC 001CEDAC 1A2E110C */  jal        func_0044b868
    /* CEDB0 001CEDB0 00000000 */   nop
    /* CEDB4 001CEDB4 00000000 */  nop
    /* CEDB8 001CEDB8 00000000 */  nop
    /* CEDBC 001CEDBC 03A50046 */  div.s      $f20, $f20, $f0
    /* CEDC0 001CEDC0 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* CEDC4 001CEDC4 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CEDC8 001CEDC8 01080046 */  sub.s      $f0, $f1, $f0
    /* CEDCC 001CEDCC 8000A0E7 */  swc1       $f0, 0x80($29)
    /* CEDD0 001CEDD0 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* CEDD4 001CEDD4 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CEDD8 001CEDD8 01080046 */  sub.s      $f0, $f1, $f0
    /* CEDDC 001CEDDC 8400A0E7 */  swc1       $f0, 0x84($29)
    /* CEDE0 001CEDE0 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* CEDE4 001CEDE4 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CEDE8 001CEDE8 01080046 */  sub.s      $f0, $f1, $f0
    /* CEDEC 001CEDEC 8800A0E7 */  swc1       $f0, 0x88($29)
    /* CEDF0 001CEDF0 8000A427 */  addiu      $4, $29, 0x80
    /* CEDF4 001CEDF4 2D288000 */  daddu      $5, $4, $0
    /* CEDF8 001CEDF8 2C900F0C */  jal        func_003e40b0
    /* CEDFC 001CEDFC 00000000 */   nop
    /* CEE00 001CEE00 46050046 */  mov.s      $f21, $f0
    /* CEE04 001CEE04 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CEE08 001CEE08 00088244 */  mtc1       $2, $f1
    /* CEE0C 001CEE0C B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CEE10 001CEE10 42080046 */  mul.s      $f1, $f1, $f0
    /* CEE14 001CEE14 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CEE18 001CEE18 02030146 */  mul.s      $f12, $f0, $f1
    /* CEE1C 001CEE1C 1A2E110C */  jal        func_0044b868
    /* CEE20 001CEE20 00000000 */   nop
    /* CEE24 001CEE24 900022C6 */  lwc1       $f2, 0x90($17)
    /* CEE28 001CEE28 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* CEE2C 001CEE2C 82100146 */  mul.s      $f2, $f2, $f1
    /* CEE30 001CEE30 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* CEE34 001CEE34 00088244 */  mtc1       $2, $f1
    /* CEE38 001CEE38 00000000 */  nop
    /* CEE3C 001CEE3C 42080246 */  mul.s      $f1, $f1, $f2
    /* CEE40 001CEE40 03080046 */  div.s      $f0, $f1, $f0
    /* CEE44 001CEE44 00000000 */  nop
    /* CEE48 001CEE48 00A80046 */  add.s      $f0, $f21, $f0
    /* CEE4C 001CEE4C 36A00046 */  c.le.s     $f20, $f0
    /* CEE50 001CEE50 03000145 */  bc1t       .L001CEE60
    /* CEE54 001CEE54 00000000 */   nop
    /* CEE58 001CEE58 02000010 */  b          .L001CEE64
    /* CEE5C 001CEE5C 00000000 */   nop
  .L001CEE60:
    /* CEE60 001CEE60 06050046 */  mov.s      $f20, $f0
  .L001CEE64:
    /* CEE64 001CEE64 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CEE68 001CEE68 C2001446 */  mul.s      $f3, $f0, $f20
    /* CEE6C 001CEE6C 8000A3E7 */  swc1       $f3, 0x80($29)
    /* CEE70 001CEE70 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* CEE74 001CEE74 82001446 */  mul.s      $f2, $f0, $f20
    /* CEE78 001CEE78 8400A2E7 */  swc1       $f2, 0x84($29)
    /* CEE7C 001CEE7C 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CEE80 001CEE80 42001446 */  mul.s      $f1, $f0, $f20
    /* CEE84 001CEE84 8800A1E7 */  swc1       $f1, 0x88($29)
    /* CEE88 001CEE88 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CEE8C 001CEE8C 00180046 */  add.s      $f0, $f3, $f0
    /* CEE90 001CEE90 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* CEE94 001CEE94 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CEE98 001CEE98 00100046 */  add.s      $f0, $f2, $f0
    /* CEE9C 001CEE9C 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CEEA0 001CEEA0 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CEEA4 001CEEA4 00080046 */  add.s      $f0, $f1, $f0
    /* CEEA8 001CEEA8 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CEEAC 001CEEAC ACB3828F */  lw         $2, -0x4C54($28)
    /* CEEB0 001CEEB0 0C00438C */  lw         $3, 0xC($2)
    /* CEEB4 001CEEB4 2000023C */  lui        $2, (0x200000 >> 16)
    /* CEEB8 001CEEB8 24106200 */  and        $2, $3, $2
    /* CEEBC 001CEEBC 05004014 */  bnez       $2, .L001CEED4
    /* CEEC0 001CEEC0 00000000 */   nop
    /* CEEC4 001CEEC4 5C00A427 */  addiu      $4, $29, 0x5C
    /* CEEC8 001CEEC8 2D288000 */  daddu      $5, $4, $0
    /* CEECC 001CEECC E8F0060C */  jal        func_001bc3a0
    /* CEED0 001CEED0 00000000 */   nop
  .L001CEED4:
    /* CEED4 001CEED4 2D200002 */  daddu      $4, $16, $0
    /* CEED8 001CEED8 4000A527 */  addiu      $5, $29, 0x40
    /* CEEDC 001CEEDC 5C00A627 */  addiu      $6, $29, 0x5C
    /* CEEE0 001CEEE0 01000724 */  addiu      $7, $0, 0x1
    /* CEEE4 001CEEE4 08EB060C */  jal        func_001bac20
    /* CEEE8 001CEEE8 00000000 */   nop
    /* CEEEC 001CEEEC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* CEEF0 001CEEF0 00608244 */  mtc1       $2, $f12
    /* CEEF4 001CEEF4 2D200002 */  daddu      $4, $16, $0
    /* CEEF8 001CEEF8 BCEF060C */  jal        func_001bbef0
    /* CEEFC 001CEEFC 00000000 */   nop
    /* CEF00 001CEF00 3000BFDF */  ld         $31, 0x30($29)
    /* CEF04 001CEF04 2000B17B */  lq         $17, 0x20($29)
    /* CEF08 001CEF08 1000B07B */  lq         $16, 0x10($29)
    /* CEF0C 001CEF0C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CEF10 001CEF10 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CEF14 001CEF14 B000BD27 */  addiu      $29, $29, 0xB0
    /* CEF18 001CEF18 0800E003 */  jr         $31
    /* CEF1C 001CEF1C 00000000 */   nop
.size func_001cece0, 0x240
