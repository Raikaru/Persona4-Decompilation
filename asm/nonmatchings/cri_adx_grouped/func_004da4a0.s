.section .text
.set noat
.set noreorder
glabel func_004da4a0
    /* 3DA4A0 004DA4A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DA4A4 004DA4A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3DA4A8 004DA4A8 2669130C */  jal        func_004da498
    /* 3DA4AC 004DA4AC 00000000 */   nop
    /* 3DA4B0 004DA4B0 40180200 */  sll        $3, $2, 1
    /* 3DA4B4 004DA4B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3DA4B8 004DA4B8 21186200 */  addu       $3, $3, $2
    /* 3DA4BC 004DA4BC 80100300 */  sll        $2, $3, 2
    /* 3DA4C0 004DA4C0 0800E003 */  jr         $31
    /* 3DA4C4 004DA4C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004da4a0, 0x28
