.section .text
.set noat
.set noreorder
glabel func_003a2ce0
    /* 2A2CE0 003A2CE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2A2CE4 003A2CE4 0400023C */  lui        $2, (0x4012F >> 16)
    /* 2A2CE8 003A2CE8 2000BFFF */  sd         $31, 0x20($29)
    /* 2A2CEC 003A2CEC 2F014534 */  ori        $5, $2, (0x4012F & 0xFFFF)
    /* 2A2CF0 003A2CF0 1000B17F */  sq         $17, 0x10($29)
    /* 2A2CF4 003A2CF4 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2A2CF8 003A2CF8 0000B07F */  sq         $16, 0x0($29)
    /* 2A2CFC 003A2CFC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2A2D00 003A2D00 2D808000 */  daddu      $16, $4, $0
    /* 2A2D04 003A2D04 09F84000 */  jalr       $2
    /* 2A2D08 003A2D08 18000424 */   addiu     $4, $0, 0x18
    /* 2A2D0C 003A2D0C 2D884000 */  daddu      $17, $2, $0
    /* 2A2D10 003A2D10 16002012 */  beqz       $17, .L003A2D6C
    /* 2A2D14 003A2D14 00000000 */   nop
    /* 2A2D18 003A2D18 14B6838F */  lw         $3, -0x49EC($28)
    /* 2A2D1C 003A2D1C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2A2D20 003A2D20 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2A2D24 003A2D24 2D202002 */  daddu      $4, $17, $0
    /* 2A2D28 003A2D28 21104300 */  addu       $2, $2, $3
    /* 2A2D2C 003A2D2C 000051AC */  sw         $17, 0x0($2)
    /* 2A2D30 003A2D30 040020AE */  sw         $0, 0x4($17)
    /* 2A2D34 003A2D34 080020AE */  sw         $0, 0x8($17)
    /* 2A2D38 003A2D38 0C0020AE */  sw         $0, 0xC($17)
    /* 2A2D3C 003A2D3C 100020AE */  sw         $0, 0x10($17)
    /* 2A2D40 003A2D40 40A10E0C */  jal        func_003a8500
    /* 2A2D44 003A2D44 140020AE */   sw        $0, 0x14($17)
    /* 2A2D48 003A2D48 589C0E0C */  jal        func_003a7160
    /* 2A2D4C 003A2D4C 2D202002 */   daddu     $4, $17, $0
    /* 2A2D50 003A2D50 28A30E0C */  jal        func_003a8ca0
    /* 2A2D54 003A2D54 00000000 */   nop
    /* 2A2D58 003A2D58 B4A40E0C */  jal        func_003a92d0
    /* 2A2D5C 003A2D5C 000022AE */   sw        $2, 0x0($17)
    /* 2A2D60 003A2D60 140022AE */  sw         $2, 0x14($17)
    /* 2A2D64 003A2D64 02000010 */  b          .L003A2D70
    /* 2A2D68 003A2D68 2D100002 */   daddu     $2, $16, $0
  .L003A2D6C:
    /* 2A2D6C 003A2D6C 2D100000 */  daddu      $2, $0, $0
  .L003A2D70:
    /* 2A2D70 003A2D70 2000BFDF */  ld         $31, 0x20($29)
    /* 2A2D74 003A2D74 1000B17B */  lq         $17, 0x10($29)
    /* 2A2D78 003A2D78 0000B07B */  lq         $16, 0x0($29)
    /* 2A2D7C 003A2D7C 0800E003 */  jr         $31
    /* 2A2D80 003A2D80 3000BD27 */   addiu     $29, $29, 0x30
    /* 2A2D84 003A2D84 00000000 */  nop
    /* 2A2D88 003A2D88 00000000 */  nop
    /* 2A2D8C 003A2D8C 00000000 */  nop
.size func_003a2ce0, 0xb0
