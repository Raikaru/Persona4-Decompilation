.section .text
.set noat
.set noreorder
glabel func_0043eb98
    /* 33EB98 0043EB98 70FFBD27 */  addiu      $29, $29, -0x90
    /* 33EB9C 0043EB9C 7000B0FF */  sd         $16, 0x70($29)
    /* 33EBA0 0043EBA0 7800B1FF */  sd         $17, 0x78($29)
    /* 33EBA4 0043EBA4 8000B2FF */  sd         $18, 0x80($29)
    /* 33EBA8 0043EBA8 8800BFFF */  sd         $31, 0x88($29)
    /* 33EBAC 0043EBAC 0C008E94 */  lhu        $14, 0xC($4)
    /* 33EBB0 0043EBB0 0200CF31 */  andi       $15, $14, 0x2
    /* 33EBB4 0043EBB4 0C00E011 */  beqz       $15, .L0043EBE8
    /* 33EBB8 0043EBB8 2D808000 */   daddu     $16, $4, $0
    /* 33EBBC 0043EBBC 43008E24 */  addiu      $14, $4, 0x43
    /* 33EBC0 0043EBC0 01000F24 */  addiu      $15, $0, 0x1
    /* 33EBC4 0043EBC4 14008FAC */  sw         $15, 0x14($4)
    /* 33EBC8 0043EBC8 10008EAC */  sw         $14, 0x10($4)
    /* 33EBCC 0043EBCC 00008EAC */  sw         $14, 0x0($4)
  .L0043EBD0:
    /* 33EBD0 0043EBD0 7000B0DF */  ld         $16, 0x70($29)
  .L0043EBD4:
    /* 33EBD4 0043EBD4 7800B1DF */  ld         $17, 0x78($29)
    /* 33EBD8 0043EBD8 8000B2DF */  ld         $18, 0x80($29)
    /* 33EBDC 0043EBDC 8800BFDF */  ld         $31, 0x88($29)
    /* 33EBE0 0043EBE0 0800E003 */  jr         $31
    /* 33EBE4 0043EBE4 9000BD27 */   addiu     $29, $29, 0x90
  .L0043EBE8:
    /* 33EBE8 0043EBE8 0E008584 */  lh         $5, 0xE($4)
    /* 33EBEC 0043EBEC 0800A004 */  bltz       $5, .L0043EC10
    /* 33EBF0 0043EBF0 0008CF35 */   ori       $15, $14, 0x800
    /* 33EBF4 0043EBF4 5400848C */  lw         $4, 0x54($4)
    /* 33EBF8 0043EBF8 6CF9100C */  jal        func_0043e5b0
    /* 33EBFC 0043EBFC 2D30A003 */   daddu     $6, $29, $0
    /* 33EC00 0043EC00 25004104 */  bgez       $2, .L0043EC98
    /* 33EC04 0043EC04 0400AF8F */   lw        $15, 0x4($29)
    /* 33EC08 0043EC08 0C000E96 */  lhu        $14, 0xC($16)
    /* 33EC0C 0043EC0C 0008CF35 */  ori        $15, $14, 0x800
  .L0043EC10:
    /* 33EC10 0043EC10 2D900000 */  daddu      $18, $0, $0
    /* 33EC14 0043EC14 0C000FA6 */  sh         $15, 0xC($16)
    /* 33EC18 0043EC18 00041124 */  addiu      $17, $0, 0x400
  .L0043EC1C:
    /* 33EC1C 0043EC1C 5400048E */  lw         $4, 0x54($16)
    /* 33EC20 0043EC20 E0FB100C */  jal        func_0043ef80
    /* 33EC24 0043EC24 00040524 */   addiu     $5, $0, 0x400
    /* 33EC28 0043EC28 09004014 */  bnez       $2, .L0043EC50
    /* 33EC2C 0043EC2C 0C000F96 */   lhu       $15, 0xC($16)
    /* 33EC30 0043EC30 43000D26 */  addiu      $13, $16, 0x43
    /* 33EC34 0043EC34 01000E24 */  addiu      $14, $0, 0x1
    /* 33EC38 0043EC38 10000DAE */  sw         $13, 0x10($16)
    /* 33EC3C 0043EC3C 0200EF35 */  ori        $15, $15, 0x2
    /* 33EC40 0043EC40 14000EAE */  sw         $14, 0x14($16)
    /* 33EC44 0043EC44 0C000FA6 */  sh         $15, 0xC($16)
    /* 33EC48 0043EC48 E1FF0010 */  b          .L0043EBD0
    /* 33EC4C 0043EC4C 00000DAE */   sw        $13, 0x0($16)
  .L0043EC50:
    /* 33EC50 0043EC50 44000E3C */  lui        $14, %hi(func_0043DFA0)
    /* 33EC54 0043EC54 54000D8E */  lw         $13, 0x54($16)
    /* 33EC58 0043EC58 A0DFCE25 */  addiu      $14, $14, %lo(func_0043DFA0)
    /* 33EC5C 0043EC5C 8000EF35 */  ori        $15, $15, 0x80
    /* 33EC60 0043EC60 100002AE */  sw         $2, 0x10($16)
    /* 33EC64 0043EC64 3C00AEAD */  sw         $14, 0x3C($13)
    /* 33EC68 0043EC68 0C000FA6 */  sh         $15, 0xC($16)
    /* 33EC6C 0043EC6C 140011AE */  sw         $17, 0x14($16)
    /* 33EC70 0043EC70 D7FF4012 */  beqz       $18, .L0043EBD0
    /* 33EC74 0043EC74 000002AE */   sw        $2, 0x0($16)
    /* 33EC78 0043EC78 E487100C */  jal        func_00421f90
    /* 33EC7C 0043EC7C 0E000486 */   lh        $4, 0xE($16)
    /* 33EC80 0043EC80 D4FF4050 */  beql       $2, $0, .L0043EBD4
    /* 33EC84 0043EC84 7000B0DF */   ld        $16, 0x70($29)
    /* 33EC88 0043EC88 0C000F96 */  lhu        $15, 0xC($16)
    /* 33EC8C 0043EC8C 0100EF35 */  ori        $15, $15, 0x1
    /* 33EC90 0043EC90 CFFF0010 */  b          .L0043EBD0
    /* 33EC94 0043EC94 0C000FA6 */   sh        $15, 0xC($16)
  .L0043EC98:
    /* 33EC98 0043EC98 00041124 */  addiu      $17, $0, 0x400
    /* 33EC9C 0043EC9C 00800D34 */  ori        $13, $0, 0x8000
    /* 33ECA0 0043ECA0 00F0EF31 */  andi       $15, $15, 0xF000
    /* 33ECA4 0043ECA4 0020EE39 */  xori       $14, $15, 0x2000
    /* 33ECA8 0043ECA8 0B00ED15 */  bne        $15, $13, .L0043ECD8
    /* 33ECAC 0043ECAC 0100D22D */   sltiu     $18, $14, 0x1
    /* 33ECB0 0043ECB0 44000F3C */  lui        $15, %hi(func_00442300)
    /* 33ECB4 0043ECB4 28000E8E */  lw         $14, 0x28($16)
    /* 33ECB8 0043ECB8 0023EF25 */  addiu      $15, $15, %lo(func_00442300)
    /* 33ECBC 0043ECBC 0700CF15 */  bne        $14, $15, .L0043ECDC
    /* 33ECC0 0043ECC0 0C000F96 */   lhu       $15, 0xC($16)
    /* 33ECC4 0043ECC4 4C0011AE */  sw         $17, 0x4C($16)
    /* 33ECC8 0043ECC8 0004EF35 */  ori        $15, $15, 0x400
    /* 33ECCC 0043ECCC 00000000 */  nop
  .L0043ECD0:
    /* 33ECD0 0043ECD0 D2FF0010 */  b          .L0043EC1C
    /* 33ECD4 0043ECD4 0C000FA6 */   sh        $15, 0xC($16)
  .L0043ECD8:
    /* 33ECD8 0043ECD8 0C000F96 */  lhu        $15, 0xC($16)
  .L0043ECDC:
    /* 33ECDC 0043ECDC FCFF0010 */  b          .L0043ECD0
    /* 33ECE0 0043ECE0 0008EF35 */   ori       $15, $15, 0x800
    /* 33ECE4 0043ECE4 00000000 */  nop
.size func_0043eb98, 0x150
