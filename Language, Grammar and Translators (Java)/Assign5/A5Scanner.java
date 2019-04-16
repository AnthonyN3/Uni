import java.io.*;

class A5Scanner {
	private final int YY_BUFFER_SIZE = 512;
	private final int YY_F = -1;
	private final int YY_NO_STATE = -1;
	private final int YY_NOT_ACCEPT = 0;
	private final int YY_START = 1;
	private final int YY_END = 2;
	private final int YY_NO_ANCHOR = 4;
	private final int YY_BOL = 128;
	private final int YY_EOF = 129;
	private java.io.BufferedReader yy_reader;
	private int yy_buffer_index;
	private int yy_buffer_read;
	private int yy_buffer_start;
	private int yy_buffer_end;
	private char yy_buffer[];
	private boolean yy_at_bol;
	private int yy_lexical_state;

	A5Scanner (java.io.Reader reader) {
		this ();
		if (null == reader) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(reader);
	}

	A5Scanner (java.io.InputStream instream) {
		this ();
		if (null == instream) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(new java.io.InputStreamReader(instream));
	}

	private A5Scanner () {
		yy_buffer = new char[YY_BUFFER_SIZE];
		yy_buffer_read = 0;
		yy_buffer_index = 0;
		yy_buffer_start = 0;
		yy_buffer_end = 0;
		yy_at_bol = true;
		yy_lexical_state = YYINITIAL;
	}

