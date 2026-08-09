.section .text
.set noat
.set noreorder
glabel func_0042c090
    /* 32C090 0042C090 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32C094 0042C094 1000B1FF */  sd         $17, 0x10($29)
    /* 32C098 0042C098 0000B0FF */  sd         $16, 0x0($29)
    /* 32C09C 0042C09C 2000BFFF */  sd         $31, 0x20($29)
    /* 32C0A0 0042C0A0 C0AF100C */  jal        func_0042bf00
    /* 32C0A4 0042C0A4 2D88A000 */   daddu     $17, $5, $0
    /* 32C0A8 0042C0A8 06B0100C */  jal        func_0042c018
    /* 32C0AC 0042C0AC 2D804000 */   daddu     $16, $2, $0
    /* 32C0B0 0042C0B0 7100023C */  lui        $2, %hi(D_0070CA20)
    /* 32C0B4 0042C0B4 2D200002 */  daddu      $4, $16, $0
    /* 32C0B8 0042C0B8 20CA468C */  lw         $6, %lo(D_0070CA20)($2)
    /* 32C0BC 0042C0BC 2D282002 */  daddu      $5, $17, $0
    /* 32C0C0 0042C0C0 2000BFDF */  ld         $31, 0x20($29)
    /* 32C0C4 0042C0C4 1000B1DF */  ld         $17, 0x10($29)
    /* 32C0C8 0042C0C8 0400C624 */  addiu      $6, $6, 0x4
    /* 32C0CC 0042C0CC 0000B0DF */  ld         $16, 0x0($29)
    /* 32C0D0 0042C0D0 08851008 */  j          func_00421420
    /* 32C0D4 0042C0D4 3000BD27 */   addiu     $29, $29, 0x30
.size func_0042c090, 0x48
