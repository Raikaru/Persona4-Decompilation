.section .text
.set noat
.set noreorder
glabel func_001f4c30
    /* F4C30 001F4C30 3000838C */  lw         $3, 0x30($4)
    /* F4C34 001F4C34 A2006290 */  lbu        $2, 0xA2($3)
    /* F4C38 001F4C38 04004010 */  beqz       $2, .L001F4C4C
    /* F4C3C 001F4C3C 00000000 */   nop
    /* F4C40 001F4C40 FFFF0224 */  addiu      $2, $0, -0x1
    /* F4C44 001F4C44 22000010 */  b          .L001F4CD0
    /* F4C48 001F4C48 00000000 */   nop
  .L001F4C4C:
    /* F4C4C 001F4C4C A4006294 */  lhu        $2, 0xA4($3)
    /* F4C50 001F4C50 0900412C */  sltiu      $1, $2, 0x9
    /* F4C54 001F4C54 1D002010 */  beqz       $1, .L001F4CCC
    /* F4C58 001F4C58 00000000 */   nop
    /* F4C5C 001F4C5C 7400033C */  lui        $3, %hi(jtbl_00747470)
    /* F4C60 001F4C60 70746324 */  addiu      $3, $3, %lo(jtbl_00747470)
    /* F4C64 001F4C64 80100200 */  sll        $2, $2, 2
    /* F4C68 001F4C68 21104300 */  addu       $2, $2, $3
    /* F4C6C 001F4C6C 0000428C */  lw         $2, 0x0($2)
    /* F4C70 001F4C70 08004000 */  jr         $2
    /* F4C74 001F4C74 00000000 */   nop
    /* F4C78 001F4C78 2D000224 */  addiu      $2, $0, 0x2D
    /* F4C7C 001F4C7C 14000010 */  b          .L001F4CD0
    /* F4C80 001F4C80 00000000 */   nop
    /* F4C84 001F4C84 2E000224 */  addiu      $2, $0, 0x2E
    /* F4C88 001F4C88 11000010 */  b          .L001F4CD0
    /* F4C8C 001F4C8C 00000000 */   nop
    /* F4C90 001F4C90 2F000224 */  addiu      $2, $0, 0x2F
    /* F4C94 001F4C94 0E000010 */  b          .L001F4CD0
    /* F4C98 001F4C98 00000000 */   nop
    /* F4C9C 001F4C9C 30000224 */  addiu      $2, $0, 0x30
    /* F4CA0 001F4CA0 0B000010 */  b          .L001F4CD0
    /* F4CA4 001F4CA4 00000000 */   nop
    /* F4CA8 001F4CA8 31000224 */  addiu      $2, $0, 0x31
    /* F4CAC 001F4CAC 08000010 */  b          .L001F4CD0
    /* F4CB0 001F4CB0 00000000 */   nop
    /* F4CB4 001F4CB4 32000224 */  addiu      $2, $0, 0x32
    /* F4CB8 001F4CB8 05000010 */  b          .L001F4CD0
    /* F4CBC 001F4CBC 00000000 */   nop
    /* F4CC0 001F4CC0 33000224 */  addiu      $2, $0, 0x33
    /* F4CC4 001F4CC4 02000010 */  b          .L001F4CD0
    /* F4CC8 001F4CC8 00000000 */   nop
  .L001F4CCC:
    /* F4CCC 001F4CCC FFFF0224 */  addiu      $2, $0, -0x1
  .L001F4CD0:
    /* F4CD0 001F4CD0 0800E003 */  jr         $31
    /* F4CD4 001F4CD4 00000000 */   nop
    /* F4CD8 001F4CD8 00000000 */  nop
    /* F4CDC 001F4CDC 00000000 */  nop
.size func_001f4c30, 0xb0
