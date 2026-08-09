.section .text
.set noat
.set noreorder
glabel func_004c2678
    /* 3C2678 004C2678 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C267C 004C267C 01000224 */  addiu      $2, $0, 0x1
    /* 3C2680 004C2680 0000BFFF */  sd         $31, 0x0($29)
    /* 3C2684 004C2684 9C008384 */  lh         $3, 0x9C($4)
    /* 3C2688 004C2688 03006214 */  bne        $3, $2, .L004C2698
    /* 3C268C 004C268C 0000BFDF */   ld        $31, 0x0($29)
    /* 3C2690 004C2690 3E091308 */  j          func_004c24f8
    /* 3C2694 004C2694 1000BD27 */   addiu     $29, $29, 0x10
  .L004C2698:
    /* 3C2698 004C2698 D8081308 */  j          func_004c2360
    /* 3C269C 004C269C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c2678, 0x28
