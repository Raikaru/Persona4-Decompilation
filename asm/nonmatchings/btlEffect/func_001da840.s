.section .text
.set noat
.set noreorder
glabel func_001da840
    /* DA840 001DA840 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA844 001DA844 0000BFFF */  sd         $31, 0x0($29)
    /* DA848 001DA848 3000828C */  lw         $2, 0x30($4)
    /* DA84C 001DA84C A2004390 */  lbu        $3, 0xA2($2)
    /* DA850 001DA850 01000224 */  addiu      $2, $0, 0x1
    /* DA854 001DA854 04106200 */  sllv       $2, $2, $3
    /* DA858 001DA858 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA85C 001DA85C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA860 001DA860 2D400000 */  daddu      $8, $0, $0
    /* DA864 001DA864 1E00093C */  lui        $9, %hi(func_001da7e0)
    /* DA868 001DA868 E0A72925 */  addiu      $9, $9, %lo(func_001da7e0)
    /* DA86C 001DA86C 3465070C */  jal        func_001d94d0
    /* DA870 001DA870 00000000 */   nop
    /* DA874 001DA874 0000BFDF */  ld         $31, 0x0($29)
    /* DA878 001DA878 1000BD27 */  addiu      $29, $29, 0x10
    /* DA87C 001DA87C 0800E003 */  jr         $31
    /* DA880 001DA880 00000000 */   nop
    /* DA884 001DA884 00000000 */  nop
    /* DA888 001DA888 00000000 */  nop
    /* DA88C 001DA88C 00000000 */  nop
.size func_001da840, 0x50
