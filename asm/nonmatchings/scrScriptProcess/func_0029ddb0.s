.section .text
.set noat
.set noreorder
glabel func_0029ddb0
    /* 19DDB0 0029DDB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 19DDB4 0029DDB4 0000BFFF */  sd         $31, 0x0($29)
    /* 19DDB8 0029DDB8 6400043C */  lui        $4, %hi(D_0063E5B8)
    /* 19DDBC 0029DDBC B8E58424 */  addiu      $4, $4, %lo(D_0063E5B8)
    /* 19DDC0 0029DDC0 14B5858F */  lw         $5, -0x4AEC($28)
    /* 19DDC4 0029DDC4 DA02110C */  jal        func_00440b68
    /* 19DDC8 0029DDC8 00000000 */   nop
    /* 19DDCC 0029DDCC 18B5828F */  lw         $2, -0x4AE8($28)
    /* 19DDD0 0029DDD0 02000010 */  b          .L0029DDDC
    /* 19DDD4 0029DDD4 00000000 */   nop
  .L0029DDD8:
    /* 19DDD8 0029DDD8 5001428C */  lw         $2, 0x150($2)
  .L0029DDDC:
    /* 19DDDC 0029DDDC 00000000 */  nop
    /* 19DDE0 0029DDE0 00000000 */  nop
    /* 19DDE4 0029DDE4 00000000 */  nop
    /* 19DDE8 0029DDE8 00000000 */  nop
    /* 19DDEC 0029DDEC FAFF4014 */  bnez       $2, .L0029DDD8
    /* 19DDF0 0029DDF0 00000000 */   nop
    /* 19DDF4 0029DDF4 6400043C */  lui        $4, %hi(D_0063E5C8)
    /* 19DDF8 0029DDF8 C8E58424 */  addiu      $4, $4, %lo(D_0063E5C8)
    /* 19DDFC 0029DDFC 14B5858F */  lw         $5, -0x4AEC($28)
    /* 19DE00 0029DE00 DA02110C */  jal        func_00440b68
    /* 19DE04 0029DE04 00000000 */   nop
    /* 19DE08 0029DE08 0000BFDF */  ld         $31, 0x0($29)
    /* 19DE0C 0029DE0C 1000BD27 */  addiu      $29, $29, 0x10
    /* 19DE10 0029DE10 0800E003 */  jr         $31
    /* 19DE14 0029DE14 00000000 */   nop
    /* 19DE18 0029DE18 00000000 */  nop
    /* 19DE1C 0029DE1C 00000000 */  nop
.size func_0029ddb0, 0x70
