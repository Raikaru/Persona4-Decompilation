.section .text
.set noat
.set noreorder
glabel func_004eb830
    /* 3EB830 004EB830 0900A054 */  bnel       $5, $0, .L004EB858
    /* 3EB834 004EB834 0000A58C */   lw        $5, 0x0($5)
  .L004EB838:
    /* 3EB838 004EB838 00000000 */  nop
    /* 3EB83C 004EB83C 00000000 */  nop
    /* 3EB840 004EB840 00000000 */  nop
    /* 3EB844 004EB844 00000000 */  nop
    /* 3EB848 004EB848 00000000 */  nop
    /* 3EB84C 004EB84C FAFF0010 */  b          .L004EB838
    /* 3EB850 004EB850 00000000 */   nop
    /* 3EB854 004EB854 00000000 */  nop
  .L004EB858:
    /* 3EB858 004EB858 0A00A018 */  blez       $5, .L004EB884
    /* 3EB85C 004EB85C 00000000 */   nop
    /* 3EB860 004EB860 FFFFA524 */  addiu      $5, $5, -0x1
    /* 3EB864 004EB864 00000000 */  nop
  .L004EB868:
    /* 3EB868 004EB868 00000000 */  nop
    /* 3EB86C 004EB86C 00000000 */  nop
    /* 3EB870 004EB870 00000000 */  nop
    /* 3EB874 004EB874 00000000 */  nop
    /* 3EB878 004EB878 00000000 */  nop
    /* 3EB87C 004EB87C FAFFA054 */  bnel       $5, $0, .L004EB868
    /* 3EB880 004EB880 FFFFA524 */   addiu     $5, $5, -0x1
  .L004EB884:
    /* 3EB884 004EB884 0800E003 */  jr         $31
    /* 3EB888 004EB888 00000000 */   nop
    /* 3EB88C 004EB88C 00000000 */  nop
.size func_004eb830, 0x60
