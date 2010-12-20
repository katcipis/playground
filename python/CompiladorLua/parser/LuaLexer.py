# $ANTLR 3.1.2 Lua.g 2010-11-30 13:20:04

import sys
from antlr3 import *
from antlr3.compat import set, frozenset


# for convenience in actions
HIDDEN = BaseRecognizer.HIDDEN

# token types
T__64=64
T__29=29
T__65=65
T__28=28
T__27=27
T__62=62
T__26=26
T__63=63
T__25=25
T__24=24
T__23=23
T__22=22
T__21=21
T__20=20
FLOAT=6
T__61=61
EOF=-1
T__60=60
HexDigit=15
T__55=55
T__56=56
T__57=57
NAME=4
T__58=58
T__51=51
T__52=52
T__53=53
T__54=54
EXP=7
HEX=8
T__59=59
COMMENT=16
T__50=50
T__42=42
T__43=43
T__40=40
T__41=41
T__46=46
T__47=47
T__44=44
T__45=45
LINE_COMMENT=17
T__48=48
T__49=49
INT=5
CHARSTRING=10
LONGSTRING=11
T__30=30
T__31=31
NORMALSTRING=9
T__32=32
T__33=33
WS=18
T__34=34
T__35=35
NEWLINE=19
T__36=36
T__37=37
T__38=38
T__39=39
UnicodeEscape=13
EscapeSequence=12
OctalEscape=14


