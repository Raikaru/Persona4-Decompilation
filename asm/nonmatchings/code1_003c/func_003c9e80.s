.section .text
.set noat
.set noreorder
glabel func_003c9e80
    /* 2C9E80 003C9E80 0400A010 */  beqz       $5, .L003C9E94
    /* 2C9E84 003C9E84 00000000 */   nop
  .L003C9E88:
    /* 2C9E88 003C9E88 680085AC */  sw         $5, 0x68($4)
    /* 2C9E8C 003C9E8C 04000010 */  b          .L003C9EA0
    /* 2C9E90 003C9E90 2D108000 */   daddu     $2, $4, $0
  .L003C9E94:
    /* 2C9E94 003C9E94 3D00053C */  lui        $5, %hi(func_003c9640)
    /* 2C9E98 003C9E98 FBFF0010 */  b          .L003C9E88
    /* 2C9E9C 003C9E9C 4096A524 */   addiu     $5, $5, %lo(func_003c9640)
  .L003C9EA0:
    /* 2C9EA0 003C9EA0 0800E003 */  jr         $31
    /* 2C9EA4 003C9EA4 00000000 */   nop
    /* 2C9EA8 003C9EA8 00000000 */  nop
    /* 2C9EAC 003C9EAC 00000000 */  nop
.size func_003c9e80, 0x30
