.section .text
.set noat
.set noreorder
glabel func_004bdaf0
    /* 3BDAF0 004BDAF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BDAF4 004BDAF4 40FC0224 */  addiu      $2, $0, -0x3C0
    /* 3BDAF8 004BDAF8 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDAFC 004BDAFC 2D80A000 */  daddu      $16, $5, $0
    /* 3BDB00 004BDB00 0800B1FF */  sd         $17, 0x8($29)
    /* 3BDB04 004BDB04 41000012 */  beqz       $16, .L004BDC0C
    /* 3BDB08 004BDB08 1000BFFF */   sd        $31, 0x10($29)
    /* 3BDB0C 004BDB0C 3100113C */  lui        $17, (0x316938 >> 16)
    /* 3BDB10 004BDB10 38693136 */  ori        $17, $17, (0x316938 & 0xFFFF)
    /* 3BDB14 004BDB14 3D001112 */  beq        $16, $17, .L004BDC0C
    /* 3BDB18 004BDB18 2D100000 */   daddu     $2, $0, $0
    /* 3BDB1C 004BDB1C 18008480 */  lb         $4, 0x18($4)
    /* 3BDB20 004BDB20 03008010 */  beqz       $4, .L004BDB30
    /* 3BDB24 004BDB24 01000224 */   addiu     $2, $0, 0x1
    /* 3BDB28 004BDB28 15008210 */  beq        $4, $2, .L004BDB80
    /* 3BDB2C 004BDB2C 00000000 */   nop
  .L004BDB30:
    /* 3BDB30 004BDB30 7500023C */  lui        $2, %hi(D_007568C0)
    /* 3BDB34 004BDB34 00009044 */  mtc1       $16, $f0
    /* 3BDB38 004BDB38 20008046 */  cvt.s.w    $f0, $f0
    /* 3BDB3C 004BDB3C C0684CC4 */  lwc1       $f12, %lo(D_007568C0)($2)
    /* 3BDB40 004BDB40 20638046 */  cvt.s.w    $f12, $f12
    /* 3BDB44 004BDB44 00000000 */  nop
    /* 3BDB48 004BDB48 00000000 */  nop
    /* 3BDB4C 004BDB4C 03030C46 */  div.s      $f12, $f0, $f12
    /* 3BDB50 004BDB50 3637110C */  jal        func_0044dcd8
    /* 3BDB54 004BDB54 00000000 */   nop
    /* 3BDB58 004BDB58 3C2E110C */  jal        func_0044b8f0
    /* 3BDB5C 004BDB5C 2D204000 */   daddu     $4, $2, $0
    /* 3BDB60 004BDB60 D2800534 */  ori        $5, $0, 0x80D2
    /* 3BDB64 004BDB64 FC2B0500 */  dsll32     $5, $5, 15
    /* 3BDB68 004BDB68 5A38110C */  jal        func_0044e168
    /* 3BDB6C 004BDB6C 2D204000 */   daddu     $4, $2, $0
    /* 3BDB70 004BDB70 F639110C */  jal        func_0044e7d8
    /* 3BDB74 004BDB74 2D204000 */   daddu     $4, $2, $0
    /* 3BDB78 004BDB78 19000010 */  b          .L004BDBE0
    /* 3BDB7C 004BDB7C 00000000 */   nop
  .L004BDB80:
    /* 3BDB80 004BDB80 1C810434 */  ori        $4, $0, 0x811C
    /* 3BDB84 004BDB84 3C2E110C */  jal        func_0044b8f0
    /* 3BDB88 004BDB88 FC230400 */   dsll32    $4, $4, 15
    /* 3BDB8C 004BDB8C F639110C */  jal        func_0044e7d8
    /* 3BDB90 004BDB90 2D204000 */   daddu     $4, $2, $0
    /* 3BDB94 004BDB94 23103002 */  subu       $2, $17, $16
    /* 3BDB98 004BDB98 00088244 */  mtc1       $2, $f1
    /* 3BDB9C 004BDB9C 60088046 */  cvt.s.w    $f1, $f1
    /* 3BDBA0 004BDBA0 7500033C */  lui        $3, %hi(D_007568C0)
    /* 3BDBA4 004BDBA4 C0686CC4 */  lwc1       $f12, %lo(D_007568C0)($3)
    /* 3BDBA8 004BDBA8 20638046 */  cvt.s.w    $f12, $f12
    /* 3BDBAC 004BDBAC 02000146 */  mul.s      $f0, $f0, $f1
    /* 3BDBB0 004BDBB0 00000000 */  nop
    /* 3BDBB4 004BDBB4 00000000 */  nop
    /* 3BDBB8 004BDBB8 03030C46 */  div.s      $f12, $f0, $f12
    /* 3BDBBC 004BDBBC 3637110C */  jal        func_0044dcd8
    /* 3BDBC0 004BDBC0 00000000 */   nop
    /* 3BDBC4 004BDBC4 48800434 */  ori        $4, $0, 0x8048
    /* 3BDBC8 004BDBC8 FC230400 */  dsll32     $4, $4, 15
    /* 3BDBCC 004BDBCC 422E110C */  jal        func_0044b908
    /* 3BDBD0 004BDBD0 2D284000 */   daddu     $5, $2, $0
    /* 3BDBD4 004BDBD4 F639110C */  jal        func_0044e7d8
    /* 3BDBD8 004BDBD8 2D204000 */   daddu     $4, $2, $0
    /* 3BDBDC 004BDBDC 07000046 */  neg.s      $f0, $f0
  .L004BDBE0:
    /* 3BDBE0 004BDBE0 70C4013C */  lui        $1, (0xC4700000 >> 16)
    /* 3BDBE4 004BDBE4 00088144 */  mtc1       $1, $f1
    /* 3BDBE8 004BDBE8 34080046 */  c.lt.s     $f1, $f0
    /* 3BDBEC 004BDBEC 01000245 */  bc1fl      .L004BDBF4
    /* 3BDBF0 004BDBF0 06080046 */   mov.s     $f0, $f1
  .L004BDBF4:
    /* 3BDBF4 004BDBF4 00088044 */  mtc1       $0, $f1
    /* 3BDBF8 004BDBF8 34000146 */  c.lt.s     $f0, $f1
    /* 3BDBFC 004BDBFC 01000245 */  bc1fl      .L004BDC04
    /* 3BDC00 004BDC00 06080046 */   mov.s     $f0, $f1
  .L004BDC04:
    /* 3BDC04 004BDC04 64000046 */  .word      0x46000064                    # cvt.w.s    $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BDC08 004BDC08 00080244 */  mfc1       $2, $f1
  .L004BDC0C:
    /* 3BDC0C 004BDC0C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDC10 004BDC10 0800B1DF */  ld         $17, 0x8($29)
    /* 3BDC14 004BDC14 1000BFDF */  ld         $31, 0x10($29)
    /* 3BDC18 004BDC18 0800E003 */  jr         $31
    /* 3BDC1C 004BDC1C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004bdaf0, 0x130
