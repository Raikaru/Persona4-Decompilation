.section .text
.set noat
.set noreorder
glabel func_004d8c78
    /* 3D8C78 004D8C78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8C7C 004D8C7C 7200033C */  lui        $3, %hi(D_00725290)
    /* 3D8C80 004D8C80 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8C84 004D8C84 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D8C88 004D8C88 90526324 */  addiu      $3, $3, %lo(D_00725290)
    /* 3D8C8C 004D8C8C 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D8C90 004D8C90 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8C94 004D8C94 0000628C */  lw         $2, 0x0($3)
    /* 3D8C98 004D8C98 C6011308 */  j          func_004c0718
    /* 3D8C9C 004D8C9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d8c78, 0x28
