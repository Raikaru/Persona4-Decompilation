#!/usr/bin/env bash
set -euo pipefail
# Run from repository root with licensed tools/retail and an existing i386 runner.
archive=docs/probe_archive/Title_palette_storage_001265a0_20261003
mkdir -p proof
python tools/regenerate_asm.py > proof/palette-regenerate.log
for audit in audit_source capture_owner audit_retail audit_color_storage audit_layer_calls audit_gp_colors audit_candidate audit_preservation audit_preserved_slices audit_sprite_alpha audit_preserved_fade; do
    python "$archive/$audit.py"
done
python "$archive/run_contracts.py" --runner "${P4_NATIVE32_RUNNER:-qemu-i386}" > proof/palette-all-native.log 2>&1
python tools/verify.py --json proof/palette-owners.json src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c src/Event/Fcl/shdSprite.c src/promoted/code1_0025.c src/promoted/code1_0036.c src/rw/basky.c > proof/palette-owners.log
python tools/decomp_lint.py src/promoted/code1_0012.c > proof/palette-lint.log
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0 > proof/palette-measure.log
python "$archive/receipt.py"
