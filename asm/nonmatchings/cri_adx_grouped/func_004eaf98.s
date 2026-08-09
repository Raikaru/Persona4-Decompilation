.section .text
.set noat
.set noreorder
glabel func_004eaf98
    /* 3EAF98 004EAF98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EAF9C 004EAF9C 2D388000 */  daddu      $7, $4, $0
    /* 3EAFA0 004EAFA0 0000BFFF */  sd         $31, 0x0($29)
    /* 3EAFA4 004EAFA4 0600E014 */  bnez       $7, .L004EAFC0
    /* 3EAFA8 004EAFA8 2D20A000 */   daddu     $4, $5, $0
    /* 3EAFAC 004EAFAC 7600043C */  lui        $4, %hi(D_0075C550)
    /* 3EAFB0 004EAFB0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAFB4 004EAFB4 50C58424 */  addiu      $4, $4, %lo(D_0075C550)
    /* 3EAFB8 004EAFB8 E6A91308 */  j          func_004ea798
    /* 3EAFBC 004EAFBC 1000BD27 */   addiu     $29, $29, 0x10
  .L004EAFC0:
    /* 3EAFC0 004EAFC0 0700801C */  bgtz       $4, .L004EAFE0
    /* 3EAFC4 004EAFC4 EE020324 */   addiu     $3, $0, 0x2EE
    /* 3EAFC8 004EAFC8 7600043C */  lui        $4, %hi(D_0075C578)
    /* 3EAFCC 004EAFCC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAFD0 004EAFD0 78C58424 */  addiu      $4, $4, %lo(D_0075C578)
    /* 3EAFD4 004EAFD4 E6A91308 */  j          func_004ea798
    /* 3EAFD8 004EAFD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EAFDC 004EAFDC 00000000 */  nop
  .L004EAFE0:
    /* 3EAFE0 004EAFE0 01000524 */  addiu      $5, $0, 0x1
    /* 3EAFE4 004EAFE4 1A008300 */  div        $0, $4, $3
    /* 3EAFE8 004EAFE8 01006050 */  beql       $3, $0, .L004EAFF0
    /* 3EAFEC 004EAFEC CD010000 */   break     0, 7
  .L004EAFF0:
    /* 3EAFF0 004EAFF0 1000E4AC */  sw         $4, 0x10($7)
    /* 3EAFF4 004EAFF4 60000624 */  addiu      $6, $0, 0x60
    /* 3EAFF8 004EAFF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAFFC 004EAFFC 12100000 */  mflo       $2
    /* 3EB000 004EB000 61004328 */  slti       $3, $2, 0x61
    /* 3EB004 004EB004 2A200200 */  slt        $4, $0, $2
    /* 3EB008 004EB008 0A10A400 */  movz       $2, $5, $4
    /* 3EB00C 004EB00C 00006338 */  xori       $3, $3, 0x0
    /* 3EB010 004EB010 0A10C300 */  movz       $2, $6, $3
    /* 3EB014 004EB014 1800E2AC */  sw         $2, 0x18($7)
    /* 3EB018 004EB018 0800E003 */  jr         $31
    /* 3EB01C 004EB01C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eaf98, 0x88
