.section .text
.set noat
.set noreorder
glabel func_0043bb70
    /* 33BB70 0043BB70 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 33BB74 0043BB74 0100A524 */  addiu      $5, $5, 0x1
    /* 33BB78 0043BB78 1000B1FF */  sd         $17, 0x10($29)
    /* 33BB7C 0043BB7C 2D108000 */  daddu      $2, $4, $0
    /* 33BB80 0043BB80 2000B2FF */  sd         $18, 0x20($29)
    /* 33BB84 0043BB84 7100113C */  lui        $17, %hi(D_0070FC64)
    /* 33BB88 0043BB88 64FC25AE */  sw         $5, %lo(D_0070FC64)($17)
    /* 33BB8C 0043BB8C 7100123C */  lui        $18, %hi(D_0070FC68)
    /* 33BB90 0043BB90 4000BFFF */  sd         $31, 0x40($29)
    /* 33BB94 0043BB94 3000B3FF */  sd         $19, 0x30($29)
    /* 33BB98 0043BB98 0000B0FF */  sd         $16, 0x0($29)
    /* 33BB9C 0043BB9C 03004014 */  bnez       $2, .L0043BBAC
    /* 33BBA0 0043BBA0 68FC46AE */   sw        $6, %lo(D_0070FC68)($18)
    /* 33BBA4 0043BBA4 2A000010 */  b          .L0043BC50
    /* 33BBA8 0043BBA8 FFFF0224 */   addiu     $2, $0, -0x1
  .L0043BBAC:
    /* 33BBAC 0043BBAC 64FC258E */  lw         $5, %lo(D_0070FC64)($17)
    /* 33BBB0 0043BBB0 0C001324 */  addiu      $19, $0, 0xC
    /* 33BBB4 0043BBB4 7100103C */  lui        $16, %hi(D_0070FC58)
    /* 33BBB8 0043BBB8 2D204000 */  daddu      $4, $2, $0
    /* 33BBBC 0043BBBC 1800B300 */  mult       $0, $5, $19
    /* 33BBC0 0043BBC0 12280000 */  mflo       $5
    /* 33BBC4 0043BBC4 B6F1100C */  jal        func_0043c6d8
    /* 33BBC8 0043BBC8 58FC02AE */   sw        $2, %lo(D_0070FC58)($16)
    /* 33BBCC 0043BBCC 58FC098E */  lw         $9, %lo(D_0070FC58)($16)
    /* 33BBD0 0043BBD0 0080023C */  lui        $2, (0x80005010 >> 16)
    /* 33BBD4 0043BBD4 10504234 */  ori        $2, $2, (0x80005010 & 0xFFFF)
    /* 33BBD8 0043BBD8 7100043C */  lui        $4, %hi(D_0070FC70)
    /* 33BBDC 0043BBDC 000022AD */  sw         $2, 0x0($9)
    /* 33BBE0 0043BBE0 1C00033C */  lui        $3, (0x1C0000 >> 16)
    /* 33BBE4 0043BBE4 70FC83AC */  sw         $3, %lo(D_0070FC70)($4)
    /* 33BBE8 0043BBE8 1B00083C */  lui        $8, (0x1BAFF0 >> 16)
    /* 33BBEC 0043BBEC F0AF0835 */  ori        $8, $8, (0x1BAFF0 & 0xFFFF)
    /* 33BBF0 0043BBF0 68FC428E */  lw         $2, %lo(D_0070FC68)($18)
    /* 33BBF4 0043BBF4 04004010 */  beqz       $2, .L0043BC08
    /* 33BBF8 0043BBF8 2000023C */   lui       $2, (0x200000 >> 16)
    /* 33BBFC 0043BBFC 1F00083C */  lui        $8, (0x1FAFF0 >> 16)
    /* 33BC00 0043BC00 70FC82AC */  sw         $2, %lo(D_0070FC70)($4)
    /* 33BC04 0043BC04 F0AF0835 */  ori        $8, $8, (0x1FAFF0 & 0xFFFF)
  .L0043BC08:
    /* 33BC08 0043BC08 040028AD */  sw         $8, 0x4($9)
    /* 33BC0C 0043BC0C 7100023C */  lui        $2, %hi(D_0070FC6C)
    /* 33BC10 0043BC10 6CFC48AC */  sw         $8, %lo(D_0070FC6C)($2)
    /* 33BC14 0043BC14 7100053C */  lui        $5, %hi(D_0070FC78)
    /* 33BC18 0043BC18 78FCA224 */  addiu      $2, $5, %lo(D_0070FC78)
    /* 33BC1C 0043BC1C 7100063C */  lui        $6, %hi(D_0070FC5C)
    /* 33BC20 0043BC20 64FC238E */  lw         $3, %lo(D_0070FC64)($17)
    /* 33BC24 0043BC24 7100073C */  lui        $7, %hi(D_0070FC60)
    /* 33BC28 0043BC28 040048AC */  sw         $8, 0x4($2)
    /* 33BC2C 0043BC2C 10500424 */  addiu      $4, $0, 0x5010
    /* 33BC30 0043BC30 18187300 */  mult       $3, $3, $19
    /* 33BC34 0043BC34 78FCA4AC */  sw         $4, %lo(D_0070FC78)($5)
    /* 33BC38 0043BC38 5CFCC9AC */  sw         $9, %lo(D_0070FC5C)($6)
    /* 33BC3C 0043BC3C 2D100000 */  daddu      $2, $0, $0
    /* 33BC40 0043BC40 080020AD */  sw         $0, 0x8($9)
    /* 33BC44 0043BC44 F4FF6324 */  addiu      $3, $3, -0xC
    /* 33BC48 0043BC48 21182301 */  addu       $3, $9, $3
    /* 33BC4C 0043BC4C 60FCE3AC */  sw         $3, %lo(D_0070FC60)($7)
  .L0043BC50:
    /* 33BC50 0043BC50 4000BFDF */  ld         $31, 0x40($29)
    /* 33BC54 0043BC54 3000B3DF */  ld         $19, 0x30($29)
    /* 33BC58 0043BC58 2000B2DF */  ld         $18, 0x20($29)
    /* 33BC5C 0043BC5C 1000B1DF */  ld         $17, 0x10($29)
    /* 33BC60 0043BC60 0000B0DF */  ld         $16, 0x0($29)
    /* 33BC64 0043BC64 0800E003 */  jr         $31
    /* 33BC68 0043BC68 5000BD27 */   addiu     $29, $29, 0x50
    /* 33BC6C 0043BC6C 00000000 */  nop
.size func_0043bb70, 0x100
