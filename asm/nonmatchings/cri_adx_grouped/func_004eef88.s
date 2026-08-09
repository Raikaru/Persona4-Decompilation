.section .text
.set noat
.set noreorder
glabel func_004eef88
    /* 3EEF88 004EEF88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEF8C 004EEF8C 08008014 */  bnez       $4, .L004EEFB0
    /* 3EEF90 004EEF90 0000BFFF */   sd        $31, 0x0($29)
    /* 3EEF94 004EEF94 7600043C */  lui        $4, %hi(D_0075CF88)
    /* 3EEF98 004EEF98 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EEF9C 004EEF9C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEFA0 004EEFA0 88CF8424 */  addiu      $4, $4, %lo(D_0075CF88)
    /* 3EEFA4 004EEFA4 F8CEA524 */  addiu      $5, $5, %lo(D_0075CEF8)
    /* 3EEFA8 004EEFA8 B6BA1308 */  j          func_004eead8
    /* 3EEFAC 004EEFAC 1000BD27 */   addiu     $29, $29, 0x10
  .L004EEFB0:
    /* 3EEFB0 004EEFB0 04008280 */  lb         $2, 0x4($4)
    /* 3EEFB4 004EEFB4 08004054 */  bnel       $2, $0, .L004EEFD8
    /* 3EEFB8 004EEFB8 1000828C */   lw        $2, 0x10($4)
    /* 3EEFBC 004EEFBC 7600043C */  lui        $4, %hi(D_0075CF98)
    /* 3EEFC0 004EEFC0 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EEFC4 004EEFC4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEFC8 004EEFC8 98CF8424 */  addiu      $4, $4, %lo(D_0075CF98)
    /* 3EEFCC 004EEFCC 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
    /* 3EEFD0 004EEFD0 B6BA1308 */  j          func_004eead8
    /* 3EEFD4 004EEFD4 1000BD27 */   addiu     $29, $29, 0x10
  .L004EEFD8:
    /* 3EEFD8 004EEFD8 2D300000 */  daddu      $6, $0, $0
    /* 3EEFDC 004EEFDC 0C00878C */  lw         $7, 0xC($4)
    /* 3EEFE0 004EEFE0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EEFE4 004EEFE4 0C004018 */  blez       $2, .L004EF018
    /* 3EEFE8 004EEFE8 140087AC */   sw        $7, 0x14($4)
    /* 3EEFEC 004EEFEC 2D28E000 */  daddu      $5, $7, $0
  .L004EEFF0:
    /* 3EEFF0 004EEFF0 0C00A0AC */  sw         $0, 0xC($5)
    /* 3EEFF4 004EEFF4 0100C624 */  addiu      $6, $6, 0x1
    /* 3EEFF8 004EEFF8 1000A324 */  addiu      $3, $5, 0x10
    /* 3EEFFC 004EEFFC 0800A0AC */  sw         $0, 0x8($5)
    /* 3EF000 004EF000 1000828C */  lw         $2, 0x10($4)
    /* 3EF004 004EF004 0000A3AC */  sw         $3, 0x0($5)
    /* 3EF008 004EF008 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EF00C 004EF00C 2A10C200 */  slt        $2, $6, $2
    /* 3EF010 004EF010 F7FF4014 */  bnez       $2, .L004EEFF0
    /* 3EF014 004EF014 2D286000 */   daddu     $5, $3, $0
  .L004EF018:
    /* 3EF018 004EF018 00110600 */  sll        $2, $6, 4
    /* 3EF01C 004EF01C 03000624 */  addiu      $6, $0, 0x3
    /* 3EF020 004EF020 21104700 */  addu       $2, $2, $7
    /* 3EF024 004EF024 24008424 */  addiu      $4, $4, 0x24
    /* 3EF028 004EF028 0C0040AC */  sw         $0, 0xC($2)
    /* 3EF02C 004EF02C 000040AC */  sw         $0, 0x0($2)
    /* 3EF030 004EF030 080040AC */  sw         $0, 0x8($2)
    /* 3EF034 004EF034 00000000 */  nop
  .L004EF038:
    /* 3EF038 004EF038 FFFFC624 */  addiu      $6, $6, -0x1
    /* 3EF03C 004EF03C 000080AC */  sw         $0, 0x0($4)
    /* 3EF040 004EF040 00000000 */  nop
    /* 3EF044 004EF044 00000000 */  nop
    /* 3EF048 004EF048 00000000 */  nop
    /* 3EF04C 004EF04C FAFFC104 */  bgez       $6, .L004EF038
    /* 3EF050 004EF050 FCFF8424 */   addiu     $4, $4, -0x4
    /* 3EF054 004EF054 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF058 004EF058 0800E003 */  jr         $31
    /* 3EF05C 004EF05C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eef88, 0xd8
