.section .text
.set noat
.set noreorder
glabel func_001c6b60
    /* C6B60 001C6B60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* C6B64 001C6B64 0000BFFF */  sd         $31, 0x0($29)
    /* C6B68 001C6B68 7041023C */  lui        $2, (0x41700000 >> 16)
    /* C6B6C 001C6B6C 00608244 */  mtc1       $2, $f12
    /* C6B70 001C6B70 0040023C */  lui        $2, (0x40000000 >> 16)
    /* C6B74 001C6B74 00688244 */  mtc1       $2, $f13
    /* C6B78 001C6B78 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* C6B7C 001C6B7C 00708244 */  mtc1       $2, $f14
    /* C6B80 001C6B80 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* C6B84 001C6B84 00788244 */  mtc1       $2, $f15
    /* C6B88 001C6B88 D819070C */  jal        func_001c6760
    /* C6B8C 001C6B8C 00000000 */   nop
    /* C6B90 001C6B90 0000BFDF */  ld         $31, 0x0($29)
    /* C6B94 001C6B94 1000BD27 */  addiu      $29, $29, 0x10
    /* C6B98 001C6B98 0800E003 */  jr         $31
    /* C6B9C 001C6B9C 00000000 */   nop
    /* C6BA0 001C6BA0 0800E003 */  jr         $31
    /* C6BA4 001C6BA4 00000000 */   nop
    /* C6BA8 001C6BA8 00000000 */  nop
    /* C6BAC 001C6BAC 00000000 */  nop
.size func_001c6b60, 0x50
