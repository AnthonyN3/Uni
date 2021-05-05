
import java.io.*;
import java.nio.file.*;
%%

%{
	static int[] ar = new int[5];
	public static void main(String argv[]) throws java.io.IOException {
		A2 yy = new A2(new FileReader("A2.input"));
		yy.yylex();
		Files.write(Paths.get("A2.output"), ("identifiers: "+ar[0]+"\n"+"keywords: "+ar[1]+"\n"+"numbers: "+ar[2]+"\n"+"comments: "+ar[3]+"\n"+"quotedString: "+ar[4]).getBytes());
      }
%}
%notunix
%integer
%type void
%class A2


%state COMMENT
%%

<YYINITIAL>"/**" {yybegin(COMMENT);  ar[3]++;}
<COMMENT>"**/" {yybegin(YYINITIAL); }

<YYINITIAL> \"[^\"]*\" { ar[4]++;}
<YYINITIAL> [0-9]+(\.*[0-9]*)? {ar[2]++;}
<YYINITIAL> WRITE|READ|IF|ELSE|RETURN|BEGIN|END|MAIN|STRING|INT|REAL { ar[1]++;}
<YYINITIAL>[a-zA-Z][a-zA-Z0-9]* { ar[0]++;}
\r|\n|. {}