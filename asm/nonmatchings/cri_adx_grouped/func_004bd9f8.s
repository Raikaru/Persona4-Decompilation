.section .text
.set noat
.set noreorder
glabel func_004bd9f8
    /* 3BD9F8 004BD9F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD9FC 004BD9FC 40FC0224 */  addiu      $2, $0, -0x3C0
    /* 3BDA00 004BDA00 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDA04 004BDA04 2D808000 */  daddu      $16, $4, $0
    /* 3BDA08 004BDA08 0800BFFF */  sd         $31, 0x8($29)
    /* 3BDA0C 004BDA0C 2C000426 */  addiu      $4, $16, 0x2C
    /* 3BDA10 004BDA10 280002AE */  sw         $2, 0x28($16)
    /* 3BDA14 004BDA14 2D280000 */  daddu      $5, $0, $0
    /* 3BDA18 004BDA18 000000A2 */  sb         $0, 0x0($16)
    /* 3BDA1C 004BDA1C 0C000624 */  addiu      $6, $0, 0xC
    /* 3BDA20 004BDA20 040000AE */  sw         $0, 0x4($16)
    /* 3BDA24 004BDA24 080000AE */  sw         $0, 0x8($16)
    /* 3BDA28 004BDA28 0C0000AE */  sw         $0, 0xC($16)
    /* 3BDA2C 004BDA2C 100000AE */  sw         $0, 0x10($16)
    /* 3BDA30 004BDA30 140000AE */  sw         $0, 0x14($16)
    /* 3BDA34 004BDA34 180000A2 */  sb         $0, 0x18($16)
    /* 3BDA38 004BDA38 1C0002AE */  sw         $2, 0x1C($16)
    /* 3BDA3C 004BDA3C 200000AE */  sw         $0, 0x20($16)
    /* 3BDA40 004BDA40 72FE100C */  jal        func_0043f9c8
    /* 3BDA44 004BDA44 240002AE */   sw        $2, 0x24($16)
    /* 3BDA48 004BDA48 38000426 */  addiu      $4, $16, 0x38
    /* 3BDA4C 004BDA4C 0800BFDF */  ld         $31, 0x8($29)
    /* 3BDA50 004BDA50 2D280000 */  daddu      $5, $0, $0
    /* 3BDA54 004BDA54 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDA58 004BDA58 0C000624 */  addiu      $6, $0, 0xC
    /* 3BDA5C 004BDA5C 72FE1008 */  j          func_0043f9c8
    /* 3BDA60 004BDA60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BDA64 004BDA64 00000000 */  nop
.size func_004bd9f8, 0x70
