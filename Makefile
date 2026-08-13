PYTHON ?= python
SPLAT_CONFIG := config/slus21782.yaml
OBJDIFF_CLI ?= objdiff-cli

.PHONY: all setup split reconcile m2c-bulk m2c-promote shared-p3 build verify check test lint lint-errors lint-full ctx objdiff objdiff-objects objdiff-report progress recovery progress-validate m2c-setup m2c clean distclean

all: build verify

setup:
	@test -n "$(ISO)" || (echo "usage: make setup ISO=/path/to/persona4.iso" && exit 2)
	$(PYTHON) tools/setup.py "$(ISO)"

split:
	$(PYTHON) -m splat split $(SPLAT_CONFIG)

m2c-setup:
	$(PYTHON) tools/setup_m2c.py

# Decompile one retail function with P4 declarations:
#   make m2c FILE=src/Battle/btlUnit.c FUNC=func_00195850
m2c:
	@test -n "$(FILE)" -a -n "$(FUNC)" || (echo "usage: make m2c FILE=src/path.c FUNC=function_name" && exit 2)
	$(PYTHON) tools/m2c_decompile.py "$(FILE)" "$(FUNC)" $(if $(STACK),--stack-structs,)

m2c-bulk:
	$(PYTHON) tools/m2c_bulk.py

m2c-promote:
	@test -f build/m2c_verify_report.json || (echo "run candidate verifier first: build/m2c_verify_report.json is missing" && exit 2)
	$(PYTHON) tools/m2c_bulk.py --promote-report build/m2c_verify_report.json

reconcile:
	$(PYTHON) tools/reconcile_function_boundaries.py

# Map functions shared with the Persona 3 FES decomp. Prefer passing a FRESH
# verifier report via P3_REPORT: without it the mapper falls back to P3's
# committed progress/metrics.json snapshot, which only refreshes on a full link
# build and therefore UNDERCOUNTS the portable set as P3 advances.
shared-p3:
	@test -n "$(P3_ROOT)" || (echo "usage: make shared-p3 P3_ROOT=/path/to/Persona3-FES-Decompilation [P3_REPORT=/path/to/verify.json]" && exit 2)
	$(PYTHON) tools/map_shared_p3.py --p3-root "$(P3_ROOT)" --with-source-evidence $(if $(P3_REPORT),--p3-report "$(P3_REPORT)",)

# Propose original translation-unit boundaries from measured evidence. Signal
# weights are calibrated against P3 ground truth (adjacent-pair same-file rate);
# the scheduler-flag signal measured at base rate and therefore carries weight 0.
# Needs a FRESH P3 verifier report -- a scoped/partial run silently weakens the
# strongest signal, so the tool prints a NOTE and upgrades if it detects one.
tu-audit:
	@test -n "$(P3_ROOT)" || (echo "usage: make tu-audit P3_ROOT=/path/to/Persona3-FES-Decompilation [P3_REPORT=/path/to/verify.json]" && exit 2)
	$(PYTHON) tools/tu_audit.py --p3-root "$(P3_ROOT)" $(if $(P3_REPORT),--p3-report "$(P3_REPORT)",)

tu-audit-json:
	@test -n "$(P3_ROOT)" || (echo "usage: make tu-audit-json P3_ROOT=/path/to/Persona3-FES-Decompilation [P3_REPORT=/path/to/verify.json]" && exit 2)
	$(PYTHON) tools/tu_audit.py --p3-root "$(P3_ROOT)" $(if $(P3_REPORT),--p3-report "$(P3_REPORT)",) --json build/tu_audit.json

# Recover original translation-unit boundaries from embedded __FILE__ assert
# strings. Unlike tu-audit's anonymous groups these carry the real filename.
file-strings:
	$(PYTHON) tools/file_strings.py

# Function-name recovery. Each producer owns one config/symbol_names.<source>.txt
# so they can be regenerated independently; reconcile merges them over the
# generated func_<address> placeholders and hard-fails on unevidenced entries.
names:
	$(PYTHON) tools/port_p3_names.py
	$(PYTHON) tools/mine_name_strings.py
	$(PYTHON) tools/reconcile_function_boundaries.py
	$(PYTHON) tools/apply_symbol_names.py

# CI gate: fails when a recovered name has not been applied to the sources.
names-check:
	$(PYTHON) tools/apply_symbol_names.py --check

build:
	$(PYTHON) tools/build.py

verify check:
	$(PYTHON) tools/verify.py

test:
	$(PYTHON) -m unittest discover -s tests -v

