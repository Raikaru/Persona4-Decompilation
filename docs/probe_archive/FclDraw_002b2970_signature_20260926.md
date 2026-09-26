# Real signature of the position constructor 002b2970

Question: which single declaration of `func_002b2970` reproduces every
retail caller? Earlier attempts each lost a set of matched callers:

- Out-pointer everywhere lost 15 nested callers
  (`FclDraw_002b2970_outpointer_20260926.md`).
- Struct return everywhere (`wip/002b2970-struct-return`, ddca243) lost 14
  callers that pass a member or element address.

**Verdict: the signature is the C struct return
`FclVec2 func_002b2970(f32 x, f32 y)`.** The 14 address callers were
artefacts of how their drafts were written: synthetic stack-layout
structs, s64 locals, and pointer-taking helpers. Each one matches under the
struct-return signature once its destination is written naturally. That
means a whole `FclVec2` local, an argument nested in another call, or an
argument to a by-value inline helper. H1 (a C++ class constructor) is ruled
out: no constructor form reproduces the callee, and C++ callers copy where
retail does not.

Measured with b210 `-O2 -Iinclude` through wibo, and `tools/verify.py`
on whole files. The combined probe is
`FclDraw_002b2970_signature_20260926.patch` (applies to 83428c1). It
uses block-scope declarations, so it is evidence only and is not meant to
land as it stands (see "Landing").

## H1: C++ constructor, ruled out

Retail callee (0x2b2970):

    addiu sp,-0x10 ; swc1 f12,8(sp) ; swc1 f13,12(sp)
    lwc1 f1,8(sp)  ; lwc1 f0,12(sp)
    swc1 f1,0(a0)  ; swc1 f0,4(a0) ; addiu sp,0x10 ; jr ra   ($v0 untouched)

