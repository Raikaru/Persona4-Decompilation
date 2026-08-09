.section .text
.set noat
.set noreorder
glabel func_003cc720
    /* 2CC720 003CC720 70FFBD27 */  addiu      $29, $29, -0x90
    /* 2CC724 003CC724 8000BE7F */  sq         $30, 0x80($29)
    /* 2CC728 003CC728 7000B77F */  sq         $23, 0x70($29)
    /* 2CC72C 003CC72C 6000B67F */  sq         $22, 0x60($29)
    /* 2CC730 003CC730 5000B57F */  sq         $21, 0x50($29)
    /* 2CC734 003CC734 4000B47F */  sq         $20, 0x40($29)
    /* 2CC738 003CC738 3000B37F */  sq         $19, 0x30($29)
    /* 2CC73C 003CC73C 2000B27F */  sq         $18, 0x20($29)
    /* 2CC740 003CC740 1000B17F */  sq         $17, 0x10($29)
    /* 2CC744 003CC744 0000B07F */  sq         $16, 0x0($29)
    /* 2CC748 003CC748 B000838C */  lw         $3, 0xB0($4)
    /* 2CC74C 003CC74C 01006230 */  andi       $2, $3, 0x1
    /* 2CC750 003CC750 74014014 */  bnez       $2, .L003CCD24
    /* 2CC754 003CC754 00000000 */   nop
    /* 2CC758 003CC758 FF006230 */  andi       $2, $3, 0xFF
    /* 2CC75C 003CC75C 71014010 */  beqz       $2, .L003CCD24
    /* 2CC760 003CC760 00000000 */   nop
    /* 2CC764 003CC764 0C006230 */  andi       $2, $3, 0xC
    /* 2CC768 003CC768 08004010 */  beqz       $2, .L003CC78C
    /* 2CC76C 003CC76C 00000000 */   nop
    /* 2CC770 003CC770 04000324 */  addiu      $3, $0, 0x4
    /* 2CC774 003CC774 01000224 */  addiu      $2, $0, 0x1
    /* 2CC778 003CC778 F00183A0 */  sb         $3, 0x1F0($4)
    /* 2CC77C 003CC77C F10180A0 */  sb         $0, 0x1F1($4)
    /* 2CC780 003CC780 B80083A0 */  sb         $3, 0xB8($4)
    /* 2CC784 003CC784 06000010 */  b          .L003CC7A0
    /* 2CC788 003CC788 B90082A0 */   sb        $2, 0xB9($4)
  .L003CC78C:
    /* 2CC78C 003CC78C 04000224 */  addiu      $2, $0, 0x4
    /* 2CC790 003CC790 F00182A0 */  sb         $2, 0x1F0($4)
    /* 2CC794 003CC794 F10180A0 */  sb         $0, 0x1F1($4)
    /* 2CC798 003CC798 B80082A0 */  sb         $2, 0xB8($4)
    /* 2CC79C 003CC79C B90080A0 */  sb         $0, 0xB9($4)
  .L003CC7A0:
    /* 2CC7A0 003CC7A0 0068033C */  lui        $3, (0x68002001 >> 16)
    /* 2CC7A4 003CC7A4 006E023C */  lui        $2, (0x6E002001 >> 16)
    /* 2CC7A8 003CC7A8 01206334 */  ori        $3, $3, (0x68002001 & 0xFFFF)
    /* 2CC7AC 003CC7AC 01204234 */  ori        $2, $2, (0x6E002001 & 0xFFFF)
    /* 2CC7B0 003CC7B0 700083AC */  sw         $3, 0x70($4)
    /* 2CC7B4 003CC7B4 2D480000 */  daddu      $9, $0, $0
    /* 2CC7B8 003CC7B8 01000324 */  addiu      $3, $0, 0x1
    /* 2CC7BC 003CC7BC 780082AC */  sw         $2, 0x78($4)
    /* 2CC7C0 003CC7C0 2D400000 */  daddu      $8, $0, $0
    /* 2CC7C4 003CC7C4 2D388000 */  daddu      $7, $4, $0
  .L003CC7C8:
    /* 2CC7C8 003CC7C8 2000E68C */  lw         $6, 0x20($7)
    /* 2CC7CC 003CC7CC 0100C530 */  andi       $5, $6, 0x1
    /* 2CC7D0 003CC7D0 5C01A010 */  beqz       $5, .L003CCD44
    /* 2CC7D4 003CC7D4 00000000 */   nop
  .L003CC7D8:
    /* 2CC7D8 003CC7D8 0500A010 */  beqz       $5, .L003CC7F0
    /* 2CC7DC 003CC7DC 00000000 */   nop
    /* 2CC7E0 003CC7E0 0020C230 */  andi       $2, $6, 0x2000
    /* 2CC7E4 003CC7E4 02004014 */  bnez       $2, .L003CC7F0
    /* 2CC7E8 003CC7E8 00000000 */   nop
    /* 2CC7EC 003CC7EC 2D180000 */  daddu      $3, $0, $0
  .L003CC7F0:
    /* 2CC7F0 003CC7F0 01002225 */  addiu      $2, $9, 0x1
    /* 2CC7F4 003CC7F4 FF004930 */  andi       $9, $2, 0xFF
  .L003CC7F8:
    /* 2CC7F8 003CC7F8 01000825 */  addiu      $8, $8, 0x1
    /* 2CC7FC 003CC7FC 0A00022D */  sltiu      $2, $8, 0xA
    /* 2CC800 003CC800 F1FF4014 */  bnez       $2, .L003CC7C8
    /* 2CC804 003CC804 0800E724 */   addiu     $7, $7, 0x8
    /* 2CC808 003CC808 B40083A0 */  sb         $3, 0xB4($4)
    /* 2CC80C 003CC80C FF003831 */  andi       $24, $9, 0xFF
    /* 2CC810 003CC810 B6008290 */  lbu        $2, 0xB6($4)
    /* 2CC814 003CC814 50010217 */  bne        $24, $2, .L003CCD58
    /* 2CC818 003CC818 00000000 */   nop
    /* 2CC81C 003CC81C 01000224 */  addiu      $2, $0, 0x1
    /* 2CC820 003CC820 75000C3C */  lui        $12, %hi(jtbl_00752E30)
    /* 2CC824 003CC824 7500083C */  lui        $8, %hi(jtbl_00752DE0)
    /* 2CC828 003CC828 75000A3C */  lui        $10, %hi(jtbl_00752E00)
    /* 2CC82C 003CC82C 7500063C */  lui        $6, %hi(jtbl_00752DB0)
    /* 2CC830 003CC830 F0018524 */  addiu      $5, $4, 0x1F0
    /* 2CC834 003CC834 02000F27 */  addiu      $15, $24, 0x2
    /* 2CC838 003CC838 302E8C25 */  addiu      $12, $12, %lo(jtbl_00752E30)
    /* 2CC83C 003CC83C E02D0825 */  addiu      $8, $8, %lo(jtbl_00752DE0)
    /* 2CC840 003CC840 002E4A25 */  addiu      $10, $10, %lo(jtbl_00752E00)
    /* 2CC844 003CC844 B02DC624 */  addiu      $6, $6, %lo(jtbl_00752DB0)
    /* 2CC848 003CC848 2D704000 */  daddu      $14, $2, $0
    /* 2CC84C 003CC84C FFFF1734 */  ori        $23, $0, 0xFFFF
    /* 2CC850 003CC850 2D684000 */  daddu      $13, $2, $0
    /* 2CC854 003CC854 02001E24 */  addiu      $30, $0, 0x2
    /* 2CC858 003CC858 2D584000 */  daddu      $11, $2, $0
    /* 2CC85C 003CC85C B8008924 */  addiu      $9, $4, 0xB8
  .L003CC860:
    /* 2CC860 003CC860 3D006010 */  beqz       $3, .L003CC958
    /* 2CC864 003CC864 00000000 */   nop
    /* 2CC868 003CC868 0400A78C */  lw         $7, 0x4($5)
    /* 2CC86C 003CC86C 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC870 003CC870 1B00F800 */  divu       $0, $7, $24
    /* 2CC874 003CC874 12380000 */  mflo       $7
    /* 2CC878 003CC878 1B00F000 */  divu       $0, $7, $16
    /* 2CC87C 003CC87C 12380000 */  mflo       $7
    /* 2CC880 003CC880 18380702 */  mult       $7, $16, $7
    /* 2CC884 003CC884 0800A7AC */  sw         $7, 0x8($5)
    /* 2CC888 003CC888 0800A78C */  lw         $7, 0x8($5)
    /* 2CC88C 003CC88C 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC890 003CC890 2A80F000 */  slt        $16, $7, $16
    /* 2CC894 003CC894 32010016 */  bnez       $16, .L003CCD60
    /* 2CC898 003CC898 00000000 */   nop
    /* 2CC89C 003CC89C 80880700 */  sll        $17, $7, 2
    /* 2CC8A0 003CC8A0 0300F024 */  addiu      $16, $7, 0x3
    /* 2CC8A4 003CC8A4 03003226 */  addiu      $18, $17, 0x3
    /* 2CC8A8 003CC8A8 83881000 */  sra        $17, $16, 2
    /* 2CC8AC 003CC8AC 83901200 */  sra        $18, $18, 2
    /* 2CC8B0 003CC8B0 40800700 */  sll        $16, $7, 1
    /* 2CC8B4 003CC8B4 21380702 */  addu       $7, $16, $7
    /* 2CC8B8 003CC8B8 40801200 */  sll        $16, $18, 1
    /* 2CC8BC 003CC8BC 0F00E724 */  addiu      $7, $7, 0xF
    /* 2CC8C0 003CC8C0 05001026 */  addiu      $16, $16, 0x5
    /* 2CC8C4 003CC8C4 03390700 */  sra        $7, $7, 4
    /* 2CC8C8 003CC8C8 21801102 */  addu       $16, $16, $17
    /* 2CC8CC 003CC8CC 21380702 */  addu       $7, $16, $7
    /* 2CC8D0 003CC8D0 1A00E702 */  div        $0, $23, $7
    /* 2CC8D4 003CC8D4 12380000 */  mflo       $7
    /* 2CC8D8 003CC8D8 0C00A7AC */  sw         $7, 0xC($5)
    /* 2CC8DC 003CC8DC 0400A78C */  lw         $7, 0x4($5)
    /* 2CC8E0 003CC8E0 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC8E4 003CC8E4 1B00EF00 */  divu       $0, $7, $15
    /* 2CC8E8 003CC8E8 12380000 */  mflo       $7
    /* 2CC8EC 003CC8EC 1B00F000 */  divu       $0, $7, $16
    /* 2CC8F0 003CC8F0 12380000 */  mflo       $7
    /* 2CC8F4 003CC8F4 18380772 */  mult1      $7, $16, $7
    /* 2CC8F8 003CC8F8 1000A7AC */  sw         $7, 0x10($5)
    /* 2CC8FC 003CC8FC 1000A78C */  lw         $7, 0x10($5)
    /* 2CC900 003CC900 80880700 */  sll        $17, $7, 2
    /* 2CC904 003CC904 40800700 */  sll        $16, $7, 1
    /* 2CC908 003CC908 03003126 */  addiu      $17, $17, 0x3
    /* 2CC90C 003CC90C 21800702 */  addu       $16, $16, $7
    /* 2CC910 003CC910 83901100 */  sra        $18, $17, 2
    /* 2CC914 003CC914 0F001026 */  addiu      $16, $16, 0xF
    /* 2CC918 003CC918 03891000 */  sra        $17, $16, 4
    /* 2CC91C 003CC91C 21905102 */  addu       $18, $18, $17
    /* 2CC920 003CC920 0300F024 */  addiu      $16, $7, 0x3
    /* 2CC924 003CC924 83881000 */  sra        $17, $16, 2
    /* 2CC928 003CC928 40901200 */  sll        $18, $18, 1
    /* 2CC92C 003CC92C 0100F024 */  addiu      $16, $7, 0x1
    /* 2CC930 003CC930 07005226 */  addiu      $18, $18, 0x7
    /* 2CC934 003CC934 40381000 */  sll        $7, $16, 1
    /* 2CC938 003CC938 21885102 */  addu       $17, $18, $17
    /* 2CC93C 003CC93C 2138F000 */  addu       $7, $7, $16
    /* 2CC940 003CC940 83380700 */  sra        $7, $7, 2
    /* 2CC944 003CC944 21382702 */  addu       $7, $17, $7
    /* 2CC948 003CC948 1A00E702 */  div        $0, $23, $7
    /* 2CC94C 003CC94C 12380000 */  mflo       $7
    /* 2CC950 003CC950 29000010 */  b          .L003CC9F8
    /* 2CC954 003CC954 1400A7AC */   sw        $7, 0x14($5)
  .L003CC958:
    /* 2CC958 003CC958 0400A78C */  lw         $7, 0x4($5)
    /* 2CC95C 003CC95C 1B00F800 */  divu       $0, $7, $24
    /* 2CC960 003CC960 0100A790 */  lbu        $7, 0x1($5)
    /* 2CC964 003CC964 00000000 */  nop
    /* 2CC968 003CC968 12800000 */  mflo       $16
    /* 2CC96C 003CC96C 23380702 */  subu       $7, $16, $7
    /* 2CC970 003CC970 0800A7AC */  sw         $7, 0x8($5)
    /* 2CC974 003CC974 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC978 003CC978 0800A78C */  lw         $7, 0x8($5)
    /* 2CC97C 003CC97C 1A00F000 */  div        $0, $7, $16
    /* 2CC980 003CC980 12380000 */  mflo       $7
    /* 2CC984 003CC984 18800702 */  mult       $16, $16, $7
    /* 2CC988 003CC988 0100A790 */  lbu        $7, 0x1($5)
    /* 2CC98C 003CC98C 2138F000 */  addu       $7, $7, $16
    /* 2CC990 003CC990 0800A7AC */  sw         $7, 0x8($5)
    /* 2CC994 003CC994 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC998 003CC998 0100A790 */  lbu        $7, 0x1($5)
    /* 2CC99C 003CC99C 0800B18C */  lw         $17, 0x8($5)
    /* 2CC9A0 003CC9A0 21380702 */  addu       $7, $16, $7
    /* 2CC9A4 003CC9A4 2A382702 */  slt        $7, $17, $7
    /* 2CC9A8 003CC9A8 EF00E014 */  bnez       $7, .L003CCD68
    /* 2CC9AC 003CC9AC 00000000 */   nop
    /* 2CC9B0 003CC9B0 0C00AEAC */  sw         $14, 0xC($5)
    /* 2CC9B4 003CC9B4 0400A78C */  lw         $7, 0x4($5)
    /* 2CC9B8 003CC9B8 1B00EF00 */  divu       $0, $7, $15
    /* 2CC9BC 003CC9BC 0100A790 */  lbu        $7, 0x1($5)
    /* 2CC9C0 003CC9C0 00000000 */  nop
    /* 2CC9C4 003CC9C4 12800000 */  mflo       $16
    /* 2CC9C8 003CC9C8 23380702 */  subu       $7, $16, $7
    /* 2CC9CC 003CC9CC 1000A7AC */  sw         $7, 0x10($5)
    /* 2CC9D0 003CC9D0 0000B090 */  lbu        $16, 0x0($5)
    /* 2CC9D4 003CC9D4 1000A78C */  lw         $7, 0x10($5)
    /* 2CC9D8 003CC9D8 1A00F000 */  div        $0, $7, $16
    /* 2CC9DC 003CC9DC 12380000 */  mflo       $7
    /* 2CC9E0 003CC9E0 18800702 */  mult       $16, $16, $7
    /* 2CC9E4 003CC9E4 0100A790 */  lbu        $7, 0x1($5)
    /* 2CC9E8 003CC9E8 2138F000 */  addu       $7, $7, $16
    /* 2CC9EC 003CC9EC 1000A7AC */  sw         $7, 0x10($5)
    /* 2CC9F0 003CC9F0 1400AEAC */  sw         $14, 0x14($5)
    /* 2CC9F4 003CC9F4 00000000 */  nop
  .L003CC9F8:
    /* 2CC9F8 003CC9F8 03006010 */  beqz       $3, .L003CCA08
    /* 2CC9FC 003CC9FC 2DA8C003 */   daddu     $21, $30, $0
    /* 2CCA00 003CCA00 2DA8A001 */  daddu      $21, $13, $0
    /* 2CCA04 003CCA04 00000000 */  nop
  .L003CCA08:
    /* 2CCA08 003CCA08 2D380000 */  daddu      $7, $0, $0
    /* 2CCA0C 003CCA0C 2D808000 */  daddu      $16, $4, $0
  .L003CCA10:
    /* 2CCA10 003CCA10 2000128E */  lw         $18, 0x20($16)
    /* 2CCA14 003CCA14 01005132 */  andi       $17, $18, 0x1
    /* 2CCA18 003CCA18 33002012 */  beqz       $17, .L003CCAE8
    /* 2CCA1C 003CCA1C 00000000 */   nop
    /* 2CCA20 003CCA20 00205132 */  andi       $17, $18, 0x2000
    /* 2CCA24 003CCA24 2E002012 */  beqz       $17, .L003CCAE0
    /* 2CCA28 003CCA28 00000000 */   nop
    /* 2CCA2C 003CCA2C 0600E12C */  sltiu      $1, $7, 0x6
    /* 2CCA30 003CCA30 29002010 */  beqz       $1, .L003CCAD8
    /* 2CCA34 003CCA34 00000000 */   nop
    /* 2CCA38 003CCA38 80880700 */  sll        $17, $7, 2
    /* 2CCA3C 003CCA3C 21882C02 */  addu       $17, $17, $12
    /* 2CCA40 003CCA40 0000318E */  lw         $17, 0x0($17)
    /* 2CCA44 003CCA44 08002002 */  jr         $17
    /* 2CCA48 003CCA48 00000000 */   nop
    /* 2CCA4C 003CCA4C 00000000 */  nop
    /* 2CCA50 003CCA50 0800B18C */  lw         $17, 0x8($5)
    /* 2CCA54 003CCA54 01003226 */  addiu      $18, $17, 0x1
    /* 2CCA58 003CCA58 40881200 */  sll        $17, $18, 1
    /* 2CCA5C 003CCA5C 21883202 */  addu       $17, $17, $18
    /* 2CCA60 003CCA60 83881100 */  sra        $17, $17, 2
    /* 2CCA64 003CCA64 1C000010 */  b          .L003CCAD8
    /* 2CCA68 003CCA68 21A8B102 */   addu      $21, $21, $17
    /* 2CCA6C 003CCA6C 00000000 */  nop
    /* 2CCA70 003CCA70 0800B18C */  lw         $17, 0x8($5)
    /* 2CCA74 003CCA74 18000010 */  b          .L003CCAD8
    /* 2CCA78 003CCA78 21A8B102 */   addu      $21, $21, $17
    /* 2CCA7C 003CCA7C 00000000 */  nop
    /* 2CCA80 003CCA80 0800B18C */  lw         $17, 0x8($5)
    /* 2CCA84 003CCA84 40881100 */  sll        $17, $17, 1
    /* 2CCA88 003CCA88 03003126 */  addiu      $17, $17, 0x3
    /* 2CCA8C 003CCA8C 83881100 */  sra        $17, $17, 2
    /* 2CCA90 003CCA90 11000010 */  b          .L003CCAD8
    /* 2CCA94 003CCA94 21A8B102 */   addu      $21, $21, $17
    /* 2CCA98 003CCA98 0800B18C */  lw         $17, 0x8($5)
    /* 2CCA9C 003CCA9C 0E000010 */  b          .L003CCAD8
    /* 2CCAA0 003CCAA0 21A8B102 */   addu      $21, $21, $17
    /* 2CCAA4 003CCAA4 00000000 */  nop
    /* 2CCAA8 003CCAA8 0800B18C */  lw         $17, 0x8($5)
    /* 2CCAAC 003CCAAC 03003126 */  addiu      $17, $17, 0x3
    /* 2CCAB0 003CCAB0 83881100 */  sra        $17, $17, 2
    /* 2CCAB4 003CCAB4 08000010 */  b          .L003CCAD8
    /* 2CCAB8 003CCAB8 21A8B102 */   addu      $21, $21, $17
    /* 2CCABC 003CCABC 00000000 */  nop
    /* 2CCAC0 003CCAC0 0800B28C */  lw         $18, 0x8($5)
    /* 2CCAC4 003CCAC4 40881200 */  sll        $17, $18, 1
    /* 2CCAC8 003CCAC8 21883202 */  addu       $17, $17, $18
    /* 2CCACC 003CCACC 0F003126 */  addiu      $17, $17, 0xF
    /* 2CCAD0 003CCAD0 03891100 */  sra        $17, $17, 4
    /* 2CCAD4 003CCAD4 21A8B102 */  addu       $21, $21, $17
  .L003CCAD8:
    /* 2CCAD8 003CCAD8 03000010 */  b          .L003CCAE8
    /* 2CCADC 003CCADC 0100B526 */   addiu     $21, $21, 0x1
  .L003CCAE0:
    /* 2CCAE0 003CCAE0 0200B526 */  addiu      $21, $21, 0x2
    /* 2CCAE4 003CCAE4 00000000 */  nop
  .L003CCAE8:
    /* 2CCAE8 003CCAE8 0100E724 */  addiu      $7, $7, 0x1
    /* 2CCAEC 003CCAEC 0A00F12C */  sltiu      $17, $7, 0xA
    /* 2CCAF0 003CCAF0 C7FF2016 */  bnez       $17, .L003CCA10
    /* 2CCAF4 003CCAF4 08001026 */   addiu     $16, $16, 0x8
    /* 2CCAF8 003CCAF8 B5008790 */  lbu        $7, 0xB5($4)
    /* 2CCAFC 003CCAFC 2D980000 */  daddu      $19, $0, $0
    /* 2CCB00 003CCB00 2DC80000 */  daddu      $25, $0, $0
    /* 2CCB04 003CCB04 2D800000 */  daddu      $16, $0, $0
    /* 2CCB08 003CCB08 2D908000 */  daddu      $18, $4, $0
    /* 2CCB0C 003CCB0C 2D88A000 */  daddu      $17, $5, $0
    /* 2CCB10 003CCB10 40380700 */  sll        $7, $7, 1
    /* 2CCB14 003CCB14 0100F424 */  addiu      $20, $7, 0x1
  .L003CCB18:
    /* 2CCB18 003CCB18 2000568E */  lw         $22, 0x20($18)
    /* 2CCB1C 003CCB1C 0100C732 */  andi       $7, $22, 0x1
    /* 2CCB20 003CCB20 9300E014 */  bnez       $7, .L003CCD70
    /* 2CCB24 003CCB24 00000000 */   nop
    /* 2CCB28 003CCB28 1000C732 */  andi       $7, $22, 0x10
    /* 2CCB2C 003CCB2C 0800E010 */  beqz       $7, .L003CCB50
    /* 2CCB30 003CCB30 00000000 */   nop
    /* 2CCB34 003CCB34 2E0039A2 */  sb         $25, 0x2E($17)
    /* 2CCB38 003CCB38 01002727 */  addiu      $7, $25, 0x1
    /* 2CCB3C 003CCB3C 180020AE */  sw         $0, 0x18($17)
    /* 2CCB40 003CCB40 FF00F930 */  andi       $25, $7, 0xFF
    /* 2CCB44 003CCB44 200020AE */  sw         $0, 0x20($17)
    /* 2CCB48 003CCB48 280020A6 */  sh         $0, 0x28($17)
    /* 2CCB4C 003CCB4C 2C0020A6 */  sh         $0, 0x2C($17)
  .L003CCB50:
    /* 2CCB50 003CCB50 01001026 */  addiu      $16, $16, 0x1
    /* 2CCB54 003CCB54 0A00072E */  sltiu      $7, $16, 0xA
    /* 2CCB58 003CCB58 08005226 */  addiu      $18, $18, 0x8
    /* 2CCB5C 003CCB5C EEFFE014 */  bnez       $7, .L003CCB18
    /* 2CCB60 003CCB60 18003126 */   addiu     $17, $17, 0x18
    /* 2CCB64 003CCB64 02006010 */  beqz       $3, .L003CCB70
    /* 2CCB68 003CCB68 2D90C003 */   daddu     $18, $30, $0
    /* 2CCB6C 003CCB6C 2D906001 */  daddu      $18, $11, $0
  .L003CCB70:
    /* 2CCB70 003CCB70 2D380000 */  daddu      $7, $0, $0
    /* 2CCB74 003CCB74 2D808000 */  daddu      $16, $4, $0
  .L003CCB78:
    /* 2CCB78 003CCB78 2000138E */  lw         $19, 0x20($16)
    /* 2CCB7C 003CCB7C 01007132 */  andi       $17, $19, 0x1
    /* 2CCB80 003CCB80 43002012 */  beqz       $17, .L003CCC90
    /* 2CCB84 003CCB84 00000000 */   nop
    /* 2CCB88 003CCB88 00207132 */  andi       $17, $19, 0x2000
    /* 2CCB8C 003CCB8C 3E002012 */  beqz       $17, .L003CCC88
    /* 2CCB90 003CCB90 00000000 */   nop
    /* 2CCB94 003CCB94 0C00E12C */  sltiu      $1, $7, 0xC
    /* 2CCB98 003CCB98 39002010 */  beqz       $1, .L003CCC80
    /* 2CCB9C 003CCB9C 00000000 */   nop
    /* 2CCBA0 003CCBA0 80880700 */  sll        $17, $7, 2
    /* 2CCBA4 003CCBA4 21882A02 */  addu       $17, $17, $10
    /* 2CCBA8 003CCBA8 0000318E */  lw         $17, 0x0($17)
    /* 2CCBAC 003CCBAC 08002002 */  jr         $17
    /* 2CCBB0 003CCBB0 00000000 */   nop
    /* 2CCBB4 003CCBB4 00000000 */  nop
    /* 2CCBB8 003CCBB8 1000B18C */  lw         $17, 0x10($5)
    /* 2CCBBC 003CCBBC 01003326 */  addiu      $19, $17, 0x1
    /* 2CCBC0 003CCBC0 40881300 */  sll        $17, $19, 1
    /* 2CCBC4 003CCBC4 21883302 */  addu       $17, $17, $19
    /* 2CCBC8 003CCBC8 83881100 */  sra        $17, $17, 2
    /* 2CCBCC 003CCBCC 2C000010 */  b          .L003CCC80
    /* 2CCBD0 003CCBD0 21905102 */   addu      $18, $18, $17
    /* 2CCBD4 003CCBD4 00000000 */  nop
    /* 2CCBD8 003CCBD8 1000B18C */  lw         $17, 0x10($5)
    /* 2CCBDC 003CCBDC 28000010 */  b          .L003CCC80
    /* 2CCBE0 003CCBE0 21905102 */   addu      $18, $18, $17
    /* 2CCBE4 003CCBE4 00000000 */  nop
    /* 2CCBE8 003CCBE8 1000B18C */  lw         $17, 0x10($5)
    /* 2CCBEC 003CCBEC 40881100 */  sll        $17, $17, 1
    /* 2CCBF0 003CCBF0 03003126 */  addiu      $17, $17, 0x3
    /* 2CCBF4 003CCBF4 83881100 */  sra        $17, $17, 2
    /* 2CCBF8 003CCBF8 21000010 */  b          .L003CCC80
    /* 2CCBFC 003CCBFC 21905102 */   addu      $18, $18, $17
    /* 2CCC00 003CCC00 1000B18C */  lw         $17, 0x10($5)
    /* 2CCC04 003CCC04 1E000010 */  b          .L003CCC80
    /* 2CCC08 003CCC08 21905102 */   addu      $18, $18, $17
    /* 2CCC0C 003CCC0C 00000000 */  nop
    /* 2CCC10 003CCC10 1000B18C */  lw         $17, 0x10($5)
    /* 2CCC14 003CCC14 03003126 */  addiu      $17, $17, 0x3
    /* 2CCC18 003CCC18 83881100 */  sra        $17, $17, 2
    /* 2CCC1C 003CCC1C 18000010 */  b          .L003CCC80
    /* 2CCC20 003CCC20 21905102 */   addu      $18, $18, $17
    /* 2CCC24 003CCC24 00000000 */  nop
    /* 2CCC28 003CCC28 1000B38C */  lw         $19, 0x10($5)
    /* 2CCC2C 003CCC2C 40881300 */  sll        $17, $19, 1
    /* 2CCC30 003CCC30 21883302 */  addu       $17, $17, $19
    /* 2CCC34 003CCC34 0F003126 */  addiu      $17, $17, 0xF
    /* 2CCC38 003CCC38 03891100 */  sra        $17, $17, 4
    /* 2CCC3C 003CCC3C 10000010 */  b          .L003CCC80
    /* 2CCC40 003CCC40 21905102 */   addu      $18, $18, $17
    /* 2CCC44 003CCC44 00000000 */  nop
    /* 2CCC48 003CCC48 1000B18C */  lw         $17, 0x10($5)
    /* 2CCC4C 003CCC4C 01003326 */  addiu      $19, $17, 0x1
    /* 2CCC50 003CCC50 40881300 */  sll        $17, $19, 1
    /* 2CCC54 003CCC54 21883302 */  addu       $17, $17, $19
    /* 2CCC58 003CCC58 83881100 */  sra        $17, $17, 2
    /* 2CCC5C 003CCC5C 08000010 */  b          .L003CCC80
    /* 2CCC60 003CCC60 21905102 */   addu      $18, $18, $17
    /* 2CCC64 003CCC64 00000000 */  nop
    /* 2CCC68 003CCC68 1000B38C */  lw         $19, 0x10($5)
    /* 2CCC6C 003CCC6C 40881300 */  sll        $17, $19, 1
    /* 2CCC70 003CCC70 21883302 */  addu       $17, $17, $19
    /* 2CCC74 003CCC74 0F003126 */  addiu      $17, $17, 0xF
    /* 2CCC78 003CCC78 03891100 */  sra        $17, $17, 4
    /* 2CCC7C 003CCC7C 21905102 */  addu       $18, $18, $17
  .L003CCC80:
    /* 2CCC80 003CCC80 03000010 */  b          .L003CCC90
    /* 2CCC84 003CCC84 01005226 */   addiu     $18, $18, 0x1
  .L003CCC88:
    /* 2CCC88 003CCC88 02005226 */  addiu      $18, $18, 0x2
    /* 2CCC8C 003CCC8C 00000000 */  nop
  .L003CCC90:
    /* 2CCC90 003CCC90 0100E724 */  addiu      $7, $7, 0x1
    /* 2CCC94 003CCC94 0C00F12C */  sltiu      $17, $7, 0xC
    /* 2CCC98 003CCC98 B7FF2016 */  bnez       $17, .L003CCB78
    /* 2CCC9C 003CCC9C 08001026 */   addiu     $16, $16, 0x8
    /* 2CCCA0 003CCCA0 B5008790 */  lbu        $7, 0xB5($4)
    /* 2CCCA4 003CCCA4 2D800000 */  daddu      $16, $0, $0
    /* 2CCCA8 003CCCA8 2DC80000 */  daddu      $25, $0, $0
    /* 2CCCAC 003CCCAC 2D980000 */  daddu      $19, $0, $0
    /* 2CCCB0 003CCCB0 2DA88000 */  daddu      $21, $4, $0
    /* 2CCCB4 003CCCB4 2DA0A000 */  daddu      $20, $5, $0
    /* 2CCCB8 003CCCB8 40380700 */  sll        $7, $7, 1
    /* 2CCCBC 003CCCBC 0100F124 */  addiu      $17, $7, 0x1
  .L003CCCC0:
    /* 2CCCC0 003CCCC0 2000B68E */  lw         $22, 0x20($21)
    /* 2CCCC4 003CCCC4 0100C732 */  andi       $7, $22, 0x1
    /* 2CCCC8 003CCCC8 5F00E014 */  bnez       $7, .L003CCE48
    /* 2CCCCC 003CCCCC 00000000 */   nop
    /* 2CCCD0 003CCCD0 1000C732 */  andi       $7, $22, 0x10
    /* 2CCCD4 003CCCD4 0800E010 */  beqz       $7, .L003CCCF8
    /* 2CCCD8 003CCCD8 00000000 */   nop
    /* 2CCCDC 003CCCDC 2E0099A2 */  sb         $25, 0x2E($20)
    /* 2CCCE0 003CCCE0 01002727 */  addiu      $7, $25, 0x1
    /* 2CCCE4 003CCCE4 1C0080AE */  sw         $0, 0x1C($20)
    /* 2CCCE8 003CCCE8 FF00F930 */  andi       $25, $7, 0xFF
    /* 2CCCEC 003CCCEC 240080AE */  sw         $0, 0x24($20)
    /* 2CCCF0 003CCCF0 2A0080A6 */  sh         $0, 0x2A($20)
    /* 2CCCF4 003CCCF4 2C0080A6 */  sh         $0, 0x2C($20)
  .L003CCCF8:
    /* 2CCCF8 003CCCF8 01007326 */  addiu      $19, $19, 0x1
    /* 2CCCFC 003CCCFC 0C00672E */  sltiu      $7, $19, 0xC
    /* 2CCD00 003CCD00 0800B526 */  addiu      $21, $21, 0x8
    /* 2CCD04 003CCD04 EEFFE014 */  bnez       $7, .L003CCCC0
    /* 2CCD08 003CCD08 18009426 */   addiu     $20, $20, 0x18
    /* 2CCD0C 003CCD0C 01004224 */  addiu      $2, $2, 0x1
    /* 2CCD10 003CCD10 0300412C */  sltiu      $1, $2, 0x3
    /* 2CCD14 003CCD14 D2FE2014 */  bnez       $1, .L003CC860
    /* 2CCD18 003CCD18 2D282001 */   daddu     $5, $9, $0
    /* 2CCD1C 003CCD1C 8C000010 */  b          .L003CCF50
    /* 2CCD20 003CCD20 01000224 */   addiu     $2, $0, 0x1
  .L003CCD24:
    /* 2CCD24 003CCD24 0C000224 */  addiu      $2, $0, 0xC
    /* 2CCD28 003CCD28 04000324 */  addiu      $3, $0, 0x4
    /* 2CCD2C 003CCD2C F00182A0 */  sb         $2, 0x1F0($4)
    /* 2CCD30 003CCD30 F10180A0 */  sb         $0, 0x1F1($4)
    /* 2CCD34 003CCD34 02000224 */  addiu      $2, $0, 0x2
    /* 2CCD38 003CCD38 B80083A0 */  sb         $3, 0xB8($4)
    /* 2CCD3C 003CCD3C 98FE0010 */  b          .L003CC7A0
    /* 2CCD40 003CCD40 B90082A0 */   sb        $2, 0xB9($4)
  .L003CCD44:
    /* 2CCD44 003CCD44 1000C230 */  andi       $2, $6, 0x10
    /* 2CCD48 003CCD48 ABFE4010 */  beqz       $2, .L003CC7F8
    /* 2CCD4C 003CCD4C 00000000 */   nop
    /* 2CCD50 003CCD50 A1FE0010 */  b          .L003CC7D8
    /* 2CCD54 003CCD54 00000000 */   nop
  .L003CCD58:
    /* 2CCD58 003CCD58 7D000010 */  b          .L003CCF50
    /* 2CCD5C 003CCD5C 2D100000 */   daddu     $2, $0, $0
  .L003CCD60:
    /* 2CCD60 003CCD60 7B000010 */  b          .L003CCF50
    /* 2CCD64 003CCD64 2D100000 */   daddu     $2, $0, $0
  .L003CCD68:
    /* 2CCD68 003CCD68 79000010 */  b          .L003CCF50
    /* 2CCD6C 003CCD6C 2D100000 */   daddu     $2, $0, $0
  .L003CCD70:
    /* 2CCD70 003CCD70 2E0039A2 */  sb         $25, 0x2E($17)
    /* 2CCD74 003CCD74 2000478E */  lw         $7, 0x20($18)
    /* 2CCD78 003CCD78 0020E730 */  andi       $7, $7, 0x2000
    /* 2CCD7C 003CCD7C 2A00E010 */  beqz       $7, .L003CCE28
    /* 2CCD80 003CCD80 00000000 */   nop
    /* 2CCD84 003CCD84 0800A78C */  lw         $7, 0x8($5)
    /* 2CCD88 003CCD88 01007626 */  addiu      $22, $19, 0x1
    /* 2CCD8C 003CCD8C 21A09602 */  addu       $20, $20, $22
    /* 2CCD90 003CCD90 0600012E */  sltiu      $1, $16, 0x6
    /* 2CCD94 003CCD94 01003627 */  addiu      $22, $25, 0x1
    /* 2CCD98 003CCD98 FF00D932 */  andi       $25, $22, 0xFF
    /* 2CCD9C 003CCD9C 180027AE */  sw         $7, 0x18($17)
    /* 2CCDA0 003CCDA0 200034AE */  sw         $20, 0x20($17)
    /* 2CCDA4 003CCDA4 280035A6 */  sh         $21, 0x28($17)
    /* 2CCDA8 003CCDA8 69FF2010 */  beqz       $1, .L003CCB50
    /* 2CCDAC 003CCDAC 2C0020A6 */   sh        $0, 0x2C($17)
    /* 2CCDB0 003CCDB0 80B01000 */  sll        $22, $16, 2
    /* 2CCDB4 003CCDB4 21B0C802 */  addu       $22, $22, $8
    /* 2CCDB8 003CCDB8 0000D68E */  lw         $22, 0x0($22)
    /* 2CCDBC 003CCDBC 0800C002 */  jr         $22
    /* 2CCDC0 003CCDC0 00000000 */   nop
    /* 2CCDC4 003CCDC4 00000000 */  nop
    /* 2CCDC8 003CCDC8 0100F324 */  addiu      $19, $7, 0x1
    /* 2CCDCC 003CCDCC 40381300 */  sll        $7, $19, 1
    /* 2CCDD0 003CCDD0 2138F300 */  addu       $7, $7, $19
    /* 2CCDD4 003CCDD4 5EFF0010 */  b          .L003CCB50
    /* 2CCDD8 003CCDD8 83980700 */   sra       $19, $7, 2
    /* 2CCDDC 003CCDDC 00000000 */  nop
    /* 2CCDE0 003CCDE0 5BFF0010 */  b          .L003CCB50
    /* 2CCDE4 003CCDE4 2D98E000 */   daddu     $19, $7, $0
    /* 2CCDE8 003CCDE8 40380700 */  sll        $7, $7, 1
    /* 2CCDEC 003CCDEC 0300E724 */  addiu      $7, $7, 0x3
    /* 2CCDF0 003CCDF0 57FF0010 */  b          .L003CCB50
    /* 2CCDF4 003CCDF4 83980700 */   sra       $19, $7, 2
    /* 2CCDF8 003CCDF8 55FF0010 */  b          .L003CCB50
    /* 2CCDFC 003CCDFC 2D98E000 */   daddu     $19, $7, $0
    /* 2CCE00 003CCE00 0300E724 */  addiu      $7, $7, 0x3
    /* 2CCE04 003CCE04 52FF0010 */  b          .L003CCB50
    /* 2CCE08 003CCE08 83980700 */   sra       $19, $7, 2
    /* 2CCE0C 003CCE0C 00000000 */  nop
    /* 2CCE10 003CCE10 40980700 */  sll        $19, $7, 1
    /* 2CCE14 003CCE14 21386702 */  addu       $7, $19, $7
    /* 2CCE18 003CCE18 0F00E724 */  addiu      $7, $7, 0xF
    /* 2CCE1C 003CCE1C 4CFF0010 */  b          .L003CCB50
    /* 2CCE20 003CCE20 03990700 */   sra       $19, $7, 4
    /* 2CCE24 003CCE24 00000000 */  nop
  .L003CCE28:
    /* 2CCE28 003CCE28 180020AE */  sw         $0, 0x18($17)
    /* 2CCE2C 003CCE2C 200020AE */  sw         $0, 0x20($17)
    /* 2CCE30 003CCE30 01002727 */  addiu      $7, $25, 0x1
    /* 2CCE34 003CCE34 280020A6 */  sh         $0, 0x28($17)
    /* 2CCE38 003CCE38 FF00F930 */  andi       $25, $7, 0xFF
    /* 2CCE3C 003CCE3C 44FF0010 */  b          .L003CCB50
    /* 2CCE40 003CCE40 2C0020A6 */   sh        $0, 0x2C($17)
    /* 2CCE44 003CCE44 00000000 */  nop
  .L003CCE48:
    /* 2CCE48 003CCE48 2E0099A2 */  sb         $25, 0x2E($20)
    /* 2CCE4C 003CCE4C 2000A78E */  lw         $7, 0x20($21)
    /* 2CCE50 003CCE50 0020E730 */  andi       $7, $7, 0x2000
    /* 2CCE54 003CCE54 3600E010 */  beqz       $7, .L003CCF30
    /* 2CCE58 003CCE58 00000000 */   nop
    /* 2CCE5C 003CCE5C 1000A78C */  lw         $7, 0x10($5)
    /* 2CCE60 003CCE60 01001626 */  addiu      $22, $16, 0x1
    /* 2CCE64 003CCE64 21883602 */  addu       $17, $17, $22
    /* 2CCE68 003CCE68 0C00612E */  sltiu      $1, $19, 0xC
    /* 2CCE6C 003CCE6C 01003627 */  addiu      $22, $25, 0x1
    /* 2CCE70 003CCE70 FF00D932 */  andi       $25, $22, 0xFF
    /* 2CCE74 003CCE74 1C0087AE */  sw         $7, 0x1C($20)
    /* 2CCE78 003CCE78 240091AE */  sw         $17, 0x24($20)
    /* 2CCE7C 003CCE7C 2A0092A6 */  sh         $18, 0x2A($20)
    /* 2CCE80 003CCE80 9DFF2010 */  beqz       $1, .L003CCCF8
    /* 2CCE84 003CCE84 2C0080A6 */   sh        $0, 0x2C($20)
    /* 2CCE88 003CCE88 80B01300 */  sll        $22, $19, 2
    /* 2CCE8C 003CCE8C 21B0C602 */  addu       $22, $22, $6
    /* 2CCE90 003CCE90 0000D68E */  lw         $22, 0x0($22)
    /* 2CCE94 003CCE94 0800C002 */  jr         $22
    /* 2CCE98 003CCE98 00000000 */   nop
    /* 2CCE9C 003CCE9C 00000000 */  nop
    /* 2CCEA0 003CCEA0 0100F024 */  addiu      $16, $7, 0x1
    /* 2CCEA4 003CCEA4 40381000 */  sll        $7, $16, 1
    /* 2CCEA8 003CCEA8 2138F000 */  addu       $7, $7, $16
    /* 2CCEAC 003CCEAC 92FF0010 */  b          .L003CCCF8
    /* 2CCEB0 003CCEB0 83800700 */   sra       $16, $7, 2
    /* 2CCEB4 003CCEB4 00000000 */  nop
    /* 2CCEB8 003CCEB8 8FFF0010 */  b          .L003CCCF8
    /* 2CCEBC 003CCEBC 2D80E000 */   daddu     $16, $7, $0
    /* 2CCEC0 003CCEC0 40380700 */  sll        $7, $7, 1
    /* 2CCEC4 003CCEC4 0300E724 */  addiu      $7, $7, 0x3
    /* 2CCEC8 003CCEC8 8BFF0010 */  b          .L003CCCF8
    /* 2CCECC 003CCECC 83800700 */   sra       $16, $7, 2
    /* 2CCED0 003CCED0 89FF0010 */  b          .L003CCCF8
    /* 2CCED4 003CCED4 2D80E000 */   daddu     $16, $7, $0
    /* 2CCED8 003CCED8 0300E724 */  addiu      $7, $7, 0x3
    /* 2CCEDC 003CCEDC 86FF0010 */  b          .L003CCCF8
    /* 2CCEE0 003CCEE0 83800700 */   sra       $16, $7, 2
    /* 2CCEE4 003CCEE4 00000000 */  nop
    /* 2CCEE8 003CCEE8 40800700 */  sll        $16, $7, 1
    /* 2CCEEC 003CCEEC 21380702 */  addu       $7, $16, $7
    /* 2CCEF0 003CCEF0 0F00E724 */  addiu      $7, $7, 0xF
    /* 2CCEF4 003CCEF4 80FF0010 */  b          .L003CCCF8
    /* 2CCEF8 003CCEF8 03810700 */   sra       $16, $7, 4
    /* 2CCEFC 003CCEFC 00000000 */  nop
    /* 2CCF00 003CCF00 0100F024 */  addiu      $16, $7, 0x1
    /* 2CCF04 003CCF04 40381000 */  sll        $7, $16, 1
    /* 2CCF08 003CCF08 2138F000 */  addu       $7, $7, $16
    /* 2CCF0C 003CCF0C 7AFF0010 */  b          .L003CCCF8
    /* 2CCF10 003CCF10 83800700 */   sra       $16, $7, 2
    /* 2CCF14 003CCF14 00000000 */  nop
    /* 2CCF18 003CCF18 40800700 */  sll        $16, $7, 1
    /* 2CCF1C 003CCF1C 21380702 */  addu       $7, $16, $7
    /* 2CCF20 003CCF20 0F00E724 */  addiu      $7, $7, 0xF
    /* 2CCF24 003CCF24 74FF0010 */  b          .L003CCCF8
    /* 2CCF28 003CCF28 03810700 */   sra       $16, $7, 4
    /* 2CCF2C 003CCF2C 00000000 */  nop
  .L003CCF30:
    /* 2CCF30 003CCF30 1C0080AE */  sw         $0, 0x1C($20)
    /* 2CCF34 003CCF34 240080AE */  sw         $0, 0x24($20)
    /* 2CCF38 003CCF38 01002727 */  addiu      $7, $25, 0x1
    /* 2CCF3C 003CCF3C 2A0080A6 */  sh         $0, 0x2A($20)
    /* 2CCF40 003CCF40 FF00F930 */  andi       $25, $7, 0xFF
    /* 2CCF44 003CCF44 6CFF0010 */  b          .L003CCCF8
    /* 2CCF48 003CCF48 2C0080A6 */   sh        $0, 0x2C($20)
    /* 2CCF4C 003CCF4C 00000000 */  nop
  .L003CCF50:
    /* 2CCF50 003CCF50 8000BE7B */  lq         $30, 0x80($29)
    /* 2CCF54 003CCF54 7000B77B */  lq         $23, 0x70($29)
    /* 2CCF58 003CCF58 6000B67B */  lq         $22, 0x60($29)
    /* 2CCF5C 003CCF5C 5000B57B */  lq         $21, 0x50($29)
    /* 2CCF60 003CCF60 4000B47B */  lq         $20, 0x40($29)
    /* 2CCF64 003CCF64 3000B37B */  lq         $19, 0x30($29)
    /* 2CCF68 003CCF68 2000B27B */  lq         $18, 0x20($29)
    /* 2CCF6C 003CCF6C 1000B17B */  lq         $17, 0x10($29)
    /* 2CCF70 003CCF70 0000B07B */  lq         $16, 0x0($29)
    /* 2CCF74 003CCF74 0800E003 */  jr         $31
    /* 2CCF78 003CCF78 9000BD27 */   addiu     $29, $29, 0x90
    /* 2CCF7C 003CCF7C 00000000 */  nop
.size func_003cc720, 0x860
