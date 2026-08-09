.section .text
.set noat
.set noreorder
glabel func_004e2b60
    /* 3E2B60 004E2B60 80FFBD27 */  addiu      $29, $29, -0x80
    /* 3E2B64 004E2B64 6000B0FF */  sd         $16, 0x60($29)
    /* 3E2B68 004E2B68 2D808000 */  daddu      $16, $4, $0
    /* 3E2B6C 004E2B6C 6800B1FF */  sd         $17, 0x68($29)
    /* 3E2B70 004E2B70 05000016 */  bnez       $16, .L004E2B88
    /* 3E2B74 004E2B74 7000BFFF */   sd        $31, 0x70($29)
    /* 3E2B78 004E2B78 7600043C */  lui        $4, %hi(D_0075A4E0)
    /* 3E2B7C 004E2B7C 1F000010 */  b          .L004E2BFC
    /* 3E2B80 004E2B80 E0A48424 */   addiu     $4, $4, %lo(D_0075A4E0)
    /* 3E2B84 004E2B84 00000000 */  nop
  .L004E2B88:
    /* 3E2B88 004E2B88 3000B127 */  addiu      $17, $29, 0x30
    /* 3E2B8C 004E2B8C 2D20A003 */  daddu      $4, $29, $0
    /* 3E2B90 004E2B90 2D282002 */  daddu      $5, $17, $0
    /* 3E2B94 004E2B94 9E87130C */  jal        func_004e1e78
    /* 3E2B98 004E2B98 2D300002 */   daddu     $6, $16, $0
    /* 3E2B9C 004E2B9C 3000A283 */  lb         $2, 0x30($29)
    /* 3E2BA0 004E2BA0 05004014 */  bnez       $2, .L004E2BB8
    /* 3E2BA4 004E2BA4 2D300002 */   daddu     $6, $16, $0
    /* 3E2BA8 004E2BA8 7600043C */  lui        $4, %hi(D_0075A4E0)
    /* 3E2BAC 004E2BAC 13000010 */  b          .L004E2BFC
    /* 3E2BB0 004E2BB0 E0A48424 */   addiu     $4, $4, %lo(D_0075A4E0)
    /* 3E2BB4 004E2BB4 00000000 */  nop
  .L004E2BB8:
    /* 3E2BB8 004E2BB8 2D20A003 */  daddu      $4, $29, $0
    /* 3E2BBC 004E2BBC 0C87130C */  jal        func_004e1c30
    /* 3E2BC0 004E2BC0 2D282002 */   daddu     $5, $17, $0
    /* 3E2BC4 004E2BC4 2D804000 */  daddu      $16, $2, $0
    /* 3E2BC8 004E2BC8 05000056 */  bnel       $16, $0, .L004E2BE0
    /* 3E2BCC 004E2BCC 5000028E */   lw        $2, 0x50($16)
    /* 3E2BD0 004E2BD0 7600043C */  lui        $4, %hi(D_0075A530)
    /* 3E2BD4 004E2BD4 6A85130C */  jal        func_004e15a8
    /* 3E2BD8 004E2BD8 30A58424 */   addiu     $4, $4, %lo(D_0075A530)
    /* 3E2BDC 004E2BDC 5000028E */  lw         $2, 0x50($16)
  .L004E2BE0:
    /* 3E2BE0 004E2BE0 05004050 */  beql       $2, $0, .L004E2BF8
    /* 3E2BE4 004E2BE4 7600043C */   lui       $4, %hi(D_0075A550)
    /* 3E2BE8 004E2BE8 09F84000 */  jalr       $2
    /* 3E2BEC 004E2BEC 2D202002 */   daddu     $4, $17, $0
    /* 3E2BF0 004E2BF0 06000010 */  b          .L004E2C0C
    /* 3E2BF4 004E2BF4 6000B0DF */   ld        $16, 0x60($29)
  .L004E2BF8:
    /* 3E2BF8 004E2BF8 50A58424 */  addiu      $4, $4, %lo(D_0075A550)
  .L004E2BFC:
    /* 3E2BFC 004E2BFC 6A85130C */  jal        func_004e15a8
    /* 3E2C00 004E2C00 00000000 */   nop
    /* 3E2C04 004E2C04 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3E2C08 004E2C08 6000B0DF */  ld         $16, 0x60($29)
  .L004E2C0C:
    /* 3E2C0C 004E2C0C 6800B1DF */  ld         $17, 0x68($29)
    /* 3E2C10 004E2C10 7000BFDF */  ld         $31, 0x70($29)
    /* 3E2C14 004E2C14 0800E003 */  jr         $31
    /* 3E2C18 004E2C18 8000BD27 */   addiu     $29, $29, 0x80
    /* 3E2C1C 004E2C1C 00000000 */  nop
.size func_004e2b60, 0xc0
