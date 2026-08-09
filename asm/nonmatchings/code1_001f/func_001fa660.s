.section .text
.set noat
.set noreorder
glabel func_001fa660
    /* FA660 001FA660 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA664 001FA664 0000BFFF */  sd         $31, 0x0($29)
    /* FA668 001FA668 ACB3848F */  lw         $4, -0x4C54($28)
    /* FA66C 001FA66C 7C0B8394 */  lhu        $3, 0xB7C($4)
    /* FA670 001FA670 05000224 */  addiu      $2, $0, 0x5
    /* FA674 001FA674 06006214 */  bne        $3, $2, .L001FA690
    /* FA678 001FA678 00000000 */   nop
    /* FA67C 001FA67C 880B848C */  lw         $4, 0xB88($4)
    /* FA680 001FA680 B883040C */  jal        func_00120ee0
    /* FA684 001FA684 00000000 */   nop
    /* FA688 001FA688 21000010 */  b          .L001FA710
    /* FA68C 001FA68C 00000000 */   nop
  .L001FA690:
    /* FA690 001FA690 840B848C */  lw         $4, 0xB84($4)
    /* FA694 001FA694 F054110C */  jal        func_004553c0
    /* FA698 001FA698 00000000 */   nop
    /* FA69C 001FA69C 1B004010 */  beqz       $2, .L001FA70C
    /* FA6A0 001FA6A0 00000000 */   nop
    /* FA6A4 001FA6A4 ACB3858F */  lw         $5, -0x4C54($28)
    /* FA6A8 001FA6A8 4C0BA424 */  addiu      $4, $5, 0xB4C
    /* FA6AC 001FA6AC 4C0BA38C */  lw         $3, 0xB4C($5)
    /* FA6B0 001FA6B0 02006230 */  andi       $2, $3, 0x2
    /* FA6B4 001FA6B4 09004014 */  bnez       $2, .L001FA6DC
    /* FA6B8 001FA6B8 00000000 */   nop
    /* FA6BC 001FA6BC 840BA28C */  lw         $2, 0xB84($5)
    /* FA6C0 001FA6C0 1001448C */  lw         $4, 0x110($2)
    /* FA6C4 001FA6C4 EC12120C */  jal        func_00484bb0
    /* FA6C8 001FA6C8 00000000 */   nop
    /* FA6CC 001FA6CC ACB3838F */  lw         $3, -0x4C54($28)
    /* FA6D0 001FA6D0 800B62AC */  sw         $2, 0xB80($3)
    /* FA6D4 001FA6D4 04000010 */  b          .L001FA6E8
    /* FA6D8 001FA6D8 00000000 */   nop
  .L001FA6DC:
    /* FA6DC 001FA6DC FDFF0224 */  addiu      $2, $0, -0x3
    /* FA6E0 001FA6E0 24106200 */  and        $2, $3, $2
    /* FA6E4 001FA6E4 000082AC */  sw         $2, 0x0($4)
  .L001FA6E8:
    /* FA6E8 001FA6E8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA6EC 001FA6EC 840B448C */  lw         $4, 0xB84($2)
    /* FA6F0 001FA6F0 F452110C */  jal        func_00454bd0
    /* FA6F4 001FA6F4 00000000 */   nop
    /* FA6F8 001FA6F8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA6FC 001FA6FC 840B40AC */  sw         $0, 0xB84($2)
    /* FA700 001FA700 01000224 */  addiu      $2, $0, 0x1
    /* FA704 001FA704 02000010 */  b          .L001FA710
    /* FA708 001FA708 00000000 */   nop
  .L001FA70C:
    /* FA70C 001FA70C 2D100000 */  daddu      $2, $0, $0
  .L001FA710:
    /* FA710 001FA710 0000BFDF */  ld         $31, 0x0($29)
    /* FA714 001FA714 1000BD27 */  addiu      $29, $29, 0x10
    /* FA718 001FA718 0800E003 */  jr         $31
    /* FA71C 001FA71C 00000000 */   nop
.size func_001fa660, 0xc0
