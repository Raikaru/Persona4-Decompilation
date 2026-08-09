.section .text
.set noat
.set noreorder
glabel func_004d8a18
    /* 3D8A18 004D8A18 0C00828C */  lw         $2, 0xC($4)
    /* 3D8A1C 004D8A1C 08004014 */  bnez       $2, .L004D8A40
    /* 3D8A20 004D8A20 01000324 */   addiu     $3, $0, 0x1
    /* 3D8A24 004D8A24 240088AC */  sw         $8, 0x24($4)
    /* 3D8A28 004D8A28 180085AC */  sw         $5, 0x18($4)
    /* 3D8A2C 004D8A2C 01000224 */  addiu      $2, $0, 0x1
    /* 3D8A30 004D8A30 1C0086AC */  sw         $6, 0x1C($4)
    /* 3D8A34 004D8A34 140083AC */  sw         $3, 0x14($4)
    /* 3D8A38 004D8A38 0800E003 */  jr         $31
    /* 3D8A3C 004D8A3C 200087AC */   sw        $7, 0x20($4)
  .L004D8A40:
    /* 3D8A40 004D8A40 0800E003 */  jr         $31
    /* 3D8A44 004D8A44 2D100000 */   daddu     $2, $0, $0
.size func_004d8a18, 0x30
