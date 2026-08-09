.section .text
.set noat
.set noreorder
glabel func_003bb030
    /* 2BB030 003BB030 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BB034 003BB034 4000BFFF */  sd         $31, 0x40($29)
    /* 2BB038 003BB038 3000B37F */  sq         $19, 0x30($29)
    /* 2BB03C 003BB03C 2000B27F */  sq         $18, 0x20($29)
    /* 2BB040 003BB040 1000B17F */  sq         $17, 0x10($29)
    /* 2BB044 003BB044 0000B07F */  sq         $16, 0x0($29)
    /* 2BB048 003BB048 54B6828F */  lw         $2, -0x49AC($28)
    /* 2BB04C 003BB04C 2D808000 */  daddu      $16, $4, $0
    /* 2BB050 003BB050 FFFF4224 */  addiu      $2, $2, -0x1
    /* 2BB054 003BB054 03004010 */  beqz       $2, .L003BB064
    /* 2BB058 003BB058 54B682AF */   sw        $2, -0x49AC($28)
  .L003BB05C:
    /* 2BB05C 003BB05C 13000010 */  b          .L003BB0AC
    /* 2BB060 003BB060 2D100002 */   daddu     $2, $16, $0
  .L003BB064:
    /* 2BB064 003BB064 8800123C */  lui        $18, %hi(D_008864E8)
    /* 2BB068 003BB068 8800113C */  lui        $17, %hi(jtbl_008873EC)
    /* 2BB06C 003BB06C 0A001324 */  addiu      $19, $0, 0xA
    /* 2BB070 003BB070 E8645226 */  addiu      $18, $18, %lo(D_008864E8)
    /* 2BB074 003BB074 EC733126 */  addiu      $17, $17, %lo(jtbl_008873EC)
  .L003BB078:
    /* 2BB078 003BB078 0000228E */  lw         $2, 0x0($17)
    /* 2BB07C 003BB07C 09F84000 */  jalr       $2
    /* 2BB080 003BB080 0000448E */   lw        $4, 0x0($18)
    /* 2BB084 003BB084 FFFF7326 */  addiu      $19, $19, -0x1
    /* 2BB088 003BB088 000040AE */  sw         $0, 0x0($18)
    /* 2BB08C 003BB08C 0400612A */  slti       $1, $19, 0x4
    /* 2BB090 003BB090 F9FF2010 */  beqz       $1, .L003BB078
    /* 2BB094 003BB094 FCFF5226 */   addiu     $18, $18, -0x4
    /* 2BB098 003BB098 0000228E */  lw         $2, 0x0($17)
    /* 2BB09C 003BB09C 09F84000 */  jalr       $2
    /* 2BB0A0 003BB0A0 1CB6848F */   lw        $4, -0x49E4($28)
    /* 2BB0A4 003BB0A4 EDFF0010 */  b          .L003BB05C
    /* 2BB0A8 003BB0A8 1CB680AF */   sw        $0, -0x49E4($28)
  .L003BB0AC:
    /* 2BB0AC 003BB0AC 4000BFDF */  ld         $31, 0x40($29)
    /* 2BB0B0 003BB0B0 3000B37B */  lq         $19, 0x30($29)
    /* 2BB0B4 003BB0B4 2000B27B */  lq         $18, 0x20($29)
    /* 2BB0B8 003BB0B8 1000B17B */  lq         $17, 0x10($29)
    /* 2BB0BC 003BB0BC 0000B07B */  lq         $16, 0x0($29)
    /* 2BB0C0 003BB0C0 0800E003 */  jr         $31
    /* 2BB0C4 003BB0C4 5000BD27 */   addiu     $29, $29, 0x50
    /* 2BB0C8 003BB0C8 00000000 */  nop
    /* 2BB0CC 003BB0CC 00000000 */  nop
.size func_003bb030, 0xa0
