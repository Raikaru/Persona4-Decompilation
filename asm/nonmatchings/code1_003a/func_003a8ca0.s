.section .text
.set noat
.set noreorder
glabel func_003a8ca0
    /* 2A8CA0 003A8CA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2A8CA4 003A8CA4 1000BFFF */  sd         $31, 0x10($29)
    /* 2A8CA8 003A8CA8 7445100C */  jal        func_004115d0
    /* 2A8CAC 003A8CAC 0000B07F */   sq        $16, 0x0($29)
    /* 2A8CB0 003A8CB0 2D804000 */  daddu      $16, $2, $0
    /* 2A8CB4 003A8CB4 13000012 */  beqz       $16, .L003A8D04
    /* 2A8CB8 003A8CB8 00000000 */   nop
    /* 2A8CBC 003A8CBC 284B100C */  jal        func_00412ca0
    /* 2A8CC0 003A8CC0 2D200002 */   daddu     $4, $16, $0
    /* 2A8CC4 003A8CC4 0D004010 */  beqz       $2, .L003A8CFC
    /* 2A8CC8 003A8CC8 00000000 */   nop
    /* 2A8CCC 003A8CCC 7100063C */  lui        $6, %hi(D_007084A0)
    /* 2A8CD0 003A8CD0 2D204000 */  daddu      $4, $2, $0
    /* 2A8CD4 003A8CD4 2D280000 */  daddu      $5, $0, $0
    /* 2A8CD8 003A8CD8 A084C624 */  addiu      $6, $6, %lo(D_007084A0)
    /* 2A8CDC 003A8CDC EC4B100C */  jal        func_00412fb0
    /* 2A8CE0 003A8CE0 2D380000 */   daddu     $7, $0, $0
    /* 2A8CE4 003A8CE4 7849100C */  jal        func_004125e0
    /* 2A8CE8 003A8CE8 2D204000 */   daddu     $4, $2, $0
    /* 2A8CEC 003A8CEC 03004010 */  beqz       $2, .L003A8CFC
    /* 2A8CF0 003A8CF0 00000000 */   nop
    /* 2A8CF4 003A8CF4 04000010 */  b          .L003A8D08
    /* 2A8CF8 003A8CF8 2D100002 */   daddu     $2, $16, $0
  .L003A8CFC:
    /* 2A8CFC 003A8CFC 9C45100C */  jal        func_00411670
    /* 2A8D00 003A8D00 2D200002 */   daddu     $4, $16, $0
  .L003A8D04:
    /* 2A8D04 003A8D04 2D100000 */  daddu      $2, $0, $0
  .L003A8D08:
    /* 2A8D08 003A8D08 1000BFDF */  ld         $31, 0x10($29)
    /* 2A8D0C 003A8D0C 0000B07B */  lq         $16, 0x0($29)
    /* 2A8D10 003A8D10 0800E003 */  jr         $31
    /* 2A8D14 003A8D14 2000BD27 */   addiu     $29, $29, 0x20
    /* 2A8D18 003A8D18 00000000 */  nop
    /* 2A8D1C 003A8D1C 00000000 */  nop
.size func_003a8ca0, 0x80
