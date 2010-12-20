# -*- coding: latin-1 -*-
from gui.AplicacaoPrincipal import ConstrutorAplicacaoPrincipal
from gui import construtor_gui

def main():
  app = ConstrutorAplicacaoPrincipal().obterAplicacaoPrincipal()
  construtor_gui.construir_gui(app)
  app.MainLoop()
  
if __name__ == "__main__":
    main()