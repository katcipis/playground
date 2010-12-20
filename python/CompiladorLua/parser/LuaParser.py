# $ANTLR 3.1.2 Lua.g 2010-11-30 13:20:03

import sys
from antlr3 import *
from antlr3.compat import set, frozenset

from antlr3.tree import *



# for convenience in actions
HIDDEN = BaseRecognizer.HIDDEN

# token types
T__64=64
T__29=29
T__65=65
T__28=28
T__62=62
T__27=27
T__63=63
T__26=26
T__25=25
T__24=24
T__23=23
T__22=22
T__21=21
T__20=20
FLOAT=6
T__61=61
T__60=60
EOF=-1
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
CHARSTRING=10
INT=5
LONGSTRING=11
T__30=30
NORMALSTRING=9
T__31=31
T__32=32
WS=18
T__33=33
T__34=34
NEWLINE=19
T__35=35
T__36=36
T__37=37
T__38=38
T__39=39
UnicodeEscape=13
OctalEscape=14
EscapeSequence=12

# token names
tokenNames = [
    "<invalid>", "<EOR>", "<DOWN>", "<UP>", 
    "NAME", "INT", "FLOAT", "EXP", "HEX", "NORMALSTRING", "CHARSTRING", 
    "LONGSTRING", "EscapeSequence", "UnicodeEscape", "OctalEscape", "HexDigit", 
    "COMMENT", "LINE_COMMENT", "WS", "NEWLINE", "';'", "'do'", "'end'", 
    "'while'", "'if'", "'then'", "'elseif'", "'else'", "'for'", "'in'", 
    "'function'", "'local'", "'='", "'return'", "'break'", "'continue'", 
    "'.'", "':'", "','", "'and'", "'or'", "'<'", "'<='", "'>'", "'>='", 
    "'=='", "'~='", "'+'", "'-'", "'*'", "'/'", "'^'", "'%'", "'..'", "'nil'", 
    "'false'", "'true'", "'...'", "'('", "')'", "'['", "']'", "'{'", "'}'", 
    "'not'", "'#'"
]




