.section .text
.set noat
.set noreorder
glabel func_0047ab90
    /* 37AB90 0047AB90 80FFBD27 */  addiu      $29, $29, -0x80
    /* 37AB94 0047AB94 6000BFFF */  sd         $31, 0x60($29)
    /* 37AB98 0047AB98 5000B57F */  sq         $21, 0x50($29)
    /* 37AB9C 0047AB9C 4000B47F */  sq         $20, 0x40($29)
    /* 37ABA0 0047ABA0 3000B37F */  sq         $19, 0x30($29)
    /* 37ABA4 0047ABA4 2000B27F */  sq         $18, 0x20($29)
    /* 37ABA8 0047ABA8 1000B17F */  sq         $17, 0x10($29)
    /* 37ABAC 0047ABAC 0000B07F */  sq         $16, 0x0($29)
    /* 37ABB0 0047ABB0 2DA08000 */  daddu      $20, $4, $0
    /* 37ABB4 0047ABB4 2D98A000 */  daddu      $19, $5, $0
    /* 37ABB8 0047ABB8 2D900001 */  daddu      $18, $8, $0
    /* 37ABBC 0047ABBC 2D882001 */  daddu      $17, $9, $0
    /* 37ABC0 0047ABC0 2DA84001 */  daddu      $21, $10, $0
    /* 37ABC4 0047ABC4 2D20C000 */  daddu      $4, $6, $0
    /* 37ABC8 0047ABC8 2D28E000 */  daddu      $5, $7, $0
    /* 37ABCC 0047ABCC 6CDE110C */  jal        func_004779b0
    /* 37ABD0 0047ABD0 00000000 */   nop
    /* 37ABD4 0047ABD4 2D804000 */  daddu      $16, $2, $0
    /* 37ABD8 0047ABD8 0100A232 */  andi       $2, $21, 0x1
    /* 37ABDC 0047ABDC 04004010 */  beqz       $2, .L0047ABF0
    /* 37ABE0 0047ABE0 00000000 */   nop
    /* 37ABE4 0047ABE4 D800028E */  lw         $2, 0xD8($16)
    /* 37ABE8 0047ABE8 00404234 */  ori        $2, $2, 0x4000
    /* 37ABEC 0047ABEC D80002AE */  sw         $2, 0xD8($16)
  .L0047ABF0:
    /* 37ABF0 0047ABF0 2D200002 */  daddu      $4, $16, $0
    /* 37ABF4 0047ABF4 D8EB110C */  jal        func_0047af60
    /* 37ABF8 0047ABF8 00000000 */   nop
    /* 37ABFC 0047ABFC 7800B2AF */  sw         $18, 0x78($29)
    /* 37AC00 0047AC00 7C00B1AF */  sw         $17, 0x7C($29)
    /* 37AC04 0047AC04 2D200002 */  daddu      $4, $16, $0
    /* 37AC08 0047AC08 7800A527 */  addiu      $5, $29, 0x78
    /* 37AC0C 0047AC0C F4EB110C */  jal        func_0047afd0
    /* 37AC10 0047AC10 00000000 */   nop
    /* 37AC14 0047AC14 2D200002 */  daddu      $4, $16, $0
    /* 37AC18 0047AC18 ACE0110C */  jal        func_004782b0
    /* 37AC1C 0047AC1C 00000000 */   nop
    /* 37AC20 0047AC20 FFFF6432 */  andi       $4, $19, 0xFFFF
    /* 37AC24 0047AC24 40180400 */  sll        $3, $4, 1
    /* 37AC28 0047AC28 21186400 */  addu       $3, $3, $4
    /* 37AC2C 0047AC2C 80180300 */  sll        $3, $3, 2
    /* 37AC30 0047AC30 21287400 */  addu       $5, $3, $20
    /* 37AC34 0047AC34 9002B0AC */  sw         $16, 0x290($5)
    /* 37AC38 0047AC38 D800038E */  lw         $3, 0xD8($16)
    /* 37AC3C 0047AC3C 04006334 */  ori        $3, $3, 0x4
    /* 37AC40 0047AC40 D80003AE */  sw         $3, 0xD8($16)
    /* 37AC44 0047AC44 9002A48C */  lw         $4, 0x290($5)
    /* 37AC48 0047AC48 D800838C */  lw         $3, 0xD8($4)
    /* 37AC4C 0047AC4C 00806334 */  ori        $3, $3, 0x8000
    /* 37AC50 0047AC50 D80083AC */  sw         $3, 0xD8($4)
    /* 37AC54 0047AC54 8C02A390 */  lbu        $3, 0x28C($5)
    /* 37AC58 0047AC58 01006334 */  ori        $3, $3, 0x1
    /* 37AC5C 0047AC5C 8C02A3A0 */  sb         $3, 0x28C($5)
    /* 37AC60 0047AC60 6000BFDF */  ld         $31, 0x60($29)
    /* 37AC64 0047AC64 5000B57B */  lq         $21, 0x50($29)
    /* 37AC68 0047AC68 4000B47B */  lq         $20, 0x40($29)
    /* 37AC6C 0047AC6C 3000B37B */  lq         $19, 0x30($29)
    /* 37AC70 0047AC70 2000B27B */  lq         $18, 0x20($29)
    /* 37AC74 0047AC74 1000B17B */  lq         $17, 0x10($29)
    /* 37AC78 0047AC78 0000B07B */  lq         $16, 0x0($29)
    /* 37AC7C 0047AC7C 8000BD27 */  addiu      $29, $29, 0x80
    /* 37AC80 0047AC80 0800E003 */  jr         $31
    /* 37AC84 0047AC84 00000000 */   nop
    /* 37AC88 0047AC88 00000000 */  nop
    /* 37AC8C 0047AC8C 00000000 */  nop
.size func_0047ab90, 0x100
