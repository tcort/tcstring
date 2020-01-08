cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)
project(tcstring VERSION 1.0.0 DESCRIPTION "simple regular expressions library"
    LANGUAGES C)

include(GNUInstallDirs)

add_library(tcstring SHARED tcstring.c)

set_target_properties(tcstring PROPERTIES VERSION ${PROJECT_VERSION}
    SOVERSION 1 PUBLIC_HEADER tcstring.h)

configure_file(tcstring.pc.in tcstring.pc @ONLY)

enable_testing(true)
add_executable(tcstring.test tcstring.test.c)
target_link_libraries(tcstring.test tcstring)
add_test(tcstring.test tcstring.test)

install(FILES ${CMAKE_BINARY_DIR}/tcstring.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS tcstring LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CPack)
