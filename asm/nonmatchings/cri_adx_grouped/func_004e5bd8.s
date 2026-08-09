.section .text
.set noat
.set noreorder
glabel func_004e5bd8
    /* 3E5BD8 004E5BD8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E5BDC 004E5BDC 1800B3FF */  sd         $19, 0x18($29)
    /* 3E5BE0 004E5BE0 7300133C */  lui        $19, %hi(D_007330D0)
    /* 3E5BE4 004E5BE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5BE8 004E5BE8 0800B1FF */  sd         $17, 0x8($29)
    /* 3E5BEC 004E5BEC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E5BF0 004E5BF0 2000BFFF */  sd         $31, 0x20($29)
    /* 3E5BF4 004E5BF4 9EC4130C */  jal        func_004f1278
    /* 3E5BF8 004E5BF8 D0306426 */   addiu     $4, $19, %lo(D_007330D0)
    /* 3E5BFC 004E5BFC 0D004010 */  beqz       $2, .L004E5C34
    /* 3E5C00 004E5C00 7300023C */   lui       $2, %hi(D_00733140)
    /* 3E5C04 004E5C04 01001224 */  addiu      $18, $0, 0x1
    /* 3E5C08 004E5C08 40315024 */  addiu      $16, $2, %lo(D_00733140)
    /* 3E5C0C 004E5C0C 27001124 */  addiu      $17, $0, 0x27
  .L004E5C10:
    /* 3E5C10 004E5C10 00000282 */  lb         $2, 0x0($16)
    /* 3E5C14 004E5C14 04005254 */  bnel       $2, $18, .L004E5C28
    /* 3E5C18 004E5C18 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3E5C1C 004E5C1C C496130C */  jal        func_004e5b10
    /* 3E5C20 004E5C20 2D200002 */   daddu     $4, $16, $0
    /* 3E5C24 004E5C24 FFFF3126 */  addiu      $17, $17, -0x1
  .L004E5C28:
    /* 3E5C28 004E5C28 F9FF2106 */  bgez       $17, .L004E5C10
    /* 3E5C2C 004E5C2C 48001026 */   addiu     $16, $16, 0x48
    /* 3E5C30 004E5C30 D03060AE */  sw         $0, %lo(D_007330D0)($19)
  .L004E5C34:
    /* 3E5C34 004E5C34 0000B0DF */  ld         $16, 0x0($29)
    /* 3E5C38 004E5C38 0800B1DF */  ld         $17, 0x8($29)
    /* 3E5C3C 004E5C3C 1000B2DF */  ld         $18, 0x10($29)
    /* 3E5C40 004E5C40 1800B3DF */  ld         $19, 0x18($29)
    /* 3E5C44 004E5C44 2000BFDF */  ld         $31, 0x20($29)
    /* 3E5C48 004E5C48 0800E003 */  jr         $31
    /* 3E5C4C 004E5C4C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e5bd8, 0x78
