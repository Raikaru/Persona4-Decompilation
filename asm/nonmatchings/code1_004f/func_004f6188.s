.section .text
.set noat
.set noreorder
glabel func_004f6188
    /* 3F6188 004F6188 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F618C 004F618C 80300600 */  sll        $6, $6, 2
    /* 3F6190 004F6190 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6194 004F6194 2130C500 */  addu       $6, $6, $5
    /* 3F6198 004F6198 9200023C */  lui        $2, %hi(D_00925FA8)
    /* 3F619C 004F619C 0000C38C */  lw         $3, 0x0($6)
    /* 3F61A0 004F61A0 A85F458C */  lw         $5, %lo(D_00925FA8)($2)
    /* 3F61A4 004F61A4 0400C68C */  lw         $6, 0x4($6)
    /* 3F61A8 004F61A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F61AC 004F61AC 2128A300 */  addu       $5, $5, $3
    /* 3F61B0 004F61B0 2330C300 */  subu       $6, $6, $3
    /* 3F61B4 004F61B4 04FE1008 */  j          func_0043f810
    /* 3F61B8 004F61B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F61BC 004F61BC 00000000 */  nop
.size func_004f6188, 0x38