class LuaLexer(Lexer):

    grammarFileName = "Lua.g"
    antlr_version = version_str_to_tuple("3.1.2")
    antlr_version_str = "3.1.2"

    def __init__(self, input=None, state=None):
        if state is None:
            state = RecognizerSharedState()
        Lexer.__init__(self, input, state)

        self.dfa3 = self.DFA3(
            self, 3,
            eot = self.DFA3_eot,
            eof = self.DFA3_eof,
            min = self.DFA3_min,
            max = self.DFA3_max,
            accept = self.DFA3_accept,
            special = self.DFA3_special,
            transition = self.DFA3_transition
            )

        self.dfa17 = self.DFA17(
            self, 17,
            eot = self.DFA17_eot,
            eof = self.DFA17_eof,
            min = self.DFA17_min,
            max = self.DFA17_max,
            accept = self.DFA17_accept,
            special = self.DFA17_special,
            transition = self.DFA17_transition
            )






    # $ANTLR start "T__20"
    def mT__20(self, ):

        try:
            _type = T__20
            _channel = DEFAULT_CHANNEL

            # Lua.g:7:7: ( ';' )
            # Lua.g:7:9: ';'
            pass 
            self.match(59)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__20"



    # $ANTLR start "T__21"
    def mT__21(self, ):

        try:
            _type = T__21
            _channel = DEFAULT_CHANNEL

            # Lua.g:8:7: ( 'do' )
            # Lua.g:8:9: 'do'
            pass 
            self.match("do")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__21"



    # $ANTLR start "T__22"
    def mT__22(self, ):

        try:
            _type = T__22
            _channel = DEFAULT_CHANNEL

            # Lua.g:9:7: ( 'end' )
            # Lua.g:9:9: 'end'
            pass 
            self.match("end")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__22"



    # $ANTLR start "T__23"
    def mT__23(self, ):

        try:
            _type = T__23
            _channel = DEFAULT_CHANNEL

            # Lua.g:10:7: ( 'while' )
            # Lua.g:10:9: 'while'
            pass 
            self.match("while")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__23"



    # $ANTLR start "T__24"
    def mT__24(self, ):

        try:
            _type = T__24
            _channel = DEFAULT_CHANNEL

            # Lua.g:11:7: ( 'if' )
            # Lua.g:11:9: 'if'
            pass 
            self.match("if")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__24"



    # $ANTLR start "T__25"
    def mT__25(self, ):

        try:
            _type = T__25
            _channel = DEFAULT_CHANNEL

            # Lua.g:12:7: ( 'then' )
            # Lua.g:12:9: 'then'
            pass 
            self.match("then")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__25"



    # $ANTLR start "T__26"
    def mT__26(self, ):

        try:
            _type = T__26
            _channel = DEFAULT_CHANNEL

            # Lua.g:13:7: ( 'elseif' )
            # Lua.g:13:9: 'elseif'
            pass 
            self.match("elseif")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__26"



    # $ANTLR start "T__27"
    def mT__27(self, ):

        try:
            _type = T__27
            _channel = DEFAULT_CHANNEL

            # Lua.g:14:7: ( 'else' )
            # Lua.g:14:9: 'else'
            pass 
            self.match("else")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__27"



    # $ANTLR start "T__28"
    def mT__28(self, ):

        try:
            _type = T__28
            _channel = DEFAULT_CHANNEL

            # Lua.g:15:7: ( 'for' )
            # Lua.g:15:9: 'for'
            pass 
            self.match("for")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__28"



    # $ANTLR start "T__29"
    def mT__29(self, ):

        try:
            _type = T__29
            _channel = DEFAULT_CHANNEL

            # Lua.g:16:7: ( 'in' )
            # Lua.g:16:9: 'in'
            pass 
            self.match("in")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__29"



    # $ANTLR start "T__30"
    def mT__30(self, ):

        try:
            _type = T__30
            _channel = DEFAULT_CHANNEL

            # Lua.g:17:7: ( 'function' )
            # Lua.g:17:9: 'function'
            pass 
            self.match("function")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__30"



    # $ANTLR start "T__31"
    def mT__31(self, ):

        try:
            _type = T__31
            _channel = DEFAULT_CHANNEL

            # Lua.g:18:7: ( 'local' )
            # Lua.g:18:9: 'local'
            pass 
            self.match("local")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__31"



    # $ANTLR start "T__32"
    def mT__32(self, ):

        try:
            _type = T__32
            _channel = DEFAULT_CHANNEL

            # Lua.g:19:7: ( '=' )
            # Lua.g:19:9: '='
            pass 
            self.match(61)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__32"



    # $ANTLR start "T__33"
    def mT__33(self, ):

        try:
            _type = T__33
            _channel = DEFAULT_CHANNEL

            # Lua.g:20:7: ( 'return' )
            # Lua.g:20:9: 'return'
            pass 
            self.match("return")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__33"



    # $ANTLR start "T__34"
    def mT__34(self, ):

        try:
            _type = T__34
            _channel = DEFAULT_CHANNEL

            # Lua.g:21:7: ( 'break' )
            # Lua.g:21:9: 'break'
            pass 
            self.match("break")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__34"



    # $ANTLR start "T__35"
    def mT__35(self, ):

        try:
            _type = T__35
            _channel = DEFAULT_CHANNEL

            # Lua.g:22:7: ( 'continue' )
            # Lua.g:22:9: 'continue'
            pass 
            self.match("continue")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__35"



    # $ANTLR start "T__36"
    def mT__36(self, ):

        try:
            _type = T__36
            _channel = DEFAULT_CHANNEL

            # Lua.g:23:7: ( '.' )
            # Lua.g:23:9: '.'
            pass 
            self.match(46)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__36"



    # $ANTLR start "T__37"
    def mT__37(self, ):

        try:
            _type = T__37
            _channel = DEFAULT_CHANNEL

            # Lua.g:24:7: ( ':' )
            # Lua.g:24:9: ':'
            pass 
            self.match(58)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__37"



    # $ANTLR start "T__38"
    def mT__38(self, ):

        try:
            _type = T__38
            _channel = DEFAULT_CHANNEL

            # Lua.g:25:7: ( ',' )
            # Lua.g:25:9: ','
            pass 
            self.match(44)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__38"



    # $ANTLR start "T__39"
    def mT__39(self, ):

        try:
            _type = T__39
            _channel = DEFAULT_CHANNEL

            # Lua.g:26:7: ( 'and' )
            # Lua.g:26:9: 'and'
            pass 
            self.match("and")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__39"



    # $ANTLR start "T__40"
    def mT__40(self, ):

        try:
            _type = T__40
            _channel = DEFAULT_CHANNEL

            # Lua.g:27:7: ( 'or' )
            # Lua.g:27:9: 'or'
            pass 
            self.match("or")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__40"



    # $ANTLR start "T__41"
    def mT__41(self, ):

        try:
            _type = T__41
            _channel = DEFAULT_CHANNEL

            # Lua.g:28:7: ( '<' )
            # Lua.g:28:9: '<'
            pass 
            self.match(60)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__41"



    # $ANTLR start "T__42"
    def mT__42(self, ):

        try:
            _type = T__42
            _channel = DEFAULT_CHANNEL

            # Lua.g:29:7: ( '<=' )
            # Lua.g:29:9: '<='
            pass 
            self.match("<=")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__42"



    # $ANTLR start "T__43"
    def mT__43(self, ):

        try:
            _type = T__43
            _channel = DEFAULT_CHANNEL

            # Lua.g:30:7: ( '>' )
            # Lua.g:30:9: '>'
            pass 
            self.match(62)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__43"



    # $ANTLR start "T__44"
    def mT__44(self, ):

        try:
            _type = T__44
            _channel = DEFAULT_CHANNEL

            # Lua.g:31:7: ( '>=' )
            # Lua.g:31:9: '>='
            pass 
            self.match(">=")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__44"



    # $ANTLR start "T__45"
    def mT__45(self, ):

        try:
            _type = T__45
            _channel = DEFAULT_CHANNEL

            # Lua.g:32:7: ( '==' )
            # Lua.g:32:9: '=='
            pass 
            self.match("==")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__45"



    # $ANTLR start "T__46"
    def mT__46(self, ):

        try:
            _type = T__46
            _channel = DEFAULT_CHANNEL

            # Lua.g:33:7: ( '~=' )
            # Lua.g:33:9: '~='
            pass 
            self.match("~=")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__46"



    # $ANTLR start "T__47"
    def mT__47(self, ):

        try:
            _type = T__47
            _channel = DEFAULT_CHANNEL

            # Lua.g:34:7: ( '+' )
            # Lua.g:34:9: '+'
            pass 
            self.match(43)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__47"



    # $ANTLR start "T__48"
    def mT__48(self, ):

        try:
            _type = T__48
            _channel = DEFAULT_CHANNEL

            # Lua.g:35:7: ( '-' )
            # Lua.g:35:9: '-'
            pass 
            self.match(45)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__48"



    # $ANTLR start "T__49"
    def mT__49(self, ):

        try:
            _type = T__49
            _channel = DEFAULT_CHANNEL

            # Lua.g:36:7: ( '*' )
            # Lua.g:36:9: '*'
            pass 
            self.match(42)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__49"



    # $ANTLR start "T__50"
    def mT__50(self, ):

        try:
            _type = T__50
            _channel = DEFAULT_CHANNEL

            # Lua.g:37:7: ( '/' )
            # Lua.g:37:9: '/'
            pass 
            self.match(47)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__50"



    # $ANTLR start "T__51"
    def mT__51(self, ):

        try:
            _type = T__51
            _channel = DEFAULT_CHANNEL

            # Lua.g:38:7: ( '^' )
            # Lua.g:38:9: '^'
            pass 
            self.match(94)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__51"



    # $ANTLR start "T__52"
    def mT__52(self, ):

        try:
            _type = T__52
            _channel = DEFAULT_CHANNEL

            # Lua.g:39:7: ( '%' )
            # Lua.g:39:9: '%'
            pass 
            self.match(37)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__52"



    # $ANTLR start "T__53"
    def mT__53(self, ):

        try:
            _type = T__53
            _channel = DEFAULT_CHANNEL

            # Lua.g:40:7: ( '..' )
            # Lua.g:40:9: '..'
            pass 
            self.match("..")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__53"



    # $ANTLR start "T__54"
    def mT__54(self, ):

        try:
            _type = T__54
            _channel = DEFAULT_CHANNEL

            # Lua.g:41:7: ( 'nil' )
            # Lua.g:41:9: 'nil'
            pass 
            self.match("nil")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__54"



    # $ANTLR start "T__55"
    def mT__55(self, ):

        try:
            _type = T__55
            _channel = DEFAULT_CHANNEL

            # Lua.g:42:7: ( 'false' )
            # Lua.g:42:9: 'false'
            pass 
            self.match("false")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__55"



    # $ANTLR start "T__56"
    def mT__56(self, ):

        try:
            _type = T__56
            _channel = DEFAULT_CHANNEL

            # Lua.g:43:7: ( 'true' )
            # Lua.g:43:9: 'true'
            pass 
            self.match("true")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__56"



    # $ANTLR start "T__57"
    def mT__57(self, ):

        try:
            _type = T__57
            _channel = DEFAULT_CHANNEL

            # Lua.g:44:7: ( '...' )
            # Lua.g:44:9: '...'
            pass 
            self.match("...")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__57"



    # $ANTLR start "T__58"
    def mT__58(self, ):

        try:
            _type = T__58
            _channel = DEFAULT_CHANNEL

            # Lua.g:45:7: ( '(' )
            # Lua.g:45:9: '('
            pass 
            self.match(40)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__58"



    # $ANTLR start "T__59"
    def mT__59(self, ):

        try:
            _type = T__59
            _channel = DEFAULT_CHANNEL

            # Lua.g:46:7: ( ')' )
            # Lua.g:46:9: ')'
            pass 
            self.match(41)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__59"



    # $ANTLR start "T__60"
    def mT__60(self, ):

        try:
            _type = T__60
            _channel = DEFAULT_CHANNEL

            # Lua.g:47:7: ( '[' )
            # Lua.g:47:9: '['
            pass 
            self.match(91)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__60"



    # $ANTLR start "T__61"
    def mT__61(self, ):

        try:
            _type = T__61
            _channel = DEFAULT_CHANNEL

            # Lua.g:48:7: ( ']' )
            # Lua.g:48:9: ']'
            pass 
            self.match(93)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__61"



    # $ANTLR start "T__62"
    def mT__62(self, ):

        try:
            _type = T__62
            _channel = DEFAULT_CHANNEL

            # Lua.g:49:7: ( '{' )
            # Lua.g:49:9: '{'
            pass 
            self.match(123)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__62"



    # $ANTLR start "T__63"
    def mT__63(self, ):

        try:
            _type = T__63
            _channel = DEFAULT_CHANNEL

            # Lua.g:50:7: ( '}' )
            # Lua.g:50:9: '}'
            pass 
            self.match(125)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__63"



    # $ANTLR start "T__64"
    def mT__64(self, ):

        try:
            _type = T__64
            _channel = DEFAULT_CHANNEL

            # Lua.g:51:7: ( 'not' )
            # Lua.g:51:9: 'not'
            pass 
            self.match("not")



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__64"



    # $ANTLR start "T__65"
    def mT__65(self, ):

        try:
            _type = T__65
            _channel = DEFAULT_CHANNEL

            # Lua.g:52:7: ( '#' )
            # Lua.g:52:9: '#'
            pass 
            self.match(35)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "T__65"



    # $ANTLR start "NAME"
    def mNAME(self, ):

        try:
            _type = NAME
            _channel = DEFAULT_CHANNEL

            # Lua.g:76:6: ( ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( options {greedy=true; } : 'a' .. 'z' | 'A' .. 'Z' | '_' | '0' .. '9' )* )
            # Lua.g:76:7: ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( options {greedy=true; } : 'a' .. 'z' | 'A' .. 'Z' | '_' | '0' .. '9' )*
            pass 
            if (65 <= self.input.LA(1) <= 90) or self.input.LA(1) == 95 or (97 <= self.input.LA(1) <= 122):
                self.input.consume()
            else:
                mse = MismatchedSetException(None, self.input)
                self.recover(mse)
                raise mse

            # Lua.g:76:30: ( options {greedy=true; } : 'a' .. 'z' | 'A' .. 'Z' | '_' | '0' .. '9' )*
            while True: #loop1
                alt1 = 5
                LA1 = self.input.LA(1)
                if LA1 == 97 or LA1 == 98 or LA1 == 99 or LA1 == 100 or LA1 == 101 or LA1 == 102 or LA1 == 103 or LA1 == 104 or LA1 == 105 or LA1 == 106 or LA1 == 107 or LA1 == 108 or LA1 == 109 or LA1 == 110 or LA1 == 111 or LA1 == 112 or LA1 == 113 or LA1 == 114 or LA1 == 115 or LA1 == 116 or LA1 == 117 or LA1 == 118 or LA1 == 119 or LA1 == 120 or LA1 == 121 or LA1 == 122:
                    alt1 = 1
                elif LA1 == 65 or LA1 == 66 or LA1 == 67 or LA1 == 68 or LA1 == 69 or LA1 == 70 or LA1 == 71 or LA1 == 72 or LA1 == 73 or LA1 == 74 or LA1 == 75 or LA1 == 76 or LA1 == 77 or LA1 == 78 or LA1 == 79 or LA1 == 80 or LA1 == 81 or LA1 == 82 or LA1 == 83 or LA1 == 84 or LA1 == 85 or LA1 == 86 or LA1 == 87 or LA1 == 88 or LA1 == 89 or LA1 == 90:
                    alt1 = 2
                elif LA1 == 95:
                    alt1 = 3
                elif LA1 == 48 or LA1 == 49 or LA1 == 50 or LA1 == 51 or LA1 == 52 or LA1 == 53 or LA1 == 54 or LA1 == 55 or LA1 == 56 or LA1 == 57:
                    alt1 = 4

                if alt1 == 1:
                    # Lua.g:76:54: 'a' .. 'z'
                    pass 
                    self.matchRange(97, 122)


                elif alt1 == 2:
                    # Lua.g:76:63: 'A' .. 'Z'
                    pass 
                    self.matchRange(65, 90)


                elif alt1 == 3:
                    # Lua.g:76:72: '_'
                    pass 
                    self.match(95)


                elif alt1 == 4:
                    # Lua.g:76:76: '0' .. '9'
                    pass 
                    self.matchRange(48, 57)


                else:
                    break #loop1





            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "NAME"



    # $ANTLR start "INT"
    def mINT(self, ):

        try:
            _type = INT
            _channel = DEFAULT_CHANNEL

            # Lua.g:79:5: ( ( '0' .. '9' )+ )
            # Lua.g:79:7: ( '0' .. '9' )+
            pass 
            # Lua.g:79:7: ( '0' .. '9' )+
            cnt2 = 0
            while True: #loop2
                alt2 = 2
                LA2_0 = self.input.LA(1)

                if ((48 <= LA2_0 <= 57)) :
                    alt2 = 1


                if alt2 == 1:
                    # Lua.g:79:8: '0' .. '9'
                    pass 
                    self.matchRange(48, 57)


                else:
                    if cnt2 >= 1:
                        break #loop2

                    eee = EarlyExitException(2, self.input)
                    raise eee

                cnt2 += 1





            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "INT"



    # $ANTLR start "FLOAT"
    def mFLOAT(self, ):

        try:
            _type = FLOAT
            _channel = DEFAULT_CHANNEL

            # Lua.g:81:8: ( INT '.' INT )
            # Lua.g:81:9: INT '.' INT
            pass 
            self.mINT()
            self.match(46)
            self.mINT()



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "FLOAT"



    # $ANTLR start "EXP"
    def mEXP(self, ):

        try:
            _type = EXP
            _channel = DEFAULT_CHANNEL

            # Lua.g:83:5: ( ( INT | FLOAT ) ( 'E' | 'e' ) ( '-' )? INT )
            # Lua.g:83:7: ( INT | FLOAT ) ( 'E' | 'e' ) ( '-' )? INT
            pass 
            # Lua.g:83:7: ( INT | FLOAT )
            alt3 = 2
            alt3 = self.dfa3.predict(self.input)
            if alt3 == 1:
                # Lua.g:83:8: INT
                pass 
                self.mINT()


            elif alt3 == 2:
                # Lua.g:83:13: FLOAT
                pass 
                self.mFLOAT()



            if self.input.LA(1) == 69 or self.input.LA(1) == 101:
                self.input.consume()
            else:
                mse = MismatchedSetException(None, self.input)
                self.recover(mse)
                raise mse

            # Lua.g:83:30: ( '-' )?
            alt4 = 2
            LA4_0 = self.input.LA(1)

            if (LA4_0 == 45) :
                alt4 = 1
            if alt4 == 1:
                # Lua.g:83:31: '-'
                pass 
                self.match(45)



            self.mINT()



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "EXP"



    # $ANTLR start "HEX"
    def mHEX(self, ):

        try:
            _type = HEX
            _channel = DEFAULT_CHANNEL

            # Lua.g:85:5: ( '0x' ( '0' .. '9' | 'a' .. 'f' )+ )
            # Lua.g:85:6: '0x' ( '0' .. '9' | 'a' .. 'f' )+
            pass 
            self.match("0x")
            # Lua.g:85:11: ( '0' .. '9' | 'a' .. 'f' )+
            cnt5 = 0
            while True: #loop5
                alt5 = 2
                LA5_0 = self.input.LA(1)

                if ((48 <= LA5_0 <= 57) or (97 <= LA5_0 <= 102)) :
                    alt5 = 1


                if alt5 == 1:
                    # Lua.g:
                    pass 
                    if (48 <= self.input.LA(1) <= 57) or (97 <= self.input.LA(1) <= 102):
                        self.input.consume()
                    else:
                        mse = MismatchedSetException(None, self.input)
                        self.recover(mse)
                        raise mse



                else:
                    if cnt5 >= 1:
                        break #loop5

                    eee = EarlyExitException(5, self.input)
                    raise eee

                cnt5 += 1





            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "HEX"



    # $ANTLR start "NORMALSTRING"
    def mNORMALSTRING(self, ):

        try:
            _type = NORMALSTRING
            _channel = DEFAULT_CHANNEL

            # Lua.g:90:5: ( '\"' ( EscapeSequence | ~ ( '\\\\' | '\"' ) )* '\"' )
            # Lua.g:90:8: '\"' ( EscapeSequence | ~ ( '\\\\' | '\"' ) )* '\"'
            pass 
            self.match(34)
            # Lua.g:90:12: ( EscapeSequence | ~ ( '\\\\' | '\"' ) )*
            while True: #loop6
                alt6 = 3
                LA6_0 = self.input.LA(1)

                if (LA6_0 == 92) :
                    alt6 = 1
                elif ((0 <= LA6_0 <= 33) or (35 <= LA6_0 <= 91) or (93 <= LA6_0 <= 65535)) :
                    alt6 = 2


                if alt6 == 1:
                    # Lua.g:90:14: EscapeSequence
                    pass 
                    self.mEscapeSequence()


                elif alt6 == 2:
                    # Lua.g:90:31: ~ ( '\\\\' | '\"' )
                    pass 
                    if (0 <= self.input.LA(1) <= 33) or (35 <= self.input.LA(1) <= 91) or (93 <= self.input.LA(1) <= 65535):
                        self.input.consume()
                    else:
                        mse = MismatchedSetException(None, self.input)
                        self.recover(mse)
                        raise mse



                else:
                    break #loop6


            self.match(34)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "NORMALSTRING"



    # $ANTLR start "CHARSTRING"
    def mCHARSTRING(self, ):

        try:
            _type = CHARSTRING
            _channel = DEFAULT_CHANNEL

            # Lua.g:94:4: ( '\\'' ( EscapeSequence | ~ ( '\\'' | '\\\\' ) )* '\\'' )
            # Lua.g:94:6: '\\'' ( EscapeSequence | ~ ( '\\'' | '\\\\' ) )* '\\''
            pass 
            self.match(39)
            # Lua.g:94:11: ( EscapeSequence | ~ ( '\\'' | '\\\\' ) )*
            while True: #loop7
                alt7 = 3
                LA7_0 = self.input.LA(1)

                if (LA7_0 == 92) :
                    alt7 = 1
                elif ((0 <= LA7_0 <= 38) or (40 <= LA7_0 <= 91) or (93 <= LA7_0 <= 65535)) :
                    alt7 = 2


                if alt7 == 1:
                    # Lua.g:94:13: EscapeSequence
                    pass 
                    self.mEscapeSequence()


                elif alt7 == 2:
                    # Lua.g:94:30: ~ ( '\\'' | '\\\\' )
                    pass 
                    if (0 <= self.input.LA(1) <= 38) or (40 <= self.input.LA(1) <= 91) or (93 <= self.input.LA(1) <= 65535):
                        self.input.consume()
                    else:
                        mse = MismatchedSetException(None, self.input)
                        self.recover(mse)
                        raise mse



                else:
                    break #loop7


            self.match(39)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "CHARSTRING"



    # $ANTLR start "LONGSTRING"
    def mLONGSTRING(self, ):

        try:
            _type = LONGSTRING
            _channel = DEFAULT_CHANNEL

            # Lua.g:98:2: ( '[' ( '=' )* '[' ( EscapeSequence | ~ ( '\\\\' | ']' ) )* ']' ( '=' )* ']' )
            # Lua.g:98:4: '[' ( '=' )* '[' ( EscapeSequence | ~ ( '\\\\' | ']' ) )* ']' ( '=' )* ']'
            pass 
            self.match(91)
            # Lua.g:98:7: ( '=' )*
            while True: #loop8
                alt8 = 2
                LA8_0 = self.input.LA(1)

                if (LA8_0 == 61) :
                    alt8 = 1


                if alt8 == 1:
                    # Lua.g:98:8: '='
                    pass 
                    self.match(61)


                else:
                    break #loop8


            self.match(91)
            # Lua.g:98:17: ( EscapeSequence | ~ ( '\\\\' | ']' ) )*
            while True: #loop9
                alt9 = 3
                LA9_0 = self.input.LA(1)

                if (LA9_0 == 92) :
                    alt9 = 1
                elif ((0 <= LA9_0 <= 91) or (94 <= LA9_0 <= 65535)) :
                    alt9 = 2


                if alt9 == 1:
                    # Lua.g:98:19: EscapeSequence
                    pass 
                    self.mEscapeSequence()


                elif alt9 == 2:
                    # Lua.g:98:36: ~ ( '\\\\' | ']' )
                    pass 
                    if (0 <= self.input.LA(1) <= 91) or (94 <= self.input.LA(1) <= 65535):
                        self.input.consume()
                    else:
                        mse = MismatchedSetException(None, self.input)
                        self.recover(mse)
                        raise mse



                else:
                    break #loop9


            self.match(93)
            # Lua.g:98:54: ( '=' )*
            while True: #loop10
                alt10 = 2
                LA10_0 = self.input.LA(1)

                if (LA10_0 == 61) :
                    alt10 = 1


                if alt10 == 1:
                    # Lua.g:98:55: '='
                    pass 
                    self.match(61)


                else:
                    break #loop10


            self.match(93)



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "LONGSTRING"



    # $ANTLR start "EscapeSequence"
    def mEscapeSequence(self, ):

        try:
            # Lua.g:103:5: ( '\\\\' ( 'b' | 't' | 'n' | 'f' | 'r' | '\\\"' | '\\'' | '\\\\' ) | UnicodeEscape | OctalEscape )
            alt11 = 3
            LA11_0 = self.input.LA(1)

            if (LA11_0 == 92) :
                LA11 = self.input.LA(2)
                if LA11 == 34 or LA11 == 39 or LA11 == 92 or LA11 == 98 or LA11 == 102 or LA11 == 110 or LA11 == 114 or LA11 == 116:
                    alt11 = 1
                elif LA11 == 117:
                    alt11 = 2
                elif LA11 == 48 or LA11 == 49 or LA11 == 50 or LA11 == 51 or LA11 == 52 or LA11 == 53 or LA11 == 54 or LA11 == 55:
                    alt11 = 3
                else:
                    nvae = NoViableAltException("", 11, 1, self.input)

                    raise nvae

            else:
                nvae = NoViableAltException("", 11, 0, self.input)

                raise nvae

            if alt11 == 1:
                # Lua.g:103:9: '\\\\' ( 'b' | 't' | 'n' | 'f' | 'r' | '\\\"' | '\\'' | '\\\\' )
                pass 
                self.match(92)
                if self.input.LA(1) == 34 or self.input.LA(1) == 39 or self.input.LA(1) == 92 or self.input.LA(1) == 98 or self.input.LA(1) == 102 or self.input.LA(1) == 110 or self.input.LA(1) == 114 or self.input.LA(1) == 116:
                    self.input.consume()
                else:
                    mse = MismatchedSetException(None, self.input)
                    self.recover(mse)
                    raise mse



            elif alt11 == 2:
                # Lua.g:104:9: UnicodeEscape
                pass 
                self.mUnicodeEscape()


            elif alt11 == 3:
                # Lua.g:105:9: OctalEscape
                pass 
                self.mOctalEscape()



        finally:

            pass

    # $ANTLR end "EscapeSequence"



    # $ANTLR start "OctalEscape"
    def mOctalEscape(self, ):

        try:
            # Lua.g:110:5: ( '\\\\' ( '0' .. '3' ) ( '0' .. '7' ) ( '0' .. '7' ) | '\\\\' ( '0' .. '7' ) ( '0' .. '7' ) | '\\\\' ( '0' .. '7' ) )
            alt12 = 3
            LA12_0 = self.input.LA(1)

            if (LA12_0 == 92) :
                LA12_1 = self.input.LA(2)

                if ((48 <= LA12_1 <= 51)) :
                    LA12_2 = self.input.LA(3)

                    if ((48 <= LA12_2 <= 55)) :
                        LA12_4 = self.input.LA(4)

                        if ((48 <= LA12_4 <= 55)) :
                            alt12 = 1
                        else:
                            alt12 = 2
                    else:
                        alt12 = 3
                elif ((52 <= LA12_1 <= 55)) :
                    LA12_3 = self.input.LA(3)

                    if ((48 <= LA12_3 <= 55)) :
                        alt12 = 2
                    else:
                        alt12 = 3
                else:
                    nvae = NoViableAltException("", 12, 1, self.input)

                    raise nvae

            else:
                nvae = NoViableAltException("", 12, 0, self.input)

                raise nvae

            if alt12 == 1:
                # Lua.g:110:9: '\\\\' ( '0' .. '3' ) ( '0' .. '7' ) ( '0' .. '7' )
                pass 
                self.match(92)
                # Lua.g:110:14: ( '0' .. '3' )
                # Lua.g:110:15: '0' .. '3'
                pass 
                self.matchRange(48, 51)



                # Lua.g:110:25: ( '0' .. '7' )
                # Lua.g:110:26: '0' .. '7'
                pass 
                self.matchRange(48, 55)



                # Lua.g:110:36: ( '0' .. '7' )
                # Lua.g:110:37: '0' .. '7'
                pass 
                self.matchRange(48, 55)





            elif alt12 == 2:
                # Lua.g:111:9: '\\\\' ( '0' .. '7' ) ( '0' .. '7' )
                pass 
                self.match(92)
                # Lua.g:111:14: ( '0' .. '7' )
                # Lua.g:111:15: '0' .. '7'
                pass 
                self.matchRange(48, 55)



                # Lua.g:111:25: ( '0' .. '7' )
                # Lua.g:111:26: '0' .. '7'
                pass 
                self.matchRange(48, 55)





            elif alt12 == 3:
                # Lua.g:112:9: '\\\\' ( '0' .. '7' )
                pass 
                self.match(92)
                # Lua.g:112:14: ( '0' .. '7' )
                # Lua.g:112:15: '0' .. '7'
                pass 
                self.matchRange(48, 55)






        finally:

            pass

    # $ANTLR end "OctalEscape"



    # $ANTLR start "UnicodeEscape"
    def mUnicodeEscape(self, ):

        try:
            # Lua.g:117:5: ( '\\\\' 'u' HexDigit HexDigit HexDigit HexDigit )
            # Lua.g:117:9: '\\\\' 'u' HexDigit HexDigit HexDigit HexDigit
            pass 
            self.match(92)
            self.match(117)
            self.mHexDigit()
            self.mHexDigit()
            self.mHexDigit()
            self.mHexDigit()




        finally:

            pass

    # $ANTLR end "UnicodeEscape"



    # $ANTLR start "HexDigit"
    def mHexDigit(self, ):

        try:
            # Lua.g:121:10: ( ( '0' .. '9' | 'a' .. 'f' | 'A' .. 'F' ) )
            # Lua.g:121:12: ( '0' .. '9' | 'a' .. 'f' | 'A' .. 'F' )
            pass 
            if (48 <= self.input.LA(1) <= 57) or (65 <= self.input.LA(1) <= 70) or (97 <= self.input.LA(1) <= 102):
                self.input.consume()
            else:
                mse = MismatchedSetException(None, self.input)
                self.recover(mse)
                raise mse





        finally:

            pass

    # $ANTLR end "HexDigit"



    # $ANTLR start "COMMENT"
    def mCOMMENT(self, ):

        try:
            _type = COMMENT
            _channel = DEFAULT_CHANNEL

            # Lua.g:125:5: ( '--[[' ( options {greedy=false; } : . )* ']]' )
            # Lua.g:125:9: '--[[' ( options {greedy=false; } : . )* ']]'
            pass 
            self.match("--[[")
            # Lua.g:125:16: ( options {greedy=false; } : . )*
            while True: #loop13
                alt13 = 2
                LA13_0 = self.input.LA(1)

                if (LA13_0 == 93) :
                    LA13_1 = self.input.LA(2)

                    if (LA13_1 == 93) :
                        alt13 = 2
                    elif ((0 <= LA13_1 <= 92) or (94 <= LA13_1 <= 65535)) :
                        alt13 = 1


                elif ((0 <= LA13_0 <= 92) or (94 <= LA13_0 <= 65535)) :
                    alt13 = 1


                if alt13 == 1:
                    # Lua.g:125:44: .
                    pass 
                    self.matchAny()


                else:
                    break #loop13


            self.match("]]")
            #action start
            self.skip();
            #action end



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "COMMENT"



    # $ANTLR start "LINE_COMMENT"
    def mLINE_COMMENT(self, ):

        try:
            _type = LINE_COMMENT
            _channel = DEFAULT_CHANNEL

            # Lua.g:129:5: ( '--' (~ ( '\\n' | '\\r' ) )* ( '\\r' )? '\\n' )
            # Lua.g:129:7: '--' (~ ( '\\n' | '\\r' ) )* ( '\\r' )? '\\n'
            pass 
            self.match("--")
            # Lua.g:129:12: (~ ( '\\n' | '\\r' ) )*
            while True: #loop14
                alt14 = 2
                LA14_0 = self.input.LA(1)

                if ((0 <= LA14_0 <= 9) or (11 <= LA14_0 <= 12) or (14 <= LA14_0 <= 65535)) :
                    alt14 = 1


                if alt14 == 1:
                    # Lua.g:129:12: ~ ( '\\n' | '\\r' )
                    pass 
                    if (0 <= self.input.LA(1) <= 9) or (11 <= self.input.LA(1) <= 12) or (14 <= self.input.LA(1) <= 65535):
                        self.input.consume()
                    else:
                        mse = MismatchedSetException(None, self.input)
                        self.recover(mse)
                        raise mse



                else:
                    break #loop14


            # Lua.g:129:26: ( '\\r' )?
            alt15 = 2
            LA15_0 = self.input.LA(1)

            if (LA15_0 == 13) :
                alt15 = 1
            if alt15 == 1:
                # Lua.g:129:26: '\\r'
                pass 
                self.match(13)



            self.match(10)
            #action start
            self.skip();
            #action end



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "LINE_COMMENT"



    # $ANTLR start "WS"
    def mWS(self, ):

        try:
            _type = WS
            _channel = DEFAULT_CHANNEL

            # Lua.g:133:5: ( ( ' ' | '\\t' | '\\u000C' ) )
            # Lua.g:133:8: ( ' ' | '\\t' | '\\u000C' )
            pass 
            if self.input.LA(1) == 9 or self.input.LA(1) == 12 or self.input.LA(1) == 32:
                self.input.consume()
            else:
                mse = MismatchedSetException(None, self.input)
                self.recover(mse)
                raise mse

            #action start
            self.skip();
            #action end



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "WS"



    # $ANTLR start "NEWLINE"
    def mNEWLINE(self, ):

        try:
            _type = NEWLINE
            _channel = DEFAULT_CHANNEL

            # Lua.g:136:9: ( ( '\\r' )? '\\n' )
            # Lua.g:136:11: ( '\\r' )? '\\n'
            pass 
            # Lua.g:136:11: ( '\\r' )?
            alt16 = 2
            LA16_0 = self.input.LA(1)

            if (LA16_0 == 13) :
                alt16 = 1
            if alt16 == 1:
                # Lua.g:136:12: '\\r'
                pass 
                self.match(13)



            self.match(10)
            #action start
            self.skip();
            #action end



            self._state.type = _type
            self._state.channel = _channel

        finally:

            pass

    # $ANTLR end "NEWLINE"



    def mTokens(self):
        # Lua.g:1:8: ( T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | T__30 | T__31 | T__32 | T__33 | T__34 | T__35 | T__36 | T__37 | T__38 | T__39 | T__40 | T__41 | T__42 | T__43 | T__44 | T__45 | T__46 | T__47 | T__48 | T__49 | T__50 | T__51 | T__52 | T__53 | T__54 | T__55 | T__56 | T__57 | T__58 | T__59 | T__60 | T__61 | T__62 | T__63 | T__64 | T__65 | NAME | INT | FLOAT | EXP | HEX | NORMALSTRING | CHARSTRING | LONGSTRING | COMMENT | LINE_COMMENT | WS | NEWLINE )
        alt17 = 58
        alt17 = self.dfa17.predict(self.input)
        if alt17 == 1:
            # Lua.g:1:10: T__20
            pass 
            self.mT__20()


        elif alt17 == 2:
            # Lua.g:1:16: T__21
            pass 
            self.mT__21()


        elif alt17 == 3:
            # Lua.g:1:22: T__22
            pass 
            self.mT__22()


        elif alt17 == 4:
            # Lua.g:1:28: T__23
            pass 
            self.mT__23()


        elif alt17 == 5:
            # Lua.g:1:34: T__24
            pass 
            self.mT__24()


        elif alt17 == 6:
            # Lua.g:1:40: T__25
            pass 
            self.mT__25()


        elif alt17 == 7:
            # Lua.g:1:46: T__26
            pass 
            self.mT__26()


        elif alt17 == 8:
            # Lua.g:1:52: T__27
            pass 
            self.mT__27()


        elif alt17 == 9:
            # Lua.g:1:58: T__28
            pass 
            self.mT__28()


        elif alt17 == 10:
            # Lua.g:1:64: T__29
            pass 
            self.mT__29()


        elif alt17 == 11:
            # Lua.g:1:70: T__30
            pass 
            self.mT__30()


        elif alt17 == 12:
            # Lua.g:1:76: T__31
            pass 
            self.mT__31()


        elif alt17 == 13:
            # Lua.g:1:82: T__32
            pass 
            self.mT__32()


        elif alt17 == 14:
            # Lua.g:1:88: T__33
            pass 
            self.mT__33()


        elif alt17 == 15:
            # Lua.g:1:94: T__34
            pass 
            self.mT__34()


        elif alt17 == 16:
            # Lua.g:1:100: T__35
            pass 
            self.mT__35()


        elif alt17 == 17:
            # Lua.g:1:106: T__36
            pass 
            self.mT__36()


        elif alt17 == 18:
            # Lua.g:1:112: T__37
            pass 
            self.mT__37()


        elif alt17 == 19:
            # Lua.g:1:118: T__38
            pass 
            self.mT__38()


        elif alt17 == 20:
            # Lua.g:1:124: T__39
            pass 
            self.mT__39()


        elif alt17 == 21:
            # Lua.g:1:130: T__40
            pass 
            self.mT__40()


        elif alt17 == 22:
            # Lua.g:1:136: T__41
            pass 
            self.mT__41()


        elif alt17 == 23:
            # Lua.g:1:142: T__42
            pass 
            self.mT__42()


        elif alt17 == 24:
            # Lua.g:1:148: T__43
            pass 
            self.mT__43()


        elif alt17 == 25:
            # Lua.g:1:154: T__44
            pass 
            self.mT__44()


        elif alt17 == 26:
            # Lua.g:1:160: T__45
            pass 
            self.mT__45()


        elif alt17 == 27:
            # Lua.g:1:166: T__46
            pass 
            self.mT__46()


        elif alt17 == 28:
            # Lua.g:1:172: T__47
            pass 
            self.mT__47()


        elif alt17 == 29:
            # Lua.g:1:178: T__48
            pass 
            self.mT__48()


        elif alt17 == 30:
            # Lua.g:1:184: T__49
            pass 
            self.mT__49()


        elif alt17 == 31:
            # Lua.g:1:190: T__50
            pass 
            self.mT__50()


        elif alt17 == 32:
            # Lua.g:1:196: T__51
            pass 
            self.mT__51()


        elif alt17 == 33:
            # Lua.g:1:202: T__52
            pass 
            self.mT__52()


        elif alt17 == 34:
            # Lua.g:1:208: T__53
            pass 
            self.mT__53()


        elif alt17 == 35:
            # Lua.g:1:214: T__54
            pass 
            self.mT__54()


        elif alt17 == 36:
            # Lua.g:1:220: T__55
            pass 
            self.mT__55()


        elif alt17 == 37:
            # Lua.g:1:226: T__56
            pass 
            self.mT__56()


        elif alt17 == 38:
            # Lua.g:1:232: T__57
            pass 
            self.mT__57()


        elif alt17 == 39:
            # Lua.g:1:238: T__58
            pass 
            self.mT__58()


        elif alt17 == 40:
            # Lua.g:1:244: T__59
            pass 
            self.mT__59()


        elif alt17 == 41:
            # Lua.g:1:250: T__60
            pass 
            self.mT__60()


        elif alt17 == 42:
            # Lua.g:1:256: T__61
            pass 
            self.mT__61()


        elif alt17 == 43:
            # Lua.g:1:262: T__62
            pass 
            self.mT__62()


        elif alt17 == 44:
            # Lua.g:1:268: T__63
            pass 
            self.mT__63()


        elif alt17 == 45:
            # Lua.g:1:274: T__64
            pass 
            self.mT__64()


        elif alt17 == 46:
            # Lua.g:1:280: T__65
            pass 
            self.mT__65()


        elif alt17 == 47:
            # Lua.g:1:286: NAME
            pass 
            self.mNAME()


        elif alt17 == 48:
            # Lua.g:1:291: INT
            pass 
            self.mINT()


        elif alt17 == 49:
            # Lua.g:1:295: FLOAT
            pass 
            self.mFLOAT()


        elif alt17 == 50:
            # Lua.g:1:301: EXP
            pass 
            self.mEXP()


        elif alt17 == 51:
            # Lua.g:1:305: HEX
            pass 
            self.mHEX()


        elif alt17 == 52:
            # Lua.g:1:309: NORMALSTRING
            pass 
            self.mNORMALSTRING()


        elif alt17 == 53:
            # Lua.g:1:322: CHARSTRING
            pass 
            self.mCHARSTRING()


        elif alt17 == 54:
            # Lua.g:1:333: LONGSTRING
            pass 
            self.mLONGSTRING()


        elif alt17 == 55:
            # Lua.g:1:344: COMMENT
            pass 
            self.mCOMMENT()


        elif alt17 == 56:
            # Lua.g:1:352: LINE_COMMENT
            pass 
            self.mLINE_COMMENT()


        elif alt17 == 57:
            # Lua.g:1:365: WS
            pass 
            self.mWS()


        elif alt17 == 58:
            # Lua.g:1:368: NEWLINE
            pass 
            self.mNEWLINE()







    # lookup tables for DFA #3

    DFA3_eot = DFA.unpack(
        u"\4\uffff"
        )

    DFA3_eof = DFA.unpack(
        u"\4\uffff"
        )

    DFA3_min = DFA.unpack(
        u"\1\60\1\56\2\uffff"
        )

    DFA3_max = DFA.unpack(
        u"\1\71\1\145\2\uffff"
        )

    DFA3_accept = DFA.unpack(
        u"\2\uffff\1\2\1\1"
        )

    DFA3_special = DFA.unpack(
        u"\4\uffff"
        )

            
    DFA3_transition = [
        DFA.unpack(u"\12\1"),
        DFA.unpack(u"\1\2\1\uffff\12\1\13\uffff\1\3\37\uffff\1\3"),
        DFA.unpack(u""),
        DFA.unpack(u"")
    ]

    # class definition for DFA #3

    DFA3 = DFA
    # lookup tables for DFA #17

    DFA17_eot = DFA.unpack(
        u"\2\uffff\7\43\1\67\3\43\1\74\2\uffff\2\43\1\100\1\102\2\uffff\1"
        u"\104\4\uffff\1\43\2\uffff\1\110\5\uffff\2\112\4\uffff\1\115\3\43"
        u"\1\121\1\122\6\43\2\uffff\3\43\1\135\1\uffff\1\43\1\137\6\uffff"
        u"\2\43\7\uffff\1\145\2\43\2\uffff\2\43\1\152\6\43\2\uffff\1\161"
        u"\3\uffff\1\163\1\164\1\165\1\uffff\1\167\1\43\1\171\1\172\1\uffff"
        u"\6\43\5\uffff\1\43\1\uffff\1\u0086\2\uffff\1\43\1\u0088\1\u0089"
        u"\1\43\1\u008b\1\43\2\uffff\1\141\1\uffff\1\u008f\1\uffff\1\43\2"
        u"\uffff\1\u0091\1\uffff\1\43\1\u008e\2\uffff\1\43\1\uffff\1\43\1"
        u"\u0095\1\u0096\2\uffff"
        )

    DFA17_eof = DFA.unpack(
        u"\u0097\uffff"
        )

    DFA17_min = DFA.unpack(
        u"\1\11\1\uffff\1\157\1\154\1\150\1\146\1\150\1\141\1\157\1\75\1"
        u"\145\1\162\1\157\1\56\2\uffff\1\156\1\162\2\75\2\uffff\1\55\4\uffff"
        u"\1\151\2\uffff\1\75\5\uffff\2\56\4\uffff\1\60\1\144\1\163\1\151"
        u"\2\60\1\145\1\165\1\162\1\156\1\154\1\143\2\uffff\1\164\1\145\1"
        u"\156\1\56\1\uffff\1\144\1\60\4\uffff\1\0\1\uffff\1\154\1\164\4"
        u"\uffff\1\60\2\uffff\1\60\1\145\1\154\2\uffff\1\156\1\145\1\60\1"
        u"\143\1\163\1\141\1\165\1\141\1\164\2\uffff\1\60\1\uffff\1\0\1\uffff"
        u"\3\60\1\uffff\1\60\1\145\2\60\1\uffff\1\164\1\145\1\154\1\162\1"
        u"\153\1\151\1\uffff\1\0\3\uffff\1\146\1\uffff\1\60\2\uffff\1\151"
        u"\2\60\1\156\1\60\1\156\4\0\1\60\1\uffff\1\157\2\uffff\1\60\1\uffff"
        u"\1\165\1\0\2\uffff\1\156\1\uffff\1\145\2\60\2\uffff"
        )

    DFA17_max = DFA.unpack(
        u"\1\176\1\uffff\1\157\1\156\1\150\1\156\1\162\1\165\1\157\1\75\1"
        u"\145\1\162\1\157\1\56\2\uffff\1\156\1\162\2\75\2\uffff\1\55\4\uffff"
        u"\1\157\2\uffff\1\133\5\uffff\1\170\1\145\4\uffff\1\172\1\144\1"
        u"\163\1\151\2\172\1\145\1\165\1\162\1\156\1\154\1\143\2\uffff\1"
        u"\164\1\145\1\156\1\56\1\uffff\1\144\1\172\4\uffff\1\uffff\1\uffff"
        u"\1\154\1\164\4\uffff\1\71\2\uffff\1\172\1\145\1\154\2\uffff\1\156"
        u"\1\145\1\172\1\143\1\163\1\141\1\165\1\141\1\164\2\uffff\1\172"
        u"\1\uffff\1\uffff\1\uffff\2\172\1\145\1\uffff\1\172\1\145\2\172"
        u"\1\uffff\1\164\1\145\1\154\1\162\1\153\1\151\1\uffff\1\uffff\3"
        u"\uffff\1\146\1\uffff\1\172\2\uffff\1\151\2\172\1\156\1\172\1\156"
        u"\4\uffff\1\172\1\uffff\1\157\2\uffff\1\172\1\uffff\1\165\1\uffff"
        u"\2\uffff\1\156\1\uffff\1\145\2\172\2\uffff"
        )

    DFA17_accept = DFA.unpack(
        u"\1\uffff\1\1\14\uffff\1\22\1\23\4\uffff\1\33\1\34\1\uffff\1\36"
        u"\1\37\1\40\1\41\1\uffff\1\47\1\50\1\uffff\1\52\1\53\1\54\1\56\1"
        u"\57\2\uffff\1\64\1\65\1\71\1\72\14\uffff\1\32\1\15\4\uffff\1\21"
        u"\2\uffff\1\27\1\26\1\31\1\30\1\uffff\1\35\2\uffff\1\66\1\51\1\63"
        u"\1\60\1\uffff\1\62\1\2\3\uffff\1\5\1\12\11\uffff\1\46\1\42\1\uffff"
        u"\1\25\1\uffff\1\70\3\uffff\1\3\4\uffff\1\11\6\uffff\1\24\1\uffff"
        u"\1\43\1\55\1\61\1\uffff\1\10\1\uffff\1\6\1\45\13\uffff\1\4\1\uffff"
        u"\1\44\1\14\1\uffff\1\17\2\uffff\1\67\1\7\1\uffff\1\16\3\uffff\1"
        u"\13\1\20"
        )

    DFA17_special = DFA.unpack(
        u"\103\uffff\1\2\34\uffff\1\7\21\uffff\1\5\16\uffff\1\0\1\4\1\6\1"
        u"\1\10\uffff\1\3\11\uffff"
        )

            
    DFA17_transition = [
        DFA.unpack(u"\1\50\1\51\1\uffff\1\50\1\51\22\uffff\1\50\1\uffff\1"
        u"\46\1\42\1\uffff\1\32\1\uffff\1\47\1\34\1\35\1\27\1\25\1\17\1\26"
        u"\1\15\1\30\1\44\11\45\1\16\1\1\1\22\1\11\1\23\2\uffff\32\43\1\36"
        u"\1\uffff\1\37\1\31\1\43\1\uffff\1\20\1\13\1\14\1\2\1\3\1\7\2\43"
        u"\1\5\2\43\1\10\1\43\1\33\1\21\2\43\1\12\1\43\1\6\2\43\1\4\3\43"
        u"\1\40\1\uffff\1\41\1\24"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\52"),
        DFA.unpack(u"\1\54\1\uffff\1\53"),
        DFA.unpack(u"\1\55"),
        DFA.unpack(u"\1\56\7\uffff\1\57"),
        DFA.unpack(u"\1\60\11\uffff\1\61"),
        DFA.unpack(u"\1\64\15\uffff\1\62\5\uffff\1\63"),
        DFA.unpack(u"\1\65"),
        DFA.unpack(u"\1\66"),
        DFA.unpack(u"\1\70"),
        DFA.unpack(u"\1\71"),
        DFA.unpack(u"\1\72"),
        DFA.unpack(u"\1\73"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\75"),
        DFA.unpack(u"\1\76"),
        DFA.unpack(u"\1\77"),
        DFA.unpack(u"\1\101"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\103"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\105\5\uffff\1\106"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\107\35\uffff\1\107"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\113\1\uffff\12\45\13\uffff\1\114\37\uffff\1\114"
        u"\22\uffff\1\111"),
        DFA.unpack(u"\1\113\1\uffff\12\45\13\uffff\1\114\37\uffff\1\114"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\116"),
        DFA.unpack(u"\1\117"),
        DFA.unpack(u"\1\120"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\123"),
        DFA.unpack(u"\1\124"),
        DFA.unpack(u"\1\125"),
        DFA.unpack(u"\1\126"),
        DFA.unpack(u"\1\127"),
        DFA.unpack(u"\1\130"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\131"),
        DFA.unpack(u"\1\132"),
        DFA.unpack(u"\1\133"),
        DFA.unpack(u"\1\134"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\136"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\133\141\1\140\uffa4\141"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\142"),
        DFA.unpack(u"\1\143"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\12\144"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\146"),
        DFA.unpack(u"\1\147"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\150"),
        DFA.unpack(u"\1\151"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\153"),
        DFA.unpack(u"\1\154"),
        DFA.unpack(u"\1\155"),
        DFA.unpack(u"\1\156"),
        DFA.unpack(u"\1\157"),
        DFA.unpack(u"\1\160"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u"\133\141\1\162\uffa4\141"),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\144\13\uffff\1\114\37\uffff\1\114"),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\10\43\1\166"
        u"\21\43"),
        DFA.unpack(u"\1\170"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\173"),
        DFA.unpack(u"\1\174"),
        DFA.unpack(u"\1\175"),
        DFA.unpack(u"\1\176"),
        DFA.unpack(u"\1\177"),
        DFA.unpack(u"\1\u0080"),
        DFA.unpack(u""),
        DFA.unpack(u"\12\u0084\1\u0083\2\u0084\1\u0082\117\u0084\1\u0081"
        u"\uffa2\u0084"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0085"),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0087"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\u008a"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\1\u008c"),
        DFA.unpack(u"\12\u0084\1\u0083\2\u0084\1\u0082\117\u0084\1\u008d"
        u"\uffa2\u0084"),
        DFA.unpack(u"\12\u008e\1\u0083\ufff5\u008e"),
        DFA.unpack(u"\0\u008e"),
        DFA.unpack(u"\12\u0084\1\u0083\2\u0084\1\u0082\117\u0084\1\u0081"
        u"\uffa2\u0084"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0090"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0092"),
        DFA.unpack(u"\12\u0084\1\u0083\2\u0084\1\u0082\117\u0084\1\u008d"
        u"\uffa2\u0084"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0093"),
        DFA.unpack(u""),
        DFA.unpack(u"\1\u0094"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u"\12\43\7\uffff\32\43\4\uffff\1\43\1\uffff\32\43"),
        DFA.unpack(u""),
        DFA.unpack(u"")
    ]

    # class definition for DFA #17

    class DFA17(DFA):
        def specialStateTransition(self_, s, input):
            # convince pylint that my self_ magic is ok ;)
            # pylint: disable-msg=E0213

            # pretend we are a member of the recognizer
            # thus semantic predicates can be evaluated
            self = self_.recognizer

            _s = s

            if s == 0: 
                LA17_129 = input.LA(1)

                s = -1
                if (LA17_129 == 93):
                    s = 141

                elif (LA17_129 == 13):
                    s = 130

                elif (LA17_129 == 10):
                    s = 131

                elif ((0 <= LA17_129 <= 9) or (11 <= LA17_129 <= 12) or (14 <= LA17_129 <= 92) or (94 <= LA17_129 <= 65535)):
                    s = 132

                if s >= 0:
                    return s
            elif s == 1: 
                LA17_132 = input.LA(1)

                s = -1
                if (LA17_132 == 93):
                    s = 129

                elif (LA17_132 == 13):
                    s = 130

                elif (LA17_132 == 10):
                    s = 131

                elif ((0 <= LA17_132 <= 9) or (11 <= LA17_132 <= 12) or (14 <= LA17_132 <= 92) or (94 <= LA17_132 <= 65535)):
                    s = 132

                if s >= 0:
                    return s
            elif s == 2: 
                LA17_67 = input.LA(1)

                s = -1
                if (LA17_67 == 91):
                    s = 96

                elif ((0 <= LA17_67 <= 90) or (92 <= LA17_67 <= 65535)):
                    s = 97

                if s >= 0:
                    return s
            elif s == 3: 
                LA17_141 = input.LA(1)

                s = -1
                if (LA17_141 == 93):
                    s = 141

                elif (LA17_141 == 13):
                    s = 130

                elif (LA17_141 == 10):
                    s = 131

                elif ((0 <= LA17_141 <= 9) or (11 <= LA17_141 <= 12) or (14 <= LA17_141 <= 92) or (94 <= LA17_141 <= 65535)):
                    s = 132

                else:
                    s = 142

                if s >= 0:
                    return s
            elif s == 4: 
                LA17_130 = input.LA(1)

                s = -1
                if ((0 <= LA17_130 <= 9) or (11 <= LA17_130 <= 65535)):
                    s = 142

                elif (LA17_130 == 10):
                    s = 131

                if s >= 0:
                    return s
            elif s == 5: 
                LA17_114 = input.LA(1)

                s = -1
                if (LA17_114 == 93):
                    s = 129

                elif (LA17_114 == 13):
                    s = 130

                elif (LA17_114 == 10):
                    s = 131

                elif ((0 <= LA17_114 <= 9) or (11 <= LA17_114 <= 12) or (14 <= LA17_114 <= 92) or (94 <= LA17_114 <= 65535)):
                    s = 132

                if s >= 0:
                    return s
            elif s == 6: 
                LA17_131 = input.LA(1)

                s = -1
                if ((0 <= LA17_131 <= 65535)):
                    s = 142

                else:
                    s = 97

                if s >= 0:
                    return s
            elif s == 7: 
                LA17_96 = input.LA(1)

                s = -1
                if (LA17_96 == 91):
                    s = 114

                elif ((0 <= LA17_96 <= 90) or (92 <= LA17_96 <= 65535)):
                    s = 97

                if s >= 0:
                    return s

            nvae = NoViableAltException(self_.getDescription(), 17, _s, input)
            self_.error(nvae)
            raise nvae
 



def main(argv, stdin=sys.stdin, stdout=sys.stdout, stderr=sys.stderr):
    from antlr3.main import LexerMain
    main = LexerMain(LuaLexer)
    main.stdin = stdin
    main.stdout = stdout
    main.stderr = stderr
    main.execute(argv)


if __name__ == '__main__':
    main(sys.argv)
