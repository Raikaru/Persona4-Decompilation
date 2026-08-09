.section .text
.set noat
.set noreorder
glabel func_0043eb40
    /* 33EB40 0043EB40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33EB44 0043EB44 0800B1FF */  sd         $17, 0x8($29)
    /* 33EB48 0043EB48 0000B0FF */  sd         $16, 0x0($29)
    /* 33EB4C 0043EB4C 2D888000 */  daddu      $17, $4, $0
    /* 33EB50 0043EB50 1000BFFF */  sd         $31, 0x10($29)
    /* 33EB54 0043EB54 2D20A000 */  daddu      $4, $5, $0
    /* 33EB58 0043EB58 9400103C */  lui        $16, %hi(D_009389E0)
    /* 33EB5C 0043EB5C 2D28C000 */  daddu      $5, $6, $0
    /* 33EB60 0043EB60 E08900AE */  sw         $0, %lo(D_009389E0)($16)
    /* 33EB64 0043EB64 B687100C */  jal        func_00421ed8
    /* 33EB68 0043EB68 2D30E000 */   daddu     $6, $7, $0
    /* 33EB6C 0043EB6C FFFF0F24 */  addiu      $15, $0, -0x1
    /* 33EB70 0043EB70 05004F54 */  bnel       $2, $15, .L0043EB88
    /* 33EB74 0043EB74 0000B0DF */   ld        $16, 0x0($29)
    /* 33EB78 0043EB78 E0890F8E */  lw         $15, %lo(D_009389E0)($16)
    /* 33EB7C 0043EB7C 0100E055 */  bnel       $15, $0, .L0043EB84
    /* 33EB80 0043EB80 00002FAE */   sw        $15, 0x0($17)
  .L0043EB84:
    /* 33EB84 0043EB84 0000B0DF */  ld         $16, 0x0($29)
  .L0043EB88:
    /* 33EB88 0043EB88 0800B1DF */  ld         $17, 0x8($29)
    /* 33EB8C 0043EB8C 1000BFDF */  ld         $31, 0x10($29)
    /* 33EB90 0043EB90 0800E003 */  jr         $31
    /* 33EB94 0043EB94 2000BD27 */   addiu     $29, $29, 0x20
.size func_0043eb40, 0x58
