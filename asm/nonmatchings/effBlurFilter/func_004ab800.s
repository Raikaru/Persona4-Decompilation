.section .text
.set noat
.set noreorder
glabel func_004ab800
    /* 3AB800 004AB800 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AB804 004AB804 0000BFFF */  sd         $31, 0x0($29)
    /* 3AB808 004AB808 1800838C */  lw         $3, 0x18($4)
    /* 3AB80C 004AB80C 40100300 */  sll        $2, $3, 1
    /* 3AB810 004AB810 21104300 */  addu       $2, $2, $3
    /* 3AB814 004AB814 C0180200 */  sll        $3, $2, 3
    /* 3AB818 004AB818 7100023C */  lui        $2, %hi(D_0071446C)
    /* 3AB81C 004AB81C 6C444224 */  addiu      $2, $2, %lo(D_0071446C)
    /* 3AB820 004AB820 21104300 */  addu       $2, $2, $3
    /* 3AB824 004AB824 0000428C */  lw         $2, 0x0($2)
    /* 3AB828 004AB828 09F84000 */  jalr       $2
    /* 3AB82C 004AB82C 00000000 */   nop
    /* 3AB830 004AB830 0000BFDF */  ld         $31, 0x0($29)
    /* 3AB834 004AB834 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AB838 004AB838 0800E003 */  jr         $31
    /* 3AB83C 004AB83C 00000000 */   nop
.size func_004ab800, 0x40
