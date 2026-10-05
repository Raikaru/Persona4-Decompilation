#!/usr/bin/env python3
"""Replay primitive owner/contract checks using the configured local compiler.

Run from the repository root:
  python docs/probe_archive/Primitive_remaining_contracts_20261005_replay.py --output build/primitive-contract-receipt.json

Creates only unique build scratch plus the explicitly selected output file.
No retail bytes or native paths are written into the receipt. The bounded
instruction interpreter rejects unsupported instructions/inexact arithmetic;
it does not model exceptional inputs, signed zero, or arbitrary EE rounding.
"""
from collections import defaultdict
from fractions import Fraction
from pathlib import Path
from types import SimpleNamespace
import argparse
import hashlib
import json
import struct
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
import verify as V
import probe_variants as P
import fnalign as A
import build as B
from measure_guarded import extract_guarded_body

gp, addresses = V.symbol_addresses()
addresses.update(B.load_symbol_addr_map())

PREVIOUS_DELTA = '''\
void func_00480f20(void *param_1, void *param_2)
{
    PrimInterpData *out = (PrimInterpData *)param_1;
    const PrimInterpData *in = (const PrimInterpData *)param_2;
    PrimQuaternion inverse;
    f32 inputY;
    f32 inputX;
    f32 inputZ;
    f32 inputW;
    f32 norm;
    f32 reciprocal;
    PrimQuaternion saved;

    saved = out->quat;
    inputY = in->quat.y;
    inputX = in->quat.x;
    inputZ = in->quat.z;
    inputW = in->quat.w;
    norm = inputX * inputX + inputY * inputY + inputZ * inputZ + inputW * inputW;
    if (norm <= 0.0f) {
        return;
    }
    {
        reciprocal = 1.0f / norm;
        inverse.w = inputW * reciprocal;
        reciprocal = -reciprocal;
        inverse.x = inputX * reciprocal;
        inverse.y = inputY * reciprocal;
        inverse.z = inputZ * reciprocal;
    }
    out->quat.w = inverse.w * saved.w -
                  (inverse.x * saved.x + inverse.y * saved.y + inverse.z * saved.z);
    out->quat.x = inverse.y * saved.z - inverse.z * saved.y;
    out->quat.y = inverse.z * saved.x - inverse.x * saved.z;
    out->quat.z = inverse.x * saved.y - inverse.y * saved.x;
    out->quat.x = out->quat.x + saved.x * inverse.w;
    out->quat.y = out->quat.y + saved.y * inverse.w;
    out->quat.z = out->quat.z + saved.z * inverse.w;
    out->quat.x = out->quat.x + inverse.x * saved.w;
    out->quat.y = out->quat.y + inverse.y * saved.w;
    out->quat.z = out->quat.z + inverse.z * saved.w;
    out->values[0] -= in->values[0];
    out->values[1] -= in->values[1];
    out->values[2] -= in->values[2];
    out->values[3] -= in->values[3];
    out->values[4] -= in->values[4];
    out->values[5] -= in->values[5];
}
'''

def owner_function(obj, name):
    if name == 'func_0045f790' and any(s['name']=='primLine3D' and s['size'] for s in obj.symbols):
        name = 'primLine3D'
    return obj.function(name)


def signed16(value):
    return (value & 0x7fff) - (value & 0x8000)


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def number(value):
    return struct.unpack('<f', struct.pack('<I', value))[0]


def exact(value):
    rounded = number(bits(float(value)))
    assert Fraction(rounded) == value, 'fixture left the exact arithmetic domain'
    return rounded


