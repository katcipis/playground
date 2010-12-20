(defstruct produto
    nome preco 
)

(defun obter_produtos (&rest produtos)
  (prog (prod nome_prod preco_prod prods))
  (setq prods (make-list (list-length produtos)))  
  (defvar lista_produtos prods)

  (loop

  (setq nome_prod (car produtos))
  (setq produtos (cdr produtos))
  
  (setq preco_prod (car produtos)) 
  (setq produtos (cdr produtos))
 
  (setq prod (make-produto :nome nome_prod :preco preco_prod))
  (push prod prods)
  
  (when (null (car produtos)) (return (setq lista_produtos prods)))

  )
)


(defun pesquisar_produto (nome_prod)
  (prog (copia_prods tmp_prod))
  (setq copia_prods lista_produtos)

  (loop
  (setq tmp_prod (car copia_prods))
  (setq copia_prods (cdr copia_prods))
  
  (if (equal (produto-nome tmp_prod) nome_prod) (return tmp_prod ) )  
  
  (when (null (car copia_prods)) (return "Produto nao encontrado"))

  )
)

(defun listar_produtos ()
  (prog (prod lista_aux))
                    
  (setq lista_aux (copy-list lista_produtos))
  
  (loop
  
  (setq prod (car lista_aux))
  (print (concatenate 'string "Produto: " (produto-nome prod)))
  (print (concatenate 'string "Preco: " ( write-to-string (produto-preco prod) ) ))
  (pop lista_aux)
    
  (when (null (car lista_aux) ) (return  "Acabaram os produtos" ) ) )
)

(defun imprimir_compras ()
  (prog (compras_aux total prod_aux))
  (setq compras_aux (copy-list compras))
  (setq total 0)
  (loop
    (setq prod_aux (pop compras_aux))
    (setq total (+ total (produto-preco prod_aux)))
    (print (concatenate 'string "Produto: " (produto-nome prod_aux) ))
    (print (concatenate 'string "Total Parcial: " (write-to-string total) ))
    (when (null (car compras_aux))  (return (print (concatenate 'string "Total: " ( write-to-string total ))))))

)

(defun fazer_compras ()
  
  (prog (escolhido produto_achado))
 
  (print "digite o produto que voce deseja")
  (setq escolhido (read))
  
  (if (equal escolhido "fim") (imprimir_compras)
  
    (progn
    
  ( setq produto_achado (pesquisar_produto escolhido ) )
  
  (if (null produto_achado) 
    
    (progn (print "Produto nao encontrado") (fazer_compras))
    
    (progn (push produto_achado compras) (fazer_compras))
    
    )
   )
  )
 )

(defun montar_menu ()
 (print "Escolha uma das opcoes abaixo digitando seu numero e apertando enter") 
 (prog (escolha))
  
 (print "1 - Pesquisar preco do produto")
 (print "2 - Listar produtos")
 (print "3 - Fazer compras")
 
 (setq escolha (read))
   
 (when (equal escolha 1) 
  (print "Agora digite o nome do produto que deseja pesquisar")
   (pesquisar_produto (write-to-string (read)) )
  )
  
  (when (equal escolha 2) 
  (print "Listando produtos")
   (listar_produtos)
  )
  
  (when (equal escolha 3) 
  (print "Faca suas compras")
    (defvar compras (make-list 10))
   (fazer_compras)
  )
  
  nil
  
 )

