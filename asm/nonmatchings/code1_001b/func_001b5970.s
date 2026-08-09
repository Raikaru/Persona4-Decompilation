.section .text
.set noat
.set noreorder
glabel func_001b5970
    /* B5970 001B5970 C0FFBD27 */  addiu      $29, $29, -0x40
    /* B5974 001B5974 3000BFFF */  sd         $31, 0x30($29)
    /* B5978 001B5978 2000B27F */  sq         $18, 0x20($29)
    /* B597C 001B597C 1000B17F */  sq         $17, 0x10($29)
    /* B5980 001B5980 0000B07F */  sq         $16, 0x0($29)
    /* B5984 001B5984 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5988 001B5988 1C004394 */  lhu        $3, 0x1C($2)
    /* B598C 001B598C 01000224 */  addiu      $2, $0, 0x1
    /* B5990 001B5990 85006214 */  bne        $3, $2, .L001B5BA8
    /* B5994 001B5994 00000000 */   nop
    /* B5998 001B5998 38000424 */  addiu      $4, $0, 0x38
    /* B599C 001B599C CC18040C */  jal        func_00106330
    /* B59A0 001B59A0 00000000 */   nop
    /* B59A4 001B59A4 04004010 */  beqz       $2, .L001B59B8
    /* B59A8 001B59A8 00000000 */   nop
    /* B59AC 001B59AC 05000224 */  addiu      $2, $0, 0x5
    /* B59B0 001B59B0 02000010 */  b          .L001B59BC
    /* B59B4 001B59B4 00000000 */   nop
  .L001B59B8:
    /* B59B8 001B59B8 08000224 */  addiu      $2, $0, 0x8
  .L001B59BC:
    /* B59BC 001B59BC FFFF4430 */  andi       $4, $2, 0xFFFF
    /* B59C0 001B59C0 402A040C */  jal        func_0010a900
    /* B59C4 001B59C4 00000000 */   nop
    /* B59C8 001B59C8 2D804000 */  daddu      $16, $2, $0
    /* B59CC 001B59CC 2D200002 */  daddu      $4, $16, $0
    /* B59D0 001B59D0 0E010524 */  addiu      $5, $0, 0x10E
    /* B59D4 001B59D4 8433040C */  jal        func_0010ce10
    /* B59D8 001B59D8 00000000 */   nop
    /* B59DC 001B59DC 27104000 */  not        $2, $2
    /* B59E0 001B59E0 2B880200 */  sltu       $17, $0, $2
    /* B59E4 001B59E4 2D200002 */  daddu      $4, $16, $0
    /* B59E8 001B59E8 0F010524 */  addiu      $5, $0, 0x10F
    /* B59EC 001B59EC 8433040C */  jal        func_0010ce10
    /* B59F0 001B59F0 00000000 */   nop
    /* B59F4 001B59F4 27104000 */  not        $2, $2
    /* B59F8 001B59F8 2B800200 */  sltu       $16, $0, $2
    /* B59FC 001B59FC ACB3828F */  lw         $2, -0x4C54($28)
    /* B5A00 001B5A00 7801528C */  lw         $18, 0x178($2)
    /* B5A04 001B5A04 66000010 */  b          .L001B5BA0
    /* B5A08 001B5A08 00000000 */   nop
  .L001B5A0C:
    /* B5A0C 001B5A0C 640A448E */  lw         $4, 0xA64($18)
    /* B5A10 001B5A10 62008010 */  beqz       $4, .L001B5B9C
    /* B5A14 001B5A14 00000000 */   nop
    /* B5A18 001B5A18 2D280000 */  daddu      $5, $0, $0
    /* B5A1C 001B5A1C 3C0A090C */  jal        func_002428f0
    /* B5A20 001B5A20 00000000 */   nop
    /* B5A24 001B5A24 5D004014 */  bnez       $2, .L001B5B9C
    /* B5A28 001B5A28 00000000 */   nop
    /* B5A2C 001B5A2C 640A448E */  lw         $4, 0xA64($18)
    /* B5A30 001B5A30 24020524 */  addiu      $5, $0, 0x224
    /* B5A34 001B5A34 CCC9080C */  jal        func_00232730
    /* B5A38 001B5A38 00000000 */   nop
    /* B5A3C 001B5A3C 11004010 */  beqz       $2, .L001B5A84
    /* B5A40 001B5A40 00000000 */   nop
    /* B5A44 001B5A44 640A448E */  lw         $4, 0xA64($18)
    /* B5A48 001B5A48 E0C7080C */  jal        func_00231f80
    /* B5A4C 001B5A4C 00000000 */   nop
    /* B5A50 001B5A50 640A448E */  lw         $4, 0xA64($18)
    /* B5A54 001B5A54 2D284000 */  daddu      $5, $2, $0
    /* B5A58 001B5A58 C8C7080C */  jal        func_00231f20
    /* B5A5C 001B5A5C 00000000 */   nop
    /* B5A60 001B5A60 640A448E */  lw         $4, 0xA64($18)
    /* B5A64 001B5A64 A4C8080C */  jal        func_00232290
    /* B5A68 001B5A68 00000000 */   nop
    /* B5A6C 001B5A6C 640A448E */  lw         $4, 0xA64($18)
    /* B5A70 001B5A70 2D284000 */  daddu      $5, $2, $0
    /* B5A74 001B5A74 D4C7080C */  jal        func_00231f50
    /* B5A78 001B5A78 00000000 */   nop
    /* B5A7C 001B5A7C 25000010 */  b          .L001B5B14
    /* B5A80 001B5A80 00000000 */   nop
  .L001B5A84:
    /* B5A84 001B5A84 640A448E */  lw         $4, 0xA64($18)
    /* B5A88 001B5A88 23020524 */  addiu      $5, $0, 0x223
    /* B5A8C 001B5A8C CCC9080C */  jal        func_00232730
    /* B5A90 001B5A90 00000000 */   nop
    /* B5A94 001B5A94 1F004010 */  beqz       $2, .L001B5B14
    /* B5A98 001B5A98 00000000 */   nop
    /* B5A9C 001B5A9C 640A448E */  lw         $4, 0xA64($18)
    /* B5AA0 001B5AA0 E0C7080C */  jal        func_00231f80
    /* B5AA4 001B5AA4 00000000 */   nop
    /* B5AA8 001B5AA8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B5AAC 001B5AAC 80100300 */  sll        $2, $3, 2
    /* B5AB0 001B5AB0 21184300 */  addu       $3, $2, $3
    /* B5AB4 001B5AB4 80100300 */  sll        $2, $3, 2
    /* B5AB8 001B5AB8 21106200 */  addu       $2, $3, $2
    /* B5ABC 001B5ABC 80180200 */  sll        $3, $2, 2
    /* B5AC0 001B5AC0 E2040224 */  addiu      $2, $0, 0x4E2
    /* B5AC4 001B5AC4 1A006200 */  div        $0, $3, $2
    /* B5AC8 001B5AC8 12280000 */  mflo       $5
    /* B5ACC 001B5ACC 640A448E */  lw         $4, 0xA64($18)
    /* B5AD0 001B5AD0 68C9080C */  jal        func_002325a0
    /* B5AD4 001B5AD4 00000000 */   nop
    /* B5AD8 001B5AD8 640A448E */  lw         $4, 0xA64($18)
    /* B5ADC 001B5ADC A4C8080C */  jal        func_00232290
    /* B5AE0 001B5AE0 00000000 */   nop
    /* B5AE4 001B5AE4 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B5AE8 001B5AE8 80100300 */  sll        $2, $3, 2
    /* B5AEC 001B5AEC 21184300 */  addu       $3, $2, $3
    /* B5AF0 001B5AF0 80100300 */  sll        $2, $3, 2
    /* B5AF4 001B5AF4 21106200 */  addu       $2, $3, $2
    /* B5AF8 001B5AF8 80180200 */  sll        $3, $2, 2
    /* B5AFC 001B5AFC E2040224 */  addiu      $2, $0, 0x4E2
    /* B5B00 001B5B00 1A006200 */  div        $0, $3, $2
    /* B5B04 001B5B04 12280000 */  mflo       $5
    /* B5B08 001B5B08 640A448E */  lw         $4, 0xA64($18)
    /* B5B0C 001B5B0C 84C9080C */  jal        func_00232610
    /* B5B10 001B5B10 00000000 */   nop
  .L001B5B14:
    /* B5B14 001B5B14 10002012 */  beqz       $17, .L001B5B58
    /* B5B18 001B5B18 00000000 */   nop
    /* B5B1C 001B5B1C 640A448E */  lw         $4, 0xA64($18)
    /* B5B20 001B5B20 E0C7080C */  jal        func_00231f80
    /* B5B24 001B5B24 00000000 */   nop
    /* B5B28 001B5B28 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B5B2C 001B5B2C 80100300 */  sll        $2, $3, 2
    /* B5B30 001B5B30 21184300 */  addu       $3, $2, $3
    /* B5B34 001B5B34 80100300 */  sll        $2, $3, 2
    /* B5B38 001B5B38 21106200 */  addu       $2, $3, $2
    /* B5B3C 001B5B3C 80180200 */  sll        $3, $2, 2
    /* B5B40 001B5B40 D0070224 */  addiu      $2, $0, 0x7D0
    /* B5B44 001B5B44 1A006200 */  div        $0, $3, $2
    /* B5B48 001B5B48 12280000 */  mflo       $5
    /* B5B4C 001B5B4C 640A448E */  lw         $4, 0xA64($18)
    /* B5B50 001B5B50 68C9080C */  jal        func_002325a0
    /* B5B54 001B5B54 00000000 */   nop
  .L001B5B58:
    /* B5B58 001B5B58 10000012 */  beqz       $16, .L001B5B9C
    /* B5B5C 001B5B5C 00000000 */   nop
    /* B5B60 001B5B60 640A448E */  lw         $4, 0xA64($18)
    /* B5B64 001B5B64 A4C8080C */  jal        func_00232290
    /* B5B68 001B5B68 00000000 */   nop
    /* B5B6C 001B5B6C FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B5B70 001B5B70 80100300 */  sll        $2, $3, 2
    /* B5B74 001B5B74 21184300 */  addu       $3, $2, $3
    /* B5B78 001B5B78 80100300 */  sll        $2, $3, 2
    /* B5B7C 001B5B7C 21106200 */  addu       $2, $3, $2
    /* B5B80 001B5B80 80180200 */  sll        $3, $2, 2
    /* B5B84 001B5B84 D0070224 */  addiu      $2, $0, 0x7D0
    /* B5B88 001B5B88 1A006200 */  div        $0, $3, $2
    /* B5B8C 001B5B8C 12280000 */  mflo       $5
    /* B5B90 001B5B90 640A448E */  lw         $4, 0xA64($18)
    /* B5B94 001B5B94 84C9080C */  jal        func_00232610
    /* B5B98 001B5B98 00000000 */   nop
  .L001B5B9C:
    /* B5B9C 001B5B9C 6C0A528E */  lw         $18, 0xA6C($18)
  .L001B5BA0:
    /* B5BA0 001B5BA0 9AFF4016 */  bnez       $18, .L001B5A0C
    /* B5BA4 001B5BA4 00000000 */   nop
  .L001B5BA8:
    /* B5BA8 001B5BA8 58F7060C */  jal        func_001bdd60
    /* B5BAC 001B5BAC 00000000 */   nop
    /* B5BB0 001B5BB0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5BB4 001B5BB4 D40D448C */  lw         $4, 0xDD4($2)
    /* B5BB8 001B5BB8 300E080C */  jal        func_002038c0
    /* B5BBC 001B5BBC 00000000 */   nop
    /* B5BC0 001B5BC0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5BC4 001B5BC4 7801508C */  lw         $16, 0x178($2)
    /* B5BC8 001B5BC8 07000010 */  b          .L001B5BE8
    /* B5BCC 001B5BCC 00000000 */   nop
  .L001B5BD0:
    /* B5BD0 001B5BD0 640A048E */  lw         $4, 0xA64($16)
    /* B5BD4 001B5BD4 03008010 */  beqz       $4, .L001B5BE4
    /* B5BD8 001B5BD8 00000000 */   nop
    /* B5BDC 001B5BDC 74CE080C */  jal        func_002339d0
    /* B5BE0 001B5BE0 00000000 */   nop
  .L001B5BE4:
    /* B5BE4 001B5BE4 6C0A108E */  lw         $16, 0xA6C($16)
  .L001B5BE8:
    /* B5BE8 001B5BE8 F9FF0016 */  bnez       $16, .L001B5BD0
    /* B5BEC 001B5BEC 00000000 */   nop
    /* B5BF0 001B5BF0 3D000424 */  addiu      $4, $0, 0x3D
    /* B5BF4 001B5BF4 CC18040C */  jal        func_00106330
    /* B5BF8 001B5BF8 00000000 */   nop
    /* B5BFC 001B5BFC 0F004014 */  bnez       $2, .L001B5C3C
    /* B5C00 001B5C00 00000000 */   nop
    /* B5C04 001B5C04 01001064 */  daddiu     $16, $0, 0x1
    /* B5C08 001B5C08 08000010 */  b          .L001B5C2C
    /* B5C0C 001B5C0C 00000000 */   nop
  .L001B5C10:
    /* B5C10 001B5C10 3C241000 */  dsll32     $4, $16, 16
    /* B5C14 001B5C14 3F240400 */  dsra32     $4, $4, 16
    /* B5C18 001B5C18 4415040C */  jal        func_00105510
    /* B5C1C 001B5C1C 00000000 */   nop
    /* B5C20 001B5C20 100040A0 */  sb         $0, 0x10($2)
    /* B5C24 001B5C24 01000226 */  addiu      $2, $16, 0x1
    /* B5C28 001B5C28 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001B5C2C:
    /* B5C2C 001B5C2C FFFF0232 */  andi       $2, $16, 0xFFFF
    /* B5C30 001B5C30 0B004228 */  slti       $2, $2, 0xB
    /* B5C34 001B5C34 F6FF4014 */  bnez       $2, .L001B5C10
    /* B5C38 001B5C38 00000000 */   nop
  .L001B5C3C:
    /* B5C3C 001B5C3C ACB3828F */  lw         $2, -0x4C54($28)
    /* B5C40 001B5C40 7401508C */  lw         $16, 0x174($2)
    /* B5C44 001B5C44 09000010 */  b          .L001B5C6C
    /* B5C48 001B5C48 00000000 */   nop
  .L001B5C4C:
    /* B5C4C 001B5C4C 0C000296 */  lhu        $2, 0xC($16)
    /* B5C50 001B5C50 24000524 */  addiu      $5, $0, 0x24
    /* B5C54 001B5C54 04004510 */  beq        $2, $5, .L001B5C68
    /* B5C58 001B5C58 00000000 */   nop
    /* B5C5C 001B5C5C 2D200002 */  daddu      $4, $16, $0
    /* B5C60 001B5C60 00C2060C */  jal        func_001b0800
    /* B5C64 001B5C64 00000000 */   nop
  .L001B5C68:
    /* B5C68 001B5C68 5004108E */  lw         $16, 0x450($16)
  .L001B5C6C:
    /* B5C6C 001B5C6C F7FF0016 */  bnez       $16, .L001B5C4C
    /* B5C70 001B5C70 00000000 */   nop
    /* B5C74 001B5C74 4C4F060C */  jal        func_00193d30
    /* B5C78 001B5C78 00000000 */   nop
    /* B5C7C 001B5C7C ACB3858F */  lw         $5, -0x4C54($28)
    /* B5C80 001B5C80 1000A48C */  lw         $4, 0x10($5)
    /* B5C84 001B5C84 0020033C */  lui        $3, (0x20000000 >> 16)
    /* B5C88 001B5C88 24188300 */  and        $3, $4, $3
    /* B5C8C 001B5C8C 17006010 */  beqz       $3, .L001B5CEC
    /* B5C90 001B5C90 00000000 */   nop
    /* B5C94 001B5C94 7001A28C */  lw         $2, 0x170($5)
    /* B5C98 001B5C98 3000428C */  lw         $2, 0x30($2)
    /* B5C9C 001B5C9C 640A448C */  lw         $4, 0xA64($2)
    /* B5CA0 001B5CA0 2D280000 */  daddu      $5, $0, $0
    /* B5CA4 001B5CA4 3C0A090C */  jal        func_002428f0
    /* B5CA8 001B5CA8 00000000 */   nop
    /* B5CAC 001B5CAC 0F004010 */  beqz       $2, .L001B5CEC
    /* B5CB0 001B5CB0 00000000 */   nop
    /* B5CB4 001B5CB4 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5CB8 001B5CB8 7001428C */  lw         $2, 0x170($2)
    /* B5CBC 001B5CBC 3000428C */  lw         $2, 0x30($2)
    /* B5CC0 001B5CC0 640A448C */  lw         $4, 0xA64($2)
    /* B5CC4 001B5CC4 01000524 */  addiu      $5, $0, 0x1
    /* B5CC8 001B5CC8 C8C7080C */  jal        func_00231f20
    /* B5CCC 001B5CCC 00000000 */   nop
    /* B5CD0 001B5CD0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5CD4 001B5CD4 7001428C */  lw         $2, 0x170($2)
    /* B5CD8 001B5CD8 3000428C */  lw         $2, 0x30($2)
    /* B5CDC 001B5CDC 640A448C */  lw         $4, 0xA64($2)
    /* B5CE0 001B5CE0 0800053C */  lui        $5, (0x80000 >> 16)
    /* B5CE4 001B5CE4 BCC9080C */  jal        func_002326f0
    /* B5CE8 001B5CE8 00000000 */   nop
  .L001B5CEC:
    /* B5CEC 001B5CEC ACB3838F */  lw         $3, -0x4C54($28)
    /* B5CF0 001B5CF0 D40D648C */  lw         $4, 0xDD4($3)
    /* B5CF4 001B5CF4 05008010 */  beqz       $4, .L001B5D0C
    /* B5CF8 001B5CF8 00000000 */   nop
    /* B5CFC 001B5CFC 2048110C */  jal        func_00452080
    /* B5D00 001B5D00 00000000 */   nop
    /* B5D04 001B5D04 ACB3838F */  lw         $3, -0x4C54($28)
    /* B5D08 001B5D08 D40D60AC */  sw         $0, 0xDD4($3)
  .L001B5D0C:
    /* B5D0C 001B5D0C 3000BFDF */  ld         $31, 0x30($29)
    /* B5D10 001B5D10 2000B27B */  lq         $18, 0x20($29)
    /* B5D14 001B5D14 1000B17B */  lq         $17, 0x10($29)
    /* B5D18 001B5D18 0000B07B */  lq         $16, 0x0($29)
    /* B5D1C 001B5D1C 4000BD27 */  addiu      $29, $29, 0x40
    /* B5D20 001B5D20 0800E003 */  jr         $31
    /* B5D24 001B5D24 00000000 */   nop
    /* B5D28 001B5D28 00000000 */  nop
    /* B5D2C 001B5D2C 00000000 */  nop
.size func_001b5970, 0x3c0