class Machine:
    def __init__(self, code, base):
        self.code, self.base, self.pc = code, base, base
        self.gpr = [0] * 32
        self.fpr = [None] * 32
        self.acc = None
        self.condition = False
        self.memory = {}
        self.writes = set()
        self.initial_reads = []
        self.pending = None
        self.trace = []
        self.gpr[29] = 0x30000
        self.gpr[31] = 0xfffffff0

    def put(self, address, value, size=4, initial=False):
        for index in range(size):
            self.memory[address + index] = (value >> (index * 8)) & 255
            if not initial:
                self.writes.add(address + index)

    def get(self, address, size=4):
        assert all(address + i in self.memory for i in range(size)), (
            f'unproduced memory at {address:x}, PC={self.pc:x}')
        if not all(address + i in self.writes for i in range(size)):
            self.initial_reads.append((self.pc, address, size))
        return sum(self.memory[address + i] << (8 * i) for i in range(size))

    def data(self, address, size):
        return bytes(self.memory[address + i] for i in range(size))

    def floating(self, reg):
        value = self.fpr[reg]
        assert value is not None, f'unproduced f{reg}, PC={self.pc:x}'
        return Fraction(value)

    def step(self):
        word, = struct.unpack_from('<I', self.code, self.pc - self.base)
        op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        rd, shift, funct = (word >> 11) & 31, (word >> 6) & 31, word & 63
        immediate = signed16(word)
        pending = self.pending
        self.pending = None
        self.trace.append(self.pc)
        if op == 0:
            if funct == 0:
                self.gpr[rd] = (self.gpr[rt] << shift) & 0xffffffff
            elif funct in (0x21, 0x2d):
                self.gpr[rd] = self.gpr[rs] + self.gpr[rt]
            elif funct == 0x25:
                self.gpr[rd] = self.gpr[rs] | self.gpr[rt]
            elif funct == 8:
                self.pending = self.gpr[rs]
            else:
                raise AssertionError(f'unsupported SPECIAL {funct:x}')
        elif op == 9:
            self.gpr[rt] = self.gpr[rs] + immediate
        elif op == 13:
            self.gpr[rt] = self.gpr[rs] | (word & 0xffff)
        elif op == 15:
            self.gpr[rt] = (word & 0xffff) << 16
        elif op in (4, 5):
            condition = self.gpr[rs] == self.gpr[rt]
            if condition == (op == 4):
                self.pending = self.pc + 4 + immediate * 4
        elif op in (0x23, 0x24, 0x37, 0x1e):
            size = {0x23: 4, 0x24: 1, 0x37: 8, 0x1e: 16}[op]
            self.gpr[rt] = self.get(self.gpr[rs] + immediate, size)
        elif op in (0x2b, 0x28, 0x3f, 0x1f):
            size = {0x2b: 4, 0x28: 1, 0x3f: 8, 0x1f: 16}[op]
            self.put(self.gpr[rs] + immediate, self.gpr[rt], size)
        elif op == 0x31:
            self.fpr[rt] = number(self.get(self.gpr[rs] + immediate))
        elif op == 0x39:
            self.put(self.gpr[rs] + immediate, bits(float(self.floating(rt))))
        elif op == 0x11:
            if rs == 4:
                self.fpr[rd] = number(self.gpr[rt] & 0xffffffff)
            elif rs == 8:
                assert rt in (0, 1), 'branch-likely not supported'
                if self.condition == bool(rt):
                    self.pending = self.pc + 4 + immediate * 4
            elif rs == 16:
                fs, ft, fd = rd, rt, shift
                left = self.floating(fs)
                if funct in (6, 7):
                    self.fpr[fd] = exact(left if funct == 6 else -left)
                else:
                    right = self.floating(ft)
                    if funct in (0, 1, 2, 3):
                        value = {0: lambda: left + right, 1: lambda: left - right,
                                 2: lambda: left * right, 3: lambda: left / right}[funct]()
                        self.fpr[fd] = exact(value)
                    elif funct == 0x18:
                        self.acc = Fraction(exact(left + right))
                    elif funct == 0x1a:
                        self.acc = Fraction(exact(left * right))
                    elif funct == 0x1e:
                        assert self.acc is not None
                        self.acc = Fraction(exact(self.acc + left * right))
                    elif funct in (0x1c, 0x1d):
                        assert self.acc is not None
                        value = self.acc + left * right if funct == 0x1c else self.acc - left * right
                        self.fpr[fd] = exact(value)
                    elif funct == 0x36:
                        self.condition = left <= right
                    else:
                        raise AssertionError(f'unsupported COP1 operation {funct:x}')
            else:
                raise AssertionError(f'unsupported COP1 format {rs:x}')
        else:
            raise AssertionError(f'unsupported opcode {op:x}, PC={self.pc:x}')
        self.gpr[0] = 0
        self.pc = pending if pending is not None else self.pc + 4

    def run(self, stop=None):
        for _ in range(1000):
            if self.pc == self.gpr[31] or (stop and stop(self)):
                return
            self.step()
        raise AssertionError('instruction budget exhausted')