# Source-honesty lint. Scoped to FIRST-PARTY code by default, so the exit code
# is a usable CI gate; rw/cri/sce middleware is reported only on request.
# `lint-errors` additionally suppresses warning lines from the report.
lint:
	$(PYTHON) tools/decomp_lint.py

lint-errors:
	$(PYTHON) tools/decomp_lint.py --errors-only

lint-full:
	$(PYTHON) tools/decomp_lint.py --include-third-party

# Flattened context for a decomp.me scratch or decomp-permuter run:
#   make ctx CTX_SRC=src/Battle/btlTarget.c
ctx:
	@test -n "$(CTX_SRC)" || (echo "usage: make ctx CTX_SRC=src/path.c" && exit 2)
	$(PYTHON) tools/m2ctx.py "$(CTX_SRC)" --decompme

# LINKED_REPORT is defined below, next to the progress targets that share it.
#
# Regenerate objdiff.json from a fresh verifier report.  The config now lists
# one unit per canonical function (tools/slus21782_functions.json), so it can
# only be regenerated from a FULL verify run.
#
# --linked-report additionally tags the functions the byte-exact link shipped
# with the `linked` category, which is what publishes the fully-linked figure to
# decomp.dev.  It is passed only when the report exists: it comes from a
# successful `make build-progress`, and a missing one must degrade to "no linked
# figure published" rather than failing the config regeneration.
objdiff:
	$(PYTHON) tools/verify.py --json build/objdiff_report.json
	$(PYTHON) tools/gen_objdiff.py --report build/objdiff_report.json --output objdiff.json $(if $(wildcard $(LINKED_REPORT)),--linked-report $(LINKED_REPORT),)

# Emit the per-unit target/base objects that objdiff.json references.
# ONLY=<substring> restricts emission to matching units.  Base objects are
# built with --skip-asm (decomp.dev's SKIP_ASM convention): INCLUDE_ASM
# fallbacks then contribute zero matched code instead of scoring 100%% by
# splicing the retail bytes.  Set SKIP_ASM=0 to emit the spliced bases
# instead (handy for visually diffing an assembly fallback in the objdiff UI).
objdiff-objects: objdiff
	$(PYTHON) tools/gen_objdiff.py --report build/objdiff_report.json --output objdiff.json --emit-objects $(if $(wildcard $(LINKED_REPORT)),--linked-report $(LINKED_REPORT),) $(if $(filter 0,$(SKIP_ASM)),,--skip-asm) $(if $(ONLY),--only "$(ONLY)",)

# Progress report for decomp.dev.  Requires every target object the config
# names to have been emitted (objdiff-objects).  OBJDIFF_CLI=/path/to/objdiff-cli
# overrides the binary; -c functionRelocDiffs=none matches the project option
# for one-shot diffs.
objdiff-report: objdiff-objects
	$(OBJDIFF_CLI) report generate -o build/report.json -c functionRelocDiffs=none

# Regenerate the committed progress endpoints. Without --write-dir the tool only
# PRINTS a summary, which is why `make progress` used to leave progress/ stale
# and CI's progress-validate then failed on a total that no longer matched the
# canonical map. The linked report comes from a successful byte-exact build, so
# run `make build-progress` first (or point LINKED_REPORT at an existing one).
VERIFY_REPORT ?= build/verify_report.json
LINKED_REPORT ?= build/linked_report.json

build-progress:
	$(PYTHON) tools/build.py --progress-report $(LINKED_REPORT)

progress:
	$(PYTHON) tools/verify.py --json $(VERIFY_REPORT)
	$(PYTHON) tools/recovery_quality.py --report $(VERIFY_REPORT) \
	    --json build/recovery.json
	$(PYTHON) tools/progress.py --report $(VERIFY_REPORT) \
	    --linked-report $(LINKED_REPORT) --write-dir progress \
	    --recovery-report build/recovery.json --update-readme README.md
	$(PYTHON) tools/progress.py --validate-dir progress

# Which matched functions still read like decompiler output, worst files first.
recovery:
	$(PYTHON) tools/verify.py --json $(VERIFY_REPORT)
	$(PYTHON) tools/recovery_quality.py --report $(VERIFY_REPORT) --worst 25

progress-validate:
	$(PYTHON) tools/progress.py --validate-dir progress

clean:
	-rm -rf build assets asm/data
	-rm -f asm/*.s asm/*.o undefined_funcs_auto.txt undefined_syms_auto.txt

distclean: clean
	-rm -rf orig
	-rm -f image.bin
