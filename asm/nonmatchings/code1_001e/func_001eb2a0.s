.section .text
.set noat
.set noreorder
glabel func_001eb2a0
    /* EB2A0 001EB2A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB2A4 001EB2A4 0000BFFF */  sd         $31, 0x0($29)
    /* EB2A8 001EB2A8 2D200000 */  daddu      $4, $0, $0
    /* EB2AC 001EB2AC 00730A0C */  jal        func_0029cc00
    /* EB2B0 001EB2B0 00000000 */   nop
    /* EB2B4 001EB2B4 2D204000 */  daddu      $4, $2, $0
    /* EB2B8 001EB2B8 5CC7080C */  jal        func_00231d70
    /* EB2BC 001EB2BC 00000000 */   nop
    /* EB2C0 001EB2C0 2D204000 */  daddu      $4, $2, $0
    /* EB2C4 001EB2C4 D4730A0C */  jal        func_0029cf50
    /* EB2C8 001EB2C8 00000000 */   nop
    /* EB2CC 001EB2CC 01000224 */  addiu      $2, $0, 0x1
    /* EB2D0 001EB2D0 0000BFDF */  ld         $31, 0x0($29)
    /* EB2D4 001EB2D4 1000BD27 */  addiu      $29, $29, 0x10
    /* EB2D8 001EB2D8 0800E003 */  jr         $31
    /* EB2DC 001EB2DC 00000000 */   nop
.size func_001eb2a0, 0x40
