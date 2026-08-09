.section .text
.set noat
.set noreorder
glabel func_004ad240
    /* 3AD240 004AD240 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AD244 004AD244 1000BFFF */  sd         $31, 0x10($29)
    /* 3AD248 004AD248 0000B07F */  sq         $16, 0x0($29)
    /* 3AD24C 004AD24C 2D808000 */  daddu      $16, $4, $0
    /* 3AD250 004AD250 38008494 */  lhu        $4, 0x38($4)
    /* 3AD254 004AD254 3405120C */  jal        func_004814d0
    /* 3AD258 004AD258 00000000 */   nop
    /* 3AD25C 004AD25C 2D204000 */  daddu      $4, $2, $0
    /* 3AD260 004AD260 2D280002 */  daddu      $5, $16, $0
    /* 3AD264 004AD264 0CB4120C */  jal        func_004ad030
    /* 3AD268 004AD268 00000000 */   nop
    /* 3AD26C 004AD26C 1000BFDF */  ld         $31, 0x10($29)
    /* 3AD270 004AD270 0000B07B */  lq         $16, 0x0($29)
    /* 3AD274 004AD274 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AD278 004AD278 0800E003 */  jr         $31
    /* 3AD27C 004AD27C 00000000 */   nop
.size func_004ad240, 0x40
