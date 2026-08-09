.section .text
.set noat
.set noreorder
glabel func_004c6a00
    /* 3C6A00 004C6A00 7100043C */  lui        $4, %hi(D_00715CA8)
    /* 3C6A04 004C6A04 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6A08 004C6A08 2D280000 */  daddu      $5, $0, $0
    /* 3C6A0C 004C6A0C A85C8424 */  addiu      $4, $4, %lo(D_00715CA8)
    /* 3C6A10 004C6A10 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6A14 004C6A14 72FE100C */  jal        func_0043f9c8
    /* 3C6A18 004C6A18 00010624 */   addiu     $6, $0, 0x100
    /* 3C6A1C 004C6A1C 7100033C */  lui        $3, %hi(D_00715CA0)
    /* 3C6A20 004C6A20 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6A24 004C6A24 7100023C */  lui        $2, %hi(D_00715CA4)
    /* 3C6A28 004C6A28 A05C60AC */  sw         $0, %lo(D_00715CA0)($3)
    /* 3C6A2C 004C6A2C A45C40AC */  sw         $0, %lo(D_00715CA4)($2)
    /* 3C6A30 004C6A30 0800E003 */  jr         $31
    /* 3C6A34 004C6A34 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c6a00, 0x38
