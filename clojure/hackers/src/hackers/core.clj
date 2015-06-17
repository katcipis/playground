(ns hackers.core
  (:gen-class))

(defn -main
  "Order hackers"
  [& [filename _]]
  (use 'clojure.java.io)
  (println "Sorting hackers file: " filename)
  (with-open [rdr (reader filename)]
    (doseq [line (line-seq rdr)]
      (println line))))
