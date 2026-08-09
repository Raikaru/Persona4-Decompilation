.section .text
.set noat
.set noreorder
glabel func_004eb7b0
    /* 3EB7B0 004EB7B0 7400083C */  lui        $8, %hi(D_0073A740)
    /* 3EB7B4 004EB7B4 2D300000 */  daddu      $6, $0, $0
    /* 3EB7B8 004EB7B8 40A7058D */  lw         $5, %lo(D_0073A740)($8)
    /* 3EB7BC 004EB7BC 1100A018 */  blez       $5, .L004EB804
    /* 3EB7C0 004EB7C0 2D200000 */   daddu     $4, $0, $0
    /* 3EB7C4 004EB7C4 7400023C */  lui        $2, %hi(D_0073A7A0)
    /* 3EB7C8 004EB7C8 A0A74424 */  addiu      $4, $2, %lo(D_0073A7A0)
    /* 3EB7CC 004EB7CC 00008380 */  lb         $3, 0x0($4)
    /* 3EB7D0 004EB7D0 0C006010 */  beqz       $3, .L004EB804
    /* 3EB7D4 004EB7D4 2D188000 */   daddu     $3, $4, $0
    /* 3EB7D8 004EB7D8 2D38A000 */  daddu      $7, $5, $0
    /* 3EB7DC 004EB7DC 2D288000 */  daddu      $5, $4, $0
  .L004EB7E0:
    /* 3EB7E0 004EB7E0 0100C624 */  addiu      $6, $6, 0x1
    /* 3EB7E4 004EB7E4 1800A524 */  addiu      $5, $5, 0x18
    /* 3EB7E8 004EB7E8 2A10C700 */  slt        $2, $6, $7
    /* 3EB7EC 004EB7EC 05004010 */  beqz       $2, .L004EB804
    /* 3EB7F0 004EB7F0 18006324 */   addiu     $3, $3, 0x18
    /* 3EB7F4 004EB7F4 0000A280 */  lb         $2, 0x0($5)
    /* 3EB7F8 004EB7F8 00000000 */  nop
    /* 3EB7FC 004EB7FC F8FF4014 */  bnez       $2, .L004EB7E0
    /* 3EB800 004EB800 2D206000 */   daddu     $4, $3, $0
  .L004EB804:
    /* 3EB804 004EB804 40A7038D */  lw         $3, %lo(D_0073A740)($8)
    /* 3EB808 004EB808 0400C310 */  beq        $6, $3, .L004EB81C
    /* 3EB80C 004EB80C 2D100000 */   daddu     $2, $0, $0
    /* 3EB810 004EB810 01000324 */  addiu      $3, $0, 0x1
    /* 3EB814 004EB814 2D108000 */  daddu      $2, $4, $0
    /* 3EB818 004EB818 000083A0 */  sb         $3, 0x0($4)
  .L004EB81C:
    /* 3EB81C 004EB81C 0800E003 */  jr         $31
    /* 3EB820 004EB820 00000000 */   nop
    /* 3EB824 004EB824 00000000 */  nop
.size func_004eb7b0, 0x78
