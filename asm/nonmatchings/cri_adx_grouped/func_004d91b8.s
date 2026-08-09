.section .text
.set noat
.set noreorder
glabel func_004d91b8
    /* 3D91B8 004D91B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D91BC 004D91BC 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D91C0 004D91C0 0000B0FF */  sd         $16, 0x0($29)
    /* 3D91C4 004D91C4 2D808000 */  daddu      $16, $4, $0
    /* 3D91C8 004D91C8 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D91CC 004D91CC 0800BFFF */  sd         $31, 0x8($29)
    /* 3D91D0 004D91D0 8003130C */  jal        func_004c0e00
    /* 3D91D4 004D91D4 00000000 */   nop
    /* 3D91D8 004D91D8 2D280002 */  daddu      $5, $16, $0
    /* 3D91DC 004D91DC 0800BFDF */  ld         $31, 0x8($29)
    /* 3D91E0 004D91E0 2D204000 */  daddu      $4, $2, $0
    /* 3D91E4 004D91E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D91E8 004D91E8 04041308 */  j          func_004c1010
    /* 3D91EC 004D91EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d91b8, 0x38
