.section .text
.set noat
.set noreorder
glabel func_003ebff0
    /* 2EBFF0 003EBFF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EBFF4 003EBFF4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2EBFF8 003EBFF8 2000BFFF */  sd         $31, 0x20($29)
    /* 2EBFFC 003EBFFC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EC000 003EC000 1000B07F */  sq         $16, 0x10($29)
    /* 2EC004 003EC004 00008244 */  mtc1       $2, $f0
    /* 2EC008 003EC008 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 2EC00C 003EC00C E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EC010 003EC010 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 2EC014 003EC014 01001024 */  addiu      $16, $0, 0x1
    /* 2EC018 003EC018 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2EC01C 003EC01C 46650046 */  mov.s      $f21, $f12
    /* 2EC020 003EC020 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EC024 003EC024 03051546 */  div.s      $f20, $f0, $f21
    /* 2EC028 003EC028 21106400 */  addu       $2, $3, $4
    /* 2EC02C 003EC02C 0C0255E4 */  swc1       $f21, 0x20C($2)
    /* 2EC030 003EC030 0C0040A0 */  sb         $0, 0xC($2)
    /* 2EC034 003EC034 0C0140A0 */  sb         $0, 0x10C($2)
  .L003EC038:
    /* 2EC038 003EC038 00089044 */  mtc1       $16, $f1
    /* 2EC03C 003EC03C 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 2EC040 003EC040 00008244 */  mtc1       $2, $f0
    /* 2EC044 003EC044 00000000 */  nop
    /* 2EC048 003EC048 60088046 */  cvt.s.w    $f1, $f1
    /* 2EC04C 003EC04C 830D0046 */  div.s      $f22, $f1, $f0
    /* 2EC050 003EC050 46A30046 */  mov.s      $f13, $f20
    /* 2EC054 003EC054 00000000 */  nop
    /* 2EC058 003EC058 00000000 */  nop
    /* 2EC05C 003EC05C 602E110C */  jal        func_0044b980
    /* 2EC060 003EC060 06B30046 */   mov.s     $f12, $f22
    /* 2EC064 003EC064 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 2EC068 003EC068 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EC06C 003EC06C 00108244 */  mtc1       $2, $f2
    /* 2EC070 003EC070 06B30046 */  mov.s      $f12, $f22
    /* 2EC074 003EC074 02100046 */  mul.s      $f0, $f2, $f0
    /* 2EC078 003EC078 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2EC07C 003EC07C 00088244 */  mtc1       $2, $f1
    /* 2EC080 003EC080 46AB0046 */  mov.s      $f13, $f21
    /* 2EC084 003EC084 00080046 */  add.s      $f0, $f1, $f0
    /* 2EC088 003EC088 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EC08C 003EC08C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EC090 003EC090 21104300 */  addu       $2, $2, $3
    /* 2EC094 003EC094 21100202 */  addu       $2, $16, $2
    /* 2EC098 003EC098 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2EC09C 003EC09C 00000344 */  mfc1       $3, $f0
    /* 2EC0A0 003EC0A0 602E110C */  jal        func_0044b980
    /* 2EC0A4 003EC0A4 0C0043A0 */   sb        $3, 0xC($2)
    /* 2EC0A8 003EC0A8 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 2EC0AC 003EC0AC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2EC0B0 003EC0B0 00108344 */  mtc1       $3, $f2
    /* 2EC0B4 003EC0B4 00088244 */  mtc1       $2, $f1
    /* 2EC0B8 003EC0B8 00000000 */  nop
    /* 2EC0BC 003EC0BC 02100046 */  mul.s      $f0, $f2, $f0
    /* 2EC0C0 003EC0C0 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EC0C4 003EC0C4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EC0C8 003EC0C8 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EC0CC 003EC0CC 00080046 */  add.s      $f0, $f1, $f0
    /* 2EC0D0 003EC0D0 21104300 */  addu       $2, $2, $3
    /* 2EC0D4 003EC0D4 21180202 */  addu       $3, $16, $2
    /* 2EC0D8 003EC0D8 01001026 */  addiu      $16, $16, 0x1
    /* 2EC0DC 003EC0DC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2EC0E0 003EC0E0 0001022A */  slti       $2, $16, 0x100
    /* 2EC0E4 003EC0E4 00000444 */  mfc1       $4, $f0
    /* 2EC0E8 003EC0E8 D3FF4014 */  bnez       $2, .L003EC038
    /* 2EC0EC 003EC0EC 0C0164A0 */   sb        $4, 0x10C($3)
    /* 2EC0F0 003EC0F0 2000BFDF */  ld         $31, 0x20($29)
    /* 2EC0F4 003EC0F4 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 2EC0F8 003EC0F8 1000B07B */  lq         $16, 0x10($29)
    /* 2EC0FC 003EC0FC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 2EC100 003EC100 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2EC104 003EC104 01000224 */  addiu      $2, $0, 0x1
    /* 2EC108 003EC108 0800E003 */  jr         $31
    /* 2EC10C 003EC10C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003ebff0, 0x120
