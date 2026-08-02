.section .text
.set noat
.set noreorder
glabel func_002ac400
    /* 1AC400 002AC400 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1AC404 002AC404 2000BFFF */  sd         $31, 0x20($29)
    /* 1AC408 002AC408 1000B07F */  sq         $16, 0x10($29)
    /* 1AC40C 002AC40C 3800908C */  lw         $16, 0x38($4)
    /* 1AC410 002AC410 04000382 */  lb         $3, 0x4($16)
    /* 1AC414 002AC414 04000224 */  addiu      $2, $0, 0x4
    /* 1AC418 002AC418 63006210 */  beq        $3, $2, .L002AC5A8
    /* 1AC41C 002AC41C 00000000 */   nop
    /* 1AC420 002AC420 03000224 */  addiu      $2, $0, 0x3
    /* 1AC424 002AC424 48006210 */  beq        $3, $2, .L002AC548
    /* 1AC428 002AC428 00000000 */   nop
    /* 1AC42C 002AC42C 02000224 */  addiu      $2, $0, 0x2
    /* 1AC430 002AC430 34006210 */  beq        $3, $2, .L002AC504
    /* 1AC434 002AC434 00000000 */   nop
    /* 1AC438 002AC438 01000224 */  addiu      $2, $0, 0x1
    /* 1AC43C 002AC43C 22006210 */  beq        $3, $2, .L002AC4C8
    /* 1AC440 002AC440 00000000 */   nop
    /* 1AC444 002AC444 03006010 */  beqz       $3, .L002AC454
    /* 1AC448 002AC448 00000000 */   nop
    /* 1AC44C 002AC44C 66000010 */  b          .L002AC5E8
    /* 1AC450 002AC450 00000000 */   nop
  .L002AC454:
    /* 1AC454 002AC454 6400043C */  lui        $4, %hi(D_0063EF70)
    /* 1AC458 002AC458 70EF8424 */  addiu      $4, $4, %lo(D_0063EF70)
    /* 1AC45C 002AC45C A8AB110C */  jal        func_0046aea0
    /* 1AC460 002AC460 00000000 */   nop
    /* 1AC464 002AC464 50B582AF */  sw         $2, -0x4AB0($28)
    /* 1AC468 002AC468 06004014 */  bnez       $2, .L002AC484
    /* 1AC46C 002AC46C 00000000 */   nop
    /* 1AC470 002AC470 6400043C */  lui        $4, %hi(D_0063EF60)
    /* 1AC474 002AC474 60EF8424 */  addiu      $4, $4, %lo(D_0063EF60)
    /* 1AC478 002AC478 93000524 */  addiu      $5, $0, 0x93
    /* 1AC47C 002AC47C CCB5110C */  jal        func_0046d730
    /* 1AC480 002AC480 00000000 */   nop
  .L002AC484:
    /* 1AC484 002AC484 6400043C */  lui        $4, %hi(D_0063EF90)
    /* 1AC488 002AC488 90EF8424 */  addiu      $4, $4, %lo(D_0063EF90)
    /* 1AC48C 002AC48C A8AB110C */  jal        func_0046aea0
    /* 1AC490 002AC490 00000000 */   nop
    /* 1AC494 002AC494 54B582AF */  sw         $2, -0x4AAC($28)
    /* 1AC498 002AC498 06004014 */  bnez       $2, .L002AC4B4
    /* 1AC49C 002AC49C 00000000 */   nop
    /* 1AC4A0 002AC4A0 6400043C */  lui        $4, %hi(D_0063EF60)
    /* 1AC4A4 002AC4A4 60EF8424 */  addiu      $4, $4, %lo(D_0063EF60)
    /* 1AC4A8 002AC4A8 95000524 */  addiu      $5, $0, 0x95
    /* 1AC4AC 002AC4AC CCB5110C */  jal        func_0046d730
    /* 1AC4B0 002AC4B0 00000000 */   nop
  .L002AC4B4:
    /* 1AC4B4 002AC4B4 04000282 */  lb         $2, 0x4($16)
    /* 1AC4B8 002AC4B8 01004224 */  addiu      $2, $2, 0x1
    /* 1AC4BC 002AC4BC 040002A2 */  sb         $2, 0x4($16)
    /* 1AC4C0 002AC4C0 49000010 */  b          .L002AC5E8
    /* 1AC4C4 002AC4C4 00000000 */   nop
  .L002AC4C8:
    /* 1AC4C8 002AC4C8 50B5848F */  lw         $4, -0x4AB0($28)
    /* 1AC4CC 002AC4CC D4A9110C */  jal        func_0046a750
    /* 1AC4D0 002AC4D0 00000000 */   nop
    /* 1AC4D4 002AC4D4 44004010 */  beqz       $2, .L002AC5E8
    /* 1AC4D8 002AC4D8 00000000 */   nop
    /* 1AC4DC 002AC4DC 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AC4E0 002AC4E0 D4A9110C */  jal        func_0046a750
    /* 1AC4E4 002AC4E4 00000000 */   nop
    /* 1AC4E8 002AC4E8 3F004010 */  beqz       $2, .L002AC5E8
    /* 1AC4EC 002AC4EC 00000000 */   nop
    /* 1AC4F0 002AC4F0 04000282 */  lb         $2, 0x4($16)
    /* 1AC4F4 002AC4F4 01004224 */  addiu      $2, $2, 0x1
    /* 1AC4F8 002AC4F8 040002A2 */  sb         $2, 0x4($16)
    /* 1AC4FC 002AC4FC 3A000010 */  b          .L002AC5E8
    /* 1AC500 002AC500 00000000 */   nop
  .L002AC504:
    /* 1AC504 002AC504 38A88427 */  addiu      $4, $28, -0x57C8
    /* 1AC508 002AC508 6400053C */  lui        $5, %hi(D_0063EF60)
    /* 1AC50C 002AC50C 60EFA524 */  addiu      $5, $5, %lo(D_0063EF60)
    /* 1AC510 002AC510 A0000624 */  addiu      $6, $0, 0xA0
    /* 1AC514 002AC514 DA02110C */  jal        func_00440b68
    /* 1AC518 002AC518 00000000 */   nop
    /* 1AC51C 002AC51C 6400043C */  lui        $4, %hi(D_0063EFB0)
    /* 1AC520 002AC520 B0EF8424 */  addiu      $4, $4, %lo(D_0063EFB0)
    /* 1AC524 002AC524 2D280000 */  daddu      $5, $0, $0
    /* 1AC528 002AC528 9852110C */  jal        func_00454a60
    /* 1AC52C 002AC52C 00000000 */   nop
    /* 1AC530 002AC530 000002AE */  sw         $2, 0x0($16)
    /* 1AC534 002AC534 04000282 */  lb         $2, 0x4($16)
    /* 1AC538 002AC538 01004224 */  addiu      $2, $2, 0x1
    /* 1AC53C 002AC53C 040002A2 */  sb         $2, 0x4($16)
    /* 1AC540 002AC540 29000010 */  b          .L002AC5E8
    /* 1AC544 002AC544 00000000 */   nop
  .L002AC548:
    /* 1AC548 002AC548 0000048E */  lw         $4, 0x0($16)
    /* 1AC54C 002AC54C F054110C */  jal        func_004553c0
    /* 1AC550 002AC550 00000000 */   nop
    /* 1AC554 002AC554 24004010 */  beqz       $2, .L002AC5E8
    /* 1AC558 002AC558 00000000 */   nop
    /* 1AC55C 002AC55C 0000A0FF */  sd         $0, 0x0($29)
    /* 1AC560 002AC560 0800A0FF */  sd         $0, 0x8($29)
    /* 1AC564 002AC564 2D200000 */  daddu      $4, $0, $0
    /* 1AC568 002AC568 6400053C */  lui        $5, %hi(D_0063EFB0)
    /* 1AC56C 002AC56C B0EFA524 */  addiu      $5, $5, %lo(D_0063EFB0)
    /* 1AC570 002AC570 2D300000 */  daddu      $6, $0, $0
    /* 1AC574 002AC574 2D380000 */  daddu      $7, $0, $0
    /* 1AC578 002AC578 2D400000 */  daddu      $8, $0, $0
    /* 1AC57C 002AC57C 2D480000 */  daddu      $9, $0, $0
    /* 1AC580 002AC580 2D500000 */  daddu      $10, $0, $0
    /* 1AC584 002AC584 2D580000 */  daddu      $11, $0, $0
    /* 1AC588 002AC588 F499110C */  jal        func_004667d0
    /* 1AC58C 002AC58C 00000000 */   nop
    /* 1AC590 002AC590 080002AE */  sw         $2, 0x8($16)
    /* 1AC594 002AC594 04000282 */  lb         $2, 0x4($16)
    /* 1AC598 002AC598 01004224 */  addiu      $2, $2, 0x1
    /* 1AC59C 002AC59C 040002A2 */  sb         $2, 0x4($16)
    /* 1AC5A0 002AC5A0 11000010 */  b          .L002AC5E8
    /* 1AC5A4 002AC5A4 00000000 */   nop
  .L002AC5A8:
    /* 1AC5A8 002AC5A8 0800048E */  lw         $4, 0x8($16)
    /* 1AC5AC 002AC5AC 3C00A527 */  addiu      $5, $29, 0x3C
    /* 1AC5B0 002AC5B0 2D300000 */  daddu      $6, $0, $0
    /* 1AC5B4 002AC5B4 749A110C */  jal        func_004669d0
    /* 1AC5B8 002AC5B8 00000000 */   nop
    /* 1AC5BC 002AC5BC 58B582AF */  sw         $2, -0x4AA8($28)
    /* 1AC5C0 002AC5C0 3C00A28F */  lw         $2, 0x3C($29)
    /* 1AC5C4 002AC5C4 08004010 */  beqz       $2, .L002AC5E8
    /* 1AC5C8 002AC5C8 00000000 */   nop
    /* 1AC5CC 002AC5CC 080000AE */  sw         $0, 0x8($16)
    /* 1AC5D0 002AC5D0 0000048E */  lw         $4, 0x0($16)
    /* 1AC5D4 002AC5D4 F452110C */  jal        func_00454bd0
    /* 1AC5D8 002AC5D8 00000000 */   nop
    /* 1AC5DC 002AC5DC FFFF0224 */  addiu      $2, $0, -0x1
    /* 1AC5E0 002AC5E0 02000010 */  b          .L002AC5EC
    /* 1AC5E4 002AC5E4 00000000 */   nop
  .L002AC5E8:
    /* 1AC5E8 002AC5E8 2D100000 */  daddu      $2, $0, $0
  .L002AC5EC:
    /* 1AC5EC 002AC5EC 2000BFDF */  ld         $31, 0x20($29)
    /* 1AC5F0 002AC5F0 1000B07B */  lq         $16, 0x10($29)
    /* 1AC5F4 002AC5F4 4000BD27 */  addiu      $29, $29, 0x40
    /* 1AC5F8 002AC5F8 0800E003 */  jr         $31
    /* 1AC5FC 002AC5FC 00000000 */   nop
.size func_002ac400, 0x200
