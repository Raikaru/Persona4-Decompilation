.section .text
.set noat
.set noreorder
glabel func_004f51a8
    /* 3F51A8 004F51A8 7400023C */  lui        $2, %hi(D_00743A50)
    /* 3F51AC 004F51AC 503A428C */  lw         $2, %lo(D_00743A50)($2)
    /* 3F51B0 004F51B0 03004010 */  beqz       $2, .L004F51C0
    /* 3F51B4 004F51B4 00000000 */   nop
    /* 3F51B8 004F51B8 440045AC */  sw         $5, 0x44($2)
    /* 3F51BC 004F51BC 400044AC */  sw         $4, 0x40($2)
  .L004F51C0:
    /* 3F51C0 004F51C0 0800E003 */  jr         $31
    /* 3F51C4 004F51C4 00000000 */   nop
.size func_004f51a8, 0x20
