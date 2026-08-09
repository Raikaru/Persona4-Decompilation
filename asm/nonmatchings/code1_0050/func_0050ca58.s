.section .text
.set noat
.set noreorder
glabel func_0050ca58
    /* 40CA58 0050CA58 05008014 */  bnez       $4, .L0050CA70
    /* 40CA5C 0050CA5C 7400033C */   lui       $3, %hi(D_00745878)
    /* 40CA60 0050CA60 7400023C */  lui        $2, %hi(D_00745878)
    /* 40CA64 0050CA64 0800E003 */  jr         $31
    /* 40CA68 0050CA68 785840AC */   sw        $0, %lo(D_00745878)($2)
    /* 40CA6C 0050CA6C 00000000 */  nop
  .L0050CA70:
    /* 40CA70 0050CA70 01000224 */  addiu      $2, $0, 0x1
    /* 40CA74 0050CA74 0800E003 */  jr         $31
    /* 40CA78 0050CA78 785862AC */   sw        $2, %lo(D_00745878)($3)
    /* 40CA7C 0050CA7C 00000000 */  nop
.size func_0050ca58, 0x28
