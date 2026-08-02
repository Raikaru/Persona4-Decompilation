.section .text
.set noat
.set noreorder
glabel func_0047aa30
    /* 37AA30 0047AA30 FC0285AC */  sw         $5, 0x2FC($4)
    /* 37AA34 0047AA34 2D380000 */  daddu      $7, $0, $0
    /* 37AA38 0047AA38 10000010 */  b          .L0047AA7C
    /* 37AA3C 0047AA3C 00000000 */   nop
  .L0047AA40:
    /* 37AA40 0047AA40 FFFFE630 */  andi       $6, $7, 0xFFFF
    /* 37AA44 0047AA44 40180600 */  sll        $3, $6, 1
    /* 37AA48 0047AA48 21186600 */  addu       $3, $3, $6
    /* 37AA4C 0047AA4C 80180300 */  sll        $3, $3, 2
    /* 37AA50 0047AA50 21308300 */  addu       $6, $4, $3
    /* 37AA54 0047AA54 8C02C390 */  lbu        $3, 0x28C($6)
    /* 37AA58 0047AA58 01006330 */  andi       $3, $3, 0x1
    /* 37AA5C 0047AA5C 05006010 */  beqz       $3, .L0047AA74
    /* 37AA60 0047AA60 00000000 */   nop
    /* 37AA64 0047AA64 9002C38C */  lw         $3, 0x290($6)
    /* 37AA68 0047AA68 02006010 */  beqz       $3, .L0047AA74
    /* 37AA6C 0047AA6C 00000000 */   nop
    /* 37AA70 0047AA70 FC0265AC */  sw         $5, 0x2FC($3)
  .L0047AA74:
    /* 37AA74 0047AA74 0100E324 */  addiu      $3, $7, 0x1
    /* 37AA78 0047AA78 FFFF6730 */  andi       $7, $3, 0xFFFF
  .L0047AA7C:
    /* 37AA7C 0047AA7C FFFFE330 */  andi       $3, $7, 0xFFFF
    /* 37AA80 0047AA80 05006328 */  slti       $3, $3, 0x5
    /* 37AA84 0047AA84 EEFF6014 */  bnez       $3, .L0047AA40
    /* 37AA88 0047AA88 00000000 */   nop
    /* 37AA8C 0047AA8C 0800E003 */  jr         $31
    /* 37AA90 0047AA90 00000000 */   nop
    /* 37AA94 0047AA94 00000000 */  nop
    /* 37AA98 0047AA98 00000000 */  nop
    /* 37AA9C 0047AA9C 00000000 */  nop
.size func_0047aa30, 0x70
