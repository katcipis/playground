require("gst")

gst.gst_init(nil, nil)

pipe     = gst.gst_pipeline_new("pipe")
source   = gst.gst_element_factory_make("audiotestsrc", "src")
identity = gst.gst_element_factory_make("identity", "id")
sink     = gst.gst_element_factory_make("autoaudiosink", "sink")

print(pipe)
print(source)
print(identity)
print(sink)

print(gst.gst_bin_add(gst.lua_gst_bin(pipe), source))
print(gst.gst_bin_add(gst.lua_gst_bin(pipe), identity))
print(gst.gst_bin_add(gst.lua_gst_bin(pipe), sink))

print(gst.gst_element_link(source, identity))
print(gst.gst_element_link(identity, sink))

gst.gst_element_set_state(pipe, gst.GST_STATE_PLAYING);
while 1 do
    print("yay playing sound")
end    

