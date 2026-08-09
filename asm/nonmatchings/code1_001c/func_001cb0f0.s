.section .text
.set noat
.set noreorder
glabel func_001cb0f0
    /* CB0F0 001CB0F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CB0F4 001CB0F4 0000BFFF */  sd         $31, 0x0($29)
    /* CB0F8 001CB0F8 E000858C */  lw         $5, 0xE0($4)
    /* CB0FC 001CB0FC 3000A38C */  lw         $3, 0x30($5)
    /* CB100 001CB100 A2006390 */  lbu        $3, 0xA2($3)
    /* CB104 001CB104 37006014 */  bnez       $3, .L001CB1E4
    /* CB108 001CB108 00000000 */   nop
    /* CB10C 001CB10C 3800A38C */  lw         $3, 0x38($5)
    /* CB110 001CB110 280183AC */  sw         $3, 0x128($4)
    /* CB114 001CB114 ACB3868F */  lw         $6, -0x4C54($28)
    /* CB118 001CB118 0C00C58C */  lw         $5, 0xC($6)
    /* CB11C 001CB11C 2000033C */  lui        $3, (0x200000 >> 16)
    /* CB120 001CB120 2418A300 */  and        $3, $5, $3
    /* CB124 001CB124 19006014 */  bnez       $3, .L001CB18C
    /* CB128 001CB128 00000000 */   nop
    /* CB12C 001CB12C 0E01C594 */  lhu        $5, 0x10E($6)
    /* CB130 001CB130 01000324 */  addiu      $3, $0, 0x1
    /* CB134 001CB134 0D00A310 */  beq        $5, $3, .L001CB16C
    /* CB138 001CB138 00000000 */   nop
    /* CB13C 001CB13C 0300A010 */  beqz       $5, .L001CB14C
    /* CB140 001CB140 00000000 */   nop
    /* CB144 001CB144 27000010 */  b          .L001CB1E4
    /* CB148 001CB148 00000000 */   nop
  .L001CB14C:
    /* CB14C 001CB14C 2042023C */  lui        $2, (0x42200000 >> 16)
    /* CB150 001CB150 00608244 */  mtc1       $2, $f12
    /* CB154 001CB154 0040023C */  lui        $2, (0x40000000 >> 16)
    /* CB158 001CB158 00688244 */  mtc1       $2, $f13
    /* CB15C 001CB15C 6429070C */  jal        func_001ca590
    /* CB160 001CB160 00000000 */   nop
    /* CB164 001CB164 1F000010 */  b          .L001CB1E4
    /* CB168 001CB168 00000000 */   nop
  .L001CB16C:
    /* CB16C 001CB16C C842023C */  lui        $2, (0x42C80000 >> 16)
    /* CB170 001CB170 00608244 */  mtc1       $2, $f12
    /* CB174 001CB174 4040023C */  lui        $2, (0x40400000 >> 16)
    /* CB178 001CB178 00688244 */  mtc1       $2, $f13
    /* CB17C 001CB17C 342B070C */  jal        func_001cacd0
    /* CB180 001CB180 00000000 */   nop
    /* CB184 001CB184 17000010 */  b          .L001CB1E4
    /* CB188 001CB188 00000000 */   nop
  .L001CB18C:
    /* CB18C 001CB18C 0E01C594 */  lhu        $5, 0x10E($6)
    /* CB190 001CB190 01000324 */  addiu      $3, $0, 0x1
    /* CB194 001CB194 0D00A310 */  beq        $5, $3, .L001CB1CC
    /* CB198 001CB198 00000000 */   nop
    /* CB19C 001CB19C 0300A010 */  beqz       $5, .L001CB1AC
    /* CB1A0 001CB1A0 00000000 */   nop
    /* CB1A4 001CB1A4 0F000010 */  b          .L001CB1E4
    /* CB1A8 001CB1A8 00000000 */   nop
  .L001CB1AC:
    /* CB1AC 001CB1AC A041023C */  lui        $2, (0x41A00000 >> 16)
    /* CB1B0 001CB1B0 00608244 */  mtc1       $2, $f12
    /* CB1B4 001CB1B4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* CB1B8 001CB1B8 00688244 */  mtc1       $2, $f13
    /* CB1BC 001CB1BC 6429070C */  jal        func_001ca590
    /* CB1C0 001CB1C0 00000000 */   nop
    /* CB1C4 001CB1C4 07000010 */  b          .L001CB1E4
    /* CB1C8 001CB1C8 00000000 */   nop
  .L001CB1CC:
    /* CB1CC 001CB1CC 4842023C */  lui        $2, (0x42480000 >> 16)
    /* CB1D0 001CB1D0 00608244 */  mtc1       $2, $f12
    /* CB1D4 001CB1D4 4040023C */  lui        $2, (0x40400000 >> 16)
    /* CB1D8 001CB1D8 00688244 */  mtc1       $2, $f13
    /* CB1DC 001CB1DC 342B070C */  jal        func_001cacd0
    /* CB1E0 001CB1E0 00000000 */   nop
  .L001CB1E4:
    /* CB1E4 001CB1E4 0000BFDF */  ld         $31, 0x0($29)
    /* CB1E8 001CB1E8 1000BD27 */  addiu      $29, $29, 0x10
    /* CB1EC 001CB1EC 0800E003 */  jr         $31
    /* CB1F0 001CB1F0 00000000 */   nop
    /* CB1F4 001CB1F4 00000000 */  nop
    /* CB1F8 001CB1F8 00000000 */  nop
    /* CB1FC 001CB1FC 00000000 */  nop
.size func_001cb0f0, 0x110
