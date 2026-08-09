.section .text
.set noat
.set noreorder
glabel func_004cc630
    /* 3CC630 004CC630 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC634 004CC634 3000B6FF */  sd         $22, 0x30($29)
    /* 3CC638 004CC638 7200163C */  lui        $22, %hi(D_00719A70)
    /* 3CC63C 004CC63C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CC640 004CC640 709AC326 */  addiu      $3, $22, %lo(D_00719A70)
    /* 3CC644 004CC644 0800B1FF */  sd         $17, 0x8($29)
    /* 3CC648 004CC648 1000B2FF */  sd         $18, 0x10($29)
    /* 3CC64C 004CC64C 1800B3FF */  sd         $19, 0x18($29)
    /* 3CC650 004CC650 2000B4FF */  sd         $20, 0x20($29)
    /* 3CC654 004CC654 2800B5FF */  sd         $21, 0x28($29)
    /* 3CC658 004CC658 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC65C 004CC65C 000062DC */  ld         $2, 0x0($3)
    /* 3CC660 004CC660 15004014 */  bnez       $2, .L004CC6B8
    /* 3CC664 004CC664 7200153C */   lui       $21, %hi(D_00719A68)
    /* 3CC668 004CC668 7200143C */  lui        $20, %hi(D_00719A30)
    /* 3CC66C 004CC66C 2D986000 */  daddu      $19, $3, $0
    /* 3CC670 004CC670 689AB226 */  addiu      $18, $21, %lo(D_00719A68)
    /* 3CC674 004CC674 01001124 */  addiu      $17, $0, 0x1
    /* 3CC678 004CC678 309A9026 */  addiu      $16, $20, %lo(D_00719A30)
    /* 3CC67C 004CC67C 00000000 */  nop
  .L004CC680:
    /* 3CC680 004CC680 000051FE */  sd         $17, 0x0($18)
    /* 3CC684 004CC684 01000524 */  addiu      $5, $0, 0x1
    /* 3CC688 004CC688 9C85100C */  jal        func_00421670
    /* 3CC68C 004CC68C 0000048E */   lw        $4, 0x0($16)
    /* 3CC690 004CC690 C485100C */  jal        func_00421710
    /* 3CC694 004CC694 0000048E */   lw        $4, 0x0($16)
    /* 3CC698 004CC698 502F130C */  jal        func_004cbd40
    /* 3CC69C 004CC69C 0000048E */   lw        $4, 0x0($16)
    /* 3CC6A0 004CC6A0 000063DE */  ld         $3, 0x0($19)
    /* 3CC6A4 004CC6A4 F6FF6010 */  beqz       $3, .L004CC680
    /* 3CC6A8 004CC6A8 709AC226 */   addiu     $2, $22, %lo(D_00719A70)
    /* 3CC6AC 004CC6AC 05000010 */  b          .L004CC6C4
    /* 3CC6B0 004CC6B0 3000B6DF */   ld        $22, 0x30($29)
    /* 3CC6B4 004CC6B4 00000000 */  nop
  .L004CC6B8:
    /* 3CC6B8 004CC6B8 7200143C */  lui        $20, %hi(D_00719A30)
    /* 3CC6BC 004CC6BC 709AC226 */  addiu      $2, $22, %lo(D_00719A70)
    /* 3CC6C0 004CC6C0 3000B6DF */  ld         $22, 0x30($29)
  .L004CC6C4:
    /* 3CC6C4 004CC6C4 689AA326 */  addiu      $3, $21, %lo(D_00719A68)
    /* 3CC6C8 004CC6C8 2800B5DF */  ld         $21, 0x28($29)
    /* 3CC6CC 004CC6CC 309A8426 */  addiu      $4, $20, %lo(D_00719A30)
    /* 3CC6D0 004CC6D0 2000B4DF */  ld         $20, 0x20($29)
    /* 3CC6D4 004CC6D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CC6D8 004CC6D8 0800B1DF */  ld         $17, 0x8($29)
    /* 3CC6DC 004CC6DC 1000B2DF */  ld         $18, 0x10($29)
    /* 3CC6E0 004CC6E0 1800B3DF */  ld         $19, 0x18($29)
    /* 3CC6E4 004CC6E4 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC6E8 004CC6E8 000040FC */  sd         $0, 0x0($2)
    /* 3CC6EC 004CC6EC 000060FC */  sd         $0, 0x0($3)
    /* 3CC6F0 004CC6F0 000080AC */  sw         $0, 0x0($4)
    /* 3CC6F4 004CC6F4 0800E003 */  jr         $31
    /* 3CC6F8 004CC6F8 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CC6FC 004CC6FC 00000000 */  nop
.size func_004cc630, 0xd0
