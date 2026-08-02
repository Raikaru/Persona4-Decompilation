.section .text
.set noat
.set noreorder
glabel func_0036fed0
    /* 26FED0 0036FED0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 26FED4 0036FED4 3000BFFF */  sd         $31, 0x30($29)
    /* 26FED8 0036FED8 2000B27F */  sq         $18, 0x20($29)
    /* 26FEDC 0036FEDC 1000B17F */  sq         $17, 0x10($29)
    /* 26FEE0 0036FEE0 0000B07F */  sq         $16, 0x0($29)
    /* 26FEE4 0036FEE4 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* 26FEE8 0036FEE8 0B000012 */  beqz       $16, .L0036FF18
    /* 26FEEC 0036FEEC 00000000 */   nop
    /* 26FEF0 0036FEF0 01000424 */  addiu      $4, $0, 0x1
    /* 26FEF4 0036FEF4 8C13040C */  jal        func_00104e30
    /* 26FEF8 0036FEF8 00000000 */   nop
    /* 26FEFC 0036FEFC 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FF00 0036FF00 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FF04 0036FF04 01000424 */  addiu      $4, $0, 0x1
    /* 26FF08 0036FF08 CC15040C */  jal        func_00105730
    /* 26FF0C 0036FF0C 00000000 */   nop
    /* 26FF10 0036FF10 0B000010 */  b          .L0036FF40
    /* 26FF14 0036FF14 00000000 */   nop
  .L0036FF18:
    /* 26FF18 0036FF18 01000424 */  addiu      $4, $0, 0x1
    /* 26FF1C 0036FF1C 5413040C */  jal        func_00104d50
    /* 26FF20 0036FF20 00000000 */   nop
    /* 26FF24 0036FF24 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 26FF28 0036FF28 42100200 */  srl        $2, $2, 1
    /* 26FF2C 0036FF2C 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FF30 0036FF30 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FF34 0036FF34 01000424 */  addiu      $4, $0, 0x1
    /* 26FF38 0036FF38 CC15040C */  jal        func_00105730
    /* 26FF3C 0036FF3C 00000000 */   nop
  .L0036FF40:
    /* 26FF40 0036FF40 2D880000 */  daddu      $17, $0, $0
    /* 26FF44 0036FF44 28000010 */  b          .L0036FFE8
    /* 26FF48 0036FF48 00000000 */   nop
  .L0036FF4C:
    /* 26FF4C 0036FF4C B817040C */  jal        func_00105ee0
    /* 26FF50 0036FF50 00000000 */   nop
    /* 26FF54 0036FF54 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* 26FF58 0036FF58 21004012 */  beqz       $18, .L0036FFE0
    /* 26FF5C 0036FF5C 00000000 */   nop
    /* 26FF60 0036FF60 3C241200 */  dsll32     $4, $18, 16
    /* 26FF64 0036FF64 3F240400 */  dsra32     $4, $4, 16
    /* 26FF68 0036FF68 8415040C */  jal        func_00105610
    /* 26FF6C 0036FF6C 00000000 */   nop
    /* 26FF70 0036FF70 1B004014 */  bnez       $2, .L0036FFE0
    /* 26FF74 0036FF74 00000000 */   nop
    /* 26FF78 0036FF78 0D000012 */  beqz       $16, .L0036FFB0
    /* 26FF7C 0036FF7C 00000000 */   nop
    /* 26FF80 0036FF80 3C941200 */  dsll32     $18, $18, 16
    /* 26FF84 0036FF84 3F941200 */  dsra32     $18, $18, 16
    /* 26FF88 0036FF88 2D204002 */  daddu      $4, $18, $0
    /* 26FF8C 0036FF8C 8C13040C */  jal        func_00104e30
    /* 26FF90 0036FF90 00000000 */   nop
    /* 26FF94 0036FF94 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FF98 0036FF98 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FF9C 0036FF9C 2D204002 */  daddu      $4, $18, $0
    /* 26FFA0 0036FFA0 CC15040C */  jal        func_00105730
    /* 26FFA4 0036FFA4 00000000 */   nop
    /* 26FFA8 0036FFA8 0D000010 */  b          .L0036FFE0
    /* 26FFAC 0036FFAC 00000000 */   nop
  .L0036FFB0:
    /* 26FFB0 0036FFB0 3C941200 */  dsll32     $18, $18, 16
    /* 26FFB4 0036FFB4 3F941200 */  dsra32     $18, $18, 16
    /* 26FFB8 0036FFB8 2D204002 */  daddu      $4, $18, $0
    /* 26FFBC 0036FFBC 5413040C */  jal        func_00104d50
    /* 26FFC0 0036FFC0 00000000 */   nop
    /* 26FFC4 0036FFC4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 26FFC8 0036FFC8 42100200 */  srl        $2, $2, 1
    /* 26FFCC 0036FFCC 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FFD0 0036FFD0 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FFD4 0036FFD4 2D204002 */  daddu      $4, $18, $0
    /* 26FFD8 0036FFD8 CC15040C */  jal        func_00105730
    /* 26FFDC 0036FFDC 00000000 */   nop
  .L0036FFE0:
    /* 26FFE0 0036FFE0 01002226 */  addiu      $2, $17, 0x1
    /* 26FFE4 0036FFE4 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L0036FFE8:
    /* 26FFE8 0036FFE8 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* 26FFEC 0036FFEC 04008228 */  slti       $2, $4, 0x4
    /* 26FFF0 0036FFF0 D6FF4014 */  bnez       $2, .L0036FF4C
    /* 26FFF4 0036FFF4 00000000 */   nop
    /* 26FFF8 0036FFF8 01000224 */  addiu      $2, $0, 0x1
    /* 26FFFC 0036FFFC 3000BFDF */  ld         $31, 0x30($29)
    /* 270000 00370000 2000B27B */  lq         $18, 0x20($29)
    /* 270004 00370004 1000B17B */  lq         $17, 0x10($29)
    /* 270008 00370008 0000B07B */  lq         $16, 0x0($29)
    /* 27000C 0037000C 4000BD27 */  addiu      $29, $29, 0x40
    /* 270010 00370010 0800E003 */  jr         $31
    /* 270014 00370014 00000000 */   nop
    /* 270018 00370018 00000000 */  nop
    /* 27001C 0037001C 00000000 */  nop
.size func_0036fed0, 0x150