def frame(machine, address, quat, values):
    payload = b'HEADER!!' + struct.pack('<10f', *(quat + values)) + b'TAIL'
    assert len(payload) == 52
    for index, value in enumerate(payload):
        machine.put(address + index, value, 1, initial=True)


def delta(code, quat, source, ambient, alias=False):
    machine = Machine(code, 0x480f20)
    machine.gpr[4], machine.gpr[5] = 0x10000, 0x10000 if alias else 0x20000
    out_values = [16., 32., 48., 64., 80., 96.]
    in_values = [1., 2., 3., 4., 5., 6.]
    frame(machine, machine.gpr[4], quat, out_values)
    if not alias:
        frame(machine, machine.gpr[5], source, in_values)
    for index, value in ambient.items():
        machine.fpr[index] = value
    machine.run()
    assert all(0x10008 <= p < 0x10030 or 0x2fff0 <= p < 0x30000 for p in machine.writes)
    assert machine.data(0x10000, 8) == b'HEADER!!'
    assert machine.data(0x10030, 4) == b'TAIL'
    return machine.data(0x10000, 52), machine


def check_delta():
    retail = lab.retail.bytes_at(0x480f20, 416)
    baseline, _ = V.ObjectFile(lab.out/'previous-delta/owner.o').function('func_00480f20')
    candidate, _ = V.ObjectFile(lab.out/'current-delta/owner.o').function('func_00480f20')
    assert len(baseline) == len(candidate)
    changed_words = [i for i in range(0,len(baseline),4) if baseline[i:i+4] != candidate[i:i+4]]
    assert changed_words == [0x4c], 'repair changed more than the norm branch destination'
    old_branch, = struct.unpack_from('<I', baseline, 0x4c)
    new_branch, = struct.unpack_from('<I', candidate, 0x4c)
    assert old_branch >> 16 == new_branch >> 16 == 0x4501
    branch_change = {'instruction_offset':'0x4c',
                     'previous_target':f'{0x480f70 + signed16(old_branch)*4:08x}',
                     'current_target':f'{0x480f70 + signed16(new_branch)*4:08x}',
                     'all_other_instruction_bytes_equal':True}
    fixtures = [([0., 0., 0., 1.], [0., 0., 0., 1.]),
                ([.5, -.25, .75, 1.], [0., 1., 0., 0.]),
                ([1., 2., 3., 4.], [.5, .5, .5, .5]),
                ([1., -2., 3., -.5], [0., 0., 0., 2.])]
    rows = []
    for index, (out, source) in enumerate(fixtures):
        expected, _ = delta(retail, out, source, {})
        before, _ = delta(baseline, out, source, {})
        after, _ = delta(candidate, out, source, {})
        assert expected == before == after
        rows.append({'case': 'positive-norm-' + str(index), 'retail_equal': True})
    for quat in ([0., 0., 0., 1.], [.5, .5, .5, .5], [0., 0., 0., 0.]):
        ambient = {0: 4., 1: 3., 9: 2., 10: 5.}
        expected, _ = delta(retail, quat, quat, ambient, alias=True)
        actual, _ = delta(candidate, quat, quat, {}, alias=True)
        assert expected == actual
        assert struct.unpack('<6f', actual[24:48]) == (0.,)*6
        rows.append({'case': 'exact-alias-' + str(len(rows)), 'retail_equal': True})
    incoming = [{0: 4., 1: 3., 9: 2., 10: 5.}, {0: 8., 1: 7., 9: 6., 10: 9.}]
    retail_outputs = []
    for ambient in incoming:
        expected, machine = delta(retail, [0.,0.,0.,1.], [0.,0.,0.,0.], ambient)
        retail_outputs.append(list(struct.unpack('<4f', expected[8:24])))
        actual, _ = delta(candidate, [0.,0.,0.,1.], [0.,0.,0.,0.], {})
        before, _ = delta(baseline, [0.,0.,0.,1.], [0.,0.,0.,0.], {})
        assert expected[24:48] == actual[24:48] != before[24:48]
        assert actual[8:24] == before[8:24]
        assert 0x480f74 not in machine.trace and 0x48104c in machine.trace
    assert retail_outputs == [[2.,3.,4.,5.], [6.,7.,8.,9.]]
    return {'guard_change':branch_change, 'positive_and_alias_cases': rows, 'zero_norm_retail_quaternions': retail_outputs,
            'zero_norm_scalar_result': [15.,30.,45.,60.,75.,90.],
            'candidate_preserves_invalid_quaternion': True}


