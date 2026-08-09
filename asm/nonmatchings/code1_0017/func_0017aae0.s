.section .text
.set noat
.set noreorder
glabel func_0017aae0
    /* 7AAE0 0017AAE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 7AAE4 0017AAE4 1000BFFF */  sd         $31, 0x10($29)
    /* 7AAE8 0017AAE8 0000B07F */  sq         $16, 0x0($29)
    /* 7AAEC 0017AAEC 2D80A000 */  daddu      $16, $5, $0
    /* 7AAF0 0017AAF0 1000A48C */  lw         $4, 0x10($5)
    /* 7AAF4 0017AAF4 D800838C */  lw         $3, 0xD8($4)
    /* 7AAF8 0017AAF8 BFFF0224 */  addiu      $2, $0, -0x41
    /* 7AAFC 0017AAFC 24106200 */  and        $2, $3, $2
    /* 7AB00 0017AB00 D80082AC */  sw         $2, 0xD8($4)
    /* 7AB04 0017AB04 14000424 */  addiu      $4, $0, 0x14
    /* 7AB08 0017AB08 02000524 */  addiu      $5, $0, 0x2
    /* 7AB0C 0017AB0C 8800023C */  lui        $2, %hi(D_00887300)
    /* 7AB10 0017AB10 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 7AB14 0017AB14 09F84000 */  jalr       $2
    /* 7AB18 0017AB18 00000000 */   nop
    /* 7AB1C 0017AB1C 1000048E */  lw         $4, 0x10($16)
    /* 7AB20 0017AB20 BCE8110C */  jal        func_0047a2f0
    /* 7AB24 0017AB24 00000000 */   nop
    /* 7AB28 0017AB28 80000626 */  addiu      $6, $16, 0x80
    /* 7AB2C 0017AB2C 08000524 */  addiu      $5, $0, 0x8
  .L0017AB30:
    /* 7AB30 0017AB30 0000C48C */  lw         $4, 0x0($6)
    /* 7AB34 0017AB34 0400C38C */  lw         $3, 0x4($6)
    /* 7AB38 0017AB38 0800C624 */  addiu      $6, $6, 0x8
    /* 7AB3C 0017AB3C FFFFA524 */  addiu      $5, $5, -0x1
    /* 7AB40 0017AB40 000044AC */  sw         $4, 0x0($2)
    /* 7AB44 0017AB44 040043AC */  sw         $3, 0x4($2)
    /* 7AB48 0017AB48 08004224 */  addiu      $2, $2, 0x8
    /* 7AB4C 0017AB4C F8FFA01C */  bgtz       $5, .L0017AB30
    /* 7AB50 0017AB50 00000000 */   nop
    /* 7AB54 0017AB54 1000048E */  lw         $4, 0x10($16)
    /* 7AB58 0017AB58 D800838C */  lw         $3, 0xD8($4)
    /* 7AB5C 0017AB5C FBFF0224 */  addiu      $2, $0, -0x5
    /* 7AB60 0017AB60 24106200 */  and        $2, $3, $2
    /* 7AB64 0017AB64 D80082AC */  sw         $2, 0xD8($4)
    /* 7AB68 0017AB68 1000048E */  lw         $4, 0x10($16)
    /* 7AB6C 0017AB6C 70E2110C */  jal        func_004789c0
    /* 7AB70 0017AB70 00000000 */   nop
    /* 7AB74 0017AB74 1000048E */  lw         $4, 0x10($16)
    /* 7AB78 0017AB78 C8E8110C */  jal        func_0047a320
    /* 7AB7C 0017AB7C 00000000 */   nop
    /* 7AB80 0017AB80 2D280000 */  daddu      $5, $0, $0
    /* 7AB84 0017AB84 0A000010 */  b          .L0017ABB0
    /* 7AB88 0017AB88 00000000 */   nop
  .L0017AB8C:
    /* 7AB8C 0017AB8C 40180500 */  sll        $3, $5, 1
    /* 7AB90 0017AB90 21186500 */  addu       $3, $3, $5
    /* 7AB94 0017AB94 80200300 */  sll        $4, $3, 2
    /* 7AB98 0017AB98 1000038E */  lw         $3, 0x10($16)
    /* 7AB9C 0017AB9C 21206400 */  addu       $4, $3, $4
    /* 7ABA0 0017ABA0 8C028390 */  lbu        $3, 0x28C($4)
    /* 7ABA4 0017ABA4 01006334 */  ori        $3, $3, 0x1
    /* 7ABA8 0017ABA8 8C0283A0 */  sb         $3, 0x28C($4)
    /* 7ABAC 0017ABAC 0100A524 */  addiu      $5, $5, 0x1
  .L0017ABB0:
    /* 7ABB0 0017ABB0 0500A328 */  slti       $3, $5, 0x5
    /* 7ABB4 0017ABB4 F5FF6014 */  bnez       $3, .L0017AB8C
    /* 7ABB8 0017ABB8 00000000 */   nop
    /* 7ABBC 0017ABBC 1000BFDF */  ld         $31, 0x10($29)
    /* 7ABC0 0017ABC0 0000B07B */  lq         $16, 0x0($29)
    /* 7ABC4 0017ABC4 2000BD27 */  addiu      $29, $29, 0x20
    /* 7ABC8 0017ABC8 0800E003 */  jr         $31
    /* 7ABCC 0017ABCC 00000000 */   nop
.size func_0017aae0, 0xf0
