.section .text
.set noat
.set noreorder
glabel func_003cb250
    /* 2CB250 003CB250 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2CB254 003CB254 4000BFFF */  sd         $31, 0x40($29)
    /* 2CB258 003CB258 3000B37F */  sq         $19, 0x30($29)
    /* 2CB25C 003CB25C 2000B27F */  sq         $18, 0x20($29)
    /* 2CB260 003CB260 2D988000 */  daddu      $19, $4, $0
    /* 2CB264 003CB264 1000B17F */  sq         $17, 0x10($29)
    /* 2CB268 003CB268 0000B07F */  sq         $16, 0x0($29)
    /* 2CB26C 003CB26C 2C007126 */  addiu      $17, $19, 0x2C
    /* 2CB270 003CB270 2C00928C */  lw         $18, 0x2C($4)
    /* 2CB274 003CB274 1A005112 */  beq        $18, $17, .L003CB2E0
    /* 2CB278 003CB278 00000000 */   nop
    /* 2CB27C 003CB27C 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2CB280 003CB280 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
  .L003CB284:
    /* 2CB284 003CB284 F4FF4526 */  addiu      $5, $18, -0xC
    /* 2CB288 003CB288 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CB28C 003CB28C 0000528E */  lw         $18, 0x0($18)
    /* 2CB290 003CB290 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CB294 003CB294 0C00A48C */  lw         $4, 0xC($5)
    /* 2CB298 003CB298 1000A28C */  lw         $2, 0x10($5)
    /* 2CB29C 003CB29C 000044AC */  sw         $4, 0x0($2)
    /* 2CB2A0 003CB2A0 1000A48C */  lw         $4, 0x10($5)
    /* 2CB2A4 003CB2A4 0C00A28C */  lw         $2, 0xC($5)
    /* 2CB2A8 003CB2A8 040044AC */  sw         $4, 0x4($2)
    /* 2CB2AC 003CB2AC 0000A48C */  lw         $4, 0x0($5)
    /* 2CB2B0 003CB2B0 0400A28C */  lw         $2, 0x4($5)
    /* 2CB2B4 003CB2B4 000044AC */  sw         $4, 0x0($2)
    /* 2CB2B8 003CB2B8 0400A48C */  lw         $4, 0x4($5)
    /* 2CB2BC 003CB2BC 0000A28C */  lw         $2, 0x0($5)
    /* 2CB2C0 003CB2C0 040044AC */  sw         $4, 0x4($2)
    /* 2CB2C4 003CB2C4 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CB2C8 003CB2C8 0000028E */  lw         $2, 0x0($16)
    /* 2CB2CC 003CB2CC 21186400 */  addu       $3, $3, $4
    /* 2CB2D0 003CB2D0 09F84000 */  jalr       $2
    /* 2CB2D4 003CB2D4 0400648C */   lw        $4, 0x4($3)
    /* 2CB2D8 003CB2D8 EAFF5116 */  bne        $18, $17, .L003CB284
    /* 2CB2DC 003CB2DC 00000000 */   nop
  .L003CB2E0:
    /* 2CB2E0 003CB2E0 2D106002 */  daddu      $2, $19, $0
    /* 2CB2E4 003CB2E4 4000BFDF */  ld         $31, 0x40($29)
    /* 2CB2E8 003CB2E8 3000B37B */  lq         $19, 0x30($29)
    /* 2CB2EC 003CB2EC 2000B27B */  lq         $18, 0x20($29)
    /* 2CB2F0 003CB2F0 1000B17B */  lq         $17, 0x10($29)
    /* 2CB2F4 003CB2F4 0000B07B */  lq         $16, 0x0($29)
    /* 2CB2F8 003CB2F8 0800E003 */  jr         $31
    /* 2CB2FC 003CB2FC 5000BD27 */   addiu     $29, $29, 0x50
.size func_003cb250, 0xb0
