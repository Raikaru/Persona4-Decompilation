.section .text
.set noat
.set noreorder
glabel func_004e3ae0
    /* 3E3AE0 004E3AE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E3AE4 004E3AE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E3AE8 004E3AE8 2D800000 */  daddu      $16, $0, $0
    /* 3E3AEC 004E3AEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3E3AF0 004E3AF0 2D888000 */  daddu      $17, $4, $0
    /* 3E3AF4 004E3AF4 1000B2FF */  sd         $18, 0x10($29)
    /* 3E3AF8 004E3AF8 1800B3FF */  sd         $19, 0x18($29)
    /* 3E3AFC 004E3AFC 2000BFFF */  sd         $31, 0x20($29)
    /* 3E3B00 004E3B00 03000010 */  b          .L004E3B10
    /* 3E3B04 004E3B04 7300133C */   lui       $19, %hi(D_00731C3C)
  .L004E3B08:
    /* 3E3B08 004E3B08 00140200 */  sll        $2, $2, 16
    /* 3E3B0C 004E3B0C 03840200 */  sra        $16, $2, 16
  .L004E3B10:
    /* 3E3B10 004E3B10 E803022A */  slti       $2, $16, 0x3E8
    /* 3E3B14 004E3B14 11004050 */  beql       $2, $0, .L004E3B5C
    /* 3E3B18 004E3B18 02003282 */   lb        $18, 0x2($17)
    /* 3E3B1C 004E3B1C 82C1130C */  jal        func_004f0608
    /* 3E3B20 004E3B20 00000000 */   nop
    /* 3E3B24 004E3B24 3C1C6426 */  addiu      $4, $19, %lo(D_00731C3C)
    /* 3E3B28 004E3B28 0000828C */  lw         $2, 0x0($4)
    /* 3E3B2C 004E3B2C 01000324 */  addiu      $3, $0, 0x1
    /* 3E3B30 004E3B30 07004314 */  bne        $2, $3, .L004E3B50
    /* 3E3B34 004E3B34 00000000 */   nop
    /* 3E3B38 004E3B38 88C1130C */  jal        func_004f0620
    /* 3E3B3C 004E3B3C 00000000 */   nop
    /* 3E3B40 004E3B40 6E8E130C */  jal        func_004e39b8
    /* 3E3B44 004E3B44 00000000 */   nop
    /* 3E3B48 004E3B48 EFFF0010 */  b          .L004E3B08
    /* 3E3B4C 004E3B4C 01000226 */   addiu     $2, $16, 0x1
  .L004E3B50:
    /* 3E3B50 004E3B50 88C1130C */  jal        func_004f0620
    /* 3E3B54 004E3B54 000083AC */   sw        $3, 0x0($4)
    /* 3E3B58 004E3B58 02003282 */  lb         $18, 0x2($17)
  .L004E3B5C:
    /* 3E3B5C 004E3B5C 02000224 */  addiu      $2, $0, 0x2
    /* 3E3B60 004E3B60 1B004256 */  bnel       $18, $2, .L004E3BD0
    /* 3E3B64 004E3B64 3C1C60AE */   sw        $0, %lo(D_00731C3C)($19)
    /* 3E3B68 004E3B68 7300023C */  lui        $2, %hi(D_00731C00)
    /* 3E3B6C 004E3B6C 01000424 */  addiu      $4, $0, 0x1
    /* 3E3B70 004E3B70 001C5024 */  addiu      $16, $2, %lo(D_00731C00)
    /* 3E3B74 004E3B74 01000382 */  lb         $3, 0x1($16)
    /* 3E3B78 004E3B78 04006414 */  bne        $3, $4, .L004E3B8C
    /* 3E3B7C 004E3B7C 01000292 */   lbu       $2, 0x1($16)
    /* 3E3B80 004E3B80 7A8E130C */  jal        func_004e39e8
    /* 3E3B84 004E3B84 2D202002 */   daddu     $4, $17, $0
    /* 3E3B88 004E3B88 01000292 */  lbu        $2, 0x1($16)
  .L004E3B8C:
    /* 3E3B8C 004E3B8C 00160200 */  sll        $2, $2, 24
    /* 3E3B90 004E3B90 03160200 */  sra        $2, $2, 24
    /* 3E3B94 004E3B94 04005254 */  bnel       $2, $18, .L004E3BA8
    /* 3E3B98 004E3B98 02002382 */   lb        $3, 0x2($17)
    /* 3E3B9C 004E3B9C 848E130C */  jal        func_004e3a10
    /* 3E3BA0 004E3BA0 2D202002 */   daddu     $4, $17, $0
    /* 3E3BA4 004E3BA4 02002382 */  lb         $3, 0x2($17)
  .L004E3BA8:
    /* 3E3BA8 004E3BA8 09000224 */  addiu      $2, $0, 0x9
    /* 3E3BAC 004E3BAC 07006210 */  beq        $3, $2, .L004E3BCC
    /* 3E3BB0 004E3BB0 03000224 */   addiu     $2, $0, 0x3
    /* 3E3BB4 004E3BB4 7300033C */  lui        $3, %hi(D_00731C5C)
    /* 3E3BB8 004E3BB8 020022A2 */  sb         $2, 0x2($17)
    /* 3E3BBC 004E3BBC 5C1C6324 */  addiu      $3, $3, %lo(D_00731C5C)
    /* 3E3BC0 004E3BC0 0000628C */  lw         $2, 0x0($3)
    /* 3E3BC4 004E3BC4 01004224 */  addiu      $2, $2, 0x1
    /* 3E3BC8 004E3BC8 000062AC */  sw         $2, 0x0($3)
  .L004E3BCC:
    /* 3E3BCC 004E3BCC 3C1C60AE */  sw         $0, %lo(D_00731C3C)($19)
  .L004E3BD0:
    /* 3E3BD0 004E3BD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E3BD4 004E3BD4 0800B1DF */  ld         $17, 0x8($29)
    /* 3E3BD8 004E3BD8 1000B2DF */  ld         $18, 0x10($29)
    /* 3E3BDC 004E3BDC 1800B3DF */  ld         $19, 0x18($29)
    /* 3E3BE0 004E3BE0 2000BFDF */  ld         $31, 0x20($29)
    /* 3E3BE4 004E3BE4 0800E003 */  jr         $31
    /* 3E3BE8 004E3BE8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3E3BEC 004E3BEC 00000000 */  nop
.size func_004e3ae0, 0x110
