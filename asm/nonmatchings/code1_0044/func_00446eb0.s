.section .text
.set noat
.set noreorder
glabel func_00446eb0
    /* 346EB0 00446EB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 346EB4 00446EB4 2D78A000 */  daddu      $15, $5, $0
    /* 346EB8 00446EB8 0000BFFF */  sd         $31, 0x0($29)
    /* 346EBC 00446EBC 2D38C000 */  daddu      $7, $6, $0
    /* 346EC0 00446EC0 2D30E001 */  daddu      $6, $15, $0
    /* 346EC4 00446EC4 0800858C */  lw         $5, 0x8($4)
    /* 346EC8 00446EC8 0000BFDF */  ld         $31, 0x0($29)
    /* 346ECC 00446ECC 1C121108 */  j          func_00444870
    /* 346ED0 00446ED0 1000BD27 */   addiu     $29, $29, 0x10
    /* 346ED4 00446ED4 00000000 */  nop
.size func_00446eb0, 0x28
