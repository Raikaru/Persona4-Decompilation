.section .text
.set noat
.set noreorder
glabel func_003ea370
    /* 2EA370 003EA370 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EA374 003EA374 1000BFFF */  sd         $31, 0x10($29)
    /* 2EA378 003EA378 0000B07F */  sq         $16, 0x0($29)
    /* 2EA37C 003EA37C 0000828C */  lw         $2, 0x0($4)
    /* 2EA380 003EA380 01004230 */  andi       $2, $2, 0x1
    /* 2EA384 003EA384 03004010 */  beqz       $2, .L003EA394
    /* 2EA388 003EA388 2D808000 */   daddu     $16, $4, $0
    /* 2EA38C 003EA38C 44A90F0C */  jal        func_003ea510
    /* 2EA390 003EA390 00000000 */   nop
  .L003EA394:
    /* 2EA394 003EA394 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EA398 003EA398 2D280002 */  daddu      $5, $16, $0
    /* 2EA39C 003EA39C 088F0F0C */  jal        func_003e3c20
    /* 2EA3A0 003EA3A0 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EA3A4 003EA3A4 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EA3A8 003EA3A8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EA3AC 003EA3AC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EA3B0 003EA3B0 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EA3B4 003EA3B4 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EA3B8 003EA3B8 21186400 */  addu       $3, $3, $4
    /* 2EA3BC 003EA3BC 0000648C */  lw         $4, 0x0($3)
    /* 2EA3C0 003EA3C0 09F84000 */  jalr       $2
    /* 2EA3C4 003EA3C4 2D280002 */   daddu     $5, $16, $0
    /* 2EA3C8 003EA3C8 1000BFDF */  ld         $31, 0x10($29)
    /* 2EA3CC 003EA3CC 01000224 */  addiu      $2, $0, 0x1
    /* 2EA3D0 003EA3D0 0000B07B */  lq         $16, 0x0($29)
    /* 2EA3D4 003EA3D4 0800E003 */  jr         $31
    /* 2EA3D8 003EA3D8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EA3DC 003EA3DC 00000000 */  nop
.size func_003ea370, 0x70
