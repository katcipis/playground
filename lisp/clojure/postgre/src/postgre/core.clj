(ns postgre.core
  (:gen-class))

(use 'korma.db)
(defdb db (postgres {:db "corepj"
                     :user "postgre"}))

(use 'korma.core)
(defentity users)


(defn -main
  "Checking postgre connection on clojure"
  [& args]
  (println "Hello, World!")
  (select users))
