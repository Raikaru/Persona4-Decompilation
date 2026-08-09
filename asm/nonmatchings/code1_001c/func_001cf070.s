.section .text
.set noat
.set noreorder
glabel func_001cf070
    /* CF070 001CF070 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CF074 001CF074 1000BFFF */  sd         $31, 0x10($29)
    /* CF078 001CF078 0000B07F */  sq         $16, 0x0($29)
    /* CF07C 001CF07C 2D808000 */  daddu      $16, $4, $0
    /* CF080 001CF080 E000828C */  lw         $2, 0xE0($4)
    /* CF084 001CF084 48044384 */  lh         $3, 0x448($2)
    /* CF088 001CF088 14006010 */  beqz       $3, .L001CF0DC
    /* CF08C 001CF08C 00000000 */   nop
    /* CF090 001CF090 01000224 */  addiu      $2, $0, 0x1
    /* CF094 001CF094 03006210 */  beq        $3, $2, .L001CF0A4
    /* CF098 001CF098 00000000 */   nop
    /* CF09C 001CF09C 1B000010 */  b          .L001CF10C
    /* CF0A0 001CF0A0 00000000 */   nop
  .L001CF0A4:
    /* CF0A4 001CF0A4 2D200000 */  daddu      $4, $0, $0
    /* CF0A8 001CF0A8 14F4120C */  jal        func_004bd050
    /* CF0AC 001CF0AC 00000000 */   nop
    /* CF0B0 001CF0B0 01004330 */  andi       $3, $2, 0x1
    /* CF0B4 001CF0B4 00110300 */  sll        $2, $3, 4
    /* CF0B8 001CF0B8 23104300 */  subu       $2, $2, $3
    /* CF0BC 001CF0BC 80100200 */  sll        $2, $2, 2
    /* CF0C0 001CF0C0 21104300 */  addu       $2, $2, $3
    /* CF0C4 001CF0C4 80180200 */  sll        $3, $2, 2
    /* CF0C8 001CF0C8 5F00023C */  lui        $2, %hi(D_005F78C0)
    /* CF0CC 001CF0CC C0784224 */  addiu      $2, $2, %lo(D_005F78C0)
    /* CF0D0 001CF0D0 21284300 */  addu       $5, $2, $3
    /* CF0D4 001CF0D4 0D000010 */  b          .L001CF10C
    /* CF0D8 001CF0D8 00000000 */   nop
  .L001CF0DC:
    /* CF0DC 001CF0DC 2D200000 */  daddu      $4, $0, $0
    /* CF0E0 001CF0E0 14F4120C */  jal        func_004bd050
    /* CF0E4 001CF0E4 00000000 */   nop
    /* CF0E8 001CF0E8 01004330 */  andi       $3, $2, 0x1
    /* CF0EC 001CF0EC 00110300 */  sll        $2, $3, 4
    /* CF0F0 001CF0F0 23104300 */  subu       $2, $2, $3
    /* CF0F4 001CF0F4 80100200 */  sll        $2, $2, 2
    /* CF0F8 001CF0F8 21104300 */  addu       $2, $2, $3
    /* CF0FC 001CF0FC 80180200 */  sll        $3, $2, 2
    /* CF100 001CF100 5F00023C */  lui        $2, %hi(D_005F7AB0)
    /* CF104 001CF104 B07A4224 */  addiu      $2, $2, %lo(D_005F7AB0)
    /* CF108 001CF108 21284300 */  addu       $5, $2, $3
  .L001CF10C:
    /* CF10C 001CF10C 2D200002 */  daddu      $4, $16, $0
    /* CF110 001CF110 02000624 */  addiu      $6, $0, 0x2
    /* CF114 001CF114 60F7060C */  jal        func_001bdd80
    /* CF118 001CF118 00000000 */   nop
    /* CF11C 001CF11C 05000424 */  addiu      $4, $0, 0x5
    /* CF120 001CF120 44CC120C */  jal        func_004b3110
    /* CF124 001CF124 00000000 */   nop
    /* CF128 001CF128 1000BFDF */  ld         $31, 0x10($29)
    /* CF12C 001CF12C 0000B07B */  lq         $16, 0x0($29)
    /* CF130 001CF130 2000BD27 */  addiu      $29, $29, 0x20
    /* CF134 001CF134 0800E003 */  jr         $31
    /* CF138 001CF138 00000000 */   nop
    /* CF13C 001CF13C 00000000 */  nop
.size func_001cf070, 0xd0
