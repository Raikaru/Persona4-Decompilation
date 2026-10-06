# Retail resource inputs needed for first-party recovery

The executable and current source establish three unresolved input contracts.
Completing their C recovery requires the Persona 4 USA retail resource data or
equivalent runtime evidence. The configured executable alone does not contain
the files named below. This record does not award matching credit or change
the remaining assembly fallbacks.

## Required data

Provide the user's Persona 4 USA disc image, or preserve these extracted paths:

| Resource | Question it resolves |
| --- | --- |
| `camp/icon.bin`, including its member directory | Does the retained save-icon archive contain the registered `camp/icon.ico` member on every reachable save path? |
| `field/data/f%03d_%03d_%03d.FBN` or the corresponding `field/pack/` members, with reachable field selection | Which loaded or filtered entry counts reach `func_0015f000`? |
| `field/pack/f%03d_%03d.CMR` payloads and archive member directories | Does each successful camera-provider path find its member, and which format versions reach the secondary-matrix branch? |

An authoritative runtime trace can substitute for a payload where it records
the particular lookup, return value, output writes, loaded version and relevant
caller's state. A report that loading completed does not establish those facts.
These inputs address the contracts below; further code-generation work remains.

## Memory-card icon size

`src/Kernel/mc.c::func_002a4b10` loads the archive named by the string at
`0x0063ed38`, `camp/icon.bin`. The save flow retains its handle while
`src/Kernel/h_memcard_grouped.c::func_004647c0` looks up `camp/icon.ico`, named
at `0x00712880`.

The real lookup provider is `src/Kernel/sdkCdvd.c::func_00455f70`. Its successful
path writes the requested size; the failed scan returns zero without producing
that size. The retail writer consumes its size slot without a corresponding
success check. The provider's relevant instruction addresses are `0x00456048`
(size store) and `0x00456074` (failed return path).

The current guarded writer retains its checks. Removing them needs a supported
successful-lookup domain established by the actual archive or trace. The prior
complete call-chain and jump-table audit is
[`Memcard_004647c0_worker10_20261005.md`](../Memcard_004647c0_worker10_20261005.md).
Its separate instruction/table residual remains ordinary matching work.

## FBN first rotation angle

`src/Kosaka/Field/k_fldFBN.c::func_0015e960` obtains the entry count from the
FBN header at offset eight and can replace it with a filtered retained count.
The caller invokes `func_0015f000` with a load handle and resource buffer.

On the first processed entry, retail loads a floating rotation angle from
`sp+0xc4` at `0x0015f224`, before its first identified store at `0x0015f344`.
The preceding stack objects at `sp+0xa0..0xa8` and `sp+0xb0..0xb8` do not supply
that word. No earlier producer or escaped reference to that slot has been
established. The current source explicitly retains the assembly fallback for
this reason.

Actual FBN contents and reachable field state determine whether the first-entry
path executes. A proven zero retained count makes that path unreachable. A
reachable nonzero count does **not** repair the missing producer: its source
lifetime must then be recovered without an invented initial angle or an
uninitialized C scalar. Supplying assets is therefore evidence for deciding
the path contract, rather than a promise that the function immediately matches.

## Camera resource outputs

`src/promoted/k_fldEnvironment.c::func_00154be0` formats the CMR member name and
calls the same archive lookup provider. In bundled mode, a missing member can
return one without writing the supplied output objects. The current
`src/Kosaka/Field/k_fldResource.c::func_0014f310` reconstruction consumes those
outputs on a nonzero provider result.

The provider copies the complete secondary matrix when the resource version is
at least `0x10002`. The legacy branch instead constructs matrix components and
ORs the previous flags word at offset `0x0c`; this requires a defined incoming
word. The requested resource inventory or trace must establish member presence
and the actual version/initialization path. A blanket assumption that all
loaded CMR files are modern is not established by the executable. Despite its
owning source filename, this camera provider reads `.CMR`, not `.ENV`; the
string at `0x005efef0` establishes the extension.

## What is available locally

The approved Persona 4 root was searched recursively, including ignored files,
for ISO, CVM, CHD, CSO, MDF, FBN, CMR, ENV and icon payload filenames. None of the
requested resources or game disc images was found. Its `orig/` contains the
retail executable and `SYSTEM.CNF`; its `assets/` contains four split executable
data files.

The other approved repository contains three historical PlayStation SDK disc
images. Read-only volume/root inspection identified SDK directories in the
Runtime 4.4 image and the `DTLS_03040_mode1.iso` image. A standard ISO9660 primary
volume descriptor was not recognized in the third image at the three checked
layouts. The receipt records those bounded observations. It does not describe
every file hidden inside unrelated compressed archives or claim that no ISO
files exist anywhere in the workspace.

## Replay and source binding

`receipt.json` records the inspected source hashes, retail strings and short
instruction witnesses. It also retains the SDK-disc metadata observations and
the exact search scope. It contains no game payloads or machine-specific paths.

From the repository root:

```text
python docs/probe_archive/First_party_resource_inputs_20261005/check_inputs.py
python docs/probe_archive/First_party_resource_inputs_20261005/check_inputs.py --retail
```

The first command checks the recorded source files. The second also checks the
configured, hash-authenticated retail executable's strings and instruction
witnesses. Neither command compiles, installs a candidate, scans external
drives, or claims to validate resources that have not been supplied.
