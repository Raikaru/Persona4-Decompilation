.section .text
.set noat
.set noreorder
glabel func_004be3d8
    /* 3BE3D8 004BE3D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE3DC 004BE3DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE3E0 004BE3E0 0400848C */  lw         $4, 0x4($4)
    /* 3BE3E4 004BE3E4 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE3E8 004BE3E8 1A7C1308 */  j          func_004df068
    /* 3BE3EC 004BE3EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be3d8, 0x18