def check_line():
    retail = lab.retail.bytes_at(0x45f790, 624)
    candidate, _ = V.ObjectFile(lab.out/'current-line/owner.o').function('primLine3D')
    results = []
    for code in (retail, candidate):
        per_object = []
        for seed in (0x100, 0x40000000):
            machine = Machine(code, 0x45f790)
            machine.gpr[4:8] = [0x10000, 0x20000, 0x21000, 0]
            for address, values in ((0x10000, [1.,2.,3.]), (0x20000, [4.,5.,6.])):
                for i, value in enumerate(values):
                    machine.put(address + i*4, bits(value), initial=True)
            machine.put(0x21000, 0x80604020, initial=True)
            machine.put(0x30000 - 0x140 + 0x9c, seed, initial=True)
            machine.run(stop=lambda state: state.pc == 0x45f960)
            flags = machine.get(machine.gpr[6] + 12)
            assert machine.gpr[5] == 2 and machine.gpr[7] == 2
            assert machine.data(machine.gpr[4], 16) == struct.pack('<3fI',1.,2.,3.,0x80604020)
            assert machine.data(machine.gpr[4]+36, 16) == struct.pack('<3fI',4.,5.,6.,0x80604020)
            per_object.append({'incoming_stack_flags':seed, 'submitted_flags':flags,
                               'reads_incoming_flags': (0x45f89c,0x2ff5c,4) in machine.initial_reads})
        results.append(per_object)
    assert [row['submitted_flags'] for row in results[0]] == [0x20103,0x40020003]
    assert [row['submitted_flags'] for row in results[1]] == [0x20003,0x20003]
    assert all(row['reads_incoming_flags'] for row in results[0])
    assert not any(row['reads_incoming_flags'] for row in results[1])
    return {'retail':results[0], 'guarded_C':results[1], 'vertex_packets_equal':True}


