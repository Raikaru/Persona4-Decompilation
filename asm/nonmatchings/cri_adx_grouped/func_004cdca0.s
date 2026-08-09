.section .text
.set noat
.set noreorder
glabel func_004cdca0
    /* 3CDCA0 004CDCA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CDCA4 004CDCA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDCA8 004CDCA8 2D808000 */  daddu      $16, $4, $0
    /* 3CDCAC 004CDCAC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CDCB0 004CDCB0 2D88A000 */  daddu      $17, $5, $0
    /* 3CDCB4 004CDCB4 1000BFFF */  sd         $31, 0x10($29)
    /* 3CDCB8 004CDCB8 080011AE */  sw         $17, 0x8($16)
    /* 3CDCBC 004CDCBC 1407130C */  jal        func_004c1c50
    /* 3CDCC0 004CDCC0 0400048E */   lw        $4, 0x4($16)
    /* 3CDCC4 004CDCC4 0400048E */  lw         $4, 0x4($16)
    /* 3CDCC8 004CDCC8 2D282002 */  daddu      $5, $17, $0
    /* 3CDCCC 004CDCCC 0800B1DF */  ld         $17, 0x8($29)
    /* 3CDCD0 004CDCD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDCD4 004CDCD4 1000BFDF */  ld         $31, 0x10($29)
    /* 3CDCD8 004CDCD8 9A061308 */  j          func_004c1a68
    /* 3CDCDC 004CDCDC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cdca0, 0x40
