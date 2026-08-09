.section .text
.set noat
.set noreorder
glabel func_003e03b0
    /* 2E03B0 003E03B0 68B7858F */  lw         $5, -0x4898($28)
    /* 2E03B4 003E03B4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E03B8 003E03B8 000082C4 */  lwc1       $f2, 0x0($4)
    /* 2E03BC 003E03BC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E03C0 003E03C0 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2E03C4 003E03C4 01000224 */  addiu      $2, $0, 0x1
    /* 2E03C8 003E03C8 080080C4 */  lwc1       $f0, 0x8($4)
    /* 2E03CC 003E03CC 21186500 */  addu       $3, $3, $5
    /* 2E03D0 003E03D0 0C0062E4 */  swc1       $f2, 0xC($3)
    /* 2E03D4 003E03D4 100061E4 */  swc1       $f1, 0x10($3)
    /* 2E03D8 003E03D8 0800E003 */  jr         $31
    /* 2E03DC 003E03DC 140060E4 */   swc1      $f0, 0x14($3)
.size func_003e03b0, 0x30
