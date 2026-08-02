.section .text
.set noat
.set noreorder
glabel func_0045aeb0
    /* 35AEB0 0045AEB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 35AEB4 0045AEB4 1000BFFF */  sd         $31, 0x10($29)
    /* 35AEB8 0045AEB8 0000B07F */  sq         $16, 0x0($29)
    /* 35AEBC 0045AEBC 3C840400 */  dsll32     $16, $4, 16
    /* 35AEC0 0045AEC0 3F841000 */  dsra32     $16, $16, 16
    /* 35AEC4 0045AEC4 0500012A */  slti       $1, $16, 0x5
    /* 35AEC8 0045AEC8 1F002010 */  beqz       $1, .L0045AF48
    /* 35AECC 0045AECC 00000000 */   nop
    /* 35AED0 0045AED0 34010224 */  addiu      $2, $0, 0x134
    /* 35AED4 0045AED4 18380202 */  mult       $7, $16, $2
    /* 35AED8 0045AED8 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35AEDC 0045AEDC 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35AEE0 0045AEE0 21304700 */  addu       $6, $2, $7
    /* 35AEE4 0045AEE4 01000224 */  addiu      $2, $0, 0x1
    /* 35AEE8 0045AEE8 0000C2AC */  sw         $2, 0x0($6)
    /* 35AEEC 0045AEEC 8D00023C */  lui        $2, %hi(D_008D2B98)
    /* 35AEF0 0045AEF0 982B4224 */  addiu      $2, $2, %lo(D_008D2B98)
    /* 35AEF4 0045AEF4 21104700 */  addu       $2, $2, $7
    /* 35AEF8 0045AEF8 000040A4 */  sh         $0, 0x0($2)
    /* 35AEFC 0045AEFC 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35AF00 0045AF00 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35AF04 0045AF04 21104700 */  addu       $2, $2, $7
    /* 35AF08 0045AF08 000040A4 */  sh         $0, 0x0($2)
    /* 35AF0C 0045AF0C 8D00023C */  lui        $2, %hi(D_008D2BA4)
    /* 35AF10 0045AF10 A42B4224 */  addiu      $2, $2, %lo(D_008D2BA4)
    /* 35AF14 0045AF14 21204700 */  addu       $4, $2, $7
    /* 35AF18 0045AF18 00008384 */  lh         $3, 0x0($4)
    /* 35AF1C 0045AF1C 8D00023C */  lui        $2, %hi(D_008D2BA6)
    /* 35AF20 0045AF20 A62B4224 */  addiu      $2, $2, %lo(D_008D2BA6)
    /* 35AF24 0045AF24 21104700 */  addu       $2, $2, $7
    /* 35AF28 0045AF28 000043A4 */  sh         $3, 0x0($2)
    /* 35AF2C 0045AF2C 000080A4 */  sh         $0, 0x0($4)
    /* 35AF30 0045AF30 1800C424 */  addiu      $4, $6, 0x18
    /* 35AF34 0045AF34 0C0A110C */  jal        func_00442830
    /* 35AF38 0045AF38 00000000 */   nop
    /* 35AF3C 0045AF3C 2D200002 */  daddu      $4, $16, $0
    /* 35AF40 0045AF40 B466110C */  jal        func_00459ad0
    /* 35AF44 0045AF44 00000000 */   nop
  .L0045AF48:
    /* 35AF48 0045AF48 01000224 */  addiu      $2, $0, 0x1
    /* 35AF4C 0045AF4C 1000BFDF */  ld         $31, 0x10($29)
    /* 35AF50 0045AF50 0000B07B */  lq         $16, 0x0($29)
    /* 35AF54 0045AF54 2000BD27 */  addiu      $29, $29, 0x20
    /* 35AF58 0045AF58 0800E003 */  jr         $31
    /* 35AF5C 0045AF5C 00000000 */   nop
.size func_0045aeb0, 0xb0
