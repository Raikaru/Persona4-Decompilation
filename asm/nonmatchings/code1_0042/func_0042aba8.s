.section .text
.set noat
.set noreorder
glabel func_0042aba8
    /* 32ABA8 0042ABA8 90FFBD27 */  addiu      $29, $29, -0x70
    /* 32ABAC 0042ABAC 5000B4FF */  sd         $20, 0x50($29)
    /* 32ABB0 0042ABB0 4000B3FF */  sd         $19, 0x40($29)
    /* 32ABB4 0042ABB4 2DA0C000 */  daddu      $20, $6, $0
    /* 32ABB8 0042ABB8 3000B2FF */  sd         $18, 0x30($29)
    /* 32ABBC 0042ABBC 2D98E000 */  daddu      $19, $7, $0
    /* 32ABC0 0042ABC0 1000B0FF */  sd         $16, 0x10($29)
    /* 32ABC4 0042ABC4 2D90A000 */  daddu      $18, $5, $0
    /* 32ABC8 0042ABC8 6000BFFF */  sd         $31, 0x60($29)
    /* 32ABCC 0042ABCC 2D808000 */  daddu      $16, $4, $0
    /* 32ABD0 0042ABD0 5AA8100C */  jal        func_0042a168
    /* 32ABD4 0042ABD4 2000B1FF */   sd        $17, 0x20($29)
    /* 32ABD8 0042ABD8 2C004004 */  bltz       $2, .L0042AC8C
    /* 32ABDC 0042ABDC FFFF023C */   lui       $2, (0xFFFF0000 >> 16)
    /* 32ABE0 0042ABE0 9AA8100C */  jal        func_0042a268
    /* 32ABE4 0042ABE4 00000000 */   nop
    /* 32ABE8 0042ABE8 04004050 */  beql       $2, $0, .L0042ABFC
    /* 32ABEC 0042ABEC 8900023C */   lui       $2, %hi(D_00891148)
    /* 32ABF0 0042ABF0 FEFF023C */  lui        $2, (0xFFFEFFFC >> 16)
    /* 32ABF4 0042ABF4 25000010 */  b          .L0042AC8C
    /* 32ABF8 0042ABF8 FCFF4234 */   ori       $2, $2, (0xFFFEFFFC & 0xFFFF)
  .L0042ABFC:
    /* 32ABFC 0042ABFC 2D280002 */  daddu      $5, $16, $0
    /* 32AC00 0042AC00 48115124 */  addiu      $17, $2, %lo(D_00891148)
    /* 32AC04 0042AC04 FC000624 */  addiu      $6, $0, 0xFC
    /* 32AC08 0042AC08 2D202002 */  daddu      $4, $17, $0
    /* 32AC0C 0042AC0C 7A0B110C */  jal        func_00442de8
    /* 32AC10 0042AC10 F8FF3026 */   addiu     $16, $17, -0x8
    /* 32AC14 0042AC14 2D284002 */  daddu      $5, $18, $0
    /* 32AC18 0042AC18 030100A2 */  sb         $0, 0x103($16)
    /* 32AC1C 0042AC1C FC002426 */  addiu      $4, $17, 0xFC
    /* 32AC20 0042AC20 7A0B110C */  jal        func_00442de8
    /* 32AC24 0042AC24 FC000624 */   addiu     $6, $0, 0xFC
    /* 32AC28 0042AC28 8900043C */  lui        $4, %hi(D_00891340)
    /* 32AC2C 0042AC2C FF0100A2 */  sb         $0, 0x1FF($16)
    /* 32AC30 0042AC30 2D286002 */  daddu      $5, $19, $0
    /* 32AC34 0042AC34 40138424 */  addiu      $4, $4, %lo(D_00891340)
    /* 32AC38 0042AC38 0000A0AF */  sw         $0, 0x0($29)
    /* 32AC3C 0042AC3C 2D300000 */  daddu      $6, $0, $0
    /* 32AC40 0042AC40 2D380002 */  daddu      $7, $16, $0
    /* 32AC44 0042AC44 00020824 */  addiu      $8, $0, 0x200
    /* 32AC48 0042AC48 2D480002 */  daddu      $9, $16, $0
    /* 32AC4C 0042AC4C 10000A24 */  addiu      $10, $0, 0x10
    /* 32AC50 0042AC50 2C96100C */  jal        func_004258b0
    /* 32AC54 0042AC54 2D580000 */   daddu     $11, $0, $0
    /* 32AC58 0042AC58 04004304 */  bgezl      $2, .L0042AC6C
    /* 32AC5C 0042AC5C F8FF228E */   lw        $2, -0x8($17)
    /* 32AC60 0042AC60 FEFF023C */  lui        $2, (0xFFFEFFFF >> 16)
    /* 32AC64 0042AC64 09000010 */  b          .L0042AC8C
    /* 32AC68 0042AC68 FFFF4234 */   ori       $2, $2, (0xFFFEFFFF & 0xFFFF)
  .L0042AC6C:
    /* 32AC6C 0042AC6C 04004054 */  bnel       $2, $0, .L0042AC80
    /* 32AC70 0042AC70 000082AE */   sw        $2, 0x0($20)
    /* 32AC74 0042AC74 FEFF023C */  lui        $2, (0xFFFEFFFD >> 16)
    /* 32AC78 0042AC78 04000010 */  b          .L0042AC8C
    /* 32AC7C 0042AC7C FDFF4234 */   ori       $2, $2, (0xFFFEFFFD & 0xFFFF)
  .L0042AC80:
    /* 32AC80 0042AC80 2D100000 */  daddu      $2, $0, $0
    /* 32AC84 0042AC84 0400038E */  lw         $3, 0x4($16)
    /* 32AC88 0042AC88 040083AE */  sw         $3, 0x4($20)
  .L0042AC8C:
    /* 32AC8C 0042AC8C 6000BFDF */  ld         $31, 0x60($29)
    /* 32AC90 0042AC90 5000B4DF */  ld         $20, 0x50($29)
    /* 32AC94 0042AC94 4000B3DF */  ld         $19, 0x40($29)
    /* 32AC98 0042AC98 3000B2DF */  ld         $18, 0x30($29)
    /* 32AC9C 0042AC9C 2000B1DF */  ld         $17, 0x20($29)
    /* 32ACA0 0042ACA0 1000B0DF */  ld         $16, 0x10($29)
    /* 32ACA4 0042ACA4 0800E003 */  jr         $31
    /* 32ACA8 0042ACA8 7000BD27 */   addiu     $29, $29, 0x70
    /* 32ACAC 0042ACAC 00000000 */  nop
.size func_0042aba8, 0x108
