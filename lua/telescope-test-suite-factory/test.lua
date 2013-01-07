
local Factory = require "test-suite-factory"

context("My Test suite", function () 

    local my_test_suite = Factory.create_test_suite()
    my_test_suite()

end)
