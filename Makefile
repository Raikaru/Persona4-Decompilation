PYTHON ?= python
SPLAT_CONFIG := config/slus21782.yaml

.PHONY: all setup split consolidate reconcile m2c-bulk m2c-promote shared-p3 build verify check test progress progress-validate m2c-setup m2c clean distclean

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

consolidate:
	$(PYTHON) tools/consolidate_sources.py

reconcile: consolidate
	$(PYTHON) tools/reconcile_function_boundaries.py

shared-p3:
	@test -n "$(P3_ROOT)" || (echo "usage: make shared-p3 P3_ROOT=/path/to/Persona3-FES-Decompilation" && exit 2)
	$(PYTHON) tools/map_shared_p3.py --p3-root "$(P3_ROOT)" --with-source-evidence

build:
	$(PYTHON) tools/build.py

verify check:
	$(PYTHON) tools/verify.py

test:
	$(PYTHON) -m unittest discover -s tests -v

progress:
	$(PYTHON) tools/progress.py

progress-validate:
	$(PYTHON) tools/progress.py --validate-dir progress

clean:
	-rm -rf build assets asm/data
	-rm -f asm/*.s asm/*.o undefined_funcs_auto.txt undefined_syms_auto.txt

distclean: clean
	-rm -rf orig
	-rm -f image.bin
