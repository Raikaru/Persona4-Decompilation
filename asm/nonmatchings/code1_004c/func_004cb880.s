.section .text
.set noat
.set noreorder
glabel func_004cb880
    /* 3CB880 004CB880 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CB884 004CB884 7200023C */  lui        $2, %hi(D_00719A68)
    /* 3CB888 004CB888 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB88C 004CB88C 689A4724 */  addiu      $7, $2, %lo(D_00719A68)
    /* 3CB890 004CB890 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB894 004CB894 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB898 004CB898 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB89C 004CB89C 2000B4FF */  sd         $20, 0x20($29)
    /* 3CB8A0 004CB8A0 2800B5FF */  sd         $21, 0x28($29)
    /* 3CB8A4 004CB8A4 3000B6FF */  sd         $22, 0x30($29)
    /* 3CB8A8 004CB8A8 3800BFFF */  sd         $31, 0x38($29)
    /* 3CB8AC 004CB8AC 0000E3DC */  ld         $3, 0x0($7)
    /* 3CB8B0 004CB8B0 27006014 */  bnez       $3, .L004CB950
    /* 3CB8B4 004CB8B4 7200023C */   lui       $2, %hi(D_00719A70)
    /* 3CB8B8 004CB8B8 7200023C */  lui        $2, %hi(D_00719A00)
    /* 3CB8BC 004CB8BC 7200033C */  lui        $3, %hi(D_00719A3C)
    /* 3CB8C0 004CB8C0 7200043C */  lui        $4, %hi(D_00719AB8)
    /* 3CB8C4 004CB8C4 7200053C */  lui        $5, %hi(D_00719A40)
    /* 3CB8C8 004CB8C8 7200063C */  lui        $6, %hi(D_007199D8)
    /* 3CB8CC 004CB8CC 009A5324 */  addiu      $19, $2, %lo(D_00719A00)
    /* 3CB8D0 004CB8D0 3C9A7624 */  addiu      $22, $3, %lo(D_00719A3C)
    /* 3CB8D4 004CB8D4 B89A9224 */  addiu      $18, $4, %lo(D_00719AB8)
    /* 3CB8D8 004CB8D8 409AB524 */  addiu      $21, $5, %lo(D_00719A40)
    /* 3CB8DC 004CB8DC D899D124 */  addiu      $17, $6, %lo(D_007199D8)
    /* 3CB8E0 004CB8E0 2DA0E000 */  daddu      $20, $7, $0
    /* 3CB8E4 004CB8E4 00000000 */  nop
  .L004CB8E8:
    /* 3CB8E8 004CB8E8 000062DE */  ld         $2, 0x0($19)
    /* 3CB8EC 004CB8EC 01004264 */  daddiu     $2, $2, 0x1
    /* 3CB8F0 004CB8F0 000062FE */  sd         $2, 0x0($19)
    /* 3CB8F4 004CB8F4 6A2F130C */  jal        func_004cbda8
    /* 3CB8F8 004CB8F8 0000C48E */   lw        $4, 0x0($22)
    /* 3CB8FC 004CB8FC 0000438E */  lw         $3, 0x0($18)
    /* 3CB900 004CB900 03006014 */  bnez       $3, .L004CB910
    /* 3CB904 004CB904 00000000 */   nop
    /* 3CB908 004CB908 6834130C */  jal        func_004cd1a0
    /* 3CB90C 004CB90C 00000000 */   nop
  .L004CB910:
    /* 3CB910 004CB910 000040AE */  sw         $0, 0x0($18)
    /* 3CB914 004CB914 7830130C */  jal        func_004cc1e0
    /* 3CB918 004CB918 01001024 */   addiu     $16, $0, 0x1
    /* 3CB91C 004CB91C 03005014 */  bne        $2, $16, .L004CB92C
    /* 3CB920 004CB920 00000000 */   nop
    /* 3CB924 004CB924 6A2F130C */  jal        func_004cbda8
    /* 3CB928 004CB928 0000A48E */   lw        $4, 0x0($21)
  .L004CB92C:
    /* 3CB92C 004CB92C FC32130C */  jal        func_004ccbf0
    /* 3CB930 004CB930 00000000 */   nop
    /* 3CB934 004CB934 20C4130C */  jal        func_004f1080
    /* 3CB938 004CB938 000030AE */   sw        $16, 0x0($17)
    /* 3CB93C 004CB93C 4A2F130C */  jal        func_004cbd28
    /* 3CB940 004CB940 000020AE */   sw        $0, 0x0($17)
    /* 3CB944 004CB944 000082DE */  ld         $2, 0x0($20)
    /* 3CB948 004CB948 E7FF4010 */  beqz       $2, .L004CB8E8
    /* 3CB94C 004CB94C 7200023C */   lui       $2, %hi(D_00719A70)
  .L004CB950:
    /* 3CB950 004CB950 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB954 004CB954 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB958 004CB958 01000324 */  addiu      $3, $0, 0x1
    /* 3CB95C 004CB95C 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB960 004CB960 709A4224 */  addiu      $2, $2, %lo(D_00719A70)
    /* 3CB964 004CB964 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB968 004CB968 2000B4DF */  ld         $20, 0x20($29)
    /* 3CB96C 004CB96C 2800B5DF */  ld         $21, 0x28($29)
    /* 3CB970 004CB970 3000B6DF */  ld         $22, 0x30($29)
    /* 3CB974 004CB974 3800BFDF */  ld         $31, 0x38($29)
    /* 3CB978 004CB978 000043FC */  sd         $3, 0x0($2)
    /* 3CB97C 004CB97C 88851008 */  j          func_00421620
    /* 3CB980 004CB980 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CB984 004CB984 00000000 */  nop
.size func_004cb880, 0x108
