"""One-time inverse-transform audit against 3686cbd1; not a unit test.

This intentionally constrains the entire guarded owner only at this checkpoint.
Subsequent separately evidenced repairs should not run this historical gate.
"""
from pathlib import Path
import hashlib
import re
import sys
ROOT = Path(__file__).resolve().parents[3]
sys.path[:0] = [str(ROOT / "tools")]
from measure_guarded import extract_guarded_body
OWNER = ROOT / "src/Kosaka/Field/k_fldAI.c"
PROTOTYPE = "extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);"
# Three consecutive old scalar names, in x/y/z order, for each real object.
SCALARS = {
    "state11Delta": ("200", "1fc", "1f8"),
    "state11Right": ("1f0", "1ec", "1e8"),
    "state11Forward": ("1e0", "1dc", "1d8"),
    "state10Delta": ("1c0", "1bc", "1b8"),
    "state10Right": ("1b0", "1ac", "1a8"),
    "state10Forward": ("1a0", "19c", "198"),
    "state9Direction": ("180", "17c", "178"),
    "state9Delta": ("170", "16c", "168"),
    "state9Right": ("160", "15c", "158"),
    "state9Forward": ("150", "14c", "148"),
    "state8Delta": ("120", "11c", "118"),
    "state8Right": ("110", "10c", "108"),
    "state8Forward": ("100", "fc", "f8"),
    "state7Delta": ("e0", "dc", "d8"),
    "state7Right": ("d0", "cc", "c8"),
    "state7Forward": ("c0", "bc", "b8"),
    "state6Direction": ("a0", "9c", "98"),
    "state6Delta": ("90", "8c", "88"),
    "state2Delta": ("50", "4c", "48"),
    "state2Right": ("40", "3c", "38"),
    "state2Forward": ("30", "2c", "28"),
}
# sha256 of whitespace/comment-insensitive C tokens in guarded baseline
# 3686cbd1:src/Kosaka/Field/k_fldAI.c, FUN_0017F490 arm. No git is needed at test time.
BASELINE_TOKENS_SHA256 = "960181ec43cdf0cabb1aebc5fee18e17fb03617d976b1433d23f371638577ebf"


def tokens(source):
    source = re.sub(r"/\*.*?\*/|//[^\n]*", "", source, flags=re.S)
    return re.findall(r"[A-Za-z_][A-Za-z_0-9]*|(?:[0-9]+(?:\.[0-9]*)?(?:[eE][+-]?[0-9]+)?)[uUlLfF]*|==|!=|<=|>=|<<|>>|&&|\|\||->|[^\s]", source)


def body():
    return extract_guarded_body(OWNER.read_text(), "FUN_0017F490", "func_0017f490")


def baseline_equivalent(source):
    assert source.count(PROTOTYPE) == 1, "canonical complete-vector floating prototype"
    assert "FUN_003e40b0" not in source, "no stale integer-return name"
    assert len(re.findall(r"\bRwV3dNormalize\(", source)) == 26
    calls = re.findall(r"(?m)^\s*(?:(temp_v(?:8|10)) = )?RwV3dNormalize\(&(state\w+),&(state\w+)\);", source)
    assert len(calls) == 25 and sum(bool(c[0]) for c in calls) == 10
    assert all(c[1] == c[2] for c in calls), "every call is in-place"
    for name, offsets in SCALARS.items():
        declaration = "FldAIVec3 " + name + ";"
        assert source.count(declaration) == 1, name
        source = source.replace(declaration, " ".join("float fStack_" + x + ";" for x in offsets))
        for component, offset in zip("xyz", offsets):
            source = re.sub(r"\b" + name + r"\." + component + r"\b", "fStack_" + offset, source)
        source = re.sub(r"&" + name + r"\b", "&fStack_" + offsets[0], source)
    source = source.replace(PROTOTYPE, "extern int FUN_003e40b0();")
    source = re.sub(r"(temp_v(?:8|10) = )RwV3dNormalize\(", r"\1(float)FUN_003e40b0(", source)
    source = source.replace("RwV3dNormalize(", "FUN_003e40b0(")
    digest = hashlib.sha256(" ".join(tokens(source)).encode()).hexdigest()
    assert digest == BASELINE_TOKENS_SHA256, "repair changed tokens outside scalar-to-vector/canonical-float-call allowlist"


if __name__ == "__main__":
    baseline_equivalent(body())
    print("PASS: all owner tokens outside the 21 scalar-to-struct and 25 canonical-call replacements match 3686cbd1")
