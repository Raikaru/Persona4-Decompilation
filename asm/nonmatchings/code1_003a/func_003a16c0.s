.section .text
.set noat
.set noreorder
glabel func_003a16c0
    /* 2A16C0 003A16C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2A16C4 003A16C4 3A00063C */  lui        $6, %hi(func_003a2ce0)
    /* 2A16C8 003A16C8 3A00073C */  lui        $7, %hi(func_003a2d90)
    /* 2A16CC 003A16CC 0000BFFF */  sd         $31, 0x0($29)
    /* 2A16D0 003A16D0 04000424 */  addiu      $4, $0, 0x4
    /* 2A16D4 003A16D4 2F010524 */  addiu      $5, $0, 0x12F
    /* 2A16D8 003A16D8 E02CC624 */  addiu      $6, $6, %lo(func_003a2ce0)
    /* 2A16DC 003A16DC 4CA20F0C */  jal        func_003e8930
    /* 2A16E0 003A16E0 902DE724 */   addiu     $7, $7, %lo(func_003a2d90)
    /* 2A16E4 003A16E4 03004104 */  bgez       $2, .L003A16F4
    /* 2A16E8 003A16E8 14B682AF */   sw        $2, -0x49EC($28)
    /* 2A16EC 003A16EC 0C000010 */  b          .L003A1720
    /* 2A16F0 003A16F0 2D100000 */   daddu     $2, $0, $0
  .L003A16F4:
    /* 2A16F4 003A16F4 3A00063C */  lui        $6, %hi(func_003a15e0)
    /* 2A16F8 003A16F8 3A00073C */  lui        $7, %hi(func_003a1600)
    /* 2A16FC 003A16FC 04000424 */  addiu      $4, $0, 0x4
    /* 2A1700 003A1700 2F010524 */  addiu      $5, $0, 0x12F
    /* 2A1704 003A1704 E015C624 */  addiu      $6, $6, %lo(func_003a15e0)
    /* 2A1708 003A1708 0016E724 */  addiu      $7, $7, %lo(func_003a1600)
    /* 2A170C 003A170C AC060F0C */  jal        func_003c1ab0
    /* 2A1710 003A1710 2D400000 */   daddu     $8, $0, $0
    /* 2A1714 003A1714 10B682AF */  sw         $2, -0x49F0($28)
    /* 2A1718 003A1718 2A104000 */  slt        $2, $2, $0
    /* 2A171C 003A171C 01004238 */  xori       $2, $2, 0x1
  .L003A1720:
    /* 2A1720 003A1720 0000BFDF */  ld         $31, 0x0($29)
    /* 2A1724 003A1724 0800E003 */  jr         $31
    /* 2A1728 003A1728 1000BD27 */   addiu     $29, $29, 0x10
    /* 2A172C 003A172C 00000000 */  nop
.size func_003a16c0, 0x70
