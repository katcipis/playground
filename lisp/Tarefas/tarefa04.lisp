(defun exec_um_a ()
  (prog(resultado))
  (setq resultado (+ (read) (read) ))
  (print resultado)
  (+ resultado 3)   
 )

(defun exec_um_b () 
   (list  (read))  
 )

(defun exec_um_c ()
  (prog(resultado))
  (setq resultado (+ (read) (read) ))
  (list  resultado) 
)

(defun exec_um_d ()
  (prog(a b c))
  (setq a (read))
  (setq b (read))
  (setq c (read))
  (list  a b c) 
 )

(defun exec_um_e ()
  (prog(a b c d e))
  (setq a (read) )
  (setq b (read) )
  (setq c (read) )
  (setq d (+ a b))
  (setq e (* d c))
  (list  d e) 
 )

(defun exec_dois_a ()
  (prog(a))
  (setq a (read))
  (if (= a 0)
      0
     (if (< a 0)
      -1
       1
     )
  )
)

(defun exec_dois_b (nome)
  
  
  ( if (equal nome (read))
    (progn
       (print (concatenate 'string "Olá " nome))
       t)

    nil
    )
     
)

(defun exec_dois_c (a b c)
        (case a
                ('* (* b c))
                ('/ (/ b c))
                (otherwise (print"Operador Inválido")  0)
        )
)

(defun exec_dois_d ( a b c )
        (or (= a b) (= a c))
)

(defun exec_dois_e ( elem lista )
        (equal elem (find elem lista ))       
)
