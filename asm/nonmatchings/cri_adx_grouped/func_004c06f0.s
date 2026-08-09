.section .text
.set noat
.set noreorder
glabel func_004c06f0
    /* 3C06F0 004C06F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C06F4 004C06F4 04008010 */  beqz       $4, .L004C0708
    /* 3C06F8 004C06F8 0000BFFF */   sd        $31, 0x0($29)
    /* 3C06FC 004C06FC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C0700 004C0700 82031308 */  j          func_004c0e08
    /* 3C0704 004C0704 1000BD27 */   addiu     $29, $29, 0x10
  .L004C0708:
    /* 3C0708 004C0708 0000BFDF */  ld         $31, 0x0($29)
    /* 3C070C 004C070C 0800E003 */  jr         $31
    /* 3C0710 004C0710 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C0714 004C0714 00000000 */  nop
.size func_004c06f0, 0x28
