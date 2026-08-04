.section .text
.set noat
.set noreorder
glabel func_0043e5b0
    /* 33E5B0 0043E5B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33E5B4 0043E5B4 0000B0FF */  sd         $16, 0x0($29)
    /* 33E5B8 0043E5B8 0800B1FF */  sd         $17, 0x8($29)
    /* 33E5BC 0043E5BC 9400103C */  lui        $16, %hi(D_009389E0)
    /* 33E5C0 0043E5C0 1000BFFF */  sd         $31, 0x10($29)
    /* 33E5C4 0043E5C4 2D888000 */  daddu      $17, $4, $0
    /* 33E5C8 0043E5C8 E08900AE */  sw         $0, %lo(D_009389E0)($16)
    /* 33E5CC 0043E5CC 2D20A000 */  daddu      $4, $5, $0
    /* 33E5D0 0043E5D0 E687100C */  jal        func_00421f98
    /* 33E5D4 0043E5D4 2D28C000 */   daddu     $5, $6, $0
    /* 33E5D8 0043E5D8 FFFF0F24 */  addiu      $15, $0, -0x1
    /* 33E5DC 0043E5DC 05004F54 */  bnel       $2, $15, .L0043E5F4
    /* 33E5E0 0043E5E0 0000B0DF */   ld        $16, 0x0($29)
    /* 33E5E4 0043E5E4 E0890F8E */  lw         $15, %lo(D_009389E0)($16)
    /* 33E5E8 0043E5E8 0100E055 */  bnel       $15, $0, .L0043E5F0
    /* 33E5EC 0043E5EC 00002FAE */   sw        $15, 0x0($17)
  .L0043E5F0:
    /* 33E5F0 0043E5F0 0000B0DF */  ld         $16, 0x0($29)
  .L0043E5F4:
    /* 33E5F4 0043E5F4 0800B1DF */  ld         $17, 0x8($29)
    /* 33E5F8 0043E5F8 1000BFDF */  ld         $31, 0x10($29)
    /* 33E5FC 0043E5FC 0800E003 */  jr         $31
    /* 33E600 0043E600 2000BD27 */   addiu     $29, $29, 0x20
    /* 33E604 0043E604 00000000 */  nop
.size func_0043e5b0, 0x58
