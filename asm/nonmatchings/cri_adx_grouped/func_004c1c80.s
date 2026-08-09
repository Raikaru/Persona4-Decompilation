.section .text
.set noat
.set noreorder
glabel func_004c1c80
    /* 3C1C80 004C1C80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C1C84 004C1C84 0000B0FF */  sd         $16, 0x0($29)
    /* 3C1C88 004C1C88 2D80A000 */  daddu      $16, $5, $0
    /* 3C1C8C 004C1C8C 0800B1FF */  sd         $17, 0x8($29)
    /* 3C1C90 004C1C90 2D888000 */  daddu      $17, $4, $0
    /* 3C1C94 004C1C94 1000BFFF */  sd         $31, 0x10($29)
    /* 3C1C98 004C1C98 B400228E */  lw         $2, 0xB4($17)
    /* 3C1C9C 004C1C9C 05004010 */  beqz       $2, .L004C1CB4
    /* 3C1CA0 004C1CA0 2D204000 */   daddu     $4, $2, $0
    /* 3C1CA4 004C1CA4 7100023C */  lui        $2, %hi(D_00714A0C)
    /* 3C1CA8 004C1CA8 0C4A438C */  lw         $3, %lo(D_00714A0C)($2)
    /* 3C1CAC 004C1CAC 09F86000 */  jalr       $3
    /* 3C1CB0 004C1CB0 00000000 */   nop
  .L004C1CB4:
    /* 3C1CB4 004C1CB4 60000224 */  addiu      $2, $0, 0x60
    /* 3C1CB8 004C1CB8 B80030AE */  sw         $16, 0xB8($17)
    /* 3C1CBC 004C1CBC 1A000202 */  div        $0, $16, $2
    /* 3C1CC0 004C1CC0 01004050 */  beql       $2, $0, .L004C1CC8
    /* 3C1CC4 004C1CC4 CD010000 */   break     0, 7
  .L004C1CC8:
    /* 3C1CC8 004C1CC8 0000B0DF */  ld         $16, 0x0($29)
    /* 3C1CCC 004C1CCC 1000BFDF */  ld         $31, 0x10($29)
    /* 3C1CD0 004C1CD0 12180000 */  mflo       $3
    /* 3C1CD4 004C1CD4 BC0023AE */  sw         $3, 0xBC($17)
    /* 3C1CD8 004C1CD8 0800B1DF */  ld         $17, 0x8($29)
    /* 3C1CDC 004C1CDC 0800E003 */  jr         $31
    /* 3C1CE0 004C1CE0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3C1CE4 004C1CE4 00000000 */  nop
.size func_004c1c80, 0x68
