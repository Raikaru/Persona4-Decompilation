.section .text
.set noat
.set noreorder
glabel func_004c78c8
    /* 3C78C8 004C78C8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C78CC 004C78CC 2D18C000 */  daddu      $3, $6, $0
    /* 3C78D0 004C78D0 2D10A000 */  daddu      $2, $5, $0
    /* 3C78D4 004C78D4 2D280000 */  daddu      $5, $0, $0
    /* 3C78D8 004C78D8 0F000A3C */  lui        $10, (0xFFFFF >> 16)
    /* 3C78DC 004C78DC 2D58E000 */  daddu      $11, $7, $0
    /* 3C78E0 004C78E0 0000A8AF */  sw         $8, 0x0($29)
    /* 3C78E4 004C78E4 2D406000 */  daddu      $8, $3, $0
    /* 3C78E8 004C78E8 0800A9AF */  sw         $9, 0x8($29)
    /* 3C78EC 004C78EC 2D480000 */  daddu      $9, $0, $0
    /* 3C78F0 004C78F0 2D300000 */  daddu      $6, $0, $0
    /* 3C78F4 004C78F4 2D384000 */  daddu      $7, $2, $0
    /* 3C78F8 004C78F8 FFFF4A35 */  ori        $10, $10, (0xFFFFF & 0xFFFF)
    /* 3C78FC 004C78FC 2000BFFF */  sd         $31, 0x20($29)
    /* 3C7900 004C7900 E01E130C */  jal        func_004c7b80
    /* 3C7904 004C7904 1000A0AF */   sw        $0, 0x10($29)
    /* 3C7908 004C7908 2000BFDF */  ld         $31, 0x20($29)
    /* 3C790C 004C790C 0800E003 */  jr         $31
    /* 3C7910 004C7910 3000BD27 */   addiu     $29, $29, 0x30
    /* 3C7914 004C7914 00000000 */  nop
.size func_004c78c8, 0x50
