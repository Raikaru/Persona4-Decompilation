.section .text
.set noat
.set noreorder
glabel func_0043fb38
    /* 33FB38 0043FB38 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33FB3C 0043FB3C 0000B0FF */  sd         $16, 0x0($29)
    /* 33FB40 0043FB40 0800B1FF */  sd         $17, 0x8($29)
    /* 33FB44 0043FB44 1000BFFF */  sd         $31, 0x10($29)
    /* 33FB48 0043FB48 2D808000 */  daddu      $16, $4, $0
    /* 33FB4C 0043FB4C 2D88A000 */  daddu      $17, $5, $0
    /* 33FB50 0043FB50 4C008E8C */  lw         $14, 0x4C($4)
    /* 33FB54 0043FB54 0700C015 */  bnez       $14, .L0043FB74
    /* 33FB58 0043FB58 04000524 */   addiu     $5, $0, 0x4
    /* 33FB5C 0043FB5C CEF1100C */  jal        func_0043c738
    /* 33FB60 0043FB60 10000624 */   addiu     $6, $0, 0x10
    /* 33FB64 0043FB64 4C0002AE */  sw         $2, 0x4C($16)
    /* 33FB68 0043FB68 2D780000 */  daddu      $15, $0, $0
    /* 33FB6C 0043FB6C 0B004010 */  beqz       $2, .L0043FB9C
    /* 33FB70 0043FB70 2D704000 */   daddu     $14, $2, $0
  .L0043FB74:
    /* 33FB74 0043FB74 80781100 */  sll        $15, $17, 2
    /* 33FB78 0043FB78 2170EE01 */  addu       $14, $15, $14
    /* 33FB7C 0043FB7C 0000C28D */  lw         $2, 0x0($14)
    /* 33FB80 0043FB80 0C004010 */  beqz       $2, .L0043FBB4
    /* 33FB84 0043FB84 01000F24 */   addiu     $15, $0, 0x1
    /* 33FB88 0043FB88 00004F8C */  lw         $15, 0x0($2)
    /* 33FB8C 0043FB8C 0000CFAD */  sw         $15, 0x0($14)
  .L0043FB90:
    /* 33FB90 0043FB90 100040AC */  sw         $0, 0x10($2)
    /* 33FB94 0043FB94 2D784000 */  daddu      $15, $2, $0
    /* 33FB98 0043FB98 0C0040AC */  sw         $0, 0xC($2)
  .L0043FB9C:
    /* 33FB9C 0043FB9C 0000B0DF */  ld         $16, 0x0($29)
    /* 33FBA0 0043FBA0 2D10E001 */  daddu      $2, $15, $0
    /* 33FBA4 0043FBA4 0800B1DF */  ld         $17, 0x8($29)
    /* 33FBA8 0043FBA8 1000BFDF */  ld         $31, 0x10($29)
    /* 33FBAC 0043FBAC 0800E003 */  jr         $31
    /* 33FBB0 0043FBB0 2000BD27 */   addiu     $29, $29, 0x20
  .L0043FBB4:
    /* 33FBB4 0043FBB4 2D200002 */  daddu      $4, $16, $0
    /* 33FBB8 0043FBB8 04802F02 */  sllv       $16, $15, $17
    /* 33FBBC 0043FBBC 01000524 */  addiu      $5, $0, 0x1
    /* 33FBC0 0043FBC0 80301000 */  sll        $6, $16, 2
    /* 33FBC4 0043FBC4 CEF1100C */  jal        func_0043c738
    /* 33FBC8 0043FBC8 1400C624 */   addiu     $6, $6, 0x14
    /* 33FBCC 0043FBCC F3FF4010 */  beqz       $2, .L0043FB9C
    /* 33FBD0 0043FBD0 2D780000 */   daddu     $15, $0, $0
    /* 33FBD4 0043FBD4 040051AC */  sw         $17, 0x4($2)
    /* 33FBD8 0043FBD8 EDFF0010 */  b          .L0043FB90
    /* 33FBDC 0043FBDC 080050AC */   sw        $16, 0x8($2)
.size func_0043fb38, 0xa8
