.section .text
.set noat
.set noreorder
glabel func_002b29e0
    /* 1B29E0 002B29E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B29E4 002B29E4 24600046 */  .word      0x46006024                    # cvt.w.s    $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1B29E8 002B29E8 00000344 */  mfc1       $3, $f0
    /* 1B29EC 002B29EC 00000000 */  nop
    /* 1B29F0 002B29F0 0800A3AF */  sw         $3, 0x8($29)
    /* 1B29F4 002B29F4 24680046 */  .word      0x46006824                    # cvt.w.s    $f0, $f13 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1B29F8 002B29F8 00000344 */  mfc1       $3, $f0
    /* 1B29FC 002B29FC 00000000 */  nop
    /* 1B2A00 002B2A00 0C00A3AF */  sw         $3, 0xC($29)
    /* 1B2A04 002B2A04 0000A3C7 */  lwc1       $f3, 0x0($29)
    /* 1B2A08 002B2A08 0400A2C7 */  lwc1       $f2, 0x4($29)
    /* 1B2A0C 002B2A0C 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 1B2A10 002B2A10 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1B2A14 002B2A14 000083E4 */  swc1       $f3, 0x0($4)
    /* 1B2A18 002B2A18 040082E4 */  swc1       $f2, 0x4($4)
    /* 1B2A1C 002B2A1C 080081E4 */  swc1       $f1, 0x8($4)
    /* 1B2A20 002B2A20 0C0080E4 */  swc1       $f0, 0xC($4)
    /* 1B2A24 002B2A24 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B2A28 002B2A28 0800E003 */  jr         $31
    /* 1B2A2C 002B2A2C 00000000 */   nop
.size func_002b29e0, 0x50
