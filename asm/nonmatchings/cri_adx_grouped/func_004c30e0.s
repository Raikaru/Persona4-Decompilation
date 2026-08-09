.section .text
.set noat
.set noreorder
glabel func_004c30e0
    /* 3C30E0 004C30E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C30E4 004C30E4 02000224 */  addiu      $2, $0, 0x2
    /* 3C30E8 004C30E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3C30EC 004C30EC 9C008384 */  lh         $3, 0x9C($4)
    /* 3C30F0 004C30F0 05006214 */  bne        $3, $2, .L004C3108
    /* 3C30F4 004C30F4 01000224 */   addiu     $2, $0, 0x1
    /* 3C30F8 004C30F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C30FC 004C30FC CE0B1308 */  j          func_004c2f38
    /* 3C3100 004C3100 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C3104 004C3104 00000000 */  nop
  .L004C3108:
    /* 3C3108 004C3108 03006214 */  bne        $3, $2, .L004C3118
    /* 3C310C 004C310C 0000BFDF */   ld        $31, 0x0($29)
    /* 3C3110 004C3110 6E0B1308 */  j          func_004c2db8
    /* 3C3114 004C3114 1000BD27 */   addiu     $29, $29, 0x10
  .L004C3118:
    /* 3C3118 004C3118 080B1308 */  j          func_004c2c20
    /* 3C311C 004C311C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c30e0, 0x40
