.section .text
.set noat
.set noreorder
glabel func_0041e278
    /* 31E278 0041E278 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 31E27C 0041E27C 01000524 */  addiu      $5, $0, 0x1
    /* 31E280 0041E280 0000B0FF */  sd         $16, 0x0($29)
    /* 31E284 0041E284 1000BFFF */  sd         $31, 0x10($29)
    /* 31E288 0041E288 2E6F100C */  jal        func_0041bcb8
    /* 31E28C 0041E28C 2D808000 */   daddu     $16, $4, $0
    /* 31E290 0041E290 2D200002 */  daddu      $4, $16, $0
    /* 31E294 0041E294 2E6F100C */  jal        func_0041bcb8
    /* 31E298 0041E298 08000524 */   addiu     $5, $0, 0x8
    /* 31E29C 0041E29C 2D200002 */  daddu      $4, $16, $0
    /* 31E2A0 0041E2A0 2E6F100C */  jal        func_0041bcb8
    /* 31E2A4 0041E2A4 01000524 */   addiu     $5, $0, 0x1
    /* 31E2A8 0041E2A8 2D200002 */  daddu      $4, $16, $0
    /* 31E2AC 0041E2AC 2E6F100C */  jal        func_0041bcb8
    /* 31E2B0 0041E2B0 07000524 */   addiu     $5, $0, 0x7
    /* 31E2B4 0041E2B4 2D200002 */  daddu      $4, $16, $0
    /* 31E2B8 0041E2B8 2E6F100C */  jal        func_0041bcb8
    /* 31E2BC 0041E2BC 01000524 */   addiu     $5, $0, 0x1
    /* 31E2C0 0041E2C0 2D200002 */  daddu      $4, $16, $0
    /* 31E2C4 0041E2C4 2E6F100C */  jal        func_0041bcb8
    /* 31E2C8 0041E2C8 14000524 */   addiu     $5, $0, 0x14
    /* 31E2CC 0041E2CC 2D200002 */  daddu      $4, $16, $0
    /* 31E2D0 0041E2D0 2E6F100C */  jal        func_0041bcb8
    /* 31E2D4 0041E2D4 01000524 */   addiu     $5, $0, 0x1
    /* 31E2D8 0041E2D8 2D200002 */  daddu      $4, $16, $0
    /* 31E2DC 0041E2DC 2E6F100C */  jal        func_0041bcb8
    /* 31E2E0 0041E2E0 16000524 */   addiu     $5, $0, 0x16
    /* 31E2E4 0041E2E4 2D200002 */  daddu      $4, $16, $0
    /* 31E2E8 0041E2E8 2E6F100C */  jal        func_0041bcb8
    /* 31E2EC 0041E2EC 01000524 */   addiu     $5, $0, 0x1
    /* 31E2F0 0041E2F0 2D200002 */  daddu      $4, $16, $0
    /* 31E2F4 0041E2F4 2E6F100C */  jal        func_0041bcb8
    /* 31E2F8 0041E2F8 16000524 */   addiu     $5, $0, 0x16
    /* 31E2FC 0041E2FC 1000BFDF */  ld         $31, 0x10($29)
    /* 31E300 0041E300 0000B0DF */  ld         $16, 0x0($29)
    /* 31E304 0041E304 0800E003 */  jr         $31
    /* 31E308 0041E308 2000BD27 */   addiu     $29, $29, 0x20
    /* 31E30C 0041E30C 00000000 */  nop
.size func_0041e278, 0x98
