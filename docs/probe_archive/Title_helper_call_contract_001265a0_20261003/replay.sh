#!/usr/bin/env bash
set -euo pipefail
archive=docs/probe_archive/Title_helper_call_contract_001265a0_20261003
mkdir -p proof
python tools/regenerate_asm.py > proof/helper-regenerate.log
for audit in audit_source capture_owner audit_preservation audit_machine; do
 python "$archive/$audit.py"
done
python "$archive/audit_prior_scopes.py" > proof/helper-prior-machine.log 2>&1
export P4_NATIVE32_RUNNER="${P4_NATIVE32_RUNNER:-qemu-i386}"
python "$archive/run_contracts.py" --runner "$P4_NATIVE32_RUNNER" > proof/helper-all-native.log 2>&1
python tools/verify.py --json proof/helper-owners.json src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c src/Event/Fcl/shdSprite.c src/promoted/code1_0025.c src/promoted/code1_0036.c src/rw/basky.c src/Kernel/sdkTask.c src/sdkOt.c src/promoted/code1_0046.c src/promoted/code1_003e.c src/renderware/plcore/bamatrix.c src/Graphics/Model/mdlManager.c > proof/helper-owners.log
python tools/decomp_lint.py src/promoted/code1_0012.c > proof/helper-lint.log
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0 > proof/helper-measure.log
python "$archive/receipt.py"
