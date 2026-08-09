.section .text
.set noat
.set noreorder
glabel func_004c79a0
    /* 3C79A0 004C79A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C79A4 004C79A4 0F000A3C */  lui        $10, (0xFFFFF >> 16)
    /* 3C79A8 004C79A8 2D58E000 */  daddu      $11, $7, $0
    /* 3C79AC 004C79AC 2D380000 */  daddu      $7, $0, $0
    /* 3C79B0 004C79B0 0000A8AF */  sw         $8, 0x0($29)
    /* 3C79B4 004C79B4 2D400000 */  daddu      $8, $0, $0
    /* 3C79B8 004C79B8 0800A9AF */  sw         $9, 0x8($29)
    /* 3C79BC 004C79BC 2D480000 */  daddu      $9, $0, $0
    /* 3C79C0 004C79C0 FFFF4A35 */  ori        $10, $10, (0xFFFFF & 0xFFFF)
    /* 3C79C4 004C79C4 2000BFFF */  sd         $31, 0x20($29)
    /* 3C79C8 004C79C8 E01E130C */  jal        func_004c7b80
    /* 3C79CC 004C79CC 1000A0AF */   sw        $0, 0x10($29)
    /* 3C79D0 004C79D0 2000BFDF */  ld         $31, 0x20($29)
    /* 3C79D4 004C79D4 0800E003 */  jr         $31
    /* 3C79D8 004C79D8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3C79DC 004C79DC 00000000 */  nop
.size func_004c79a0, 0x40
