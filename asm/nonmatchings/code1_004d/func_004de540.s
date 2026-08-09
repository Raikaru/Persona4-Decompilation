.section .text
.set noat
.set noreorder
glabel func_004de540
    /* 3DE540 004DE540 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DE544 004DE544 1000B0FF */  sd         $16, 0x10($29)
    /* 3DE548 004DE548 2D808000 */  daddu      $16, $4, $0
    /* 3DE54C 004DE54C 1800B1FF */  sd         $17, 0x18($29)
    /* 3DE550 004DE550 2D88C000 */  daddu      $17, $6, $0
    /* 3DE554 004DE554 2000B2FF */  sd         $18, 0x20($29)
    /* 3DE558 004DE558 2D90A000 */  daddu      $18, $5, $0
    /* 3DE55C 004DE55C 2D20A003 */  daddu      $4, $29, $0
    /* 3DE560 004DE560 0C000624 */  addiu      $6, $0, 0xC
    /* 3DE564 004DE564 2800BFFF */  sd         $31, 0x28($29)
    /* 3DE568 004DE568 72FE100C */  jal        func_0043f9c8
    /* 3DE56C 004DE56C 2D280000 */   daddu     $5, $0, $0
    /* 3DE570 004DE570 02000324 */  addiu      $3, $0, 0x2
    /* 3DE574 004DE574 01000224 */  addiu      $2, $0, 0x1
    /* 3DE578 004DE578 0000B0AF */  sw         $16, 0x0($29)
    /* 3DE57C 004DE57C 0400A3AF */  sw         $3, 0x4($29)
    /* 3DE580 004DE580 E080130C */  jal        func_004e0380
    /* 3DE584 004DE584 0800A2AF */   sw        $2, 0x8($29)
    /* 3DE588 004DE588 2D20A003 */  daddu      $4, $29, $0
    /* 3DE58C 004DE58C 2D284002 */  daddu      $5, $18, $0
    /* 3DE590 004DE590 7079130C */  jal        func_004de5c0
    /* 3DE594 004DE594 2D302002 */   daddu     $6, $17, $0
    /* 3DE598 004DE598 E680130C */  jal        func_004e0398
    /* 3DE59C 004DE59C 2D804000 */   daddu     $16, $2, $0
    /* 3DE5A0 004DE5A0 1800B1DF */  ld         $17, 0x18($29)
    /* 3DE5A4 004DE5A4 2D100002 */  daddu      $2, $16, $0
    /* 3DE5A8 004DE5A8 2000B2DF */  ld         $18, 0x20($29)
    /* 3DE5AC 004DE5AC 1000B0DF */  ld         $16, 0x10($29)
    /* 3DE5B0 004DE5B0 2800BFDF */  ld         $31, 0x28($29)
    /* 3DE5B4 004DE5B4 0800E003 */  jr         $31
    /* 3DE5B8 004DE5B8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DE5BC 004DE5BC 00000000 */  nop
.size func_004de540, 0x80
