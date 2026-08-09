.section .text
.set noat
.set noreorder
glabel func_004cc830
    /* 3CC830 004CC830 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC834 004CC834 3000B6FF */  sd         $22, 0x30($29)
    /* 3CC838 004CC838 7200163C */  lui        $22, %hi(D_00719A60)
    /* 3CC83C 004CC83C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CC840 004CC840 609AC326 */  addiu      $3, $22, %lo(D_00719A60)
    /* 3CC844 004CC844 0800B1FF */  sd         $17, 0x8($29)
    /* 3CC848 004CC848 1000B2FF */  sd         $18, 0x10($29)
    /* 3CC84C 004CC84C 1800B3FF */  sd         $19, 0x18($29)
    /* 3CC850 004CC850 2000B4FF */  sd         $20, 0x20($29)
    /* 3CC854 004CC854 2800B5FF */  sd         $21, 0x28($29)
    /* 3CC858 004CC858 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC85C 004CC85C 000062DC */  ld         $2, 0x0($3)
    /* 3CC860 004CC860 15004014 */  bnez       $2, .L004CC8B8
    /* 3CC864 004CC864 7200153C */   lui       $21, %hi(D_00719A58)
    /* 3CC868 004CC868 7200143C */  lui        $20, %hi(D_00719A2C)
    /* 3CC86C 004CC86C 2D986000 */  daddu      $19, $3, $0
    /* 3CC870 004CC870 589AB226 */  addiu      $18, $21, %lo(D_00719A58)
    /* 3CC874 004CC874 01001124 */  addiu      $17, $0, 0x1
    /* 3CC878 004CC878 2C9A9026 */  addiu      $16, $20, %lo(D_00719A2C)
    /* 3CC87C 004CC87C 00000000 */  nop
  .L004CC880:
    /* 3CC880 004CC880 000051FE */  sd         $17, 0x0($18)
    /* 3CC884 004CC884 01000524 */  addiu      $5, $0, 0x1
    /* 3CC888 004CC888 9C85100C */  jal        func_00421670
    /* 3CC88C 004CC88C 0000048E */   lw        $4, 0x0($16)
    /* 3CC890 004CC890 C485100C */  jal        func_00421710
    /* 3CC894 004CC894 0000048E */   lw        $4, 0x0($16)
    /* 3CC898 004CC898 502F130C */  jal        func_004cbd40
    /* 3CC89C 004CC89C 0000048E */   lw        $4, 0x0($16)
    /* 3CC8A0 004CC8A0 000063DE */  ld         $3, 0x0($19)
    /* 3CC8A4 004CC8A4 F6FF6010 */  beqz       $3, .L004CC880
    /* 3CC8A8 004CC8A8 609AC226 */   addiu     $2, $22, %lo(D_00719A60)
    /* 3CC8AC 004CC8AC 05000010 */  b          .L004CC8C4
    /* 3CC8B0 004CC8B0 3000B6DF */   ld        $22, 0x30($29)
    /* 3CC8B4 004CC8B4 00000000 */  nop
  .L004CC8B8:
    /* 3CC8B8 004CC8B8 7200143C */  lui        $20, %hi(D_00719A2C)
    /* 3CC8BC 004CC8BC 609AC226 */  addiu      $2, $22, %lo(D_00719A60)
    /* 3CC8C0 004CC8C0 3000B6DF */  ld         $22, 0x30($29)
  .L004CC8C4:
    /* 3CC8C4 004CC8C4 589AA326 */  addiu      $3, $21, %lo(D_00719A58)
    /* 3CC8C8 004CC8C8 2800B5DF */  ld         $21, 0x28($29)
    /* 3CC8CC 004CC8CC 2C9A8426 */  addiu      $4, $20, %lo(D_00719A2C)
    /* 3CC8D0 004CC8D0 2000B4DF */  ld         $20, 0x20($29)
    /* 3CC8D4 004CC8D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CC8D8 004CC8D8 0800B1DF */  ld         $17, 0x8($29)
    /* 3CC8DC 004CC8DC 1000B2DF */  ld         $18, 0x10($29)
    /* 3CC8E0 004CC8E0 1800B3DF */  ld         $19, 0x18($29)
    /* 3CC8E4 004CC8E4 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC8E8 004CC8E8 000040FC */  sd         $0, 0x0($2)
    /* 3CC8EC 004CC8EC 000060FC */  sd         $0, 0x0($3)
    /* 3CC8F0 004CC8F0 000080AC */  sw         $0, 0x0($4)
    /* 3CC8F4 004CC8F4 0800E003 */  jr         $31
    /* 3CC8F8 004CC8F8 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CC8FC 004CC8FC 00000000 */  nop
.size func_004cc830, 0xd0
