.section .text
.set noat
.set noreorder
glabel func_003b82d0
    /* 2B82D0 003B82D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2B82D4 003B82D4 3B00063C */  lui        $6, %hi(func_003b7860)
    /* 2B82D8 003B82D8 3B00073C */  lui        $7, %hi(func_003b7970)
    /* 2B82DC 003B82DC 0000BFFF */  sd         $31, 0x0($29)
    /* 2B82E0 003B82E0 2D200000 */  daddu      $4, $0, $0
    /* 2B82E4 003B82E4 16010524 */  addiu      $5, $0, 0x116
    /* 2B82E8 003B82E8 6078C624 */  addiu      $6, $6, %lo(func_003b7860)
    /* 2B82EC 003B82EC 4CA20F0C */  jal        func_003e8930
    /* 2B82F0 003B82F0 7079E724 */   addiu     $7, $7, %lo(func_003b7970)
    /* 2B82F4 003B82F4 8800033C */  lui        $3, %hi(D_00886490)
    /* 2B82F8 003B82F8 3B00063C */  lui        $6, %hi(func_003b7a90)
    /* 2B82FC 003B82FC 3B00073C */  lui        $7, %hi(func_003b7ad0)
    /* 2B8300 003B8300 3B00083C */  lui        $8, %hi(func_003b7b00)
    /* 2B8304 003B8304 04000424 */  addiu      $4, $0, 0x4
    /* 2B8308 003B8308 906462AC */  sw         $2, %lo(D_00886490)($3)
    /* 2B830C 003B830C 16010524 */  addiu      $5, $0, 0x116
    /* 2B8310 003B8310 907AC624 */  addiu      $6, $6, %lo(func_003b7a90)
    /* 2B8314 003B8314 D07AE724 */  addiu      $7, $7, %lo(func_003b7ad0)
    /* 2B8318 003B8318 AC060F0C */  jal        func_003c1ab0
    /* 2B831C 003B831C 007B0825 */   addiu     $8, $8, %lo(func_003b7b00)
    /* 2B8320 003B8320 8800033C */  lui        $3, %hi(D_00886494)
    /* 2B8324 003B8324 3C00053C */  lui        $5, %hi(func_003b8050)
    /* 2B8328 003B8328 3C00063C */  lui        $6, %hi(func_003b82b0)
    /* 2B832C 003B832C 3C00073C */  lui        $7, %hi(func_003b82c0)
    /* 2B8330 003B8330 16010424 */  addiu      $4, $0, 0x116
    /* 2B8334 003B8334 946462AC */  sw         $2, %lo(D_00886494)($3)
    /* 2B8338 003B8338 5080A524 */  addiu      $5, $5, %lo(func_003b8050)
    /* 2B833C 003B833C B082C624 */  addiu      $6, $6, %lo(func_003b82b0)
    /* 2B8340 003B8340 C4060F0C */  jal        func_003c1b10
    /* 2B8344 003B8344 C082E724 */   addiu     $7, $7, %lo(func_003b82c0)
    /* 2B8348 003B8348 3B00053C */  lui        $5, %hi(func_003b7b20)
    /* 2B834C 003B834C 16010424 */  addiu      $4, $0, 0x116
    /* 2B8350 003B8350 D0060F0C */  jal        func_003c1b40
    /* 2B8354 003B8354 207BA524 */   addiu     $5, $5, %lo(func_003b7b20)
    /* 2B8358 003B8358 3B00053C */  lui        $5, %hi(func_003b7bb0)
    /* 2B835C 003B835C 16010424 */  addiu      $4, $0, 0x116
    /* 2B8360 003B8360 D8060F0C */  jal        func_003c1b60
    /* 2B8364 003B8364 B07BA524 */   addiu     $5, $5, %lo(func_003b7bb0)
    /* 2B8368 003B8368 3B00063C */  lui        $6, %hi(func_003b79f0)
    /* 2B836C 003B836C 3B00073C */  lui        $7, %hi(func_003b7a10)
    /* 2B8370 003B8370 3B00083C */  lui        $8, %hi(func_003b7a80)
    /* 2B8374 003B8374 04000424 */  addiu      $4, $0, 0x4
    /* 2B8378 003B8378 16010524 */  addiu      $5, $0, 0x116
    /* 2B837C 003B837C F079C624 */  addiu      $6, $6, %lo(func_003b79f0)
    /* 2B8380 003B8380 107AE724 */  addiu      $7, $7, %lo(func_003b7a10)
    /* 2B8384 003B8384 DC0A0F0C */  jal        func_003c2b70
    /* 2B8388 003B8388 807A0825 */   addiu     $8, $8, %lo(func_003b7a80)
    /* 2B838C 003B838C 8800033C */  lui        $3, %hi(D_00886498)
    /* 2B8390 003B8390 3B00053C */  lui        $5, %hi(func_003b7e00)
    /* 2B8394 003B8394 3B00063C */  lui        $6, %hi(func_003b7ca0)
    /* 2B8398 003B8398 3B00073C */  lui        $7, %hi(func_003b7c10)
    /* 2B839C 003B839C 16010424 */  addiu      $4, $0, 0x116
    /* 2B83A0 003B83A0 986462AC */  sw         $2, %lo(D_00886498)($3)
    /* 2B83A4 003B83A4 007EA524 */  addiu      $5, $5, %lo(func_003b7e00)
    /* 2B83A8 003B83A8 A07CC624 */  addiu      $6, $6, %lo(func_003b7ca0)
    /* 2B83AC 003B83AC E80A0F0C */  jal        func_003c2ba0
    /* 2B83B0 003B83B0 107CE724 */   addiu     $7, $7, %lo(func_003b7c10)
    /* 2B83B4 003B83B4 0000BFDF */  ld         $31, 0x0($29)
    /* 2B83B8 003B83B8 01000224 */  addiu      $2, $0, 0x1
    /* 2B83BC 003B83BC 0800E003 */  jr         $31
    /* 2B83C0 003B83C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 2B83C4 003B83C4 00000000 */  nop
    /* 2B83C8 003B83C8 00000000 */  nop
    /* 2B83CC 003B83CC 00000000 */  nop
.size func_003b82d0, 0x100
