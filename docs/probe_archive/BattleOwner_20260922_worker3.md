# Battle owner continuation, 2026-09-22, worker-3

No functions were promoted in this probe batch. Production remains ASM. The
useful new result is `func_001b6120`: explicit geometry-loop values plus scoped
loop-invariant optimization reduce its current full-owner residual from 58 to
26 fully relocated instruction words. Its exact candidate source is retained
below, including the corrected quaternion load order. This is a measured
opening, not an assertion that the remaining source is unreachable.

## Scope and provenance

The only assigned production owner was `src/promoted/code1_001b.c`; it was not
edited in this batch. Its source SHA-256 remains
`02a3d51234b8653236a8475e8c613e32b57ca7a6be94279c35fcde945e1da51d`. The full owner and five included headers were
authenticated by the completed audit. No shared header, vendor/SDK implementation,
commit, push or full build was involved.

Native compiler: `D:/mwcps2-3.0.1b210-060308/mwccps2.exe`; SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`; configured flags `-O2 -Iinclude`. Every probe
compiled the complete current owner. Allocated data and all 122 sibling functions'
raw bytes and canonical relocations were rechecked after each successful probe.

Root for all new receipts:
`build/continue-first-party-20260922/action-transition-worker3/`.
The read-only artifact audit is `audit-20260922-worker3/AUDIT.json`; the compact
45-probe index is `audit-20260922-worker3/AUDIT.md`. The audit independently
reimplemented relocation for the primary action candidate and the best camera
candidate, reproducing all 9 and 100 relocations respectively without masking
instruction bits. Neither target references an owned allocated section; all
allocated owner data was separately unchanged. The one failed C89 record probe
retains its compile log and was corrected in a fresh destination.

## Action transition: func_001b05d0

Before testing, all 48 completed results in
`build/first-party-next-20260922/action-transition/` were inspected, along with
`action_transition.py` and the earlier three typed-record receipts in
`build/continuation-20260921/battle-worker6/001b05d0/`. No completed script or
probe destination was rerun or overwritten.

All 22 new probes in `probes/` retain 36 differing words, 492 emitted bytes in
the 496-byte retail window, nine fully resolved relocations, 122 unchanged
siblings and unchanged allocated data. New mechanisms were an output-reference
lookup; real table-pointer reuse in status case 1; flag-to-table and
table-to-entry-flag value lifetimes; a separate reserve-entry temporary;
field-address/staged-value/helper consumption of the selected-entry flags;
explicit register priority; propagation disabled for the true selector/address
phases; and lifetime/scalarization controls applied to those phases.

The remaining differences are still search base/result/entry register choices.
The null initialization, both search bounds, first-table reload through
`func_001bf3a0_add`, all real calls and case-1 reload semantics were retained.
Representative independent receipt:
`probes/output-reference-result-last/result.json`, with the independent audit in
the `independent_targets` member of `AUDIT.json`. This batch does not establish
anything about a future callback-transport or authentic declaration correction.

## Camera setup: func_001b6120

| Candidate | Words | Bytes / window |
| --- | ---: | ---: |
| `camera-setup/current-owner-baseline` | 58 | 1968 / 1968 |
| `camera-setup/explicit-geometry-loop-values` | 53 | 1968 / 1968 |
| `camera-setup/explicit-loop-values-invariant` | 26 | 1968 / 1968 |
| `camera-setup/quaternion-y-first-load` | 26 | 1968 / 1968 |

The loop mechanism names its real UV scale and white color before entering the
89-vertex loop, initializes the real loop index before its two tables, and
enables scoped `opt_loop_invariants`. The geometry loop, including every constant,
address calculation, load/store and branch, is now exact. Loading quaternion Y
before X also matches retail. Its word score remains 26 because those loads
also contain the still-different base register.

The residual is the shared camera-base/matrix-destination register rotation,
the second four-float snapshot's load/store order, and the final four-byte palette
snapshot's load/store order. Matrix and quaternion arithmetic already match.
Current tested native-address lifetimes, actual pointer reuse, record snapshots,
matrix/vector inline-copy boundaries, promoted palette values and reuse of real
vector temporaries do not close that residual. Whole-function propagation-off
with the loop values is worse at 365 words; do not substitute it for the scoped
loop-invariant mechanism.

Best full-owner source SHA-256: `30b4142d581710800d22e26fe01e2a110eaedea020630e00b5772082d7840e62`.
Best object SHA-256: `ef1ae26ab783afae507e0429ba71d1ffcd4012080cbaf51597d43d9af708264f`.
Best body SHA-256: `c312fa6f7353f7b97c5fb1cd1fc731a517f6c41bb86fc58156af92dc3ae7a5fe`.
The complete source/object/compiler receipt and word-by-word residual remain in
`camera-setup/quaternion-y-first-load/`. The fenced body below is identical to
that directory's `body.c`.

## Other inspected owner candidate

`func_001ba0e0` currently measures 176 words, 1084/1104 bytes. Its local
`func_00457130`/`func_00457140` declarations differ from the existing provider
in `src/promoted/code1_0045.c`: the getter returns `s8 *`, and the setter takes
four `s8` values. Correcting only those private declarations in a scratch owner
gives 183 words and 1116/1104 bytes. A genuine inline byte-rounding boundary does
not change either result. The provider was inspected only and remains untouched;
no candidate with an inconsistent signature was promoted. Receipts are in
`effect-blend/`.

## Completed sessions

Primary probe sessions: `15692`, `7736`, `46394`, `64006`.
Effect-blend session: `35020`.
Camera sessions: `25812`, `21952`, `18329`, `46296`, `23530`.
Artifact audit: `19814`.
All of these completed with exit 0. Individual probe failures are retained in
their own compiler receipts; `camera-setup/palette-snapshot-record/compile.log`
records the C89 declaration placement rejection. Its corrected successor is
`camera-setup/palette-snapshot-record-c89/`, measuring 30 words.

## Retained camera candidate (still NONMATCHING)

```c
#pragma push
#pragma opt_loop_invariants on
void func_001b6120(void)
{
    extern u8 *func_004571a0(void);
    extern u8 *func_004571c0(void);
    extern u8 *func_00149d20(void);
    extern void func_003dc610(void *arg0, void *arg1);
    extern void func_0043f810(void *dst, const void *src, u32 size);
    extern s32 func_00442088(char *dst, const char *fmt, ...);
    extern u8 *func_003ef650(s32 arg0, ...);
    extern s32 func_003ef6d0(void);
    extern u16 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
    extern void func_003c42b0(void *a, void *b);
    extern u8 *func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(void *a);
    extern u8 *func_003e9c10(u8 *a0, const f32 *a1, s32 a2);
    extern char D_005F7270[];
    extern u8 D_0060A140[];
    extern f32 D_0060A410[];
    extern f32 D_0060A840[];
    extern u8 iGpffffa4d8;
    extern u8 iGpffffa4d9;
    extern u8 iGpffffa4da;
    extern u8 iGpffffa4db;
    extern f32 fGpffff81f4;
    extern f32 fGpffffb458;
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    extern u_long128 D_00922C60[4];
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } Matrix;
    u8 *base;
    u8 *cam;
    u8 *vec;
    u8 *tmp;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 qw;
    f32 inv;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 t10;
    f32 t9;
    f32 t8;
    f32 t7;
    f32 t6;
    f32 t5;
    f32 t4_2;
    f32 t3_2;
    f32 t2_2;
    Matrix matrix;
    u_long128 *dst;
    u_long128 *src;
    s32 count;
    char buf[0x80];
    u8 *handle;
    u8 *work;
    u8 *p;
    u8 *dstPos;
    u8 *dstUv;
    u8 *dstCol;
    f32 *tblA;
    f32 *tblB;
    u32 i;
    f32 uvScale;
    u8 white;
    f32 pos[3];
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    cam = func_004571a0();
    base = D_0076449C;
    a = *(f32 *)(cam + 0x18);
    b = *(f32 *)(cam + 0x1C);
    c = *(f32 *)(cam + 0x20);
    d = *(f32 *)(cam + 0x24);
    *(f32 *)(base + 0x270) = a;
    *(f32 *)(base + 0x274) = b;
    *(f32 *)(base + 0x278) = c;
    *(f32 *)(base + 0x27C) = d;
    cam = func_004571c0();
    base = D_0076449C;
    a = *(f32 *)(cam + 0x18);
    b = *(f32 *)(cam + 0x1C);
    c = *(f32 *)(cam + 0x20);
    d = *(f32 *)(cam + 0x24);
    *(f32 *)(base + 0x280) = a;
    *(f32 *)(base + 0x284) = b;
    *(f32 *)(base + 0x288) = c;
    *(f32 *)(base + 0x28C) = d;
    vec = func_00149ca0();
    base = D_0076449C;
    a = *(f32 *)(vec + 0x0);
    b = *(f32 *)(vec + 0x4);
    c = *(f32 *)(vec + 0x8);
    d = *(f32 *)(vec + 0xC);
    *(f32 *)(base + 0x1BC) = a;
    *(f32 *)(base + 0x1C0) = b;
    *(f32 *)(base + 0x1C4) = c;
    *(f32 *)(base + 0x1C8) = d;
    vec = func_00149ce0();
    base = D_0076449C;
    a = *(f32 *)(vec + 0x0);
    b = *(f32 *)(vec + 0x4);
    c = *(f32 *)(vec + 0x8);
    d = *(f32 *)(vec + 0xC);
    *(f32 *)(base + 0x1CC) = a;
    *(f32 *)(base + 0x1D0) = b;
    *(f32 *)(base + 0x1D4) = c;
    *(f32 *)(base + 0x1D8) = d;
    tmp = func_00149d20();
    base = D_0076449C;
    func_003dc610(base + 0x1DC, tmp);
    base = D_0076449C;
    *(f32 *)(base + 0x24C) = fGpffff81f4 * (f32)iGpffffa4d8;
    base = D_0076449C;
    *(f32 *)(base + 0x250) = fGpffff81f4 * (f32)iGpffffa4d9;
    base = D_0076449C;
    *(f32 *)(base + 0x254) = fGpffff81f4 * (f32)iGpffffa4da;
    base = D_0076449C;
    *(f32 *)(base + 0x258) = fGpffff81f4 * (f32)iGpffffa4db;
    vec = (u8 *)func_0014acd0();
    base = D_0076449C;
    a = *(f32 *)(vec + 0x0);
    b = *(f32 *)(vec + 0x4);
    c = *(f32 *)(vec + 0x8);
    d = *(f32 *)(vec + 0xC);
    *(f32 *)(base + 0x1EC) = a;
    *(f32 *)(base + 0x1F0) = b;
    *(f32 *)(base + 0x1F4) = c;
    *(f32 *)(base + 0x1F8) = d;
    vec = (u8 *)func_0014ad10();
    base = D_0076449C;
    a = *(f32 *)(vec + 0x0);
    b = *(f32 *)(vec + 0x4);
    c = *(f32 *)(vec + 0x8);
    d = *(f32 *)(vec + 0xC);
    *(f32 *)(base + 0x1FC) = a;
    *(f32 *)(base + 0x200) = b;
    *(f32 *)(base + 0x204) = c;
    *(f32 *)(base + 0x208) = d;
    tmp = (u8 *)func_0014ad50();
    base = D_0076449C;
    func_003dc610(base + 0x20C, tmp);
    base = D_0076449C;
    func_0043f810(base + 0x21C, base + 0x1EC, 0x30);
    base = D_0076449C;
    a = *(f32 *)(base + 0x1BC);
    b = *(f32 *)(base + 0x1C0);
    c = *(f32 *)(base + 0x1C4);
    d = *(f32 *)(base + 0x1C8);
    D_00922CA0[0] = a;
    D_00922CA4[0] = b;
    D_00922CA8[0] = c;
    D_00922CAC[0] = d;
    a = *(f32 *)(base + 0x1CC);
    b = *(f32 *)(base + 0x1D0);
    c = *(f32 *)(base + 0x1D4);
    d = *(f32 *)(base + 0x1D8);
    D_00922CB0[0] = a;
    D_00922CB4[0] = b;
    D_00922CB8[0] = c;
    D_00922CBC[0] = d;
    base = D_0076449C;
    qy = *(f32 *)(base + 0x1E0);
    qx = *(f32 *)(base + 0x1DC);
    qz = *(f32 *)(base + 0x1E4);
    qw = *(f32 *)(base + 0x1E8);
    inv = 2.0f / ((qx * qx) + (qy * qy) + (qz * qz) + (qw * qw));
    sx = qx * inv;
    sy = qy * inv;
    sz = qz * inv;
    t10 = sx * qw;
    t9 = sy * qw;
    t8 = sz * qw;
    t7 = qx * sx;
    t6 = qy * sy;
    t5 = qz * sz;
    t4_2 = qy * sz;
    t3_2 = qz * sx;
    t2_2 = qx * sy;
    matrix.right.x = 1.0f - (t6 + t5);
    matrix.right.y = t2_2 + t8;
    matrix.right.z = t3_2 - t9;
    matrix.up.x = t2_2 - t8;
    matrix.up.y = 1.0f - (t5 + t7);
    matrix.up.z = t4_2 + t10;
    matrix.at.x = t3_2 + t9;
    matrix.at.y = t4_2 - t10;
    matrix.at.z = 1.0f - (t7 + t6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    src = (u_long128 *)&matrix;
    dst = D_00922C60;
    count = 4;
    do {
        u_long128 row = *src;
        src++;
        count--;
        *dst = row;
        dst++;
    } while (count > 0);
    D_00922CC0[0] = 1;
    *(f32 *)(D_0076449C + 0x25C) = fGpffff81f4 * (f32)((u8 *)&fGpffffb458)[4];
    *(f32 *)(D_0076449C + 0x260) = fGpffff81f4 * (f32)((u8 *)&fGpffffb458)[5];
    *(f32 *)(D_0076449C + 0x264) = fGpffff81f4 * (f32)((u8 *)&fGpffffb458)[6];
    *(f32 *)(D_0076449C + 0x268) = fGpffff81f4 * (f32)((u8 *)&fGpffffb458)[7];
    if (func_001ef9a0() != 0x20B) {
        func_003e8180(func_00457120(), 35.0f);
    } else {
        func_003e8180(func_00457120(), 100.0f);
    }
    base = D_0076449C;
    *(u32 *)(base + 0xC) |= 0x2000002;
    base = D_0076449C;
    func_00442088(buf, D_005F7270, *(u16 *)(base + 0x26C), *(u16 *)(base + 0x26E));
    *(u8 **)(D_0076449C + 0xE78) = func_003ef650(func_003ef6d0(), buf);
    if (*(u32 *)(D_0076449C + 0xE78) != 0) {
        *(u32 *)(D_0076449C + 0xE80) = 0;
        *(u8 **)(D_0076449C + 0xE7C) = (u8 *)func_00482f70(1, 0x76, 0x59, D_0060A140, 0x4C);
        base = D_0076449C;
        func_003c42b0(*(void **)(*(u8 **)(base + 0xE7C) + 0x14), *(void **)(base + 0xE78));
        base = D_0076449C;
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18), 0xFF2);
        base = D_0076449C;
        p = *(u8 **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18);
        dstPos = *(u8 **)(*(u8 **)(p + 0x5C) + 0x14);
        dstUv = *(u8 **)(p + 0x34);
        dstCol = *(u8 **)(p + 0x30);
        i = 0;
        tblA = D_0060A410;
        tblB = D_0060A840;
        uvScale = 8.0f;
        white = 0xFF;
        for (; i < 0x59; i++) {
            *(f32 *)(dstPos + 0) = tblA[i * 3 + 0];
            *(f32 *)(dstPos + 4) = tblA[i * 3 + 1];
            *(f32 *)(dstPos + 8) = tblA[i * 3 + 2];
            *(f32 *)(dstUv + 0) = tblB[i * 2 + 0];
            *(f32 *)(dstUv + 4) = uvScale * tblB[i * 2 + 1];
            dstCol[0] = white;
            dstCol[1] = white;
            dstCol[2] = white;
            dstCol[3] = white;
            dstPos += 0xC;
            dstUv += 8;
            dstCol += 4;
        }
        base = D_0076449C;
        work = *(u8 **)(base + 0xE7C);
        p = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
        func_003c22f0(p);
        if ((*(u16 *)work & 4) != 0) {
            *(u16 *)(p + 0xC) |= 1;
        }
        base = D_0076449C;
        handle = *(u8 **)(base + 0xE7C);
        work = *(u8 **)(handle + 0x14);
        c0 = iGpffffa4d8;
        c3 = iGpffffa4db;
        c1 = iGpffffa4d9;
        c2 = iGpffffa4da;
        *(u8 *)(work + 4) = c0;
        *(u8 *)(work + 5) = c1;
        *(u8 *)(work + 6) = c2;
        *(u8 *)(work + 7) = c3;
        pos[0] = 0.0f;
        pos[1] = 5.0f;
        pos[2] = 0.0f;
        base = D_0076449C;
        func_003e9c10(*(u8 **)(*(u8 **)(base + 0xE7C) + 0xC), pos, 0);
    }
}

#pragma pop
```
