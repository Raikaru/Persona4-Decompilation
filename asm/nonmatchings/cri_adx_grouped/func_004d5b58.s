.section .text
.set noat
.set noreorder
glabel func_004d5b58
    /* 3D5B58 004D5B58 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D5B5C 004D5B5C 1800B3FF */  sd         $19, 0x18($29)
    /* 3D5B60 004D5B60 7200133C */  lui        $19, %hi(D_00724E68)
    /* 3D5B64 004D5B64 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5B68 004D5B68 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5B6C 004D5B6C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D5B70 004D5B70 2000BFFF */  sd         $31, 0x20($29)
    /* 3D5B74 004D5B74 2A15130C */  jal        func_004c54a8
    /* 3D5B78 004D5B78 684E7026 */   addiu     $16, $19, %lo(D_00724E68)
    /* 3D5B7C 004D5B7C 0000028E */  lw         $2, 0x0($16)
    /* 3D5B80 004D5B80 07004010 */  beqz       $2, .L004D5BA0
    /* 3D5B84 004D5B84 1000B2DF */   ld        $18, 0x10($29)
    /* 3D5B88 004D5B88 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5B8C 004D5B8C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5B90 004D5B90 1800B3DF */  ld         $19, 0x18($29)
    /* 3D5B94 004D5B94 2000BFDF */  ld         $31, 0x20($29)
    /* 3D5B98 004D5B98 30151308 */  j          func_004c54c0
    /* 3D5B9C 004D5B9C 3000BD27 */   addiu     $29, $29, 0x30
  .L004D5BA0:
    /* 3D5BA0 004D5BA0 01000224 */  addiu      $2, $0, 0x1
    /* 3D5BA4 004D5BA4 01001224 */  addiu      $18, $0, 0x1
    /* 3D5BA8 004D5BA8 000002AE */  sw         $2, 0x0($16)
    /* 3D5BAC 004D5BAC 3015130C */  jal        func_004c54c0
    /* 3D5BB0 004D5BB0 0F001124 */   addiu     $17, $0, 0xF
    /* 3D5BB4 004D5BB4 2A15130C */  jal        func_004c54a8
    /* 3D5BB8 004D5BB8 00000000 */   nop
    /* 3D5BBC 004D5BBC E43A130C */  jal        func_004ceb90
    /* 3D5BC0 004D5BC0 00000000 */   nop
    /* 3D5BC4 004D5BC4 02000224 */  addiu      $2, $0, 0x2
    /* 3D5BC8 004D5BC8 7200033C */  lui        $3, %hi(D_007188C0)
    /* 3D5BCC 004D5BCC 000002AE */  sw         $2, 0x0($16)
    /* 3D5BD0 004D5BD0 C0887024 */  addiu      $16, $3, %lo(D_007188C0)
    /* 3D5BD4 004D5BD4 00000000 */  nop
  .L004D5BD8:
    /* 3D5BD8 004D5BD8 00000282 */  lb         $2, 0x0($16)
    /* 3D5BDC 004D5BDC 04005254 */  bnel       $2, $18, .L004D5BF0
    /* 3D5BE0 004D5BE0 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3D5BE4 004D5BE4 9A61130C */  jal        func_004d8668
    /* 3D5BE8 004D5BE8 2D200002 */   daddu     $4, $16, $0
    /* 3D5BEC 004D5BEC FFFF3126 */  addiu      $17, $17, -0x1
  .L004D5BF0:
    /* 3D5BF0 004D5BF0 F9FF2106 */  bgez       $17, .L004D5BD8
    /* 3D5BF4 004D5BF4 C8001026 */   addiu     $16, $16, 0xC8
    /* 3D5BF8 004D5BF8 03000224 */  addiu      $2, $0, 0x3
    /* 3D5BFC 004D5BFC 684E7026 */  addiu      $16, $19, %lo(D_00724E68)
    /* 3D5C00 004D5C00 EE35130C */  jal        func_004cd7b8
    /* 3D5C04 004D5C04 000002AE */   sw        $2, 0x0($16)
    /* 3D5C08 004D5C08 7200033C */  lui        $3, %hi(D_00724E70)
    /* 3D5C0C 004D5C0C 704E628C */  lw         $2, %lo(D_00724E70)($3)
    /* 3D5C10 004D5C10 33004228 */  slti       $2, $2, 0x33
    /* 3D5C14 004D5C14 03004010 */  beqz       $2, .L004D5C24
    /* 3D5C18 004D5C18 00000000 */   nop
    /* 3D5C1C 004D5C1C EE35130C */  jal        func_004cd7b8
    /* 3D5C20 004D5C20 00000000 */   nop
  .L004D5C24:
    /* 3D5C24 004D5C24 000000AE */  sw         $0, 0x0($16)
    /* 3D5C28 004D5C28 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5C2C 004D5C2C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5C30 004D5C30 1000B2DF */  ld         $18, 0x10($29)
    /* 3D5C34 004D5C34 1800B3DF */  ld         $19, 0x18($29)
    /* 3D5C38 004D5C38 2000BFDF */  ld         $31, 0x20($29)
    /* 3D5C3C 004D5C3C 30151308 */  j          func_004c54c0
    /* 3D5C40 004D5C40 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D5C44 004D5C44 00000000 */  nop
.size func_004d5b58, 0xf0
