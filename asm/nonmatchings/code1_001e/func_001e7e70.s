.section .text
.set noat
.set noreorder
glabel func_001e7e70
    /* E7E70 001E7E70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E7E74 001E7E74 0000BFFF */  sd         $31, 0x0($29)
    /* E7E78 001E7E78 2D200000 */  daddu      $4, $0, $0
    /* E7E7C 001E7E7C 00730A0C */  jal        func_0029cc00
    /* E7E80 001E7E80 00000000 */   nop
    /* E7E84 001E7E84 3C210200 */  dsll32     $4, $2, 4
    /* E7E88 001E7E88 3E210400 */  dsrl32     $4, $4, 4
    /* E7E8C 001E7E8C 30C3060C */  jal        func_001b0cc0
    /* E7E90 001E7E90 00000000 */   nop
    /* E7E94 001E7E94 3000448C */  lw         $4, 0x30($2)
    /* E7E98 001E7E98 A2008290 */  lbu        $2, 0xA2($4)
    /* E7E9C 001E7E9C 09004014 */  bnez       $2, .L001E7EC4
    /* E7EA0 001E7EA0 00000000 */   nop
    /* E7EA4 001E7EA4 A4008394 */  lhu        $3, 0xA4($4)
    /* E7EA8 001E7EA8 01000224 */  addiu      $2, $0, 0x1
    /* E7EAC 001E7EAC 05006210 */  beq        $3, $2, .L001E7EC4
    /* E7EB0 001E7EB0 00000000 */   nop
    /* E7EB4 001E7EB4 640A828C */  lw         $2, 0xA64($4)
    /* E7EB8 001E7EB8 10004480 */  lb         $4, 0x10($2)
    /* E7EBC 001E7EBC 02000010 */  b          .L001E7EC8
    /* E7EC0 001E7EC0 00000000 */   nop
  .L001E7EC4:
    /* E7EC4 001E7EC4 FFFF0424 */  addiu      $4, $0, -0x1
  .L001E7EC8:
    /* E7EC8 001E7EC8 D4730A0C */  jal        func_0029cf50
    /* E7ECC 001E7ECC 00000000 */   nop
    /* E7ED0 001E7ED0 01000224 */  addiu      $2, $0, 0x1
    /* E7ED4 001E7ED4 0000BFDF */  ld         $31, 0x0($29)
    /* E7ED8 001E7ED8 1000BD27 */  addiu      $29, $29, 0x10
    /* E7EDC 001E7EDC 0800E003 */  jr         $31
    /* E7EE0 001E7EE0 00000000 */   nop
    /* E7EE4 001E7EE4 00000000 */  nop
    /* E7EE8 001E7EE8 00000000 */  nop
    /* E7EEC 001E7EEC 00000000 */  nop
.size func_001e7e70, 0x80
