# Typed community origin initialization

Four production assignments now initialize the menu origin as f32 positive zero: X/Y in creator 00356250 and X/Y in controller 0035E8B0's initialization case. No signature, layout, control flow, callback, allocation, shared declaration or guarded source changes. The standalone source delta has no dependency on the rank24 guarded work or the rectangle/palette changes in this checkout's ancestry.

## Actual producer and reader evidence

Matched renderer 00356A10's actual context view declares a Vec2f origin at +4, and its actual expressions read `menu->origin.x` and `menu->origin.y`. Retail uses LWC1 at 00356A64/+4 and 00356A68/+8. Rank24 has the same two-component view, but the repair and its portable tests depend only on the existing matched renderer.

The creator's retail stores are SW zero at 00356278/+4 and 0035627C/+8. The controller performs the same stores at 0035E904 and 0035E908 before calling that creator. The C now describes positive-zero float initialization rather than installing an integer effective type at the subsequently read float fields. On a declared menu-origin object, the new f32 lvalues refer to its genuine components. On valid aligned allocated menu storage, they establish the corresponding float field types. Alignment and access width remain four bytes.

The other initializer at 0035F0C0 writes +8/+C for a different context and calls 0035C830. It is excluded. This is a bounded audit of the two actual community initialization paths and their matched reader; it is not a claim that every possible writer or broader menu object/dispatcher contract has been closed.

## Exact preservation

Both whole owner objects are byte-for-byte identical to the predecessor in production and all-guards modes, including all 80 functions, symbols, allocated data and raw relocations. 00356250 remains MATCH at 1,488 bytes and 0035E8B0 at 1,740 bytes. Verify remains 78 MATCH / two ASM. The guarded rank24 image is unchanged at 4,752 bytes / 308 minimum / 315 anchored / 525 greedy. No matching gain is claimed.

The branch-relative audit compares against 0d58b7c703fe46d4ee8fb5ccb0e311c37214b3ae. A second, self-contained production-projection audit reverses exactly the four changed statements in the current owning source and compiles both forms. It does not need any unpublished predecessor object or guarded body, and also confirms entire-object identity in both modes. The reverse projection changes no other statement or declaration.

## Focused native validation

The final two-method run passes in 1.995 seconds with zero skips. At strict-aliasing O0 and O2, 32,768 scenarios compile the four exact changed store statements and the matched renderer's exact origin-read statements against a genuine declared prefix containing the actual Vec2f type. Cases cover every opacity byte, eight prior representations for each component, and both initializer paths. Prior component patterns include ordinary values, both zero signs, subnormal and NaN-like bits. Those prior patterns are byte-copied and overwritten, never numerically read before initialization. The complete prefix representation and surrounding canaries must equal the expected positive-zero update; readback must contain exactly zero bits.

Five independent controls omit either creator component, store negative zero, change the controller's X value, or duplicate its X store instead of clearing Y. Every control must fail by CHECK exit exactly 1 with empty stderr at both levels; the byte check runs before any failed-control float read. This tests the changed statements and genuine field types. It deliberately does not execute the unrelated full constructor/controller paths or claim a complete strict-type menu model. Old integer-store expressions are not executed as a purported strict-aliasing proof. The complete owning functions are separately bound by exact EE object/retail verification.

The test module is self-contained apart from existing native32_support, recovery_quality and the published shd_misc_internal.h/Vec2f declaration. It does not import a rectangle test, unpublished header, or rank24 guarded source. The initial scratch fixture also read back through rank24's expressions, but the final portable fixture relies only on the matched production reader; final output is native-origin-final.log.

## Replay and production projection

Source /workspace/shared/p4-toolchain/env.sh and run from the repository root:

    python docs/probe_archive/Community_origin_initialization_20261002/audit_projection.py
    python docs/probe_archive/Community_origin_initialization_20261002/producer_reader_evidence.py
    python /workspace/shared/run_p4_qemu32_tests.py "$PWD" test_community_origin_initialization
    python tools/verify.py src/promoted/code1_0035.c

The projection audit writes to build/community/origin-projection. The optional lineage-specific audit.py writes to build/community/origin and reproduces the guarded metric reported above. A production-only integration can apply the four source replacements, this independent test and proof; no guard or unrelated prerequisite is needed. Main-tree source review, full build/C-membership and both retail hash gates remain the parent's integration work. This lane did not push or publish.

Source lint has zero errors; inherited unrelated pragma/signature advisories remain in lint.log. The existing private menu and SDK callback/dispatcher qualifications continue to apply outside these four initialization expressions.
