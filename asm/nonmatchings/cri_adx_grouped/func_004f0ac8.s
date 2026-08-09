.section .text
.set noat
.set noreorder
glabel func_004f0ac8
    /* 3F0AC8 004F0AC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0ACC 004F0ACC 0800822C */  sltiu      $2, $4, 0x8
    /* 3F0AD0 004F0AD0 07004014 */  bnez       $2, .L004F0AF0
    /* 3F0AD4 004F0AD4 0000BFFF */   sd        $31, 0x0($29)
    /* 3F0AD8 004F0AD8 7600043C */  lui        $4, %hi(D_0075D1E8)
    /* 3F0ADC 004F0ADC 24000010 */  b          .L004F0B70
    /* 3F0AE0 004F0AE0 E8D18424 */   addiu     $4, $4, %lo(D_0075D1E8)
    /* 3F0AE4 004F0AE4 00000000 */  nop
  .L004F0AE8:
    /* 3F0AE8 004F0AE8 1C000010 */  b          .L004F0B5C
    /* 3F0AEC 004F0AEC 080007AD */   sw        $7, 0x8($8)
  .L004F0AF0:
    /* 3F0AF0 004F0AF0 C0100400 */  sll        $2, $4, 3
    /* 3F0AF4 004F0AF4 7600033C */  lui        $3, %hi(D_0075D210)
    /* 3F0AF8 004F0AF8 21104400 */  addu       $2, $2, $4
    /* 3F0AFC 004F0AFC 10D26A24 */  addiu      $10, $3, %lo(D_0075D210)
    /* 3F0B00 004F0B00 C0100200 */  sll        $2, $2, 3
    /* 3F0B04 004F0B04 2D480000 */  daddu      $9, $0, $0
    /* 3F0B08 004F0B08 9200043C */  lui        $4, %hi(D_00925BE0)
    /* 3F0B0C 004F0B0C E05B8424 */  addiu      $4, $4, %lo(D_00925BE0)
    /* 3F0B10 004F0B10 21208200 */  addu       $4, $4, $2
    /* 3F0B14 004F0B14 0000838C */  lw         $3, 0x0($4)
    /* 3F0B18 004F0B18 0C006010 */  beqz       $3, .L004F0B4C
    /* 3F0B1C 004F0B1C 2D408000 */   daddu     $8, $4, $0
    /* 3F0B20 004F0B20 01002925 */  addiu      $9, $9, 0x1
    /* 3F0B24 004F0B24 00000000 */  nop
  .L004F0B28:
    /* 3F0B28 004F0B28 0C008424 */  addiu      $4, $4, 0xC
    /* 3F0B2C 004F0B2C 06002229 */  slti       $2, $9, 0x6
    /* 3F0B30 004F0B30 0A004010 */  beqz       $2, .L004F0B5C
    /* 3F0B34 004F0B34 2D408000 */   daddu     $8, $4, $0
    /* 3F0B38 004F0B38 0000828C */  lw         $2, 0x0($4)
    /* 3F0B3C 004F0B3C 00000000 */  nop
    /* 3F0B40 004F0B40 00000000 */  nop
    /* 3F0B44 004F0B44 F8FF4054 */  bnel       $2, $0, .L004F0B28
    /* 3F0B48 004F0B48 01002925 */   addiu     $9, $9, 0x1
  .L004F0B4C:
    /* 3F0B4C 004F0B4C 000085AC */  sw         $5, 0x0($4)
    /* 3F0B50 004F0B50 E5FFE014 */  bnez       $7, .L004F0AE8
    /* 3F0B54 004F0B54 040086AC */   sw        $6, 0x4($4)
    /* 3F0B58 004F0B58 08008AAC */  sw         $10, 0x8($4)
  .L004F0B5C:
    /* 3F0B5C 004F0B5C 06000224 */  addiu      $2, $0, 0x6
    /* 3F0B60 004F0B60 06002255 */  bnel       $9, $2, .L004F0B7C
    /* 3F0B64 004F0B64 2D102001 */   daddu     $2, $9, $0
    /* 3F0B68 004F0B68 7600043C */  lui        $4, %hi(D_0075D218)
    /* 3F0B6C 004F0B6C 18D28424 */  addiu      $4, $4, %lo(D_0075D218)
  .L004F0B70:
    /* 3F0B70 004F0B70 F8C1130C */  jal        func_004f07e0
    /* 3F0B74 004F0B74 00000000 */   nop
    /* 3F0B78 004F0B78 FFFF0224 */  addiu      $2, $0, -0x1
  .L004F0B7C:
    /* 3F0B7C 004F0B7C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0B80 004F0B80 0800E003 */  jr         $31
    /* 3F0B84 004F0B84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0ac8, 0xc0
