#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/../../.."
mkdir -p proof/field-ai
python tools/regenerate_asm.py
python docs/probe_archive/Field_AI_normalization_0017f490_20261003/native-baseline-token-audit.py >proof/field-ai/native-baseline-token-audit.log
python docs/probe_archive/Field_AI_normalization_0017f490_20261003/capture_owner.py >proof/field-ai/owners.log
python docs/probe_archive/Field_AI_normalization_0017f490_20261003/audit_normalization.py >proof/field-ai/machine.log
python tools/verify.py --json proof/field-ai/verify.json src/Kosaka/Field/k_fldAI.c src/promoted/code1_003e.c >proof/field-ai/verify.log
python tools/measure_guarded.py src/Kosaka/Field/k_fldAI.c func_0017f490 --save-candidate proof/field-ai/after.c >proof/field-ai/after-measure.log
python tools/fnalign.py src/Kosaka/Field/k_fldAI.c func_0017f490 --candidate proof/field-ai/after.c --quiet >proof/field-ai/after-align.log
python tools/decomp_lint.py src/Kosaka/Field/k_fldAI.c >proof/field-ai/lint.log
if [[ -n "${P4_NATIVE32_ADAPTER:-}" ]]; then
  python "$P4_NATIVE32_ADAPTER" "$PWD" test_field_ai_normalization_contract >proof/field-ai/native.log 2>&1
else
  python -m unittest discover -s tests -p test_field_ai_normalization_contract.py -v >proof/field-ai/native.log 2>&1
  if grep -q 'skipped=' proof/field-ai/native.log; then
    echo 'Skipped native contracts are unverified' >&2
    exit 2
  fi
fi
