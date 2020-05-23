FILE(GLOB sources *.c)
idf_component_register(SRCS ${sources} component1.c component2.c component3.c
                       LDFRAGMENTS "initcalls.lf")

# --whole-archive is required since some of the objct files inside the lib
# archive will not provide any symbols required by the linking process.
# However they do provide initcall sections which need to be included in
# the linking process
target_link_options(${COMPONENT_LIB} PUBLIC "-Wl,--whole-archive")
target_link_options(${COMPONENT_LIB} PUBLIC "$<TARGET_LINKER_FILE:${COMPONENT_LIB}>")
target_link_options(${COMPONENT_LIB} PUBLIC "-Wl,--no-whole-archive")
