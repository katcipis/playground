<<<<<<<<<<<<<<CIDADE>>>>>>>>>>>>>>

(defclass Cidade ()
  (
    (nome 
             :accessor obter_nome
             :initform nil
             :initarg :nome
    )
    
    (arestas 
             :accessor obter_arestas
             :initform (make-list 2)
             :initarg :arestas
    )
    
    (hospital 
             :accessor obter_hospital
             :initform nil
             :initarg :hospital
    )
    
   )
)

(defun criar_cidade_hosp (nome arestas hospital)
   (make-instance 'Cidade :nome nome :arestas arestas :hospital hospital)
)

(defun criar_cidade_aresta (nome arestas)
   (make-instance 'Cidade :nome nome :arestas arestas)
)

(defun criar_cidade (nome)
   (make-instance 'Cidade :nome nome)
)

<<<<<<<<<<<<<<ARESTA>>>>>>>>>>>>>>

(defclass Aresta ()
  (
    (cidade 
             :accessor obter_cidade
             :initarg :cidade
    )
    
    (custo 
             :accessor obter_custo
             :initarg :custo
    )
    
   )
)

(defun criar_aresta (cidade custo)
   (make-instance 'Aresta :cidade cidade :custo custo)
)

<<<<<<<<<<<<<<HOSPITAL>>>>>>>>>>>>>>

(defstruct Leito
   numero ocupado
 )

(defclass Hospital ()
  (
    (ambulancias 
             :accessor obter_ambulancias
             :initform nil
             :initarg :ambulancias
    )
    
    (leitos 
             :accessor obter_leitos
             :initform (make-list 5)
             :initarg :leitos
    )
    
    (cidade 
             :accessor obter_cidade
             :initform nil
             :initarg :cidade
    )
    
   )
)

(defmethod leito_livre ((hosp Hospital))
  (prog (leitos possui))
  
  (setq leitos (obter_leitos hosp))
  (setq possui nil)
  
  (loop
  (if (not(Leito-ocupado(car leitos))) 
    (setq possui t)
  )
  (pop leitos)
  (when (null(car leitos)) (return))  
  )
  
  t
)

(defun criar_hospital_amb (qtdade_leitos qtdade_ambulancias local)
  (prog (leitos ambulancias))
  
  (setq leitos (make-list qtdade_leitos))
  (setq ambulancias (make-list qtdade_ambulancias))
  
  (loop
    (push (make-Leito :numero qtdade_leitos :ocupado nil) leitos)
    (setq qtdade_leitos (- qtdade_leitos 1))
    (when (= qtdade_leitos 0) (return))
  )
  
  (loop
    (push (criar_ambulancia qtdade_ambulancias local) ambulancias)
    (setq qtdade_ambulancias (- qtdade_ambulancias 1))
    (when (= qtdade_ambulancias 0) (return))
  )
  
  (make-instance 'Hospital :ambulancias ambulancias :leitos leitos :cidade local)
)

(defun criar_hospital (qtdade_leitos local)
  (prog (leitos))
  
  (setq leitos (make-list qtdade_leitos))
  
  (loop
    (push (make-Leito :numero qtdade_leitos :ocupado nil) leitos)
    (setq qtdade_leitos (- qtdade_leitos 1))
    (when (= qtdade_leitos 0) (return))
  )
  
  (make-instance 'Hospital :leitos leitos :cidade local)
)

<<<<<<<<<<<<<<AMBULANCIA>>>>>>>>>>>>>>

(defclass Ambulancia ()
  (
    (numero 
             :accessor obter_numero
             :initarg :numero
    )
    
    (status 
             :accessor obter_status
             :initform hosp_origem
             :initarg :status
    )
    
    (local 
             :accessor obter_local
             :initarg :local
    )
    
    (origem 
             :accessor obter_origem
             :initarg :origem
    )
    
   )
)

(defun criar_ambulancia (numero local)  
   (make-instance 'Ambulancia :numero numero :local local :origem local)
)

(defmethod esta_livre ((ambulancia Ambulancia))

   (or (eq (obter_status ambulancia) hosp_origem) 
       (eq (obter_status ambulancia) tran_retrem_paciente)
   )
    
)

(defun iniciar_status_ambulancias ()
 (defconstant hosp_origem "No hospital de origem") 
 (defconstant tran_retrem_paciente "Em transito e retornando de remocao de paciente") 
 (defconstant tran_trans_paciente "Em transito e transportando paciente") 
 (defconstant tran_atentendo "Em transito atendendo chamado")
 )

<<<<<<<<<<<<<<<<<<<<<<<<<<<FUNCOES>>>>>>>>>>>>>>>>>>>>>>>>>>

(defstruct dijkstra
   vertice estimativa precedente fechado
 )

(defun ocorrencia (cidade)
  (prog (checados vertices indice melhorhosp))
  (defvar hosp_livres)
  (defvar amb_livres)
  
  (setf amb_livres (make-list 1))
  (setf hosp_livres (make-list 1))
  
  (setq checados (make-list 1))
  
  (obter_hosp_livres cidade checados)
  (setq checados (make-list 1))
  (obter_amb_livres cidade checados)
  
  (setq caminho (calcular_caminho_min cidade))
  (setq indice 0)
  (setq melhorhosp nil)
  
  (loop
    (if (null melhorhosp)
       (progn 
         (if (/= (dijkstra-estimativa (nth indice caminho)) 0) 
           (setq melhorhosp indice)
          )
        )
      
        (progn
          (if (< (dijkstra-estimativa (nth indice caminho)) (dijkstra-estimativa (nth melhorhosp caminho)))
             (if (/= (dijkstra-estimativa (nth indice caminho)) 0) 
               (setq melhorhosp indice)
              )
          ) 
       )
     )
    
   (setq indice (+  indice 1))
   (when (null (nth indice caminho) ) (return nil))
    
   )
  
  (nth melhorhosp caminho)
  
 )

(defun obter_dijkstra (cidade dijkstras)
  (prog (indice retorno))
  (setq indice 0)
  (setq retorno nil)
  
  (loop
    
   (if (equal cidade (dijkstra-vertice (nth indice dijkstras)) )
       (setq retorno (nth indice dijkstras))
   ) 
    
   (setq indice (+  1))
   (when (null (nth indice dijkstras) ) (return retorno))
    
   )
  
 )

(defun calcular_caminho_min (cidade)
  (prog (vertices vtmp custoadjacentetmp totaltmp indice))
  
  (setq vertices (criar_lista_dijkstra cidade))
  
  (loop
   (setq vtmp (obter_melhor_vertice_aberto vertices))
   (setf (dijkstra-fechado vtmp) t)
   (setq indice 0)
    
    (loop
      
     (if ( null (dijkstra-fechado (nth indice vertices)) )
       (progn
           (setq custoadjacentetmp (sao_adjacentes (dijkstra-vertice vtmp) (dijkstra-vertice (nth indice vertices))))
           (if (not( null custoadjacentetmp ))
              (progn
                 (setq totaltmp (+ (dijkstra-estimativa vtmp) custoadjacentetmp))
                    (if (< totaltmp (dijkstra-estimativa (nth indice vertices)))
                      (progn
                        (setf (dijkstra-estimativa (nth indice vertices)) totaltmp) 
                        (setf (dijkstra-precedente (nth indice vertices)) (dijkstra-vertice vtmp))
                      )
                    )
               )
            )
         )
     )
       
     (setq indice (+ indice 1))
     (when (null (nth indice vertices)) (return nil))
    )
    
   (when (estao_fechados vertices) (return vertices)) 
   )
  
 )

(defun sao_adjacentes (vertice_um vertice_dois)
  (prog (tmp retorno)) 
   
  (setq tmp 0)
  (setq retorno nil)
  
  (loop
    
   (if (equal (obter_cidade(nth tmp (obter_arestas vertice_um))) vertice_dois )
       (setq retorno (obter_custo(nth tmp (obter_arestas vertice_um))) )
   ) 
    
   (setq tmp (+ tmp 1))
   (when (null (nth tmp (obter_arestas vertice_um)) ) (return retorno))
    
   )
 )

(defun obter_melhor_vertice_aberto (vertices)
  (prog (tmp retorno))
  (setq tmp 0)
  (setq retorno nil)
  (loop
    
    (if ( null (dijkstra-fechado (nth tmp vertices)) )
       (progn
          (if (null retorno)
              (progn
                (setq retorno (nth tmp vertices))
              )
             
              (progn 
                 (if (> (dijkstra-estimativa retorno) (dijkstra-estimativa (nth tmp vertices)) )
                    (setq retorno (nth tmp vertices))
                 )  
              )
           ) 
       )
    )
   
    
   (setq tmp (+ tmp 1))
   (when (null (nth tmp vertices) ) (return retorno))
    
   )
  
 )

(defun criar_lista_dijkstra (cidade)
  (prog (lista tmp))
  (setq lista (make-list 10))
  
  (push (make-dijkstra :vertice cidade_um :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_dois :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_tres :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_quatro :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_cinco :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_seis :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_sete :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_oito :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_nove :estimativa infinito :precedente nil :fechado nil) lista)
  (push (make-dijkstra :vertice cidade_dez :estimativa infinito :precedente nil :fechado nil) lista)
  
  (setq tmp 0)
  (loop
    
   (if (equal cidade  (dijkstra-vertice (nth tmp lista) ) )
       (setf (dijkstra-estimativa (nth tmp lista)) 0)
       (setf (dijkstra-precedente (nth tmp lista)) (dijkstra-vertice (nth tmp lista)))
   ) 
    
   (setq tmp (+ tmp 1))
   (when (null (nth tmp lista)) (return lista))
    
   )
  )

(defun estao_fechados (lista_dijkstra)
  (prog (tmp retorno)) 
   
  (setq tmp 0)
  (setq retorno t)
  
  (loop
    
   (if ( null (dijkstra-fechado (nth tmp lista)) )
       (setq retorno nil)
   ) 
    
   (setq tmp (+ tmp 1))
   (when (null (nth tmp lista)) (return retorno))
    
   )
  
)

(defun obter_hosp_livres (cidade checados)
  (prog (arestas))
  (if (not(member cidade checados))
    
    (progn
  
      (push cidade checados)
      (setq arestas (copy-list (obter_arestas cidade)) )
      
      (if (obter_hospital cidade)
        (progn
          (if (leito_livre (obter_hospital cidade))
            (progn 
              (push (obter_hospital cidade) hosp_livres)
              )
           )
        )
      )
      
      (loop
      (obter_hosp_livres (obter_cidade (car arestas)) checados)
      (pop arestas)
      (when (null(car arestas)) (return))
      )
      
     ) 
    
  )
  
)

(defun obter_amb_livres (cidade checados)
  (prog (arestas tmp_ambs))
  (if (not(member cidade checados))
    
    (progn
  
      (push cidade checados)
      (setq arestas (copy-list (obter_arestas cidade)) )
      
      (if (obter_hospital cidade)
        (progn
          (if (obter_ambulancias (obter_hospital cidade))
            (progn 
              (setq tmp_ambs (copy-list (obter_ambulancias (obter_hospital cidade))))
                (loop
                   ( if (esta_livre (car tmp_ambs))
                     (push (car tmp_ambs) amb_livres)
                   )
                  
                (pop tmp_ambs)
                (when (null(car tmp_ambs)) (return))
                )
              )
           )
        )
      )
      
      (loop
      (obter_amb_livres (obter_cidade (car arestas)) checados)
      (pop arestas)
      (when (null(car arestas)) (return))
      )
      
     ) 
    
  )
  
)


<<<<<<<<<<<<<<<<<<<<<<<<<<<PROGRAMA>>>>>>>>>>>>>>>>>>>>>>>>>>

(defun iniciar()
  (iniciar_status_ambulancias)
  
  (defconstant cidade_um (criar_cidade "Cidade01"))
  (defconstant cidade_dois (criar_cidade "Cidade02"))
  (defconstant cidade_tres (criar_cidade "Cidade03"))
  (defconstant cidade_quatro (criar_cidade "Cidade04"))
  (defconstant cidade_cinco (criar_cidade "Cidade05"))
  (defconstant cidade_seis (criar_cidade "Cidade06"))
  (defconstant cidade_sete (criar_cidade "Cidade07"))
  (defconstant cidade_oito (criar_cidade "Cidade08"))
  (defconstant cidade_nove (criar_cidade "Cidade09"))
  (defconstant cidade_dez (criar_cidade "Cidade10"))
  (defconstant infinito 9999999)
  
  (iniciar_hospitais)
  
  (conectar_cidades)
  
  (prog (vertices))
  
  (ocorrencia cidade_dois)
  
)

(defun iniciar_hospitais ()
  
  (setf (obter_hospital cidade_um) (criar_hospital_amb 5 2 cidade_um) )
  (setf (obter_hospital cidade_tres) (criar_hospital 4 cidade_tres) )
  (setf (obter_hospital cidade_quatro) (criar_hospital_amb 7 1 cidade_quatro) )
  (setf (obter_hospital cidade_seis) (criar_hospital 3 cidade_seis) )
  (setf (obter_hospital cidade_dez) (criar_hospital_amb 10 1 cidade_dez) )
  (setf (obter_hospital cidade_cinco)  (criar_hospital_amb 8 2 cidade_cinco) )
  
  )

(defun conectar_cidades ()
  
  (push (criar_aresta cidade_quatro 10) (obter_arestas cidade_um))
  (push (criar_aresta cidade_sete 15) (obter_arestas cidade_um))
  (push (criar_aresta cidade_tres 8) (obter_arestas cidade_um))
  
  (push (criar_aresta cidade_quatro 20) (obter_arestas cidade_dois))
  (push (criar_aresta cidade_tres 5) (obter_arestas cidade_dois))
  (push (criar_aresta cidade_cinco 7) (obter_arestas cidade_dois))
  
  (push (criar_aresta cidade_um 8) (obter_arestas cidade_tres))
  (push (criar_aresta cidade_dois 5) (obter_arestas cidade_tres))
  (push (criar_aresta cidade_cinco 20) (obter_arestas cidade_tres))
  (push (criar_aresta cidade_seis 3) (obter_arestas cidade_tres))
  (push (criar_aresta cidade_sete 7) (obter_arestas cidade_tres))
  
  (push (criar_aresta cidade_dois 20) (obter_arestas cidade_quatro))
  (push (criar_aresta cidade_um 10) (obter_arestas cidade_quatro))
  (push (criar_aresta cidade_sete 8) (obter_arestas cidade_quatro))
  
  (push (criar_aresta cidade_tres 20) (obter_arestas cidade_cinco))
  (push (criar_aresta cidade_dois 7) (obter_arestas cidade_cinco))
  (push (criar_aresta cidade_oito 6) (obter_arestas cidade_cinco))
  
  (push (criar_aresta cidade_tres 3) (obter_arestas cidade_seis))
  (push (criar_aresta cidade_nove 13) (obter_arestas cidade_seis))
  (push (criar_aresta cidade_oito 9) (obter_arestas cidade_seis))
  (push (criar_aresta cidade_dez 11) (obter_arestas cidade_seis))
  
  (push (criar_aresta cidade_quatro 8) (obter_arestas cidade_sete))
  (push (criar_aresta cidade_um 15) (obter_arestas cidade_sete))
  (push (criar_aresta cidade_tres 7) (obter_arestas cidade_sete))
  (push (criar_aresta cidade_nove 3) (obter_arestas cidade_sete))
  
  (push (criar_aresta cidade_cinco 6) (obter_arestas cidade_oito))
  (push (criar_aresta cidade_seis 9) (obter_arestas cidade_oito))
  (push (criar_aresta cidade_dez 15) (obter_arestas cidade_oito))
  
  (push (criar_aresta cidade_sete 3) (obter_arestas cidade_nove))
  (push (criar_aresta cidade_seis 13) (obter_arestas cidade_nove))
  (push (criar_aresta cidade_dez 6) (obter_arestas cidade_nove))
  
  (push (criar_aresta cidade_oito 15) (obter_arestas cidade_dez))
  (push (criar_aresta cidade_seis 11) (obter_arestas cidade_dez))
  (push (criar_aresta cidade_nove 6) (obter_arestas cidade_dez))
 )