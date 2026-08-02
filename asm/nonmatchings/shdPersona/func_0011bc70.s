.section .text
.set noat
.set noreorder
glabel func_0011bc70
    /* 1BC70 0011BC70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BC74 0011BC74 1000BFFF */  sd         $31, 0x10($29)
    /* 1BC78 0011BC78 0000B07F */  sq         $16, 0x0($29)
    /* 1BC7C 0011BC7C 3800908C */  lw         $16, 0x38($4)
    /* 1BC80 0011BC80 3405048E */  lw         $4, 0x534($16)
    /* 1BC84 0011BC84 01008330 */  andi       $3, $4, 0x1
    /* 1BC88 0011BC88 04006010 */  beqz       $3, .L0011BC9C
    /* 1BC8C 0011BC8C 00000000 */   nop
    /* 1BC90 0011BC90 04008330 */  andi       $3, $4, 0x4
    /* 1BC94 0011BC94 05006010 */  beqz       $3, .L0011BCAC
    /* 1BC98 0011BC98 00000000 */   nop
  .L0011BC9C:
    /* 1BC9C 0011BC9C 4000033C */  lui        $3, (0x400000 >> 16)
    /* 1BCA0 0011BCA0 24188300 */  and        $3, $4, $3
    /* 1BCA4 0011BCA4 40006010 */  beqz       $3, .L0011BDA8
    /* 1BCA8 0011BCA8 00000000 */   nop
  .L0011BCAC:
    /* 1BCAC 0011BCAC 3405028E */  lw         $2, 0x534($16)
    /* 1BCB0 0011BCB0 04004334 */  ori        $3, $2, 0x4
    /* 1BCB4 0011BCB4 340503AE */  sw         $3, 0x534($16)
    /* 1BCB8 0011BCB8 FDFF0224 */  addiu      $2, $0, -0x3
    /* 1BCBC 0011BCBC 24186200 */  and        $3, $3, $2
    /* 1BCC0 0011BCC0 340503AE */  sw         $3, 0x534($16)
    /* 1BCC4 0011BCC4 FFF70224 */  addiu      $2, $0, -0x801
    /* 1BCC8 0011BCC8 24186200 */  and        $3, $3, $2
    /* 1BCCC 0011BCCC 340503AE */  sw         $3, 0x534($16)
    /* 1BCD0 0011BCD0 FFEF0224 */  addiu      $2, $0, -0x1001
    /* 1BCD4 0011BCD4 24186200 */  and        $3, $3, $2
    /* 1BCD8 0011BCD8 340503AE */  sw         $3, 0x534($16)
    /* 1BCDC 0011BCDC FFDF0224 */  addiu      $2, $0, -0x2001
    /* 1BCE0 0011BCE0 24186200 */  and        $3, $3, $2
    /* 1BCE4 0011BCE4 340503AE */  sw         $3, 0x534($16)
    /* 1BCE8 0011BCE8 FFBF0224 */  addiu      $2, $0, -0x4001
    /* 1BCEC 0011BCEC 24106200 */  and        $2, $3, $2
    /* 1BCF0 0011BCF0 340502AE */  sw         $2, 0x534($16)
    /* 1BCF4 0011BCF4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BCF8 0011BCF8 880002A2 */  sb         $2, 0x88($16)
    /* 1BCFC 0011BCFC E1C3023C */  lui        $2, (0xC3E10000 >> 16)
    /* 1BD00 0011BD00 440402AE */  sw         $2, 0x444($16)
    /* 1BD04 0011BD04 2C05038E */  lw         $3, 0x52C($16)
    /* 1BD08 0011BD08 04000724 */  addiu      $7, $0, 0x4
    /* 1BD0C 0011BD0C 19006710 */  beq        $3, $7, .L0011BD74
    /* 1BD10 0011BD10 00000000 */   nop
    /* 1BD14 0011BD14 02000224 */  addiu      $2, $0, 0x2
    /* 1BD18 0011BD18 16006210 */  beq        $3, $2, .L0011BD74
    /* 1BD1C 0011BD1C 00000000 */   nop
    /* 1BD20 0011BD20 03000224 */  addiu      $2, $0, 0x3
    /* 1BD24 0011BD24 13006210 */  beq        $3, $2, .L0011BD74
    /* 1BD28 0011BD28 00000000 */   nop
    /* 1BD2C 0011BD2C 01000524 */  addiu      $5, $0, 0x1
    /* 1BD30 0011BD30 10006510 */  beq        $3, $5, .L0011BD74
    /* 1BD34 0011BD34 00000000 */   nop
    /* 1BD38 0011BD38 03006010 */  beqz       $3, .L0011BD48
    /* 1BD3C 0011BD3C 00000000 */   nop
    /* 1BD40 0011BD40 07000010 */  b          .L0011BD60
    /* 1BD44 0011BD44 00000000 */   nop
  .L0011BD48:
    /* 1BD48 0011BD48 2D200000 */  daddu      $4, $0, $0
    /* 1BD4C 0011BD4C 2D300000 */  daddu      $6, $0, $0
    /* 1BD50 0011BD50 D86B110C */  jal        func_0045af60
    /* 1BD54 0011BD54 00000000 */   nop
    /* 1BD58 0011BD58 06000010 */  b          .L0011BD74
    /* 1BD5C 0011BD5C 00000000 */   nop
  .L0011BD60:
    /* 1BD60 0011BD60 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1BD64 0011BD64 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1BD68 0011BD68 CC0C0524 */  addiu      $5, $0, 0xCCC
    /* 1BD6C 0011BD6C CCB5110C */  jal        func_0046d730
    /* 1BD70 0011BD70 00000000 */   nop
  .L0011BD74:
    /* 1BD74 0011BD74 080500A6 */  sh         $0, 0x508($16)
    /* 1BD78 0011BD78 05050292 */  lbu        $2, 0x505($16)
    /* 1BD7C 0011BD7C 040502A2 */  sb         $2, 0x504($16)
    /* 1BD80 0011BD80 060500A2 */  sb         $0, 0x506($16)
    /* 1BD84 0011BD84 2D200002 */  daddu      $4, $16, $0
    /* 1BD88 0011BD88 01000524 */  addiu      $5, $0, 0x1
    /* 1BD8C 0011BD8C A86A040C */  jal        func_0011aaa0
    /* 1BD90 0011BD90 00000000 */   nop
    /* 1BD94 0011BD94 3405048E */  lw         $4, 0x534($16)
    /* 1BD98 0011BD98 7FFF033C */  lui        $3, (0xFF7FFFFF >> 16)
    /* 1BD9C 0011BD9C FFFF6334 */  ori        $3, $3, (0xFF7FFFFF & 0xFFFF)
    /* 1BDA0 0011BDA0 24188300 */  and        $3, $4, $3
    /* 1BDA4 0011BDA4 340503AE */  sw         $3, 0x534($16)
  .L0011BDA8:
    /* 1BDA8 0011BDA8 1000BFDF */  ld         $31, 0x10($29)
    /* 1BDAC 0011BDAC 0000B07B */  lq         $16, 0x0($29)
    /* 1BDB0 0011BDB0 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BDB4 0011BDB4 0800E003 */  jr         $31
    /* 1BDB8 0011BDB8 00000000 */   nop
    /* 1BDBC 0011BDBC 00000000 */  nop
.size func_0011bc70, 0x150
