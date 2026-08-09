.section .text
.set noat
.set noreorder
glabel func_001c8b00
    /* C8B00 001C8B00 70FFBD27 */  addiu      $29, $29, -0x90
    /* C8B04 001C8B04 5000BFFF */  sd         $31, 0x50($29)
    /* C8B08 001C8B08 4000B47F */  sq         $20, 0x40($29)
    /* C8B0C 001C8B0C 3000B37F */  sq         $19, 0x30($29)
    /* C8B10 001C8B10 2000B27F */  sq         $18, 0x20($29)
    /* C8B14 001C8B14 1000B17F */  sq         $17, 0x10($29)
    /* C8B18 001C8B18 0000B07F */  sq         $16, 0x0($29)
    /* C8B1C 001C8B1C 2D808000 */  daddu      $16, $4, $0
    /* C8B20 001C8B20 06018394 */  lhu        $3, 0x106($4)
    /* C8B24 001C8B24 66006014 */  bnez       $3, .L001C8CC0
    /* C8B28 001C8B28 00000000 */   nop
    /* C8B2C 001C8B2C 485C110C */  jal        func_00457120
    /* C8B30 001C8B30 00000000 */   nop
    /* C8B34 001C8B34 0400428C */  lw         $2, 0x4($2)
    /* C8B38 001C8B38 10005224 */  addiu      $18, $2, 0x10
    /* C8B3C 001C8B3C E000028E */  lw         $2, 0xE0($16)
    /* C8B40 001C8B40 98004424 */  addiu      $4, $2, 0x98
    /* C8B44 001C8B44 F062070C */  jal        func_001d8bc0
    /* C8B48 001C8B48 00000000 */   nop
    /* C8B4C 001C8B4C 3000538C */  lw         $19, 0x30($2)
    /* C8B50 001C8B50 E000028E */  lw         $2, 0xE0($16)
    /* C8B54 001C8B54 3000508C */  lw         $16, 0x30($2)
    /* C8B58 001C8B58 2D206002 */  daddu      $4, $19, $0
    /* C8B5C 001C8B5C 6000A527 */  addiu      $5, $29, 0x60
    /* C8B60 001C8B60 8800A627 */  addiu      $6, $29, 0x88
    /* C8B64 001C8B64 2D384002 */  daddu      $7, $18, $0
    /* C8B68 001C8B68 3422070C */  jal        func_001c88d0
    /* C8B6C 001C8B6C 00000000 */   nop
    /* C8B70 001C8B70 53004010 */  beqz       $2, .L001C8CC0
    /* C8B74 001C8B74 00000000 */   nop
    /* C8B78 001C8B78 2D206002 */  daddu      $4, $19, $0
    /* C8B7C 001C8B7C 4CF5060C */  jal        func_001bd530
    /* C8B80 001C8B80 00000000 */   nop
    /* C8B84 001C8B84 2D880000 */  daddu      $17, $0, $0
    /* C8B88 001C8B88 4A000010 */  b          .L001C8CB4
    /* C8B8C 001C8B8C 00000000 */   nop
  .L001C8B90:
    /* C8B90 001C8B90 C0201100 */  sll        $4, $17, 3
    /* C8B94 001C8B94 ACB3838F */  lw         $3, -0x4C54($28)
    /* C8B98 001C8B98 21186400 */  addu       $3, $3, $4
    /* C8B9C 001C8B9C 7801748C */  lw         $20, 0x178($3)
    /* C8BA0 001C8BA0 41000010 */  b          .L001C8CA8
    /* C8BA4 001C8BA4 00000000 */   nop
  .L001C8BA8:
    /* C8BA8 001C8BA8 9C00838E */  lw         $3, 0x9C($20)
    /* C8BAC 001C8BAC 08006330 */  andi       $3, $3, 0x8
    /* C8BB0 001C8BB0 3C006010 */  beqz       $3, .L001C8CA4
    /* C8BB4 001C8BB4 00000000 */   nop
    /* C8BB8 001C8BB8 3A007412 */  beq        $19, $20, .L001C8CA4
    /* C8BBC 001C8BBC 00000000 */   nop
    /* C8BC0 001C8BC0 38001412 */  beq        $16, $20, .L001C8CA4
    /* C8BC4 001C8BC4 00000000 */   nop
    /* C8BC8 001C8BC8 2D208002 */  daddu      $4, $20, $0
    /* C8BCC 001C8BCC 7000A527 */  addiu      $5, $29, 0x70
    /* C8BD0 001C8BD0 8C00A627 */  addiu      $6, $29, 0x8C
    /* C8BD4 001C8BD4 2D384002 */  daddu      $7, $18, $0
    /* C8BD8 001C8BD8 3422070C */  jal        func_001c88d0
    /* C8BDC 001C8BDC 00000000 */   nop
    /* C8BE0 001C8BE0 06004014 */  bnez       $2, .L001C8BFC
    /* C8BE4 001C8BE4 00000000 */   nop
    /* C8BE8 001C8BE8 2D206002 */  daddu      $4, $19, $0
    /* C8BEC 001C8BEC 4CF5060C */  jal        func_001bd530
    /* C8BF0 001C8BF0 00000000 */   nop
    /* C8BF4 001C8BF4 2B000010 */  b          .L001C8CA4
    /* C8BF8 001C8BF8 00000000 */   nop
  .L001C8BFC:
    /* C8BFC 001C8BFC 8C00A1C7 */  lwc1       $f1, 0x8C($29)
    /* C8C00 001C8C00 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* C8C04 001C8C04 36080046 */  c.le.s     $f1, $f0
    /* C8C08 001C8C08 06000145 */  bc1t       .L001C8C24
    /* C8C0C 001C8C0C 00000000 */   nop
    /* C8C10 001C8C10 2D206002 */  daddu      $4, $19, $0
    /* C8C14 001C8C14 4CF5060C */  jal        func_001bd530
    /* C8C18 001C8C18 00000000 */   nop
    /* C8C1C 001C8C1C 21000010 */  b          .L001C8CA4
    /* C8C20 001C8C20 00000000 */   nop
  .L001C8C24:
    /* C8C24 001C8C24 7000A48F */  lw         $4, 0x70($29)
    /* C8C28 001C8C28 6000A38F */  lw         $3, 0x60($29)
    /* C8C2C 001C8C2C 7800A28F */  lw         $2, 0x78($29)
    /* C8C30 001C8C30 21108200 */  addu       $2, $4, $2
    /* C8C34 001C8C34 2A084300 */  slt        $1, $2, $3
    /* C8C38 001C8C38 17002014 */  bnez       $1, .L001C8C98
    /* C8C3C 001C8C3C 00000000 */   nop
    /* C8C40 001C8C40 6800A28F */  lw         $2, 0x68($29)
    /* C8C44 001C8C44 21106200 */  addu       $2, $3, $2
    /* C8C48 001C8C48 2A084400 */  slt        $1, $2, $4
    /* C8C4C 001C8C4C 12002014 */  bnez       $1, .L001C8C98
    /* C8C50 001C8C50 00000000 */   nop
    /* C8C54 001C8C54 7400A48F */  lw         $4, 0x74($29)
    /* C8C58 001C8C58 6400A38F */  lw         $3, 0x64($29)
    /* C8C5C 001C8C5C 7C00A28F */  lw         $2, 0x7C($29)
    /* C8C60 001C8C60 21108200 */  addu       $2, $4, $2
    /* C8C64 001C8C64 2A084300 */  slt        $1, $2, $3
    /* C8C68 001C8C68 0B002014 */  bnez       $1, .L001C8C98
    /* C8C6C 001C8C6C 00000000 */   nop
    /* C8C70 001C8C70 6C00A28F */  lw         $2, 0x6C($29)
    /* C8C74 001C8C74 21106200 */  addu       $2, $3, $2
    /* C8C78 001C8C78 2A084400 */  slt        $1, $2, $4
    /* C8C7C 001C8C7C 06002014 */  bnez       $1, .L001C8C98
    /* C8C80 001C8C80 00000000 */   nop
    /* C8C84 001C8C84 2D208002 */  daddu      $4, $20, $0
    /* C8C88 001C8C88 3CF5060C */  jal        func_001bd4f0
    /* C8C8C 001C8C8C 00000000 */   nop
    /* C8C90 001C8C90 04000010 */  b          .L001C8CA4
    /* C8C94 001C8C94 00000000 */   nop
  .L001C8C98:
    /* C8C98 001C8C98 2D206002 */  daddu      $4, $19, $0
    /* C8C9C 001C8C9C 4CF5060C */  jal        func_001bd530
    /* C8CA0 001C8CA0 00000000 */   nop
  .L001C8CA4:
    /* C8CA4 001C8CA4 6C0A948E */  lw         $20, 0xA6C($20)
  .L001C8CA8:
    /* C8CA8 001C8CA8 BFFF8016 */  bnez       $20, .L001C8BA8
    /* C8CAC 001C8CAC 00000000 */   nop
    /* C8CB0 001C8CB0 01003126 */  addiu      $17, $17, 0x1
  .L001C8CB4:
    /* C8CB4 001C8CB4 0200232A */  slti       $3, $17, 0x2
    /* C8CB8 001C8CB8 B5FF6014 */  bnez       $3, .L001C8B90
    /* C8CBC 001C8CBC 00000000 */   nop
  .L001C8CC0:
    /* C8CC0 001C8CC0 5000BFDF */  ld         $31, 0x50($29)
    /* C8CC4 001C8CC4 4000B47B */  lq         $20, 0x40($29)
    /* C8CC8 001C8CC8 3000B37B */  lq         $19, 0x30($29)
    /* C8CCC 001C8CCC 2000B27B */  lq         $18, 0x20($29)
    /* C8CD0 001C8CD0 1000B17B */  lq         $17, 0x10($29)
    /* C8CD4 001C8CD4 0000B07B */  lq         $16, 0x0($29)
    /* C8CD8 001C8CD8 9000BD27 */  addiu      $29, $29, 0x90
    /* C8CDC 001C8CDC 0800E003 */  jr         $31
    /* C8CE0 001C8CE0 00000000 */   nop
    /* C8CE4 001C8CE4 00000000 */  nop
    /* C8CE8 001C8CE8 00000000 */  nop
    /* C8CEC 001C8CEC 00000000 */  nop
.size func_001c8b00, 0x1f0
