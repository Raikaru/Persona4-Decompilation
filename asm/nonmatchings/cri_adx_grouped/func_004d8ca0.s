.section .text
.set noat
.set noreorder
glabel func_004d8ca0
    /* 3D8CA0 004D8CA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8CA4 004D8CA4 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D8CA8 004D8CA8 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8CAC 004D8CAC 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D8CB0 004D8CB0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8CB4 004D8CB4 FC011308 */  j          func_004c07f0
    /* 3D8CB8 004D8CB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8CBC 004D8CBC 00000000 */  nop
.size func_004d8ca0, 0x20
