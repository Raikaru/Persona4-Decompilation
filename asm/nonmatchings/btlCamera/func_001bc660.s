.section .text
.set noat
.set noreorder
glabel func_001bc660
    /* BC660 001BC660 B0FFBD27 */  addiu      $29, $29, -0x50
    /* BC664 001BC664 4000BFFF */  sd         $31, 0x40($29)
    /* BC668 001BC668 3000B37F */  sq         $19, 0x30($29)
    /* BC66C 001BC66C 2000B27F */  sq         $18, 0x20($29)
    /* BC670 001BC670 1000B17F */  sq         $17, 0x10($29)
    /* BC674 001BC674 0000B07F */  sq         $16, 0x0($29)
    /* BC678 001BC678 2D988000 */  daddu      $19, $4, $0
    /* BC67C 001BC67C 2D90A000 */  daddu      $18, $5, $0
    /* BC680 001BC680 2D88C000 */  daddu      $17, $6, $0
    /* BC684 001BC684 6CB3080C */  jal        func_0022cdb0
    /* BC688 001BC688 00000000 */   nop
    /* BC68C 001BC68C 2D804000 */  daddu      $16, $2, $0
    /* BC690 001BC690 08004014 */  bnez       $2, .L001BC6B4
    /* BC694 001BC694 00000000 */   nop
    /* BC698 001BC698 FFFF6432 */  andi       $4, $19, 0xFFFF
    /* BC69C 001BC69C 80180400 */  sll        $3, $4, 2
    /* BC6A0 001BC6A0 21186400 */  addu       $3, $3, $4
    /* BC6A4 001BC6A4 80200300 */  sll        $4, $3, 2
    /* BC6A8 001BC6A8 5F00033C */  lui        $3, %hi(D_005F74C0)
    /* BC6AC 001BC6AC C0746324 */  addiu      $3, $3, %lo(D_005F74C0)
    /* BC6B0 001BC6B0 21806400 */  addu       $16, $3, $4
  .L001BC6B4:
    /* BC6B4 001BC6B4 FFFF6632 */  andi       $6, $19, 0xFFFF
    /* BC6B8 001BC6B8 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC6BC 001BC6BC F4006394 */  lhu        $3, 0xF4($3)
    /* BC6C0 001BC6C0 04006614 */  bne        $3, $6, .L001BC6D4
    /* BC6C4 001BC6C4 00000000 */   nop
    /* BC6C8 001BC6C8 0800038E */  lw         $3, 0x8($16)
    /* BC6CC 001BC6CC 3F006010 */  beqz       $3, .L001BC7CC
    /* BC6D0 001BC6D0 00000000 */   nop
  .L001BC6D4:
    /* BC6D4 001BC6D4 02000764 */  daddiu     $7, $0, 0x2
    /* BC6D8 001BC6D8 0B000010 */  b          .L001BC708
    /* BC6DC 001BC6DC 00000000 */   nop
  .L001BC6E0:
    /* BC6E0 001BC6E0 ACB3858F */  lw         $5, -0x4C54($28)
    /* BC6E4 001BC6E4 40180300 */  sll        $3, $3, 1
    /* BC6E8 001BC6E8 2118A300 */  addu       $3, $5, $3
    /* BC6EC 001BC6EC 06016494 */  lhu        $4, 0x106($3)
    /* BC6F0 001BC6F0 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* BC6F4 001BC6F4 40180300 */  sll        $3, $3, 1
    /* BC6F8 001BC6F8 2118A300 */  addu       $3, $5, $3
    /* BC6FC 001BC6FC 080164A4 */  sh         $4, 0x108($3)
    /* BC700 001BC700 FFFFE324 */  addiu      $3, $7, -0x1
    /* BC704 001BC704 FFFF6730 */  andi       $7, $3, 0xFFFF
  .L001BC708:
    /* BC708 001BC708 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* BC70C 001BC70C F4FF6010 */  beqz       $3, .L001BC6E0
    /* BC710 001BC710 00000000 */   nop
    /* BC714 001BC714 ACB3848F */  lw         $4, -0x4C54($28)
    /* BC718 001BC718 F4008394 */  lhu        $3, 0xF4($4)
    /* BC71C 001BC71C 080183A4 */  sh         $3, 0x108($4)
    /* BC720 001BC720 ACB3848F */  lw         $4, -0x4C54($28)
    /* BC724 001BC724 F4008394 */  lhu        $3, 0xF4($4)
    /* BC728 001BC728 06006614 */  bne        $3, $6, .L001BC744
    /* BC72C 001BC72C 00000000 */   nop
    /* BC730 001BC730 0E018394 */  lhu        $3, 0x10E($4)
    /* BC734 001BC734 01006324 */  addiu      $3, $3, 0x1
    /* BC738 001BC738 0E0183A4 */  sh         $3, 0x10E($4)
    /* BC73C 001BC73C 02000010 */  b          .L001BC748
    /* BC740 001BC740 00000000 */   nop
  .L001BC744:
    /* BC744 001BC744 0E0180A4 */  sh         $0, 0x10E($4)
  .L001BC748:
    /* BC748 001BC748 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC74C 001BC74C F40073A4 */  sh         $19, 0xF4($3)
    /* BC750 001BC750 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC754 001BC754 FC0060AC */  sw         $0, 0xFC($3)
    /* BC758 001BC758 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC75C 001BC75C 000160AC */  sw         $0, 0x100($3)
    /* BC760 001BC760 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC764 001BC764 040172AC */  sw         $18, 0x104($3)
    /* BC768 001BC768 0C00038E */  lw         $3, 0xC($16)
    /* BC76C 001BC76C 07006010 */  beqz       $3, .L001BC78C
    /* BC770 001BC770 00000000 */   nop
    /* BC774 001BC774 ACB3848F */  lw         $4, -0x4C54($28)
    /* BC778 001BC778 F800838C */  lw         $3, 0xF8($4)
    /* BC77C 001BC77C 02006334 */  ori        $3, $3, 0x2
    /* BC780 001BC780 F80083AC */  sw         $3, 0xF8($4)
    /* BC784 001BC784 06000010 */  b          .L001BC7A0
    /* BC788 001BC788 00000000 */   nop
  .L001BC78C:
    /* BC78C 001BC78C ACB3858F */  lw         $5, -0x4C54($28)
    /* BC790 001BC790 F800A48C */  lw         $4, 0xF8($5)
    /* BC794 001BC794 FDFF0324 */  addiu      $3, $0, -0x3
    /* BC798 001BC798 24188300 */  and        $3, $4, $3
    /* BC79C 001BC79C F800A3AC */  sw         $3, 0xF8($5)
  .L001BC7A0:
    /* BC7A0 001BC7A0 03002012 */  beqz       $17, .L001BC7B0
    /* BC7A4 001BC7A4 00000000 */   nop
    /* BC7A8 001BC7A8 C0F4060C */  jal        func_001bd300
    /* BC7AC 001BC7AC 00000000 */   nop
  .L001BC7B0:
    /* BC7B0 001BC7B0 0000038E */  lw         $3, 0x0($16)
    /* BC7B4 001BC7B4 05006010 */  beqz       $3, .L001BC7CC
    /* BC7B8 001BC7B8 00000000 */   nop
    /* BC7BC 001BC7BC ACB3828F */  lw         $2, -0x4C54($28)
    /* BC7C0 001BC7C0 24004424 */  addiu      $4, $2, 0x24
    /* BC7C4 001BC7C4 09F86000 */  jalr       $3
    /* BC7C8 001BC7C8 00000000 */   nop
  .L001BC7CC:
    /* BC7CC 001BC7CC 4000BFDF */  ld         $31, 0x40($29)
    /* BC7D0 001BC7D0 3000B37B */  lq         $19, 0x30($29)
    /* BC7D4 001BC7D4 2000B27B */  lq         $18, 0x20($29)
    /* BC7D8 001BC7D8 1000B17B */  lq         $17, 0x10($29)
    /* BC7DC 001BC7DC 0000B07B */  lq         $16, 0x0($29)
    /* BC7E0 001BC7E0 5000BD27 */  addiu      $29, $29, 0x50
    /* BC7E4 001BC7E4 0800E003 */  jr         $31
    /* BC7E8 001BC7E8 00000000 */   nop
    /* BC7EC 001BC7EC 00000000 */  nop
.size func_001bc660, 0x190
