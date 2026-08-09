.section .text
.set noat
.set noreorder
glabel func_001ef7e0
    /* EF7E0 001EF7E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EF7E4 001EF7E4 1000BFFF */  sd         $31, 0x10($29)
    /* EF7E8 001EF7E8 0000B07F */  sq         $16, 0x0($29)
    /* EF7EC 001EF7EC 68BE070C */  jal        func_001ef9a0
    /* EF7F0 001EF7F0 00000000 */   nop
    /* EF7F4 001EF7F4 40180200 */  sll        $3, $2, 1
    /* EF7F8 001EF7F8 21106200 */  addu       $2, $3, $2
    /* EF7FC 001EF7FC C0180200 */  sll        $3, $2, 3
    /* EF800 001EF800 14B4828F */  lw         $2, -0x4BEC($28)
    /* EF804 001EF804 21184300 */  addu       $3, $2, $3
    /* EF808 001EF808 ACB3848F */  lw         $4, -0x4C54($28)
    /* EF80C 001EF80C 5A0C8294 */  lhu        $2, 0xC5A($4)
    /* EF810 001EF810 04004014 */  bnez       $2, .L001EF824
    /* EF814 001EF814 00000000 */   nop
    /* EF818 001EF818 2D100000 */  daddu      $2, $0, $0
    /* EF81C 001EF81C 23000010 */  b          .L001EF8AC
    /* EF820 001EF820 00000000 */   nop
  .L001EF824:
    /* EF824 001EF824 0000638C */  lw         $3, 0x0($3)
    /* EF828 001EF828 02006230 */  andi       $2, $3, 0x2
    /* EF82C 001EF82C 04004010 */  beqz       $2, .L001EF840
    /* EF830 001EF830 00000000 */   nop
    /* EF834 001EF834 2D100000 */  daddu      $2, $0, $0
    /* EF838 001EF838 1C000010 */  b          .L001EF8AC
    /* EF83C 001EF83C 00000000 */   nop
  .L001EF840:
    /* EF840 001EF840 04006230 */  andi       $2, $3, 0x4
    /* EF844 001EF844 04004010 */  beqz       $2, .L001EF858
    /* EF848 001EF848 00000000 */   nop
    /* EF84C 001EF84C 01000224 */  addiu      $2, $0, 0x1
    /* EF850 001EF850 16000010 */  b          .L001EF8AC
    /* EF854 001EF854 00000000 */   nop
  .L001EF858:
    /* EF858 001EF858 2000828C */  lw         $2, 0x20($4)
    /* EF85C 001EF85C 04004014 */  bnez       $2, .L001EF870
    /* EF860 001EF860 00000000 */   nop
    /* EF864 001EF864 2D180000 */  daddu      $3, $0, $0
    /* EF868 001EF868 08000010 */  b          .L001EF88C
    /* EF86C 001EF86C 00000000 */   nop
  .L001EF870:
    /* EF870 001EF870 0600412C */  sltiu      $1, $2, 0x6
    /* EF874 001EF874 04002014 */  bnez       $1, .L001EF888
    /* EF878 001EF878 00000000 */   nop
    /* EF87C 001EF87C 04000324 */  addiu      $3, $0, 0x4
    /* EF880 001EF880 02000010 */  b          .L001EF88C
    /* EF884 001EF884 00000000 */   nop
  .L001EF888:
    /* EF888 001EF888 FFFF4324 */  addiu      $3, $2, -0x1
  .L001EF88C:
    /* EF88C 001EF88C B0A98227 */  addiu      $2, $28, -0x5650
    /* EF890 001EF890 21104300 */  addu       $2, $2, $3
    /* EF894 001EF894 00005090 */  lbu        $16, 0x0($2)
    /* EF898 001EF898 64000424 */  addiu      $4, $0, 0x64
    /* EF89C 001EF89C 5CC7080C */  jal        func_00231d70
    /* EF8A0 001EF8A0 00000000 */   nop
    /* EF8A4 001EF8A4 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* EF8A8 001EF8A8 2B104300 */  sltu       $2, $2, $3
  .L001EF8AC:
    /* EF8AC 001EF8AC 1000BFDF */  ld         $31, 0x10($29)
    /* EF8B0 001EF8B0 0000B07B */  lq         $16, 0x0($29)
    /* EF8B4 001EF8B4 2000BD27 */  addiu      $29, $29, 0x20
    /* EF8B8 001EF8B8 0800E003 */  jr         $31
    /* EF8BC 001EF8BC 00000000 */   nop
.size func_001ef7e0, 0xe0
