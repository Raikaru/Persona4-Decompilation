.section .text
.set noat
.set noreorder
glabel func_0039b380
    /* 29B380 0039B380 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 29B384 0039B384 3A00063C */  lui        $6, %hi(func_0039ac20)
    /* 29B388 0039B388 3A00073C */  lui        $7, %hi(func_0039ac40)
    /* 29B38C 0039B38C 0000BFFF */  sd         $31, 0x0($29)
    /* 29B390 0039B390 2D200000 */  daddu      $4, $0, $0
    /* 29B394 0039B394 05010524 */  addiu      $5, $0, 0x105
    /* 29B398 0039B398 20ACC624 */  addiu      $6, $6, %lo(func_0039ac20)
    /* 29B39C 0039B39C 4CA20F0C */  jal        func_003e8930
    /* 29B3A0 0039B3A0 40ACE724 */   addiu     $7, $7, %lo(func_0039ac40)
    /* 29B3A4 0039B3A4 03004104 */  bgez       $2, .L0039B3B4
    /* 29B3A8 0039B3A8 00000000 */   nop
    /* 29B3AC 0039B3AC 24000010 */  b          .L0039B440
    /* 29B3B0 0039B3B0 2D100000 */   daddu     $2, $0, $0
  .L0039B3B4:
    /* 29B3B4 0039B3B4 3A00063C */  lui        $6, %hi(func_0039ac60)
    /* 29B3B8 0039B3B8 3A00083C */  lui        $8, %hi(func_0039ac80)
    /* 29B3BC 0039B3BC 60ACC624 */  addiu      $6, $6, %lo(func_0039ac60)
    /* 29B3C0 0039B3C0 0C000424 */  addiu      $4, $0, 0xC
    /* 29B3C4 0039B3C4 05010524 */  addiu      $5, $0, 0x105
    /* 29B3C8 0039B3C8 80AC0825 */  addiu      $8, $8, %lo(func_0039ac80)
    /* 29B3CC 0039B3CC AC060F0C */  jal        func_003c1ab0
    /* 29B3D0 0039B3D0 2D38C000 */   daddu     $7, $6, $0
    /* 29B3D4 0039B3D4 03004104 */  bgez       $2, .L0039B3E4
    /* 29B3D8 0039B3D8 ECB582AF */   sw        $2, -0x4A14($28)
    /* 29B3DC 0039B3DC 18000010 */  b          .L0039B440
    /* 29B3E0 0039B3E0 2D100000 */   daddu     $2, $0, $0
  .L0039B3E4:
    /* 29B3E4 0039B3E4 3A00063C */  lui        $6, %hi(func_0039b290)
    /* 29B3E8 0039B3E8 3A00073C */  lui        $7, %hi(func_0039ae30)
    /* 29B3EC 0039B3EC 3A00083C */  lui        $8, %hi(func_0039ae90)
    /* 29B3F0 0039B3F0 0C000424 */  addiu      $4, $0, 0xC
    /* 29B3F4 0039B3F4 05010524 */  addiu      $5, $0, 0x105
    /* 29B3F8 0039B3F8 90B2C624 */  addiu      $6, $6, %lo(func_0039b290)
    /* 29B3FC 0039B3FC 30AEE724 */  addiu      $7, $7, %lo(func_0039ae30)
    /* 29B400 0039B400 DC0A0F0C */  jal        func_003c2b70
    /* 29B404 0039B404 90AE0825 */   addiu     $8, $8, %lo(func_0039ae90)
    /* 29B408 0039B408 03004104 */  bgez       $2, .L0039B418
    /* 29B40C 0039B40C F0B582AF */   sw        $2, -0x4A10($28)
    /* 29B410 0039B410 0B000010 */  b          .L0039B440
    /* 29B414 0039B414 2D100000 */   daddu     $2, $0, $0
  .L0039B418:
    /* 29B418 0039B418 3A00053C */  lui        $5, %hi(func_0039b080)
    /* 29B41C 0039B41C 3A00063C */  lui        $6, %hi(func_0039af40)
    /* 29B420 0039B420 3A00073C */  lui        $7, %hi(func_0039b210)
    /* 29B424 0039B424 05010424 */  addiu      $4, $0, 0x105
    /* 29B428 0039B428 80B0A524 */  addiu      $5, $5, %lo(func_0039b080)
    /* 29B42C 0039B42C 40AFC624 */  addiu      $6, $6, %lo(func_0039af40)
    /* 29B430 0039B430 E80A0F0C */  jal        func_003c2ba0
    /* 29B434 0039B434 10B2E724 */   addiu     $7, $7, %lo(func_0039b210)
    /* 29B438 0039B438 2A104000 */  slt        $2, $2, $0
    /* 29B43C 0039B43C 01004238 */  xori       $2, $2, 0x1
  .L0039B440:
    /* 29B440 0039B440 0000BFDF */  ld         $31, 0x0($29)
    /* 29B444 0039B444 0800E003 */  jr         $31
    /* 29B448 0039B448 1000BD27 */   addiu     $29, $29, 0x10
    /* 29B44C 0039B44C 00000000 */  nop
.size func_0039b380, 0xd0
