.section .text
.set noat
.set noreorder
glabel func_001fe060
    /* FE060 001FE060 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FE064 001FE064 0000BFFF */  sd         $31, 0x0($29)
    /* FE068 001FE068 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* FE06C 001FE06C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* FE070 001FE070 09F84000 */  jalr       $2
    /* FE074 001FE074 00000000 */   nop
    /* FE078 001FE078 0000BFDF */  ld         $31, 0x0($29)
    /* FE07C 001FE07C 1000BD27 */  addiu      $29, $29, 0x10
    /* FE080 001FE080 0800E003 */  jr         $31
    /* FE084 001FE084 00000000 */   nop
    /* FE088 001FE088 00000000 */  nop
    /* FE08C 001FE08C 00000000 */  nop
.size func_001fe060, 0x30
