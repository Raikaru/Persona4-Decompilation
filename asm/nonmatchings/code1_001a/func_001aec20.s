.section .text
.set noat
.set noreorder
glabel func_001aec20
    /* AEC20 001AEC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AEC24 001AEC24 1000BFFF */  sd         $31, 0x10($29)
    /* AEC28 001AEC28 0000B07F */  sq         $16, 0x0($29)
    /* AEC2C 001AEC2C 2D808000 */  daddu      $16, $4, $0
    /* AEC30 001AEC30 38000426 */  addiu      $4, $16, 0x38
    /* AEC34 001AEC34 ECAC070C */  jal        func_001eb3b0
    /* AEC38 001AEC38 00000000 */   nop
    /* AEC3C 001AEC3C 2D200002 */  daddu      $4, $16, $0
    /* AEC40 001AEC40 98000526 */  addiu      $5, $16, 0x98
    /* AEC44 001AEC44 00010624 */  addiu      $6, $0, 0x100
    /* AEC48 001AEC48 2D380000 */  daddu      $7, $0, $0
    /* AEC4C 001AEC4C C45F070C */  jal        func_001d7f10
    /* AEC50 001AEC50 00000000 */   nop
    /* AEC54 001AEC54 2D200000 */  daddu      $4, $0, $0
    /* AEC58 001AEC58 08000010 */  b          .L001AEC7C
    /* AEC5C 001AEC5C 00000000 */   nop
  .L001AEC60:
    /* AEC60 001AEC60 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* AEC64 001AEC64 80100200 */  sll        $2, $2, 2
    /* AEC68 001AEC68 21180202 */  addu       $3, $16, $2
    /* AEC6C 001AEC6C 9800628C */  lw         $2, 0x98($3)
    /* AEC70 001AEC70 380062AC */  sw         $2, 0x38($3)
    /* AEC74 001AEC74 01008224 */  addiu      $2, $4, 0x1
    /* AEC78 001AEC78 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001AEC7C:
    /* AEC7C 001AEC7C D0000396 */  lhu        $3, 0xD0($16)
    /* AEC80 001AEC80 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* AEC84 001AEC84 2A104300 */  slt        $2, $2, $3
    /* AEC88 001AEC88 F5FF4014 */  bnez       $2, .L001AEC60
    /* AEC8C 001AEC8C 00000000 */   nop
    /* AEC90 001AEC90 6A0003A6 */  sh         $3, 0x6A($16)
    /* AEC94 001AEC94 02000224 */  addiu      $2, $0, 0x2
    /* AEC98 001AEC98 6C0002A6 */  sh         $2, 0x6C($16)
    /* AEC9C 001AEC9C 00010224 */  addiu      $2, $0, 0x100
    /* AECA0 001AECA0 6E0002A6 */  sh         $2, 0x6E($16)
    /* AECA4 001AECA4 2D200002 */  daddu      $4, $16, $0
    /* AECA8 001AECA8 3CC5070C */  jal        func_001f14f0
    /* AECAC 001AECAC 00000000 */   nop
    /* AECB0 001AECB0 2D300000 */  daddu      $6, $0, $0
    /* AECB4 001AECB4 2D280000 */  daddu      $5, $0, $0
    /* AECB8 001AECB8 6A000496 */  lhu        $4, 0x6A($16)
    /* AECBC 001AECBC 0C000010 */  b          .L001AECF0
    /* AECC0 001AECC0 00000000 */   nop
  .L001AECC4:
    /* AECC4 001AECC4 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* AECC8 001AECC8 80180300 */  sll        $3, $3, 2
    /* AECCC 001AECCC 21180302 */  addu       $3, $16, $3
    /* AECD0 001AECD0 3800638C */  lw         $3, 0x38($3)
    /* AECD4 001AECD4 E000638C */  lw         $3, 0xE0($3)
    /* AECD8 001AECD8 03006010 */  beqz       $3, .L001AECE8
    /* AECDC 001AECDC 00000000 */   nop
    /* AECE0 001AECE0 0100C324 */  addiu      $3, $6, 0x1
    /* AECE4 001AECE4 FFFF6630 */  andi       $6, $3, 0xFFFF
  .L001AECE8:
    /* AECE8 001AECE8 0100A324 */  addiu      $3, $5, 0x1
    /* AECEC 001AECEC FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001AECF0:
    /* AECF0 001AECF0 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* AECF4 001AECF4 2A186400 */  slt        $3, $3, $4
    /* AECF8 001AECF8 F2FF6014 */  bnez       $3, .L001AECC4
    /* AECFC 001AECFC 00000000 */   nop
    /* AED00 001AED00 FFFFC330 */  andi       $3, $6, 0xFFFF
    /* AED04 001AED04 05008314 */  bne        $4, $3, .L001AED1C
    /* AED08 001AED08 00000000 */   nop
    /* AED0C 001AED0C 02010324 */  addiu      $3, $0, 0x102
    /* AED10 001AED10 6E0003A6 */  sh         $3, 0x6E($16)
    /* AED14 001AED14 09000010 */  b          .L001AED3C
    /* AED18 001AED18 00000000 */   nop
  .L001AED1C:
    /* AED1C 001AED1C 05006010 */  beqz       $3, .L001AED34
    /* AED20 001AED20 00000000 */   nop
    /* AED24 001AED24 00010324 */  addiu      $3, $0, 0x100
    /* AED28 001AED28 6E0003A6 */  sh         $3, 0x6E($16)
    /* AED2C 001AED2C 03000010 */  b          .L001AED3C
    /* AED30 001AED30 00000000 */   nop
  .L001AED34:
    /* AED34 001AED34 01010324 */  addiu      $3, $0, 0x101
    /* AED38 001AED38 6E0003A6 */  sh         $3, 0x6E($16)
  .L001AED3C:
    /* AED3C 001AED3C 1000BFDF */  ld         $31, 0x10($29)
    /* AED40 001AED40 0000B07B */  lq         $16, 0x0($29)
    /* AED44 001AED44 2000BD27 */  addiu      $29, $29, 0x20
    /* AED48 001AED48 0800E003 */  jr         $31
    /* AED4C 001AED4C 00000000 */   nop
.size func_001aec20, 0x130
