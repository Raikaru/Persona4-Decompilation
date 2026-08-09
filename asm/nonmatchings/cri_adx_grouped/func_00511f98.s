.section .text
.set noat
.set noreorder
glabel func_00511f98
    /* 411F98 00511F98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411F9C 00511F9C 2D100000 */  daddu      $2, $0, $0
    /* 411FA0 00511FA0 04008010 */  beqz       $4, .L00511FB4
    /* 411FA4 00511FA4 0000BFFF */   sd        $31, 0x0($29)
    /* 411FA8 00511FA8 264B130C */  jal        func_004d2c98
    /* 411FAC 00511FAC 00000000 */   nop
    /* 411FB0 00511FB0 2D100000 */  daddu      $2, $0, $0
  .L00511FB4:
    /* 411FB4 00511FB4 0000BFDF */  ld         $31, 0x0($29)
    /* 411FB8 00511FB8 0800E003 */  jr         $31
    /* 411FBC 00511FBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511f98, 0x28
