.section .text
.set noat
.set noreorder
glabel func_0047aaa0
    /* 37AAA0 0047AAA0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 37AAA4 0047AAA4 5000BFFF */  sd         $31, 0x50($29)
    /* 37AAA8 0047AAA8 4000B47F */  sq         $20, 0x40($29)
    /* 37AAAC 0047AAAC 3000B37F */  sq         $19, 0x30($29)
    /* 37AAB0 0047AAB0 2000B27F */  sq         $18, 0x20($29)
    /* 37AAB4 0047AAB4 1000B17F */  sq         $17, 0x10($29)
    /* 37AAB8 0047AAB8 0000B07F */  sq         $16, 0x0($29)
    /* 37AABC 0047AABC 2D988000 */  daddu      $19, $4, $0
    /* 37AAC0 0047AAC0 2D90A000 */  daddu      $18, $5, $0
    /* 37AAC4 0047AAC4 2D880001 */  daddu      $17, $8, $0
    /* 37AAC8 0047AAC8 2DA02001 */  daddu      $20, $9, $0
    /* 37AACC 0047AACC 2D20C000 */  daddu      $4, $6, $0
    /* 37AAD0 0047AAD0 2D28E000 */  daddu      $5, $7, $0
    /* 37AAD4 0047AAD4 6CDE110C */  jal        func_004779b0
    /* 37AAD8 0047AAD8 00000000 */   nop
    /* 37AADC 0047AADC 2D804000 */  daddu      $16, $2, $0
    /* 37AAE0 0047AAE0 01008232 */  andi       $2, $20, 0x1
    /* 37AAE4 0047AAE4 04004010 */  beqz       $2, .L0047AAF8
    /* 37AAE8 0047AAE8 00000000 */   nop
    /* 37AAEC 0047AAEC D800028E */  lw         $2, 0xD8($16)
    /* 37AAF0 0047AAF0 00404234 */  ori        $2, $2, 0x4000
    /* 37AAF4 0047AAF4 D80002AE */  sw         $2, 0xD8($16)
  .L0047AAF8:
    /* 37AAF8 0047AAF8 2D200002 */  daddu      $4, $16, $0
    /* 37AAFC 0047AAFC D8EB110C */  jal        func_0047af60
    /* 37AB00 0047AB00 00000000 */   nop
    /* 37AB04 0047AB04 2D200002 */  daddu      $4, $16, $0
    /* 37AB08 0047AB08 2D282002 */  daddu      $5, $17, $0
    /* 37AB0C 0047AB0C FCEB110C */  jal        func_0047aff0
    /* 37AB10 0047AB10 00000000 */   nop
    /* 37AB14 0047AB14 2D200002 */  daddu      $4, $16, $0
    /* 37AB18 0047AB18 ACE0110C */  jal        func_004782b0
    /* 37AB1C 0047AB1C 00000000 */   nop
    /* 37AB20 0047AB20 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* 37AB24 0047AB24 40180400 */  sll        $3, $4, 1
    /* 37AB28 0047AB28 21186400 */  addu       $3, $3, $4
    /* 37AB2C 0047AB2C 80180300 */  sll        $3, $3, 2
    /* 37AB30 0047AB30 21287300 */  addu       $5, $3, $19
    /* 37AB34 0047AB34 9002B0AC */  sw         $16, 0x290($5)
    /* 37AB38 0047AB38 D800038E */  lw         $3, 0xD8($16)
    /* 37AB3C 0047AB3C 04006334 */  ori        $3, $3, 0x4
    /* 37AB40 0047AB40 D80003AE */  sw         $3, 0xD8($16)
    /* 37AB44 0047AB44 9002A48C */  lw         $4, 0x290($5)
    /* 37AB48 0047AB48 D800838C */  lw         $3, 0xD8($4)
    /* 37AB4C 0047AB4C 00806334 */  ori        $3, $3, 0x8000
    /* 37AB50 0047AB50 D80083AC */  sw         $3, 0xD8($4)
    /* 37AB54 0047AB54 8C02A390 */  lbu        $3, 0x28C($5)
    /* 37AB58 0047AB58 01006334 */  ori        $3, $3, 0x1
    /* 37AB5C 0047AB5C 8C02A3A0 */  sb         $3, 0x28C($5)
    /* 37AB60 0047AB60 5000BFDF */  ld         $31, 0x50($29)
    /* 37AB64 0047AB64 4000B47B */  lq         $20, 0x40($29)
    /* 37AB68 0047AB68 3000B37B */  lq         $19, 0x30($29)
    /* 37AB6C 0047AB6C 2000B27B */  lq         $18, 0x20($29)
    /* 37AB70 0047AB70 1000B17B */  lq         $17, 0x10($29)
    /* 37AB74 0047AB74 0000B07B */  lq         $16, 0x0($29)
    /* 37AB78 0047AB78 6000BD27 */  addiu      $29, $29, 0x60
    /* 37AB7C 0047AB7C 0800E003 */  jr         $31
    /* 37AB80 0047AB80 00000000 */   nop
    /* 37AB84 0047AB84 00000000 */  nop
    /* 37AB88 0047AB88 00000000 */  nop
    /* 37AB8C 0047AB8C 00000000 */  nop
.size func_0047aaa0, 0xf0
