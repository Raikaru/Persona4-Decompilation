import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';

const root = path.dirname(fileURLToPath(import.meta.url));
const compilation = JSON.parse(fs.readFileSync(path.join(root, 'compile.json'), 'utf8'));
const digest = data => crypto.createHash('sha256').update(data).digest('hex');
assert.equal(digest(fs.readFileSync(path.join(root, 'fixture.c'))), compilation.fixture_sha256);
const modules = {};
for (const profile of compilation.profiles) {
    const bytes = fs.readFileSync(path.join(root, `${profile.name}.wasm`));
    assert.equal(digest(bytes), profile.wasm_sha256);
    const module = new WebAssembly.Module(bytes);
    assert.deepEqual(WebAssembly.Module.imports(module), []);
    modules[profile.name] = module;
}
const invoke = (profile, name) => new WebAssembly.Instance(modules[profile], {}).exports[name]();
const currentOrdinary = invoke('corrected', 'run_ordinary');
const currentExtreme = invoke('corrected', 'run_extremes');
const previousOrdinary = invoke('previous', 'run_ordinary');
assert.equal(currentOrdinary, 24);
assert.equal(currentExtreme, 960);
assert.equal(previousOrdinary, 24);
const controls = [];
for (const name of ['old_width_overflow', 'old_height_overflow']) {
    const correctedBits = invoke('corrected', name) >>> 0;
    assert.equal(correctedBits, 0x4f000000);
    let failure;
    try { invoke('previous', name); }
    catch (error) { failure = error; }
    assert(failure instanceof WebAssembly.RuntimeError, `${name} must trigger the signed-overflow negative control`);
    assert.match(failure.message, /unreachable/);
    controls.push({name, previous_ubsan_trap: true, trap: failure.message,
                   corrected_float_bits: correctedBits.toString(16)});
}
const result = {
    fixture_sha256: compilation.fixture_sha256,
    runtime: `Node ${process.version} WebAssembly`,
    corrected_ordinary_checks: currentOrdinary,
    corrected_extreme_checks: currentExtreme,
    previous_ordinary_checks: previousOrdinary,
    negative_controls: controls,
    result: 'PASS',
    scope: 'Actual extracted C extent helpers in wasm32 under UBSan trap mode; neither a PS2 runtime test nor an entire-renderer execution',
    dynamic_imports: [],
    native_matching_compiles: 0,
    runner_sha256: digest(fs.readFileSync(fileURLToPath(import.meta.url)))
};
fs.writeFileSync(path.join(root, 'execution.json'), JSON.stringify(result, null, 2) + '\n');
console.log(JSON.stringify(result, null, 2));
