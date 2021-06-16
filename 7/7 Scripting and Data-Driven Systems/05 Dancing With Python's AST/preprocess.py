# -*- coding: GBK -*-
# $Id: preprocess.py 20 2005-12-31 03:34:33Z zouguangxian $
import os
from compiler import ast, pycodegen
import utils

class Visitor:
    def visitCallFunc(self, node):
        func_name = utils.getFullName( node.node )
        if func_name in utils.helper.functions :
            for arg in node.args :
                if isinstance( arg, ast.Const ) :
                    if isinstance( arg.value, basestring ):
                        utils.helper.append( arg.value )

        # lines between '>>>' and '<<<' are copied from pycodegen
        # >>>                                    
        pos = 0
        kw = 0
        self.visit(node.node)        
        for arg in node.args:
            self.visit(arg)
            if isinstance(arg, ast.Keyword):
                kw = kw + 1
            else:
                pos = pos + 1
        if node.star_args is not None:
            self.visit(node.star_args)
        if node.dstar_args is not None:
            self.visit(node.dstar_args)
        # <<<
