.section .text
.set noat
.set noreorder
glabel func_0052aae0
    /* 42AAE0 0052AAE0 0F000524 */  addiu      $5, $0, 0xF
    /* 42AAE4 0052AAE4 0F008224 */  addiu      $2, $4, 0xF
  .L0052AAE8:
    /* 42AAE8 0052AAE8 FFFFA524 */  addiu      $5, $5, -0x1
    /* 42AAEC 0052AAEC 000040A0 */  sb         $0, 0x0($2)
    /* 42AAF0 0052AAF0 00000000 */  nop
    /* 42AAF4 0052AAF4 00000000 */  nop
    /* 42AAF8 0052AAF8 00000000 */  nop
    /* 42AAFC 0052AAFC FAFFA104 */  bgez       $5, .L0052AAE8
    /* 42AB00 0052AB00 FFFF4224 */   addiu     $2, $2, -0x1
    /* 42AB04 0052AB04 143F013C */  lui        $1, (0x3F14FDF3 >> 16)
    /* 42AB08 0052AB08 F3FD2134 */  ori        $1, $1, (0x3F14FDF3 & 0xFFFF)
    /* 42AB0C 0052AB0C 00108144 */  mtc1       $1, $f2
    /* 42AB10 0052AB10 10000524 */  addiu      $5, $0, 0x10
    /* 42AB14 0052AB14 004F013C */  lui        $1, (0x4F000000 >> 16)
    /* 42AB18 0052AB18 00088144 */  mtc1       $1, $f1
    /* 42AB1C 0052AB1C 0080073C */  lui        $7, (0x80000000 >> 16)
  .L0052AB20:
    /* 42AB20 0052AB20 F0FFA224 */  addiu      $2, $5, -0x10
    /* 42AB24 0052AB24 21308500 */  addu       $6, $4, $5
    /* 42AB28 0052AB28 00008244 */  mtc1       $2, $f0
    /* 42AB2C 0052AB2C 20008046 */  cvt.s.w    $f0, $f0
    /* 42AB30 0052AB30 0100A524 */  addiu      $5, $5, 0x1
    /* 42AB34 0052AB34 02000246 */  mul.s      $f0, $f0, $f2
    /* 42AB38 0052AB38 36080046 */  c.le.s     $f1, $f0
    /* 42AB3C 0052AB3C E4000046 */  .word      0x460000E4                    # cvt.w.s    $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 42AB40 0052AB40 00180244 */  mfc1       $2, $f3
    /* 42AB44 0052AB44 05000045 */  bc1f       .L0052AB5C
    /* 42AB48 0052AB48 EC00A328 */   slti      $3, $5, 0xEC
    /* 42AB4C 0052AB4C 01000146 */  sub.s      $f0, $f0, $f1
    /* 42AB50 0052AB50 E4000046 */  .word      0x460000E4                    # cvt.w.s    $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 42AB54 0052AB54 00180244 */  mfc1       $2, $f3
    /* 42AB58 0052AB58 25104700 */  or         $2, $2, $7
  .L0052AB5C:
    /* 42AB5C 0052AB5C F0FF6014 */  bnez       $3, .L0052AB20
    /* 42AB60 0052AB60 0000C2A0 */   sb        $2, 0x0($6)
    /* 42AB64 0052AB64 EC000524 */  addiu      $5, $0, 0xEC
    /* 42AB68 0052AB68 80FF0624 */  addiu      $6, $0, -0x80
    /* 42AB6C 0052AB6C 00000000 */  nop
  .L0052AB70:
    /* 42AB70 0052AB70 21188500 */  addu       $3, $4, $5
    /* 42AB74 0052AB74 0100A524 */  addiu      $5, $5, 0x1
    /* 42AB78 0052AB78 0001A228 */  slti       $2, $5, 0x100
    /* 42AB7C 0052AB7C 00000000 */  nop
    /* 42AB80 0052AB80 00000000 */  nop
    /* 42AB84 0052AB84 FAFF4014 */  bnez       $2, .L0052AB70
    /* 42AB88 0052AB88 000066A0 */   sb        $6, 0x0($3)
    /* 42AB8C 0052AB8C 0800E003 */  jr         $31
    /* 42AB90 0052AB90 00000000 */   nop
    /* 42AB94 0052AB94 00000000 */  nop
.size func_0052aae0, 0xb8
