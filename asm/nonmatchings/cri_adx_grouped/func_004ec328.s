.section .text
.set noat
.set noreorder
glabel func_004ec328
    /* 3EC328 004EC328 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC32C 004EC32C E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EC330 004EC330 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC334 004EC334 01000424 */  addiu      $4, $0, 0x1
    /* 3EC338 004EC338 0000B0FF */  sd         $16, 0x0($29)
    /* 3EC33C 004EC33C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EC340 004EC340 05006414 */  bne        $3, $4, .L004EC358
    /* 3EC344 004EC344 1000BFFF */   sd        $31, 0x10($29)
    /* 3EC348 004EC348 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC34C 004EC34C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC350 004EC350 20006018 */  blez       $3, .L004EC3D4
    /* 3EC354 004EC354 0000B0DF */   ld        $16, 0x0($29)
  .L004EC358:
    /* 3EC358 004EC358 7400033C */  lui        $3, %hi(D_0073A78C)
    /* 3EC35C 004EC35C 8CA76324 */  addiu      $3, $3, %lo(D_0073A78C)
    /* 3EC360 004EC360 0000628C */  lw         $2, 0x0($3)
    /* 3EC364 004EC364 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EC368 004EC368 19004014 */  bnez       $2, .L004EC3D0
    /* 3EC36C 004EC36C 000062AC */   sw        $2, 0x0($3)
    /* 3EC370 004EC370 7400103C */  lui        $16, %hi(D_0073A75C)
    /* 3EC374 004EC374 7400113C */  lui        $17, %hi(D_0073D1E0)
    /* 3EC378 004EC378 5CA71026 */  addiu      $16, $16, %lo(D_0073A75C)
    /* 3EC37C 004EC37C E0D13126 */  addiu      $17, $17, %lo(D_0073D1E0)
    /* 3EC380 004EC380 82A7100C */  jal        func_00429e08
    /* 3EC384 004EC384 0000048E */   lw        $4, 0x0($16)
    /* 3EC388 004EC388 000000AE */  sw         $0, 0x0($16)
    /* 3EC38C 004EC38C 7400103C */  lui        $16, %hi(D_0073A794)
    /* 3EC390 004EC390 0000248E */  lw         $4, 0x0($17)
    /* 3EC394 004EC394 5095130C */  jal        func_004e5540
    /* 3EC398 004EC398 94A71026 */   addiu     $16, $16, %lo(D_0073A794)
    /* 3EC39C 004EC39C 000020AE */  sw         $0, 0x0($17)
    /* 3EC3A0 004EC3A0 82A7100C */  jal        func_00429e08
    /* 3EC3A4 004EC3A4 0000048E */   lw        $4, 0x0($16)
    /* 3EC3A8 004EC3A8 B4AD130C */  jal        func_004eb6d0
    /* 3EC3AC 004EC3AC 000000AE */   sw        $0, 0x0($16)
    /* 3EC3B0 004EC3B0 02B0130C */  jal        func_004ec008
    /* 3EC3B4 004EC3B4 00000000 */   nop
    /* 3EC3B8 004EC3B8 0A96130C */  jal        func_004e5828
    /* 3EC3BC 004EC3BC 00000000 */   nop
    /* 3EC3C0 004EC3C0 D4C0130C */  jal        func_004f0350
    /* 3EC3C4 004EC3C4 00000000 */   nop
    /* 3EC3C8 004EC3C8 ECBF130C */  jal        func_004effb0
    /* 3EC3CC 004EC3CC 00000000 */   nop
  .L004EC3D0:
    /* 3EC3D0 004EC3D0 0000B0DF */  ld         $16, 0x0($29)
  .L004EC3D4:
    /* 3EC3D4 004EC3D4 0800B1DF */  ld         $17, 0x8($29)
    /* 3EC3D8 004EC3D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3EC3DC 004EC3DC 0800E003 */  jr         $31
    /* 3EC3E0 004EC3E0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EC3E4 004EC3E4 00000000 */  nop
.size func_004ec328, 0xc0
