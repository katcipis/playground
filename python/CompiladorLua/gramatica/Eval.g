tree grammar Eval;

options {
  tokenVocab=Lua;
  language=Python;
  output=AST;
  ASTLabelType=CommonTree;
}

prog: (stat)+ {self.handle()};

chunk : (stat (';')?)* (laststat (';')?)?;

block : chunk;

stat :  functioncall {self.handle_call()} | 
	'do' block 'end' | 
	'while' {self.handle_while()} exp 'do' {self.handle_start_while()}block {self.handle_end_while()} 'end'| 
	'if' exp 'then' {self.handle_end_or()}block ('elseif' {self.handle_end_andor()} exp1 'then' block1)* ('else' {self.handle_end_andor()} block2)? 'end' {self.handle_end_and()} | 
	'for' namelist 'in' NAME 'do' block 'end' | 
	'function' funcname? {self.handle_function($funcname.tree) } funcbody {self.handle_end_function()}|
	'local function' NAME  funcbody  | 
	^('=' 'local'? namelist explist1 ) {self.handle_declaracao($namelist.tree)};

laststat : 'return' (explist1)? {self.handle_return()} | 'break' | 'continue';

funcname : NAME ('.' NAME)* (':' NAME)? ;

namelist : NAME (',' NAME)*;

explist1 : exp (',' exp)*;

atom: 'nil' | 'false' | 'true' | string | number  | '...' | function | prefixexp | tableconstructor;

exp: ^('and' {self.handle_and()} exp0 exp1) 
   | ^('or' {self.handle_or()} exp0 exp1 {self.handle_end_all()}) 
   | ^('<' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "lt" , 0)}
   | ^('<=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "le" , 0)}
   | ^('>' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "lt" , 1)}
   | ^('>=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "le" , 1)}
   | ^('==' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "eq" , 0)}
   | ^('~=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "eq" , 1)}
   | ^('+' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "add")}
   | ^('-' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "sub")}
   | ^('*' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "mul")}
   | ^('/' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "div")}
   | ^('^' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "pow")}
   | ^('%' exp0 exp1)
   | ^('..' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "concat")}
   | atom {self.handle_associar($atom.tree)}
   | unop exp
   ;

exp0: expA;
exp1: expA;
block1: block;
block2: block;

expA: ^('and' exp0 exp1) {self.handle_end()}
   | ^('or' exp0 exp1)
   | ^('<' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "lt" , 0)}
   | ^('<=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "le" , 0)}
   | ^('>' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "lt" , 1)}
   | ^('>=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "le" , 1)}
   | ^('==' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "eq" , 0)}
   | ^('~=' exp0 exp1){self.handle_exp_comp($exp0.tree, $exp1.tree, "eq" , 1)}
   | ^('+' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "add")}
   | ^('-' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "sub")}
   | ^('*' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "mul")}
   | ^('/' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "div")}
   | ^('^' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "pow")}
   | ^('%' exp0 exp1)
   | ^('..' exp0 exp1){self.handle_aritmetica($exp0.tree, $exp1.tree, "concat")}
   | atom
   | unop exp
   ;

prefixexp: NAME ((':' NAME) args)*;

functioncall: NAME {self.handle_functioncall($NAME.tree)} nameAndArgs+;

nameAndArgs: (':' NAME)? args;

varSuffix: nameAndArgs* ('[' exp ']' | '.' NAME);

args :  '(' (explist2 {self.handle_function_arg($explist2.tree)} )? ')' | tableconstructor | string ;

explist2 : expA (',' expA)*;

function : 'function' funcbody;

funcbody : '(' (parlist1 {self.handle_parametros($parlist1.tree)})?')' block 'end';

parlist1 : namelist (',' '...')? | '...';

tableconstructor : '{' (fieldlist)? '}';

fieldlist : field (fieldsep field)* (fieldsep)?;

field : '[' exp ']' '=' exp | NAME '=' exp | exp;

fieldsep : ',' | ';';

unop : '-' | 'not' | '#';

number : INT | FLOAT | EXP | HEX;

string	: NORMALSTRING | CHARSTRING | LONGSTRING;

