.section .text
.set noat
.set noreorder
glabel func_004e5c68
    /* 3E5C68 004E5C68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5C6C 004E5C6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5C70 004E5C70 0800BFFF */  sd         $31, 0x8($29)
    /* 3E5C74 004E5C74 520A110C */  jal        func_00442948
    /* 3E5C78 004E5C78 2D808000 */   daddu     $16, $4, $0
    /* 3E5C7C 004E5C7C 2D384000 */  daddu      $7, $2, $0
    /* 3E5C80 004E5C80 1300E010 */  beqz       $7, .L004E5CD0
    /* 3E5C84 004E5C84 2D300000 */   daddu     $6, $0, $0
    /* 3E5C88 004E5C88 2F000924 */  addiu      $9, $0, 0x2F
    /* 3E5C8C 004E5C8C 5C000824 */  addiu      $8, $0, 0x5C
    /* 3E5C90 004E5C90 21200602 */  addu       $4, $16, $6
    /* 3E5C94 004E5C94 00000000 */  nop
  .L004E5C98:
    /* 3E5C98 004E5C98 0100C624 */  addiu      $6, $6, 0x1
    /* 3E5C9C 004E5C9C 00008280 */  lb         $2, 0x0($4)
    /* 3E5CA0 004E5CA0 2B28C700 */  sltu       $5, $6, $7
    /* 3E5CA4 004E5CA4 03004914 */  bne        $2, $9, .L004E5CB4
    /* 3E5CA8 004E5CA8 00008390 */   lbu       $3, 0x0($4)
    /* 3E5CAC 004E5CAC 000088A0 */  sb         $8, 0x0($4)
    /* 3E5CB0 004E5CB0 2D180001 */  daddu      $3, $8, $0
  .L004E5CB4:
    /* 3E5CB4 004E5CB4 9FFF6224 */  addiu      $2, $3, -0x61
    /* 3E5CB8 004E5CB8 1A00422C */  sltiu      $2, $2, 0x1A
    /* 3E5CBC 004E5CBC 02004010 */  beqz       $2, .L004E5CC8
    /* 3E5CC0 004E5CC0 E0FF6224 */   addiu     $2, $3, -0x20
    /* 3E5CC4 004E5CC4 000082A0 */  sb         $2, 0x0($4)
  .L004E5CC8:
    /* 3E5CC8 004E5CC8 F3FFA014 */  bnez       $5, .L004E5C98
    /* 3E5CCC 004E5CCC 21200602 */   addu      $4, $16, $6
  .L004E5CD0:
    /* 3E5CD0 004E5CD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E5CD4 004E5CD4 0800BFDF */  ld         $31, 0x8($29)
    /* 3E5CD8 004E5CD8 0800E003 */  jr         $31
    /* 3E5CDC 004E5CDC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e5c68, 0x78
