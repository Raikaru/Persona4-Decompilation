.section .text
.set noat
.set noreorder
glabel func_0042daf8
    /* 32DAF8 0042DAF8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 32DAFC 0042DAFC 3000B3FF */  sd         $19, 0x30($29)
    /* 32DB00 0042DB00 2000B2FF */  sd         $18, 0x20($29)
    /* 32DB04 0042DB04 2D98C000 */  daddu      $19, $6, $0
    /* 32DB08 0042DB08 0000B0FF */  sd         $16, 0x0($29)
    /* 32DB0C 0042DB0C 2D90A000 */  daddu      $18, $5, $0
    /* 32DB10 0042DB10 4000BFFF */  sd         $31, 0x40($29)
    /* 32DB14 0042DB14 2D808000 */  daddu      $16, $4, $0
    /* 32DB18 0042DB18 08000106 */  bgez       $16, .L0042DB3C
    /* 32DB1C 0042DB1C 1000B1FF */   sd        $17, 0x10($29)
    /* 32DB20 0042DB20 FF7F023C */  lui        $2, (0x7FFFFFFF >> 16)
    /* 32DB24 0042DB24 8900033C */  lui        $3, %hi(D_00894A48)
    /* 32DB28 0042DB28 FFFF4234 */  ori        $2, $2, (0x7FFFFFFF & 0xFFFF)
    /* 32DB2C 0042DB2C 484A7124 */  addiu      $17, $3, %lo(D_00894A48)
    /* 32DB30 0042DB30 24800202 */  and        $16, $16, $2
    /* 32DB34 0042DB34 05000010 */  b          .L0042DB4C
    /* 32DB38 0042DB38 20000224 */   addiu     $2, $0, 0x20
  .L0042DB3C:
    /* 32DB3C 0042DB3C 7100023C */  lui        $2, %hi(D_0070DCB0)
    /* 32DB40 0042DB40 7100033C */  lui        $3, %hi(D_0070DCB4)
    /* 32DB44 0042DB44 B0DC518C */  lw         $17, %lo(D_0070DCB0)($2)
    /* 32DB48 0042DB48 B4DC628C */  lw         $2, %lo(D_0070DCB4)($3)
  .L0042DB4C:
    /* 32DB4C 0042DB4C 2B100202 */  sltu       $2, $16, $2
    /* 32DB50 0042DB50 04004014 */  bnez       $2, .L0042DB64
    /* 32DB54 0042DB54 00000000 */   nop
    /* 32DB58 0042DB58 0080023C */  lui        $2, (0x80000069 >> 16)
    /* 32DB5C 0042DB5C 0D000010 */  b          .L0042DB94
    /* 32DB60 0042DB60 69004234 */   ori       $2, $2, (0x80000069 & 0xFFFF)
  .L0042DB64:
    /* 32DB64 0042DB64 88AE100C */  jal        func_0042ba20
    /* 32DB68 0042DB68 00000000 */   nop
    /* 32DB6C 0042DB6C 00191000 */  sll        $3, $16, 4
    /* 32DB70 0042DB70 21187100 */  addu       $3, $3, $17
    /* 32DB74 0042DB74 000072AC */  sw         $18, 0x0($3)
    /* 32DB78 0042DB78 040073AC */  sw         $19, 0x4($3)
    /* 32DB7C 0042DB7C 2D208003 */  daddu      $4, $28, $0
    /* 32DB80 0042DB80 03004010 */  beqz       $2, .L0042DB90
    /* 32DB84 0042DB84 080064AC */   sw        $4, 0x8($3)
    /* 32DB88 0042DB88 9CAE100C */  jal        func_0042ba70
    /* 32DB8C 0042DB8C 00000000 */   nop
  .L0042DB90:
    /* 32DB90 0042DB90 2D100000 */  daddu      $2, $0, $0
  .L0042DB94:
    /* 32DB94 0042DB94 4000BFDF */  ld         $31, 0x40($29)
    /* 32DB98 0042DB98 3000B3DF */  ld         $19, 0x30($29)
    /* 32DB9C 0042DB9C 2000B2DF */  ld         $18, 0x20($29)
    /* 32DBA0 0042DBA0 1000B1DF */  ld         $17, 0x10($29)
    /* 32DBA4 0042DBA4 0000B0DF */  ld         $16, 0x0($29)
    /* 32DBA8 0042DBA8 0800E003 */  jr         $31
    /* 32DBAC 0042DBAC 5000BD27 */   addiu     $29, $29, 0x50
.size func_0042daf8, 0xb8
