# 这个cmakelists文件专门用来安装algorithms库
file(GLOB Includes *.h)
message(STATUS "these .h files will be installed: ${Includes}")
install(FILES ${Includes} DESTINATION include/algorithms)