.section .text
.set noat
.set noreorder
glabel func_004ea690
    /* 3EA690 004EA690 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA694 004EA694 2D180000 */  daddu      $3, $0, $0
    /* 3EA698 004EA698 0000BFFF */  sd         $31, 0x0($29)
    /* 3EA69C 004EA69C 18008010 */  beqz       $4, .L004EA700
    /* 3EA6A0 004EA6A0 2D100000 */   daddu     $2, $0, $0
    /* 3EA6A4 004EA6A4 CB000224 */  addiu      $2, $0, 0xCB
    /* 3EA6A8 004EA6A8 1100A210 */  beq        $5, $2, .L004EA6F0
    /* 3EA6AC 004EA6AC CC00A228 */   slti      $2, $5, 0xCC
    /* 3EA6B0 004EA6B0 07004010 */  beqz       $2, .L004EA6D0
    /* 3EA6B4 004EA6B4 CD000224 */   addiu     $2, $0, 0xCD
    /* 3EA6B8 004EA6B8 C9000224 */  addiu      $2, $0, 0xC9
    /* 3EA6BC 004EA6BC 0800A210 */  beq        $5, $2, .L004EA6E0
    /* 3EA6C0 004EA6C0 2D106000 */   daddu     $2, $3, $0
    /* 3EA6C4 004EA6C4 0F000010 */  b          .L004EA704
    /* 3EA6C8 004EA6C8 0000BFDF */   ld        $31, 0x0($29)
    /* 3EA6CC 004EA6CC 00000000 */  nop
  .L004EA6D0:
    /* 3EA6D0 004EA6D0 0700A210 */  beq        $5, $2, .L004EA6F0
    /* 3EA6D4 004EA6D4 2D106000 */   daddu     $2, $3, $0
    /* 3EA6D8 004EA6D8 0A000010 */  b          .L004EA704
    /* 3EA6DC 004EA6DC 0000BFDF */   ld        $31, 0x0($29)
  .L004EA6E0:
    /* 3EA6E0 004EA6E0 74A9130C */  jal        func_004ea5d0
    /* 3EA6E4 004EA6E4 00000000 */   nop
    /* 3EA6E8 004EA6E8 04000010 */  b          .L004EA6FC
    /* 3EA6EC 004EA6EC 2D184000 */   daddu     $3, $2, $0
  .L004EA6F0:
    /* 3EA6F0 004EA6F0 08A8130C */  jal        func_004ea020
    /* 3EA6F4 004EA6F4 00000000 */   nop
    /* 3EA6F8 004EA6F8 2D184000 */  daddu      $3, $2, $0
  .L004EA6FC:
    /* 3EA6FC 004EA6FC 2D106000 */  daddu      $2, $3, $0
  .L004EA700:
    /* 3EA700 004EA700 0000BFDF */  ld         $31, 0x0($29)
  .L004EA704:
    /* 3EA704 004EA704 0800E003 */  jr         $31
    /* 3EA708 004EA708 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA70C 004EA70C 00000000 */  nop
.size func_004ea690, 0x80
