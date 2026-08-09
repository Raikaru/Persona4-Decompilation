.section .text
.set noat
.set noreorder
glabel func_003eaf60
    /* 2EAF60 003EAF60 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2EAF64 003EAF64 3A000524 */  addiu      $5, $0, 0x3A
    /* 2EAF68 003EAF68 4000BFFF */  sd         $31, 0x40($29)
    /* 2EAF6C 003EAF6C 3000B37F */  sq         $19, 0x30($29)
    /* 2EAF70 003EAF70 2000B27F */  sq         $18, 0x20($29)
    /* 2EAF74 003EAF74 1000B17F */  sq         $17, 0x10($29)
    /* 2EAF78 003EAF78 0000B07F */  sq         $16, 0x0($29)
    /* 2EAF7C 003EAF7C 8800103C */  lui        $16, %hi(D_008873BC)
    /* 2EAF80 003EAF80 BC731026 */  addiu      $16, $16, %lo(D_008873BC)
    /* 2EAF84 003EAF84 0000028E */  lw         $2, 0x0($16)
    /* 2EAF88 003EAF88 09F84000 */  jalr       $2
    /* 2EAF8C 003EAF8C 2D888000 */   daddu     $17, $4, $0
    /* 2EAF90 003EAF90 03004010 */  beqz       $2, .L003EAFA0
    /* 2EAF94 003EAF94 00000000 */   nop
    /* 2EAF98 003EAF98 02000010 */  b          .L003EAFA4
    /* 2EAF9C 003EAF9C 2D904000 */   daddu     $18, $2, $0
  .L003EAFA0:
    /* 2EAFA0 003EAFA0 2D902002 */  daddu      $18, $17, $0
  .L003EAFA4:
    /* 2EAFA4 003EAFA4 0000028E */  lw         $2, 0x0($16)
    /* 2EAFA8 003EAFA8 2D204002 */  daddu      $4, $18, $0
    /* 2EAFAC 003EAFAC 09F84000 */  jalr       $2
    /* 2EAFB0 003EAFB0 2F000524 */   addiu     $5, $0, 0x2F
    /* 2EAFB4 003EAFB4 02004010 */  beqz       $2, .L003EAFC0
    /* 2EAFB8 003EAFB8 00000000 */   nop
    /* 2EAFBC 003EAFBC 2D904000 */  daddu      $18, $2, $0
  .L003EAFC0:
    /* 2EAFC0 003EAFC0 0000028E */  lw         $2, 0x0($16)
    /* 2EAFC4 003EAFC4 2D204002 */  daddu      $4, $18, $0
    /* 2EAFC8 003EAFC8 09F84000 */  jalr       $2
    /* 2EAFCC 003EAFCC 5C000524 */   addiu     $5, $0, 0x5C
    /* 2EAFD0 003EAFD0 03004010 */  beqz       $2, .L003EAFE0
    /* 2EAFD4 003EAFD4 00000000 */   nop
    /* 2EAFD8 003EAFD8 03000010 */  b          .L003EAFE8
    /* 2EAFDC 003EAFDC 0000038E */   lw        $3, 0x0($16)
  .L003EAFE0:
    /* 2EAFE0 003EAFE0 2D104002 */  daddu      $2, $18, $0
    /* 2EAFE4 003EAFE4 0000038E */  lw         $3, 0x0($16)
  .L003EAFE8:
    /* 2EAFE8 003EAFE8 2D204000 */  daddu      $4, $2, $0
    /* 2EAFEC 003EAFEC 09F86000 */  jalr       $3
    /* 2EAFF0 003EAFF0 2E000524 */   addiu     $5, $0, 0x2E
    /* 2EAFF4 003EAFF4 2D804000 */  daddu      $16, $2, $0
    /* 2EAFF8 003EAFF8 2B000012 */  beqz       $16, .L003EB0A8
    /* 2EAFFC 003EAFFC 00000000 */   nop
    /* 2EB000 003EB000 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EB004 003EB004 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EB008 003EB008 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EB00C 003EB00C 21104300 */  addu       $2, $2, $3
    /* 2EB010 003EB010 1C02538C */  lw         $19, 0x21C($2)
    /* 2EB014 003EB014 12006012 */  beqz       $19, .L003EB060
    /* 2EB018 003EB018 00000000 */   nop
    /* 2EB01C 003EB01C 8800123C */  lui        $18, %hi(D_008873C8)
    /* 2EB020 003EB020 C8735226 */  addiu      $18, $18, %lo(D_008873C8)
  .L003EB024:
    /* 2EB024 003EB024 0000428E */  lw         $2, 0x0($18)
    /* 2EB028 003EB028 2D206002 */  daddu      $4, $19, $0
    /* 2EB02C 003EB02C 09F84000 */  jalr       $2
    /* 2EB030 003EB030 2D280002 */   daddu     $5, $16, $0
    /* 2EB034 003EB034 0C004010 */  beqz       $2, .L003EB068
    /* 2EB038 003EB038 00000000 */   nop
    /* 2EB03C 003EB03C 0000428E */  lw         $2, 0x0($18)
    /* 2EB040 003EB040 14006426 */  addiu      $4, $19, 0x14
    /* 2EB044 003EB044 09F84000 */  jalr       $2
    /* 2EB048 003EB048 2D280002 */   daddu     $5, $16, $0
    /* 2EB04C 003EB04C 06004010 */  beqz       $2, .L003EB068
    /* 2EB050 003EB050 00000000 */   nop
    /* 2EB054 003EB054 3000738E */  lw         $19, 0x30($19)
    /* 2EB058 003EB058 F2FF6016 */  bnez       $19, .L003EB024
    /* 2EB05C 003EB05C 00000000 */   nop
  .L003EB060:
    /* 2EB060 003EB060 12000010 */  b          .L003EB0AC
    /* 2EB064 003EB064 2D100000 */   daddu     $2, $0, $0
  .L003EB068:
    /* 2EB068 003EB068 2800628E */  lw         $2, 0x28($19)
    /* 2EB06C 003EB06C 0C004010 */  beqz       $2, .L003EB0A0
    /* 2EB070 003EB070 00000000 */   nop
    /* 2EB074 003EB074 3F00063C */  lui        $6, %hi(func_003eaf00)
    /* 2EB078 003EB078 5C00B027 */  addiu      $16, $29, 0x5C
    /* 2EB07C 003EB07C 5800A2AF */  sw         $2, 0x58($29)
    /* 2EB080 003EB080 2D202002 */  daddu      $4, $17, $0
    /* 2EB084 003EB084 05000524 */  addiu      $5, $0, 0x5
    /* 2EB088 003EB088 00AFC624 */  addiu      $6, $6, %lo(func_003eaf00)
    /* 2EB08C 003EB08C 5800A727 */  addiu      $7, $29, 0x58
    /* 2EB090 003EB090 DCAA0F0C */  jal        func_003eab70
    /* 2EB094 003EB094 000000AE */   sw        $0, 0x0($16)
    /* 2EB098 003EB098 04000010 */  b          .L003EB0AC
    /* 2EB09C 003EB09C 0000028E */   lw        $2, 0x0($16)
  .L003EB0A0:
    /* 2EB0A0 003EB0A0 02000010 */  b          .L003EB0AC
    /* 2EB0A4 003EB0A4 2D100000 */   daddu     $2, $0, $0
  .L003EB0A8:
    /* 2EB0A8 003EB0A8 2D100000 */  daddu      $2, $0, $0
  .L003EB0AC:
    /* 2EB0AC 003EB0AC 4000BFDF */  ld         $31, 0x40($29)
    /* 2EB0B0 003EB0B0 3000B37B */  lq         $19, 0x30($29)
    /* 2EB0B4 003EB0B4 2000B27B */  lq         $18, 0x20($29)
    /* 2EB0B8 003EB0B8 1000B17B */  lq         $17, 0x10($29)
    /* 2EB0BC 003EB0BC 0000B07B */  lq         $16, 0x0($29)
    /* 2EB0C0 003EB0C0 0800E003 */  jr         $31
    /* 2EB0C4 003EB0C4 6000BD27 */   addiu     $29, $29, 0x60
    /* 2EB0C8 003EB0C8 00000000 */  nop
    /* 2EB0CC 003EB0CC 00000000 */  nop
.size func_003eaf60, 0x170
