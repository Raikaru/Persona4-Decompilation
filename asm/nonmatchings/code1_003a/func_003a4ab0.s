.section .text
.set noat
.set noreorder
glabel func_003a4ab0
    /* 2A4AB0 003A4AB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2A4AB4 003A4AB4 3000BFFF */  sd         $31, 0x30($29)
    /* 2A4AB8 003A4AB8 2000B27F */  sq         $18, 0x20($29)
    /* 2A4ABC 003A4ABC 1000B17F */  sq         $17, 0x10($29)
    /* 2A4AC0 003A4AC0 2D908000 */  daddu      $18, $4, $0
    /* 2A4AC4 003A4AC4 0000B07F */  sq         $16, 0x0($29)
    /* 2A4AC8 003A4AC8 2D88C000 */  daddu      $17, $6, $0
    /* 2A4ACC 003A4ACC 0300A104 */  bgez       $5, .L003A4ADC
    /* 2A4AD0 003A4AD0 03810500 */   sra       $16, $5, 4
    /* 2A4AD4 003A4AD4 0F00A224 */  addiu      $2, $5, 0xF
    /* 2A4AD8 003A4AD8 03810200 */  sra        $16, $2, 4
  .L003A4ADC:
    /* 2A4ADC 003A4ADC 9886100C */  jal        func_00421a60
    /* 2A4AE0 003A4AE0 2D200000 */   daddu     $4, $0, $0
    /* 2A4AE4 003A4AE4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2A4AE8 003A4AE8 00D4648C */  lw         $4, -0x2C00($3)
    /* 2A4AEC 003A4AEC 00018430 */  andi       $4, $4, 0x100
    /* 2A4AF0 003A4AF0 60008014 */  bnez       $4, .L003A4C74
    /* 2A4AF4 003A4AF4 00000000 */   nop
    /* 2A4AF8 003A4AF8 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003A4AFC:
    /* 2A4AFC 003A4AFC 00D0648C */  lw         $4, -0x3000($3)
    /* 2A4B00 003A4B00 00018430 */  andi       $4, $4, 0x100
    /* 2A4B04 003A4B04 70008014 */  bnez       $4, .L003A4CC8
    /* 2A4B08 003A4B08 00000000 */   nop
    /* 2A4B0C 003A4B0C 0070053C */  lui        $5, (0x70000000 >> 16)
  .L003A4B10:
    /* 2A4B10 003A4B10 2D300000 */  daddu      $6, $0, $0
  .L003A4B14:
    /* 2A4B14 003A4B14 0000247A */  lq         $4, 0x0($17)
    /* 2A4B18 003A4B18 0800C624 */  addiu      $6, $6, 0x8
    /* 2A4B1C 003A4B1C 0002C328 */  slti       $3, $6, 0x200
    /* 2A4B20 003A4B20 0000A47C */  sq         $4, (0x70000000 & 0xFFFF)($5)
    /* 2A4B24 003A4B24 1000247A */  lq         $4, 0x10($17)
    /* 2A4B28 003A4B28 1000A47C */  sq         $4, (0x70000010 & 0xFFFF)($5)
    /* 2A4B2C 003A4B2C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B30 003A4B30 2000A47C */  sq         $4, (0x70000020 & 0xFFFF)($5)
    /* 2A4B34 003A4B34 1000247A */  lq         $4, 0x10($17)
    /* 2A4B38 003A4B38 3000A47C */  sq         $4, (0x70000030 & 0xFFFF)($5)
    /* 2A4B3C 003A4B3C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B40 003A4B40 4000A47C */  sq         $4, (0x70000040 & 0xFFFF)($5)
    /* 2A4B44 003A4B44 1000247A */  lq         $4, 0x10($17)
    /* 2A4B48 003A4B48 5000A47C */  sq         $4, (0x70000050 & 0xFFFF)($5)
    /* 2A4B4C 003A4B4C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B50 003A4B50 6000A47C */  sq         $4, (0x70000060 & 0xFFFF)($5)
    /* 2A4B54 003A4B54 1000247A */  lq         $4, 0x10($17)
    /* 2A4B58 003A4B58 7000A47C */  sq         $4, (0x70000070 & 0xFFFF)($5)
    /* 2A4B5C 003A4B5C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B60 003A4B60 8000A47C */  sq         $4, (0x70000080 & 0xFFFF)($5)
    /* 2A4B64 003A4B64 1000247A */  lq         $4, 0x10($17)
    /* 2A4B68 003A4B68 9000A47C */  sq         $4, (0x70000090 & 0xFFFF)($5)
    /* 2A4B6C 003A4B6C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B70 003A4B70 A000A47C */  sq         $4, (0x700000A0 & 0xFFFF)($5)
    /* 2A4B74 003A4B74 1000247A */  lq         $4, 0x10($17)
    /* 2A4B78 003A4B78 B000A47C */  sq         $4, (0x700000B0 & 0xFFFF)($5)
    /* 2A4B7C 003A4B7C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B80 003A4B80 C000A47C */  sq         $4, (0x700000C0 & 0xFFFF)($5)
    /* 2A4B84 003A4B84 1000247A */  lq         $4, 0x10($17)
    /* 2A4B88 003A4B88 D000A47C */  sq         $4, (0x700000D0 & 0xFFFF)($5)
    /* 2A4B8C 003A4B8C 0000247A */  lq         $4, 0x0($17)
    /* 2A4B90 003A4B90 E000A47C */  sq         $4, (0x700000E0 & 0xFFFF)($5)
    /* 2A4B94 003A4B94 1000247A */  lq         $4, 0x10($17)
    /* 2A4B98 003A4B98 F000A47C */  sq         $4, (0x700000F0 & 0xFFFF)($5)
    /* 2A4B9C 003A4B9C DDFF6014 */  bnez       $3, .L003A4B14
    /* 2A4BA0 003A4BA0 0001A524 */   addiu     $5, $5, %lo(D_70000100)
    /* 2A4BA4 003A4BA4 0104012A */  slti       $1, $16, 0x401
    /* 2A4BA8 003A4BA8 15002014 */  bnez       $1, .L003A4C00
    /* 2A4BAC 003A4BAC 00000000 */   nop
    /* 2A4BB0 003A4BB0 00010524 */  addiu      $5, $0, 0x100
    /* 2A4BB4 003A4BB4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2A4BB8 003A4BB8 00040424 */  addiu      $4, $0, 0x400
  .L003A4BBC:
    /* 2A4BBC 003A4BBC 00D0668C */  lw         $6, -0x3000($3)
    /* 2A4BC0 003A4BC0 0001C630 */  andi       $6, $6, 0x100
    /* 2A4BC4 003A4BC4 4D00C014 */  bnez       $6, .L003A4CFC
    /* 2A4BC8 003A4BC8 00000000 */   nop
    /* 2A4BCC 003A4BCC 00000000 */  nop
  .L003A4BD0:
    /* 2A4BD0 003A4BD0 10E065AC */  sw         $5, -0x1FF0($3)
    /* 2A4BD4 003A4BD4 80D060AC */  sw         $0, -0x2F80($3)
    /* 2A4BD8 003A4BD8 10D072AC */  sw         $18, -0x2FF0($3)
    /* 2A4BDC 003A4BDC 20D064AC */  sw         $4, -0x2FE0($3)
    /* 2A4BE0 003A4BE0 00D065AC */  sw         $5, -0x3000($3)
    /* 2A4BE4 003A4BE4 0F000000 */  sync
    /* 2A4BE8 003A4BE8 0F040000 */  sync.p
    /* 2A4BEC 003A4BEC 00FC1026 */  addiu      $16, $16, -0x400
    /* 2A4BF0 003A4BF0 0104012A */  slti       $1, $16, 0x401
    /* 2A4BF4 003A4BF4 F1FF2010 */  beqz       $1, .L003A4BBC
    /* 2A4BF8 003A4BF8 00405226 */   addiu     $18, $18, 0x4000
    /* 2A4BFC 003A4BFC 00000000 */  nop
  .L003A4C00:
    /* 2A4C00 003A4C00 4B000012 */  beqz       $16, .L003A4D30
    /* 2A4C04 003A4C04 00000000 */   nop
    /* 2A4C08 003A4C08 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2A4C0C 003A4C0C 00D0648C */  lw         $4, -0x3000($3)
    /* 2A4C10 003A4C10 00018430 */  andi       $4, $4, 0x100
    /* 2A4C14 003A4C14 0C008010 */  beqz       $4, .L003A4C48
    /* 2A4C18 003A4C18 00000000 */   nop
    /* 2A4C1C 003A4C1C 00010424 */  addiu      $4, $0, 0x100
    /* 2A4C20 003A4C20 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2A4C24 003A4C24 0F000000 */  sync
    /* 2A4C28 003A4C28 0F040000 */  sync.p
  .L003A4C2C:
    /* 2A4C2C 003A4C2C 00000000 */  nop
    /* 2A4C30 003A4C30 00000000 */  nop
    /* 2A4C34 003A4C34 00000000 */  nop
    /* 2A4C38 003A4C38 00000000 */  nop
    /* 2A4C3C 003A4C3C 00000000 */  nop
    /* 2A4C40 003A4C40 FAFF0041 */  bc0f       .L003A4C2C /* handwritten instruction */
    /* 2A4C44 003A4C44 00000000 */   nop
  .L003A4C48:
    /* 2A4C48 003A4C48 00010424 */  addiu      $4, $0, 0x100
    /* 2A4C4C 003A4C4C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2A4C50 003A4C50 10E064AC */  sw         $4, -0x1FF0($3)
    /* 2A4C54 003A4C54 80D060AC */  sw         $0, -0x2F80($3)
    /* 2A4C58 003A4C58 10D072AC */  sw         $18, -0x2FF0($3)
    /* 2A4C5C 003A4C5C 20D070AC */  sw         $16, -0x2FE0($3)
    /* 2A4C60 003A4C60 00D064AC */  sw         $4, -0x3000($3)
    /* 2A4C64 003A4C64 0F000000 */  sync
    /* 2A4C68 003A4C68 0F040000 */  sync.p
    /* 2A4C6C 003A4C6C 30000010 */  b          .L003A4D30
    /* 2A4C70 003A4C70 00000000 */   nop
  .L003A4C74:
    /* 2A4C74 003A4C74 00020424 */  addiu      $4, $0, 0x200
    /* 2A4C78 003A4C78 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2A4C7C 003A4C7C 0F000000 */  sync
    /* 2A4C80 003A4C80 0F040000 */  sync.p
  .L003A4C84:
    /* 2A4C84 003A4C84 00000000 */  nop
    /* 2A4C88 003A4C88 00000000 */  nop
    /* 2A4C8C 003A4C8C 00000000 */  nop
    /* 2A4C90 003A4C90 00000000 */  nop
    /* 2A4C94 003A4C94 00000000 */  nop
    /* 2A4C98 003A4C98 FAFF0041 */  bc0f       .L003A4C84 /* handwritten instruction */
    /* 2A4C9C 003A4C9C 00000000 */   nop
    /* 2A4CA0 003A4CA0 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003A4CA4:
    /* 2A4CA4 003A4CA4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2A4CA8 003A4CA8 00018430 */  andi       $4, $4, 0x100
    /* 2A4CAC 003A4CAC 00000000 */  nop
    /* 2A4CB0 003A4CB0 00000000 */  nop
    /* 2A4CB4 003A4CB4 00000000 */  nop
    /* 2A4CB8 003A4CB8 FAFF8014 */  bnez       $4, .L003A4CA4
    /* 2A4CBC 003A4CBC 00000000 */   nop
    /* 2A4CC0 003A4CC0 8EFF0010 */  b          .L003A4AFC
    /* 2A4CC4 003A4CC4 0110033C */   lui       $3, (0x10010000 >> 16)
  .L003A4CC8:
    /* 2A4CC8 003A4CC8 00010424 */  addiu      $4, $0, 0x100
    /* 2A4CCC 003A4CCC 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2A4CD0 003A4CD0 0F000000 */  sync
    /* 2A4CD4 003A4CD4 0F040000 */  sync.p
  .L003A4CD8:
    /* 2A4CD8 003A4CD8 00000000 */  nop
    /* 2A4CDC 003A4CDC 00000000 */  nop
    /* 2A4CE0 003A4CE0 00000000 */  nop
    /* 2A4CE4 003A4CE4 00000000 */  nop
    /* 2A4CE8 003A4CE8 00000000 */  nop
    /* 2A4CEC 003A4CEC FAFF0041 */  bc0f       .L003A4CD8 /* handwritten instruction */
    /* 2A4CF0 003A4CF0 00000000 */   nop
    /* 2A4CF4 003A4CF4 86FF0010 */  b          .L003A4B10
    /* 2A4CF8 003A4CF8 0070053C */   lui       $5, (0x700000F0 >> 16)
  .L003A4CFC:
    /* 2A4CFC 003A4CFC 20E065AC */  sw         $5, -0x1FE0($3)
    /* 2A4D00 003A4D00 0F000000 */  sync
    /* 2A4D04 003A4D04 0F040000 */  sync.p
  .L003A4D08:
    /* 2A4D08 003A4D08 00000000 */  nop
    /* 2A4D0C 003A4D0C 00000000 */  nop
    /* 2A4D10 003A4D10 00000000 */  nop
    /* 2A4D14 003A4D14 00000000 */  nop
    /* 2A4D18 003A4D18 00000000 */  nop
    /* 2A4D1C 003A4D1C FAFF0041 */  bc0f       .L003A4D08 /* handwritten instruction */
    /* 2A4D20 003A4D20 00000000 */   nop
    /* 2A4D24 003A4D24 AAFF0010 */  b          .L003A4BD0
    /* 2A4D28 003A4D28 00000000 */   nop
    /* 2A4D2C 003A4D2C 00000000 */  nop
  .L003A4D30:
    /* 2A4D30 003A4D30 3000BFDF */  ld         $31, 0x30($29)
    /* 2A4D34 003A4D34 2000B27B */  lq         $18, 0x20($29)
    /* 2A4D38 003A4D38 1000B17B */  lq         $17, 0x10($29)
    /* 2A4D3C 003A4D3C 0000B07B */  lq         $16, 0x0($29)
    /* 2A4D40 003A4D40 0800E003 */  jr         $31
    /* 2A4D44 003A4D44 4000BD27 */   addiu     $29, $29, 0x40
    /* 2A4D48 003A4D48 00000000 */  nop
    /* 2A4D4C 003A4D4C 00000000 */  nop
.size func_003a4ab0, 0x2a0
