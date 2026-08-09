.section .text
.set noat
.set noreorder
glabel func_001b0bf0
    /* B0BF0 001B0BF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* B0BF4 001B0BF4 1000BFFF */  sd         $31, 0x10($29)
    /* B0BF8 001B0BF8 0000B07F */  sq         $16, 0x0($29)
    /* B0BFC 001B0BFC ACB3838F */  lw         $3, -0x4C54($28)
    /* B0C00 001B0C00 7401648C */  lw         $4, 0x174($3)
    /* B0C04 001B0C04 15000010 */  b          .L001B0C5C
    /* B0C08 001B0C08 00000000 */   nop
  .L001B0C0C:
    /* B0C0C 001B0C0C 5004908C */  lw         $16, 0x450($4)
    /* B0C10 001B0C10 03000012 */  beqz       $16, .L001B0C20
    /* B0C14 001B0C14 00000000 */   nop
    /* B0C18 001B0C18 4C04828C */  lw         $2, 0x44C($4)
    /* B0C1C 001B0C1C 4C0402AE */  sw         $2, 0x44C($16)
  .L001B0C20:
    /* B0C20 001B0C20 4C04838C */  lw         $3, 0x44C($4)
    /* B0C24 001B0C24 05006010 */  beqz       $3, .L001B0C3C
    /* B0C28 001B0C28 00000000 */   nop
    /* B0C2C 001B0C2C 5004828C */  lw         $2, 0x450($4)
    /* B0C30 001B0C30 500462AC */  sw         $2, 0x450($3)
    /* B0C34 001B0C34 04000010 */  b          .L001B0C48
    /* B0C38 001B0C38 00000000 */   nop
  .L001B0C3C:
    /* B0C3C 001B0C3C 5004838C */  lw         $3, 0x450($4)
    /* B0C40 001B0C40 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0C44 001B0C44 740143AC */  sw         $3, 0x174($2)
  .L001B0C48:
    /* B0C48 001B0C48 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* B0C4C 001B0C4C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* B0C50 001B0C50 09F84000 */  jalr       $2
    /* B0C54 001B0C54 00000000 */   nop
    /* B0C58 001B0C58 2D200002 */  daddu      $4, $16, $0
  .L001B0C5C:
    /* B0C5C 001B0C5C EBFF8014 */  bnez       $4, .L001B0C0C
    /* B0C60 001B0C60 00000000 */   nop
    /* B0C64 001B0C64 1000BFDF */  ld         $31, 0x10($29)
    /* B0C68 001B0C68 0000B07B */  lq         $16, 0x0($29)
    /* B0C6C 001B0C6C 2000BD27 */  addiu      $29, $29, 0x20
    /* B0C70 001B0C70 0800E003 */  jr         $31
    /* B0C74 001B0C74 00000000 */   nop
    /* B0C78 001B0C78 00000000 */  nop
    /* B0C7C 001B0C7C 00000000 */  nop
.size func_001b0bf0, 0x90
