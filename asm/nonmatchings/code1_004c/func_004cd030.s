.section .text
.set noat
.set noreorder
glabel func_004cd030
    /* 3CD030 004CD030 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD034 004CD034 7200033C */  lui        $3, %hi(D_00719994)
    /* 3CD038 004CD038 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD03C 004CD03C 94996324 */  addiu      $3, $3, %lo(D_00719994)
    /* 3CD040 004CD040 0000628C */  lw         $2, 0x0($3)
    /* 3CD044 004CD044 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3CD048 004CD048 21004014 */  bnez       $2, .L004CD0D0
    /* 3CD04C 004CD04C 000062AC */   sw        $2, 0x0($3)
    /* 3CD050 004CD050 EA30130C */  jal        func_004cc3a8
    /* 3CD054 004CD054 00000000 */   nop
    /* 3CD058 004CD058 2431130C */  jal        func_004cc490
    /* 3CD05C 004CD05C 00000000 */   nop
    /* 3CD060 004CD060 5831130C */  jal        func_004cc560
    /* 3CD064 004CD064 00000000 */   nop
    /* 3CD068 004CD068 C031130C */  jal        func_004cc700
    /* 3CD06C 004CD06C 00000000 */   nop
    /* 3CD070 004CD070 8C31130C */  jal        func_004cc630
    /* 3CD074 004CD074 00000000 */   nop
    /* 3CD078 004CD078 0C32130C */  jal        func_004cc830
    /* 3CD07C 004CD07C 00000000 */   nop
    /* 3CD080 004CD080 4032130C */  jal        func_004cc900
    /* 3CD084 004CD084 00000000 */   nop
    /* 3CD088 004CD088 7200023C */  lui        $2, %hi(D_00719A38)
    /* 3CD08C 004CD08C 7200033C */  lui        $3, %hi(D_007212C8)
    /* 3CD090 004CD090 389A4224 */  addiu      $2, $2, %lo(D_00719A38)
    /* 3CD094 004CD094 C812658C */  lw         $5, %lo(D_007212C8)($3)
    /* 3CD098 004CD098 9C85100C */  jal        func_00421670
    /* 3CD09C 004CD09C 0000448C */   lw        $4, 0x0($2)
    /* 3CD0A0 004CD0A0 2D200000 */  daddu      $4, $0, $0
    /* 3CD0A4 004CD0A4 B0C3130C */  jal        func_004f0ec0
    /* 3CD0A8 004CD0A8 2D280000 */   daddu     $5, $0, $0
    /* 3CD0AC 004CD0AC 2D200000 */  daddu      $4, $0, $0
    /* 3CD0B0 004CD0B0 B6C3130C */  jal        func_004f0ed8
    /* 3CD0B4 004CD0B4 2D280000 */   daddu     $5, $0, $0
    /* 3CD0B8 004CD0B8 7200023C */  lui        $2, %hi(D_00719998)
    /* 3CD0BC 004CD0BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD0C0 004CD0C0 989940AC */  sw         $0, %lo(D_00719998)($2)
    /* 3CD0C4 004CD0C4 88C41308 */  j          func_004f1220
    /* 3CD0C8 004CD0C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD0CC 004CD0CC 00000000 */  nop
  .L004CD0D0:
    /* 3CD0D0 004CD0D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD0D4 004CD0D4 0800E003 */  jr         $31
    /* 3CD0D8 004CD0D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD0DC 004CD0DC 00000000 */  nop
.size func_004cd030, 0xb0
