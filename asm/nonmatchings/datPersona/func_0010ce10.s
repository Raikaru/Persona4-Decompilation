.section .text
.set noat
.set noreorder
glabel func_0010ce10
    /* CE10 0010CE10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CE14 0010CE14 2000BFFF */  sd         $31, 0x20($29)
    /* CE18 0010CE18 1000B17F */  sq         $17, 0x10($29)
    /* CE1C 0010CE1C 0000B07F */  sq         $16, 0x0($29)
    /* CE20 0010CE20 2D808000 */  daddu      $16, $4, $0
    /* CE24 0010CE24 2D88A000 */  daddu      $17, $5, $0
    /* CE28 0010CE28 04000012 */  beqz       $16, .L0010CE3C
    /* CE2C 0010CE2C 00000000 */   nop
    /* CE30 0010CE30 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* CE34 0010CE34 06004014 */  bnez       $2, .L0010CE50
    /* CE38 0010CE38 00000000 */   nop
  .L0010CE3C:
    /* CE3C 0010CE3C 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CE40 0010CE40 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CE44 0010CE44 0A070524 */  addiu      $5, $0, 0x70A
    /* CE48 0010CE48 CCB5110C */  jal        func_0046d730
    /* CE4C 0010CE4C 00000000 */   nop
  .L0010CE50:
    /* CE50 0010CE50 2D100000 */  daddu      $2, $0, $0
    /* CE54 0010CE54 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* CE58 0010CE58 09000010 */  b          .L0010CE80
    /* CE5C 0010CE5C 00000000 */   nop
  .L0010CE60:
    /* CE60 0010CE60 40180200 */  sll        $3, $2, 1
    /* CE64 0010CE64 21180302 */  addu       $3, $16, $3
    /* CE68 0010CE68 0C006394 */  lhu        $3, 0xC($3)
    /* CE6C 0010CE6C 03006414 */  bne        $3, $4, .L0010CE7C
    /* CE70 0010CE70 00000000 */   nop
    /* CE74 0010CE74 06000010 */  b          .L0010CE90
    /* CE78 0010CE78 00000000 */   nop
  .L0010CE7C:
    /* CE7C 0010CE7C 01004224 */  addiu      $2, $2, 0x1
  .L0010CE80:
    /* CE80 0010CE80 08004328 */  slti       $3, $2, 0x8
    /* CE84 0010CE84 F6FF6014 */  bnez       $3, .L0010CE60
    /* CE88 0010CE88 00000000 */   nop
    /* CE8C 0010CE8C FFFF0224 */  addiu      $2, $0, -0x1
  .L0010CE90:
    /* CE90 0010CE90 2000BFDF */  ld         $31, 0x20($29)
    /* CE94 0010CE94 1000B17B */  lq         $17, 0x10($29)
    /* CE98 0010CE98 0000B07B */  lq         $16, 0x0($29)
    /* CE9C 0010CE9C 3000BD27 */  addiu      $29, $29, 0x30
    /* CEA0 0010CEA0 0800E003 */  jr         $31
    /* CEA4 0010CEA4 00000000 */   nop
    /* CEA8 0010CEA8 00000000 */  nop
    /* CEAC 0010CEAC 00000000 */  nop
.size func_0010ce10, 0xa0
