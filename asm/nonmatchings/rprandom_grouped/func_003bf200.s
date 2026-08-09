.section .text
.set noat
.set noreorder
glabel func_003bf200
    /* 2BF200 003BF200 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BF204 003BF204 1000BFFF */  sd         $31, 0x10($29)
    /* 2BF208 003BF208 0000B07F */  sq         $16, 0x0($29)
    /* 2BF20C 003BF20C B4B6828F */  lw         $2, -0x494C($28)
    /* 2BF210 003BF210 2D808000 */  daddu      $16, $4, $0
    /* 2BF214 003BF214 21100202 */  addu       $2, $16, $2
    /* 2BF218 003BF218 0000448C */  lw         $4, 0x0($2)
    /* 2BF21C 003BF21C 20020F0C */  jal        func_003c0880
    /* 2BF220 003BF220 2D280002 */   daddu     $5, $16, $0
    /* 2BF224 003BF224 300F0F0C */  jal        func_003c3cc0
    /* 2BF228 003BF228 2D200002 */   daddu     $4, $16, $0
    /* 2BF22C 003BF22C 2D100002 */  daddu      $2, $16, $0
    /* 2BF230 003BF230 1000BFDF */  ld         $31, 0x10($29)
    /* 2BF234 003BF234 0000B07B */  lq         $16, 0x0($29)
    /* 2BF238 003BF238 0800E003 */  jr         $31
    /* 2BF23C 003BF23C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003bf200, 0x40
