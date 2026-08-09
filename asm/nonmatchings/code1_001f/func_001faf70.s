.section .text
.set noat
.set noreorder
glabel func_001faf70
    /* FAF70 001FAF70 80FFBD27 */  addiu      $29, $29, -0x80
    /* FAF74 001FAF74 7000BFFF */  sd         $31, 0x70($29)
    /* FAF78 001FAF78 6000B67F */  sq         $22, 0x60($29)
    /* FAF7C 001FAF7C 5000B57F */  sq         $21, 0x50($29)
    /* FAF80 001FAF80 4000B47F */  sq         $20, 0x40($29)
    /* FAF84 001FAF84 3000B37F */  sq         $19, 0x30($29)
    /* FAF88 001FAF88 2000B27F */  sq         $18, 0x20($29)
    /* FAF8C 001FAF8C 1000B17F */  sq         $17, 0x10($29)
    /* FAF90 001FAF90 0000B07F */  sq         $16, 0x0($29)
    /* FAF94 001FAF94 2D888000 */  daddu      $17, $4, $0
    /* FAF98 001FAF98 2D80A000 */  daddu      $16, $5, $0
    /* FAF9C 001FAF9C 2DB0C000 */  daddu      $22, $6, $0
    /* FAFA0 001FAFA0 0400001E */  bgtz       $16, .L001FAFB4
    /* FAFA4 001FAFA4 00000000 */   nop
    /* FAFA8 001FAFA8 2D100000 */  daddu      $2, $0, $0
    /* FAFAC 001FAFAC 63000010 */  b          .L001FB13C
    /* FAFB0 001FAFB0 00000000 */   nop
  .L001FAFB4:
    /* FAFB4 001FAFB4 80101000 */  sll        $2, $16, 2
    /* FAFB8 001FAFB8 21105000 */  addu       $2, $2, $16
    /* FAFBC 001FAFBC C0180200 */  sll        $3, $2, 3
    /* FAFC0 001FAFC0 B8B3828F */  lw         $2, -0x4C48($28)
    /* FAFC4 001FAFC4 21184300 */  addu       $3, $2, $3
    /* FAFC8 001FAFC8 00006290 */  lbu        $2, 0x0($3)
    /* FAFCC 001FAFCC 08004230 */  andi       $2, $2, 0x8
    /* FAFD0 001FAFD0 04004014 */  bnez       $2, .L001FAFE4
    /* FAFD4 001FAFD4 00000000 */   nop
    /* FAFD8 001FAFD8 2D100000 */  daddu      $2, $0, $0
    /* FAFDC 001FAFDC 57000010 */  b          .L001FB13C
    /* FAFE0 001FAFE0 00000000 */   nop
  .L001FAFE4:
    /* FAFE4 001FAFE4 2000728C */  lw         $18, 0x20($3)
    /* FAFE8 001FAFE8 7F7F023C */  lui        $2, (0x7F7FFFFF >> 16)
    /* FAFEC 001FAFEC FFFF4234 */  ori        $2, $2, (0x7F7FFFFF & 0xFFFF)
    /* FAFF0 001FAFF0 24104202 */  and        $2, $18, $2
    /* FAFF4 001FAFF4 32004010 */  beqz       $2, .L001FB0C0
    /* FAFF8 001FAFF8 00000000 */   nop
    /* FAFFC 001FAFFC 8080023C */  lui        $2, (0x80800000 >> 16)
    /* FB000 001FB000 24104202 */  and        $2, $18, $2
    /* FB004 001FB004 2E004014 */  bnez       $2, .L001FB0C0
    /* FB008 001FB008 00000000 */   nop
    /* FB00C 001FB00C 2DA80000 */  daddu      $21, $0, $0
    /* FB010 001FB010 1C000010 */  b          .L001FB084
    /* FB014 001FB014 00000000 */   nop
  .L001FB018:
    /* FB018 001FB018 01000224 */  addiu      $2, $0, 0x1
    /* FB01C 001FB01C 0498A202 */  sllv       $19, $2, $21
    /* FB020 001FB020 24105302 */  and        $2, $18, $19
    /* FB024 001FB024 16004010 */  beqz       $2, .L001FB080
    /* FB028 001FB028 00000000 */   nop
    /* FB02C 001FB02C 2DA00000 */  daddu      $20, $0, $0
    /* FB030 001FB030 0C000010 */  b          .L001FB064
    /* FB034 001FB034 00000000 */   nop
  .L001FB038:
    /* FB038 001FB038 80101400 */  sll        $2, $20, 2
    /* FB03C 001FB03C 21102202 */  addu       $2, $17, $2
    /* FB040 001FB040 3800428C */  lw         $2, 0x38($2)
    /* FB044 001FB044 3000428C */  lw         $2, 0x30($2)
    /* FB048 001FB048 640A448C */  lw         $4, 0xA64($2)
    /* FB04C 001FB04C 2D286002 */  daddu      $5, $19, $0
    /* FB050 001FB050 30D0080C */  jal        func_002340c0
    /* FB054 001FB054 00000000 */   nop
    /* FB058 001FB058 06004010 */  beqz       $2, .L001FB074
    /* FB05C 001FB05C 00000000 */   nop
    /* FB060 001FB060 01009426 */  addiu      $20, $20, 0x1
  .L001FB064:
    /* FB064 001FB064 6A002296 */  lhu        $2, 0x6A($17)
    /* FB068 001FB068 2B108202 */  sltu       $2, $20, $2
    /* FB06C 001FB06C F2FF4014 */  bnez       $2, .L001FB038
    /* FB070 001FB070 00000000 */   nop
  .L001FB074:
    /* FB074 001FB074 6A002296 */  lhu        $2, 0x6A($17)
    /* FB078 001FB078 05008216 */  bne        $20, $2, .L001FB090
    /* FB07C 001FB07C 00000000 */   nop
  .L001FB080:
    /* FB080 001FB080 0100B526 */  addiu      $21, $21, 0x1
  .L001FB084:
    /* FB084 001FB084 2000A22E */  sltiu      $2, $21, 0x20
    /* FB088 001FB088 E3FF4014 */  bnez       $2, .L001FB018
    /* FB08C 001FB08C 00000000 */   nop
  .L001FB090:
    /* FB090 001FB090 20000224 */  addiu      $2, $0, 0x20
    /* FB094 001FB094 0A00A216 */  bne        $21, $2, .L001FB0C0
    /* FB098 001FB098 00000000 */   nop
    /* FB09C 001FB09C 00304232 */  andi       $2, $18, 0x3000
    /* FB0A0 001FB0A0 04004010 */  beqz       $2, .L001FB0B4
    /* FB0A4 001FB0A4 00000000 */   nop
    /* FB0A8 001FB0A8 05000224 */  addiu      $2, $0, 0x5
    /* FB0AC 001FB0AC 02000010 */  b          .L001FB0B8
    /* FB0B0 001FB0B0 00000000 */   nop
  .L001FB0B4:
    /* FB0B4 001FB0B4 03000224 */  addiu      $2, $0, 0x3
  .L001FB0B8:
    /* FB0B8 001FB0B8 20000010 */  b          .L001FB13C
    /* FB0BC 001FB0BC 00000000 */   nop
  .L001FB0C0:
    /* FB0C0 001FB0C0 2D900000 */  daddu      $18, $0, $0
    /* FB0C4 001FB0C4 12000010 */  b          .L001FB110
    /* FB0C8 001FB0C8 00000000 */   nop
  .L001FB0CC:
    /* FB0CC 001FB0CC FFFF0432 */  andi       $4, $16, 0xFFFF
    /* FB0D0 001FB0D0 3000238E */  lw         $3, 0x30($17)
    /* FB0D4 001FB0D4 80101200 */  sll        $2, $18, 2
    /* FB0D8 001FB0D8 21102202 */  addu       $2, $17, $2
    /* FB0DC 001FB0DC 3800428C */  lw         $2, 0x38($2)
    /* FB0E0 001FB0E0 3000428C */  lw         $2, 0x30($2)
    /* FB0E4 001FB0E4 640A658C */  lw         $5, 0xA64($3)
    /* FB0E8 001FB0E8 640A468C */  lw         $6, 0xA64($2)
    /* FB0EC 001FB0EC 2D38C002 */  daddu      $7, $22, $0
    /* FB0F0 001FB0F0 78E8080C */  jal        func_0023a1e0
    /* FB0F4 001FB0F4 00000000 */   nop
    /* FB0F8 001FB0F8 09004010 */  beqz       $2, .L001FB120
    /* FB0FC 001FB0FC 00000000 */   nop
    /* FB100 001FB100 FFFF0334 */  ori        $3, $0, 0xFFFF
    /* FB104 001FB104 06004310 */  beq        $2, $3, .L001FB120
    /* FB108 001FB108 00000000 */   nop
    /* FB10C 001FB10C 01005226 */  addiu      $18, $18, 0x1
  .L001FB110:
    /* FB110 001FB110 6A002296 */  lhu        $2, 0x6A($17)
    /* FB114 001FB114 2B104202 */  sltu       $2, $18, $2
    /* FB118 001FB118 ECFF4014 */  bnez       $2, .L001FB0CC
    /* FB11C 001FB11C 00000000 */   nop
  .L001FB120:
    /* FB120 001FB120 6A002296 */  lhu        $2, 0x6A($17)
    /* FB124 001FB124 04004216 */  bne        $18, $2, .L001FB138
    /* FB128 001FB128 00000000 */   nop
    /* FB12C 001FB12C 04000224 */  addiu      $2, $0, 0x4
    /* FB130 001FB130 02000010 */  b          .L001FB13C
    /* FB134 001FB134 00000000 */   nop
  .L001FB138:
    /* FB138 001FB138 2D100000 */  daddu      $2, $0, $0
  .L001FB13C:
    /* FB13C 001FB13C 7000BFDF */  ld         $31, 0x70($29)
    /* FB140 001FB140 6000B67B */  lq         $22, 0x60($29)
    /* FB144 001FB144 5000B57B */  lq         $21, 0x50($29)
    /* FB148 001FB148 4000B47B */  lq         $20, 0x40($29)
    /* FB14C 001FB14C 3000B37B */  lq         $19, 0x30($29)
    /* FB150 001FB150 2000B27B */  lq         $18, 0x20($29)
    /* FB154 001FB154 1000B17B */  lq         $17, 0x10($29)
    /* FB158 001FB158 0000B07B */  lq         $16, 0x0($29)
    /* FB15C 001FB15C 8000BD27 */  addiu      $29, $29, 0x80
    /* FB160 001FB160 0800E003 */  jr         $31
    /* FB164 001FB164 00000000 */   nop
    /* FB168 001FB168 00000000 */  nop
    /* FB16C 001FB16C 00000000 */  nop
.size func_001faf70, 0x200
