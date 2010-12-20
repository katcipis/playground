(defstruct Produto
    nome preco 
)

<<<<<<< MERCEARIA >>>>>>

(defclass Mercearia () 
  (
    (estoque 
             :accessor obter_estoque
             :initform (criar_estoque)
             :initarg :estoque
    )
   
  )
)

(defun criar_mercearia (estoque)
   (make-instance 'Mercearia :estoque estoque)
)

(defmethod busca_prod ((merc Mercearia) nome)
  (prog (produtos))
  (setq produtos (obter_produtos (obter_estoque merc)) )
  
  (loop
    
    (if (equal (produto-nome (car produtos)) nome)
        (return (car produtos))
      )
    
    (setq produtos (cdr produtos))
    (when (null (car produtos)) (return nil))
  )
)

(defmethod imprimir_estoque ( (merc Mercearia) )
  
  (prog (estoque produtos descanso))
  (setq descanso 1)
  (setq estoque (obter_estoque merc))
  (setq produtos (copy-list (ordenar estoque)))
  
  (loop
    
    (if (= descanso 20) 
     (progn
      (print "Digite algo e pressione enter para continuar")
      (read)
      (setq descanso 1)
       ) 
     )
    
    (print (car produtos))
    (setq produtos (cdr produtos))
    (setq descanso (+ descanso 1))
    
    (when (null (car produtos)) (return) )
   )
  
 )

<<<<<<< ESTOQUE >>>>>>

(defclass Estoque () 
  ( 
    (produtos 
             :accessor obter_produtos
             :initform (make-list 10)
             :initarg :produtos
    )
  )
)

(defun criar_estoque ()
   (make-instance 'Estoque)
)

(defmethod inserir ((e Estoque) (p Produto))
     (push p (obter_produtos e))
)

(defun inserir_produtos (estoque &rest produtos)
  (prog (prod nome_prod preco_prod))
     
  (loop

  (setq nome_prod (car produtos))
  (setq produtos (cdr produtos))
  
  (setq preco_prod (car produtos)) 
  (setq produtos (cdr produtos))
 
  (setq prod (make-produto :nome nome_prod :preco preco_prod))
  (push prod (obter_produtos estoque))
  
  (when (null (car produtos)) (return estoque))

  )
  
)

(defmethod ordenar ((e Estoque))
  (prog (produtos maior maiorprod indice indiceb))
  
  (setq produtos (obter_produtos e))
  (setq indice (- (list-length produtos) 1))
  
  (loop
    
    (setq maior 0 )
    (setq indiceb 0)
    
    (loop
   
    (if (not(equal nil (nth indiceb produtos)) )
      (progn
        (if (string< (Produto-nome (nth maior produtos)) 
              (Produto-nome (nth indiceb produtos)))
        (setq maior indiceb)
       )
     )
    )
      
    (setq indiceb (+ indiceb 1))
    (when (> indiceb indice) (return) )
      
   )
    
    (if (not(equal nil (nth indice produtos)) )
      
      (progn
      (setq maiorprod (nth maior produtos))
      (setf (nth maior produtos) (nth indice produtos) )
      (setf (nth indice produtos) maiorprod )
      )

    )    
    
    (setq indice (- indice 1))
    (when (= 0 indice) (return produtos))
  )
  
)
<<<<<<<<<<<<< LISTA DE COMPRAS >>>>>>>>>>>>>

(defclass ListaDeCompras () 
  ( 
    (compras 
             :accessor obter_compras
             :initform (make-list 10)
             :initarg :compras
    )
    
    (mercearia 
             :accessor obter_mercearia
             :initarg :mercearia
    )
  )
)

(defun criar_lista_de_compras (mercearia)
   (make-instance 'ListaDeCompras :mercearia mercearia)
)

(defmethod termina_compras ((lista ListaDeCompras))
  (prog (compras total))
  (setq compras (copy-list(obter_compras lista)))
  (setq total 0)
  (print "Voce comprou os seguintes produtos")
  
  (loop
    (setq total (+ total (Produto-preco (car compras)) ))
    (print (Produto-nome (car compras)))
    (setq compras (cdr compras))
    (when (null(car compras)) (return) )
    )
  
  (print (concatenate 'string "Total: " (write-to-string total)))
 )

(defmethod comprar ((lista ListaDeCompras) nome_prod)
  (prog (merc prod_achado compras total))
  (setq merc (obter_mercearia lista))
  
  (setq prod_achado (busca_prod merc nome_prod))
  
  (if (not(null prod_achado)) 
   (push prod_achado (obter_compras lista)) 
    (print "Produto nao achado")
   )
  
  (setq compras (copy-list(obter_compras lista)))
  (setq total 0)
  (print "Ate agora voce comprou os seguintes produtos")
  
  (loop
    (setq total (+ total (Produto-preco (car compras)) ))
    (print (Produto-nome (car compras)))
    (setq compras (cdr compras))
    (when (null(car compras)) (return) )
    )
  
  (print (concatenate 'string "Total Parcial: " (write-to-string total)))
 )

<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>

(defun iniciar_menu (mercearia lista_de_compras)
  
  (print "Escolha uma das opcoes abaixo digitando seu numero e apertando enter") 
 (prog (escolha))
  
 (print "1 - Pesquisar preco do produto")
 (print "2 - Listar produtos")
 (print "3 - Fazer compras")
 
 (setq escolha (read))
   
 (when (equal escolha 1) 
  (print "Agora digite o nome do produto que deseja pesquisar")
   (busca_prod mercearia (write-to-string (read)) )
  )
  
  (when (equal escolha 2) 
  (print "Listando produtos")
   (imprimir_estoque mercearia)
  )
  
  (when (equal escolha 3) 
  (print "Faca suas compras")
  (fazer_compras lista_de_compras)
  )
  
  nil
  
 )

(defun fazer_compras (lista)
  (prog (produto))
  (print "Digite o nome do produto que deseja comprar ou fim para encerrar compras")
  ( setq produto (write-to-string (read)) )
  
  (if (string= produto "fim") 
    (prog
    (print "Segue a lista dos produtos comprados e o total das compras")
    (termina_compras lista)
    )
   
    (prog
    (comprar lista produto)
    (fazer_compras lista)
    ) 
  )
  
 )

<<<<<<<<<<<<< TESTE >>>>>>>>>>>>>

(defun teste ()
  
  (prog (estoque mercearia))
  (setq estoque (criar_estoque))
  
  (inserir estoque (make-Produto :nome "Pao" :preco 1))
  (inserir estoque (make-Produto :nome "Agua" :preco 1))
  (inserir estoque (make-Produto :nome "Coca" :preco 3))
  (inserir estoque (make-Produto :nome "Sucrilhos" :preco 5))
  (inserir estoque (make-Produto :nome "Nescau" :preco 4))
  (inserir estoque (make-Produto :nome "Farinha" :preco 2))
  (inserir estoque (make-Produto :nome "Milho" :preco 2))
  (inserir estoque (make-Produto :nome "Picanha" :preco 15))
  
  (setq mercearia (criar_mercearia estoque))
  
  (print "Testando busca")
  (print (busca_prod mercearia "Pao"))
  (print (busca_prod mercearia "Sucrilhos"))
  (print (busca_prod mercearia "Coco"))
  
  (print "Testando Impressao de Estoque")
  (imprimir_estoque mercearia)
  
  (print "Testando Compras")
  (setq lista_de_compras (criar_lista_de_compras mercearia))
  (comprar lista_de_compras "Pao")
  (comprar lista_de_compras "Nescau")
  (comprar lista_de_compras "Farinha")
  (comprar lista_de_compras "Coconuts")
  (comprar lista_de_compras "Picanha")
  (comprar lista_de_compras "Abacate")
  
  (print "Testando Terminando Compras")
  (termina_compras lista_de_compras)
  (print "Iniciando programa")
  (iniciar_menu mercearia (criar_lista_de_compras mercearia))
 )
