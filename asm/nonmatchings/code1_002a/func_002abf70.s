.section .text
.set noat
.set noreorder
glabel func_002abf70
    /* 1ABF70 002ABF70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1ABF74 002ABF74 2000BFFF */  sd         $31, 0x20($29)
    /* 1ABF78 002ABF78 1000B17F */  sq         $17, 0x10($29)
    /* 1ABF7C 002ABF7C 0000B07F */  sq         $16, 0x0($29)
    /* 1ABF80 002ABF80 2D888000 */  daddu      $17, $4, $0
    /* 1ABF84 002ABF84 3800908C */  lw         $16, 0x38($4)
    /* 1ABF88 002ABF88 00000482 */  lb         $4, 0x0($16)
    /* 1ABF8C 002ABF8C 0700812C */  sltiu      $1, $4, 0x7
    /* 1ABF90 002ABF90 AF002010 */  beqz       $1, .L002AC250
    /* 1ABF94 002ABF94 00000000 */   nop
    /* 1ABF98 002ABF98 7500033C */  lui        $3, %hi(jtbl_007487C0)
    /* 1ABF9C 002ABF9C C0876324 */  addiu      $3, $3, %lo(jtbl_007487C0)
    /* 1ABFA0 002ABFA0 80100400 */  sll        $2, $4, 2
    /* 1ABFA4 002ABFA4 21104300 */  addu       $2, $2, $3
    /* 1ABFA8 002ABFA8 0000428C */  lw         $2, 0x0($2)
    /* 1ABFAC 002ABFAC 08004000 */  jr         $2
    /* 1ABFB0 002ABFB0 00000000 */   nop
    /* 1ABFB4 002ABFB4 01008224 */  addiu      $2, $4, 0x1
    /* 1ABFB8 002ABFB8 000002A2 */  sb         $2, 0x0($16)
    /* 1ABFBC 002ABFBC A4000010 */  b          .L002AC250
    /* 1ABFC0 002ABFC0 00000000 */   nop
    /* 1ABFC4 002ABFC4 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1ABFC8 002ABFC8 00608244 */  mtc1       $2, $f12
    /* 1ABFCC 002ABFCC 1C43023C */  lui        $2, (0x431C0000 >> 16)
    /* 1ABFD0 002ABFD0 00688244 */  mtc1       $2, $f13
    /* 1ABFD4 002ABFD4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1ABFD8 002ABFD8 00708244 */  mtc1       $2, $f14
    /* 1ABFDC 002ABFDC C006028E */  lw         $2, 0x6C0($16)
    /* 1ABFE0 002ABFE0 80180200 */  sll        $3, $2, 2
    /* 1ABFE4 002ABFE4 6400023C */  lui        $2, %hi(D_0063EEA0)
    /* 1ABFE8 002ABFE8 A0EE4224 */  addiu      $2, $2, %lo(D_0063EEA0)
    /* 1ABFEC 002ABFEC 21104300 */  addu       $2, $2, $3
    /* 1ABFF0 002ABFF0 FFFF0424 */  addiu      $4, $0, -0x1
    /* 1ABFF4 002ABFF4 2D280000 */  daddu      $5, $0, $0
    /* 1ABFF8 002ABFF8 2D300000 */  daddu      $6, $0, $0
    /* 1ABFFC 002ABFFC 0000478C */  lw         $7, 0x0($2)
    /* 1AC000 002AC000 2D400000 */  daddu      $8, $0, $0
    /* 1AC004 002AC004 2D480000 */  daddu      $9, $0, $0
    /* 1AC008 002AC008 B4D3090C */  jal        func_00274ed0
    /* 1AC00C 002AC00C 00000000 */   nop
    /* 1AC010 002AC010 8C00023C */  lui        $2, %hi(D_008C027A)
    /* 1AC014 002AC014 7A024394 */  lhu        $3, %lo(D_008C027A)($2)
    /* 1AC018 002AC018 00806230 */  andi       $2, $3, 0x8000
    /* 1AC01C 002AC01C 0B004010 */  beqz       $2, .L002AC04C
    /* 1AC020 002AC020 00000000 */   nop
    /* 1AC024 002AC024 C006048E */  lw         $4, 0x6C0($16)
    /* 1AC028 002AC028 01000524 */  addiu      $5, $0, 0x1
    /* 1AC02C 002AC02C 03000624 */  addiu      $6, $0, 0x3
    /* 1AC030 002AC030 2D380000 */  daddu      $7, $0, $0
    /* 1AC034 002AC034 2D40A000 */  daddu      $8, $5, $0
    /* 1AC038 002AC038 2CCB0A0C */  jal        func_002b2cb0
    /* 1AC03C 002AC03C 00000000 */   nop
    /* 1AC040 002AC040 C00602AE */  sw         $2, 0x6C0($16)
    /* 1AC044 002AC044 82000010 */  b          .L002AC250
    /* 1AC048 002AC048 00000000 */   nop
  .L002AC04C:
    /* 1AC04C 002AC04C 00206230 */  andi       $2, $3, 0x2000
    /* 1AC050 002AC050 0B004010 */  beqz       $2, .L002AC080
    /* 1AC054 002AC054 00000000 */   nop
    /* 1AC058 002AC058 C006048E */  lw         $4, 0x6C0($16)
    /* 1AC05C 002AC05C 01000524 */  addiu      $5, $0, 0x1
    /* 1AC060 002AC060 2D300000 */  daddu      $6, $0, $0
    /* 1AC064 002AC064 03000724 */  addiu      $7, $0, 0x3
    /* 1AC068 002AC068 2D40A000 */  daddu      $8, $5, $0
    /* 1AC06C 002AC06C 40CB0A0C */  jal        func_002b2d00
    /* 1AC070 002AC070 00000000 */   nop
    /* 1AC074 002AC074 C00602AE */  sw         $2, 0x6C0($16)
    /* 1AC078 002AC078 75000010 */  b          .L002AC250
    /* 1AC07C 002AC07C 00000000 */   nop
  .L002AC080:
    /* 1AC080 002AC080 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1AC084 002AC084 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1AC088 002AC088 40006230 */  andi       $2, $3, 0x40
    /* 1AC08C 002AC08C 30004010 */  beqz       $2, .L002AC150
    /* 1AC090 002AC090 00000000 */   nop
    /* 1AC094 002AC094 C806028E */  lw         $2, 0x6C8($16)
    /* 1AC098 002AC098 02004010 */  beqz       $2, .L002AC0A4
    /* 1AC09C 002AC09C 00000000 */   nop
    /* 1AC0A0 002AC0A0 C80600AE */  sw         $0, 0x6C8($16)
  .L002AC0A4:
    /* 1AC0A4 002AC0A4 C006038E */  lw         $3, 0x6C0($16)
    /* 1AC0A8 002AC0A8 03000224 */  addiu      $2, $0, 0x3
    /* 1AC0AC 002AC0AC 1F006210 */  beq        $3, $2, .L002AC12C
    /* 1AC0B0 002AC0B0 00000000 */   nop
    /* 1AC0B4 002AC0B4 02000224 */  addiu      $2, $0, 0x2
    /* 1AC0B8 002AC0B8 15006210 */  beq        $3, $2, .L002AC110
    /* 1AC0BC 002AC0BC 00000000 */   nop
    /* 1AC0C0 002AC0C0 01000224 */  addiu      $2, $0, 0x1
    /* 1AC0C4 002AC0C4 0C006210 */  beq        $3, $2, .L002AC0F8
    /* 1AC0C8 002AC0C8 00000000 */   nop
    /* 1AC0CC 002AC0CC 03006010 */  beqz       $3, .L002AC0DC
    /* 1AC0D0 002AC0D0 00000000 */   nop
    /* 1AC0D4 002AC0D4 19000010 */  b          .L002AC13C
    /* 1AC0D8 002AC0D8 00000000 */   nop
  .L002AC0DC:
    /* 1AC0DC 002AC0DC 2D202002 */  daddu      $4, $17, $0
    /* 1AC0E0 002AC0E0 2D280000 */  daddu      $5, $0, $0
    /* 1AC0E4 002AC0E4 D4F60A0C */  jal        func_002bdb50
    /* 1AC0E8 002AC0E8 00000000 */   nop
    /* 1AC0EC 002AC0EC C80602AE */  sw         $2, 0x6C8($16)
    /* 1AC0F0 002AC0F0 12000010 */  b          .L002AC13C
    /* 1AC0F4 002AC0F4 00000000 */   nop
  .L002AC0F8:
    /* 1AC0F8 002AC0F8 2D202002 */  daddu      $4, $17, $0
    /* 1AC0FC 002AC0FC 449D0B0C */  jal        func_002e7510
    /* 1AC100 002AC100 00000000 */   nop
    /* 1AC104 002AC104 C80602AE */  sw         $2, 0x6C8($16)
    /* 1AC108 002AC108 0C000010 */  b          .L002AC13C
    /* 1AC10C 002AC10C 00000000 */   nop
  .L002AC110:
    /* 1AC110 002AC110 4CB580A3 */  sb         $0, -0x4AB4($28)
    /* 1AC114 002AC114 2D202002 */  daddu      $4, $17, $0
    /* 1AC118 002AC118 98440C0C */  jal        func_00311260
    /* 1AC11C 002AC11C 00000000 */   nop
    /* 1AC120 002AC120 C80602AE */  sw         $2, 0x6C8($16)
    /* 1AC124 002AC124 05000010 */  b          .L002AC13C
    /* 1AC128 002AC128 00000000 */   nop
  .L002AC12C:
    /* 1AC12C 002AC12C 2D202002 */  daddu      $4, $17, $0
    /* 1AC130 002AC130 EC240D0C */  jal        func_003493b0
    /* 1AC134 002AC134 00000000 */   nop
    /* 1AC138 002AC138 C80602AE */  sw         $2, 0x6C8($16)
  .L002AC13C:
    /* 1AC13C 002AC13C 00000282 */  lb         $2, 0x0($16)
    /* 1AC140 002AC140 01004224 */  addiu      $2, $2, 0x1
    /* 1AC144 002AC144 000002A2 */  sb         $2, 0x0($16)
    /* 1AC148 002AC148 41000010 */  b          .L002AC250
    /* 1AC14C 002AC14C 00000000 */   nop
  .L002AC150:
    /* 1AC150 002AC150 10006230 */  andi       $2, $3, 0x10
    /* 1AC154 002AC154 16004010 */  beqz       $2, .L002AC1B0
    /* 1AC158 002AC158 00000000 */   nop
    /* 1AC15C 002AC15C C806028E */  lw         $2, 0x6C8($16)
    /* 1AC160 002AC160 02004010 */  beqz       $2, .L002AC16C
    /* 1AC164 002AC164 00000000 */   nop
    /* 1AC168 002AC168 C80600AE */  sw         $0, 0x6C8($16)
  .L002AC16C:
    /* 1AC16C 002AC16C C006038E */  lw         $3, 0x6C0($16)
    /* 1AC170 002AC170 02000224 */  addiu      $2, $0, 0x2
    /* 1AC174 002AC174 03006210 */  beq        $3, $2, .L002AC184
    /* 1AC178 002AC178 00000000 */   nop
    /* 1AC17C 002AC17C 07000010 */  b          .L002AC19C
    /* 1AC180 002AC180 00000000 */   nop
  .L002AC184:
    /* 1AC184 002AC184 01000224 */  addiu      $2, $0, 0x1
    /* 1AC188 002AC188 4CB582A3 */  sb         $2, -0x4AB4($28)
    /* 1AC18C 002AC18C 2D202002 */  daddu      $4, $17, $0
    /* 1AC190 002AC190 98440C0C */  jal        func_00311260
    /* 1AC194 002AC194 00000000 */   nop
    /* 1AC198 002AC198 C80602AE */  sw         $2, 0x6C8($16)
  .L002AC19C:
    /* 1AC19C 002AC19C 00000282 */  lb         $2, 0x0($16)
    /* 1AC1A0 002AC1A0 01004224 */  addiu      $2, $2, 0x1
    /* 1AC1A4 002AC1A4 000002A2 */  sb         $2, 0x0($16)
    /* 1AC1A8 002AC1A8 29000010 */  b          .L002AC250
    /* 1AC1AC 002AC1AC 00000000 */   nop
  .L002AC1B0:
    /* 1AC1B0 002AC1B0 80006230 */  andi       $2, $3, 0x80
    /* 1AC1B4 002AC1B4 26004010 */  beqz       $2, .L002AC250
    /* 1AC1B8 002AC1B8 00000000 */   nop
    /* 1AC1BC 002AC1BC 2D200000 */  daddu      $4, $0, $0
    /* 1AC1C0 002AC1C0 2D280000 */  daddu      $5, $0, $0
    /* 1AC1C4 002AC1C4 2D300000 */  daddu      $6, $0, $0
    /* 1AC1C8 002AC1C8 0A000724 */  addiu      $7, $0, 0xA
    /* 1AC1CC 002AC1CC D86B110C */  jal        func_0045af60
    /* 1AC1D0 002AC1D0 00000000 */   nop
    /* 1AC1D4 002AC1D4 1E000010 */  b          .L002AC250
    /* 1AC1D8 002AC1D8 00000000 */   nop
    /* 1AC1DC 002AC1DC 4CB58383 */  lb         $3, -0x4AB4($28)
    /* 1AC1E0 002AC1E0 01000224 */  addiu      $2, $0, 0x1
    /* 1AC1E4 002AC1E4 10006214 */  bne        $3, $2, .L002AC228
    /* 1AC1E8 002AC1E8 00000000 */   nop
    /* 1AC1EC 002AC1EC A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1AC1F0 002AC1F0 00608244 */  mtc1       $2, $f12
    /* 1AC1F4 002AC1F4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AC1F8 002AC1F8 00708244 */  mtc1       $2, $f14
    /* 1AC1FC 002AC1FC 46630046 */  mov.s      $f13, $f12
    /* 1AC200 002AC200 8080023C */  lui        $2, (0x808080FF >> 16)
    /* 1AC204 002AC204 FF804434 */  ori        $4, $2, (0x808080FF & 0xFFFF)
    /* 1AC208 002AC208 2D280000 */  daddu      $5, $0, $0
    /* 1AC20C 002AC20C 02000624 */  addiu      $6, $0, 0x2
    /* 1AC210 002AC210 6400073C */  lui        $7, %hi(D_0063EEB0)
    /* 1AC214 002AC214 B0EEE724 */  addiu      $7, $7, %lo(D_0063EEB0)
    /* 1AC218 002AC218 2D400000 */  daddu      $8, $0, $0
    /* 1AC21C 002AC21C 2D480000 */  daddu      $9, $0, $0
    /* 1AC220 002AC220 B4D3090C */  jal        func_00274ed0
    /* 1AC224 002AC224 00000000 */   nop
  .L002AC228:
    /* 1AC228 002AC228 C806048E */  lw         $4, 0x6C8($16)
    /* 1AC22C 002AC22C 2449110C */  jal        func_00452490
    /* 1AC230 002AC230 00000000 */   nop
    /* 1AC234 002AC234 06004014 */  bnez       $2, .L002AC250
    /* 1AC238 002AC238 00000000 */   nop
    /* 1AC23C 002AC23C 000000A2 */  sb         $0, 0x0($16)
    /* 1AC240 002AC240 A8F70A0C */  jal        func_002bdea0
    /* 1AC244 002AC244 00000000 */   nop
    /* 1AC248 002AC248 D0230C0C */  jal        func_00308f40
    /* 1AC24C 002AC24C 00000000 */   nop
  .L002AC250:
    /* 1AC250 002AC250 2D100000 */  daddu      $2, $0, $0
    /* 1AC254 002AC254 2000BFDF */  ld         $31, 0x20($29)
    /* 1AC258 002AC258 1000B17B */  lq         $17, 0x10($29)
    /* 1AC25C 002AC25C 0000B07B */  lq         $16, 0x0($29)
    /* 1AC260 002AC260 3000BD27 */  addiu      $29, $29, 0x30
    /* 1AC264 002AC264 0800E003 */  jr         $31
    /* 1AC268 002AC268 00000000 */   nop
    /* 1AC26C 002AC26C 00000000 */  nop
.size func_002abf70, 0x300
