.section .text
.set noat
.set noreorder
glabel func_004e8be8
    /* 3E8BE8 004E8BE8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E8BEC 004E8BEC 9200023C */  lui        $2, %hi(D_00924980)
    /* 3E8BF0 004E8BF0 2000B4FF */  sd         $20, 0x20($29)
    /* 3E8BF4 004E8BF4 80495424 */  addiu      $20, $2, %lo(D_00924980)
    /* 3E8BF8 004E8BF8 0000B0FF */  sd         $16, 0x0($29)
    /* 3E8BFC 004E8BFC 2D808000 */  daddu      $16, $4, $0
    /* 3E8C00 004E8C00 0800B1FF */  sd         $17, 0x8($29)
    /* 3E8C04 004E8C04 2D88C000 */  daddu      $17, $6, $0
    /* 3E8C08 004E8C08 1800B3FF */  sd         $19, 0x18($29)
    /* 3E8C0C 004E8C0C 2D98A000 */  daddu      $19, $5, $0
    /* 3E8C10 004E8C10 00100624 */  addiu      $6, $0, 0x1000
    /* 3E8C14 004E8C14 2D208002 */  daddu      $4, $20, $0
    /* 3E8C18 004E8C18 2D280000 */  daddu      $5, $0, $0
    /* 3E8C1C 004E8C1C 1000B2FF */  sd         $18, 0x10($29)
    /* 3E8C20 004E8C20 2800BFFF */  sd         $31, 0x28($29)
    /* 3E8C24 004E8C24 72FE100C */  jal        func_0043f9c8
    /* 3E8C28 004E8C28 2D90E000 */   daddu     $18, $7, $0
    /* 3E8C2C 004E8C2C 7300033C */  lui        $3, %hi(D_00734370)
    /* 3E8C30 004E8C30 7043628C */  lw         $2, %lo(D_00734370)($3)
    /* 3E8C34 004E8C34 03004014 */  bnez       $2, .L004E8C44
    /* 3E8C38 004E8C38 00000000 */   nop
    /* 3E8C3C 004E8C3C DCA2130C */  jal        func_004e8b70
    /* 3E8C40 004E8C40 00000000 */   nop
  .L004E8C44:
    /* 3E8C44 004E8C44 5EA2130C */  jal        func_004e8978
    /* 3E8C48 004E8C48 00000000 */   nop
    /* 3E8C4C 004E8C4C 34000012 */  beqz       $16, .L004E8D20
    /* 3E8C50 004E8C50 2D100000 */   daddu     $2, $0, $0
    /* 3E8C54 004E8C54 04006016 */  bnez       $19, .L004E8C68
    /* 3E8C58 004E8C58 7600043C */   lui       $4, %hi(D_0075B868)
    /* 3E8C5C 004E8C5C 2D280000 */  daddu      $5, $0, $0
    /* 3E8C60 004E8C60 06000010 */  b          .L004E8C7C
    /* 3E8C64 004E8C64 68B88424 */   addiu     $4, $4, %lo(D_0075B868)
  .L004E8C68:
    /* 3E8C68 004E8C68 09002016 */  bnez       $17, .L004E8C90
    /* 3E8C6C 004E8C6C 2D206002 */   daddu     $4, $19, $0
    /* 3E8C70 004E8C70 7600043C */  lui        $4, %hi(D_0075B898)
    /* 3E8C74 004E8C74 2D280000 */  daddu      $5, $0, $0
    /* 3E8C78 004E8C78 98B88424 */  addiu      $4, $4, %lo(D_0075B898)
  .L004E8C7C:
    /* 3E8C7C 004E8C7C DE34130C */  jal        func_004cd378
    /* 3E8C80 004E8C80 00000000 */   nop
    /* 3E8C84 004E8C84 26000010 */  b          .L004E8D20
    /* 3E8C88 004E8C88 2D100000 */   daddu     $2, $0, $0
    /* 3E8C8C 004E8C8C 00000000 */  nop
  .L004E8C90:
    /* 3E8C90 004E8C90 2D280000 */  daddu      $5, $0, $0
    /* 3E8C94 004E8C94 72FE100C */  jal        func_0043f9c8
    /* 3E8C98 004E8C98 2D302002 */   daddu     $6, $17, $0
    /* 3E8C9C 004E8C9C 2D200002 */  daddu      $4, $16, $0
    /* 3E8CA0 004E8CA0 98A1130C */  jal        func_004e8660
    /* 3E8CA4 004E8CA4 2D288002 */   daddu     $5, $20, $0
    /* 3E8CA8 004E8CA8 0B004054 */  bnel       $2, $0, .L004E8CD8
    /* 3E8CAC 004E8CAC 09005026 */   addiu     $16, $18, 0x9
    /* 3E8CB0 004E8CB0 7600043C */  lui        $4, %hi(D_0075B8C8)
    /* 3E8CB4 004E8CB4 2D280002 */  daddu      $5, $16, $0
    /* 3E8CB8 004E8CB8 DE34130C */  jal        func_004cd378
    /* 3E8CBC 004E8CBC C8B88424 */   addiu     $4, $4, %lo(D_0075B8C8)
    /* 3E8CC0 004E8CC0 7600053C */  lui        $5, %hi(D_0075B8F0)
    /* 3E8CC4 004E8CC4 F0B8A524 */  addiu      $5, $5, %lo(D_0075B8F0)
    /* 3E8CC8 004E8CC8 169D130C */  jal        func_004e7458
    /* 3E8CCC 004E8CCC 2D200000 */   daddu     $4, $0, $0
    /* 3E8CD0 004E8CD0 13000010 */  b          .L004E8D20
    /* 3E8CD4 004E8CD4 2D100000 */   daddu     $2, $0, $0
  .L004E8CD8:
    /* 3E8CD8 004E8CD8 2D384002 */  daddu      $7, $18, $0
    /* 3E8CDC 004E8CDC 1B003002 */  divu       $0, $17, $16
    /* 3E8CE0 004E8CE0 2D288002 */  daddu      $5, $20, $0
    /* 3E8CE4 004E8CE4 2D206002 */  daddu      $4, $19, $0
    /* 3E8CE8 004E8CE8 01000052 */  beql       $16, $0, .L004E8CF0
    /* 3E8CEC 004E8CEC CD010000 */   break     0, 7
  .L004E8CF0:
    /* 3E8CF0 004E8CF0 01005226 */  addiu      $18, $18, 0x1
    /* 3E8CF4 004E8CF4 12880000 */  mflo       $17
    /* 3E8CF8 004E8CF8 2D302002 */  daddu      $6, $17, $0
    /* 3E8CFC 004E8CFC 30A1130C */  jal        func_004e84c0
    /* 3E8D00 004E8D00 C0881100 */   sll       $17, $17, 3
    /* 3E8D04 004E8D04 2D206002 */  daddu      $4, $19, $0
    /* 3E8D08 004E8D08 F0A1130C */  jal        func_004e87c0
    /* 3E8D0C 004E8D0C 2D284000 */   daddu     $5, $2, $0
    /* 3E8D10 004E8D10 01000052 */  beql       $16, $0, .L004E8D18
    /* 3E8D14 004E8D14 CD010000 */   break     0, 7
  .L004E8D18:
    /* 3E8D18 004E8D18 18105200 */  mult       $2, $2, $18
    /* 3E8D1C 004E8D1C 21102202 */  addu       $2, $17, $2
  .L004E8D20:
    /* 3E8D20 004E8D20 0000B0DF */  ld         $16, 0x0($29)
    /* 3E8D24 004E8D24 0800B1DF */  ld         $17, 0x8($29)
    /* 3E8D28 004E8D28 1000B2DF */  ld         $18, 0x10($29)
    /* 3E8D2C 004E8D2C 1800B3DF */  ld         $19, 0x18($29)
    /* 3E8D30 004E8D30 2000B4DF */  ld         $20, 0x20($29)
    /* 3E8D34 004E8D34 2800BFDF */  ld         $31, 0x28($29)
    /* 3E8D38 004E8D38 0800E003 */  jr         $31
    /* 3E8D3C 004E8D3C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e8be8, 0x158
