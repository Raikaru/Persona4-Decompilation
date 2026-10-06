"""Authenticated unified-patch reconstruction, reused from the follower replay."""
import re

def apply_recorded_patch(raw, patch, reverse=False):
    """Apply one authenticated unified diff, checking every preimage line."""
    source = raw.decode('utf-8').splitlines(keepends=True)
    lines = patch.decode('utf-8').splitlines(keepends=True)
    output, position, cursor = [], 0, 0
    hunks = 0
    while cursor < len(lines):
        match = re.match(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@', lines[cursor])
        if not match:
            assert lines[cursor].startswith(('--- ', '+++ ')), lines[cursor]
            cursor += 1
            continue
        old_start, old_count = int(match[1]), int(match[2] or 1)
        new_start, new_count = int(match[3]), int(match[4] or 1)
        start = (new_start if reverse else old_start) - 1
        assert start >= position
        output.extend(source[position:start])
        position = start
        cursor += 1
        consumed = added = 0
        while cursor < len(lines) and not lines[cursor].startswith('@@ '):
            line = lines[cursor]
            assert line and line[0] in ' +-', line
            operation, payload = line[0], line[1:]
            if reverse and operation != ' ':
                operation = '+' if operation == '-' else '-'
            if operation in (' ', '-'):
                assert position < len(source) and source[position] == payload, (hunks, position + 1)
                position += 1
                consumed += 1
            if operation in (' ', '+'):
                output.append(payload)
                added += 1
            cursor += 1
        assert consumed == (new_count if reverse else old_count)
        assert added == (old_count if reverse else new_count)
        hunks += 1
    assert hunks
    output.extend(source[position:])
    return ''.join(output).encode('utf-8')
