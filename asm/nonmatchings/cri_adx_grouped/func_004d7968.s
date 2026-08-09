.section .text
.set noat
.set noreorder
glabel func_004d7968
    /* 3D7968 004D7968 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3D796C 004D796C 3000B0FF */  sd         $16, 0x30($29)
    /* 3D7970 004D7970 2D808000 */  daddu      $16, $4, $0
    /* 3D7974 004D7974 4800B3FF */  sd         $19, 0x48($29)
    /* 3D7978 004D7978 00081324 */  addiu      $19, $0, 0x800
    /* 3D797C 004D797C 3800B1FF */  sd         $17, 0x38($29)
    /* 3D7980 004D7980 4000B2FF */  sd         $18, 0x40($29)
    /* 3D7984 004D7984 5000B4FF */  sd         $20, 0x50($29)
    /* 3D7988 004D7988 5800B5FF */  sd         $21, 0x58($29)
    /* 3D798C 004D798C 6000BFFF */  sd         $31, 0x60($29)
    /* 3D7990 004D7990 2000A0AF */  sw         $0, 0x20($29)
    /* 3D7994 004D7994 0400118E */  lw         $17, 0x4($16)
    /* 3D7998 004D7998 02000292 */  lbu        $2, 0x2($16)
    /* 3D799C 004D799C 2400A0AF */  sw         $0, 0x24($29)
    /* 3D79A0 004D79A0 0200422C */  sltiu      $2, $2, 0x2
    /* 3D79A4 004D79A4 18004010 */  beqz       $2, .L004D7A08
    /* 3D79A8 004D79A8 A80000AE */   sw        $0, 0xA8($16)
    /* 3D79AC 004D79AC AC000382 */  lb         $3, 0xAC($16)
    /* 3D79B0 004D79B0 01000224 */  addiu      $2, $0, 0x1
    /* 3D79B4 004D79B4 14006214 */  bne        $3, $2, .L004D7A08
    /* 3D79B8 004D79B8 00000000 */   nop
    /* 3D79BC 004D79BC FE47130C */  jal        func_004d1ff8
    /* 3D79C0 004D79C0 0800048E */   lw        $4, 0x8($16)
    /* 3D79C4 004D79C4 02000324 */  addiu      $3, $0, 0x2
    /* 3D79C8 004D79C8 E2004350 */  beql       $2, $3, .L004D7D54
    /* 3D79CC 004D79CC 3000B0DF */   ld        $16, 0x30($29)
    /* 3D79D0 004D79D0 1000048E */  lw         $4, 0x10($16)
    /* 3D79D4 004D79D4 06008050 */  beql       $4, $0, .L004D79F0
    /* 3D79D8 004D79D8 B400058E */   lw        $5, 0xB4($16)
    /* 3D79DC 004D79DC 0000838C */  lw         $3, 0x0($4)
    /* 3D79E0 004D79E0 1400628C */  lw         $2, 0x14($3)
    /* 3D79E4 004D79E4 09F84000 */  jalr       $2
    /* 3D79E8 004D79E8 00000000 */   nop
    /* 3D79EC 004D79EC B400058E */  lw         $5, 0xB4($16)
  .L004D79F0:
    /* 3D79F0 004D79F0 2D200002 */  daddu      $4, $16, $0
    /* 3D79F4 004D79F4 B800068E */  lw         $6, 0xB8($16)
    /* 3D79F8 004D79F8 BC00078E */  lw         $7, 0xBC($16)
    /* 3D79FC 004D79FC 2850130C */  jal        func_004d40a0
    /* 3D7A00 004D7A00 C000088E */   lw        $8, 0xC0($16)
    /* 3D7A04 004D7A04 AC0000A2 */  sb         $0, 0xAC($16)
  .L004D7A08:
    /* 3D7A08 004D7A08 2637130C */  jal        func_004cdc98
    /* 3D7A0C 004D7A0C 2D202002 */   daddu     $4, $17, $0
    /* 3D7A10 004D7A10 2D184000 */  daddu      $3, $2, $0
    /* 3D7A14 004D7A14 02000224 */  addiu      $2, $0, 0x2
    /* 3D7A18 004D7A18 C9006254 */  bnel       $3, $2, .L004D7D40
    /* 3D7A1C 004D7A1C 04000224 */   addiu     $2, $0, 0x4
    /* 3D7A20 004D7A20 6A3B130C */  jal        func_004ceda8
    /* 3D7A24 004D7A24 2D202002 */   daddu     $4, $17, $0
    /* 3D7A28 004D7A28 03000582 */  lb         $5, 0x3($16)
    /* 3D7A2C 004D7A2C 2DA04000 */  daddu      $20, $2, $0
    /* 3D7A30 004D7A30 2A10B400 */  slt        $2, $5, $20
    /* 3D7A34 004D7A34 0C004010 */  beqz       $2, .L004D7A68
    /* 3D7A38 004D7A38 2D30A003 */   daddu     $6, $29, $0
    /* 3D7A3C 004D7A3C 2D208002 */  daddu      $4, $20, $0
    /* 3D7A40 004D7A40 1A1B130C */  jal        func_004c6c68
    /* 3D7A44 004D7A44 10000724 */   addiu     $7, $0, 0x10
    /* 3D7A48 004D7A48 7600043C */  lui        $4, %hi(D_00759490)
    /* 3D7A4C 004D7A4C 90948424 */  addiu      $4, $4, %lo(D_00759490)
    /* 3D7A50 004D7A50 BC1A130C */  jal        func_004c6af0
    /* 3D7A54 004D7A54 2D28A003 */   daddu     $5, $29, $0
    /* 3D7A58 004D7A58 C250130C */  jal        func_004d4308
    /* 3D7A5C 004D7A5C 2D200002 */   daddu     $4, $16, $0
    /* 3D7A60 004D7A60 BC000010 */  b          .L004D7D54
    /* 3D7A64 004D7A64 3000B0DF */   ld        $16, 0x30($29)
  .L004D7A68:
    /* 3D7A68 004D7A68 643B130C */  jal        func_004ced90
    /* 3D7A6C 004D7A6C 2D202002 */   daddu     $4, $17, $0
    /* 3D7A70 004D7A70 2D202002 */  daddu      $4, $17, $0
    /* 3D7A74 004D7A74 8E3B130C */  jal        func_004cee38
    /* 3D7A78 004D7A78 2D904000 */   daddu     $18, $2, $0
    /* 3D7A7C 004D7A7C 2DA04000 */  daddu      $20, $2, $0
    /* 3D7A80 004D7A80 0B00805A */  blezl      $20, .L004D7AB0
    /* 3D7A84 004D7A84 3800038E */   lw        $3, 0x38($16)
    /* 3D7A88 004D7A88 3800028E */  lw         $2, 0x38($16)
    /* 3D7A8C 004D7A8C 1A004202 */  div        $0, $18, $2
    /* 3D7A90 004D7A90 01004050 */  beql       $2, $0, .L004D7A98
    /* 3D7A94 004D7A94 CD010000 */   break     0, 7
  .L004D7A98:
    /* 3D7A98 004D7A98 12200000 */  mflo       $4
    /* 3D7A9C 004D7A9C 40180400 */  sll        $3, $4, 1
    /* 3D7AA0 004D7AA0 21186400 */  addu       $3, $3, $4
    /* 3D7AA4 004D7AA4 0C000010 */  b          .L004D7AD8
    /* 3D7AA8 004D7AA8 480003AE */   sw        $3, 0x48($16)
    /* 3D7AAC 004D7AAC 00000000 */  nop
  .L004D7AB0:
    /* 3D7AB0 004D7AB0 1A004302 */  div        $0, $18, $3
    /* 3D7AB4 004D7AB4 01006050 */  beql       $3, $0, .L004D7ABC
    /* 3D7AB8 004D7AB8 CD010000 */   break     0, 7
  .L004D7ABC:
    /* 3D7ABC 004D7ABC 12200000 */  mflo       $4
    /* 3D7AC0 004D7AC0 40100400 */  sll        $2, $4, 1
    /* 3D7AC4 004D7AC4 21104400 */  addu       $2, $2, $4
    /* 3D7AC8 004D7AC8 C21F0200 */  srl        $3, $2, 31
    /* 3D7ACC 004D7ACC 21104300 */  addu       $2, $2, $3
    /* 3D7AD0 004D7AD0 43100200 */  sra        $2, $2, 1
    /* 3D7AD4 004D7AD4 480002AE */  sw         $2, 0x48($16)
  .L004D7AD8:
    /* 3D7AD8 004D7AD8 763B130C */  jal        func_004cedd8
    /* 3D7ADC 004D7ADC 2D202002 */   daddu     $4, $17, $0
    /* 3D7AE0 004D7AE0 4800058E */  lw         $5, 0x48($16)
    /* 3D7AE4 004D7AE4 40100200 */  sll        $2, $2, 1
    /* 3D7AE8 004D7AE8 2D202002 */  daddu      $4, $17, $0
    /* 3D7AEC 004D7AEC 2128A200 */  addu       $5, $5, $2
    /* 3D7AF0 004D7AF0 01004050 */  beql       $2, $0, .L004D7AF8
    /* 3D7AF4 004D7AF4 CD010000 */   break     0, 7
  .L004D7AF8:
    /* 3D7AF8 004D7AF8 1A00A200 */  div        $0, $5, $2
    /* 3D7AFC 004D7AFC 12280000 */  mflo       $5
    /* 3D7B00 004D7B00 1828A200 */  mult       $5, $5, $2
    /* 3D7B04 004D7B04 3C37130C */  jal        func_004cdcf0
    /* 3D7B08 004D7B08 480005AE */   sw        $5, 0x48($16)
    /* 3D7B0C 004D7B0C 3400805A */  blezl      $20, .L004D7BE0
    /* 3D7B10 004D7B10 0800048E */   lw        $4, 0x8($16)
    /* 3D7B14 004D7B14 02000382 */  lb         $3, 0x2($16)
    /* 3D7B18 004D7B18 02000224 */  addiu      $2, $0, 0x2
    /* 3D7B1C 004D7B1C 04006214 */  bne        $3, $2, .L004D7B30
    /* 3D7B20 004D7B20 00000000 */   nop
    /* 3D7B24 004D7B24 19000010 */  b          .L004D7B8C
    /* 3D7B28 004D7B28 500000AE */   sw        $0, 0x50($16)
    /* 3D7B2C 004D7B2C 00000000 */  nop
  .L004D7B30:
    /* 3D7B30 004D7B30 B23B130C */  jal        func_004ceec8
    /* 3D7B34 004D7B34 2D202002 */   daddu     $4, $17, $0
    /* 3D7B38 004D7B38 01006052 */  beql       $19, $0, .L004D7B40
    /* 3D7B3C 004D7B3C CD010000 */   break     0, 7
  .L004D7B40:
    /* 3D7B40 004D7B40 1A005300 */  div        $0, $2, $19
    /* 3D7B44 004D7B44 FF074224 */  addiu      $2, $2, 0x7FF
    /* 3D7B48 004D7B48 10180000 */  mfhi       $3
    /* 3D7B4C 004D7B4C 1A005300 */  div        $0, $2, $19
    /* 3D7B50 004D7B50 23186302 */  subu       $3, $19, $3
    /* 3D7B54 004D7B54 500003AE */  sw         $3, 0x50($16)
    /* 3D7B58 004D7B58 12100000 */  mflo       $2
    /* 3D7B5C 004D7B5C 1A007300 */  div        $0, $3, $19
    /* 3D7B60 004D7B60 2D284000 */  daddu      $5, $2, $0
    /* 3D7B64 004D7B64 10200000 */  mfhi       $4
    /* 3D7B68 004D7B68 500004AE */  sw         $4, 0x50($16)
    /* 3D7B6C 004D7B6C 0800048E */  lw         $4, 0x8($16)
    /* 3D7B70 004D7B70 EA48130C */  jal        func_004d23a8
    /* 3D7B74 004D7B74 8C0002AE */   sw        $2, 0x8C($16)
    /* 3D7B78 004D7B78 4D00053C */  lui        $5, %hi(func_004d7570)
    /* 3D7B7C 004D7B7C 0800048E */  lw         $4, 0x8($16)
    /* 3D7B80 004D7B80 7075A524 */  addiu      $5, $5, %lo(func_004d7570)
    /* 3D7B84 004D7B84 D248130C */  jal        func_004d2348
    /* 3D7B88 004D7B88 2D300002 */   daddu     $6, $16, $0
  .L004D7B8C:
    /* 3D7B8C 004D7B8C AC3B130C */  jal        func_004ceeb0
    /* 3D7B90 004D7B90 2D202002 */   daddu     $4, $17, $0
    /* 3D7B94 004D7B94 9A3B130C */  jal        func_004cee68
    /* 3D7B98 004D7B98 2D202002 */   daddu     $4, $17, $0
    /* 3D7B9C 004D7B9C 2D202002 */  daddu      $4, $17, $0
    /* 3D7BA0 004D7BA0 900002AE */  sw         $2, 0x90($16)
    /* 3D7BA4 004D7BA4 523B130C */  jal        func_004ced48
    /* 3D7BA8 004D7BA8 2D284000 */   daddu     $5, $2, $0
    /* 3D7BAC 004D7BAC 2D202002 */  daddu      $4, $17, $0
    /* 3D7BB0 004D7BB0 5A3B130C */  jal        func_004ced68
    /* 3D7BB4 004D7BB4 2D280000 */   daddu     $5, $0, $0
    /* 3D7BB8 004D7BB8 2D202002 */  daddu      $4, $17, $0
    /* 3D7BBC 004D7BBC 563B130C */  jal        func_004ced58
    /* 3D7BC0 004D7BC0 2D280000 */   daddu     $5, $0, $0
    /* 3D7BC4 004D7BC4 4D00053C */  lui        $5, %hi(func_004d7320)
    /* 3D7BC8 004D7BC8 2073A524 */  addiu      $5, $5, %lo(func_004d7320)
    /* 3D7BCC 004D7BCC 2D202002 */  daddu      $4, $17, $0
    /* 3D7BD0 004D7BD0 4E3B130C */  jal        func_004ced38
    /* 3D7BD4 004D7BD4 2D300002 */   daddu     $6, $16, $0
    /* 3D7BD8 004D7BD8 16000010 */  b          .L004D7C34
    /* 3D7BDC 004D7BDC 00000000 */   nop
  .L004D7BE0:
    /* 3D7BE0 004D7BE0 04008010 */  beqz       $4, .L004D7BF4
    /* 3D7BE4 004D7BE4 00000000 */   nop
    /* 3D7BE8 004D7BE8 FF7F053C */  lui        $5, (0x7FFFFFFF >> 16)
    /* 3D7BEC 004D7BEC EA48130C */  jal        func_004d23a8
    /* 3D7BF0 004D7BF0 FFFFA534 */   ori       $5, $5, (0x7FFFFFFF & 0xFFFF)
  .L004D7BF4:
    /* 3D7BF4 004D7BF4 823B130C */  jal        func_004cee08
    /* 3D7BF8 004D7BF8 2D202002 */   daddu     $4, $17, $0
    /* 3D7BFC 004D7BFC 2D202002 */  daddu      $4, $17, $0
    /* 3D7C00 004D7C00 523B130C */  jal        func_004ced48
    /* 3D7C04 004D7C04 2D284000 */   daddu     $5, $2, $0
    /* 3D7C08 004D7C08 2D202002 */  daddu      $4, $17, $0
    /* 3D7C0C 004D7C0C 5A3B130C */  jal        func_004ced68
    /* 3D7C10 004D7C10 2D280000 */   daddu     $5, $0, $0
    /* 3D7C14 004D7C14 2D202002 */  daddu      $4, $17, $0
    /* 3D7C18 004D7C18 563B130C */  jal        func_004ced58
    /* 3D7C1C 004D7C1C 2D280000 */   daddu     $5, $0, $0
    /* 3D7C20 004D7C20 4D00053C */  lui        $5, %hi(func_004d7680)
    /* 3D7C24 004D7C24 8076A524 */  addiu      $5, $5, %lo(func_004d7680)
    /* 3D7C28 004D7C28 2D202002 */  daddu      $4, $17, $0
    /* 3D7C2C 004D7C2C 4E3B130C */  jal        func_004ced38
    /* 3D7C30 004D7C30 2D300002 */   daddu     $6, $16, $0
  .L004D7C34:
    /* 3D7C34 004D7C34 643B130C */  jal        func_004ced90
    /* 3D7C38 004D7C38 2D202002 */   daddu     $4, $17, $0
    /* 3D7C3C 004D7C3C 2D202002 */  daddu      $4, $17, $0
    /* 3D7C40 004D7C40 6A3B130C */  jal        func_004ceda8
    /* 3D7C44 004D7C44 2D904000 */   daddu     $18, $2, $0
    /* 3D7C48 004D7C48 2D202002 */  daddu      $4, $17, $0
    /* 3D7C4C 004D7C4C 823B130C */  jal        func_004cee08
    /* 3D7C50 004D7C50 2DA04000 */   daddu     $20, $2, $0
    /* 3D7C54 004D7C54 2D202002 */  daddu      $4, $17, $0
    /* 3D7C58 004D7C58 703B130C */  jal        func_004cedc0
    /* 3D7C5C 004D7C5C 2DA84000 */   daddu     $21, $2, $0
    /* 3D7C60 004D7C60 0C00048E */  lw         $4, 0xC($16)
    /* 3D7C64 004D7C64 1836130C */  jal        func_004cd860
    /* 3D7C68 004D7C68 2D284000 */   daddu     $5, $2, $0
    /* 3D7C6C 004D7C6C 0C00048E */  lw         $4, 0xC($16)
    /* 3D7C70 004D7C70 0036130C */  jal        func_004cd800
    /* 3D7C74 004D7C74 2D284002 */   daddu     $5, $18, $0
    /* 3D7C78 004D7C78 0C00048E */  lw         $4, 0xC($16)
    /* 3D7C7C 004D7C7C FA35130C */  jal        func_004cd7e8
    /* 3D7C80 004D7C80 2D288002 */   daddu     $5, $20, $0
    /* 3D7C84 004D7C84 0C00048E */  lw         $4, 0xC($16)
    /* 3D7C88 004D7C88 5236130C */  jal        func_004cd948
    /* 3D7C8C 004D7C8C 2D28A002 */   daddu     $5, $21, $0
    /* 3D7C90 004D7C90 2D200002 */  daddu      $4, $16, $0
    /* 3D7C94 004D7C94 4454130C */  jal        func_004d5110
    /* 3D7C98 004D7C98 40000586 */   lh        $5, 0x40($16)
    /* 3D7C9C 004D7C9C 2D200002 */  daddu      $4, $16, $0
    /* 3D7CA0 004D7CA0 2000A527 */  addiu      $5, $29, 0x20
    /* 3D7CA4 004D7CA4 B258130C */  jal        func_004d62c8
    /* 3D7CA8 004D7CA8 2400A627 */   addiu     $6, $29, 0x24
    /* 3D7CAC 004D7CAC 2000A58F */  lw         $5, 0x20($29)
    /* 3D7CB0 004D7CB0 0300A014 */  bnez       $5, .L004D7CC0
    /* 3D7CB4 004D7CB4 2400A68F */   lw        $6, 0x24($29)
    /* 3D7CB8 004D7CB8 0300C010 */  beqz       $6, .L004D7CC8
    /* 3D7CBC 004D7CBC 00000000 */   nop
  .L004D7CC0:
    /* 3D7CC0 004D7CC0 B058130C */  jal        func_004d62c0
    /* 3D7CC4 004D7CC4 2D200002 */   daddu     $4, $16, $0
  .L004D7CC8:
    /* 3D7CC8 004D7CC8 865D130C */  jal        func_004d7618
    /* 3D7CCC 004D7CCC 2D200002 */   daddu     $4, $16, $0
    /* 3D7CD0 004D7CD0 7400048E */  lw         $4, 0x74($16)
    /* 3D7CD4 004D7CD4 04008050 */  beql       $4, $0, .L004D7CE8
    /* 3D7CD8 004D7CD8 2D202002 */   daddu     $4, $17, $0
    /* 3D7CDC 004D7CDC 8E06130C */  jal        func_004c1a38
    /* 3D7CE0 004D7CE0 2D284002 */   daddu     $5, $18, $0
    /* 3D7CE4 004D7CE4 2D202002 */  daddu      $4, $17, $0
  .L004D7CE8:
    /* 3D7CE8 004D7CE8 5E3B130C */  jal        func_004ced78
    /* 3D7CEC 004D7CEC 02001324 */   addiu     $19, $0, 0x2
    /* 3D7CF0 004D7CF0 07005354 */  bnel       $2, $19, .L004D7D10
    /* 3D7CF4 004D7CF4 0C00048E */   lw        $4, 0xC($16)
    /* 3D7CF8 004D7CF8 0C3C130C */  jal        func_004cf030
    /* 3D7CFC 004D7CFC 2D202002 */   daddu     $4, $17, $0
    /* 3D7D00 004D7D00 0C00048E */  lw         $4, 0xC($16)
    /* 3D7D04 004D7D04 5636130C */  jal        func_004cd958
    /* 3D7D08 004D7D08 2D284000 */   daddu     $5, $2, $0
    /* 3D7D0C 004D7D0C 0C00048E */  lw         $4, 0xC($16)
  .L004D7D10:
    /* 3D7D10 004D7D10 C235130C */  jal        func_004cd708
    /* 3D7D14 004D7D14 01000524 */   addiu     $5, $0, 0x1
    /* 3D7D18 004D7D18 7200023C */  lui        $2, %hi(D_00724EB8)
    /* 3D7D1C 004D7D1C B84E428C */  lw         $2, %lo(D_00724EB8)($2)
    /* 3D7D20 004D7D20 05004010 */  beqz       $2, .L004D7D38
    /* 3D7D24 004D7D24 2D284002 */   daddu     $5, $18, $0
    /* 3D7D28 004D7D28 2D308002 */  daddu      $6, $20, $0
    /* 3D7D2C 004D7D2C 2D38A002 */  daddu      $7, $21, $0
    /* 3D7D30 004D7D30 09F84000 */  jalr       $2
    /* 3D7D34 004D7D34 2D200002 */   daddu     $4, $16, $0
  .L004D7D38:
    /* 3D7D38 004D7D38 05000010 */  b          .L004D7D50
    /* 3D7D3C 004D7D3C 010013A2 */   sb        $19, 0x1($16)
  .L004D7D40:
    /* 3D7D40 004D7D40 04006254 */  bnel       $3, $2, .L004D7D54
    /* 3D7D44 004D7D44 3000B0DF */   ld        $16, 0x30($29)
    /* 3D7D48 004D7D48 06000224 */  addiu      $2, $0, 0x6
    /* 3D7D4C 004D7D4C 010002A2 */  sb         $2, 0x1($16)
  .L004D7D50:
    /* 3D7D50 004D7D50 3000B0DF */  ld         $16, 0x30($29)
  .L004D7D54:
    /* 3D7D54 004D7D54 3800B1DF */  ld         $17, 0x38($29)
    /* 3D7D58 004D7D58 4000B2DF */  ld         $18, 0x40($29)
    /* 3D7D5C 004D7D5C 4800B3DF */  ld         $19, 0x48($29)
    /* 3D7D60 004D7D60 5000B4DF */  ld         $20, 0x50($29)
    /* 3D7D64 004D7D64 5800B5DF */  ld         $21, 0x58($29)
    /* 3D7D68 004D7D68 6000BFDF */  ld         $31, 0x60($29)
    /* 3D7D6C 004D7D6C 0800E003 */  jr         $31
    /* 3D7D70 004D7D70 7000BD27 */   addiu     $29, $29, 0x70
    /* 3D7D74 004D7D74 00000000 */  nop
.size func_004d7968, 0x410
