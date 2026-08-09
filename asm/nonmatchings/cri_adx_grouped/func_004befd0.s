.section .text
.set noat
.set noreorder
glabel func_004befd0
    /* 3BEFD0 004BEFD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BEFD4 004BEFD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BEFD8 004BEFD8 2D808000 */  daddu      $16, $4, $0
    /* 3BEFDC 004BEFDC 1800B3FF */  sd         $19, 0x18($29)
    /* 3BEFE0 004BEFE0 2D98A000 */  daddu      $19, $5, $0
    /* 3BEFE4 004BEFE4 2000B4FF */  sd         $20, 0x20($29)
    /* 3BEFE8 004BEFE8 0800B1FF */  sd         $17, 0x8($29)
    /* 3BEFEC 004BEFEC 1000B2FF */  sd         $18, 0x10($29)
    /* 3BEFF0 004BEFF0 2800BFFF */  sd         $31, 0x28($29)
    /* 3BEFF4 004BEFF4 5000028E */  lw         $2, 0x50($16)
    /* 3BEFF8 004BEFF8 0B004014 */  bnez       $2, .L004BF028
    /* 3BEFFC 004BEFFC 2DA0C000 */   daddu     $20, $6, $0
    /* 3BF000 004BF000 7500043C */  lui        $4, %hi(D_00756F78)
    /* 3BF004 004BF004 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF008 004BF008 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF00C 004BF00C 786F8424 */  addiu      $4, $4, %lo(D_00756F78)
    /* 3BF010 004BF010 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF014 004BF014 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF018 004BF018 2000B4DF */  ld         $20, 0x20($29)
    /* 3BF01C 004BF01C 2800BFDF */  ld         $31, 0x28($29)
    /* 3BF020 004BF020 A8F51208 */  j          func_004bd6a0
    /* 3BF024 004BF024 3000BD27 */   addiu     $29, $29, 0x30
  .L004BF028:
    /* 3BF028 004BF028 9400028E */  lw         $2, 0x94($16)
    /* 3BF02C 004BF02C 25004050 */  beql       $2, $0, .L004BF0C4
    /* 3BF030 004BF030 0000B0DF */   ld        $16, 0x0($29)
    /* 3BF034 004BF034 23006206 */  bltzl      $19, .L004BF0C4
    /* 3BF038 004BF038 0000B0DF */   ld        $16, 0x0($29)
    /* 3BF03C 004BF03C 8400028E */  lw         $2, 0x84($16)
    /* 3BF040 004BF040 2A106202 */  slt        $2, $19, $2
    /* 3BF044 004BF044 1F004050 */  beql       $2, $0, .L004BF0C4
    /* 3BF048 004BF048 0000B0DF */   ld        $16, 0x0($29)
    /* 3BF04C 004BF04C C000048E */  lw         $4, 0xC0($16)
    /* 3BF050 004BF050 1B008010 */  beqz       $4, .L004BF0C0
    /* 3BF054 004BF054 80101300 */   sll       $2, $19, 2
    /* 3BF058 004BF058 01000324 */  addiu      $3, $0, 0x1
    /* 3BF05C 004BF05C 21104400 */  addu       $2, $2, $4
    /* 3BF060 004BF060 000054AC */  sw         $20, 0x0($2)
    /* 3BF064 004BF064 A4000482 */  lb         $4, 0xA4($16)
    /* 3BF068 004BF068 05008354 */  bnel       $4, $3, .L004BF080
    /* 3BF06C 004BF06C A000028E */   lw        $2, 0xA0($16)
    /* 3BF070 004BF070 6000028E */  lw         $2, 0x60($16)
    /* 3BF074 004BF074 13004454 */  bnel       $2, $4, .L004BF0C4
    /* 3BF078 004BF078 0000B0DF */   ld        $16, 0x0($29)
    /* 3BF07C 004BF07C A000028E */  lw         $2, 0xA0($16)
  .L004BF080:
    /* 3BF080 004BF080 0F004018 */  blez       $2, .L004BF0C0
    /* 3BF084 004BF084 2D900000 */   daddu     $18, $0, $0
    /* 3BF088 004BF088 18001126 */  addiu      $17, $16, 0x18
    /* 3BF08C 004BF08C 0000248E */  lw         $4, 0x0($17)
  .L004BF090:
    /* 3BF090 004BF090 0C003126 */  addiu      $17, $17, 0xC
    /* 3BF094 004BF094 BC00068E */  lw         $6, 0xBC($16)
    /* 3BF098 004BF098 2D286002 */  daddu      $5, $19, $0
    /* 3BF09C 004BF09C 0000828C */  lw         $2, 0x0($4)
    /* 3BF0A0 004BF0A0 01005226 */  addiu      $18, $18, 0x1
    /* 3BF0A4 004BF0A4 3000438C */  lw         $3, 0x30($2)
    /* 3BF0A8 004BF0A8 09F86000 */  jalr       $3
    /* 3BF0AC 004BF0AC 2130D400 */   addu      $6, $6, $20
    /* 3BF0B0 004BF0B0 A000028E */  lw         $2, 0xA0($16)
    /* 3BF0B4 004BF0B4 2A104202 */  slt        $2, $18, $2
    /* 3BF0B8 004BF0B8 F5FF4054 */  bnel       $2, $0, .L004BF090
    /* 3BF0BC 004BF0BC 0000248E */   lw        $4, 0x0($17)
  .L004BF0C0:
    /* 3BF0C0 004BF0C0 0000B0DF */  ld         $16, 0x0($29)
  .L004BF0C4:
    /* 3BF0C4 004BF0C4 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF0C8 004BF0C8 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF0CC 004BF0CC 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF0D0 004BF0D0 2000B4DF */  ld         $20, 0x20($29)
    /* 3BF0D4 004BF0D4 2800BFDF */  ld         $31, 0x28($29)
    /* 3BF0D8 004BF0D8 0800E003 */  jr         $31
    /* 3BF0DC 004BF0DC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004befd0, 0x110
