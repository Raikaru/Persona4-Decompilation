.section .text
.set noat
.set noreorder
glabel func_004eb158
    /* 3EB158 004EB158 7200023C */  lui        $2, %hi(D_00724E80)
    /* 3EB15C 004EB15C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB160 004EB160 804E428C */  lw         $2, %lo(D_00724E80)($2)
    /* 3EB164 004EB164 03004010 */  beqz       $2, .L004EB174
    /* 3EB168 004EB168 0000BFFF */   sd        $31, 0x0($29)
    /* 3EB16C 004EB16C 09F84000 */  jalr       $2
    /* 3EB170 004EB170 00000000 */   nop
  .L004EB174:
    /* 3EB174 004EB174 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB178 004EB178 0800E003 */  jr         $31
    /* 3EB17C 004EB17C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb158, 0x28
