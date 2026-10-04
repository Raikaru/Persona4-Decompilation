# Field event controller: exact candidate, 2026-10-03

## Status

The C implementation for `func_00172e00` emits **6260 executable bytes**.
An independent review resolved all **285 relocations** and confirmed an exact
retail instruction stream, followed by the genuine **12 zero alignment bytes**.
Independent source and extent review accepted the guarded checkpoint. This
append removes only the target fallback and its NONMATCHING marker. Fresh
production verification and full linked hashes are pending at this freeze;
publication is not yet approved.

The public base is `18c3a8d4c1ef76c780c68ebc1f4b110cb559ed18`. The prior guarded
recovery checkpoint is `aaf3556893547db90a5cd5da9bbf4728b80d5049`.
The retained rank14 source was reconstructed after an executor rollback; all
results below were rerun after that rollback rather than inferred from lost logs.

## Source changes

The retained 27-word candidate was closed with ordinary source representations:

- Use the resource ID's real unsigned-halfword local type
- Scope propagation and constant-pullout settings to the target while retaining
  its existing common-subexpression and loop-invariant settings
- Compute each real table index before loading its corresponding table base
- Capture the field state before reading the unit pointer in state 15
- Load the FOV at the call and convert the animation to its actual signed-halfword
  argument type before loading its blend value
- Declare the genuinely used first actor-scan index in the existing selection
  scope; its initialization and uses remain at their original points

No fake calls, dummy values, synthetic branches, padding instructions, volatile
steering, or ordinary-computation assembly were added.

### Field-file transport

The field ID is semantically an unsigned halfword. The internal file provider
accepts a word and explicitly converts it to an unsigned halfword before use.
Its shared declaration, definition, and both caller owners now agree.

Retail `0015ff34` masks the incoming first argument before every semantic use.
The only direct callers are `001562f8` (loads an unsigned halfword) and
`00173ff0` (forwards the zero-extended getter result as a word). No authoritative
SDK declaration or narrow callback type was found. This is evidence for the
observed transport and conversion, not a claim about the original Atlus typedef.
The existing post-mask comparison against -1 is present in retail and remains
unchanged; it is not an invented branch. A coherent narrow getter-return
alternative was measured but inserted extra caller conversions, so it was not
retained.

### Complete snapshot extent

The pre-existing `F630Frame` declared 108 bytes with alignment 4, while the actual
provider cleared and copied 112 bytes in seven EE quadwords. MWCC layout probes
confirmed this discrepancy. The append adds the real cleared/copied word at
+0x6c, declares the required 16-byte alignment, and uses the complete object as
the clear/copy base. The complete 64-function provider object remains byte-for-
byte identical, SHA-256:

`df7b1906b4cdda76d8b5e3d6df2a300fb9140f197975230ce3fd3c151be638c5`

## Verification completed

- All 13 affected production owners preserve 431 functions: 423 MATCH and 8 ASM
- Independent review confirms the 13 complete production objects are identical
  to the public baseline before the byte-neutral snapshot append
- Forced-C event owner: target and all 25 siblings are fully resolved exact;
  ordered references are preserved and no allocated nontext/data/table section
  is introduced
- Snapshot append: complete object identity, all 64 functions and relocation
  records preserved; declared size/alignment changes from 108/4 to 112/16
- Published primitive `00480940` remains unchanged
- `git diff --check` passes

All positive fixtures run at both `-O0` and `-O2` under the repository's unchanged
Clang i386 undefined-behavior/bounds sanitizer flags, using QEMU-i386 only as the
execution adapter. Negative controls run at `-O2`:

| Fixture | Cases per optimization | Negative controls |
| --- | ---: | ---: |
| Controller | 3,458 | 9 |
| Actual getters/environment/area providers | 293,296 (1,302,000 assertions) | 6 |
| Actual field-file provider | 983,202 (11,142,902 assertions) | 5 |
| Actual snapshot provider | 320 | 5 |

The controller fixture substitutes most external providers. The separate suites
execute the actual named provider bodies. The snapshot fixture uses the existing
project convention of a 16-byte copy-only vector type for i386's unavailable
scalar `__int128`; it does not rewrite the provider body. Its checks cover both
camera-getter evaluations, all output bytes, zeroed reserved bytes and output
canaries, with shortened-copy, shortened-matrix, wrong-tail, wrong-ID and wrong-
getter controls. These are bounded machine-independent fixtures, not EE hardware
or gameplay execution.

## Remaining acceptance gates

The frozen snapshot append has been independently accepted. Run fresh scoped
and whole-repository verification, linked image/ELF hash checks and the complete
native regression suite against this production-C append, then obtain final
review before publication.

## Replay

After configuring the authorized compiler and retail inputs:

```sh
python tools/fnalign.py src/promoted/k_fldEvent.c func_00172e00 --quiet
python tools/verify.py $(git diff --name-only 18c3a8d4 HEAD -- 'src/*.c')
PYTHONPATH=tests python -m unittest test_field_event_controller test_field_transition_contracts test_field_file_transport test_field_snapshot_extent
```

The final command requires a working native32 execution route. This environment
used the external QEMU adapter, preserving the repository compiler, sanitizer
flags, fixture bodies and assertions; skipped tests are not accepted as passes.
