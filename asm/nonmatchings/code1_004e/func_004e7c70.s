.section .text
.set noat
.set noreorder
glabel func_004e7c70
    /* 3E7C70 004E7C70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E7C74 004E7C74 2D388000 */  daddu      $7, $4, $0
    /* 3E7C78 004E7C78 0700E014 */  bnez       $7, .L004E7C98
    /* 3E7C7C 004E7C7C 0000BFFF */   sd        $31, 0x0($29)
    /* 3E7C80 004E7C80 7600053C */  lui        $5, %hi(D_0075B6D0)
    /* 3E7C84 004E7C84 169D130C */  jal        func_004e7458
    /* 3E7C88 004E7C88 D0B6A524 */   addiu     $5, $5, %lo(D_0075B6D0)
    /* 3E7C8C 004E7C8C 1A000010 */  b          .L004E7CF8
    /* 3E7C90 004E7C90 2D100000 */   daddu     $2, $0, $0
    /* 3E7C94 004E7C94 00000000 */  nop
  .L004E7C98:
    /* 3E7C98 004E7C98 0300C014 */  bnez       $6, .L004E7CA8
    /* 3E7C9C 004E7C9C 02000224 */   addiu     $2, $0, 0x2
    /* 3E7CA0 004E7CA0 0D000010 */  b          .L004E7CD8
    /* 3E7CA4 004E7CA4 1C00E5AC */   sw        $5, 0x1C($7)
  .L004E7CA8:
    /* 3E7CA8 004E7CA8 0500C214 */  bne        $6, $2, .L004E7CC0
    /* 3E7CAC 004E7CAC 01000224 */   addiu     $2, $0, 0x1
    /* 3E7CB0 004E7CB0 1000E48C */  lw         $4, 0x10($7)
    /* 3E7CB4 004E7CB4 21108500 */  addu       $2, $4, $5
    /* 3E7CB8 004E7CB8 08000010 */  b          .L004E7CDC
    /* 3E7CBC 004E7CBC 1C00E2AC */   sw        $2, 0x1C($7)
  .L004E7CC0:
    /* 3E7CC0 004E7CC0 0600C214 */  bne        $6, $2, .L004E7CDC
    /* 3E7CC4 004E7CC4 1000E48C */   lw        $4, 0x10($7)
    /* 3E7CC8 004E7CC8 1C00E28C */  lw         $2, 0x1C($7)
    /* 3E7CCC 004E7CCC 21104500 */  addu       $2, $2, $5
    /* 3E7CD0 004E7CD0 02000010 */  b          .L004E7CDC
    /* 3E7CD4 004E7CD4 1C00E2AC */   sw        $2, 0x1C($7)
  .L004E7CD8:
    /* 3E7CD8 004E7CD8 1000E48C */  lw         $4, 0x10($7)
  .L004E7CDC:
    /* 3E7CDC 004E7CDC 1C00E28C */  lw         $2, 0x1C($7)
    /* 3E7CE0 004E7CE0 2800E0AC */  sw         $0, 0x28($7)
    /* 3E7CE4 004E7CE4 2A184400 */  slt        $3, $2, $4
    /* 3E7CE8 004E7CE8 0A108300 */  movz       $2, $4, $3
    /* 3E7CEC 004E7CEC 00004428 */  slti       $4, $2, 0x0
    /* 3E7CF0 004E7CF0 0B100400 */  movn       $2, $0, $4
    /* 3E7CF4 004E7CF4 1C00E2AC */  sw         $2, 0x1C($7)
  .L004E7CF8:
    /* 3E7CF8 004E7CF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E7CFC 004E7CFC 0800E003 */  jr         $31
    /* 3E7D00 004E7D00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E7D04 004E7D04 00000000 */  nop
.size func_004e7c70, 0x98
