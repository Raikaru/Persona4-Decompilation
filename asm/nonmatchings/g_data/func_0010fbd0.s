.section .text
.set noat
.set noreorder
glabel func_0010fbd0
    /* FBD0 0010FBD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FBD4 0010FBD4 1000BFFF */  sd         $31, 0x10($29)
    /* FBD8 0010FBD8 0000B07F */  sq         $16, 0x0($29)
    /* FBDC 0010FBDC 2D808000 */  daddu      $16, $4, $0
    /* FBE0 0010FBE0 0001022E */  sltiu      $2, $16, 0x100
    /* FBE4 0010FBE4 06004014 */  bnez       $2, .L0010FC00
    /* FBE8 0010FBE8 00000000 */   nop
    /* FBEC 0010FBEC 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FBF0 0010FBF0 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FBF4 0010FBF4 040F0524 */  addiu      $5, $0, 0xF04
    /* FBF8 0010FBF8 CCB5110C */  jal        func_0046d730
    /* FBFC 0010FBFC 00000000 */   nop
  .L0010FC00:
    /* FC00 0010FC00 80101000 */  sll        $2, $16, 2
    /* FC04 0010FC04 21105000 */  addu       $2, $2, $16
    /* FC08 0010FC08 40100200 */  sll        $2, $2, 1
    /* FC0C 0010FC0C 21105000 */  addu       $2, $2, $16
    /* FC10 0010FC10 C0180200 */  sll        $3, $2, 3
    /* FC14 0010FC14 E0B3828F */  lw         $2, -0x4C20($28)
    /* FC18 0010FC18 21104300 */  addu       $2, $2, $3
    /* FC1C 0010FC1C 00004394 */  lhu        $3, 0x0($2)
    /* FC20 0010FC20 02006230 */  andi       $2, $3, 0x2
    /* FC24 0010FC24 04004010 */  beqz       $2, .L0010FC38
    /* FC28 0010FC28 00000000 */   nop
    /* FC2C 0010FC2C 02000224 */  addiu      $2, $0, 0x2
    /* FC30 0010FC30 0E000010 */  b          .L0010FC6C
    /* FC34 0010FC34 00000000 */   nop
  .L0010FC38:
    /* FC38 0010FC38 04006230 */  andi       $2, $3, 0x4
    /* FC3C 0010FC3C 04004010 */  beqz       $2, .L0010FC50
    /* FC40 0010FC40 00000000 */   nop
    /* FC44 0010FC44 04000224 */  addiu      $2, $0, 0x4
    /* FC48 0010FC48 08000010 */  b          .L0010FC6C
    /* FC4C 0010FC4C 00000000 */   nop
  .L0010FC50:
    /* FC50 0010FC50 08006230 */  andi       $2, $3, 0x8
    /* FC54 0010FC54 04004010 */  beqz       $2, .L0010FC68
    /* FC58 0010FC58 00000000 */   nop
    /* FC5C 0010FC5C 08000224 */  addiu      $2, $0, 0x8
    /* FC60 0010FC60 02000010 */  b          .L0010FC6C
    /* FC64 0010FC64 00000000 */   nop
  .L0010FC68:
    /* FC68 0010FC68 2D100000 */  daddu      $2, $0, $0
  .L0010FC6C:
    /* FC6C 0010FC6C 1000BFDF */  ld         $31, 0x10($29)
    /* FC70 0010FC70 0000B07B */  lq         $16, 0x0($29)
    /* FC74 0010FC74 2000BD27 */  addiu      $29, $29, 0x20
    /* FC78 0010FC78 0800E003 */  jr         $31
    /* FC7C 0010FC7C 00000000 */   nop
.size func_0010fbd0, 0xb0
