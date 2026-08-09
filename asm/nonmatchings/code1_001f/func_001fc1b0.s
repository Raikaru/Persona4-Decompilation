.section .text
.set noat
.set noreorder
glabel func_001fc1b0
    /* FC1B0 001FC1B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FC1B4 001FC1B4 1000BFFF */  sd         $31, 0x10($29)
    /* FC1B8 001FC1B8 0000B07F */  sq         $16, 0x0($29)
    /* FC1BC 001FC1BC 2D808000 */  daddu      $16, $4, $0
    /* FC1C0 001FC1C0 6200043C */  lui        $4, %hi(D_006251F0)
    /* FC1C4 001FC1C4 F0518424 */  addiu      $4, $4, %lo(D_006251F0)
    /* FC1C8 001FC1C8 E048110C */  jal        func_00452380
    /* FC1CC 001FC1CC 00000000 */   nop
    /* FC1D0 001FC1D0 10004014 */  bnez       $2, .L001FC214
    /* FC1D4 001FC1D4 00000000 */   nop
    /* FC1D8 001FC1D8 02000224 */  addiu      $2, $0, 0x2
    /* FC1DC 001FC1DC 68B482A3 */  sb         $2, -0x4B98($28)
    /* FC1E0 001FC1E0 6EB490A7 */  sh         $16, -0x4B92($28)
    /* FC1E4 001FC1E4 69B480A3 */  sb         $0, -0x4B97($28)
    /* FC1E8 001FC1E8 6200043C */  lui        $4, %hi(D_006251F0)
    /* FC1EC 001FC1EC F0518424 */  addiu      $4, $4, %lo(D_006251F0)
    /* FC1F0 001FC1F0 C9000524 */  addiu      $5, $0, 0xC9
    /* FC1F4 001FC1F4 2D300000 */  daddu      $6, $0, $0
    /* FC1F8 001FC1F8 2D380000 */  daddu      $7, $0, $0
    /* FC1FC 001FC1FC 2000083C */  lui        $8, %hi(func_001fbb50)
    /* FC200 001FC200 50BB0825 */  addiu      $8, $8, %lo(func_001fbb50)
    /* FC204 001FC204 2D480000 */  daddu      $9, $0, $0
    /* FC208 001FC208 68B48A27 */  addiu      $10, $28, -0x4B98
    /* FC20C 001FC20C 7847110C */  jal        func_00451de0
    /* FC210 001FC210 00000000 */   nop
  .L001FC214:
    /* FC214 001FC214 1000BFDF */  ld         $31, 0x10($29)
    /* FC218 001FC218 0000B07B */  lq         $16, 0x0($29)
    /* FC21C 001FC21C 2000BD27 */  addiu      $29, $29, 0x20
    /* FC220 001FC220 0800E003 */  jr         $31
    /* FC224 001FC224 00000000 */   nop
    /* FC228 001FC228 00000000 */  nop
    /* FC22C 001FC22C 00000000 */  nop
.size func_001fc1b0, 0x80
