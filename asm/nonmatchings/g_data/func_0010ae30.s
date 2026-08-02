.section .text
.set noat
.set noreorder
glabel func_0010ae30
    /* AE30 0010AE30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* AE34 0010AE34 2000BFFF */  sd         $31, 0x20($29)
    /* AE38 0010AE38 1000B17F */  sq         $17, 0x10($29)
    /* AE3C 0010AE3C 0000B07F */  sq         $16, 0x0($29)
    /* AE40 0010AE40 2D888000 */  daddu      $17, $4, $0
    /* AE44 0010AE44 3C841100 */  dsll32     $16, $17, 16
    /* AE48 0010AE48 3F841000 */  dsra32     $16, $16, 16
    /* AE4C 0010AE4C 07000006 */  bltz       $16, .L0010AE6C
    /* AE50 0010AE50 00000000 */   nop
    /* AE54 0010AE54 6C2D040C */  jal        func_0010b5b0
    /* AE58 0010AE58 00000000 */   nop
    /* AE5C 0010AE5C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* AE60 0010AE60 2A100202 */  slt        $2, $16, $2
    /* AE64 0010AE64 06004014 */  bnez       $2, .L0010AE80
    /* AE68 0010AE68 00000000 */   nop
  .L0010AE6C:
    /* AE6C 0010AE6C 5E00043C */  lui        $4, %hi(D_005E4318)
    /* AE70 0010AE70 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* AE74 0010AE74 17040524 */  addiu      $5, $0, 0x417
    /* AE78 0010AE78 CCB5110C */  jal        func_0046d730
    /* AE7C 0010AE7C 00000000 */   nop
  .L0010AE80:
    /* AE80 0010AE80 40101000 */  sll        $2, $16, 1
    /* AE84 0010AE84 21105000 */  addu       $2, $2, $16
    /* AE88 0010AE88 00190200 */  sll        $3, $2, 4
    /* AE8C 0010AE8C 7900023C */  lui        $2, %hi(D_00797F8C)
    /* AE90 0010AE90 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* AE94 0010AE94 21104300 */  addu       $2, $2, $3
    /* AE98 0010AE98 00004294 */  lhu        $2, 0x0($2)
    /* AE9C 0010AE9C 01004230 */  andi       $2, $2, 0x1
    /* AEA0 0010AEA0 04004014 */  bnez       $2, .L0010AEB4
    /* AEA4 0010AEA4 00000000 */   nop
    /* AEA8 0010AEA8 2D100000 */  daddu      $2, $0, $0
    /* AEAC 0010AEAC 52000010 */  b          .L0010AFF8
    /* AEB0 0010AEB0 00000000 */   nop
  .L0010AEB4:
    /* AEB4 0010AEB4 182D040C */  jal        func_0010b460
    /* AEB8 0010AEB8 00000000 */   nop
    /* AEBC 0010AEBC 3C840200 */  dsll32     $16, $2, 16
    /* AEC0 0010AEC0 3F841000 */  dsra32     $16, $16, 16
    /* AEC4 0010AEC4 3C8C1100 */  dsll32     $17, $17, 16
    /* AEC8 0010AEC8 3F8C1100 */  dsra32     $17, $17, 16
    /* AECC 0010AECC 16000010 */  b          .L0010AF28
    /* AED0 0010AED0 00000000 */   nop
  .L0010AED4:
    /* AED4 0010AED4 3C1C1100 */  dsll32     $3, $17, 16
    /* AED8 0010AED8 3F1C0300 */  dsra32     $3, $3, 16
    /* AEDC 0010AEDC 40100300 */  sll        $2, $3, 1
    /* AEE0 0010AEE0 21104300 */  addu       $2, $2, $3
    /* AEE4 0010AEE4 00110200 */  sll        $2, $2, 4
    /* AEE8 0010AEE8 7900053C */  lui        $5, %hi(D_007973A0)
    /* AEEC 0010AEEC A073A524 */  addiu      $5, $5, %lo(D_007973A0)
    /* AEF0 0010AEF0 2120A200 */  addu       $4, $5, $2
    /* AEF4 0010AEF4 01006324 */  addiu      $3, $3, 0x1
    /* AEF8 0010AEF8 40100300 */  sll        $2, $3, 1
    /* AEFC 0010AEFC 21104300 */  addu       $2, $2, $3
    /* AF00 0010AF00 00110200 */  sll        $2, $2, 4
    /* AF04 0010AF04 2110A200 */  addu       $2, $5, $2
    /* AF08 0010AF08 EC0B8424 */  addiu      $4, $4, 0xBEC
    /* AF0C 0010AF0C EC0B4524 */  addiu      $5, $2, 0xBEC
    /* AF10 0010AF10 30000624 */  addiu      $6, $0, 0x30
    /* AF14 0010AF14 04FE100C */  jal        func_0043f810
    /* AF18 0010AF18 00000000 */   nop
    /* AF1C 0010AF1C 01002226 */  addiu      $2, $17, 0x1
    /* AF20 0010AF20 3C8C0200 */  dsll32     $17, $2, 16
    /* AF24 0010AF24 3F8C1100 */  dsra32     $17, $17, 16
  .L0010AF28:
    /* AF28 0010AF28 3C141100 */  dsll32     $2, $17, 16
    /* AF2C 0010AF2C 3F140200 */  dsra32     $2, $2, 16
    /* AF30 0010AF30 0B004228 */  slti       $2, $2, 0xB
    /* AF34 0010AF34 E7FF4014 */  bnez       $2, .L0010AED4
    /* AF38 0010AF38 00000000 */   nop
    /* AF3C 0010AF3C 7A00043C */  lui        $4, %hi(D_0079819C)
    /* AF40 0010AF40 9C818424 */  addiu      $4, $4, %lo(D_0079819C)
    /* AF44 0010AF44 2D280000 */  daddu      $5, $0, $0
    /* AF48 0010AF48 30000624 */  addiu      $6, $0, 0x30
    /* AF4C 0010AF4C 72FE100C */  jal        func_0043f9c8
    /* AF50 0010AF50 00000000 */   nop
    /* AF54 0010AF54 6C2D040C */  jal        func_0010b5b0
    /* AF58 0010AF58 00000000 */   nop
    /* AF5C 0010AF5C FFFF4630 */  andi       $6, $2, 0xFFFF
    /* AF60 0010AF60 2D380000 */  daddu      $7, $0, $0
    /* AF64 0010AF64 3C2C1000 */  dsll32     $5, $16, 16
    /* AF68 0010AF68 3F2C0500 */  dsra32     $5, $5, 16
    /* AF6C 0010AF6C 7900043C */  lui        $4, %hi(D_007973A0)
    /* AF70 0010AF70 A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* AF74 0010AF74 13000010 */  b          .L0010AFC4
    /* AF78 0010AF78 00000000 */   nop
  .L0010AF7C:
    /* AF7C 0010AF7C FFFFE330 */  andi       $3, $7, 0xFFFF
    /* AF80 0010AF80 40100300 */  sll        $2, $3, 1
    /* AF84 0010AF84 21104300 */  addu       $2, $2, $3
    /* AF88 0010AF88 00110200 */  sll        $2, $2, 4
    /* AF8C 0010AF8C 21188200 */  addu       $3, $4, $2
    /* AF90 0010AF90 EC0B6294 */  lhu        $2, 0xBEC($3)
    /* AF94 0010AF94 01004230 */  andi       $2, $2, 0x1
    /* AF98 0010AF98 08004010 */  beqz       $2, .L0010AFBC
    /* AF9C 0010AF9C 00000000 */   nop
    /* AFA0 0010AFA0 EE0B6294 */  lhu        $2, 0xBEE($3)
    /* AFA4 0010AFA4 05004514 */  bne        $2, $5, .L0010AFBC
    /* AFA8 0010AFA8 00000000 */   nop
    /* AFAC 0010AFAC 3C240700 */  dsll32     $4, $7, 16
    /* AFB0 0010AFB0 3F240400 */  dsra32     $4, $4, 16
    /* AFB4 0010AFB4 08000010 */  b          .L0010AFD8
    /* AFB8 0010AFB8 00000000 */   nop
  .L0010AFBC:
    /* AFBC 0010AFBC 0100E224 */  addiu      $2, $7, 0x1
    /* AFC0 0010AFC0 FFFF4730 */  andi       $7, $2, 0xFFFF
  .L0010AFC4:
    /* AFC4 0010AFC4 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AFC8 0010AFC8 2A104600 */  slt        $2, $2, $6
    /* AFCC 0010AFCC EBFF4014 */  bnez       $2, .L0010AF7C
    /* AFD0 0010AFD0 00000000 */   nop
    /* AFD4 0010AFD4 FFFF0424 */  addiu      $4, $0, -0x1
  .L0010AFD8:
    /* AFD8 0010AFD8 3C1C0400 */  dsll32     $3, $4, 16
    /* AFDC 0010AFDC 3F1C0300 */  dsra32     $3, $3, 16
    /* AFE0 0010AFE0 FFFF0224 */  addiu      $2, $0, -0x1
    /* AFE4 0010AFE4 03006210 */  beq        $3, $2, .L0010AFF4
    /* AFE8 0010AFE8 00000000 */   nop
    /* AFEC 0010AFEC EC2C040C */  jal        func_0010b3b0
    /* AFF0 0010AFF0 00000000 */   nop
  .L0010AFF4:
    /* AFF4 0010AFF4 01000224 */  addiu      $2, $0, 0x1
  .L0010AFF8:
    /* AFF8 0010AFF8 2000BFDF */  ld         $31, 0x20($29)
    /* AFFC 0010AFFC 1000B17B */  lq         $17, 0x10($29)
    /* B000 0010B000 0000B07B */  lq         $16, 0x0($29)
    /* B004 0010B004 3000BD27 */  addiu      $29, $29, 0x30
    /* B008 0010B008 0800E003 */  jr         $31
    /* B00C 0010B00C 00000000 */   nop
.size func_0010ae30, 0x1e0
