.section .text
.set noat
.set noreorder
glabel func_001da640
    /* DA640 001DA640 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA644 001DA644 0000BFFF */  sd         $31, 0x0($29)
    /* DA648 001DA648 3000828C */  lw         $2, 0x30($4)
    /* DA64C 001DA64C A2004390 */  lbu        $3, 0xA2($2)
    /* DA650 001DA650 01000224 */  addiu      $2, $0, 0x1
    /* DA654 001DA654 04106200 */  sllv       $2, $2, $3
    /* DA658 001DA658 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA65C 001DA65C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA660 001DA660 2D400000 */  daddu      $8, $0, $0
    /* DA664 001DA664 1E00093C */  lui        $9, %hi(func_001da5f0)
    /* DA668 001DA668 F0A52925 */  addiu      $9, $9, %lo(func_001da5f0)
    /* DA66C 001DA66C 3465070C */  jal        func_001d94d0
    /* DA670 001DA670 00000000 */   nop
    /* DA674 001DA674 0000BFDF */  ld         $31, 0x0($29)
    /* DA678 001DA678 1000BD27 */  addiu      $29, $29, 0x10
    /* DA67C 001DA67C 0800E003 */  jr         $31
    /* DA680 001DA680 00000000 */   nop
    /* DA684 001DA684 00000000 */  nop
    /* DA688 001DA688 00000000 */  nop
    /* DA68C 001DA68C 00000000 */  nop
.size func_001da640, 0x50
