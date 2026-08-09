.section .text
.set noat
.set noreorder
glabel func_004ed1f0
    /* 3ED1F0 004ED1F0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED1F4 004ED1F4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED1F8 004ED1F8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED1FC 004ED1FC 01000424 */  addiu      $4, $0, 0x1
    /* 3ED200 004ED200 05006414 */  bne        $3, $4, .L004ED218
    /* 3ED204 004ED204 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED208 004ED208 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ED20C 004ED20C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ED210 004ED210 07006018 */  blez       $3, .L004ED230
    /* 3ED214 004ED214 0000BFDF */   ld        $31, 0x0($29)
  .L004ED218:
    /* 3ED218 004ED218 7600043C */  lui        $4, %hi(D_0075CB68)
    /* 3ED21C 004ED21C 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED220 004ED220 68CB8424 */  addiu      $4, $4, %lo(D_0075CB68)
    /* 3ED224 004ED224 FC341308 */  j          func_004cd3f0
    /* 3ED228 004ED228 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED22C 004ED22C 00000000 */  nop
  .L004ED230:
    /* 3ED230 004ED230 0800E003 */  jr         $31
    /* 3ED234 004ED234 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed1f0, 0x48
