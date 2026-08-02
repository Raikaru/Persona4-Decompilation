.section .text
.set noat
.set noreorder
glabel func_0012d160
    /* 2D160 0012D160 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D164 0012D164 0000BFFF */  sd         $31, 0x0($29)
    /* 2D168 0012D168 3800848C */  lw         $4, 0x38($4)
    /* 2D16C 0012D16C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2D170 0012D170 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2D174 0012D174 09F84000 */  jalr       $2
    /* 2D178 0012D178 00000000 */   nop
    /* 2D17C 0012D17C 0000BFDF */  ld         $31, 0x0($29)
    /* 2D180 0012D180 1000BD27 */  addiu      $29, $29, 0x10
    /* 2D184 0012D184 0800E003 */  jr         $31
    /* 2D188 0012D188 00000000 */   nop
    /* 2D18C 0012D18C 00000000 */  nop
.size func_0012d160, 0x30
