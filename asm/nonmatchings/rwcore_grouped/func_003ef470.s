.section .text
.set noat
.set noreorder
glabel func_003ef470
    /* 2EF470 003EF470 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2EF474 003EF474 8800023C */  lui        $2, %hi(D_008873B0)
    /* 2EF478 003EF478 2000BFFF */  sd         $31, 0x20($29)
    /* 2EF47C 003EF47C 20000624 */  addiu      $6, $0, 0x20
    /* 2EF480 003EF480 1000B17F */  sq         $17, 0x10($29)
    /* 2EF484 003EF484 0000B07F */  sq         $16, 0x0($29)
    /* 2EF488 003EF488 2D888000 */  daddu      $17, $4, $0
    /* 2EF48C 003EF48C B073428C */  lw         $2, %lo(D_008873B0)($2)
    /* 2EF490 003EF490 2D80A000 */  daddu      $16, $5, $0
    /* 2EF494 003EF494 09F84000 */  jalr       $2
    /* 2EF498 003EF498 10002426 */   addiu     $4, $17, 0x10
    /* 2EF49C 003EF49C 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2EF4A0 003EF4A0 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2EF4A4 003EF4A4 09F84000 */  jalr       $2
    /* 2EF4A8 003EF4A8 2D200002 */   daddu     $4, $16, $0
    /* 2EF4AC 003EF4AC 2000412C */  sltiu      $1, $2, 0x20
    /* 2EF4B0 003EF4B0 03002010 */  beqz       $1, .L003EF4C0
    /* 2EF4B4 003EF4B4 00000000 */   nop
  .L003EF4B8:
    /* 2EF4B8 003EF4B8 0F000010 */  b          .L003EF4F8
    /* 2EF4BC 003EF4BC 2D102002 */   daddu     $2, $17, $0
  .L003EF4C0:
    /* 2EF4C0 003EF4C0 1F000882 */  lb         $8, 0x1F($16)
    /* 2EF4C4 003EF4C4 01000224 */  addiu      $2, $0, 0x1
    /* 2EF4C8 003EF4C8 3800A2AF */  sw         $2, 0x38($29)
    /* 2EF4CC 003EF4CC 2D280002 */  daddu      $5, $16, $0
    /* 2EF4D0 003EF4D0 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EF4D4 003EF4D4 20000624 */  addiu      $6, $0, 0x20
    /* 2EF4D8 003EF4D8 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EF4DC 003EF4DC 647D0F0C */  jal        func_003df590
    /* 2EF4E0 003EF4E0 1F000724 */   addiu     $7, $0, 0x1F
    /* 2EF4E4 003EF4E4 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2EF4E8 003EF4E8 347D0F0C */  jal        func_003df4d0
    /* 2EF4EC 003EF4EC 3800A427 */   addiu     $4, $29, 0x38
    /* 2EF4F0 003EF4F0 F1FF0010 */  b          .L003EF4B8
    /* 2EF4F4 003EF4F4 2F0020A2 */   sb        $0, 0x2F($17)
  .L003EF4F8:
    /* 2EF4F8 003EF4F8 2000BFDF */  ld         $31, 0x20($29)
    /* 2EF4FC 003EF4FC 1000B17B */  lq         $17, 0x10($29)
    /* 2EF500 003EF500 0000B07B */  lq         $16, 0x0($29)
    /* 2EF504 003EF504 0800E003 */  jr         $31
    /* 2EF508 003EF508 4000BD27 */   addiu     $29, $29, 0x40
    /* 2EF50C 003EF50C 00000000 */  nop
.size func_003ef470, 0xa0