class LuaParser(Parser):
    grammarFileName = "Lua.g"
    antlr_version = version_str_to_tuple("3.1.2")
    antlr_version_str = "3.1.2"
    tokenNames = tokenNames

    def __init__(self, input, state=None):
        if state is None:
            state = RecognizerSharedState()

        Parser.__init__(self, input, state)


        self.dfa11 = self.DFA11(
            self, 11,
            eot = self.DFA11_eot,
            eof = self.DFA11_eof,
            min = self.DFA11_min,
            max = self.DFA11_max,
            accept = self.DFA11_accept,
            special = self.DFA11_special,
            transition = self.DFA11_transition
            )






                
        self._adaptor = CommonTreeAdaptor()


        
    def getTreeAdaptor(self):
        return self._adaptor

    def setTreeAdaptor(self, adaptor):
        self._adaptor = adaptor

    adaptor = property(getTreeAdaptor, setTreeAdaptor)


    class prog_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "prog"
    # Lua.g:10:1: prog : ( stat )+ ;
    def prog(self, ):

        retval = self.prog_return()
        retval.start = self.input.LT(1)

        root_0 = None

        stat1 = None



        try:
            try:
                # Lua.g:10:5: ( ( stat )+ )
                # Lua.g:10:7: ( stat )+
                pass 
                root_0 = self._adaptor.nil()

                # Lua.g:10:7: ( stat )+
                cnt1 = 0
                while True: #loop1
                    alt1 = 2
                    LA1_0 = self.input.LA(1)

                    if (LA1_0 == NAME or LA1_0 == 21 or (23 <= LA1_0 <= 24) or LA1_0 == 28 or (30 <= LA1_0 <= 31)) :
                        alt1 = 1


                    if alt1 == 1:
                        # Lua.g:10:8: stat
                        pass 
                        self._state.following.append(self.FOLLOW_stat_in_prog39)
                        stat1 = self.stat()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, stat1.tree)
                        #action start
                        print(stat1.tree.toStringTree())
                        #action end


                    else:
                        if cnt1 >= 1:
                            break #loop1

                        eee = EarlyExitException(1, self.input)
                        raise eee

                    cnt1 += 1





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "prog"

    class chunk_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "chunk"
    # Lua.g:12:1: chunk : ( stat ( ';' )? )* ( laststat ( ';' )? )? ;
    def chunk(self, ):

        retval = self.chunk_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal3 = None
        char_literal5 = None
        stat2 = None

        laststat4 = None


        char_literal3_tree = None
        char_literal5_tree = None

        try:
            try:
                # Lua.g:12:7: ( ( stat ( ';' )? )* ( laststat ( ';' )? )? )
                # Lua.g:12:9: ( stat ( ';' )? )* ( laststat ( ';' )? )?
                pass 
                root_0 = self._adaptor.nil()

                # Lua.g:12:9: ( stat ( ';' )? )*
                while True: #loop3
                    alt3 = 2
                    LA3_0 = self.input.LA(1)

                    if (LA3_0 == NAME or LA3_0 == 21 or (23 <= LA3_0 <= 24) or LA3_0 == 28 or (30 <= LA3_0 <= 31)) :
                        alt3 = 1


                    if alt3 == 1:
                        # Lua.g:12:10: stat ( ';' )?
                        pass 
                        self._state.following.append(self.FOLLOW_stat_in_chunk53)
                        stat2 = self.stat()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, stat2.tree)
                        # Lua.g:12:15: ( ';' )?
                        alt2 = 2
                        LA2_0 = self.input.LA(1)

                        if (LA2_0 == 20) :
                            alt2 = 1
                        if alt2 == 1:
                            # Lua.g:12:16: ';'
                            pass 
                            char_literal3=self.match(self.input, 20, self.FOLLOW_20_in_chunk56)

                            char_literal3_tree = self._adaptor.createWithPayload(char_literal3)
                            self._adaptor.addChild(root_0, char_literal3_tree)






                    else:
                        break #loop3


                # Lua.g:12:24: ( laststat ( ';' )? )?
                alt5 = 2
                LA5_0 = self.input.LA(1)

                if ((33 <= LA5_0 <= 35)) :
                    alt5 = 1
                if alt5 == 1:
                    # Lua.g:12:25: laststat ( ';' )?
                    pass 
                    self._state.following.append(self.FOLLOW_laststat_in_chunk63)
                    laststat4 = self.laststat()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, laststat4.tree)
                    # Lua.g:12:34: ( ';' )?
                    alt4 = 2
                    LA4_0 = self.input.LA(1)

                    if (LA4_0 == 20) :
                        alt4 = 1
                    if alt4 == 1:
                        # Lua.g:12:35: ';'
                        pass 
                        char_literal5=self.match(self.input, 20, self.FOLLOW_20_in_chunk66)

                        char_literal5_tree = self._adaptor.createWithPayload(char_literal5)
                        self._adaptor.addChild(root_0, char_literal5_tree)










                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "chunk"

    class block_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "block"
    # Lua.g:14:1: block : chunk ;
    def block(self, ):

        retval = self.block_return()
        retval.start = self.input.LT(1)

        root_0 = None

        chunk6 = None



        try:
            try:
                # Lua.g:14:7: ( chunk )
                # Lua.g:14:9: chunk
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_chunk_in_block78)
                chunk6 = self.chunk()

                self._state.following.pop()
                self._adaptor.addChild(root_0, chunk6.tree)



                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "block"

    class stat_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "stat"
    # Lua.g:16:1: stat : ( functioncall | 'do' block 'end' | 'while' exp 'do' block 'end' | 'if' exp 'then' block ( 'elseif' exp 'then' block )* ( 'else' block )? 'end' | 'for' namelist 'in' NAME 'do' block 'end' | 'function' ( funcname )? funcbody | 'local' 'function' NAME funcbody | ( 'local' )? namelist ( '=' explist1 )? -> ^( '=' ( 'local' )? namelist explist1 ) );
    def stat(self, ):

        retval = self.stat_return()
        retval.start = self.input.LT(1)

        root_0 = None

        string_literal8 = None
        string_literal10 = None
        string_literal11 = None
        string_literal13 = None
        string_literal15 = None
        string_literal16 = None
        string_literal18 = None
        string_literal20 = None
        string_literal22 = None
        string_literal24 = None
        string_literal26 = None
        string_literal27 = None
        string_literal29 = None
        NAME30 = None
        string_literal31 = None
        string_literal33 = None
        string_literal34 = None
        string_literal37 = None
        string_literal38 = None
        NAME39 = None
        string_literal41 = None
        char_literal43 = None
        functioncall7 = None

        block9 = None

        exp12 = None

        block14 = None

        exp17 = None

        block19 = None

        exp21 = None

        block23 = None

        block25 = None

        namelist28 = None

        block32 = None

        funcname35 = None

        funcbody36 = None

        funcbody40 = None

        namelist42 = None

        explist144 = None


        string_literal8_tree = None
        string_literal10_tree = None
        string_literal11_tree = None
        string_literal13_tree = None
        string_literal15_tree = None
        string_literal16_tree = None
        string_literal18_tree = None
        string_literal20_tree = None
        string_literal22_tree = None
        string_literal24_tree = None
        string_literal26_tree = None
        string_literal27_tree = None
        string_literal29_tree = None
        NAME30_tree = None
        string_literal31_tree = None
        string_literal33_tree = None
        string_literal34_tree = None
        string_literal37_tree = None
        string_literal38_tree = None
        NAME39_tree = None
        string_literal41_tree = None
        char_literal43_tree = None
        stream_32 = RewriteRuleTokenStream(self._adaptor, "token 32")
        stream_31 = RewriteRuleTokenStream(self._adaptor, "token 31")
        stream_namelist = RewriteRuleSubtreeStream(self._adaptor, "rule namelist")
        stream_explist1 = RewriteRuleSubtreeStream(self._adaptor, "rule explist1")
        try:
            try:
                # Lua.g:16:6: ( functioncall | 'do' block 'end' | 'while' exp 'do' block 'end' | 'if' exp 'then' block ( 'elseif' exp 'then' block )* ( 'else' block )? 'end' | 'for' namelist 'in' NAME 'do' block 'end' | 'function' ( funcname )? funcbody | 'local' 'function' NAME funcbody | ( 'local' )? namelist ( '=' explist1 )? -> ^( '=' ( 'local' )? namelist explist1 ) )
                alt11 = 8
                alt11 = self.dfa11.predict(self.input)
                if alt11 == 1:
                    # Lua.g:16:9: functioncall
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_functioncall_in_stat87)
                    functioncall7 = self.functioncall()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, functioncall7.tree)


                elif alt11 == 2:
                    # Lua.g:17:2: 'do' block 'end'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal8=self.match(self.input, 21, self.FOLLOW_21_in_stat93)

                    string_literal8_tree = self._adaptor.createWithPayload(string_literal8)
                    self._adaptor.addChild(root_0, string_literal8_tree)

                    self._state.following.append(self.FOLLOW_block_in_stat95)
                    block9 = self.block()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, block9.tree)
                    string_literal10=self.match(self.input, 22, self.FOLLOW_22_in_stat97)

                    string_literal10_tree = self._adaptor.createWithPayload(string_literal10)
                    self._adaptor.addChild(root_0, string_literal10_tree)



                elif alt11 == 3:
                    # Lua.g:18:2: 'while' exp 'do' block 'end'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal11=self.match(self.input, 23, self.FOLLOW_23_in_stat103)

                    string_literal11_tree = self._adaptor.createWithPayload(string_literal11)
                    self._adaptor.addChild(root_0, string_literal11_tree)

                    self._state.following.append(self.FOLLOW_exp_in_stat105)
                    exp12 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp12.tree)
                    string_literal13=self.match(self.input, 21, self.FOLLOW_21_in_stat107)

                    string_literal13_tree = self._adaptor.createWithPayload(string_literal13)
                    self._adaptor.addChild(root_0, string_literal13_tree)

                    self._state.following.append(self.FOLLOW_block_in_stat109)
                    block14 = self.block()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, block14.tree)
                    string_literal15=self.match(self.input, 22, self.FOLLOW_22_in_stat111)

                    string_literal15_tree = self._adaptor.createWithPayload(string_literal15)
                    self._adaptor.addChild(root_0, string_literal15_tree)



                elif alt11 == 4:
                    # Lua.g:19:2: 'if' exp 'then' block ( 'elseif' exp 'then' block )* ( 'else' block )? 'end'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal16=self.match(self.input, 24, self.FOLLOW_24_in_stat117)

                    string_literal16_tree = self._adaptor.createWithPayload(string_literal16)
                    self._adaptor.addChild(root_0, string_literal16_tree)

                    self._state.following.append(self.FOLLOW_exp_in_stat119)
                    exp17 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp17.tree)
                    string_literal18=self.match(self.input, 25, self.FOLLOW_25_in_stat121)

                    string_literal18_tree = self._adaptor.createWithPayload(string_literal18)
                    self._adaptor.addChild(root_0, string_literal18_tree)

                    self._state.following.append(self.FOLLOW_block_in_stat123)
                    block19 = self.block()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, block19.tree)
                    # Lua.g:19:24: ( 'elseif' exp 'then' block )*
                    while True: #loop6
                        alt6 = 2
                        LA6_0 = self.input.LA(1)

                        if (LA6_0 == 26) :
                            alt6 = 1


                        if alt6 == 1:
                            # Lua.g:19:25: 'elseif' exp 'then' block
                            pass 
                            string_literal20=self.match(self.input, 26, self.FOLLOW_26_in_stat126)

                            string_literal20_tree = self._adaptor.createWithPayload(string_literal20)
                            self._adaptor.addChild(root_0, string_literal20_tree)

                            self._state.following.append(self.FOLLOW_exp_in_stat128)
                            exp21 = self.exp()

                            self._state.following.pop()
                            self._adaptor.addChild(root_0, exp21.tree)
                            string_literal22=self.match(self.input, 25, self.FOLLOW_25_in_stat130)

                            string_literal22_tree = self._adaptor.createWithPayload(string_literal22)
                            self._adaptor.addChild(root_0, string_literal22_tree)

                            self._state.following.append(self.FOLLOW_block_in_stat132)
                            block23 = self.block()

                            self._state.following.pop()
                            self._adaptor.addChild(root_0, block23.tree)


                        else:
                            break #loop6


                    # Lua.g:19:53: ( 'else' block )?
                    alt7 = 2
                    LA7_0 = self.input.LA(1)

                    if (LA7_0 == 27) :
                        alt7 = 1
                    if alt7 == 1:
                        # Lua.g:19:54: 'else' block
                        pass 
                        string_literal24=self.match(self.input, 27, self.FOLLOW_27_in_stat137)

                        string_literal24_tree = self._adaptor.createWithPayload(string_literal24)
                        self._adaptor.addChild(root_0, string_literal24_tree)

                        self._state.following.append(self.FOLLOW_block_in_stat139)
                        block25 = self.block()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, block25.tree)



                    string_literal26=self.match(self.input, 22, self.FOLLOW_22_in_stat143)

                    string_literal26_tree = self._adaptor.createWithPayload(string_literal26)
                    self._adaptor.addChild(root_0, string_literal26_tree)



                elif alt11 == 5:
                    # Lua.g:20:2: 'for' namelist 'in' NAME 'do' block 'end'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal27=self.match(self.input, 28, self.FOLLOW_28_in_stat149)

                    string_literal27_tree = self._adaptor.createWithPayload(string_literal27)
                    self._adaptor.addChild(root_0, string_literal27_tree)

                    self._state.following.append(self.FOLLOW_namelist_in_stat151)
                    namelist28 = self.namelist()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, namelist28.tree)
                    string_literal29=self.match(self.input, 29, self.FOLLOW_29_in_stat153)

                    string_literal29_tree = self._adaptor.createWithPayload(string_literal29)
                    self._adaptor.addChild(root_0, string_literal29_tree)

                    NAME30=self.match(self.input, NAME, self.FOLLOW_NAME_in_stat155)

                    NAME30_tree = self._adaptor.createWithPayload(NAME30)
                    self._adaptor.addChild(root_0, NAME30_tree)

                    string_literal31=self.match(self.input, 21, self.FOLLOW_21_in_stat157)

                    string_literal31_tree = self._adaptor.createWithPayload(string_literal31)
                    self._adaptor.addChild(root_0, string_literal31_tree)

                    self._state.following.append(self.FOLLOW_block_in_stat159)
                    block32 = self.block()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, block32.tree)
                    string_literal33=self.match(self.input, 22, self.FOLLOW_22_in_stat161)

                    string_literal33_tree = self._adaptor.createWithPayload(string_literal33)
                    self._adaptor.addChild(root_0, string_literal33_tree)



                elif alt11 == 6:
                    # Lua.g:21:2: 'function' ( funcname )? funcbody
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal34=self.match(self.input, 30, self.FOLLOW_30_in_stat167)

                    string_literal34_tree = self._adaptor.createWithPayload(string_literal34)
                    self._adaptor.addChild(root_0, string_literal34_tree)

                    # Lua.g:21:13: ( funcname )?
                    alt8 = 2
                    LA8_0 = self.input.LA(1)

                    if (LA8_0 == NAME) :
                        alt8 = 1
                    if alt8 == 1:
                        # Lua.g:21:13: funcname
                        pass 
                        self._state.following.append(self.FOLLOW_funcname_in_stat169)
                        funcname35 = self.funcname()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, funcname35.tree)



                    self._state.following.append(self.FOLLOW_funcbody_in_stat172)
                    funcbody36 = self.funcbody()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, funcbody36.tree)


                elif alt11 == 7:
                    # Lua.g:22:2: 'local' 'function' NAME funcbody
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal37=self.match(self.input, 31, self.FOLLOW_31_in_stat177)

                    string_literal37_tree = self._adaptor.createWithPayload(string_literal37)
                    self._adaptor.addChild(root_0, string_literal37_tree)

                    string_literal38=self.match(self.input, 30, self.FOLLOW_30_in_stat179)

                    string_literal38_tree = self._adaptor.createWithPayload(string_literal38)
                    self._adaptor.addChild(root_0, string_literal38_tree)

                    NAME39=self.match(self.input, NAME, self.FOLLOW_NAME_in_stat181)

                    NAME39_tree = self._adaptor.createWithPayload(NAME39)
                    self._adaptor.addChild(root_0, NAME39_tree)

                    self._state.following.append(self.FOLLOW_funcbody_in_stat183)
                    funcbody40 = self.funcbody()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, funcbody40.tree)


                elif alt11 == 8:
                    # Lua.g:23:2: ( 'local' )? namelist ( '=' explist1 )?
                    pass 
                    # Lua.g:23:2: ( 'local' )?
                    alt9 = 2
                    LA9_0 = self.input.LA(1)

                    if (LA9_0 == 31) :
                        alt9 = 1
                    if alt9 == 1:
                        # Lua.g:23:2: 'local'
                        pass 
                        string_literal41=self.match(self.input, 31, self.FOLLOW_31_in_stat189) 
                        stream_31.add(string_literal41)



                    self._state.following.append(self.FOLLOW_namelist_in_stat192)
                    namelist42 = self.namelist()

                    self._state.following.pop()
                    stream_namelist.add(namelist42.tree)
                    # Lua.g:23:20: ( '=' explist1 )?
                    alt10 = 2
                    LA10_0 = self.input.LA(1)

                    if (LA10_0 == 32) :
                        alt10 = 1
                    if alt10 == 1:
                        # Lua.g:23:21: '=' explist1
                        pass 
                        char_literal43=self.match(self.input, 32, self.FOLLOW_32_in_stat195) 
                        stream_32.add(char_literal43)
                        self._state.following.append(self.FOLLOW_explist1_in_stat197)
                        explist144 = self.explist1()

                        self._state.following.pop()
                        stream_explist1.add(explist144.tree)




                    # AST Rewrite
                    # elements: namelist, explist1, 31, 32
                    # token labels: 
                    # rule labels: retval
                    # token list labels: 
                    # rule list labels: 
                    # wildcard labels: 

                    retval.tree = root_0

                    if retval is not None:
                        stream_retval = RewriteRuleSubtreeStream(self._adaptor, "rule retval", retval.tree)
                    else:
                        stream_retval = RewriteRuleSubtreeStream(self._adaptor, "token retval", None)


                    root_0 = self._adaptor.nil()
                    # 23:36: -> ^( '=' ( 'local' )? namelist explist1 )
                    # Lua.g:23:39: ^( '=' ( 'local' )? namelist explist1 )
                    root_1 = self._adaptor.nil()
                    root_1 = self._adaptor.becomeRoot(stream_32.nextNode(), root_1)

                    # Lua.g:23:45: ( 'local' )?
                    if stream_31.hasNext():
                        self._adaptor.addChild(root_1, stream_31.nextNode())


                    stream_31.reset();
                    self._adaptor.addChild(root_1, stream_namelist.nextTree())
                    self._adaptor.addChild(root_1, stream_explist1.nextTree())

                    self._adaptor.addChild(root_0, root_1)



                    retval.tree = root_0


                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "stat"

    class laststat_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "laststat"
    # Lua.g:25:1: laststat : ( 'return' ( explist1 )? | 'break' | 'continue' );
    def laststat(self, ):

        retval = self.laststat_return()
        retval.start = self.input.LT(1)

        root_0 = None

        string_literal45 = None
        string_literal47 = None
        string_literal48 = None
        explist146 = None


        string_literal45_tree = None
        string_literal47_tree = None
        string_literal48_tree = None

        try:
            try:
                # Lua.g:25:10: ( 'return' ( explist1 )? | 'break' | 'continue' )
                alt13 = 3
                LA13 = self.input.LA(1)
                if LA13 == 33:
                    alt13 = 1
                elif LA13 == 34:
                    alt13 = 2
                elif LA13 == 35:
                    alt13 = 3
                else:
                    nvae = NoViableAltException("", 13, 0, self.input)

                    raise nvae

                if alt13 == 1:
                    # Lua.g:25:12: 'return' ( explist1 )?
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal45=self.match(self.input, 33, self.FOLLOW_33_in_laststat220)

                    string_literal45_tree = self._adaptor.createWithPayload(string_literal45)
                    self._adaptor.addChild(root_0, string_literal45_tree)

                    # Lua.g:25:21: ( explist1 )?
                    alt12 = 2
                    LA12_0 = self.input.LA(1)

                    if ((NAME <= LA12_0 <= LONGSTRING) or LA12_0 == 30 or LA12_0 == 48 or (54 <= LA12_0 <= 58) or LA12_0 == 62 or (64 <= LA12_0 <= 65)) :
                        alt12 = 1
                    if alt12 == 1:
                        # Lua.g:25:22: explist1
                        pass 
                        self._state.following.append(self.FOLLOW_explist1_in_laststat223)
                        explist146 = self.explist1()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, explist146.tree)





                elif alt13 == 2:
                    # Lua.g:25:35: 'break'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal47=self.match(self.input, 34, self.FOLLOW_34_in_laststat229)

                    string_literal47_tree = self._adaptor.createWithPayload(string_literal47)
                    self._adaptor.addChild(root_0, string_literal47_tree)



                elif alt13 == 3:
                    # Lua.g:25:45: 'continue'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal48=self.match(self.input, 35, self.FOLLOW_35_in_laststat233)

                    string_literal48_tree = self._adaptor.createWithPayload(string_literal48)
                    self._adaptor.addChild(root_0, string_literal48_tree)



                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "laststat"

    class funcname_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "funcname"
    # Lua.g:27:1: funcname : NAME ( '.' NAME )* ( ':' NAME )? ;
    def funcname(self, ):

        retval = self.funcname_return()
        retval.start = self.input.LT(1)

        root_0 = None

        NAME49 = None
        char_literal50 = None
        NAME51 = None
        char_literal52 = None
        NAME53 = None

        NAME49_tree = None
        char_literal50_tree = None
        NAME51_tree = None
        char_literal52_tree = None
        NAME53_tree = None

        try:
            try:
                # Lua.g:27:10: ( NAME ( '.' NAME )* ( ':' NAME )? )
                # Lua.g:27:12: NAME ( '.' NAME )* ( ':' NAME )?
                pass 
                root_0 = self._adaptor.nil()

                NAME49=self.match(self.input, NAME, self.FOLLOW_NAME_in_funcname241)

                NAME49_tree = self._adaptor.createWithPayload(NAME49)
                self._adaptor.addChild(root_0, NAME49_tree)

                # Lua.g:27:17: ( '.' NAME )*
                while True: #loop14
                    alt14 = 2
                    LA14_0 = self.input.LA(1)

                    if (LA14_0 == 36) :
                        alt14 = 1


                    if alt14 == 1:
                        # Lua.g:27:18: '.' NAME
                        pass 
                        char_literal50=self.match(self.input, 36, self.FOLLOW_36_in_funcname244)

                        char_literal50_tree = self._adaptor.createWithPayload(char_literal50)
                        self._adaptor.addChild(root_0, char_literal50_tree)

                        NAME51=self.match(self.input, NAME, self.FOLLOW_NAME_in_funcname246)

                        NAME51_tree = self._adaptor.createWithPayload(NAME51)
                        self._adaptor.addChild(root_0, NAME51_tree)



                    else:
                        break #loop14


                # Lua.g:27:29: ( ':' NAME )?
                alt15 = 2
                LA15_0 = self.input.LA(1)

                if (LA15_0 == 37) :
                    alt15 = 1
                if alt15 == 1:
                    # Lua.g:27:30: ':' NAME
                    pass 
                    char_literal52=self.match(self.input, 37, self.FOLLOW_37_in_funcname251)

                    char_literal52_tree = self._adaptor.createWithPayload(char_literal52)
                    self._adaptor.addChild(root_0, char_literal52_tree)

                    NAME53=self.match(self.input, NAME, self.FOLLOW_NAME_in_funcname253)

                    NAME53_tree = self._adaptor.createWithPayload(NAME53)
                    self._adaptor.addChild(root_0, NAME53_tree)







                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "funcname"

    class namelist_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "namelist"
    # Lua.g:29:1: namelist : NAME ( ',' NAME )* ;
    def namelist(self, ):

        retval = self.namelist_return()
        retval.start = self.input.LT(1)

        root_0 = None

        NAME54 = None
        char_literal55 = None
        NAME56 = None

        NAME54_tree = None
        char_literal55_tree = None
        NAME56_tree = None

        try:
            try:
                # Lua.g:29:10: ( NAME ( ',' NAME )* )
                # Lua.g:29:12: NAME ( ',' NAME )*
                pass 
                root_0 = self._adaptor.nil()

                NAME54=self.match(self.input, NAME, self.FOLLOW_NAME_in_namelist264)

                NAME54_tree = self._adaptor.createWithPayload(NAME54)
                self._adaptor.addChild(root_0, NAME54_tree)

                # Lua.g:29:17: ( ',' NAME )*
                while True: #loop16
                    alt16 = 2
                    LA16_0 = self.input.LA(1)

                    if (LA16_0 == 38) :
                        LA16_2 = self.input.LA(2)

                        if (LA16_2 == NAME) :
                            alt16 = 1




                    if alt16 == 1:
                        # Lua.g:29:18: ',' NAME
                        pass 
                        char_literal55=self.match(self.input, 38, self.FOLLOW_38_in_namelist267)

                        char_literal55_tree = self._adaptor.createWithPayload(char_literal55)
                        self._adaptor.addChild(root_0, char_literal55_tree)

                        NAME56=self.match(self.input, NAME, self.FOLLOW_NAME_in_namelist269)

                        NAME56_tree = self._adaptor.createWithPayload(NAME56)
                        self._adaptor.addChild(root_0, NAME56_tree)



                    else:
                        break #loop16





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "namelist"

    class explist1_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "explist1"
    # Lua.g:31:1: explist1 : exp ( ',' exp )* ;
    def explist1(self, ):

        retval = self.explist1_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal58 = None
        exp57 = None

        exp59 = None


        char_literal58_tree = None

        try:
            try:
                # Lua.g:31:10: ( exp ( ',' exp )* )
                # Lua.g:31:12: exp ( ',' exp )*
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_exp_in_explist1279)
                exp57 = self.exp()

                self._state.following.pop()
                self._adaptor.addChild(root_0, exp57.tree)
                # Lua.g:31:16: ( ',' exp )*
                while True: #loop17
                    alt17 = 2
                    LA17_0 = self.input.LA(1)

                    if (LA17_0 == 38) :
                        alt17 = 1


                    if alt17 == 1:
                        # Lua.g:31:17: ',' exp
                        pass 
                        char_literal58=self.match(self.input, 38, self.FOLLOW_38_in_explist1282)

                        char_literal58_tree = self._adaptor.createWithPayload(char_literal58)
                        self._adaptor.addChild(root_0, char_literal58_tree)

                        self._state.following.append(self.FOLLOW_exp_in_explist1284)
                        exp59 = self.exp()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, exp59.tree)


                    else:
                        break #loop17





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "explist1"

    class exp_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "exp"
    # Lua.g:33:1: exp : ( unop )? exp2 ( ( 'and' | 'or' ) exp2 )* ;
    def exp(self, ):

        retval = self.exp_return()
        retval.start = self.input.LT(1)

        root_0 = None

        string_literal62 = None
        string_literal63 = None
        unop60 = None

        exp261 = None

        exp264 = None


        string_literal62_tree = None
        string_literal63_tree = None

        try:
            try:
                # Lua.g:33:4: ( ( unop )? exp2 ( ( 'and' | 'or' ) exp2 )* )
                # Lua.g:33:6: ( unop )? exp2 ( ( 'and' | 'or' ) exp2 )*
                pass 
                root_0 = self._adaptor.nil()

                # Lua.g:33:6: ( unop )?
                alt18 = 2
                LA18_0 = self.input.LA(1)

                if (LA18_0 == 48 or (64 <= LA18_0 <= 65)) :
                    alt18 = 1
                if alt18 == 1:
                    # Lua.g:33:6: unop
                    pass 
                    self._state.following.append(self.FOLLOW_unop_in_exp293)
                    unop60 = self.unop()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, unop60.tree)



                self._state.following.append(self.FOLLOW_exp2_in_exp296)
                exp261 = self.exp2()

                self._state.following.pop()
                self._adaptor.addChild(root_0, exp261.tree)
                # Lua.g:33:17: ( ( 'and' | 'or' ) exp2 )*
                while True: #loop20
                    alt20 = 2
                    LA20_0 = self.input.LA(1)

                    if ((39 <= LA20_0 <= 40)) :
                        alt20 = 1


                    if alt20 == 1:
                        # Lua.g:33:18: ( 'and' | 'or' ) exp2
                        pass 
                        # Lua.g:33:18: ( 'and' | 'or' )
                        alt19 = 2
                        LA19_0 = self.input.LA(1)

                        if (LA19_0 == 39) :
                            alt19 = 1
                        elif (LA19_0 == 40) :
                            alt19 = 2
                        else:
                            nvae = NoViableAltException("", 19, 0, self.input)

                            raise nvae

                        if alt19 == 1:
                            # Lua.g:33:19: 'and'
                            pass 
                            string_literal62=self.match(self.input, 39, self.FOLLOW_39_in_exp300)

                            string_literal62_tree = self._adaptor.createWithPayload(string_literal62)
                            root_0 = self._adaptor.becomeRoot(string_literal62_tree, root_0)



                        elif alt19 == 2:
                            # Lua.g:33:28: 'or'
                            pass 
                            string_literal63=self.match(self.input, 40, self.FOLLOW_40_in_exp305)

                            string_literal63_tree = self._adaptor.createWithPayload(string_literal63)
                            root_0 = self._adaptor.becomeRoot(string_literal63_tree, root_0)




                        self._state.following.append(self.FOLLOW_exp2_in_exp309)
                        exp264 = self.exp2()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, exp264.tree)


                    else:
                        break #loop20





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "exp"

    class exp2_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "exp2"
    # Lua.g:35:1: exp2 : exp3 ( ( '<' | '<=' | '>' | '>=' | '==' | '~=' ) exp3 )* ;
    def exp2(self, ):

        retval = self.exp2_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal66 = None
        string_literal67 = None
        char_literal68 = None
        string_literal69 = None
        string_literal70 = None
        string_literal71 = None
        exp365 = None

        exp372 = None


        char_literal66_tree = None
        string_literal67_tree = None
        char_literal68_tree = None
        string_literal69_tree = None
        string_literal70_tree = None
        string_literal71_tree = None

        try:
            try:
                # Lua.g:35:5: ( exp3 ( ( '<' | '<=' | '>' | '>=' | '==' | '~=' ) exp3 )* )
                # Lua.g:35:7: exp3 ( ( '<' | '<=' | '>' | '>=' | '==' | '~=' ) exp3 )*
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_exp3_in_exp2318)
                exp365 = self.exp3()

                self._state.following.pop()
                self._adaptor.addChild(root_0, exp365.tree)
                # Lua.g:35:12: ( ( '<' | '<=' | '>' | '>=' | '==' | '~=' ) exp3 )*
                while True: #loop22
                    alt22 = 2
                    LA22_0 = self.input.LA(1)

                    if ((41 <= LA22_0 <= 46)) :
                        alt22 = 1


                    if alt22 == 1:
                        # Lua.g:35:13: ( '<' | '<=' | '>' | '>=' | '==' | '~=' ) exp3
                        pass 
                        # Lua.g:35:13: ( '<' | '<=' | '>' | '>=' | '==' | '~=' )
                        alt21 = 6
                        LA21 = self.input.LA(1)
                        if LA21 == 41:
                            alt21 = 1
                        elif LA21 == 42:
                            alt21 = 2
                        elif LA21 == 43:
                            alt21 = 3
                        elif LA21 == 44:
                            alt21 = 4
                        elif LA21 == 45:
                            alt21 = 5
                        elif LA21 == 46:
                            alt21 = 6
                        else:
                            nvae = NoViableAltException("", 21, 0, self.input)

                            raise nvae

                        if alt21 == 1:
                            # Lua.g:35:14: '<'
                            pass 
                            char_literal66=self.match(self.input, 41, self.FOLLOW_41_in_exp2322)

                            char_literal66_tree = self._adaptor.createWithPayload(char_literal66)
                            root_0 = self._adaptor.becomeRoot(char_literal66_tree, root_0)



                        elif alt21 == 2:
                            # Lua.g:35:21: '<='
                            pass 
                            string_literal67=self.match(self.input, 42, self.FOLLOW_42_in_exp2327)

                            string_literal67_tree = self._adaptor.createWithPayload(string_literal67)
                            root_0 = self._adaptor.becomeRoot(string_literal67_tree, root_0)



                        elif alt21 == 3:
                            # Lua.g:35:29: '>'
                            pass 
                            char_literal68=self.match(self.input, 43, self.FOLLOW_43_in_exp2332)

                            char_literal68_tree = self._adaptor.createWithPayload(char_literal68)
                            root_0 = self._adaptor.becomeRoot(char_literal68_tree, root_0)



                        elif alt21 == 4:
                            # Lua.g:35:36: '>='
                            pass 
                            string_literal69=self.match(self.input, 44, self.FOLLOW_44_in_exp2337)

                            string_literal69_tree = self._adaptor.createWithPayload(string_literal69)
                            root_0 = self._adaptor.becomeRoot(string_literal69_tree, root_0)



                        elif alt21 == 5:
                            # Lua.g:35:44: '=='
                            pass 
                            string_literal70=self.match(self.input, 45, self.FOLLOW_45_in_exp2342)

                            string_literal70_tree = self._adaptor.createWithPayload(string_literal70)
                            root_0 = self._adaptor.becomeRoot(string_literal70_tree, root_0)



                        elif alt21 == 6:
                            # Lua.g:35:52: '~='
                            pass 
                            string_literal71=self.match(self.input, 46, self.FOLLOW_46_in_exp2347)

                            string_literal71_tree = self._adaptor.createWithPayload(string_literal71)
                            root_0 = self._adaptor.becomeRoot(string_literal71_tree, root_0)




                        self._state.following.append(self.FOLLOW_exp3_in_exp2351)
                        exp372 = self.exp3()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, exp372.tree)


                    else:
                        break #loop22





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "exp2"

    class exp3_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "exp3"
    # Lua.g:37:1: exp3 : exp4 ( ( '+' | '-' ) exp4 )* ;
    def exp3(self, ):

        retval = self.exp3_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal74 = None
        char_literal75 = None
        exp473 = None

        exp476 = None


        char_literal74_tree = None
        char_literal75_tree = None

        try:
            try:
                # Lua.g:37:5: ( exp4 ( ( '+' | '-' ) exp4 )* )
                # Lua.g:37:7: exp4 ( ( '+' | '-' ) exp4 )*
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_exp4_in_exp3360)
                exp473 = self.exp4()

                self._state.following.pop()
                self._adaptor.addChild(root_0, exp473.tree)
                # Lua.g:37:12: ( ( '+' | '-' ) exp4 )*
                while True: #loop24
                    alt24 = 2
                    LA24_0 = self.input.LA(1)

                    if ((47 <= LA24_0 <= 48)) :
                        alt24 = 1


                    if alt24 == 1:
                        # Lua.g:37:13: ( '+' | '-' ) exp4
                        pass 
                        # Lua.g:37:13: ( '+' | '-' )
                        alt23 = 2
                        LA23_0 = self.input.LA(1)

                        if (LA23_0 == 47) :
                            alt23 = 1
                        elif (LA23_0 == 48) :
                            alt23 = 2
                        else:
                            nvae = NoViableAltException("", 23, 0, self.input)

                            raise nvae

                        if alt23 == 1:
                            # Lua.g:37:14: '+'
                            pass 
                            char_literal74=self.match(self.input, 47, self.FOLLOW_47_in_exp3364)

                            char_literal74_tree = self._adaptor.createWithPayload(char_literal74)
                            root_0 = self._adaptor.becomeRoot(char_literal74_tree, root_0)



                        elif alt23 == 2:
                            # Lua.g:37:21: '-'
                            pass 
                            char_literal75=self.match(self.input, 48, self.FOLLOW_48_in_exp3369)

                            char_literal75_tree = self._adaptor.createWithPayload(char_literal75)
                            root_0 = self._adaptor.becomeRoot(char_literal75_tree, root_0)




                        self._state.following.append(self.FOLLOW_exp4_in_exp3373)
                        exp476 = self.exp4()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, exp476.tree)


                    else:
                        break #loop24





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "exp3"

    class exp4_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "exp4"
    # Lua.g:39:1: exp4 : atom ( ( '*' | '/' | '^' | '%' | '..' ) atom )* ;
    def exp4(self, ):

        retval = self.exp4_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal78 = None
        char_literal79 = None
        char_literal80 = None
        char_literal81 = None
        string_literal82 = None
        atom77 = None

        atom83 = None


        char_literal78_tree = None
        char_literal79_tree = None
        char_literal80_tree = None
        char_literal81_tree = None
        string_literal82_tree = None

        try:
            try:
                # Lua.g:39:5: ( atom ( ( '*' | '/' | '^' | '%' | '..' ) atom )* )
                # Lua.g:39:7: atom ( ( '*' | '/' | '^' | '%' | '..' ) atom )*
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_atom_in_exp4382)
                atom77 = self.atom()

                self._state.following.pop()
                self._adaptor.addChild(root_0, atom77.tree)
                # Lua.g:39:12: ( ( '*' | '/' | '^' | '%' | '..' ) atom )*
                while True: #loop26
                    alt26 = 2
                    LA26_0 = self.input.LA(1)

                    if ((49 <= LA26_0 <= 53)) :
                        alt26 = 1


                    if alt26 == 1:
                        # Lua.g:39:13: ( '*' | '/' | '^' | '%' | '..' ) atom
                        pass 
                        # Lua.g:39:13: ( '*' | '/' | '^' | '%' | '..' )
                        alt25 = 5
                        LA25 = self.input.LA(1)
                        if LA25 == 49:
                            alt25 = 1
                        elif LA25 == 50:
                            alt25 = 2
                        elif LA25 == 51:
                            alt25 = 3
                        elif LA25 == 52:
                            alt25 = 4
                        elif LA25 == 53:
                            alt25 = 5
                        else:
                            nvae = NoViableAltException("", 25, 0, self.input)

                            raise nvae

                        if alt25 == 1:
                            # Lua.g:39:14: '*'
                            pass 
                            char_literal78=self.match(self.input, 49, self.FOLLOW_49_in_exp4386)

                            char_literal78_tree = self._adaptor.createWithPayload(char_literal78)
                            root_0 = self._adaptor.becomeRoot(char_literal78_tree, root_0)



                        elif alt25 == 2:
                            # Lua.g:39:21: '/'
                            pass 
                            char_literal79=self.match(self.input, 50, self.FOLLOW_50_in_exp4391)

                            char_literal79_tree = self._adaptor.createWithPayload(char_literal79)
                            root_0 = self._adaptor.becomeRoot(char_literal79_tree, root_0)



                        elif alt25 == 3:
                            # Lua.g:39:28: '^'
                            pass 
                            char_literal80=self.match(self.input, 51, self.FOLLOW_51_in_exp4396)

                            char_literal80_tree = self._adaptor.createWithPayload(char_literal80)
                            root_0 = self._adaptor.becomeRoot(char_literal80_tree, root_0)



                        elif alt25 == 4:
                            # Lua.g:39:35: '%'
                            pass 
                            char_literal81=self.match(self.input, 52, self.FOLLOW_52_in_exp4401)

                            char_literal81_tree = self._adaptor.createWithPayload(char_literal81)
                            root_0 = self._adaptor.becomeRoot(char_literal81_tree, root_0)



                        elif alt25 == 5:
                            # Lua.g:39:42: '..'
                            pass 
                            string_literal82=self.match(self.input, 53, self.FOLLOW_53_in_exp4406)

                            string_literal82_tree = self._adaptor.createWithPayload(string_literal82)
                            root_0 = self._adaptor.becomeRoot(string_literal82_tree, root_0)




                        self._state.following.append(self.FOLLOW_atom_in_exp4410)
                        atom83 = self.atom()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, atom83.tree)


                    else:
                        break #loop26





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "exp4"

    class atom_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "atom"
    # Lua.g:41:1: atom : ( 'nil' | 'false' | 'true' | string | number | '...' | function | prefixexp | tableconstructor | '(' exp ')' );
    def atom(self, ):

        retval = self.atom_return()
        retval.start = self.input.LT(1)

        root_0 = None

        string_literal84 = None
        string_literal85 = None
        string_literal86 = None
        string_literal89 = None
        char_literal93 = None
        char_literal95 = None
        string87 = None

        number88 = None

        function90 = None

        prefixexp91 = None

        tableconstructor92 = None

        exp94 = None


        string_literal84_tree = None
        string_literal85_tree = None
        string_literal86_tree = None
        string_literal89_tree = None
        char_literal93_tree = None
        char_literal95_tree = None

        try:
            try:
                # Lua.g:41:5: ( 'nil' | 'false' | 'true' | string | number | '...' | function | prefixexp | tableconstructor | '(' exp ')' )
                alt27 = 10
                LA27 = self.input.LA(1)
                if LA27 == 54:
                    alt27 = 1
                elif LA27 == 55:
                    alt27 = 2
                elif LA27 == 56:
                    alt27 = 3
                elif LA27 == NORMALSTRING or LA27 == CHARSTRING or LA27 == LONGSTRING:
                    alt27 = 4
                elif LA27 == INT or LA27 == FLOAT or LA27 == EXP or LA27 == HEX:
                    alt27 = 5
                elif LA27 == 57:
                    alt27 = 6
                elif LA27 == 30:
                    alt27 = 7
                elif LA27 == NAME:
                    alt27 = 8
                elif LA27 == 62:
                    alt27 = 9
                elif LA27 == 58:
                    alt27 = 10
                else:
                    nvae = NoViableAltException("", 27, 0, self.input)

                    raise nvae

                if alt27 == 1:
                    # Lua.g:41:7: 'nil'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal84=self.match(self.input, 54, self.FOLLOW_54_in_atom419)

                    string_literal84_tree = self._adaptor.createWithPayload(string_literal84)
                    self._adaptor.addChild(root_0, string_literal84_tree)



                elif alt27 == 2:
                    # Lua.g:41:15: 'false'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal85=self.match(self.input, 55, self.FOLLOW_55_in_atom423)

                    string_literal85_tree = self._adaptor.createWithPayload(string_literal85)
                    self._adaptor.addChild(root_0, string_literal85_tree)



                elif alt27 == 3:
                    # Lua.g:41:25: 'true'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal86=self.match(self.input, 56, self.FOLLOW_56_in_atom427)

                    string_literal86_tree = self._adaptor.createWithPayload(string_literal86)
                    self._adaptor.addChild(root_0, string_literal86_tree)



                elif alt27 == 4:
                    # Lua.g:41:34: string
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_string_in_atom431)
                    string87 = self.string()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, string87.tree)


                elif alt27 == 5:
                    # Lua.g:41:43: number
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_number_in_atom435)
                    number88 = self.number()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, number88.tree)


                elif alt27 == 6:
                    # Lua.g:41:52: '...'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal89=self.match(self.input, 57, self.FOLLOW_57_in_atom439)

                    string_literal89_tree = self._adaptor.createWithPayload(string_literal89)
                    self._adaptor.addChild(root_0, string_literal89_tree)



                elif alt27 == 7:
                    # Lua.g:41:60: function
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_function_in_atom443)
                    function90 = self.function()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, function90.tree)


                elif alt27 == 8:
                    # Lua.g:41:71: prefixexp
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_prefixexp_in_atom447)
                    prefixexp91 = self.prefixexp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, prefixexp91.tree)


                elif alt27 == 9:
                    # Lua.g:41:83: tableconstructor
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_tableconstructor_in_atom451)
                    tableconstructor92 = self.tableconstructor()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, tableconstructor92.tree)


                elif alt27 == 10:
                    # Lua.g:41:102: '(' exp ')'
                    pass 
                    root_0 = self._adaptor.nil()

                    char_literal93=self.match(self.input, 58, self.FOLLOW_58_in_atom455)
                    self._state.following.append(self.FOLLOW_exp_in_atom458)
                    exp94 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp94.tree)
                    char_literal95=self.match(self.input, 59, self.FOLLOW_59_in_atom460)


                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "atom"

    class prefixexp_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "prefixexp"
    # Lua.g:43:1: prefixexp : NAME ( nameAndArgs )* ;
    def prefixexp(self, ):

        retval = self.prefixexp_return()
        retval.start = self.input.LT(1)

        root_0 = None

        NAME96 = None
        nameAndArgs97 = None


        NAME96_tree = None

        try:
            try:
                # Lua.g:43:10: ( NAME ( nameAndArgs )* )
                # Lua.g:43:12: NAME ( nameAndArgs )*
                pass 
                root_0 = self._adaptor.nil()

                NAME96=self.match(self.input, NAME, self.FOLLOW_NAME_in_prefixexp468)

                NAME96_tree = self._adaptor.createWithPayload(NAME96)
                self._adaptor.addChild(root_0, NAME96_tree)

                # Lua.g:43:17: ( nameAndArgs )*
                while True: #loop28
                    alt28 = 2
                    LA28_0 = self.input.LA(1)

                    if ((NORMALSTRING <= LA28_0 <= LONGSTRING) or LA28_0 == 37 or LA28_0 == 58 or LA28_0 == 62) :
                        alt28 = 1


                    if alt28 == 1:
                        # Lua.g:43:17: nameAndArgs
                        pass 
                        self._state.following.append(self.FOLLOW_nameAndArgs_in_prefixexp470)
                        nameAndArgs97 = self.nameAndArgs()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, nameAndArgs97.tree)


                    else:
                        break #loop28





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "prefixexp"

    class functioncall_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "functioncall"
    # Lua.g:45:1: functioncall : NAME ( nameAndArgs )+ ;
    def functioncall(self, ):

        retval = self.functioncall_return()
        retval.start = self.input.LT(1)

        root_0 = None

        NAME98 = None
        nameAndArgs99 = None


        NAME98_tree = None

        try:
            try:
                # Lua.g:45:13: ( NAME ( nameAndArgs )+ )
                # Lua.g:45:15: NAME ( nameAndArgs )+
                pass 
                root_0 = self._adaptor.nil()

                NAME98=self.match(self.input, NAME, self.FOLLOW_NAME_in_functioncall478)

                NAME98_tree = self._adaptor.createWithPayload(NAME98)
                self._adaptor.addChild(root_0, NAME98_tree)

                # Lua.g:45:20: ( nameAndArgs )+
                cnt29 = 0
                while True: #loop29
                    alt29 = 2
                    LA29_0 = self.input.LA(1)

                    if ((NORMALSTRING <= LA29_0 <= LONGSTRING) or LA29_0 == 37 or LA29_0 == 58 or LA29_0 == 62) :
                        alt29 = 1


                    if alt29 == 1:
                        # Lua.g:45:20: nameAndArgs
                        pass 
                        self._state.following.append(self.FOLLOW_nameAndArgs_in_functioncall480)
                        nameAndArgs99 = self.nameAndArgs()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, nameAndArgs99.tree)


                    else:
                        if cnt29 >= 1:
                            break #loop29

                        eee = EarlyExitException(29, self.input)
                        raise eee

                    cnt29 += 1





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "functioncall"

    class nameAndArgs_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "nameAndArgs"
    # Lua.g:47:1: nameAndArgs : ( ':' NAME )? args ;
    def nameAndArgs(self, ):

        retval = self.nameAndArgs_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal100 = None
        NAME101 = None
        args102 = None


        char_literal100_tree = None
        NAME101_tree = None

        try:
            try:
                # Lua.g:47:12: ( ( ':' NAME )? args )
                # Lua.g:47:14: ( ':' NAME )? args
                pass 
                root_0 = self._adaptor.nil()

                # Lua.g:47:14: ( ':' NAME )?
                alt30 = 2
                LA30_0 = self.input.LA(1)

                if (LA30_0 == 37) :
                    alt30 = 1
                if alt30 == 1:
                    # Lua.g:47:15: ':' NAME
                    pass 
                    char_literal100=self.match(self.input, 37, self.FOLLOW_37_in_nameAndArgs489)

                    char_literal100_tree = self._adaptor.createWithPayload(char_literal100)
                    self._adaptor.addChild(root_0, char_literal100_tree)

                    NAME101=self.match(self.input, NAME, self.FOLLOW_NAME_in_nameAndArgs491)

                    NAME101_tree = self._adaptor.createWithPayload(NAME101)
                    self._adaptor.addChild(root_0, NAME101_tree)




                self._state.following.append(self.FOLLOW_args_in_nameAndArgs495)
                args102 = self.args()

                self._state.following.pop()
                self._adaptor.addChild(root_0, args102.tree)



                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "nameAndArgs"

    class varSuffix_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "varSuffix"
    # Lua.g:49:1: varSuffix : ( nameAndArgs )* ( '[' exp ']' | '.' NAME ) ;
    def varSuffix(self, ):

        retval = self.varSuffix_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal104 = None
        char_literal106 = None
        char_literal107 = None
        NAME108 = None
        nameAndArgs103 = None

        exp105 = None


        char_literal104_tree = None
        char_literal106_tree = None
        char_literal107_tree = None
        NAME108_tree = None

        try:
            try:
                # Lua.g:49:10: ( ( nameAndArgs )* ( '[' exp ']' | '.' NAME ) )
                # Lua.g:49:12: ( nameAndArgs )* ( '[' exp ']' | '.' NAME )
                pass 
                root_0 = self._adaptor.nil()

                # Lua.g:49:12: ( nameAndArgs )*
                while True: #loop31
                    alt31 = 2
                    LA31_0 = self.input.LA(1)

                    if ((NORMALSTRING <= LA31_0 <= LONGSTRING) or LA31_0 == 37 or LA31_0 == 58 or LA31_0 == 62) :
                        alt31 = 1


                    if alt31 == 1:
                        # Lua.g:49:12: nameAndArgs
                        pass 
                        self._state.following.append(self.FOLLOW_nameAndArgs_in_varSuffix502)
                        nameAndArgs103 = self.nameAndArgs()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, nameAndArgs103.tree)


                    else:
                        break #loop31


                # Lua.g:49:25: ( '[' exp ']' | '.' NAME )
                alt32 = 2
                LA32_0 = self.input.LA(1)

                if (LA32_0 == 60) :
                    alt32 = 1
                elif (LA32_0 == 36) :
                    alt32 = 2
                else:
                    nvae = NoViableAltException("", 32, 0, self.input)

                    raise nvae

                if alt32 == 1:
                    # Lua.g:49:26: '[' exp ']'
                    pass 
                    char_literal104=self.match(self.input, 60, self.FOLLOW_60_in_varSuffix506)

                    char_literal104_tree = self._adaptor.createWithPayload(char_literal104)
                    self._adaptor.addChild(root_0, char_literal104_tree)

                    self._state.following.append(self.FOLLOW_exp_in_varSuffix508)
                    exp105 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp105.tree)
                    char_literal106=self.match(self.input, 61, self.FOLLOW_61_in_varSuffix510)

                    char_literal106_tree = self._adaptor.createWithPayload(char_literal106)
                    self._adaptor.addChild(root_0, char_literal106_tree)



                elif alt32 == 2:
                    # Lua.g:49:40: '.' NAME
                    pass 
                    char_literal107=self.match(self.input, 36, self.FOLLOW_36_in_varSuffix514)

                    char_literal107_tree = self._adaptor.createWithPayload(char_literal107)
                    self._adaptor.addChild(root_0, char_literal107_tree)

                    NAME108=self.match(self.input, NAME, self.FOLLOW_NAME_in_varSuffix516)

                    NAME108_tree = self._adaptor.createWithPayload(NAME108)
                    self._adaptor.addChild(root_0, NAME108_tree)







                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "varSuffix"

    class args_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "args"
    # Lua.g:51:1: args : ( '(' ( explist1 )? ')' | tableconstructor | string );
    def args(self, ):

        retval = self.args_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal109 = None
        char_literal111 = None
        explist1110 = None

        tableconstructor112 = None

        string113 = None


        char_literal109_tree = None
        char_literal111_tree = None

        try:
            try:
                # Lua.g:51:6: ( '(' ( explist1 )? ')' | tableconstructor | string )
                alt34 = 3
                LA34 = self.input.LA(1)
                if LA34 == 58:
                    alt34 = 1
                elif LA34 == 62:
                    alt34 = 2
                elif LA34 == NORMALSTRING or LA34 == CHARSTRING or LA34 == LONGSTRING:
                    alt34 = 3
                else:
                    nvae = NoViableAltException("", 34, 0, self.input)

                    raise nvae

                if alt34 == 1:
                    # Lua.g:51:9: '(' ( explist1 )? ')'
                    pass 
                    root_0 = self._adaptor.nil()

                    char_literal109=self.match(self.input, 58, self.FOLLOW_58_in_args526)

                    char_literal109_tree = self._adaptor.createWithPayload(char_literal109)
                    self._adaptor.addChild(root_0, char_literal109_tree)

                    # Lua.g:51:13: ( explist1 )?
                    alt33 = 2
                    LA33_0 = self.input.LA(1)

                    if ((NAME <= LA33_0 <= LONGSTRING) or LA33_0 == 30 or LA33_0 == 48 or (54 <= LA33_0 <= 58) or LA33_0 == 62 or (64 <= LA33_0 <= 65)) :
                        alt33 = 1
                    if alt33 == 1:
                        # Lua.g:51:14: explist1
                        pass 
                        self._state.following.append(self.FOLLOW_explist1_in_args529)
                        explist1110 = self.explist1()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, explist1110.tree)



                    char_literal111=self.match(self.input, 59, self.FOLLOW_59_in_args533)

                    char_literal111_tree = self._adaptor.createWithPayload(char_literal111)
                    self._adaptor.addChild(root_0, char_literal111_tree)



                elif alt34 == 2:
                    # Lua.g:51:31: tableconstructor
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_tableconstructor_in_args537)
                    tableconstructor112 = self.tableconstructor()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, tableconstructor112.tree)


                elif alt34 == 3:
                    # Lua.g:51:50: string
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_string_in_args541)
                    string113 = self.string()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, string113.tree)


                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "args"

    class function_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "function"
    # Lua.g:53:1: function : 'function' funcbody ;
    def function(self, ):

        retval = self.function_return()
        retval.start = self.input.LT(1)

        root_0 = None

        string_literal114 = None
        funcbody115 = None


        string_literal114_tree = None

        try:
            try:
                # Lua.g:53:10: ( 'function' funcbody )
                # Lua.g:53:12: 'function' funcbody
                pass 
                root_0 = self._adaptor.nil()

                string_literal114=self.match(self.input, 30, self.FOLLOW_30_in_function550)

                string_literal114_tree = self._adaptor.createWithPayload(string_literal114)
                self._adaptor.addChild(root_0, string_literal114_tree)

                self._state.following.append(self.FOLLOW_funcbody_in_function552)
                funcbody115 = self.funcbody()

                self._state.following.pop()
                self._adaptor.addChild(root_0, funcbody115.tree)



                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "function"

    class funcbody_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "funcbody"
    # Lua.g:55:1: funcbody : '(' ( parlist1 )? ')' block 'end' ;
    def funcbody(self, ):

        retval = self.funcbody_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal116 = None
        char_literal118 = None
        string_literal120 = None
        parlist1117 = None

        block119 = None


        char_literal116_tree = None
        char_literal118_tree = None
        string_literal120_tree = None

        try:
            try:
                # Lua.g:55:10: ( '(' ( parlist1 )? ')' block 'end' )
                # Lua.g:55:12: '(' ( parlist1 )? ')' block 'end'
                pass 
                root_0 = self._adaptor.nil()

                char_literal116=self.match(self.input, 58, self.FOLLOW_58_in_funcbody560)

                char_literal116_tree = self._adaptor.createWithPayload(char_literal116)
                self._adaptor.addChild(root_0, char_literal116_tree)

                # Lua.g:55:16: ( parlist1 )?
                alt35 = 2
                LA35_0 = self.input.LA(1)

                if (LA35_0 == NAME or LA35_0 == 57) :
                    alt35 = 1
                if alt35 == 1:
                    # Lua.g:55:17: parlist1
                    pass 
                    self._state.following.append(self.FOLLOW_parlist1_in_funcbody563)
                    parlist1117 = self.parlist1()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, parlist1117.tree)



                char_literal118=self.match(self.input, 59, self.FOLLOW_59_in_funcbody567)

                char_literal118_tree = self._adaptor.createWithPayload(char_literal118)
                self._adaptor.addChild(root_0, char_literal118_tree)

                self._state.following.append(self.FOLLOW_block_in_funcbody569)
                block119 = self.block()

                self._state.following.pop()
                self._adaptor.addChild(root_0, block119.tree)
                string_literal120=self.match(self.input, 22, self.FOLLOW_22_in_funcbody571)

                string_literal120_tree = self._adaptor.createWithPayload(string_literal120)
                self._adaptor.addChild(root_0, string_literal120_tree)




                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "funcbody"

    class parlist1_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "parlist1"
    # Lua.g:57:1: parlist1 : ( namelist ( ',' '...' )? | '...' );
    def parlist1(self, ):

        retval = self.parlist1_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal122 = None
        string_literal123 = None
        string_literal124 = None
        namelist121 = None


        char_literal122_tree = None
        string_literal123_tree = None
        string_literal124_tree = None

        try:
            try:
                # Lua.g:57:10: ( namelist ( ',' '...' )? | '...' )
                alt37 = 2
                LA37_0 = self.input.LA(1)

                if (LA37_0 == NAME) :
                    alt37 = 1
                elif (LA37_0 == 57) :
                    alt37 = 2
                else:
                    nvae = NoViableAltException("", 37, 0, self.input)

                    raise nvae

                if alt37 == 1:
                    # Lua.g:57:12: namelist ( ',' '...' )?
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_namelist_in_parlist1579)
                    namelist121 = self.namelist()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, namelist121.tree)
                    # Lua.g:57:21: ( ',' '...' )?
                    alt36 = 2
                    LA36_0 = self.input.LA(1)

                    if (LA36_0 == 38) :
                        alt36 = 1
                    if alt36 == 1:
                        # Lua.g:57:22: ',' '...'
                        pass 
                        char_literal122=self.match(self.input, 38, self.FOLLOW_38_in_parlist1582)

                        char_literal122_tree = self._adaptor.createWithPayload(char_literal122)
                        self._adaptor.addChild(root_0, char_literal122_tree)

                        string_literal123=self.match(self.input, 57, self.FOLLOW_57_in_parlist1584)

                        string_literal123_tree = self._adaptor.createWithPayload(string_literal123)
                        self._adaptor.addChild(root_0, string_literal123_tree)






                elif alt37 == 2:
                    # Lua.g:57:36: '...'
                    pass 
                    root_0 = self._adaptor.nil()

                    string_literal124=self.match(self.input, 57, self.FOLLOW_57_in_parlist1590)

                    string_literal124_tree = self._adaptor.createWithPayload(string_literal124)
                    self._adaptor.addChild(root_0, string_literal124_tree)



                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "parlist1"

    class tableconstructor_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "tableconstructor"
    # Lua.g:59:1: tableconstructor : '{' ( fieldlist )? '}' ;
    def tableconstructor(self, ):

        retval = self.tableconstructor_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal125 = None
        char_literal127 = None
        fieldlist126 = None


        char_literal125_tree = None
        char_literal127_tree = None

        try:
            try:
                # Lua.g:59:18: ( '{' ( fieldlist )? '}' )
                # Lua.g:59:20: '{' ( fieldlist )? '}'
                pass 
                root_0 = self._adaptor.nil()

                char_literal125=self.match(self.input, 62, self.FOLLOW_62_in_tableconstructor598)

                char_literal125_tree = self._adaptor.createWithPayload(char_literal125)
                self._adaptor.addChild(root_0, char_literal125_tree)

                # Lua.g:59:24: ( fieldlist )?
                alt38 = 2
                LA38_0 = self.input.LA(1)

                if ((NAME <= LA38_0 <= LONGSTRING) or LA38_0 == 30 or LA38_0 == 48 or (54 <= LA38_0 <= 58) or LA38_0 == 60 or LA38_0 == 62 or (64 <= LA38_0 <= 65)) :
                    alt38 = 1
                if alt38 == 1:
                    # Lua.g:59:25: fieldlist
                    pass 
                    self._state.following.append(self.FOLLOW_fieldlist_in_tableconstructor601)
                    fieldlist126 = self.fieldlist()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, fieldlist126.tree)



                char_literal127=self.match(self.input, 63, self.FOLLOW_63_in_tableconstructor605)

                char_literal127_tree = self._adaptor.createWithPayload(char_literal127)
                self._adaptor.addChild(root_0, char_literal127_tree)




                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "tableconstructor"

    class fieldlist_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "fieldlist"
    # Lua.g:61:1: fieldlist : field ( fieldsep field )* ( fieldsep )? ;
    def fieldlist(self, ):

        retval = self.fieldlist_return()
        retval.start = self.input.LT(1)

        root_0 = None

        field128 = None

        fieldsep129 = None

        field130 = None

        fieldsep131 = None



        try:
            try:
                # Lua.g:61:11: ( field ( fieldsep field )* ( fieldsep )? )
                # Lua.g:61:13: field ( fieldsep field )* ( fieldsep )?
                pass 
                root_0 = self._adaptor.nil()

                self._state.following.append(self.FOLLOW_field_in_fieldlist613)
                field128 = self.field()

                self._state.following.pop()
                self._adaptor.addChild(root_0, field128.tree)
                # Lua.g:61:19: ( fieldsep field )*
                while True: #loop39
                    alt39 = 2
                    LA39_0 = self.input.LA(1)

                    if (LA39_0 == 20 or LA39_0 == 38) :
                        LA39_1 = self.input.LA(2)

                        if ((NAME <= LA39_1 <= LONGSTRING) or LA39_1 == 30 or LA39_1 == 48 or (54 <= LA39_1 <= 58) or LA39_1 == 60 or LA39_1 == 62 or (64 <= LA39_1 <= 65)) :
                            alt39 = 1




                    if alt39 == 1:
                        # Lua.g:61:20: fieldsep field
                        pass 
                        self._state.following.append(self.FOLLOW_fieldsep_in_fieldlist616)
                        fieldsep129 = self.fieldsep()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, fieldsep129.tree)
                        self._state.following.append(self.FOLLOW_field_in_fieldlist618)
                        field130 = self.field()

                        self._state.following.pop()
                        self._adaptor.addChild(root_0, field130.tree)


                    else:
                        break #loop39


                # Lua.g:61:37: ( fieldsep )?
                alt40 = 2
                LA40_0 = self.input.LA(1)

                if (LA40_0 == 20 or LA40_0 == 38) :
                    alt40 = 1
                if alt40 == 1:
                    # Lua.g:61:38: fieldsep
                    pass 
                    self._state.following.append(self.FOLLOW_fieldsep_in_fieldlist623)
                    fieldsep131 = self.fieldsep()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, fieldsep131.tree)






                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "fieldlist"

    class field_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "field"
    # Lua.g:63:1: field : ( '[' exp ']' '=' exp | NAME '=' exp | exp );
    def field(self, ):

        retval = self.field_return()
        retval.start = self.input.LT(1)

        root_0 = None

        char_literal132 = None
        char_literal134 = None
        char_literal135 = None
        NAME137 = None
        char_literal138 = None
        exp133 = None

        exp136 = None

        exp139 = None

        exp140 = None


        char_literal132_tree = None
        char_literal134_tree = None
        char_literal135_tree = None
        NAME137_tree = None
        char_literal138_tree = None

        try:
            try:
                # Lua.g:63:7: ( '[' exp ']' '=' exp | NAME '=' exp | exp )
                alt41 = 3
                LA41 = self.input.LA(1)
                if LA41 == 60:
                    alt41 = 1
                elif LA41 == NAME:
                    LA41_2 = self.input.LA(2)

                    if (LA41_2 == 32) :
                        alt41 = 2
                    elif ((NORMALSTRING <= LA41_2 <= LONGSTRING) or LA41_2 == 20 or (37 <= LA41_2 <= 53) or LA41_2 == 58 or (62 <= LA41_2 <= 63)) :
                        alt41 = 3
                    else:
                        nvae = NoViableAltException("", 41, 2, self.input)

                        raise nvae

                elif LA41 == INT or LA41 == FLOAT or LA41 == EXP or LA41 == HEX or LA41 == NORMALSTRING or LA41 == CHARSTRING or LA41 == LONGSTRING or LA41 == 30 or LA41 == 48 or LA41 == 54 or LA41 == 55 or LA41 == 56 or LA41 == 57 or LA41 == 58 or LA41 == 62 or LA41 == 64 or LA41 == 65:
                    alt41 = 3
                else:
                    nvae = NoViableAltException("", 41, 0, self.input)

                    raise nvae

                if alt41 == 1:
                    # Lua.g:63:9: '[' exp ']' '=' exp
                    pass 
                    root_0 = self._adaptor.nil()

                    char_literal132=self.match(self.input, 60, self.FOLLOW_60_in_field633)

                    char_literal132_tree = self._adaptor.createWithPayload(char_literal132)
                    self._adaptor.addChild(root_0, char_literal132_tree)

                    self._state.following.append(self.FOLLOW_exp_in_field635)
                    exp133 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp133.tree)
                    char_literal134=self.match(self.input, 61, self.FOLLOW_61_in_field637)

                    char_literal134_tree = self._adaptor.createWithPayload(char_literal134)
                    self._adaptor.addChild(root_0, char_literal134_tree)

                    char_literal135=self.match(self.input, 32, self.FOLLOW_32_in_field639)

                    char_literal135_tree = self._adaptor.createWithPayload(char_literal135)
                    self._adaptor.addChild(root_0, char_literal135_tree)

                    self._state.following.append(self.FOLLOW_exp_in_field641)
                    exp136 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp136.tree)


                elif alt41 == 2:
                    # Lua.g:63:31: NAME '=' exp
                    pass 
                    root_0 = self._adaptor.nil()

                    NAME137=self.match(self.input, NAME, self.FOLLOW_NAME_in_field645)

                    NAME137_tree = self._adaptor.createWithPayload(NAME137)
                    self._adaptor.addChild(root_0, NAME137_tree)

                    char_literal138=self.match(self.input, 32, self.FOLLOW_32_in_field647)

                    char_literal138_tree = self._adaptor.createWithPayload(char_literal138)
                    self._adaptor.addChild(root_0, char_literal138_tree)

                    self._state.following.append(self.FOLLOW_exp_in_field649)
                    exp139 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp139.tree)


                elif alt41 == 3:
                    # Lua.g:63:46: exp
                    pass 
                    root_0 = self._adaptor.nil()

                    self._state.following.append(self.FOLLOW_exp_in_field653)
                    exp140 = self.exp()

                    self._state.following.pop()
                    self._adaptor.addChild(root_0, exp140.tree)


                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "field"

    class fieldsep_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "fieldsep"
    # Lua.g:65:1: fieldsep : ( ',' | ';' );
    def fieldsep(self, ):

        retval = self.fieldsep_return()
        retval.start = self.input.LT(1)

        root_0 = None

        set141 = None

        set141_tree = None

        try:
            try:
                # Lua.g:65:10: ( ',' | ';' )
                # Lua.g:
                pass 
                root_0 = self._adaptor.nil()

                set141 = self.input.LT(1)
                if self.input.LA(1) == 20 or self.input.LA(1) == 38:
                    self.input.consume()
                    self._adaptor.addChild(root_0, self._adaptor.createWithPayload(set141))
                    self._state.errorRecovery = False

                else:
                    mse = MismatchedSetException(None, self.input)
                    raise mse





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "fieldsep"

    class unop_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "unop"
    # Lua.g:67:1: unop : ( '-' | 'not' | '#' );
    def unop(self, ):

        retval = self.unop_return()
        retval.start = self.input.LT(1)

        root_0 = None

        set142 = None

        set142_tree = None

        try:
            try:
                # Lua.g:67:6: ( '-' | 'not' | '#' )
                # Lua.g:
                pass 
                root_0 = self._adaptor.nil()

                set142 = self.input.LT(1)
                if self.input.LA(1) == 48 or (64 <= self.input.LA(1) <= 65):
                    self.input.consume()
                    self._adaptor.addChild(root_0, self._adaptor.createWithPayload(set142))
                    self._state.errorRecovery = False

                else:
                    mse = MismatchedSetException(None, self.input)
                    raise mse





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "unop"

    class number_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "number"
    # Lua.g:69:1: number : ( INT | FLOAT | EXP | HEX );
    def number(self, ):

        retval = self.number_return()
        retval.start = self.input.LT(1)

        root_0 = None

        set143 = None

        set143_tree = None

        try:
            try:
                # Lua.g:69:8: ( INT | FLOAT | EXP | HEX )
                # Lua.g:
                pass 
                root_0 = self._adaptor.nil()

                set143 = self.input.LT(1)
                if (INT <= self.input.LA(1) <= HEX):
                    self.input.consume()
                    self._adaptor.addChild(root_0, self._adaptor.createWithPayload(set143))
                    self._state.errorRecovery = False

                else:
                    mse = MismatchedSetException(None, self.input)
                    raise mse





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "number"

    class string_return(ParserRuleReturnScope):
        def __init__(self):
            ParserRuleReturnScope.__init__(self)

            self.tree = None




    # $ANTLR start "string"
    # Lua.g:71:1: string : ( NORMALSTRING | CHARSTRING | LONGSTRING );
    def string(self, ):

        retval = self.string_return()
        retval.start = self.input.LT(1)

        root_0 = None

        set144 = None

        set144_tree = None

        try:
            try:
                # Lua.g:71:8: ( NORMALSTRING | CHARSTRING | LONGSTRING )
                # Lua.g:
                pass 
                root_0 = self._adaptor.nil()

                set144 = self.input.LT(1)
                if (NORMALSTRING <= self.input.LA(1) <= LONGSTRING):
                    self.input.consume()
                    self._adaptor.addChild(root_0, self._adaptor.createWithPayload(set144))
                    self._state.errorRecovery = False

                else:
                    mse = MismatchedSetException(None, self.input)
                    raise mse





                retval.stop = self.input.LT(-1)


                retval.tree = self._adaptor.rulePostProcessing(root_0)
                self._adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop)


            except RecognitionException, re:
                self.reportError(re)
                self.recover(self.input, re)
                retval.tree = self._adaptor.errorNode(self.input, retval.start, self.input.LT(-1), re)
        finally:

            pass

        return retval

    # $ANTLR end "string"


    # Delegated rules


    # lookup tables for DFA #11

    DFA11_eot = DFA.unpack(
        u"\13\uffff"
        )

    DFA11_eof = DFA.unpack(
        u"\1\uffff\1\10\11\uffff"
        )

    DFA11_min = DFA.unpack(
        u"\2\4\5\uffff\1\4\3\uffff"
        )

    DFA11_max = DFA.unpack(
        u"\1\37\1\76\5\uffff\1\36\3\uffff"
        )

    DFA11_accept = DFA.unpack(
        u"\2\uffff\1\2\1\3\1\4\1\5\1\6\1\uffff\1\10\1\1\1\7"
        )

    DFA11_special = DFA.unpack(
        u"\13\uffff"
        )

            
    DFA11_transition = [
        DFA.unpack(u"\1\1\20\uffff\1\2\1\uffff\1\3\1\4\3\uffff\1\5\1\uffff"
        u"\1\6\1\7"),
        DFA.unpack(u"\1\10\4\uffff\3\11\10\uffff\5\10\1\uffff\3\10\1\uffff"
        u"\6\10\1\uffff\1\11\1\10\23\uffff\1\11\3\uffff\1\11"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"\1\10\31\uffff\1\12"),
        DFA.unpack(u""),
        DFA.unpack(u""),
        DFA.unpack(u"")
    ]

    # class definition for DFA #11

    DFA11 = DFA
 

    FOLLOW_stat_in_prog39 = frozenset([1, 4, 21, 23, 24, 28, 30, 31])
    FOLLOW_stat_in_chunk53 = frozenset([1, 4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_20_in_chunk56 = frozenset([1, 4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_laststat_in_chunk63 = frozenset([1, 20])
    FOLLOW_20_in_chunk66 = frozenset([1])
    FOLLOW_chunk_in_block78 = frozenset([1])
    FOLLOW_functioncall_in_stat87 = frozenset([1])
    FOLLOW_21_in_stat93 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat95 = frozenset([22])
    FOLLOW_22_in_stat97 = frozenset([1])
    FOLLOW_23_in_stat103 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_stat105 = frozenset([21])
    FOLLOW_21_in_stat107 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat109 = frozenset([22])
    FOLLOW_22_in_stat111 = frozenset([1])
    FOLLOW_24_in_stat117 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_stat119 = frozenset([25])
    FOLLOW_25_in_stat121 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat123 = frozenset([22, 26, 27])
    FOLLOW_26_in_stat126 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_stat128 = frozenset([25])
    FOLLOW_25_in_stat130 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat132 = frozenset([22, 26, 27])
    FOLLOW_27_in_stat137 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat139 = frozenset([22])
    FOLLOW_22_in_stat143 = frozenset([1])
    FOLLOW_28_in_stat149 = frozenset([4, 21, 23, 24, 28, 29, 30, 31])
    FOLLOW_namelist_in_stat151 = frozenset([29])
    FOLLOW_29_in_stat153 = frozenset([4])
    FOLLOW_NAME_in_stat155 = frozenset([21])
    FOLLOW_21_in_stat157 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_stat159 = frozenset([22])
    FOLLOW_22_in_stat161 = frozenset([1])
    FOLLOW_30_in_stat167 = frozenset([4, 58])
    FOLLOW_funcname_in_stat169 = frozenset([4, 58])
    FOLLOW_funcbody_in_stat172 = frozenset([1])
    FOLLOW_31_in_stat177 = frozenset([30])
    FOLLOW_30_in_stat179 = frozenset([4])
    FOLLOW_NAME_in_stat181 = frozenset([4, 58])
    FOLLOW_funcbody_in_stat183 = frozenset([1])
    FOLLOW_31_in_stat189 = frozenset([4, 21, 23, 24, 28, 30, 31, 32])
    FOLLOW_namelist_in_stat192 = frozenset([1, 32])
    FOLLOW_32_in_stat195 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_explist1_in_stat197 = frozenset([1])
    FOLLOW_33_in_laststat220 = frozenset([1, 4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_explist1_in_laststat223 = frozenset([1])
    FOLLOW_34_in_laststat229 = frozenset([1])
    FOLLOW_35_in_laststat233 = frozenset([1])
    FOLLOW_NAME_in_funcname241 = frozenset([1, 36, 37])
    FOLLOW_36_in_funcname244 = frozenset([4])
    FOLLOW_NAME_in_funcname246 = frozenset([1, 36, 37])
    FOLLOW_37_in_funcname251 = frozenset([4])
    FOLLOW_NAME_in_funcname253 = frozenset([1])
    FOLLOW_NAME_in_namelist264 = frozenset([1, 38])
    FOLLOW_38_in_namelist267 = frozenset([4])
    FOLLOW_NAME_in_namelist269 = frozenset([1, 38])
    FOLLOW_exp_in_explist1279 = frozenset([1, 38])
    FOLLOW_38_in_explist1282 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_explist1284 = frozenset([1, 38])
    FOLLOW_unop_in_exp293 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp2_in_exp296 = frozenset([1, 39, 40])
    FOLLOW_39_in_exp300 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_40_in_exp305 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp2_in_exp309 = frozenset([1, 39, 40])
    FOLLOW_exp3_in_exp2318 = frozenset([1, 41, 42, 43, 44, 45, 46])
    FOLLOW_41_in_exp2322 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_42_in_exp2327 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_43_in_exp2332 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_44_in_exp2337 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_45_in_exp2342 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_46_in_exp2347 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp3_in_exp2351 = frozenset([1, 41, 42, 43, 44, 45, 46])
    FOLLOW_exp4_in_exp3360 = frozenset([1, 47, 48])
    FOLLOW_47_in_exp3364 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_48_in_exp3369 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp4_in_exp3373 = frozenset([1, 47, 48])
    FOLLOW_atom_in_exp4382 = frozenset([1, 49, 50, 51, 52, 53])
    FOLLOW_49_in_exp4386 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_50_in_exp4391 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_51_in_exp4396 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_52_in_exp4401 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_53_in_exp4406 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_atom_in_exp4410 = frozenset([1, 49, 50, 51, 52, 53])
    FOLLOW_54_in_atom419 = frozenset([1])
    FOLLOW_55_in_atom423 = frozenset([1])
    FOLLOW_56_in_atom427 = frozenset([1])
    FOLLOW_string_in_atom431 = frozenset([1])
    FOLLOW_number_in_atom435 = frozenset([1])
    FOLLOW_57_in_atom439 = frozenset([1])
    FOLLOW_function_in_atom443 = frozenset([1])
    FOLLOW_prefixexp_in_atom447 = frozenset([1])
    FOLLOW_tableconstructor_in_atom451 = frozenset([1])
    FOLLOW_58_in_atom455 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_atom458 = frozenset([59])
    FOLLOW_59_in_atom460 = frozenset([1])
    FOLLOW_NAME_in_prefixexp468 = frozenset([1, 9, 10, 11, 37, 58, 62])
    FOLLOW_nameAndArgs_in_prefixexp470 = frozenset([1, 9, 10, 11, 37, 58, 62])
    FOLLOW_NAME_in_functioncall478 = frozenset([9, 10, 11, 37, 58, 62])
    FOLLOW_nameAndArgs_in_functioncall480 = frozenset([1, 9, 10, 11, 37, 58, 62])
    FOLLOW_37_in_nameAndArgs489 = frozenset([4])
    FOLLOW_NAME_in_nameAndArgs491 = frozenset([9, 10, 11, 37, 58, 62])
    FOLLOW_args_in_nameAndArgs495 = frozenset([1])
    FOLLOW_nameAndArgs_in_varSuffix502 = frozenset([9, 10, 11, 36, 37, 58, 60, 62])
    FOLLOW_60_in_varSuffix506 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_varSuffix508 = frozenset([61])
    FOLLOW_61_in_varSuffix510 = frozenset([1])
    FOLLOW_36_in_varSuffix514 = frozenset([4])
    FOLLOW_NAME_in_varSuffix516 = frozenset([1])
    FOLLOW_58_in_args526 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 59, 62, 64, 65])
    FOLLOW_explist1_in_args529 = frozenset([59])
    FOLLOW_59_in_args533 = frozenset([1])
    FOLLOW_tableconstructor_in_args537 = frozenset([1])
    FOLLOW_string_in_args541 = frozenset([1])
    FOLLOW_30_in_function550 = frozenset([4, 58])
    FOLLOW_funcbody_in_function552 = frozenset([1])
    FOLLOW_58_in_funcbody560 = frozenset([4, 21, 23, 24, 28, 30, 31, 38, 57, 59])
    FOLLOW_parlist1_in_funcbody563 = frozenset([59])
    FOLLOW_59_in_funcbody567 = frozenset([4, 20, 21, 23, 24, 28, 30, 31, 33, 34, 35])
    FOLLOW_block_in_funcbody569 = frozenset([22])
    FOLLOW_22_in_funcbody571 = frozenset([1])
    FOLLOW_namelist_in_parlist1579 = frozenset([1, 38])
    FOLLOW_38_in_parlist1582 = frozenset([57])
    FOLLOW_57_in_parlist1584 = frozenset([1])
    FOLLOW_57_in_parlist1590 = frozenset([1])
    FOLLOW_62_in_tableconstructor598 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 60, 62, 63, 64, 65])
    FOLLOW_fieldlist_in_tableconstructor601 = frozenset([63])
    FOLLOW_63_in_tableconstructor605 = frozenset([1])
    FOLLOW_field_in_fieldlist613 = frozenset([1, 20, 38])
    FOLLOW_fieldsep_in_fieldlist616 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 60, 62, 64, 65])
    FOLLOW_field_in_fieldlist618 = frozenset([1, 20, 38])
    FOLLOW_fieldsep_in_fieldlist623 = frozenset([1])
    FOLLOW_60_in_field633 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_field635 = frozenset([61])
    FOLLOW_61_in_field637 = frozenset([32])
    FOLLOW_32_in_field639 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_field641 = frozenset([1])
    FOLLOW_NAME_in_field645 = frozenset([32])
    FOLLOW_32_in_field647 = frozenset([4, 5, 6, 7, 8, 9, 10, 11, 30, 48, 54, 55, 56, 57, 58, 62, 64, 65])
    FOLLOW_exp_in_field649 = frozenset([1])
    FOLLOW_exp_in_field653 = frozenset([1])
    FOLLOW_set_in_fieldsep0 = frozenset([1])
    FOLLOW_set_in_unop0 = frozenset([1])
    FOLLOW_set_in_number0 = frozenset([1])
    FOLLOW_set_in_string0 = frozenset([1])



def main(argv, stdin=sys.stdin, stdout=sys.stdout, stderr=sys.stderr):
    from antlr3.main import ParserMain
    main = ParserMain("LuaLexer", LuaParser)
    main.stdin = stdin
    main.stdout = stdout
    main.stderr = stderr
    main.execute(argv)


if __name__ == '__main__':
    main(sys.argv)
