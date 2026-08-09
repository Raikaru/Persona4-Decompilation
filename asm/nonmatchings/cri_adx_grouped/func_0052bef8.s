.section .text
.set noat
.set noreorder
glabel func_0052bef8
    /* 42BEF8 0052BEF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BEFC 0052BEFC 0000BFFF */  sd         $31, 0x0($29)
    /* 42BF00 0052BF00 0000BFDF */  ld         $31, 0x0($29)
    /* 42BF04 0052BF04 C4AF1408 */  j          func_0052bf10
    /* 42BF08 0052BF08 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BF0C 0052BF0C 00000000 */  nop
.size func_0052bef8, 0x18
