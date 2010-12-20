
-- SHOULD NOT SEE ME ON THE LEXER, IM A COMMENT

print("testing our lexer !!!")

local function teste()
    for variavel in obj do
        if variavel then 
            continue
        end
    end
 
    return true
end

a = {}
a["pine"] = 5

--[[ SHOULD NOT SEE 
     ME ON THE 
     LEXER, IM A 
     MULTILINECOMMENT
]]

print(a)
print(a["pine"])
