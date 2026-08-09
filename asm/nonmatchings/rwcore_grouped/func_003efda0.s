.section .text
.set noat
.set noreorder
glabel func_003efda0
    /* 2EFDA0 003EFDA0 0400838C */  lw         $3, 0x4($4)
    /* 2EFDA4 003EFDA4 03006014 */  bnez       $3, .L003EFDB4
    /* 2EFDA8 003EFDA8 00000000 */   nop
  .L003EFDAC:
    /* 2EFDAC 003EFDAC 08000010 */  b          .L003EFDD0
    /* 2EFDB0 003EFDB0 00000000 */   nop
  .L003EFDB4:
    /* 2EFDB4 003EFDB4 0800858C */  lw         $5, 0x8($4)
    /* 2EFDB8 003EFDB8 0C00838C */  lw         $3, 0xC($4)
    /* 2EFDBC 003EFDBC 000065AC */  sw         $5, 0x0($3)
    /* 2EFDC0 003EFDC0 0C00858C */  lw         $5, 0xC($4)
    /* 2EFDC4 003EFDC4 0800838C */  lw         $3, 0x8($4)
    /* 2EFDC8 003EFDC8 F8FF0010 */  b          .L003EFDAC
    /* 2EFDCC 003EFDCC 040065AC */   sw        $5, 0x4($3)
  .L003EFDD0:
    /* 2EFDD0 003EFDD0 0800E003 */  jr         $31
    /* 2EFDD4 003EFDD4 00000000 */   nop
    /* 2EFDD8 003EFDD8 00000000 */  nop
    /* 2EFDDC 003EFDDC 00000000 */  nop
.size func_003efda0, 0x40
