.section .text
.set noat
.set noreorder
glabel func_003dd5c0
    /* 2DD5C0 003DD5C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DD5C4 003DD5C4 02000324 */  addiu      $3, $0, 0x2
    /* 2DD5C8 003DD5C8 0D00A310 */  beq        $5, $3, .L003DD600
    /* 2DD5CC 003DD5CC 0000BFFF */   sd        $31, 0x0($29)
    /* 2DD5D0 003DD5D0 01000324 */  addiu      $3, $0, 0x1
    /* 2DD5D4 003DD5D4 0300A310 */  beq        $5, $3, .L003DD5E4
    /* 2DD5D8 003DD5D8 00000000 */   nop
    /* 2DD5DC 003DD5DC 0E000010 */  b          .L003DD618
    /* 2DD5E0 003DD5E0 0000BFDF */   ld        $31, 0x0($29)
  .L003DD5E4:
    /* 2DD5E4 003DD5E4 2000838C */  lw         $3, 0x20($4)
    /* 2DD5E8 003DD5E8 0A006010 */  beqz       $3, .L003DD614
    /* 2DD5EC 003DD5EC 00000000 */   nop
    /* 2DD5F0 003DD5F0 09F86000 */  jalr       $3
    /* 2DD5F4 003DD5F4 50008424 */   addiu     $4, $4, 0x50
    /* 2DD5F8 003DD5F8 06000010 */  b          .L003DD614
    /* 2DD5FC 003DD5FC 00000000 */   nop
  .L003DD600:
    /* 2DD600 003DD600 2400838C */  lw         $3, 0x24($4)
    /* 2DD604 003DD604 03006010 */  beqz       $3, .L003DD614
    /* 2DD608 003DD608 00000000 */   nop
    /* 2DD60C 003DD60C 09F86000 */  jalr       $3
    /* 2DD610 003DD610 50008424 */   addiu     $4, $4, 0x50
  .L003DD614:
    /* 2DD614 003DD614 0000BFDF */  ld         $31, 0x0($29)
  .L003DD618:
    /* 2DD618 003DD618 0800E003 */  jr         $31
    /* 2DD61C 003DD61C 1000BD27 */   addiu     $29, $29, 0x10
.size func_003dd5c0, 0x60
