pcall(require, "luarocks.require")
require "alien"
require "alien.struct"

local gst = alien.load("/usr/lib/libgstreamer-0.10.so")

local init = gst.gst_init
      init:types("pointer", "pointer", "pointer")
      init(nil, nil)

local factory = gst.gst_element_factory_make
      factory:types("pointer", "string", "string")

local link = gst.gst_element_link
      link:types("int", "pointer", "pointer")

local new_pipe = gst.gst_pipeline_new
      new_pipe:types("pointer", "string")

local bin_add = gst.gst_bin_add
      bin_add:types("int","pointer","pointer")

local set_state = gst.gst_element_set_state
      set_state:types("int", "pointer", "int")

local new_main_loop = gst.g_main_loop_new
      new_main_loop:types("pointer", "pointer", "int")

local run_main_loop = gst.g_main_loop_run
      run_main_loop:types("void", "pointer")

local loop   = new_main_loop(nil, 0)
local pipe   = new_pipe("pipe_teste")
local source = factory("audiotestsrc", "src_teste")
local sink   = factory("pulsesink", "sink_teste")

print(pipe)
print(source)
print(sink)

print(bin_add(pipe,source))
print(bin_add(pipe, sink))
print(link(source, sink))

set_state(pipe, 4)
run_main_loop(loop)

