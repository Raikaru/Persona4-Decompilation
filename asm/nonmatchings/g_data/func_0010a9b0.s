.section .text
.set noat
.set noreorder
glabel func_0010a9b0
    /* A9B0 0010A9B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A9B4 0010A9B4 1000BFFF */  sd         $31, 0x10($29)
    /* A9B8 0010A9B8 0000B07F */  sq         $16, 0x0($29)
    /* A9BC 0010A9BC FFFF9030 */  andi       $16, $4, 0xFFFF
    /* A9C0 0010A9C0 01000224 */  addiu      $2, $0, 0x1
    /* A9C4 0010A9C4 04000212 */  beq        $16, $2, .L0010A9D8
    /* A9C8 0010A9C8 00000000 */   nop
    /* A9CC 0010A9CC 2D100000 */  daddu      $2, $0, $0
    /* A9D0 0010A9D0 24000010 */  b          .L0010AA64
    /* A9D4 0010A9D4 00000000 */   nop
  .L0010A9D8:
    /* A9D8 0010A9D8 08000216 */  bne        $16, $2, .L0010A9FC
    /* A9DC 0010A9DC 00000000 */   nop
    /* A9E0 0010A9E0 7900023C */  lui        $2, %hi(D_00797F88)
    /* A9E4 0010A9E4 887F4484 */  lh         $4, %lo(D_00797F88)($2)
    /* A9E8 0010A9E8 382B040C */  jal        func_0010ace0
    /* A9EC 0010A9EC 00000000 */   nop
    /* A9F0 0010A9F0 2D804000 */  daddu      $16, $2, $0
    /* A9F4 0010A9F4 11000010 */  b          .L0010AA3C
    /* A9F8 0010A9F8 00000000 */   nop
  .L0010A9FC:
    /* A9FC 0010A9FC 0B00022A */  slti       $2, $16, 0xB
    /* AA00 0010AA00 06004014 */  bnez       $2, .L0010AA1C
    /* AA04 0010AA04 00000000 */   nop
    /* AA08 0010AA08 5E00043C */  lui        $4, %hi(D_005E4318)
    /* AA0C 0010AA0C 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* AA10 0010AA10 A5030524 */  addiu      $5, $0, 0x3A5
    /* AA14 0010AA14 CCB5110C */  jal        func_0046d730
    /* AA18 0010AA18 00000000 */   nop
  .L0010AA1C:
    /* AA1C 0010AA1C FEFF0326 */  addiu      $3, $16, -0x2
    /* AA20 0010AA20 00110300 */  sll        $2, $3, 4
    /* AA24 0010AA24 21104300 */  addu       $2, $2, $3
    /* AA28 0010AA28 C0180200 */  sll        $3, $2, 3
    /* AA2C 0010AA2C 7900023C */  lui        $2, %hi(D_00796E50)
    /* AA30 0010AA30 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* AA34 0010AA34 21104300 */  addu       $2, $2, $3
    /* AA38 0010AA38 54005024 */  addiu      $16, $2, 0x54
  .L0010AA3C:
    /* AA3C 0010AA3C 06000016 */  bnez       $16, .L0010AA58
    /* AA40 0010AA40 00000000 */   nop
    /* AA44 0010AA44 5E00043C */  lui        $4, %hi(D_005E4318)
    /* AA48 0010AA48 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* AA4C 0010AA4C A9030524 */  addiu      $5, $0, 0x3A9
    /* AA50 0010AA50 CCB5110C */  jal        func_0046d730
    /* AA54 0010AA54 00000000 */   nop
  .L0010AA58:
    /* AA58 0010AA58 00000296 */  lhu        $2, 0x0($16)
    /* AA5C 0010AA5C 04004230 */  andi       $2, $2, 0x4
    /* AA60 0010AA60 2B100200 */  sltu       $2, $0, $2
  .L0010AA64:
    /* AA64 0010AA64 1000BFDF */  ld         $31, 0x10($29)
    /* AA68 0010AA68 0000B07B */  lq         $16, 0x0($29)
    /* AA6C 0010AA6C 2000BD27 */  addiu      $29, $29, 0x20
    /* AA70 0010AA70 0800E003 */  jr         $31
    /* AA74 0010AA74 00000000 */   nop
    /* AA78 0010AA78 00000000 */  nop
    /* AA7C 0010AA7C 00000000 */  nop
.size func_0010a9b0, 0xd0
