.section .text
.set noat
.set noreorder
glabel func_004c0d60
    /* 3C0D60 004C0D60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C0D64 004C0D64 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0D68 004C0D68 2D80A000 */  daddu      $16, $5, $0
    /* 3C0D6C 004C0D6C 0800B1FF */  sd         $17, 0x8($29)
    /* 3C0D70 004C0D70 1000BFFF */  sd         $31, 0x10($29)
    /* 3C0D74 004C0D74 9003130C */  jal        func_004c0e40
    /* 3C0D78 004C0D78 2D888000 */   daddu     $17, $4, $0
    /* 3C0D7C 004C0D7C 1B004010 */  beqz       $2, .L004C0DEC
    /* 3C0D80 004C0D80 2D200002 */   daddu     $4, $16, $0
    /* 3C0D84 004C0D84 A6FA120C */  jal        func_004bea98
    /* 3C0D88 004C0D88 00000000 */   nop
    /* 3C0D8C 004C0D8C 17004010 */  beqz       $2, .L004C0DEC
    /* 3C0D90 004C0D90 2D200002 */   daddu     $4, $16, $0
    /* 3C0D94 004C0D94 54FE120C */  jal        func_004bf950
    /* 3C0D98 004C0D98 00000000 */   nop
    /* 3C0D9C 004C0D9C F603130C */  jal        func_004c0fd8
    /* 3C0DA0 004C0DA0 4000248E */   lw        $4, 0x40($17)
    /* 3C0DA4 004C0DA4 0F004010 */  beqz       $2, .L004C0DE4
    /* 3C0DA8 004C0DA8 00000000 */   nop
    /* 3C0DAC 004C0DAC F803130C */  jal        func_004c0fe0
    /* 3C0DB0 004C0DB0 4000248E */   lw        $4, 0x40($17)
    /* 3C0DB4 004C0DB4 0B004010 */  beqz       $2, .L004C0DE4
    /* 3C0DB8 004C0DB8 2D200002 */   daddu     $4, $16, $0
    /* 3C0DBC 004C0DBC B0FB120C */  jal        func_004beec0
    /* 3C0DC0 004C0DC0 00000000 */   nop
    /* 3C0DC4 004C0DC4 01000324 */  addiu      $3, $0, 0x1
    /* 3C0DC8 004C0DC8 06004314 */  bne        $2, $3, .L004C0DE4
    /* 3C0DCC 004C0DCC 00000000 */   nop
    /* 3C0DD0 004C0DD0 FA03130C */  jal        func_004c0fe8
    /* 3C0DD4 004C0DD4 4000248E */   lw        $4, 0x40($17)
    /* 3C0DD8 004C0DD8 2D200002 */  daddu      $4, $16, $0
    /* 3C0DDC 004C0DDC 4EFE120C */  jal        func_004bf938
    /* 3C0DE0 004C0DE0 2D284000 */   daddu     $5, $2, $0
  .L004C0DE4:
    /* 3C0DE4 004C0DE4 58FE120C */  jal        func_004bf960
    /* 3C0DE8 004C0DE8 2D200002 */   daddu     $4, $16, $0
  .L004C0DEC:
    /* 3C0DEC 004C0DEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C0DF0 004C0DF0 0800B1DF */  ld         $17, 0x8($29)
    /* 3C0DF4 004C0DF4 1000BFDF */  ld         $31, 0x10($29)
    /* 3C0DF8 004C0DF8 0800E003 */  jr         $31
    /* 3C0DFC 004C0DFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c0d60, 0xa0
