.section .text
.set noat
.set noreorder
glabel func_001de000
    /* DE000 001DE000 10FFBD27 */  addiu      $29, $29, -0xF0
    /* DE004 001DE004 9000BFFF */  sd         $31, 0x90($29)
    /* DE008 001DE008 8000BE7F */  sq         $30, 0x80($29)
    /* DE00C 001DE00C 7000B77F */  sq         $23, 0x70($29)
    /* DE010 001DE010 6000B67F */  sq         $22, 0x60($29)
    /* DE014 001DE014 5000B57F */  sq         $21, 0x50($29)
    /* DE018 001DE018 4000B47F */  sq         $20, 0x40($29)
    /* DE01C 001DE01C 3000B37F */  sq         $19, 0x30($29)
    /* DE020 001DE020 2000B27F */  sq         $18, 0x20($29)
    /* DE024 001DE024 1000B17F */  sq         $17, 0x10($29)
    /* DE028 001DE028 0000B07F */  sq         $16, 0x0($29)
    /* DE02C 001DE02C 2DA88000 */  daddu      $21, $4, $0
    /* DE030 001DE030 2DA0A000 */  daddu      $20, $5, $0
    /* DE034 001DE034 DC00A7AF */  sw         $7, 0xDC($29)
    /* DE038 001DE038 3CBC0600 */  dsll32     $23, $6, 16
    /* DE03C 001DE03C 3FBC1700 */  dsra32     $23, $23, 16
    /* DE040 001DE040 10000224 */  addiu      $2, $0, 0x10
    /* DE044 001DE044 0500E216 */  bne        $23, $2, .L001DE05C
    /* DE048 001DE048 00000000 */   nop
    /* DE04C 001DE04C 4876070C */  jal        func_001dd920
    /* DE050 001DE050 00000000 */   nop
    /* DE054 001DE054 B7000010 */  b          .L001DE334
    /* DE058 001DE058 00000000 */   nop
  .L001DE05C:
    /* DE05C 001DE05C 2D900000 */  daddu      $18, $0, $0
    /* DE060 001DE060 3000B08E */  lw         $16, 0x30($21)
    /* DE064 001DE064 640A048E */  lw         $4, 0xA64($16)
    /* DE068 001DE068 2D280000 */  daddu      $5, $0, $0
    /* DE06C 001DE06C 38F6080C */  jal        func_0023d8e0
    /* DE070 001DE070 00000000 */   nop
    /* DE074 001DE074 3C2C0200 */  dsll32     $5, $2, 16
    /* DE078 001DE078 3F2C0500 */  dsra32     $5, $5, 16
    /* DE07C 001DE07C 0A00B714 */  bne        $5, $23, .L001DE0A8
    /* DE080 001DE080 00000000 */   nop
    /* DE084 001DE084 2D208002 */  daddu      $4, $20, $0
    /* DE088 001DE088 01000624 */  addiu      $6, $0, 0x1
    /* DE08C 001DE08C D86C070C */  jal        func_001db360
    /* DE090 001DE090 00000000 */   nop
    /* DE094 001DE094 04004010 */  beqz       $2, .L001DE0A8
    /* DE098 001DE098 00000000 */   nop
    /* DE09C 001DE09C E000A0A7 */  sh         $0, 0xE0($29)
    /* DE0A0 001DE0A0 01004226 */  addiu      $2, $18, 0x1
    /* DE0A4 001DE0A4 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DE0A8:
    /* DE0A8 001DE0A8 640A048E */  lw         $4, 0xA64($16)
    /* DE0AC 001DE0AC 4CF8080C */  jal        func_0023e130
    /* DE0B0 001DE0B0 00000000 */   nop
    /* DE0B4 001DE0B4 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* DE0B8 001DE0B8 640A048E */  lw         $4, 0xA64($16)
    /* DE0BC 001DE0BC 50F8080C */  jal        func_0023e140
    /* DE0C0 001DE0C0 00000000 */   nop
    /* DE0C4 001DE0C4 C000A27F */  sq         $2, 0xC0($29)
    /* DE0C8 001DE0C8 2D980000 */  daddu      $19, $0, $0
    /* DE0CC 001DE0CC FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DE0D0 001DE0D0 B000A27F */  sq         $2, 0xB0($29)
    /* DE0D4 001DE0D4 5A000010 */  b          .L001DE240
    /* DE0D8 001DE0D8 00000000 */   nop
  .L001DE0DC:
    /* DE0DC 001DE0DC FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DE0E0 001DE0E0 40180200 */  sll        $3, $2, 1
    /* DE0E4 001DE0E4 C000A27B */  lq         $2, 0xC0($29)
    /* DE0E8 001DE0E8 21F04300 */  addu       $30, $2, $3
    /* DE0EC 001DE0EC 0000C597 */  lhu        $5, 0x0($30)
    /* DE0F0 001DE0F0 5100A010 */  beqz       $5, .L001DE238
    /* DE0F4 001DE0F4 00000000 */   nop
    /* DE0F8 001DE0F8 B801A128 */  slti       $1, $5, 0x1B8
    /* DE0FC 001DE0FC 4E002010 */  beqz       $1, .L001DE238
    /* DE100 001DE100 00000000 */   nop
    /* DE104 001DE104 640A048E */  lw         $4, 0xA64($16)
    /* DE108 001DE108 38F6080C */  jal        func_0023d8e0
    /* DE10C 001DE10C 00000000 */   nop
    /* DE110 001DE110 3C140200 */  dsll32     $2, $2, 16
    /* DE114 001DE114 3F140200 */  dsra32     $2, $2, 16
    /* DE118 001DE118 A000A27F */  sq         $2, 0xA0($29)
    /* DE11C 001DE11C 46005714 */  bne        $2, $23, .L001DE238
    /* DE120 001DE120 00000000 */   nop
    /* DE124 001DE124 0000D197 */  lhu        $17, 0x0($30)
    /* DE128 001DE128 4002222A */  slti       $2, $17, 0x240
    /* DE12C 001DE12C 06004014 */  bnez       $2, .L001DE148
    /* DE130 001DE130 00000000 */   nop
    /* DE134 001DE134 6100043C */  lui        $4, %hi(D_006095E0)
    /* DE138 001DE138 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DE13C 001DE13C 5F040524 */  addiu      $5, $0, 0x45F
    /* DE140 001DE140 CCB5110C */  jal        func_0046d730
    /* DE144 001DE144 00000000 */   nop
  .L001DE148:
    /* DE148 001DE148 3000B68E */  lw         $22, 0x30($21)
    /* DE14C 001DE14C B801212A */  slti       $1, $17, 0x1B8
    /* DE150 001DE150 1D002010 */  beqz       $1, .L001DE1C8
    /* DE154 001DE154 00000000 */   nop
    /* DE158 001DE158 640AC48E */  lw         $4, 0xA64($22)
    /* DE15C 001DE15C 0800023C */  lui        $2, (0x80008 >> 16)
    /* DE160 001DE160 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DE164 001DE164 C4C9080C */  jal        func_00232710
    /* DE168 001DE168 00000000 */   nop
    /* DE16C 001DE16C 04004010 */  beqz       $2, .L001DE180
    /* DE170 001DE170 00000000 */   nop
    /* DE174 001DE174 2D100000 */  daddu      $2, $0, $0
    /* DE178 001DE178 1D000010 */  b          .L001DE1F0
    /* DE17C 001DE17C 00000000 */   nop
  .L001DE180:
    /* DE180 001DE180 640AC48E */  lw         $4, 0xA64($22)
    /* DE184 001DE184 2D282002 */  daddu      $5, $17, $0
    /* DE188 001DE188 CCC9080C */  jal        func_00232730
    /* DE18C 001DE18C 00000000 */   nop
    /* DE190 001DE190 04004014 */  bnez       $2, .L001DE1A4
    /* DE194 001DE194 00000000 */   nop
    /* DE198 001DE198 2D100000 */  daddu      $2, $0, $0
    /* DE19C 001DE19C 14000010 */  b          .L001DE1F0
    /* DE1A0 001DE1A0 00000000 */   nop
  .L001DE1A4:
    /* DE1A4 001DE1A4 640AC48E */  lw         $4, 0xA64($22)
    /* DE1A8 001DE1A8 2D282002 */  daddu      $5, $17, $0
    /* DE1AC 001DE1AC 70F7080C */  jal        func_0023ddc0
    /* DE1B0 001DE1B0 00000000 */   nop
    /* DE1B4 001DE1B4 0D004010 */  beqz       $2, .L001DE1EC
    /* DE1B8 001DE1B8 00000000 */   nop
    /* DE1BC 001DE1BC 2D100000 */  daddu      $2, $0, $0
    /* DE1C0 001DE1C0 0B000010 */  b          .L001DE1F0
    /* DE1C4 001DE1C4 00000000 */   nop
  .L001DE1C8:
    /* DE1C8 001DE1C8 640AC48E */  lw         $4, 0xA64($22)
    /* DE1CC 001DE1CC 2D282002 */  daddu      $5, $17, $0
    /* DE1D0 001DE1D0 CCC9080C */  jal        func_00232730
    /* DE1D4 001DE1D4 00000000 */   nop
    /* DE1D8 001DE1D8 04004014 */  bnez       $2, .L001DE1EC
    /* DE1DC 001DE1DC 00000000 */   nop
    /* DE1E0 001DE1E0 2D100000 */  daddu      $2, $0, $0
    /* DE1E4 001DE1E4 02000010 */  b          .L001DE1F0
    /* DE1E8 001DE1E8 00000000 */   nop
  .L001DE1EC:
    /* DE1EC 001DE1EC 01000224 */  addiu      $2, $0, 0x1
  .L001DE1F0:
    /* DE1F0 001DE1F0 11004010 */  beqz       $2, .L001DE238
    /* DE1F4 001DE1F4 00000000 */   nop
    /* DE1F8 001DE1F8 A000A27B */  lq         $2, 0xA0($29)
    /* DE1FC 001DE1FC 3C2C0200 */  dsll32     $5, $2, 16
    /* DE200 001DE200 3F2C0500 */  dsra32     $5, $5, 16
    /* DE204 001DE204 2D208002 */  daddu      $4, $20, $0
    /* DE208 001DE208 01000624 */  addiu      $6, $0, 0x1
    /* DE20C 001DE20C D86C070C */  jal        func_001db360
    /* DE210 001DE210 00000000 */   nop
    /* DE214 001DE214 08004010 */  beqz       $2, .L001DE238
    /* DE218 001DE218 00000000 */   nop
    /* DE21C 001DE21C 0000C397 */  lhu        $3, 0x0($30)
    /* DE220 001DE220 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DE224 001DE224 40100200 */  sll        $2, $2, 1
    /* DE228 001DE228 21105D00 */  addu       $2, $2, $29
    /* DE22C 001DE22C E00043A4 */  sh         $3, 0xE0($2)
    /* DE230 001DE230 01004226 */  addiu      $2, $18, 0x1
    /* DE234 001DE234 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DE238:
    /* DE238 001DE238 01006226 */  addiu      $2, $19, 0x1
    /* DE23C 001DE23C FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001DE240:
    /* DE240 001DE240 FFFF6332 */  andi       $3, $19, 0xFFFF
    /* DE244 001DE244 B000A27B */  lq         $2, 0xB0($29)
    /* DE248 001DE248 2A106200 */  slt        $2, $3, $2
    /* DE24C 001DE24C A3FF4014 */  bnez       $2, .L001DE0DC
    /* DE250 001DE250 00000000 */   nop
    /* DE254 001DE254 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DE258 001DE258 35004018 */  blez       $2, .L001DE330
    /* DE25C 001DE25C 00000000 */   nop
    /* DE260 001DE260 01000824 */  addiu      $8, $0, 0x1
    /* DE264 001DE264 DC00A28F */  lw         $2, 0xDC($29)
    /* DE268 001DE268 17004810 */  beq        $2, $8, .L001DE2C8
    /* DE26C 001DE26C 00000000 */   nop
    /* DE270 001DE270 03004010 */  beqz       $2, .L001DE280
    /* DE274 001DE274 00000000 */   nop
    /* DE278 001DE278 24000010 */  b          .L001DE30C
    /* DE27C 001DE27C 00000000 */   nop
  .L001DE280:
    /* DE280 001DE280 2D20A002 */  daddu      $4, $21, $0
    /* DE284 001DE284 2D288002 */  daddu      $5, $20, $0
    /* DE288 001DE288 E000A627 */  addiu      $6, $29, 0xE0
    /* DE28C 001DE28C 2D384002 */  daddu      $7, $18, $0
    /* DE290 001DE290 2D400000 */  daddu      $8, $0, $0
    /* DE294 001DE294 7074070C */  jal        func_001dd1c0
    /* DE298 001DE298 00000000 */   nop
    /* DE29C 001DE29C 25004104 */  bgez       $2, .L001DE334
    /* DE2A0 001DE2A0 00000000 */   nop
    /* DE2A4 001DE2A4 2D20A002 */  daddu      $4, $21, $0
    /* DE2A8 001DE2A8 2D288002 */  daddu      $5, $20, $0
    /* DE2AC 001DE2AC E000A627 */  addiu      $6, $29, 0xE0
    /* DE2B0 001DE2B0 2D384002 */  daddu      $7, $18, $0
    /* DE2B4 001DE2B4 01000824 */  addiu      $8, $0, 0x1
    /* DE2B8 001DE2B8 7074070C */  jal        func_001dd1c0
    /* DE2BC 001DE2BC 00000000 */   nop
    /* DE2C0 001DE2C0 1C000010 */  b          .L001DE334
    /* DE2C4 001DE2C4 00000000 */   nop
  .L001DE2C8:
    /* DE2C8 001DE2C8 2D20A002 */  daddu      $4, $21, $0
    /* DE2CC 001DE2CC 2D288002 */  daddu      $5, $20, $0
    /* DE2D0 001DE2D0 E000A627 */  addiu      $6, $29, 0xE0
    /* DE2D4 001DE2D4 2D384002 */  daddu      $7, $18, $0
    /* DE2D8 001DE2D8 7074070C */  jal        func_001dd1c0
    /* DE2DC 001DE2DC 00000000 */   nop
    /* DE2E0 001DE2E0 14004104 */  bgez       $2, .L001DE334
    /* DE2E4 001DE2E4 00000000 */   nop
    /* DE2E8 001DE2E8 2D20A002 */  daddu      $4, $21, $0
    /* DE2EC 001DE2EC 2D288002 */  daddu      $5, $20, $0
    /* DE2F0 001DE2F0 E000A627 */  addiu      $6, $29, 0xE0
    /* DE2F4 001DE2F4 2D384002 */  daddu      $7, $18, $0
    /* DE2F8 001DE2F8 2D400000 */  daddu      $8, $0, $0
    /* DE2FC 001DE2FC 7074070C */  jal        func_001dd1c0
    /* DE300 001DE300 00000000 */   nop
    /* DE304 001DE304 0B000010 */  b          .L001DE334
    /* DE308 001DE308 00000000 */   nop
  .L001DE30C:
    /* DE30C 001DE30C 2D20A002 */  daddu      $4, $21, $0
    /* DE310 001DE310 2D288002 */  daddu      $5, $20, $0
    /* DE314 001DE314 E000A627 */  addiu      $6, $29, 0xE0
    /* DE318 001DE318 2D384002 */  daddu      $7, $18, $0
    /* DE31C 001DE31C FFFF0834 */  ori        $8, $0, 0xFFFF
    /* DE320 001DE320 7074070C */  jal        func_001dd1c0
    /* DE324 001DE324 00000000 */   nop
    /* DE328 001DE328 02000010 */  b          .L001DE334
    /* DE32C 001DE32C 00000000 */   nop
  .L001DE330:
    /* DE330 001DE330 FFFF0224 */  addiu      $2, $0, -0x1
  .L001DE334:
    /* DE334 001DE334 9000BFDF */  ld         $31, 0x90($29)
    /* DE338 001DE338 8000BE7B */  lq         $30, 0x80($29)
    /* DE33C 001DE33C 7000B77B */  lq         $23, 0x70($29)
    /* DE340 001DE340 6000B67B */  lq         $22, 0x60($29)
    /* DE344 001DE344 5000B57B */  lq         $21, 0x50($29)
    /* DE348 001DE348 4000B47B */  lq         $20, 0x40($29)
    /* DE34C 001DE34C 3000B37B */  lq         $19, 0x30($29)
    /* DE350 001DE350 2000B27B */  lq         $18, 0x20($29)
    /* DE354 001DE354 1000B17B */  lq         $17, 0x10($29)
    /* DE358 001DE358 0000B07B */  lq         $16, 0x0($29)
    /* DE35C 001DE35C F000BD27 */  addiu      $29, $29, 0xF0
    /* DE360 001DE360 0800E003 */  jr         $31
    /* DE364 001DE364 00000000 */   nop
    /* DE368 001DE368 00000000 */  nop
    /* DE36C 001DE36C 00000000 */  nop
.size func_001de000, 0x370
