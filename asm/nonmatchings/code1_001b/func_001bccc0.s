.section .text
.set noat
.set noreorder
glabel func_001bccc0
    /* BCCC0 001BCCC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* BCCC4 001BCCC4 4000BFFF */  sd         $31, 0x40($29)
    /* BCCC8 001BCCC8 3000B37F */  sq         $19, 0x30($29)
    /* BCCCC 001BCCCC 2000B27F */  sq         $18, 0x20($29)
    /* BCCD0 001BCCD0 1000B17F */  sq         $17, 0x10($29)
    /* BCCD4 001BCCD4 0000B07F */  sq         $16, 0x0($29)
    /* BCCD8 001BCCD8 2D988000 */  daddu      $19, $4, $0
    /* BCCDC 001BCCDC 2D90A000 */  daddu      $18, $5, $0
    /* BCCE0 001BCCE0 2D88C000 */  daddu      $17, $6, $0
    /* BCCE4 001BCCE4 2D80E000 */  daddu      $16, $7, $0
    /* BCCE8 001BCCE8 02020424 */  addiu      $4, $0, 0x202
    /* BCCEC 001BCCEC 10000524 */  addiu      $5, $0, 0x10
    /* BCCF0 001BCCF0 1C51060C */  jal        func_00194470
    /* BCCF4 001BCCF4 00000000 */   nop
    /* BCCF8 001BCCF8 1C00033C */  lui        $3, %hi(func_001bcc80)
    /* BCCFC 001BCCFC 80CC6324 */  addiu      $3, $3, %lo(func_001bcc80)
    /* BCD00 001BCD00 6C0043AC */  sw         $3, 0x6C($2)
    /* BCD04 001BCD04 7800438C */  lw         $3, 0x78($2)
    /* BCD08 001BCD08 000073AC */  sw         $19, 0x0($3)
    /* BCD0C 001BCD0C 040072A4 */  sh         $18, 0x4($3)
    /* BCD10 001BCD10 080071AC */  sw         $17, 0x8($3)
    /* BCD14 001BCD14 0C0070AC */  sw         $16, 0xC($3)
    /* BCD18 001BCD18 4000BFDF */  ld         $31, 0x40($29)
    /* BCD1C 001BCD1C 3000B37B */  lq         $19, 0x30($29)
    /* BCD20 001BCD20 2000B27B */  lq         $18, 0x20($29)
    /* BCD24 001BCD24 1000B17B */  lq         $17, 0x10($29)
    /* BCD28 001BCD28 0000B07B */  lq         $16, 0x0($29)
    /* BCD2C 001BCD2C 5000BD27 */  addiu      $29, $29, 0x50
    /* BCD30 001BCD30 0800E003 */  jr         $31
    /* BCD34 001BCD34 00000000 */   nop
    /* BCD38 001BCD38 00000000 */  nop
    /* BCD3C 001BCD3C 00000000 */  nop
.size func_001bccc0, 0x80
