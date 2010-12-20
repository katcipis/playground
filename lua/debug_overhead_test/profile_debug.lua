if (#arg < 2) then
    print("Usage:lua profile_debug.lua [logmode] [profile_result_path]")
    print("logmode: stdout rawfile lualoggingfile lualoggingsocket nolog")
    return
end

local profiler = require("profiler")
local square   = math.sqrt
local sin      = math.sin
local cos      = math.cosh

local logmodes = {
                     rawfile = function ()
                                   local file     = io.open("rawfile.log", "w+")
                                   return function (...)
                                              file:write(...)
                                              file:write("\n")
                                          end
                               end,

                      stdout = function () return print end,

                      lualoggingfile = function ()
                                           require "logging.file" 
                                           local logger = logging.file("lualoggingfile.log")
                                           --logger:setLevel(logging.INFO) --REMOVE THIS
                                           local concat = table.concat
                                           return function (...)
                                                      logger:debug(concat({...}))
                                                  end
                                       end,

                      lualoggingsocket = function ()
                                             require "logging.socket"
                                             local logger = logging.socket("localhost", 5000) 
                                             --logger:setLevel(logging.INFO) --REMOVE THIS
                                             local concat = table.concat
                                             return function (...)
                                                      logger:debug(concat({...}))
                                                    end
                                         end,

                      nolog = function () return function() end end
                 }

local debug = logmodes[arg[1]]()

if (not debug) then
    print(arg[1], "is not a valid debug mode !!!")
    return
end

function simulate_calc(i)
            local results = {} 
            for i = i, 2000 do
                results[#results + 1] = square(i) ^ 7 + sin(i) + cos(i)
                debug("result [", #results, "] is ", results[#results])
            end
         end 

-- starts the test
profiler.start(arg[2])

for i=1, 1000 do
    debug("this is the [", i, "] call.")
    simulate_calc(i)
end

profiler.stop()

