

tree grammar Eval;

options {
  backtrack=true;
  tokenVocab=Lua;
  language=Python;
  output=AST;
  ASTLabelType=CommonTree;
}

prog: (stat {print($stat.tree.toStringTree())})+ ;

chunk : (stat (';')?)* (laststat (';')?)?;

block : chunk;

stat :  ^('=' varlist1 explist1) |  
	functioncall | 
	'do' block 'end' | 
	'while' exp 'do' block 'end' | 
	'if' exp 'then' block ('elseif' exp 'then' block)* ('else' block)? 'end' | 
	'for' namelist 'in' var 'do' block 'end' | 
	'function' funcname funcbody | 
	'local' 'function' NAME funcbody | 
	^('=' 'local' namelist explist1);

laststat : 'return' (explist1)? | 'break' | 'continue';

funcname : NAME ('.' NAME)* (':' NAME)? ;

varlist1 : var (',' var)*;

namelist : NAME (',' NAME)*;

explist1 : exp (',' exp)*;

exp :  ('nil' | 'false' | 'true' | number | string | '...' | function | prefixexp | tableconstructor | unop exp) (('+'^ | '-'^ | '*'^ | '/'^ | '^'^ | '%'^ | '..'^ | '<'^ | '<='^ | '>'^ | '>='^ | '=='^ | '~='^ | 'and'^ | 'or'^) exp)* ;

var: (NAME | '('! exp ')'! varSuffix) varSuffix*;

prefixexp: varOrExp nameAndArgs*;

functioncall: varOrExp nameAndArgs+;

/*
var :  NAME | prefixexp '[' exp ']' | prefixexp '.' NAME; 

prefixexp : var | functioncall | '(' exp ')';

functioncall :  prefixexp args | prefixexp ':' NAME args ;
*/

varOrExp: var | '('! exp ')'!; 

nameAndArgs: (':' NAME)? args;

varSuffix: nameAndArgs* ('[' exp ']' | '.' NAME);

args :  '(' (explist1)? ')' | tableconstructor | string ;

function : 'function' funcbody;

funcbody : '(' (parlist1)? ')' block 'end';

parlist1 : namelist (',' '...')? | '...';

tableconstructor : '{' (fieldlist)? '}';

fieldlist : field (fieldsep field)* (fieldsep)?;

field : '[' exp ']' '=' exp | NAME '=' exp | exp;

fieldsep : ',' | ';';

unop : '-' | 'not' | '#';

number : INT | FLOAT | EXP | HEX;

string	: NORMALSTRING | CHARSTRING | LONGSTRING;



