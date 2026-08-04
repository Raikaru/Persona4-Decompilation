.section .text
.set noat
.set noreorder
glabel func_0041f178
    /* 31F178 0041F178 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 31F17C 0041F17C FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* 31F180 0041F180 0000BFFF */  sd         $31, 0x0($29)
    /* 31F184 0041F184 FFFF4234 */  ori        $2, $2, (0xFFFFFFF & 0xFFFF)
    /* 31F188 0041F188 2428A200 */  and        $5, $5, $2
    /* 31F18C 0041F18C 0020033C */  lui        $3, (0x20000000 >> 16)
    /* 31F190 0041F190 4000878C */  lw         $7, 0x40($4)
    /* 31F194 0041F194 2528A300 */  or         $5, $5, $3
    /* 31F198 0041F198 01000224 */  addiu      $2, $0, 0x1
    /* 31F19C 0041F19C C400E2AC */  sw         $2, 0xC4($7)
    /* 31F1A0 0041F1A0 EC00E5AC */  sw         $5, 0xEC($7)
    /* 31F1A4 0041F1A4 F800E6AC */  sw         $6, 0xF8($7)
    /* 31F1A8 0041F1A8 F000E0AC */  sw         $0, 0xF0($7)
    /* 31F1AC 0041F1AC 367A100C */  jal        func_0041e8d8
    /* 31F1B0 0041F1B0 F400E0AC */   sw        $0, 0xF4($7)
    /* 31F1B4 0041F1B4 0000BFDF */  ld         $31, 0x0($29)
    /* 31F1B8 0041F1B8 0800E003 */  jr         $31
    /* 31F1BC 0041F1BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0041f178, 0x48
