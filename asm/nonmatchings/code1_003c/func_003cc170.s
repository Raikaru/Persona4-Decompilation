.section .text
.set noat
.set noreorder
glabel func_003cc170
    /* 2CC170 003CC170 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CC174 003CC174 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CC178 003CC178 0000BFFF */  sd         $31, 0x0($29)
    /* 2CC17C 003CC17C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CC180 003CC180 B8B9838F */  lw         $3, -0x4648($28)
    /* 2CC184 003CC184 21104300 */  addu       $2, $2, $3
    /* 2CC188 003CC188 3C0040AC */  sw         $0, 0x3C($2)
    /* 2CC18C 003CC18C 400040AC */  sw         $0, 0x40($2)
    /* 2CC190 003CC190 440040AC */  sw         $0, 0x44($2)
    /* 2CC194 003CC194 480040AC */  sw         $0, 0x48($2)
    /* 2CC198 003CC198 4C0040AC */  sw         $0, 0x4C($2)
    /* 2CC19C 003CC19C 500040AC */  sw         $0, 0x50($2)
    /* 2CC1A0 003CC1A0 540040AC */  sw         $0, 0x54($2)
    /* 2CC1A4 003CC1A4 580040AC */  sw         $0, 0x58($2)
    /* 2CC1A8 003CC1A8 60530F0C */  jal        func_003d4d80
    /* 2CC1AC 003CC1AC 5C0040AC */   sw        $0, 0x5C($2)
    /* 2CC1B0 003CC1B0 09004014 */  bnez       $2, .L003CC1D8
    /* 2CC1B4 003CC1B4 00000000 */   nop
  .L003CC1B8:
    /* 2CC1B8 003CC1B8 0B004014 */  bnez       $2, .L003CC1E8
    /* 2CC1BC 003CC1BC 00000000 */   nop
  .L003CC1C0:
    /* 2CC1C0 003CC1C0 0D004014 */  bnez       $2, .L003CC1F8
    /* 2CC1C4 003CC1C4 00000000 */   nop
  .L003CC1C8:
    /* 2CC1C8 003CC1C8 0F004010 */  beqz       $2, .L003CC208
    /* 2CC1CC 003CC1CC 00000000 */   nop
    /* 2CC1D0 003CC1D0 16000010 */  b          .L003CC22C
    /* 2CC1D4 003CC1D4 01000224 */   addiu     $2, $0, 0x1
  .L003CC1D8:
    /* 2CC1D8 003CC1D8 A8530F0C */  jal        func_003d4ea0
    /* 2CC1DC 003CC1DC 00000000 */   nop
    /* 2CC1E0 003CC1E0 F5FF0010 */  b          .L003CC1B8
    /* 2CC1E4 003CC1E4 00000000 */   nop
  .L003CC1E8:
    /* 2CC1E8 003CC1E8 84530F0C */  jal        func_003d4e10
    /* 2CC1EC 003CC1EC 00000000 */   nop
    /* 2CC1F0 003CC1F0 F3FF0010 */  b          .L003CC1C0
    /* 2CC1F4 003CC1F4 00000000 */   nop
  .L003CC1F8:
    /* 2CC1F8 003CC1F8 DC300F0C */  jal        func_003cc370
    /* 2CC1FC 003CC1FC 00000000 */   nop
    /* 2CC200 003CC200 F1FF0010 */  b          .L003CC1C8
    /* 2CC204 003CC204 00000000 */   nop
  .L003CC208:
    /* 2CC208 003CC208 18310F0C */  jal        func_003cc460
    /* 2CC20C 003CC20C 00000000 */   nop
    /* 2CC210 003CC210 80530F0C */  jal        func_003d4e00
    /* 2CC214 003CC214 00000000 */   nop
    /* 2CC218 003CC218 A4530F0C */  jal        func_003d4e90
    /* 2CC21C 003CC21C 00000000 */   nop
    /* 2CC220 003CC220 5C530F0C */  jal        func_003d4d70
    /* 2CC224 003CC224 00000000 */   nop
    /* 2CC228 003CC228 2D100000 */  daddu      $2, $0, $0
  .L003CC22C:
    /* 2CC22C 003CC22C 0000BFDF */  ld         $31, 0x0($29)
    /* 2CC230 003CC230 0800E003 */  jr         $31
    /* 2CC234 003CC234 1000BD27 */   addiu     $29, $29, 0x10
    /* 2CC238 003CC238 00000000 */  nop
    /* 2CC23C 003CC23C 00000000 */  nop
.size func_003cc170, 0xd0
