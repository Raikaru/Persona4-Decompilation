.section .text
.set noat
.set noreorder
glabel func_002bafc0
    /* 1BAFC0 002BAFC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BAFC4 002BAFC4 1000BFFF */  sd         $31, 0x10($29)
    /* 1BAFC8 002BAFC8 0000B07F */  sq         $16, 0x0($29)
    /* 1BAFCC 002BAFCC 3C160400 */  dsll32     $2, $4, 24
    /* 1BAFD0 002BAFD0 3F160200 */  dsra32     $2, $2, 24
    /* 1BAFD4 002BAFD4 80180200 */  sll        $3, $2, 2
    /* 1BAFD8 002BAFD8 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BAFDC 002BAFDC 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BAFE0 002BAFE0 21804300 */  addu       $16, $2, $3
    /* 1BAFE4 002BAFE4 0000038E */  lw         $3, 0x0($16)
    /* 1BAFE8 002BAFE8 04006014 */  bnez       $3, .L002BAFFC
    /* 1BAFEC 002BAFEC 00000000 */   nop
    /* 1BAFF0 002BAFF0 2D100000 */  daddu      $2, $0, $0
    /* 1BAFF4 002BAFF4 0E000010 */  b          .L002BB030
    /* 1BAFF8 002BAFF8 00000000 */   nop
  .L002BAFFC:
    /* 1BAFFC 002BAFFC 0000628C */  lw         $2, 0x0($3)
    /* 1BB000 002BB000 04004104 */  bgez       $2, .L002BB014
    /* 1BB004 002BB004 00000000 */   nop
    /* 1BB008 002BB008 2D100000 */  daddu      $2, $0, $0
    /* 1BB00C 002BB00C 08000010 */  b          .L002BB030
    /* 1BB010 002BB010 00000000 */   nop
  .L002BB014:
    /* 1BB014 002BB014 080065AC */  sw         $5, 0x8($3)
    /* 1BB018 002BB018 38EC0A0C */  jal        func_002bb0e0
    /* 1BB01C 002BB01C 00000000 */   nop
    /* 1BB020 002BB020 0000038E */  lw         $3, 0x0($16)
    /* 1BB024 002BB024 0D0062A0 */  sb         $2, 0xD($3)
    /* 1BB028 002BB028 78B580A3 */  sb         $0, -0x4A88($28)
    /* 1BB02C 002BB02C 01000224 */  addiu      $2, $0, 0x1
  .L002BB030:
    /* 1BB030 002BB030 1000BFDF */  ld         $31, 0x10($29)
    /* 1BB034 002BB034 0000B07B */  lq         $16, 0x0($29)
    /* 1BB038 002BB038 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BB03C 002BB03C 0800E003 */  jr         $31
    /* 1BB040 002BB040 00000000 */   nop
    /* 1BB044 002BB044 00000000 */  nop
    /* 1BB048 002BB048 00000000 */  nop
    /* 1BB04C 002BB04C 00000000 */  nop
.size func_002bafc0, 0x90
