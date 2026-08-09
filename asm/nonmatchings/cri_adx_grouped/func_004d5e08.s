.section .text
.set noat
.set noreorder
glabel func_004d5e08
    /* 3D5E08 004D5E08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D5E0C 004D5E0C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D5E10 004D5E10 2D908000 */  daddu      $18, $4, $0
    /* 3D5E14 004D5E14 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5E18 004D5E18 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5E1C 004D5E1C 0A004016 */  bnez       $18, .L004D5E48
    /* 3D5E20 004D5E20 1800BFFF */   sd        $31, 0x18($29)
    /* 3D5E24 004D5E24 7600043C */  lui        $4, %hi(D_00759130)
    /* 3D5E28 004D5E28 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5E2C 004D5E2C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5E30 004D5E30 30918424 */  addiu      $4, $4, %lo(D_00759130)
    /* 3D5E34 004D5E34 1000B2DF */  ld         $18, 0x10($29)
    /* 3D5E38 004D5E38 1800BFDF */  ld         $31, 0x18($29)
    /* 3D5E3C 004D5E3C A61A1308 */  j          func_004c6a98
    /* 3D5E40 004D5E40 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D5E44 004D5E44 00000000 */  nop
  .L004D5E48:
    /* 3D5E48 004D5E48 1400438E */  lw         $3, 0x14($18)
    /* 3D5E4C 004D5E4C 2D800000 */  daddu      $16, $0, $0
    /* 3D5E50 004D5E50 6C0045A2 */  sb         $5, 0x6C($18)
    /* 3D5E54 004D5E54 06006010 */  beqz       $3, .L004D5E70
    /* 3D5E58 004D5E58 2D206000 */   daddu     $4, $3, $0
    /* 3D5E5C 004D5E5C 0000638C */  lw         $3, 0x0($3)
    /* 3D5E60 004D5E60 2400628C */  lw         $2, 0x24($3)
    /* 3D5E64 004D5E64 09F84000 */  jalr       $2
    /* 3D5E68 004D5E68 01000524 */   addiu     $5, $0, 0x1
    /* 3D5E6C 004D5E6C 2D804000 */  daddu      $16, $2, $0
  .L004D5E70:
    /* 3D5E70 004D5E70 FC3A130C */  jal        func_004cebf0
    /* 3D5E74 004D5E74 0400448E */   lw        $4, 0x4($18)
    /* 3D5E78 004D5E78 0400448E */  lw         $4, 0x4($18)
    /* 3D5E7C 004D5E7C A03B130C */  jal        func_004cee80
    /* 3D5E80 004D5E80 21805000 */   addu      $16, $2, $16
    /* 3D5E84 004D5E84 0400448E */  lw         $4, 0x4($18)
    /* 3D5E88 004D5E88 2D884000 */  daddu      $17, $2, $0
    /* 3D5E8C 004D5E8C FF072226 */  addiu      $2, $17, 0x7FF
    /* 3D5E90 004D5E90 FE0F2526 */  addiu      $5, $17, 0xFFE
    /* 3D5E94 004D5E94 00004328 */  slti       $3, $2, 0x0
    /* 3D5E98 004D5E98 0B10A300 */  movn       $2, $5, $3
    /* 3D5E9C 004D5E9C C3120200 */  sra        $2, $2, 11
    /* 3D5EA0 004D5EA0 B23B130C */  jal        func_004ceec8
    /* 3D5EA4 004D5EA4 C08A0200 */   sll       $17, $2, 11
    /* 3D5EA8 004D5EA8 FF074324 */  addiu      $3, $2, 0x7FF
    /* 3D5EAC 004D5EAC FE0F4224 */  addiu      $2, $2, 0xFFE
    /* 3D5EB0 004D5EB0 00006428 */  slti       $4, $3, 0x0
    /* 3D5EB4 004D5EB4 0B184400 */  movn       $3, $2, $4
    /* 3D5EB8 004D5EB8 C31A0300 */  sra        $3, $3, 11
    /* 3D5EBC 004D5EBC C01A0300 */  sll        $3, $3, 11
    /* 3D5EC0 004D5EC0 23187100 */  subu       $3, $3, $17
    /* 3D5EC4 004D5EC4 0400601C */  bgtz       $3, .L004D5ED8
    /* 3D5EC8 004D5EC8 23801102 */   subu      $16, $16, $17
    /* 3D5ECC 004D5ECC 09000010 */  b          .L004D5EF4
    /* 3D5ED0 004D5ED0 C40040AE */   sw        $0, 0xC4($18)
    /* 3D5ED4 004D5ED4 00000000 */  nop
  .L004D5ED8:
    /* 3D5ED8 004D5ED8 1A000302 */  div        $0, $16, $3
    /* 3D5EDC 004D5EDC 01006050 */  beql       $3, $0, .L004D5EE4
    /* 3D5EE0 004D5EE0 CD010000 */   break     0, 7
  .L004D5EE4:
    /* 3D5EE4 004D5EE4 12100000 */  mflo       $2
    /* 3D5EE8 004D5EE8 18204300 */  mult       $4, $2, $3
    /* 3D5EEC 004D5EEC 21109100 */  addu       $2, $4, $17
    /* 3D5EF0 004D5EF0 C40042AE */  sw         $2, 0xC4($18)
  .L004D5EF4:
    /* 3D5EF4 004D5EF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5EF8 004D5EF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5EFC 004D5EFC 1000B2DF */  ld         $18, 0x10($29)
    /* 3D5F00 004D5F00 1800BFDF */  ld         $31, 0x18($29)
    /* 3D5F04 004D5F04 0800E003 */  jr         $31
    /* 3D5F08 004D5F08 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D5F0C 004D5F0C 00000000 */  nop
.size func_004d5e08, 0x108
