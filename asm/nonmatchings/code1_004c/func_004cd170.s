.section .text
.set noat
.set noreorder
glabel func_004cd170
    /* 3CD170 004CD170 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD174 004CD174 9200023C */  lui        $2, %hi(D_00922E20)
    /* 3CD178 004CD178 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD17C 004CD17C 202E4224 */  addiu      $2, $2, %lo(D_00922E20)
    /* 3CD180 004CD180 0000438C */  lw         $3, 0x0($2)
    /* 3CD184 004CD184 04006050 */  beql       $3, $0, .L004CD198
    /* 3CD188 004CD188 0000BFDF */   ld        $31, 0x0($29)
    /* 3CD18C 004CD18C 09F86000 */  jalr       $3
    /* 3CD190 004CD190 0400448C */   lw        $4, 0x4($2)
    /* 3CD194 004CD194 0000BFDF */  ld         $31, 0x0($29)
  .L004CD198:
    /* 3CD198 004CD198 0800E003 */  jr         $31
    /* 3CD19C 004CD19C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd170, 0x30
