.section .text
.set noat
.set noreorder
glabel func_002bc7a0
    /* 1BC7A0 002BC7A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BC7A4 002BC7A4 0000BFFF */  sd         $31, 0x0($29)
    /* 1BC7A8 002BC7A8 2D488000 */  daddu      $9, $4, $0
    /* 1BC7AC 002BC7AC 3C160800 */  dsll32     $2, $8, 24
    /* 1BC7B0 002BC7B0 3F160200 */  dsra32     $2, $2, 24
    /* 1BC7B4 002BC7B4 80180200 */  sll        $3, $2, 2
    /* 1BC7B8 002BC7B8 6400023C */  lui        $2, %hi(D_0063F2B0)
    /* 1BC7BC 002BC7BC B0F24224 */  addiu      $2, $2, %lo(D_0063F2B0)
    /* 1BC7C0 002BC7C0 21104300 */  addu       $2, $2, $3
    /* 1BC7C4 002BC7C4 2D20A000 */  daddu      $4, $5, $0
    /* 1BC7C8 002BC7C8 2D28C000 */  daddu      $5, $6, $0
    /* 1BC7CC 002BC7CC 2D30E000 */  daddu      $6, $7, $0
    /* 1BC7D0 002BC7D0 01000724 */  addiu      $7, $0, 0x1
    /* 1BC7D4 002BC7D4 0000488C */  lw         $8, 0x0($2)
    /* 1BC7D8 002BC7D8 7CE4090C */  jal        func_002791f0
    /* 1BC7DC 002BC7DC 00000000 */   nop
    /* 1BC7E0 002BC7E0 0000BFDF */  ld         $31, 0x0($29)
    /* 1BC7E4 002BC7E4 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BC7E8 002BC7E8 0800E003 */  jr         $31
    /* 1BC7EC 002BC7EC 00000000 */   nop
.size func_002bc7a0, 0x50
