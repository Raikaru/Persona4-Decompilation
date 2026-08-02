.section .text
.set noat
.set noreorder
glabel func_0010fcb0
    /* FCB0 0010FCB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FCB4 0010FCB4 1000BFFF */  sd         $31, 0x10($29)
    /* FCB8 0010FCB8 0000B07F */  sq         $16, 0x0($29)
    /* FCBC 0010FCBC 2D808000 */  daddu      $16, $4, $0
    /* FCC0 0010FCC0 04000006 */  bltz       $16, .L0010FCD4
    /* FCC4 0010FCC4 00000000 */   nop
    /* FCC8 0010FCC8 0001022A */  slti       $2, $16, 0x100
    /* FCCC 0010FCCC 06004014 */  bnez       $2, .L0010FCE8
    /* FCD0 0010FCD0 00000000 */   nop
  .L0010FCD4:
    /* FCD4 0010FCD4 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FCD8 0010FCD8 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FCDC 0010FCDC 1D0F0524 */  addiu      $5, $0, 0xF1D
    /* FCE0 0010FCE0 CCB5110C */  jal        func_0046d730
    /* FCE4 0010FCE4 00000000 */   nop
  .L0010FCE8:
    /* FCE8 0010FCE8 40101000 */  sll        $2, $16, 1
    /* FCEC 0010FCEC 21105000 */  addu       $2, $2, $16
    /* FCF0 0010FCF0 00190200 */  sll        $3, $2, 4
    /* FCF4 0010FCF4 7A00023C */  lui        $2, %hi(D_007981CC)
    /* FCF8 0010FCF8 CC814224 */  addiu      $2, $2, %lo(D_007981CC)
    /* FCFC 0010FCFC 21104300 */  addu       $2, $2, $3
    /* FD00 0010FD00 00004294 */  lhu        $2, 0x0($2)
    /* FD04 0010FD04 01004230 */  andi       $2, $2, 0x1
    /* FD08 0010FD08 07004010 */  beqz       $2, .L0010FD28
    /* FD0C 0010FD0C 00000000 */   nop
    /* FD10 0010FD10 7900023C */  lui        $2, %hi(D_007973A0)
    /* FD14 0010FD14 A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* FD18 0010FD18 21104300 */  addu       $2, $2, $3
    /* FD1C 0010FD1C 2C0E4224 */  addiu      $2, $2, 0xE2C
    /* FD20 0010FD20 02000010 */  b          .L0010FD2C
    /* FD24 0010FD24 00000000 */   nop
  .L0010FD28:
    /* FD28 0010FD28 2D100000 */  daddu      $2, $0, $0
  .L0010FD2C:
    /* FD2C 0010FD2C 1000BFDF */  ld         $31, 0x10($29)
    /* FD30 0010FD30 0000B07B */  lq         $16, 0x0($29)
    /* FD34 0010FD34 2000BD27 */  addiu      $29, $29, 0x20
    /* FD38 0010FD38 0800E003 */  jr         $31
    /* FD3C 0010FD3C 00000000 */   nop
.size func_0010fcb0, 0x90
