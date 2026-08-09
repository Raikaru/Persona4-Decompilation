.section .text
.set noat
.set noreorder
glabel func_004e9eb0
    /* 3E9EB0 004E9EB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E9EB4 004E9EB4 1000B0FF */  sd         $16, 0x10($29)
    /* 3E9EB8 004E9EB8 1800B1FF */  sd         $17, 0x18($29)
    /* 3E9EBC 004E9EBC 2D888000 */  daddu      $17, $4, $0
    /* 3E9EC0 004E9EC0 2000B2FF */  sd         $18, 0x20($29)
    /* 3E9EC4 004E9EC4 2800BFFF */  sd         $31, 0x28($29)
    /* 3E9EC8 004E9EC8 520A110C */  jal        func_00442948
    /* 3E9ECC 004E9ECC 2D90A000 */   daddu     $18, $5, $0
    /* 3E9ED0 004E9ED0 7400033C */  lui        $3, %hi(D_00739628)
    /* 3E9ED4 004E9ED4 7600053C */  lui        $5, %hi(D_0075BE00)
    /* 3E9ED8 004E9ED8 28967024 */  addiu      $16, $3, %lo(D_00739628)
    /* 3E9EDC 004E9EDC 11000324 */  addiu      $3, $0, 0x11
    /* 3E9EE0 004E9EE0 00BEA524 */  addiu      $5, $5, %lo(D_0075BE00)
    /* 3E9EE4 004E9EE4 2D302002 */  daddu      $6, $17, $0
    /* 3E9EE8 004E9EE8 06004310 */  beq        $2, $3, .L004E9F04
    /* 3E9EEC 004E9EEC 2D200002 */   daddu     $4, $16, $0
    /* 3E9EF0 004E9EF0 2208110C */  jal        func_00442088
    /* 3E9EF4 004E9EF4 00000000 */   nop
    /* 3E9EF8 004E9EF8 2D280002 */  daddu      $5, $16, $0
    /* 3E9EFC 004E9EFC 9AA7130C */  jal        func_004e9e68
    /* 3E9F00 004E9F00 2D200000 */   daddu     $4, $0, $0
  .L004E9F04:
    /* 3E9F04 004E9F04 08002382 */  lb         $3, 0x8($17)
    /* 3E9F08 004E9F08 2E000224 */  addiu      $2, $0, 0x2E
    /* 3E9F0C 004E9F0C 0A006210 */  beq        $3, $2, .L004E9F38
    /* 3E9F10 004E9F10 7400103C */   lui       $16, %hi(D_00739628)
    /* 3E9F14 004E9F14 7600053C */  lui        $5, %hi(D_0075BE40)
    /* 3E9F18 004E9F18 28961026 */  addiu      $16, $16, %lo(D_00739628)
    /* 3E9F1C 004E9F1C 40BEA524 */  addiu      $5, $5, %lo(D_0075BE40)
    /* 3E9F20 004E9F20 2D200002 */  daddu      $4, $16, $0
    /* 3E9F24 004E9F24 2208110C */  jal        func_00442088
    /* 3E9F28 004E9F28 2D302002 */   daddu     $6, $17, $0
    /* 3E9F2C 004E9F2C 2D200000 */  daddu      $4, $0, $0
    /* 3E9F30 004E9F30 9AA7130C */  jal        func_004e9e68
    /* 3E9F34 004E9F34 2D280002 */   daddu     $5, $16, $0
  .L004E9F38:
    /* 3E9F38 004E9F38 2D28A003 */  daddu      $5, $29, $0
    /* 3E9F3C 004E9F3C 10000624 */  addiu      $6, $0, 0x10
    /* 3E9F40 004E9F40 2D202002 */  daddu      $4, $17, $0
    /* 3E9F44 004E9F44 A6A7130C */  jal        func_004e9e98
    /* 3E9F48 004E9F48 0000B1AF */   sw        $17, 0x0($29)
    /* 3E9F4C 004E9F4C 10000624 */  addiu      $6, $0, 0x10
    /* 3E9F50 004E9F50 3C800200 */  dsll32     $16, $2, 0
    /* 3E9F54 004E9F54 3F801000 */  dsra32     $16, $16, 0
    /* 3E9F58 004E9F58 0000A28F */  lw         $2, 0x0($29)
    /* 3E9F5C 004E9F5C 2D28A003 */  daddu      $5, $29, $0
    /* 3E9F60 004E9F60 00004380 */  lb         $3, 0x0($2)
    /* 3E9F64 004E9F64 02006010 */  beqz       $3, .L004E9F70
    /* 3E9F68 004E9F68 01004224 */   addiu     $2, $2, 0x1
    /* 3E9F6C 004E9F6C 0000A2AF */  sw         $2, 0x0($29)
  .L004E9F70:
    /* 3E9F70 004E9F70 07004012 */  beqz       $18, .L004E9F90
    /* 3E9F74 004E9F74 2D100002 */   daddu     $2, $16, $0
    /* 3E9F78 004E9F78 A6A7130C */  jal        func_004e9e98
    /* 3E9F7C 004E9F7C 0000A48F */   lw        $4, 0x0($29)
    /* 3E9F80 004E9F80 3C100200 */  dsll32     $2, $2, 0
    /* 3E9F84 004E9F84 3F100200 */  dsra32     $2, $2, 0
    /* 3E9F88 004E9F88 000042AE */  sw         $2, 0x0($18)
    /* 3E9F8C 004E9F8C 2D100002 */  daddu      $2, $16, $0
  .L004E9F90:
    /* 3E9F90 004E9F90 1000B0DF */  ld         $16, 0x10($29)
    /* 3E9F94 004E9F94 1800B1DF */  ld         $17, 0x18($29)
    /* 3E9F98 004E9F98 2000B2DF */  ld         $18, 0x20($29)
    /* 3E9F9C 004E9F9C 2800BFDF */  ld         $31, 0x28($29)
    /* 3E9FA0 004E9FA0 0800E003 */  jr         $31
    /* 3E9FA4 004E9FA4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e9eb0, 0xf8
