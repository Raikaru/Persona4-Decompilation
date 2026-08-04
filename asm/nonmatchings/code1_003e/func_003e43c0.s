.section .text
.set noat
.set noreorder
glabel func_003e43c0
    /* 2E43C0 003E43C0 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E43C4 003E43C4 3E00073C */  lui        $7, %hi(func_003e3dc0)
    /* 2E43C8 003E43C8 A0B785AF */  sw         $5, -0x4860($28)
    /* 2E43CC 003E43CC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E43D0 003E43D0 2D108000 */  daddu      $2, $4, $0
    /* 2E43D4 003E43D4 3E00063C */  lui        $6, %hi(func_003e3d00)
    /* 2E43D8 003E43D8 21286500 */  addu       $5, $3, $5
    /* 2E43DC 003E43DC C03DE724 */  addiu      $7, $7, %lo(func_003e3dc0)
    /* 2E43E0 003E43E0 3E00043C */  lui        $4, %hi(func_003e3f00)
    /* 2E43E4 003E43E4 3E00033C */  lui        $3, %hi(func_003e3e60)
    /* 2E43E8 003E43E8 003DC624 */  addiu      $6, $6, %lo(func_003e3d00)
    /* 2E43EC 003E43EC 0800A7AC */  sw         $7, 0x8($5)
    /* 2E43F0 003E43F0 003F8424 */  addiu      $4, $4, %lo(func_003e3f00)
    /* 2E43F4 003E43F4 0C00A6AC */  sw         $6, 0xC($5)
    /* 2E43F8 003E43F8 603E6324 */  addiu      $3, $3, %lo(func_003e3e60)
    /* 2E43FC 003E43FC 1000A4AC */  sw         $4, 0x10($5)
    /* 2E4400 003E4400 1400A3AC */  sw         $3, 0x14($5)
    /* 2E4404 003E4404 A4B7838F */  lw         $3, -0x485C($28)
    /* 2E4408 003E4408 01006324 */  addiu      $3, $3, 0x1
    /* 2E440C 003E440C 0800E003 */  jr         $31
    /* 2E4410 003E4410 A4B783AF */   sw        $3, -0x485C($28)
    /* 2E4414 003E4414 00000000 */  nop
    /* 2E4418 003E4418 00000000 */  nop
    /* 2E441C 003E441C 00000000 */  nop
.size func_003e43c0, 0x60
