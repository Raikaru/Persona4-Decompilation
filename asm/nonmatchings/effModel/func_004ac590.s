.section .text
.set noat
.set noreorder
glabel func_004ac590
    /* 3AC590 004AC590 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AC594 004AC594 1000BFFF */  sd         $31, 0x10($29)
    /* 3AC598 004AC598 0000B07F */  sq         $16, 0x0($29)
    /* 3AC59C 004AC59C 2D808000 */  daddu      $16, $4, $0
    /* 3AC5A0 004AC5A0 8C00838C */  lw         $3, 0x8C($4)
    /* 3AC5A4 004AC5A4 9800828C */  lw         $2, 0x98($4)
    /* 3AC5A8 004AC5A8 2B086200 */  sltu       $1, $3, $2
    /* 3AC5AC 004AC5AC 03002010 */  beqz       $1, .L004AC5BC
    /* 3AC5B0 004AC5B0 00000000 */   nop
    /* 3AC5B4 004AC5B4 06006014 */  bnez       $3, .L004AC5D0
    /* 3AC5B8 004AC5B8 00000000 */   nop
  .L004AC5BC:
    /* 3AC5BC 004AC5BC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AC5C0 004AC5C0 240002AE */  sw         $2, 0x24($16)
    /* 3AC5C4 004AC5C4 9800028E */  lw         $2, 0x98($16)
    /* 3AC5C8 004AC5C8 01004224 */  addiu      $2, $2, 0x1
    /* 3AC5CC 004AC5CC 980002AE */  sw         $2, 0x98($16)
  .L004AC5D0:
    /* 3AC5D0 004AC5D0 54000496 */  lhu        $4, 0x54($16)
    /* 3AC5D4 004AC5D4 1805120C */  jal        func_00481460
    /* 3AC5D8 004AC5D8 00000000 */   nop
    /* 3AC5DC 004AC5DC 2D204000 */  daddu      $4, $2, $0
    /* 3AC5E0 004AC5E0 2D280002 */  daddu      $5, $16, $0
    /* 3AC5E4 004AC5E4 C0B0120C */  jal        func_004ac300
    /* 3AC5E8 004AC5E8 00000000 */   nop
    /* 3AC5EC 004AC5EC 1000BFDF */  ld         $31, 0x10($29)
    /* 3AC5F0 004AC5F0 0000B07B */  lq         $16, 0x0($29)
    /* 3AC5F4 004AC5F4 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AC5F8 004AC5F8 0800E003 */  jr         $31
    /* 3AC5FC 004AC5FC 00000000 */   nop
.size func_004ac590, 0x70
