"""Variable-choice search: move one local's whole use set into another local of
the same declared type that is dead over that span.

    from varchoice import candidates
    for name, text in candidates(body): ...

A use set is the innermost brace block containing every reference of a local
(excluding its declaration). Another local W qualifies when it has the same
declared type, is not referenced inside that block, is not referenced in any
loop that encloses the block, and its next reference after the block (if any)
is a plain assignment `W = ...`. Winners still need a manual liveness check.
"""
import re

DECL = re.compile(r"^\s+((?:const\s+|unsigned\s+|signed\s+|register\s+)*[A-Za-z_]\w*(?:\s*\*+)?)\s*\b([A-Za-z_]\w*)\s*;\s*$")


def _blocks(text):
    stack, spans = [], []
    for i, ch in enumerate(text):
        if ch == "{":
            stack.append(i)
        elif ch == "}" and stack:
            spans.append((stack.pop(), i))
    return spans


def _loops(text, spans):
    out = []
    for a, b in spans:
        head = text[text.rfind("\n", 0, a) + 1:a]
        if re.search(r"\b(for|while)\b", head) or head.strip() == "do":
            out.append((a, b))
    return out


def candidates(text, func_start=0):
    lines = text.split("\n")
    decls = {}
    off = 0
    for ln in lines:
        m = DECL.match(ln)
        if m and off >= func_start:
            typ = re.sub(r"\s+", " ", m.group(1).replace("register ", "")).strip()
            decls.setdefault(m.group(2), (typ, off + ln.index(m.group(2))))
        off += len(ln) + 1
    spans = _blocks(text)
    loops = _loops(text, spans)
    refs = {}
    for name, (typ, dpos) in decls.items():
        refs[name] = [m.start() for m in re.finditer(rf"\b{re.escape(name)}\b", text) if m.start() != dpos]
    for v, (typ, _) in decls.items():
        rv = refs[v]
        if not rv:
            continue
        lo, hi = min(rv), max(rv)
        enc = [s for s in spans if s[0] < lo and hi < s[1]]
        if not enc:
            continue
        blk = min(enc, key=lambda s: s[1] - s[0])
        encl_loops = [l for l in loops if l[0] <= blk[0] and blk[1] <= l[1]]
        for w, (wtyp, _) in decls.items():
            if w == v or wtyp != typ:
                continue
            rw = refs[w]
            if any(blk[0] <= p <= blk[1] for p in rw):
                continue
            if any(l[0] <= p <= l[1] for l in encl_loops for p in rw):
                continue
            after = [p for p in rw if p > blk[1]]
            if after:
                p = min(after)
                tail = text[p + len(w):p + len(w) + 4]
                if not re.match(r"\s*=[^=]", tail):
                    continue
            seg = text[blk[0]:blk[1] + 1]
            seg2 = re.sub(rf"\b{re.escape(v)}\b", w, seg)
            yield f"{v}->{w}", text[:blk[0]] + seg2 + text[blk[1] + 1:]


def _next_is_def(text, name, pos):
    """True when the next reference of `name` at or after pos is a plain assignment (or none)."""
    m = re.compile(rf"\b{re.escape(name)}\b").search(text, pos)
    if not m:
        return True
    tail = text[m.end():m.end() + 4]
    return bool(re.match(r"\s*=[^=]", tail))


def web_candidates(text, func_start=0):
    """Move one definition's web (def statement up to the next def of the same
    variable inside its block, or the block end) into another dead local."""
    lines = text.split("\n")
    decls = {}
    off = 0
    for ln in lines:
        m = DECL.match(ln)
        if m and off >= func_start:
            typ = re.sub(r"\s+", " ", m.group(1).replace("register ", "")).strip()
            decls.setdefault(m.group(2), (typ, off + ln.index(m.group(2))))
        off += len(ln) + 1
    spans = _blocks(text)
    loops = _loops(text, spans)
    for v, (typ, dpos) in decls.items():
        for d in re.finditer(rf"(?m)^(\s+){re.escape(v)} = [^;]*;", text):
            start = d.start()
            enc = [s for s in spans if s[0] < start < s[1]]
            if not enc:
                continue
            blk = min(enc, key=lambda s: s[1] - s[0])
            nxt = re.compile(rf"(?m)^\s+{re.escape(v)} = ").search(text, d.end(), blk[1])
            end = nxt.start() if nxt else blk[1]
            if not _next_is_def(text, v, end):
                continue
            encl_loops = [l for l in loops if l[0] <= start and end <= l[1]]
            # loop-carried: v read in an enclosing loop before this def
            if any(re.search(rf"\b{re.escape(v)}\b", text[l[0]:start]) for l in encl_loops):
                continue
            seg = text[start:end]
            # the web must not escape into a nested block that ends after `end`
            if seg.count("{") != seg.count("}"):
                continue
            for w, (wtyp, _) in decls.items():
                if w == v or wtyp != typ:
                    continue
                if re.search(rf"\b{re.escape(w)}\b", seg):
                    continue
                if any(re.search(rf"\b{re.escape(w)}\b", text[l[0]:l[1]]) for l in encl_loops):
                    continue
                if not _next_is_def(text, w, end):
                    continue
                seg2 = re.sub(rf"\b{re.escape(v)}\b", w, seg)
                yield f"{v}@{d.start()}->{w}", text[:start] + seg2 + text[end:]
