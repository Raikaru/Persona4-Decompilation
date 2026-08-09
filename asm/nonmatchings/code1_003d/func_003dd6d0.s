.section .text
.set noat
.set noreorder
glabel func_003dd6d0
    /* 2DD6D0 003DD6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DD6D4 003DD6D4 1C008010 */  beqz       $4, .L003DD748
    /* 2DD6D8 003DD6D8 0000BFFF */   sd        $31, 0x0($29)
    /* 2DD6DC 003DD6DC 3000838C */  lw         $3, 0x30($4)
    /* 2DD6E0 003DD6E0 19006010 */  beqz       $3, .L003DD748
    /* 2DD6E4 003DD6E4 00000000 */   nop
    /* 2DD6E8 003DD6E8 4000878C */  lw         $7, 0x40($4)
    /* 2DD6EC 003DD6EC 01000324 */  addiu      $3, $0, 0x1
    /* 2DD6F0 003DD6F0 1200E310 */  beq        $7, $3, .L003DD73C
    /* 2DD6F4 003DD6F4 00000000 */   nop
    /* 2DD6F8 003DD6F8 4800838C */  lw         $3, 0x48($4)
    /* 2DD6FC 003DD6FC 0F006010 */  beqz       $3, .L003DD73C
    /* 2DD700 003DD700 00000000 */   nop
    /* 2DD704 003DD704 04000224 */  addiu      $2, $0, 0x4
    /* 2DD708 003DD708 0300E214 */  bne        $7, $2, .L003DD718
    /* 2DD70C 003DD70C 00000000 */   nop
    /* 2DD710 003DD710 02000010 */  b          .L003DD71C
    /* 2DD714 003DD714 1000858C */   lw        $5, 0x10($4)
  .L003DD718:
    /* 2DD718 003DD718 4400858C */  lw         $5, 0x44($4)
  .L003DD71C:
    /* 2DD71C 003DD71C 01000224 */  addiu      $2, $0, 0x1
    /* 2DD720 003DD720 400082AC */  sw         $2, 0x40($4)
    /* 2DD724 003DD724 4C00888C */  lw         $8, 0x4C($4)
    /* 2DD728 003DD728 4800828C */  lw         $2, 0x48($4)
    /* 2DD72C 003DD72C 09F84000 */  jalr       $2
    /* 2DD730 003DD730 3800868C */   lw        $6, 0x38($4)
  .L003DD734:
    /* 2DD734 003DD734 05000010 */  b          .L003DD74C
    /* 2DD738 003DD738 0000BFDF */   ld        $31, 0x0($29)
  .L003DD73C:
    /* 2DD73C 003DD73C 01000324 */  addiu      $3, $0, 0x1
    /* 2DD740 003DD740 FCFF0010 */  b          .L003DD734
    /* 2DD744 003DD744 400083AC */   sw        $3, 0x40($4)
  .L003DD748:
    /* 2DD748 003DD748 0000BFDF */  ld         $31, 0x0($29)
  .L003DD74C:
    /* 2DD74C 003DD74C 0800E003 */  jr         $31
    /* 2DD750 003DD750 1000BD27 */   addiu     $29, $29, 0x10
    /* 2DD754 003DD754 00000000 */  nop
    /* 2DD758 003DD758 00000000 */  nop
    /* 2DD75C 003DD75C 00000000 */  nop
.size func_003dd6d0, 0x90
