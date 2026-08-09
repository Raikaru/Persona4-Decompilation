.section .text
.set noat
.set noreorder
glabel func_0019ab00
    /* 9AB00 0019AB00 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 9AB04 0019AB04 5000BFFF */  sd         $31, 0x50($29)
    /* 9AB08 0019AB08 4000B37F */  sq         $19, 0x40($29)
    /* 9AB0C 0019AB0C 3000B27F */  sq         $18, 0x30($29)
    /* 9AB10 0019AB10 2000B17F */  sq         $17, 0x20($29)
    /* 9AB14 0019AB14 1000B07F */  sq         $16, 0x10($29)
    /* 9AB18 0019AB18 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 9AB1C 0019AB1C 0C009094 */  lhu        $16, 0xC($4)
    /* 9AB20 0019AB20 080094C4 */  lwc1       $f20, 0x8($4)
    /* 9AB24 0019AB24 04009194 */  lhu        $17, 0x4($4)
    /* 9AB28 0019AB28 0000928C */  lw         $18, 0x0($4)
    /* 9AB2C 0019AB2C 9800428E */  lw         $2, 0x98($18)
    /* 9AB30 0019AB30 02004230 */  andi       $2, $2, 0x2
    /* 9AB34 0019AB34 2D004010 */  beqz       $2, .L0019ABEC
    /* 9AB38 0019AB38 00000000 */   nop
    /* 9AB3C 0019AB3C 2D204002 */  daddu      $4, $18, $0
    /* 9AB40 0019AB40 04000524 */  addiu      $5, $0, 0x4
    /* 9AB44 0019AB44 6476060C */  jal        func_0019d990
    /* 9AB48 0019AB48 00000000 */   nop
    /* 9AB4C 0019AB4C 9800428E */  lw         $2, 0x98($18)
    /* 9AB50 0019AB50 02004230 */  andi       $2, $2, 0x2
    /* 9AB54 0019AB54 0C004010 */  beqz       $2, .L0019AB88
    /* 9AB58 0019AB58 00000000 */   nop
    /* 9AB5C 0019AB5C 000A448E */  lw         $4, 0xA00($18)
    /* 9AB60 0019AB60 2D280000 */  daddu      $5, $0, $0
    /* 9AB64 0019AB64 20E8110C */  jal        func_0047a080
    /* 9AB68 0019AB68 00000000 */   nop
    /* 9AB6C 0019AB6C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 9AB70 0019AB70 00000244 */  mfc1       $2, $f0
    /* 9AB74 0019AB74 00000000 */  nop
    /* 9AB78 0019AB78 3C140200 */  dsll32     $2, $2, 16
    /* 9AB7C 0019AB7C 3F140200 */  dsra32     $2, $2, 16
    /* 9AB80 0019AB80 02000010 */  b          .L0019AB8C
    /* 9AB84 0019AB84 00000000 */   nop
  .L0019AB88:
    /* 9AB88 0019AB88 2D100000 */  daddu      $2, $0, $0
  .L0019AB8C:
    /* 9AB8C 0019AB8C 3C9C0200 */  dsll32     $19, $2, 16
    /* 9AB90 0019AB90 3F9C1300 */  dsra32     $19, $19, 16
    /* 9AB94 0019AB94 DA094586 */  lh         $5, 0x9DA($18)
    /* 9AB98 0019AB98 2D204002 */  daddu      $4, $18, $0
    /* 9AB9C 0019AB9C 2D302002 */  daddu      $6, $17, $0
    /* 9ABA0 0019ABA0 06A30046 */  mov.s      $f12, $f20
    /* 9ABA4 0019ABA4 2D380002 */  daddu      $7, $16, $0
    /* 9ABA8 0019ABA8 4862060C */  jal        func_00198920
    /* 9ABAC 0019ABAC 00000000 */   nop
    /* 9ABB0 0019ABB0 9800428E */  lw         $2, 0x98($18)
    /* 9ABB4 0019ABB4 02004230 */  andi       $2, $2, 0x2
    /* 9ABB8 0019ABB8 08004010 */  beqz       $2, .L0019ABDC
    /* 9ABBC 0019ABBC 00000000 */   nop
    /* 9ABC0 0019ABC0 00009344 */  mtc1       $19, $f0
    /* 9ABC4 0019ABC4 00000000 */  nop
    /* 9ABC8 0019ABC8 20038046 */  cvt.s.w    $f12, $f0
    /* 9ABCC 0019ABCC 000A448E */  lw         $4, 0xA00($18)
    /* 9ABD0 0019ABD0 2D280000 */  daddu      $5, $0, $0
    /* 9ABD4 0019ABD4 98E7110C */  jal        func_00479e60
    /* 9ABD8 0019ABD8 00000000 */   nop
  .L0019ABDC:
    /* 9ABDC 0019ABDC 2D204002 */  daddu      $4, $18, $0
    /* 9ABE0 0019ABE0 04000524 */  addiu      $5, $0, 0x4
    /* 9ABE4 0019ABE4 E875060C */  jal        func_0019d7a0
    /* 9ABE8 0019ABE8 00000000 */   nop
  .L0019ABEC:
    /* 9ABEC 0019ABEC 01000224 */  addiu      $2, $0, 0x1
    /* 9ABF0 0019ABF0 5000BFDF */  ld         $31, 0x50($29)
    /* 9ABF4 0019ABF4 4000B37B */  lq         $19, 0x40($29)
    /* 9ABF8 0019ABF8 3000B27B */  lq         $18, 0x30($29)
    /* 9ABFC 0019ABFC 2000B17B */  lq         $17, 0x20($29)
    /* 9AC00 0019AC00 1000B07B */  lq         $16, 0x10($29)
    /* 9AC04 0019AC04 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 9AC08 0019AC08 6000BD27 */  addiu      $29, $29, 0x60
    /* 9AC0C 0019AC0C 0800E003 */  jr         $31
    /* 9AC10 0019AC10 00000000 */   nop
    /* 9AC14 0019AC14 00000000 */  nop
    /* 9AC18 0019AC18 00000000 */  nop
    /* 9AC1C 0019AC1C 00000000 */  nop
.size func_0019ab00, 0x120
