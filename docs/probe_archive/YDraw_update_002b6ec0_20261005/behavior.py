"""Bounded EE scalar interpreter for the update-loop behavioral regression.

Runs actual resolved native instructions and hash-validated retail bytes.
External providers use explicit hooks; all volatile registers are poisoned at
each provider boundary. Floating comparisons cover finite values and signed
zero only. This is not a general PS2 emulator or a proof of FPU exceptions.
"""
from collections import Counter
from pathlib import Path
import json
import struct
import sys

import hashlib

ADDR = 0x002B6EC0

def sha(raw):
    return hashlib.sha256(raw).hexdigest()

MASK = (1 << 64) - 1
STOP = 0x0BAD0000
TASK = 0x01000000
CONTEXTS = (0x01100000, 0x01200000, 0x01300000)
NODES = 0x01400000
ANIMATION = 0x01500000
STACK = 0x01601000

def signed(value, width):
    mask = (1 << width) - 1
    value &= mask
    return value - (1 << width) if value >> (width - 1) else value

def fbits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]

def fvalue(value):
    return struct.unpack('<f', struct.pack('<I', value))[0]

class Memory:
    def __init__(self):
        self.regions = []

    def add(self, address, size, label):
        assert not any(address < a + len(b) and a < address + size for a, b, _ in self.regions)
        self.regions.append((address, bytearray(size), label))

    def region(self, address, size):
        address &= 0xFFFFFFFF
        for base, data, _ in self.regions:
            if base <= address and address + size <= base + len(data):
                return data, address - base
        raise AssertionError(f'unmapped memory {address:08x}+{size}')

    def put(self, address, value, size=4):
        data, off = self.region(address, size)
        data[off:off+size] = (value & ((1 << (8*size)) - 1)).to_bytes(size, 'little')

    def get(self, address, size=4):
        data, off = self.region(address, size)
        return int.from_bytes(data[off:off+size], 'little')

    def copy(self, dest, source, size):
        src, off = self.region(source, size)
        raw = bytes(src[off:off+size])
        dst, off = self.region(dest, size)
        dst[off:off+size] = raw

    def observable(self):
        return {label: sha(data) for _, data, label in self.regions if label != 'stack'}

