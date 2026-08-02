.section .text
.set noat
.set noreorder
glabel func_002a6c30
    /* 1A6C30 002A6C30 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1A6C34 002A6C34 4000BFFF */  sd         $31, 0x40($29)
    /* 1A6C38 002A6C38 3000B37F */  sq         $19, 0x30($29)
    /* 1A6C3C 002A6C3C 2000B27F */  sq         $18, 0x20($29)
    /* 1A6C40 002A6C40 1000B17F */  sq         $17, 0x10($29)
    /* 1A6C44 002A6C44 0000B07F */  sq         $16, 0x0($29)
    /* 1A6C48 002A6C48 2D988000 */  daddu      $19, $4, $0
    /* 1A6C4C 002A6C4C 2D90A000 */  daddu      $18, $5, $0
    /* 1A6C50 002A6C50 2D88E000 */  daddu      $17, $7, $0
    /* 1A6C54 002A6C54 6C00C010 */  beqz       $6, .L002A6E08
    /* 1A6C58 002A6C58 00000000 */   nop
    /* 1A6C5C 002A6C5C 0400238E */  lw         $3, 0x4($17)
    /* 1A6C60 002A6C60 0800023C */  lui        $2, (0x80000 >> 16)
    /* 1A6C64 002A6C64 24106200 */  and        $2, $3, $2
    /* 1A6C68 002A6C68 09004010 */  beqz       $2, .L002A6C90
    /* 1A6C6C 002A6C6C 00000000 */   nop
    /* 1A6C70 002A6C70 D003228E */  lw         $2, 0x3D0($17)
    /* 1A6C74 002A6C74 05004128 */  slti       $1, $2, 0x5
    /* 1A6C78 002A6C78 0A002010 */  beqz       $1, .L002A6CA4
    /* 1A6C7C 002A6C7C 00000000 */   nop
    /* 1A6C80 002A6C80 01004224 */  addiu      $2, $2, 0x1
    /* 1A6C84 002A6C84 D00322AE */  sw         $2, 0x3D0($17)
    /* 1A6C88 002A6C88 06000010 */  b          .L002A6CA4
    /* 1A6C8C 002A6C8C 00000000 */   nop
  .L002A6C90:
    /* 1A6C90 002A6C90 D003228E */  lw         $2, 0x3D0($17)
    /* 1A6C94 002A6C94 03004018 */  blez       $2, .L002A6CA4
    /* 1A6C98 002A6C98 00000000 */   nop
    /* 1A6C9C 002A6C9C FFFF4224 */  addiu      $2, $2, -0x1
    /* 1A6CA0 002A6CA0 D00322AE */  sw         $2, 0x3D0($17)
  .L002A6CA4:
    /* 1A6CA4 002A6CA4 D00320C6 */  lwc1       $f0, 0x3D0($17)
    /* 1A6CA8 002A6CA8 60008046 */  cvt.s.w    $f1, $f0
    /* 1A6CAC 002A6CAC A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1A6CB0 002A6CB0 00008244 */  mtc1       $2, $f0
    /* 1A6CB4 002A6CB4 00000000 */  nop
    /* 1A6CB8 002A6CB8 43080046 */  div.s      $f1, $f1, $f0
    /* 1A6CBC 002A6CBC 00008644 */  mtc1       $6, $f0
    /* 1A6CC0 002A6CC0 00000000 */  nop
    /* 1A6CC4 002A6CC4 20008046 */  cvt.s.w    $f0, $f0
    /* 1A6CC8 002A6CC8 02080046 */  mul.s      $f0, $f1, $f0
    /* 1A6CCC 002A6CCC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1A6CD0 002A6CD0 00001044 */  mfc1       $16, $f0
    /* 1A6CD4 002A6CD4 F5016226 */  addiu      $2, $19, 0x1F5
    /* 1A6CD8 002A6CD8 00008244 */  mtc1       $2, $f0
    /* 1A6CDC 002A6CDC 00000000 */  nop
    /* 1A6CE0 002A6CE0 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6CE4 002A6CE4 9B014226 */  addiu      $2, $18, 0x19B
    /* 1A6CE8 002A6CE8 00008244 */  mtc1       $2, $f0
    /* 1A6CEC 002A6CEC 00000000 */  nop
    /* 1A6CF0 002A6CF0 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6CF4 002A6CF4 00708044 */  mtc1       $0, $f14
    /* 1A6CF8 002A6CF8 FF000532 */  andi       $5, $16, 0xFF
    /* 1A6CFC 002A6CFC FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6D00 002A6D00 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6D04 002A6D04 24000624 */  addiu      $6, $0, 0x24
    /* 1A6D08 002A6D08 2D380000 */  daddu      $7, $0, $0
    /* 1A6D0C 002A6D0C 9803288E */  lw         $8, 0x398($17)
    /* 1A6D10 002A6D10 01000924 */  addiu      $9, $0, 0x1
    /* 1A6D14 002A6D14 FC7C090C */  jal        func_0025f3f0
    /* 1A6D18 002A6D18 00000000 */   nop
    /* 1A6D1C 002A6D1C 07026226 */  addiu      $2, $19, 0x207
    /* 1A6D20 002A6D20 00008244 */  mtc1       $2, $f0
    /* 1A6D24 002A6D24 00000000 */  nop
    /* 1A6D28 002A6D28 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6D2C 002A6D2C 9D014226 */  addiu      $2, $18, 0x19D
    /* 1A6D30 002A6D30 00008244 */  mtc1       $2, $f0
    /* 1A6D34 002A6D34 00000000 */  nop
    /* 1A6D38 002A6D38 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6D3C 002A6D3C 00708044 */  mtc1       $0, $f14
    /* 1A6D40 002A6D40 FF000532 */  andi       $5, $16, 0xFF
    /* 1A6D44 002A6D44 FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6D48 002A6D48 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6D4C 002A6D4C 27000624 */  addiu      $6, $0, 0x27
    /* 1A6D50 002A6D50 2D380000 */  daddu      $7, $0, $0
    /* 1A6D54 002A6D54 9803288E */  lw         $8, 0x398($17)
    /* 1A6D58 002A6D58 01000924 */  addiu      $9, $0, 0x1
    /* 1A6D5C 002A6D5C FC7C090C */  jal        func_0025f3f0
    /* 1A6D60 002A6D60 00000000 */   nop
    /* 1A6D64 002A6D64 2C026226 */  addiu      $2, $19, 0x22C
    /* 1A6D68 002A6D68 00008244 */  mtc1       $2, $f0
    /* 1A6D6C 002A6D6C 00000000 */  nop
    /* 1A6D70 002A6D70 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6D74 002A6D74 9B014226 */  addiu      $2, $18, 0x19B
    /* 1A6D78 002A6D78 00008244 */  mtc1       $2, $f0
    /* 1A6D7C 002A6D7C 00000000 */  nop
    /* 1A6D80 002A6D80 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6D84 002A6D84 00708044 */  mtc1       $0, $f14
    /* 1A6D88 002A6D88 FF000532 */  andi       $5, $16, 0xFF
    /* 1A6D8C 002A6D8C FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6D90 002A6D90 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6D94 002A6D94 25000624 */  addiu      $6, $0, 0x25
    /* 1A6D98 002A6D98 2D380000 */  daddu      $7, $0, $0
    /* 1A6D9C 002A6D9C 9803288E */  lw         $8, 0x398($17)
    /* 1A6DA0 002A6DA0 01000924 */  addiu      $9, $0, 0x1
    /* 1A6DA4 002A6DA4 FC7C090C */  jal        func_0025f3f0
    /* 1A6DA8 002A6DA8 00000000 */   nop
    /* 1A6DAC 002A6DAC 3E026226 */  addiu      $2, $19, 0x23E
    /* 1A6DB0 002A6DB0 00008244 */  mtc1       $2, $f0
    /* 1A6DB4 002A6DB4 00000000 */  nop
    /* 1A6DB8 002A6DB8 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6DBC 002A6DBC 9D014226 */  addiu      $2, $18, 0x19D
    /* 1A6DC0 002A6DC0 00008244 */  mtc1       $2, $f0
    /* 1A6DC4 002A6DC4 00000000 */  nop
    /* 1A6DC8 002A6DC8 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6DCC 002A6DCC 00708044 */  mtc1       $0, $f14
    /* 1A6DD0 002A6DD0 FF000532 */  andi       $5, $16, 0xFF
    /* 1A6DD4 002A6DD4 FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6DD8 002A6DD8 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6DDC 002A6DDC 28000624 */  addiu      $6, $0, 0x28
    /* 1A6DE0 002A6DE0 2D380000 */  daddu      $7, $0, $0
    /* 1A6DE4 002A6DE4 9803288E */  lw         $8, 0x398($17)
    /* 1A6DE8 002A6DE8 01000924 */  addiu      $9, $0, 0x1
    /* 1A6DEC 002A6DEC FC7C090C */  jal        func_0025f3f0
    /* 1A6DF0 002A6DF0 00000000 */   nop
    /* 1A6DF4 002A6DF4 0400248E */  lw         $4, 0x4($17)
    /* 1A6DF8 002A6DF8 F7FF033C */  lui        $3, (0xFFF7FFFF >> 16)
    /* 1A6DFC 002A6DFC FFFF6334 */  ori        $3, $3, (0xFFF7FFFF & 0xFFFF)
    /* 1A6E00 002A6E00 24188300 */  and        $3, $4, $3
    /* 1A6E04 002A6E04 040023AE */  sw         $3, 0x4($17)
  .L002A6E08:
    /* 1A6E08 002A6E08 4000BFDF */  ld         $31, 0x40($29)
    /* 1A6E0C 002A6E0C 3000B37B */  lq         $19, 0x30($29)
    /* 1A6E10 002A6E10 2000B27B */  lq         $18, 0x20($29)
    /* 1A6E14 002A6E14 1000B17B */  lq         $17, 0x10($29)
    /* 1A6E18 002A6E18 0000B07B */  lq         $16, 0x0($29)
    /* 1A6E1C 002A6E1C 5000BD27 */  addiu      $29, $29, 0x50
    /* 1A6E20 002A6E20 0800E003 */  jr         $31
    /* 1A6E24 002A6E24 00000000 */   nop
    /* 1A6E28 002A6E28 00000000 */  nop
    /* 1A6E2C 002A6E2C 00000000 */  nop
.size func_002a6c30, 0x200
