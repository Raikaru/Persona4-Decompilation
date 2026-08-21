#!/usr/bin/env python3
"""Disassemble a retail function window.

Two backends. Ghidra is preferred and is the DEFAULT, because it is the only
one that decodes the Emotion Engine extensions: the FPU multiply-accumulate
ops (mula.S / madda.S / madd.S / msub.S / adda.S / suba.S) and the COP2/VU
macro-mode ops. rabbitizer prints all of those as `.word 0x46...` tagged
INVALID, and -- worse -- inside those words it names float registers with
INTEGER register names, so `$a2` silently means `$f6`. Two lanes each lost an
hour to that before the EE-aware path existed.

Ghidra backend: a headless GhidraMCP server with the
`ghidra-emotionengine-reloaded` extension, giving `r5900:LE:32:default`.
Start it (once, from the repo root) as a managed process:

    gmcp serve --port 8091 --file orig/SLUS_217.82

Nothing here imports outside the stdlib, so it runs fine under `python -E -s`
with PYTHONNOUSERSITE=1. That is the whole point: no more unsetting it.

rabbitizer backend: only used with --rabbitizer, or automatically when no
Ghidra server answers. It needs user site-packages, so it must run with
PYTHONNOUSERSITE unset.

Usage:
    python -E -s tools/recon_dis.py 003e4030 [more addrs ...]
    python -E -s tools/recon_dis.py --rabbitizer 003e4030
"""

import json
import os
import sys
import urllib.error
import urllib.request

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_PORTS = (8091, 8089, 8090, 8092, 8093, 8094)


def windows():
    """addr -> retail window size, from the canonical function table."""
    with open(os.path.join(REPO, "tools", "slus21782_functions.json")) as f:
        return json.load(f)["windows"]


def _post(url, payload, timeout=120):
    req = urllib.request.Request(
        url,
        data=json.dumps(payload).encode(),
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    with urllib.request.urlopen(req, timeout=timeout) as r:
        return json.loads(r.read())


def find_server():
    """Base URL of a live GhidraMCP instance, or None."""
    forced = os.environ.get("GHIDRA_MCP_URL")
    candidates = [forced] if forced else [
        "http://127.0.0.1:%d" % p for p in DEFAULT_PORTS
    ]
    for base in candidates:
        try:
            urllib.request.urlopen(base + "/check_connection", timeout=2).read()
            return base
        except Exception:
            continue
    return None


def dis_ghidra(base, addr, size):
    r = _post(base + "/disassemble_bytes",
              {"start_address": "0x%08x" % addr,
               "length": size,
               "max_instructions": max(64, size // 4 + 8)})
    if not r.get("success"):
        raise RuntimeError(r.get("error") or r.get("message") or "disassemble failed")
    out = ["--- %08x size %d  [ghidra r5900]" % (addr, size)]
    for i in r.get("instructions", []):
        # Ghidra reports delay-slot instructions with a leading underscore.
        m = i["mnemonic"].lstrip("_")
        raw = i.get("bytes", "")
        word = "".join(reversed([raw[j:j + 2] for j in range(0, len(raw), 2)]))
        out.append("%s: %s %-11s %s" % (i["address"], word, m, i.get("operands", "")))
    if r.get("truncated"):
        out.append("... TRUNCATED, %d instructions total" % r.get("instructions_total", 0))
    return "\n".join(out)


def dis_rabbitizer(addr, size):
    sys.path.insert(0, os.path.join(REPO, "tools"))
    import rabbitizer                      # needs user site-packages
    from verify import RetailElf, load_config

    cfg = load_config()
    target = json.load(open(os.path.join(REPO, "config", "target.json")))
    elf = RetailElf(cfg["retail_elf"], target, target["elf"]["sha1"])
    data = elf.bytes_at(addr, size)
    out = ["--- %08x size %d  [rabbitizer -- EE ops will show as INVALID]" % (addr, size)]
    for i in range(0, size, 4):
        word = int.from_bytes(data[i:i + 4], "little")
        out.append("%08x: %08x %s"
                   % (addr + i, word, rabbitizer.Instruction(word, addr + i).disassemble()))
    return "\n".join(out)


def main(argv):
    use_rab = "--rabbitizer" in argv
    addrs = [a for a in argv if not a.startswith("-")]
    if not addrs:
        print(__doc__.strip())
        return 2

    win = windows()
    base = None if use_rab else find_server()
    if base is None and not use_rab:
        print("RECON_dis: no Ghidra server answered; falling back to rabbitizer, "
              "which cannot decode the EE FPU/VU ops. Start one with:\n"
              "  gmcp serve --port 8091 --file orig/SLUS_217.82",
              file=sys.stderr)

    for spec in addrs:
        addr = int(spec, 16)
        size = win.get("%08x" % addr)
        if size is None:
            print("RECON_dis: no canonical window for %08x" % addr, file=sys.stderr)
            continue
        if base:
            try:
                print(dis_ghidra(base, addr, size))
                continue
            except Exception as exc:
                print("RECON_dis: ghidra failed on %08x (%s); using rabbitizer"
                      % (addr, exc), file=sys.stderr)
        print(dis_rabbitizer(addr, size))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
