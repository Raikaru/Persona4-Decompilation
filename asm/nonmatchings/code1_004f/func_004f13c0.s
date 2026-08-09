.section .text
.set noat
.set noreorder
glabel func_004f13c0
    /* 3F13C0 004F13C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F13C4 004F13C4 01000224 */  addiu      $2, $0, 0x1
    /* 3F13C8 004F13C8 0F00C210 */  beq        $6, $2, .L004F1408
    /* 3F13CC 004F13CC 0000BFFF */   sd        $31, 0x0($29)
    /* 3F13D0 004F13D0 0D00C010 */  beqz       $6, .L004F1408
    /* 3F13D4 004F13D4 2D100000 */   daddu     $2, $0, $0
    /* 3F13D8 004F13D8 02000224 */  addiu      $2, $0, 0x2
    /* 3F13DC 004F13DC 0A00C210 */  beq        $6, $2, .L004F1408
    /* 3F13E0 004F13E0 7600063C */   lui       $6, %hi(D_0075D3F8)
    /* 3F13E4 004F13E4 7600043C */  lui        $4, %hi(D_0075D3E0)
    /* 3F13E8 004F13E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F13EC 004F13EC E0D38424 */  addiu      $4, $4, %lo(D_0075D3E0)
    /* 3F13F0 004F13F0 F8D3C624 */  addiu      $6, $6, %lo(D_0075D3F8)
    /* 3F13F4 004F13F4 84000524 */  addiu      $5, $0, 0x84
    /* 3F13F8 004F13F8 2D380000 */  daddu      $7, $0, $0
    /* 3F13FC 004F13FC 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F1400 004F1400 F0D41308 */  j          func_004f53c0
    /* 3F1404 004F1404 1000BD27 */   addiu     $29, $29, 0x10
  .L004F1408:
    /* 3F1408 004F1408 0000BFDF */  ld         $31, 0x0($29)
    /* 3F140C 004F140C 2D304000 */  daddu      $6, $2, $0
    /* 3F1410 004F1410 42881308 */  j          func_004e2108
    /* 3F1414 004F1414 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f13c0, 0x58
