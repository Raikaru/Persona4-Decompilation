# Five-sprite card controller and angle forwarding

Worktree: `build/first-party-publish-latest`, resumed after the rebase at
`c4388741f9070eaec2b37e3a3af3684886d1a581`. The owner now verifies
**33 MATCH / 2 ASM**: `00348c40` is recovered C, and the already matched
`0033fa30` explicitly forwards its real angle input. This work changes only
`src/promoted/y_CmbCardEff.c` and this note. No vendor implementation or shared
header is changed.

In the paths below, `lane` means
`build/continue-first-party-20260922/card-effect-worker2-rebase-20260922`.
The committed `00347c70` closure and every earlier probe destination remain
intact. The rebased starting owner is SHA-256
`6ea52ff1837e235c2464843b49dfc0c4200cd4f438021feaf0c97c4b09003bb5`.

## Five-sprite recovery

`func_00348c40` creates five sprites, assigns a mode-dependent color, and
configures their bounds animations. It transitions its own phase to one,
then returns -1 only when the fifth sprite's work reports completion.

The saved `348c40-tail-unsigned-index` candidate had 44 differing register
words at 1,560 / 1,568 bytes. The constructor results already used real
independent four-byte color objects, and the old padding member was gone.
The missing mechanism was the lifetime of the repeated color computation.
`cmbFiveSpriteColor` now performs that computation as a genuine inline
value constructor. Its three clamped channels and base value live within
the helper, independently of the controller's handle and loop temporaries.
The two call sites retain their distinct `(index + 2) * 10` and
`(index + 1) * 10` inputs. This closes all 44 register words without added
state, stores, barriers or ordinary assembly.

The setup object names all eleven bounds packets and twelve position
records by their actual roles. Three color outputs remain separate local
objects; no unused member forces their stack offsets. The flags and depth
setters now use their actual pointer and unsigned-word contracts from
`src/promoted/y_draw.c`. Both setter calls reload the stored handle after
the color callback. The signed-byte state comparison and branch return
retain retail behavior for all other phase values.

## Actual missing argument

`func_0033fa30` is called twice by the card controller. At `0033e938`, retail
passes zero in `$f12`; at `0033f028`, it passes the current animation angle.
The helper does not alter `$f12` before its call to `func_003dc740` at
`0033fa6c`. Its C definition omitted that float parameter, and its local
quaternion declaration omitted the angle entirely. The old native match
depended on an incidental live register across a C call with missing input.

The definition now accepts `f32 angle` and explicitly forwards it. The
private quaternion declaration agrees with the existing contract in
`include/rw/sky2/rtquat.h`: quaternion destination, constant axis pointer,
float angle, and integer combine mode, returning the destination pointer.
The owner uses the real `RtQuat` and `RwV3d` tags as opaque interface types.
Its other quaternion call in the guarded controller uses the same order.
Both actual first-party C caller sites already pass all three helper inputs;
the repository search found no additional authoritative C callers.

The angle repair does not add a function to the MATCH count; the
five-sprite controller supplies the one new recovery.

## Native proof and object provenance

