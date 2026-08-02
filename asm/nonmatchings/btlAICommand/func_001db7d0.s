.section .text
.set noat
.set noreorder
glabel func_001db7d0
    /* DB7D0 001DB7D0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* DB7D4 001DB7D4 4000BFFF */  sd         $31, 0x40($29)
    /* DB7D8 001DB7D8 3000B37F */  sq         $19, 0x30($29)
    /* DB7DC 001DB7DC 2000B27F */  sq         $18, 0x20($29)
    /* DB7E0 001DB7E0 1000B17F */  sq         $17, 0x10($29)
    /* DB7E4 001DB7E4 0000B07F */  sq         $16, 0x0($29)
    /* DB7E8 001DB7E8 2D98A000 */  daddu      $19, $5, $0
    /* DB7EC 001DB7EC 3000838C */  lw         $3, 0x30($4)
    /* DB7F0 001DB7F0 A2006290 */  lbu        $2, 0xA2($3)
    /* DB7F4 001DB7F4 04004014 */  bnez       $2, .L001DB808
    /* DB7F8 001DB7F8 00000000 */   nop
    /* DB7FC 001DB7FC 01000224 */  addiu      $2, $0, 0x1
    /* DB800 001DB800 02000010 */  b          .L001DB80C
    /* DB804 001DB804 00000000 */   nop
  .L001DB808:
    /* DB808 001DB808 2D100000 */  daddu      $2, $0, $0
  .L001DB80C:
    /* DB80C 001DB80C FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DB810 001DB810 640A648C */  lw         $4, 0xA64($3)
    /* DB814 001DB814 88C7080C */  jal        func_00231e20
    /* DB818 001DB818 00000000 */   nop
    /* DB81C 001DB81C FF005130 */  andi       $17, $2, 0xFF
    /* DB820 001DB820 ACB3828F */  lw         $2, -0x4C54($28)
    /* DB824 001DB824 7401528C */  lw         $18, 0x174($2)
    /* DB828 001DB828 FFFF1032 */  andi       $16, $16, 0xFFFF
    /* DB82C 001DB82C 1B000010 */  b          .L001DB89C
    /* DB830 001DB830 00000000 */   nop
  .L001DB834:
    /* DB834 001DB834 1A004396 */  lhu        $3, 0x1A($18)
    /* DB838 001DB838 01006230 */  andi       $2, $3, 0x1
    /* DB83C 001DB83C 16004010 */  beqz       $2, .L001DB898
    /* DB840 001DB840 00000000 */   nop
    /* DB844 001DB844 08006230 */  andi       $2, $3, 0x8
    /* DB848 001DB848 13004010 */  beqz       $2, .L001DB898
    /* DB84C 001DB84C 00000000 */   nop
    /* DB850 001DB850 3000438E */  lw         $3, 0x30($18)
    /* DB854 001DB854 A2006290 */  lbu        $2, 0xA2($3)
    /* DB858 001DB858 0F005014 */  bne        $2, $16, .L001DB898
    /* DB85C 001DB85C 00000000 */   nop
    /* DB860 001DB860 640A648C */  lw         $4, 0xA64($3)
    /* DB864 001DB864 88C7080C */  jal        func_00231e20
    /* DB868 001DB868 00000000 */   nop
    /* DB86C 001DB86C FF004330 */  andi       $3, $2, 0xFF
    /* DB870 001DB870 2B107100 */  sltu       $2, $3, $17
    /* DB874 001DB874 08004014 */  bnez       $2, .L001DB898
    /* DB878 001DB878 00000000 */   nop
    /* DB87C 001DB87C 23107100 */  subu       $2, $3, $17
    /* DB880 001DB880 2B105300 */  sltu       $2, $2, $19
    /* DB884 001DB884 04004014 */  bnez       $2, .L001DB898
    /* DB888 001DB888 00000000 */   nop
    /* DB88C 001DB88C 01000224 */  addiu      $2, $0, 0x1
    /* DB890 001DB890 05000010 */  b          .L001DB8A8
    /* DB894 001DB894 00000000 */   nop
  .L001DB898:
    /* DB898 001DB898 5004528E */  lw         $18, 0x450($18)
  .L001DB89C:
    /* DB89C 001DB89C E5FF4016 */  bnez       $18, .L001DB834
    /* DB8A0 001DB8A0 00000000 */   nop
    /* DB8A4 001DB8A4 2D100000 */  daddu      $2, $0, $0
  .L001DB8A8:
    /* DB8A8 001DB8A8 4000BFDF */  ld         $31, 0x40($29)
    /* DB8AC 001DB8AC 3000B37B */  lq         $19, 0x30($29)
    /* DB8B0 001DB8B0 2000B27B */  lq         $18, 0x20($29)
    /* DB8B4 001DB8B4 1000B17B */  lq         $17, 0x10($29)
    /* DB8B8 001DB8B8 0000B07B */  lq         $16, 0x0($29)
    /* DB8BC 001DB8BC 5000BD27 */  addiu      $29, $29, 0x50
    /* DB8C0 001DB8C0 0800E003 */  jr         $31
    /* DB8C4 001DB8C4 00000000 */   nop
    /* DB8C8 001DB8C8 00000000 */  nop
    /* DB8CC 001DB8CC 00000000 */  nop
.size func_001db7d0, 0x100
