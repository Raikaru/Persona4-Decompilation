.section .text
.set noat
.set noreorder
glabel func_0041f1c0
    /* 31F1C0 0041F1C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 31F1C4 0041F1C4 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* 31F1C8 0041F1C8 0000BFFF */  sd         $31, 0x0($29)
    /* 31F1CC 0041F1CC FFFF4234 */  ori        $2, $2, (0xFFFFFFF & 0xFFFF)
    /* 31F1D0 0041F1D0 2428A200 */  and        $5, $5, $2
    /* 31F1D4 0041F1D4 0020033C */  lui        $3, (0x20000000 >> 16)
    /* 31F1D8 0041F1D8 4000878C */  lw         $7, 0x40($4)
    /* 31F1DC 0041F1DC 2528A300 */  or         $5, $5, $3
    /* 31F1E0 0041F1E0 F800E6AC */  sw         $6, 0xF8($7)
    /* 31F1E4 0041F1E4 EC00E5AC */  sw         $5, 0xEC($7)
    /* 31F1E8 0041F1E8 F000E0AC */  sw         $0, 0xF0($7)
    /* 31F1EC 0041F1EC C400E0AC */  sw         $0, 0xC4($7)
    /* 31F1F0 0041F1F0 367A100C */  jal        func_0041e8d8
    /* 31F1F4 0041F1F4 F400E0AC */   sw        $0, 0xF4($7)
    /* 31F1F8 0041F1F8 0000BFDF */  ld         $31, 0x0($29)
    /* 31F1FC 0041F1FC 0800E003 */  jr         $31
    /* 31F200 0041F200 1000BD27 */   addiu     $29, $29, 0x10
    /* 31F204 0041F204 00000000 */  nop
.size func_0041f1c0, 0x48
