.section .text
.set noat
.set noreorder
glabel func_004d8a78
    /* 3D8A78 004D8A78 0C00828C */  lw         $2, 0xC($4)
    /* 3D8A7C 004D8A7C 08004014 */  bnez       $2, .L004D8AA0
    /* 3D8A80 004D8A80 01000324 */   addiu     $3, $0, 0x1
    /* 3D8A84 004D8A84 240088AC */  sw         $8, 0x24($4)
    /* 3D8A88 004D8A88 180085AC */  sw         $5, 0x18($4)
    /* 3D8A8C 004D8A8C 01000224 */  addiu      $2, $0, 0x1
    /* 3D8A90 004D8A90 1C0086AC */  sw         $6, 0x1C($4)
    /* 3D8A94 004D8A94 140083AC */  sw         $3, 0x14($4)
    /* 3D8A98 004D8A98 0800E003 */  jr         $31
    /* 3D8A9C 004D8A9C 200087AC */   sw        $7, 0x20($4)
  .L004D8AA0:
    /* 3D8AA0 004D8AA0 0800E003 */  jr         $31
    /* 3D8AA4 004D8AA4 2D100000 */   daddu     $2, $0, $0
.size func_004d8a78, 0x30
