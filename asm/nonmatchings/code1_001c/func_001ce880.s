.section .text
.set noat
.set noreorder
glabel func_001ce880
    /* CE880 001CE880 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CE884 001CE884 0000BFFF */  sd         $31, 0x0($29)
    /* CE888 001CE888 8CC1023C */  lui        $2, (0xC18C0000 >> 16)
    /* CE88C 001CE88C 00608244 */  mtc1       $2, $f12
    /* CE890 001CE890 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CE894 001CE894 00688244 */  mtc1       $2, $f13
    /* CE898 001CE898 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CE89C 001CE89C 00708244 */  mtc1       $2, $f14
    /* CE8A0 001CE8A0 8839070C */  jal        func_001ce620
    /* CE8A4 001CE8A4 00000000 */   nop
    /* CE8A8 001CE8A8 0000BFDF */  ld         $31, 0x0($29)
    /* CE8AC 001CE8AC 1000BD27 */  addiu      $29, $29, 0x10
    /* CE8B0 001CE8B0 0800E003 */  jr         $31
    /* CE8B4 001CE8B4 00000000 */   nop
    /* CE8B8 001CE8B8 00000000 */  nop
    /* CE8BC 001CE8BC 00000000 */  nop
.size func_001ce880, 0x40
