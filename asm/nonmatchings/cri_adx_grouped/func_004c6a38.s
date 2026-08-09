.section .text
.set noat
.set noreorder
glabel func_004c6a38
    /* 3C6A38 004C6A38 7100043C */  lui        $4, %hi(D_00715CA8)
    /* 3C6A3C 004C6A3C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6A40 004C6A40 2D280000 */  daddu      $5, $0, $0
    /* 3C6A44 004C6A44 A85C8424 */  addiu      $4, $4, %lo(D_00715CA8)
    /* 3C6A48 004C6A48 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6A4C 004C6A4C 72FE100C */  jal        func_0043f9c8
    /* 3C6A50 004C6A50 00010624 */   addiu     $6, $0, 0x100
    /* 3C6A54 004C6A54 7100033C */  lui        $3, %hi(D_00715CA0)
    /* 3C6A58 004C6A58 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6A5C 004C6A5C 7100023C */  lui        $2, %hi(D_00715CA4)
    /* 3C6A60 004C6A60 A05C60AC */  sw         $0, %lo(D_00715CA0)($3)
    /* 3C6A64 004C6A64 A45C40AC */  sw         $0, %lo(D_00715CA4)($2)
    /* 3C6A68 004C6A68 0800E003 */  jr         $31
    /* 3C6A6C 004C6A6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c6a38, 0x38
