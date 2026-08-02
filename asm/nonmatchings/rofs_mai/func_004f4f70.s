.section .text
.set noat
.set noreorder
glabel func_004f4f70
    /* 3F4F70 004F4F70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3F4F74 004F4F74 2D408000 */  daddu      $8, $4, $0
    /* 3F4F78 004F4F78 3000B0FF */  sd         $16, 0x30($29)
    /* 3F4F7C 004F4F7C 1000B027 */  addiu      $16, $29, 0x10
    /* 3F4F80 004F4F80 2D20A003 */  daddu      $4, $29, $0
    /* 3F4F84 004F4F84 09000624 */  addiu      $6, $0, 0x9
    /* 3F4F88 004F4F88 2D280002 */  daddu      $5, $16, $0
    /* 3F4F8C 004F4F8C 3800BFFF */  sd         $31, 0x38($29)
    /* 3F4F90 004F4F90 02CB130C */  jal        func_004f2c08
    /* 3F4F94 004F4F94 20000724 */   addiu     $7, $0, 0x20
    /* 3F4F98 004F4F98 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4F9C 004F4F9C 7600063C */  lui        $6, %hi(D_0075D7C0)
    /* 3F4FA0 004F4FA0 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4FA4 004F4FA4 C0D7C624 */  addiu      $6, $6, %lo(D_0075D7C0)
    /* 3F4FA8 004F4FA8 2D280000 */  daddu      $5, $0, $0
    /* 3F4FAC 004F4FAC 2D380000 */  daddu      $7, $0, $0
    /* 3F4FB0 004F4FB0 03004014 */  bnez       $2, .L004F4FC0
    /* 3F4FB4 004F4FB4 9CFF0824 */   addiu     $8, $0, -0x64
    /* 3F4FB8 004F4FB8 0C000010 */  b          .L004F4FEC
    /* 3F4FBC 004F4FBC 7F070524 */   addiu     $5, $0, 0x77F
  .L004F4FC0:
    /* 3F4FC0 004F4FC0 A0CB130C */  jal        func_004f2e80
    /* 3F4FC4 004F4FC4 2D20A003 */   daddu     $4, $29, $0
    /* 3F4FC8 004F4FC8 2D200002 */  daddu      $4, $16, $0
    /* 3F4FCC 004F4FCC 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F4FD0 004F4FD0 85070524 */  addiu      $5, $0, 0x785
    /* 3F4FD4 004F4FD4 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F4FD8 004F4FD8 2D380000 */  daddu      $7, $0, $0
    /* 3F4FDC 004F4FDC 08004014 */  bnez       $2, .L004F5000
    /* 3F4FE0 004F4FE0 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F4FE4 004F4FE4 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4FE8 004F4FE8 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
  .L004F4FEC:
    /* 3F4FEC 004F4FEC F0D4130C */  jal        func_004f53c0
    /* 3F4FF0 004F4FF0 00000000 */   nop
    /* 3F4FF4 004F4FF4 06000010 */  b          .L004F5010
    /* 3F4FF8 004F4FF8 2D100000 */   daddu     $2, $0, $0
    /* 3F4FFC 004F4FFC 00000000 */  nop
  .L004F5000:
    /* 3F5000 004F5000 1000458C */  lw         $5, 0x10($2)
    /* 3F5004 004F5004 90E0130C */  jal        func_004f8240
    /* 3F5008 004F5008 2D304000 */   daddu     $6, $2, $0
    /* 3F500C 004F500C 2B100200 */  sltu       $2, $0, $2
  .L004F5010:
    /* 3F5010 004F5010 3000B0DF */  ld         $16, 0x30($29)
    /* 3F5014 004F5014 3800BFDF */  ld         $31, 0x38($29)
    /* 3F5018 004F5018 0800E003 */  jr         $31
    /* 3F501C 004F501C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004f4f70, 0xb0
