.section .text
.set noat
.set noreorder
glabel func_001ec2b0
    /* EC2B0 001EC2B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EC2B4 001EC2B4 0000BFFF */  sd         $31, 0x0($29)
    /* EC2B8 001EC2B8 0400A9C4 */  lwc1       $f9, 0x4($5)
    /* EC2BC 001EC2BC 040088C4 */  lwc1       $f8, 0x4($4)
    /* EC2C0 001EC2C0 0000A1C4 */  lwc1       $f1, 0x0($5)
    /* EC2C4 001EC2C4 000087C4 */  lwc1       $f7, 0x0($4)
    /* EC2C8 001EC2C8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* EC2CC 001EC2CC 080086C4 */  lwc1       $f6, 0x8($4)
    /* EC2D0 001EC2D0 1A400946 */  mula.s     $f8, $f9
    /* EC2D4 001EC2D4 00288044 */  mtc1       $0, $f5
    /* EC2D8 001EC2D8 1E380146 */  madda.s    $f7, $f1
    /* EC2DC 001EC2DC 1E300046 */  madda.s    $f6, $f0
    /* EC2E0 001EC2E0 0C00A4C4 */  lwc1       $f4, 0xC($5)
    /* EC2E4 001EC2E4 0C0083C4 */  lwc1       $f3, 0xC($4)
    /* EC2E8 001EC2E8 1C1B0446 */  madd.s     $f12, $f3, $f4
    /* EC2EC 001EC2EC 34600546 */  c.lt.s     $f12, $f5
    /* EC2F0 001EC2F0 0C000045 */  bc1f       .L001EC324
    /* EC2F4 001EC2F4 00000000 */   nop
    /* EC2F8 001EC2F8 87000046 */  neg.s      $f2, $f0
    /* EC2FC 001EC2FC 47080046 */  neg.s      $f1, $f1
    /* EC300 001EC300 07480046 */  neg.s      $f0, $f9
    /* EC304 001EC304 02400046 */  mul.s      $f0, $f8, $f0
    /* EC308 001EC308 18280046 */  adda.s     $f5, $f0
    /* EC30C 001EC30C 1C380146 */  madd.s     $f0, $f7, $f1
    /* EC310 001EC310 18280046 */  adda.s     $f5, $f0
    /* EC314 001EC314 5C300246 */  madd.s     $f1, $f6, $f2
    /* EC318 001EC318 07200046 */  neg.s      $f0, $f4
    /* EC31C 001EC31C 18280146 */  adda.s     $f5, $f1
    /* EC320 001EC320 1C1B0046 */  madd.s     $f12, $f3, $f0
  .L001EC324:
    /* EC324 001EC324 482E110C */  jal        func_0044b920
    /* EC328 001EC328 00000000 */   nop
    /* EC32C 001EC32C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* EC330 001EC330 00088244 */  mtc1       $2, $f1
    /* EC334 001EC334 00000000 */  nop
    /* EC338 001EC338 02080046 */  mul.s      $f0, $f1, $f0
    /* EC33C 001EC33C 0000BFDF */  ld         $31, 0x0($29)
    /* EC340 001EC340 1000BD27 */  addiu      $29, $29, 0x10
    /* EC344 001EC344 0800E003 */  jr         $31
    /* EC348 001EC348 00000000 */   nop
    /* EC34C 001EC34C 00000000 */  nop
.size func_001ec2b0, 0xa0
