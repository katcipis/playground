import antlr3
import sys
from LuaLexer import LuaLexer
from LuaParser import LuaParser

if len(sys.argv) < 2 :
  print("Usage {0} [input_file]".format(sys.argv[0]))
  exit()

char_stream = antlr3.ANTLRFileStream(sys.argv[1])

lexer = LuaLexer(char_stream)
tokens = antlr3.CommonTokenStream(lexer)
print("TOKENS = ")
for token in tokens.getTokens():
  print("Token " + token.getText() + " Line [" + str(token.getLine()) + "] Type[" + str(token.getType()) + "]")




