.section .text
.set noat
.set noreorder
glabel func_001bbf90
    /* BBF90 001BBF90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* BBF94 001BBF94 1000BFFF */  sd         $31, 0x10($29)
    /* BBF98 001BBF98 0000B07F */  sq         $16, 0x0($29)
    /* BBF9C 001BBF9C 2D808000 */  daddu      $16, $4, $0
    /* BBFA0 001BBFA0 00008394 */  lhu        $3, 0x0($4)
    /* BBFA4 001BBFA4 02006230 */  andi       $2, $3, 0x2
    /* BBFA8 001BBFA8 0A004010 */  beqz       $2, .L001BBFD4
    /* BBFAC 001BBFAC 00000000 */   nop
    /* BBFB0 001BBFB0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BBFB4 001BBFB4 00608244 */  mtc1       $2, $f12
    /* BBFB8 001BBFB8 84000426 */  addiu      $4, $16, 0x84
    /* BBFBC 001BBFBC 8CB1070C */  jal        func_001ec630
    /* BBFC0 001BBFC0 00000000 */   nop
    /* BBFC4 001BBFC4 800001C6 */  lwc1       $f1, 0x80($16)
    /* BBFC8 001BBFC8 01030146 */  sub.s      $f12, $f0, $f1
    /* BBFCC 001BBFCC 49000010 */  b          .L001BC0F4
    /* BBFD0 001BBFD0 00000000 */   nop
  .L001BBFD4:
    /* BBFD4 001BBFD4 04006230 */  andi       $2, $3, 0x4
    /* BBFD8 001BBFD8 27004010 */  beqz       $2, .L001BC078
    /* BBFDC 001BBFDC 00000000 */   nop
    /* BBFE0 001BBFE0 940002C6 */  lwc1       $f2, 0x94($16)
    /* BBFE4 001BBFE4 308480C7 */  lwc1       $f0, -0x7BD0($28)
    /* BBFE8 001BBFE8 34100046 */  c.lt.s     $f2, $f0
    /* BBFEC 001BBFEC 1F000045 */  bc1f       .L001BC06C
    /* BBFF0 001BBFF0 00000000 */   nop
    /* BBFF4 001BBFF4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BBFF8 001BBFF8 00088244 */  mtc1       $2, $f1
    /* BBFFC 001BBFFC 840000C6 */  lwc1       $f0, 0x84($16)
    /* BC000 001BC000 03080046 */  div.s      $f0, $f1, $f0
    /* BC004 001BC004 00110046 */  add.s      $f4, $f2, $f0
    /* BC008 001BC008 940004E6 */  swc1       $f4, 0x94($16)
    /* BC00C 001BC00C 8040023C */  lui        $2, (0x40800000 >> 16)
    /* BC010 001BC010 00188244 */  mtc1       $2, $f3
    /* BC014 001BC014 00C0023C */  lui        $2, (0xC0000000 >> 16)
    /* BC018 001BC018 00008244 */  mtc1       $2, $f0
    /* BC01C 001BC01C 00000000 */  nop
    /* BC020 001BC020 82000446 */  mul.s      $f2, $f0, $f4
    /* BC024 001BC024 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* BC028 001BC028 00088244 */  mtc1       $2, $f1
    /* BC02C 001BC02C 00008044 */  mtc1       $0, $f0
    /* BC030 001BC030 00000000 */  nop
    /* BC034 001BC034 18000146 */  adda.s     $f0, $f1
    /* BC038 001BC038 1E100446 */  madda.s    $f2, $f4
    /* BC03C 001BC03C 9C180446 */  madd.s     $f2, $f3, $f4
    /* BC040 001BC040 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BC044 001BC044 00088244 */  mtc1       $2, $f1
    /* BC048 001BC048 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BC04C 001BC04C 00008244 */  mtc1       $2, $f0
    /* BC050 001BC050 00000000 */  nop
    /* BC054 001BC054 01100046 */  sub.s      $f0, $f2, $f0
    /* BC058 001BC058 42080046 */  mul.s      $f1, $f1, $f0
    /* BC05C 001BC05C 800000C6 */  lwc1       $f0, 0x80($16)
    /* BC060 001BC060 010B0046 */  sub.s      $f12, $f1, $f0
    /* BC064 001BC064 23000010 */  b          .L001BC0F4
    /* BC068 001BC068 00000000 */   nop
  .L001BC06C:
    /* BC06C 001BC06C 00608044 */  mtc1       $0, $f12
    /* BC070 001BC070 20000010 */  b          .L001BC0F4
    /* BC074 001BC074 00000000 */   nop
  .L001BC078:
    /* BC078 001BC078 08006230 */  andi       $2, $3, 0x8
    /* BC07C 001BC07C 19004010 */  beqz       $2, .L001BC0E4
    /* BC080 001BC080 00000000 */   nop
    /* BC084 001BC084 880002C6 */  lwc1       $f2, 0x88($16)
    /* BC088 001BC088 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BC08C 001BC08C 00088244 */  mtc1       $2, $f1
    /* BC090 001BC090 840000C6 */  lwc1       $f0, 0x84($16)
    /* BC094 001BC094 02080046 */  mul.s      $f0, $f1, $f0
    /* BC098 001BC098 36100046 */  c.le.s     $f2, $f0
    /* BC09C 001BC09C 0E000145 */  bc1t       .L001BC0D8
    /* BC0A0 001BC0A0 00000000 */   nop
    /* BC0A4 001BC0A4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BC0A8 001BC0A8 00608244 */  mtc1       $2, $f12
    /* BC0AC 001BC0AC 84000426 */  addiu      $4, $16, 0x84
    /* BC0B0 001BC0B0 8CB1070C */  jal        func_001ec630
    /* BC0B4 001BC0B4 00000000 */   nop
    /* BC0B8 001BC0B8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BC0BC 001BC0BC 00088244 */  mtc1       $2, $f1
    /* BC0C0 001BC0C0 00000000 */  nop
    /* BC0C4 001BC0C4 42000146 */  mul.s      $f1, $f0, $f1
    /* BC0C8 001BC0C8 800000C6 */  lwc1       $f0, 0x80($16)
    /* BC0CC 001BC0CC 010B0046 */  sub.s      $f12, $f1, $f0
    /* BC0D0 001BC0D0 08000010 */  b          .L001BC0F4
    /* BC0D4 001BC0D4 00000000 */   nop
  .L001BC0D8:
    /* BC0D8 001BC0D8 00608044 */  mtc1       $0, $f12
    /* BC0DC 001BC0DC 05000010 */  b          .L001BC0F4
    /* BC0E0 001BC0E0 00000000 */   nop
  .L001BC0E4:
    /* BC0E4 001BC0E4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BC0E8 001BC0E8 00088244 */  mtc1       $2, $f1
    /* BC0EC 001BC0EC 840000C6 */  lwc1       $f0, 0x84($16)
    /* BC0F0 001BC0F0 030B0046 */  div.s      $f12, $f1, $f0
  .L001BC0F4:
    /* BC0F4 001BC0F4 800000C6 */  lwc1       $f0, 0x80($16)
    /* BC0F8 001BC0F8 00000C46 */  add.s      $f0, $f0, $f12
    /* BC0FC 001BC0FC 800000E6 */  swc1       $f0, 0x80($16)
    /* BC100 001BC100 2D200002 */  daddu      $4, $16, $0
    /* BC104 001BC104 60EF060C */  jal        func_001bbd80
    /* BC108 001BC108 00000000 */   nop
    /* BC10C 001BC10C ACB3828F */  lw         $2, -0x4C54($28)
    /* BC110 001BC110 24004424 */  addiu      $4, $2, 0x24
    /* BC114 001BC114 C0004524 */  addiu      $5, $2, 0xC0
    /* BC118 001BC118 CC004624 */  addiu      $6, $2, 0xCC
    /* BC11C 001BC11C 10EF060C */  jal        func_001bbc40
    /* BC120 001BC120 00000000 */   nop
    /* BC124 001BC124 1000BFDF */  ld         $31, 0x10($29)
    /* BC128 001BC128 0000B07B */  lq         $16, 0x0($29)
    /* BC12C 001BC12C 2000BD27 */  addiu      $29, $29, 0x20
    /* BC130 001BC130 0800E003 */  jr         $31
    /* BC134 001BC134 00000000 */   nop
    /* BC138 001BC138 00000000 */  nop
    /* BC13C 001BC13C 00000000 */  nop
.size func_001bbf90, 0x1b0
