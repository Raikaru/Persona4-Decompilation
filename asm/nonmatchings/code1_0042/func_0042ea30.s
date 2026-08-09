.section .text
.set noat
.set noreorder
glabel func_0042ea30
    /* 32EA30 0042EA30 01800234 */  ori        $2, $0, 0x8001
    /* 32EA34 0042EA34 26008210 */  beq        $4, $2, .L0042EAD0
    /* 32EA38 0042EA38 7100023C */   lui       $2, %hi(D_0070DCE8)
    /* 32EA3C 0042EA3C 03800234 */  ori        $2, $0, 0x8003
    /* 32EA40 0042EA40 21008210 */  beq        $4, $2, .L0042EAC8
    /* 32EA44 0042EA44 7100023C */   lui       $2, %hi(D_0070DD40)
    /* 32EA48 0042EA48 02800234 */  ori        $2, $0, 0x8002
    /* 32EA4C 0042EA4C 1C008210 */  beq        $4, $2, .L0042EAC0
    /* 32EA50 0042EA50 7100023C */   lui       $2, %hi(D_0070DDC0)
    /* 32EA54 0042EA54 04800234 */  ori        $2, $0, 0x8004
    /* 32EA58 0042EA58 17008210 */  beq        $4, $2, .L0042EAB8
    /* 32EA5C 0042EA5C 7100023C */   lui       $2, %hi(D_0070EE90)
    /* 32EA60 0042EA60 11800234 */  ori        $2, $0, 0x8011
    /* 32EA64 0042EA64 10008210 */  beq        $4, $2, .L0042EAA8
    /* 32EA68 0042EA68 13800234 */   ori       $2, $0, 0x8013
    /* 32EA6C 0042EA6C 0C008210 */  beq        $4, $2, .L0042EAA0
    /* 32EA70 0042EA70 7100023C */   lui       $2, %hi(D_0070EEC0)
    /* 32EA74 0042EA74 12800234 */  ori        $2, $0, 0x8012
    /* 32EA78 0042EA78 07008210 */  beq        $4, $2, .L0042EA98
    /* 32EA7C 0042EA7C 7100023C */   lui       $2, %hi(D_0070F300)
    /* 32EA80 0042EA80 14800234 */  ori        $2, $0, 0x8014
    /* 32EA84 0042EA84 13008254 */  bnel       $4, $2, .L0042EAD4
    /* 32EA88 0042EA88 2D100000 */   daddu     $2, $0, $0
    /* 32EA8C 0042EA8C 7100023C */  lui        $2, %hi(D_0070F840)
    /* 32EA90 0042EA90 10000010 */  b          .L0042EAD4
    /* 32EA94 0042EA94 40F84224 */   addiu     $2, $2, %lo(D_0070F840)
  .L0042EA98:
    /* 32EA98 0042EA98 0E000010 */  b          .L0042EAD4
    /* 32EA9C 0042EA9C 00F34224 */   addiu     $2, $2, %lo(D_0070F300)
  .L0042EAA0:
    /* 32EAA0 0042EAA0 0C000010 */  b          .L0042EAD4
    /* 32EAA4 0042EAA4 C0EE4224 */   addiu     $2, $2, %lo(D_0070EEC0)
  .L0042EAA8:
    /* 32EAA8 0042EAA8 7100023C */  lui        $2, %hi(D_0070DCEC)
    /* 32EAAC 0042EAAC ECDC428C */  lw         $2, %lo(D_0070DCEC)($2)
    /* 32EAB0 0042EAB0 09000010 */  b          .L0042EAD8
    /* 32EAB4 0042EAB4 0000A2AC */   sw        $2, 0x0($5)
  .L0042EAB8:
    /* 32EAB8 0042EAB8 06000010 */  b          .L0042EAD4
    /* 32EABC 0042EABC 90EE4224 */   addiu     $2, $2, %lo(D_0070EE90)
  .L0042EAC0:
    /* 32EAC0 0042EAC0 04000010 */  b          .L0042EAD4
    /* 32EAC4 0042EAC4 C0DD4224 */   addiu     $2, $2, %lo(D_0070DDC0)
  .L0042EAC8:
    /* 32EAC8 0042EAC8 02000010 */  b          .L0042EAD4
    /* 32EACC 0042EACC 40DD4224 */   addiu     $2, $2, %lo(D_0070DD40)
  .L0042EAD0:
    /* 32EAD0 0042EAD0 E8DC428C */  lw         $2, %lo(D_0070DCE8)($2)
  .L0042EAD4:
    /* 32EAD4 0042EAD4 0000A2AC */  sw         $2, 0x0($5)
  .L0042EAD8:
    /* 32EAD8 0042EAD8 0800E003 */  jr         $31
    /* 32EADC 0042EADC 01000224 */   addiu     $2, $0, 0x1
.size func_0042ea30, 0xb0
