.section .text
.set noat
.set noreorder
glabel func_004c7788
    /* 3C7788 004C7788 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C778C 004C778C 7100083C */  lui        $8, %hi(D_007167C8)
    /* 3C7790 004C7790 0000BFFF */  sd         $31, 0x0($29)
    /* 3C7794 004C7794 C0FF0224 */  addiu      $2, $0, -0x40
    /* 3C7798 004C7798 C8670825 */  addiu      $8, $8, %lo(D_007167C8)
    /* 3C779C 004C779C 00080924 */  addiu      $9, $0, 0x800
    /* 3C77A0 004C77A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3C77A4 004C77A4 24400201 */  and        $8, $8, $2
    /* 3C77A8 004C77A8 9A1E1308 */  j          func_004c7a68
    /* 3C77AC 004C77AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7788, 0x28
