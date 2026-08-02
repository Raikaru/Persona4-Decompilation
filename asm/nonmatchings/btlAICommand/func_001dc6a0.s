.section .text
.set noat
.set noreorder
glabel func_001dc6a0
    /* DC6A0 001DC6A0 90FFBD27 */  addiu      $29, $29, -0x70
    /* DC6A4 001DC6A4 3000BFFF */  sd         $31, 0x30($29)
    /* DC6A8 001DC6A8 2000B27F */  sq         $18, 0x20($29)
    /* DC6AC 001DC6AC 1000B17F */  sq         $17, 0x10($29)
    /* DC6B0 001DC6B0 0000B07F */  sq         $16, 0x0($29)
    /* DC6B4 001DC6B4 2D908000 */  daddu      $18, $4, $0
    /* DC6B8 001DC6B8 2D800000 */  daddu      $16, $0, $0
    /* DC6BC 001DC6BC ACB3828F */  lw         $2, -0x4C54($28)
    /* DC6C0 001DC6C0 7401518C */  lw         $17, 0x174($2)
    /* DC6C4 001DC6C4 1D000010 */  b          .L001DC73C
    /* DC6C8 001DC6C8 00000000 */   nop
  .L001DC6CC:
    /* DC6CC 001DC6CC 1A005112 */  beq        $18, $17, .L001DC738
    /* DC6D0 001DC6D0 00000000 */   nop
    /* DC6D4 001DC6D4 1A002396 */  lhu        $3, 0x1A($17)
    /* DC6D8 001DC6D8 01006230 */  andi       $2, $3, 0x1
    /* DC6DC 001DC6DC 16004010 */  beqz       $2, .L001DC738
    /* DC6E0 001DC6E0 00000000 */   nop
    /* DC6E4 001DC6E4 08006230 */  andi       $2, $3, 0x8
    /* DC6E8 001DC6E8 13004010 */  beqz       $2, .L001DC738
    /* DC6EC 001DC6EC 00000000 */   nop
    /* DC6F0 001DC6F0 3000248E */  lw         $4, 0x30($17)
    /* DC6F4 001DC6F4 3000428E */  lw         $2, 0x30($18)
    /* DC6F8 001DC6F8 A2004390 */  lbu        $3, 0xA2($2)
    /* DC6FC 001DC6FC A2008290 */  lbu        $2, 0xA2($4)
    /* DC700 001DC700 0D006214 */  bne        $3, $2, .L001DC738
    /* DC704 001DC704 00000000 */   nop
    /* DC708 001DC708 640A848C */  lw         $4, 0xA64($4)
    /* DC70C 001DC70C 0800053C */  lui        $5, (0x80000 >> 16)
    /* DC710 001DC710 C4C9080C */  jal        func_00232710
    /* DC714 001DC714 00000000 */   nop
    /* DC718 001DC718 07004014 */  bnez       $2, .L001DC738
    /* DC71C 001DC71C 00000000 */   nop
    /* DC720 001DC720 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DC724 001DC724 80100200 */  sll        $2, $2, 2
    /* DC728 001DC728 21105D00 */  addu       $2, $2, $29
    /* DC72C 001DC72C 400051AC */  sw         $17, 0x40($2)
    /* DC730 001DC730 01000226 */  addiu      $2, $16, 0x1
    /* DC734 001DC734 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001DC738:
    /* DC738 001DC738 5004318E */  lw         $17, 0x450($17)
  .L001DC73C:
    /* DC73C 001DC73C E3FF2016 */  bnez       $17, .L001DC6CC
    /* DC740 001DC740 00000000 */   nop
    /* DC744 001DC744 FFFF0432 */  andi       $4, $16, 0xFFFF
    /* DC748 001DC748 06008014 */  bnez       $4, .L001DC764
    /* DC74C 001DC74C 00000000 */   nop
    /* DC750 001DC750 380052AE */  sw         $18, 0x38($18)
    /* DC754 001DC754 01000224 */  addiu      $2, $0, 0x1
    /* DC758 001DC758 6A0042A6 */  sh         $2, 0x6A($18)
    /* DC75C 001DC75C 09000010 */  b          .L001DC784
    /* DC760 001DC760 00000000 */   nop
  .L001DC764:
    /* DC764 001DC764 5CC7080C */  jal        func_00231d70
    /* DC768 001DC768 00000000 */   nop
    /* DC76C 001DC76C 80100200 */  sll        $2, $2, 2
    /* DC770 001DC770 21105D00 */  addu       $2, $2, $29
    /* DC774 001DC774 4000428C */  lw         $2, 0x40($2)
    /* DC778 001DC778 380042AE */  sw         $2, 0x38($18)
    /* DC77C 001DC77C 01000224 */  addiu      $2, $0, 0x1
    /* DC780 001DC780 6A0042A6 */  sh         $2, 0x6A($18)
  .L001DC784:
    /* DC784 001DC784 3000BFDF */  ld         $31, 0x30($29)
    /* DC788 001DC788 2000B27B */  lq         $18, 0x20($29)
    /* DC78C 001DC78C 1000B17B */  lq         $17, 0x10($29)
    /* DC790 001DC790 0000B07B */  lq         $16, 0x0($29)
    /* DC794 001DC794 7000BD27 */  addiu      $29, $29, 0x70
    /* DC798 001DC798 0800E003 */  jr         $31
    /* DC79C 001DC79C 00000000 */   nop
.size func_001dc6a0, 0x100
