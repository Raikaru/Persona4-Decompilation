.section .text
.set noat
.set noreorder
glabel func_004abbb0
    /* 3ABBB0 004ABBB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ABBB4 004ABBB4 1000BFFF */  sd         $31, 0x10($29)
    /* 3ABBB8 004ABBB8 0000B07F */  sq         $16, 0x0($29)
    /* 3ABBBC 004ABBBC 2D808000 */  daddu      $16, $4, $0
    /* 3ABBC0 004ABBC0 A8E8110C */  jal        func_0047a2a0
    /* 3ABBC4 004ABBC4 00000000 */   nop
    /* 3ABBC8 004ABBC8 2D200002 */  daddu      $4, $16, $0
    /* 3ABBCC 004ABBCC 2D280000 */  daddu      $5, $0, $0
    /* 3ABBD0 004ABBD0 28E7110C */  jal        func_00479ca0
    /* 3ABBD4 004ABBD4 00000000 */   nop
    /* 3ABBD8 004ABBD8 0E004010 */  beqz       $2, .L004ABC14
    /* 3ABBDC 004ABBDC 00000000 */   nop
    /* 3ABBE0 004ABBE0 2D200002 */  daddu      $4, $16, $0
    /* 3ABBE4 004ABBE4 2D280000 */  daddu      $5, $0, $0
    /* 3ABBE8 004ABBE8 2D300000 */  daddu      $6, $0, $0
    /* 3ABBEC 004ABBEC 2D380000 */  daddu      $7, $0, $0
    /* 3ABBF0 004ABBF0 2D400000 */  daddu      $8, $0, $0
    /* 3ABBF4 004ABBF4 50E6110C */  jal        func_00479940
    /* 3ABBF8 004ABBF8 00000000 */   nop
    /* 3ABBFC 004ABBFC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ABC00 004ABC00 00608244 */  mtc1       $2, $f12
    /* 3ABC04 004ABC04 2D200002 */  daddu      $4, $16, $0
    /* 3ABC08 004ABC08 2D280000 */  daddu      $5, $0, $0
    /* 3ABC0C 004ABC0C 38E8110C */  jal        func_0047a0e0
    /* 3ABC10 004ABC10 00000000 */   nop
  .L004ABC14:
    /* 3ABC14 004ABC14 D800038E */  lw         $3, 0xD8($16)
    /* 3ABC18 004ABC18 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3ABC1C 004ABC1C 24106200 */  and        $2, $3, $2
    /* 3ABC20 004ABC20 D80002AE */  sw         $2, 0xD8($16)
    /* 3ABC24 004ABC24 2D200002 */  daddu      $4, $16, $0
    /* 3ABC28 004ABC28 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3ABC2C 004ABC2C 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3ABC30 004ABC30 2D300002 */  daddu      $6, $16, $0
    /* 3ABC34 004ABC34 ACE3110C */  jal        func_00478eb0
    /* 3ABC38 004ABC38 00000000 */   nop
    /* 3ABC3C 004ABC3C 1000BFDF */  ld         $31, 0x10($29)
    /* 3ABC40 004ABC40 0000B07B */  lq         $16, 0x0($29)
    /* 3ABC44 004ABC44 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ABC48 004ABC48 0800E003 */  jr         $31
    /* 3ABC4C 004ABC4C 00000000 */   nop
.size func_004abbb0, 0xa0
