.section .text
.set noat
.set noreorder
glabel func_001f9fa0
    /* F9FA0 001F9FA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* F9FA4 001F9FA4 3000BFFF */  sd         $31, 0x30($29)
    /* F9FA8 001F9FA8 2000B27F */  sq         $18, 0x20($29)
    /* F9FAC 001F9FAC 1000B17F */  sq         $17, 0x10($29)
    /* F9FB0 001F9FB0 0000B07F */  sq         $16, 0x0($29)
    /* F9FB4 001F9FB4 01001124 */  addiu      $17, $0, 0x1
    /* F9FB8 001F9FB8 2D900000 */  daddu      $18, $0, $0
    /* F9FBC 001F9FBC 26000010 */  b          .L001FA058
    /* F9FC0 001F9FC0 00000000 */   nop
  .L001F9FC4:
    /* F9FC4 001F9FC4 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9FC8 001F9FC8 80101200 */  sll        $2, $18, 2
    /* F9FCC 001F9FCC 21106200 */  addu       $2, $3, $2
    /* F9FD0 001F9FD0 6C0B448C */  lw         $4, 0xB6C($2)
    /* F9FD4 001F9FD4 1F008010 */  beqz       $4, .L001FA054
    /* F9FD8 001F9FD8 00000000 */   nop
    /* F9FDC 001F9FDC F054110C */  jal        func_004553c0
    /* F9FE0 001F9FE0 00000000 */   nop
    /* F9FE4 001F9FE4 1A004010 */  beqz       $2, .L001FA050
    /* F9FE8 001F9FE8 00000000 */   nop
    /* F9FEC 001F9FEC ACB3838F */  lw         $3, -0x4C54($28)
    /* F9FF0 001F9FF0 4C0B628C */  lw         $2, 0xB4C($3)
    /* F9FF4 001F9FF4 01004230 */  andi       $2, $2, 0x1
    /* F9FF8 001F9FF8 0A004014 */  bnez       $2, .L001FA024
    /* F9FFC 001F9FFC 00000000 */   nop
    /* FA000 001FA000 80801200 */  sll        $16, $18, 2
    /* FA004 001FA004 21107000 */  addu       $2, $3, $16
    /* FA008 001FA008 6C0B428C */  lw         $2, 0xB6C($2)
    /* FA00C 001FA00C 1001448C */  lw         $4, 0x110($2)
    /* FA010 001FA010 EC12120C */  jal        func_00484bb0
    /* FA014 001FA014 00000000 */   nop
    /* FA018 001FA018 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA01C 001FA01C 21187000 */  addu       $3, $3, $16
    /* FA020 001FA020 5C0B62AC */  sw         $2, 0xB5C($3)
  .L001FA024:
    /* FA024 001FA024 80801200 */  sll        $16, $18, 2
    /* FA028 001FA028 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA02C 001FA02C 21105000 */  addu       $2, $2, $16
    /* FA030 001FA030 6C0B448C */  lw         $4, 0xB6C($2)
    /* FA034 001FA034 F452110C */  jal        func_00454bd0
    /* FA038 001FA038 00000000 */   nop
    /* FA03C 001FA03C ACB3828F */  lw         $2, -0x4C54($28)
    /* FA040 001FA040 21105000 */  addu       $2, $2, $16
    /* FA044 001FA044 6C0B40AC */  sw         $0, 0xB6C($2)
    /* FA048 001FA048 02000010 */  b          .L001FA054
    /* FA04C 001FA04C 00000000 */   nop
  .L001FA050:
    /* FA050 001FA050 2D880000 */  daddu      $17, $0, $0
  .L001FA054:
    /* FA054 001FA054 01005226 */  addiu      $18, $18, 0x1
  .L001FA058:
    /* FA058 001FA058 0400422A */  slti       $2, $18, 0x4
    /* FA05C 001FA05C D9FF4014 */  bnez       $2, .L001F9FC4
    /* FA060 001FA060 00000000 */   nop
    /* FA064 001FA064 21002012 */  beqz       $17, .L001FA0EC
    /* FA068 001FA068 00000000 */   nop
    /* FA06C 001FA06C ACB3828F */  lw         $2, -0x4C54($28)
    /* FA070 001FA070 580B448C */  lw         $4, 0xB58($2)
    /* FA074 001FA074 F054110C */  jal        func_004553c0
    /* FA078 001FA078 00000000 */   nop
    /* FA07C 001FA07C 1B004010 */  beqz       $2, .L001FA0EC
    /* FA080 001FA080 00000000 */   nop
    /* FA084 001FA084 ACB3858F */  lw         $5, -0x4C54($28)
    /* FA088 001FA088 4C0BA424 */  addiu      $4, $5, 0xB4C
    /* FA08C 001FA08C 4C0BA38C */  lw         $3, 0xB4C($5)
    /* FA090 001FA090 01006230 */  andi       $2, $3, 0x1
    /* FA094 001FA094 09004014 */  bnez       $2, .L001FA0BC
    /* FA098 001FA098 00000000 */   nop
    /* FA09C 001FA09C 580BA28C */  lw         $2, 0xB58($5)
    /* FA0A0 001FA0A0 1001448C */  lw         $4, 0x110($2)
    /* FA0A4 001FA0A4 EC12120C */  jal        func_00484bb0
    /* FA0A8 001FA0A8 00000000 */   nop
    /* FA0AC 001FA0AC ACB3838F */  lw         $3, -0x4C54($28)
    /* FA0B0 001FA0B0 540B62AC */  sw         $2, 0xB54($3)
    /* FA0B4 001FA0B4 04000010 */  b          .L001FA0C8
    /* FA0B8 001FA0B8 00000000 */   nop
  .L001FA0BC:
    /* FA0BC 001FA0BC FEFF0224 */  addiu      $2, $0, -0x2
    /* FA0C0 001FA0C0 24106200 */  and        $2, $3, $2
    /* FA0C4 001FA0C4 000082AC */  sw         $2, 0x0($4)
  .L001FA0C8:
    /* FA0C8 001FA0C8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA0CC 001FA0CC 580B448C */  lw         $4, 0xB58($2)
    /* FA0D0 001FA0D0 F452110C */  jal        func_00454bd0
    /* FA0D4 001FA0D4 00000000 */   nop
    /* FA0D8 001FA0D8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA0DC 001FA0DC 580B40AC */  sw         $0, 0xB58($2)
    /* FA0E0 001FA0E0 01000224 */  addiu      $2, $0, 0x1
    /* FA0E4 001FA0E4 02000010 */  b          .L001FA0F0
    /* FA0E8 001FA0E8 00000000 */   nop
  .L001FA0EC:
    /* FA0EC 001FA0EC 2D100000 */  daddu      $2, $0, $0
  .L001FA0F0:
    /* FA0F0 001FA0F0 3000BFDF */  ld         $31, 0x30($29)
    /* FA0F4 001FA0F4 2000B27B */  lq         $18, 0x20($29)
    /* FA0F8 001FA0F8 1000B17B */  lq         $17, 0x10($29)
    /* FA0FC 001FA0FC 0000B07B */  lq         $16, 0x0($29)
    /* FA100 001FA100 4000BD27 */  addiu      $29, $29, 0x40
    /* FA104 001FA104 0800E003 */  jr         $31
    /* FA108 001FA108 00000000 */   nop
    /* FA10C 001FA10C 00000000 */  nop
.size func_001f9fa0, 0x170
