from Eval import Eval
import re

class Translator(Eval):
    def __init__(self, nodes):
        Eval.__init__(self, nodes)
        self.dados = []
        self.codigo = [".function"]
        self.label = 0
        self.parametros = [] 
        self.while_cond = "off"
        self.and_cond = "on"
        self.or_cond = "off"
        self.swhile = -1
        # key = linha que se encontra // value = linhas a pular
        self.tabela_jmp_and = {} #a tabela and ve se eh falso e pula pro fim
        self.tabela_jmp_or = {} #a tabela or ve se eh verdade e pula pro bloco
        self.tabela_jmp = {}
        self.tabela_jmp_while = {}

    def atualizar_tabsim(self, vezes):
        print self.tabela_jmp_and
        print self.tabela_jmp_or
        print self.tabela_jmp_while
        #if self.or_cond == "on":
        #    self.atualizar_tab_or(vezes)
        #if self.and_cond == "on":
        #    self.atualizar_tab_and(vezes)
        self.atualizar_tab_jmp(vezes)
        if self.while_cond == "on":
            print "ATUALIZANDO"
            self.atualizar_tab_while(vezes)

    def atualizar_tab_jmp(self, vezes):
        for linha in self.tabela_jmp.keys():
            self.tabela_jmp[linha] += vezes

    def atualizar_tab_while(self, vezes):
        for linha in self.tabela_jmp_while.keys():
            self.tabela_jmp_while[linha] += vezes

    def atualizar_tab_and(self, vezes):
        for linha in self.tabela_jmp_and.keys():
            self.tabela_jmp_and[linha] += vezes

    def atualizar_tab_or(self, vezes):
        for linha in self.tabela_jmp_or.keys():
            self.tabela_jmp_or[linha] += vezes

    def handle(self):
        '''
        ultima funcao chamada, entao manda escrever tudo no arquivo
        '''
        self.codigo.append("return 0 0")
        self.codigo.append(".end")
        self.escrever()

    def handle_declaracao(self, namelist):
        if self.retornar_posicao(namelist) < 0:
            self.codigo.append("setglobal 0, \"" + str(namelist) + "\"")
            self.dados.append(str(namelist.getText()))
            self.atualizar_tabsim(1)
            print "declarao + 1"

    def handle_and(self):
        self.and_cond = "on"

    def handle_or(self):
        self.cond_or = "on"
        
   
    def handle_aritmetica(self, a, b, op):

        comando = op + " 0 "

        #se a ou b forem um operador, nao podemos carregar as variaveis em 0, por risco de perder o valor da ultima operacao
        if a.getType() is not 4 or b.getType() is not 4 or a.getType() is not 5 or a.getType() is not 5:
             reg = 1
        else:
             reg = 0
        r = 0
        if a.getType() == 4: #caso seja uma variavel, devemos busca-la
            self.codigo.append("getglobal " + str(reg) + " \"" + str(a.getText()) + "\"")
            self.atualizar_tabsim(1)
            print "cond + 1"
            comando = comando + str(reg) + " "
            reg += 1
        elif a.getType() == 5: #inteiro
            comando = comando + " #" + str(a.getText()) + " "
        else: #outro operador...e agora, onde esta o valor anterior? assumimos que em 0 ainda
            comando = comando + " " + str(r)
            r = 1

        if b.getType() == 4: #caso seja uma variavel, devemos busca-la
            self.codigo.append("getglobal " + str(reg) + " \"" +  str(b.getText()) + "\"")
            print "cond + 1"
            self.atualizar_tabsim(1)
            comando = comando + str(reg) 
        elif b.getType() == 5: #inteiro
            comando = comando + " #" + str(b.getText())
        else: #outro operador...e agora, onde esta o valor anterior? assumimos que em 0 ou 1
            comando = comando + " " + str(r)

        self.atualizar_tabsim(1)
        print "cond + 1"
        self.codigo.append(comando)

    def handle_associar(self, var):

        #caso seja um parametros, apenas buscamos direto
        if var in self.parametros: return

        self.dados.append(var)

        if type(var) == int:
            self.codigo.append("move 0 " + str(var) + "")
        elif var.getType() == 4:
            self.codigo.append("loadk 0 \"" + str(var.getText()) + "\"")
        elif var.getType() == 9:
            self.codigo.append("loadk 0 " + str(var.getText()) )
        else:
            self.codigo.append("loadk 0 #" + str(var.getText()))
        self.atualizar_tabsim(1)
        print "associar + 1"

    def retornar_posicao(self, simbolo):
        '''
        retorna em qual posicao da lista o simbolo se encontra
        para saber se ele ja foi declarado
        '''
        posicao = len(self.dados)-1 #comeca de tras para frente para pegar o valor mais atualizado
        for i in self.dados:
           if i == simbolo:
               return posicao
           posicao -= 1
        return -1

    def handle_return(self):
        self.codigo.append("return1 0 0 ")

    def handle_functioncall(self, nome):
        self.codigo.append("getglobal 0 \"" + str(nome.getText()) + "\"")
        self.atualizar_tabsim(1)
        print "functioncall + 1"

    def handle_call(self):
        self.codigo.append("call 0 0 1")
        self.atualizar_tabsim(1)
        print "call + 1"

    def handle_function_arg(self, args):
        filhos = args.getChildren()

        #significa que so tem um argumento, o proprio args
	if len(filhos) == 0:
            filhos = [args]

        indice = 1
        for filho in filhos:

            if str(filho.getText()) != "," and str(filho.getText()) not in self.parametros:

                #verifica se eh um valor ja declarado, se for, so pega
                pos = self.retornar_posicao(filho.getText())
                if pos >= 0:
                    self.codigo.append("getglobal "+str(indice)+" \"" + str(filho.getText()) + "\"" )
                else:
                    self.codigo.append("loadk "+str(indice)+" " + str(filho.getText()) )
                indice += 1
                self.atualizar_tabsim(1)
                print "function args + 1"
      

    def handle_end_and(self):

        #agora temos que resolver tudo que estava na tabela de simbolos
        for linha in self.tabela_jmp.keys():
            self.codigo[linha] = "jmp #" + str(self.tabela_jmp.get(linha))
        self.tabela_jmp.clear()
        print "deu clear A"
        self.and_cond = "on"

    def handle_end_or(self):
        if self.or_cond == "off": return

        #agora temos que resolver tudo que estava na tabela de simbolos
        for linha in self.tabela_jmp.keys():
            self.codigo[linha] = "jmp #" + str(self.tabela_jmp.get(linha))
        self.tabela_jmp.clear()
        print "deu clear B"
        self.or_cond = "off"

    def handle_exp_comp(self, a, b, op, vl):
        '''
        por default o vl vem setado como se nao tivesse outras condicoes para testar
        senao cai em um dos dois casos abaixo:
        PARA LEMBRAR:
        and: se a primeira cond nao satisfaz, ja pula pro fim, senao vai pra proxima
        or: se a primeira cond nao satisfaz, vai para a proxima, senao vai pro bloco
        '''

        reg = 0
        if self.or_cond == "on":
            vl = int(not vl) #inverte o valor
        
        comando = op + " " + str(vl) + " " #se for falso executa a linha debaixo, senao pula a proxima linha
        if a.getType() == 4: #NAME
            self.codigo.append("getglobal " + str(reg) + " \"" + str(a.getText()) + "\"")
            comando = comando + str(reg) + " "
            reg += 1
        elif a.getType() == 9: #NORMALSTRING 
             comando = comando + " " + a.getText() + ""
        else: #INT
             comando = comando + " #" + a.getText()

        if b.getType() == 4: #NAME
            self.codigo.append("getglobal " + str(reg) + " \"" + str(a.getText()) + "\"")
            comando = comando + str(reg) + " "
            reg += 1
        elif b.getType() == 9: #NORMALSTRING 
             comando = comando + " " + b.getText() + ""
        else: #INT
             comando = comando + " #" + b.getText()

        self.codigo.append(str(comando))
        self.atualizar_tabsim(reg + 2) 
        print "cond + 2 + ", str(reg)  
        self.swhile += reg + 2
        #if self.or_cond == "on":
        self.tabela_jmp[len(self.codigo)] = 0
    
        print "criou  cond", self.tabela_jmp
        if self.while_cond == "on":
            self.tabela_jmp_while[len(self.codigo)] = 0
        
        self.codigo.append("") #linha vazia que sera preenchida pelo jump depois que resolvermos a tabela de simbolos

    def escrever(self):
        arq = open("/home/patricia/svn/CompiladorLua/docs/executar.asm","w")
        for i in self.codigo:
            arq.write(i + "\n")


    def handle_while(self):
        #esperamos que depois disso venha uma exp, devemos contar qnts linhas de expressao tem
        #para transferi-las para o fim do while
        self.swhile = -1
        self.linha_while = len(self.codigo)
        self.while_cond = "on"
        print"ON!!!!!"
  
    def handle_start_while(self):

        #devemos contar quantas linhas tem o bloco, para sabermos para onde devemos pular
        self.tabela_jmp_while[len(self.codigo)] = 0
        self.codigo.append("")

    def handle_end_while(self):
       self.cond_while = "off"

       #passa a condicao para o final do bloco
       trecho = self.codigo[self.linha_while:(self.linha_while + self.swhile)]
       del self.codigo[self.linha_while:(self.linha_while + self.swhile)]

       for i in trecho: self.codigo.append(str(i))

       m = min(self.tabela_jmp_while.keys())
       pulo = 3 + self.tabela_jmp_while[m]
       self.codigo.append("jmp #-" + str(pulo))

       #atualiza o jmp 
       for linha in self.tabela_jmp_while.keys():
           self.codigo[linha - self.swhile] = "jmp #" + str(self.tabela_jmp_while[linha])
       self.tabela_jmp_while.clear()

    def handle_parametros(self, parametros):
        ind = 2
        pars = parametros.getChildren()
        if len(pars) == 0:
            pars = [parametros]
        reg = 0
        self.parametros = []
        for par in pars:
            self.parametros.append(str(par.getText()))
            self.codigo.append("move " + str(ind) + " " + str(reg))
            reg += 1

    def handle_function(self, nome):
        self.codigo.append(str(nome) + " .function")
        self.nome = nome
    
    def handle_end_function(self):
        self.codigo.append(".end")
        self.codigo.append("closure    0 " + str(self.nome) )
        self.codigo.append("setglobal  0 \"" + str(self.nome) + "\"")
        print self.codigo
 
    def handle_end_all(self):
        self.or_cond = "off"
            


    def handle_end_andor(self):
        self.handle_end_and()
        self.handle_end_or()
