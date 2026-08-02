.section .text
.set noat
.set noreorder
glabel func_002b3ae0
    /* 1B3AE0 002B3AE0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1B3AE4 002B3AE4 3000BFFF */  sd         $31, 0x30($29)
    /* 1B3AE8 002B3AE8 2000B17F */  sq         $17, 0x20($29)
    /* 1B3AEC 002B3AEC 1000B07F */  sq         $16, 0x10($29)
    /* 1B3AF0 002B3AF0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1B3AF4 002B3AF4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1B3AF8 002B3AF8 4800A5FF */  sd         $5, 0x48($29)
    /* 1B3AFC 002B3AFC 46650046 */  mov.s      $f21, $f12
    /* 1B3B00 002B3B00 2D88C000 */  daddu      $17, $6, $0
    /* 1B3B04 002B3B04 3800908C */  lw         $16, 0x38($4)
    /* 1B3B08 002B3B08 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 1B3B0C 002B3B0C 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 1B3B10 002B3B10 BCE8110C */  jal        func_0047a2f0
    /* 1B3B14 002B3B14 00000000 */   nop
    /* 1B3B18 002B3B18 2D204000 */  daddu      $4, $2, $0
    /* 1B3B1C 002B3B1C 742D050C */  jal        func_0014b5d0
    /* 1B3B20 002B3B20 00000000 */   nop
    /* 1B3B24 002B3B24 00088044 */  mtc1       $0, $f1
    /* 1B3B28 002B3B28 00000000 */  nop
    /* 1B3B2C 002B3B2C 34000146 */  c.lt.s     $f0, $f1
    /* 1B3B30 002B3B30 07000145 */  bc1t       .L002B3B50
    /* 1B3B34 002B3B34 00000000 */   nop
    /* 1B3B38 002B3B38 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1B3B3C 002B3B3C 00088244 */  mtc1       $2, $f1
    /* 1B3B40 002B3B40 00000000 */  nop
    /* 1B3B44 002B3B44 01050146 */  sub.s      $f20, $f0, $f1
    /* 1B3B48 002B3B48 05000010 */  b          .L002B3B60
    /* 1B3B4C 002B3B4C 00000000 */   nop
  .L002B3B50:
    /* 1B3B50 002B3B50 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1B3B54 002B3B54 00088244 */  mtc1       $2, $f1
    /* 1B3B58 002B3B58 00000000 */  nop
    /* 1B3B5C 002B3B5C 00050146 */  add.s      $f20, $f0, $f1
  .L002B3B60:
    /* 1B3B60 002B3B60 100000C6 */  lwc1       $f0, 0x10($16)
    /* 1B3B64 002B3B64 40A00046 */  add.s      $f1, $f20, $f0
    /* 1B3B68 002B3B68 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* 1B3B6C 002B3B6C 00008244 */  mtc1       $2, $f0
    /* 1B3B70 002B3B70 00000000 */  nop
    /* 1B3B74 002B3B74 020D0046 */  mul.s      $f20, $f1, $f0
    /* 1B3B78 002B3B78 20000382 */  lb         $3, 0x20($16)
    /* 1B3B7C 002B3B7C 01000224 */  addiu      $2, $0, 0x1
    /* 1B3B80 002B3B80 17006214 */  bne        $3, $2, .L002B3BE0
    /* 1B3B84 002B3B84 00000000 */   nop
    /* 1B3B88 002B3B88 D0B10A0C */  jal        func_002ac740
    /* 1B3B8C 002B3B8C 00000000 */   nop
    /* 1B3B90 002B3B90 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1B3B94 002B3B94 00808344 */  mtc1       $3, $f16
    /* 1B3B98 002B3B98 4800ACC7 */  lwc1       $f12, 0x48($29)
    /* 1B3B9C 002B3B9C 4C00ADC7 */  lwc1       $f13, 0x4C($29)
    /* 1B3BA0 002B3BA0 86AB0046 */  mov.s      $f14, $f21
    /* 1B3BA4 002B3BA4 2D202002 */  daddu      $4, $17, $0
    /* 1B3BA8 002B3BA8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1B3BAC 002B3BAC 10000624 */  addiu      $6, $0, 0x10
    /* 1B3BB0 002B3BB0 2D384000 */  daddu      $7, $2, $0
    /* 1B3BB4 002B3BB4 01000824 */  addiu      $8, $0, 0x1
    /* 1B3BB8 002B3BB8 14000986 */  lh         $9, 0x14($16)
    /* 1B3BBC 002B3BBC 16000A86 */  lh         $10, 0x16($16)
    /* 1B3BC0 002B3BC0 C6A30046 */  mov.s      $f15, $f20
    /* 1B3BC4 002B3BC4 46840046 */  mov.s      $f17, $f16
    /* 1B3BC8 002B3BC8 79000B3C */  lui        $11, %hi(D_00794D20)
    /* 1B3BCC 002B3BCC 204D6B25 */  addiu      $11, $11, %lo(D_00794D20)
    /* 1B3BD0 002B3BD0 347B090C */  jal        func_0025ecd0
    /* 1B3BD4 002B3BD4 00000000 */   nop
    /* 1B3BD8 002B3BD8 15000010 */  b          .L002B3C30
    /* 1B3BDC 002B3BDC 00000000 */   nop
  .L002B3BE0:
    /* 1B3BE0 002B3BE0 D0B10A0C */  jal        func_002ac740
    /* 1B3BE4 002B3BE4 00000000 */   nop
    /* 1B3BE8 002B3BE8 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1B3BEC 002B3BEC 00808344 */  mtc1       $3, $f16
    /* 1B3BF0 002B3BF0 4800ACC7 */  lwc1       $f12, 0x48($29)
    /* 1B3BF4 002B3BF4 4C00ADC7 */  lwc1       $f13, 0x4C($29)
    /* 1B3BF8 002B3BF8 86AB0046 */  mov.s      $f14, $f21
    /* 1B3BFC 002B3BFC 2D202002 */  daddu      $4, $17, $0
    /* 1B3C00 002B3C00 FF000524 */  addiu      $5, $0, 0xFF
    /* 1B3C04 002B3C04 10000624 */  addiu      $6, $0, 0x10
    /* 1B3C08 002B3C08 2D384000 */  daddu      $7, $2, $0
    /* 1B3C0C 002B3C0C 01000824 */  addiu      $8, $0, 0x1
    /* 1B3C10 002B3C10 14000986 */  lh         $9, 0x14($16)
    /* 1B3C14 002B3C14 16000A86 */  lh         $10, 0x16($16)
    /* 1B3C18 002B3C18 C6A30046 */  mov.s      $f15, $f20
    /* 1B3C1C 002B3C1C 46840046 */  mov.s      $f17, $f16
    /* 1B3C20 002B3C20 79000B3C */  lui        $11, %hi(D_00794DE0)
    /* 1B3C24 002B3C24 E04D6B25 */  addiu      $11, $11, %lo(D_00794DE0)
    /* 1B3C28 002B3C28 347B090C */  jal        func_0025ecd0
    /* 1B3C2C 002B3C2C 00000000 */   nop
  .L002B3C30:
    /* 1B3C30 002B3C30 3000BFDF */  ld         $31, 0x30($29)
    /* 1B3C34 002B3C34 2000B17B */  lq         $17, 0x20($29)
    /* 1B3C38 002B3C38 1000B07B */  lq         $16, 0x10($29)
    /* 1B3C3C 002B3C3C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1B3C40 002B3C40 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1B3C44 002B3C44 5000BD27 */  addiu      $29, $29, 0x50
    /* 1B3C48 002B3C48 0800E003 */  jr         $31
    /* 1B3C4C 002B3C4C 00000000 */   nop
.size func_002b3ae0, 0x170
