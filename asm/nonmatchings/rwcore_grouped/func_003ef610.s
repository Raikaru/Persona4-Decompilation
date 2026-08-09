.section .text
.set noat
.set noreorder
glabel func_003ef610
    /* 2EF610 003EF610 0400828C */  lw         $2, 0x4($4)
    /* 2EF614 003EF614 03004014 */  bnez       $2, .L003EF624
    /* 2EF618 003EF618 00000000 */   nop
  .L003EF61C:
    /* 2EF61C 003EF61C 09000010 */  b          .L003EF644
    /* 2EF620 003EF620 2D108000 */   daddu     $2, $4, $0
  .L003EF624:
    /* 2EF624 003EF624 040080AC */  sw         $0, 0x4($4)
    /* 2EF628 003EF628 0800838C */  lw         $3, 0x8($4)
    /* 2EF62C 003EF62C 0C00828C */  lw         $2, 0xC($4)
    /* 2EF630 003EF630 000043AC */  sw         $3, 0x0($2)
    /* 2EF634 003EF634 0C00838C */  lw         $3, 0xC($4)
    /* 2EF638 003EF638 0800828C */  lw         $2, 0x8($4)
    /* 2EF63C 003EF63C F7FF0010 */  b          .L003EF61C
    /* 2EF640 003EF640 040043AC */   sw        $3, 0x4($2)
  .L003EF644:
    /* 2EF644 003EF644 0800E003 */  jr         $31
    /* 2EF648 003EF648 00000000 */   nop
    /* 2EF64C 003EF64C 00000000 */  nop
.size func_003ef610, 0x40
