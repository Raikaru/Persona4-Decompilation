.section .text
.set noat
.set noreorder
glabel func_001f5bd0
    /* F5BD0 001F5BD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* F5BD4 001F5BD4 2000BFFF */  sd         $31, 0x20($29)
    /* F5BD8 001F5BD8 1000B07F */  sq         $16, 0x10($29)
    /* F5BDC 001F5BDC 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* F5BE0 001F5BE0 0800B6E7 */  swc1       $f22, 0x8($29)
    /* F5BE4 001F5BE4 0400B5E7 */  swc1       $f21, 0x4($29)
    /* F5BE8 001F5BE8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* F5BEC 001F5BEC 2D808000 */  daddu      $16, $4, $0
    /* F5BF0 001F5BF0 FFFF0732 */  andi       $7, $16, 0xFFFF
    /* F5BF4 001F5BF4 01000424 */  addiu      $4, $0, 0x1
    /* F5BF8 001F5BF8 0418E400 */  sllv       $3, $4, $7
    /* F5BFC 001F5BFC FFFF6630 */  andi       $6, $3, 0xFFFF
    /* F5C00 001F5C00 ACB3858F */  lw         $5, -0x4C54($28)
    /* F5C04 001F5C04 480AA394 */  lhu        $3, 0xA48($5)
    /* F5C08 001F5C08 25186600 */  or         $3, $3, $6
    /* F5C0C 001F5C0C 480AA3A4 */  sh         $3, 0xA48($5)
    /* F5C10 001F5C10 0300E010 */  beqz       $7, .L001F5C20
    /* F5C14 001F5C14 00000000 */   nop
    /* F5C18 001F5C18 95000010 */  b          .L001F5E70
    /* F5C1C 001F5C1C 00000000 */   nop
  .L001F5C20:
    /* F5C20 001F5C20 03000524 */  addiu      $5, $0, 0x3
    /* F5C24 001F5C24 0800063C */  lui        $6, (0x80000 >> 16)
    /* F5C28 001F5C28 7CBD070C */  jal        func_001ef5f0
    /* F5C2C 001F5C2C 00000000 */   nop
    /* F5C30 001F5C30 06004004 */  bltz       $2, .L001F5C4C
    /* F5C34 001F5C34 00000000 */   nop
    /* F5C38 001F5C38 00008244 */  mtc1       $2, $f0
    /* F5C3C 001F5C3C 00000000 */  nop
    /* F5C40 001F5C40 60058046 */  cvt.s.w    $f21, $f0
    /* F5C44 001F5C44 08000010 */  b          .L001F5C68
    /* F5C48 001F5C48 00000000 */   nop
  .L001F5C4C:
    /* F5C4C 001F5C4C 42180200 */  srl        $3, $2, 1
    /* F5C50 001F5C50 01004230 */  andi       $2, $2, 0x1
    /* F5C54 001F5C54 25186200 */  or         $3, $3, $2
    /* F5C58 001F5C58 00008344 */  mtc1       $3, $f0
    /* F5C5C 001F5C5C 00000000 */  nop
    /* F5C60 001F5C60 60058046 */  cvt.s.w    $f21, $f0
    /* F5C64 001F5C64 40AD1546 */  add.s      $f21, $f21, $f21
  .L001F5C68:
    /* F5C68 001F5C68 02000424 */  addiu      $4, $0, 0x2
    /* F5C6C 001F5C6C 03000524 */  addiu      $5, $0, 0x3
    /* F5C70 001F5C70 0800063C */  lui        $6, (0x80000 >> 16)
    /* F5C74 001F5C74 7CBD070C */  jal        func_001ef5f0
    /* F5C78 001F5C78 00000000 */   nop
    /* F5C7C 001F5C7C 06004004 */  bltz       $2, .L001F5C98
    /* F5C80 001F5C80 00000000 */   nop
    /* F5C84 001F5C84 00008244 */  mtc1       $2, $f0
    /* F5C88 001F5C88 00000000 */  nop
    /* F5C8C 001F5C8C 20058046 */  cvt.s.w    $f20, $f0
    /* F5C90 001F5C90 08000010 */  b          .L001F5CB4
    /* F5C94 001F5C94 00000000 */   nop
  .L001F5C98:
    /* F5C98 001F5C98 42180200 */  srl        $3, $2, 1
    /* F5C9C 001F5C9C 01004230 */  andi       $2, $2, 0x1
    /* F5CA0 001F5CA0 25186200 */  or         $3, $3, $2
    /* F5CA4 001F5CA4 00008344 */  mtc1       $3, $f0
    /* F5CA8 001F5CA8 00000000 */  nop
    /* F5CAC 001F5CAC 20058046 */  cvt.s.w    $f20, $f0
    /* F5CB0 001F5CB0 00A51446 */  add.s      $f20, $f20, $f20
  .L001F5CB4:
    /* F5CB4 001F5CB4 01000424 */  addiu      $4, $0, 0x1
    /* F5CB8 001F5CB8 04000524 */  addiu      $5, $0, 0x4
    /* F5CBC 001F5CBC 0800063C */  lui        $6, (0x80000 >> 16)
    /* F5CC0 001F5CC0 7CBD070C */  jal        func_001ef5f0
    /* F5CC4 001F5CC4 00000000 */   nop
    /* F5CC8 001F5CC8 06004004 */  bltz       $2, .L001F5CE4
    /* F5CCC 001F5CCC 00000000 */   nop
    /* F5CD0 001F5CD0 00008244 */  mtc1       $2, $f0
    /* F5CD4 001F5CD4 00000000 */  nop
    /* F5CD8 001F5CD8 E0058046 */  cvt.s.w    $f23, $f0
    /* F5CDC 001F5CDC 08000010 */  b          .L001F5D00
    /* F5CE0 001F5CE0 00000000 */   nop
  .L001F5CE4:
    /* F5CE4 001F5CE4 42180200 */  srl        $3, $2, 1
    /* F5CE8 001F5CE8 01004230 */  andi       $2, $2, 0x1
    /* F5CEC 001F5CEC 25186200 */  or         $3, $3, $2
    /* F5CF0 001F5CF0 00008344 */  mtc1       $3, $f0
    /* F5CF4 001F5CF4 00000000 */  nop
    /* F5CF8 001F5CF8 E0058046 */  cvt.s.w    $f23, $f0
    /* F5CFC 001F5CFC C0BD1746 */  add.s      $f23, $f23, $f23
  .L001F5D00:
    /* F5D00 001F5D00 02000424 */  addiu      $4, $0, 0x2
    /* F5D04 001F5D04 04000524 */  addiu      $5, $0, 0x4
    /* F5D08 001F5D08 0800063C */  lui        $6, (0x80000 >> 16)
    /* F5D0C 001F5D0C 7CBD070C */  jal        func_001ef5f0
    /* F5D10 001F5D10 00000000 */   nop
    /* F5D14 001F5D14 06004004 */  bltz       $2, .L001F5D30
    /* F5D18 001F5D18 00000000 */   nop
    /* F5D1C 001F5D1C 00008244 */  mtc1       $2, $f0
    /* F5D20 001F5D20 00000000 */  nop
    /* F5D24 001F5D24 A0058046 */  cvt.s.w    $f22, $f0
    /* F5D28 001F5D28 08000010 */  b          .L001F5D4C
    /* F5D2C 001F5D2C 00000000 */   nop
  .L001F5D30:
    /* F5D30 001F5D30 42180200 */  srl        $3, $2, 1
    /* F5D34 001F5D34 01004230 */  andi       $2, $2, 0x1
    /* F5D38 001F5D38 25186200 */  or         $3, $3, $2
    /* F5D3C 001F5D3C 00008344 */  mtc1       $3, $f0
    /* F5D40 001F5D40 00000000 */  nop
    /* F5D44 001F5D44 A0058046 */  cvt.s.w    $f22, $f0
    /* F5D48 001F5D48 80B51646 */  add.s      $f22, $f22, $f22
  .L001F5D4C:
    /* F5D4C 001F5D4C 0F000424 */  addiu      $4, $0, 0xF
    /* F5D50 001F5D50 5CC7080C */  jal        func_00231d70
    /* F5D54 001F5D54 00000000 */   nop
    /* F5D58 001F5D58 05004324 */  addiu      $3, $2, 0x5
    /* F5D5C 001F5D5C 06006004 */  bltz       $3, .L001F5D78
    /* F5D60 001F5D60 00000000 */   nop
    /* F5D64 001F5D64 00008344 */  mtc1       $3, $f0
    /* F5D68 001F5D68 00000000 */  nop
    /* F5D6C 001F5D6C 20008046 */  cvt.s.w    $f0, $f0
    /* F5D70 001F5D70 08000010 */  b          .L001F5D94
    /* F5D74 001F5D74 00000000 */   nop
  .L001F5D78:
    /* F5D78 001F5D78 42200300 */  srl        $4, $3, 1
    /* F5D7C 001F5D7C 01006330 */  andi       $3, $3, 0x1
    /* F5D80 001F5D80 25208300 */  or         $4, $4, $3
    /* F5D84 001F5D84 00008444 */  mtc1       $4, $f0
    /* F5D88 001F5D88 00000000 */  nop
    /* F5D8C 001F5D8C 20008046 */  cvt.s.w    $f0, $f0
    /* F5D90 001F5D90 00000046 */  add.s      $f0, $f0, $f0
  .L001F5D94:
    /* F5D94 001F5D94 2041033C */  lui        $3, (0x41200000 >> 16)
    /* F5D98 001F5D98 00188344 */  mtc1       $3, $f3
    /* F5D9C 001F5D9C 00000000 */  nop
    /* F5DA0 001F5DA0 83000346 */  div.s      $f2, $f0, $f3
    /* F5DA4 001F5DA4 43A81446 */  div.s      $f1, $f21, $f20
    /* F5DA8 001F5DA8 03B81646 */  div.s      $f0, $f23, $f22
    /* F5DAC 001F5DAC 42080046 */  mul.s      $f1, $f1, $f0
    /* F5DB0 001F5DB0 F041033C */  lui        $3, (0x41F00000 >> 16)
    /* F5DB4 001F5DB4 00008344 */  mtc1       $3, $f0
    /* F5DB8 001F5DB8 00000000 */  nop
    /* F5DBC 001F5DBC 02000146 */  mul.s      $f0, $f0, $f1
    /* F5DC0 001F5DC0 42100046 */  mul.s      $f1, $f2, $f0
    /* F5DC4 001F5DC4 4842033C */  lui        $3, (0x42480000 >> 16)
    /* F5DC8 001F5DC8 00008344 */  mtc1       $3, $f0
    /* F5DCC 001F5DCC 00000000 */  nop
    /* F5DD0 001F5DD0 36080046 */  c.le.s     $f1, $f0
    /* F5DD4 001F5DD4 04000145 */  bc1t       .L001F5DE8
    /* F5DD8 001F5DD8 00000000 */   nop
    /* F5DDC 001F5DDC 46000046 */  mov.s      $f1, $f0
    /* F5DE0 001F5DE0 05000010 */  b          .L001F5DF8
    /* F5DE4 001F5DE4 00000000 */   nop
  .L001F5DE8:
    /* F5DE8 001F5DE8 34080346 */  c.lt.s     $f1, $f3
    /* F5DEC 001F5DEC 02000045 */  bc1f       .L001F5DF8
    /* F5DF0 001F5DF0 00000000 */   nop
    /* F5DF4 001F5DF4 46180046 */  mov.s      $f1, $f3
  .L001F5DF8:
    /* F5DF8 001F5DF8 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* F5DFC 001F5DFC 80280300 */  sll        $5, $3, 2
    /* F5E00 001F5E00 ACB3838F */  lw         $3, -0x4C54($28)
    /* F5E04 001F5E04 2118A300 */  addu       $3, $5, $3
    /* F5E08 001F5E08 440A60A4 */  sh         $0, 0xA44($3)
    /* F5E0C 001F5E0C C842033C */  lui        $3, (0x42C80000 >> 16)
    /* F5E10 001F5E10 00008344 */  mtc1       $3, $f0
    /* F5E14 001F5E14 00000000 */  nop
    /* F5E18 001F5E18 43000146 */  div.s      $f1, $f0, $f1
    /* F5E1C 001F5E1C 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* F5E20 001F5E20 00008344 */  mtc1       $3, $f0
    /* F5E24 001F5E24 00000000 */  nop
    /* F5E28 001F5E28 36000146 */  c.le.s     $f0, $f1
    /* F5E2C 001F5E2C 07000145 */  bc1t       .L001F5E4C
    /* F5E30 001F5E30 00000000 */   nop
    /* F5E34 001F5E34 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* F5E38 001F5E38 00000444 */  mfc1       $4, $f0
    /* F5E3C 001F5E3C 00000000 */  nop
    /* F5E40 001F5E40 FFFF8430 */  andi       $4, $4, 0xFFFF
    /* F5E44 001F5E44 07000010 */  b          .L001F5E64
    /* F5E48 001F5E48 00000000 */   nop
  .L001F5E4C:
    /* F5E4C 001F5E4C 01080046 */  sub.s      $f0, $f1, $f0
    /* F5E50 001F5E50 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* F5E54 001F5E54 00000444 */  mfc1       $4, $f0
    /* F5E58 001F5E58 0080033C */  lui        $3, (0x80000000 >> 16)
    /* F5E5C 001F5E5C 25208300 */  or         $4, $4, $3
    /* F5E60 001F5E60 FFFF8430 */  andi       $4, $4, 0xFFFF
  .L001F5E64:
    /* F5E64 001F5E64 ACB3838F */  lw         $3, -0x4C54($28)
    /* F5E68 001F5E68 2118A300 */  addu       $3, $5, $3
    /* F5E6C 001F5E6C 460A64A4 */  sh         $4, 0xA46($3)
  .L001F5E70:
    /* F5E70 001F5E70 2000BFDF */  ld         $31, 0x20($29)
    /* F5E74 001F5E74 1000B07B */  lq         $16, 0x10($29)
    /* F5E78 001F5E78 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* F5E7C 001F5E7C 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* F5E80 001F5E80 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* F5E84 001F5E84 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* F5E88 001F5E88 3000BD27 */  addiu      $29, $29, 0x30
    /* F5E8C 001F5E8C 0800E003 */  jr         $31
    /* F5E90 001F5E90 00000000 */   nop
    /* F5E94 001F5E94 00000000 */  nop
    /* F5E98 001F5E98 00000000 */  nop
    /* F5E9C 001F5E9C 00000000 */  nop
.size func_001f5bd0, 0x2d0
