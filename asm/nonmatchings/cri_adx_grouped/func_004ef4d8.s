.section .text
.set noat
.set noreorder
glabel func_004ef4d8
    /* 3EF4D8 004EF4D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF4DC 004EF4DC 2D408000 */  daddu      $8, $4, $0
    /* 3EF4E0 004EF4E0 09000015 */  bnez       $8, .L004EF508
    /* 3EF4E4 004EF4E4 0000BFFF */   sd        $31, 0x0($29)
    /* 3EF4E8 004EF4E8 7600043C */  lui        $4, %hi(D_0075D008)
    /* 3EF4EC 004EF4EC 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF4F0 004EF4F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF4F4 004EF4F4 08D08424 */  addiu      $4, $4, %lo(D_0075D008)
    /* 3EF4F8 004EF4F8 F8CEA524 */  addiu      $5, $5, %lo(D_0075CEF8)
    /* 3EF4FC 004EF4FC B6BA1308 */  j          func_004eead8
    /* 3EF500 004EF500 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EF504 004EF504 00000000 */  nop
  .L004EF508:
    /* 3EF508 004EF508 04000281 */  lb         $2, 0x4($8)
    /* 3EF50C 004EF50C 08004014 */  bnez       $2, .L004EF530
    /* 3EF510 004EF510 0400A22C */   sltiu     $2, $5, 0x4
    /* 3EF514 004EF514 7600043C */  lui        $4, %hi(D_0075D018)
    /* 3EF518 004EF518 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF51C 004EF51C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF520 004EF520 18D08424 */  addiu      $4, $4, %lo(D_0075D018)
    /* 3EF524 004EF524 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
    /* 3EF528 004EF528 B6BA1308 */  j          func_004eead8
    /* 3EF52C 004EF52C 1000BD27 */   addiu     $29, $29, 0x10
  .L004EF530:
    /* 3EF530 004EF530 1B004050 */  beql       $2, $0, .L004EF5A0
    /* 3EF534 004EF534 2800028D */   lw        $2, 0x28($8)
    /* 3EF538 004EF538 0400CA8C */  lw         $10, 0x4($6)
    /* 3EF53C 004EF53C 2C004019 */  blez       $10, .L004EF5F0
    /* 3EF540 004EF540 0000BFDF */   ld        $31, 0x0($29)
    /* 3EF544 004EF544 0000C98C */  lw         $9, 0x0($6)
    /* 3EF548 004EF548 29002011 */  beqz       $9, .L004EF5F0
    /* 3EF54C 004EF54C 80280500 */   sll       $5, $5, 2
    /* 3EF550 004EF550 08000B25 */  addiu      $11, $8, 0x8
    /* 3EF554 004EF554 05000281 */  lb         $2, 0x5($8)
    /* 3EF558 004EF558 2118AB00 */  addu       $3, $5, $11
    /* 3EF55C 004EF55C 01000424 */  addiu      $4, $0, 0x1
    /* 3EF560 004EF560 0B004414 */  bne        $2, $4, .L004EF590
    /* 3EF564 004EF564 1000678C */   lw        $7, 0x10($3)
    /* 3EF568 004EF568 0900E010 */  beqz       $7, .L004EF590
    /* 3EF56C 004EF56C 21102A01 */   addu      $2, $9, $10
    /* 3EF570 004EF570 0800E38C */  lw         $3, 0x8($7)
    /* 3EF574 004EF574 07004354 */  bnel       $2, $3, .L004EF594
    /* 3EF578 004EF578 1400078D */   lw        $7, 0x14($8)
    /* 3EF57C 004EF57C 0C00E28C */  lw         $2, 0xC($7)
    /* 3EF580 004EF580 0800E9AC */  sw         $9, 0x8($7)
    /* 3EF584 004EF584 21104A00 */  addu       $2, $2, $10
    /* 3EF588 004EF588 19000010 */  b          .L004EF5F0
    /* 3EF58C 004EF58C 0C00E2AC */   sw        $2, 0xC($7)
  .L004EF590:
    /* 3EF590 004EF590 1400078D */  lw         $7, 0x14($8)
  .L004EF594:
    /* 3EF594 004EF594 0A00E054 */  bnel       $7, $0, .L004EF5C0
    /* 3EF598 004EF598 0000E28C */   lw        $2, 0x0($7)
    /* 3EF59C 004EF59C 2800028D */  lw         $2, 0x28($8)
  .L004EF5A0:
    /* 3EF5A0 004EF5A0 13004010 */  beqz       $2, .L004EF5F0
    /* 3EF5A4 004EF5A4 0000BFDF */   ld        $31, 0x0($29)
    /* 3EF5A8 004EF5A8 2C00048D */  lw         $4, 0x2C($8)
    /* 3EF5AC 004EF5AC 09F84000 */  jalr       $2
    /* 3EF5B0 004EF5B0 FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EF5B4 004EF5B4 0E000010 */  b          .L004EF5F0
    /* 3EF5B8 004EF5B8 0000BFDF */   ld        $31, 0x0($29)
    /* 3EF5BC 004EF5BC 00000000 */  nop
  .L004EF5C0:
    /* 3EF5C0 004EF5C0 1000A324 */  addiu      $3, $5, 0x10
    /* 3EF5C4 004EF5C4 21186301 */  addu       $3, $11, $3
    /* 3EF5C8 004EF5C8 0700C468 */  ldl        $4, 0x7($6)
    /* 3EF5CC 004EF5CC 0000C46C */  ldr        $4, 0x0($6)
    /* 3EF5D0 004EF5D0 0F00E4B0 */  sdl        $4, 0xF($7)
    /* 3EF5D4 004EF5D4 0800E4B4 */  sdr        $4, 0x8($7)
    /* 3EF5D8 004EF5D8 140002AD */  sw         $2, 0x14($8)
    /* 3EF5DC 004EF5DC 0000E0AC */  sw         $0, 0x0($7)
    /* 3EF5E0 004EF5E0 0000628C */  lw         $2, 0x0($3)
    /* 3EF5E4 004EF5E4 0000E2AC */  sw         $2, 0x0($7)
    /* 3EF5E8 004EF5E8 000067AC */  sw         $7, 0x0($3)
    /* 3EF5EC 004EF5EC 0000BFDF */  ld         $31, 0x0($29)
  .L004EF5F0:
    /* 3EF5F0 004EF5F0 0800E003 */  jr         $31
    /* 3EF5F4 004EF5F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ef4d8, 0x120
