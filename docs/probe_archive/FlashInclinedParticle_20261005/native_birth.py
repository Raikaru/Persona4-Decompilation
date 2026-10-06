"""Execute the installed particle layout and birth fragment, with controlled RNG.

This is not the whole Flash pass or VU emulation. The independent byte-offset
oracle checks the actual C birth branch using exactly representable inputs.
"""
from pathlib import Path
import argparse
import hashlib
import json
import re
import sys
import tempfile

ARCHIVE = Path(__file__).resolve().parent
ROOT = ARCHIVE.parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--output", type=Path, required=True)
parser.add_argument("--emit-only", action="store_true")
args = parser.parse_args()
OUT = args.output.resolve()
OUT.mkdir(parents=True, exist_ok=True)
sys.path.insert(0, str(ROOT / "tests"))
sys.path.insert(0, str(ROOT / "tools"))
from native32_support import RUNTIME_C, ENTRY_C, native32_runtime
from measure_guarded import extract_guarded_body
import probe_variants as P

owner = ROOT / "src/promoted/effPolygonFlash.c"
original = owner.read_bytes()
body = extract_guarded_body(P._read_text(owner), "FUN_004A0C00", "func_004a0c00")
record_type = re.search(r"typedef struct FlashInclinedParticle \{.*?\} FlashInclinedParticle;", body, re.S).group()
start = body.index("if (age == -1) {")
end, depth = start, 0
while end < len(body):
    if body[end] == "{":
        depth += 1
    elif body[end] == "}":
        depth -= 1
        if depth == 0:
            end += 1
            break
    end += 1
branch = body[start:end]
assert "particle->radiusStep" in branch and "__asm__" not in branch

common = RUNTIME_C + r'''
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
static unsigned scenario, floatCalls, intCalls;
#define CHECK(value) do { if (!(value)) native32_failure(__LINE__, scenario, #value); } while (0)
static unsigned draw(unsigned index) { return (scenario + 2 * index) % 5; }
static f32 effMiscRandFloat(u32 argument) {
    CHECK(argument == 0 && floatCalls < 7);
    return (f32)draw(floatCalls++) * 0.25f;
}
static u32 effMiscRand(u32 argument) {
    CHECK(argument == 0 && intCalls == 0);
    ++intCalls;
    return scenario * 73U + 5U;
}
''' + record_type + r'''
static void birthFragment(FlashInclinedParticle *particle, u8 *config, s32 life,
                          s32 firstFrame, s32 initialAge, s32 *budget) {
    s32 age = particle->age;
    s32 births = *budget;
    f32 fullTurn = 8.0f, unit = 1.0f;
    f32 cosine, factor, radius, endpoint;
    do {
BRANCH
    } while (0);
    *budget = births;
}
'''.replace("BRANCH", branch)

