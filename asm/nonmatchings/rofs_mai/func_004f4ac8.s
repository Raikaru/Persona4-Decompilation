.section .text
.set noat
.set noreorder
glabel func_004f4ac8
    /* 3F4AC8 004F4AC8 C0FDBD27 */  addiu      $29, $29, -0x240
    /* 3F4ACC 004F4ACC 00020724 */  addiu      $7, $0, 0x200
    /* 3F4AD0 004F4AD0 2802B3FF */  sd         $19, 0x228($29)
    /* 3F4AD4 004F4AD4 1000B327 */  addiu      $19, $29, 0x10
    /* 3F4AD8 004F4AD8 3002B4FF */  sd         $20, 0x230($29)
    /* 3F4ADC 004F4ADC 2DA08000 */  daddu      $20, $4, $0
    /* 3F4AE0 004F4AE0 1802B1FF */  sd         $17, 0x218($29)
    /* 3F4AE4 004F4AE4 2D88A000 */  daddu      $17, $5, $0
    /* 3F4AE8 004F4AE8 2002B2FF */  sd         $18, 0x220($29)
    /* 3F4AEC 004F4AEC 2D90C000 */  daddu      $18, $6, $0
    /* 3F4AF0 004F4AF0 2D20A003 */  daddu      $4, $29, $0
    /* 3F4AF4 004F4AF4 2D286002 */  daddu      $5, $19, $0
    /* 3F4AF8 004F4AF8 09000624 */  addiu      $6, $0, 0x9
    /* 3F4AFC 004F4AFC 1002B0FF */  sd         $16, 0x210($29)
    /* 3F4B00 004F4B00 3802BFFF */  sd         $31, 0x238($29)
    /* 3F4B04 004F4B04 02CB130C */  jal        func_004f2c08
    /* 3F4B08 004F4B08 2D408002 */   daddu     $8, $20, $0
    /* 3F4B0C 004F4B0C 08004054 */  bnel       $2, $0, .L004F4B30
    /* 3F4B10 004F4B10 2D20A003 */   daddu     $4, $29, $0
    /* 3F4B14 004F4B14 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4B18 004F4B18 7600063C */  lui        $6, %hi(D_0075D7C0)
    /* 3F4B1C 004F4B1C C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4B20 004F4B20 C0D7C624 */  addiu      $6, $6, %lo(D_0075D7C0)
    /* 3F4B24 004F4B24 1E000010 */  b          .L004F4BA0
    /* 3F4B28 004F4B28 CE060524 */   addiu     $5, $0, 0x6CE
    /* 3F4B2C 004F4B2C 00000000 */  nop
  .L004F4B30:
    /* 3F4B30 004F4B30 A0CB130C */  jal        func_004f2e80
    /* 3F4B34 004F4B34 2D280000 */   daddu     $5, $0, $0
    /* 3F4B38 004F4B38 2D804000 */  daddu      $16, $2, $0
    /* 3F4B3C 004F4B3C 0A000016 */  bnez       $16, .L004F4B68
    /* 3F4B40 004F4B40 7600043C */   lui       $4, %hi(D_0075D6C8)
    /* 3F4B44 004F4B44 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F4B48 004F4B48 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4B4C 004F4B4C 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F4B50 004F4B50 D4060524 */  addiu      $5, $0, 0x6D4
    /* 3F4B54 004F4B54 2D380000 */  daddu      $7, $0, $0
    /* 3F4B58 004F4B58 F0D4130C */  jal        func_004f53c0
    /* 3F4B5C 004F4B5C 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F4B60 004F4B60 59000010 */  b          .L004F4CC8
    /* 3F4B64 004F4B64 1002B0DF */   ld        $16, 0x210($29)
  .L004F4B68:
    /* 3F4B68 004F4B68 03002016 */  bnez       $17, .L004F4B78
    /* 3F4B6C 004F4B6C 2D202002 */   daddu     $4, $17, $0
    /* 3F4B70 004F4B70 11000010 */  b          .L004F4BB8
    /* 3F4B74 004F4B74 1000118E */   lw        $17, 0x10($16)
  .L004F4B78:
    /* 3F4B78 004F4B78 D4C5130C */  jal        func_004f1750
    /* 3F4B7C 004F4B7C 2D284002 */   daddu     $5, $18, $0
    /* 3F4B80 004F4B80 2D884000 */  daddu      $17, $2, $0
    /* 3F4B84 004F4B84 0D002016 */  bnez       $17, .L004F4BBC
    /* 3F4B88 004F4B88 1000A383 */   lb        $3, 0x10($29)
    /* 3F4B8C 004F4B8C 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4B90 004F4B90 7600063C */  lui        $6, %hi(D_0075D888)
    /* 3F4B94 004F4B94 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4B98 004F4B98 88D8C624 */  addiu      $6, $6, %lo(D_0075D888)
    /* 3F4B9C 004F4B9C DF060524 */  addiu      $5, $0, 0x6DF
  .L004F4BA0:
    /* 3F4BA0 004F4BA0 2D380000 */  daddu      $7, $0, $0
    /* 3F4BA4 004F4BA4 F0D4130C */  jal        func_004f53c0
    /* 3F4BA8 004F4BA8 9CFF0824 */   addiu     $8, $0, -0x64
    /* 3F4BAC 004F4BAC 46000010 */  b          .L004F4CC8
    /* 3F4BB0 004F4BB0 1002B0DF */   ld        $16, 0x210($29)
    /* 3F4BB4 004F4BB4 00000000 */  nop
  .L004F4BB8:
    /* 3F4BB8 004F4BB8 1000A383 */  lb         $3, 0x10($29)
  .L004F4BBC:
    /* 3F4BBC 004F4BBC 2F000224 */  addiu      $2, $0, 0x2F
    /* 3F4BC0 004F4BC0 03006210 */  beq        $3, $2, .L004F4BD0
    /* 3F4BC4 004F4BC4 5C000224 */   addiu     $2, $0, 0x5C
    /* 3F4BC8 004F4BC8 13006254 */  bnel       $3, $2, .L004F4C18
    /* 3F4BCC 004F4BCC 1000058E */   lw        $5, 0x10($16)
  .L004F4BD0:
    /* 3F4BD0 004F4BD0 7400123C */  lui        $18, %hi(D_00743A50)
    /* 3F4BD4 004F4BD4 0800068E */  lw         $6, 0x8($16)
    /* 3F4BD8 004F4BD8 503A428E */  lw         $2, %lo(D_00743A50)($18)
    /* 3F4BDC 004F4BDC 2D406002 */  daddu      $8, $19, $0
    /* 3F4BE0 004F4BE0 0C00078E */  lw         $7, 0xC($16)
    /* 3F4BE4 004F4BE4 2D200002 */  daddu      $4, $16, $0
    /* 3F4BE8 004F4BE8 1EE1130C */  jal        func_004f8478
    /* 3F4BEC 004F4BEC 4800458C */   lw        $5, 0x48($2)
    /* 3F4BF0 004F4BF0 2D304000 */  daddu      $6, $2, $0
    /* 3F4BF4 004F4BF4 2E00C05C */  bgtzl      $6, .L004F4CB0
    /* 3F4BF8 004F4BF8 00080824 */   addiu     $8, $0, 0x800
    /* 3F4BFC 004F4BFC 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4C00 004F4C00 7600063C */  lui        $6, %hi(D_0075D8A0)
    /* 3F4C04 004F4C04 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4C08 004F4C08 A0D8C624 */  addiu      $6, $6, %lo(D_0075D8A0)
    /* 3F4C0C 004F4C0C F2060524 */  addiu      $5, $0, 0x6F2
    /* 3F4C10 004F4C10 0D000010 */  b          .L004F4C48
    /* 3F4C14 004F4C14 2D380000 */   daddu     $7, $0, $0
  .L004F4C18:
    /* 3F4C18 004F4C18 2D206002 */  daddu      $4, $19, $0
    /* 3F4C1C 004F4C1C 90E0130C */  jal        func_004f8240
    /* 3F4C20 004F4C20 2D300002 */   daddu     $6, $16, $0
    /* 3F4C24 004F4C24 2D204000 */  daddu      $4, $2, $0
    /* 3F4C28 004F4C28 0B008014 */  bnez       $4, .L004F4C58
    /* 3F4C2C 004F4C2C 40100400 */   sll       $2, $4, 1
    /* 3F4C30 004F4C30 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4C34 004F4C34 7600063C */  lui        $6, %hi(D_0075D7E8)
    /* 3F4C38 004F4C38 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4C3C 004F4C3C E8D7C624 */  addiu      $6, $6, %lo(D_0075D7E8)
    /* 3F4C40 004F4C40 2D388002 */  daddu      $7, $20, $0
    /* 3F4C44 004F4C44 FE060524 */  addiu      $5, $0, 0x6FE
  .L004F4C48:
    /* 3F4C48 004F4C48 F0D4130C */  jal        func_004f53c0
    /* 3F4C4C 004F4C4C 95FF0824 */   addiu     $8, $0, -0x6B
    /* 3F4C50 004F4C50 1D000010 */  b          .L004F4CC8
    /* 3F4C54 004F4C54 1002B0DF */   ld        $16, 0x210($29)
  .L004F4C58:
    /* 3F4C58 004F4C58 1000038E */  lw         $3, 0x10($16)
    /* 3F4C5C 004F4C5C 21104400 */  addu       $2, $2, $4
    /* 3F4C60 004F4C60 00110200 */  sll        $2, $2, 4
    /* 3F4C64 004F4C64 21186200 */  addu       $3, $3, $2
    /* 3F4C68 004F4C68 E8FF6324 */  addiu      $3, $3, -0x18
    /* 3F4C6C 004F4C6C 0C006290 */  lbu        $2, 0xC($3)
    /* 3F4C70 004F4C70 02004230 */  andi       $2, $2, 0x2
    /* 3F4C74 004F4C74 0C004054 */  bnel       $2, $0, .L004F4CA8
    /* 3F4C78 004F4C78 0000688C */   lw        $8, 0x0($3)
    /* 3F4C7C 004F4C7C 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4C80 004F4C80 7600063C */  lui        $6, %hi(D_0075D8B8)
    /* 3F4C84 004F4C84 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4C88 004F4C88 B8D8C624 */  addiu      $6, $6, %lo(D_0075D8B8)
    /* 3F4C8C 004F4C8C 07070524 */  addiu      $5, $0, 0x707
    /* 3F4C90 004F4C90 2D380000 */  daddu      $7, $0, $0
    /* 3F4C94 004F4C94 F0D4130C */  jal        func_004f53c0
    /* 3F4C98 004F4C98 96FF0824 */   addiu     $8, $0, -0x6A
    /* 3F4C9C 004F4C9C 0A000010 */  b          .L004F4CC8
    /* 3F4CA0 004F4CA0 1002B0DF */   ld        $16, 0x210($29)
    /* 3F4CA4 004F4CA4 00000000 */  nop
  .L004F4CA8:
    /* 3F4CA8 004F4CA8 7400123C */  lui        $18, %hi(D_00743A50)
    /* 3F4CAC 004F4CAC 0800668C */  lw         $6, 0x8($3)
  .L004F4CB0:
    /* 3F4CB0 004F4CB0 503A428E */  lw         $2, %lo(D_00743A50)($18)
    /* 3F4CB4 004F4CB4 2D200002 */  daddu      $4, $16, $0
    /* 3F4CB8 004F4CB8 2D382002 */  daddu      $7, $17, $0
    /* 3F4CBC 004F4CBC 62DF130C */  jal        func_004f7d88
    /* 3F4CC0 004F4CC0 4800458C */   lw        $5, 0x48($2)
    /* 3F4CC4 004F4CC4 1002B0DF */  ld         $16, 0x210($29)
  .L004F4CC8:
    /* 3F4CC8 004F4CC8 1802B1DF */  ld         $17, 0x218($29)
    /* 3F4CCC 004F4CCC 2002B2DF */  ld         $18, 0x220($29)
    /* 3F4CD0 004F4CD0 2802B3DF */  ld         $19, 0x228($29)
    /* 3F4CD4 004F4CD4 3002B4DF */  ld         $20, 0x230($29)
    /* 3F4CD8 004F4CD8 3802BFDF */  ld         $31, 0x238($29)
    /* 3F4CDC 004F4CDC 0800E003 */  jr         $31
    /* 3F4CE0 004F4CE0 4002BD27 */   addiu     $29, $29, 0x240
    /* 3F4CE4 004F4CE4 00000000 */  nop
.size func_004f4ac8, 0x220
