# Field rotation axis contract, 2026-10-05

`func_00168de0` now declares its real axis argument as `const void *` and
its task argument as `u8 *`. The provider forwards the axis to the existing
model-matrix rotation interface. Its callers use that same contract, with
the constant axis referenced through `D_00756510` instead of an integer
literal. No shared header, symbol map or toolchain configuration changes.

The installed five owners retain **197 MATCH / 8 ASM** across 205 functions.
This contract repair earns **zero new C matches**. Further private AI
reconstructions are not part of this change.

## Contract and call coverage

The provider receives the task in `a0`, the XYZ axis pointer in `a1`, and
the angle in `f12`. It reads the task's current position, translates the
model to the origin, forwards the axis and angle to `func_0047a1a0`, and
translates back. The axis is not modified. The existing
`include/model_matrix_internal.h` already describes the downstream axis
as a pointer.

The receipt enumerates **14 direct retail call sites plus one provider
forward**, all checked against the pinned retail image. The direct calls
are distributed across `k_fldUnit.c` (three), `k_fldEvent.c` (one),
`code1_0018.c` (two) and `k_fldAI.c` (eight). They pass either the global
XYZ axis or a complete local vector.

The primary AI guard had no parameter prototype. Its call therefore
converted its float angle to double before the call. The explicit contract
removes that incorrect promotion and supplies the required float argument.
That guard's other known reconstruction defects remain guarded.

## Actual-owner native proof

The configured compiler rebuilt every installed default owner and each
complete owner with `NON_MATCHING` enabled. Both sets of actual objects
equal the pre-install proof objects. Every default function retains its
original raw code and relocation records. All default code relocations
were then resolved explicitly, including compiler-local references to
independently checked data objects.

| Owner | MATCH / ASM | Functions | Code relocations | Owned data bytes | Data relocations |
| --- | ---: | ---: | ---: | ---: | ---: |
| `src/promoted/code1_0016.c` | 62 / 2 | 64 | 735 | 56 | 14 |
| `src/promoted/k_fldUnit.c` | 41 / 1 | 42 | 682 | 20 | 0 |
| `src/promoted/k_fldEvent.c` | 25 / 1 | 26 | 707 | 0 | 0 |
| `src/promoted/code1_0018.c` | 60 / 2 | 62 | 918 | 54 | 6 |
| `src/Kosaka/Field/k_fldAI.c` | 9 / 2 | 11 | 465 | 0 | 0 |
| **Total** | **197 / 8** | **205** | **3507** | **130** | **20** |

All 11 allocated non-code objects have independently anchored addresses
and exact retail payloads after resolving their 20 pointer relocations.
The proof neither claims foreign gaps nor infers unanchored objects from
neighbouring addresses. All allocated data is also unchanged between the
before/after default and guarded builds.

The provider itself emits 212 code bytes in its 224-byte retail window,
with twelve zero tail bytes and four resolved code relocations. Its code
is unchanged by the pointer correction.

Three guarded functions change:

* `func_0018a200`: four changed instructions, comprising two integer
  LUI/ORI address pairs replaced by the real relocatable LUI/ADDIU pointer
  pairs. The function remains 6564 bytes.
* `func_0017f490`: fourteen changed instructions, comprising seven such
  address pairs. The function remains 11784 bytes.
* `func_0017d3c0`: the incorrect float-to-double helper call and argument
  sequence disappear. The guarded function changes from 5168 to 5156
  bytes; the sixteen aligned changes include resulting branch
  displacement updates. It remains an assembly fallback.

The complete guarded provider, unit and event owners remain unchanged.
The receipt retains every changed guarded instruction and relocation,
rather than treating unchanged size as sufficient evidence.

Scoped lint reports zero errors and 72 warnings: 57 existing declaration
disagreements, 14 measured optimization-pragma findings, and one existing
volatile-use finding. No remaining warning concerns `func_00168de0`.
The scoped whitespace check passes.

## Published rain recovery bridge

The rain owner advances from source SHA256
`2dbf202c8a55048f4b4e6b7774c5e3f7721f85c6465747a6ee2b1f7fc1fe2cb8`
to
`83489c0664b8eeb15a5b46605295d1ac54108d468ba0cf3623a41a10c46e4eaf`.
The `func_00182bc0` source region is unchanged. Its default and guarded
native body and relocations, every other default function, and all owned
data are unchanged. The receipt records the full default object identity
and the rain source-region hash on both sides, linking this declaration
change to `Rain_00182bc0_20261005_receipt.json` without modifying that
historical receipt.

## Replaying the proof

The portable receipt, checker and replay script are
`Field_axis_contract_20261005_receipt.json`,
`Field_axis_contract_20261005_proof.py` and
`Field_axis_contract_20261005_replay.py`, alongside this note.

From the repository root, with the configured native compiler available:

```text
build/venv/Scripts/python.exe docs/probe_archive/Field_axis_contract_20261005_replay.py --hashes-only
build/venv/Scripts/python.exe docs/probe_archive/Field_axis_contract_20261005_replay.py
```

The replay authenticates current source/header/tool inputs, compiles the
five actual owners in default and guarded modes, resolves all default
code and owned data, and checks their recorded objects. It writes only
its selected scratch output directory; it does not install source or run
a full-tree build. Historical scratch objects and the detailed experiment
chain remain under `build/resume-field-worker12/axis-contract/`.
