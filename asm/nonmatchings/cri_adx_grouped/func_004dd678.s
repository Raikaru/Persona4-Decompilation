.section .text
.set noat
.set noreorder
glabel func_004dd678
    /* 3DD678 004DD678 7300083C */  lui        $8, %hi(D_00729994)
    /* 3DD67C 004DD67C 9499028D */  lw         $2, %lo(D_00729994)($8)
    /* 3DD680 004DD680 22004014 */  bnez       $2, .L004DD70C
    /* 3DD684 004DD684 7300023C */   lui       $2, %hi(D_0072A88F)
    /* 3DD688 004DD688 E0FF0324 */  addiu      $3, $0, -0x20
    /* 3DD68C 004DD68C 8FA84224 */  addiu      $2, $2, %lo(D_0072A88F)
    /* 3DD690 004DD690 7300043C */  lui        $4, %hi(D_007299DC)
    /* 3DD694 004DD694 24304300 */  and        $6, $2, $3
    /* 3DD698 004DD698 E1FF4724 */  addiu      $7, $2, -0x1F
    /* 3DD69C 004DD69C DC9986AC */  sw         $6, %lo(D_007299DC)($4)
    /* 3DD6A0 004DD6A0 00040524 */  addiu      $5, $0, 0x400
    /* 3DD6A4 004DD6A4 00000000 */  nop
  .L004DD6A8:
    /* 3DD6A8 004DD6A8 2110E500 */  addu       $2, $7, $5
    /* 3DD6AC 004DD6AC 2120C500 */  addu       $4, $6, $5
    /* 3DD6B0 004DD6B0 00004390 */  lbu        $3, 0x0($2)
    /* 3DD6B4 004DD6B4 FFFFA524 */  addiu      $5, $5, -0x1
    /* 3DD6B8 004DD6B8 00000000 */  nop
    /* 3DD6BC 004DD6BC FAFFA104 */  bgez       $5, .L004DD6A8
    /* 3DD6C0 004DD6C0 000083A0 */   sb        $3, 0x0($4)
    /* 3DD6C4 004DD6C4 7300023C */  lui        $2, %hi(D_0072896F)
    /* 3DD6C8 004DD6C8 E0FF0324 */  addiu      $3, $0, -0x20
    /* 3DD6CC 004DD6CC 6F894224 */  addiu      $2, $2, %lo(D_0072896F)
    /* 3DD6D0 004DD6D0 7300043C */  lui        $4, %hi(D_007299D8)
    /* 3DD6D4 004DD6D4 24304300 */  and        $6, $2, $3
    /* 3DD6D8 004DD6D8 E1FF4724 */  addiu      $7, $2, -0x1F
    /* 3DD6DC 004DD6DC D89986AC */  sw         $6, %lo(D_007299D8)($4)
    /* 3DD6E0 004DD6E0 00100524 */  addiu      $5, $0, 0x1000
    /* 3DD6E4 004DD6E4 00000000 */  nop
  .L004DD6E8:
    /* 3DD6E8 004DD6E8 2110E500 */  addu       $2, $7, $5
    /* 3DD6EC 004DD6EC 2120C500 */  addu       $4, $6, $5
    /* 3DD6F0 004DD6F0 00004390 */  lbu        $3, 0x0($2)
    /* 3DD6F4 004DD6F4 FFFFA524 */  addiu      $5, $5, -0x1
    /* 3DD6F8 004DD6F8 00000000 */  nop
    /* 3DD6FC 004DD6FC FAFFA104 */  bgez       $5, .L004DD6E8
    /* 3DD700 004DD700 000083A0 */   sb        $3, 0x0($4)
    /* 3DD704 004DD704 01000224 */  addiu      $2, $0, 0x1
    /* 3DD708 004DD708 949902AD */  sw         $2, %lo(D_00729994)($8)
  .L004DD70C:
    /* 3DD70C 004DD70C 0800E003 */  jr         $31
    /* 3DD710 004DD710 00000000 */   nop
    /* 3DD714 004DD714 00000000 */  nop
.size func_004dd678, 0xa0
