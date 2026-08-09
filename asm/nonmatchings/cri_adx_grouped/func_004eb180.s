.section .text
.set noat
.set noreorder
glabel func_004eb180
    /* 3EB180 004EB180 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EB184 004EB184 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB188 004EB188 2D88C000 */  daddu      $17, $6, $0
    /* 3EB18C 004EB18C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EB190 004EB190 2D90A000 */  daddu      $18, $5, $0
    /* 3EB194 004EB194 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB198 004EB198 09008014 */  bnez       $4, .L004EB1C0
    /* 3EB19C 004EB19C 1800BFFF */   sd        $31, 0x18($29)
    /* 3EB1A0 004EB1A0 7600043C */  lui        $4, %hi(D_0075C620)
    /* 3EB1A4 004EB1A4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB1A8 004EB1A8 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB1AC 004EB1AC 20C68424 */  addiu      $4, $4, %lo(D_0075C620)
    /* 3EB1B0 004EB1B0 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB1B4 004EB1B4 1800BFDF */  ld         $31, 0x18($29)
    /* 3EB1B8 004EB1B8 A61A1308 */  j          func_004c6a98
    /* 3EB1BC 004EB1BC 2000BD27 */   addiu     $29, $29, 0x20
  .L004EB1C0:
    /* 3EB1C0 004EB1C0 0400838C */  lw         $3, 0x4($4)
    /* 3EB1C4 004EB1C4 03008280 */  lb         $2, 0x3($4)
    /* 3EB1C8 004EB1C8 0400708C */  lw         $16, 0x4($3)
    /* 3EB1CC 004EB1CC 02004228 */  slti       $2, $2, 0x2
    /* 3EB1D0 004EB1D0 03004014 */  bnez       $2, .L004EB1E0
    /* 3EB1D4 004EB1D4 E800048E */   lw        $4, 0xE8($16)
    /* 3EB1D8 004EB1D8 09008014 */  bnez       $4, .L004EB200
    /* 3EB1DC 004EB1DC 00000000 */   nop
  .L004EB1E0:
    /* 3EB1E0 004EB1E0 7600043C */  lui        $4, %hi(D_0075C650)
    /* 3EB1E4 004EB1E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB1E8 004EB1E8 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB1EC 004EB1EC 50C68424 */  addiu      $4, $4, %lo(D_0075C650)
    /* 3EB1F0 004EB1F0 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB1F4 004EB1F4 1800BFDF */  ld         $31, 0x18($29)
    /* 3EB1F8 004EB1F8 A61A1308 */  j          func_004c6a98
    /* 3EB1FC 004EB1FC 2000BD27 */   addiu     $29, $29, 0x20
  .L004EB200:
    /* 3EB200 004EB200 96AB130C */  jal        func_004eae58
    /* 3EB204 004EB204 00000000 */   nop
    /* 3EB208 004EB208 F00011AE */  sw         $17, 0xF0($16)
    /* 3EB20C 004EB20C EC0012AE */  sw         $18, 0xEC($16)
    /* 3EB210 004EB210 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB214 004EB214 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB218 004EB218 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB21C 004EB21C 1800BFDF */  ld         $31, 0x18($29)
    /* 3EB220 004EB220 0800E003 */  jr         $31
    /* 3EB224 004EB224 2000BD27 */   addiu     $29, $29, 0x20
.size func_004eb180, 0xa8
