.section .text
.set noat
.set noreorder
glabel func_001bdd30
    /* BDD30 001BDD30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* BDD34 001BDD34 0000BFFF */  sd         $31, 0x0($29)
    /* BDD38 001BDD38 ACB3838F */  lw         $3, -0x4C54($28)
    /* BDD3C 001BDD3C BC00648C */  lw         $4, 0xBC($3)
    /* BDD40 001BDD40 03008010 */  beqz       $4, .L001BDD50
    /* BDD44 001BDD44 00000000 */   nop
    /* BDD48 001BDD48 D8EE0E0C */  jal        func_003bbb60
    /* BDD4C 001BDD4C 00000000 */   nop
  .L001BDD50:
    /* BDD50 001BDD50 0000BFDF */  ld         $31, 0x0($29)
    /* BDD54 001BDD54 1000BD27 */  addiu      $29, $29, 0x10
    /* BDD58 001BDD58 0800E003 */  jr         $31
    /* BDD5C 001BDD5C 00000000 */   nop
.size func_001bdd30, 0x30
