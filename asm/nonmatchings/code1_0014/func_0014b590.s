.section .text
.set noat
.set noreorder
glabel func_0014b590
    /* 4B590 0014B590 24600046 */  .word      0x46006024                    # cvt.w.s    $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4B594 0014B594 00000344 */  mfc1       $3, $f0
    /* 4B598 0014B598 20008046 */  cvt.s.w    $f0, $f0
    /* 4B59C 0014B59C 81600046 */  sub.s      $f2, $f12, $f0
    /* 4B5A0 0014B5A0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 4B5A4 0014B5A4 00088244 */  mtc1       $2, $f1
    /* 4B5A8 0014B5A8 00000000 */  nop
    /* 4B5AC 0014B5AC 34100146 */  c.lt.s     $f2, $f1
    /* 4B5B0 0014B5B0 05000145 */  bc1t       .L0014B5C8
    /* 4B5B4 0014B5B4 00000000 */   nop
    /* 4B5B8 0014B5B8 01006224 */  addiu      $2, $3, 0x1
    /* 4B5BC 0014B5BC 00008244 */  mtc1       $2, $f0
    /* 4B5C0 0014B5C0 00000000 */  nop
    /* 4B5C4 0014B5C4 20008046 */  cvt.s.w    $f0, $f0
  .L0014B5C8:
    /* 4B5C8 0014B5C8 0800E003 */  jr         $31
    /* 4B5CC 0014B5CC 00000000 */   nop
.size func_0014b590, 0x40
