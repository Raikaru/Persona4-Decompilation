.section .text
.set noat
.set noreorder
glabel func_004e80e0
    /* 3E80E0 004E80E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E80E4 004E80E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3E80E8 004E80E8 16A0130C */  jal        func_004e8058
    /* 3E80EC 004E80EC 00000000 */   nop
    /* 3E80F0 004E80F0 FFFF033C */  lui        $3, (0xFFFF0000 >> 16)
    /* 3E80F4 004E80F4 3E180300 */  dsrl32     $3, $3, 0
    /* 3E80F8 004E80F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E80FC 004E80FC 24104300 */  and        $2, $2, $3
    /* 3E8100 004E8100 3C100200 */  dsll32     $2, $2, 0
    /* 3E8104 004E8104 3F100200 */  dsra32     $2, $2, 0
    /* 3E8108 004E8108 0800E003 */  jr         $31
    /* 3E810C 004E810C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e80e0, 0x30
