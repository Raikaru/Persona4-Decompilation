.section .text
.set noat
.set noreorder
glabel func_003dea20
    /* 2DEA20 003DEA20 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2DEA24 003DEA24 6000BFFF */  sd         $31, 0x60($29)
    /* 2DEA28 003DEA28 5000B57F */  sq         $21, 0x50($29)
    /* 2DEA2C 003DEA2C 4000B47F */  sq         $20, 0x40($29)
    /* 2DEA30 003DEA30 2DA88000 */  daddu      $21, $4, $0
    /* 2DEA34 003DEA34 3000B37F */  sq         $19, 0x30($29)
    /* 2DEA38 003DEA38 2DA0A000 */  daddu      $20, $5, $0
    /* 2DEA3C 003DEA3C 2000B27F */  sq         $18, 0x20($29)
    /* 2DEA40 003DEA40 2D98C000 */  daddu      $19, $6, $0
    /* 2DEA44 003DEA44 1000B17F */  sq         $17, 0x10($29)
    /* 2DEA48 003DEA48 2D90E000 */  daddu      $18, $7, $0
    /* 2DEA4C 003DEA4C 2D880001 */  daddu      $17, $8, $0
    /* 2DEA50 003DEA50 0000B07F */  sq         $16, 0x0($29)
    /* 2DEA54 003DEA54 40760F0C */  jal        func_003dd900
    /* 2DEA58 003DEA58 2D202002 */   daddu     $4, $17, $0
    /* 2DEA5C 003DEA5C 03004010 */  beqz       $2, .L003DEA6C
    /* 2DEA60 003DEA60 00000000 */   nop
    /* 2DEA64 003DEA64 A3000010 */  b          .L003DECF4
    /* 2DEA68 003DEA68 2D100000 */   daddu     $2, $0, $0
  .L003DEA6C:
    /* 2DEA6C 003DEA6C 0400023C */  lui        $2, (0x401BE >> 16)
    /* 2DEA70 003DEA70 BE014534 */  ori        $5, $2, (0x401BE & 0xFFFF)
    /* 2DEA74 003DEA74 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2DEA78 003DEA78 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2DEA7C 003DEA7C 09F84000 */  jalr       $2
    /* 2DEA80 003DEA80 5C000424 */   addiu     $4, $0, 0x5C
    /* 2DEA84 003DEA84 3E00033C */  lui        $3, %hi(func_003de280)
    /* 2DEA88 003DEA88 2D804000 */  daddu      $16, $2, $0
    /* 2DEA8C 003DEA8C 80E26324 */  addiu      $3, $3, %lo(func_003de280)
    /* 2DEA90 003DEA90 2D20A002 */  daddu      $4, $21, $0
    /* 2DEA94 003DEA94 140043AC */  sw         $3, 0x14($2)
    /* 2DEA98 003DEA98 3E00033C */  lui        $3, %hi(func_003de2d0)
    /* 2DEA9C 003DEA9C D0E26324 */  addiu      $3, $3, %lo(func_003de2d0)
    /* 2DEAA0 003DEAA0 180043AC */  sw         $3, 0x18($2)
    /* 2DEAA4 003DEAA4 3E00033C */  lui        $3, %hi(func_003de2c0)
    /* 2DEAA8 003DEAA8 C0E26324 */  addiu      $3, $3, %lo(func_003de2c0)
    /* 2DEAAC 003DEAAC 1C0043AC */  sw         $3, 0x1C($2)
    /* 2DEAB0 003DEAB0 3E00033C */  lui        $3, %hi(func_003de2d0 + 0x20)
    /* 2DEAB4 003DEAB4 F0E26324 */  addiu      $3, $3, %lo(func_003de2d0 + 0x20)
    /* 2DEAB8 003DEAB8 280043AC */  sw         $3, 0x28($2)
    /* 2DEABC 003DEABC 3E00033C */  lui        $3, %hi(func_003de4c0)
    /* 2DEAC0 003DEAC0 C0E46324 */  addiu      $3, $3, %lo(func_003de4c0)
    /* 2DEAC4 003DEAC4 2C0043AC */  sw         $3, 0x2C($2)
    /* 2DEAC8 003DEAC8 3E00033C */  lui        $3, %hi(func_003de4d0)
    /* 2DEACC 003DEACC D0E46324 */  addiu      $3, $3, %lo(func_003de4d0)
    /* 2DEAD0 003DEAD0 300043AC */  sw         $3, 0x30($2)
    /* 2DEAD4 003DEAD4 3E00033C */  lui        $3, %hi(func_003de6a0)
    /* 2DEAD8 003DEAD8 A0E66324 */  addiu      $3, $3, %lo(func_003de6a0)
    /* 2DEADC 003DEADC 340043AC */  sw         $3, 0x34($2)
    /* 2DEAE0 003DEAE0 3E00033C */  lui        $3, %hi(func_003de740)
    /* 2DEAE4 003DEAE4 40E76324 */  addiu      $3, $3, %lo(func_003de740)
    /* 2DEAE8 003DEAE8 380043AC */  sw         $3, 0x38($2)
    /* 2DEAEC 003DEAEC 3E00033C */  lui        $3, %hi(func_003de8c0)
    /* 2DEAF0 003DEAF0 C0E86324 */  addiu      $3, $3, %lo(func_003de8c0)
    /* 2DEAF4 003DEAF4 3C0043AC */  sw         $3, 0x3C($2)
    /* 2DEAF8 003DEAF8 3E00033C */  lui        $3, %hi(func_003de9b0)
    /* 2DEAFC 003DEAFC B0E96324 */  addiu      $3, $3, %lo(func_003de9b0)
    /* 2DEB00 003DEB00 400043AC */  sw         $3, 0x40($2)
    /* 2DEB04 003DEB04 3E00033C */  lui        $3, %hi(func_003dd590)
    /* 2DEB08 003DEB08 90D56324 */  addiu      $3, $3, %lo(func_003dd590)
    /* 2DEB0C 003DEB0C 440043AC */  sw         $3, 0x44($2)
    /* 2DEB10 003DEB10 3E00033C */  lui        $3, %hi(func_003de9c0)
    /* 2DEB14 003DEB14 C0E96324 */  addiu      $3, $3, %lo(func_003de9c0)
    /* 2DEB18 003DEB18 480043AC */  sw         $3, 0x48($2)
    /* 2DEB1C 003DEB1C 3E00033C */  lui        $3, %hi(func_003dea10)
    /* 2DEB20 003DEB20 10EA6324 */  addiu      $3, $3, %lo(func_003dea10)
    /* 2DEB24 003DEB24 4C0043AC */  sw         $3, 0x4C($2)
    /* 2DEB28 003DEB28 0400023C */  lui        $2, (0x401BE >> 16)
    /* 2DEB2C 003DEB2C BE014634 */  ori        $6, $2, (0x401BE & 0xFFFF)
    /* 2DEB30 003DEB30 8800023C */  lui        $2, %hi(D_008873F4)
    /* 2DEB34 003DEB34 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 2DEB38 003DEB38 09F84000 */  jalr       $2
    /* 2DEB3C 003DEB3C 70000524 */   addiu     $5, $0, 0x70
    /* 2DEB40 003DEB40 580002AE */  sw         $2, 0x58($16)
    /* 2DEB44 003DEB44 2A081500 */  slt        $1, $0, $21
    /* 2DEB48 003DEB48 58000C8E */  lw         $12, 0x58($16)
    /* 2DEB4C 003DEB4C 56002010 */  beqz       $1, .L003DECA8
    /* 2DEB50 003DEB50 2D680000 */   daddu     $13, $0, $0
    /* 2DEB54 003DEB54 0900A12A */  slti       $1, $21, 0x9
    /* 2DEB58 003DEB58 41002014 */  bnez       $1, .L003DEC60
    /* 2DEB5C 003DEB5C F8FFA926 */   addiu     $9, $21, -0x8
    /* 2DEB60 003DEB60 2A08A002 */  slt        $1, $21, $0
    /* 2DEB64 003DEB64 07002014 */  bnez       $1, .L003DEB84
    /* 2DEB68 003DEB68 2D100000 */   daddu     $2, $0, $0
    /* 2DEB6C 003DEB6C FF7F013C */  lui        $1, (0x7FFFFFFF >> 16)
    /* 2DEB70 003DEB70 FFFF2134 */  ori        $1, $1, (0x7FFFFFFF & 0xFFFF)
    /* 2DEB74 003DEB74 2A08A102 */  slt        $1, $21, $1
    /* 2DEB78 003DEB78 02002010 */  beqz       $1, .L003DEB84
    /* 2DEB7C 003DEB7C 00000000 */   nop
    /* 2DEB80 003DEB80 01000224 */  addiu      $2, $0, 0x1
  .L003DEB84:
    /* 2DEB84 003DEB84 36004010 */  beqz       $2, .L003DEC60
    /* 2DEB88 003DEB88 00000000 */   nop
    /* 2DEB8C 003DEB8C 40381300 */  sll        $7, $19, 1
    /* 2DEB90 003DEB90 C0401300 */  sll        $8, $19, 3
    /* 2DEB94 003DEB94 2130F300 */  addu       $6, $7, $19
    /* 2DEB98 003DEB98 80281300 */  sll        $5, $19, 2
    /* 2DEB9C 003DEB9C 2D588001 */  daddu      $11, $12, $0
    /* 2DEBA0 003DEBA0 2D500000 */  daddu      $10, $0, $0
    /* 2DEBA4 003DEBA4 2120B300 */  addu       $4, $5, $19
    /* 2DEBA8 003DEBA8 40180600 */  sll        $3, $6, 1
    /* 2DEBAC 003DEBAC 23101301 */  subu       $2, $8, $19
  .L003DEBB0:
    /* 2DEBB0 003DEBB0 500070AD */  sw         $16, 0x50($11)
    /* 2DEBB4 003DEBB4 21708A02 */  addu       $14, $20, $10
    /* 2DEBB8 003DEBB8 68006EAD */  sw         $14, 0x68($11)
    /* 2DEBBC 003DEBBC 0800AD25 */  addiu      $13, $13, 0x8
    /* 2DEBC0 003DEBC0 21705301 */  addu       $14, $10, $19
    /* 2DEBC4 003DEBC4 6C0073AD */  sw         $19, 0x6C($11)
    /* 2DEBC8 003DEBC8 21788E02 */  addu       $15, $20, $14
    /* 2DEBCC 003DEBCC C00070AD */  sw         $16, 0xC0($11)
    /* 2DEBD0 003DEBD0 D8006FAD */  sw         $15, 0xD8($11)
    /* 2DEBD4 003DEBD4 21704701 */  addu       $14, $10, $7
    /* 2DEBD8 003DEBD8 DC0073AD */  sw         $19, 0xDC($11)
    /* 2DEBDC 003DEBDC 21788E02 */  addu       $15, $20, $14
    /* 2DEBE0 003DEBE0 300170AD */  sw         $16, 0x130($11)
    /* 2DEBE4 003DEBE4 21704601 */  addu       $14, $10, $6
    /* 2DEBE8 003DEBE8 48016FAD */  sw         $15, 0x148($11)
    /* 2DEBEC 003DEBEC 21C08E02 */  addu       $24, $20, $14
    /* 2DEBF0 003DEBF0 4C0173AD */  sw         $19, 0x14C($11)
    /* 2DEBF4 003DEBF4 21704501 */  addu       $14, $10, $5
    /* 2DEBF8 003DEBF8 A00170AD */  sw         $16, 0x1A0($11)
    /* 2DEBFC 003DEBFC 21788E02 */  addu       $15, $20, $14
    /* 2DEC00 003DEC00 B80178AD */  sw         $24, 0x1B8($11)
    /* 2DEC04 003DEC04 21704401 */  addu       $14, $10, $4
    /* 2DEC08 003DEC08 BC0173AD */  sw         $19, 0x1BC($11)
    /* 2DEC0C 003DEC0C 21C88E02 */  addu       $25, $20, $14
    /* 2DEC10 003DEC10 100270AD */  sw         $16, 0x210($11)
    /* 2DEC14 003DEC14 21704301 */  addu       $14, $10, $3
    /* 2DEC18 003DEC18 28026FAD */  sw         $15, 0x228($11)
    /* 2DEC1C 003DEC1C 21C08E02 */  addu       $24, $20, $14
    /* 2DEC20 003DEC20 2C0273AD */  sw         $19, 0x22C($11)
    /* 2DEC24 003DEC24 21704201 */  addu       $14, $10, $2
    /* 2DEC28 003DEC28 800270AD */  sw         $16, 0x280($11)
    /* 2DEC2C 003DEC2C 21788E02 */  addu       $15, $20, $14
    /* 2DEC30 003DEC30 980279AD */  sw         $25, 0x298($11)
    /* 2DEC34 003DEC34 2A70A901 */  slt        $14, $13, $9
    /* 2DEC38 003DEC38 9C0273AD */  sw         $19, 0x29C($11)
    /* 2DEC3C 003DEC3C 21504801 */  addu       $10, $10, $8
    /* 2DEC40 003DEC40 F00270AD */  sw         $16, 0x2F0($11)
    /* 2DEC44 003DEC44 080378AD */  sw         $24, 0x308($11)
    /* 2DEC48 003DEC48 0C0373AD */  sw         $19, 0x30C($11)
    /* 2DEC4C 003DEC4C 600370AD */  sw         $16, 0x360($11)
    /* 2DEC50 003DEC50 78036FAD */  sw         $15, 0x378($11)
    /* 2DEC54 003DEC54 7C0373AD */  sw         $19, 0x37C($11)
    /* 2DEC58 003DEC58 D5FFC015 */  bnez       $14, .L003DEBB0
    /* 2DEC5C 003DEC5C 80036B25 */   addiu     $11, $11, 0x380
  .L003DEC60:
    /* 2DEC60 003DEC60 2A08B501 */  slt        $1, $13, $21
    /* 2DEC64 003DEC64 10002010 */  beqz       $1, .L003DECA8
    /* 2DEC68 003DEC68 00000000 */   nop
    /* 2DEC6C 003DEC6C C0100D00 */  sll        $2, $13, 3
    /* 2DEC70 003DEC70 23104D00 */  subu       $2, $2, $13
    /* 2DEC74 003DEC74 00110200 */  sll        $2, $2, 4
    /* 2DEC78 003DEC78 21208201 */  addu       $4, $12, $2
    /* 2DEC7C 003DEC7C 1818B301 */  mult       $3, $13, $19
  .L003DEC80:
    /* 2DEC80 003DEC80 21108302 */  addu       $2, $20, $3
    /* 2DEC84 003DEC84 500090AC */  sw         $16, 0x50($4)
    /* 2DEC88 003DEC88 680082AC */  sw         $2, 0x68($4)
    /* 2DEC8C 003DEC8C 0100AD25 */  addiu      $13, $13, 0x1
    /* 2DEC90 003DEC90 6C0093AC */  sw         $19, 0x6C($4)
    /* 2DEC94 003DEC94 2A10B501 */  slt        $2, $13, $21
    /* 2DEC98 003DEC98 21187300 */  addu       $3, $3, $19
    /* 2DEC9C 003DEC9C F8FF4014 */  bnez       $2, .L003DEC80
    /* 2DECA0 003DECA0 70008424 */   addiu     $4, $4, 0x70
    /* 2DECA4 003DECA4 00000000 */  nop
  .L003DECA8:
    /* 2DECA8 003DECA8 2D28A002 */  daddu      $5, $21, $0
    /* 2DECAC 003DECAC 2D302002 */  daddu      $6, $17, $0
    /* 2DECB0 003DECB0 2D384002 */  daddu      $7, $18, $0
    /* 2DECB4 003DECB4 A4740F0C */  jal        func_003dd290
    /* 2DECB8 003DECB8 2D200002 */   daddu     $4, $16, $0
    /* 2DECBC 003DECBC 01000324 */  addiu      $3, $0, 0x1
    /* 2DECC0 003DECC0 03004314 */  bne        $2, $3, .L003DECD0
    /* 2DECC4 003DECC4 00000000 */   nop
    /* 2DECC8 003DECC8 0A000010 */  b          .L003DECF4
    /* 2DECCC 003DECCC 2D100002 */   daddu     $2, $16, $0
  .L003DECD0:
    /* 2DECD0 003DECD0 8800113C */  lui        $17, %hi(jtbl_008873EC)
    /* 2DECD4 003DECD4 EC733126 */  addiu      $17, $17, %lo(jtbl_008873EC)
    /* 2DECD8 003DECD8 0000228E */  lw         $2, 0x0($17)
    /* 2DECDC 003DECDC 09F84000 */  jalr       $2
    /* 2DECE0 003DECE0 5800048E */   lw        $4, 0x58($16)
    /* 2DECE4 003DECE4 0000228E */  lw         $2, 0x0($17)
    /* 2DECE8 003DECE8 09F84000 */  jalr       $2
    /* 2DECEC 003DECEC 2D200002 */   daddu     $4, $16, $0
    /* 2DECF0 003DECF0 2D100000 */  daddu      $2, $0, $0
  .L003DECF4:
    /* 2DECF4 003DECF4 6000BFDF */  ld         $31, 0x60($29)
    /* 2DECF8 003DECF8 5000B57B */  lq         $21, 0x50($29)
    /* 2DECFC 003DECFC 4000B47B */  lq         $20, 0x40($29)
    /* 2DED00 003DED00 3000B37B */  lq         $19, 0x30($29)
    /* 2DED04 003DED04 2000B27B */  lq         $18, 0x20($29)
    /* 2DED08 003DED08 1000B17B */  lq         $17, 0x10($29)
    /* 2DED0C 003DED0C 0000B07B */  lq         $16, 0x0($29)
    /* 2DED10 003DED10 0800E003 */  jr         $31
    /* 2DED14 003DED14 7000BD27 */   addiu     $29, $29, 0x70
    /* 2DED18 003DED18 00000000 */  nop
    /* 2DED1C 003DED1C 00000000 */  nop
.size func_003dea20, 0x300
