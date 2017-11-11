set(SOURCES core.c IOfile.c)
set(HEADERS core.h IOfile.h)

add_library(core ${SOURCES} ${HEADERS})
target_link_libraries(core graphic)