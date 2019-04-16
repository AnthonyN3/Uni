import java_cup.runtime.Symbol;
import java_cup.runtime.Scanner;
%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A3Scanner
%eofval{ return null;
%eofval}

IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
NUMBER = [0-9]+(\.*[0-9]*)?	//[0-9]+

%state COMMENT
%%

<YYINITIAL>"/**" {yybegin(COMMENT); }
<COMMENT>"**/" {yybegin(YYINITIAL); }

<YYINITIAL> ":=" { return new Symbol(A3Symbol.ASSIGN); }
<YYINITIAL> "==" { return new Symbol(A3Symbol.EQUAL); }
<YYINITIAL> "!=" { return new Symbol(A3Symbol.NOTEQUAL); }

<YYINITIAL> "+" { return new Symbol(A3Symbol.PLUS); }
<YYINITIAL> "-" { return new Symbol(A3Symbol.MINUS); }
<YYINITIAL> "*" { return new Symbol(A3Symbol.TIMES); }
<YYINITIAL> "/" { return new Symbol(A3Symbol.DIVIDE); }

<YYINITIAL> \"[^\"]*\" {return new Symbol(A3Symbol.QUOTE);}

<YYINITIAL> ";" {return new Symbol(A3Symbol.SEMICOLON); }
<YYINITIAL> "(" {return new Symbol(A3Symbol.OP); }
<YYINITIAL> ")" {return new Symbol(A3Symbol.CP); }
<YYINITIAL> "," {return new Symbol(A3Symbol.COMMA); }

<YYINITIAL> "WRITE" { return new Symbol(A3Symbol.WRITE); }
<YYINITIAL> "READ"	{ return new Symbol(A3Symbol.READ); }
<YYINITIAL> "IF"	{ return new Symbol(A3Symbol.IF);}
<YYINITIAL> "ELSE"	{ return new Symbol(A3Symbol.ELSE);}
<YYINITIAL> "RETURN" { return new Symbol(A3Symbol.RETURN);}
<YYINITIAL> "BEGIN"	{ return new Symbol(A3Symbol.BEGIN);}
<YYINITIAL> "END"	{ return new Symbol(A3Symbol.END);}
<YYINITIAL> "MAIN"	{ return new Symbol(A3Symbol.MAIN);}

<YYINITIAL> INT|REAL|STRING { return new Symbol(A3Symbol.TYPE);}

<YYINITIAL> {NUMBER} { return new Symbol(A3Symbol.NUM); }  
<YYINITIAL> {IDENTIFIER} {return new Symbol(A3Symbol.ID); }

<YYINITIAL>\r|\n|\t|" " {}
<YYINITIAL>. {return new Symbol(A3Symbol.error);}
.|\r|\n {}


