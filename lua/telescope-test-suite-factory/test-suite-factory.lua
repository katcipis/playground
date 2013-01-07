--Just a small POC.

local Factory = {}

function Factory.create_test_suite()

    local test_suite = function ()
        context ("Factory context", function ()

            test("Factory test 1", function ()
                assert_true(1 == 1)
            end)

            test("Factory test 1", function ()
                assert_equal("abacate","abacate")
            end)

        end)

    end

    --damn you unportable way to get/set the environment !!!
    --if the test suite environment is not the same of the caller
    --telescope simply wont work, it does a lot of magic to 
    --the original loaded file, when you run tsc test.lua.
    setfenv(test_suite, getfenv(2))
    return test_suite
end

return Factory

