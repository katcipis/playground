local outerPrint = function() 
    print("should see me");
end

local doSomePrinting = function() 
    local innerPrint = function() 
        print("should not see me");
    end
    outerPrint(); -- works :-)
    innerPrint(); -- breaks here
end

setfenv(doSomePrinting, {});
doSomePrinting();
