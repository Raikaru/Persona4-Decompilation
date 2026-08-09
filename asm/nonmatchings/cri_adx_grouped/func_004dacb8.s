.section .text
.set noat
.set noreorder
glabel func_004dacb8
    /* 3DACB8 004DACB8 80FFBD27 */  addiu      $29, $29, -0x80
    /* 3DACBC 004DACBC 7300033C */  lui        $3, %hi(D_00728948)
    /* 3DACC0 004DACC0 6000B6FF */  sd         $22, 0x60($29)
    /* 3DACC4 004DACC4 2DB00000 */  daddu      $22, $0, $0
    /* 3DACC8 004DACC8 6800B7FF */  sd         $23, 0x68($29)
    /* 3DACCC 004DACCC 2DB82001 */  daddu      $23, $9, $0
    /* 3DACD0 004DACD0 3000B0FF */  sd         $16, 0x30($29)
    /* 3DACD4 004DACD4 3800B1FF */  sd         $17, 0x38($29)
    /* 3DACD8 004DACD8 4000B2FF */  sd         $18, 0x40($29)
    /* 3DACDC 004DACDC 4800B3FF */  sd         $19, 0x48($29)
    /* 3DACE0 004DACE0 5000B4FF */  sd         $20, 0x50($29)
    /* 3DACE4 004DACE4 5800B5FF */  sd         $21, 0x58($29)
    /* 3DACE8 004DACE8 7000BEFF */  sd         $30, 0x70($29)
    /* 3DACEC 004DACEC 7800BFFF */  sd         $31, 0x78($29)
    /* 3DACF0 004DACF0 1000A28C */  lw         $2, 0x10($5)
    /* 3DACF4 004DACF4 1400A2AF */  sw         $2, 0x14($29)
    /* 3DACF8 004DACF8 7300023C */  lui        $2, %hi(D_007282A4)
    /* 3DACFC 004DACFC 1800AA8C */  lw         $10, 0x18($5)
    /* 3DAD00 004DAD00 0800A7AF */  sw         $7, 0x8($29)
    /* 3DAD04 004DAD04 1C00AAAF */  sw         $10, 0x1C($29)
    /* 3DAD08 004DAD08 0000A4AF */  sw         $4, 0x0($29)
    /* 3DAD0C 004DAD0C 0400A6AF */  sw         $6, 0x4($29)
    /* 3DAD10 004DAD10 0C00A8AF */  sw         $8, 0xC($29)
    /* 3DAD14 004DAD14 1400A78F */  lw         $7, 0x14($29)
    /* 3DAD18 004DAD18 0400A48C */  lw         $4, 0x4($5)
    /* 3DAD1C 004DAD1C 1000A4AF */  sw         $4, 0x10($29)
    /* 3DAD20 004DAD20 1400A58C */  lw         $5, 0x14($5)
    /* 3DAD24 004DAD24 488960AC */  sw         $0, %lo(D_00728948)($3)
    /* 3DAD28 004DAD28 1800A5AF */  sw         $5, 0x18($29)
    /* 3DAD2C 004DAD2C 1A01E018 */  blez       $7, .L004DB198
    /* 3DAD30 004DAD30 A48240AC */   sw        $0, %lo(D_007282A4)($2)
    /* 3DAD34 004DAD34 2400A0AF */  sw         $0, 0x24($29)
    /* 3DAD38 004DAD38 2800A0AF */  sw         $0, 0x28($29)
    /* 3DAD3C 004DAD3C 00000000 */  nop
  .L004DAD40:
    /* 3DAD40 004DAD40 2DF00000 */  daddu      $30, $0, $0
    /* 3DAD44 004DAD44 1800A88F */  lw         $8, 0x18($29)
    /* 3DAD48 004DAD48 2A40C802 */  slt        $8, $22, $8
    /* 3DAD4C 004DAD4C FE000010 */  b          .L004DB148
    /* 3DAD50 004DAD50 2000A8AF */   sw        $8, 0x20($29)
    /* 3DAD54 004DAD54 00000000 */  nop
  .L004DAD58:
    /* 3DAD58 004DAD58 0400AA8F */  lw         $10, 0x4($29)
    /* 3DAD5C 004DAD5C 21105600 */  addu       $2, $2, $22
    /* 3DAD60 004DAD60 80100200 */  sll        $2, $2, 2
    /* 3DAD64 004DAD64 21104A00 */  addu       $2, $2, $10
    /* 3DAD68 004DAD68 0000458C */  lw         $5, 0x0($2)
    /* 3DAD6C 004DAD6C D800A010 */  beqz       $5, .L004DB0D0
    /* 3DAD70 004DAD70 40181E00 */   sll       $3, $30, 1
    /* 3DAD74 004DAD74 0C00A48F */  lw         $4, 0xC($29)
    /* 3DAD78 004DAD78 21907E00 */  addu       $18, $3, $30
    /* 3DAD7C 004DAD7C 40100500 */  sll        $2, $5, 1
    /* 3DAD80 004DAD80 21184402 */  addu       $3, $18, $4
    /* 3DAD84 004DAD84 21104500 */  addu       $2, $2, $5
    /* 3DAD88 004DAD88 40190300 */  sll        $3, $3, 5
    /* 3DAD8C 004DAD8C 2800A78F */  lw         $7, 0x28($29)
    /* 3DAD90 004DAD90 21187600 */  addu       $3, $3, $22
    /* 3DAD94 004DAD94 0800AA8F */  lw         $10, 0x8($29)
    /* 3DAD98 004DAD98 C0100200 */  sll        $2, $2, 3
    /* 3DAD9C 004DAD9C 1C00A88F */  lw         $8, 0x1C($29)
    /* 3DADA0 004DADA0 80180300 */  sll        $3, $3, 2
    /* 3DADA4 004DADA4 2110E200 */  addu       $2, $7, $2
    /* 3DADA8 004DADA8 21186A00 */  addu       $3, $3, $10
    /* 3DADAC 004DADAC 21304800 */  addu       $6, $2, $8
    /* 3DADB0 004DADB0 0000628C */  lw         $2, 0x0($3)
    /* 3DADB4 004DADB4 7300033C */  lui        $3, %hi(D_007285F0)
    /* 3DADB8 004DADB8 F0856324 */  addiu      $3, $3, %lo(D_007285F0)
    /* 3DADBC 004DADBC 0800C48C */  lw         $4, 0x8($6)
    /* 3DADC0 004DADC0 80100200 */  sll        $2, $2, 2
    /* 3DADC4 004DADC4 03001124 */  addiu      $17, $0, 0x3
    /* 3DADC8 004DADC8 21104300 */  addu       $2, $2, $3
    /* 3DADCC 004DADCC 1400D48C */  lw         $20, 0x14($6)
    /* 3DADD0 004DADD0 1000D38C */  lw         $19, 0x10($6)
    /* 3DADD4 004DADD4 48009114 */  bne        $4, $17, .L004DAEF8
    /* 3DADD8 004DADD8 0000558C */   lw        $21, 0x0($2)
    /* 3DADDC 004DADDC 0400D18C */  lw         $17, 0x4($6)
    /* 3DADE0 004DADE0 0900222A */  slti       $2, $17, 0x9
    /* 3DADE4 004DADE4 24004010 */  beqz       $2, .L004DAE78
    /* 3DADE8 004DADE8 0000A48F */   lw        $4, 0x0($29)
    /* 3DADEC 004DADEC 40281100 */  sll        $5, $17, 1
    /* 3DADF0 004DADF0 F265130C */  jal        func_004d97c8
    /* 3DADF4 004DADF4 2128B100 */   addu      $5, $5, $17
    /* 3DADF8 004DADF8 80181100 */  sll        $3, $17, 2
    /* 3DADFC 004DADFC 7300043C */  lui        $4, %hi(D_007288C0)
    /* 3DAE00 004DAE00 C0888424 */  addiu      $4, $4, %lo(D_007288C0)
    /* 3DAE04 004DAE04 21186400 */  addu       $3, $3, $4
    /* 3DAE08 004DAE08 40211200 */  sll        $4, $18, 5
    /* 3DAE0C 004DAE0C 0000658C */  lw         $5, 0x0($3)
    /* 3DAE10 004DAE10 21209600 */  addu       $4, $4, $22
    /* 3DAE14 004DAE14 40200400 */  sll        $4, $4, 1
    /* 3DAE18 004DAE18 24184500 */  and        $3, $2, $5
    /* 3DAE1C 004DAE1C 07102202 */  srav       $2, $2, $17
    /* 3DAE20 004DAE20 18387300 */  mult       $7, $3, $19
    /* 3DAE24 004DAE24 24284500 */  and        $5, $2, $5
    /* 3DAE28 004DAE28 1818B300 */  mult       $3, $5, $19
    /* 3DAE2C 004DAE2C 21209700 */  addu       $4, $4, $23
    /* 3DAE30 004DAE30 07102202 */  srav       $2, $2, $17
    /* 3DAE34 004DAE34 2130F400 */  addu       $6, $7, $20
    /* 3DAE38 004DAE38 83300600 */  sra        $6, $6, 2
    /* 3DAE3C 004DAE3C 1830D500 */  mult       $6, $6, $21
    /* 3DAE40 004DAE40 03340600 */  sra        $6, $6, 16
    /* 3DAE44 004DAE44 800086A4 */  sh         $6, 0x80($4)
    /* 3DAE48 004DAE48 21307400 */  addu       $6, $3, $20
    /* 3DAE4C 004DAE4C 83300600 */  sra        $6, $6, 2
    /* 3DAE50 004DAE50 18185300 */  mult       $3, $2, $19
    /* 3DAE54 004DAE54 1830D500 */  mult       $6, $6, $21
    /* 3DAE58 004DAE58 03340600 */  sra        $6, $6, 16
    /* 3DAE5C 004DAE5C 400086A4 */  sh         $6, 0x40($4)
    /* 3DAE60 004DAE60 21307400 */  addu       $6, $3, $20
    /* 3DAE64 004DAE64 83300600 */  sra        $6, $6, 2
    /* 3DAE68 004DAE68 1830D500 */  mult       $6, $6, $21
    /* 3DAE6C 004DAE6C 03340600 */  sra        $6, $6, 16
    /* 3DAE70 004DAE70 A0000010 */  b          .L004DB0F4
    /* 3DAE74 004DAE74 000086A4 */   sh        $6, 0x0($4)
  .L004DAE78:
    /* 3DAE78 004DAE78 2D282002 */  daddu      $5, $17, $0
    /* 3DAE7C 004DAE7C F265130C */  jal        func_004d97c8
    /* 3DAE80 004DAE80 40811200 */   sll       $16, $18, 5
    /* 3DAE84 004DAE84 2D282002 */  daddu      $5, $17, $0
    /* 3DAE88 004DAE88 18185300 */  mult       $3, $2, $19
    /* 3DAE8C 004DAE8C 21801602 */  addu       $16, $16, $22
    /* 3DAE90 004DAE90 40801000 */  sll        $16, $16, 1
    /* 3DAE94 004DAE94 0000A48F */  lw         $4, 0x0($29)
    /* 3DAE98 004DAE98 21801702 */  addu       $16, $16, $23
    /* 3DAE9C 004DAE9C 21307400 */  addu       $6, $3, $20
    /* 3DAEA0 004DAEA0 83300600 */  sra        $6, $6, 2
    /* 3DAEA4 004DAEA4 1830D500 */  mult       $6, $6, $21
    /* 3DAEA8 004DAEA8 03340600 */  sra        $6, $6, 16
    /* 3DAEAC 004DAEAC F265130C */  jal        func_004d97c8
    /* 3DAEB0 004DAEB0 000006A6 */   sh        $6, 0x0($16)
    /* 3DAEB4 004DAEB4 2D282002 */  daddu      $5, $17, $0
    /* 3DAEB8 004DAEB8 18185300 */  mult       $3, $2, $19
    /* 3DAEBC 004DAEBC 0000A48F */  lw         $4, 0x0($29)
    /* 3DAEC0 004DAEC0 21307400 */  addu       $6, $3, $20
    /* 3DAEC4 004DAEC4 83300600 */  sra        $6, $6, 2
    /* 3DAEC8 004DAEC8 1830D500 */  mult       $6, $6, $21
    /* 3DAECC 004DAECC 03340600 */  sra        $6, $6, 16
    /* 3DAED0 004DAED0 F265130C */  jal        func_004d97c8
    /* 3DAED4 004DAED4 400006A6 */   sh        $6, 0x40($16)
    /* 3DAED8 004DAED8 18185300 */  mult       $3, $2, $19
    /* 3DAEDC 004DAEDC 21307400 */  addu       $6, $3, $20
    /* 3DAEE0 004DAEE0 83300600 */  sra        $6, $6, 2
    /* 3DAEE4 004DAEE4 1830D500 */  mult       $6, $6, $21
    /* 3DAEE8 004DAEE8 03340600 */  sra        $6, $6, 16
    /* 3DAEEC 004DAEEC 81000010 */  b          .L004DB0F4
    /* 3DAEF0 004DAEF0 800006A6 */   sh        $6, 0x80($16)
    /* 3DAEF4 004DAEF4 00000000 */  nop
  .L004DAEF8:
    /* 3DAEF8 004DAEF8 0400C58C */  lw         $5, 0x4($6)
    /* 3DAEFC 004DAEFC 0000A48F */  lw         $4, 0x0($29)
    /* 3DAF00 004DAF00 F265130C */  jal        func_004d97c8
    /* 3DAF04 004DAF04 0000D08C */   lw        $16, 0x0($6)
    /* 3DAF08 004DAF08 1B001116 */  bne        $16, $17, .L004DAF78
    /* 3DAF0C 004DAF0C 2D384000 */   daddu     $7, $2, $0
    /* 3DAF10 004DAF10 7300023C */  lui        $2, %hi(D_00729A90)
    /* 3DAF14 004DAF14 40191200 */  sll        $3, $18, 5
    /* 3DAF18 004DAF18 909A4424 */  addiu      $4, $2, %lo(D_00729A90)
    /* 3DAF1C 004DAF1C 21187600 */  addu       $3, $3, $22
    /* 3DAF20 004DAF20 2110E400 */  addu       $2, $7, $4
    /* 3DAF24 004DAF24 20008424 */  addiu      $4, $4, 0x20
    /* 3DAF28 004DAF28 00004580 */  lb         $5, 0x0($2)
    /* 3DAF2C 004DAF2C 2110E400 */  addu       $2, $7, $4
    /* 3DAF30 004DAF30 40180300 */  sll        $3, $3, 1
    /* 3DAF34 004DAF34 21208700 */  addu       $4, $4, $7
    /* 3DAF38 004DAF38 1840B300 */  mult       $8, $5, $19
    /* 3DAF3C 004DAF3C 21187700 */  addu       $3, $3, $23
    /* 3DAF40 004DAF40 21301401 */  addu       $6, $8, $20
    /* 3DAF44 004DAF44 83300600 */  sra        $6, $6, 2
    /* 3DAF48 004DAF48 1830D500 */  mult       $6, $6, $21
    /* 3DAF4C 004DAF4C 03340600 */  sra        $6, $6, 16
    /* 3DAF50 004DAF50 000066A4 */  sh         $6, 0x0($3)
    /* 3DAF54 004DAF54 00004580 */  lb         $5, 0x0($2)
    /* 3DAF58 004DAF58 1810B300 */  mult       $2, $5, $19
    /* 3DAF5C 004DAF5C 21305400 */  addu       $6, $2, $20
    /* 3DAF60 004DAF60 83300600 */  sra        $6, $6, 2
    /* 3DAF64 004DAF64 1830D500 */  mult       $6, $6, $21
    /* 3DAF68 004DAF68 03340600 */  sra        $6, $6, 16
    /* 3DAF6C 004DAF6C 400066A4 */  sh         $6, 0x40($3)
    /* 3DAF70 004DAF70 3A000010 */  b          .L004DB05C
    /* 3DAF74 004DAF74 20008580 */   lb        $5, 0x20($4)
  .L004DAF78:
    /* 3DAF78 004DAF78 05000224 */  addiu      $2, $0, 0x5
    /* 3DAF7C 004DAF7C 1C000216 */  bne        $16, $2, .L004DAFF0
    /* 3DAF80 004DAF80 09000224 */   addiu     $2, $0, 0x9
    /* 3DAF84 004DAF84 7300023C */  lui        $2, %hi(D_00729AF0)
    /* 3DAF88 004DAF88 40191200 */  sll        $3, $18, 5
    /* 3DAF8C 004DAF8C F09A4424 */  addiu      $4, $2, %lo(D_00729AF0)
    /* 3DAF90 004DAF90 21187600 */  addu       $3, $3, $22
    /* 3DAF94 004DAF94 2110E400 */  addu       $2, $7, $4
    /* 3DAF98 004DAF98 80008424 */  addiu      $4, $4, 0x80
    /* 3DAF9C 004DAF9C 00004580 */  lb         $5, 0x0($2)
    /* 3DAFA0 004DAFA0 2110E400 */  addu       $2, $7, $4
    /* 3DAFA4 004DAFA4 40180300 */  sll        $3, $3, 1
    /* 3DAFA8 004DAFA8 21208700 */  addu       $4, $4, $7
    /* 3DAFAC 004DAFAC 1840B300 */  mult       $8, $5, $19
    /* 3DAFB0 004DAFB0 21187700 */  addu       $3, $3, $23
    /* 3DAFB4 004DAFB4 21301401 */  addu       $6, $8, $20
    /* 3DAFB8 004DAFB8 83300600 */  sra        $6, $6, 2
    /* 3DAFBC 004DAFBC 1830D500 */  mult       $6, $6, $21
    /* 3DAFC0 004DAFC0 03340600 */  sra        $6, $6, 16
    /* 3DAFC4 004DAFC4 000066A4 */  sh         $6, 0x0($3)
    /* 3DAFC8 004DAFC8 00004580 */  lb         $5, 0x0($2)
    /* 3DAFCC 004DAFCC 1810B300 */  mult       $2, $5, $19
    /* 3DAFD0 004DAFD0 21305400 */  addu       $6, $2, $20
    /* 3DAFD4 004DAFD4 83300600 */  sra        $6, $6, 2
    /* 3DAFD8 004DAFD8 1830D500 */  mult       $6, $6, $21
    /* 3DAFDC 004DAFDC 03340600 */  sra        $6, $6, 16
    /* 3DAFE0 004DAFE0 400066A4 */  sh         $6, 0x40($3)
    /* 3DAFE4 004DAFE4 1D000010 */  b          .L004DB05C
    /* 3DAFE8 004DAFE8 80008580 */   lb        $5, 0x80($4)
    /* 3DAFEC 004DAFEC 00000000 */  nop
  .L004DAFF0:
    /* 3DAFF0 004DAFF0 21000216 */  bne        $16, $2, .L004DB078
    /* 3DAFF4 004DAFF4 40111200 */   sll       $2, $18, 5
    /* 3DAFF8 004DAFF8 7300023C */  lui        $2, %hi(D_00729C70)
    /* 3DAFFC 004DAFFC 40191200 */  sll        $3, $18, 5
    /* 3DB000 004DB000 709C4424 */  addiu      $4, $2, %lo(D_00729C70)
    /* 3DB004 004DB004 21187600 */  addu       $3, $3, $22
    /* 3DB008 004DB008 2110E400 */  addu       $2, $7, $4
    /* 3DB00C 004DB00C 00048424 */  addiu      $4, $4, 0x400
    /* 3DB010 004DB010 00004580 */  lb         $5, 0x0($2)
    /* 3DB014 004DB014 2110E400 */  addu       $2, $7, $4
    /* 3DB018 004DB018 40180300 */  sll        $3, $3, 1
    /* 3DB01C 004DB01C 21208700 */  addu       $4, $4, $7
    /* 3DB020 004DB020 1840B300 */  mult       $8, $5, $19
    /* 3DB024 004DB024 21187700 */  addu       $3, $3, $23
    /* 3DB028 004DB028 21301401 */  addu       $6, $8, $20
    /* 3DB02C 004DB02C 83300600 */  sra        $6, $6, 2
    /* 3DB030 004DB030 1830D500 */  mult       $6, $6, $21
    /* 3DB034 004DB034 03340600 */  sra        $6, $6, 16
    /* 3DB038 004DB038 000066A4 */  sh         $6, 0x0($3)
    /* 3DB03C 004DB03C 00004580 */  lb         $5, 0x0($2)
    /* 3DB040 004DB040 1810B300 */  mult       $2, $5, $19
    /* 3DB044 004DB044 21305400 */  addu       $6, $2, $20
    /* 3DB048 004DB048 83300600 */  sra        $6, $6, 2
    /* 3DB04C 004DB04C 1830D500 */  mult       $6, $6, $21
    /* 3DB050 004DB050 03340600 */  sra        $6, $6, 16
    /* 3DB054 004DB054 400066A4 */  sh         $6, 0x40($3)
    /* 3DB058 004DB058 00048580 */  lb         $5, 0x400($4)
  .L004DB05C:
    /* 3DB05C 004DB05C 1810B300 */  mult       $2, $5, $19
    /* 3DB060 004DB060 21305400 */  addu       $6, $2, $20
    /* 3DB064 004DB064 83300600 */  sra        $6, $6, 2
    /* 3DB068 004DB068 1830D500 */  mult       $6, $6, $21
    /* 3DB06C 004DB06C 03340600 */  sra        $6, $6, 16
    /* 3DB070 004DB070 20000010 */  b          .L004DB0F4
    /* 3DB074 004DB074 800066A4 */   sh        $6, 0x80($3)
  .L004DB078:
    /* 3DB078 004DB078 2D880000 */  daddu      $17, $0, $0
    /* 3DB07C 004DB07C 21105600 */  addu       $2, $2, $22
    /* 3DB080 004DB080 40100200 */  sll        $2, $2, 1
    /* 3DB084 004DB084 21285700 */  addu       $5, $2, $23
  .L004DB088:
    /* 3DB088 004DB088 1A00F000 */  div        $0, $7, $16
    /* 3DB08C 004DB08C 01003126 */  addiu      $17, $17, 0x1
    /* 3DB090 004DB090 0300242A */  slti       $4, $17, 0x3
    /* 3DB094 004DB094 01000052 */  beql       $16, $0, .L004DB09C
    /* 3DB098 004DB098 CD010000 */   break     0, 7
  .L004DB09C:
    /* 3DB09C 004DB09C 10100000 */  mfhi       $2
    /* 3DB0A0 004DB0A0 12180000 */  mflo       $3
    /* 3DB0A4 004DB0A4 18385300 */  mult       $7, $2, $19
    /* 3DB0A8 004DB0A8 2130F400 */  addu       $6, $7, $20
    /* 3DB0AC 004DB0AC 2D386000 */  daddu      $7, $3, $0
    /* 3DB0B0 004DB0B0 83300600 */  sra        $6, $6, 2
    /* 3DB0B4 004DB0B4 1830D500 */  mult       $6, $6, $21
    /* 3DB0B8 004DB0B8 03340600 */  sra        $6, $6, 16
    /* 3DB0BC 004DB0BC 0000A6A4 */  sh         $6, 0x0($5)
    /* 3DB0C0 004DB0C0 F1FF8014 */  bnez       $4, .L004DB088
    /* 3DB0C4 004DB0C4 4000A524 */   addiu     $5, $5, 0x40
    /* 3DB0C8 004DB0C8 0B000010 */  b          .L004DB0F8
    /* 3DB0CC 004DB0CC 1000A88F */   lw        $8, 0x10($29)
  .L004DB0D0:
    /* 3DB0D0 004DB0D0 40101E00 */  sll        $2, $30, 1
    /* 3DB0D4 004DB0D4 21105E00 */  addu       $2, $2, $30
    /* 3DB0D8 004DB0D8 40110200 */  sll        $2, $2, 5
    /* 3DB0DC 004DB0DC 21105600 */  addu       $2, $2, $22
    /* 3DB0E0 004DB0E0 40100200 */  sll        $2, $2, 1
    /* 3DB0E4 004DB0E4 21105700 */  addu       $2, $2, $23
    /* 3DB0E8 004DB0E8 800040A4 */  sh         $0, 0x80($2)
    /* 3DB0EC 004DB0EC 000040A4 */  sh         $0, 0x0($2)
    /* 3DB0F0 004DB0F0 400040A4 */  sh         $0, 0x40($2)
  .L004DB0F4:
    /* 3DB0F4 004DB0F4 1000A88F */  lw         $8, 0x10($29)
  .L004DB0F8:
    /* 3DB0F8 004DB0F8 02000224 */  addiu      $2, $0, 0x2
    /* 3DB0FC 004DB0FC 12000255 */  bnel       $8, $2, .L004DB148
    /* 3DB100 004DB100 0100DE27 */   addiu     $30, $30, 0x1
    /* 3DB104 004DB104 2000AA8F */  lw         $10, 0x20($29)
    /* 3DB108 004DB108 0F004055 */  bnel       $10, $0, .L004DB148
    /* 3DB10C 004DB10C 0100DE27 */   addiu     $30, $30, 0x1
    /* 3DB110 004DB110 2400A48F */  lw         $4, 0x24($29)
    /* 3DB114 004DB114 40181600 */  sll        $3, $22, 1
    /* 3DB118 004DB118 21187700 */  addu       $3, $3, $23
    /* 3DB11C 004DB11C 02001124 */  addiu      $17, $0, 0x2
    /* 3DB120 004DB120 2110E402 */  addu       $2, $23, $4
    /* 3DB124 004DB124 C0004424 */  addiu      $4, $2, 0xC0
  .L004DB128:
    /* 3DB128 004DB128 00006294 */  lhu        $2, 0x0($3)
    /* 3DB12C 004DB12C 40006324 */  addiu      $3, $3, 0x40
    /* 3DB130 004DB130 FFFF3126 */  addiu      $17, $17, -0x1
    /* 3DB134 004DB134 000082A4 */  sh         $2, 0x0($4)
    /* 3DB138 004DB138 00000000 */  nop
    /* 3DB13C 004DB13C FAFF2106 */  bgez       $17, .L004DB128
    /* 3DB140 004DB140 40008424 */   addiu     $4, $4, 0x40
    /* 3DB144 004DB144 0100DE27 */  addiu      $30, $30, 0x1
  .L004DB148:
    /* 3DB148 004DB148 2000A78F */  lw         $7, 0x20($29)
    /* 3DB14C 004DB14C 0600E010 */  beqz       $7, .L004DB168
    /* 3DB150 004DB150 1000A88F */   lw        $8, 0x10($29)
    /* 3DB154 004DB154 2A10C803 */  slt        $2, $30, $8
    /* 3DB158 004DB158 FFFE4014 */  bnez       $2, .L004DAD58
    /* 3DB15C 004DB15C 40111E00 */   sll       $2, $30, 5
    /* 3DB160 004DB160 04000010 */  b          .L004DB174
    /* 3DB164 004DB164 2400AA8F */   lw        $10, 0x24($29)
  .L004DB168:
    /* 3DB168 004DB168 FBFEC01B */  blez       $30, .L004DAD58
    /* 3DB16C 004DB16C 40111E00 */   sll       $2, $30, 5
    /* 3DB170 004DB170 2400AA8F */  lw         $10, 0x24($29)
  .L004DB174:
    /* 3DB174 004DB174 0100D626 */  addiu      $22, $22, 0x1
    /* 3DB178 004DB178 2800A48F */  lw         $4, 0x28($29)
    /* 3DB17C 004DB17C 1400A38F */  lw         $3, 0x14($29)
    /* 3DB180 004DB180 02004A25 */  addiu      $10, $10, 0x2
    /* 3DB184 004DB184 80018424 */  addiu      $4, $4, 0x180
    /* 3DB188 004DB188 2400AAAF */  sw         $10, 0x24($29)
    /* 3DB18C 004DB18C 2A10C302 */  slt        $2, $22, $3
    /* 3DB190 004DB190 EBFE4014 */  bnez       $2, .L004DAD40
    /* 3DB194 004DB194 2800A4AF */   sw        $4, 0x28($29)
  .L004DB198:
    /* 3DB198 004DB198 1400B68F */  lw         $22, 0x14($29)
    /* 3DB19C 004DB19C 2000C22A */  slti       $2, $22, 0x20
    /* 3DB1A0 004DB1A0 20004010 */  beqz       $2, .L004DB224
    /* 3DB1A4 004DB1A4 3000B0DF */   ld        $16, 0x30($29)
    /* 3DB1A8 004DB1A8 1000A78F */  lw         $7, 0x10($29)
    /* 3DB1AC 004DB1AC 00000000 */  nop
  .L004DB1B0:
    /* 3DB1B0 004DB1B0 1700E018 */  blez       $7, .L004DB210
    /* 3DB1B4 004DB1B4 2DF00000 */   daddu     $30, $0, $0
    /* 3DB1B8 004DB1B8 2D180000 */  daddu      $3, $0, $0
    /* 3DB1BC 004DB1BC 00000000 */  nop
  .L004DB1C0:
    /* 3DB1C0 004DB1C0 21107E00 */  addu       $2, $3, $30
    /* 3DB1C4 004DB1C4 02001124 */  addiu      $17, $0, 0x2
    /* 3DB1C8 004DB1C8 40110200 */  sll        $2, $2, 5
    /* 3DB1CC 004DB1CC 21105600 */  addu       $2, $2, $22
    /* 3DB1D0 004DB1D0 40100200 */  sll        $2, $2, 1
    /* 3DB1D4 004DB1D4 21105700 */  addu       $2, $2, $23
    /* 3DB1D8 004DB1D8 80004224 */  addiu      $2, $2, 0x80
    /* 3DB1DC 004DB1DC 00000000 */  nop
  .L004DB1E0:
    /* 3DB1E0 004DB1E0 FFFF3126 */  addiu      $17, $17, -0x1
    /* 3DB1E4 004DB1E4 000040A4 */  sh         $0, 0x0($2)
    /* 3DB1E8 004DB1E8 00000000 */  nop
    /* 3DB1EC 004DB1EC 00000000 */  nop
    /* 3DB1F0 004DB1F0 00000000 */  nop
    /* 3DB1F4 004DB1F4 FAFF2106 */  bgez       $17, .L004DB1E0
    /* 3DB1F8 004DB1F8 C0FF4224 */   addiu     $2, $2, -0x40
    /* 3DB1FC 004DB1FC 1000A88F */  lw         $8, 0x10($29)
    /* 3DB200 004DB200 0100DE27 */  addiu      $30, $30, 0x1
    /* 3DB204 004DB204 2A10C803 */  slt        $2, $30, $8
    /* 3DB208 004DB208 EDFF4014 */  bnez       $2, .L004DB1C0
    /* 3DB20C 004DB20C 02006324 */   addiu     $3, $3, 0x2
  .L004DB210:
    /* 3DB210 004DB210 0100D626 */  addiu      $22, $22, 0x1
    /* 3DB214 004DB214 2000C22A */  slti       $2, $22, 0x20
    /* 3DB218 004DB218 E5FF4014 */  bnez       $2, .L004DB1B0
    /* 3DB21C 004DB21C 1000A78F */   lw        $7, 0x10($29)
    /* 3DB220 004DB220 3000B0DF */  ld         $16, 0x30($29)
  .L004DB224:
    /* 3DB224 004DB224 3800B1DF */  ld         $17, 0x38($29)
    /* 3DB228 004DB228 4000B2DF */  ld         $18, 0x40($29)
    /* 3DB22C 004DB22C 4800B3DF */  ld         $19, 0x48($29)
    /* 3DB230 004DB230 5000B4DF */  ld         $20, 0x50($29)
    /* 3DB234 004DB234 5800B5DF */  ld         $21, 0x58($29)
    /* 3DB238 004DB238 6000B6DF */  ld         $22, 0x60($29)
    /* 3DB23C 004DB23C 6800B7DF */  ld         $23, 0x68($29)
    /* 3DB240 004DB240 7000BEDF */  ld         $30, 0x70($29)
    /* 3DB244 004DB244 7800BFDF */  ld         $31, 0x78($29)
    /* 3DB248 004DB248 0800E003 */  jr         $31
    /* 3DB24C 004DB24C 8000BD27 */   addiu     $29, $29, 0x80
.size func_004dacb8, 0x598
