#!/usr/bin/env python
""" Usage: call with <filename> <typename>
"""

import sys
import clang.cindex

from clang.cindex import Config
from clang.cindex import Cursor

Config.set_library_file("/usr/lib/llvm-3.8/lib/libclang-3.8.so.1")

def find_typerefs(node, typename):
    """ Find all references to the type named 'typename'
    """
    if node.kind.is_reference():
        ref_node = clang.cindex.Cursor_ref(node)
        if ref_node.spelling == typename:
            print 'Found %s [line=%s, col=%s]' % (
                typename, node.location.line, node.location.column)
    # Recurse for children of this node
    for c in node.get_children():
        find_typerefs(c, typename)

index = clang.cindex.Index.create()
tu = index.parse(sys.argv[1])
print 'Translation unit:', tu.spelling
find_typerefs(tu.cursor, sys.argv[2])
