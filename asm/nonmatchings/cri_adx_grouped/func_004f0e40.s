.section .text
.set noat
.set noreorder
glabel func_004f0e40
    /* 3F0E40 004F0E40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0E44 004F0E44 9200023C */  lui        $2, %hi(D_00925E20)
    /* 3F0E48 004F0E48 205E4224 */  addiu      $2, $2, %lo(D_00925E20)
    /* 3F0E4C 004F0E4C C0200400 */  sll        $4, $4, 3
    /* 3F0E50 004F0E50 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0E54 004F0E54 21184400 */  addu       $3, $2, $4
    /* 3F0E58 004F0E58 21208200 */  addu       $4, $4, $2
    /* 3F0E5C 004F0E5C 0000828C */  lw         $2, 0x0($4)
    /* 3F0E60 004F0E60 04004050 */  beql       $2, $0, .L004F0E74
    /* 3F0E64 004F0E64 0000BFDF */   ld        $31, 0x0($29)
    /* 3F0E68 004F0E68 09F84000 */  jalr       $2
    /* 3F0E6C 004F0E6C 0400648C */   lw        $4, 0x4($3)
    /* 3F0E70 004F0E70 0000BFDF */  ld         $31, 0x0($29)
  .L004F0E74:
    /* 3F0E74 004F0E74 0800E003 */  jr         $31
    /* 3F0E78 004F0E78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F0E7C 004F0E7C 00000000 */  nop
.size func_004f0e40, 0x40
