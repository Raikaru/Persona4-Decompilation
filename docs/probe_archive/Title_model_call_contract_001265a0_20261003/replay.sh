#!/usr/bin/env bash
set -euo pipefail
# Run at repository root with licensed tools/retail and an existing i386 runner.
archive=docs/probe_archive/Title_model_call_contract_001265a0_20261003
mkdir -p proof
python tools/regenerate_asm.py > proof/model-regenerate.log
for audit in audit_source capture_owner audit_retail audit_preservation audit_color_storage audit_layer_calls audit_gp_colors audit_candidate audit_alpha_aliases audit_sprite_alpha audit_preserved_fade audit_model_calls; do
    python "$archive/$audit.py"
done
python "$archive/run_contracts.py" --runner "${P4_NATIVE32_RUNNER:-qemu-i386}" > proof/model-all-native.log 2>&1
python tools/verify.py --json proof/model-owners.json src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c src/Event/Fcl/shdSprite.c src/promoted/code1_0025.c src/promoted/code1_0036.c src/rw/basky.c > proof/model-owners.log
python tools/decomp_lint.py src/promoted/code1_0012.c > proof/model-lint.log
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0 > proof/model-measure.log
python "$archive/receipt.py"
