.section .text
.set noat
.set noreorder
glabel func_004ea550
    /* 3EA550 004EA550 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA554 004EA554 2D308000 */  daddu      $6, $4, $0
    /* 3EA558 004EA558 0700C014 */  bnez       $6, .L004EA578
    /* 3EA55C 004EA55C 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA560 004EA560 7600053C */  lui        $5, %hi(D_0075BFD8)
    /* 3EA564 004EA564 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA568 004EA568 D8BFA524 */  addiu      $5, $5, %lo(D_0075BFD8)
    /* 3EA56C 004EA56C 9AA71308 */  j          func_004e9e68
    /* 3EA570 004EA570 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA574 004EA574 00000000 */  nop
  .L004EA578:
    /* 3EA578 004EA578 0800C28C */  lw         $2, 0x8($6)
    /* 3EA57C 004EA57C 1000C38C */  lw         $3, 0x10($6)
    /* 3EA580 004EA580 21104500 */  addu       $2, $2, $5
    /* 3EA584 004EA584 0400C48C */  lw         $4, 0x4($6)
    /* 3EA588 004EA588 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EA58C 004EA58C 0400C5AC */  sw         $5, 0x4($6)
    /* 3EA590 004EA590 1A004500 */  div        $0, $2, $5
    /* 3EA594 004EA594 0100A050 */  beql       $5, $0, .L004EA59C
    /* 3EA598 004EA598 CD010000 */   break     0, 7
  .L004EA59C:
    /* 3EA59C 004EA59C 12100000 */  mflo       $2
    /* 3EA5A0 004EA5A0 18186400 */  mult       $3, $3, $4
    /* 3EA5A4 004EA5A4 0C00C2AC */  sw         $2, 0xC($6)
    /* 3EA5A8 004EA5A8 1800C28C */  lw         $2, 0x18($6)
    /* 3EA5AC 004EA5AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA5B0 004EA5B0 1A006500 */  div        $0, $3, $5
    /* 3EA5B4 004EA5B4 12180000 */  mflo       $3
    /* 3EA5B8 004EA5B8 18104500 */  mult       $2, $2, $5
    /* 3EA5BC 004EA5BC 1000C3AC */  sw         $3, 0x10($6)
    /* 3EA5C0 004EA5C0 1400C2AC */  sw         $2, 0x14($6)
    /* 3EA5C4 004EA5C4 0800E003 */  jr         $31
    /* 3EA5C8 004EA5C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA5CC 004EA5CC 00000000 */  nop
.size func_004ea550, 0x80
