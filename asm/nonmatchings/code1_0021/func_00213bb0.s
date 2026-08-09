.section .text
.set noat
.set noreorder
glabel func_00213bb0
    /* 113BB0 00213BB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 113BB4 00213BB4 0000BFFF */  sd         $31, 0x0($29)
    /* 113BB8 00213BB8 5849110C */  jal        func_00452560
    /* 113BBC 00213BBC 00000000 */   nop
    /* 113BC0 00213BC0 0C08448C */  lw         $4, 0x80C($2)
    /* 113BC4 00213BC4 FBFF0324 */  addiu      $3, $0, -0x5
    /* 113BC8 00213BC8 24188300 */  and        $3, $4, $3
    /* 113BCC 00213BCC 0C0843AC */  sw         $3, 0x80C($2)
    /* 113BD0 00213BD0 0000BFDF */  ld         $31, 0x0($29)
    /* 113BD4 00213BD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 113BD8 00213BD8 0800E003 */  jr         $31
    /* 113BDC 00213BDC 00000000 */   nop
.size func_00213bb0, 0x30
