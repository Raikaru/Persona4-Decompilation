.section .text
.set noat
.set noreorder
glabel func_004fb9e8
    /* 3FB9E8 004FB9E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB9EC 004FB9EC 2D280000 */  daddu      $5, $0, $0
    /* 3FB9F0 004FB9F0 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB9F4 004FB9F4 60019024 */  addiu      $16, $4, 0x160
    /* 3FB9F8 004FB9F8 2D200002 */  daddu      $4, $16, $0
    /* 3FB9FC 004FB9FC 0800BFFF */  sd         $31, 0x8($29)
    /* 3FBA00 004FBA00 72FE100C */  jal        func_0043f9c8
    /* 3FBA04 004FBA04 30050624 */   addiu     $6, $0, 0x530
    /* 3FBA08 004FBA08 FF000224 */  addiu      $2, $0, 0xFF
    /* 3FBA0C 004FBA0C 01000324 */  addiu      $3, $0, 0x1
    /* 3FBA10 004FBA10 D40003AE */  sw         $3, 0xD4($16)
    /* 3FBA14 004FBA14 7C0002AE */  sw         $2, 0x7C($16)
    /* 3FBA18 004FBA18 240500AE */  sw         $0, 0x524($16)
    /* 3FBA1C 004FBA1C 4C0003AE */  sw         $3, 0x4C($16)
    /* 3FBA20 004FBA20 700000AE */  sw         $0, 0x70($16)
    /* 3FBA24 004FBA24 740002AE */  sw         $2, 0x74($16)
    /* 3FBA28 004FBA28 780002AE */  sw         $2, 0x78($16)
    /* 3FBA2C 004FBA2C 700400AE */  sw         $0, 0x470($16)
    /* 3FBA30 004FBA30 740400AE */  sw         $0, 0x474($16)
    /* 3FBA34 004FBA34 780400AE */  sw         $0, 0x478($16)
    /* 3FBA38 004FBA38 7C0400AE */  sw         $0, 0x47C($16)
    /* 3FBA3C 004FBA3C 800400AE */  sw         $0, 0x480($16)
    /* 3FBA40 004FBA40 840400AE */  sw         $0, 0x484($16)
    /* 3FBA44 004FBA44 8C0400AE */  sw         $0, 0x48C($16)
    /* 3FBA48 004FBA48 C80300AE */  sw         $0, 0x3C8($16)
    /* 3FBA4C 004FBA4C 000500AE */  sw         $0, 0x500($16)
    /* 3FBA50 004FBA50 040500AE */  sw         $0, 0x504($16)
    /* 3FBA54 004FBA54 140500AE */  sw         $0, 0x514($16)
    /* 3FBA58 004FBA58 D00000AE */  sw         $0, 0xD0($16)
    /* 3FBA5C 004FBA5C 0800BFDF */  ld         $31, 0x8($29)
    /* 3FBA60 004FBA60 0000B0DF */  ld         $16, 0x0($29)
    /* 3FBA64 004FBA64 0800E003 */  jr         $31
    /* 3FBA68 004FBA68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FBA6C 004FBA6C 00000000 */  nop
.size func_004fb9e8, 0x88
