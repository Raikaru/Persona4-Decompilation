#!/usr/bin/env python3
"""Run tools/fnalign.py against a specific mwccps2 build.

Usage: verscan.py <compiler.exe> <file.c> <func> [--candidate X] [--quiet]
"""
import sys
from pathlib import Path

sys.path.insert(0, "tools")
import fnalign  # noqa: E402

COMPILER = sys.argv[1]
sys.argv = [sys.argv[0]] + sys.argv[2:]

_orig = fnalign.load_config


def patched():
    cfg = dict(_orig())
    cfg["mwcc"] = COMPILER
    cfg["mwcc_versions"] = {}
    return cfg


fnalign.load_config = patched
fnalign.main()
