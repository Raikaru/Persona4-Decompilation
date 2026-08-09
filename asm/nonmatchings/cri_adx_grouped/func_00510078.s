.section .text
.set noat
.set noreorder
glabel func_00510078
    /* 410078 00510078 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41007C 0051007C 0000BFFF */  sd         $31, 0x0($29)
    /* 410080 00510080 4800848C */  lw         $4, 0x48($4)
    /* 410084 00510084 0000BFDF */  ld         $31, 0x0($29)
    /* 410088 00510088 14A51308 */  j          func_004e9450
    /* 41008C 0051008C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510078, 0x18
