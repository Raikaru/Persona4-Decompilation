.section .text
.set noat
.set noreorder
glabel func_004c9d70
    /* 3C9D70 004C9D70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9D74 004C9D74 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9D78 004C9D78 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9D7C 004C9D7C 2A15130C */  jal        func_004c54a8
    /* 3C9D80 004C9D80 00000000 */   nop
    /* 3C9D84 004C9D84 7200023C */  lui        $2, %hi(D_00718888)
    /* 3C9D88 004C9D88 88885024 */  addiu      $16, $2, %lo(D_00718888)
    /* 3C9D8C 004C9D8C 0000038E */  lw         $3, 0x0($16)
    /* 3C9D90 004C9D90 05006010 */  beqz       $3, .L004C9DA8
    /* 3C9D94 004C9D94 0800BFDF */   ld        $31, 0x8($29)
    /* 3C9D98 004C9D98 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9D9C 004C9D9C 30151308 */  j          func_004c54c0
    /* 3C9DA0 004C9DA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9DA4 004C9DA4 00000000 */  nop
  .L004C9DA8:
    /* 3C9DA8 004C9DA8 01000224 */  addiu      $2, $0, 0x1
    /* 3C9DAC 004C9DAC 3015130C */  jal        func_004c54c0
    /* 3C9DB0 004C9DB0 000002AE */   sw        $2, 0x0($16)
    /* 3C9DB4 004C9DB4 02000224 */  addiu      $2, $0, 0x2
    /* 3C9DB8 004C9DB8 6490130C */  jal        func_004e4190
    /* 3C9DBC 004C9DBC 000002AE */   sw        $2, 0x0($16)
    /* 3C9DC0 004C9DC0 03000224 */  addiu      $2, $0, 0x3
    /* 3C9DC4 004C9DC4 B24A130C */  jal        func_004d2ac8
    /* 3C9DC8 004C9DC8 000002AE */   sw        $2, 0x0($16)
    /* 3C9DCC 004C9DCC 04000224 */  addiu      $2, $0, 0x4
    /* 3C9DD0 004C9DD0 884A130C */  jal        func_004d2a20
    /* 3C9DD4 004C9DD4 000002AE */   sw        $2, 0x0($16)
    /* 3C9DD8 004C9DD8 05000224 */  addiu      $2, $0, 0x5
    /* 3C9DDC 004C9DDC E624130C */  jal        func_004c9398
    /* 3C9DE0 004C9DE0 000002AE */   sw        $2, 0x0($16)
    /* 3C9DE4 004C9DE4 06000224 */  addiu      $2, $0, 0x6
    /* 3C9DE8 004C9DE8 884A130C */  jal        func_004d2a20
    /* 3C9DEC 004C9DEC 000002AE */   sw        $2, 0x0($16)
    /* 3C9DF0 004C9DF0 07000224 */  addiu      $2, $0, 0x7
    /* 3C9DF4 004C9DF4 B24A130C */  jal        func_004d2ac8
    /* 3C9DF8 004C9DF8 000002AE */   sw        $2, 0x0($16)
    /* 3C9DFC 004C9DFC 08000224 */  addiu      $2, $0, 0x8
    /* 3C9E00 004C9E00 6490130C */  jal        func_004e4190
    /* 3C9E04 004C9E04 000002AE */   sw        $2, 0x0($16)
    /* 3C9E08 004C9E08 000000AE */  sw         $0, 0x0($16)
    /* 3C9E0C 004C9E0C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9E10 004C9E10 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9E14 004C9E14 0800E003 */  jr         $31
    /* 3C9E18 004C9E18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9E1C 004C9E1C 00000000 */  nop
.size func_004c9d70, 0xb0
