.section .text
.set noat
.set noreorder
glabel func_0050dee8
    /* 40DEE8 0050DEE8 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 40DEEC 0050DEEC B000B0FF */  sd         $16, 0xB0($29)
    /* 40DEF0 0050DEF0 2D80A000 */  daddu      $16, $5, $0
    /* 40DEF4 0050DEF4 B800B1FF */  sd         $17, 0xB8($29)
    /* 40DEF8 0050DEF8 C000BFFF */  sd         $31, 0xC0($29)
    /* 40DEFC 0050DEFC 0A35140C */  jal        func_0050d428
    /* 40DF00 0050DF00 2D888000 */   daddu     $17, $4, $0
    /* 40DF04 0050DF04 01000324 */  addiu      $3, $0, 0x1
    /* 40DF08 0050DF08 2D200002 */  daddu      $4, $16, $0
    /* 40DF0C 0050DF0C 2D280000 */  daddu      $5, $0, $0
    /* 40DF10 0050DF10 09004310 */  beq        $2, $3, .L0050DF38
    /* 40DF14 0050DF14 60000624 */   addiu     $6, $0, 0x60
    /* 40DF18 0050DF18 72FE100C */  jal        func_0043f9c8
    /* 40DF1C 0050DF1C 00000000 */   nop
    /* 40DF20 0050DF20 7600043C */  lui        $4, %hi(D_0075F5E8)
    /* 40DF24 0050DF24 8844140C */  jal        func_00511220
    /* 40DF28 0050DF28 E8F58424 */   addiu     $4, $4, %lo(D_0075F5E8)
    /* 40DF2C 0050DF2C 27000010 */  b          .L0050DFCC
    /* 40DF30 0050DF30 B000B0DF */   ld        $16, 0xB0($29)
    /* 40DF34 0050DF34 00000000 */  nop
  .L0050DF38:
    /* 40DF38 0050DF38 9833140C */  jal        func_0050ce60
    /* 40DF3C 0050DF3C 2D202002 */   daddu     $4, $17, $0
    /* 40DF40 0050DF40 2D200002 */  daddu      $4, $16, $0
    /* 40DF44 0050DF44 2D28A003 */  daddu      $5, $29, $0
    /* 40DF48 0050DF48 05004014 */  bnez       $2, .L0050DF60
    /* 40DF4C 0050DF4C 60000624 */   addiu     $6, $0, 0x60
    /* 40DF50 0050DF50 72FE100C */  jal        func_0043f9c8
    /* 40DF54 0050DF54 2D280000 */   daddu     $5, $0, $0
    /* 40DF58 0050DF58 1C000010 */  b          .L0050DFCC
    /* 40DF5C 0050DF5C B000B0DF */   ld        $16, 0xB0($29)
  .L0050DF60:
    /* 40DF60 0050DF60 6094140C */  jal        func_00525180
    /* 40DF64 0050DF64 2D204000 */   daddu     $4, $2, $0
    /* 40DF68 0050DF68 3800A3DF */  ld         $3, 0x38($29)
    /* 40DF6C 0050DF6C 4000A4DF */  ld         $4, 0x40($29)
    /* 40DF70 0050DF70 4800A5DF */  ld         $5, 0x48($29)
    /* 40DF74 0050DF74 5000A6DF */  ld         $6, 0x50($29)
    /* 40DF78 0050DF78 5800A7DF */  ld         $7, 0x58($29)
    /* 40DF7C 0050DF7C 6000A8DF */  ld         $8, 0x60($29)
    /* 40DF80 0050DF80 6800A9DF */  ld         $9, 0x68($29)
    /* 40DF84 0050DF84 7000AADF */  ld         $10, 0x70($29)
    /* 40DF88 0050DF88 7800ABDF */  ld         $11, 0x78($29)
    /* 40DF8C 0050DF8C 8000ACDF */  ld         $12, 0x80($29)
    /* 40DF90 0050DF90 8800ADDF */  ld         $13, 0x88($29)
    /* 40DF94 0050DF94 9000A2DF */  ld         $2, 0x90($29)
    /* 40DF98 0050DF98 000003FE */  sd         $3, 0x0($16)
    /* 40DF9C 0050DF9C 580002FE */  sd         $2, 0x58($16)
    /* 40DFA0 0050DFA0 080004FE */  sd         $4, 0x8($16)
    /* 40DFA4 0050DFA4 100005FE */  sd         $5, 0x10($16)
    /* 40DFA8 0050DFA8 180006FE */  sd         $6, 0x18($16)
    /* 40DFAC 0050DFAC 200007FE */  sd         $7, 0x20($16)
    /* 40DFB0 0050DFB0 280008FE */  sd         $8, 0x28($16)
    /* 40DFB4 0050DFB4 300009FE */  sd         $9, 0x30($16)
    /* 40DFB8 0050DFB8 38000AFE */  sd         $10, 0x38($16)
    /* 40DFBC 0050DFBC 40000BFE */  sd         $11, 0x40($16)
    /* 40DFC0 0050DFC0 48000CFE */  sd         $12, 0x48($16)
    /* 40DFC4 0050DFC4 50000DFE */  sd         $13, 0x50($16)
    /* 40DFC8 0050DFC8 B000B0DF */  ld         $16, 0xB0($29)
  .L0050DFCC:
    /* 40DFCC 0050DFCC B800B1DF */  ld         $17, 0xB8($29)
    /* 40DFD0 0050DFD0 C000BFDF */  ld         $31, 0xC0($29)
    /* 40DFD4 0050DFD4 0800E003 */  jr         $31
    /* 40DFD8 0050DFD8 D000BD27 */   addiu     $29, $29, 0xD0
    /* 40DFDC 0050DFDC 00000000 */  nop
.size func_0050dee8, 0xf8
