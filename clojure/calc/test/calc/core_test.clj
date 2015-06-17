(ns calc.core-test
  (:require [clojure.test :refer :all]
            [calc.core :refer :all]))

(deftest a-test
  (testing "Adding two numbers"
    (is (= 2 (calc.core/add 1 1)))))

(deftest a-test
  (testing "Adding three numbers"
    (is (= 5 (calc.core/add 1 1 3)))))
