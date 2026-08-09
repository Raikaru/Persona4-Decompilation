.section .text
.set noat
.set noreorder
glabel func_002b2a60
    /* 1B2A60 002B2A60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B2A64 002B2A64 0C00A5A3 */  sb         $5, 0xC($29)
    /* 1B2A68 002B2A68 0D00A6A3 */  sb         $6, 0xD($29)
    /* 1B2A6C 002B2A6C 0E00A7A3 */  sb         $7, 0xE($29)
    /* 1B2A70 002B2A70 0F00A8A3 */  sb         $8, 0xF($29)
    /* 1B2A74 002B2A74 0C00A793 */  lbu        $7, 0xC($29)
    /* 1B2A78 002B2A78 0D00A693 */  lbu        $6, 0xD($29)
    /* 1B2A7C 002B2A7C 0E00A593 */  lbu        $5, 0xE($29)
    /* 1B2A80 002B2A80 0F00A393 */  lbu        $3, 0xF($29)
    /* 1B2A84 002B2A84 000087A0 */  sb         $7, 0x0($4)
    /* 1B2A88 002B2A88 010086A0 */  sb         $6, 0x1($4)
    /* 1B2A8C 002B2A8C 020085A0 */  sb         $5, 0x2($4)
    /* 1B2A90 002B2A90 030083A0 */  sb         $3, 0x3($4)
    /* 1B2A94 002B2A94 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B2A98 002B2A98 0800E003 */  jr         $31
    /* 1B2A9C 002B2A9C 00000000 */   nop
.size func_002b2a60, 0x40
