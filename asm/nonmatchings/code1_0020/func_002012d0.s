.section .text
.set noat
.set noreorder
glabel func_002012d0
    /* 1012D0 002012D0 24600046 */  .word      0x46006024                    # cvt.w.s    $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1012D4 002012D4 00000344 */  mfc1       $3, $f0
    /* 1012D8 002012D8 00000000 */  nop
    /* 1012DC 002012DC 040083AC */  sw         $3, 0x4($4)
    /* 1012E0 002012E0 24680046 */  .word      0x46006824                    # cvt.w.s    $f0, $f13 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1012E4 002012E4 00000344 */  mfc1       $3, $f0
    /* 1012E8 002012E8 00000000 */  nop
    /* 1012EC 002012EC 080083AC */  sw         $3, 0x8($4)
    /* 1012F0 002012F0 0C0080AC */  sw         $0, 0xC($4)
    /* 1012F4 002012F4 100080AC */  sw         $0, 0x10($4)
    /* 1012F8 002012F8 0800E003 */  jr         $31
    /* 1012FC 002012FC 00000000 */   nop
.size func_002012d0, 0x30
