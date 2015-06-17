(ns calc.core-test
  (:require [clojure.test :refer :all]
            [calc.core :refer :all]))

(deftest adding-numbers
  (testing "Adding two numbers"
    (is (= 2 (calc.core/add 1 1))))
  (testing "Adding three numbers"
    (is (= 5 (calc.core/add 1 1 3))))
  (testing "Adding five numbers"
    (is (= 17 (calc.core/add 1 1 3 5 7)))))

(deftest dividing-numbers
  (testing "dividing two numbers"
    (is (= 2 (calc.core/divide 4 2))))
  (testing "cant divide by zero"
    (is (thrown? AssertionError (calc.core/divide 4 0)))))