def relocate(body, relocs, mapping, bases):
    output = bytearray(body)
    pending = defaultdict(list)
    errors = []
    for reloc in relocs:
        offset, kind, name = reloc['offset'], reloc['r_type'], reloc.get('symbol') or ''
        address = V.resolve_symbol(name, gp, mapping)
        key = (name, reloc.get('target_section'), reloc.get('target_value'))
        if not name and reloc.get('target_section') in bases:
            address = bases[reloc['target_section']] + reloc.get('target_value', 0)
        if address is None:
            errors.append(dict(reloc, reason='unresolved symbol'))
            continue
        word, = struct.unpack_from('<I', body, offset)
        if kind == 4:
            value = (word & 0xfc000000) | (((address + ((word & 0x3ffffff) << 2)) >> 2) & 0x3ffffff)
        elif kind == 5:
            pending[key].append((offset, word))
            continue
        elif kind == 6:
            for hi_offset, hi_word in pending.pop(key, []):
                full = address + ((hi_word & 0xffff) << 16) + signed16(word)
                struct.pack_into('<I', output, hi_offset,
                                 (hi_word & 0xffff0000) | (((full + 0x8000) >> 16) & 0xffff))
            value = (word & 0xffff0000) | ((address + signed16(word)) & 0xffff)
        elif kind in (7, 8):
            displacement = address + signed16(word) - gp
            if not -0x8000 <= displacement < 0x8000:
                errors.append(dict(reloc, reason='GP out of range'))
            value = (word & 0xffff0000) | (displacement & 0xffff)
        elif kind == 2:
            value = (word + address) & 0xffffffff
        else:
            errors.append(dict(reloc, reason='unsupported relocation'))
            continue
        struct.pack_into('<I', output, offset, value)
    errors += [dict(symbol=str(key), reason='unpaired HI16') for key, entries in pending.items() if entries]
    return bytes(output), errors


