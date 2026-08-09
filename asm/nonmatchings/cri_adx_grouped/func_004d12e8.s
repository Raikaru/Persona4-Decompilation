.section .text
.set noat
.set noreorder
glabel func_004d12e8
    /* 3D12E8 004D12E8 D6028280 */  lb         $2, 0x2D6($4)
    /* 3D12EC 004D12EC 01000324 */  addiu      $3, $0, 0x1
    /* 3D12F0 004D12F0 05004310 */  beq        $2, $3, .L004D1308
    /* 3D12F4 004D12F4 00000000 */   nop
    /* 3D12F8 004D12F8 4800828C */  lw         $2, 0x48($4)
    /* 3D12FC 004D12FC D60283A0 */  sb         $3, 0x2D6($4)
    /* 3D1300 004D1300 24004224 */  addiu      $2, $2, 0x24
    /* 3D1304 004D1304 480082AC */  sw         $2, 0x48($4)
  .L004D1308:
    /* 3D1308 004D1308 0800E003 */  jr         $31
    /* 3D130C 004D130C E80285A4 */   sh        $5, 0x2E8($4)
.size func_004d12e8, 0x28
