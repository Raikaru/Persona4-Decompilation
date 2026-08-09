.section .text
.set noat
.set noreorder
glabel func_004deb38
    /* 3DEB38 004DEB38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DEB3C 004DEB3C 0F00083C */  lui        $8, (0xFFFFF >> 16)
    /* 3DEB40 004DEB40 0000BFFF */  sd         $31, 0x0($29)
    /* 3DEB44 004DEB44 2D380000 */  daddu      $7, $0, $0
    /* 3DEB48 004DEB48 FFFF0835 */  ori        $8, $8, (0xFFFFF & 0xFFFF)
    /* 3DEB4C 004DEB4C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DEB50 004DEB50 7E7A1308 */  j          func_004de9f8
    /* 3DEB54 004DEB54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004deb38, 0x20
