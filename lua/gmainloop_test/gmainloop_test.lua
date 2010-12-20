local gnome = require("gnome")
local glib = require("glib")
-- This fails...why? local gtk  = require("gtk")

print("gnome: ")
for key, val in pairs(gnome) do
    print(key.." : "..tostring(val))
end
print("=========================================")

print("glib: ")
for key, val in pairs(glib) do
    print(key.." : "..tostring(val))
end
print("=========================================")
