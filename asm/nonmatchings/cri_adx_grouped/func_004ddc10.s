.section .text
.set noat
.set noreorder
glabel func_004ddc10
    /* 3DDC10 004DDC10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DDC14 004DDC14 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDC18 004DDC18 2D808000 */  daddu      $16, $4, $0
    /* 3DDC1C 004DDC1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DDC20 004DDC20 14000012 */  beqz       $16, .L004DDC74
    /* 3DDC24 004DDC24 1000BFFF */   sd        $31, 0x10($29)
    /* 3DDC28 004DDC28 0C00028E */  lw         $2, 0xC($16)
    /* 3DDC2C 004DDC2C 3C00118E */  lw         $17, 0x3C($16)
    /* 3DDC30 004DDC30 03004010 */  beqz       $2, .L004DDC40
    /* 3DDC34 004DDC34 2D204000 */   daddu     $4, $2, $0
    /* 3DDC38 004DDC38 1E65130C */  jal        func_004d9478
    /* 3DDC3C 004DDC3C 0C0000AE */   sw        $0, 0xC($16)
  .L004DDC40:
    /* 3DDC40 004DDC40 0000048E */  lw         $4, 0x0($16)
    /* 3DDC44 004DDC44 04008050 */  beql       $4, $0, .L004DDC58
    /* 3DDC48 004DDC48 2D200002 */   daddu     $4, $16, $0
    /* 3DDC4C 004DDC4C BC67130C */  jal        func_004d9ef0
    /* 3DDC50 004DDC50 000000AE */   sw        $0, 0x0($16)
    /* 3DDC54 004DDC54 2D200002 */  daddu      $4, $16, $0
  .L004DDC58:
    /* 3DDC58 004DDC58 2D280000 */  daddu      $5, $0, $0
    /* 3DDC5C 004DDC5C 72FE100C */  jal        func_0043f9c8
    /* 3DDC60 004DDC60 50000624 */   addiu     $6, $0, 0x50
    /* 3DDC64 004DDC64 80181100 */  sll        $3, $17, 2
    /* 3DDC68 004DDC68 7300013C */  lui        $1, %hi(D_00729A40)
    /* 3DDC6C 004DDC6C 21082300 */  addu       $1, $1, $3
    /* 3DDC70 004DDC70 409A20AC */  sw         $0, %lo(D_00729A40)($1)
  .L004DDC74:
    /* 3DDC74 004DDC74 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDC78 004DDC78 0800B1DF */  ld         $17, 0x8($29)
    /* 3DDC7C 004DDC7C 1000BFDF */  ld         $31, 0x10($29)
    /* 3DDC80 004DDC80 0800E003 */  jr         $31
    /* 3DDC84 004DDC84 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ddc10, 0x78
