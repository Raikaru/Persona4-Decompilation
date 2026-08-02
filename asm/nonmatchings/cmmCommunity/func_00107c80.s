.section .text
.set noat
.set noreorder
glabel func_00107c80
    /* 7C80 00107C80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 7C84 00107C84 0000BFFF */  sd         $31, 0x0($29)
    /* 7C88 00107C88 381C040C */  jal        func_001070e0
    /* 7C8C 00107C8C 00000000 */   nop
    /* 7C90 00107C90 04004014 */  bnez       $2, .L00107CA4
    /* 7C94 00107C94 00000000 */   nop
    /* 7C98 00107C98 2D100000 */  daddu      $2, $0, $0
    /* 7C9C 00107C9C 03000010 */  b          .L00107CAC
    /* 7CA0 00107CA0 00000000 */   nop
  .L00107CA4:
    /* 7CA4 00107CA4 0000428C */  lw         $2, 0x0($2)
    /* 7CA8 00107CA8 01004230 */  andi       $2, $2, 0x1
  .L00107CAC:
    /* 7CAC 00107CAC 04004010 */  beqz       $2, .L00107CC0
    /* 7CB0 00107CB0 00000000 */   nop
    /* 7CB4 00107CB4 01000224 */  addiu      $2, $0, 0x1
    /* 7CB8 00107CB8 02000010 */  b          .L00107CC4
    /* 7CBC 00107CBC 00000000 */   nop
  .L00107CC0:
    /* 7CC0 00107CC0 2D100000 */  daddu      $2, $0, $0
  .L00107CC4:
    /* 7CC4 00107CC4 0000BFDF */  ld         $31, 0x0($29)
    /* 7CC8 00107CC8 1000BD27 */  addiu      $29, $29, 0x10
    /* 7CCC 00107CCC 0800E003 */  jr         $31
    /* 7CD0 00107CD0 00000000 */   nop
    /* 7CD4 00107CD4 00000000 */  nop
    /* 7CD8 00107CD8 00000000 */  nop
    /* 7CDC 00107CDC 00000000 */  nop
.size func_00107c80, 0x60
