.section .text
.set noat
.set noreorder
glabel func_003fbc50
    /* 2FBC50 003FBC50 70F7BD27 */  addiu      $29, $29, -0x890
    /* 2FBC54 003FBC54 4000B47F */  sq         $20, 0x40($29)
    /* 2FBC58 003FBC58 3000B37F */  sq         $19, 0x30($29)
    /* 2FBC5C 003FBC5C 2000B27F */  sq         $18, 0x20($29)
    /* 2FBC60 003FBC60 1000B17F */  sq         $17, 0x10($29)
    /* 2FBC64 003FBC64 0000B07F */  sq         $16, 0x0($29)
    /* 2FBC68 003FBC68 1000838C */  lw         $3, 0x10($4)
    /* 2FBC6C 003FBC6C 2A080300 */  slt        $1, $0, $3
    /* 2FBC70 003FBC70 C9002010 */  beqz       $1, .L003FBF98
    /* 2FBC74 003FBC74 2DC00000 */   daddu     $24, $0, $0
    /* 2FBC78 003FBC78 2A080300 */  slt        $1, $0, $3
    /* 2FBC7C 003FBC7C C6002010 */  beqz       $1, .L003FBF98
    /* 2FBC80 003FBC80 5000AD27 */   addiu     $13, $29, 0x50
    /* 2FBC84 003FBC84 6000AC27 */  addiu      $12, $29, 0x60
    /* 2FBC88 003FBC88 7000AB27 */  addiu      $11, $29, 0x70
    /* 2FBC8C 003FBC8C 8000AA27 */  addiu      $10, $29, 0x80
    /* 2FBC90 003FBC90 9000A327 */  addiu      $3, $29, 0x90
  .L003FBC94:
    /* 2FBC94 003FBC94 0C00858C */  lw         $5, 0xC($4)
    /* 2FBC98 003FBC98 2A080500 */  slt        $1, $0, $5
    /* 2FBC9C 003FBC9C A7002010 */  beqz       $1, .L003FBF3C
    /* 2FBCA0 003FBCA0 2DC80000 */   daddu     $25, $0, $0
    /* 2FBCA4 003FBCA4 1800888C */  lw         $8, 0x18($4)
    /* 2FBCA8 003FBCA8 2D780000 */  daddu      $15, $0, $0
    /* 2FBCAC 003FBCAC 0400878C */  lw         $7, 0x4($4)
    /* 2FBCB0 003FBCB0 04000933 */  andi       $9, $24, 0x4
    /* 2FBCB4 003FBCB4 02000627 */  addiu      $6, $24, 0x2
  .L003FBCB8:
    /* 2FBCB8 003FBCB8 18280803 */  mult       $5, $24, $8
    /* 2FBCBC 003FBCBC 2128E500 */  addu       $5, $7, $5
    /* 2FBCC0 003FBCC0 2128B900 */  addu       $5, $5, $25
    /* 2FBCC4 003FBCC4 0000A578 */  lq         $5, 0x0($5)
    /* 2FBCC8 003FBCC8 5000A57F */  sq         $5, 0x50($29)
    /* 2FBCCC 003FBCCC 18280873 */  mult1      $5, $24, $8
    /* 2FBCD0 003FBCD0 2128E500 */  addu       $5, $7, $5
    /* 2FBCD4 003FBCD4 2128B900 */  addu       $5, $5, $25
    /* 2FBCD8 003FBCD8 1000A578 */  lq         $5, 0x10($5)
    /* 2FBCDC 003FBCDC 0000857D */  sq         $5, 0x0($12)
    /* 2FBCE0 003FBCE0 1828C800 */  mult       $5, $6, $8
    /* 2FBCE4 003FBCE4 2128E500 */  addu       $5, $7, $5
    /* 2FBCE8 003FBCE8 2128B900 */  addu       $5, $5, $25
    /* 2FBCEC 003FBCEC 0000A578 */  lq         $5, 0x0($5)
    /* 2FBCF0 003FBCF0 0000657D */  sq         $5, 0x0($11)
    /* 2FBCF4 003FBCF4 1828C870 */  mult1      $5, $6, $8
    /* 2FBCF8 003FBCF8 2D900000 */  daddu      $18, $0, $0
    /* 2FBCFC 003FBCFC 2170E500 */  addu       $14, $7, $5
    /* 2FBD00 003FBD00 2128FD01 */  addu       $5, $15, $29
    /* 2FBD04 003FBD04 9000A0FC */  sd         $0, 0x90($5)
    /* 2FBD08 003FBD08 2128D901 */  addu       $5, $14, $25
    /* 2FBD0C 003FBD0C 1000B078 */  lq         $16, 0x10($5)
    /* 2FBD10 003FBD10 0800E525 */  addiu      $5, $15, 0x8
    /* 2FBD14 003FBD14 0000507D */  sq         $16, 0x0($10)
    /* 2FBD18 003FBD18 2170BD00 */  addu       $14, $5, $29
    /* 2FBD1C 003FBD1C 0002E525 */  addiu      $5, $15, 0x200
    /* 2FBD20 003FBD20 9000C0FD */  sd         $0, 0x90($14)
    /* 2FBD24 003FBD24 2128BD00 */  addu       $5, $5, $29
    /* 2FBD28 003FBD28 9000A0FC */  sd         $0, 0x90($5)
    /* 2FBD2C 003FBD2C 0802E525 */  addiu      $5, $15, 0x208
    /* 2FBD30 003FBD30 2170BD00 */  addu       $14, $5, $29
    /* 2FBD34 003FBD34 0004E525 */  addiu      $5, $15, 0x400
    /* 2FBD38 003FBD38 9000C0FD */  sd         $0, 0x90($14)
    /* 2FBD3C 003FBD3C 2170BD00 */  addu       $14, $5, $29
    /* 2FBD40 003FBD40 0804E525 */  addiu      $5, $15, 0x408
    /* 2FBD44 003FBD44 9000C0FD */  sd         $0, 0x90($14)
    /* 2FBD48 003FBD48 2128BD00 */  addu       $5, $5, $29
    /* 2FBD4C 003FBD4C 9000A0FC */  sd         $0, 0x90($5)
    /* 2FBD50 003FBD50 0006E525 */  addiu      $5, $15, 0x600
    /* 2FBD54 003FBD54 2170BD00 */  addu       $14, $5, $29
    /* 2FBD58 003FBD58 0806E525 */  addiu      $5, $15, 0x608
    /* 2FBD5C 003FBD5C 9000C0FD */  sd         $0, 0x90($14)
    /* 2FBD60 003FBD60 2128BD00 */  addu       $5, $5, $29
    /* 2FBD64 003FBD64 9000A0FC */  sd         $0, 0x90($5)
  .L003FBD68:
    /* 2FBD68 003FBD68 2D880000 */  daddu      $17, $0, $0
  .L003FBD6C:
    /* 2FBD6C 003FBD6C 1B002011 */  beqz       $9, .L003FBDDC
    /* 2FBD70 003FBD70 00000000 */   nop
    /* 2FBD74 003FBD74 21705102 */  addu       $14, $18, $17
    /* 2FBD78 003FBD78 0200D031 */  andi       $16, $14, 0x2
    /* 2FBD7C 003FBD7C 2000C531 */  andi       $5, $14, 0x20
    /* 2FBD80 003FBD80 80801000 */  sll        $16, $16, 2
    /* 2FBD84 003FBD84 43280500 */  sra        $5, $5, 1
    /* 2FBD88 003FBD88 25980502 */  or         $19, $16, $5
    /* 2FBD8C 003FBD8C 0400C531 */  andi       $5, $14, 0x4
    /* 2FBD90 003FBD90 83800500 */  sra        $16, $5, 2
    /* 2FBD94 003FBD94 0800C531 */  andi       $5, $14, 0x8
    /* 2FBD98 003FBD98 25801302 */  or         $16, $16, $19
    /* 2FBD9C 003FBD9C 83280500 */  sra        $5, $5, 2
    /* 2FBDA0 003FBDA0 2598B000 */  or         $19, $5, $16
    /* 2FBDA4 003FBDA4 1000C531 */  andi       $5, $14, 0x10
    /* 2FBDA8 003FBDA8 83800500 */  sra        $16, $5, 2
    /* 2FBDAC 003FBDAC 4000C531 */  andi       $5, $14, 0x40
    /* 2FBDB0 003FBDB0 25801302 */  or         $16, $16, $19
    /* 2FBDB4 003FBDB4 43280500 */  sra        $5, $5, 1
    /* 2FBDB8 003FBDB8 2528B000 */  or         $5, $5, $16
    /* 2FBDBC 003FBDBC 0100D031 */  andi       $16, $14, 0x1
    /* 2FBDC0 003FBDC0 80991000 */  sll        $19, $16, 6
    /* 2FBDC4 003FBDC4 2780C001 */  not        $16, $14
    /* 2FBDC8 003FBDC8 01001032 */  andi       $16, $16, 0x1
    /* 2FBDCC 003FBDCC 80801000 */  sll        $16, $16, 2
    /* 2FBDD0 003FBDD0 25807002 */  or         $16, $19, $16
    /* 2FBDD4 003FBDD4 18000010 */  b          .L003FBE38
    /* 2FBDD8 003FBDD8 2680B000 */   xor       $16, $5, $16
  .L003FBDDC:
    /* 2FBDDC 003FBDDC 21705102 */  addu       $14, $18, $17
    /* 2FBDE0 003FBDE0 0200D031 */  andi       $16, $14, 0x2
    /* 2FBDE4 003FBDE4 0100C531 */  andi       $5, $14, 0x1
    /* 2FBDE8 003FBDE8 80A01000 */  sll        $20, $16, 2
    /* 2FBDEC 003FBDEC 2000D031 */  andi       $16, $14, 0x20
    /* 2FBDF0 003FBDF0 43981000 */  sra        $19, $16, 1
    /* 2FBDF4 003FBDF4 0400D031 */  andi       $16, $14, 0x4
    /* 2FBDF8 003FBDF8 25989302 */  or         $19, $20, $19
    /* 2FBDFC 003FBDFC 83801000 */  sra        $16, $16, 2
    /* 2FBE00 003FBE00 25A01302 */  or         $20, $16, $19
    /* 2FBE04 003FBE04 0800D031 */  andi       $16, $14, 0x8
    /* 2FBE08 003FBE08 83981000 */  sra        $19, $16, 2
    /* 2FBE0C 003FBE0C 1000D031 */  andi       $16, $14, 0x10
    /* 2FBE10 003FBE10 25987402 */  or         $19, $19, $20
    /* 2FBE14 003FBE14 83801000 */  sra        $16, $16, 2
    /* 2FBE18 003FBE18 25A01302 */  or         $20, $16, $19
    /* 2FBE1C 003FBE1C 4000D031 */  andi       $16, $14, 0x40
    /* 2FBE20 003FBE20 43981000 */  sra        $19, $16, 1
    /* 2FBE24 003FBE24 80810500 */  sll        $16, $5, 6
    /* 2FBE28 003FBE28 25987402 */  or         $19, $19, $20
    /* 2FBE2C 003FBE2C 80280500 */  sll        $5, $5, 2
    /* 2FBE30 003FBE30 25280502 */  or         $5, $16, $5
    /* 2FBE34 003FBE34 26806502 */  xor        $16, $19, $5
  .L003FBE38:
    /* 2FBE38 003FBE38 01000532 */  andi       $5, $16, 0x1
    /* 2FBE3C 003FBE3C 1A00A010 */  beqz       $5, .L003FBEA8
    /* 2FBE40 003FBE40 00000000 */   nop
    /* 2FBE44 003FBE44 01002532 */  andi       $5, $17, 0x1
    /* 2FBE48 003FBE48 0600A010 */  beqz       $5, .L003FBE64
    /* 2FBE4C 003FBE4C 00000000 */   nop
    /* 2FBE50 003FBE50 43280E00 */  sra        $5, $14, 1
    /* 2FBE54 003FBE54 2128A501 */  addu       $5, $13, $5
    /* 2FBE58 003FBE58 0000A590 */  lbu        $5, 0x0($5)
    /* 2FBE5C 003FBE5C 06000010 */  b          .L003FBE78
    /* 2FBE60 003FBE60 F000A530 */   andi      $5, $5, 0xF0
  .L003FBE64:
    /* 2FBE64 003FBE64 43280E00 */  sra        $5, $14, 1
    /* 2FBE68 003FBE68 2128A501 */  addu       $5, $13, $5
    /* 2FBE6C 003FBE6C 0000A590 */  lbu        $5, 0x0($5)
    /* 2FBE70 003FBE70 0F00A530 */  andi       $5, $5, 0xF
    /* 2FBE74 003FBE74 00290500 */  sll        $5, $5, 4
  .L003FBE78:
    /* 2FBE78 003FBE78 43711000 */  sra        $14, $16, 5
    /* 2FBE7C 003FBE7C FF00A530 */  andi       $5, $5, 0xFF
    /* 2FBE80 003FBE80 809A0E00 */  sll        $19, $14, 10
    /* 2FBE84 003FBE84 1F000E32 */  andi       $14, $16, 0x1F
    /* 2FBE88 003FBE88 21702E03 */  addu       $14, $25, $14
    /* 2FBE8C 003FBE8C 21706E02 */  addu       $14, $19, $14
    /* 2FBE90 003FBE90 43700E00 */  sra        $14, $14, 1
    /* 2FBE94 003FBE94 2180DD01 */  addu       $16, $14, $29
    /* 2FBE98 003FBE98 90000E92 */  lbu        $14, 0x90($16)
    /* 2FBE9C 003FBE9C 2528C501 */  or         $5, $14, $5
    /* 2FBEA0 003FBEA0 19000010 */  b          .L003FBF08
    /* 2FBEA4 003FBEA4 900005A2 */   sb        $5, 0x90($16)
  .L003FBEA8:
    /* 2FBEA8 003FBEA8 01002532 */  andi       $5, $17, 0x1
    /* 2FBEAC 003FBEAC 0700A010 */  beqz       $5, .L003FBECC
    /* 2FBEB0 003FBEB0 00000000 */   nop
    /* 2FBEB4 003FBEB4 43280E00 */  sra        $5, $14, 1
    /* 2FBEB8 003FBEB8 2128A501 */  addu       $5, $13, $5
    /* 2FBEBC 003FBEBC 0000A590 */  lbu        $5, 0x0($5)
    /* 2FBEC0 003FBEC0 F000A530 */  andi       $5, $5, 0xF0
    /* 2FBEC4 003FBEC4 05000010 */  b          .L003FBEDC
    /* 2FBEC8 003FBEC8 03290500 */   sra       $5, $5, 4
  .L003FBECC:
    /* 2FBECC 003FBECC 43280E00 */  sra        $5, $14, 1
    /* 2FBED0 003FBED0 2128A501 */  addu       $5, $13, $5
    /* 2FBED4 003FBED4 0000A590 */  lbu        $5, 0x0($5)
    /* 2FBED8 003FBED8 0F00A530 */  andi       $5, $5, 0xF
  .L003FBEDC:
    /* 2FBEDC 003FBEDC 43711000 */  sra        $14, $16, 5
    /* 2FBEE0 003FBEE0 FF00A530 */  andi       $5, $5, 0xFF
    /* 2FBEE4 003FBEE4 809A0E00 */  sll        $19, $14, 10
    /* 2FBEE8 003FBEE8 1F000E32 */  andi       $14, $16, 0x1F
    /* 2FBEEC 003FBEEC 21702E03 */  addu       $14, $25, $14
    /* 2FBEF0 003FBEF0 21706E02 */  addu       $14, $19, $14
    /* 2FBEF4 003FBEF4 43700E00 */  sra        $14, $14, 1
    /* 2FBEF8 003FBEF8 2180DD01 */  addu       $16, $14, $29
    /* 2FBEFC 003FBEFC 90000E92 */  lbu        $14, 0x90($16)
    /* 2FBF00 003FBF00 2528C501 */  or         $5, $14, $5
    /* 2FBF04 003FBF04 900005A2 */  sb         $5, 0x90($16)
  .L003FBF08:
    /* 2FBF08 003FBF08 01003126 */  addiu      $17, $17, 0x1
    /* 2FBF0C 003FBF0C 2000252A */  slti       $5, $17, 0x20
    /* 2FBF10 003FBF10 96FFA014 */  bnez       $5, .L003FBD6C
    /* 2FBF14 003FBF14 00000000 */   nop
    /* 2FBF18 003FBF18 20005226 */  addiu      $18, $18, 0x20
    /* 2FBF1C 003FBF1C 8000452A */  slti       $5, $18, 0x80
    /* 2FBF20 003FBF20 91FFA014 */  bnez       $5, .L003FBD68
    /* 2FBF24 003FBF24 00000000 */   nop
    /* 2FBF28 003FBF28 0C00858C */  lw         $5, 0xC($4)
    /* 2FBF2C 003FBF2C 20003927 */  addiu      $25, $25, 0x20
    /* 2FBF30 003FBF30 2A702503 */  slt        $14, $25, $5
    /* 2FBF34 003FBF34 60FFC015 */  bnez       $14, .L003FBCB8
    /* 2FBF38 003FBF38 1000EF25 */   addiu     $15, $15, 0x10
  .L003FBF3C:
    /* 2FBF3C 003FBF3C 2D380000 */  daddu      $7, $0, $0
    /* 2FBF40 003FBF40 2D306000 */  daddu      $6, $3, $0
  .L003FBF44:
    /* 2FBF44 003FBF44 43400500 */  sra        $8, $5, 1
    /* 2FBF48 003FBF48 2A080800 */  slt        $1, $0, $8
    /* 2FBF4C 003FBF4C 14002010 */  beqz       $1, .L003FBFA0
    /* 2FBF50 003FBF50 2D780000 */   daddu     $15, $0, $0
    /* 2FBF54 003FBF54 21700703 */  addu       $14, $24, $7
  .L003FBF58:
    /* 2FBF58 003FBF58 2128CF00 */  addu       $5, $6, $15
    /* 2FBF5C 003FBF5C 0000A978 */  lq         $9, 0x0($5)
    /* 2FBF60 003FBF60 1800858C */  lw         $5, 0x18($4)
    /* 2FBF64 003FBF64 1840AE00 */  mult       $8, $5, $14
    /* 2FBF68 003FBF68 0400858C */  lw         $5, 0x4($4)
    /* 2FBF6C 003FBF6C 2128A800 */  addu       $5, $5, $8
    /* 2FBF70 003FBF70 2128AF00 */  addu       $5, $5, $15
    /* 2FBF74 003FBF74 0000A97C */  sq         $9, 0x0($5)
    /* 2FBF78 003FBF78 1000EF25 */  addiu      $15, $15, 0x10
    /* 2FBF7C 003FBF7C 0C00858C */  lw         $5, 0xC($4)
    /* 2FBF80 003FBF80 43400500 */  sra        $8, $5, 1
    /* 2FBF84 003FBF84 2A40E801 */  slt        $8, $15, $8
    /* 2FBF88 003FBF88 F3FF0015 */  bnez       $8, .L003FBF58
    /* 2FBF8C 003FBF8C 00000000 */   nop
    /* 2FBF90 003FBF90 04000010 */  b          .L003FBFA4
    /* 2FBF94 003FBF94 0100E724 */   addiu     $7, $7, 0x1
  .L003FBF98:
    /* 2FBF98 003FBF98 0C000010 */  b          .L003FBFCC
    /* 2FBF9C 003FBF9C 4000B47B */   lq        $20, 0x40($29)
  .L003FBFA0:
    /* 2FBFA0 003FBFA0 0100E724 */  addiu      $7, $7, 0x1
  .L003FBFA4:
    /* 2FBFA4 003FBFA4 0400E828 */  slti       $8, $7, 0x4
    /* 2FBFA8 003FBFA8 E6FF0015 */  bnez       $8, .L003FBF44
    /* 2FBFAC 003FBFAC 0002C624 */   addiu     $6, $6, 0x200
    /* 2FBFB0 003FBFB0 1000858C */  lw         $5, 0x10($4)
    /* 2FBFB4 003FBFB4 04001827 */  addiu      $24, $24, 0x4
    /* 2FBFB8 003FBFB8 2A280503 */  slt        $5, $24, $5
    /* 2FBFBC 003FBFBC 35FFA014 */  bnez       $5, .L003FBC94
    /* 2FBFC0 003FBFC0 00000000 */   nop
    /* 2FBFC4 003FBFC4 F4FF0010 */  b          .L003FBF98
    /* 2FBFC8 003FBFC8 00000000 */   nop
  .L003FBFCC:
    /* 2FBFCC 003FBFCC 3000B37B */  lq         $19, 0x30($29)
    /* 2FBFD0 003FBFD0 2000B27B */  lq         $18, 0x20($29)
    /* 2FBFD4 003FBFD4 1000B17B */  lq         $17, 0x10($29)
    /* 2FBFD8 003FBFD8 0000B07B */  lq         $16, 0x0($29)
    /* 2FBFDC 003FBFDC 0800E003 */  jr         $31
    /* 2FBFE0 003FBFE0 9008BD27 */   addiu     $29, $29, 0x890
    /* 2FBFE4 003FBFE4 00000000 */  nop
    /* 2FBFE8 003FBFE8 00000000 */  nop
    /* 2FBFEC 003FBFEC 00000000 */  nop
.size func_003fbc50, 0x3a0
