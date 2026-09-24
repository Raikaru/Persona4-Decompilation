# Projected ring renderer 0045fbe0

The recovered ring renderer emits exactly 1,504 native bytes in its 1,504-byte
retail window. All 31 code relocations resolve exactly, with no missing tail or
function-owned data. The compiler is the configured MWCCPS2 b210, with the
owner's normal `-O2 -Iinclude` flags and no function-local optimization override.

## Recovered operation and objects

The function first tests a center/radius sphere against the current camera's
frustum. For a visible sphere it copies an optional 64-byte orientation matrix,
or constructs the original identity matrix, then sets its translation to the
ring center. It optionally saves and installs six render states, generates
twenty points, transforms each through the orientation and camera-view matrices,
projects their coordinates and depth, and appends the first point to close a
21-vertex polyline. The original render-state restoration remains conditional.

The local objects are complete: a sphere, a matrix with eight two-word transport
rows, three three-component points, six saved states, and twenty-one 64-byte
immediate-mode vertices. The matrix copy advances eight bytes per iteration.
Colors retain the unsigned-byte-to-float conversion, including the compiler's
unsigned conversion sequence. Projection arithmetic keeps the ratio, distance,
and scaled-distance operations separate in their observed order.

The identity path deliberately retains an original defect. Retail expands
`RwMatrixSetIdentityMacro`, including a read/OR/write of the local flags without
a preceding initialization. The corresponding macro is in
`include/rw/plcore/bamatrix.h`. The recovery does not invent a zero-initialization
store or claim that this inherited operation is defined portable C behavior.

## Source changes that closed the native difference

The seven-word frontier had the correct instruction count and control flow,
but exchanged the screen-depth scale and near-clip saved floating registers.
Explicit ratio/distance values first restored the multiplication operand order.
The scalar probe then exposed the saved-float allocation order. Declaring the
real angle and projection values in the measured order reproduced the remaining
loads, projection-slope computation, and uses without register bindings,
arithmetic assembly, padding, or artificial effects.

The exact discovery still reinterpreted a caller-owned float array as a vector
structure. The final interface instead uses a complete `RwV3d`-tagged center.
Both callers in `src/promoted/code1_0046.c` now construct that same compatible
three-float object and pass its address. Their native bodies are unchanged.
The frustum-test and point-transform declarations also use the provider's
actual camera/sphere, vector/matrix, and return types, as established by
`src/renderware/core/bacamera.c` and `src/renderware/plcore/bavector.c`.
The generated accumulator priming instruction needs no explicit source-level
addition of zero; the final expression is the ordinary multiply-and-add.

## Retained evidence

Sources, native objects, compiler receipts, comparisons, and relocation proofs
are retained under `build/finish-first-party-20260922/continue-41-ring/`.
`saved-float-order` is the exact discovery. `reviewed` is the final owner source;
`center-contract-callers` contains the coordinated caller source and native
object. The owner comparison preserves all 59 other functions. The caller
comparison preserves all 58 functions, including both modified source callers.
Allocated data is unchanged in both files.

The fully resolved target SHA-256 is
`26a5381f032e4f58a1854fd36ecbc502b432dfb7d821488233d9a44f2e0bf7ea`.
Installed-source, full-build, and publication results are separate receipts
under `build/finish-first-party-20260922/continue-42-integration/`.
