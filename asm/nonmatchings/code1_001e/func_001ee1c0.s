.section .text
.set noat
.set noreorder
glabel func_001ee1c0
    /* EE1C0 001EE1C0 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE1C4 001EE1C4 180360AC */  sw         $0, 0x318($3)
    /* EE1C8 001EE1C8 80BF043C */  lui        $4, (0xBF800000 >> 16)
    /* EE1CC 001EE1CC ACB3838F */  lw         $3, -0x4C54($28)
    /* EE1D0 001EE1D0 F00764AC */  sw         $4, 0x7F0($3)
    /* EE1D4 001EE1D4 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE1D8 001EE1D8 200964AC */  sw         $4, 0x920($3)
    /* EE1DC 001EE1DC 2AF90324 */  addiu      $3, $0, -0x6D6
    /* EE1E0 001EE1E0 00008344 */  mtc1       $3, $f0
    /* EE1E4 001EE1E4 00000000 */  nop
    /* EE1E8 001EE1E8 60008046 */  cvt.s.w    $f1, $f0
    /* EE1EC 001EE1EC ACB3838F */  lw         $3, -0x4C54($28)
    /* EE1F0 001EE1F0 1C0361E4 */  swc1       $f1, 0x31C($3)
    /* EE1F4 001EE1F4 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE1F8 001EE1F8 200361E4 */  swc1       $f1, 0x320($3)
    /* EE1FC 001EE1FC ACB3838F */  lw         $3, -0x4C54($28)
    /* EE200 001EE200 4C0461E4 */  swc1       $f1, 0x44C($3)
    /* EE204 001EE204 D6060324 */  addiu      $3, $0, 0x6D6
    /* EE208 001EE208 00008344 */  mtc1       $3, $f0
    /* EE20C 001EE20C 00000000 */  nop
    /* EE210 001EE210 20008046 */  cvt.s.w    $f0, $f0
    /* EE214 001EE214 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE218 001EE218 500460E4 */  swc1       $f0, 0x450($3)
    /* EE21C 001EE21C ACB3838F */  lw         $3, -0x4C54($28)
    /* EE220 001EE220 7C0560E4 */  swc1       $f0, 0x57C($3)
    /* EE224 001EE224 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE228 001EE228 800561E4 */  swc1       $f1, 0x580($3)
    /* EE22C 001EE22C ACB3838F */  lw         $3, -0x4C54($28)
    /* EE230 001EE230 AC0660E4 */  swc1       $f0, 0x6AC($3)
    /* EE234 001EE234 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE238 001EE238 B00660E4 */  swc1       $f0, 0x6B0($3)
    /* EE23C 001EE23C 0800E003 */  jr         $31
    /* EE240 001EE240 00000000 */   nop
    /* EE244 001EE244 00000000 */  nop
    /* EE248 001EE248 00000000 */  nop
    /* EE24C 001EE24C 00000000 */  nop
.size func_001ee1c0, 0x90
