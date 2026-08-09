.section .text
.set noat
.set noreorder
glabel func_001b3fb0
    /* B3FB0 001B3FB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B3FB4 001B3FB4 0000BFFF */  sd         $31, 0x0($29)
    /* B3FB8 001B3FB8 30EF0A0C */  jal        func_002bbcc0
    /* B3FBC 001B3FBC 00000000 */   nop
    /* B3FC0 001B3FC0 80ED0A0C */  jal        func_002bb600
    /* B3FC4 001B3FC4 00000000 */   nop
    /* B3FC8 001B3FC8 1D004014 */  bnez       $2, .L001B4040
    /* B3FCC 001B3FCC 00000000 */   nop
    /* B3FD0 001B3FD0 50EC0A0C */  jal        func_002bb140
    /* B3FD4 001B3FD4 00000000 */   nop
    /* B3FD8 001B3FD8 0C004014 */  bnez       $2, .L001B400C
    /* B3FDC 001B3FDC 00000000 */   nop
    /* B3FE0 001B3FE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3FE4 001B3FE4 D40D448C */  lw         $4, 0xDD4($2)
    /* B3FE8 001B3FE8 D44E080C */  jal        func_00213b50
    /* B3FEC 001B3FEC 00000000 */   nop
    /* B3FF0 001B3FF0 E0EC0A0C */  jal        func_002bb380
    /* B3FF4 001B3FF4 00000000 */   nop
    /* B3FF8 001B3FF8 38ED0A0C */  jal        func_002bb4e0
    /* B3FFC 001B3FFC 00000000 */   nop
    /* B4000 001B4000 0A000224 */  addiu      $2, $0, 0xA
    /* B4004 001B4004 0F000010 */  b          .L001B4044
    /* B4008 001B4008 00000000 */   nop
  .L001B400C:
    /* B400C 001B400C ACB3848F */  lw         $4, -0x4C54($28)
    /* B4010 001B4010 0C00838C */  lw         $3, 0xC($4)
    /* B4014 001B4014 7FFF023C */  lui        $2, (0xFF7FFFFF >> 16)
    /* B4018 001B4018 FFFF4234 */  ori        $2, $2, (0xFF7FFFFF & 0xFFFF)
    /* B401C 001B401C 24106200 */  and        $2, $3, $2
    /* B4020 001B4020 0C0082AC */  sw         $2, 0xC($4)
    /* B4024 001B4024 E0EC0A0C */  jal        func_002bb380
    /* B4028 001B4028 00000000 */   nop
    /* B402C 001B402C 38ED0A0C */  jal        func_002bb4e0
    /* B4030 001B4030 00000000 */   nop
    /* B4034 001B4034 08000224 */  addiu      $2, $0, 0x8
    /* B4038 001B4038 02000010 */  b          .L001B4044
    /* B403C 001B403C 00000000 */   nop
  .L001B4040:
    /* B4040 001B4040 2D100000 */  daddu      $2, $0, $0
  .L001B4044:
    /* B4044 001B4044 0000BFDF */  ld         $31, 0x0($29)
    /* B4048 001B4048 1000BD27 */  addiu      $29, $29, 0x10
    /* B404C 001B404C 0800E003 */  jr         $31
    /* B4050 001B4050 00000000 */   nop
    /* B4054 001B4054 00000000 */  nop
    /* B4058 001B4058 00000000 */  nop
    /* B405C 001B405C 00000000 */  nop
.size func_001b3fb0, 0xb0
