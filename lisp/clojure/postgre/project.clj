(defproject postgre "0.1.0-SNAPSHOT"
  :description "FIXME: write description"
  :url "http://example.com/FIXME"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [
                 [korma "0.4.2"] 
                 [org.postgresql/postgresql "9.3-1102-jdbc41"]
                 [org.clojure/clojure "1.6.0"]]
  :main ^:skip-aot postgre.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
