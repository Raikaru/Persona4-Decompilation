.section .text
.set noat
.set noreorder
glabel func_002b32a0
    /* 1B32A0 002B32A0 2A108500 */  slt        $2, $4, $5
    /* 1B32A4 002B32A4 04004014 */  bnez       $2, .L002B32B8
    /* 1B32A8 002B32A8 00000000 */   nop
    /* 1B32AC 002B32AC 2D10A000 */  daddu      $2, $5, $0
    /* 1B32B0 002B32B0 05000010 */  b          .L002B32C8
    /* 1B32B4 002B32B4 00000000 */   nop
  .L002B32B8:
    /* 1B32B8 002B32B8 0200C014 */  bnez       $6, .L002B32C4
    /* 1B32BC 002B32BC 00000000 */   nop
    /* 1B32C0 002B32C0 2D380000 */  daddu      $7, $0, $0
  .L002B32C4:
    /* 1B32C4 002B32C4 2D10E000 */  daddu      $2, $7, $0
  .L002B32C8:
    /* 1B32C8 002B32C8 0800E003 */  jr         $31
    /* 1B32CC 002B32CC 00000000 */   nop
.size func_002b32a0, 0x30