def inspect(label):
    directory = lab.out / label
    obj = V.ObjectFile(directory / 'owner.o')
    candidate_markers = {m['addr']: m for m in V.scan_markers(directory/'owner.c')}
    masked_exact = []
    for marker in lab.markers:
        code, relocs = owner_function(obj, marker['name'])
        window = lab.windows['windows'][f"{marker['addr']:08x}"]
        target = lab.retail.bytes_at(marker['addr'], window)
        diff, _ = V.compare(code, relocs, target)
        if not diff and len(code) <= len(target) and not any(target[len(code):]):
            masked_exact.append(marker)
    bases = B.recover_section_bases(obj, masked_exact, lab.retail, gp)
    more = B.recover_pointer_data_bases(obj, masked_exact, lab.retail, gp)
    if more is not None:
        bases.update(more)
    # MWLD concatenates same-name sections in object order with each original
    # alignment. Three independently anchored tables place the filename too.
    groups = defaultdict(list)
    layouts = {}
    for section in obj.sections:
        if section['flags'] & 2 and not section['flags'] & 4 and section['size']:
            groups[section['name']].append(section)
    for name, sections in groups.items():
        concatenated = B.recover_concatenated_layout(sections, bases)
        assert concatenated is not None, 'no independently anchored data layout'
        base, offsets, total = concatenated
        layouts[name] = (base, offsets, total)
        for section, offset in zip(sections, offsets):
            address = base + offset
            assert bases.get(section['idx'], address) == address
            bases[section['idx']] = address
    mapping = dict(addresses)
    for symbol in obj.symbols:
        if symbol['name'] and symbol['shndx'] in bases:
            mapping[symbol['name']] = bases[symbol['shndx']] + symbol['value']
    rows, resolved_functions, covered = [], {}, defaultdict(set)
    for marker in lab.markers:
        name = marker['name']
        code, relocs = owner_function(obj, name)
        resolved, errors = relocate(code, relocs, mapping, bases)
        window = lab.windows['windows'][f"{marker['addr']:08x}"]
        target = lab.retail.bytes_at(marker['addr'], window)
        exact = not errors and len(code) <= window and resolved == target[:len(code)] and not any(target[len(code):])
        row = dict(name=name, address=f"{marker['addr']:08x}", bytes=len(code), window=window,
                   exact=exact, source_kind='ASM' if candidate_markers[marker['addr']].get('asm') else 'C',
                   relocation_count=len(relocs), errors=errors,
                   code_sha256=hashlib.sha256(code).hexdigest(),
                   resolved_sha256=hashlib.sha256(resolved).hexdigest(),
                   zero_suffix_size=window-len(code) if len(code)<=window and not any(target[len(code):]) else None)
        rows.append(row)
        resolved_functions[name] = resolved
        names = {name, 'primLine3D'} if name == 'func_0045f790' else {name}
        symbol = next(s for s in obj.symbols if s['name'] in names and s['size'] and 0 < s['shndx'] < len(obj.sections))
        covered[symbol['shndx']].update(range(symbol['value'],symbol['value']+symbol['size']))
    data, executable, data_payloads = [], [], {}
    for section in obj.sections:
        if not section['flags'] & 2 or not section['size']:
            continue
        raw = obj.data[section['offset']:section['offset']+section['size']]
        if section['flags'] & 4:
            extra = [i for i in range(section['size']) if i not in covered[section['idx']]]
            assert all(offset in covered[section['idx']] for offset, _, _ in B.section_relocs(obj, section['idx']))
            executable.append(dict(index=section['idx'],name=section['name'],size=section['size'],
                                   covered_bytes=section['size']-len(extra),
                                   zero_gap_bytes=len(extra),all_gaps_zero=not any(raw[i] for i in extra)))
            continue
        base = bases.get(section['idx'])
        relocs = [dict(offset=o, r_type=k, symbol=n) for o,k,n in B.section_relocs(obj, section['idx'])]
        assert section['type'] != 8 or not relocs
        payload, errors = (bytes(section['size']), []) if section['type'] == 8 else relocate(raw, relocs, mapping, bases)
        exact = base is not None and not errors and payload == lab.retail.bytes_at(base,len(payload))
        data_payloads[section['idx']] = payload
        data.append(dict(index=section['idx'], name=section['name'], address=f'{base:08x}' if base is not None else None,
                         size=section['size'], alignment=section['addralign'], errors=errors,
                         relocation_count=len(relocs), exact=exact, sha256=hashlib.sha256(payload).hexdigest()))
    data_ok, layout = B.plan_data_sections(obj, masked_exact, lab.retail, gp, set(addresses),
        independent_literals=True, independent_rodata=True, independent_bss=True,
        independent_initialized=True, symbol_addresses=addresses)
    storage_spans = []
    for name, sections in groups.items():
        base, offsets, total = layouts[name]
        payload = bytearray(total)
        for section, offset in zip(sections, offsets):
            payload[offset:offset+section['size']] = data_payloads[section['idx']]
        assert bytes(payload) == lab.retail.bytes_at(base,total), 'data alignment gap differs'
        storage_spans.append(dict(name=name, address=f'{base:08x}', size=total,
                                  alignment_gap_bytes=total-sum(s['size'] for s in sections),
                                  exact=True,sha256=hashlib.sha256(payload).hexdigest()))
    result = dict(label=label, logical_owner='src/Graphics/primitive.c',
                  source_sha256=hashlib.sha256((directory/'owner.c').read_bytes()).hexdigest(),
                  object_sha256=hashlib.sha256(obj.data).hexdigest(),functions=rows,
                  allocated_data=data, storage_spans=storage_spans, executable_sections=executable, planner_data_placeable=data_ok,
                  compiler='MWCCPS2 3.0.1 b210',retail_sha1=lab.windows['sha1'])
    assert all(not row['errors'] for row in rows+data), 'unresolved relocations'
    if not all(row['exact'] for row in data) or not data_ok:
        print(json.dumps({'data':data,'planner':data_ok,'layout':layout},indent=2),flush=True)
    assert all(row['exact'] for row in data) and data_ok, 'data placement failure'
    assert all(row['all_gaps_zero'] for row in executable), 'unaccounted code bytes'
    (directory/'resolved-proof.json').write_text(json.dumps(result,indent=2)+'\n')
    print(label, 'exact windows',sum(r['exact'] for r in rows),'/',len(rows),
          'data',len(data),'/',len(data),'planner',data_ok,'relocations',sum(r['relocation_count'] for r in rows+data),flush=True)
    return result, resolved_functions


