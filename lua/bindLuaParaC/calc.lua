module(..., package.seeall)

-----------------------------------------------------
-- Class attributes and methods goes on this table --
-----------------------------------------------------
local Calc = {} 

--------------------------------------
-- Metamethods goes on this table   --
-- Index must point to the table    --
-- where the methods will be stored --
--------------------------------------
local Calc_mt = { __index = Calc }

--- Creates a Calc object.
-- Constructor function. 
-- @return A Calc object. 
function new (number1, number2)
    local obj = {}      
    -- set the metatable of the new object as the Calc_mt table.
    setmetatable(obj, Calc_mt)
    obj.number1 = number1
    obj.number2 = number2
    return obj
end

function Calc:sum()
    return self.number1 + self.number2
end

function Calc:sub()
    return self.number1 - self.number2
end

function Calc:mul()
    return self.number1 * self.number2
end

function Calc:div()
    return self.number1 / self.number2
end
