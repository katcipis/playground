java -classpath ../install/antlr-3.1.2.jar org.antlr.Tool -verbose Lua.g
java -classpath ../install/antlr-3.1.2.jar org.antlr.Tool -verbose Eval.g

rm -f ../parser/LuaLexer.py
rm -f ../parser/LuaParser.py
rm -f ../parser/Lua__.g
rm -f ../parser/*.pyc
rm -f ../parser/Lua.tokens

mv *.py ../parser
mv Lua.tokens ../parser
mv Eval.tokens ../parser
