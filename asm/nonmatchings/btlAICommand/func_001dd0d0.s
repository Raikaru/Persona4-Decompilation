.section .text
.set noat
.set noreorder
glabel func_001dd0d0
    /* DD0D0 001DD0D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DD0D4 001DD0D4 1000BFFF */  sd         $31, 0x10($29)
    /* DD0D8 001DD0D8 0000B07F */  sq         $16, 0x0($29)
    /* DD0DC 001DD0DC 2D808000 */  daddu      $16, $4, $0
    /* DD0E0 001DD0E0 98000526 */  addiu      $5, $16, 0x98
    /* DD0E4 001DD0E4 6E008694 */  lhu        $6, 0x6E($4)
    /* DD0E8 001DD0E8 2D380000 */  daddu      $7, $0, $0
    /* DD0EC 001DD0EC C45F070C */  jal        func_001d7f10
    /* DD0F0 001DD0F0 00000000 */   nop
    /* DD0F4 001DD0F4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DD0F8 001DD0F8 14004010 */  beqz       $2, .L001DD14C
    /* DD0FC 001DD0FC 00000000 */   nop
    /* DD100 001DD100 2D200000 */  daddu      $4, $0, $0
    /* DD104 001DD104 08000010 */  b          .L001DD128
    /* DD108 001DD108 00000000 */   nop
  .L001DD10C:
    /* DD10C 001DD10C FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DD110 001DD110 80100200 */  sll        $2, $2, 2
    /* DD114 001DD114 21180202 */  addu       $3, $16, $2
    /* DD118 001DD118 9800628C */  lw         $2, 0x98($3)
    /* DD11C 001DD11C 380062AC */  sw         $2, 0x38($3)
    /* DD120 001DD120 01008224 */  addiu      $2, $4, 0x1
    /* DD124 001DD124 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DD128:
    /* DD128 001DD128 D0000396 */  lhu        $3, 0xD0($16)
    /* DD12C 001DD12C FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DD130 001DD130 2A104300 */  slt        $2, $2, $3
    /* DD134 001DD134 F5FF4014 */  bnez       $2, .L001DD10C
    /* DD138 001DD138 00000000 */   nop
    /* DD13C 001DD13C 6A0003A6 */  sh         $3, 0x6A($16)
    /* DD140 001DD140 01000224 */  addiu      $2, $0, 0x1
    /* DD144 001DD144 19000010 */  b          .L001DD1AC
    /* DD148 001DD148 00000000 */   nop
  .L001DD14C:
    /* DD14C 001DD14C 2D380000 */  daddu      $7, $0, $0
    /* DD150 001DD150 2D280000 */  daddu      $5, $0, $0
    /* DD154 001DD154 2D300000 */  daddu      $6, $0, $0
    /* DD158 001DD158 D0000496 */  lhu        $4, 0xD0($16)
    /* DD15C 001DD15C 0D000010 */  b          .L001DD194
    /* DD160 001DD160 00000000 */   nop
  .L001DD164:
    /* DD164 001DD164 80100600 */  sll        $2, $6, 2
    /* DD168 001DD168 21100202 */  addu       $2, $16, $2
    /* DD16C 001DD16C 9800438C */  lw         $3, 0x98($2)
    /* DD170 001DD170 3000628C */  lw         $2, 0x30($3)
    /* DD174 001DD174 640A428C */  lw         $2, 0xA64($2)
    /* DD178 001DD178 08004294 */  lhu        $2, 0x8($2)
    /* DD17C 001DD17C 2B08A200 */  sltu       $1, $5, $2
    /* DD180 001DD180 03002010 */  beqz       $1, .L001DD190
    /* DD184 001DD184 00000000 */   nop
    /* DD188 001DD188 2D386000 */  daddu      $7, $3, $0
    /* DD18C 001DD18C 2D284000 */  daddu      $5, $2, $0
  .L001DD190:
    /* DD190 001DD190 0100C624 */  addiu      $6, $6, 0x1
  .L001DD194:
    /* DD194 001DD194 2B10C400 */  sltu       $2, $6, $4
    /* DD198 001DD198 F2FF4014 */  bnez       $2, .L001DD164
    /* DD19C 001DD19C 00000000 */   nop
    /* DD1A0 001DD1A0 380007AE */  sw         $7, 0x38($16)
    /* DD1A4 001DD1A4 01000224 */  addiu      $2, $0, 0x1
    /* DD1A8 001DD1A8 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DD1AC:
    /* DD1AC 001DD1AC 1000BFDF */  ld         $31, 0x10($29)
    /* DD1B0 001DD1B0 0000B07B */  lq         $16, 0x0($29)
    /* DD1B4 001DD1B4 2000BD27 */  addiu      $29, $29, 0x20
    /* DD1B8 001DD1B8 0800E003 */  jr         $31
    /* DD1BC 001DD1BC 00000000 */   nop
.size func_001dd0d0, 0xf0
