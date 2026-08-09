.section .text
.set noat
.set noreorder
glabel func_004d9e10
    /* 3D9E10 004D9E10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D9E14 004D9E14 0000B0FF */  sd         $16, 0x0($29)
    /* 3D9E18 004D9E18 2D808000 */  daddu      $16, $4, $0
    /* 3D9E1C 004D9E1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D9E20 004D9E20 1000B2FF */  sd         $18, 0x10($29)
    /* 3D9E24 004D9E24 7300123C */  lui        $18, %hi(D_007288E8)
    /* 3D9E28 004D9E28 1800BFFF */  sd         $31, 0x18($29)
    /* 3D9E2C 004D9E2C E8884326 */  addiu      $3, $18, %lo(D_007288E8)
    /* 3D9E30 004D9E30 0000628C */  lw         $2, 0x0($3)
    /* 3D9E34 004D9E34 0B004010 */  beqz       $2, .L004D9E64
    /* 3D9E38 004D9E38 2D880000 */   daddu     $17, $0, $0
    /* 3D9E3C 004D9E3C 01003126 */  addiu      $17, $17, 0x1
  .L004D9E40:
    /* 3D9E40 004D9E40 1000222A */  slti       $2, $17, 0x10
    /* 3D9E44 004D9E44 07004010 */  beqz       $2, .L004D9E64
    /* 3D9E48 004D9E48 04006324 */   addiu     $3, $3, 0x4
    /* 3D9E4C 004D9E4C 0000628C */  lw         $2, 0x0($3)
    /* 3D9E50 004D9E50 00000000 */  nop
    /* 3D9E54 004D9E54 00000000 */  nop
    /* 3D9E58 004D9E58 00000000 */  nop
    /* 3D9E5C 004D9E5C F8FF4054 */  bnel       $2, $0, .L004D9E40
    /* 3D9E60 004D9E60 01003126 */   addiu     $17, $17, 0x1
  .L004D9E64:
    /* 3D9E64 004D9E64 10000324 */  addiu      $3, $0, 0x10
    /* 3D9E68 004D9E68 1B002312 */  beq        $17, $3, .L004D9ED8
    /* 3D9E6C 004D9E6C 2D100000 */   daddu     $2, $0, $0
    /* 3D9E70 004D9E70 2D30A000 */  daddu      $6, $5, $0
    /* 3D9E74 004D9E74 2D280000 */  daddu      $5, $0, $0
    /* 3D9E78 004D9E78 72FE100C */  jal        func_0043f9c8
    /* 3D9E7C 004D9E7C 2D200002 */   daddu     $4, $16, $0
    /* 3D9E80 004D9E80 E8884326 */  addiu      $3, $18, %lo(D_007288E8)
    /* 3D9E84 004D9E84 80101100 */  sll        $2, $17, 2
    /* 3D9E88 004D9E88 280A0426 */  addiu      $4, $16, 0xA28
    /* 3D9E8C 004D9E8C 21104300 */  addu       $2, $2, $3
    /* 3D9E90 004D9E90 14100524 */  addiu      $5, $0, 0x1014
    /* 3D9E94 004D9E94 000050AC */  sw         $16, 0x0($2)
    /* 3D9E98 004D9E98 DA75130C */  jal        func_004dd768
    /* 3D9E9C 004D9E9C A60111A2 */   sb        $17, 0x1A6($16)
    /* 3D9EA0 004D9EA0 2D184000 */  daddu      $3, $2, $0
    /* 3D9EA4 004D9EA4 0C006010 */  beqz       $3, .L004D9ED8
    /* 3D9EA8 004D9EA8 B00103AE */   sw        $3, 0x1B0($16)
    /* 3D9EAC 004D9EAC 23000226 */  addiu      $2, $16, 0x23
    /* 3D9EB0 004D9EB0 E0FF0324 */  addiu      $3, $0, -0x20
    /* 3D9EB4 004D9EB4 24104300 */  and        $2, $2, $3
    /* 3D9EB8 004D9EB8 000002AE */  sw         $2, 0x0($16)
    /* 3D9EBC 004D9EBC E4010426 */  addiu      $4, $16, 0x1E4
    /* 3D9EC0 004D9EC0 2D280000 */  daddu      $5, $0, $0
    /* 3D9EC4 004D9EC4 72FE100C */  jal        func_0043f9c8
    /* 3D9EC8 004D9EC8 08000624 */   addiu     $6, $0, 0x8
    /* 3D9ECC 004D9ECC 01000324 */  addiu      $3, $0, 0x1
    /* 3D9ED0 004D9ED0 A40103A2 */  sb         $3, 0x1A4($16)
    /* 3D9ED4 004D9ED4 2D100002 */  daddu      $2, $16, $0
  .L004D9ED8:
    /* 3D9ED8 004D9ED8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D9EDC 004D9EDC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D9EE0 004D9EE0 1000B2DF */  ld         $18, 0x10($29)
    /* 3D9EE4 004D9EE4 1800BFDF */  ld         $31, 0x18($29)
    /* 3D9EE8 004D9EE8 0800E003 */  jr         $31
    /* 3D9EEC 004D9EEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d9e10, 0xe0
