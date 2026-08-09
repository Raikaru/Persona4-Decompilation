.section .text
.set noat
.set noreorder
glabel func_004efd98
    /* 3EFD98 004EFD98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EFD9C 004EFD9C 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFDA0 004EFDA0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFDA4 004EFDA4 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFDA8 004EFDA8 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFDAC 004EFDAC 0800B1FF */  sd         $17, 0x8($29)
    /* 3EFDB0 004EFDB0 1000BFFF */  sd         $31, 0x10($29)
    /* 3EFDB4 004EFDB4 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFDB8 004EFDB8 000044AC */  sw         $4, 0x0($2)
    /* 3EFDBC 004EFDBC 26000424 */  addiu      $4, $0, 0x26
    /* 3EFDC0 004EFDC0 040045AC */  sw         $5, 0x4($2)
    /* 3EFDC4 004EFDC4 2D284000 */  daddu      $5, $2, $0
    /* 3EFDC8 004EFDC8 080046AC */  sw         $6, 0x8($2)
    /* 3EFDCC 004EFDCC 03000624 */  addiu      $6, $0, 0x3
    /* 3EFDD0 004EFDD0 2D88E000 */  daddu      $17, $7, $0
    /* 3EFDD4 004EFDD4 2D380002 */  daddu      $7, $16, $0
    /* 3EFDD8 004EFDD8 2896130C */  jal        func_004e58a0
    /* 3EFDDC 004EFDDC 02000824 */   addiu     $8, $0, 0x2
    /* 3EFDE0 004EFDE0 0000038E */  lw         $3, 0x0($16)
    /* 3EFDE4 004EFDE4 0400028E */  lw         $2, 0x4($16)
    /* 3EFDE8 004EFDE8 000023AE */  sw         $3, 0x0($17)
    /* 3EFDEC 004EFDEC 040022AE */  sw         $2, 0x4($17)
    /* 3EFDF0 004EFDF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFDF4 004EFDF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3EFDF8 004EFDF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3EFDFC 004EFDFC 0800E003 */  jr         $31
    /* 3EFE00 004EFE00 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EFE04 004EFE04 00000000 */  nop
.size func_004efd98, 0x70
