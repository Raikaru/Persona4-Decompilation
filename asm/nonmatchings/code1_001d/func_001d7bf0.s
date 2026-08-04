.section .text
.set noat
.set noreorder
glabel func_001d7bf0
    /* D7BF0 001D7BF0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* D7BF4 001D7BF4 3000BFFF */  sd         $31, 0x30($29)
    /* D7BF8 001D7BF8 2000B27F */  sq         $18, 0x20($29)
    /* D7BFC 001D7BFC 1000B17F */  sq         $17, 0x10($29)
    /* D7C00 001D7C00 0000B07F */  sq         $16, 0x0($29)
    /* D7C04 001D7C04 2D908000 */  daddu      $18, $4, $0
    /* D7C08 001D7C08 2D88A000 */  daddu      $17, $5, $0
    /* D7C0C 001D7C0C 2D80C000 */  daddu      $16, $6, $0
    /* D7C10 001D7C10 09030424 */  addiu      $4, $0, 0x309
    /* D7C14 001D7C14 0C000524 */  addiu      $5, $0, 0xC
    /* D7C18 001D7C18 1C51060C */  jal        func_00194470
    /* D7C1C 001D7C1C 00000000 */   nop
    /* D7C20 001D7C20 1D00033C */  lui        $3, %hi(func_001d7bb0)
    /* D7C24 001D7C24 B07B6324 */  addiu      $3, $3, %lo(func_001d7bb0)
    /* D7C28 001D7C28 6C0043AC */  sw         $3, 0x6C($2)
    /* D7C2C 001D7C2C 7800438C */  lw         $3, 0x78($2)
    /* D7C30 001D7C30 000072AC */  sw         $18, 0x0($3)
    /* D7C34 001D7C34 040071AC */  sw         $17, 0x4($3)
    /* D7C38 001D7C38 080070AC */  sw         $16, 0x8($3)
    /* D7C3C 001D7C3C 3000BFDF */  ld         $31, 0x30($29)
    /* D7C40 001D7C40 2000B27B */  lq         $18, 0x20($29)
    /* D7C44 001D7C44 1000B17B */  lq         $17, 0x10($29)
    /* D7C48 001D7C48 0000B07B */  lq         $16, 0x0($29)
    /* D7C4C 001D7C4C 4000BD27 */  addiu      $29, $29, 0x40
    /* D7C50 001D7C50 0800E003 */  jr         $31
    /* D7C54 001D7C54 00000000 */   nop
    /* D7C58 001D7C58 00000000 */  nop
    /* D7C5C 001D7C5C 00000000 */  nop
.size func_001d7bf0, 0x70
