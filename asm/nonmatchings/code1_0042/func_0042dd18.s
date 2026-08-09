.section .text
.set noat
.set noreorder
glabel func_0042dd18
    /* 32DD18 0042DD18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32DD1C 0042DD1C 0B000524 */  addiu      $5, $0, 0xB
    /* 32DD20 0042DD20 0000B0FF */  sd         $16, 0x0($29)
    /* 32DD24 0042DD24 1000BFFF */  sd         $31, 0x10($29)
    /* 32DD28 0042DD28 7100103C */  lui        $16, %hi(D_0070DD20)
    /* 32DD2C 0042DD2C 0000838C */  lw         $3, 0x0($4)
    /* 32DD30 0042DD30 7100043C */  lui        $4, %hi(D_0070DD24)
    /* 32DD34 0042DD34 20DD03AE */  sw         $3, %lo(D_0070DD20)($16)
    /* 32DD38 0042DD38 20DD028E */  lw         $2, %lo(D_0070DD20)($16)
    /* 32DD3C 0042DD3C 24DD82AC */  sw         $2, %lo(D_0070DD24)($4)
    /* 32DD40 0042DD40 20DD038E */  lw         $3, %lo(D_0070DD20)($16)
    /* 32DD44 0042DD44 06006514 */  bne        $3, $5, .L0042DD60
    /* 32DD48 0042DD48 7100023C */   lui       $2, %hi(D_0070DCE8)
    /* 32DD4C 0042DD4C 20DD00AE */  sw         $0, %lo(D_0070DD20)($16)
    /* 32DD50 0042DD50 7100023C */  lui        $2, %hi(D_0070DCF4)
    /* 32DD54 0042DD54 F4DC40AC */  sw         $0, %lo(D_0070DCF4)($2)
    /* 32DD58 0042DD58 14000010 */  b          .L0042DDAC
    /* 32DD5C 0042DD5C 1000BFDF */   ld        $31, 0x10($29)
  .L0042DD60:
    /* 32DD60 0042DD60 E8DC448C */  lw         $4, %lo(D_0070DCE8)($2)
    /* 32DD64 0042DD64 0486100C */  jal        func_00421810
    /* 32DD68 0042DD68 00000000 */   nop
    /* 32DD6C 0042DD6C 7100033C */  lui        $3, %hi(D_0070DCD4)
    /* 32DD70 0042DD70 D4DC628C */  lw         $2, %lo(D_0070DCD4)($3)
    /* 32DD74 0042DD74 09004010 */  beqz       $2, .L0042DD9C
    /* 32DD78 0042DD78 8900023C */   lui       $2, %hi(D_00894C80)
    /* 32DD7C 0042DD7C 804C438C */  lw         $3, %lo(D_00894C80)($2)
    /* 32DD80 0042DD80 06006010 */  beqz       $3, .L0042DD9C
    /* 32DD84 0042DD84 7100023C */   lui       $2, %hi(D_0070DCE0)
    /* 32DD88 0042DD88 E0DC448C */  lw         $4, %lo(D_0070DCE0)($2)
    /* 32DD8C 0042DD8C 0486100C */  jal        func_00421810
    /* 32DD90 0042DD90 00000000 */   nop
    /* 32DD94 0042DD94 03000010 */  b          .L0042DDA4
    /* 32DD98 0042DD98 00000000 */   nop
  .L0042DD9C:
    /* 32DD9C 0042DD9C 7100023C */  lui        $2, %hi(D_0070DCF4)
    /* 32DDA0 0042DDA0 F4DC40AC */  sw         $0, %lo(D_0070DCF4)($2)
  .L0042DDA4:
    /* 32DDA4 0042DDA4 20DD00AE */  sw         $0, %lo(D_0070DD20)($16)
    /* 32DDA8 0042DDA8 1000BFDF */  ld         $31, 0x10($29)
  .L0042DDAC:
    /* 32DDAC 0042DDAC 0000B0DF */  ld         $16, 0x0($29)
    /* 32DDB0 0042DDB0 0800E003 */  jr         $31
    /* 32DDB4 0042DDB4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0042dd18, 0xa0
