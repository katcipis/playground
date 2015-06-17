(ns calc.core
  (:gen-class))

(defn add 
  ([a b]
  (+ a b))
  ([a b c]
  (+ a b c)))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
