(ns calc.core
  (:gen-class))

;Variadic stuff: http://clojure-doc.org/articles/language/functions.html#variadic-functions
(defn add 
  [& args]
  (apply + args))

;defn is just a macro
(def add2 
  (fn
    [& args]
    (apply + args)))

;Pre conditions and keyword args (keyword args uses variadic args)
(defn divide 
  [& {:keys [num denom]}]
   {:pre [(> denom 0)]}
  (/ num denom))

;Recursion
(defn factorial 
  [n]
  (if (== n 0) 1 (* n (factorial (- n 1)))))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
