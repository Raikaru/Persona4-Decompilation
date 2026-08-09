.section .text
.set noat
.set noreorder
glabel func_004efc70
    /* 3EFC70 004EFC70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFC74 004EFC74 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFC78 004EFC78 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFC7C 004EFC7C 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFC80 004EFC80 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFC84 004EFC84 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFC88 004EFC88 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFC8C 004EFC8C 000044AC */  sw         $4, 0x0($2)
    /* 3EFC90 004EFC90 040045AC */  sw         $5, 0x4($2)
    /* 3EFC94 004EFC94 2D284000 */  daddu      $5, $2, $0
    /* 3EFC98 004EFC98 080046AC */  sw         $6, 0x8($2)
    /* 3EFC9C 004EFC9C 03000624 */  addiu      $6, $0, 0x3
    /* 3EFCA0 004EFCA0 2D380002 */  daddu      $7, $16, $0
    /* 3EFCA4 004EFCA4 22000424 */  addiu      $4, $0, 0x22
    /* 3EFCA8 004EFCA8 2896130C */  jal        func_004e58a0
    /* 3EFCAC 004EFCAC 01000824 */   addiu     $8, $0, 0x1
    /* 3EFCB0 004EFCB0 0000028E */  lw         $2, 0x0($16)
    /* 3EFCB4 004EFCB4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFCB8 004EFCB8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFCBC 004EFCBC 0800E003 */  jr         $31
    /* 3EFCC0 004EFCC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFCC4 004EFCC4 00000000 */  nop
.size func_004efc70, 0x58
