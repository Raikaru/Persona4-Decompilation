.section .text
.set noat
.set noreorder
glabel func_003fd940
    /* 2FD940 003FD940 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 2FD944 003FD944 01000524 */  addiu      $5, $0, 0x1
    /* 2FD948 003FD948 5000BFFF */  sd         $31, 0x50($29)
    /* 2FD94C 003FD94C BC00A627 */  addiu      $6, $29, 0xBC
    /* 2FD950 003FD950 4000B47F */  sq         $20, 0x40($29)
    /* 2FD954 003FD954 B800A727 */  addiu      $7, $29, 0xB8
    /* 2FD958 003FD958 3000B37F */  sq         $19, 0x30($29)
    /* 2FD95C 003FD95C 2000B27F */  sq         $18, 0x20($29)
    /* 2FD960 003FD960 1000B17F */  sq         $17, 0x10($29)
    /* 2FD964 003FD964 0000B07F */  sq         $16, 0x0($29)
    /* 2FD968 003FD968 147C0F0C */  jal        func_003df050
    /* 2FD96C 003FD96C 2D808000 */   daddu     $16, $4, $0
    /* 2FD970 003FD970 8D004010 */  beqz       $2, .L003FDBA8
    /* 2FD974 003FD974 00000000 */   nop
    /* 2FD978 003FD978 B800A38F */  lw         $3, 0xB8($29)
    /* 2FD97C 003FD97C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2FD980 003FD980 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2FD984 003FD984 2B106200 */  sltu       $2, $3, $2
    /* 2FD988 003FD988 CD004014 */  bnez       $2, .L003FDCC0
    /* 2FD98C 003FD98C 00000000 */   nop
    /* 2FD990 003FD990 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2FD994 003FD994 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2FD998 003FD998 2B086100 */  sltu       $1, $3, $1
    /* 2FD99C 003FD99C C8002010 */  beqz       $1, .L003FDCC0
    /* 2FD9A0 003FD9A0 00000000 */   nop
    /* 2FD9A4 003FD9A4 6000A427 */  addiu      $4, $29, 0x60
    /* 2FD9A8 003FD9A8 2D280000 */  daddu      $5, $0, $0
    /* 2FD9AC 003FD9AC 72FE100C */  jal        func_0043f9c8
    /* 2FD9B0 003FD9B0 40000624 */   addiu     $6, $0, 0x40
    /* 2FD9B4 003FD9B4 BC00A68F */  lw         $6, 0xBC($29)
    /* 2FD9B8 003FD9B8 2D200002 */  daddu      $4, $16, $0
    /* 2FD9BC 003FD9BC D87C0F0C */  jal        func_003df360
    /* 2FD9C0 003FD9C0 6000A527 */   addiu     $5, $29, 0x60
    /* 2FD9C4 003FD9C4 7A004010 */  beqz       $2, .L003FDBB0
    /* 2FD9C8 003FD9C8 00000000 */   nop
    /* 2FD9CC 003FD9CC 6E00B327 */  addiu      $19, $29, 0x6E
    /* 2FD9D0 003FD9D0 00006296 */  lhu        $2, 0x0($19)
    /* 2FD9D4 003FD9D4 02004228 */  slti       $2, $2, 0x2
    /* 2FD9D8 003FD9D8 77004014 */  bnez       $2, .L003FDBB8
    /* 2FD9DC 003FD9DC 00000000 */   nop
  .L003FD9E0:
    /* 2FD9E0 003FD9E0 7C00B127 */  addiu      $17, $29, 0x7C
    /* 2FD9E4 003FD9E4 F8AB928F */  lw         $18, -0x5408($28)
    /* 2FD9E8 003FD9E8 0000228E */  lw         $2, 0x0($17)
    /* 2FD9EC 003FD9EC 6C00A797 */  lhu        $7, 0x6C($29)
    /* 2FD9F0 003FD9F0 6000A48F */  lw         $4, 0x60($29)
    /* 2FD9F4 003FD9F4 6400A58F */  lw         $5, 0x64($29)
    /* 2FD9F8 003FD9F8 6800A68F */  lw         $6, 0x68($29)
    /* 2FD9FC 003FD9FC 82100200 */  srl        $2, $2, 2
    /* 2FDA00 003FDA00 01004224 */  addiu      $2, $2, 0x1
    /* 2FDA04 003FDA04 64B10F0C */  jal        func_003ec590
    /* 2FDA08 003FDA08 F8AB82AF */   sw        $2, -0x5408($28)
    /* 2FDA0C 003FDA0C 2DA04000 */  daddu      $20, $2, $0
    /* 2FDA10 003FDA10 F8AB92AF */  sw         $18, -0x5408($28)
    /* 2FDA14 003FDA14 6B008012 */  beqz       $20, .L003FDBC4
    /* 2FDA18 003FDA18 ACB880AF */   sw        $0, -0x4754($28)
    /* 2FDA1C 003FDA1C 38B9838F */  lw         $3, -0x46C8($28)
    /* 2FDA20 003FDA20 7000A28F */  lw         $2, 0x70($29)
    /* 2FDA24 003FDA24 21908302 */  addu       $18, $20, $3
    /* 2FDA28 003FDA28 080042AE */  sw         $2, 0x8($18)
    /* 2FDA2C 003FDA2C 7400A28F */  lw         $2, 0x74($29)
    /* 2FDA30 003FDA30 0C0042AE */  sw         $2, 0xC($18)
    /* 2FDA34 003FDA34 7800A28F */  lw         $2, 0x78($29)
    /* 2FDA38 003FDA38 100042AE */  sw         $2, 0x10($18)
    /* 2FDA3C 003FDA3C 0000228E */  lw         $2, 0x0($17)
    /* 2FDA40 003FDA40 160042A2 */  sb         $2, 0x16($18)
    /* 2FDA44 003FDA44 8000A28F */  lw         $2, 0x80($29)
    /* 2FDA48 003FDA48 180042AE */  sw         $2, 0x18($18)
    /* 2FDA4C 003FDA4C 8400A28F */  lw         $2, 0x84($29)
    /* 2FDA50 003FDA50 1C0042AE */  sw         $2, 0x1C($18)
    /* 2FDA54 003FDA54 8800A28F */  lw         $2, 0x88($29)
    /* 2FDA58 003FDA58 200042AE */  sw         $2, 0x20($18)
    /* 2FDA5C 003FDA5C 8C00A28F */  lw         $2, 0x8C($29)
    /* 2FDA60 003FDA60 240042AE */  sw         $2, 0x24($18)
    /* 2FDA64 003FDA64 9000A28F */  lw         $2, 0x90($29)
    /* 2FDA68 003FDA68 280042AE */  sw         $2, 0x28($18)
    /* 2FDA6C 003FDA6C 9400A28F */  lw         $2, 0x94($29)
    /* 2FDA70 003FDA70 2C0042AE */  sw         $2, 0x2C($18)
    /* 2FDA74 003FDA74 9800A28F */  lw         $2, 0x98($29)
    /* 2FDA78 003FDA78 300042AE */  sw         $2, 0x30($18)
    /* 2FDA7C 003FDA7C 9C00A28F */  lw         $2, 0x9C($29)
    /* 2FDA80 003FDA80 140042A6 */  sh         $2, 0x14($18)
    /* 2FDA84 003FDA84 00006296 */  lhu        $2, 0x0($19)
    /* 2FDA88 003FDA88 02004228 */  slti       $2, $2, 0x2
    /* 2FDA8C 003FDA8C 4F004014 */  bnez       $2, .L003FDBCC
    /* 2FDA90 003FDA90 00000000 */   nop
  .L003FDA94:
    /* 2FDA94 003FDA94 00006396 */  lhu        $3, 0x0($19)
    /* 2FDA98 003FDA98 02006128 */  slti       $1, $3, 0x2
    /* 2FDA9C 003FDA9C 13002010 */  beqz       $1, .L003FDAEC
    /* 2FDAA0 003FDAA0 00000000 */   nop
    /* 2FDAA4 003FDAA4 01000224 */  addiu      $2, $0, 0x1
    /* 2FDAA8 003FDAA8 09006214 */  bne        $3, $2, .L003FDAD0
    /* 2FDAAC 003FDAAC 00000000 */   nop
    /* 2FDAB0 003FDAB0 36004292 */  lbu        $2, 0x36($18)
    /* 2FDAB4 003FDAB4 01004230 */  andi       $2, $2, 0x1
    /* 2FDAB8 003FDAB8 49004014 */  bnez       $2, .L003FDBE0
    /* 2FDABC 003FDABC 00000000 */   nop
    /* 2FDAC0 003FDAC0 36004292 */  lbu        $2, 0x36($18)
    /* 2FDAC4 003FDAC4 02004234 */  ori        $2, $2, 0x2
    /* 2FDAC8 003FDAC8 08000010 */  b          .L003FDAEC
    /* 2FDACC 003FDACC 360042A2 */   sb        $2, 0x36($18)
  .L003FDAD0:
    /* 2FDAD0 003FDAD0 36004292 */  lbu        $2, 0x36($18)
    /* 2FDAD4 003FDAD4 01004230 */  andi       $2, $2, 0x1
    /* 2FDAD8 003FDAD8 45004014 */  bnez       $2, .L003FDBF0
    /* 2FDADC 003FDADC 00000000 */   nop
    /* 2FDAE0 003FDAE0 36004292 */  lbu        $2, 0x36($18)
    /* 2FDAE4 003FDAE4 FD004230 */  andi       $2, $2, 0xFD
    /* 2FDAE8 003FDAE8 360042A2 */  sb         $2, 0x36($18)
  .L003FDAEC:
    /* 2FDAEC 003FDAEC 2D200002 */  daddu      $4, $16, $0
    /* 2FDAF0 003FDAF0 01000524 */  addiu      $5, $0, 0x1
    /* 2FDAF4 003FDAF4 BC00A627 */  addiu      $6, $29, 0xBC
    /* 2FDAF8 003FDAF8 147C0F0C */  jal        func_003df050
    /* 2FDAFC 003FDAFC B800A727 */   addiu     $7, $29, 0xB8
    /* 2FDB00 003FDB00 3F004010 */  beqz       $2, .L003FDC00
    /* 2FDB04 003FDB04 00000000 */   nop
    /* 2FDB08 003FDB08 B800A38F */  lw         $3, 0xB8($29)
    /* 2FDB0C 003FDB0C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2FDB10 003FDB10 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2FDB14 003FDB14 2B106200 */  sltu       $2, $3, $2
    /* 2FDB18 003FDB18 5F004014 */  bnez       $2, .L003FDC98
    /* 2FDB1C 003FDB1C 00000000 */   nop
    /* 2FDB20 003FDB20 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2FDB24 003FDB24 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2FDB28 003FDB28 2B086100 */  sltu       $1, $3, $1
    /* 2FDB2C 003FDB2C 5A002010 */  beqz       $1, .L003FDC98
    /* 2FDB30 003FDB30 00000000 */   nop
    /* 2FDB34 003FDB34 00006396 */  lhu        $3, 0x0($19)
    /* 2FDB38 003FDB38 02006228 */  slti       $2, $3, 0x2
    /* 2FDB3C 003FDB3C 34004014 */  bnez       $2, .L003FDC10
    /* 2FDB40 003FDB40 00000000 */   nop
    /* 2FDB44 003FDB44 02000224 */  addiu      $2, $0, 0x2
    /* 2FDB48 003FDB48 4F006214 */  bne        $3, $2, .L003FDC88
    /* 2FDB4C 003FDB4C 00000000 */   nop
    /* 2FDB50 003FDB50 2400828E */  lw         $2, 0x24($20)
    /* 2FDB54 003FDB54 2D200002 */  daddu      $4, $16, $0
    /* 2FDB58 003FDB58 2800518E */  lw         $17, 0x28($18)
    /* 2FDB5C 003FDB5C 0400458C */  lw         $5, 0x4($2)
    /* 2FDB60 003FDB60 448A0F0C */  jal        func_003e2910
    /* 2FDB64 003FDB64 2D302002 */   daddu     $6, $17, $0
    /* 2FDB68 003FDB68 3A002216 */  bne        $17, $2, .L003FDC54
    /* 2FDB6C 003FDB6C 00000000 */   nop
    /* 2FDB70 003FDB70 2C00518E */  lw         $17, 0x2C($18)
    /* 2FDB74 003FDB74 3B002012 */  beqz       $17, .L003FDC64
    /* 2FDB78 003FDB78 00000000 */   nop
    /* 2FDB7C 003FDB7C 0800828E */  lw         $2, 0x8($20)
    /* 2FDB80 003FDB80 2D200002 */  daddu      $4, $16, $0
    /* 2FDB84 003FDB84 2D302002 */  daddu      $6, $17, $0
    /* 2FDB88 003FDB88 448A0F0C */  jal        func_003e2910
    /* 2FDB8C 003FDB8C B0FF4524 */   addiu     $5, $2, -0x50
    /* 2FDB90 003FDB90 34002212 */  beq        $17, $2, .L003FDC64
    /* 2FDB94 003FDB94 00000000 */   nop
    /* 2FDB98 003FDB98 CCB00F0C */  jal        func_003ec330
    /* 2FDB9C 003FDB9C 2D208002 */   daddu     $4, $20, $0
    /* 2FDBA0 003FDBA0 50000010 */  b          .L003FDCE4
    /* 2FDBA4 003FDBA4 2D100000 */   daddu     $2, $0, $0
  .L003FDBA8:
    /* 2FDBA8 003FDBA8 4E000010 */  b          .L003FDCE4
    /* 2FDBAC 003FDBAC 2D100000 */   daddu     $2, $0, $0
  .L003FDBB0:
    /* 2FDBB0 003FDBB0 4C000010 */  b          .L003FDCE4
    /* 2FDBB4 003FDBB4 2D100000 */   daddu     $2, $0, $0
  .L003FDBB8:
    /* 2FDBB8 003FDBB8 01000224 */  addiu      $2, $0, 0x1
    /* 2FDBBC 003FDBBC 88FF0010 */  b          .L003FD9E0
    /* 2FDBC0 003FDBC0 ACB882AF */   sw        $2, -0x4754($28)
  .L003FDBC4:
    /* 2FDBC4 003FDBC4 47000010 */  b          .L003FDCE4
    /* 2FDBC8 003FDBC8 2D100000 */   daddu     $2, $0, $0
  .L003FDBCC:
    /* 2FDBCC 003FDBCC 0400838E */  lw         $3, 0x4($20)
    /* 2FDBD0 003FDBD0 2800428E */  lw         $2, 0x28($18)
    /* 2FDBD4 003FDBD4 21106200 */  addu       $2, $3, $2
    /* 2FDBD8 003FDBD8 AEFF0010 */  b          .L003FDA94
    /* 2FDBDC 003FDBDC 080082AE */   sw        $2, 0x8($20)
  .L003FDBE0:
    /* 2FDBE0 003FDBE0 CCB00F0C */  jal        func_003ec330
    /* 2FDBE4 003FDBE4 2D208002 */   daddu     $4, $20, $0
    /* 2FDBE8 003FDBE8 3E000010 */  b          .L003FDCE4
    /* 2FDBEC 003FDBEC 2D100000 */   daddu     $2, $0, $0
  .L003FDBF0:
    /* 2FDBF0 003FDBF0 CCB00F0C */  jal        func_003ec330
    /* 2FDBF4 003FDBF4 2D208002 */   daddu     $4, $20, $0
    /* 2FDBF8 003FDBF8 3A000010 */  b          .L003FDCE4
    /* 2FDBFC 003FDBFC 2D100000 */   daddu     $2, $0, $0
  .L003FDC00:
    /* 2FDC00 003FDC00 CCB00F0C */  jal        func_003ec330
    /* 2FDC04 003FDC04 2D208002 */   daddu     $4, $20, $0
    /* 2FDC08 003FDC08 36000010 */  b          .L003FDCE4
    /* 2FDC0C 003FDC0C 2D100000 */   daddu     $2, $0, $0
  .L003FDC10:
    /* 2FDC10 003FDC10 2D200002 */  daddu      $4, $16, $0
    /* 2FDC14 003FDC14 0400858E */  lw         $5, 0x4($20)
    /* 2FDC18 003FDC18 BC00B08F */  lw         $16, 0xBC($29)
    /* 2FDC1C 003FDC1C 448A0F0C */  jal        func_003e2910
    /* 2FDC20 003FDC20 2D300002 */   daddu     $6, $16, $0
    /* 2FDC24 003FDC24 05000212 */  beq        $16, $2, .L003FDC3C
    /* 2FDC28 003FDC28 00000000 */   nop
    /* 2FDC2C 003FDC2C CCB00F0C */  jal        func_003ec330
    /* 2FDC30 003FDC30 2D208002 */   daddu     $4, $20, $0
    /* 2FDC34 003FDC34 2B000010 */  b          .L003FDCE4
    /* 2FDC38 003FDC38 2D100000 */   daddu     $2, $0, $0
  .L003FDC3C:
    /* 2FDC3C 003FDC3C 0400848E */  lw         $4, 0x4($20)
    /* 2FDC40 003FDC40 21109000 */  addu       $2, $4, $16
    /* 2FDC44 003FDC44 3688100C */  jal        func_004220d8
    /* 2FDC48 003FDC48 7F004524 */   addiu     $5, $2, 0x7F
  .L003FDC4C:
    /* 2FDC4C 003FDC4C 25000010 */  b          .L003FDCE4
    /* 2FDC50 003FDC50 2D108002 */   daddu     $2, $20, $0
  .L003FDC54:
    /* 2FDC54 003FDC54 CCB00F0C */  jal        func_003ec330
    /* 2FDC58 003FDC58 2D208002 */   daddu     $4, $20, $0
    /* 2FDC5C 003FDC5C 21000010 */  b          .L003FDCE4
    /* 2FDC60 003FDC60 2D100000 */   daddu     $2, $0, $0
  .L003FDC64:
    /* 2FDC64 003FDC64 2400838E */  lw         $3, 0x24($20)
    /* 2FDC68 003FDC68 0800828E */  lw         $2, 0x8($20)
    /* 2FDC6C 003FDC6C 0400648C */  lw         $4, 0x4($3)
    /* 2FDC70 003FDC70 21105100 */  addu       $2, $2, $17
    /* 2FDC74 003FDC74 B0FF4224 */  addiu      $2, $2, -0x50
    /* 2FDC78 003FDC78 3688100C */  jal        func_004220d8
    /* 2FDC7C 003FDC7C 7F004524 */   addiu     $5, $2, 0x7F
    /* 2FDC80 003FDC80 F2FF0010 */  b          .L003FDC4C
    /* 2FDC84 003FDC84 00000000 */   nop
  .L003FDC88:
    /* 2FDC88 003FDC88 CCB00F0C */  jal        func_003ec330
    /* 2FDC8C 003FDC8C 2D208002 */   daddu     $4, $20, $0
    /* 2FDC90 003FDC90 14000010 */  b          .L003FDCE4
    /* 2FDC94 003FDC94 2D100000 */   daddu     $2, $0, $0
  .L003FDC98:
    /* 2FDC98 003FDC98 01000324 */  addiu      $3, $0, 0x1
    /* 2FDC9C 003FDC9C 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2FDCA0 003FDCA0 B000A3AF */  sw         $3, 0xB0($29)
    /* 2FDCA4 003FDCA4 647D0F0C */  jal        func_003df590
    /* 2FDCA8 003FDCA8 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2FDCAC 003FDCAC B400A2AF */  sw         $2, 0xB4($29)
    /* 2FDCB0 003FDCB0 347D0F0C */  jal        func_003df4d0
    /* 2FDCB4 003FDCB4 B000A427 */   addiu     $4, $29, 0xB0
    /* 2FDCB8 003FDCB8 0A000010 */  b          .L003FDCE4
    /* 2FDCBC 003FDCBC 2D100000 */   daddu     $2, $0, $0
  .L003FDCC0:
    /* 2FDCC0 003FDCC0 01000324 */  addiu      $3, $0, 0x1
    /* 2FDCC4 003FDCC4 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2FDCC8 003FDCC8 A800A3AF */  sw         $3, 0xA8($29)
    /* 2FDCCC 003FDCCC 647D0F0C */  jal        func_003df590
    /* 2FDCD0 003FDCD0 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2FDCD4 003FDCD4 AC00A2AF */  sw         $2, 0xAC($29)
    /* 2FDCD8 003FDCD8 347D0F0C */  jal        func_003df4d0
    /* 2FDCDC 003FDCDC A800A427 */   addiu     $4, $29, 0xA8
    /* 2FDCE0 003FDCE0 2D100000 */  daddu      $2, $0, $0
  .L003FDCE4:
    /* 2FDCE4 003FDCE4 5000BFDF */  ld         $31, 0x50($29)
    /* 2FDCE8 003FDCE8 4000B47B */  lq         $20, 0x40($29)
    /* 2FDCEC 003FDCEC 3000B37B */  lq         $19, 0x30($29)
    /* 2FDCF0 003FDCF0 2000B27B */  lq         $18, 0x20($29)
    /* 2FDCF4 003FDCF4 1000B17B */  lq         $17, 0x10($29)
    /* 2FDCF8 003FDCF8 0000B07B */  lq         $16, 0x0($29)
    /* 2FDCFC 003FDCFC 0800E003 */  jr         $31
    /* 2FDD00 003FDD00 C000BD27 */   addiu     $29, $29, 0xC0
    /* 2FDD04 003FDD04 00000000 */  nop
    /* 2FDD08 003FDD08 00000000 */  nop
    /* 2FDD0C 003FDD0C 00000000 */  nop
.size func_003fd940, 0x3d0
