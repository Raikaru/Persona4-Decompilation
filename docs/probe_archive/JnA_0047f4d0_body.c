/* object_size=220; window=224; normalized_diff=51 differing words (reloc-masked); differing_offsets=0x0000..0x00d8 excluding the four reloc-masked-equal words reported by fndiff; classification=near_match_struct_copy_but_FPR_saves; chain=plain natural C reproduced all three adda.s/madd.s accumulator pairs; ruled_out=typed helper call with local scalar vector (frame 0x40 and f20/f21 saves), pointer-only helper plus scalar locals (frame 0x30 but f20-f23 saves and dead assignment omitted), no-prototype helper (fptodp conversions), K&R parameters (fptodp/dptofp and oversized frame), third helper parameter, opt_propagation off, and optimization_level 1/2; frame=0x50, ra saved at sp+0x20, f20 saved at sp+0, pointer-only struct dataflow. */

/* Best attempted body. Struct copies force the exact four scalar loads and
 * stores around each helper call, but MWCC still preserves interpolation
 * factor f14 in f20 across the external calls and leaves the frame 0x20 too
 * large. The target was restored to its exact INCLUDE_ASM baseline. */
/* Candidate source body used for the measured residual: */
u8 *func_0047f4d0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    struct Vec4 {
        f32 v[4];
    } first, second;

    first = *(struct Vec4 *)func_0047f3a0(arg0);
    fparg0 = fparg1;
    second = *(struct Vec4 *)func_0047f3a0(arg1);
    D_00922C44 = first.v[1] + (second.v[1] - first.v[1]) * fparg2;
    D_00922C48 = first.v[2] + (second.v[2] - first.v[2]) * fparg2;
    D_00922C4C = first.v[3] + (second.v[3] - first.v[3]) * fparg2;
    return D_00922C40;
}
