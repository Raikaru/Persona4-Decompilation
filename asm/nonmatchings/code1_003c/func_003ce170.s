.section .text
.set noat
.set noreorder
glabel func_003ce170
    /* 2CE170 003CE170 0800858C */  lw         $5, 0x8($4)
    /* 2CE174 003CE174 2D180000 */  daddu      $3, $0, $0
    /* 2CE178 003CE178 01000224 */  addiu      $2, $0, 0x1
    /* 2CE17C 003CE17C 75000A3C */  lui        $10, %hi(jtbl_00752EA0)
    /* 2CE180 003CE180 2D384000 */  daddu      $7, $2, $0
    /* 2CE184 003CE184 2D404000 */  daddu      $8, $2, $0
    /* 2CE188 003CE188 2D484000 */  daddu      $9, $2, $0
    /* 2CE18C 003CE18C A02E4A25 */  addiu      $10, $10, %lo(jtbl_00752EA0)
  .L003CE190:
    /* 2CE190 003CE190 0000A68C */  lw         $6, 0x0($5)
    /* 2CE194 003CE194 FFFFCB30 */  andi       $11, $6, 0xFFFF
    /* 2CE198 003CE198 02370600 */  srl        $6, $6, 28
    /* 2CE19C 003CE19C 0700C630 */  andi       $6, $6, 0x7
    /* 2CE1A0 003CE1A0 0800C12C */  sltiu      $1, $6, 0x8
    /* 2CE1A4 003CE1A4 1C002010 */  beqz       $1, .L003CE218
    /* 2CE1A8 003CE1A8 00000000 */   nop
    /* 2CE1AC 003CE1AC 80300600 */  sll        $6, $6, 2
    /* 2CE1B0 003CE1B0 2130CA00 */  addu       $6, $6, $10
    /* 2CE1B4 003CE1B4 0000C68C */  lw         $6, 0x0($6)
    /* 2CE1B8 003CE1B8 0800C000 */  jr         $6
    /* 2CE1BC 003CE1BC 00000000 */   nop
    /* 2CE1C0 003CE1C0 15000010 */  b          .L003CE218
    /* 2CE1C4 003CE1C4 2D182001 */   daddu     $3, $9, $0
    /* 2CE1C8 003CE1C8 01006625 */  addiu      $6, $11, 0x1
    /* 2CE1CC 003CE1CC 00310600 */  sll        $6, $6, 4
    /* 2CE1D0 003CE1D0 11000010 */  b          .L003CE218
    /* 2CE1D4 003CE1D4 2128A600 */   addu      $5, $5, $6
    /* 2CE1D8 003CE1D8 0400A68C */  lw         $6, 0x4($5)
    /* 2CE1DC 003CE1DC 0800828C */  lw         $2, 0x8($4)
    /* 2CE1E0 003CE1E0 2330C200 */  subu       $6, $6, $2
    /* 2CE1E4 003CE1E4 0300C104 */  bgez       $6, .L003CE1F4
    /* 2CE1E8 003CE1E8 03110600 */   sra       $2, $6, 4
    /* 2CE1EC 003CE1EC 0F00C224 */  addiu      $2, $6, 0xF
    /* 2CE1F0 003CE1F0 03110200 */  sra        $2, $2, 4
  .L003CE1F4:
    /* 2CE1F4 003CE1F4 0400A2AC */  sw         $2, 0x4($5)
    /* 2CE1F8 003CE1F8 2D100000 */  daddu      $2, $0, $0
    /* 2CE1FC 003CE1FC 06000010 */  b          .L003CE218
    /* 2CE200 003CE200 1000A524 */   addiu     $5, $5, 0x10
    /* 2CE204 003CE204 00000000 */  nop
    /* 2CE208 003CE208 03000010 */  b          .L003CE218
    /* 2CE20C 003CE20C 2D180001 */   daddu     $3, $8, $0
    /* 2CE210 003CE210 2D18E000 */  daddu      $3, $7, $0
    /* 2CE214 003CE214 00000000 */  nop
  .L003CE218:
    /* 2CE218 003CE218 2B300300 */  sltu       $6, $0, $3
    /* 2CE21C 003CE21C 0100C638 */  xori       $6, $6, 0x1
    /* 2CE220 003CE220 DBFFC014 */  bnez       $6, .L003CE190
    /* 2CE224 003CE224 00000000 */   nop
    /* 2CE228 003CE228 0800E003 */  jr         $31
    /* 2CE22C 003CE22C 00000000 */   nop
.size func_003ce170, 0xc0
