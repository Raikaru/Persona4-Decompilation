.section .text
.set noat
.set noreorder
glabel func_004f30c0
    /* 3F30C0 004F30C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F30C4 004F30C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F30C8 004F30C8 2D808000 */  daddu      $16, $4, $0
    /* 3F30CC 004F30CC 04000012 */  beqz       $16, .L004F30E0
    /* 3F30D0 004F30D0 0800BFFF */   sd        $31, 0x8($29)
    /* 3F30D4 004F30D4 2D280000 */  daddu      $5, $0, $0
    /* 3F30D8 004F30D8 72FE100C */  jal        func_0043f9c8
    /* 3F30DC 004F30DC 34000624 */   addiu     $6, $0, 0x34
  .L004F30E0:
    /* 3F30E0 004F30E0 7400023C */  lui        $2, %hi(D_00743A50)
    /* 3F30E4 004F30E4 503A428C */  lw         $2, %lo(D_00743A50)($2)
    /* 3F30E8 004F30E8 2C00438C */  lw         $3, 0x2C($2)
    /* 3F30EC 004F30EC 01000352 */  beql       $16, $3, .L004F30F4
    /* 3F30F0 004F30F0 2C0040AC */   sw        $0, 0x2C($2)
  .L004F30F4:
    /* 3F30F4 004F30F4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F30F8 004F30F8 0800BFDF */  ld         $31, 0x8($29)
    /* 3F30FC 004F30FC 0800E003 */  jr         $31
    /* 3F3100 004F3100 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F3104 004F3104 00000000 */  nop
.size func_004f30c0, 0x48
