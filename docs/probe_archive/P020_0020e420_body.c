/* object_size=not_measured window=416 normalized_diff=not_measured differing_offsets=not_measured classification=confirmed COP1 accumulator floor; retail contains adda.s and msub.s in the branch at 0x0020e4e0-0x0020e4f4; ruled_out=the retail window has no movz/movn, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; no source probe attempted per floor-first rule. Entry first-touches preserve a mixed ABI signature: incoming $a0/$a1/$a2/$a3 plus $f12/$f13, likely declaration order arg0, fparg0, fparg1, arg1, arg2, arg3 rather than grouping classes. Plain compliant MWCCPS2 C cannot emit the accumulator chain. */
/* Retail outline (not compiled): unpack arg3 bytes into four signed color locals;
 * if (arg0's flag byte is nonzero) call func_00442088/func_00442948, adjust the
 * two float coordinates using the COP1 adda.s/msub.s chain, then iterate the
 * returned count and call func_00201650(arg0,10,sp144[i]-25,colors...,f12,f13),
 * advancing f12 by 19.0f each iteration. */
