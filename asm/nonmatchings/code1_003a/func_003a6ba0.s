.section .text
.set noat
.set noreorder
glabel func_003a6ba0
    /* 2A6BA0 003A6BA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2A6BA4 003A6BA4 3000BFFF */  sd         $31, 0x30($29)
    /* 2A6BA8 003A6BA8 2000B27F */  sq         $18, 0x20($29)
    /* 2A6BAC 003A6BAC 1000B17F */  sq         $17, 0x10($29)
    /* 2A6BB0 003A6BB0 7445100C */  jal        func_004115d0
    /* 2A6BB4 003A6BB4 0000B07F */   sq        $16, 0x0($29)
    /* 2A6BB8 003A6BB8 2D884000 */  daddu      $17, $2, $0
    /* 2A6BBC 003A6BBC 82002012 */  beqz       $17, .L003A6DC8
    /* 2A6BC0 003A6BC0 00000000 */   nop
    /* 2A6BC4 003A6BC4 284B100C */  jal        func_00412ca0
    /* 2A6BC8 003A6BC8 2D202002 */   daddu     $4, $17, $0
    /* 2A6BCC 003A6BCC A04E0F0C */  jal        func_003d3a80
    /* 2A6BD0 003A6BD0 2D804000 */   daddu     $16, $2, $0
    /* 2A6BD4 003A6BD4 2D904000 */  daddu      $18, $2, $0
    /* 2A6BD8 003A6BD8 7D004012 */  beqz       $18, .L003A6DD0
    /* 2A6BDC 003A6BDC 00000000 */   nop
    /* 2A6BE0 003A6BE0 2D200002 */  daddu      $4, $16, $0
    /* 2A6BE4 003A6BE4 2D280000 */  daddu      $5, $0, $0
    /* 2A6BE8 003A6BE8 2D304002 */  daddu      $6, $18, $0
    /* 2A6BEC 003A6BEC EC4B100C */  jal        func_00412fb0
    /* 2A6BF0 003A6BF0 2D380000 */   daddu     $7, $0, $0
    /* 2A6BF4 003A6BF4 0000458E */  lw         $5, 0x0($18)
    /* 2A6BF8 003A6BF8 2D200002 */  daddu      $4, $16, $0
    /* 2A6BFC 003A6BFC 2D300000 */  daddu      $6, $0, $0
    /* 2A6C00 003A6C00 A44B100C */  jal        func_00412e90
    /* 2A6C04 003A6C04 2D380000 */   daddu     $7, $0, $0
    /* 2A6C08 003A6C08 8800043C */  lui        $4, %hi(D_00885A50)
    /* 2A6C0C 003A6C0C 7100053C */  lui        $5, %hi(D_0070B570)
    /* 2A6C10 003A6C10 2D884000 */  daddu      $17, $2, $0
    /* 2A6C14 003A6C14 505A8424 */  addiu      $4, $4, %lo(D_00885A50)
    /* 2A6C18 003A6C18 70B5A524 */  addiu      $5, $5, %lo(D_0070B570)
    /* 2A6C1C 003A6C1C 04FE100C */  jal        func_0043f810
    /* 2A6C20 003A6C20 10000624 */   addiu     $6, $0, 0x10
    /* 2A6C24 003A6C24 006C033C */  lui        $3, (0x6C000000 >> 16)
    /* 2A6C28 003A6C28 8800023C */  lui        $2, %hi(D_00885A28)
    /* 2A6C2C 003A6C2C 285A43AC */  sw         $3, %lo(D_00885A28)($2)
    /* 2A6C30 003A6C30 8800043C */  lui        $4, %hi(D_00885A40)
    /* 2A6C34 003A6C34 8800023C */  lui        $2, %hi(D_00885A58)
    /* 2A6C38 003A6C38 7100053C */  lui        $5, %hi(D_0070B550)
    /* 2A6C3C 003A6C3C 585A438C */  lw         $3, %lo(D_00885A58)($2)
    /* 2A6C40 003A6C40 405A8424 */  addiu      $4, $4, %lo(D_00885A40)
    /* 2A6C44 003A6C44 50B5A524 */  addiu      $5, $5, %lo(D_0070B550)
    /* 2A6C48 003A6C48 10000624 */  addiu      $6, $0, 0x10
    /* 2A6C4C 003A6C4C 04006334 */  ori        $3, $3, 0x4
    /* 2A6C50 003A6C50 8800023C */  lui        $2, %hi(D_00885A58)
    /* 2A6C54 003A6C54 01006334 */  ori        $3, $3, 0x1
    /* 2A6C58 003A6C58 08006334 */  ori        $3, $3, 0x8
    /* 2A6C5C 003A6C5C 04FE100C */  jal        func_0043f810
    /* 2A6C60 003A6C60 585A43AC */   sw        $3, %lo(D_00885A58)($2)
    /* 2A6C64 003A6C64 8800023C */  lui        $2, %hi(D_00885A48)
    /* 2A6C68 003A6C68 8800043C */  lui        $4, %hi(D_00885A30)
    /* 2A6C6C 003A6C6C 485A478C */  lw         $7, %lo(D_00885A48)($2)
    /* 2A6C70 003A6C70 FFDF0324 */  addiu      $3, $0, -0x2001
    /* 2A6C74 003A6C74 7100053C */  lui        $5, %hi(D_0070B570)
    /* 2A6C78 003A6C78 305A8424 */  addiu      $4, $4, %lo(D_00885A30)
    /* 2A6C7C 003A6C7C 70B5A524 */  addiu      $5, $5, %lo(D_0070B570)
    /* 2A6C80 003A6C80 10000624 */  addiu      $6, $0, 0x10
    /* 2A6C84 003A6C84 2418E300 */  and        $3, $7, $3
    /* 2A6C88 003A6C88 8800023C */  lui        $2, %hi(D_00885A48)
    /* 2A6C8C 003A6C8C 04006334 */  ori        $3, $3, 0x4
    /* 2A6C90 003A6C90 01006334 */  ori        $3, $3, 0x1
    /* 2A6C94 003A6C94 08006334 */  ori        $3, $3, 0x8
    /* 2A6C98 003A6C98 04FE100C */  jal        func_0043f810
    /* 2A6C9C 003A6C9C 485A43AC */   sw        $3, %lo(D_00885A48)($2)
    /* 2A6CA0 003A6CA0 0064033C */  lui        $3, (0x64000004 >> 16)
    /* 2A6CA4 003A6CA4 8800043C */  lui        $4, %hi(D_00885A20)
    /* 2A6CA8 003A6CA8 04006334 */  ori        $3, $3, (0x64000004 & 0xFFFF)
    /* 2A6CAC 003A6CAC 7100053C */  lui        $5, %hi(D_0070B580)
    /* 2A6CB0 003A6CB0 01006334 */  ori        $3, $3, 0x1
    /* 2A6CB4 003A6CB4 8800023C */  lui        $2, %hi(D_00885A38)
    /* 2A6CB8 003A6CB8 08006334 */  ori        $3, $3, 0x8
    /* 2A6CBC 003A6CBC 205A8424 */  addiu      $4, $4, %lo(D_00885A20)
    /* 2A6CC0 003A6CC0 80B5A524 */  addiu      $5, $5, %lo(D_0070B580)
    /* 2A6CC4 003A6CC4 10000624 */  addiu      $6, $0, 0x10
    /* 2A6CC8 003A6CC8 04FE100C */  jal        func_0043f810
    /* 2A6CCC 003A6CCC 385A43AC */   sw        $3, %lo(D_00885A38)($2)
    /* 2A6CD0 003A6CD0 006C033C */  lui        $3, (0x6C000004 >> 16)
    /* 2A6CD4 003A6CD4 8800053C */  lui        $5, %hi(D_00885A50)
    /* 2A6CD8 003A6CD8 04006334 */  ori        $3, $3, (0x6C000004 & 0xFFFF)
    /* 2A6CDC 003A6CDC 8800023C */  lui        $2, %hi(D_00885A28)
    /* 2A6CE0 003A6CE0 01006334 */  ori        $3, $3, 0x1
    /* 2A6CE4 003A6CE4 2D202002 */  daddu      $4, $17, $0
    /* 2A6CE8 003A6CE8 08006334 */  ori        $3, $3, 0x8
    /* 2A6CEC 003A6CEC 505AA524 */  addiu      $5, $5, %lo(D_00885A50)
    /* 2A6CF0 003A6CF0 08000624 */  addiu      $6, $0, 0x8
    /* 2A6CF4 003A6CF4 4C4C0F0C */  jal        func_003d3130
    /* 2A6CF8 003A6CF8 285A43AC */   sw        $3, %lo(D_00885A28)($2)
    /* 2A6CFC 003A6CFC 8800053C */  lui        $5, %hi(D_00885A40)
    /* 2A6D00 003A6D00 2D202002 */  daddu      $4, $17, $0
    /* 2A6D04 003A6D04 405AA524 */  addiu      $5, $5, %lo(D_00885A40)
    /* 2A6D08 003A6D08 4C4C0F0C */  jal        func_003d3130
    /* 2A6D0C 003A6D0C 04000624 */   addiu     $6, $0, 0x4
    /* 2A6D10 003A6D10 8800053C */  lui        $5, %hi(D_00885A30)
    /* 2A6D14 003A6D14 2D202002 */  daddu      $4, $17, $0
    /* 2A6D18 003A6D18 305AA524 */  addiu      $5, $5, %lo(D_00885A30)
    /* 2A6D1C 003A6D1C 4C4C0F0C */  jal        func_003d3130
    /* 2A6D20 003A6D20 06000624 */   addiu     $6, $0, 0x6
    /* 2A6D24 003A6D24 8800053C */  lui        $5, %hi(D_00885A20)
    /* 2A6D28 003A6D28 2D202002 */  daddu      $4, $17, $0
    /* 2A6D2C 003A6D2C 205AA524 */  addiu      $5, $5, %lo(D_00885A20)
    /* 2A6D30 003A6D30 4C4C0F0C */  jal        func_003d3130
    /* 2A6D34 003A6D34 07000624 */   addiu     $6, $0, 0x7
    /* 2A6D38 003A6D38 2D202002 */  daddu      $4, $17, $0
    /* 2A6D3C 003A6D3C 04000524 */  addiu      $5, $0, 0x4
    /* 2A6D40 003A6D40 E04D0F0C */  jal        func_003d3780
    /* 2A6D44 003A6D44 35000624 */   addiu     $6, $0, 0x35
    /* 2A6D48 003A6D48 7849100C */  jal        func_004125e0
    /* 2A6D4C 003A6D4C 2D200002 */   daddu     $4, $16, $0
    /* 2A6D50 003A6D50 0000458E */  lw         $5, 0x0($18)
    /* 2A6D54 003A6D54 2D884000 */  daddu      $17, $2, $0
    /* 2A6D58 003A6D58 2D202002 */  daddu      $4, $17, $0
    /* 2A6D5C 003A6D5C 2D300000 */  daddu      $6, $0, $0
    /* 2A6D60 003A6D60 A44B100C */  jal        func_00412e90
    /* 2A6D64 003A6D64 2D380000 */   daddu     $7, $0, $0
    /* 2A6D68 003A6D68 2D804000 */  daddu      $16, $2, $0
    /* 2A6D6C 003A6D6C D4000524 */  addiu      $5, $0, 0xD4
    /* 2A6D70 003A6D70 384E0F0C */  jal        func_003d38e0
    /* 2A6D74 003A6D74 2D200002 */   daddu     $4, $16, $0
    /* 2A6D78 003A6D78 7100053C */  lui        $5, %hi(D_00708470)
    /* 2A6D7C 003A6D7C 2D200002 */  daddu      $4, $16, $0
    /* 2A6D80 003A6D80 7084A524 */  addiu      $5, $5, %lo(D_00708470)
    /* 2A6D84 003A6D84 484E0F0C */  jal        func_003d3920
    /* 2A6D88 003A6D88 04000624 */   addiu     $6, $0, 0x4
    /* 2A6D8C 003A6D8C 3D00063C */  lui        $6, %hi(func_003d0850)
    /* 2A6D90 003A6D90 2D200002 */  daddu      $4, $16, $0
    /* 2A6D94 003A6D94 02000524 */  addiu      $5, $0, 0x2
    /* 2A6D98 003A6D98 684E0F0C */  jal        func_003d39a0
    /* 2A6D9C 003A6D9C 5008C624 */   addiu     $6, $6, %lo(func_003d0850)
    /* 2A6DA0 003A6DA0 3A00063C */  lui        $6, %hi(func_003a6570)
    /* 2A6DA4 003A6DA4 2D200002 */  daddu      $4, $16, $0
    /* 2A6DA8 003A6DA8 03000524 */  addiu      $5, $0, 0x3
    /* 2A6DAC 003A6DAC 684E0F0C */  jal        func_003d39a0
    /* 2A6DB0 003A6DB0 7065C624 */   addiu     $6, $6, %lo(func_003a6570)
    /* 2A6DB4 003A6DB4 3A00063C */  lui        $6, %hi(func_003a6650)
    /* 2A6DB8 003A6DB8 2D200002 */  daddu      $4, $16, $0
    /* 2A6DBC 003A6DBC 04000524 */  addiu      $5, $0, 0x4
    /* 2A6DC0 003A6DC0 684E0F0C */  jal        func_003d39a0
    /* 2A6DC4 003A6DC4 5066C624 */   addiu     $6, $6, %lo(func_003a6650)
  .L003A6DC8:
    /* 2A6DC8 003A6DC8 02000010 */  b          .L003A6DD4
    /* 2A6DCC 003A6DCC 2D102002 */   daddu     $2, $17, $0
  .L003A6DD0:
    /* 2A6DD0 003A6DD0 2D100000 */  daddu      $2, $0, $0
  .L003A6DD4:
    /* 2A6DD4 003A6DD4 3000BFDF */  ld         $31, 0x30($29)
    /* 2A6DD8 003A6DD8 2000B27B */  lq         $18, 0x20($29)
    /* 2A6DDC 003A6DDC 1000B17B */  lq         $17, 0x10($29)
    /* 2A6DE0 003A6DE0 0000B07B */  lq         $16, 0x0($29)
    /* 2A6DE4 003A6DE4 0800E003 */  jr         $31
    /* 2A6DE8 003A6DE8 4000BD27 */   addiu     $29, $29, 0x40
    /* 2A6DEC 003A6DEC 00000000 */  nop
.size func_003a6ba0, 0x250
