.section .text
.set noat
.set noreorder
glabel func_003bb4a0
    /* 2BB4A0 003BB4A0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BB4A4 003BB4A4 3000BFFF */  sd         $31, 0x30($29)
    /* 2BB4A8 003BB4A8 2000B27F */  sq         $18, 0x20($29)
    /* 2BB4AC 003BB4AC 1000B17F */  sq         $17, 0x10($29)
    /* 2BB4B0 003BB4B0 2D908000 */  daddu      $18, $4, $0
    /* 2BB4B4 003BB4B4 0000B07F */  sq         $16, 0x0($29)
    /* 2BB4B8 003BB4B8 2D88A000 */  daddu      $17, $5, $0
    /* 2BB4BC 003BB4BC 2B002006 */  bltz       $17, .L003BB56C
    /* 2BB4C0 003BB4C0 2D80C000 */   daddu     $16, $6, $0
    /* 2BB4C4 003BB4C4 0C00438E */  lw         $3, 0xC($18)
    /* 2BB4C8 003BB4C8 02000224 */  addiu      $2, $0, 0x2
    /* 2BB4CC 003BB4CC 09006210 */  beq        $3, $2, .L003BB4F4
    /* 2BB4D0 003BB4D0 00000000 */   nop
    /* 2BB4D4 003BB4D4 01000424 */  addiu      $4, $0, 0x1
    /* 2BB4D8 003BB4D8 03006410 */  beq        $3, $4, .L003BB4E8
    /* 2BB4DC 003BB4DC 00000000 */   nop
    /* 2BB4E0 003BB4E0 08000010 */  b          .L003BB504
    /* 2BB4E4 003BB4E4 02010224 */   addiu     $2, $0, 0x102
  .L003BB4E8:
    /* 2BB4E8 003BB4E8 0800428E */  lw         $2, 0x8($18)
    /* 2BB4EC 003BB4EC 0B000010 */  b          .L003BB51C
    /* 2BB4F0 003BB4F0 FEFF4224 */   addiu     $2, $2, -0x2
  .L003BB4F4:
    /* 2BB4F4 003BB4F4 0800428E */  lw         $2, 0x8($18)
    /* 2BB4F8 003BB4F8 08000010 */  b          .L003BB51C
    /* 2BB4FC 003BB4FC FDFF4224 */   addiu     $2, $2, -0x3
    /* 2BB500 003BB500 02010224 */  addiu      $2, $0, 0x102
  .L003BB504:
    /* 2BB504 003BB504 647D0F0C */  jal        func_003df590
    /* 2BB508 003BB508 4000A2AF */   sw        $2, 0x40($29)
    /* 2BB50C 003BB50C 4400A2AF */  sw         $2, 0x44($29)
    /* 2BB510 003BB510 347D0F0C */  jal        func_003df4d0
    /* 2BB514 003BB514 4000A427 */   addiu     $4, $29, 0x40
    /* 2BB518 003BB518 2D100000 */  daddu      $2, $0, $0
  .L003BB51C:
    /* 2BB51C 003BB51C 2A082202 */  slt        $1, $17, $2
    /* 2BB520 003BB520 12002010 */  beqz       $1, .L003BB56C
    /* 2BB524 003BB524 00000000 */   nop
    /* 2BB528 003BB528 1400428E */  lw         $2, 0x14($18)
    /* 2BB52C 003BB52C 40181100 */  sll        $3, $17, 1
    /* 2BB530 003BB530 000002C6 */  lwc1       $f2, 0x0($16)
    /* 2BB534 003BB534 21187100 */  addu       $3, $3, $17
    /* 2BB538 003BB538 040001C6 */  lwc1       $f1, 0x4($16)
    /* 2BB53C 003BB53C 80180300 */  sll        $3, $3, 2
    /* 2BB540 003BB540 080000C6 */  lwc1       $f0, 0x8($16)
    /* 2BB544 003BB544 21104300 */  addu       $2, $2, $3
    /* 2BB548 003BB548 000042E4 */  swc1       $f2, 0x0($2)
    /* 2BB54C 003BB54C 040041E4 */  swc1       $f1, 0x4($2)
    /* 2BB550 003BB550 080040E4 */  swc1       $f0, 0x8($2)
    /* 2BB554 003BB554 1400458E */  lw         $5, 0x14($18)
    /* 2BB558 003BB558 90E60E0C */  jal        func_003b9a40
    /* 2BB55C 003BB55C 2D204002 */   daddu     $4, $18, $0
    /* 2BB560 003BB560 0A900200 */  movz       $18, $0, $2
    /* 2BB564 003BB564 0C000010 */  b          .L003BB598
    /* 2BB568 003BB568 2D104002 */   daddu     $2, $18, $0
  .L003BB56C:
    /* 2BB56C 003BB56C 02010324 */  addiu      $3, $0, 0x102
    /* 2BB570 003BB570 0080023C */  lui        $2, (0x80000003 >> 16)
    /* 2BB574 003BB574 7100053C */  lui        $5, %hi(D_0070AF50)
    /* 2BB578 003BB578 4800A3AF */  sw         $3, 0x48($29)
    /* 2BB57C 003BB57C 03004434 */  ori        $4, $2, (0x80000003 & 0xFFFF)
    /* 2BB580 003BB580 647D0F0C */  jal        func_003df590
    /* 2BB584 003BB584 50AFA524 */   addiu     $5, $5, %lo(D_0070AF50)
    /* 2BB588 003BB588 4C00A2AF */  sw         $2, 0x4C($29)
    /* 2BB58C 003BB58C 347D0F0C */  jal        func_003df4d0
    /* 2BB590 003BB590 4800A427 */   addiu     $4, $29, 0x48
    /* 2BB594 003BB594 2D100000 */  daddu      $2, $0, $0
  .L003BB598:
    /* 2BB598 003BB598 3000BFDF */  ld         $31, 0x30($29)
    /* 2BB59C 003BB59C 2000B27B */  lq         $18, 0x20($29)
    /* 2BB5A0 003BB5A0 1000B17B */  lq         $17, 0x10($29)
    /* 2BB5A4 003BB5A4 0000B07B */  lq         $16, 0x0($29)
    /* 2BB5A8 003BB5A8 0800E003 */  jr         $31
    /* 2BB5AC 003BB5AC 5000BD27 */   addiu     $29, $29, 0x50
.size func_003bb4a0, 0x110
