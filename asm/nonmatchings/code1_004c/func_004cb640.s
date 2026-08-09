.section .text
.set noat
.set noreorder
glabel func_004cb640
    /* 3CB640 004CB640 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CB644 004CB644 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB648 004CB648 2D888000 */  daddu      $17, $4, $0
    /* 3CB64C 004CB64C 2800B5FF */  sd         $21, 0x28($29)
    /* 3CB650 004CB650 2DA8A000 */  daddu      $21, $5, $0
    /* 3CB654 004CB654 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB658 004CB658 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB65C 004CB65C 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB660 004CB660 2000B4FF */  sd         $20, 0x20($29)
    /* 3CB664 004CB664 26002012 */  beqz       $17, .L004CB700
    /* 3CB668 004CB668 3000BFFF */   sd        $31, 0x30($29)
    /* 3CB66C 004CB66C 7200023C */  lui        $2, %hi(D_007199A0)
    /* 3CB670 004CB670 7200103C */  lui        $16, %hi(D_007199D4)
    /* 3CB674 004CB674 A099458C */  lw         $5, %lo(D_007199A0)($2)
    /* 3CB678 004CB678 01000224 */  addiu      $2, $0, 0x1
    /* 3CB67C 004CB67C D4991026 */  addiu      $16, $16, %lo(D_007199D4)
    /* 3CB680 004CB680 EB0B123C */  lui        $18, (0xBEBC1FF >> 16)
    /* 3CB684 004CB684 000002AE */  sw         $2, 0x0($16)
    /* 3CB688 004CB688 2D980002 */  daddu      $19, $16, $0
    /* 3CB68C 004CB68C FFC15236 */  ori        $18, $18, (0xBEBC1FF & 0xFFFF)
    /* 3CB690 004CB690 9C85100C */  jal        func_00421670
    /* 3CB694 004CB694 7600143C */   lui       $20, %hi(D_00758910)
    /* 3CB698 004CB698 2D800000 */  daddu      $16, $0, $0
    /* 3CB69C 004CB69C 00000000 */  nop
  .L004CB6A0:
    /* 3CB6A0 004CB6A0 362F130C */  jal        func_004cbcd8
    /* 3CB6A4 004CB6A4 2D202002 */   daddu     $4, $17, $0
    /* 3CB6A8 004CB6A8 502F130C */  jal        func_004cbd40
    /* 3CB6AC 004CB6AC 2D202002 */   daddu     $4, $17, $0
    /* 3CB6B0 004CB6B0 2A185002 */  slt        $3, $18, $16
    /* 3CB6B4 004CB6B4 0000628E */  lw         $2, 0x0($19)
    /* 3CB6B8 004CB6B8 05004010 */  beqz       $2, .L004CB6D0
    /* 3CB6BC 004CB6BC 01001026 */   addiu     $16, $16, 0x1
    /* 3CB6C0 004CB6C0 F7FF6010 */  beqz       $3, .L004CB6A0
    /* 3CB6C4 004CB6C4 00000000 */   nop
    /* 3CB6C8 004CB6C8 F8C1130C */  jal        func_004f07e0
    /* 3CB6CC 004CB6CC 10898426 */   addiu     $4, $20, %lo(D_00758910)
  .L004CB6D0:
    /* 3CB6D0 004CB6D0 2D202002 */  daddu      $4, $17, $0
    /* 3CB6D4 004CB6D4 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB6D8 004CB6D8 2D28A002 */  daddu      $5, $21, $0
    /* 3CB6DC 004CB6DC 2800B5DF */  ld         $21, 0x28($29)
    /* 3CB6E0 004CB6E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB6E4 004CB6E4 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB6E8 004CB6E8 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB6EC 004CB6EC 2000B4DF */  ld         $20, 0x20($29)
    /* 3CB6F0 004CB6F0 3000BFDF */  ld         $31, 0x30($29)
    /* 3CB6F4 004CB6F4 9C851008 */  j          func_00421670
    /* 3CB6F8 004CB6F8 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CB6FC 004CB6FC 00000000 */  nop
  .L004CB700:
    /* 3CB700 004CB700 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB704 004CB704 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB708 004CB708 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB70C 004CB70C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB710 004CB710 2000B4DF */  ld         $20, 0x20($29)
    /* 3CB714 004CB714 2800B5DF */  ld         $21, 0x28($29)
    /* 3CB718 004CB718 3000BFDF */  ld         $31, 0x30($29)
    /* 3CB71C 004CB71C 0800E003 */  jr         $31
    /* 3CB720 004CB720 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CB724 004CB724 00000000 */  nop
.size func_004cb640, 0xe8