	private boolean yy_eof_done = false;
	private final int YYINITIAL = 0;
	private final int COMMENT = 1;
	private final int yy_state_dtrans[] = {
		0,
		40
	};
	private void yybegin (int state) {
		yy_lexical_state = state;
	}
	private int yy_advance ()
		throws java.io.IOException {
		int next_read;
		int i;
		int j;

		if (yy_buffer_index < yy_buffer_read) {
			return yy_buffer[yy_buffer_index++];
		}

		if (0 != yy_buffer_start) {
			i = yy_buffer_start;
			j = 0;
			while (i < yy_buffer_read) {
				yy_buffer[j] = yy_buffer[i];
				++i;
				++j;
			}
			yy_buffer_end = yy_buffer_end - yy_buffer_start;
			yy_buffer_start = 0;
			yy_buffer_read = j;
			yy_buffer_index = j;
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}

		while (yy_buffer_index >= yy_buffer_read) {
			if (yy_buffer_index >= yy_buffer.length) {
				yy_buffer = yy_double(yy_buffer);
			}
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}
		return yy_buffer[yy_buffer_index++];
	}
	private void yy_move_end () {
		if (yy_buffer_end > yy_buffer_start &&
		    '\n' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
		if (yy_buffer_end > yy_buffer_start &&
		    '\r' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
	}
	private boolean yy_last_was_cr=false;
	private void yy_mark_start () {
		yy_buffer_start = yy_buffer_index;
	}
	private void yy_mark_end () {
		yy_buffer_end = yy_buffer_index;
	}
	private void yy_to_mark () {
		yy_buffer_index = yy_buffer_end;
		yy_at_bol = (yy_buffer_end > yy_buffer_start) &&
		            ('\r' == yy_buffer[yy_buffer_end-1] ||
		             '\n' == yy_buffer[yy_buffer_end-1] ||
		             2028/*LS*/ == yy_buffer[yy_buffer_end-1] ||
		             2029/*PS*/ == yy_buffer[yy_buffer_end-1]);
	}
	private java.lang.String yytext () {
		return (new java.lang.String(yy_buffer,
			yy_buffer_start,
			yy_buffer_end - yy_buffer_start));
	}
	private int yylength () {
		return yy_buffer_end - yy_buffer_start;
	}
	private char[] yy_double (char buf[]) {
		int i;
		char newbuf[];
		newbuf = new char[2*buf.length];
		for (i = 0; i < buf.length; ++i) {
			newbuf[i] = buf[i];
		}
		return newbuf;
	}
	private final int YY_E_INTERNAL = 0;
	private final int YY_E_MATCH = 1;
	private java.lang.String yy_error_string[] = {
		"Error: Internal error.\n",
		"Error: Unmatched input.\n"
	};
	private void yy_error (int code,boolean fatal) {
		java.lang.System.out.print(yy_error_string[code]);
		java.lang.System.out.flush();
		if (fatal) {
			throw new Error("Fatal Error.\n");
		}
	}
	private int[][] unpackFromString(int size1, int size2, String st) {
		int colonIndex = -1;
		String lengthString;
		int sequenceLength = 0;
		int sequenceInteger = 0;

		int commaIndex;
		String workString;

		int res[][] = new int[size1][size2];
		for (int i= 0; i < size1; i++) {
			for (int j= 0; j < size2; j++) {
				if (sequenceLength != 0) {
					res[i][j] = sequenceInteger;
					sequenceLength--;
					continue;
				}
				commaIndex = st.indexOf(',');
				workString = (commaIndex==-1) ? st :
					st.substring(0, commaIndex);
				st = st.substring(commaIndex+1);
				colonIndex = workString.indexOf(':');
				if (colonIndex == -1) {
					res[i][j]=Integer.parseInt(workString);
					continue;
				}
				lengthString =
					workString.substring(colonIndex+1);
				sequenceLength=Integer.parseInt(lengthString);
				workString=workString.substring(0,colonIndex);
				sequenceInteger=Integer.parseInt(workString);
				res[i][j] = sequenceInteger;
				sequenceLength--;
			}
		}
		return res;
	}
	private int yy_acpt[] = {
		/* 0 */ YY_NOT_ACCEPT,
		/* 1 */ YY_NO_ANCHOR,
		/* 2 */ YY_NO_ANCHOR,
		/* 3 */ YY_NO_ANCHOR,
		/* 4 */ YY_NO_ANCHOR,
		/* 5 */ YY_NO_ANCHOR,
		/* 6 */ YY_NO_ANCHOR,
		/* 7 */ YY_NO_ANCHOR,
		/* 8 */ YY_NO_ANCHOR,
		/* 9 */ YY_NO_ANCHOR,
		/* 10 */ YY_NO_ANCHOR,
		/* 11 */ YY_NO_ANCHOR,
		/* 12 */ YY_NO_ANCHOR,
		/* 13 */ YY_NO_ANCHOR,
		/* 14 */ YY_NO_ANCHOR,
		/* 15 */ YY_NO_ANCHOR,
		/* 16 */ YY_NO_ANCHOR,
		/* 17 */ YY_NO_ANCHOR,
		/* 18 */ YY_NO_ANCHOR,
		/* 19 */ YY_NO_ANCHOR,
		/* 20 */ YY_NO_ANCHOR,
		/* 21 */ YY_NO_ANCHOR,
		/* 22 */ YY_NO_ANCHOR,
		/* 23 */ YY_NO_ANCHOR,
		/* 24 */ YY_NO_ANCHOR,
		/* 25 */ YY_NO_ANCHOR,
		/* 26 */ YY_NO_ANCHOR,
		/* 27 */ YY_NO_ANCHOR,
		/* 28 */ YY_NO_ANCHOR,
		/* 29 */ YY_NO_ANCHOR,
		/* 30 */ YY_NO_ANCHOR,
		/* 31 */ YY_NO_ANCHOR,
		/* 32 */ YY_NOT_ACCEPT,
		/* 33 */ YY_NO_ANCHOR,
		/* 34 */ YY_NO_ANCHOR,
		/* 35 */ YY_NO_ANCHOR,
		/* 36 */ YY_NO_ANCHOR,
		/* 37 */ YY_NOT_ACCEPT,
		/* 38 */ YY_NO_ANCHOR,
		/* 39 */ YY_NO_ANCHOR,
		/* 40 */ YY_NOT_ACCEPT,
		/* 41 */ YY_NO_ANCHOR,
		/* 42 */ YY_NO_ANCHOR,
		/* 43 */ YY_NOT_ACCEPT,
		/* 44 */ YY_NO_ANCHOR,
		/* 45 */ YY_NO_ANCHOR,
		/* 46 */ YY_NO_ANCHOR,
		/* 47 */ YY_NO_ANCHOR,
		/* 48 */ YY_NO_ANCHOR,
		/* 49 */ YY_NO_ANCHOR,
		/* 50 */ YY_NO_ANCHOR,
		/* 51 */ YY_NO_ANCHOR,
		/* 52 */ YY_NO_ANCHOR,
		/* 53 */ YY_NO_ANCHOR,
		/* 54 */ YY_NO_ANCHOR,
		/* 55 */ YY_NO_ANCHOR,
		/* 56 */ YY_NO_ANCHOR,
		/* 57 */ YY_NO_ANCHOR,
		/* 58 */ YY_NO_ANCHOR,
		/* 59 */ YY_NO_ANCHOR,
		/* 60 */ YY_NO_ANCHOR,
		/* 61 */ YY_NO_ANCHOR,
		/* 62 */ YY_NO_ANCHOR,
		/* 63 */ YY_NO_ANCHOR,
		/* 64 */ YY_NO_ANCHOR,
		/* 65 */ YY_NO_ANCHOR,
		/* 66 */ YY_NO_ANCHOR,
		/* 67 */ YY_NO_ANCHOR,
		/* 68 */ YY_NO_ANCHOR,
		/* 69 */ YY_NO_ANCHOR,
		/* 70 */ YY_NO_ANCHOR
	};
	private int yy_cmap[] = unpackFromString(1,130,
"9:9,32:2,9:2,32,9:18,32,5,8,9:5,11,12,2,6,13,7,30,1,29:10,3,10,9,4,9:3,19,2" +
"6,31,20,18,21,27,31,16,31:2,22,28,25,31:3,15,23,17,24,31,14,31:3,9:6,31:26," +
"9:5,0:2")[0];

	private int yy_rmap[] = unpackFromString(1,71,
"0,1,2,1,3,1:6,4,5,1:5,6,1,6:10,1:2,7,8,9,10,11,12,13,14,15,12,16,17,1,18,19" +
",20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,6,41,42")[0];

	private int yy_nxt[][] = unpackFromString(43,33,
"1,2,3,4,33,38,5,6,41,44,7,8,9,10,11,61,34,68,52,68:4,69,68:2,70,68,62,12,44" +
",68,13,-1:35,32,-1:34,14,-1:42,68,63,68:14,-1,68,-1:30,12,53,-1:16,68:16,-1" +
",68,-1:3,19,-1:34,15,-1:42,68:7,18,68:3,39,68:4,-1,68,-1:30,35,-1:5,43,-1:3" +
"1,37:7,17,37:24,-1:4,16,-1:42,68:3,20,68:12,-1,68,-1,1,30,36,30:30,-1:14,68" +
":6,21,68:9,-1,68,-1:2,31,-1:45,68:6,22,68,23,68:7,-1,68,-1:15,68:4,24,68:11" +
",-1,68,-1:15,68:11,25,68:4,-1,68,-1:15,68:4,26,68:11,-1,68,-1:15,68:11,27,6" +
"8:4,-1,68,-1:15,68:11,28,68:4,-1,68,-1:15,68:13,29,68:2,-1,68,-1:15,68:8,55" +
",68:2,42,68:4,-1,68,-1:30,35,53,-1:16,68:3,66,68,45,68:10,-1,68,-1:15,68:9," +
"46,68:6,-1,68,-1:15,68:2,47,68:13,-1,68,-1:15,68:3,48,68:12,-1,68,-1:15,68:" +
"2,49,68:13,-1,68,-1:15,68,50,68:14,-1,68,-1:15,68:11,51,68:4,-1,68,-1:15,68" +
":4,54,68:11,-1,68,-1:15,68:5,56,68:10,-1,68,-1:15,68:2,57,68:13,-1,68,-1:15" +
",68,67,68:14,-1,68,-1:15,68:13,58,68:2,-1,68,-1:15,68:10,59,68:5,-1,68,-1:1" +
"5,68:2,60,68:13,-1,68,-1:15,68:3,64,68:12,-1,68,-1:15,68:4,65,68:11,-1,68,-" +
"1");

	public Symbol yylex ()
		throws java.io.IOException {
		int yy_lookahead;
		int yy_anchor = YY_NO_ANCHOR;
		int yy_state = yy_state_dtrans[yy_lexical_state];
		int yy_next_state = YY_NO_STATE;
		int yy_last_accept_state = YY_NO_STATE;
		boolean yy_initial = true;
		int yy_this_accept;

		yy_mark_start();
		yy_this_accept = yy_acpt[yy_state];
		if (YY_NOT_ACCEPT != yy_this_accept) {
			yy_last_accept_state = yy_state;
			yy_mark_end();
		}
		while (true) {
			if (yy_initial && yy_at_bol) yy_lookahead = YY_BOL;
			else yy_lookahead = yy_advance();
			yy_next_state = YY_F;
			yy_next_state = yy_nxt[yy_rmap[yy_state]][yy_cmap[yy_lookahead]];
			if (YY_EOF == yy_lookahead && true == yy_initial) {
 return new Symbol(A5Sym.EOF);
			}
			if (YY_F != yy_next_state) {
				yy_state = yy_next_state;
				yy_initial = false;
				yy_this_accept = yy_acpt[yy_state];
				if (YY_NOT_ACCEPT != yy_this_accept) {
					yy_last_accept_state = yy_state;
					yy_mark_end();
				}
			}
			else {
				if (YY_NO_STATE == yy_last_accept_state) {
					throw (new Error("Lexical Error: Unmatched Input."));
				}
				else {
					yy_anchor = yy_acpt[yy_last_accept_state];
					if (0 != (YY_END & yy_anchor)) {
						yy_move_end();
					}
					yy_to_mark();
					switch (yy_last_accept_state) {
					case 1:
						
					case -2:
						break;
					case 2:
						{ return new Symbol(A5Sym.DIVIDE); }
					case -3:
						break;
					case 3:
						{ return new Symbol(A5Sym.TIMES); }
					case -4:
						break;
					case 4:
						{return new Symbol(A5Sym.error);}
					case -5:
						break;
					case 5:
						{ return new Symbol(A5Sym.PLUS); }
					case -6:
						break;
					case 6:
						{ return new Symbol(A5Sym.MINUS); }
					case -7:
						break;
					case 7:
						{return new Symbol(A5Sym.SEMICOLON); }
					case -8:
						break;
					case 8:
						{return new Symbol(A5Sym.OP); }
					case -9:
						break;
					case 9:
						{return new Symbol(A5Sym.CP); }
					case -10:
						break;
					case 10:
						{return new Symbol(A5Sym.COMMA); }
					case -11:
						break;
					case 11:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -12:
						break;
					case 12:
						{ return new Symbol(A5Sym.NUM,yytext()); }
					case -13:
						break;
					case 13:
						{}
					case -14:
						break;
					case 14:
						{ return new Symbol(A5Sym.ASSIGN); }
					case -15:
						break;
					case 15:
						{ return new Symbol(A5Sym.EQUAL); }
					case -16:
						break;
					case 16:
						{ return new Symbol(A5Sym.NOTEQUAL); }
					case -17:
						break;
					case 17:
						{return new Symbol(A5Sym.QUOTE,yytext());}
					case -18:
						break;
					case 18:
						{ return new Symbol(A5Sym.IF);}
					case -19:
						break;
					case 19:
						{yybegin(COMMENT); }
					case -20:
						break;
					case 20:
						{ return new Symbol(A5Sym.INT);}
					case -21:
						break;
					case 21:
						{ return new Symbol(A5Sym.END);}
					case -22:
						break;
					case 22:
						{ return new Symbol(A5Sym.READ); }
					case -23:
						break;
					case 23:
						{ return new Symbol(A5Sym.REAL);}
					case -24:
						break;
					case 24:
						{ return new Symbol(A5Sym.ELSE);}
					case -25:
						break;
					case 25:
						{ return new Symbol(A5Sym.MAIN);}
					case -26:
						break;
					case 26:
						{ return new Symbol(A5Sym.WRITE); }
					case -27:
						break;
					case 27:
						{ return new Symbol(A5Sym.BEGIN);}
					case -28:
						break;
					case 28:
						{ return new Symbol(A5Sym.RETURN);}
					case -29:
						break;
					case 29:
						{ return new Symbol(A5Sym.STRING);}
					case -30:
						break;
					case 30:
						{}
					case -31:
						break;
					case 31:
						{yybegin(YYINITIAL); }
					case -32:
						break;
					case 33:
						{return new Symbol(A5Sym.error);}
					case -33:
						break;
					case 34:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -34:
						break;
					case 35:
						{ return new Symbol(A5Sym.NUM,yytext()); }
					case -35:
						break;
					case 36:
						{}
					case -36:
						break;
					case 38:
						{return new Symbol(A5Sym.error);}
					case -37:
						break;
					case 39:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -38:
						break;
					case 41:
						{return new Symbol(A5Sym.error);}
					case -39:
						break;
					case 42:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -40:
						break;
					case 44:
						{return new Symbol(A5Sym.error);}
					case -41:
						break;
					case 45:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -42:
						break;
					case 46:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -43:
						break;
					case 47:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -44:
						break;
					case 48:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -45:
						break;
					case 49:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -46:
						break;
					case 50:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -47:
						break;
					case 51:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -48:
						break;
					case 52:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -49:
						break;
					case 53:
						{ return new Symbol(A5Sym.NUM,yytext()); }
					case -50:
						break;
					case 54:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -51:
						break;
					case 55:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -52:
						break;
					case 56:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -53:
						break;
					case 57:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -54:
						break;
					case 58:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -55:
						break;
					case 59:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -56:
						break;
					case 60:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -57:
						break;
					case 61:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -58:
						break;
					case 62:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -59:
						break;
					case 63:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -60:
						break;
					case 64:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -61:
						break;
					case 65:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -62:
						break;
					case 66:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -63:
						break;
					case 67:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -64:
						break;
					case 68:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -65:
						break;
					case 69:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -66:
						break;
					case 70:
						{return new Symbol(A5Sym.ID,yytext()); }
					case -67:
						break;
					default:
						yy_error(YY_E_INTERNAL,false);
					case -1:
					}
					yy_initial = true;
					yy_state = yy_state_dtrans[yy_lexical_state];
					yy_next_state = YY_NO_STATE;
					yy_last_accept_state = YY_NO_STATE;
					yy_mark_start();
					yy_this_accept = yy_acpt[yy_state];
					if (YY_NOT_ACCEPT != yy_this_accept) {
						yy_last_accept_state = yy_state;
						yy_mark_end();
					}
				}
			}
		}
	}
}
