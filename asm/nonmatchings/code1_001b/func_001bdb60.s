.section .text
.set noat
.set noreorder
glabel func_001bdb60
    /* BDB60 001BDB60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BDB64 001BDB64 2000BFFF */  sd         $31, 0x20($29)
    /* BDB68 001BDB68 1000B17F */  sq         $17, 0x10($29)
    /* BDB6C 001BDB6C 0000B07F */  sq         $16, 0x0($29)
    /* BDB70 001BDB70 485C110C */  jal        func_00457120
    /* BDB74 001BDB74 00000000 */   nop
    /* BDB78 001BDB78 0C42033C */  lui        $3, (0x420C0000 >> 16)
    /* BDB7C 001BDB7C 00608344 */  mtc1       $3, $f12
    /* BDB80 001BDB80 2D204000 */  daddu      $4, $2, $0
    /* BDB84 001BDB84 60A00F0C */  jal        func_003e8180
    /* BDB88 001BDB88 00000000 */   nop
    /* BDB8C 001BDB8C 485C110C */  jal        func_00457120
    /* BDB90 001BDB90 00000000 */   nop
    /* BDB94 001BDB94 2042033C */  lui        $3, (0x42200000 >> 16)
    /* BDB98 001BDB98 00608344 */  mtc1       $3, $f12
    /* BDB9C 001BDB9C 2D204000 */  daddu      $4, $2, $0
    /* BDBA0 001BDBA0 F45D110C */  jal        func_004577d0
    /* BDBA4 001BDBA4 00000000 */   nop
    /* BDBA8 001BDBA8 ACB3838F */  lw         $3, -0x4C54($28)
    /* BDBAC 001BDBAC 24007024 */  addiu      $16, $3, 0x24
    /* BDBB0 001BDBB0 01000224 */  addiu      $2, $0, 0x1
    /* BDBB4 001BDBB4 240062A4 */  sh         $2, 0x24($3)
    /* BDBB8 001BDBB8 980060A4 */  sh         $0, 0x98($3)
    /* BDBBC 001BDBBC 9A0060A4 */  sh         $0, 0x9A($3)
    /* BDBC0 001BDBC0 9C0060A4 */  sh         $0, 0x9C($3)
    /* BDBC4 001BDBC4 A40060AC */  sw         $0, 0xA4($3)
    /* BDBC8 001BDBC8 A00060AC */  sw         $0, 0xA0($3)
    /* BDBCC 001BDBCC 5F00043C */  lui        $4, %hi(D_005F72B0)
    /* BDBD0 001BDBD0 B0728424 */  addiu      $4, $4, %lo(D_005F72B0)
    /* BDBD4 001BDBD4 3A000524 */  addiu      $5, $0, 0x3A
    /* BDBD8 001BDBD8 A43A110C */  jal        func_0044ea90
    /* BDBDC 001BDBDC 00000000 */   nop
    /* BDBE0 001BDBE0 30000424 */  addiu      $4, $0, 0x30
    /* BDBE4 001BDBE4 0400053C */  lui        $5, (0x40000 >> 16)
    /* BDBE8 001BDBE8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* BDBEC 001BDBEC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* BDBF0 001BDBF0 09F84000 */  jalr       $2
    /* BDBF4 001BDBF4 00000000 */   nop
    /* BDBF8 001BDBF8 2D884000 */  daddu      $17, $2, $0
    /* BDBFC 001BDBFC 2D202002 */  daddu      $4, $17, $0
    /* BDC00 001BDC00 2D280000 */  daddu      $5, $0, $0
    /* BDC04 001BDC04 30000624 */  addiu      $6, $0, 0x30
    /* BDC08 001BDC08 72FE100C */  jal        func_0043f9c8
    /* BDC0C 001BDC0C 00000000 */   nop
    /* BDC10 001BDC10 04000424 */  addiu      $4, $0, 0x4
    /* BDC14 001BDC14 01000524 */  addiu      $5, $0, 0x1
    /* BDC18 001BDC18 2D302002 */  daddu      $6, $17, $0
    /* BDC1C 001BDC1C F8EE0E0C */  jal        func_003bbbe0
    /* BDC20 001BDC20 00000000 */   nop
    /* BDC24 001BDC24 980002AE */  sw         $2, 0x98($16)
    /* BDC28 001BDC28 2D202002 */  daddu      $4, $17, $0
    /* BDC2C 001BDC2C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* BDC30 001BDC30 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* BDC34 001BDC34 09F84000 */  jalr       $2
    /* BDC38 001BDC38 00000000 */   nop
    /* BDC3C 001BDC3C 485C110C */  jal        func_00457120
    /* BDC40 001BDC40 00000000 */   nop
    /* BDC44 001BDC44 148380C7 */  lwc1       $f0, -0x7CEC($28)
    /* BDC48 001BDC48 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC4C 001BDC4C D80040E4 */  swc1       $f0, 0xD8($2)
    /* BDC50 001BDC50 188380C7 */  lwc1       $f0, -0x7CE8($28)
    /* BDC54 001BDC54 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC58 001BDC58 CC0040E4 */  swc1       $f0, 0xCC($2)
    /* BDC5C 001BDC5C 1C8380C7 */  lwc1       $f0, -0x7CE4($28)
    /* BDC60 001BDC60 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC64 001BDC64 D00040E4 */  swc1       $f0, 0xD0($2)
    /* BDC68 001BDC68 208380C7 */  lwc1       $f0, -0x7CE0($28)
    /* BDC6C 001BDC6C ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC70 001BDC70 D40040E4 */  swc1       $f0, 0xD4($2)
    /* BDC74 001BDC74 248380C7 */  lwc1       $f0, -0x7CDC($28)
    /* BDC78 001BDC78 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC7C 001BDC7C C00040E4 */  swc1       $f0, 0xC0($2)
    /* BDC80 001BDC80 288380C7 */  lwc1       $f0, -0x7CD8($28)
    /* BDC84 001BDC84 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC88 001BDC88 C40040E4 */  swc1       $f0, 0xC4($2)
    /* BDC8C 001BDC8C 2C8380C7 */  lwc1       $f0, -0x7CD4($28)
    /* BDC90 001BDC90 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDC94 001BDC94 C80040E4 */  swc1       $f0, 0xC8($2)
    /* BDC98 001BDC98 848180C7 */  lwc1       $f0, -0x7E7C($28)
    /* BDC9C 001BDC9C ACB3828F */  lw         $2, -0x4C54($28)
    /* BDCA0 001BDCA0 DC0040E4 */  swc1       $f0, 0xDC($2)
    /* BDCA4 001BDCA4 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDCA8 001BDCA8 F40040A4 */  sh         $0, 0xF4($2)
    /* BDCAC 001BDCAC ACB3828F */  lw         $2, -0x4C54($28)
    /* BDCB0 001BDCB0 0E0140A4 */  sh         $0, 0x10E($2)
    /* BDCB4 001BDCB4 2D200000 */  daddu      $4, $0, $0
    /* BDCB8 001BDCB8 08000010 */  b          .L001BDCDC
    /* BDCBC 001BDCBC 00000000 */   nop
  .L001BDCC0:
    /* BDCC0 001BDCC0 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* BDCC4 001BDCC4 40180200 */  sll        $3, $2, 1
    /* BDCC8 001BDCC8 ACB3828F */  lw         $2, -0x4C54($28)
    /* BDCCC 001BDCCC 21104300 */  addu       $2, $2, $3
    /* BDCD0 001BDCD0 080140A4 */  sh         $0, 0x108($2)
    /* BDCD4 001BDCD4 01008224 */  addiu      $2, $4, 0x1
    /* BDCD8 001BDCD8 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001BDCDC:
    /* BDCDC 001BDCDC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* BDCE0 001BDCE0 03004228 */  slti       $2, $2, 0x3
    /* BDCE4 001BDCE4 F6FF4014 */  bnez       $2, .L001BDCC0
    /* BDCE8 001BDCE8 00000000 */   nop
    /* BDCEC 001BDCEC ACB3838F */  lw         $3, -0x4C54($28)
    /* BDCF0 001BDCF0 F800628C */  lw         $2, 0xF8($3)
    /* BDCF4 001BDCF4 02004234 */  ori        $2, $2, 0x2
    /* BDCF8 001BDCF8 F80062AC */  sw         $2, 0xF8($3)
    /* BDCFC 001BDCFC ACB3828F */  lw         $2, -0x4C54($28)
    /* BDD00 001BDD00 10014424 */  addiu      $4, $2, 0x110
    /* BDD04 001BDD04 B844070C */  jal        func_001d12e0
    /* BDD08 001BDD08 00000000 */   nop
    /* BDD0C 001BDD0C 2000BFDF */  ld         $31, 0x20($29)
    /* BDD10 001BDD10 1000B17B */  lq         $17, 0x10($29)
    /* BDD14 001BDD14 0000B07B */  lq         $16, 0x0($29)
    /* BDD18 001BDD18 3000BD27 */  addiu      $29, $29, 0x30
    /* BDD1C 001BDD1C 0800E003 */  jr         $31
    /* BDD20 001BDD20 00000000 */   nop
    /* BDD24 001BDD24 00000000 */  nop
    /* BDD28 001BDD28 00000000 */  nop
    /* BDD2C 001BDD2C 00000000 */  nop
.size func_001bdb60, 0x1d0
