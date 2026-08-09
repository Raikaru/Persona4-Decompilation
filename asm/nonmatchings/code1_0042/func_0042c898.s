.section .text
.set noat
.set noreorder
glabel func_0042c898
    /* 32C898 0042C898 0400828C */  lw         $2, 0x4($4)
    /* 32C89C 0042C89C 03004010 */  beqz       $2, .L0042C8AC
    /* 32C8A0 0042C8A0 0000838C */   lw        $3, 0x0($4)
    /* 32C8A4 0042C8A4 03000010 */  b          .L0042C8B4
    /* 32C8A8 0042C8A8 000043AC */   sw        $3, 0x0($2)
  .L0042C8AC:
    /* 32C8AC 0042C8AC 7100023C */  lui        $2, %hi(D_0070DCA0)
    /* 32C8B0 0042C8B0 A0DC43AC */  sw         $3, %lo(D_0070DCA0)($2)
  .L0042C8B4:
    /* 32C8B4 0042C8B4 04006050 */  beql       $3, $0, .L0042C8C8
    /* 32C8B8 0042C8B8 040080AC */   sw        $0, 0x4($4)
    /* 32C8BC 0042C8BC 0400828C */  lw         $2, 0x4($4)
    /* 32C8C0 0042C8C0 040062AC */  sw         $2, 0x4($3)
    /* 32C8C4 0042C8C4 040080AC */  sw         $0, 0x4($4)
  .L0042C8C8:
    /* 32C8C8 0042C8C8 0800E003 */  jr         $31
    /* 32C8CC 0042C8CC 2D106000 */   daddu     $2, $3, $0
.size func_0042c898, 0x38
