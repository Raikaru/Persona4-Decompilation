.section .text
.set noat
.set noreorder
glabel func_0050d3d8
    /* 40D3D8 0050D3D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D3DC 0050D3DC 0000BFFF */  sd         $31, 0x0($29)
    /* 40D3E0 0050D3E0 4000848C */  lw         $4, 0x40($4)
    /* 40D3E4 0050D3E4 0000BFDF */  ld         $31, 0x0($29)
    /* 40D3E8 0050D3E8 E6471408 */  j          func_00511f98
    /* 40D3EC 0050D3EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050d3d8, 0x18
