.section .text
.set noat
.set noreorder
glabel func_0010fde0
    /* FDE0 0010FDE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FDE4 0010FDE4 2000BFFF */  sd         $31, 0x20($29)
    /* FDE8 0010FDE8 1000B17F */  sq         $17, 0x10($29)
    /* FDEC 0010FDEC 0000B07F */  sq         $16, 0x0($29)
    /* FDF0 0010FDF0 2D888000 */  daddu      $17, $4, $0
    /* FDF4 0010FDF4 06002016 */  bnez       $17, .L0010FE10
    /* FDF8 0010FDF8 00000000 */   nop
    /* FDFC 0010FDFC 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FE00 0010FE00 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FE04 0010FE04 5D0F0524 */  addiu      $5, $0, 0xF5D
    /* FE08 0010FE08 CCB5110C */  jal        func_0046d730
    /* FE0C 0010FE0C 00000000 */   nop
  .L0010FE10:
    /* FE10 0010FE10 02002296 */  lhu        $2, 0x2($17)
    /* FE14 0010FE14 04004004 */  bltz       $2, .L0010FE28
    /* FE18 0010FE18 00000000 */   nop
    /* FE1C 0010FE1C 00014228 */  slti       $2, $2, 0x100
    /* FE20 0010FE20 06004014 */  bnez       $2, .L0010FE3C
    /* FE24 0010FE24 00000000 */   nop
  .L0010FE28:
    /* FE28 0010FE28 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FE2C 0010FE2C 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FE30 0010FE30 5E0F0524 */  addiu      $5, $0, 0xF5E
    /* FE34 0010FE34 CCB5110C */  jal        func_0046d730
    /* FE38 0010FE38 00000000 */   nop
  .L0010FE3C:
    /* FE3C 0010FE3C 02003096 */  lhu        $16, 0x2($17)
    /* FE40 0010FE40 C0101000 */  sll        $2, $16, 3
    /* FE44 0010FE44 23105000 */  subu       $2, $2, $16
    /* FE48 0010FE48 40180200 */  sll        $3, $2, 1
    /* FE4C 0010FE4C D4B3828F */  lw         $2, -0x4C2C($28)
    /* FE50 0010FE50 21104300 */  addu       $2, $2, $3
    /* FE54 0010FE54 00004394 */  lhu        $3, 0x0($2)
    /* FE58 0010FE58 08006230 */  andi       $2, $3, 0x8
    /* FE5C 0010FE5C 04004010 */  beqz       $2, .L0010FE70
    /* FE60 0010FE60 00000000 */   nop
    /* FE64 0010FE64 2D102002 */  daddu      $2, $17, $0
    /* FE68 0010FE68 45000010 */  b          .L0010FF80
    /* FE6C 0010FE6C 00000000 */   nop
  .L0010FE70:
    /* FE70 0010FE70 20006230 */  andi       $2, $3, 0x20
    /* FE74 0010FE74 04004010 */  beqz       $2, .L0010FE88
    /* FE78 0010FE78 00000000 */   nop
    /* FE7C 0010FE7C 2D102002 */  daddu      $2, $17, $0
    /* FE80 0010FE80 3F000010 */  b          .L0010FF80
    /* FE84 0010FE84 00000000 */   nop
  .L0010FE88:
    /* FE88 0010FE88 04000006 */  bltz       $16, .L0010FE9C
    /* FE8C 0010FE8C 00000000 */   nop
    /* FE90 0010FE90 0001022A */  slti       $2, $16, 0x100
    /* FE94 0010FE94 06004014 */  bnez       $2, .L0010FEB0
    /* FE98 0010FE98 00000000 */   nop
  .L0010FE9C:
    /* FE9C 0010FE9C 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FEA0 0010FEA0 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FEA4 0010FEA4 1D0F0524 */  addiu      $5, $0, 0xF1D
    /* FEA8 0010FEA8 CCB5110C */  jal        func_0046d730
    /* FEAC 0010FEAC 00000000 */   nop
  .L0010FEB0:
    /* FEB0 0010FEB0 40101000 */  sll        $2, $16, 1
    /* FEB4 0010FEB4 21105000 */  addu       $2, $2, $16
    /* FEB8 0010FEB8 00190200 */  sll        $3, $2, 4
    /* FEBC 0010FEBC 7A00023C */  lui        $2, %hi(D_007981CC)
    /* FEC0 0010FEC0 CC814224 */  addiu      $2, $2, %lo(D_007981CC)
    /* FEC4 0010FEC4 21104300 */  addu       $2, $2, $3
    /* FEC8 0010FEC8 00004294 */  lhu        $2, 0x0($2)
    /* FECC 0010FECC 01004230 */  andi       $2, $2, 0x1
    /* FED0 0010FED0 07004010 */  beqz       $2, .L0010FEF0
    /* FED4 0010FED4 00000000 */   nop
    /* FED8 0010FED8 7900023C */  lui        $2, %hi(D_007973A0)
    /* FEDC 0010FEDC A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* FEE0 0010FEE0 21104300 */  addu       $2, $2, $3
    /* FEE4 0010FEE4 2C0E4224 */  addiu      $2, $2, 0xE2C
    /* FEE8 0010FEE8 02000010 */  b          .L0010FEF4
    /* FEEC 0010FEEC 00000000 */   nop
  .L0010FEF0:
    /* FEF0 0010FEF0 2D100000 */  daddu      $2, $0, $0
  .L0010FEF4:
    /* FEF4 0010FEF4 03004010 */  beqz       $2, .L0010FF04
    /* FEF8 0010FEF8 00000000 */   nop
    /* FEFC 0010FEFC 20000010 */  b          .L0010FF80
    /* FF00 0010FF00 00000000 */   nop
  .L0010FF04:
    /* FF04 0010FF04 06002016 */  bnez       $17, .L0010FF20
    /* FF08 0010FF08 00000000 */   nop
    /* FF0C 0010FF0C 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FF10 0010FF10 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FF14 0010FF14 270F0524 */  addiu      $5, $0, 0xF27
    /* FF18 0010FF18 CCB5110C */  jal        func_0046d730
    /* FF1C 0010FF1C 00000000 */   nop
  .L0010FF20:
    /* FF20 0010FF20 02002296 */  lhu        $2, 0x2($17)
    /* FF24 0010FF24 04004004 */  bltz       $2, .L0010FF38
    /* FF28 0010FF28 00000000 */   nop
    /* FF2C 0010FF2C 00014228 */  slti       $2, $2, 0x100
    /* FF30 0010FF30 06004014 */  bnez       $2, .L0010FF4C
    /* FF34 0010FF34 00000000 */   nop
  .L0010FF38:
    /* FF38 0010FF38 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FF3C 0010FF3C 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FF40 0010FF40 280F0524 */  addiu      $5, $0, 0xF28
    /* FF44 0010FF44 CCB5110C */  jal        func_0046d730
    /* FF48 0010FF48 00000000 */   nop
  .L0010FF4C:
    /* FF4C 0010FF4C 02002396 */  lhu        $3, 0x2($17)
    /* FF50 0010FF50 40100300 */  sll        $2, $3, 1
    /* FF54 0010FF54 21104300 */  addu       $2, $2, $3
    /* FF58 0010FF58 00190200 */  sll        $3, $2, 4
    /* FF5C 0010FF5C 7900023C */  lui        $2, %hi(D_007973A0)
    /* FF60 0010FF60 A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* FF64 0010FF64 21104300 */  addu       $2, $2, $3
    /* FF68 0010FF68 2C0E4424 */  addiu      $4, $2, 0xE2C
    /* FF6C 0010FF6C 2D282002 */  daddu      $5, $17, $0
    /* FF70 0010FF70 30000624 */  addiu      $6, $0, 0x30
    /* FF74 0010FF74 04FE100C */  jal        func_0043f810
    /* FF78 0010FF78 00000000 */   nop
    /* FF7C 0010FF7C 2D100000 */  daddu      $2, $0, $0
  .L0010FF80:
    /* FF80 0010FF80 2000BFDF */  ld         $31, 0x20($29)
    /* FF84 0010FF84 1000B17B */  lq         $17, 0x10($29)
    /* FF88 0010FF88 0000B07B */  lq         $16, 0x0($29)
    /* FF8C 0010FF8C 3000BD27 */  addiu      $29, $29, 0x30
    /* FF90 0010FF90 0800E003 */  jr         $31
    /* FF94 0010FF94 00000000 */   nop
    /* FF98 0010FF98 00000000 */  nop
    /* FF9C 0010FF9C 00000000 */  nop
.size func_0010fde0, 0x1c0
