.section .text
.set noat
.set noreorder
glabel func_0050cdb0
    /* 40CDB0 0050CDB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CDB4 0050CDB4 0000BFFF */  sd         $31, 0x0($29)
    /* 40CDB8 0050CDB8 0000BFDF */  ld         $31, 0x0($29)
    /* 40CDBC 0050CDBC 74321408 */  j          func_0050c9d0
    /* 40CDC0 0050CDC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CDC4 0050CDC4 00000000 */  nop
.size func_0050cdb0, 0x18
