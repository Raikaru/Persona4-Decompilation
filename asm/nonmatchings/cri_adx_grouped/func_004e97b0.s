.section .text
.set noat
.set noreorder
glabel func_004e97b0
    /* 3E97B0 004E97B0 7300023C */  lui        $2, %hi(D_007344B8)
    /* 3E97B4 004E97B4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E97B8 004E97B8 B844468C */  lw         $6, %lo(D_007344B8)($2)
    /* 3E97BC 004E97BC 0600C010 */  beqz       $6, .L004E97D8
    /* 3E97C0 004E97C0 0000BFFF */   sd        $31, 0x0($29)
    /* 3E97C4 004E97C4 7300023C */  lui        $2, %hi(D_007344BC)
    /* 3E97C8 004E97C8 7300033C */  lui        $3, %hi(D_007344C0)
    /* 3E97CC 004E97CC BC44448C */  lw         $4, %lo(D_007344BC)($2)
    /* 3E97D0 004E97D0 09F8C000 */  jalr       $6
    /* 3E97D4 004E97D4 C044658C */   lw        $5, %lo(D_007344C0)($3)
  .L004E97D8:
    /* 3E97D8 004E97D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E97DC 004E97DC 0800E003 */  jr         $31
    /* 3E97E0 004E97E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E97E4 004E97E4 00000000 */  nop
.size func_004e97b0, 0x38
