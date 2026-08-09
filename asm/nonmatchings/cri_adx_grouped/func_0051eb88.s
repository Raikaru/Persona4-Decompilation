.section .text
.set noat
.set noreorder
glabel func_0051eb88
    /* 41EB88 0051EB88 2D18A000 */  daddu      $3, $5, $0
    /* 41EB8C 0051EB8C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41EB90 0051EB90 FDFF6228 */  slti       $2, $3, -0x3
    /* 41EB94 0051EB94 0000BFFF */  sd         $31, 0x0($29)
    /* 41EB98 0051EB98 05004014 */  bnez       $2, .L0051EBB0
    /* 41EB9C 0051EB9C FFFF6628 */   slti      $6, $3, -0x1
    /* 41EBA0 0051EBA0 0700C014 */  bnez       $6, .L0051EBC0
    /* 41EBA4 0051EBA4 0000BFDF */   ld        $31, 0x0($29)
    /* 41EBA8 0051EBA8 05006010 */  beqz       $3, .L0051EBC0
    /* 41EBAC 0051EBAC 00000000 */   nop
  .L0051EBB0:
    /* 41EBB0 0051EBB0 0000BFDF */  ld         $31, 0x0($29)
    /* 41EBB4 0051EBB4 B45E1408 */  j          func_00517ad0
    /* 41EBB8 0051EBB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 41EBBC 0051EBBC 00000000 */  nop
  .L0051EBC0:
    /* 41EBC0 0051EBC0 0800E003 */  jr         $31
    /* 41EBC4 0051EBC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051eb88, 0x40
