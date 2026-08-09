.section .text
.set noat
.set noreorder
glabel func_0042bbc8
    /* 32BBC8 0042BBC8 80FFBD27 */  addiu      $29, $29, -0x80
    /* 32BBCC 0042BBCC 7100023C */  lui        $2, %hi(D_0070CD00)
    /* 32BBD0 0042BBD0 5000B5FF */  sd         $21, 0x50($29)
    /* 32BBD4 0042BBD4 4000B4FF */  sd         $20, 0x40($29)
    /* 32BBD8 0042BBD8 4300153C */  lui        $21, %hi(func_0042bb40)
    /* 32BBDC 0042BBDC 3000B3FF */  sd         $19, 0x30($29)
    /* 32BBE0 0042BBE0 4300143C */  lui        $20, %hi(func_0042bb08)
    /* 32BBE4 0042BBE4 2000B2FF */  sd         $18, 0x20($29)
    /* 32BBE8 0042BBE8 1000B1FF */  sd         $17, 0x10($29)
    /* 32BBEC 0042BBEC 0000B0FF */  sd         $16, 0x0($29)
    /* 32BBF0 0042BBF0 7000BFFF */  sd         $31, 0x70($29)
    /* 32BBF4 0042BBF4 00CD5024 */  addiu      $16, $2, %lo(D_0070CD00)
    /* 32BBF8 0042BBF8 6000B6FF */  sd         $22, 0x60($29)
    /* 32BBFC 0042BBFC 00CD448C */  lw         $4, %lo(D_0070CD00)($2)
    /* 32BC00 0042BC00 32AF100C */  jal        func_0042bcc8
    /* 32BC04 0042BC04 0400058E */   lw        $5, 0x4($16)
    /* 32BC08 0042BC08 0C00058E */  lw         $5, 0xC($16)
    /* 32BC0C 0042BC0C 32AF100C */  jal        func_0042bcc8
    /* 32BC10 0042BC10 0800048E */   lw        $4, 0x8($16)
    /* 32BC14 0042BC14 0080043C */  lui        $4, (0x80000000 >> 16)
    /* 32BC18 0042BC18 0880053C */  lui        $5, (0x80080000 >> 16)
    /* 32BC1C 0042BC1C E0AE100C */  jal        func_0042bb80
    /* 32BC20 0042BC20 40BBA626 */   addiu     $6, $21, %lo(func_0042bb40)
    /* 32BC24 0042BC24 2D984000 */  daddu      $19, $2, $0
    /* 32BC28 0042BC28 0080043C */  lui        $4, (0x80000000 >> 16)
    /* 32BC2C 0042BC2C 0880053C */  lui        $5, (0x80080000 >> 16)
    /* 32BC30 0042BC30 E0AE100C */  jal        func_0042bb80
    /* 32BC34 0042BC34 08BB8626 */   addiu     $6, $20, %lo(func_0042bb08)
    /* 32BC38 0042BC38 F4FD7126 */  addiu      $17, $19, -0x20C
    /* 32BC3C 0042BC3C 2D904000 */  daddu      $18, $2, $0
    /* 32BC40 0042BC40 98FE5026 */  addiu      $16, $18, -0x168
    /* 32BC44 0042BC44 14003012 */  beq        $17, $16, .L0042BC98
    /* 32BC48 0042BC48 7100163C */   lui       $22, %hi(D_0070CCF8)
    /* 32BC4C 0042BC4C 2B103002 */  sltu       $2, $17, $16
  .L0042BC50:
    /* 32BC50 0042BC50 07004010 */  beqz       $2, .L0042BC70
    /* 32BC54 0042BC54 04006426 */   addiu     $4, $19, 0x4
    /* 32BC58 0042BC58 0880053C */  lui        $5, (0x80080000 >> 16)
    /* 32BC5C 0042BC5C E0AE100C */  jal        func_0042bb80
    /* 32BC60 0042BC60 40BBA626 */   addiu     $6, $21, %lo(func_0042bb40)
    /* 32BC64 0042BC64 2D984000 */  daddu      $19, $2, $0
    /* 32BC68 0042BC68 07000010 */  b          .L0042BC88
    /* 32BC6C 0042BC6C F4FD7126 */   addiu     $17, $19, -0x20C
  .L0042BC70:
    /* 32BC70 0042BC70 04004426 */  addiu      $4, $18, 0x4
    /* 32BC74 0042BC74 0880053C */  lui        $5, (0x80080000 >> 16)
    /* 32BC78 0042BC78 E0AE100C */  jal        func_0042bb80
    /* 32BC7C 0042BC7C 08BB8626 */   addiu     $6, $20, %lo(func_0042bb08)
    /* 32BC80 0042BC80 2D904000 */  daddu      $18, $2, $0
    /* 32BC84 0042BC84 98FE5026 */  addiu      $16, $18, -0x168
  .L0042BC88:
    /* 32BC88 0042BC88 F1FF3016 */  bne        $17, $16, .L0042BC50
    /* 32BC8C 0042BC8C 2B103002 */   sltu      $2, $17, $16
    /* 32BC90 0042BC90 02000010 */  b          .L0042BC9C
    /* 32BC94 0042BC94 F8CCD1AE */   sw        $17, %lo(D_0070CCF8)($22)
  .L0042BC98:
    /* 32BC98 0042BC98 F8CCD1AE */  sw         $17, %lo(D_0070CCF8)($22)
  .L0042BC9C:
    /* 32BC9C 0042BC9C 7000BFDF */  ld         $31, 0x70($29)
    /* 32BCA0 0042BCA0 6000B6DF */  ld         $22, 0x60($29)
    /* 32BCA4 0042BCA4 5000B5DF */  ld         $21, 0x50($29)
    /* 32BCA8 0042BCA8 4000B4DF */  ld         $20, 0x40($29)
    /* 32BCAC 0042BCAC 3000B3DF */  ld         $19, 0x30($29)
    /* 32BCB0 0042BCB0 2000B2DF */  ld         $18, 0x20($29)
    /* 32BCB4 0042BCB4 1000B1DF */  ld         $17, 0x10($29)
    /* 32BCB8 0042BCB8 0000B0DF */  ld         $16, 0x0($29)
    /* 32BCBC 0042BCBC 0800E003 */  jr         $31
    /* 32BCC0 0042BCC0 8000BD27 */   addiu     $29, $29, 0x80
    /* 32BCC4 0042BCC4 00000000 */  nop
.size func_0042bbc8, 0x100
