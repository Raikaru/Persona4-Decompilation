.section .text
.set noat
.set noreorder
glabel func_0050ba08
    /* 40BA08 0050BA08 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 40BA0C 0050BA0C 0000B0FF */  sd         $16, 0x0($29)
    /* 40BA10 0050BA10 2D808000 */  daddu      $16, $4, $0
    /* 40BA14 0050BA14 0800B1FF */  sd         $17, 0x8($29)
    /* 40BA18 0050BA18 2D88A000 */  daddu      $17, $5, $0
    /* 40BA1C 0050BA1C 1800B3FF */  sd         $19, 0x18($29)
    /* 40BA20 0050BA20 2D980000 */  daddu      $19, $0, $0
    /* 40BA24 0050BA24 1000B2FF */  sd         $18, 0x10($29)
    /* 40BA28 0050BA28 2000B4FF */  sd         $20, 0x20($29)
    /* 40BA2C 0050BA2C 0A000012 */  beqz       $16, .L0050BA58
    /* 40BA30 0050BA30 2800BFFF */   sd        $31, 0x28($29)
    /* 40BA34 0050BA34 9833140C */  jal        func_0050ce60
    /* 40BA38 0050BA38 00000000 */   nop
    /* 40BA3C 0050BA3C 7400033C */  lui        $3, %hi(D_00745870)
    /* 40BA40 0050BA40 2D904000 */  daddu      $18, $2, $0
    /* 40BA44 0050BA44 7400023C */  lui        $2, %hi(D_0074586C)
    /* 40BA48 0050BA48 6C5850AC */  sw         $16, %lo(D_0074586C)($2)
    /* 40BA4C 0050BA4C 07000010 */  b          .L0050BA6C
    /* 40BA50 0050BA50 705872AC */   sw        $18, %lo(D_00745870)($3)
    /* 40BA54 0050BA54 00000000 */  nop
  .L0050BA58:
    /* 40BA58 0050BA58 7400023C */  lui        $2, %hi(D_0074586C)
    /* 40BA5C 0050BA5C 7400033C */  lui        $3, %hi(D_00745870)
    /* 40BA60 0050BA60 6C5840AC */  sw         $0, %lo(D_0074586C)($2)
    /* 40BA64 0050BA64 2D900000 */  daddu      $18, $0, $0
    /* 40BA68 0050BA68 705860AC */  sw         $0, %lo(D_00745870)($3)
  .L0050BA6C:
    /* 40BA6C 0050BA6C 0B002012 */  beqz       $17, .L0050BA9C
    /* 40BA70 0050BA70 9300023C */   lui       $2, %hi(D_0092AA60)
    /* 40BA74 0050BA74 60AA4524 */  addiu      $5, $2, %lo(D_0092AA60)
    /* 40BA78 0050BA78 0000A48C */  lw         $4, 0x0($5)
    /* 40BA7C 0050BA7C 80100400 */  sll        $2, $4, 2
    /* 40BA80 0050BA80 0F008328 */  slti       $3, $4, 0xF
    /* 40BA84 0050BA84 9300013C */  lui        $1, %hi(D_0092AA20)
    /* 40BA88 0050BA88 21082200 */  addu       $1, $1, $2
    /* 40BA8C 0050BA8C 20AA31AC */  sw         $17, %lo(D_0092AA20)($1)
    /* 40BA90 0050BA90 02006010 */  beqz       $3, .L0050BA9C
    /* 40BA94 0050BA94 01008224 */   addiu     $2, $4, 0x1
    /* 40BA98 0050BA98 0000A2AC */  sw         $2, 0x0($5)
  .L0050BA9C:
    /* 40BA9C 0050BA9C 00FF023C */  lui        $2, (0xFF000F18 >> 16)
    /* 40BAA0 0050BAA0 180F4234 */  ori        $2, $2, (0xFF000F18 & 0xFFFF)
    /* 40BAA4 0050BAA4 2A105100 */  slt        $2, $2, $17
    /* 40BAA8 0050BAA8 1D004014 */  bnez       $2, .L0050BB20
    /* 40BAAC 0050BAAC 00000000 */   nop
    /* 40BAB0 0050BAB0 00FF023C */  lui        $2, (0xFF000F17 >> 16)
    /* 40BAB4 0050BAB4 170F4234 */  ori        $2, $2, (0xFF000F17 & 0xFFFF)
    /* 40BAB8 0050BAB8 2A102202 */  slt        $2, $17, $2
    /* 40BABC 0050BABC 46004010 */  beqz       $2, .L0050BBD8
    /* 40BAC0 0050BAC0 9300143C */   lui       $20, %hi(D_0092AA68)
    /* 40BAC4 0050BAC4 00FF023C */  lui        $2, (0xFF00040C >> 16)
    /* 40BAC8 0050BAC8 0C044234 */  ori        $2, $2, (0xFF00040C & 0xFFFF)
    /* 40BACC 0050BACC 46002212 */  beq        $17, $2, .L0050BBE8
    /* 40BAD0 0050BAD0 2A105100 */   slt       $2, $2, $17
    /* 40BAD4 0050BAD4 08004014 */  bnez       $2, .L0050BAF8
    /* 40BAD8 0050BAD8 00000000 */   nop
    /* 40BADC 0050BADC 00FF023C */  lui        $2, (0xFF000408 >> 16)
    /* 40BAE0 0050BAE0 08044234 */  ori        $2, $2, (0xFF000408 & 0xFFFF)
    /* 40BAE4 0050BAE4 41002212 */  beq        $17, $2, .L0050BBEC
    /* 40BAE8 0050BAE8 7600053C */   lui       $5, %hi(D_0075EB10)
    /* 40BAEC 0050BAEC 5F000010 */  b          .L0050BC6C
    /* 40BAF0 0050BAF0 7600053C */   lui       $5, %hi(D_0075ECA8)
    /* 40BAF4 0050BAF4 00000000 */  nop
  .L0050BAF8:
    /* 40BAF8 0050BAF8 00FF023C */  lui        $2, (0xFF000C04 >> 16)
    /* 40BAFC 0050BAFC 040C4234 */  ori        $2, $2, (0xFF000C04 & 0xFFFF)
    /* 40BB00 0050BB00 49002212 */  beq        $17, $2, .L0050BC28
    /* 40BB04 0050BB04 9300143C */   lui       $20, %hi(D_0092AA68)
    /* 40BB08 0050BB08 00FF023C */  lui        $2, (0xFF000F15 >> 16)
    /* 40BB0C 0050BB0C 150F4234 */  ori        $2, $2, (0xFF000F15 & 0xFFFF)
    /* 40BB10 0050BB10 3D002212 */  beq        $17, $2, .L0050BC08
    /* 40BB14 0050BB14 7600053C */   lui       $5, %hi(D_0075EB68)
    /* 40BB18 0050BB18 54000010 */  b          .L0050BC6C
    /* 40BB1C 0050BB1C 7600053C */   lui       $5, %hi(D_0075ECA8)
  .L0050BB20:
    /* 40BB20 0050BB20 00FF023C */  lui        $2, (0xFF000F40 >> 16)
    /* 40BB24 0050BB24 400F4234 */  ori        $2, $2, (0xFF000F40 & 0xFFFF)
    /* 40BB28 0050BB28 17002212 */  beq        $17, $2, .L0050BB88
    /* 40BB2C 0050BB2C 2A105100 */   slt       $2, $2, $17
    /* 40BB30 0050BB30 0B004014 */  bnez       $2, .L0050BB60
    /* 40BB34 0050BB34 FFFF222A */   slti      $2, $17, -0x1
    /* 40BB38 0050BB38 00FF023C */  lui        $2, (0xFF000F1C >> 16)
    /* 40BB3C 0050BB3C 1C0F4234 */  ori        $2, $2, (0xFF000F1C & 0xFFFF)
    /* 40BB40 0050BB40 29002212 */  beq        $17, $2, .L0050BBE8
    /* 40BB44 0050BB44 9300143C */   lui       $20, %hi(D_0092AA68)
    /* 40BB48 0050BB48 00FF023C */  lui        $2, (0xFF000F1F >> 16)
    /* 40BB4C 0050BB4C 1F0F4234 */  ori        $2, $2, (0xFF000F1F & 0xFFFF)
    /* 40BB50 0050BB50 3D002212 */  beq        $17, $2, .L0050BC48
    /* 40BB54 0050BB54 7600053C */   lui       $5, %hi(D_0075EC60)
    /* 40BB58 0050BB58 44000010 */  b          .L0050BC6C
    /* 40BB5C 0050BB5C 7600053C */   lui       $5, %hi(D_0075ECA8)
  .L0050BB60:
    /* 40BB60 0050BB60 41004010 */  beqz       $2, .L0050BC68
    /* 40BB64 0050BB64 9300143C */   lui       $20, %hi(D_0092AA68)
    /* 40BB68 0050BB68 FDFF222A */  slti       $2, $17, -0x3
    /* 40BB6C 0050BB6C 3F004054 */  bnel       $2, $0, .L0050BC6C
    /* 40BB70 0050BB70 7600053C */   lui       $5, %hi(D_0075ECA8)
    /* 40BB74 0050BB74 9300143C */  lui        $20, %hi(D_0092AA68)
    /* 40BB78 0050BB78 7600053C */  lui        $5, %hi(D_0075EA80)
    /* 40BB7C 0050BB7C 1C000010 */  b          .L0050BBF0
    /* 40BB80 0050BB80 80EAA524 */   addiu     $5, $5, %lo(D_0075EA80)
    /* 40BB84 0050BB84 00000000 */  nop
  .L0050BB88:
    /* 40BB88 0050BB88 9300143C */  lui        $20, %hi(D_0092AA68)
    /* 40BB8C 0050BB8C 7600053C */  lui        $5, %hi(D_0075EA98)
    /* 40BB90 0050BB90 68AA9026 */  addiu      $16, $20, %lo(D_0092AA68)
    /* 40BB94 0050BB94 00FF063C */  lui        $6, (0xFF000F40 >> 16)
    /* 40BB98 0050BB98 98EAA524 */  addiu      $5, $5, %lo(D_0075EA98)
    /* 40BB9C 0050BB9C 2D200002 */  daddu      $4, $16, $0
    /* 40BBA0 0050BBA0 2208110C */  jal        func_00442088
    /* 40BBA4 0050BBA4 400FC634 */   ori       $6, $6, (0xFF000F40 & 0xFFFF)
    /* 40BBA8 0050BBA8 04004012 */  beqz       $18, .L0050BBBC
    /* 40BBAC 0050BBAC 00000000 */   nop
    /* 40BBB0 0050BBB0 B882140C */  jal        func_00520ae0
    /* 40BBB4 0050BBB4 2D204002 */   daddu     $4, $18, $0
    /* 40BBB8 0050BBB8 2D984000 */  daddu      $19, $2, $0
  .L0050BBBC:
    /* 40BBBC 0050BBBC 2F006012 */  beqz       $19, .L0050BC7C
    /* 40BBC0 0050BBC0 2D200002 */   daddu     $4, $16, $0
    /* 40BBC4 0050BBC4 2D286002 */  daddu      $5, $19, $0
    /* 40BBC8 0050BBC8 A00A110C */  jal        func_00442a80
    /* 40BBCC 0050BBCC E9000624 */   addiu     $6, $0, 0xE9
    /* 40BBD0 0050BBD0 2B000010 */  b          .L0050BC80
    /* 40BBD4 0050BBD4 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
  .L0050BBD8:
    /* 40BBD8 0050BBD8 7600053C */  lui        $5, %hi(D_0075EAB0)
    /* 40BBDC 0050BBDC 04000010 */  b          .L0050BBF0
    /* 40BBE0 0050BBE0 B0EAA524 */   addiu     $5, $5, %lo(D_0075EAB0)
    /* 40BBE4 0050BBE4 00000000 */  nop
  .L0050BBE8:
    /* 40BBE8 0050BBE8 7600053C */  lui        $5, %hi(D_0075EB10)
  .L0050BBEC:
    /* 40BBEC 0050BBEC 10EBA524 */  addiu      $5, $5, %lo(D_0075EB10)
  .L0050BBF0:
    /* 40BBF0 0050BBF0 2D302002 */  daddu      $6, $17, $0
    /* 40BBF4 0050BBF4 2208110C */  jal        func_00442088
    /* 40BBF8 0050BBF8 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
    /* 40BBFC 0050BBFC 20000010 */  b          .L0050BC80
    /* 40BC00 0050BC00 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
    /* 40BC04 0050BC04 00000000 */  nop
  .L0050BC08:
    /* 40BC08 0050BC08 00FF063C */  lui        $6, (0xFF000F15 >> 16)
    /* 40BC0C 0050BC0C 68EBA524 */  addiu      $5, $5, %lo(D_0075EB68)
    /* 40BC10 0050BC10 68AA8426 */  addiu      $4, $20, %lo(D_0092AA68)
    /* 40BC14 0050BC14 2208110C */  jal        func_00442088
    /* 40BC18 0050BC18 150FC634 */   ori       $6, $6, (0xFF000F15 & 0xFFFF)
    /* 40BC1C 0050BC1C 18000010 */  b          .L0050BC80
    /* 40BC20 0050BC20 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
    /* 40BC24 0050BC24 00000000 */  nop
  .L0050BC28:
    /* 40BC28 0050BC28 7600053C */  lui        $5, %hi(D_0075EBD8)
    /* 40BC2C 0050BC2C 00FF063C */  lui        $6, (0xFF000C04 >> 16)
    /* 40BC30 0050BC30 D8EBA524 */  addiu      $5, $5, %lo(D_0075EBD8)
    /* 40BC34 0050BC34 68AA8426 */  addiu      $4, $20, %lo(D_0092AA68)
    /* 40BC38 0050BC38 2208110C */  jal        func_00442088
    /* 40BC3C 0050BC3C 040CC634 */   ori       $6, $6, (0xFF000C04 & 0xFFFF)
    /* 40BC40 0050BC40 0F000010 */  b          .L0050BC80
    /* 40BC44 0050BC44 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
  .L0050BC48:
    /* 40BC48 0050BC48 00FF063C */  lui        $6, (0xFF000F1F >> 16)
    /* 40BC4C 0050BC4C 60ECA524 */  addiu      $5, $5, %lo(D_0075EC60)
    /* 40BC50 0050BC50 68AA8426 */  addiu      $4, $20, %lo(D_0092AA68)
    /* 40BC54 0050BC54 2208110C */  jal        func_00442088
    /* 40BC58 0050BC58 1F0FC634 */   ori       $6, $6, (0xFF000F1F & 0xFFFF)
    /* 40BC5C 0050BC5C 08000010 */  b          .L0050BC80
    /* 40BC60 0050BC60 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
    /* 40BC64 0050BC64 00000000 */  nop
  .L0050BC68:
    /* 40BC68 0050BC68 7600053C */  lui        $5, %hi(D_0075ECA8)
  .L0050BC6C:
    /* 40BC6C 0050BC6C A8ECA524 */  addiu      $5, $5, %lo(D_0075ECA8)
    /* 40BC70 0050BC70 2D302002 */  daddu      $6, $17, $0
    /* 40BC74 0050BC74 2208110C */  jal        func_00442088
    /* 40BC78 0050BC78 68AA8426 */   addiu     $4, $20, %lo(D_0092AA68)
  .L0050BC7C:
    /* 40BC7C 0050BC7C 68AA8426 */  addiu      $4, $20, %lo(D_0092AA68)
  .L0050BC80:
    /* 40BC80 0050BC80 2000B4DF */  ld         $20, 0x20($29)
    /* 40BC84 0050BC84 0000B0DF */  ld         $16, 0x0($29)
    /* 40BC88 0050BC88 0800B1DF */  ld         $17, 0x8($29)
    /* 40BC8C 0050BC8C 1000B2DF */  ld         $18, 0x10($29)
    /* 40BC90 0050BC90 1800B3DF */  ld         $19, 0x18($29)
    /* 40BC94 0050BC94 2800BFDF */  ld         $31, 0x28($29)
    /* 40BC98 0050BC98 88441408 */  j          func_00511220
    /* 40BC9C 0050BC9C 3000BD27 */   addiu     $29, $29, 0x30
.size func_0050ba08, 0x298
