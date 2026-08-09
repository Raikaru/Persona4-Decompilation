.section .text
.set noat
.set noreorder
glabel func_001ea780
    /* EA780 001EA780 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA784 001EA784 0000BFFF */  sd         $31, 0x0($29)
    /* EA788 001EA788 2D200000 */  daddu      $4, $0, $0
    /* EA78C 001EA78C 54730A0C */  jal        func_0029cd50
    /* EA790 001EA790 00000000 */   nop
    /* EA794 001EA794 8800023C */  lui        $2, %hi(D_00881420)
    /* EA798 001EA798 201440E4 */  swc1       $f0, %lo(D_00881420)($2)
    /* EA79C 001EA79C 01000424 */  addiu      $4, $0, 0x1
    /* EA7A0 001EA7A0 54730A0C */  jal        func_0029cd50
    /* EA7A4 001EA7A4 00000000 */   nop
    /* EA7A8 001EA7A8 8800023C */  lui        $2, %hi(D_00881424)
    /* EA7AC 001EA7AC 241440E4 */  swc1       $f0, %lo(D_00881424)($2)
    /* EA7B0 001EA7B0 02000424 */  addiu      $4, $0, 0x2
    /* EA7B4 001EA7B4 54730A0C */  jal        func_0029cd50
    /* EA7B8 001EA7B8 00000000 */   nop
    /* EA7BC 001EA7BC 8800023C */  lui        $2, %hi(D_00881428)
    /* EA7C0 001EA7C0 281440E4 */  swc1       $f0, %lo(D_00881428)($2)
    /* EA7C4 001EA7C4 03000424 */  addiu      $4, $0, 0x3
    /* EA7C8 001EA7C8 54730A0C */  jal        func_0029cd50
    /* EA7CC 001EA7CC 00000000 */   nop
    /* EA7D0 001EA7D0 8800023C */  lui        $2, %hi(D_00881400)
    /* EA7D4 001EA7D4 001440E4 */  swc1       $f0, %lo(D_00881400)($2)
    /* EA7D8 001EA7D8 04000424 */  addiu      $4, $0, 0x4
    /* EA7DC 001EA7DC 54730A0C */  jal        func_0029cd50
    /* EA7E0 001EA7E0 00000000 */   nop
    /* EA7E4 001EA7E4 8800023C */  lui        $2, %hi(D_00881404)
    /* EA7E8 001EA7E8 041440E4 */  swc1       $f0, %lo(D_00881404)($2)
    /* EA7EC 001EA7EC 05000424 */  addiu      $4, $0, 0x5
    /* EA7F0 001EA7F0 54730A0C */  jal        func_0029cd50
    /* EA7F4 001EA7F4 00000000 */   nop
    /* EA7F8 001EA7F8 8800023C */  lui        $2, %hi(D_00881408)
    /* EA7FC 001EA7FC 081440E4 */  swc1       $f0, %lo(D_00881408)($2)
    /* EA800 001EA800 06000424 */  addiu      $4, $0, 0x6
    /* EA804 001EA804 54730A0C */  jal        func_0029cd50
    /* EA808 001EA808 00000000 */   nop
    /* EA80C 001EA80C 58B480E7 */  swc1       $f0, -0x4BA8($28)
    /* EA810 001EA810 01000224 */  addiu      $2, $0, 0x1
    /* EA814 001EA814 0000BFDF */  ld         $31, 0x0($29)
    /* EA818 001EA818 1000BD27 */  addiu      $29, $29, 0x10
    /* EA81C 001EA81C 0800E003 */  jr         $31
    /* EA820 001EA820 00000000 */   nop
    /* EA824 001EA824 00000000 */  nop
    /* EA828 001EA828 00000000 */  nop
    /* EA82C 001EA82C 00000000 */  nop
.size func_001ea780, 0xb0