class Machine:
    def __init__(self, code, case, gp, global_address, threshold_address):
        self.code, self.case = code, case
        self.pc, self.pending = ADDR, None
        self.gpr, self.fpr = [0]*32, [0]*32
        self.condition = False
        self.memory = Memory()
        self.memory.add(TASK, 0x40, 'task')
        for index, context in enumerate(CONTEXTS):
            self.memory.add(context, 0x31220, f'context{index}')
            self.memory.put(context, 0x01700000 + index * 0x100)
            self.memory.put(context + 0x30C04, 91, 2)
            for slot in range(0x30C):
                self.memory.put(context + 0x30C06 + slot*2, 0x7FFF, 2)
            for row_index, properties in case['rows'].items():
                row = context + row_index * 0x100
                values = dict(flags=1, opacity=0x91, scaleX=1., scaleY=2., frame=-7,
                    originX=-231, originY=32760, order=2, depth=17., x=-53., y=82.,
                    angle=0.5, red=0xE1, green=0x93, blue=0x5A, positionFlag=0, opacityFlag=0)
                values.update(properties)
                values['frame'] += index * 2
                values['order'] += index
                values['x'] += index * 100.
                for field, off, size in (('flags',0x14,2),('frame',8,2),('order',0xC,4),
                    ('originX',0x10,2),('originY',0x12,2),('opacity',0x72,1),
                    ('red',0x89,1),('green',0x8A,1),('blue',0x8B,1),
                    ('positionFlag',0x4B,1),('opacityFlag',0x77,1)):
                    self.memory.put(row+off, values[field], size)
                for field, off in (('depth',0x18),('x',0x3C),('y',0x40),('angle',0xD4),('scaleX',0xA4),('scaleY',0xB0)):
                    self.memory.put(row+off, fbits(values[field]))
        self.memory.add(NODES, 0x10000, 'nodes')
        self.memory.add(ANIMATION, 0xF0, 'animation')
        self.memory.add(STACK - 0x1000, 0x1000, 'stack')
        self.memory.add(global_address, 4, 'global_work')
        self.memory.add(threshold_address, 4, 'threshold')
        self.memory.put(global_address, TASK)
        self.memory.put(TASK + 0x38, CONTEXTS[0])
        self.memory.put(threshold_address, fbits(case.get('threshold', 0.1)))
        self.gpr[4], self.gpr[28], self.gpr[29], self.gpr[31] = TASK, gp, STACK, STOP
        for index in range(16,24):
            self.gpr[index] = 0x1234560000 + index
        self.initial_saved = self.gpr[16:24]
        self.calls, self.covered, self.counts = [], set(), Counter()
        self.node_count = 0
        self.swapped = False
        self.context_index = 0

    def swap(self, label):
        if label == self.case.get('swap') and not self.swapped:
            self.context_index = 1
            self.memory.put(TASK + 0x38, CONTEXTS[self.context_index])
            self.swapped = True

    def provider(self):
        address = self.pc
        args = [value & 0xFFFFFFFF for value in self.gpr[4:12]]
        result = 0
        if address == 0x002B89A0:
            self.calls.append(('animate', args[0]))
            self.memory.copy(ANIMATION, args[0], 0xF0)
            if 'animation_flags' in self.case:
                self.memory.put(ANIMATION, self.case['animation_flags'], 2)
            self.swap('animation')
            result = ANIMATION
        elif address == 0x0043F810:
            self.calls.append(('copy', *args[:3]))
            assert args[2] == 0xF0
            self.memory.copy(args[0], args[1], args[2])
        elif address == 0x002B7CD0:
            self.calls.append(('cull', args[0], signed(args[1],16), signed(args[2],16)))
            if self.case.get('cull_inactive'):
                context = self.memory.get(TASK + 0x38)
                row = context + signed(args[1],16) * 0x100
                self.memory.put(row + 0x14, self.memory.get(row + 0x14,2) & ~1,2)
            self.swap('cull')
        elif address == 0x00460990:
            result = NODES + self.node_count*0x30
            self.node_count += 1
            self.calls.append(('allocate', result))
            self.swap('allocate')
        elif address == 0x00460AC0:
            self.calls.append(('enqueue', args[0], args[1], self.memory.get(args[1]+8), self.memory.get(args[1]+0x10)))
            self.swap('enqueue')
        elif address == 0x002B2A30:
            self.calls.append(('color', *[arg & 255 for arg in args[:4]]))
            result = ((args[0] & 255) << 24) | ((args[1] & 255) << 16) | ((args[2] & 255) << 8) | (args[3] & 255)
        elif address == 0x0025ECD0:
            self.calls.append(('draw', args[0], args[1] & 255, signed(args[2],32), args[3],
                signed(args[4],32), signed(args[5],16), signed(args[6],16), args[7], *self.fpr[12:18]))
            self.swap('draw')
        else:
            raise AssertionError(f'unsupported external call {address:08x}')
        return_pc = self.gpr[31] & 0xFFFFFFFF
        # Callers cannot depend on volatile register residue. Saved registers,
        # stack, global pointer and the explicit result follow the EE ABI.
        for index in (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,24,25):
            self.gpr[index] = 0x43A00000 + index*0x123
        for index in range(20):
            self.fpr[index] = 0x41200000 + index
        self.gpr[2] = signed(result,32) & MASK
        self.pc = return_pc

    def step(self):
        if not ADDR <= self.pc < ADDR + len(self.code):
            self.provider()
            return
        word = struct.unpack_from('<I', self.code, self.pc-ADDR)[0]
        op, rs, rt = word >> 26, word >> 21 & 31, word >> 16 & 31
        rd, shift, fn = word >> 11 & 31, word >> 6 & 31, word & 63
        immediate = signed(word,16)
        pending, self.pending = self.pending, None
        self.covered.add(self.pc)
        self.counts[(op,fn if op in (0,17) else 0)] += 1
        a,b = self.gpr[rs],self.gpr[rt]
        if op == 0:
            if fn == 0: self.gpr[rd] = signed(b << shift,32) & MASK
            elif fn == 2: self.gpr[rd] = signed((b & 0xFFFFFFFF) >> shift,32) & MASK
            elif fn == 3: self.gpr[rd] = signed(signed(b,32) >> shift,32) & MASK
            elif fn == 4: self.gpr[rd] = signed(b << (a & 31),32) & MASK
            elif fn == 7: self.gpr[rd] = signed(signed(b,32) >> (a & 31),32) & MASK
            elif fn == 8: self.pending = a & 0xFFFFFFFF
            elif fn == 0x21: self.gpr[rd] = signed(a+b,32) & MASK
            elif fn == 0x24: self.gpr[rd] = a & b
            elif fn == 0x25: self.gpr[rd] = a | b
            elif fn == 0x2D: self.gpr[rd] = (a+b) & MASK
            elif fn == 0x3C: self.gpr[rd] = (b << (shift+32)) & MASK
            elif fn == 0x3F: self.gpr[rd] = (signed(b,64) >> (shift+32)) & MASK
            else: raise AssertionError(f'unsupported SPECIAL {fn:x} at {self.pc:x}')
        elif op == 2:
            self.pending = ((self.pc+4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
        elif op == 3:
            self.gpr[31] = self.pc + 8
            self.pending = ((self.pc+4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
        elif op in (4,5):
            if (a == b) == (op == 4): self.pending = self.pc+4+4*immediate
        elif op in (6,7):
            if (signed(a,64) <= 0) == (op == 6): self.pending = self.pc+4+4*immediate
        elif op == 9: self.gpr[rt] = signed(a+immediate,32) & MASK
        elif op == 10: self.gpr[rt] = int(signed(a,64) < immediate)
        elif op == 12: self.gpr[rt] = a & (word & 65535)
        elif op == 13: self.gpr[rt] = a | (word & 65535)
        elif op == 15: self.gpr[rt] = signed((word & 65535) << 16,32) & MASK
        elif op in (0x20,0x21,0x23,0x24,0x25,0x37,0x1E):
            size = {0x20:1,0x21:2,0x23:4,0x24:1,0x25:2,0x37:8,0x1E:16}[op]
            value = self.memory.get(a+immediate,size)
            self.gpr[rt] = signed(value,size*8) & MASK if op in (0x20,0x21,0x23) else value
        elif op in (0x28,0x29,0x2B,0x3F,0x1F):
            size = {0x28:1,0x29:2,0x2B:4,0x3F:8,0x1F:16}[op]
            self.memory.put(a+immediate,b,size)
        elif op == 0x31: self.fpr[rt] = self.memory.get(a+immediate)
        elif op == 0x11:
            if rs == 8:
                assert rt in (0,1)
                if self.condition == bool(rt): self.pending = self.pc+4+4*immediate
            elif rs == 16 and fn in (0x36,0x34,0x32):
                left,right = fvalue(self.fpr[rd]),fvalue(self.fpr[rt])
                assert abs(left) < float('inf') and abs(right) < float('inf')
                self.condition = {0x36:lambda:left<=right,0x34:lambda:left<right,0x32:lambda:left==right}[fn]()
            else: raise AssertionError(f'unsupported COP1 {word:x}')
        else: raise AssertionError(f'unsupported opcode {op:x}, PC={self.pc:x}')
        self.gpr[0] = 0
        self.pc = pending if pending is not None else self.pc+4

    def run(self):
        for instructions in range(150000):
            if self.pc == STOP:
                assert self.gpr[2] == 0 and self.gpr[29] == STACK
                assert self.gpr[16:24] == self.initial_saved
                return self.calls,self.memory.observable()
            self.step()
        raise AssertionError('instruction budget exhausted')

def fixtures():
    yield dict(label='all_inactive',rows={})
    for flag in (1,3,0x4001,0x2001,0x6001):
        for opacity,scaleX,scaleY in ((145,1.,2.),(0,1.,2.),(128,0.,2.),(255,1.,-1.),(7,-0.,0.)):
            yield dict(label=f'gate_{flag:x}_{opacity}_{scaleX}_{scaleY}',rows={3:dict(flags=flag,opacity=opacity,scaleX=scaleX,scaleY=scaleY)})
    for flag in (0x4001,0x2001):
        for bit in range(1,14):
            yield dict(label=f'scan_{flag:x}_bit{bit}',rows={0:dict(flags=flag | (1<<bit),scaleX=-1.)})
    for flag in (1,3,0x4001,0x2001):
        yield dict(label=f'animation_clears_active_{flag:x}',rows={779:dict(flags=flag)},animation_flags=flag & ~1)
        yield dict(label=f'culling_clears_active_{flag:x}',rows={0:dict(flags=flag)},cull_inactive=True)
    for field in ('positionFlag','opacityFlag'):
        for value in (-128,-1,1,127):
            yield dict(label=f'{field}_{value}',rows={127:dict(opacity=0,**{field:value})})
    for boundary in ('animation','cull','allocate','enqueue','draw'):
        yield dict(label='replace_'+boundary,rows={1:dict(flags=0x4001),3:dict(flags=0x2001),779:dict(flags=1)},swap=boundary)
    yield dict(label='mixed_sparse',rows={0:dict(flags=0x4001),1:dict(opacity=0),3:dict(flags=3,opacity=0),127:dict(flags=0x2001,scaleX=-1.),779:dict(flags=1)})
    for flag in (1,0x4001,0x2001):
        for field in ('scaleX','scaleY'):
            for bits in (0x3DCCCCCC,0x3DCCCCCD,0x3DCCCCCE):
                yield dict(label=f'cutoff_{flag:x}_{field}_{bits:08x}',rows={3:dict(flags=flag,**{field:fvalue(bits)})})

def audit_pair(target, candidate, gp, global_address, threshold_address):
    receipts,covered = [],set()
    for case in fixtures():
        expected = Machine(target,case,gp,global_address,threshold_address)
        actual = Machine(candidate,case,gp,global_address,threshold_address)
        e,a = expected.run(),actual.run()
        covered.update(expected.covered)
        receipts.append(dict(case=case['label'],equal=e==a,
            retail_calls=len(e[0]),candidate_calls=len(a[0]),
            retail_observables_sha256=sha(json.dumps(e,sort_keys=True).encode()),
            candidate_observables_sha256=sha(json.dumps(a,sort_keys=True).encode())))
    return dict(target_sha256=sha(target),candidate_sha256=sha(candidate),
        cases=len(receipts),passed=sum(r['equal'] for r in receipts),
        retail_instructions_covered=len(covered),
        uncovered_offsets=[off for off in range(0,1524,4) if ADDR+off not in covered],
        scope='Finite ordered comparisons; hooked providers; volatile GPR/FPR poisoning; full observable-memory and call-channel comparison',
        results=receipts)
