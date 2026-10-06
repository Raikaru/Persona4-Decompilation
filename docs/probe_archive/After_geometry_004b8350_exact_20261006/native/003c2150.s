003c2150 addiu $sp, $sp, -0x40
003c2154 sd $ra, 0x30($sp)
003c2158 sq $s2, 0x20($sp)
003c215c sq $s1, 0x10($sp)
003c2160 move $s2, $a0
003c2164 sq $s0, 0x0($sp)
003c2168 move $s0, $a2
003c216c beqz $s0, 0x3c21b0
003c2170 move $s1, $a1
003c2174 addiu $a0, $s2, 0x20
003c2178 jal 0x3c4bc0
003c217c move $a1, $s0
003c2180 bltz $v0, 0x3c2194
003c2184 nop 
003c2188 sh $v0, 6($s1)
003c218c b 0x3c21bc
003c2190 move $v0, $s2
003c2194 move $a1, $s0
003c2198 jal 0x3c4a80
003c219c addiu $a0, $s2, 0x20
003c21a0 bgez $v0, 0x3c2188
003c21a4 nop 
003c21a8 b 0x3c21bc
003c21ac move $v0, $zero
003c21b0 ori $v0, $zero, 0xffff
003c21b4 b 0x3c218c
003c21b8 sh $v0, 6($s1)
003c21bc ld $ra, 0x30($sp)
003c21c0 lq $s2, 0x20($sp)
003c21c4 lq $s1, 0x10($sp)
003c21c8 lq $s0, 0x0($sp)
003c21cc jr $ra
003c21d0 addiu $sp, $sp, 0x40
003c21d4 nop 
003c21d8 nop 
003c21dc nop 
