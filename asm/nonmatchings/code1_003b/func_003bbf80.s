.section .text
.set noat
.set noreorder
glabel func_003bbf80
    /* 2BBF80 003BBF80 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2BBF84 003BBF84 7000BFFF */  sd         $31, 0x70($29)
    /* 2BBF88 003BBF88 6000B67F */  sq         $22, 0x60($29)
    /* 2BBF8C 003BBF8C 5000B57F */  sq         $21, 0x50($29)
    /* 2BBF90 003BBF90 4000B47F */  sq         $20, 0x40($29)
    /* 2BBF94 003BBF94 2DA88000 */  daddu      $21, $4, $0
    /* 2BBF98 003BBF98 3000B37F */  sq         $19, 0x30($29)
    /* 2BBF9C 003BBF9C 2000B27F */  sq         $18, 0x20($29)
    /* 2BBFA0 003BBFA0 1000B17F */  sq         $17, 0x10($29)
    /* 2BBFA4 003BBFA4 0000B07F */  sq         $16, 0x0($29)
    /* 2BBFA8 003BBFA8 0400A38C */  lw         $3, 0x4($5)
    /* 2BBFAC 003BBFAC 040083AC */  sw         $3, 0x4($4)
    /* 2BBFB0 003BBFB0 0800A38C */  lw         $3, 0x8($5)
    /* 2BBFB4 003BBFB4 080083AC */  sw         $3, 0x8($4)
    /* 2BBFB8 003BBFB8 0000A38C */  lw         $3, 0x0($5)
    /* 2BBFBC 003BBFBC 18006010 */  beqz       $3, .L003BC020
    /* 2BBFC0 003BBFC0 2D90A000 */   daddu     $18, $5, $0
    /* 2BBFC4 003BBFC4 0000A0AE */  sw         $0, 0x0($21)
    /* 2BBFC8 003BBFC8 0000448E */  lw         $4, 0x0($18)
    /* 2BBFCC 003BBFCC 14008010 */  beqz       $4, .L003BC020
    /* 2BBFD0 003BBFD0 00000000 */   nop
    /* 2BBFD4 003BBFD4 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2BBFD8 003BBFD8 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2BBFDC 003BBFDC 09F84000 */  jalr       $2
    /* 2BBFE0 003BBFE0 00000000 */   nop
    /* 2BBFE4 003BBFE4 01004424 */  addiu      $4, $2, 0x1
    /* 2BBFE8 003BBFE8 0300023C */  lui        $2, (0x30002 >> 16)
    /* 2BBFEC 003BBFEC 02004534 */  ori        $5, $2, (0x30002 & 0xFFFF)
    /* 2BBFF0 003BBFF0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BBFF4 003BBFF4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BBFF8 003BBFF8 09F84000 */  jalr       $2
    /* 2BBFFC 003BBFFC 00000000 */   nop
    /* 2BC000 003BC000 0000A2AE */  sw         $2, 0x0($21)
    /* 2BC004 003BC004 0000A48E */  lw         $4, 0x0($21)
    /* 2BC008 003BC008 05008010 */  beqz       $4, .L003BC020
    /* 2BC00C 003BC00C 00000000 */   nop
    /* 2BC010 003BC010 8800023C */  lui        $2, %hi(D_008873AC)
    /* 2BC014 003BC014 AC73428C */  lw         $2, %lo(D_008873AC)($2)
    /* 2BC018 003BC018 09F84000 */  jalr       $2
    /* 2BC01C 003BC01C 0000458E */   lw        $5, 0x0($18)
  .L003BC020:
    /* 2BC020 003BC020 0C00438E */  lw         $3, 0xC($18)
    /* 2BC024 003BC024 40006010 */  beqz       $3, .L003BC128
    /* 2BC028 003BC028 00000000 */   nop
    /* 2BC02C 003BC02C 44F40E0C */  jal        func_003bd110
    /* 2BC030 003BC030 0400A48E */   lw        $4, 0x4($21)
    /* 2BC034 003BC034 0800A38E */  lw         $3, 0x8($21)
    /* 2BC038 003BC038 18806200 */  mult       $16, $3, $2
    /* 2BC03C 003BC03C 8800113C */  lui        $17, %hi(jtbl_008873E8)
    /* 2BC040 003BC040 E8733126 */  addiu      $17, $17, %lo(jtbl_008873E8)
    /* 2BC044 003BC044 0000228E */  lw         $2, 0x0($17)
    /* 2BC048 003BC048 0300033C */  lui        $3, (0x3011F >> 16)
    /* 2BC04C 003BC04C 1F016534 */  ori        $5, $3, (0x3011F & 0xFFFF)
    /* 2BC050 003BC050 09F84000 */  jalr       $2
    /* 2BC054 003BC054 2D200002 */   daddu     $4, $16, $0
    /* 2BC058 003BC058 0C00A2AE */  sw         $2, 0xC($21)
    /* 2BC05C 003BC05C 03000324 */  addiu      $3, $0, 0x3
    /* 2BC060 003BC060 0400A48E */  lw         $4, 0x4($21)
    /* 2BC064 003BC064 2C008314 */  bne        $4, $3, .L003BC118
    /* 2BC068 003BC068 00000000 */   nop
    /* 2BC06C 003BC06C 0C00538E */  lw         $19, 0xC($18)
    /* 2BC070 003BC070 0800A38E */  lw         $3, 0x8($21)
    /* 2BC074 003BC074 0C00B28E */  lw         $18, 0xC($21)
    /* 2BC078 003BC078 2A080300 */  slt        $1, $0, $3
    /* 2BC07C 003BC07C 2A002010 */  beqz       $1, .L003BC128
    /* 2BC080 003BC080 2DA00000 */   daddu     $20, $0, $0
    /* 2BC084 003BC084 8800103C */  lui        $16, %hi(D_008873D4)
    /* 2BC088 003BC088 8800163C */  lui        $22, %hi(D_008873AC)
    /* 2BC08C 003BC08C D4731026 */  addiu      $16, $16, %lo(D_008873D4)
    /* 2BC090 003BC090 AC73D626 */  addiu      $22, $22, %lo(D_008873AC)
  .L003BC094:
    /* 2BC094 003BC094 0000638E */  lw         $3, 0x0($19)
    /* 2BC098 003BC098 1D006010 */  beqz       $3, .L003BC110
    /* 2BC09C 003BC09C 00000000 */   nop
    /* 2BC0A0 003BC0A0 000040AE */  sw         $0, 0x0($18)
    /* 2BC0A4 003BC0A4 0000648E */  lw         $4, 0x0($19)
    /* 2BC0A8 003BC0A8 11008010 */  beqz       $4, .L003BC0F0
    /* 2BC0AC 003BC0AC 00000000 */   nop
    /* 2BC0B0 003BC0B0 0000028E */  lw         $2, 0x0($16)
    /* 2BC0B4 003BC0B4 09F84000 */  jalr       $2
    /* 2BC0B8 003BC0B8 00000000 */   nop
    /* 2BC0BC 003BC0BC 01004424 */  addiu      $4, $2, 0x1
    /* 2BC0C0 003BC0C0 0300023C */  lui        $2, (0x30002 >> 16)
    /* 2BC0C4 003BC0C4 02004534 */  ori        $5, $2, (0x30002 & 0xFFFF)
    /* 2BC0C8 003BC0C8 0000228E */  lw         $2, 0x0($17)
    /* 2BC0CC 003BC0CC 09F84000 */  jalr       $2
    /* 2BC0D0 003BC0D0 00000000 */   nop
    /* 2BC0D4 003BC0D4 000042AE */  sw         $2, 0x0($18)
    /* 2BC0D8 003BC0D8 0000448E */  lw         $4, 0x0($18)
    /* 2BC0DC 003BC0DC 04008010 */  beqz       $4, .L003BC0F0
    /* 2BC0E0 003BC0E0 00000000 */   nop
    /* 2BC0E4 003BC0E4 0000C28E */  lw         $2, 0x0($22)
    /* 2BC0E8 003BC0E8 09F84000 */  jalr       $2
    /* 2BC0EC 003BC0EC 0000658E */   lw        $5, 0x0($19)
  .L003BC0F0:
    /* 2BC0F0 003BC0F0 0800A38E */  lw         $3, 0x8($21)
    /* 2BC0F4 003BC0F4 01009426 */  addiu      $20, $20, 0x1
    /* 2BC0F8 003BC0F8 04007326 */  addiu      $19, $19, 0x4
    /* 2BC0FC 003BC0FC 2A188302 */  slt        $3, $20, $3
    /* 2BC100 003BC100 E4FF6014 */  bnez       $3, .L003BC094
    /* 2BC104 003BC104 04005226 */   addiu     $18, $18, 0x4
    /* 2BC108 003BC108 08000010 */  b          .L003BC12C
    /* 2BC10C 003BC10C 7000BFDF */   ld        $31, 0x70($29)
  .L003BC110:
    /* 2BC110 003BC110 F7FF0010 */  b          .L003BC0F0
    /* 2BC114 003BC114 000040AE */   sw        $0, 0x0($18)
  .L003BC118:
    /* 2BC118 003BC118 0C00A48E */  lw         $4, 0xC($21)
    /* 2BC11C 003BC11C 0C00458E */  lw         $5, 0xC($18)
    /* 2BC120 003BC120 04FE100C */  jal        func_0043f810
    /* 2BC124 003BC124 2D300002 */   daddu     $6, $16, $0
  .L003BC128:
    /* 2BC128 003BC128 7000BFDF */  ld         $31, 0x70($29)
  .L003BC12C:
    /* 2BC12C 003BC12C 6000B67B */  lq         $22, 0x60($29)
    /* 2BC130 003BC130 5000B57B */  lq         $21, 0x50($29)
    /* 2BC134 003BC134 4000B47B */  lq         $20, 0x40($29)
    /* 2BC138 003BC138 3000B37B */  lq         $19, 0x30($29)
    /* 2BC13C 003BC13C 2000B27B */  lq         $18, 0x20($29)
    /* 2BC140 003BC140 1000B17B */  lq         $17, 0x10($29)
    /* 2BC144 003BC144 0000B07B */  lq         $16, 0x0($29)
    /* 2BC148 003BC148 0800E003 */  jr         $31
    /* 2BC14C 003BC14C 8000BD27 */   addiu     $29, $29, 0x80
.size func_003bbf80, 0x1d0
