.section .text
.set noat
.set noreorder
glabel func_003fea90
    /* 2FEA90 003FEA90 00FFBD27 */  addiu      $29, $29, -0x100
    /* 2FEA94 003FEA94 0041023C */  lui        $2, (0x41000000 >> 16)
    /* 2FEA98 003FEA98 9000BFFF */  sd         $31, 0x90($29)
    /* 2FEA9C 003FEA9C 00208244 */  mtc1       $2, $f4
    /* 2FEAA0 003FEAA0 8000BE7F */  sq         $30, 0x80($29)
    /* 2FEAA4 003FEAA4 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FEAA8 003FEAA8 7000B77F */  sq         $23, 0x70($29)
    /* 2FEAAC 003FEAAC 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FEAB0 003FEAB0 6000B67F */  sq         $22, 0x60($29)
    /* 2FEAB4 003FEAB4 5000B57F */  sq         $21, 0x50($29)
    /* 2FEAB8 003FEAB8 4000B47F */  sq         $20, 0x40($29)
    /* 2FEABC 003FEABC 3000B37F */  sq         $19, 0x30($29)
    /* 2FEAC0 003FEAC0 2DA08000 */  daddu      $20, $4, $0
    /* 2FEAC4 003FEAC4 2000B27F */  sq         $18, 0x20($29)
    /* 2FEAC8 003FEAC8 1000B17F */  sq         $17, 0x10($29)
    /* 2FEACC 003FEACC 0000B07F */  sq         $16, 0x0($29)
    /* 2FEAD0 003FEAD0 B0C963C4 */  lwc1       $f3, %lo(D_0088C9B0)($3)
    /* 2FEAD4 003FEAD4 C8C942C4 */  lwc1       $f2, %lo(D_0088C9C8)($2)
    /* 2FEAD8 003FEAD8 E0188046 */  cvt.s.w    $f3, $f3
    /* 2FEADC 003FEADC 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2FEAE0 003FEAE0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 2FEAE4 003FEAE4 A0108046 */  cvt.s.w    $f2, $f2
    /* 2FEAE8 003FEAE8 C2200346 */  mul.s      $f3, $f4, $f3
    /* 2FEAEC 003FEAEC 83180246 */  div.s      $f2, $f3, $f2
    /* 2FEAF0 003FEAF0 00088344 */  mtc1       $3, $f1
    /* 2FEAF4 003FEAF4 00008244 */  mtc1       $2, $f0
    /* 2FEAF8 003FEAF8 00000000 */  nop
    /* 2FEAFC 003FEAFC 40080246 */  add.s      $f1, $f1, $f2
    /* 2FEB00 003FEB00 36000146 */  c.le.s     $f0, $f1
    /* 2FEB04 003FEB04 05000145 */  bc1t       .L003FEB1C
    /* 2FEB08 003FEB08 00000000 */   nop
    /* 2FEB0C 003FEB0C 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEB10 003FEB10 00001544 */  mfc1       $21, $f0
    /* 2FEB14 003FEB14 07000010 */  b          .L003FEB34
    /* 2FEB18 003FEB18 00000000 */   nop
  .L003FEB1C:
    /* 2FEB1C 003FEB1C 01080046 */  sub.s      $f0, $f1, $f0
    /* 2FEB20 003FEB20 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 2FEB24 003FEB24 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEB28 003FEB28 00001544 */  mfc1       $21, $f0
    /* 2FEB2C 003FEB2C 00000000 */  nop
    /* 2FEB30 003FEB30 25A8A202 */  or         $21, $21, $2
  .L003FEB34:
    /* 2FEB34 003FEB34 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FEB38 003FEB38 8900033C */  lui        $3, %hi(D_0088C9CC)
    /* 2FEB3C 003FEB3C B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FEB40 003FEB40 CCC9668C */  lw         $6, %lo(D_0088C9CC)($3)
    /* 2FEB44 003FEB44 00188444 */  mtc1       $4, $f3
    /* 2FEB48 003FEB48 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 2FEB4C 003FEB4C 0041033C */  lui        $3, (0x41000000 >> 16)
    /* 2FEB50 003FEB50 E0188046 */  cvt.s.w    $f3, $f3
    /* 2FEB54 003FEB54 00208344 */  mtc1       $3, $f4
    /* 2FEB58 003FEB58 00108644 */  mtc1       $6, $f2
    /* 2FEB5C 003FEB5C 00000000 */  nop
    /* 2FEB60 003FEB60 C2200346 */  mul.s      $f3, $f4, $f3
    /* 2FEB64 003FEB64 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2FEB68 003FEB68 A0108046 */  cvt.s.w    $f2, $f2
    /* 2FEB6C 003FEB6C 83180246 */  div.s      $f2, $f3, $f2
    /* 2FEB70 003FEB70 00088344 */  mtc1       $3, $f1
    /* 2FEB74 003FEB74 00008244 */  mtc1       $2, $f0
    /* 2FEB78 003FEB78 00000000 */  nop
    /* 2FEB7C 003FEB7C 40080246 */  add.s      $f1, $f1, $f2
    /* 2FEB80 003FEB80 36000146 */  c.le.s     $f0, $f1
    /* 2FEB84 003FEB84 05000145 */  bc1t       .L003FEB9C
    /* 2FEB88 003FEB88 00000000 */   nop
    /* 2FEB8C 003FEB8C 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEB90 003FEB90 00001144 */  mfc1       $17, $f0
    /* 2FEB94 003FEB94 07000010 */  b          .L003FEBB4
    /* 2FEB98 003FEB98 00000000 */   nop
  .L003FEB9C:
    /* 2FEB9C 003FEB9C 01080046 */  sub.s      $f0, $f1, $f0
    /* 2FEBA0 003FEBA0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 2FEBA4 003FEBA4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEBA8 003FEBA8 00001144 */  mfc1       $17, $f0
    /* 2FEBAC 003FEBAC 00000000 */  nop
    /* 2FEBB0 003FEBB0 25882202 */  or         $17, $17, $2
  .L003FEBB4:
    /* 2FEBB4 003FEBB4 00008444 */  mtc1       $4, $f0
    /* 2FEBB8 003FEBB8 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 2FEBBC 003FEBBC 00088244 */  mtc1       $2, $f1
    /* 2FEBC0 003FEBC0 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2FEBC4 003FEBC4 20008046 */  cvt.s.w    $f0, $f0
    /* 2FEBC8 003FEBC8 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 2FEBCC 003FEBCC 82080046 */  mul.s      $f2, $f1, $f0
    /* 2FEBD0 003FEBD0 00088644 */  mtc1       $6, $f1
    /* 2FEBD4 003FEBD4 00008344 */  mtc1       $3, $f0
    /* 2FEBD8 003FEBD8 00000000 */  nop
    /* 2FEBDC 003FEBDC 60088046 */  cvt.s.w    $f1, $f1
    /* 2FEBE0 003FEBE0 43100146 */  div.s      $f1, $f2, $f1
    /* 2FEBE4 003FEBE4 40000146 */  add.s      $f1, $f0, $f1
    /* 2FEBE8 003FEBE8 00008244 */  mtc1       $2, $f0
    /* 2FEBEC 003FEBEC 00000000 */  nop
    /* 2FEBF0 003FEBF0 36000146 */  c.le.s     $f0, $f1
    /* 2FEBF4 003FEBF4 05000145 */  bc1t       .L003FEC0C
    /* 2FEBF8 003FEBF8 00000000 */   nop
    /* 2FEBFC 003FEBFC 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEC00 003FEC00 00001044 */  mfc1       $16, $f0
    /* 2FEC04 003FEC04 08000010 */  b          .L003FEC28
    /* 2FEC08 003FEC08 0070023C */   lui       $2, (0x70000013 >> 16)
  .L003FEC0C:
    /* 2FEC0C 003FEC0C 01080046 */  sub.s      $f0, $f1, $f0
    /* 2FEC10 003FEC10 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 2FEC14 003FEC14 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FEC18 003FEC18 00001044 */  mfc1       $16, $f0
    /* 2FEC1C 003FEC1C 00000000 */  nop
    /* 2FEC20 003FEC20 25800202 */  or         $16, $16, $2
    /* 2FEC24 003FEC24 0070023C */  lui        $2, (0x70000013 >> 16)
  .L003FEC28:
    /* 2FEC28 003FEC28 3C201500 */  dsll32     $4, $21, 0
    /* 2FEC2C 003FEC2C 13004234 */  ori        $2, $2, (0x70000013 & 0xFFFF)
    /* 2FEC30 003FEC30 3E200400 */  dsrl32     $4, $4, 0
    /* 2FEC34 003FEC34 D000A27F */  sq         $2, 0xD0($29)
    /* 2FEC38 003FEC38 2D900000 */  daddu      $18, $0, $0
    /* 2FEC3C 003FEC3C 0010023C */  lui        $2, (0x10000000 >> 16)
    /* 2FEC40 003FEC40 2DB80000 */  daddu      $23, $0, $0
    /* 2FEC44 003FEC44 3C180200 */  dsll32     $3, $2, 0
    /* 2FEC48 003FEC48 2DF00000 */  daddu      $30, $0, $0
    /* 2FEC4C 003FEC4C 12800234 */  ori        $2, $0, 0x8012
    /* 2FEC50 003FEC50 E800A0FF */  sd         $0, 0xE8($29)
    /* 2FEC54 003FEC54 25104300 */  or         $2, $2, $3
    /* 2FEC58 003FEC58 C000A27F */  sq         $2, 0xC0($29)
    /* 2FEC5C 003FEC5C FF7F033C */  lui        $3, (0x7FFF0000 >> 16)
    /* 2FEC60 003FEC60 3C100300 */  dsll32     $2, $3, 0
    /* 2FEC64 003FEC64 25106200 */  or         $2, $3, $2
    /* 2FEC68 003FEC68 B000A27F */  sq         $2, 0xB0($29)
    /* 2FEC6C 003FEC6C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2FEC70 003FEC70 3C100200 */  dsll32     $2, $2, 0
    /* 2FEC74 003FEC74 A62E110C */  jal        func_0044ba98
    /* 2FEC78 003FEC78 A000A27F */   sq        $2, 0xA0($29)
    /* 2FEC7C 003FEC7C 8046023C */  lui        $2, (0x46800000 >> 16)
    /* 2FEC80 003FEC80 E000A0FF */  sd         $0, 0xE0($29)
    /* 2FEC84 003FEC84 00088244 */  mtc1       $2, $f1
    /* 2FEC88 003FEC88 00000000 */  nop
    /* 2FEC8C 003FEC8C 03000146 */  div.s      $f0, $f0, $f1
    /* 2FEC90 003FEC90 FC00A0E7 */  swc1       $f0, 0xFC($29)
  .L003FEC94:
    /* 2FEC94 003FEC94 1F014012 */  beqz       $18, .L003FF114
    /* 2FEC98 003FEC98 00000000 */   nop
    /* 2FEC9C 003FEC9C 01000224 */  addiu      $2, $0, 0x1
    /* 2FECA0 003FECA0 1F014212 */  beq        $18, $2, .L003FF120
    /* 2FECA4 003FECA4 00000000 */   nop
    /* 2FECA8 003FECA8 02000224 */  addiu      $2, $0, 0x2
    /* 2FECAC 003FECAC 04004216 */  bne        $18, $2, .L003FECC0
    /* 2FECB0 003FECB0 00000000 */   nop
    /* 2FECB4 003FECB4 8900133C */  lui        $19, %hi(D_0088C2C0)
    /* 2FECB8 003FECB8 03000010 */  b          .L003FECC8
    /* 2FECBC 003FECBC C0C27326 */   addiu     $19, $19, %lo(D_0088C2C0)
  .L003FECC0:
    /* 2FECC0 003FECC0 8900133C */  lui        $19, %hi(D_0088C400)
    /* 2FECC4 003FECC4 00C47326 */  addiu      $19, $19, %lo(D_0088C400)
  .L003FECC8:
    /* 2FECC8 003FECC8 8900023C */  lui        $2, %hi(D_0088C9D4)
    /* 2FECCC 003FECCC D4C9428C */  lw         $2, %lo(D_0088C9D4)($2)
    /* 2FECD0 003FECD0 02004230 */  andi       $2, $2, 0x2
    /* 2FECD4 003FECD4 03004010 */  beqz       $2, .L003FECE4
    /* 2FECD8 003FECD8 00000000 */   nop
    /* 2FECDC 003FECDC 03000010 */  b          .L003FECEC
    /* 2FECE0 003FECE0 2DB00000 */   daddu     $22, $0, $0
  .L003FECE4:
    /* 2FECE4 003FECE4 02004232 */  andi       $2, $18, 0x2
    /* 2FECE8 003FECE8 2BB00200 */  sltu       $22, $0, $2
  .L003FECEC:
    /* 2FECEC 003FECEC D000A27B */  lq         $2, 0xD0($29)
    /* 2FECF0 003FECF0 0E000324 */  addiu      $3, $0, 0xE
    /* 2FECF4 003FECF4 8913E272 */  pcpyld     $2, $23, $2
    /* 2FECF8 003FECF8 0000627E */  sq         $2, 0x0($19)
    /* 2FECFC 003FECFC C000A27B */  lq         $2, 0xC0($29)
    /* 2FED00 003FED00 89136270 */  pcpyld     $2, $3, $2
    /* 2FED04 003FED04 0F00C012 */  beqz       $22, .L003FED44
    /* 2FED08 003FED08 1000627E */   sq        $2, 0x10($19)
    /* 2FED0C 003FED0C 6003868E */  lw         $6, 0x360($20)
    /* 2FED10 003FED10 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FED14 003FED14 C8C9438C */  lw         $3, %lo(D_0088C9C8)($2)
    /* 2FED18 003FED18 3C230600 */  dsll32     $4, $6, 12
    /* 2FED1C 003FED1C FE260400 */  dsrl32     $4, $4, 27
    /* 2FED20 003FED20 83190300 */  sra        $3, $3, 6
    /* 2FED24 003FED24 00260400 */  sll        $4, $4, 24
    /* 2FED28 003FED28 001C0300 */  sll        $3, $3, 16
    /* 2FED2C 003FED2C FF01C230 */  andi       $2, $6, 0x1FF
    /* 2FED30 003FED30 25188300 */  or         $3, $4, $3
    /* 2FED34 003FED34 25104300 */  or         $2, $2, $3
    /* 2FED38 003FED38 3C180200 */  dsll32     $3, $2, 0
    /* 2FED3C 003FED3C 0E000010 */  b          .L003FED78
    /* 2FED40 003FED40 3E180300 */   dsrl32    $3, $3, 0
  .L003FED44:
    /* 2FED44 003FED44 1000868E */  lw         $6, 0x10($20)
    /* 2FED48 003FED48 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FED4C 003FED4C C8C9438C */  lw         $3, %lo(D_0088C9C8)($2)
    /* 2FED50 003FED50 3C230600 */  dsll32     $4, $6, 12
    /* 2FED54 003FED54 FE260400 */  dsrl32     $4, $4, 27
    /* 2FED58 003FED58 83190300 */  sra        $3, $3, 6
    /* 2FED5C 003FED5C 00260400 */  sll        $4, $4, 24
    /* 2FED60 003FED60 001C0300 */  sll        $3, $3, 16
    /* 2FED64 003FED64 FF01C230 */  andi       $2, $6, 0x1FF
    /* 2FED68 003FED68 25188300 */  or         $3, $4, $3
    /* 2FED6C 003FED6C 25104300 */  or         $2, $2, $3
    /* 2FED70 003FED70 3C180200 */  dsll32     $3, $2, 0
    /* 2FED74 003FED74 3E180300 */  dsrl32     $3, $3, 0
  .L003FED78:
    /* 2FED78 003FED78 4C000224 */  addiu      $2, $0, 0x4C
    /* 2FED7C 003FED7C 8900043C */  lui        $4, %hi(D_0088C9D0)
    /* 2FED80 003FED80 89134370 */  pcpyld     $2, $2, $3
    /* 2FED84 003FED84 2000627E */  sq         $2, 0x20($19)
    /* 2FED88 003FED88 40000324 */  addiu      $3, $0, 0x40
    /* 2FED8C 003FED8C 18000224 */  addiu      $2, $0, 0x18
    /* 2FED90 003FED90 89135E70 */  pcpyld     $2, $2, $30
    /* 2FED94 003FED94 3000627E */  sq         $2, 0x30($19)
    /* 2FED98 003FED98 B000A27B */  lq         $2, 0xB0($29)
    /* 2FED9C 003FED9C 89136270 */  pcpyld     $2, $3, $2
    /* 2FEDA0 003FEDA0 4000627E */  sq         $2, 0x40($19)
    /* 2FEDA4 003FEDA4 47000324 */  addiu      $3, $0, 0x47
    /* 2FEDA8 003FEDA8 0300023C */  lui        $2, (0x30000 >> 16)
    /* 2FEDAC 003FEDAC 89136270 */  pcpyld     $2, $3, $2
    /* 2FEDB0 003FEDB0 5000627E */  sq         $2, 0x50($19)
    /* 2FEDB4 003FEDB4 E00183DE */  ld         $3, 0x1E0($20)
    /* 2FEDB8 003FEDB8 01000224 */  addiu      $2, $0, 0x1
    /* 2FEDBC 003FEDBC 3C300200 */  dsll32     $6, $2, 0
    /* 2FEDC0 003FEDC0 3C390300 */  dsll32     $7, $3, 4
    /* 2FEDC4 003FEDC4 3E3F0700 */  dsrl32     $7, $7, 28
    /* 2FEDC8 003FEDC8 FF016330 */  andi       $3, $3, 0x1FF
    /* 2FEDCC 003FEDCC 383E0700 */  dsll       $7, $7, 24
    /* 2FEDD0 003FEDD0 2530E600 */  or         $6, $7, $6
    /* 2FEDD4 003FEDD4 2530C300 */  or         $6, $6, $3
    /* 2FEDD8 003FEDD8 4E000324 */  addiu      $3, $0, 0x4E
    /* 2FEDDC 003FEDDC 891B6670 */  pcpyld     $3, $3, $6
    /* 2FEDE0 003FEDE0 6000637E */  sq         $3, 0x60($19)
    /* 2FEDE4 003FEDE4 D0C9838C */  lw         $3, %lo(D_0088C9D0)($4)
    /* 2FEDE8 003FEDE8 1800612C */  sltiu      $1, $3, 0x18
    /* 2FEDEC 003FEDEC 0A100100 */  movz       $2, $0, $1
    /* 2FEDF0 003FEDF0 45000324 */  addiu      $3, $0, 0x45
    /* 2FEDF4 003FEDF4 89136270 */  pcpyld     $2, $3, $2
    /* 2FEDF8 003FEDF8 7000627E */  sq         $2, 0x70($19)
    /* 2FEDFC 003FEDFC 01004332 */  andi       $3, $18, 0x1
    /* 2FEE00 003FEE00 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FEE04 003FEE04 B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FEE08 003FEE08 8900023C */  lui        $2, %hi(D_0088C9B0)
    /* 2FEE0C 003FEE0C FFFF8464 */  daddiu     $4, $4, -0x1
    /* 2FEE10 003FEE10 B0C9428C */  lw         $2, %lo(D_0088C9B0)($2)
    /* 2FEE14 003FEE14 BC200400 */  dsll32     $4, $4, 2
    /* 2FEE18 003FEE18 FFFF4264 */  daddiu     $2, $2, -0x1
    /* 2FEE1C 003FEE1C B8130200 */  dsll       $2, $2, 14
    /* 2FEE20 003FEE20 25108200 */  or         $2, $4, $2
    /* 2FEE24 003FEE24 0A004434 */  ori        $4, $2, 0xA
    /* 2FEE28 003FEE28 08000224 */  addiu      $2, $0, 0x8
    /* 2FEE2C 003FEE2C 89134470 */  pcpyld     $2, $2, $4
    /* 2FEE30 003FEE30 19006010 */  beqz       $3, .L003FEE98
    /* 2FEE34 003FEE34 8000627E */   sq        $2, 0x80($19)
    /* 2FEE38 003FEE38 0A000224 */  addiu      $2, $0, 0xA
    /* 2FEE3C 003FEE3C D00187DE */  ld         $7, 0x1D0($20)
    /* 2FEE40 003FEE40 3C200200 */  dsll32     $4, $2, 0
    /* 2FEE44 003FEE44 00A80234 */  ori        $2, $0, 0xA800
    /* 2FEE48 003FEE48 381C0200 */  dsll       $3, $2, 16
    /* 2FEE4C 003FEE4C 8900023C */  lui        $2, %hi(D_0088C9B0)
    /* 2FEE50 003FEE50 25206400 */  or         $4, $3, $4
    /* 2FEE54 003FEE54 B0C9438C */  lw         $3, %lo(D_0088C9B0)($2)
    /* 2FEE58 003FEE58 BC300700 */  dsll32     $6, $7, 2
    /* 2FEE5C 003FEE5C BE360600 */  dsrl32     $6, $6, 26
    /* 2FEE60 003FEE60 38350600 */  dsll       $6, $6, 20
    /* 2FEE64 003FEE64 2520C400 */  or         $4, $6, $4
    /* 2FEE68 003FEE68 FF01E230 */  andi       $2, $7, 0x1FF
    /* 2FEE6C 003FEE6C 82190300 */  srl        $3, $3, 6
    /* 2FEE70 003FEE70 3C100200 */  dsll32     $2, $2, 0
    /* 2FEE74 003FEE74 801B0300 */  sll        $3, $3, 14
    /* 2FEE78 003FEE78 3F100200 */  dsra32     $2, $2, 0
    /* 2FEE7C 003FEE7C 3C180300 */  dsll32     $3, $3, 0
    /* 2FEE80 003FEE80 40110200 */  sll        $2, $2, 5
    /* 2FEE84 003FEE84 3E180300 */  dsrl32     $3, $3, 0
    /* 2FEE88 003FEE88 FF3F4230 */  andi       $2, $2, 0x3FFF
    /* 2FEE8C 003FEE8C 25188300 */  or         $3, $4, $3
    /* 2FEE90 003FEE90 18000010 */  b          .L003FEEF4
    /* 2FEE94 003FEE94 25184300 */   or        $3, $2, $3
  .L003FEE98:
    /* 2FEE98 003FEE98 0A000224 */  addiu      $2, $0, 0xA
    /* 2FEE9C 003FEE9C 600087DE */  ld         $7, 0x60($20)
    /* 2FEEA0 003FEEA0 3C200200 */  dsll32     $4, $2, 0
    /* 2FEEA4 003FEEA4 00A80234 */  ori        $2, $0, 0xA800
    /* 2FEEA8 003FEEA8 381C0200 */  dsll       $3, $2, 16
    /* 2FEEAC 003FEEAC 8900023C */  lui        $2, %hi(D_0088C9B0)
    /* 2FEEB0 003FEEB0 25206400 */  or         $4, $3, $4
    /* 2FEEB4 003FEEB4 B0C9438C */  lw         $3, %lo(D_0088C9B0)($2)
    /* 2FEEB8 003FEEB8 BC300700 */  dsll32     $6, $7, 2
    /* 2FEEBC 003FEEBC BE360600 */  dsrl32     $6, $6, 26
    /* 2FEEC0 003FEEC0 38350600 */  dsll       $6, $6, 20
    /* 2FEEC4 003FEEC4 2520C400 */  or         $4, $6, $4
    /* 2FEEC8 003FEEC8 FF01E230 */  andi       $2, $7, 0x1FF
    /* 2FEECC 003FEECC 82190300 */  srl        $3, $3, 6
    /* 2FEED0 003FEED0 3C100200 */  dsll32     $2, $2, 0
    /* 2FEED4 003FEED4 801B0300 */  sll        $3, $3, 14
    /* 2FEED8 003FEED8 3F100200 */  dsra32     $2, $2, 0
    /* 2FEEDC 003FEEDC 3C180300 */  dsll32     $3, $3, 0
    /* 2FEEE0 003FEEE0 40110200 */  sll        $2, $2, 5
    /* 2FEEE4 003FEEE4 3E180300 */  dsrl32     $3, $3, 0
    /* 2FEEE8 003FEEE8 FF3F4230 */  andi       $2, $2, 0x3FFF
    /* 2FEEEC 003FEEEC 25188300 */  or         $3, $4, $3
    /* 2FEEF0 003FEEF0 25184300 */  or         $3, $2, $3
  .L003FEEF4:
    /* 2FEEF4 003FEEF4 06000224 */  addiu      $2, $0, 0x6
    /* 2FEEF8 003FEEF8 89134370 */  pcpyld     $2, $2, $3
    /* 2FEEFC 003FEEFC 9000627E */  sq         $2, 0x90($19)
    /* 2FEF00 003FEF00 61000324 */  addiu      $3, $0, 0x61
    /* 2FEF04 003FEF04 14000224 */  addiu      $2, $0, 0x14
    /* 2FEF08 003FEF08 89134370 */  pcpyld     $2, $2, $3
    /* 2FEF0C 003FEF0C E800A3DF */  ld         $3, 0xE8($29)
    /* 2FEF10 003FEF10 A000627E */  sq         $2, 0xA0($19)
    /* 2FEF14 003FEF14 16000224 */  addiu      $2, $0, 0x16
    /* 2FEF18 003FEF18 89136270 */  pcpyld     $2, $3, $2
    /* 2FEF1C 003FEF1C B000627E */  sq         $2, 0xB0($19)
    /* 2FEF20 003FEF20 01000324 */  addiu      $3, $0, 0x1
    /* 2FEF24 003FEF24 A000A27B */  lq         $2, 0xA0($29)
    /* 2FEF28 003FEF28 89136270 */  pcpyld     $2, $3, $2
    /* 2FEF2C 003FEF2C 0300C012 */  beqz       $22, .L003FEF3C
    /* 2FEF30 003FEF30 C000627E */   sq        $2, 0xC0($19)
    /* 2FEF34 003FEF34 02000010 */  b          .L003FEF40
    /* 2FEF38 003FEF38 2D100002 */   daddu     $2, $16, $0
  .L003FEF3C:
    /* 2FEF3C 003FEF3C 2D102002 */  daddu      $2, $17, $0
  .L003FEF40:
    /* 2FEF40 003FEF40 3C200200 */  dsll32     $4, $2, 0
    /* 2FEF44 003FEF44 A62E110C */  jal        func_0044ba98
    /* 2FEF48 003FEF48 3E200400 */   dsrl32    $4, $4, 0
    /* 2FEF4C 003FEF4C 8046023C */  lui        $2, (0x46800000 >> 16)
    /* 2FEF50 003FEF50 05000324 */  addiu      $3, $0, 0x5
    /* 2FEF54 003FEF54 00088244 */  mtc1       $2, $f1
    /* 2FEF58 003FEF58 8900043C */  lui        $4, %hi(D_0088C9B0)
    /* 2FEF5C 003FEF5C 03000146 */  div.s      $f0, $f0, $f1
    /* 2FEF60 003FEF60 E000A2DF */  ld         $2, 0xE0($29)
    /* 2FEF64 003FEF64 892B6270 */  pcpyld     $5, $3, $2
    /* 2FEF68 003FEF68 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* 2FEF6C 003FEF6C F800A39F */  lwu        $3, 0xF8($29)
    /* 2FEF70 003FEF70 FC00A29F */  lwu        $2, 0xFC($29)
    /* 2FEF74 003FEF74 3C180300 */  dsll32     $3, $3, 0
    /* 2FEF78 003FEF78 25186200 */  or         $3, $3, $2
    /* 2FEF7C 003FEF7C 02000224 */  addiu      $2, $0, 0x2
    /* 2FEF80 003FEF80 89134370 */  pcpyld     $2, $2, $3
    /* 2FEF84 003FEF84 D000627E */  sq         $2, 0xD0($19)
    /* 2FEF88 003FEF88 E000657E */  sq         $5, 0xE0($19)
    /* 2FEF8C 003FEF8C B0C9828C */  lw         $2, %lo(D_0088C9B0)($4)
    /* 2FEF90 003FEF90 00110200 */  sll        $2, $2, 4
    /* 2FEF94 003FEF94 21105500 */  addu       $2, $2, $21
    /* 2FEF98 003FEF98 04004004 */  bltz       $2, .L003FEFAC
    /* 2FEF9C 003FEF9C 00000000 */   nop
    /* 2FEFA0 003FEFA0 00008244 */  mtc1       $2, $f0
    /* 2FEFA4 003FEFA4 08000010 */  b          .L003FEFC8
    /* 2FEFA8 003FEFA8 60008046 */   cvt.s.w   $f1, $f0
  .L003FEFAC:
    /* 2FEFAC 003FEFAC 42180200 */  srl        $3, $2, 1
    /* 2FEFB0 003FEFB0 01004230 */  andi       $2, $2, 0x1
    /* 2FEFB4 003FEFB4 25186200 */  or         $3, $3, $2
    /* 2FEFB8 003FEFB8 00008344 */  mtc1       $3, $f0
    /* 2FEFBC 003FEFBC 00000000 */  nop
    /* 2FEFC0 003FEFC0 60008046 */  cvt.s.w    $f1, $f0
    /* 2FEFC4 003FEFC4 40080146 */  add.s      $f1, $f1, $f1
  .L003FEFC8:
    /* 2FEFC8 003FEFC8 8046023C */  lui        $2, (0x46800000 >> 16)
    /* 2FEFCC 003FEFCC 00008244 */  mtc1       $2, $f0
    /* 2FEFD0 003FEFD0 00000000 */  nop
    /* 2FEFD4 003FEFD4 03080046 */  div.s      $f0, $f1, $f0
    /* 2FEFD8 003FEFD8 00000000 */  nop
    /* 2FEFDC 003FEFDC 00000000 */  nop
    /* 2FEFE0 003FEFE0 0300C012 */  beqz       $22, .L003FEFF0
    /* 2FEFE4 003FEFE4 F400A0E7 */   swc1      $f0, 0xF4($29)
    /* 2FEFE8 003FEFE8 02000010 */  b          .L003FEFF4
    /* 2FEFEC 003FEFEC 2D180002 */   daddu     $3, $16, $0
  .L003FEFF0:
    /* 2FEFF0 003FEFF0 2D182002 */  daddu      $3, $17, $0
  .L003FEFF4:
    /* 2FEFF4 003FEFF4 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FEFF8 003FEFF8 B4C9428C */  lw         $2, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FEFFC 003FEFFC 00110200 */  sll        $2, $2, 4
    /* 2FF000 003FF000 21104300 */  addu       $2, $2, $3
    /* 2FF004 003FF004 04004004 */  bltz       $2, .L003FF018
    /* 2FF008 003FF008 00000000 */   nop
    /* 2FF00C 003FF00C 00008244 */  mtc1       $2, $f0
    /* 2FF010 003FF010 08000010 */  b          .L003FF034
    /* 2FF014 003FF014 60008046 */   cvt.s.w   $f1, $f0
  .L003FF018:
    /* 2FF018 003FF018 42180200 */  srl        $3, $2, 1
    /* 2FF01C 003FF01C 01004230 */  andi       $2, $2, 0x1
    /* 2FF020 003FF020 25186200 */  or         $3, $3, $2
    /* 2FF024 003FF024 00008344 */  mtc1       $3, $f0
    /* 2FF028 003FF028 00000000 */  nop
    /* 2FF02C 003FF02C 60008046 */  cvt.s.w    $f1, $f0
    /* 2FF030 003FF030 40080146 */  add.s      $f1, $f1, $f1
  .L003FF034:
    /* 2FF034 003FF034 8046023C */  lui        $2, (0x46800000 >> 16)
    /* 2FF038 003FF038 8900063C */  lui        $6, %hi(D_0088C9CC)
    /* 2FF03C 003FF03C 00008244 */  mtc1       $2, $f0
    /* 2FF040 003FF040 8900033C */  lui        $3, %hi(D_0088C9C8)
    /* 2FF044 003FF044 2D206002 */  daddu      $4, $19, $0
    /* 2FF048 003FF048 03080046 */  div.s      $f0, $f1, $f0
    /* 2FF04C 003FF04C 40016226 */  addiu      $2, $19, 0x140
    /* 2FF050 003FF050 7F004524 */  addiu      $5, $2, 0x7F
    /* 2FF054 003FF054 F000A0E7 */  swc1       $f0, 0xF0($29)
    /* 2FF058 003FF058 F000A79F */  lwu        $7, 0xF0($29)
    /* 2FF05C 003FF05C F400A29F */  lwu        $2, 0xF4($29)
    /* 2FF060 003FF060 3C380700 */  dsll32     $7, $7, 0
    /* 2FF064 003FF064 2538E200 */  or         $7, $7, $2
    /* 2FF068 003FF068 02000224 */  addiu      $2, $0, 0x2
    /* 2FF06C 003FF06C 89134770 */  pcpyld     $2, $2, $7
    /* 2FF070 003FF070 F000627E */  sq         $2, 0xF0($19)
    /* 2FF074 003FF074 C8C9628C */  lw         $2, %lo(D_0088C9C8)($3)
    /* 2FF078 003FF078 CCC9C68C */  lw         $6, %lo(D_0088C9CC)($6)
    /* 2FF07C 003FF07C 00110200 */  sll        $2, $2, 4
    /* 2FF080 003FF080 001D0600 */  sll        $3, $6, 20
    /* 2FF084 003FF084 25106200 */  or         $2, $3, $2
    /* 2FF088 003FF088 3C180200 */  dsll32     $3, $2, 0
    /* 2FF08C 003FF08C 3F180300 */  dsra32     $3, $3, 0
    /* 2FF090 003FF090 05000224 */  addiu      $2, $0, 0x5
    /* 2FF094 003FF094 89134370 */  pcpyld     $2, $2, $3
    /* 2FF098 003FF098 0001627E */  sq         $2, 0x100($19)
    /* 2FF09C 003FF09C D8B883DF */  ld         $3, -0x4728($28)
    /* 2FF0A0 003FF0A0 18000224 */  addiu      $2, $0, 0x18
    /* 2FF0A4 003FF0A4 89134370 */  pcpyld     $2, $2, $3
    /* 2FF0A8 003FF0A8 1001627E */  sq         $2, 0x110($19)
    /* 2FF0AC 003FF0AC 600083DE */  ld         $3, 0x60($20)
    /* 2FF0B0 003FF0B0 4C000224 */  addiu      $2, $0, 0x4C
    /* 2FF0B4 003FF0B4 89134370 */  pcpyld     $2, $2, $3
    /* 2FF0B8 003FF0B8 2001627E */  sq         $2, 0x120($19)
    /* 2FF0BC 003FF0BC 700083DE */  ld         $3, 0x70($20)
    /* 2FF0C0 003FF0C0 4E000224 */  addiu      $2, $0, 0x4E
    /* 2FF0C4 003FF0C4 89134370 */  pcpyld     $2, $2, $3
    /* 2FF0C8 003FF0C8 3688100C */  jal        func_004220d8
    /* 2FF0CC 003FF0CC 3001627E */   sq        $2, 0x130($19)
    /* 2FF0D0 003FF0D0 01005226 */  addiu      $18, $18, 0x1
    /* 2FF0D4 003FF0D4 0400432E */  sltiu      $3, $18, 0x4
    /* 2FF0D8 003FF0D8 EEFE6014 */  bnez       $3, .L003FEC94
    /* 2FF0DC 003FF0DC 00000000 */   nop
    /* 2FF0E0 003FF0E0 8900043C */  lui        $4, %hi(D_0088C040)
    /* 2FF0E4 003FF0E4 8900033C */  lui        $3, %hi(D_0088C180)
    /* 2FF0E8 003FF0E8 40C08424 */  addiu      $4, $4, %lo(D_0088C040)
    /* 2FF0EC 003FF0EC 80C16324 */  addiu      $3, $3, %lo(D_0088C180)
    /* 2FF0F0 003FF0F0 C00384AE */  sw         $4, 0x3C0($20)
    /* 2FF0F4 003FF0F4 8900043C */  lui        $4, %hi(D_0088C2C0)
    /* 2FF0F8 003FF0F8 C40383AE */  sw         $3, 0x3C4($20)
    /* 2FF0FC 003FF0FC C0C28424 */  addiu      $4, $4, %lo(D_0088C2C0)
    /* 2FF100 003FF100 8900033C */  lui        $3, %hi(D_0088C400)
    /* 2FF104 003FF104 00C46324 */  addiu      $3, $3, %lo(D_0088C400)
    /* 2FF108 003FF108 C80384AE */  sw         $4, 0x3C8($20)
    /* 2FF10C 003FF10C 07000010 */  b          .L003FF12C
    /* 2FF110 003FF110 CC0383AE */   sw        $3, 0x3CC($20)
  .L003FF114:
    /* 2FF114 003FF114 8900133C */  lui        $19, %hi(D_0088C040)
    /* 2FF118 003FF118 EBFE0010 */  b          .L003FECC8
    /* 2FF11C 003FF11C 40C07326 */   addiu     $19, $19, %lo(D_0088C040)
  .L003FF120:
    /* 2FF120 003FF120 8900133C */  lui        $19, %hi(D_0088C180)
    /* 2FF124 003FF124 E8FE0010 */  b          .L003FECC8
    /* 2FF128 003FF128 80C17326 */   addiu     $19, $19, %lo(D_0088C180)
  .L003FF12C:
    /* 2FF12C 003FF12C 9000BFDF */  ld         $31, 0x90($29)
    /* 2FF130 003FF130 8000BE7B */  lq         $30, 0x80($29)
    /* 2FF134 003FF134 7000B77B */  lq         $23, 0x70($29)
    /* 2FF138 003FF138 6000B67B */  lq         $22, 0x60($29)
    /* 2FF13C 003FF13C 5000B57B */  lq         $21, 0x50($29)
    /* 2FF140 003FF140 4000B47B */  lq         $20, 0x40($29)
    /* 2FF144 003FF144 3000B37B */  lq         $19, 0x30($29)
    /* 2FF148 003FF148 2000B27B */  lq         $18, 0x20($29)
    /* 2FF14C 003FF14C 1000B17B */  lq         $17, 0x10($29)
    /* 2FF150 003FF150 0000B07B */  lq         $16, 0x0($29)
    /* 2FF154 003FF154 0800E003 */  jr         $31
    /* 2FF158 003FF158 0001BD27 */   addiu     $29, $29, 0x100
    /* 2FF15C 003FF15C 00000000 */  nop
.size func_003fea90, 0x6d0
