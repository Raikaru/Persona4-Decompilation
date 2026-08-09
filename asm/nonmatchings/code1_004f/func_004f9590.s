.section .text
.set noat
.set noreorder
glabel func_004f9590
    /* 3F9590 004F9590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9594 004F9594 2D10A000 */  daddu      $2, $5, $0
    /* 3F9598 004F9598 0000BFFF */  sd         $31, 0x0($29)
    /* 3F959C 004F959C 2D18C000 */  daddu      $3, $6, $0
    /* 3F95A0 004F95A0 2D50E000 */  daddu      $10, $7, $0
    /* 3F95A4 004F95A4 2D580001 */  daddu      $11, $8, $0
    /* 3F95A8 004F95A8 0B008010 */  beqz       $4, .L004F95D8
    /* 3F95AC 004F95AC 2D602001 */   daddu     $12, $9, $0
    /* 3F95B0 004F95B0 0D004204 */  bltzl      $2, .L004F95E8
    /* 3F95B4 004F95B4 9CFF0224 */   addiu     $2, $0, -0x64
    /* 3F95B8 004F95B8 0B006004 */  bltz       $3, .L004F95E8
    /* 3F95BC 004F95BC 9CFF0224 */   addiu     $2, $0, -0x64
    /* 3F95C0 004F95C0 09004005 */  bltz       $10, .L004F95E8
    /* 3F95C4 004F95C4 00000000 */   nop
    /* 3F95C8 004F95C8 08006011 */  beqz       $11, .L004F95EC
    /* 3F95CC 004F95CC 0000BFDF */   ld        $31, 0x0($29)
    /* 3F95D0 004F95D0 03008105 */  bgez       $12, .L004F95E0
    /* 3F95D4 004F95D4 00000000 */   nop
  .L004F95D8:
    /* 3F95D8 004F95D8 03000010 */  b          .L004F95E8
    /* 3F95DC 004F95DC 9CFF0224 */   addiu     $2, $0, -0x64
  .L004F95E0:
    /* 3F95E0 004F95E0 D4E4130C */  jal        func_004f9350
    /* 3F95E4 004F95E4 00000000 */   nop
  .L004F95E8:
    /* 3F95E8 004F95E8 0000BFDF */  ld         $31, 0x0($29)
  .L004F95EC:
    /* 3F95EC 004F95EC 0800E003 */  jr         $31
    /* 3F95F0 004F95F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F95F4 004F95F4 00000000 */  nop
.size func_004f9590, 0x68
