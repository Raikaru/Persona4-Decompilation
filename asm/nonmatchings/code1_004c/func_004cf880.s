.section .text
.set noat
.set noreorder
glabel func_004cf880
    /* 3CF880 004CF880 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF884 004CF884 0000B0FF */  sd         $16, 0x0($29)
    /* 3CF888 004CF888 0800BFFF */  sd         $31, 0x8($29)
    /* 3CF88C 004CF88C CE3D130C */  jal        func_004cf738
    /* 3CF890 004CF890 2D808000 */   daddu     $16, $4, $0
    /* 3CF894 004CF894 2D404000 */  daddu      $8, $2, $0
    /* 3CF898 004CF898 1C000011 */  beqz       $8, .L004CF90C
    /* 3CF89C 004CF89C 7200033C */   lui       $3, %hi(D_00723608)
    /* 3CF8A0 004CF8A0 08366424 */  addiu      $4, $3, %lo(D_00723608)
    /* 3CF8A4 004CF8A4 00008280 */  lb         $2, 0x0($4)
    /* 3CF8A8 004CF8A8 0F004010 */  beqz       $2, .L004CF8E8
    /* 3CF8AC 004CF8AC 2D380000 */   daddu     $7, $0, $0
    /* 3CF8B0 004CF8B0 2D308000 */  daddu      $6, $4, $0
    /* 3CF8B4 004CF8B4 2D288000 */  daddu      $5, $4, $0
  .L004CF8B8:
    /* 3CF8B8 004CF8B8 0100E724 */  addiu      $7, $7, 0x1
    /* 3CF8BC 004CF8BC 9000C624 */  addiu      $6, $6, 0x90
    /* 3CF8C0 004CF8C0 1000E328 */  slti       $3, $7, 0x10
    /* 3CF8C4 004CF8C4 09006010 */  beqz       $3, .L004CF8EC
    /* 3CF8C8 004CF8C8 9000A524 */   addiu     $5, $5, 0x90
    /* 3CF8CC 004CF8CC 0000C280 */  lb         $2, 0x0($6)
    /* 3CF8D0 004CF8D0 00000000 */  nop
    /* 3CF8D4 004CF8D4 F8FF4014 */  bnez       $2, .L004CF8B8
    /* 3CF8D8 004CF8D8 2D20A000 */   daddu     $4, $5, $0
    /* 3CF8DC 004CF8DC 04000010 */  b          .L004CF8F0
    /* 3CF8E0 004CF8E0 140090AC */   sw        $16, 0x14($4)
    /* 3CF8E4 004CF8E4 00000000 */  nop
  .L004CF8E8:
    /* 3CF8E8 004CF8E8 01000324 */  addiu      $3, $0, 0x1
  .L004CF8EC:
    /* 3CF8EC 004CF8EC 140090AC */  sw         $16, 0x14($4)
  .L004CF8F0:
    /* 3CF8F0 004CF8F0 05006010 */  beqz       $3, .L004CF908
    /* 3CF8F4 004CF8F4 880088AC */   sw        $8, 0x88($4)
    /* 3CF8F8 004CF8F8 01000324 */  addiu      $3, $0, 0x1
    /* 3CF8FC 004CF8FC 2D108000 */  daddu      $2, $4, $0
    /* 3CF900 004CF900 02000010 */  b          .L004CF90C
    /* 3CF904 004CF904 000083A0 */   sb        $3, 0x0($4)
  .L004CF908:
    /* 3CF908 004CF908 2D100000 */  daddu      $2, $0, $0
  .L004CF90C:
    /* 3CF90C 004CF90C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CF910 004CF910 0800BFDF */  ld         $31, 0x8($29)
    /* 3CF914 004CF914 0800E003 */  jr         $31
    /* 3CF918 004CF918 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CF91C 004CF91C 00000000 */  nop
.size func_004cf880, 0xa0
