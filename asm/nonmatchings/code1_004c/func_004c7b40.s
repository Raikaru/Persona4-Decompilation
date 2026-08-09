.section .text
.set noat
.set noreorder
glabel func_004c7b40
    /* 3C7B40 004C7B40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C7B44 004C7B44 0F000A3C */  lui        $10, (0xFFFFF >> 16)
    /* 3C7B48 004C7B48 2D58E000 */  daddu      $11, $7, $0
    /* 3C7B4C 004C7B4C 2D380000 */  daddu      $7, $0, $0
    /* 3C7B50 004C7B50 0000A8AF */  sw         $8, 0x0($29)
    /* 3C7B54 004C7B54 2D400000 */  daddu      $8, $0, $0
    /* 3C7B58 004C7B58 0800A9AF */  sw         $9, 0x8($29)
    /* 3C7B5C 004C7B5C 2D480000 */  daddu      $9, $0, $0
    /* 3C7B60 004C7B60 01000224 */  addiu      $2, $0, 0x1
    /* 3C7B64 004C7B64 FFFF4A35 */  ori        $10, $10, (0xFFFFF & 0xFFFF)
    /* 3C7B68 004C7B68 2000BFFF */  sd         $31, 0x20($29)
    /* 3C7B6C 004C7B6C E01E130C */  jal        func_004c7b80
    /* 3C7B70 004C7B70 1000A2AF */   sw        $2, 0x10($29)
    /* 3C7B74 004C7B74 2000BFDF */  ld         $31, 0x20($29)
    /* 3C7B78 004C7B78 0800E003 */  jr         $31
    /* 3C7B7C 004C7B7C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004c7b40, 0x40
