.section .text
.set noat
.set noreorder
glabel func_001fadc0
    /* FADC0 001FADC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FADC4 001FADC4 0000BFFF */  sd         $31, 0x0($29)
    /* FADC8 001FADC8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FADCC 001FADCC 0C00438C */  lw         $3, 0xC($2)
    /* FADD0 001FADD0 2000023C */  lui        $2, (0x200000 >> 16)
    /* FADD4 001FADD4 24106200 */  and        $2, $3, $2
    /* FADD8 001FADD8 06004010 */  beqz       $2, .L001FADF4
    /* FADDC 001FADDC 00000000 */   nop
    /* FADE0 001FADE0 04000524 */  addiu      $5, $0, 0x4
    /* FADE4 001FADE4 B4AE080C */  jal        func_0022bad0
    /* FADE8 001FADE8 00000000 */   nop
    /* FADEC 001FADEC 02000010 */  b          .L001FADF8
    /* FADF0 001FADF0 00000000 */   nop
  .L001FADF4:
    /* FADF4 001FADF4 2D100000 */  daddu      $2, $0, $0
  .L001FADF8:
    /* FADF8 001FADF8 0000BFDF */  ld         $31, 0x0($29)
    /* FADFC 001FADFC 1000BD27 */  addiu      $29, $29, 0x10
    /* FAE00 001FAE00 0800E003 */  jr         $31
    /* FAE04 001FAE04 00000000 */   nop
    /* FAE08 001FAE08 00000000 */  nop
    /* FAE0C 001FAE0C 00000000 */  nop
.size func_001fadc0, 0x50
