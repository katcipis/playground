(ns calc.core
  (:gen-class))

;Variadic stuff: http://clojure-doc.org/articles/language/functions.html#variadic-functions
(defn add 
  ([& args]
  (apply + args)))

;Pre conditions
(defn divide 
  ([a b]
   {:pre [(> b 0)]}
  (/ a b)))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
