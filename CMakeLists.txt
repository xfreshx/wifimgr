cmake_minimum_required(VERSION 2.8)

project(WifiMAnager)

find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

find_path(LADB_INCLUDE_DIR ...)

if((NOT LADB_INCLUDE_DIR) OR (NOT EXISTS ${LADB_INCLUDE_DIR}))

    message("Unable to find libadb")

    # we have a submodule setup for foo, assume it is under external/foo
    # now we need to clone this submodule
    execute_process(COMMAND git submodule update --init -- external/libadb
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    # set FOO_INCLUDE_DIR properly
    set(FOO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/foo/path/to/include
        CACHE PATH "foo include directory")

    # also install it
    install(DIRECTORY ${FOO_INCLUDE_DIR}/foo DESTINATION ${some_dest})

    # for convenience setup a target
    add_library(foo INTERFACE)
    target_include_directories(foo INTERFACE
                               $<BUILD_INTERFACE:${FOO_INCLUDE_DIR}>
                               $<INSTALL_INTERFACE:${some_dest}>)

    # need to export target as well
    install(TARGETS foo EXPORT my_export_set DESTINATION ${some_dest})
else()
    # see above, setup target as well
endif()

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
