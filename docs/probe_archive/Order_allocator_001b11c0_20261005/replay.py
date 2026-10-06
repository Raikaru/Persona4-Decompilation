"""Replay the captured coloring and a diagnostic alternative without a compiler."""
from pathlib import Path
import hashlib
import json

HERE = Path(__file__).resolve().parent


def coloring(graph, order):
    nodes = graph["nodes"]
    count = graph["physical_node_count"]
    assert sorted(order) == list(range(count, len(nodes)))
    colors = list(range(count)) + [-1] * (len(nodes) - count)
    for index in order:
        available = graph["ordinary_mask"]
        for neighbor in nodes[index]["neighbors"]:
            assert 0 <= neighbor < len(nodes)
            if colors[neighbor] >= 0:
                available &= ~(1 << colors[neighbor])
        assert available, (index, "Unexpected spill in this bounded graph")
        colors[index] = (available & -available).bit_length() - 1
    return colors


def main():
    receipt = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    raw = (HERE / "graph.json").read_bytes()
    assert hashlib.sha256(raw).hexdigest() == receipt["normalized_graph_sha256"]
    graph = json.loads(raw)
    assert graph["schema_version"] == 1 and len(graph["nodes"]) == 64
    original = graph["validated_coloring_order"]
    baseline = coloring(graph, original)
    assert baseline == [node["assigned_color"] for node in graph["nodes"]]
    alternate = [node for node in original if node not in (37, 38, 48)]
    at = alternate.index(36)
    alternate[at:at] = [37, 38, 48]
    candidate = coloring(graph, alternate)
    changes = {index: [before, after] for index, (before, after) in enumerate(zip(baseline, candidate))
               if before != after}
    assert changes == {37: [11, 9], 48: [9, 11]}
    assert candidate[38] == baseline[38] == 10
    print(json.dumps({"captured_colors_reproduced": 64, "diagnostic_changes": changes,
                      "retail_trio_colors": {"key": candidate[48], "scan": candidate[38], "index": candidate[37]},
                      "compiler_invoked": False, "native_object_modified": False,
                      "exact_C_candidate": False}, indent=2))


if __name__ == "__main__":
    main()