def compile_profile(label, address=None, body=None):
    source = lab.original
    if address is not None:
        marker = 'FUN_' + address.upper()
        name = 'func_' + address
        if body is None:
            body = extract_guarded_body(source, marker, name)
        start, end = P.region_for(source, marker, name)
        source = P.splice_region(source, start, end,
                                 P._normalise_candidate(body, lab.newline), lab.newline)
    directory = lab.out/label
    directory.mkdir(parents=True)
    cpath = directory/'owner.c'
    cpath.write_bytes(source.encode('utf-8',errors='surrogateescape'))
    ok, log = P._compile_in_context(cpath,lab.owner,lab.cfg,directory/'owner.o')
    (directory/'compile.log').write_text(log,encoding='utf-8')
    if not ok:
        raise RuntimeError('Full owner compilation failed: '+log)


def target_score(label, address):
    obj = V.ObjectFile(lab.out/label/'owner.o')
    code, relocs = owner_function(obj,'func_'+address)
    retail = lab.retail.bytes_at(int(address,16), lab.windows['windows'][address])
    mask = V.mask_bytes(max(len(code),len(retail)),relocs)
    words = [i for i in range(0,len(mask),4)
             if not (i>=len(code) and not any(retail[i:i+4])) and any(
                 (code[j] if j<len(code) else None)!=(retail[j] if j<len(retail) else None)
                 for j in range(i,min(i+4,len(mask))) if not mask[j])]
    _, edits, _ = A.align(A.decode(retail,int(address,16)),A.decode(code,int(address,16)),
                           {r['offset']//4 for r in relocs})
    diff, _ = V.compare(code,relocs,retail)
    return dict(address=address,object_bytes=len(code),retail_window=len(retail),
                differing_words=len(words),aligned_edits=edits,
                exact=not diff and len(code)<=len(retail) and not any(retail[len(code):]))


def main():
    global lab
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    owner=ROOT/'src/Graphics/primitive.c'
    original_bytes=owner.read_bytes()
    cfg=V.load_config()
    windows=V._read_json(V.FUNCTION_WINDOWS)
    lab=SimpleNamespace(owner=owner,original=P._read_text(owner),newline=P._newline_for(original_bytes),
                        out=Path(tempfile.mkdtemp(prefix='primitive-contract-20261005-',dir=ROOT/'build')),
                        cfg=cfg,windows=windows,markers=V.scan_markers(owner),
                        retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']))
    compile_profile('production')
    compile_profile('current-line','0045f790')
    compile_profile('current-delta','00480f20')
    compile_profile('previous-delta','00480f20',PREVIOUS_DELTA)
    baseline, functions=inspect('production')
    assert all(row['exact'] for row in baseline['functions'])
    assert sum(row['source_kind']=='C' for row in baseline['functions'])==10
    profiles={'production':baseline}
    signatures=lambda proof: sorted((r['address'],r['size'],r['alignment'],r['sha256']) for r in proof['allocated_data'])
    for label, changed in [('current-line','func_0045f790'),('current-delta','func_00480f20'),('previous-delta','func_00480f20')]:
        result, current=inspect(label)
        result['unchanged_resolved_functions']=[name for name in functions if current[name]==functions[name]]
        result['changed_resolved_functions']=[name for name in functions if current[name]!=functions[name]]
        result['owned_data_same']=signatures(baseline)==signatures(result)
        assert result['changed_resolved_functions']==[changed] and result['owned_data_same']
        profiles[label]=result
    result=dict(logical_owner='src/Graphics/primitive.c',owner_sha256=hashlib.sha256(original_bytes).hexdigest(),
                retail_sha1=windows['sha1'],compiler='MWCCPS2 3.0.1 b210',
                compile_flags=V.unit_compile_flags(owner,cfg['compile_flags']),
                default_C_matches=10,default_ASM_fallbacks=2,
                target_scores=[target_score('current-line','0045f790'),target_score('current-delta','00480f20')],
                contracts={'arithmetic_domain':'finite dyadic fixtures; exceptional arithmetic and signed zero excluded',
                           'delta':check_delta(),'line':check_line()},
                whole_owner_profiles=profiles)
    assert owner.read_bytes()==original_bytes, 'owner changed during replay'
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print('PASS: owner, relocations, complete storage spans, finite contracts and unchanged siblings.')


if __name__=='__main__':
    main()
