.section .text
.set noat
.set noreorder
glabel func_00121db0
    /* 21DB0 00121DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 21DB4 00121DB4 0000BFFF */  sd         $31, 0x0($29)
    /* 21DB8 00121DB8 CCB1848F */  lw         $4, -0x4E34($28)
    /* 21DBC 00121DBC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 21DC0 00121DC0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 21DC4 00121DC4 09F84000 */  jalr       $2
    /* 21DC8 00121DC8 00000000 */   nop
    /* 21DCC 00121DCC CCB180AF */  sw         $0, -0x4E34($28)
    /* 21DD0 00121DD0 0000BFDF */  ld         $31, 0x0($29)
    /* 21DD4 00121DD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 21DD8 00121DD8 0800E003 */  jr         $31
    /* 21DDC 00121DDC 00000000 */   nop
.size func_00121db0, 0x30
