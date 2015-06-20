(ns postgre.core
  (:gen-class))

(use 'korma.db)
(defdb db (postgres {:db "postgres"
                     :host "localhost"
                     :port 5432
                     :user "postgres"}))

(use 'korma.core)
(defentity users)


(defn -main
  "Checking postgre connection on clojure"
  [& args]
  (println "Creating table")
  (defentity address (table :__addresses :address))
  (println "Searching")
  (select address))
