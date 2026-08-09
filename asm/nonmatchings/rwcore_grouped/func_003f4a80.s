.section .text
.set noat
.set noreorder
glabel func_003f4a80
    /* 2F4A80 003F4A80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F4A84 003F4A84 0000BFFF */  sd         $31, 0x0($29)
    /* 2F4A88 003F4A88 D0CB0F0C */  jal        func_003f2f40
    /* 2F4A8C 003F4A8C 00000000 */   nop
    /* 2F4A90 003F4A90 8CB8828F */  lw         $2, -0x4774($28)
    /* 2F4A94 003F4A94 22004010 */  beqz       $2, .L003F4B20
    /* 2F4A98 003F4A98 00000000 */   nop
    /* 2F4A9C 003F4A9C 0110023C */  lui        $2, (0x10010000 >> 16)
    /* 2F4AA0 003F4AA0 00D0438C */  lw         $3, -0x3000($2)
    /* 2F4AA4 003F4AA4 00016330 */  andi       $3, $3, 0x100
    /* 2F4AA8 003F4AA8 2B006014 */  bnez       $3, .L003F4B58
    /* 2F4AAC 003F4AAC 00000000 */   nop
    /* 2F4AB0 003F4AB0 90B8828F */  lw         $2, -0x4770($28)
  .L003F4AB4:
    /* 2F4AB4 003F4AB4 10004010 */  beqz       $2, .L003F4AF8
    /* 2F4AB8 003F4AB8 00000000 */   nop
    /* 2F4ABC 003F4ABC 88B8838F */  lw         $3, -0x4778($28)
    /* 2F4AC0 003F4AC0 21110424 */  addiu      $4, $0, 0x1121
    /* 2F4AC4 003F4AC4 22010224 */  addiu      $2, $0, 0x122
    /* 2F4AC8 003F4AC8 000064AC */  sw         $4, 0x0($3)
    /* 2F4ACC 003F4ACC 94B8848F */  lw         $4, -0x476C($28)
    /* 2F4AD0 003F4AD0 88B8838F */  lw         $3, -0x4778($28)
    /* 2F4AD4 003F4AD4 040064AC */  sw         $4, 0x4($3)
    /* 2F4AD8 003F4AD8 88B8848F */  lw         $4, -0x4778($28)
    /* 2F4ADC 003F4ADC 08008324 */  addiu      $3, $4, 0x8
    /* 2F4AE0 003F4AE0 88B883AF */  sw         $3, -0x4778($28)
    /* 2F4AE4 003F4AE4 080082AC */  sw         $2, 0x8($4)
    /* 2F4AE8 003F4AE8 90B8838F */  lw         $3, -0x4770($28)
    /* 2F4AEC 003F4AEC 88B8828F */  lw         $2, -0x4778($28)
    /* 2F4AF0 003F4AF0 07000010 */  b          .L003F4B10
    /* 2F4AF4 003F4AF4 040043AC */   sw        $3, 0x4($2)
  .L003F4AF8:
    /* 2F4AF8 003F4AF8 8CB8838F */  lw         $3, -0x4774($28)
    /* 2F4AFC 003F4AFC 88B8828F */  lw         $2, -0x4778($28)
    /* 2F4B00 003F4B00 000043AC */  sw         $3, 0x0($2)
    /* 2F4B04 003F4B04 94B8838F */  lw         $3, -0x476C($28)
    /* 2F4B08 003F4B08 88B8828F */  lw         $2, -0x4778($28)
    /* 2F4B0C 003F4B0C 040043AC */  sw         $3, 0x4($2)
  .L003F4B10:
    /* 2F4B10 003F4B10 94B880AF */  sw         $0, -0x476C($28)
    /* 2F4B14 003F4B14 90B880AF */  sw         $0, -0x4770($28)
    /* 2F4B18 003F4B18 8CB880AF */  sw         $0, -0x4774($28)
    /* 2F4B1C 003F4B1C 88B880AF */  sw         $0, -0x4778($28)
  .L003F4B20:
    /* 2F4B20 003F4B20 D8C90F0C */  jal        func_003f2760
    /* 2F4B24 003F4B24 00000000 */   nop
    /* 2F4B28 003F4B28 70B88493 */  lbu        $4, -0x4790($28)
    /* 2F4B2C 003F4B2C 78B88327 */  addiu      $3, $28, -0x4788
    /* 2F4B30 003F4B30 58B8828F */  lw         $2, -0x47A8($28)
    /* 2F4B34 003F4B34 80200400 */  sll        $4, $4, 2
    /* 2F4B38 003F4B38 21186400 */  addu       $3, $3, $4
    /* 2F4B3C 003F4B3C 0000638C */  lw         $3, 0x0($3)
    /* 2F4B40 003F4B40 12006210 */  beq        $3, $2, .L003F4B8C
    /* 2F4B44 003F4B44 00000000 */   nop
    /* 2F4B48 003F4B48 B4CC0F0C */  jal        func_003f32d0
    /* 2F4B4C 003F4B4C 00000000 */   nop
    /* 2F4B50 003F4B50 0F000010 */  b          .L003F4B90
    /* 2F4B54 003F4B54 40B88293 */   lbu       $2, -0x47C0($28)
  .L003F4B58:
    /* 2F4B58 003F4B58 00010324 */  addiu      $3, $0, 0x100
    /* 2F4B5C 003F4B5C 20E043AC */  sw         $3, -0x1FE0($2)
    /* 2F4B60 003F4B60 0F000000 */  sync
    /* 2F4B64 003F4B64 0F040000 */  sync.p
  .L003F4B68:
    /* 2F4B68 003F4B68 00000000 */  nop
    /* 2F4B6C 003F4B6C 00000000 */  nop
    /* 2F4B70 003F4B70 00000000 */  nop
    /* 2F4B74 003F4B74 00000000 */  nop
    /* 2F4B78 003F4B78 00000000 */  nop
    /* 2F4B7C 003F4B7C FAFF0041 */  bc0f       .L003F4B68 /* handwritten instruction */
    /* 2F4B80 003F4B80 00000000 */   nop
    /* 2F4B84 003F4B84 CBFF0010 */  b          .L003F4AB4
    /* 2F4B88 003F4B88 90B8828F */   lw        $2, -0x4770($28)
  .L003F4B8C:
    /* 2F4B8C 003F4B8C 40B88293 */  lbu        $2, -0x47C0($28)
  .L003F4B90:
    /* 2F4B90 003F4B90 00000000 */  nop
    /* 2F4B94 003F4B94 00000000 */  nop
    /* 2F4B98 003F4B98 00000000 */  nop
    /* 2F4B9C 003F4B9C 00000000 */  nop
    /* 2F4BA0 003F4BA0 FAFF4014 */  bnez       $2, .L003F4B8C
    /* 2F4BA4 003F4BA4 00000000 */   nop
    /* 2F4BA8 003F4BA8 3CB88293 */  lbu        $2, -0x47C4($28)
    /* 2F4BAC 003F4BAC F7FF4014 */  bnez       $2, .L003F4B8C
    /* 2F4BB0 003F4BB0 00000000 */   nop
    /* 2F4BB4 003F4BB4 40B88293 */  lbu        $2, -0x47C0($28)
    /* 2F4BB8 003F4BB8 F4FF4014 */  bnez       $2, .L003F4B8C
    /* 2F4BBC 003F4BBC 00000000 */   nop
    /* 2F4BC0 003F4BC0 F8D20F0C */  jal        func_003f4be0
    /* 2F4BC4 003F4BC4 00000000 */   nop
    /* 2F4BC8 003F4BC8 0000BFDF */  ld         $31, 0x0($29)
    /* 2F4BCC 003F4BCC 0800E003 */  jr         $31
    /* 2F4BD0 003F4BD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 2F4BD4 003F4BD4 00000000 */  nop
    /* 2F4BD8 003F4BD8 00000000 */  nop
    /* 2F4BDC 003F4BDC 00000000 */  nop
.size func_003f4a80, 0x160
