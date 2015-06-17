(ns calc.core
  (:gen-class))

(defn add 
  ([& args]
  (apply + args)))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
