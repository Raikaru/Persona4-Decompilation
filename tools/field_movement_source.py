"""Extract the Field movement definition for bounded source-fragment witnesses.

This is not a C preprocessor. Outer promotion/guard scaffolding is irrelevant;
directives inside the definition and line splices require explicit preprocessing.
The verifier's lexer masks comments and literals while preserving offsets.
"""
import re

from verify import sanitize_c_lines


def code_view(source):
    """Offset-preserving executable-token view; reject unsupported C splices."""
    # C splicing precedes comment recognition. Reject it rather than let a
    # continued // comment or split directive masquerade as executable code.
    if re.search(r'\?\?[=/\'()!<>-]', source):
        raise ValueError('trigraphs require explicit preprocessing')
    if re.search(r'\\\r?\n', source):
        raise ValueError('line splices require explicit preprocessing')
    lines = source.splitlines(keepends=True)
    # sanitize_c_lines expects lines without their newline (including for
    # backslash-continued literals); restore exact line lengths afterwards.
    code_lines = sanitize_c_lines([line.rstrip('\r\n') for line in lines])
    code = ''.join(clean + line[len(line.rstrip('\r\n')):]
                   for line, clean in zip(lines, code_lines))
    if re.search(r'%:|<%|%>|<:|:>', code):
        raise ValueError('digraphs require explicit preprocessing')
    return code


def movement_definition(source):
    code_lines = code_view(source).splitlines(keepends=True)
    masked = []
    for line in code_lines:
        # Outer guard and pragma lines are not part of the definition.
        masked.append(''.join('\n' if c == '\n' else ' ' for c in line)
                      if line.lstrip().startswith('#') else line)
    code = ''.join(masked)
    matches = list(re.finditer(r'\bs32\s+func_00174e10\s*\(\s*u8\s*\*\s*arg0\s*\)\s*\{', code))
    if len(matches) != 1:
        raise ValueError('expected exactly one Field movement definition')
    start = matches[0].start()
    opening = matches[0].end() - 1
    depth = 0
    for end in range(opening, len(code)):
        depth += (code[end] == '{') - (code[end] == '}')
        if depth == 0:
            body = source[start:end + 1]
            if re.search(r'^\s*#',
                         code_view(body), re.M):
                raise ValueError('directive inside Field movement definition requires explicit preprocessing')
            return body
    raise ValueError('unterminated Field movement definition')
