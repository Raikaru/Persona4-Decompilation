.section .text
.set noat
.set noreorder
glabel func_0052b9a0
    /* 42B9A0 0052B9A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42B9A4 0052B9A4 7400023C */  lui        $2, %hi(D_00745C78)
    /* 42B9A8 0052B9A8 0000BFFF */  sd         $31, 0x0($29)
    /* 42B9AC 0052B9AC 785C4224 */  addiu      $2, $2, %lo(D_00745C78)
    /* 42B9B0 0052B9B0 2D28C000 */  daddu      $5, $6, $0
    /* 42B9B4 0052B9B4 0800438C */  lw         $3, 0x8($2)
    /* 42B9B8 0052B9B8 0000468C */  lw         $6, 0x0($2)
    /* 42B9BC 0052B9BC 01006324 */  addiu      $3, $3, 0x1
    /* 42B9C0 0052B9C0 0400448C */  lw         $4, 0x4($2)
    /* 42B9C4 0052B9C4 0300C010 */  beqz       $6, .L0052B9D4
    /* 42B9C8 0052B9C8 080043AC */   sw        $3, 0x8($2)
    /* 42B9CC 0052B9CC 09F8C000 */  jalr       $6
    /* 42B9D0 0052B9D0 00000000 */   nop
  .L0052B9D4:
    /* 42B9D4 0052B9D4 0000BFDF */  ld         $31, 0x0($29)
    /* 42B9D8 0052B9D8 0800E003 */  jr         $31
    /* 42B9DC 0052B9DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052b9a0, 0x40
