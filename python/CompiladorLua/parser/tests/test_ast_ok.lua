a = 5
b = 7
c = a + b
d = (c + a) * (b + 7)

function main(a, b,c)
    local x = a + b * c
    return x * a + 5
end

while a == 20000005 do 
    a = 6
end

if (a + b * c == d and a % 5 ~= 0) then
    print("operator precedence works !!!")
end

main(a,b,c)


