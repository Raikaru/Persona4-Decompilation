.section .text
.set noat
.set noreorder
glabel func_004effb0
    /* 3EFFB0 004EFFB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFFB4 004EFFB4 7400033C */  lui        $3, %hi(D_00742E04)
    /* 3EFFB8 004EFFB8 0000BFFF */  sd         $31, 0x0($29)
    /* 3EFFBC 004EFFBC 042E6324 */  addiu      $3, $3, %lo(D_00742E04)
    /* 3EFFC0 004EFFC0 0000628C */  lw         $2, 0x0($3)
    /* 3EFFC4 004EFFC4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EFFC8 004EFFC8 05004014 */  bnez       $2, .L004EFFE0
    /* 3EFFCC 004EFFCC 000062AC */   sw        $2, 0x0($3)
    /* 3EFFD0 004EFFD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFFD4 004EFFD4 0A961308 */  j          func_004e5828
    /* 3EFFD8 004EFFD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFFDC 004EFFDC 00000000 */  nop
  .L004EFFE0:
    /* 3EFFE0 004EFFE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFFE4 004EFFE4 0800E003 */  jr         $31
    /* 3EFFE8 004EFFE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFFEC 004EFFEC 00000000 */  nop
.size func_004effb0, 0x40
