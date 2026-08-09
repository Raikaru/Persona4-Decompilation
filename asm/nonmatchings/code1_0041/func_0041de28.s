.section .text
.set noat
.set noreorder
glabel func_0041de28
    /* 31DE28 0041DE28 70FFBD27 */  addiu      $29, $29, -0x90
    /* 31DE2C 0041DE2C 7500023C */  lui        $2, %hi(D_00753BA8)
    /* 31DE30 0041DE30 3000B0FF */  sd         $16, 0x30($29)
    /* 31DE34 0041DE34 4000B1FF */  sd         $17, 0x40($29)
    /* 31DE38 0041DE38 2D808000 */  daddu      $16, $4, $0
    /* 31DE3C 0041DE3C 8000BFFF */  sd         $31, 0x80($29)
    /* 31DE40 0041DE40 7000B4FF */  sd         $20, 0x70($29)
    /* 31DE44 0041DE44 6000B3FF */  sd         $19, 0x60($29)
    /* 31DE48 0041DE48 5000B2FF */  sd         $18, 0x50($29)
    /* 31DE4C 0041DE4C A83B4724 */  addiu      $7, $2, %lo(D_00753BA8)
    /* 31DE50 0041DE50 0700E368 */  ldl        $3, 0x7($7)
    /* 31DE54 0041DE54 0000E36C */  ldr        $3, 0x0($7)
    /* 31DE58 0041DE58 0F00E568 */  ldl        $5, 0xF($7)
    /* 31DE5C 0041DE5C 0800E56C */  ldr        $5, 0x8($7)
    /* 31DE60 0041DE60 1700E668 */  ldl        $6, 0x17($7)
    /* 31DE64 0041DE64 1000E66C */  ldr        $6, 0x10($7)
    /* 31DE68 0041DE68 0700A3B3 */  sdl        $3, 0x7($29)
    /* 31DE6C 0041DE6C 0000A3B7 */  sdr        $3, 0x0($29)
    /* 31DE70 0041DE70 0F00A5B3 */  sdl        $5, 0xF($29)
    /* 31DE74 0041DE74 0800A5B7 */  sdr        $5, 0x8($29)
    /* 31DE78 0041DE78 1700A6B3 */  sdl        $6, 0x17($29)
    /* 31DE7C 0041DE7C 1000A6B7 */  sdr        $6, 0x10($29)
    /* 31DE80 0041DE80 1F00E368 */  ldl        $3, 0x1F($7)
    /* 31DE84 0041DE84 1800E36C */  ldr        $3, 0x18($7)
    /* 31DE88 0041DE88 2700E568 */  ldl        $5, 0x27($7)
    /* 31DE8C 0041DE8C 2000E56C */  ldr        $5, 0x20($7)
    /* 31DE90 0041DE90 2800E68C */  lw         $6, 0x28($7)
    /* 31DE94 0041DE94 1F00A3B3 */  sdl        $3, 0x1F($29)
    /* 31DE98 0041DE98 1800A3B7 */  sdr        $3, 0x18($29)
    /* 31DE9C 0041DE9C 2700A5B3 */  sdl        $5, 0x27($29)
    /* 31DEA0 0041DEA0 2000A5B7 */  sdr        $5, 0x20($29)
    /* 31DEA4 0041DEA4 2800A6AF */  sw         $6, 0x28($29)
    /* 31DEA8 0041DEA8 6678100C */  jal        func_0041e198
    /* 31DEAC 0041DEAC 01001124 */   addiu     $17, $0, 0x1
    /* 31DEB0 0041DEB0 04000010 */  b          .L0041DEC4
    /* 31DEB4 0041DEB4 2D200002 */   daddu     $4, $16, $0
  .L0041DEB8:
    /* 31DEB8 0041DEB8 0C78100C */  jal        func_0041e030
    /* 31DEBC 0041DEBC 00000000 */   nop
    /* 31DEC0 0041DEC0 2D200002 */  daddu      $4, $16, $0
  .L0041DEC4:
    /* 31DEC4 0041DEC4 686F100C */  jal        func_0041bda0
    /* 31DEC8 0041DEC8 18000524 */   addiu     $5, $0, 0x18
    /* 31DECC 0041DECC 2D200002 */  daddu      $4, $16, $0
    /* 31DED0 0041DED0 04005110 */  beq        $2, $17, .L0041DEE4
    /* 31DED4 0041DED4 08000524 */   addiu     $5, $0, 0x8
    /* 31DED8 0041DED8 7808028E */  lw         $2, 0x878($16)
    /* 31DEDC 0041DEDC F6FF4010 */  beqz       $2, .L0041DEB8
    /* 31DEE0 0041DEE0 00000000 */   nop
  .L0041DEE4:
    /* 31DEE4 0041DEE4 B5011224 */  addiu      $18, $0, 0x1B5
    /* 31DEE8 0041DEE8 B2011424 */  addiu      $20, $0, 0x1B2
    /* 31DEEC 0041DEEC 33000010 */  b          .L0041DFBC
    /* 31DEF0 0041DEF0 0A001324 */   addiu     $19, $0, 0xA
    /* 31DEF4 0041DEF4 00000000 */  nop
  .L0041DEF8:
    /* 31DEF8 0041DEF8 1E005214 */  bne        $2, $18, .L0041DF74
    /* 31DEFC 0041DEFC 2D200002 */   daddu     $4, $16, $0
  .L0041DF00:
    /* 31DF00 0041DF00 6478100C */  jal        func_0041e190
    /* 31DF04 0041DF04 01001124 */   addiu     $17, $0, 0x1
    /* 31DF08 0041DF08 2D200002 */  daddu      $4, $16, $0
    /* 31DF0C 0041DF0C 2E6F100C */  jal        func_0041bcb8
    /* 31DF10 0041DF10 04000524 */   addiu     $5, $0, 0x4
    /* 31DF14 0041DF14 2B186202 */  sltu       $3, $19, $2
    /* 31DF18 0041DF18 0B100300 */  movn       $2, $0, $3
    /* 31DF1C 0041DF1C 80100200 */  sll        $2, $2, 2
    /* 31DF20 0041DF20 2118A203 */  addu       $3, $29, $2
    /* 31DF24 0041DF24 0000628C */  lw         $2, 0x0($3)
    /* 31DF28 0041DF28 09F84000 */  jalr       $2
    /* 31DF2C 0041DF2C 2D200002 */   daddu     $4, $16, $0
    /* 31DF30 0041DF30 6678100C */  jal        func_0041e198
    /* 31DF34 0041DF34 2D200002 */   daddu     $4, $16, $0
    /* 31DF38 0041DF38 04000010 */  b          .L0041DF4C
    /* 31DF3C 0041DF3C 2D200002 */   daddu     $4, $16, $0
  .L0041DF40:
    /* 31DF40 0041DF40 0C78100C */  jal        func_0041e030
    /* 31DF44 0041DF44 00000000 */   nop
    /* 31DF48 0041DF48 2D200002 */  daddu      $4, $16, $0
  .L0041DF4C:
    /* 31DF4C 0041DF4C 686F100C */  jal        func_0041bda0
    /* 31DF50 0041DF50 18000524 */   addiu     $5, $0, 0x18
    /* 31DF54 0041DF54 2D200002 */  daddu      $4, $16, $0
    /* 31DF58 0041DF58 19005110 */  beq        $2, $17, .L0041DFC0
    /* 31DF5C 0041DF5C 08000524 */   addiu     $5, $0, 0x8
    /* 31DF60 0041DF60 7808028E */  lw         $2, 0x878($16)
    /* 31DF64 0041DF64 F6FF4010 */  beqz       $2, .L0041DF40
    /* 31DF68 0041DF68 00000000 */   nop
    /* 31DF6C 0041DF6C 13000010 */  b          .L0041DFBC
    /* 31DF70 0041DF70 00000000 */   nop
  .L0041DF74:
    /* 31DF74 0041DF74 6478100C */  jal        func_0041e190
    /* 31DF78 0041DF78 01001124 */   addiu     $17, $0, 0x1
    /* 31DF7C 0041DF7C 6678100C */  jal        func_0041e198
    /* 31DF80 0041DF80 2D200002 */   daddu     $4, $16, $0
    /* 31DF84 0041DF84 05000010 */  b          .L0041DF9C
    /* 31DF88 0041DF88 2D200002 */   daddu     $4, $16, $0
    /* 31DF8C 0041DF8C 00000000 */  nop
  .L0041DF90:
    /* 31DF90 0041DF90 0C78100C */  jal        func_0041e030
    /* 31DF94 0041DF94 00000000 */   nop
    /* 31DF98 0041DF98 2D200002 */  daddu      $4, $16, $0
  .L0041DF9C:
    /* 31DF9C 0041DF9C 686F100C */  jal        func_0041bda0
    /* 31DFA0 0041DFA0 18000524 */   addiu     $5, $0, 0x18
    /* 31DFA4 0041DFA4 2D200002 */  daddu      $4, $16, $0
    /* 31DFA8 0041DFA8 05005110 */  beq        $2, $17, .L0041DFC0
    /* 31DFAC 0041DFAC 08000524 */   addiu     $5, $0, 0x8
    /* 31DFB0 0041DFB0 7808028E */  lw         $2, 0x878($16)
    /* 31DFB4 0041DFB4 F6FF4010 */  beqz       $2, .L0041DF90
    /* 31DFB8 0041DFB8 00000000 */   nop
  .L0041DFBC:
    /* 31DFBC 0041DFBC 2D200002 */  daddu      $4, $16, $0
  .L0041DFC0:
    /* 31DFC0 0041DFC0 686F100C */  jal        func_0041bda0
    /* 31DFC4 0041DFC4 20000524 */   addiu     $5, $0, 0x20
    /* 31DFC8 0041DFC8 CDFF5210 */  beq        $2, $18, .L0041DF00
    /* 31DFCC 0041DFCC 2D200002 */   daddu     $4, $16, $0
    /* 31DFD0 0041DFD0 C9FF5410 */  beq        $2, $20, .L0041DEF8
    /* 31DFD4 0041DFD4 8000BFDF */   ld        $31, 0x80($29)
    /* 31DFD8 0041DFD8 7000B4DF */  ld         $20, 0x70($29)
    /* 31DFDC 0041DFDC 6000B3DF */  ld         $19, 0x60($29)
    /* 31DFE0 0041DFE0 5000B2DF */  ld         $18, 0x50($29)
    /* 31DFE4 0041DFE4 4000B1DF */  ld         $17, 0x40($29)
    /* 31DFE8 0041DFE8 3000B0DF */  ld         $16, 0x30($29)
    /* 31DFEC 0041DFEC 0800E003 */  jr         $31
    /* 31DFF0 0041DFF0 9000BD27 */   addiu     $29, $29, 0x90
    /* 31DFF4 0041DFF4 00000000 */  nop
.size func_0041de28, 0x1d0
