.section .text
.set noat
.set noreorder
glabel func_001ebb00
    /* EBB00 001EBB00 A0FFBD27 */  addiu      $29, $29, -0x60
    /* EBB04 001EBB04 5000BFFF */  sd         $31, 0x50($29)
    /* EBB08 001EBB08 4000B47F */  sq         $20, 0x40($29)
    /* EBB0C 001EBB0C 3000B37F */  sq         $19, 0x30($29)
    /* EBB10 001EBB10 2000B27F */  sq         $18, 0x20($29)
    /* EBB14 001EBB14 1000B17F */  sq         $17, 0x10($29)
    /* EBB18 001EBB18 0000B07F */  sq         $16, 0x0($29)
    /* EBB1C 001EBB1C 2DA08000 */  daddu      $20, $4, $0
    /* EBB20 001EBB20 2D98A000 */  daddu      $19, $5, $0
    /* EBB24 001EBB24 2D90C000 */  daddu      $18, $6, $0
    /* EBB28 001EBB28 000D0424 */  addiu      $4, $0, 0xD00
    /* EBB2C 001EBB2C 10000524 */  addiu      $5, $0, 0x10
    /* EBB30 001EBB30 1C51060C */  jal        func_00194470
    /* EBB34 001EBB34 00000000 */   nop
    /* EBB38 001EBB38 2D884000 */  daddu      $17, $2, $0
    /* EBB3C 001EBB3C 47004390 */  lbu        $3, 0x47($2)
    /* EBB40 001EBB40 EE006330 */  andi       $3, $3, 0xEE
    /* EBB44 001EBB44 470043A0 */  sb         $3, 0x47($2)
    /* EBB48 001EBB48 1F00033C */  lui        $3, %hi(func_001eba20)
    /* EBB4C 001EBB4C 20BA6324 */  addiu      $3, $3, %lo(func_001eba20)
    /* EBB50 001EBB50 6C0043AC */  sw         $3, 0x6C($2)
    /* EBB54 001EBB54 7800508C */  lw         $16, 0x78($2)
    /* EBB58 001EBB58 FFFF6332 */  andi       $3, $19, 0xFFFF
    /* EBB5C 001EBB5C 03000224 */  addiu      $2, $0, 0x3
    /* EBB60 001EBB60 11006210 */  beq        $3, $2, .L001EBBA8
    /* EBB64 001EBB64 00000000 */   nop
    /* EBB68 001EBB68 02000224 */  addiu      $2, $0, 0x2
    /* EBB6C 001EBB6C 0A006210 */  beq        $3, $2, .L001EBB98
    /* EBB70 001EBB70 00000000 */   nop
    /* EBB74 001EBB74 01000224 */  addiu      $2, $0, 0x1
    /* EBB78 001EBB78 03006210 */  beq        $3, $2, .L001EBB88
    /* EBB7C 001EBB7C 00000000 */   nop
    /* EBB80 001EBB80 0D000010 */  b          .L001EBBB8
    /* EBB84 001EBB84 00000000 */   nop
  .L001EBB88:
    /* EBB88 001EBB88 28B4828F */  lw         $2, -0x4BD8($28)
    /* EBB8C 001EBB8C 0C0002AE */  sw         $2, 0xC($16)
    /* EBB90 001EBB90 09000010 */  b          .L001EBBB8
    /* EBB94 001EBB94 00000000 */   nop
  .L001EBB98:
    /* EBB98 001EBB98 2CB4828F */  lw         $2, -0x4BD4($28)
    /* EBB9C 001EBB9C 0C0002AE */  sw         $2, 0xC($16)
    /* EBBA0 001EBBA0 05000010 */  b          .L001EBBB8
    /* EBBA4 001EBBA4 00000000 */   nop
  .L001EBBA8:
    /* EBBA8 001EBBA8 2D200000 */  daddu      $4, $0, $0
    /* EBBAC 001EBBAC B4B3080C */  jal        func_0022ced0
    /* EBBB0 001EBBB0 00000000 */   nop
    /* EBBB4 001EBBB4 0C0002AE */  sw         $2, 0xC($16)
  .L001EBBB8:
    /* EBBB8 001EBBB8 000014AE */  sw         $20, 0x0($16)
    /* EBBBC 001EBBBC 0C00048E */  lw         $4, 0xC($16)
    /* EBBC0 001EBBC0 2D284002 */  daddu      $5, $18, $0
    /* EBBC4 001EBBC4 88770A0C */  jal        func_0029de20
    /* EBBC8 001EBBC8 00000000 */   nop
    /* EBBCC 001EBBCC 040002AE */  sw         $2, 0x4($16)
    /* EBBD0 001EBBD0 080000AE */  sw         $0, 0x8($16)
    /* EBBD4 001EBBD4 2D102002 */  daddu      $2, $17, $0
    /* EBBD8 001EBBD8 5000BFDF */  ld         $31, 0x50($29)
    /* EBBDC 001EBBDC 4000B47B */  lq         $20, 0x40($29)
    /* EBBE0 001EBBE0 3000B37B */  lq         $19, 0x30($29)
    /* EBBE4 001EBBE4 2000B27B */  lq         $18, 0x20($29)
    /* EBBE8 001EBBE8 1000B17B */  lq         $17, 0x10($29)
    /* EBBEC 001EBBEC 0000B07B */  lq         $16, 0x0($29)
    /* EBBF0 001EBBF0 6000BD27 */  addiu      $29, $29, 0x60
    /* EBBF4 001EBBF4 0800E003 */  jr         $31
    /* EBBF8 001EBBF8 00000000 */   nop
    /* EBBFC 001EBBFC 00000000 */  nop
.size func_001ebb00, 0x100
