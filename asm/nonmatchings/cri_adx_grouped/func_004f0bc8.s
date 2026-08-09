.section .text
.set noat
.set noreorder
glabel func_004f0bc8
    /* 3F0BC8 004F0BC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0BCC 004F0BCC 2D308000 */  daddu      $6, $4, $0
    /* 3F0BD0 004F0BD0 0600A22C */  sltiu      $2, $5, 0x6
    /* 3F0BD4 004F0BD4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0BD8 004F0BD8 07004014 */  bnez       $2, .L004F0BF8
    /* 3F0BDC 004F0BDC 0800C32C */   sltiu     $3, $6, 0x8
    /* 3F0BE0 004F0BE0 7600043C */  lui        $4, %hi(D_0075D248)
    /* 3F0BE4 004F0BE4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0BE8 004F0BE8 48D28424 */  addiu      $4, $4, %lo(D_0075D248)
    /* 3F0BEC 004F0BEC F8C11308 */  j          func_004f07e0
    /* 3F0BF0 004F0BF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F0BF4 004F0BF4 00000000 */  nop
  .L004F0BF8:
    /* 3F0BF8 004F0BF8 07006014 */  bnez       $3, .L004F0C18
    /* 3F0BFC 004F0BFC 40180500 */   sll       $3, $5, 1
    /* 3F0C00 004F0C00 7600043C */  lui        $4, %hi(D_0075D268)
    /* 3F0C04 004F0C04 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0C08 004F0C08 68D28424 */  addiu      $4, $4, %lo(D_0075D268)
    /* 3F0C0C 004F0C0C F8C11308 */  j          func_004f07e0
    /* 3F0C10 004F0C10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F0C14 004F0C14 00000000 */  nop
  .L004F0C18:
    /* 3F0C18 004F0C18 C0200600 */  sll        $4, $6, 3
    /* 3F0C1C 004F0C1C 21186500 */  addu       $3, $3, $5
    /* 3F0C20 004F0C20 21208600 */  addu       $4, $4, $6
    /* 3F0C24 004F0C24 C0200400 */  sll        $4, $4, 3
    /* 3F0C28 004F0C28 80180300 */  sll        $3, $3, 2
    /* 3F0C2C 004F0C2C 9200023C */  lui        $2, %hi(D_00925BE0)
    /* 3F0C30 004F0C30 21186400 */  addu       $3, $3, $4
    /* 3F0C34 004F0C34 E05B4224 */  addiu      $2, $2, %lo(D_00925BE0)
    /* 3F0C38 004F0C38 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0C3C 004F0C3C 21284300 */  addu       $5, $2, $3
    /* 3F0C40 004F0C40 21206200 */  addu       $4, $3, $2
    /* 3F0C44 004F0C44 2D10A000 */  daddu      $2, $5, $0
    /* 3F0C48 004F0C48 000080AC */  sw         $0, 0x0($4)
    /* 3F0C4C 004F0C4C 040040AC */  sw         $0, 0x4($2)
    /* 3F0C50 004F0C50 0800A0AC */  sw         $0, 0x8($5)
    /* 3F0C54 004F0C54 0800E003 */  jr         $31
    /* 3F0C58 004F0C58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F0C5C 004F0C5C 00000000 */  nop
.size func_004f0bc8, 0x98
