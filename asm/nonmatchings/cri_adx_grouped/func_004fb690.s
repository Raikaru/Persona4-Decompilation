.section .text
.set noat
.set noreorder
glabel func_004fb690
    /* 3FB690 004FB690 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3FB694 004FB694 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB698 004FB698 2D80A000 */  daddu      $16, $5, $0
    /* 3FB69C 004FB69C 1800B3FF */  sd         $19, 0x18($29)
    /* 3FB6A0 004FB6A0 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB6A4 004FB6A4 1000B2FF */  sd         $18, 0x10($29)
    /* 3FB6A8 004FB6A8 2000BFFF */  sd         $31, 0x20($29)
    /* 3FB6AC 004FB6AC 1E04140C */  jal        func_00501078
    /* 3FB6B0 004FB6B0 2D988000 */   daddu     $19, $4, $0
    /* 3FB6B4 004FB6B4 0A004010 */  beqz       $2, .L004FB6E0
    /* 3FB6B8 004FB6B8 0800B1DF */   ld        $17, 0x8($29)
    /* 3FB6BC 004FB6BC 03FF053C */  lui        $5, (0xFF03020A >> 16)
    /* 3FB6C0 004FB6C0 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB6C4 004FB6C4 2D200000 */  daddu      $4, $0, $0
    /* 3FB6C8 004FB6C8 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB6CC 004FB6CC 0A02A534 */  ori        $5, $5, (0xFF03020A & 0xFFFF)
    /* 3FB6D0 004FB6D0 1800B3DF */  ld         $19, 0x18($29)
    /* 3FB6D4 004FB6D4 2000BFDF */  ld         $31, 0x20($29)
    /* 3FB6D8 004FB6D8 82ED1308 */  j          func_004fb608
    /* 3FB6DC 004FB6DC 3000BD27 */   addiu     $29, $29, 0x30
  .L004FB6E0:
    /* 3FB6E0 004FB6E0 03FF113C */  lui        $17, (0xFF030305 >> 16)
    /* 3FB6E4 004FB6E4 04001224 */  addiu      $18, $0, 0x4
    /* 3FB6E8 004FB6E8 05033136 */  ori        $17, $17, (0xFF030305 & 0xFFFF)
    /* 3FB6EC 004FB6EC 00000000 */  nop
  .L004FB6F0:
    /* 3FB6F0 004FB6F0 3E1A140C */  jal        func_005068f8
    /* 3FB6F4 004FB6F4 2D200002 */   daddu     $4, $16, $0
    /* 3FB6F8 004FB6F8 2D200002 */  daddu      $4, $16, $0
    /* 3FB6FC 004FB6FC 01000524 */  addiu      $5, $0, 0x1
    /* 3FB700 004FB700 04000624 */  addiu      $6, $0, 0x4
    /* 3FB704 004FB704 07004010 */  beqz       $2, .L004FB724
    /* 3FB708 004FB708 CC004330 */   andi      $3, $2, 0xCC
    /* 3FB70C 004FB70C 05006054 */  bnel       $3, $0, .L004FB724
    /* 3FB710 004FB710 2D880000 */   daddu     $17, $0, $0
    /* 3FB714 004FB714 C81A140C */  jal        func_00506b20
    /* 3FB718 004FB718 00000000 */   nop
    /* 3FB71C 004FB71C F4FF5210 */  beq        $2, $18, .L004FB6F0
    /* 3FB720 004FB720 00000000 */   nop
  .L004FB724:
    /* 3FB724 004FB724 2D206002 */  daddu      $4, $19, $0
    /* 3FB728 004FB728 1800B3DF */  ld         $19, 0x18($29)
    /* 3FB72C 004FB72C 2D282002 */  daddu      $5, $17, $0
    /* 3FB730 004FB730 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB734 004FB734 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB738 004FB738 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB73C 004FB73C 2000BFDF */  ld         $31, 0x20($29)
    /* 3FB740 004FB740 82ED1308 */  j          func_004fb608
    /* 3FB744 004FB744 3000BD27 */   addiu     $29, $29, 0x30
.size func_004fb690, 0xb8
