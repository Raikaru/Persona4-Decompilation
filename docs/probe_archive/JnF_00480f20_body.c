// Lane JnF residual archive: func_00480f20.
// Candidate object: 404 bytes; retail window: 416 bytes.
// normalized_diff: 97 reloc-masked words reported by fndiff; differing offsets below cover 0x04-0x190, with 0x194-0x19c absent from the shorter candidate.
// Differing instruction offsets (retail-relative): 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x60, 0x64, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0, 0xc4, 0xc8, 0xcc, 0xd0, 0xd4, 0xd8, 0xdc, 0xe0, 0xe4, 0xe8, 0xec, 0xf0, 0xf4, 0xf8, 0xfc, 0x100, 0x104, 0x108, 0x10c, 0x110, 0x114, 0x118, 0x11c, 0x120, 0x124, 0x128, 0x12c, 0x130, 0x134, 0x138, 0x13c, 0x140, 0x144, 0x148, 0x14c, 0x150, 0x154, 0x158, 0x15c, 0x160, 0x164, 0x168, 0x16c, 0x170, 0x174, 0x178, 0x17c, 0x180, 0x184, 0x188, 0x18c, 0x190; the final three retail words are beyond the candidate object.
// COP1 accumulator chain reproduced from plain C: all 25 retail accumulator-chain operations (mula.s/madda.s/madd.s/msub.s/adda.s) were emitted naturally. The residual is ordinary FPR colouring/load scheduling and a shorter 404-byte object, not a COP1 expressiveness floor.
// Ruled out: volatile (banned); scalar saved-value and saved-array forms without a late pointer; pointer-at-entry versus late pointer variants; tested local declaration/assignment order permutations; natural accumulator parenthesization variants; allowed pragma probes (opt_propagation, opt_common_subs, opt_loop_invariants, schedule, optimization_level), with no retained pragma.
void func_00480f20(void* param_1, void* param_2)
{
    PrimInterpData* out = (PrimInterpData*)param_1;
    const PrimInterpData* in = (const PrimInterpData*)param_2;
    f32 saved[4];
    f32 *savedp;
    f32 inY;
    f32 inX;
    f32 inZ;
    f32 inW;
    f32 norm;
    f32 inverse;

    saved[0] = out->quat.x;
    saved[1] = out->quat.y;
    saved[2] = out->quat.z;
    saved[3] = out->quat.w;
    inY = in->quat.y;
    inX = in->quat.x;
    inZ = in->quat.z;
    inW = in->quat.w;
    norm = inY * inY;
    norm += inX * inX;
    norm += inZ * inZ;
    norm += inW * inW;
    if (norm > 0.0f)
    {
        inverse = 1.0f / norm;
        inW = inW * inverse;
        inverse = -inverse;
        inX = inX * inverse;
        inY = inY * inverse;
        inZ = inZ * inverse;
    }
    savedp = saved;
    out->quat.w = inW * savedp[3] -
                  (inY * savedp[1] + inX * savedp[0] + inZ * savedp[2]);
    out->quat.x = inZ * savedp[1] - inY * savedp[2];
    out->quat.y = inX * savedp[2] - inZ * savedp[0];
    out->quat.z = inY * savedp[0] - inX * savedp[1];
    out->quat.x = out->quat.x + savedp[0] * inW;
    out->quat.y = out->quat.y + savedp[1] * inW;
    out->quat.z = out->quat.z + savedp[2] * inW;
    out->quat.x = out->quat.x + inX * savedp[3];
    out->quat.y = out->quat.y + inY * savedp[3];
    out->quat.z = out->quat.z + inZ * savedp[3];
    out->values[0] -= in->values[0];
    out->values[1] -= in->values[1];
    out->values[2] -= in->values[2];
    out->values[3] -= in->values[3];
    out->values[4] -= in->values[4];
    out->values[5] -= in->values[5];
}
