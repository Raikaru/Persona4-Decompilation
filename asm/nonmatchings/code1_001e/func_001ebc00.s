.section .text
.set noat
.set noreorder
glabel func_001ebc00
    /* EBC00 001EBC00 80FFBD27 */  addiu      $29, $29, -0x80
    /* EBC04 001EBC04 6000BFFF */  sd         $31, 0x60($29)
    /* EBC08 001EBC08 5000B57F */  sq         $21, 0x50($29)
    /* EBC0C 001EBC0C 4000B47F */  sq         $20, 0x40($29)
    /* EBC10 001EBC10 3000B37F */  sq         $19, 0x30($29)
    /* EBC14 001EBC14 2000B27F */  sq         $18, 0x20($29)
    /* EBC18 001EBC18 1000B17F */  sq         $17, 0x10($29)
    /* EBC1C 001EBC1C 0000B07F */  sq         $16, 0x0($29)
    /* EBC20 001EBC20 2DA88000 */  daddu      $21, $4, $0
    /* EBC24 001EBC24 2DA0A000 */  daddu      $20, $5, $0
    /* EBC28 001EBC28 3000828C */  lw         $2, 0x30($4)
    /* EBC2C 001EBC2C 640A448C */  lw         $4, 0xA64($2)
    /* EBC30 001EBC30 50F8080C */  jal        func_0023e140
    /* EBC34 001EBC34 00000000 */   nop
    /* EBC38 001EBC38 2D804000 */  daddu      $16, $2, $0
    /* EBC3C 001EBC3C 2D900000 */  daddu      $18, $0, $0
    /* EBC40 001EBC40 2D980000 */  daddu      $19, $0, $0
    /* EBC44 001EBC44 3B010010 */  b          .L001EC134
    /* EBC48 001EBC48 00000000 */   nop
  .L001EBC4C:
    /* EBC4C 001EBC4C FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EBC50 001EBC50 40100200 */  sll        $2, $2, 1
    /* EBC54 001EBC54 21100202 */  addu       $2, $16, $2
    /* EBC58 001EBC58 00005194 */  lhu        $17, 0x0($2)
    /* EBC5C 001EBC5C 33012012 */  beqz       $17, .L001EC12C
    /* EBC60 001EBC60 00000000 */   nop
    /* EBC64 001EBC64 AD000224 */  addiu      $2, $0, 0xAD
    /* EBC68 001EBC68 23012212 */  beq        $17, $2, .L001EC0F8
    /* EBC6C 001EBC6C 00000000 */   nop
    /* EBC70 001EBC70 AC000224 */  addiu      $2, $0, 0xAC
    /* EBC74 001EBC74 20012212 */  beq        $17, $2, .L001EC0F8
    /* EBC78 001EBC78 00000000 */   nop
    /* EBC7C 001EBC7C AB000224 */  addiu      $2, $0, 0xAB
    /* EBC80 001EBC80 1D012212 */  beq        $17, $2, .L001EC0F8
    /* EBC84 001EBC84 00000000 */   nop
    /* EBC88 001EBC88 A9000224 */  addiu      $2, $0, 0xA9
    /* EBC8C 001EBC8C 1A012212 */  beq        $17, $2, .L001EC0F8
    /* EBC90 001EBC90 00000000 */   nop
    /* EBC94 001EBC94 A8000224 */  addiu      $2, $0, 0xA8
    /* EBC98 001EBC98 17012212 */  beq        $17, $2, .L001EC0F8
    /* EBC9C 001EBC9C 00000000 */   nop
    /* EBCA0 001EBCA0 A6000224 */  addiu      $2, $0, 0xA6
    /* EBCA4 001EBCA4 14012212 */  beq        $17, $2, .L001EC0F8
    /* EBCA8 001EBCA8 00000000 */   nop
    /* EBCAC 001EBCAC A5000224 */  addiu      $2, $0, 0xA5
    /* EBCB0 001EBCB0 11012212 */  beq        $17, $2, .L001EC0F8
    /* EBCB4 001EBCB4 00000000 */   nop
    /* EBCB8 001EBCB8 A4000224 */  addiu      $2, $0, 0xA4
    /* EBCBC 001EBCBC 0E012212 */  beq        $17, $2, .L001EC0F8
    /* EBCC0 001EBCC0 00000000 */   nop
    /* EBCC4 001EBCC4 A3000224 */  addiu      $2, $0, 0xA3
    /* EBCC8 001EBCC8 0B012212 */  beq        $17, $2, .L001EC0F8
    /* EBCCC 001EBCCC 00000000 */   nop
    /* EBCD0 001EBCD0 A2000224 */  addiu      $2, $0, 0xA2
    /* EBCD4 001EBCD4 08012212 */  beq        $17, $2, .L001EC0F8
    /* EBCD8 001EBCD8 00000000 */   nop
    /* EBCDC 001EBCDC A1000224 */  addiu      $2, $0, 0xA1
    /* EBCE0 001EBCE0 05012212 */  beq        $17, $2, .L001EC0F8
    /* EBCE4 001EBCE4 00000000 */   nop
    /* EBCE8 001EBCE8 A0000224 */  addiu      $2, $0, 0xA0
    /* EBCEC 001EBCEC 02012212 */  beq        $17, $2, .L001EC0F8
    /* EBCF0 001EBCF0 00000000 */   nop
    /* EBCF4 001EBCF4 9F000224 */  addiu      $2, $0, 0x9F
    /* EBCF8 001EBCF8 FF002212 */  beq        $17, $2, .L001EC0F8
    /* EBCFC 001EBCFC 00000000 */   nop
    /* EBD00 001EBD00 9E000224 */  addiu      $2, $0, 0x9E
    /* EBD04 001EBD04 FC002212 */  beq        $17, $2, .L001EC0F8
    /* EBD08 001EBD08 00000000 */   nop
    /* EBD0C 001EBD0C 9D000224 */  addiu      $2, $0, 0x9D
    /* EBD10 001EBD10 F9002212 */  beq        $17, $2, .L001EC0F8
    /* EBD14 001EBD14 00000000 */   nop
    /* EBD18 001EBD18 9C000224 */  addiu      $2, $0, 0x9C
    /* EBD1C 001EBD1C F6002212 */  beq        $17, $2, .L001EC0F8
    /* EBD20 001EBD20 00000000 */   nop
    /* EBD24 001EBD24 9B000224 */  addiu      $2, $0, 0x9B
    /* EBD28 001EBD28 F3002212 */  beq        $17, $2, .L001EC0F8
    /* EBD2C 001EBD2C 00000000 */   nop
    /* EBD30 001EBD30 9A000224 */  addiu      $2, $0, 0x9A
    /* EBD34 001EBD34 F0002212 */  beq        $17, $2, .L001EC0F8
    /* EBD38 001EBD38 00000000 */   nop
    /* EBD3C 001EBD3C 99000224 */  addiu      $2, $0, 0x99
    /* EBD40 001EBD40 ED002212 */  beq        $17, $2, .L001EC0F8
    /* EBD44 001EBD44 00000000 */   nop
    /* EBD48 001EBD48 98000224 */  addiu      $2, $0, 0x98
    /* EBD4C 001EBD4C EA002212 */  beq        $17, $2, .L001EC0F8
    /* EBD50 001EBD50 00000000 */   nop
    /* EBD54 001EBD54 97000224 */  addiu      $2, $0, 0x97
    /* EBD58 001EBD58 E7002212 */  beq        $17, $2, .L001EC0F8
    /* EBD5C 001EBD5C 00000000 */   nop
    /* EBD60 001EBD60 96000224 */  addiu      $2, $0, 0x96
    /* EBD64 001EBD64 E4002212 */  beq        $17, $2, .L001EC0F8
    /* EBD68 001EBD68 00000000 */   nop
    /* EBD6C 001EBD6C 95000224 */  addiu      $2, $0, 0x95
    /* EBD70 001EBD70 E1002212 */  beq        $17, $2, .L001EC0F8
    /* EBD74 001EBD74 00000000 */   nop
    /* EBD78 001EBD78 94000224 */  addiu      $2, $0, 0x94
    /* EBD7C 001EBD7C DE002212 */  beq        $17, $2, .L001EC0F8
    /* EBD80 001EBD80 00000000 */   nop
    /* EBD84 001EBD84 93000224 */  addiu      $2, $0, 0x93
    /* EBD88 001EBD88 DB002212 */  beq        $17, $2, .L001EC0F8
    /* EBD8C 001EBD8C 00000000 */   nop
    /* EBD90 001EBD90 92000224 */  addiu      $2, $0, 0x92
    /* EBD94 001EBD94 D8002212 */  beq        $17, $2, .L001EC0F8
    /* EBD98 001EBD98 00000000 */   nop
    /* EBD9C 001EBD9C 91000224 */  addiu      $2, $0, 0x91
    /* EBDA0 001EBDA0 D5002212 */  beq        $17, $2, .L001EC0F8
    /* EBDA4 001EBDA4 00000000 */   nop
    /* EBDA8 001EBDA8 90000224 */  addiu      $2, $0, 0x90
    /* EBDAC 001EBDAC D2002212 */  beq        $17, $2, .L001EC0F8
    /* EBDB0 001EBDB0 00000000 */   nop
    /* EBDB4 001EBDB4 8F000224 */  addiu      $2, $0, 0x8F
    /* EBDB8 001EBDB8 CF002212 */  beq        $17, $2, .L001EC0F8
    /* EBDBC 001EBDBC 00000000 */   nop
    /* EBDC0 001EBDC0 8E000224 */  addiu      $2, $0, 0x8E
    /* EBDC4 001EBDC4 CC002212 */  beq        $17, $2, .L001EC0F8
    /* EBDC8 001EBDC8 00000000 */   nop
    /* EBDCC 001EBDCC 8C000224 */  addiu      $2, $0, 0x8C
    /* EBDD0 001EBDD0 C9002212 */  beq        $17, $2, .L001EC0F8
    /* EBDD4 001EBDD4 00000000 */   nop
    /* EBDD8 001EBDD8 8B000224 */  addiu      $2, $0, 0x8B
    /* EBDDC 001EBDDC C6002212 */  beq        $17, $2, .L001EC0F8
    /* EBDE0 001EBDE0 00000000 */   nop
    /* EBDE4 001EBDE4 8A000224 */  addiu      $2, $0, 0x8A
    /* EBDE8 001EBDE8 C3002212 */  beq        $17, $2, .L001EC0F8
    /* EBDEC 001EBDEC 00000000 */   nop
    /* EBDF0 001EBDF0 89000224 */  addiu      $2, $0, 0x89
    /* EBDF4 001EBDF4 C0002212 */  beq        $17, $2, .L001EC0F8
    /* EBDF8 001EBDF8 00000000 */   nop
    /* EBDFC 001EBDFC 88000224 */  addiu      $2, $0, 0x88
    /* EBE00 001EBE00 BD002212 */  beq        $17, $2, .L001EC0F8
    /* EBE04 001EBE04 00000000 */   nop
    /* EBE08 001EBE08 87000224 */  addiu      $2, $0, 0x87
    /* EBE0C 001EBE0C BA002212 */  beq        $17, $2, .L001EC0F8
    /* EBE10 001EBE10 00000000 */   nop
    /* EBE14 001EBE14 86000224 */  addiu      $2, $0, 0x86
    /* EBE18 001EBE18 B7002212 */  beq        $17, $2, .L001EC0F8
    /* EBE1C 001EBE1C 00000000 */   nop
    /* EBE20 001EBE20 85000224 */  addiu      $2, $0, 0x85
    /* EBE24 001EBE24 B4002212 */  beq        $17, $2, .L001EC0F8
    /* EBE28 001EBE28 00000000 */   nop
    /* EBE2C 001EBE2C 84000224 */  addiu      $2, $0, 0x84
    /* EBE30 001EBE30 B1002212 */  beq        $17, $2, .L001EC0F8
    /* EBE34 001EBE34 00000000 */   nop
    /* EBE38 001EBE38 83000224 */  addiu      $2, $0, 0x83
    /* EBE3C 001EBE3C AE002212 */  beq        $17, $2, .L001EC0F8
    /* EBE40 001EBE40 00000000 */   nop
    /* EBE44 001EBE44 82000224 */  addiu      $2, $0, 0x82
    /* EBE48 001EBE48 AB002212 */  beq        $17, $2, .L001EC0F8
    /* EBE4C 001EBE4C 00000000 */   nop
    /* EBE50 001EBE50 81000224 */  addiu      $2, $0, 0x81
    /* EBE54 001EBE54 A8002212 */  beq        $17, $2, .L001EC0F8
    /* EBE58 001EBE58 00000000 */   nop
    /* EBE5C 001EBE5C 80000224 */  addiu      $2, $0, 0x80
    /* EBE60 001EBE60 A5002212 */  beq        $17, $2, .L001EC0F8
    /* EBE64 001EBE64 00000000 */   nop
    /* EBE68 001EBE68 7F000224 */  addiu      $2, $0, 0x7F
    /* EBE6C 001EBE6C A2002212 */  beq        $17, $2, .L001EC0F8
    /* EBE70 001EBE70 00000000 */   nop
    /* EBE74 001EBE74 7E000224 */  addiu      $2, $0, 0x7E
    /* EBE78 001EBE78 9F002212 */  beq        $17, $2, .L001EC0F8
    /* EBE7C 001EBE7C 00000000 */   nop
    /* EBE80 001EBE80 7D000224 */  addiu      $2, $0, 0x7D
    /* EBE84 001EBE84 9C002212 */  beq        $17, $2, .L001EC0F8
    /* EBE88 001EBE88 00000000 */   nop
    /* EBE8C 001EBE8C 7C000224 */  addiu      $2, $0, 0x7C
    /* EBE90 001EBE90 99002212 */  beq        $17, $2, .L001EC0F8
    /* EBE94 001EBE94 00000000 */   nop
    /* EBE98 001EBE98 7B000224 */  addiu      $2, $0, 0x7B
    /* EBE9C 001EBE9C 96002212 */  beq        $17, $2, .L001EC0F8
    /* EBEA0 001EBEA0 00000000 */   nop
    /* EBEA4 001EBEA4 7A000224 */  addiu      $2, $0, 0x7A
    /* EBEA8 001EBEA8 93002212 */  beq        $17, $2, .L001EC0F8
    /* EBEAC 001EBEAC 00000000 */   nop
    /* EBEB0 001EBEB0 79000224 */  addiu      $2, $0, 0x79
    /* EBEB4 001EBEB4 90002212 */  beq        $17, $2, .L001EC0F8
    /* EBEB8 001EBEB8 00000000 */   nop
    /* EBEBC 001EBEBC 78000224 */  addiu      $2, $0, 0x78
    /* EBEC0 001EBEC0 8D002212 */  beq        $17, $2, .L001EC0F8
    /* EBEC4 001EBEC4 00000000 */   nop
    /* EBEC8 001EBEC8 5F000224 */  addiu      $2, $0, 0x5F
    /* EBECC 001EBECC 8A002212 */  beq        $17, $2, .L001EC0F8
    /* EBED0 001EBED0 00000000 */   nop
    /* EBED4 001EBED4 5E000224 */  addiu      $2, $0, 0x5E
    /* EBED8 001EBED8 87002212 */  beq        $17, $2, .L001EC0F8
    /* EBEDC 001EBEDC 00000000 */   nop
    /* EBEE0 001EBEE0 5D000224 */  addiu      $2, $0, 0x5D
    /* EBEE4 001EBEE4 84002212 */  beq        $17, $2, .L001EC0F8
    /* EBEE8 001EBEE8 00000000 */   nop
    /* EBEEC 001EBEEC 5C000224 */  addiu      $2, $0, 0x5C
    /* EBEF0 001EBEF0 81002212 */  beq        $17, $2, .L001EC0F8
    /* EBEF4 001EBEF4 00000000 */   nop
    /* EBEF8 001EBEF8 5B000224 */  addiu      $2, $0, 0x5B
    /* EBEFC 001EBEFC 7E002212 */  beq        $17, $2, .L001EC0F8
    /* EBF00 001EBF00 00000000 */   nop
    /* EBF04 001EBF04 5A000224 */  addiu      $2, $0, 0x5A
    /* EBF08 001EBF08 7B002212 */  beq        $17, $2, .L001EC0F8
    /* EBF0C 001EBF0C 00000000 */   nop
    /* EBF10 001EBF10 59000224 */  addiu      $2, $0, 0x59
    /* EBF14 001EBF14 78002212 */  beq        $17, $2, .L001EC0F8
    /* EBF18 001EBF18 00000000 */   nop
    /* EBF1C 001EBF1C 58000224 */  addiu      $2, $0, 0x58
    /* EBF20 001EBF20 75002212 */  beq        $17, $2, .L001EC0F8
    /* EBF24 001EBF24 00000000 */   nop
    /* EBF28 001EBF28 56000224 */  addiu      $2, $0, 0x56
    /* EBF2C 001EBF2C 72002212 */  beq        $17, $2, .L001EC0F8
    /* EBF30 001EBF30 00000000 */   nop
    /* EBF34 001EBF34 55000224 */  addiu      $2, $0, 0x55
    /* EBF38 001EBF38 6F002212 */  beq        $17, $2, .L001EC0F8
    /* EBF3C 001EBF3C 00000000 */   nop
    /* EBF40 001EBF40 54000224 */  addiu      $2, $0, 0x54
    /* EBF44 001EBF44 6C002212 */  beq        $17, $2, .L001EC0F8
    /* EBF48 001EBF48 00000000 */   nop
    /* EBF4C 001EBF4C 53000224 */  addiu      $2, $0, 0x53
    /* EBF50 001EBF50 69002212 */  beq        $17, $2, .L001EC0F8
    /* EBF54 001EBF54 00000000 */   nop
    /* EBF58 001EBF58 35000224 */  addiu      $2, $0, 0x35
    /* EBF5C 001EBF5C 66002212 */  beq        $17, $2, .L001EC0F8
    /* EBF60 001EBF60 00000000 */   nop
    /* EBF64 001EBF64 34000224 */  addiu      $2, $0, 0x34
    /* EBF68 001EBF68 63002212 */  beq        $17, $2, .L001EC0F8
    /* EBF6C 001EBF6C 00000000 */   nop
    /* EBF70 001EBF70 33000224 */  addiu      $2, $0, 0x33
    /* EBF74 001EBF74 60002212 */  beq        $17, $2, .L001EC0F8
    /* EBF78 001EBF78 00000000 */   nop
    /* EBF7C 001EBF7C 2D000224 */  addiu      $2, $0, 0x2D
    /* EBF80 001EBF80 5D002212 */  beq        $17, $2, .L001EC0F8
    /* EBF84 001EBF84 00000000 */   nop
    /* EBF88 001EBF88 2C000224 */  addiu      $2, $0, 0x2C
    /* EBF8C 001EBF8C 5A002212 */  beq        $17, $2, .L001EC0F8
    /* EBF90 001EBF90 00000000 */   nop
    /* EBF94 001EBF94 2B000224 */  addiu      $2, $0, 0x2B
    /* EBF98 001EBF98 57002212 */  beq        $17, $2, .L001EC0F8
    /* EBF9C 001EBF9C 00000000 */   nop
    /* EBFA0 001EBFA0 2A000224 */  addiu      $2, $0, 0x2A
    /* EBFA4 001EBFA4 54002212 */  beq        $17, $2, .L001EC0F8
    /* EBFA8 001EBFA8 00000000 */   nop
    /* EBFAC 001EBFAC 29000224 */  addiu      $2, $0, 0x29
    /* EBFB0 001EBFB0 51002212 */  beq        $17, $2, .L001EC0F8
    /* EBFB4 001EBFB4 00000000 */   nop
    /* EBFB8 001EBFB8 28000224 */  addiu      $2, $0, 0x28
    /* EBFBC 001EBFBC 4E002212 */  beq        $17, $2, .L001EC0F8
    /* EBFC0 001EBFC0 00000000 */   nop
    /* EBFC4 001EBFC4 27000224 */  addiu      $2, $0, 0x27
    /* EBFC8 001EBFC8 4B002212 */  beq        $17, $2, .L001EC0F8
    /* EBFCC 001EBFCC 00000000 */   nop
    /* EBFD0 001EBFD0 21000224 */  addiu      $2, $0, 0x21
    /* EBFD4 001EBFD4 48002212 */  beq        $17, $2, .L001EC0F8
    /* EBFD8 001EBFD8 00000000 */   nop
    /* EBFDC 001EBFDC 20000224 */  addiu      $2, $0, 0x20
    /* EBFE0 001EBFE0 45002212 */  beq        $17, $2, .L001EC0F8
    /* EBFE4 001EBFE4 00000000 */   nop
    /* EBFE8 001EBFE8 1F000224 */  addiu      $2, $0, 0x1F
    /* EBFEC 001EBFEC 42002212 */  beq        $17, $2, .L001EC0F8
    /* EBFF0 001EBFF0 00000000 */   nop
    /* EBFF4 001EBFF4 1E000224 */  addiu      $2, $0, 0x1E
    /* EBFF8 001EBFF8 3F002212 */  beq        $17, $2, .L001EC0F8
    /* EBFFC 001EBFFC 00000000 */   nop
    /* EC000 001EC000 1D000224 */  addiu      $2, $0, 0x1D
    /* EC004 001EC004 3C002212 */  beq        $17, $2, .L001EC0F8
    /* EC008 001EC008 00000000 */   nop
    /* EC00C 001EC00C 1C000224 */  addiu      $2, $0, 0x1C
    /* EC010 001EC010 39002212 */  beq        $17, $2, .L001EC0F8
    /* EC014 001EC014 00000000 */   nop
    /* EC018 001EC018 1B000224 */  addiu      $2, $0, 0x1B
    /* EC01C 001EC01C 36002212 */  beq        $17, $2, .L001EC0F8
    /* EC020 001EC020 00000000 */   nop
    /* EC024 001EC024 1A000224 */  addiu      $2, $0, 0x1A
    /* EC028 001EC028 33002212 */  beq        $17, $2, .L001EC0F8
    /* EC02C 001EC02C 00000000 */   nop
    /* EC030 001EC030 15000224 */  addiu      $2, $0, 0x15
    /* EC034 001EC034 30002212 */  beq        $17, $2, .L001EC0F8
    /* EC038 001EC038 00000000 */   nop
    /* EC03C 001EC03C 14000224 */  addiu      $2, $0, 0x14
    /* EC040 001EC040 2D002212 */  beq        $17, $2, .L001EC0F8
    /* EC044 001EC044 00000000 */   nop
    /* EC048 001EC048 13000224 */  addiu      $2, $0, 0x13
    /* EC04C 001EC04C 2A002212 */  beq        $17, $2, .L001EC0F8
    /* EC050 001EC050 00000000 */   nop
    /* EC054 001EC054 12000224 */  addiu      $2, $0, 0x12
    /* EC058 001EC058 27002212 */  beq        $17, $2, .L001EC0F8
    /* EC05C 001EC05C 00000000 */   nop
    /* EC060 001EC060 11000224 */  addiu      $2, $0, 0x11
    /* EC064 001EC064 24002212 */  beq        $17, $2, .L001EC0F8
    /* EC068 001EC068 00000000 */   nop
    /* EC06C 001EC06C 10000224 */  addiu      $2, $0, 0x10
    /* EC070 001EC070 21002212 */  beq        $17, $2, .L001EC0F8
    /* EC074 001EC074 00000000 */   nop
    /* EC078 001EC078 0F000224 */  addiu      $2, $0, 0xF
    /* EC07C 001EC07C 1E002212 */  beq        $17, $2, .L001EC0F8
    /* EC080 001EC080 00000000 */   nop
    /* EC084 001EC084 0E000224 */  addiu      $2, $0, 0xE
    /* EC088 001EC088 1B002212 */  beq        $17, $2, .L001EC0F8
    /* EC08C 001EC08C 00000000 */   nop
    /* EC090 001EC090 08000224 */  addiu      $2, $0, 0x8
    /* EC094 001EC094 18002212 */  beq        $17, $2, .L001EC0F8
    /* EC098 001EC098 00000000 */   nop
    /* EC09C 001EC09C 07000224 */  addiu      $2, $0, 0x7
    /* EC0A0 001EC0A0 15002212 */  beq        $17, $2, .L001EC0F8
    /* EC0A4 001EC0A4 00000000 */   nop
    /* EC0A8 001EC0A8 06000224 */  addiu      $2, $0, 0x6
    /* EC0AC 001EC0AC 12002212 */  beq        $17, $2, .L001EC0F8
    /* EC0B0 001EC0B0 00000000 */   nop
    /* EC0B4 001EC0B4 05000224 */  addiu      $2, $0, 0x5
    /* EC0B8 001EC0B8 0F002212 */  beq        $17, $2, .L001EC0F8
    /* EC0BC 001EC0BC 00000000 */   nop
    /* EC0C0 001EC0C0 04000224 */  addiu      $2, $0, 0x4
    /* EC0C4 001EC0C4 0C002212 */  beq        $17, $2, .L001EC0F8
    /* EC0C8 001EC0C8 00000000 */   nop
    /* EC0CC 001EC0CC 03000224 */  addiu      $2, $0, 0x3
    /* EC0D0 001EC0D0 09002212 */  beq        $17, $2, .L001EC0F8
    /* EC0D4 001EC0D4 00000000 */   nop
    /* EC0D8 001EC0D8 02000224 */  addiu      $2, $0, 0x2
    /* EC0DC 001EC0DC 06002212 */  beq        $17, $2, .L001EC0F8
    /* EC0E0 001EC0E0 00000000 */   nop
    /* EC0E4 001EC0E4 01000224 */  addiu      $2, $0, 0x1
    /* EC0E8 001EC0E8 03002212 */  beq        $17, $2, .L001EC0F8
    /* EC0EC 001EC0EC 00000000 */   nop
    /* EC0F0 001EC0F0 0E000010 */  b          .L001EC12C
    /* EC0F4 001EC0F4 00000000 */   nop
  .L001EC0F8:
    /* EC0F8 001EC0F8 3000A28E */  lw         $2, 0x30($21)
    /* EC0FC 001EC0FC 640A448C */  lw         $4, 0xA64($2)
    /* EC100 001EC100 2D282002 */  daddu      $5, $17, $0
    /* EC104 001EC104 70F7080C */  jal        func_0023ddc0
    /* EC108 001EC108 00000000 */   nop
    /* EC10C 001EC10C 07004014 */  bnez       $2, .L001EC12C
    /* EC110 001EC110 00000000 */   nop
    /* EC114 001EC114 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* EC118 001EC118 40100200 */  sll        $2, $2, 1
    /* EC11C 001EC11C 21105D00 */  addu       $2, $2, $29
    /* EC120 001EC120 700051A4 */  sh         $17, 0x70($2)
    /* EC124 001EC124 01004226 */  addiu      $2, $18, 0x1
    /* EC128 001EC128 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001EC12C:
    /* EC12C 001EC12C 01006226 */  addiu      $2, $19, 0x1
    /* EC130 001EC130 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001EC134:
    /* EC134 001EC134 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EC138 001EC138 08004228 */  slti       $2, $2, 0x8
    /* EC13C 001EC13C C3FE4014 */  bnez       $2, .L001EBC4C
    /* EC140 001EC140 00000000 */   nop
    /* EC144 001EC144 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* EC148 001EC148 0A008014 */  bnez       $4, .L001EC174
    /* EC14C 001EC14C 00000000 */   nop
    /* EC150 001EC150 01000224 */  addiu      $2, $0, 0x1
    /* EC154 001EC154 340082A6 */  sh         $2, 0x34($20)
    /* EC158 001EC158 3000A28E */  lw         $2, 0x30($21)
    /* EC15C 001EC15C 640A448C */  lw         $4, 0xA64($2)
    /* EC160 001EC160 F8F7080C */  jal        func_0023dfe0
    /* EC164 001EC164 00000000 */   nop
    /* EC168 001EC168 360082A6 */  sh         $2, 0x36($20)
    /* EC16C 001EC16C 09000010 */  b          .L001EC194
    /* EC170 001EC170 00000000 */   nop
  .L001EC174:
    /* EC174 001EC174 02000224 */  addiu      $2, $0, 0x2
    /* EC178 001EC178 340082A6 */  sh         $2, 0x34($20)
    /* EC17C 001EC17C 5CC7080C */  jal        func_00231d70
    /* EC180 001EC180 00000000 */   nop
    /* EC184 001EC184 40180200 */  sll        $3, $2, 1
    /* EC188 001EC188 21187D00 */  addu       $3, $3, $29
    /* EC18C 001EC18C 70006394 */  lhu        $3, 0x70($3)
    /* EC190 001EC190 360083A6 */  sh         $3, 0x36($20)
  .L001EC194:
    /* EC194 001EC194 6000BFDF */  ld         $31, 0x60($29)
    /* EC198 001EC198 5000B57B */  lq         $21, 0x50($29)
    /* EC19C 001EC19C 4000B47B */  lq         $20, 0x40($29)
    /* EC1A0 001EC1A0 3000B37B */  lq         $19, 0x30($29)
    /* EC1A4 001EC1A4 2000B27B */  lq         $18, 0x20($29)
    /* EC1A8 001EC1A8 1000B17B */  lq         $17, 0x10($29)
    /* EC1AC 001EC1AC 0000B07B */  lq         $16, 0x0($29)
    /* EC1B0 001EC1B0 8000BD27 */  addiu      $29, $29, 0x80
    /* EC1B4 001EC1B4 0800E003 */  jr         $31
    /* EC1B8 001EC1B8 00000000 */   nop
    /* EC1BC 001EC1BC 00000000 */  nop
.size func_001ebc00, 0x5c0
