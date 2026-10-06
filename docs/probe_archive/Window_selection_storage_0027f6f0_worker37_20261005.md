# Window selection storage proof — `func_0027f6f0`

The remaining owned-data question for the recovered `func_0027f6f0` candidate is resolved. The candidate does not depend on missing external storage or an unidentified asset. Its only previously unresolved allocated section is a native 76-byte `.rodata` switch table at retail address `0x007481B0`.

The table contains 19 `R_MIPS_32` relocations. Every entry targets the compiler-local `func_0027f6f0` symbol plus an internal-label addend, so the section is a function-relative jump table. Resolving those addends from the candidate function entry gives 12 of 19 retail pointers exactly. The other seven entries differ only because the corresponding candidate handlers are laid out at different instruction offsets: table byte offsets `0x04`, `0x0c`, `0x28`, `0x38`, and `0x3c` point to handlers that are `0x3c` earlier than retail; offsets `0x34` and `0x40` point to handlers that are `0x08` earlier. No independent data value is missing.

The complete owner proof covers 260 bytes of allocated non-code storage and 64 storage relocations. All 184 bytes outside this jump table resolve exactly to retail. Within the jump table, the 12 handler pointers above resolve exactly and the seven remaining pointer differences track the candidate's code-layout differences. All 20 sibling functions in the owner remain exact.

The candidate itself remains nonmatching and is not suitable for promotion: `func_0027f6f0` emits 8556 bytes in an 8624-byte retail window, has 305 resolved code relocations and 440 fully resolved differing words, and its missing retail suffix is not zero-only padding. The storage result therefore closes the old standalone data-section blocker but does not justify a data-only fix or removing the ASM fallback.

Reproducibility hashes from the configured b210 compile and authentic retail image:

| Artifact | SHA-256 |
| --- | --- |
| Current owner `src/promoted/itfMsgProcedure_Window.c` | `4ac20829f43d412a50751c43bdf7ac53f1d3808df43e3408c276fc9bd5fb0f0b` |
| Archived candidate body `docs/probe_archive/Window_owner_contracts_worker24_20261005_0027f6f0.c` | `a436238b25023cbda975bc343e4fe94f3388bbeee9fd28ee5cbe4717ed16b93d` |
| Complete candidate owner source used for the native compile | `1705896d2f1746a955f9969d628d4b7715972e8861772ec7bb72a0944f34590f` |
| Native complete-owner object | `f7b02f9afc8b67052cf017ee701cbcd4c51b05de3d4cef971585165af497e5df` |
| Complete jump-table/owner proof JSON | `c260ca099c00f7326d04be5e609f6c0807142353f3c29e0ae7bd3eeeac407f5c` |
| Focused section-50 inspection JSON | `e5c60e080ec6fda533744282d522528de486f7290c9971aa88750baefd5f1b1d` |

The binary object and scratch proof JSON are intentionally not archived here. This note records their hashes and the independently checked results needed to continue code recovery without treating section 50 as an unknown storage contract.

The accompanying JSON retains the complete numeric owner/storage diagnosis and the independently recalculated label deltas. The historical candidate body named above remains local, not a committed dependency or a claimed fresh-checkout replay. No executable bytes or native object are included.
