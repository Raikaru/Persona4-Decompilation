"""Replay the unmodified b210 simplify routine on its retained native graph.

This checks the recorded allocator order only. It neither predicts liveness
from source nor changes a compiler, register graph, C source, or output object.
"""
from pathlib import Path
import hashlib
import json

HERE = Path(__file__).resolve().parent / 'allocation-evidence'
binding = json.loads((HERE / 'binding.json').read_text())
for name, row in binding.items():
    assert hashlib.sha256((HERE / name).read_bytes()).hexdigest() == row['sha256'], name

document = json.loads((HERE / '000019-after_colorgraph_assignment.json').read_text())
expected = json.loads((HERE / '000019-after_colorgraph_assignment-replay.json').read_text())
data = document['register_allocation']
nodes = data['nodes']
by_name = {node['id']: node['array_index'] for node in nodes}
neighbors = {node['array_index']: [by_name[name] for name in node['neighbors']] for node in nodes}
flags = {node['array_index']: int(node['flags_raw_u16'], 16) for node in nodes}
assert not any(value & 4 for value in flags.values()), 'This retained graph has no coalesced aliases'

# Native b210 constants loaded by 004c1de0 from 005e90d0 and 005e90d4.
secondary_cost = float.fromhex('0x1.fffffep+126')
maximum_cost = float.fromhex('0x1.fffffep+127')


def weight(index, other):
    return 2 if (flags[index] | flags[other]) & 0x200 else 1


resources = data['resources']
ordinary_mask = int(resources['allocatable']['ordinary_mask_recomputed_u32'], 16)
available = {index for index in range(32) if ordinary_mask & (1 << index)}
available.update(resources['fallback']['physical_ids_i32'])
threshold = len(available)
degree = {index: sum(weight(index, other) for other in links) for index, links in neighbors.items()}
remaining = set(range(32, len(nodes)))
removed = []


def remove(index):
    remaining.remove(index)
    removed.append(index)
    for other in neighbors[index]:
        degree[other] -= weight(index, other)


def cost(index):
    if flags[index] & 0x80:
        return maximum_cost
    if flags[index] & 0x400:
        return secondary_cost
    return nodes[index]['spill_score_i32'] / degree[index]


while remaining:
    simplified = False
    for index in sorted(remaining):
        if degree[index] < threshold:
            remove(index)
            simplified = True
    if not simplified:
        remove(min(sorted(remaining, reverse=True), key=cost))

actual_order = list(reversed(removed))
expected_order = [by_name[name] for name in expected['replay']['work_list_order']]
assert actual_order == expected_order
assert all(degree[node['array_index']] == node['dynamic_degree_i16'] for node in nodes)
assert expected['match_observed']
print(json.dumps({'threshold': threshold, 'nodes': len(nodes),
                  'every_simplification_order_entry_equal': True,
                  'every_final_dynamic_degree_equal': True,
                  'retained_colorgraph_replay_equals_observed': True}, indent=2))
