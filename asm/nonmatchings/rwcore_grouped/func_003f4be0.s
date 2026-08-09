.section .text
.set noat
.set noreorder
glabel func_003f4be0
    /* 2F4BE0 003F4BE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F4BE4 003F4BE4 0000BFFF */  sd         $31, 0x0($29)
    /* 2F4BE8 003F4BE8 04B88293 */  lbu        $2, -0x47FC($28)
    /* 2F4BEC 003F4BEC 17004014 */  bnez       $2, .L003F4C4C
    /* 2F4BF0 003F4BF0 00000000 */   nop
  .L003F4BF4:
    /* 2F4BF4 003F4BF4 00B88293 */  lbu        $2, -0x4800($28)
    /* 2F4BF8 003F4BF8 18004014 */  bnez       $2, .L003F4C5C
    /* 2F4BFC 003F4BFC 00000000 */   nop
  .L003F4C00:
    /* 2F4C00 003F4C00 FCB78293 */  lbu        $2, -0x4804($28)
    /* 2F4C04 003F4C04 19004014 */  bnez       $2, .L003F4C6C
    /* 2F4C08 003F4C08 00000000 */   nop
  .L003F4C0C:
    /* 2F4C0C 003F4C0C E0AB858F */  lw         $5, -0x5420($28)
    /* 2F4C10 003F4C10 4485100C */  jal        func_00421510
    /* 2F4C14 003F4C14 02000424 */   addiu     $4, $0, 0x2
    /* 2F4C18 003F4C18 DCAB858F */  lw         $5, -0x5424($28)
    /* 2F4C1C 003F4C1C FFFF0224 */  addiu      $2, $0, -0x1
    /* 2F4C20 003F4C20 01000424 */  addiu      $4, $0, 0x1
    /* 2F4C24 003F4C24 4485100C */  jal        func_00421510
    /* 2F4C28 003F4C28 E0AB82AF */   sw        $2, -0x5420($28)
    /* 2F4C2C 003F4C2C D8AB858F */  lw         $5, -0x5428($28)
    /* 2F4C30 003F4C30 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2F4C34 003F4C34 02000424 */  addiu      $4, $0, 0x2
    /* 2F4C38 003F4C38 3885100C */  jal        func_004214e0
    /* 2F4C3C 003F4C3C DCAB82AF */   sw        $2, -0x5424($28)
    /* 2F4C40 003F4C40 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2F4C44 003F4C44 0D000010 */  b          .L003F4C7C
    /* 2F4C48 003F4C48 D8AB83AF */   sw        $3, -0x5428($28)
  .L003F4C4C:
    /* 2F4C4C 003F4C4C E488100C */  jal        func_00422390
    /* 2F4C50 003F4C50 02000424 */   addiu     $4, $0, 0x2
    /* 2F4C54 003F4C54 E7FF0010 */  b          .L003F4BF4
    /* 2F4C58 003F4C58 04B880A3 */   sb        $0, -0x47FC($28)
  .L003F4C5C:
    /* 2F4C5C 003F4C5C E488100C */  jal        func_00422390
    /* 2F4C60 003F4C60 01000424 */   addiu     $4, $0, 0x1
    /* 2F4C64 003F4C64 E6FF0010 */  b          .L003F4C00
    /* 2F4C68 003F4C68 00B880A3 */   sb        $0, -0x4800($28)
  .L003F4C6C:
    /* 2F4C6C 003F4C6C B088100C */  jal        func_004222c0
    /* 2F4C70 003F4C70 02000424 */   addiu     $4, $0, 0x2
    /* 2F4C74 003F4C74 E5FF0010 */  b          .L003F4C0C
    /* 2F4C78 003F4C78 FCB780A3 */   sb        $0, -0x4804($28)
  .L003F4C7C:
    /* 2F4C7C 003F4C7C 0000BFDF */  ld         $31, 0x0($29)
    /* 2F4C80 003F4C80 0800E003 */  jr         $31
    /* 2F4C84 003F4C84 1000BD27 */   addiu     $29, $29, 0x10
    /* 2F4C88 003F4C88 00000000 */  nop
    /* 2F4C8C 003F4C8C 00000000 */  nop
.size func_003f4be0, 0xb0
