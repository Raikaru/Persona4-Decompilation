.section .text
.set noat
.set noreorder
glabel func_0027bec0
    /* 17BEC0 0027BEC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 17BEC4 0027BEC4 0000BFFF */  sd         $31, 0x0($29)
    /* 17BEC8 0027BEC8 44E0090C */  jal        func_00278110
    /* 17BECC 0027BECC 00000000 */   nop
    /* 17BED0 0027BED0 0800033C */  lui        $3, (0x80000 >> 16)
    /* 17BED4 0027BED4 24184300 */  and        $3, $2, $3
    /* 17BED8 0027BED8 05006010 */  beqz       $3, .L0027BEF0
    /* 17BEDC 0027BEDC 00000000 */   nop
    /* 17BEE0 0027BEE0 00034230 */  andi       $2, $2, 0x300
    /* 17BEE4 0027BEE4 00014128 */  slti       $1, $2, 0x100
    /* 17BEE8 0027BEE8 04002010 */  beqz       $1, .L0027BEFC
    /* 17BEEC 0027BEEC 00000000 */   nop
  .L0027BEF0:
    /* 17BEF0 0027BEF0 01000224 */  addiu      $2, $0, 0x1
    /* 17BEF4 0027BEF4 02000010 */  b          .L0027BF00
    /* 17BEF8 0027BEF8 00000000 */   nop
  .L0027BEFC:
    /* 17BEFC 0027BEFC 2D100000 */  daddu      $2, $0, $0
  .L0027BF00:
    /* 17BF00 0027BF00 0000BFDF */  ld         $31, 0x0($29)
    /* 17BF04 0027BF04 1000BD27 */  addiu      $29, $29, 0x10
    /* 17BF08 0027BF08 0800E003 */  jr         $31
    /* 17BF0C 0027BF0C 00000000 */   nop
.size func_0027bec0, 0x50
