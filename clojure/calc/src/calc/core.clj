(ns calc.core
  (:gen-class))

;Variadic stuff: http://clojure-doc.org/articles/language/functions.html#variadic-functions
(defn add 
  [& args]
  (apply + args))

;Pre conditions and keyword args
(defn divide 
  [& {:keys [num denom]}]
   {:pre [(> denom 0)]}
  (/ num denom))

;Recursion
(defn factorial 
  [n]
  1)

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
