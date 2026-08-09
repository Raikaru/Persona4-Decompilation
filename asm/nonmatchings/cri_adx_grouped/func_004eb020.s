.section .text
.set noat
.set noreorder
glabel func_004eb020
    /* 3EB020 004EB020 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EB024 004EB024 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB028 004EB028 2D808000 */  daddu      $16, $4, $0
    /* 3EB02C 004EB02C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EB030 004EB030 2D90C000 */  daddu      $18, $6, $0
    /* 3EB034 004EB034 1800B3FF */  sd         $19, 0x18($29)
    /* 3EB038 004EB038 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB03C 004EB03C 2000BFFF */  sd         $31, 0x20($29)
    /* 3EB040 004EB040 03000282 */  lb         $2, 0x3($16)
    /* 3EB044 004EB044 02004228 */  slti       $2, $2, 0x2
    /* 3EB048 004EB048 0B004010 */  beqz       $2, .L004EB078
    /* 3EB04C 004EB04C 2D98A000 */   daddu     $19, $5, $0
    /* 3EB050 004EB050 7600043C */  lui        $4, %hi(D_0075C5A8)
    /* 3EB054 004EB054 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB058 004EB058 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB05C 004EB05C A8C58424 */  addiu      $4, $4, %lo(D_0075C5A8)
    /* 3EB060 004EB060 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB064 004EB064 1800B3DF */  ld         $19, 0x18($29)
    /* 3EB068 004EB068 2000BFDF */  ld         $31, 0x20($29)
    /* 3EB06C 004EB06C A61A1308 */  j          func_004c6a98
    /* 3EB070 004EB070 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EB074 004EB074 00000000 */  nop
  .L004EB078:
    /* 3EB078 004EB078 C250130C */  jal        func_004d4308
    /* 3EB07C 004EB07C 00000000 */   nop
    /* 3EB080 004EB080 56AC130C */  jal        func_004eb158
    /* 3EB084 004EB084 2D200002 */   daddu     $4, $16, $0
    /* 3EB088 004EB088 4F00043C */  lui        $4, %hi(func_004eb300)
    /* 3EB08C 004EB08C 2D280000 */  daddu      $5, $0, $0
    /* 3EB090 004EB090 D0A9130C */  jal        func_004ea740
    /* 3EB094 004EB094 00B38424 */   addiu     $4, $4, %lo(func_004eb300)
    /* 3EB098 004EB098 F2A9130C */  jal        func_004ea7c8
    /* 3EB09C 004EB09C 2D200000 */   daddu     $4, $0, $0
    /* 3EB0A0 004EB0A0 0400028E */  lw         $2, 0x4($16)
    /* 3EB0A4 004EB0A4 7432130C */  jal        func_004cc9d0
    /* 3EB0A8 004EB0A8 0400518C */   lw        $17, 0x4($2)
    /* 3EB0AC 004EB0AC 2D206002 */  daddu      $4, $19, $0
    /* 3EB0B0 004EB0B0 20AA130C */  jal        func_004ea880
    /* 3EB0B4 004EB0B4 2D284002 */   daddu     $5, $18, $0
    /* 3EB0B8 004EB0B8 2D804000 */  daddu      $16, $2, $0
    /* 3EB0BC 004EB0BC 0A000016 */  bnez       $16, .L004EB0E8
    /* 3EB0C0 004EB0C0 2D200002 */   daddu     $4, $16, $0
    /* 3EB0C4 004EB0C4 7600043C */  lui        $4, %hi(D_0075C5E8)
    /* 3EB0C8 004EB0C8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB0CC 004EB0CC 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB0D0 004EB0D0 E8C58424 */  addiu      $4, $4, %lo(D_0075C5E8)
    /* 3EB0D4 004EB0D4 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB0D8 004EB0D8 1800B3DF */  ld         $19, 0x18($29)
    /* 3EB0DC 004EB0DC 2000BFDF */  ld         $31, 0x20($29)
    /* 3EB0E0 004EB0E0 A61A1308 */  j          func_004c6a98
    /* 3EB0E4 004EB0E4 3000BD27 */   addiu     $29, $29, 0x30
  .L004EB0E8:
    /* 3EB0E8 004EB0E8 EC00258E */  lw         $5, 0xEC($17)
    /* 3EB0EC 004EB0EC 96AB130C */  jal        func_004eae58
    /* 3EB0F0 004EB0F0 F000268E */   lw        $6, 0xF0($17)
    /* 3EB0F4 004EB0F4 E80030AE */  sw         $16, 0xE8($17)
    /* 3EB0F8 004EB0F8 4F00023C */  lui        $2, %hi(func_004eb228)
    /* 3EB0FC 004EB0FC 4F00033C */  lui        $3, %hi(func_004eb2b0)
    /* 3EB100 004EB100 4F00043C */  lui        $4, %hi(func_004eb298)
    /* 3EB104 004EB104 4F00053C */  lui        $5, %hi(func_004eb2e8)
    /* 3EB108 004EB108 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB10C 004EB10C 28B24224 */  addiu      $2, $2, %lo(func_004eb228)
    /* 3EB110 004EB110 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB114 004EB114 B0B26324 */  addiu      $3, $3, %lo(func_004eb2b0)
    /* 3EB118 004EB118 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB11C 004EB11C 98B28424 */  addiu      $4, $4, %lo(func_004eb298)
    /* 3EB120 004EB120 1800B3DF */  ld         $19, 0x18($29)
    /* 3EB124 004EB124 E8B2A524 */  addiu      $5, $5, %lo(func_004eb2e8)
    /* 3EB128 004EB128 2000BFDF */  ld         $31, 0x20($29)
    /* 3EB12C 004EB12C 7200063C */  lui        $6, %hi(D_00724E80)
    /* 3EB130 004EB130 7100073C */  lui        $7, %hi(D_00714C2C)
    /* 3EB134 004EB134 7100083C */  lui        $8, %hi(D_00714C30)
    /* 3EB138 004EB138 7200093C */  lui        $9, %hi(D_007212E4)
    /* 3EB13C 004EB13C 804EC2AC */  sw         $2, %lo(D_00724E80)($6)
    /* 3EB140 004EB140 2C4CE3AC */  sw         $3, %lo(D_00714C2C)($7)
    /* 3EB144 004EB144 304C04AD */  sw         $4, %lo(D_00714C30)($8)
    /* 3EB148 004EB148 E41225AD */  sw         $5, %lo(D_007212E4)($9)
    /* 3EB14C 004EB14C 7A321308 */  j          func_004cc9e8
    /* 3EB150 004EB150 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EB154 004EB154 00000000 */  nop
.size func_004eb020, 0x138
