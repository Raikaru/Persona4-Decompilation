.section .text
.set noat
.set noreorder
glabel func_0022fa90
    /* 12FA90 0022FA90 ACB3868F */  lw         $6, -0x4C54($28)
    /* 12FA94 0022FA94 0C00C38C */  lw         $3, 0xC($6)
    /* 12FA98 0022FA98 2000023C */  lui        $2, (0x200000 >> 16)
    /* 12FA9C 0022FA9C 24106200 */  and        $2, $3, $2
    /* 12FAA0 0022FAA0 04004014 */  bnez       $2, .L0022FAB4
    /* 12FAA4 0022FAA4 00000000 */   nop
    /* 12FAA8 0022FAA8 01000224 */  addiu      $2, $0, 0x1
    /* 12FAAC 0022FAAC 16000010 */  b          .L0022FB08
    /* 12FAB0 0022FAB0 00000000 */   nop
  .L0022FAB4:
    /* 12FAB4 0022FAB4 1A008294 */  lhu        $2, 0x1A($4)
    /* 12FAB8 0022FAB8 01004230 */  andi       $2, $2, 0x1
    /* 12FABC 0022FABC 04004014 */  bnez       $2, .L0022FAD0
    /* 12FAC0 0022FAC0 00000000 */   nop
    /* 12FAC4 0022FAC4 01000224 */  addiu      $2, $0, 0x1
    /* 12FAC8 0022FAC8 0F000010 */  b          .L0022FB08
    /* 12FACC 0022FACC 00000000 */   nop
  .L0022FAD0:
    /* 12FAD0 0022FAD0 3000828C */  lw         $2, 0x30($4)
    /* 12FAD4 0022FAD4 A2004390 */  lbu        $3, 0xA2($2)
    /* 12FAD8 0022FAD8 01000224 */  addiu      $2, $0, 0x1
    /* 12FADC 0022FADC 03006210 */  beq        $3, $2, .L0022FAEC
    /* 12FAE0 0022FAE0 00000000 */   nop
    /* 12FAE4 0022FAE4 08000010 */  b          .L0022FB08
    /* 12FAE8 0022FAE8 00000000 */   nop
  .L0022FAEC:
    /* 12FAEC 0022FAEC 3C140500 */  dsll32     $2, $5, 16
    /* 12FAF0 0022FAF0 3F140200 */  dsra32     $2, $2, 16
    /* 12FAF4 0022FAF4 21104600 */  addu       $2, $2, $6
    /* 12FAF8 0022FAF8 100C4380 */  lb         $3, 0xC10($2)
    /* 12FAFC 0022FAFC FEFF0224 */  addiu      $2, $0, -0x2
    /* 12FB00 0022FB00 26106200 */  xor        $2, $3, $2
    /* 12FB04 0022FB04 2B100200 */  sltu       $2, $0, $2
  .L0022FB08:
    /* 12FB08 0022FB08 0800E003 */  jr         $31
    /* 12FB0C 0022FB0C 00000000 */   nop
.size func_0022fa90, 0x80
