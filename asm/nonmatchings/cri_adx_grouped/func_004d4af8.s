.section .text
.set noat
.set noreorder
glabel func_004d4af8
    /* 3D4AF8 004D4AF8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D4AFC 004D4AFC 2D28A003 */  daddu      $5, $29, $0
    /* 3D4B00 004D4B00 1000BFFF */  sd         $31, 0x10($29)
    /* 3D4B04 004D4B04 F251130C */  jal        func_004d47c8
    /* 3D4B08 004D4B08 0400A627 */   addiu     $6, $29, 0x4
    /* 3D4B0C 004D4B0C 0000A1C7 */  lwc1       $f1, 0x0($29)
    /* 3D4B10 004D4B10 60088046 */  cvt.s.w    $f1, $f1
    /* 3D4B14 004D4B14 C842013C */  lui        $1, (0x42C80000 >> 16)
    /* 3D4B18 004D4B18 00008144 */  mtc1       $1, $f0
    /* 3D4B1C 004D4B1C 0400A2C7 */  lwc1       $f2, 0x4($29)
    /* 3D4B20 004D4B20 A0108046 */  cvt.s.w    $f2, $f2
    /* 3D4B24 004D4B24 1000BFDF */  ld         $31, 0x10($29)
    /* 3D4B28 004D4B28 00000000 */  nop
    /* 3D4B2C 004D4B2C 00000000 */  nop
    /* 3D4B30 004D4B30 43080246 */  div.s      $f1, $f1, $f2
    /* 3D4B34 004D4B34 42080046 */  mul.s      $f1, $f1, $f0
    /* 3D4B38 004D4B38 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3D4B3C 004D4B3C 00000244 */  mfc1       $2, $f0
    /* 3D4B40 004D4B40 0800E003 */  jr         $31
    /* 3D4B44 004D4B44 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d4af8, 0x50
