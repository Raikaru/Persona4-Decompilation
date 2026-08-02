.section .text
.set noat
.set noreorder
glabel func_0035dd40
    /* 25DD40 0035DD40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 25DD44 0035DD44 2000BFFF */  sd         $31, 0x20($29)
    /* 25DD48 0035DD48 1000B17F */  sq         $17, 0x10($29)
    /* 25DD4C 0035DD4C 0000B07F */  sq         $16, 0x0($29)
    /* 25DD50 0035DD50 2D888000 */  daddu      $17, $4, $0
    /* 25DD54 0035DD54 04008390 */  lbu        $3, 0x4($4)
    /* 25DD58 0035DD58 02006334 */  ori        $3, $3, 0x2
    /* 25DD5C 0035DD5C 040083A0 */  sb         $3, 0x4($4)
    /* 25DD60 0035DD60 2D800000 */  daddu      $16, $0, $0
    /* 25DD64 0035DD64 17000010 */  b          .L0035DDC4
    /* 25DD68 0035DD68 00000000 */   nop
  .L0035DD6C:
    /* 25DD6C 0035DD6C 80181000 */  sll        $3, $16, 2
    /* 25DD70 0035DD70 21102302 */  addu       $2, $17, $3
    /* 25DD74 0035DD74 4800428C */  lw         $2, 0x48($2)
    /* 25DD78 0035DD78 0A004010 */  beqz       $2, .L0035DDA4
    /* 25DD7C 0035DD7C 00000000 */   nop
    /* 25DD80 0035DD80 6500023C */  lui        $2, %hi(D_0064D3A0)
    /* 25DD84 0035DD84 A0D34224 */  addiu      $2, $2, %lo(D_0064D3A0)
    /* 25DD88 0035DD88 21104300 */  addu       $2, $2, $3
    /* 25DD8C 0035DD8C 0000448C */  lw         $4, 0x0($2)
    /* 25DD90 0035DD90 01000524 */  addiu      $5, $0, 0x1
    /* 25DD94 0035DD94 E418040C */  jal        func_00106390
    /* 25DD98 0035DD98 00000000 */   nop
    /* 25DD9C 0035DD9C 08000010 */  b          .L0035DDC0
    /* 25DDA0 0035DDA0 00000000 */   nop
  .L0035DDA4:
    /* 25DDA4 0035DDA4 6500023C */  lui        $2, %hi(D_0064D3A0)
    /* 25DDA8 0035DDA8 A0D34224 */  addiu      $2, $2, %lo(D_0064D3A0)
    /* 25DDAC 0035DDAC 21104300 */  addu       $2, $2, $3
    /* 25DDB0 0035DDB0 0000448C */  lw         $4, 0x0($2)
    /* 25DDB4 0035DDB4 2D280000 */  daddu      $5, $0, $0
    /* 25DDB8 0035DDB8 E418040C */  jal        func_00106390
    /* 25DDBC 0035DDBC 00000000 */   nop
  .L0035DDC0:
    /* 25DDC0 0035DDC0 01001026 */  addiu      $16, $16, 0x1
  .L0035DDC4:
    /* 25DDC4 0035DDC4 0600032A */  slti       $3, $16, 0x6
    /* 25DDC8 0035DDC8 E8FF6014 */  bnez       $3, .L0035DD6C
    /* 25DDCC 0035DDCC 00000000 */   nop
    /* 25DDD0 0035DDD0 2000BFDF */  ld         $31, 0x20($29)
    /* 25DDD4 0035DDD4 1000B17B */  lq         $17, 0x10($29)
    /* 25DDD8 0035DDD8 0000B07B */  lq         $16, 0x0($29)
    /* 25DDDC 0035DDDC 3000BD27 */  addiu      $29, $29, 0x30
    /* 25DDE0 0035DDE0 0800E003 */  jr         $31
    /* 25DDE4 0035DDE4 00000000 */   nop
    /* 25DDE8 0035DDE8 00000000 */  nop
    /* 25DDEC 0035DDEC 00000000 */  nop
.size func_0035dd40, 0xb0
