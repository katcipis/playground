(ns hackers.core
  (:gen-class))

(defn -main
  [& [filename _]]
  (with-open [rdr (clojure.java.io/reader filename)]
    (doseq [name (sort (fn [a,b] (> (count a) (count b))) (line-seq rdr))] (println name))))
