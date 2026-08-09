.section .text
.set noat
.set noreorder
glabel func_004c6a70
    /* 3C6A70 004C6A70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6A74 004C6A74 7100023C */  lui        $2, %hi(D_00715CA0)
    /* 3C6A78 004C6A78 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6A7C 004C6A7C 7100033C */  lui        $3, %hi(D_00715CA4)
    /* 3C6A80 004C6A80 A05C44AC */  sw         $4, %lo(D_00715CA0)($2)
    /* 3C6A84 004C6A84 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6A88 004C6A88 A45C65AC */  sw         $5, %lo(D_00715CA4)($3)
    /* 3C6A8C 004C6A8C A0C31308 */  j          func_004f0e80
    /* 3C6A90 004C6A90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6A94 004C6A94 00000000 */  nop
.size func_004c6a70, 0x28
