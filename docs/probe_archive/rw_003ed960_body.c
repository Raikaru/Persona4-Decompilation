/* _rwFrameSyncHierarchyLTM / FUN_003ED960: not installed, still ASM.
 * Measured in src/renderware/core/basync.c with MWCCPS2 b119 -O4,p,
 * -inline auto and a schedule-on bracket around the target: 248-byte C
 * object / 256-byte retail window, two differing instruction words at
 * +0xc0 and +0xd0 (the final byte load and store select 3($s3) / 0($s0)
 * in the opposite order from retail). The omitted eight bytes are zero
 * alignment. The pointer local below corrects the earlier $s0/$s1 swap.
 * No marker or body from this archive is installed in production source;
 * src/rw/basync.c retains the sole FUN_003ED960 INCLUDE_ASM fallback.
 *
 * Reproduce by replacing the existing FrameSyncHierarchyLTMRecurse body in
 * src/renderware/core/basync.c with the first function below, bracketing
 * _rwFrameSyncHierarchyLTM with schedule on/off, and adding its FUN marker
 * only in an isolated probe. Never leave two owners in the source tree.
 *
 * Measured rejected variants: verbatim helper + schedule on was 248/256,
 * six register-color words different; explicit unqualified privateFlags
 * pointer reduced it to two. Split oldFlags/inheritedFlags, changing the
 * integer widths, declaration and register hints, explicit object/field
 * stores, and opt_common_subs/opt_propagation brackets did not close it.
 * Reading privateFlags through a volatile pointer reduced the score to
 * zero, but ordinary-memory volatile used for compiler steering is forbidden
 * by docs/matching.md and MUST NOT be installed. Find an honest C shape.
 */

static void
FrameSyncHierarchyLTMRecurse(RwFrame * frame, RwInt32 flags)
{
    RWFUNCTION(RWSTRING("FrameSyncHierarchyLTMRecurse"));

    /* NULL is a valid termination condition */
    while (frame)
    {
        RwUInt8 *privateFlags = &((RwObject *)frame)->privateFlags;
        RwInt32 accumflags = flags | *privateFlags;

        RWASSERTISTYPE(frame, rwFRAME);

        if (accumflags & rwFRAMEPRIVATESUBTREESYNCLTM)
        {
            RwMatrixMultiply(&frame->ltm,
                             &frame->modelling,
                             &((RwFrameGetParent(frame))->ltm));
            rwObjectSetPrivateFlags(frame, rwObjectGetPrivateFlags(frame) &
                                            ~(rwFRAMEPRIVATESUBTREESYNCLTM));
        }

        FrameSyncHierarchyLTMRecurse(frame->child, accumflags);
        frame = frame->next;
    }

    RWRETURNVOID();
}

#pragma schedule on
void
_rwFrameSyncHierarchyLTM(RwFrame * frame)
{
    RwInt32 oldFlags;

    RWFUNCTION(RWSTRING("_rwFrameSyncHierarchyLTM"));
    RWASSERT(frame);
    RWASSERTISTYPE(frame, rwFRAME);
    RWASSERT(frame->root == frame);

    oldFlags = rwObjectGetPrivateFlags(frame);

    if (oldFlags & rwFRAMEPRIVATESUBTREESYNCLTM)
    {
        RwMatrixCopy(&frame->ltm, &frame->modelling);
    }

    FrameSyncHierarchyLTMRecurse(frame->child, oldFlags);

    rwObjectSetPrivateFlags(frame, oldFlags &
                                    ~(rwFRAMEPRIVATEHIERARCHYSYNCLTM |
                                      rwFRAMEPRIVATESUBTREESYNCLTM));

    RWRETURNVOID();
}
#pragma schedule off
