.section .text
.set noat
.set noreorder
glabel func_004aec50
    /* 3AEC50 004AEC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AEC54 004AEC54 0000BFFF */  sd         $31, 0x0($29)
    /* 3AEC58 004AEC58 5800848C */  lw         $4, 0x58($4)
    /* 3AEC5C 004AEC5C 03008010 */  beqz       $4, .L004AEC6C
    /* 3AEC60 004AEC60 00000000 */   nop
    /* 3AEC64 004AEC64 404B120C */  jal        func_00492d00
    /* 3AEC68 004AEC68 00000000 */   nop
  .L004AEC6C:
    /* 3AEC6C 004AEC6C 0000BFDF */  ld         $31, 0x0($29)
    /* 3AEC70 004AEC70 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AEC74 004AEC74 0800E003 */  jr         $31
    /* 3AEC78 004AEC78 00000000 */   nop
    /* 3AEC7C 004AEC7C 00000000 */  nop
.size func_004aec50, 0x30
