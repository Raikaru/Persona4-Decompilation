# Message selection recovery on the current public baseline

Base: `354c1add` (the public 6,754/6,861 first-party checkpoint).
The target remains `NON_MATCHING`, with its original assembly fallback.
No new exact-function credit is claimed.

## Fresh measurements

Configured MWCCPS2 3.0.1 b210, whole `itfMsgProcedure_Window.c` owner,
existing `opt_loop_invariants on`:

| Source | Object / window | Aligned edits | Masked differing words |
| --- | ---: | ---: | ---: |
| Unmodified baseline | 8,520 / 8,624 | 769 | 1,940 |
| Selection, forwarding and live-counter repair | 8,596 / 8,624 | 648 | 1,938 |
| Inlined resource helper and direct switch exit | 8,556 / 8,624 | 590 | 668 |

The final alignment additionally has 159 relocation-only replacements. Its
frame remains 0x2F0 rather than retail's 0x300. The 0x300-frame literal shapes
from the archived September 30 research were not copied in as a match.

This reconstructs the earlier selection/handle findings on the current
published rectangle packet API; it does not reintroduce the old incompatible
`const void *` primitive declarations. New work recovers the resource helper's
join and actual eight-byte storage, its task-pointer lookup result, and adds
48 pending/ready/task-creation scenarios and three negative controls.

## Evidence and observable behavior

- Retail `002811F4` loads GP-0x5880 (0x763870), bytes `ff a1 07 cc`;
  `002812B4` loads GP-0x587C (0x763874), bytes `42 3c 2b ff`. Both are
  packed color transports, not converted texture-handle values. These
  addresses and contents were read afresh from the hash-validated retail ELF.
- The background at 0x63C130 is `{40,135,540,202}`; the selection template
  at 0x63C140 is `{0,0,350,28}`. Retail changes the first two signed words
  to 56 and the computed row position, copies all four words, then passes
  that modified snapshot. The draft had changed the last word and passed
  a different, unchanged object.
- `0027FB5C` reloads the live halfword frame counter after a renderer call;
  `00280428` reloads it before completion. Keeping the pre-call value missed
  provider-visible mutations. No volatile qualification is needed.
- Case 7 uses ascending modes 0/1/2, each scanning the same eight 24-byte
  records for the first clear in-use bit. The existing sibling's inlined
  first-free helper expresses the retail pointer lifetime and early return.
- Resource lookup at `0027F7FC` and its phase-5 counterpart uses an inlined
  helper: found and state >=2 returns its word at +4; missing triggers the
  second lookup, then an exact eight-byte clear and task creation. Retail
  `0027F844..0027F888` proves the clear, priority 15, callbacks and zero
  delay/free-delay/work arguments. A zero returned resource branches directly
  to the switch epilogue. Both paths now preserve that join without a fake
  return value, padding or allocation barrier.
- `MsgProcWindowResource` owns state +0, flags +2 and sprite word +4. Its
  producers use the same eight-byte type. The independent 12-byte calendar
  work record is unchanged. Task lookup now has its actual byte-pointer
  return and signed-character name declaration from `sdkTask.c`.
- The real manager indexes 32-byte entries by a signed handle. The flags
  getter consumes this handle, and the visibility predicate forwards it.
  All five Window procedure entries now forward their actual handle.
- Selected row is a signed halfword at message+0x4A; choice count is one
  at +0x4E. Public return values are sign-extended 32-bit integers. The
  shared header reconciles every authoritative consumer of these four APIs,
  preserving caller bytecode instead of narrowing the public return ABI.

## Validation

Fresh focused verification: **273 MATCH / five ASM across 278 functions**
in the six affected production owners, with no status or size regressions.
All allocated production sections, padding and canonical relocation bindings
are unchanged. In both fully guarded Window owners all 20 non-target function
bodies and complete sections remain unchanged; only the target's code and its
19-entry switch table change. The complete guarded `code1_002b.c` object also
preserves every allocated section and relocation binding.

At O0 and O2 under the approved QEMU i386 adapter, with the original native32
compiler/sanitizer flags and no body rewrites:

- 224 window scenarios: selection rectangles/colors, enabled/disabled paths,
  selected rows/counts, first-free/full-table/unsupported scan modes, live
  frame-counter mutations, and all 48 phase-4/5 resource cases
- 864 actual manager/visibility scenarios: handles, flags and signed-halfword
  boundaries, using the real provider and forwarding bodies
- Ten negative mutations rejected at both levels: wrong color, wrong
  rectangle coordinate, unmodified rectangle, lost width, stale frame,
  pending resource use, missing second lookup, wrong task priority, wrong
  forwarded handle and wrong selected-row offset
- Existing message-forwarding and rectangle-payload suites also pass;
  **28 tests total, no skips**

The fixtures stub rendering, trigonometry and task lookup/creation explicitly;
they do not execute PS2 graphics or the full task scheduler. The manager
fixture tests zero/negative stored counts, but the selection renderer itself
is only exercised with positive counts. Phase-9/12 zero-choice conversion is
still an unresolved domain issue. Other inherited font/flags ABI advisories
are not represented as repaired. Scoped lint has zero errors and 107 retained
warnings; `git diff --check` passes.

## Full verification and linkage

Full verification passes all 13,102 markers: 9,574 MATCH / 3,528 ASM;
first-party remains 6,754 MATCH / 107 ASM. Full retail linkage passes with
604 source C owners and 54 Sony SDK objects. All six changed owners remain
C-linked, and the complete linked-function membership is identical to the
baseline report.

- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`

The initial scratch link lacked the generated `undefined_*_auto.txt` inputs.
Restoring those verified baseline-generated files restored 604-owner eligibility;
no source, linker rule or link-floor relaxation was used to pass the gate.

## Reproduction

```sh
python tools/verify.py --json build/message-selection-verify.json \
  src/promoted/itfMsgProcedure_Window.c src/itfMesManager.c \
  src/promoted/code1_0027.c src/promoted/code1_002b.c \
  src/nmCmdList.c src/Event/Fcl/fclMisc.c
python tools/measure_guarded.py src/promoted/itfMsgProcedure_Window.c \
  func_0027f6f0 --save-candidate build/message-selection-body.c
python tools/fnalign.py src/promoted/itfMsgProcedure_Window.c func_0027f6f0 \
  --candidate build/message-selection-body.c --quiet
python -m unittest discover -s tests -p 'test_message_window_selection_contract.py'
python -m unittest discover -s tests -p 'test_message_handle_contract.py'
python -m unittest discover -s tests -p 'test_message_procedure_forwarding_contract.py'
python -m unittest discover -s tests -p 'test_rectangle_payload_contract.py'
```

Where direct i386 execution is unavailable, use the approved runner adapter;
a skipped fixture is not runtime evidence. Source-only delivery excludes the
retail executable, generated assembly, proprietary compiler and native objects.

The isolated source checkpoint uses the assistant identity `dot <dot@localhost>`
via per-command Git options. It does not change repository/global identity and
was not pushed.
