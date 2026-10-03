#!/usr/bin/env bash
set -euo pipefail
# Run at repository root with configured licensed tools and retail input.
archive=docs/probe_archive/Title_matrix_contract_001265a0_20261003
mkdir -p proof
python tools/regenerate_asm.py > proof/matrix-regenerate.log
for audit in audit_source capture_owner audit_retail audit_preservation audit_prior_scopes audit_machine; do
    python "$archive/$audit.py"
done
export P4_NATIVE32_RUNNER="${P4_NATIVE32_RUNNER:-qemu-i386}"
python -m unittest discover -s tests -p test_title_matrix_contract.py -v > proof/matrix-native.log 2>&1
python docs/probe_archive/Title_model_call_contract_001265a0_20261003/run_contracts.py --runner "$P4_NATIVE32_RUNNER" > proof/matrix-prior-native.log 2>&1
python -m unittest discover -s tests -p test_title_entry_contract.py -v >> proof/matrix-prior-native.log 2>&1
python tools/verify.py --json proof/matrix-owners.json src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c src/Event/Fcl/shdSprite.c src/promoted/code1_0025.c src/promoted/code1_0036.c src/rw/basky.c src/Kernel/sdkTask.c src/sdkOt.c src/promoted/code1_0046.c src/promoted/code1_003e.c src/renderware/plcore/bamatrix.c src/Graphics/Model/mdlManager.c > proof/matrix-owners.log
python tools/decomp_lint.py src/promoted/code1_0012.c > proof/matrix-lint.log
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0 > proof/matrix-measure.log
python "$archive/receipt.py"
