.section .text
.set noat
.set noreorder
glabel func_001bcb50
    /* BCB50 001BCB50 90FFBD27 */  addiu      $29, $29, -0x70
    /* BCB54 001BCB54 6000BFFF */  sd         $31, 0x60($29)
    /* BCB58 001BCB58 5000B47F */  sq         $20, 0x50($29)
    /* BCB5C 001BCB5C 4000B37F */  sq         $19, 0x40($29)
    /* BCB60 001BCB60 3000B27F */  sq         $18, 0x30($29)
    /* BCB64 001BCB64 2000B17F */  sq         $17, 0x20($29)
    /* BCB68 001BCB68 1000B07F */  sq         $16, 0x10($29)
    /* BCB6C 001BCB6C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* BCB70 001BCB70 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BCB74 001BCB74 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BCB78 001BCB78 2DA08000 */  daddu      $20, $4, $0
    /* BCB7C 001BCB7C 2D98A000 */  daddu      $19, $5, $0
    /* BCB80 001BCB80 2D90C000 */  daddu      $18, $6, $0
    /* BCB84 001BCB84 46650046 */  mov.s      $f21, $f12
    /* BCB88 001BCB88 2D88E000 */  daddu      $17, $7, $0
    /* BCB8C 001BCB8C 2D800001 */  daddu      $16, $8, $0
    /* BCB90 001BCB90 066D0046 */  mov.s      $f20, $f13
    /* BCB94 001BCB94 86750046 */  mov.s      $f22, $f14
    /* BCB98 001BCB98 01020424 */  addiu      $4, $0, 0x201
    /* BCB9C 001BCB9C 44000524 */  addiu      $5, $0, 0x44
    /* BCBA0 001BCBA0 1C51060C */  jal        func_00194470
    /* BCBA4 001BCBA4 00000000 */   nop
    /* BCBA8 001BCBA8 1C00033C */  lui        $3, %hi(func_001bc980)
    /* BCBAC 001BCBAC 80C96324 */  addiu      $3, $3, %lo(func_001bc980)
    /* BCBB0 001BCBB0 6C0043AC */  sw         $3, 0x6C($2)
    /* BCBB4 001BCBB4 7800448C */  lw         $4, 0x78($2)
    /* BCBB8 001BCBB8 000094AC */  sw         $20, 0x0($4)
    /* BCBBC 001BCBBC 3C0096E4 */  swc1       $f22, 0x3C($4)
    /* BCBC0 001BCBC0 12006012 */  beqz       $19, .L001BCC0C
    /* BCBC4 001BCBC4 00000000 */   nop
    /* BCBC8 001BCBC8 10004012 */  beqz       $18, .L001BCC0C
    /* BCBCC 001BCBCC 00000000 */   nop
    /* BCBD0 001BCBD0 000062C6 */  lwc1       $f2, 0x0($19)
    /* BCBD4 001BCBD4 040061C6 */  lwc1       $f1, 0x4($19)
    /* BCBD8 001BCBD8 080060C6 */  lwc1       $f0, 0x8($19)
    /* BCBDC 001BCBDC 040082E4 */  swc1       $f2, 0x4($4)
    /* BCBE0 001BCBE0 080081E4 */  swc1       $f1, 0x8($4)
    /* BCBE4 001BCBE4 0C0080E4 */  swc1       $f0, 0xC($4)
    /* BCBE8 001BCBE8 000042C6 */  lwc1       $f2, 0x0($18)
    /* BCBEC 001BCBEC 040041C6 */  lwc1       $f1, 0x4($18)
    /* BCBF0 001BCBF0 080040C6 */  lwc1       $f0, 0x8($18)
    /* BCBF4 001BCBF4 100082E4 */  swc1       $f2, 0x10($4)
    /* BCBF8 001BCBF8 140081E4 */  swc1       $f1, 0x14($4)
    /* BCBFC 001BCBFC 180080E4 */  swc1       $f0, 0x18($4)
    /* BCC00 001BCC00 400080AC */  sw         $0, 0x40($4)
    /* BCC04 001BCC04 03000010 */  b          .L001BCC14
    /* BCC08 001BCC08 00000000 */   nop
  .L001BCC0C:
    /* BCC0C 001BCC0C 01000324 */  addiu      $3, $0, 0x1
    /* BCC10 001BCC10 400083AC */  sw         $3, 0x40($4)
  .L001BCC14:
    /* BCC14 001BCC14 000022C6 */  lwc1       $f2, 0x0($17)
    /* BCC18 001BCC18 040021C6 */  lwc1       $f1, 0x4($17)
    /* BCC1C 001BCC1C 080020C6 */  lwc1       $f0, 0x8($17)
    /* BCC20 001BCC20 1C0082E4 */  swc1       $f2, 0x1C($4)
    /* BCC24 001BCC24 200081E4 */  swc1       $f1, 0x20($4)
    /* BCC28 001BCC28 240080E4 */  swc1       $f0, 0x24($4)
    /* BCC2C 001BCC2C 000002C6 */  lwc1       $f2, 0x0($16)
    /* BCC30 001BCC30 040001C6 */  lwc1       $f1, 0x4($16)
    /* BCC34 001BCC34 080000C6 */  lwc1       $f0, 0x8($16)
    /* BCC38 001BCC38 280082E4 */  swc1       $f2, 0x28($4)
    /* BCC3C 001BCC3C 2C0081E4 */  swc1       $f1, 0x2C($4)
    /* BCC40 001BCC40 300080E4 */  swc1       $f0, 0x30($4)
    /* BCC44 001BCC44 340095E4 */  swc1       $f21, 0x34($4)
    /* BCC48 001BCC48 380094E4 */  swc1       $f20, 0x38($4)
    /* BCC4C 001BCC4C 6000BFDF */  ld         $31, 0x60($29)
    /* BCC50 001BCC50 5000B47B */  lq         $20, 0x50($29)
    /* BCC54 001BCC54 4000B37B */  lq         $19, 0x40($29)
    /* BCC58 001BCC58 3000B27B */  lq         $18, 0x30($29)
    /* BCC5C 001BCC5C 2000B17B */  lq         $17, 0x20($29)
    /* BCC60 001BCC60 1000B07B */  lq         $16, 0x10($29)
    /* BCC64 001BCC64 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* BCC68 001BCC68 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* BCC6C 001BCC6C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BCC70 001BCC70 7000BD27 */  addiu      $29, $29, 0x70
    /* BCC74 001BCC74 0800E003 */  jr         $31
    /* BCC78 001BCC78 00000000 */   nop
    /* BCC7C 001BCC7C 00000000 */  nop
.size func_001bcb50, 0x130
