.section .text
.set noat
.set noreorder
glabel func_002bb550
    /* 1BB550 002BB550 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BB554 002BB554 1000BFFF */  sd         $31, 0x10($29)
    /* 1BB558 002BB558 0000B07F */  sq         $16, 0x0($29)
    /* 1BB55C 002BB55C 3C160400 */  dsll32     $2, $4, 24
    /* 1BB560 002BB560 3F160200 */  dsra32     $2, $2, 24
    /* 1BB564 002BB564 80180200 */  sll        $3, $2, 2
    /* 1BB568 002BB568 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BB56C 002BB56C 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BB570 002BB570 21804300 */  addu       $16, $2, $3
    /* 1BB574 002BB574 0000028E */  lw         $2, 0x0($16)
    /* 1BB578 002BB578 04004014 */  bnez       $2, .L002BB58C
    /* 1BB57C 002BB57C 00000000 */   nop
    /* 1BB580 002BB580 2D100000 */  daddu      $2, $0, $0
    /* 1BB584 002BB584 16000010 */  b          .L002BB5E0
    /* 1BB588 002BB588 00000000 */   nop
  .L002BB58C:
    /* 1BB58C 002BB58C 0000448C */  lw         $4, 0x0($2)
    /* 1BB590 002BB590 10008004 */  bltz       $4, .L002BB5D4
    /* 1BB594 002BB594 00000000 */   nop
    /* 1BB598 002BB598 FCDD090C */  jal        func_002777f0
    /* 1BB59C 002BB59C 00000000 */   nop
    /* 1BB5A0 002BB5A0 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1BB5A4 002BB5A4 0000028E */  lw         $2, 0x0($16)
    /* 1BB5A8 002BB5A8 000043AC */  sw         $3, 0x0($2)
    /* 1BB5AC 002BB5AC 0000028E */  lw         $2, 0x0($16)
    /* 1BB5B0 002BB5B0 040040A0 */  sb         $0, 0x4($2)
    /* 1BB5B4 002BB5B4 0000028E */  lw         $2, 0x0($16)
    /* 1BB5B8 002BB5B8 050040A0 */  sb         $0, 0x5($2)
    /* 1BB5BC 002BB5BC 0000048E */  lw         $4, 0x0($16)
    /* 1BB5C0 002BB5C0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1BB5C4 002BB5C4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1BB5C8 002BB5C8 09F84000 */  jalr       $2
    /* 1BB5CC 002BB5CC 00000000 */   nop
    /* 1BB5D0 002BB5D0 000000AE */  sw         $0, 0x0($16)
  .L002BB5D4:
    /* 1BB5D4 002BB5D4 74830B0C */  jal        func_002e0dd0
    /* 1BB5D8 002BB5D8 00000000 */   nop
    /* 1BB5DC 002BB5DC 01000224 */  addiu      $2, $0, 0x1
  .L002BB5E0:
    /* 1BB5E0 002BB5E0 1000BFDF */  ld         $31, 0x10($29)
    /* 1BB5E4 002BB5E4 0000B07B */  lq         $16, 0x0($29)
    /* 1BB5E8 002BB5E8 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BB5EC 002BB5EC 0800E003 */  jr         $31
    /* 1BB5F0 002BB5F0 00000000 */   nop
    /* 1BB5F4 002BB5F4 00000000 */  nop
    /* 1BB5F8 002BB5F8 00000000 */  nop
    /* 1BB5FC 002BB5FC 00000000 */  nop
.size func_002bb550, 0xb0
