.section .text
.set noat
.set noreorder
glabel func_004cbc88
    /* 3CBC88 004CBC88 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBC8C 004CBC8C 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBC90 004CBC90 2D808000 */  daddu      $16, $4, $0
    /* 3CBC94 004CBC94 0C000012 */  beqz       $16, .L004CBCC8
    /* 3CBC98 004CBC98 3800BFFF */   sd        $31, 0x38($29)
    /* 3CBC9C 004CBC9C BC85100C */  jal        func_004216f0
    /* 3CBCA0 004CBCA0 2D28A003 */   daddu     $5, $29, $0
    /* 3CBCA4 004CBCA4 2D200002 */  daddu      $4, $16, $0
    /* 3CBCA8 004CBCA8 0000A38F */  lw         $3, 0x0($29)
    /* 3CBCAC 004CBCAC 04000224 */  addiu      $2, $0, 0x4
    /* 3CBCB0 004CBCB0 03006210 */  beq        $3, $2, .L004CBCC0
    /* 3CBCB4 004CBCB4 0C000524 */   addiu     $5, $0, 0xC
    /* 3CBCB8 004CBCB8 04006514 */  bne        $3, $5, .L004CBCCC
    /* 3CBCBC 004CBCBC 3000B0DF */   ld        $16, 0x30($29)
  .L004CBCC0:
    /* 3CBCC0 004CBCC0 AA89100C */  jal        func_004226a8
    /* 3CBCC4 004CBCC4 00000000 */   nop
  .L004CBCC8:
    /* 3CBCC8 004CBCC8 3000B0DF */  ld         $16, 0x30($29)
  .L004CBCCC:
    /* 3CBCCC 004CBCCC 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBCD0 004CBCD0 0800E003 */  jr         $31
    /* 3CBCD4 004CBCD4 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cbc88, 0x50
