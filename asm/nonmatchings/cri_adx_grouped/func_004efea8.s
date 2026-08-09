.section .text
.set noat
.set noreorder
glabel func_004efea8
    /* 3EFEA8 004EFEA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFEAC 004EFEAC 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFEB0 004EFEB0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFEB4 004EFEB4 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFEB8 004EFEB8 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFEBC 004EFEBC 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFEC0 004EFEC0 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFEC4 004EFEC4 000044AC */  sw         $4, 0x0($2)
    /* 3EFEC8 004EFEC8 040045AC */  sw         $5, 0x4($2)
    /* 3EFECC 004EFECC 2D284000 */  daddu      $5, $2, $0
    /* 3EFED0 004EFED0 2D380002 */  daddu      $7, $16, $0
    /* 3EFED4 004EFED4 29000424 */  addiu      $4, $0, 0x29
    /* 3EFED8 004EFED8 02000624 */  addiu      $6, $0, 0x2
    /* 3EFEDC 004EFEDC 2896130C */  jal        func_004e58a0
    /* 3EFEE0 004EFEE0 01000824 */   addiu     $8, $0, 0x1
    /* 3EFEE4 004EFEE4 0000028E */  lw         $2, 0x0($16)
    /* 3EFEE8 004EFEE8 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFEEC 004EFEEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFEF0 004EFEF0 0800E003 */  jr         $31
    /* 3EFEF4 004EFEF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004efea8, 0x50
