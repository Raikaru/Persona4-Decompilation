.section .text
.set noat
.set noreorder
glabel func_004abe80
    /* 3ABE80 004ABE80 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3ABE84 004ABE84 4000BFFF */  sd         $31, 0x40($29)
    /* 3ABE88 004ABE88 3000B27F */  sq         $18, 0x30($29)
    /* 3ABE8C 004ABE8C 2000B17F */  sq         $17, 0x20($29)
    /* 3ABE90 004ABE90 1000B07F */  sq         $16, 0x10($29)
    /* 3ABE94 004ABE94 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3ABE98 004ABE98 2D908000 */  daddu      $18, $4, $0
    /* 3ABE9C 004ABE9C 7100043C */  lui        $4, %hi(D_007144B8)
    /* 3ABEA0 004ABEA0 B8448424 */  addiu      $4, $4, %lo(D_007144B8)
    /* 3ABEA4 004ABEA4 71010524 */  addiu      $5, $0, 0x171
    /* 3ABEA8 004ABEA8 A43A110C */  jal        func_0044ea90
    /* 3ABEAC 004ABEAC 00000000 */   nop
    /* 3ABEB0 004ABEB0 9C000424 */  addiu      $4, $0, 0x9C
    /* 3ABEB4 004ABEB4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3ABEB8 004ABEB8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3ABEBC 004ABEBC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3ABEC0 004ABEC0 09F84000 */  jalr       $2
    /* 3ABEC4 004ABEC4 00000000 */   nop
    /* 3ABEC8 004ABEC8 2D884000 */  daddu      $17, $2, $0
    /* 3ABECC 004ABECC 2D202002 */  daddu      $4, $17, $0
    /* 3ABED0 004ABED0 2D280000 */  daddu      $5, $0, $0
    /* 3ABED4 004ABED4 9C000624 */  addiu      $6, $0, 0x9C
    /* 3ABED8 004ABED8 72FE100C */  jal        func_0043f9c8
    /* 3ABEDC 004ABEDC 00000000 */   nop
    /* 3ABEE0 004ABEE0 06002016 */  bnez       $17, .L004ABEFC
    /* 3ABEE4 004ABEE4 00000000 */   nop
    /* 3ABEE8 004ABEE8 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3ABEEC 004ABEEC A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3ABEF0 004ABEF0 73000524 */  addiu      $5, $0, 0x73
    /* 3ABEF4 004ABEF4 CCB5110C */  jal        func_0046d730
    /* 3ABEF8 004ABEF8 00000000 */   nop
  .L004ABEFC:
    /* 3ABEFC 004ABEFC 980020AE */  sw         $0, 0x98($17)
    /* 3ABF00 004ABF00 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3ABF04 004ABF04 280022AE */  sw         $2, 0x28($17)
    /* 3ABF08 004ABF08 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ABF0C 004ABF0C 00A08244 */  mtc1       $2, $f20
    /* 3ABF10 004ABF10 200022AE */  sw         $2, 0x20($17)
    /* 3ABF14 004ABF14 000020FA */  sqc2       $vf0, 0x0($17)
    /* 3ABF18 004ABF18 100020FA */  sqc2       $vf0, 0x10($17)
    /* 3ABF1C 004ABF1C 58004012 */  beqz       $18, .L004AC080
    /* 3ABF20 004ABF20 00000000 */   nop
    /* 3ABF24 004ABF24 2D204002 */  daddu      $4, $18, $0
    /* 3ABF28 004ABF28 2411120C */  jal        func_00484490
    /* 3ABF2C 004ABF2C 00000000 */   nop
    /* 3ABF30 004ABF30 2D804000 */  daddu      $16, $2, $0
    /* 3ABF34 004ABF34 06000016 */  bnez       $16, .L004ABF50
    /* 3ABF38 004ABF38 00000000 */   nop
    /* 3ABF3C 004ABF3C 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3ABF40 004ABF40 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3ABF44 004ABF44 83000524 */  addiu      $5, $0, 0x83
    /* 3ABF48 004ABF48 CCB5110C */  jal        func_0046d730
    /* 3ABF4C 004ABF4C 00000000 */   nop
  .L004ABF50:
    /* 3ABF50 004ABF50 2C002426 */  addiu      $4, $17, 0x2C
    /* 3ABF54 004ABF54 2D280002 */  daddu      $5, $16, $0
    /* 3ABF58 004ABF58 68000624 */  addiu      $6, $0, 0x68
    /* 3ABF5C 004ABF5C 04FE100C */  jal        func_0043f810
    /* 3ABF60 004ABF60 00000000 */   nop
    /* 3ABF64 004ABF64 2D204002 */  daddu      $4, $18, $0
    /* 3ABF68 004ABF68 3411120C */  jal        func_004844d0
    /* 3ABF6C 004ABF6C 00000000 */   nop
    /* 3ABF70 004ABF70 2D804000 */  daddu      $16, $2, $0
    /* 3ABF74 004ABF74 42000012 */  beqz       $16, .L004AC080
    /* 3ABF78 004ABF78 00000000 */   nop
    /* 3ABF7C 004ABF7C 1C004396 */  lhu        $3, 0x1C($18)
    /* 3ABF80 004ABF80 03000224 */  addiu      $2, $0, 0x3
    /* 3ABF84 004ABF84 06006210 */  beq        $3, $2, .L004ABFA0
    /* 3ABF88 004ABF88 00000000 */   nop
    /* 3ABF8C 004ABF8C 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3ABF90 004ABF90 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3ABF94 004ABF94 8A000524 */  addiu      $5, $0, 0x8A
    /* 3ABF98 004ABF98 CCB5110C */  jal        func_0046d730
    /* 3ABF9C 004ABF9C 00000000 */   nop
  .L004ABFA0:
    /* 3ABFA0 004ABFA0 2400528E */  lw         $18, 0x24($18)
    /* 3ABFA4 004ABFA4 04000010 */  b          .L004ABFB8
    /* 3ABFA8 004ABFA8 00000000 */   nop
  .L004ABFAC:
    /* 3ABFAC 004ABFAC 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3ABFB0 004ABFB0 01004224 */  addiu      $2, $2, 0x1
    /* 3ABFB4 004ABFB4 90BB82A7 */  sh         $2, -0x4470($28)
  .L004ABFB8:
    /* 3ABFB8 004ABFB8 06000424 */  addiu      $4, $0, 0x6
    /* 3ABFBC 004ABFBC 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3ABFC0 004ABFC0 2D300000 */  daddu      $6, $0, $0
    /* 3ABFC4 004ABFC4 10DF110C */  jal        func_00477c40
    /* 3ABFC8 004ABFC8 00000000 */   nop
    /* 3ABFCC 004ABFCC F7FF4014 */  bnez       $2, .L004ABFAC
    /* 3ABFD0 004ABFD0 00000000 */   nop
    /* 3ABFD4 004ABFD4 06000424 */  addiu      $4, $0, 0x6
    /* 3ABFD8 004ABFD8 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3ABFDC 004ABFDC 2D300002 */  daddu      $6, $16, $0
    /* 3ABFE0 004ABFE0 2D384002 */  daddu      $7, $18, $0
    /* 3ABFE4 004ABFE4 01000824 */  addiu      $8, $0, 0x1
    /* 3ABFE8 004ABFE8 C4DF110C */  jal        func_00477f10
    /* 3ABFEC 004ABFEC 00000000 */   nop
    /* 3ABFF0 004ABFF0 2D804000 */  daddu      $16, $2, $0
    /* 3ABFF4 004ABFF4 2D200002 */  daddu      $4, $16, $0
    /* 3ABFF8 004ABFF8 A8E8110C */  jal        func_0047a2a0
    /* 3ABFFC 004ABFFC 00000000 */   nop
    /* 3AC000 004AC000 2D200002 */  daddu      $4, $16, $0
    /* 3AC004 004AC004 2D280000 */  daddu      $5, $0, $0
    /* 3AC008 004AC008 28E7110C */  jal        func_00479ca0
    /* 3AC00C 004AC00C 00000000 */   nop
    /* 3AC010 004AC010 0D004010 */  beqz       $2, .L004AC048
    /* 3AC014 004AC014 00000000 */   nop
    /* 3AC018 004AC018 2D200002 */  daddu      $4, $16, $0
    /* 3AC01C 004AC01C 2D280000 */  daddu      $5, $0, $0
    /* 3AC020 004AC020 2D300000 */  daddu      $6, $0, $0
    /* 3AC024 004AC024 2D380000 */  daddu      $7, $0, $0
    /* 3AC028 004AC028 2D400000 */  daddu      $8, $0, $0
    /* 3AC02C 004AC02C 50E6110C */  jal        func_00479940
    /* 3AC030 004AC030 00000000 */   nop
    /* 3AC034 004AC034 2D200002 */  daddu      $4, $16, $0
    /* 3AC038 004AC038 2D280000 */  daddu      $5, $0, $0
    /* 3AC03C 004AC03C 06A30046 */  mov.s      $f12, $f20
    /* 3AC040 004AC040 38E8110C */  jal        func_0047a0e0
    /* 3AC044 004AC044 00000000 */   nop
  .L004AC048:
    /* 3AC048 004AC048 D800038E */  lw         $3, 0xD8($16)
    /* 3AC04C 004AC04C FDFF0224 */  addiu      $2, $0, -0x3
    /* 3AC050 004AC050 24106200 */  and        $2, $3, $2
    /* 3AC054 004AC054 D80002AE */  sw         $2, 0xD8($16)
    /* 3AC058 004AC058 2D200002 */  daddu      $4, $16, $0
    /* 3AC05C 004AC05C 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3AC060 004AC060 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3AC064 004AC064 2D300002 */  daddu      $6, $16, $0
    /* 3AC068 004AC068 ACE3110C */  jal        func_00478eb0
    /* 3AC06C 004AC06C 00000000 */   nop
    /* 3AC070 004AC070 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3AC074 004AC074 01004224 */  addiu      $2, $2, 0x1
    /* 3AC078 004AC078 90BB82A7 */  sh         $2, -0x4470($28)
    /* 3AC07C 004AC07C 940030AE */  sw         $16, 0x94($17)
  .L004AC080:
    /* 3AC080 004AC080 2D102002 */  daddu      $2, $17, $0
    /* 3AC084 004AC084 4000BFDF */  ld         $31, 0x40($29)
    /* 3AC088 004AC088 3000B27B */  lq         $18, 0x30($29)
    /* 3AC08C 004AC08C 2000B17B */  lq         $17, 0x20($29)
    /* 3AC090 004AC090 1000B07B */  lq         $16, 0x10($29)
    /* 3AC094 004AC094 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AC098 004AC098 5000BD27 */  addiu      $29, $29, 0x50
    /* 3AC09C 004AC09C 0800E003 */  jr         $31
    /* 3AC0A0 004AC0A0 00000000 */   nop
    /* 3AC0A4 004AC0A4 00000000 */  nop
    /* 3AC0A8 004AC0A8 00000000 */  nop
    /* 3AC0AC 004AC0AC 00000000 */  nop
.size func_004abe80, 0x230