The configured compiler is native MWCC PS2 b210, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`, using
`-O2 -Iinclude` and the actual full owner context. The eight inherited
header hashes agree with the committed `00347c70` receipt.

`lane/33fa30-explicit-angle-contract` is the first exact fixture:
**224 / 224 bytes, all seven relocations resolved, no owned data, and no
suffix**. All 34 siblings and all allocated data remain unchanged.

`lane/348c40-real-color-helper` is the first exact sprite fixture.
`lane/sprite-closure-v2/native` independently compiles the final, named
combined owner. Its source SHA-256 is
`5503b212a643c38ea2e39579006650885dc384bf237c95eb17b218b68f4dcc02`;
its object SHA-256 is
`543e29ba8393f28f89ddc877746ff15126701717827fa8c81e89fcacc60f8bd9`.

`sprite-closure-v2/native/full-proof.json` proves the new 1,560-byte sprite
body and its eight retail zero alignment bytes with complete relocation
resolution. All 34 sibling function bodies, canonical relocations and all
allocated data agree with the rebased baseline. Additional independent
retail proofs cover `0033fa30`, `00347c70`, constructor `00349290` and the
unchanged assembly caller `0033e810`. The assembly caller is identified as
ASM throughout; its byte proof is not a new C recovery. `00347c70` still
emits 1,204 bytes followed by 12 zero bytes, with all 14 relocations correct.

The earlier angle-only experiment is retained in `lane/angle-closure` and
was not integrated separately. Its function/data preservation check was
successful; an overly broad whole-ELF equality assertion caught the
anonymous string-table name `@940` changing to `@941`. Its completed object
was inspected without a compiler retry. The accepted combined source uses
explicit UTF-8 reads and preserves all unrelated owner text.

## Controlled provider validation

`lane/angle-host-validation` executes the actual recovered helper body
against typed, controlled providers using native Clang 21.1.7 at both
`-O0` and `-O2`. Each run passes **288 cases**: six angles including signed
zero, four valid card indices, three scales, both phase branches, and
unchanged or replaced nested child pointers during the position callback.

The checks require the exact angle bits, axis, combine mode, callback order,
position and scale arguments, quaternion result bytes, and the post-callback
reload of the child work pointer. The old source fails the strict typed
control for both the missing quaternion argument and incompatible helper
function-pointer type.

The host has eight-byte pointers; console integer widths remain fixed and
the host fixture places pointer fields at valid host alignment. Existing
raw representation accesses retain `-fno-strict-aliasing`. These are
controlled contract tests, not PS2, graphics, scheduler, vendor implementation,
or sanitizer execution. No broader runtime claim is made.

`lane/sprite-behavior-v2` runs the exact named sprite controller and inline
helper with **four-byte pointers** using Clang's Wasm target and Node's
WebAssembly runtime. Each of `-O0` and `-O2` passes **2,554 cases**:
1,024 initialization cases across all 256 mode bytes and four callback
mutation combinations; 768 completion checks across all 256 completion
bytes; and 762 checks of every other phase byte.

An independent event/state model checks every creation, position, bounds,
color, flags, depth and animation argument in order, including the fifth
sprite's second gradient color. Controlled callbacks can change the mode
before the color branch and replace a stored handle after a color setter.
The model checks the later handle reloads, final handle slots, return value,
phase and unchanged work canaries. A deliberately incorrect green-channel
offset fails the model. The bounds prefix is not interpreted numerically;
only its initialized dimensions are checked. These tests do not execute
PS2 graphics or SDK implementations.

## Remaining guarded functions

The address, block-scope, typed-work, narrow-channel, record-lifetime and
initialization-helper experiments preceding the exact color helper remain
in their original destinations. All completed objects and their
34-sibling/data checks are retained. They are no longer an unresolved
`00348c40` frontier.

The two larger guarded drafts contained additional correctness problems.
New scratch candidates retain those discoveries without promoting a
nonmatching controller:

* `0033e810` initially read a byte at the child task's work-pointer field;
  retail dereferences that work pointer before reading its first byte.
  Its axis was also split across unrelated local objects. New candidates
  use the full axis record and correct work-pointer chain. The source
  still needs further lifetime, copy, and conditional-value analysis.
* `00345700` treated symbolic decompiler byte names as descending C array
  indices after a constructor had written four ascending bytes. Typed
  source/copy color records restore the defined four-channel values.
  The field at `slot + 0x11c` also numerically converted a float to integer;
  retail `00345e38` is a float store. The new candidates correct both.

The larger-controller measurements in `remaining.py` are explicitly
exploratory and relocation-masked while code differs. Anonymous jump tables
do not have proven placements in those candidates. They are not MATCH
evidence. Each result records the actual source/object hashes, raw
relocations, diagnostic alignment, allocated sections and all 34 unchanged
sibling functions.

## Final official verification

`lane/sprite-closure-v2/official/verify.json` reports **33 MATCH / 2 ASM**
for all 35 first-party owner functions. The actual official verifier's
freshly compiled whole object is identical to the final native object.
`source-binding.json`, `invocation.json`, and `full-proof.json` bind that
report, object and independent proofs to the integrated source.

Scoped decomp lint reports zero errors and the one inherited, documented
loop-invariant advisory for `00347c70`. The source diff check passes.
Only `0033e810` and `00345700` remain ASM. The sealed handoff records all
source, object, dependency, report and behavior-receipt hashes. No full
build, commit or push is performed by this worker.
