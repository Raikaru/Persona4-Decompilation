.section .text
.set noat
.set noreorder
glabel func_004ea8c8
    /* 3EA8C8 004EA8C8 7400023C */  lui        $2, %hi(D_00739758)
    /* 3EA8CC 004EA8CC D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EA8D0 004EA8D0 58974224 */  addiu      $2, $2, %lo(D_00739758)
    /* 3EA8D4 004EA8D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3EA8D8 004EA8D8 1800B3FF */  sd         $19, 0x18($29)
    /* 3EA8DC 004EA8DC 2D98A000 */  daddu      $19, $5, $0
    /* 3EA8E0 004EA8E0 2D908000 */  daddu      $18, $4, $0
    /* 3EA8E4 004EA8E4 2D204000 */  daddu      $4, $2, $0
    /* 3EA8E8 004EA8E8 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA8EC 004EA8EC 68010624 */  addiu      $6, $0, 0x168
    /* 3EA8F0 004EA8F0 0800B1FF */  sd         $17, 0x8($29)
    /* 3EA8F4 004EA8F4 2000BFFF */  sd         $31, 0x20($29)
    /* 3EA8F8 004EA8F8 DEFD100C */  jal        func_0043f778
    /* 3EA8FC 004EA8FC 2D288000 */   daddu     $5, $4, $0
    /* 3EA900 004EA900 05004056 */  bnel       $18, $0, .L004EA918
    /* 3EA904 004EA904 0004622A */   slti      $2, $19, 0x400
    /* 3EA908 004EA908 7600043C */  lui        $4, %hi(D_0075C480)
    /* 3EA90C 004EA90C 24000010 */  b          .L004EA9A0
    /* 3EA910 004EA910 80C48424 */   addiu     $4, $4, %lo(D_0075C480)
    /* 3EA914 004EA914 00000000 */  nop
  .L004EA918:
    /* 3EA918 004EA918 05004050 */  beql       $2, $0, .L004EA930
    /* 3EA91C 004EA91C 03004232 */   andi      $2, $18, 0x3
    /* 3EA920 004EA920 7600043C */  lui        $4, %hi(D_0075C4A8)
    /* 3EA924 004EA924 1E000010 */  b          .L004EA9A0
    /* 3EA928 004EA928 A8C48424 */   addiu     $4, $4, %lo(D_0075C4A8)
    /* 3EA92C 004EA92C 00000000 */  nop
  .L004EA930:
    /* 3EA930 004EA930 03004010 */  beqz       $2, .L004EA940
    /* 3EA934 004EA934 2D804002 */   daddu     $16, $18, $0
    /* 3EA938 004EA938 23104202 */  subu       $2, $18, $2
    /* 3EA93C 004EA93C 04005024 */  addiu      $16, $2, 0x4
  .L004EA940:
    /* 3EA940 004EA940 2D880002 */  daddu      $17, $16, $0
    /* 3EA944 004EA944 2D280000 */  daddu      $5, $0, $0
    /* 3EA948 004EA948 2D202002 */  daddu      $4, $17, $0
    /* 3EA94C 004EA94C 2C000624 */  addiu      $6, $0, 0x2C
    /* 3EA950 004EA950 72FE100C */  jal        func_0043f9c8
    /* 3EA954 004EA954 2C003026 */   addiu     $16, $17, 0x2C
    /* 3EA958 004EA958 03000232 */  andi       $2, $16, 0x3
    /* 3EA95C 004EA95C 000032AE */  sw         $18, 0x0($17)
    /* 3EA960 004EA960 03004010 */  beqz       $2, .L004EA970
    /* 3EA964 004EA964 040033AE */   sw        $19, 0x4($17)
    /* 3EA968 004EA968 23100202 */  subu       $2, $16, $2
    /* 3EA96C 004EA96C 04005024 */  addiu      $16, $2, 0x4
  .L004EA970:
    /* 3EA970 004EA970 80010226 */  addiu      $2, $16, 0x180
    /* 3EA974 004EA974 080030AE */  sw         $16, 0x8($17)
    /* 3EA978 004EA978 0C0022AE */  sw         $2, 0xC($17)
    /* 3EA97C 004EA97C 92AA130C */  jal        func_004eaa48
    /* 3EA980 004EA980 2D202002 */   daddu     $4, $17, $0
    /* 3EA984 004EA984 00030326 */  addiu      $3, $16, 0x300
    /* 3EA988 004EA988 21105302 */  addu       $2, $18, $19
    /* 3EA98C 004EA98C 2B104300 */  sltu       $2, $2, $3
    /* 3EA990 004EA990 06004050 */  beql       $2, $0, .L004EA9AC
    /* 3EA994 004EA994 2D102002 */   daddu     $2, $17, $0
    /* 3EA998 004EA998 7600043C */  lui        $4, %hi(D_0075C4D0)
    /* 3EA99C 004EA99C D0C48424 */  addiu      $4, $4, %lo(D_0075C4D0)
  .L004EA9A0:
    /* 3EA9A0 004EA9A0 E6A9130C */  jal        func_004ea798
    /* 3EA9A4 004EA9A4 00000000 */   nop
    /* 3EA9A8 004EA9A8 2D100000 */  daddu      $2, $0, $0
  .L004EA9AC:
    /* 3EA9AC 004EA9AC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA9B0 004EA9B0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EA9B4 004EA9B4 1000B2DF */  ld         $18, 0x10($29)
    /* 3EA9B8 004EA9B8 1800B3DF */  ld         $19, 0x18($29)
    /* 3EA9BC 004EA9BC 2000BFDF */  ld         $31, 0x20($29)
    /* 3EA9C0 004EA9C0 0800E003 */  jr         $31
    /* 3EA9C4 004EA9C4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004ea8c8, 0x100
