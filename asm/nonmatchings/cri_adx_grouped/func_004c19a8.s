.section .text
.set noat
.set noreorder
glabel func_004c19a8
    /* 3C19A8 004C19A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C19AC 004C19AC 02000224 */  addiu      $2, $0, 0x2
    /* 3C19B0 004C19B0 0000BFFF */  sd         $31, 0x0($29)
    /* 3C19B4 004C19B4 01008380 */  lb         $3, 0x1($4)
    /* 3C19B8 004C19B8 03006214 */  bne        $3, $2, .L004C19C8
    /* 3C19BC 004C19BC 0000BFDF */   ld        $31, 0x0($29)
    /* 3C19C0 004C19C0 C6051308 */  j          func_004c1718
    /* 3C19C4 004C19C4 1000BD27 */   addiu     $29, $29, 0x10
  .L004C19C8:
    /* 3C19C8 004C19C8 0800E003 */  jr         $31
    /* 3C19CC 004C19CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c19a8, 0x28
