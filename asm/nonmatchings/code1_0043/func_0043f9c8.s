.section .text
.set noat
.set noreorder
glabel func_0043f9c8
    /* 33F9C8 0043F9C8 0800C22C */  sltiu      $2, $6, 0x8
    /* 33F9CC 0043F9CC 1E004014 */  bnez       $2, .L0043FA48
    /* 33F9D0 0043F9D0 2D188000 */   daddu     $3, $4, $0
    /* 33F9D4 0043F9D4 0F008230 */  andi       $2, $4, 0xF
    /* 33F9D8 0043F9D8 1B004014 */  bnez       $2, .L0043FA48
    /* 33F9DC 0043F9DC 2D388000 */   daddu     $7, $4, $0
    /* 33F9E0 0043F9E0 FF00A930 */  andi       $9, $5, 0xFF
    /* 33F9E4 0043F9E4 2000CA2C */  sltiu      $10, $6, 0x20
    /* 33F9E8 0043F9E8 2D402001 */  daddu      $8, $9, $0
    /* 33F9EC 0043F9EC 381A0800 */  dsll       $3, $8, 8
    /* 33F9F0 0043F9F0 25406900 */  or         $8, $3, $9
    /* 33F9F4 0043F9F4 E91E0870 */  pcpyh      $3, $8
    /* 33F9F8 0043F9F8 0E004015 */  bnez       $10, .L0043FA34
    /* 33F9FC 0043F9FC 0800C22C */   sltiu     $2, $6, 0x8
    /* 33FA00 0043FA00 89436370 */  pcpyld     $8, $3, $3
  .L0043FA04:
    /* 33FA04 0043FA04 0000E87C */  sq         $8, 0x0($7)
    /* 33FA08 0043FA08 E0FFC624 */  addiu      $6, $6, -0x20
    /* 33FA0C 0043FA0C 1000E724 */  addiu      $7, $7, 0x10
    /* 33FA10 0043FA10 2000C22C */  sltiu      $2, $6, 0x20
    /* 33FA14 0043FA14 0000E87C */  sq         $8, 0x0($7)
    /* 33FA18 0043FA18 FAFF4010 */  beqz       $2, .L0043FA04
    /* 33FA1C 0043FA1C 1000E724 */   addiu     $7, $7, 0x10
    /* 33FA20 0043FA20 04000010 */  b          .L0043FA34
    /* 33FA24 0043FA24 0800C22C */   sltiu     $2, $6, 0x8
  .L0043FA28:
    /* 33FA28 0043FA28 F8FFC624 */  addiu      $6, $6, -0x8
    /* 33FA2C 0043FA2C 0800E724 */  addiu      $7, $7, 0x8
    /* 33FA30 0043FA30 0800C22C */  sltiu      $2, $6, 0x8
  .L0043FA34:
    /* 33FA34 0043FA34 00000000 */  nop
    /* 33FA38 0043FA38 00000000 */  nop
    /* 33FA3C 0043FA3C FAFF4050 */  beql       $2, $0, .L0043FA28
    /* 33FA40 0043FA40 0000E3FC */   sd        $3, 0x0($7)
    /* 33FA44 0043FA44 2D18E000 */  daddu      $3, $7, $0
  .L0043FA48:
    /* 33FA48 0043FA48 FFFF023C */  lui        $2, (0xFFFFFFFF >> 16)
    /* 33FA4C 0043FA4C FFFFC624 */  addiu      $6, $6, -0x1
    /* 33FA50 0043FA50 FFFF4234 */  ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
    /* 33FA54 0043FA54 0A00C210 */  beq        $6, $2, .L0043FA80
    /* 33FA58 0043FA58 00000000 */   nop
    /* 33FA5C 0043FA5C FFFF023C */  lui        $2, (0xFFFFFFFF >> 16)
    /* 33FA60 0043FA60 FFFF4234 */  ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
  .L0043FA64:
    /* 33FA64 0043FA64 000065A0 */  sb         $5, 0x0($3)
    /* 33FA68 0043FA68 FFFFC624 */  addiu      $6, $6, -0x1
    /* 33FA6C 0043FA6C 01006324 */  addiu      $3, $3, 0x1
    /* 33FA70 0043FA70 00000000 */  nop
    /* 33FA74 0043FA74 00000000 */  nop
    /* 33FA78 0043FA78 FAFFC214 */  bne        $6, $2, .L0043FA64
    /* 33FA7C 0043FA7C 00000000 */   nop
  .L0043FA80:
    /* 33FA80 0043FA80 0800E003 */  jr         $31
    /* 33FA84 0043FA84 2D108000 */   daddu     $2, $4, $0
.size func_0043f9c8, 0xc0
