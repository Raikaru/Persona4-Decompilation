.section .text
.set noat
.set noreorder
glabel func_003dd7d0
    /* 2DD7D0 003DD7D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DD7D4 003DD7D4 8800023C */  lui        $2, %hi(D_00887184)
    /* 2DD7D8 003DD7D8 0000BFFF */  sd         $31, 0x0($29)
    /* 2DD7DC 003DD7DC 8471438C */  lw         $3, %lo(D_00887184)($2)
    /* 2DD7E0 003DD7E0 0F006018 */  blez       $3, .L003DD820
    /* 2DD7E4 003DD7E4 00000000 */   nop
    /* 2DD7E8 003DD7E8 8800023C */  lui        $2, %hi(D_00887188)
    /* 2DD7EC 003DD7EC 8871428C */  lw         $2, %lo(D_00887188)($2)
    /* 2DD7F0 003DD7F0 01004224 */  addiu      $2, $2, 0x1
    /* 2DD7F4 003DD7F4 2A086200 */  slt        $1, $3, $2
    /* 2DD7F8 003DD7F8 09002010 */  beqz       $1, .L003DD820
    /* 2DD7FC 003DD7FC 00000000 */   nop
    /* 2DD800 003DD800 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DD804 003DD804 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DD808 003DD808 03004010 */  beqz       $2, .L003DD818
    /* 2DD80C 003DD80C 00000000 */   nop
    /* 2DD810 003DD810 09F84000 */  jalr       $2
    /* 2DD814 003DD814 05000424 */   addiu     $4, $0, 0x5
  .L003DD818:
    /* 2DD818 003DD818 02000010 */  b          .L003DD824
    /* 2DD81C 003DD81C 2D100000 */   daddu     $2, $0, $0
  .L003DD820:
    /* 2DD820 003DD820 01000224 */  addiu      $2, $0, 0x1
  .L003DD824:
    /* 2DD824 003DD824 0000BFDF */  ld         $31, 0x0($29)
    /* 2DD828 003DD828 0800E003 */  jr         $31
    /* 2DD82C 003DD82C 1000BD27 */   addiu     $29, $29, 0x10
.size func_003dd7d0, 0x60
