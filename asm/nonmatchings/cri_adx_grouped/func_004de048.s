.section .text
.set noat
.set noreorder
glabel func_004de048
    /* 3DE048 004DE048 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE04C 004DE04C 02000224 */  addiu      $2, $0, 0x2
    /* 3DE050 004DE050 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE054 004DE054 05008380 */  lb         $3, 0x5($4)
    /* 3DE058 004DE058 05006214 */  bne        $3, $2, .L004DE070
    /* 3DE05C 004DE05C 01000224 */   addiu     $2, $0, 0x1
    /* 3DE060 004DE060 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE064 004DE064 68771308 */  j          func_004ddda0
    /* 3DE068 004DE068 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DE06C 004DE06C 00000000 */  nop
  .L004DE070:
    /* 3DE070 004DE070 03006214 */  bne        $3, $2, .L004DE080
    /* 3DE074 004DE074 0000BFDF */   ld        $31, 0x0($29)
    /* 3DE078 004DE078 50771308 */  j          func_004ddd40
    /* 3DE07C 004DE07C 1000BD27 */   addiu     $29, $29, 0x10
  .L004DE080:
    /* 3DE080 004DE080 0800E003 */  jr         $31
    /* 3DE084 004DE084 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de048, 0x40
