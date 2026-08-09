.section .text
.set noat
.set noreorder
glabel func_00527b08
    /* 427B08 00527B08 0100A05C */  bgtzl      $5, .L00527B10
    /* 427B0C 00527B0C 100085AC */   sw        $5, 0x10($4)
  .L00527B10:
    /* 427B10 00527B10 0800E003 */  jr         $31
    /* 427B14 00527B14 00000000 */   nop
.size func_00527b08, 0x10
