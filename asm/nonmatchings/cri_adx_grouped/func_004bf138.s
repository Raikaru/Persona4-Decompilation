.section .text
.set noat
.set noreorder
glabel func_004bf138
    /* 3BF138 004BF138 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BF13C 004BF13C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BF140 004BF140 2D888000 */  daddu      $17, $4, $0
    /* 3BF144 004BF144 1800B3FF */  sd         $19, 0x18($29)
    /* 3BF148 004BF148 0000B0FF */  sd         $16, 0x0($29)
    /* 3BF14C 004BF14C 1000B2FF */  sd         $18, 0x10($29)
    /* 3BF150 004BF150 2000BFFF */  sd         $31, 0x20($29)
    /* 3BF154 004BF154 5000228E */  lw         $2, 0x50($17)
    /* 3BF158 004BF158 0B004014 */  bnez       $2, .L004BF188
    /* 3BF15C 004BF15C 2D98A000 */   daddu     $19, $5, $0
    /* 3BF160 004BF160 7500043C */  lui        $4, %hi(D_00756FB0)
    /* 3BF164 004BF164 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF168 004BF168 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF16C 004BF16C B06F8424 */  addiu      $4, $4, %lo(D_00756FB0)
    /* 3BF170 004BF170 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF174 004BF174 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF178 004BF178 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF17C 004BF17C A8F51208 */  j          func_004bd6a0
    /* 3BF180 004BF180 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BF184 004BF184 00000000 */  nop
  .L004BF188:
    /* 3BF188 004BF188 A000228E */  lw         $2, 0xA0($17)
    /* 3BF18C 004BF18C 0E004018 */  blez       $2, .L004BF1C8
    /* 3BF190 004BF190 2D900000 */   daddu     $18, $0, $0
    /* 3BF194 004BF194 18003026 */  addiu      $16, $17, 0x18
    /* 3BF198 004BF198 0000048E */  lw         $4, 0x0($16)
    /* 3BF19C 004BF19C 00000000 */  nop
  .L004BF1A0:
    /* 3BF1A0 004BF1A0 0C001026 */  addiu      $16, $16, 0xC
    /* 3BF1A4 004BF1A4 2D286002 */  daddu      $5, $19, $0
    /* 3BF1A8 004BF1A8 0000828C */  lw         $2, 0x0($4)
    /* 3BF1AC 004BF1AC 3800438C */  lw         $3, 0x38($2)
    /* 3BF1B0 004BF1B0 09F86000 */  jalr       $3
    /* 3BF1B4 004BF1B4 01005226 */   addiu     $18, $18, 0x1
    /* 3BF1B8 004BF1B8 A000228E */  lw         $2, 0xA0($17)
    /* 3BF1BC 004BF1BC 2A104202 */  slt        $2, $18, $2
    /* 3BF1C0 004BF1C0 F7FF4054 */  bnel       $2, $0, .L004BF1A0
    /* 3BF1C4 004BF1C4 0000048E */   lw        $4, 0x0($16)
  .L004BF1C8:
    /* 3BF1C8 004BF1C8 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF1CC 004BF1CC 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF1D0 004BF1D0 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF1D4 004BF1D4 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF1D8 004BF1D8 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF1DC 004BF1DC 0800E003 */  jr         $31
    /* 3BF1E0 004BF1E0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BF1E4 004BF1E4 00000000 */  nop
.size func_004bf138, 0xb0
