.section .text
.set noat
.set noreorder
glabel func_0051aa40
    /* 41AA40 0051AA40 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 41AA44 0051AA44 1000B0FF */  sd         $16, 0x10($29)
    /* 41AA48 0051AA48 2000B2FF */  sd         $18, 0x20($29)
    /* 41AA4C 0051AA4C 2D908000 */  daddu      $18, $4, $0
    /* 41AA50 0051AA50 1800B1FF */  sd         $17, 0x18($29)
    /* 41AA54 0051AA54 78005026 */  addiu      $16, $18, 0x78
    /* 41AA58 0051AA58 2800B3FF */  sd         $19, 0x28($29)
    /* 41AA5C 0051AA5C 3000BFFF */  sd         $31, 0x30($29)
    /* 41AA60 0051AA60 C01F538E */  lw         $19, 0x1FC0($18)
    /* 41AA64 0051AA64 FA6E140C */  jal        func_0051bbe8
    /* 41AA68 0051AA68 0000718E */   lw        $17, 0x0($19)
    /* 41AA6C 0051AA6C 01000324 */  addiu      $3, $0, 0x1
    /* 41AA70 0051AA70 26004350 */  beql       $2, $3, .L0051AB0C
    /* 41AA74 0051AA74 1000B0DF */   ld        $16, 0x10($29)
    /* 41AA78 0051AA78 0000028E */  lw         $2, 0x0($16)
    /* 41AA7C 0051AA7C 05004010 */  beqz       $2, .L0051AA94
    /* 41AA80 0051AA80 2D202002 */   daddu     $4, $17, $0
    /* 41AA84 0051AA84 7C00038E */  lw         $3, 0x7C($16)
    /* 41AA88 0051AA88 1F006010 */  beqz       $3, .L0051AB08
    /* 41AA8C 0051AA8C 01000224 */   addiu     $2, $0, 0x1
    /* 41AA90 0051AA90 2D202002 */  daddu      $4, $17, $0
  .L0051AA94:
    /* 41AA94 0051AA94 B413140C */  jal        func_00504ed0
    /* 41AA98 0051AA98 2D28A003 */   daddu     $5, $29, $0
    /* 41AA9C 0051AA9C 2D204002 */  daddu      $4, $18, $0
    /* 41AAA0 0051AAA0 0300033C */  lui        $3, (0x3FFFF >> 16)
    /* 41AAA4 0051AAA4 0000A68F */  lw         $6, 0x0($29)
    /* 41AAA8 0051AAA8 FFFF6334 */  ori        $3, $3, (0x3FFFF & 0xFFFF)
    /* 41AAAC 0051AAAC 01000524 */  addiu      $5, $0, 0x1
    /* 41AAB0 0051AAB0 1500C310 */  beq        $6, $3, .L0051AB08
    /* 41AAB4 0051AAB4 01000224 */   addiu     $2, $0, 0x1
    /* 41AAB8 0051AAB8 7854140C */  jal        func_005151e0
    /* 41AABC 0051AABC 00000000 */   nop
    /* 41AAC0 0051AAC0 2D204002 */  daddu      $4, $18, $0
    /* 41AAC4 0051AAC4 1401638E */  lw         $3, 0x114($19)
    /* 41AAC8 0051AAC8 01000524 */  addiu      $5, $0, 0x1
    /* 41AACC 0051AACC 2A304300 */  slt        $6, $2, $3
    /* 41AAD0 0051AAD0 0D00C010 */  beqz       $6, .L0051AB08
    /* 41AAD4 0051AAD4 01000224 */   addiu     $2, $0, 0x1
    /* 41AAD8 0051AAD8 589E140C */  jal        func_00527960
    /* 41AADC 0051AADC 00000000 */   nop
    /* 41AAE0 0051AAE0 2D204002 */  daddu      $4, $18, $0
    /* 41AAE4 0051AAE4 0100512C */  sltiu      $17, $2, 0x1
    /* 41AAE8 0051AAE8 7854140C */  jal        func_005151e0
    /* 41AAEC 0051AAEC 2D282002 */   daddu     $5, $17, $0
    /* 41AAF0 0051AAF0 2D204002 */  daddu      $4, $18, $0
    /* 41AAF4 0051AAF4 2D282002 */  daddu      $5, $17, $0
    /* 41AAF8 0051AAF8 6854140C */  jal        func_005151a0
    /* 41AAFC 0051AAFC 2D804000 */   daddu     $16, $2, $0
    /* 41AB00 0051AB00 2A800202 */  slt        $16, $16, $2
    /* 41AB04 0051AB04 0100022E */  sltiu      $2, $16, 0x1
  .L0051AB08:
    /* 41AB08 0051AB08 1000B0DF */  ld         $16, 0x10($29)
  .L0051AB0C:
    /* 41AB0C 0051AB0C 1800B1DF */  ld         $17, 0x18($29)
    /* 41AB10 0051AB10 2000B2DF */  ld         $18, 0x20($29)
    /* 41AB14 0051AB14 2800B3DF */  ld         $19, 0x28($29)
    /* 41AB18 0051AB18 3000BFDF */  ld         $31, 0x30($29)
    /* 41AB1C 0051AB1C 0800E003 */  jr         $31
    /* 41AB20 0051AB20 4000BD27 */   addiu     $29, $29, 0x40
    /* 41AB24 0051AB24 00000000 */  nop
.size func_0051aa40, 0xe8
