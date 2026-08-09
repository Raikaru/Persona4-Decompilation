.section .text
.set noat
.set noreorder
glabel func_004f6d60
    /* 3F6D60 004F6D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F6D64 004F6D64 2D108000 */  daddu      $2, $4, $0
    /* 3F6D68 004F6D68 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6D6C 004F6D6C 04004424 */  addiu      $4, $2, 0x4
    /* 3F6D70 004F6D70 2D40A000 */  daddu      $8, $5, $0
    /* 3F6D74 004F6D74 0000478C */  lw         $7, 0x0($2)
    /* 3F6D78 004F6D78 04000525 */  addiu      $5, $8, 0x4
    /* 3F6D7C 004F6D7C 00004390 */  lbu        $3, 0x0($2)
    /* 3F6D80 004F6D80 03120700 */  sra        $2, $7, 8
    /* 3F6D84 004F6D84 023E0700 */  srl        $7, $7, 24
    /* 3F6D88 004F6D88 2D304000 */  daddu      $6, $2, $0
    /* 3F6D8C 004F6D8C FF004230 */  andi       $2, $2, 0xFF
    /* 3F6D90 004F6D90 00140200 */  sll        $2, $2, 16
    /* 3F6D94 004F6D94 001E0300 */  sll        $3, $3, 24
    /* 3F6D98 004F6D98 00FFC630 */  andi       $6, $6, 0xFF00
    /* 3F6D9C 004F6D9C 25186700 */  or         $3, $3, $7
    /* 3F6DA0 004F6DA0 2530C200 */  or         $6, $6, $2
    /* 3F6DA4 004F6DA4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F6DA8 004F6DA8 25186600 */  or         $3, $3, $6
    /* 3F6DAC 004F6DAC 000003AD */  sw         $3, 0x0($8)
    /* 3F6DB0 004F6DB0 76DA1308 */  j          func_004f69d8
    /* 3F6DB4 004F6DB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f6d60, 0x58