| source (compiled as .cpp) | emitted body |
|---|---|
| `FclVec2::FclVec2(f32,f32)`, with the body or with an init list | `swc1 f12,0(a0); swc1 f13,4(a0); move v0,a0; jr` |
| constructor via a temp and `*this = t` | same (the temp folds), `move v0,a0` |
| static factory or free function on a class that has a constructor | named return value optimisation: `swc1 f12,0(a0); swc1 f13,4(a0); jr`, with no stack round trip |
| free function on a POD typedef struct, in C++ | **identical to retail**, but this is plain struct return (H2's ABI), not a constructor |
| C: `FclVec2 f(f32 x, f32 y){FclVec2 v; v.x=x; v.y=y; return v;}` | **identical to retail** |

Every constructor sets `$v0 = this` and stores straight through `$a0`, so
none can produce retail's stack round trip.

The callers rule it out too. In C++ even a whole local is filled through a
temporary, with an `lwc1/swc1` copy. In C a whole local receives the
return directly, and retail does receive directly (for example 00324410
`addiu a0,sp,0x60` then `ld a2,0x60(sp)`).

## H2: C struct return, all 14 address callers MATCH

How b210 places a struct return:

- A whole local of the struct type, a union whose first member is the
  struct, or a global object at offset 0: the call writes straight into
  it.
- A struct member at a nonzero offset, an array element, or a store
  through a pointer: the call writes a fresh temporary, then copies it with
  `lwc1/swc1`.
- A struct passed by value to a call, or to an inline function's
  parameter: the call writes a fresh temporary. An 8-byte struct is loaded
  with `ld`. A 16- or 12-byte struct is passed by address, `addiu aN,sp,tmp`.
  An inline parameter is then copied into its own stack slot.

The "work" and "setup" structs in the old drafts reproduce that last
layout by hand: temporaries, followed by copies into inline parameters.

| unit | function | rewrite | result |
|---|---|---|---|
| y_fclCombineDraw | 00324410 | s64 sp60/58/50 become `FclVec2` locals, `x = f(..)`; 69f0 is called with `FclVec2` arguments | MATCH |
| y_fclCombineDraw | 0032f4d0 | named `FclVec2` locals, `x = f(..)`, and `FclVec2 tbl[5]` plus a sixth local `sp78` (see below) | MATCH |
| y_fclCombineDraw | 003218a0 | return type `FclVec2`, not `FclDrawPosition`; 83e0 takes `FclVec2` | MATCH |
| y_fclCombine | 0030b060 | 4 locals become `FclVec2`, `x = f(..)`; 324f80 is declared as its definition `(u8*, FclVec2, s32, s8)` | MATCH |
| y_fclCombine | 0030f650 | 10 union or s64 locals become `FclVec2` | MATCH |
| y_fclCombine | 002ed430 | 26 s64 locals become `FclPackedPosition`, `x.position = f(..)`, passing `x.bits` to the s64-declared consumers | MATCH |
| y_fclCombine | 00302770 | 38 s64 locals, handled the same way as 002ed430 | MATCH |
| y_draw | 002b83e0 | `positions` struct removed; the inline `fclStartPosition` takes `f2` by value; `fclStartPosition(arg0, func_002b2970(..), p1.position, ..)` | MATCH |
| y_CmbCardEff | 0033fc80 | `work` removed. By-value inline helpers `cmbSetMove`, `cmbSetColor` and `cmbAddPath`, with the 2970/2a60 calls nested in their arguments; 29a0 returns `CmbVec3f`; 3489c0 takes `CmbVec3f` by value | MATCH |
| y_CmbCardEff | 003407f0 | same helpers, applied mechanically | MATCH |
| y_CmbCardEff | 00341640 | same | MATCH |
| y_CmbCardEff | 003427a0 | same | MATCH |
| y_CmbCardEff | 00343cf0 | same | MATCH |
| y_CmbCardEff | 00348c40 | `setup` removed. 29e0 returns `FclBoundsPacket`; 5c90, 5db0 and 5fd0 get `func_002b2970(..)` and `func_002b29e0(..)` nested in their arguments, with the bounds passed by value | MATCH |

No other function in the four files regressed:

| unit | before | after |
|---|---|---|
| y_fclCombineDraw | 63 MATCH, 7 ASM | 63 MATCH, 7 ASM |
| y_fclCombine | 35 MATCH, 6 ASM | 35 MATCH, 6 ASM |
| y_draw | 55 MATCH, 3 ASM | 55 MATCH, 3 ASM |
| y_CmbCardEff | 33 MATCH, 2 ASM | 33 MATCH, 2 ASM |

The 15 nested callers from the out-pointer note already match with struct
return. y_fclShopDraw and y_fclCombineDraw call it that way at HEAD.

Notes from the individual rewrites:

- **0032f4d0.** Retail places the sixth temporary at `&tbl[5]` (tbl at
  0x50, temporary at 0x78). The array is `FclVec2 tbl[5]` and the sixth
  store `tbl[slot] = sp78` runs one element past the end, onto `sp78`
  itself. This is an original off-by-one that is harmless. `tbl[6]` gives
  41 differing words (the frame layout moves).
- **002b83e0.** With named start and end locals, the temporary copies
  vanish and the function comes out 68 bytes short (837 differing words).
  Passing the argument by value to the inline is required.
- **002b83e0 with `FclVec2 p1`.** Declaring `p1` as a plain `FclVec2`
  instead of the `FclDrawPosition` union also MATCHes, with the header
  prototype changed to match.
- **0033fc80.** Converting only the positions left 137 differing words,
  and these were stack offsets only. Also routing the colours through the
  by-value `cmbSetColor` left 46, which were the position slots shifted by
  8 because the Vec3 was a named local. Making 29a0 a struct return nested
  in 3489c0 gave MATCH.
- **cmbAddPath.** The helper must address `slot + idx*0x84 + off` from the
  unshifted base. Pre-shifting `p += idx*0x84` gives 1016 differing words
  on 0033fc80.
- **Callees that take the bounds and Vec3 by value.** Checked in their
  own units: y_draw 002b5db0, 002b5ef0 and 002b5fd0 with
  `FclBoundsPacket` by value still MATCH, and so does y_CmbCardEff
  003489c0 with `CmbVec3f` by value. All 11 other 3489c0 call sites in
  that file are unchanged.
- **Sibling constructors.** Plain C struct-return definitions of
  002b29e0 (`FclBoundsPacket`, where the eight "residue" bytes are just
  the uninitialised part of the struct) and 002b29a0 (Vec3) reproduce
  retail exactly.

## Landing (recommended path)

Adopt `FclVec2 func_002b2970(f32 x, f32 y);` as the one declaration in
`fcl_draw_types.h`, with the C definition above in code1_002b. Treat the
sibling constructors the same way:

- `FclBoundsPacket func_002b29e0(f32, f32)`
- `CmbVec3f func_002b29a0(f32, f32, f32)`
- 5db0, 5ef0 and 5fd0 take `FclBoundsPacket` by value
- 3489c0 takes `CmbVec3f` by value

Then rewrite every pointer-form caller as in the patch: whole locals, or
calls nested in by-value arguments. Delete the synthetic layout structs
(`CmbFc80Work`, `Cmb407Work`, `CmbFiveSpriteSetup` and `positions`), and
add the three `y_CmbCardEff` inline helpers once at file scope.

The probe still declares these at block scope, which disagrees with the
current file-scope and header prototypes. The landing change must make all
of them agree.

Open follow-ups:

- **002ed430 and 00302770** still pass `x.bits` because their consumers
  are declared with s64 (0031e5b0, 0031fa20, 0032c660, 003191c0, 0033e540,
  and others). The natural end state is `FclVec2` parameters on those
  consumers, as for 69f0 and 324f80. That was not measured.
- **Remaining pointer-form callers** in code1_002b, code1_002e, y_smap and
  y_fclItemShopDraw were not in the 14. Branch ddca243 regressed only the
  14, so these already held under struct return there. They were not
  re-measured here, so re-verify them when landing.
