.section .text
.set noat
.set noreorder
glabel func_00200cb0
    /* 100CB0 00200CB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 100CB4 00200CB4 0000BFFF */  sd         $31, 0x0($29)
    /* 100CB8 00200CB8 6200043C */  lui        $4, %hi(D_00625240)
    /* 100CBC 00200CBC 40528424 */  addiu      $4, $4, %lo(D_00625240)
    /* 100CC0 00200CC0 2000053C */  lui        $5, %hi(func_00200ce0)
    /* 100CC4 00200CC4 E00CA524 */  addiu      $5, $5, %lo(func_00200ce0)
    /* 100CC8 00200CC8 E4D5120C */  jal        func_004b5790
    /* 100CCC 00200CCC 00000000 */   nop
    /* 100CD0 00200CD0 0000BFDF */  ld         $31, 0x0($29)
    /* 100CD4 00200CD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 100CD8 00200CD8 0800E003 */  jr         $31
    /* 100CDC 00200CDC 00000000 */   nop
.size func_00200cb0, 0x30
