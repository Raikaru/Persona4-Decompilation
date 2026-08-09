.section .text
.set noat
.set noreorder
glabel func_004c7a68
    /* 3C7A68 004C7A68 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C7A6C 004C7A6C 2D18C000 */  daddu      $3, $6, $0
    /* 3C7A70 004C7A70 2D10A000 */  daddu      $2, $5, $0
    /* 3C7A74 004C7A74 2D280000 */  daddu      $5, $0, $0
    /* 3C7A78 004C7A78 0F000A3C */  lui        $10, (0xFFFFF >> 16)
    /* 3C7A7C 004C7A7C 2D58E000 */  daddu      $11, $7, $0
    /* 3C7A80 004C7A80 0000A8AF */  sw         $8, 0x0($29)
    /* 3C7A84 004C7A84 2D406000 */  daddu      $8, $3, $0
    /* 3C7A88 004C7A88 2D384000 */  daddu      $7, $2, $0
    /* 3C7A8C 004C7A8C 01000224 */  addiu      $2, $0, 0x1
    /* 3C7A90 004C7A90 0800A9AF */  sw         $9, 0x8($29)
    /* 3C7A94 004C7A94 2D480000 */  daddu      $9, $0, $0
    /* 3C7A98 004C7A98 2D300000 */  daddu      $6, $0, $0
    /* 3C7A9C 004C7A9C FFFF4A35 */  ori        $10, $10, (0xFFFFF & 0xFFFF)
    /* 3C7AA0 004C7AA0 2000BFFF */  sd         $31, 0x20($29)
    /* 3C7AA4 004C7AA4 E01E130C */  jal        func_004c7b80
    /* 3C7AA8 004C7AA8 1000A2AF */   sw        $2, 0x10($29)
    /* 3C7AAC 004C7AAC 2000BFDF */  ld         $31, 0x20($29)
    /* 3C7AB0 004C7AB0 0800E003 */  jr         $31
    /* 3C7AB4 004C7AB4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004c7a68, 0x50
