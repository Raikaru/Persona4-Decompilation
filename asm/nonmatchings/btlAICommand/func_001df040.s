.section .text
.set noat
.set noreorder
glabel func_001df040
    /* DF040 001DF040 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF044 001DF044 1000BFFF */  sd         $31, 0x10($29)
    /* DF048 001DF048 0000B07F */  sq         $16, 0x0($29)
    /* DF04C 001DF04C 14740A0C */  jal        func_0029d050
    /* DF050 001DF050 00000000 */   nop
    /* DF054 001DF054 2D804000 */  daddu      $16, $2, $0
    /* DF058 001DF058 2D200000 */  daddu      $4, $0, $0
    /* DF05C 001DF05C 00730A0C */  jal        func_0029cc00
    /* DF060 001DF060 00000000 */   nop
    /* DF064 001DF064 0A004004 */  bltz       $2, .L001DF090
    /* DF068 001DF068 00000000 */   nop
    /* DF06C 001DF06C 03000324 */  addiu      $3, $0, 0x3
    /* DF070 001DF070 6C0003A6 */  sh         $3, 0x6C($16)
    /* DF074 001DF074 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* DF078 001DF078 700002A6 */  sh         $2, 0x70($16)
    /* DF07C 001DF07C 480E090C */  jal        func_00243920
    /* DF080 001DF080 00000000 */   nop
    /* DF084 001DF084 6E0002A6 */  sh         $2, 0x6E($16)
    /* DF088 001DF088 06000010 */  b          .L001DF0A4
    /* DF08C 001DF08C 00000000 */   nop
  .L001DF090:
    /* DF090 001DF090 2D200002 */  daddu      $4, $16, $0
    /* DF094 001DF094 38000526 */  addiu      $5, $16, 0x38
    /* DF098 001DF098 02800634 */  ori        $6, $0, 0x8002
    /* DF09C 001DF09C 9079070C */  jal        func_001de640
    /* DF0A0 001DF0A0 00000000 */   nop
  .L001DF0A4:
    /* DF0A4 001DF0A4 01000224 */  addiu      $2, $0, 0x1
    /* DF0A8 001DF0A8 1000BFDF */  ld         $31, 0x10($29)
    /* DF0AC 001DF0AC 0000B07B */  lq         $16, 0x0($29)
    /* DF0B0 001DF0B0 2000BD27 */  addiu      $29, $29, 0x20
    /* DF0B4 001DF0B4 0800E003 */  jr         $31
    /* DF0B8 001DF0B8 00000000 */   nop
    /* DF0BC 001DF0BC 00000000 */  nop
.size func_001df040, 0x80
