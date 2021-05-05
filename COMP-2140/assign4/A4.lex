import java_cup.runtime.*;
%%
%implements Scanner
%type Symbol
%function next_token
%class A4Scanner
%eofval{ return null;
%eofval}

IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
NUMBER = [0-9]+(\.*[0-9]*)?	//[0-9]+

%state COMMENT
%%

<YYINITIAL>"/**" {yybegin(COMMENT); }
<COMMENT>"**/" {yybegin(YYINITIAL); }

<YYINITIAL>":=" { return new Symbol(A4Symbol.ASSIGN); }
<YYINITIAL>"==" { return new Symbol(A4Symbol.EQUAL); }
<YYINITIAL>"!=" { return new Symbol(A4Symbol.NOTEQUAL); }

<YYINITIAL>"+" { return new Symbol(A4Symbol.PLUS); }
<YYINITIAL>"-" { return new Symbol(A4Symbol.MINUS); }
<YYINITIAL>"*" { return new Symbol(A4Symbol.TIMES); }
<YYINITIAL>"/" { return new Symbol(A4Symbol.DIVIDE); }

<YYINITIAL> \"[^\"]*\" {return new Symbol(A4Symbol.QUOTE,yytext());}

<YYINITIAL>";" {return new Symbol(A4Symbol.SEMICOLON); }
<YYINITIAL>"(" {return new Symbol(A4Symbol.OP); }
<YYINITIAL>")" {return new Symbol(A4Symbol.CP); }
<YYINITIAL>"," {return new Symbol(A4Symbol.COMMA); }

<YYINITIAL>WRITE { return new Symbol(A4Symbol.WRITE); }
<YYINITIAL>READ	{ return new Symbol(A4Symbol.READ); }
<YYINITIAL>IF	{ return new Symbol(A4Symbol.IF);}
<YYINITIAL>ELSE	{ return new Symbol(A4Symbol.ELSE);}
<YYINITIAL>RETURN { return new Symbol(A4Symbol.RETURN);}
<YYINITIAL>BEGIN	{ return new Symbol(A4Symbol.BEGIN);}
<YYINITIAL>END	{ return new Symbol(A4Symbol.END);}
<YYINITIAL>MAIN	{ return new Symbol(A4Symbol.MAIN);}

<YYINITIAL> INT { return new Symbol(A4Symbol.INT);}
<YYINITIAL> REAL { return new Symbol(A4Symbol.REAL);}
<YYINITIAL> STRING { return new Symbol(A4Symbol.STRING);}


<YYINITIAL> {NUMBER} { return new Symbol(A4Symbol.NUM,yytext()); }  
<YYINITIAL> {IDENTIFIER} {return new Symbol(A4Symbol.ID,yytext()); }



<YYINITIAL>\r|\n|\t|" " {}
<YYINITIAL>. {return new Symbol(A4Symbol.error);}
.|\r|\n {}


