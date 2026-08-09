.section .text
.set noat
.set noreorder
glabel func_004eec78
    /* 3EEC78 004EEC78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEC7C 004EEC7C 7400083C */  lui        $8, %hi(D_00742028)
    /* 3EEC80 004EEC80 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEC84 004EEC84 28200325 */  addiu      $3, $8, %lo(D_00742028)
    /* 3EEC88 004EEC88 0800BFFF */  sd         $31, 0x8($29)
    /* 3EEC8C 004EEC8C 2D488000 */  daddu      $9, $4, $0
    /* 3EEC90 004EEC90 2D50A000 */  daddu      $10, $5, $0
    /* 3EEC94 004EEC94 2D38C000 */  daddu      $7, $6, $0
    /* 3EEC98 004EEC98 04006280 */  lb         $2, 0x4($3)
    /* 3EEC9C 004EEC9C 0D004010 */  beqz       $2, .L004EECD4
    /* 3EECA0 004EECA0 2D200000 */   daddu     $4, $0, $0
    /* 3EECA4 004EECA4 04006324 */  addiu      $3, $3, 0x4
    /* 3EECA8 004EECA8 01008424 */  addiu      $4, $4, 0x1
    /* 3EECAC 004EECAC 00000000 */  nop
  .L004EECB0:
    /* 3EECB0 004EECB0 40008228 */  slti       $2, $4, 0x40
    /* 3EECB4 004EECB4 07004010 */  beqz       $2, .L004EECD4
    /* 3EECB8 004EECB8 30006324 */   addiu     $3, $3, 0x30
    /* 3EECBC 004EECBC 00006280 */  lb         $2, 0x0($3)
    /* 3EECC0 004EECC0 00000000 */  nop
    /* 3EECC4 004EECC4 00000000 */  nop
    /* 3EECC8 004EECC8 00000000 */  nop
    /* 3EECCC 004EECCC F8FF4054 */  bnel       $2, $0, .L004EECB0
    /* 3EECD0 004EECD0 01008424 */   addiu     $4, $4, 0x1
  .L004EECD4:
    /* 3EECD4 004EECD4 40000324 */  addiu      $3, $0, 0x40
    /* 3EECD8 004EECD8 1C008310 */  beq        $4, $3, .L004EED4C
    /* 3EECDC 004EECDC 2D100000 */   daddu     $2, $0, $0
    /* 3EECE0 004EECE0 40800400 */  sll        $16, $4, 1
    /* 3EECE4 004EECE4 28200325 */  addiu      $3, $8, %lo(D_00742028)
    /* 3EECE8 004EECE8 21800402 */  addu       $16, $16, $4
    /* 3EECEC 004EECEC 0F00E424 */  addiu      $4, $7, 0xF
    /* 3EECF0 004EECF0 0000E228 */  slti       $2, $7, 0x0
    /* 3EECF4 004EECF4 00811000 */  sll        $16, $16, 4
    /* 3EECF8 004EECF8 21800302 */  addu       $16, $16, $3
    /* 3EECFC 004EECFC 7400033C */  lui        $3, %hi(D_00741FF0)
    /* 3EED00 004EED00 0B388200 */  movn       $7, $4, $2
    /* 3EED04 004EED04 01000224 */  addiu      $2, $0, 0x1
    /* 3EED08 004EED08 7600053C */  lui        $5, %hi(D_0075CEC8)
    /* 3EED0C 004EED0C 4F00063C */  lui        $6, %hi(func_004eeab8)
    /* 3EED10 004EED10 F01F6324 */  addiu      $3, $3, %lo(D_00741FF0)
    /* 3EED14 004EED14 C8CEA524 */  addiu      $5, $5, %lo(D_0075CEC8)
    /* 3EED18 004EED18 03390700 */  sra        $7, $7, 4
    /* 3EED1C 004EED1C B8EAC624 */  addiu      $6, $6, %lo(func_004eeab8)
    /* 3EED20 004EED20 040002A2 */  sb         $2, 0x4($16)
    /* 3EED24 004EED24 2D200002 */  daddu      $4, $16, $0
    /* 3EED28 004EED28 000003AE */  sw         $3, 0x0($16)
    /* 3EED2C 004EED2C 050009A2 */  sb         $9, 0x5($16)
    /* 3EED30 004EED30 080005AE */  sw         $5, 0x8($16)
    /* 3EED34 004EED34 0C000AAE */  sw         $10, 0xC($16)
    /* 3EED38 004EED38 100007AE */  sw         $7, 0x10($16)
    /* 3EED3C 004EED3C 280006AE */  sw         $6, 0x28($16)
    /* 3EED40 004EED40 E2BB130C */  jal        func_004eef88
    /* 3EED44 004EED44 2C0010AE */   sw        $16, 0x2C($16)
    /* 3EED48 004EED48 2D100002 */  daddu      $2, $16, $0
  .L004EED4C:
    /* 3EED4C 004EED4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EED50 004EED50 0800BFDF */  ld         $31, 0x8($29)
    /* 3EED54 004EED54 0800E003 */  jr         $31
    /* 3EED58 004EED58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EED5C 004EED5C 00000000 */  nop
.size func_004eec78, 0xe8
