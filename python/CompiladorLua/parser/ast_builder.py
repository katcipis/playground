import antlr3
import sys
from LuaLexer import LuaLexer
from LuaParser import LuaParser
from Translator import Translator

if len(sys.argv) < 2 :
  print("Usage {0} [input_file]".format(sys.argv[0]))
  exit()

char_stream = antlr3.ANTLRFileStream(sys.argv[1])

lexer = LuaLexer(char_stream)
tokens = antlr3.CommonTokenStream(lexer)
parser = LuaParser(tokens)

r = parser.prog()
#this is the root of the AST
root = r.tree
print("-------------")
nodes = antlr3.tree.CommonTreeNodeStream(root)
nodes.setTokenStream(tokens)

eval = Translator(nodes)
eval.prog()



