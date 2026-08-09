.section .text
.set noat
.set noreorder
glabel func_0040eee0
    /* 30EEE0 0040EEE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 30EEE4 0040EEE4 7100023C */  lui        $2, %hi(D_0070C374)
    /* 30EEE8 0040EEE8 0000BFFF */  sd         $31, 0x0($29)
    /* 30EEEC 0040EEEC 7100033C */  lui        $3, %hi(D_0070C358)
    /* 30EEF0 0040EEF0 74C344AC */  sw         $4, %lo(D_0070C374)($2)
    /* 30EEF4 0040EEF4 7100023C */  lui        $2, %hi(D_0070C340)
    /* 30EEF8 0040EEF8 58C364AC */  sw         $4, %lo(D_0070C358)($3)
    /* 30EEFC 0040EEFC 40C3428C */  lw         $2, %lo(D_0070C340)($2)
    /* 30EF00 0040EF00 7100033C */  lui        $3, %hi(D_0070C35C)
    /* 30EF04 0040EF04 A8B980AF */  sw         $0, -0x4658($28)
    /* 30EF08 0040EF08 1C004014 */  bnez       $2, .L0040EF7C
    /* 30EF0C 0040EF0C 5CC365AC */   sw        $5, %lo(D_0070C35C)($3)
    /* 30EF10 0040EF10 4100033C */  lui        $3, %hi(func_0040df40)
    /* 30EF14 0040EF14 7100023C */  lui        $2, %hi(D_0070C360)
    /* 30EF18 0040EF18 40DF6324 */  addiu      $3, $3, %lo(func_0040df40)
    /* 30EF1C 0040EF1C 60C343AC */  sw         $3, %lo(D_0070C360)($2)
  .L0040EF20:
    /* 30EF20 0040EF20 0010023C */  lui        $2, (0x10000000 >> 16)
    /* 30EF24 0040EF24 0E000424 */  addiu      $4, $0, 0xE
    /* 30EF28 0040EF28 3C180200 */  dsll32     $3, $2, 0
    /* 30EF2C 0040EF2C 05800234 */  ori        $2, $0, 0x8005
    /* 30EF30 0040EF30 25184300 */  or         $3, $2, $3
    /* 30EF34 0040EF34 891B8370 */  pcpyld     $3, $4, $3
    /* 30EF38 0040EF38 8900023C */  lui        $2, %hi(D_0088CCF0)
    /* 30EF3C 0040EF3C 2D200000 */  daddu      $4, $0, $0
    /* 30EF40 0040EF40 F0CC437C */  sq         $3, %lo(D_0088CCF0)($2)
    /* 30EF44 0040EF44 3F000324 */  addiu      $3, $0, 0x3F
    /* 30EF48 0040EF48 8900023C */  lui        $2, %hi(D_0088CCC0)
    /* 30EF4C 0040EF4C 891B6470 */  pcpyld     $3, $3, $4
    /* 30EF50 0040EF50 C0CC437C */  sq         $3, %lo(D_0088CCC0)($2)
    /* 30EF54 0040EF54 51000324 */  addiu      $3, $0, 0x51
    /* 30EF58 0040EF58 8900023C */  lui        $2, %hi(D_0088CCD0)
    /* 30EF5C 0040EF5C 891B6470 */  pcpyld     $3, $3, $4
    /* 30EF60 0040EF60 D0CC437C */  sq         $3, %lo(D_0088CCD0)($2)
    /* 30EF64 0040EF64 53000324 */  addiu      $3, $0, 0x53
    /* 30EF68 0040EF68 8900023C */  lui        $2, %hi(D_0088CCE0)
    /* 30EF6C 0040EF6C 891B6470 */  pcpyld     $3, $3, $4
    /* 30EF70 0040EF70 E0CC437C */  sq         $3, %lo(D_0088CCE0)($2)
    /* 30EF74 0040EF74 24000010 */  b          .L0040F008
    /* 30EF78 0040EF78 01000224 */   addiu     $2, $0, 0x1
  .L0040EF7C:
    /* 30EF7C 0040EF7C 14AC848F */  lw         $4, -0x53EC($28)
    /* 30EF80 0040EF80 0400023C */  lui        $2, (0x40411 >> 16)
    /* 30EF84 0040EF84 11044534 */  ori        $5, $2, (0x40411 & 0xFFFF)
    /* 30EF88 0040EF88 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 30EF8C 0040EF8C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 30EF90 0040EF90 40180400 */  sll        $3, $4, 1
    /* 30EF94 0040EF94 21186400 */  addu       $3, $3, $4
    /* 30EF98 0040EF98 09F84000 */  jalr       $2
    /* 30EF9C 0040EF9C 80200300 */   sll       $4, $3, 2
    /* 30EFA0 0040EFA0 7100033C */  lui        $3, %hi(D_0070C354)
    /* 30EFA4 0040EFA4 03004014 */  bnez       $2, .L0040EFB4
    /* 30EFA8 0040EFA8 54C362AC */   sw        $2, %lo(D_0070C354)($3)
    /* 30EFAC 0040EFAC 16000010 */  b          .L0040F008
    /* 30EFB0 0040EFB0 2D100000 */   daddu     $2, $0, $0
  .L0040EFB4:
    /* 30EFB4 0040EFB4 FFFF0724 */  addiu      $7, $0, -0x1
    /* 30EFB8 0040EFB8 7100023C */  lui        $2, %hi(D_0070C344)
    /* 30EFBC 0040EFBC 44C347AC */  sw         $7, %lo(D_0070C344)($2)
    /* 30EFC0 0040EFC0 4100053C */  lui        $5, %hi(func_0040e830)
    /* 30EFC4 0040EFC4 7100023C */  lui        $2, %hi(D_0070C348)
    /* 30EFC8 0040EFC8 30E8A524 */  addiu      $5, $5, %lo(func_0040e830)
    /* 30EFCC 0040EFCC 48C347AC */  sw         $7, %lo(D_0070C348)($2)
    /* 30EFD0 0040EFD0 7100043C */  lui        $4, %hi(D_0070C34C)
    /* 30EFD4 0040EFD4 7100023C */  lui        $2, %hi(D_0070C360)
    /* 30EFD8 0040EFD8 14AC868F */  lw         $6, -0x53EC($28)
    /* 30EFDC 0040EFDC 60C345AC */  sw         $5, %lo(D_0070C360)($2)
    /* 30EFE0 0040EFE0 7100033C */  lui        $3, %hi(D_0070C350)
    /* 30EFE4 0040EFE4 7100023C */  lui        $2, %hi(D_0070C364)
    /* 30EFE8 0040EFE8 64C340AC */  sw         $0, %lo(D_0070C364)($2)
    /* 30EFEC 0040EFEC 7100023C */  lui        $2, %hi(D_0070C36C)
    /* 30EFF0 0040EFF0 6CC347AC */  sw         $7, %lo(D_0070C36C)($2)
    /* 30EFF4 0040EFF4 7100023C */  lui        $2, %hi(D_0070C370)
    /* 30EFF8 0040EFF8 4CC386AC */  sw         $6, %lo(D_0070C34C)($4)
    /* 30EFFC 0040EFFC 70C347AC */  sw         $7, %lo(D_0070C370)($2)
    /* 30F000 0040F000 C7FF0010 */  b          .L0040EF20
    /* 30F004 0040F004 50C366AC */   sw        $6, %lo(D_0070C350)($3)
  .L0040F008:
    /* 30F008 0040F008 0000BFDF */  ld         $31, 0x0($29)
    /* 30F00C 0040F00C 0800E003 */  jr         $31
    /* 30F010 0040F010 1000BD27 */   addiu     $29, $29, 0x10
    /* 30F014 0040F014 00000000 */  nop
    /* 30F018 0040F018 00000000 */  nop
    /* 30F01C 0040F01C 00000000 */  nop
.size func_0040eee0, 0x140
