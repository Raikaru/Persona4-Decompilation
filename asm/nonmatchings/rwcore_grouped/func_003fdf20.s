.section .text
.set noat
.set noreorder
glabel func_003fdf20
    /* 2FDF20 003FDF20 90FEBD27 */  addiu      $29, $29, -0x170
    /* 2FDF24 003FDF24 4000BFFF */  sd         $31, 0x40($29)
    /* 2FDF28 003FDF28 6C01A627 */  addiu      $6, $29, 0x16C
    /* 2FDF2C 003FDF2C 3000B37F */  sq         $19, 0x30($29)
    /* 2FDF30 003FDF30 6801A727 */  addiu      $7, $29, 0x168
    /* 2FDF34 003FDF34 2000B27F */  sq         $18, 0x20($29)
    /* 2FDF38 003FDF38 1000B17F */  sq         $17, 0x10($29)
    /* 2FDF3C 003FDF3C 2D90A000 */  daddu      $18, $5, $0
    /* 2FDF40 003FDF40 0000B07F */  sq         $16, 0x0($29)
    /* 2FDF44 003FDF44 2D888000 */  daddu      $17, $4, $0
    /* 2FDF48 003FDF48 0000A0AC */  sw         $0, 0x0($5)
    /* 2FDF4C 003FDF4C 147C0F0C */  jal        func_003df050
    /* 2FDF50 003FDF50 01000524 */   addiu     $5, $0, 0x1
    /* 2FDF54 003FDF54 30004010 */  beqz       $2, .L003FE018
    /* 2FDF58 003FDF58 00000000 */   nop
    /* 2FDF5C 003FDF5C 6801A38F */  lw         $3, 0x168($29)
    /* 2FDF60 003FDF60 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2FDF64 003FDF64 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2FDF68 003FDF68 2B106200 */  sltu       $2, $3, $2
    /* 2FDF6C 003FDF6C 07004014 */  bnez       $2, .L003FDF8C
    /* 2FDF70 003FDF70 2D800000 */   daddu     $16, $0, $0
    /* 2FDF74 003FDF74 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2FDF78 003FDF78 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2FDF7C 003FDF7C 2B086100 */  sltu       $1, $3, $1
    /* 2FDF80 003FDF80 02002010 */  beqz       $1, .L003FDF8C
    /* 2FDF84 003FDF84 00000000 */   nop
    /* 2FDF88 003FDF88 01001024 */  addiu      $16, $0, 0x1
  .L003FDF8C:
    /* 2FDF8C 003FDF8C 86000012 */  beqz       $16, .L003FE1A8
    /* 2FDF90 003FDF90 00000000 */   nop
    /* 2FDF94 003FDF94 6001A427 */  addiu      $4, $29, 0x160
    /* 2FDF98 003FDF98 2D280000 */  daddu      $5, $0, $0
    /* 2FDF9C 003FDF9C 72FE100C */  jal        func_0043f9c8
    /* 2FDFA0 003FDFA0 08000624 */   addiu     $6, $0, 0x8
    /* 2FDFA4 003FDFA4 6C01B38F */  lw         $19, 0x16C($29)
    /* 2FDFA8 003FDFA8 2D202002 */  daddu      $4, $17, $0
    /* 2FDFAC 003FDFAC 6001A527 */  addiu      $5, $29, 0x160
    /* 2FDFB0 003FDFB0 448A0F0C */  jal        func_003e2910
    /* 2FDFB4 003FDFB4 2D306002 */   daddu     $6, $19, $0
    /* 2FDFB8 003FDFB8 19006216 */  bne        $19, $2, .L003FE020
    /* 2FDFBC 003FDFBC 00000000 */   nop
    /* 2FDFC0 003FDFC0 6001A393 */  lbu        $3, 0x160($29)
    /* 2FDFC4 003FDFC4 50000224 */  addiu      $2, $0, 0x50
    /* 2FDFC8 003FDFC8 17006214 */  bne        $3, $2, .L003FE028
    /* 2FDFCC 003FDFCC 00000000 */   nop
    /* 2FDFD0 003FDFD0 6101A393 */  lbu        $3, 0x161($29)
    /* 2FDFD4 003FDFD4 53000224 */  addiu      $2, $0, 0x53
    /* 2FDFD8 003FDFD8 13006214 */  bne        $3, $2, .L003FE028
    /* 2FDFDC 003FDFDC 00000000 */   nop
    /* 2FDFE0 003FDFE0 6201A393 */  lbu        $3, 0x162($29)
    /* 2FDFE4 003FDFE4 32000224 */  addiu      $2, $0, 0x32
    /* 2FDFE8 003FDFE8 0F006214 */  bne        $3, $2, .L003FE028
    /* 2FDFEC 003FDFEC 00000000 */   nop
    /* 2FDFF0 003FDFF0 6301A293 */  lbu        $2, 0x163($29)
    /* 2FDFF4 003FDFF4 0C004014 */  bnez       $2, .L003FE028
    /* 2FDFF8 003FDFF8 00000000 */   nop
    /* 2FDFFC 003FDFFC D000A427 */  addiu      $4, $29, 0xD0
    /* 2FE000 003FE000 D8930F0C */  jal        func_003e4f60
    /* 2FE004 003FE004 2D282002 */   daddu     $5, $17, $0
    /* 2FE008 003FE008 09004014 */  bnez       $2, .L003FE030
    /* 2FE00C 003FE00C 00000000 */   nop
    /* 2FE010 003FE010 6F000010 */  b          .L003FE1D0
    /* 2FE014 003FE014 2D100000 */   daddu     $2, $0, $0
  .L003FE018:
    /* 2FE018 003FE018 6D000010 */  b          .L003FE1D0
    /* 2FE01C 003FE01C 2D100000 */   daddu     $2, $0, $0
  .L003FE020:
    /* 2FE020 003FE020 6B000010 */  b          .L003FE1D0
    /* 2FE024 003FE024 2D100000 */   daddu     $2, $0, $0
  .L003FE028:
    /* 2FE028 003FE028 69000010 */  b          .L003FE1D0
    /* 2FE02C 003FE02C 2D100000 */   daddu     $2, $0, $0
  .L003FE030:
    /* 2FE030 003FE030 5000A427 */  addiu      $4, $29, 0x50
    /* 2FE034 003FE034 D8930F0C */  jal        func_003e4f60
    /* 2FE038 003FE038 2D282002 */   daddu     $5, $17, $0
    /* 2FE03C 003FE03C 03004014 */  bnez       $2, .L003FE04C
    /* 2FE040 003FE040 00000000 */   nop
    /* 2FE044 003FE044 62000010 */  b          .L003FE1D0
    /* 2FE048 003FE048 2D100000 */   daddu     $2, $0, $0
  .L003FE04C:
    /* 2FE04C 003FE04C 2D202002 */  daddu      $4, $17, $0
    /* 2FE050 003FE050 01000524 */  addiu      $5, $0, 0x1
    /* 2FE054 003FE054 6C01A627 */  addiu      $6, $29, 0x16C
    /* 2FE058 003FE058 147C0F0C */  jal        func_003df050
    /* 2FE05C 003FE05C 6801A727 */   addiu     $7, $29, 0x168
    /* 2FE060 003FE060 3F004010 */  beqz       $2, .L003FE160
    /* 2FE064 003FE064 00000000 */   nop
    /* 2FE068 003FE068 6801A38F */  lw         $3, 0x168($29)
    /* 2FE06C 003FE06C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2FE070 003FE070 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2FE074 003FE074 2B106200 */  sltu       $2, $3, $2
    /* 2FE078 003FE078 3D004014 */  bnez       $2, .L003FE170
    /* 2FE07C 003FE07C 00000000 */   nop
    /* 2FE080 003FE080 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2FE084 003FE084 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2FE088 003FE088 2B086100 */  sltu       $1, $3, $1
    /* 2FE08C 003FE08C 38002010 */  beqz       $1, .L003FE170
    /* 2FE090 003FE090 00000000 */   nop
    /* 2FE094 003FE094 6C01A58F */  lw         $5, 0x16C($29)
    /* 2FE098 003FE098 50F60F0C */  jal        func_003fd940
    /* 2FE09C 003FE09C 2D202002 */   daddu     $4, $17, $0
    /* 2FE0A0 003FE0A0 2D884000 */  daddu      $17, $2, $0
    /* 2FE0A4 003FE0A4 30002012 */  beqz       $17, .L003FE168
    /* 2FE0A8 003FE0A8 00000000 */   nop
    /* 2FE0AC 003FE0AC B8BC0F0C */  jal        func_003ef2e0
    /* 2FE0B0 003FE0B0 2D202002 */   daddu     $4, $17, $0
    /* 2FE0B4 003FE0B4 000042AE */  sw         $2, 0x0($18)
    /* 2FE0B8 003FE0B8 0000448E */  lw         $4, 0x0($18)
    /* 2FE0BC 003FE0BC 36008010 */  beqz       $4, .L003FE198
    /* 2FE0C0 003FE0C0 00000000 */   nop
    /* 2FE0C4 003FE0C4 1CBD0F0C */  jal        func_003ef470
    /* 2FE0C8 003FE0C8 D000A527 */   addiu     $5, $29, 0xD0
    /* 2FE0CC 003FE0CC 0000448E */  lw         $4, 0x0($18)
    /* 2FE0D0 003FE0D0 44BD0F0C */  jal        func_003ef510
    /* 2FE0D4 003FE0D4 5000A527 */   addiu     $5, $29, 0x50
    /* 2FE0D8 003FE0D8 0000448E */  lw         $4, 0x0($18)
    /* 2FE0DC 003FE0DC 6401A627 */  addiu      $6, $29, 0x164
    /* 2FE0E0 003FE0E0 0000C590 */  lbu        $5, 0x0($6)
    /* 2FE0E4 003FE0E4 00FF0224 */  addiu      $2, $0, -0x100
    /* 2FE0E8 003FE0E8 5000838C */  lw         $3, 0x50($4)
    /* 2FE0EC 003FE0EC 24106200 */  and        $2, $3, $2
    /* 2FE0F0 003FE0F0 25104500 */  or         $2, $2, $5
    /* 2FE0F4 003FE0F4 500082AC */  sw         $2, 0x50($4)
    /* 2FE0F8 003FE0F8 0000C28C */  lw         $2, 0x0($6)
    /* 2FE0FC 003FE0FC 031A0200 */  sra        $3, $2, 8
    /* 2FE100 003FE100 03130200 */  sra        $2, $2, 12
    /* 2FE104 003FE104 0F004230 */  andi       $2, $2, 0xF
    /* 2FE108 003FE108 02004014 */  bnez       $2, .L003FE114
    /* 2FE10C 003FE10C 0F006330 */   andi      $3, $3, 0xF
    /* 2FE110 003FE110 2D106000 */  daddu      $2, $3, $0
  .L003FE114:
    /* 2FE114 003FE114 0000478E */  lw         $7, 0x0($18)
    /* 2FE118 003FE118 001A0300 */  sll        $3, $3, 8
    /* 2FE11C 003FE11C 000F6430 */  andi       $4, $3, 0xF00
    /* 2FE120 003FE120 00130200 */  sll        $2, $2, 12
    /* 2FE124 003FE124 FFFF033C */  lui        $3, (0xFFFF0FFF >> 16)
    /* 2FE128 003FE128 FFF00524 */  addiu      $5, $0, -0xF01
    /* 2FE12C 003FE12C FF0F6334 */  ori        $3, $3, (0xFFFF0FFF & 0xFFFF)
    /* 2FE130 003FE130 00F04230 */  andi       $2, $2, 0xF000
    /* 2FE134 003FE134 5000E68C */  lw         $6, 0x50($7)
    /* 2FE138 003FE138 2428C500 */  and        $5, $6, $5
    /* 2FE13C 003FE13C 2520A400 */  or         $4, $5, $4
    /* 2FE140 003FE140 5000E4AC */  sw         $4, 0x50($7)
    /* 2FE144 003FE144 0000458E */  lw         $5, 0x0($18)
    /* 2FE148 003FE148 5000A48C */  lw         $4, 0x50($5)
    /* 2FE14C 003FE14C 24188300 */  and        $3, $4, $3
    /* 2FE150 003FE150 25106200 */  or         $2, $3, $2
    /* 2FE154 003FE154 5000A2AC */  sw         $2, 0x50($5)
  .L003FE158:
    /* 2FE158 003FE158 1D000010 */  b          .L003FE1D0
    /* 2FE15C 003FE15C 2D100002 */   daddu     $2, $16, $0
  .L003FE160:
    /* 2FE160 003FE160 1B000010 */  b          .L003FE1D0
    /* 2FE164 003FE164 2D100000 */   daddu     $2, $0, $0
  .L003FE168:
    /* 2FE168 003FE168 19000010 */  b          .L003FE1D0
    /* 2FE16C 003FE16C 2D100000 */   daddu     $2, $0, $0
  .L003FE170:
    /* 2FE170 003FE170 01000324 */  addiu      $3, $0, 0x1
    /* 2FE174 003FE174 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2FE178 003FE178 5801A3AF */  sw         $3, 0x158($29)
    /* 2FE17C 003FE17C 647D0F0C */  jal        func_003df590
    /* 2FE180 003FE180 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2FE184 003FE184 5C01A2AF */  sw         $2, 0x15C($29)
    /* 2FE188 003FE188 347D0F0C */  jal        func_003df4d0
    /* 2FE18C 003FE18C 5801A427 */   addiu     $4, $29, 0x158
    /* 2FE190 003FE190 0F000010 */  b          .L003FE1D0
    /* 2FE194 003FE194 2D100000 */   daddu     $2, $0, $0
  .L003FE198:
    /* 2FE198 003FE198 CCB00F0C */  jal        func_003ec330
    /* 2FE19C 003FE19C 2D202002 */   daddu     $4, $17, $0
    /* 2FE1A0 003FE1A0 0B000010 */  b          .L003FE1D0
    /* 2FE1A4 003FE1A4 2D100000 */   daddu     $2, $0, $0
  .L003FE1A8:
    /* 2FE1A8 003FE1A8 01000324 */  addiu      $3, $0, 0x1
    /* 2FE1AC 003FE1AC 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2FE1B0 003FE1B0 5001A3AF */  sw         $3, 0x150($29)
    /* 2FE1B4 003FE1B4 647D0F0C */  jal        func_003df590
    /* 2FE1B8 003FE1B8 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2FE1BC 003FE1BC 5401A2AF */  sw         $2, 0x154($29)
    /* 2FE1C0 003FE1C0 347D0F0C */  jal        func_003df4d0
    /* 2FE1C4 003FE1C4 5001A427 */   addiu     $4, $29, 0x150
    /* 2FE1C8 003FE1C8 E3FF0010 */  b          .L003FE158
    /* 2FE1CC 003FE1CC 00000000 */   nop
  .L003FE1D0:
    /* 2FE1D0 003FE1D0 4000BFDF */  ld         $31, 0x40($29)
    /* 2FE1D4 003FE1D4 3000B37B */  lq         $19, 0x30($29)
    /* 2FE1D8 003FE1D8 2000B27B */  lq         $18, 0x20($29)
    /* 2FE1DC 003FE1DC 1000B17B */  lq         $17, 0x10($29)
    /* 2FE1E0 003FE1E0 0000B07B */  lq         $16, 0x0($29)
    /* 2FE1E4 003FE1E4 0800E003 */  jr         $31
    /* 2FE1E8 003FE1E8 7001BD27 */   addiu     $29, $29, 0x170
    /* 2FE1EC 003FE1EC 00000000 */  nop
.size func_003fdf20, 0x2d0