test = r'''
/* These offsets come from the retail LW/SWC1 sites, independently of names. */
static void floatAt(u8 *record, unsigned offset, f32 value) { memcpy(record + offset, &value, 4); }
static f32 adjusted(f32 base, unsigned variationQuarters, unsigned sample) {
    unsigned numerator = 16U - variationQuarters * (4U - sample);
    return base * (f32)numerator / 16.0f;
}
int main(void) {
    static const s32 ages[] = {-2, -1, 0, 4, 0x7fffffff};
    struct { u8 prefix[0x60]; f32 values[12]; } config;
    static const f32 parameters[] = {8.0f,0.5f,16.0f,0.75f,32.0f,0.25f,64.0f,1.0f,0.5f,0.5f,128.0f,0.25f};
    struct { u8 before[16]; FlashInclinedParticle particle; u8 after[16]; } actual;
    u8 expected[sizeof(actual)], configBefore[sizeof(config)];
    CHECK(sizeof(FlashInclinedParticle) == 0x20);
    CHECK(__builtin_offsetof(FlashInclinedParticle, age) == 0);
    CHECK(__builtin_offsetof(FlashInclinedParticle, velocity) == 4);
    CHECK(__builtin_offsetof(FlashInclinedParticle, phase) == 8);
    CHECK(__builtin_offsetof(FlashInclinedParticle, length) == 12);
    CHECK(__builtin_offsetof(FlashInclinedParticle, radius) == 16);
    CHECK(__builtin_offsetof(FlashInclinedParticle, radiusStep) == 20);
    CHECK(__builtin_offsetof(FlashInclinedParticle, inclination) == 24);
    CHECK(__builtin_offsetof(FlashInclinedParticle, width) == 28);
    memset(&config, 0x5a, sizeof(config));
    memcpy(config.values, parameters, sizeof(parameters));
    memcpy(configBefore, &config, sizeof(config));
    for (unsigned ai=0; ai<5; ++ai)
    for (unsigned first=0; first<2; ++first)
    for (unsigned budget=0; budget<4; ++budget)
    for (unsigned exponent=0; exponent<8; ++exponent)
    for (unsigned reverse=0; reverse<2; ++reverse) {
        s32 actualBudget = (s32)budget;
        s32 life = 1 << exponent;
        s32 initialAge = reverse ? life : 0;
        unsigned born = ages[ai] == -1 && budget != 0;
        memset(&actual, 0xa5, sizeof(actual));
        actual.particle.age = ages[ai];
        memcpy(expected, &actual, sizeof(actual));
        if (born) {
            u8 *bytes = expected + 16;
            s32 age = first ? (s32)((scenario * 73U + 5U) % (unsigned)life) : initialAge;
            f32 initial = adjusted(32.0f, 1, draw(2));
            f32 terminal = adjusted(64.0f, 4, draw(3));
            memcpy(bytes, &age, 4);
            floatAt(bytes, 4, adjusted(128.0f, 1, draw(4)));
            floatAt(bytes, 8, 2.0f * (f32)draw(0));
            floatAt(bytes, 12, adjusted(16.0f, 3, draw(1)));
            floatAt(bytes, 16, initial);
            floatAt(bytes, 20, (terminal - initial) / (f32)life);
            floatAt(bytes, 24, adjusted(0.5f, 2, draw(6)));
            floatAt(bytes, 28, adjusted(8.0f, 2, draw(5)));
        }
        floatCalls = intCalls = 0;
        birthFragment(&actual.particle, (u8 *)&config, life, first, initialAge, &actualBudget);
        CHECK(memcmp(&actual, expected, sizeof(actual)) == 0);
        CHECK(memcmp(&config, configBefore, sizeof(config)) == 0);
        CHECK(actualBudget == (s32)(budget - born));
        CHECK(floatCalls == (born ? 7U : 0U));
        CHECK(intCalls == (born && first ? 1U : 0U));
        ++scenario;
    }
    CHECK(scenario == 640);
    native32_text("640 particle layout/birth cases passed\n");
    return 0;
}
'''

source = common + test + ENTRY_C
mutated_type = record_type.replace("f32 length;", "f32 swap;").replace("f32 width;", "f32 length;").replace("f32 swap;", "f32 width;")
cases = {"installed": source, "swapped-length-width": source.replace(record_type, mutated_type),
         "reversed-radius-step": source.replace("(endpoint - cosine)", "(cosine - endpoint)")}
assert len(set(cases.values())) == 3
directory = OUT / "native-birth"
directory.mkdir(exist_ok=True)
tempfile.tempdir = str(directory)
if args.emit_only:
    for label, content in cases.items():
        (directory / (label + ".c")).write_text(content)
    print("Emitted authenticated fixture inputs; no compiler or runtime called")
    raise SystemExit(0)
runtime = native32_runtime()
rows = []
for label, text in cases.items():
    path = directory / (label + ".c")
    path.write_text(text)
    for opt in ("-O0", "-O2"):
        binary = runtime.compile(path, directory / (label + opt), opt)
        result = runtime.run(binary)
        if label == "installed":
            assert result.returncode == 0 and result.stdout == "640 particle layout/birth cases passed\n", result
        else:
            assert result.returncode == 1 and "scenario" in result.stdout, result
        row = {"case": label, "optimization": opt, "exit_code": result.returncode,
               "stdout": result.stdout, "source_sha256": hashlib.sha256(text.encode()).hexdigest()}
        rows.append(row)
        print(json.dumps(row), flush=True)
assert owner.read_bytes() == original
receipt = {"owner_sha256": hashlib.sha256(original).hexdigest(),
           "type_sha256": hashlib.sha256(record_type.encode()).hexdigest(),
           "branch_sha256": hashlib.sha256(branch.encode()).hexdigest(), "results": rows,
           "scope": "Installed particle layout and unmodified birth branch only; controlled RNG, dyadic inputs, byte-offset oracle and canaries. No VU or complete scene/render execution.",
           "host": "freestanding i386 with undefined/bounds sanitizers"}
(directory / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
