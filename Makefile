PYTHON ?= python
SPLAT_CONFIG := config/slus21782.yaml

.PHONY: all setup split reconcile build verify check test clean distclean

all: build verify

setup:
	@test -n "$(ISO)" || (echo "usage: make setup ISO=/path/to/persona4.iso" && exit 2)
	$(PYTHON) tools/setup.py "$(ISO)"

split:
	$(PYTHON) -m splat split $(SPLAT_CONFIG)

reconcile:
	$(PYTHON) tools/reconcile_function_boundaries.py

build:
	$(PYTHON) tools/build.py

verify check:
	$(PYTHON) tools/verify.py

test:
	$(PYTHON) -m unittest discover -s tests -v

clean:
	-rm -rf build assets asm/data
	-rm -f asm/*.s asm/*.o undefined_funcs_auto.txt undefined_syms_auto.txt

distclean: clean
	-rm -rf orig
	-rm -f image.bin
