.section .text
.set noat
.set noreorder
glabel func_004a5bb0
    /* 3A5BB0 004A5BB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3A5BB4 004A5BB4 3000BFFF */  sd         $31, 0x30($29)
    /* 3A5BB8 004A5BB8 2000B27F */  sq         $18, 0x20($29)
    /* 3A5BBC 004A5BBC 1000B17F */  sq         $17, 0x10($29)
    /* 3A5BC0 004A5BC0 0000B07F */  sq         $16, 0x0($29)
    /* 3A5BC4 004A5BC4 2D888000 */  daddu      $17, $4, $0
    /* 3A5BC8 004A5BC8 7100043C */  lui        $4, %hi(D_007141A0)
    /* 3A5BCC 004A5BCC A0418424 */  addiu      $4, $4, %lo(D_007141A0)
    /* 3A5BD0 004A5BD0 1C000524 */  addiu      $5, $0, 0x1C
    /* 3A5BD4 004A5BD4 A43A110C */  jal        func_0044ea90
    /* 3A5BD8 004A5BD8 00000000 */   nop
    /* 3A5BDC 004A5BDC D4000424 */  addiu      $4, $0, 0xD4
    /* 3A5BE0 004A5BE0 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3A5BE4 004A5BE4 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3A5BE8 004A5BE8 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3A5BEC 004A5BEC 09F84000 */  jalr       $2
    /* 3A5BF0 004A5BF0 00000000 */   nop
    /* 3A5BF4 004A5BF4 2D804000 */  daddu      $16, $2, $0
    /* 3A5BF8 004A5BF8 06000016 */  bnez       $16, .L004A5C14
    /* 3A5BFC 004A5BFC 00000000 */   nop
    /* 3A5C00 004A5C00 7100043C */  lui        $4, %hi(D_007141A0)
    /* 3A5C04 004A5C04 A0418424 */  addiu      $4, $4, %lo(D_007141A0)
    /* 3A5C08 004A5C08 1D000524 */  addiu      $5, $0, 0x1D
    /* 3A5C0C 004A5C0C CCB5110C */  jal        func_0046d730
    /* 3A5C10 004A5C10 00000000 */   nop
  .L004A5C14:
    /* 3A5C14 004A5C14 2D200002 */  daddu      $4, $16, $0
    /* 3A5C18 004A5C18 2D280000 */  daddu      $5, $0, $0
    /* 3A5C1C 004A5C1C D4000624 */  addiu      $6, $0, 0xD4
    /* 3A5C20 004A5C20 72FE100C */  jal        func_0043f9c8
    /* 3A5C24 004A5C24 00000000 */   nop
    /* 3A5C28 004A5C28 000000FA */  sqc2       $vf0, 0x0($16)
    /* 3A5C2C 004A5C2C 100000FA */  sqc2       $vf0, 0x10($16)
    /* 3A5C30 004A5C30 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3A5C34 004A5C34 240002AE */  sw         $2, 0x24($16)
    /* 3A5C38 004A5C38 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3A5C3C 004A5C3C 200002AE */  sw         $2, 0x20($16)
    /* 3A5C40 004A5C40 04002016 */  bnez       $17, .L004A5C54
    /* 3A5C44 004A5C44 00000000 */   nop
    /* 3A5C48 004A5C48 2D100002 */  daddu      $2, $16, $0
    /* 3A5C4C 004A5C4C 5A000010 */  b          .L004A5DB8
    /* 3A5C50 004A5C50 00000000 */   nop
  .L004A5C54:
    /* 3A5C54 004A5C54 01000424 */  addiu      $4, $0, 0x1
    /* 3A5C58 004A5C58 02000524 */  addiu      $5, $0, 0x2
    /* 3A5C5C 004A5C5C 04000624 */  addiu      $6, $0, 0x4
    /* 3A5C60 004A5C60 7100073C */  lui        $7, %hi(D_00713408)
    /* 3A5C64 004A5C64 0834E724 */  addiu      $7, $7, %lo(D_00713408)
    /* 3A5C68 004A5C68 4C000824 */  addiu      $8, $0, 0x4C
    /* 3A5C6C 004A5C6C DC0B120C */  jal        func_00482f70
    /* 3A5C70 004A5C70 00000000 */   nop
    /* 3A5C74 004A5C74 C80002AE */  sw         $2, 0xC8($16)
    /* 3A5C78 004A5C78 1000428C */  lw         $2, 0x10($2)
    /* 3A5C7C 004A5C7C 1800428C */  lw         $2, 0x18($2)
    /* 3A5C80 004A5C80 3000438C */  lw         $3, 0x30($2)
    /* 3A5C84 004A5C84 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3A5C88 004A5C88 000062AC */  sw         $2, 0x0($3)
    /* 3A5C8C 004A5C8C 040062AC */  sw         $2, 0x4($3)
    /* 3A5C90 004A5C90 080062AC */  sw         $2, 0x8($3)
    /* 3A5C94 004A5C94 0C0062AC */  sw         $2, 0xC($3)
    /* 3A5C98 004A5C98 0C002296 */  lhu        $2, 0xC($17)
    /* 3A5C9C 004A5C9C 280002AE */  sw         $2, 0x28($16)
    /* 3A5CA0 004A5CA0 2D202002 */  daddu      $4, $17, $0
    /* 3A5CA4 004A5CA4 2411120C */  jal        func_00484490
    /* 3A5CA8 004A5CA8 00000000 */   nop
    /* 3A5CAC 004A5CAC 2D904000 */  daddu      $18, $2, $0
    /* 3A5CB0 004A5CB0 06004016 */  bnez       $18, .L004A5CCC
    /* 3A5CB4 004A5CB4 00000000 */   nop
    /* 3A5CB8 004A5CB8 7100043C */  lui        $4, %hi(D_007141A0)
    /* 3A5CBC 004A5CBC A0418424 */  addiu      $4, $4, %lo(D_007141A0)
    /* 3A5CC0 004A5CC0 47000524 */  addiu      $5, $0, 0x47
    /* 3A5CC4 004A5CC4 CCB5110C */  jal        func_0046d730
    /* 3A5CC8 004A5CC8 00000000 */   nop
  .L004A5CCC:
    /* 3A5CCC 004A5CCC 30000426 */  addiu      $4, $16, 0x30
    /* 3A5CD0 004A5CD0 2D284002 */  daddu      $5, $18, $0
    /* 3A5CD4 004A5CD4 98000624 */  addiu      $6, $0, 0x98
    /* 3A5CD8 004A5CD8 04FE100C */  jal        func_0043f810
    /* 3A5CDC 004A5CDC 00000000 */   nop
    /* 3A5CE0 004A5CE0 2D202002 */  daddu      $4, $17, $0
    /* 3A5CE4 004A5CE4 3411120C */  jal        func_004844d0
    /* 3A5CE8 004A5CE8 00000000 */   nop
    /* 3A5CEC 004A5CEC 31004010 */  beqz       $2, .L004A5DB4
    /* 3A5CF0 004A5CF0 00000000 */   nop
    /* 3A5CF4 004A5CF4 1C002496 */  lhu        $4, 0x1C($17)
    /* 3A5CF8 004A5CF8 07000324 */  addiu      $3, $0, 0x7
    /* 3A5CFC 004A5CFC 22008310 */  beq        $4, $3, .L004A5D88
    /* 3A5D00 004A5D00 00000000 */   nop
    /* 3A5D04 004A5D04 04000324 */  addiu      $3, $0, 0x4
    /* 3A5D08 004A5D08 15008310 */  beq        $4, $3, .L004A5D60
    /* 3A5D0C 004A5D0C 00000000 */   nop
    /* 3A5D10 004A5D10 02000324 */  addiu      $3, $0, 0x2
    /* 3A5D14 004A5D14 0C008310 */  beq        $4, $3, .L004A5D48
    /* 3A5D18 004A5D18 00000000 */   nop
    /* 3A5D1C 004A5D1C 01000324 */  addiu      $3, $0, 0x1
    /* 3A5D20 004A5D20 03008310 */  beq        $4, $3, .L004A5D30
    /* 3A5D24 004A5D24 00000000 */   nop
    /* 3A5D28 004A5D28 1D000010 */  b          .L004A5DA0
    /* 3A5D2C 004A5D2C 00000000 */   nop
  .L004A5D30:
    /* 3A5D30 004A5D30 C800048E */  lw         $4, 0xC8($16)
    /* 3A5D34 004A5D34 2D284000 */  daddu      $5, $2, $0
    /* 3A5D38 004A5D38 5C0E120C */  jal        func_00483970
    /* 3A5D3C 004A5D3C 00000000 */   nop
    /* 3A5D40 004A5D40 1C000010 */  b          .L004A5DB4
    /* 3A5D44 004A5D44 00000000 */   nop
  .L004A5D48:
    /* 3A5D48 004A5D48 2D204000 */  daddu      $4, $2, $0
    /* 3A5D4C 004A5D4C 6007120C */  jal        func_00481d80
    /* 3A5D50 004A5D50 00000000 */   nop
    /* 3A5D54 004A5D54 D00002AE */  sw         $2, 0xD0($16)
    /* 3A5D58 004A5D58 16000010 */  b          .L004A5DB4
    /* 3A5D5C 004A5D5C 00000000 */   nop
  .L004A5D60:
    /* 3A5D60 004A5D60 00004494 */  lhu        $4, 0x0($2)
    /* 3A5D64 004A5D64 C004120C */  jal        func_00481300
    /* 3A5D68 004A5D68 00000000 */   nop
    /* 3A5D6C 004A5D6C C800038E */  lw         $3, 0xC8($16)
    /* 3A5D70 004A5D70 1400648C */  lw         $4, 0x14($3)
    /* 3A5D74 004A5D74 2D284000 */  daddu      $5, $2, $0
    /* 3A5D78 004A5D78 AC100F0C */  jal        func_003c42b0
    /* 3A5D7C 004A5D7C 00000000 */   nop
    /* 3A5D80 004A5D80 0C000010 */  b          .L004A5DB4
    /* 3A5D84 004A5D84 00000000 */   nop
  .L004A5D88:
    /* 3A5D88 004A5D88 2D204000 */  daddu      $4, $2, $0
    /* 3A5D8C 004A5D8C 000A120C */  jal        func_00482800
    /* 3A5D90 004A5D90 00000000 */   nop
    /* 3A5D94 004A5D94 CC0002AE */  sw         $2, 0xCC($16)
    /* 3A5D98 004A5D98 06000010 */  b          .L004A5DB4
    /* 3A5D9C 004A5D9C 00000000 */   nop
  .L004A5DA0:
    /* 3A5DA0 004A5DA0 7100043C */  lui        $4, %hi(D_007141A0)
    /* 3A5DA4 004A5DA4 A0418424 */  addiu      $4, $4, %lo(D_007141A0)
    /* 3A5DA8 004A5DA8 5D000524 */  addiu      $5, $0, 0x5D
    /* 3A5DAC 004A5DAC CCB5110C */  jal        func_0046d730
    /* 3A5DB0 004A5DB0 00000000 */   nop
  .L004A5DB4:
    /* 3A5DB4 004A5DB4 2D100002 */  daddu      $2, $16, $0
  .L004A5DB8:
    /* 3A5DB8 004A5DB8 3000BFDF */  ld         $31, 0x30($29)
    /* 3A5DBC 004A5DBC 2000B27B */  lq         $18, 0x20($29)
    /* 3A5DC0 004A5DC0 1000B17B */  lq         $17, 0x10($29)
    /* 3A5DC4 004A5DC4 0000B07B */  lq         $16, 0x0($29)
    /* 3A5DC8 004A5DC8 4000BD27 */  addiu      $29, $29, 0x40
    /* 3A5DCC 004A5DCC 0800E003 */  jr         $31
    /* 3A5DD0 004A5DD0 00000000 */   nop
    /* 3A5DD4 004A5DD4 00000000 */  nop
    /* 3A5DD8 004A5DD8 00000000 */  nop
    /* 3A5DDC 004A5DDC 00000000 */  nop
.size func_004a5bb0, 0x230
