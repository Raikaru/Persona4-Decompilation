.section .text
.set noat
.set noreorder
glabel func_004f29b8
    /* 3F29B8 004F29B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F29BC 004F29BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F29C0 004F29C0 0800BFFF */  sd         $31, 0x8($29)
    /* 3F29C4 004F29C4 28D5130C */  jal        func_004f54a0
    /* 3F29C8 004F29C8 2D808000 */   daddu     $16, $4, $0
    /* 3F29CC 004F29CC 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F29D0 004F29D0 7600063C */  lui        $6, %hi(D_0075D5B8)
    /* 3F29D4 004F29D4 483A428C */  lw         $2, %lo(D_00743A48)($2)
    /* 3F29D8 004F29D8 2D200002 */  daddu      $4, $16, $0
    /* 3F29DC 004F29DC B8D5C624 */  addiu      $6, $6, %lo(D_0075D5B8)
    /* 3F29E0 004F29E0 E6010524 */  addiu      $5, $0, 0x1E6
    /* 3F29E4 004F29E4 2D380000 */  daddu      $7, $0, $0
    /* 3F29E8 004F29E8 09004010 */  beqz       $2, .L004F2A10
    /* 3F29EC 004F29EC 35FF0824 */   addiu     $8, $0, -0xCB
    /* 3F29F0 004F29F0 4C00428C */  lw         $2, 0x4C($2)
    /* 3F29F4 004F29F4 09F84000 */  jalr       $2
    /* 3F29F8 004F29F8 00000000 */   nop
    /* 3F29FC 004F29FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2A00 004F2A00 0800BFDF */  ld         $31, 0x8($29)
    /* 3F2A04 004F2A04 0800E003 */  jr         $31
    /* 3F2A08 004F2A08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F2A0C 004F2A0C 00000000 */  nop
  .L004F2A10:
    /* 3F2A10 004F2A10 7600043C */  lui        $4, %hi(D_0075D488)
    /* 3F2A14 004F2A14 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2A18 004F2A18 0800BFDF */  ld         $31, 0x8($29)
    /* 3F2A1C 004F2A1C 88D48424 */  addiu      $4, $4, %lo(D_0075D488)
    /* 3F2A20 004F2A20 F0D41308 */  j          func_004f53c0
    /* 3F2A24 004F2A24 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f29b8, 0x70
