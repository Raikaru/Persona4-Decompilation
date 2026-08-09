.section .text
.set noat
.set noreorder
glabel func_003df550
    /* 2DF550 003DF550 60B7858F */  lw         $5, -0x48A0($28)
    /* 2DF554 003DF554 8800063C */  lui        $6, %hi(D_008872E0)
    /* 2DF558 003DF558 E072C624 */  addiu      $6, $6, %lo(D_008872E0)
    /* 2DF55C 003DF55C 2D108000 */  daddu      $2, $4, $0
    /* 2DF560 003DF560 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 2DF564 003DF564 2128C500 */  addu       $5, $6, $5
    /* 2DF568 003DF568 0000A1C4 */  lwc1       $f1, 0x0($5)
    /* 2DF56C 003DF56C 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2DF570 003DF570 000081E4 */  swc1       $f1, 0x0($4)
    /* 2DF574 003DF574 040080E4 */  swc1       $f0, 0x4($4)
    /* 2DF578 003DF578 60B7848F */  lw         $4, -0x48A0($28)
    /* 2DF57C 003DF57C 2120C400 */  addu       $4, $6, $4
    /* 2DF580 003DF580 000080AC */  sw         $0, 0x0($4)
    /* 2DF584 003DF584 0800E003 */  jr         $31
    /* 2DF588 003DF588 040083AC */   sw        $3, 0x4($4)
    /* 2DF58C 003DF58C 00000000 */  nop
.size func_003df550, 0x40
