.section .text
.set noat
.set noreorder
glabel func_0015ca30
    /* 5CA30 0015CA30 90FFBD27 */  addiu      $29, $29, -0x70
    /* 5CA34 0015CA34 5000BFFF */  sd         $31, 0x50($29)
    /* 5CA38 0015CA38 4000B47F */  sq         $20, 0x40($29)
    /* 5CA3C 0015CA3C 3000B37F */  sq         $19, 0x30($29)
    /* 5CA40 0015CA40 2000B27F */  sq         $18, 0x20($29)
    /* 5CA44 0015CA44 1000B17F */  sq         $17, 0x10($29)
    /* 5CA48 0015CA48 0000B07F */  sq         $16, 0x0($29)
    /* 5CA4C 0015CA4C A054050C */  jal        func_00155280
    /* 5CA50 0015CA50 00000000 */   nop
    /* 5CA54 0015CA54 F018508C */  lw         $16, 0x18F0($2)
    /* 5CA58 0015CA58 04000016 */  bnez       $16, .L0015CA6C
    /* 5CA5C 0015CA5C 00000000 */   nop
    /* 5CA60 0015CA60 2D100000 */  daddu      $2, $0, $0
    /* 5CA64 0015CA64 55000010 */  b          .L0015CBBC
    /* 5CA68 0015CA68 00000000 */   nop
  .L0015CA6C:
    /* 5CA6C 0015CA6C A054050C */  jal        func_00155280
    /* 5CA70 0015CA70 00000000 */   nop
    /* 5CA74 0015CA74 EC18428C */  lw         $2, 0x18EC($2)
    /* 5CA78 0015CA78 FFFF4224 */  addiu      $2, $2, -0x1
    /* 5CA7C 0015CA7C 40110200 */  sll        $2, $2, 5
    /* 5CA80 0015CA80 21A00202 */  addu       $20, $16, $2
    /* 5CA84 0015CA84 03001324 */  addiu      $19, $0, 0x3
    /* 5CA88 0015CA88 1F001224 */  addiu      $18, $0, 0x1F
    /* 5CA8C 0015CA8C 05001124 */  addiu      $17, $0, 0x5
    /* 5CA90 0015CA90 2C18040C */  jal        func_001060b0
    /* 5CA94 0015CA94 00000000 */   nop
    /* 5CA98 0015CA98 3C240200 */  dsll32     $4, $2, 16
    /* 5CA9C 0015CA9C 3F240400 */  dsra32     $4, $4, 16
    /* 5CAA0 0015CAA0 6C00A527 */  addiu      $5, $29, 0x6C
    /* 5CAA4 0015CAA4 6800A627 */  addiu      $6, $29, 0x68
    /* 5CAA8 0015CAA8 3441040C */  jal        func_001104d0
    /* 5CAAC 0015CAAC 00000000 */   nop
    /* 5CAB0 0015CAB0 2D800000 */  daddu      $16, $0, $0
    /* 5CAB4 0015CAB4 33000010 */  b          .L0015CB84
    /* 5CAB8 0015CAB8 00000000 */   nop
  .L0015CABC:
    /* 5CABC 0015CABC 00008496 */  lhu        $4, 0x0($20)
    /* 5CAC0 0015CAC0 02008596 */  lhu        $5, 0x2($20)
    /* 5CAC4 0015CAC4 2D306002 */  daddu      $6, $19, $0
    /* 5CAC8 0015CAC8 2D384002 */  daddu      $7, $18, $0
    /* 5CACC 0015CACC 6C2F050C */  jal        func_0014bdb0
    /* 5CAD0 0015CAD0 00000000 */   nop
    /* 5CAD4 0015CAD4 01000324 */  addiu      $3, $0, 0x1
    /* 5CAD8 0015CAD8 25004314 */  bne        $2, $3, .L0015CB70
    /* 5CADC 0015CADC 00000000 */   nop
    /* 5CAE0 0015CAE0 00008396 */  lhu        $3, 0x0($20)
    /* 5CAE4 0015CAE4 6C00A28F */  lw         $2, 0x6C($29)
    /* 5CAE8 0015CAE8 0C006214 */  bne        $3, $2, .L0015CB1C
    /* 5CAEC 0015CAEC 00000000 */   nop
    /* 5CAF0 0015CAF0 02008396 */  lhu        $3, 0x2($20)
    /* 5CAF4 0015CAF4 6800A28F */  lw         $2, 0x68($29)
    /* 5CAF8 0015CAF8 08006214 */  bne        $3, $2, .L0015CB1C
    /* 5CAFC 0015CAFC 00000000 */   nop
    /* 5CB00 0015CB00 3018040C */  jal        func_001060c0
    /* 5CB04 0015CB04 00000000 */   nop
    /* 5CB08 0015CB08 FF004330 */  andi       $3, $2, 0xFF
    /* 5CB0C 0015CB0C 04008296 */  lhu        $2, 0x4($20)
    /* 5CB10 0015CB10 2A106200 */  slt        $2, $3, $2
    /* 5CB14 0015CB14 19004014 */  bnez       $2, .L0015CB7C
    /* 5CB18 0015CB18 00000000 */   nop
  .L0015CB1C:
    /* 5CB1C 0015CB1C 6C00A28F */  lw         $2, 0x6C($29)
    /* 5CB20 0015CB20 0A006216 */  bne        $19, $2, .L0015CB4C
    /* 5CB24 0015CB24 00000000 */   nop
    /* 5CB28 0015CB28 6800A28F */  lw         $2, 0x68($29)
    /* 5CB2C 0015CB2C 07004216 */  bne        $18, $2, .L0015CB4C
    /* 5CB30 0015CB30 00000000 */   nop
    /* 5CB34 0015CB34 3018040C */  jal        func_001060c0
    /* 5CB38 0015CB38 00000000 */   nop
    /* 5CB3C 0015CB3C FF004230 */  andi       $2, $2, 0xFF
    /* 5CB40 0015CB40 2A082202 */  slt        $1, $17, $2
    /* 5CB44 0015CB44 0D002014 */  bnez       $1, .L0015CB7C
    /* 5CB48 0015CB48 00000000 */   nop
  .L0015CB4C:
    /* 5CB4C 0015CB4C 0800848E */  lw         $4, 0x8($20)
    /* 5CB50 0015CB50 FFFF0224 */  addiu      $2, $0, -0x1
    /* 5CB54 0015CB54 11008210 */  beq        $4, $2, .L0015CB9C
    /* 5CB58 0015CB58 00000000 */   nop
    /* 5CB5C 0015CB5C CC18040C */  jal        func_00106330
    /* 5CB60 0015CB60 00000000 */   nop
    /* 5CB64 0015CB64 01000324 */  addiu      $3, $0, 0x1
    /* 5CB68 0015CB68 0C004310 */  beq        $2, $3, .L0015CB9C
    /* 5CB6C 0015CB6C 00000000 */   nop
  .L0015CB70:
    /* 5CB70 0015CB70 00009396 */  lhu        $19, 0x0($20)
    /* 5CB74 0015CB74 02009296 */  lhu        $18, 0x2($20)
    /* 5CB78 0015CB78 04009196 */  lhu        $17, 0x4($20)
  .L0015CB7C:
    /* 5CB7C 0015CB7C 01001026 */  addiu      $16, $16, 0x1
    /* 5CB80 0015CB80 E0FF9426 */  addiu      $20, $20, -0x20
  .L0015CB84:
    /* 5CB84 0015CB84 A054050C */  jal        func_00155280
    /* 5CB88 0015CB88 00000000 */   nop
    /* 5CB8C 0015CB8C EC18428C */  lw         $2, 0x18EC($2)
    /* 5CB90 0015CB90 2B100202 */  sltu       $2, $16, $2
    /* 5CB94 0015CB94 C9FF4014 */  bnez       $2, .L0015CABC
    /* 5CB98 0015CB98 00000000 */   nop
  .L0015CB9C:
    /* 5CB9C 0015CB9C A054050C */  jal        func_00155280
    /* 5CBA0 0015CBA0 00000000 */   nop
    /* 5CBA4 0015CBA4 EC18428C */  lw         $2, 0x18EC($2)
    /* 5CBA8 0015CBA8 2B100202 */  sltu       $2, $16, $2
    /* 5CBAC 0015CBAC 02004014 */  bnez       $2, .L0015CBB8
    /* 5CBB0 0015CBB0 00000000 */   nop
    /* 5CBB4 0015CBB4 2DA00000 */  daddu      $20, $0, $0
  .L0015CBB8:
    /* 5CBB8 0015CBB8 2D108002 */  daddu      $2, $20, $0
  .L0015CBBC:
    /* 5CBBC 0015CBBC 5000BFDF */  ld         $31, 0x50($29)
    /* 5CBC0 0015CBC0 4000B47B */  lq         $20, 0x40($29)
    /* 5CBC4 0015CBC4 3000B37B */  lq         $19, 0x30($29)
    /* 5CBC8 0015CBC8 2000B27B */  lq         $18, 0x20($29)
    /* 5CBCC 0015CBCC 1000B17B */  lq         $17, 0x10($29)
    /* 5CBD0 0015CBD0 0000B07B */  lq         $16, 0x0($29)
    /* 5CBD4 0015CBD4 7000BD27 */  addiu      $29, $29, 0x70
    /* 5CBD8 0015CBD8 0800E003 */  jr         $31
    /* 5CBDC 0015CBDC 00000000 */   nop
.size func_0015ca30, 0x1b0
