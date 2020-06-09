

function(conan_message MESSAGE_OUTPUT)
    if(NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif()
endfunction()


macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS FRAMEWORKS_DIRS)
    if(APPLE)
        foreach(_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAME ${_FRAMEWORK} PATHS ${FRAMEWORKS_DIRS})
            if(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${FRAMEWORKS_DIRS}")
            endif()
        endforeach()
    endif()
endmacro()


function(conan_package_library_targets libraries package_libdir deps out_libraries out_libraries_target build_type package_name)
    unset(_CONAN_ACTUAL_TARGETS CACHE)
    unset(_CONAN_FOUND_SYSTEM_LIBS CACHE)
    foreach(_LIBRARY_NAME ${libraries})
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            list(APPEND _out_libraries ${CONAN_FOUND_LIBRARY})
            if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
                # Create a micro-target for each lib/a found
                set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME}${build_type})
                if(NOT TARGET ${_LIB_NAME})
                    # Create a micro-target for each lib/a found
                    add_library(${_LIB_NAME} UNKNOWN IMPORTED)
                    set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
                    set(_CONAN_ACTUAL_TARGETS ${_CONAN_ACTUAL_TARGETS} ${_LIB_NAME})
                else()
                    conan_message(STATUS "Skipping already existing target: ${_LIB_NAME}")
                endif()
                list(APPEND _out_libraries_target ${_LIB_NAME})
            endif()
            conan_message(STATUS "Found: ${CONAN_FOUND_LIBRARY}")
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            list(APPEND _out_libraries_target ${_LIBRARY_NAME})
            list(APPEND _out_libraries ${_LIBRARY_NAME})
            set(_CONAN_FOUND_SYSTEM_LIBS "${_CONAN_FOUND_SYSTEM_LIBS};${_LIBRARY_NAME}")
        endif()
        unset(CONAN_FOUND_LIBRARY CACHE)
    endforeach()

    if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
        # Add all dependencies to all targets
        string(REPLACE " " ";" deps_list "${deps}")
        foreach(_CONAN_ACTUAL_TARGET ${_CONAN_ACTUAL_TARGETS})
            set_property(TARGET ${_CONAN_ACTUAL_TARGET} PROPERTY INTERFACE_LINK_LIBRARIES "${_CONAN_FOUND_SYSTEM_LIBS};${deps_list}")
        endforeach()
    endif()

    set(${out_libraries} ${_out_libraries} PARENT_SCOPE)
    set(${out_libraries_target} ${_out_libraries_target} PARENT_SCOPE)
endfunction()


include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated Findxcb-proto.cmake")
# Global approach
set(xcb-proto_FOUND 1)
set(xcb-proto_VERSION "1.13")

find_package_handle_standard_args(xcb-proto REQUIRED_VARS
                                  xcb-proto_VERSION VERSION_VAR xcb-proto_VERSION)
mark_as_advanced(xcb-proto_FOUND xcb-proto_VERSION)


set(xcb-proto_INCLUDE_DIRS )
set(xcb-proto_INCLUDE_DIR "")
set(xcb-proto_INCLUDES )
set(xcb-proto_RES_DIRS )
set(xcb-proto_DEFINITIONS )
set(xcb-proto_LINKER_FLAGS_LIST
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>
)
set(xcb-proto_COMPILE_DEFINITIONS )
set(xcb-proto_COMPILE_OPTIONS_LIST "" "")
set(xcb-proto_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(xcb-proto_LIBRARIES "") # Will be filled later
set(xcb-proto_LIBS "") # Same as xcb-proto_LIBRARIES
set(xcb-proto_SYSTEM_LIBS )
set(xcb-proto_FRAMEWORK_DIRS )
set(xcb-proto_FRAMEWORKS )
set(xcb-proto_FRAMEWORKS_FOUND "") # Will be filled later
set(xcb-proto_BUILD_MODULES_PATHS )

conan_find_apple_frameworks(xcb-proto_FRAMEWORKS_FOUND "${xcb-proto_FRAMEWORKS}" "${xcb-proto_FRAMEWORK_DIRS}")

mark_as_advanced(xcb-proto_INCLUDE_DIRS
                 xcb-proto_INCLUDE_DIR
                 xcb-proto_INCLUDES
                 xcb-proto_DEFINITIONS
                 xcb-proto_LINKER_FLAGS_LIST
                 xcb-proto_COMPILE_DEFINITIONS
                 xcb-proto_COMPILE_OPTIONS_LIST
                 xcb-proto_LIBRARIES
                 xcb-proto_LIBS
                 xcb-proto_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to xcb-proto_LIBS and xcb-proto_LIBRARY_LIST
set(xcb-proto_LIBRARY_LIST )
set(xcb-proto_LIB_DIRS "/home/pierre/.conan/data/xcb-proto/1.13/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_xcb-proto_DEPENDENCIES "${xcb-proto_FRAMEWORKS_FOUND} ${xcb-proto_SYSTEM_LIBS} ")

conan_package_library_targets("${xcb-proto_LIBRARY_LIST}"  # libraries
                              "${xcb-proto_LIB_DIRS}"      # package_libdir
                              "${_xcb-proto_DEPENDENCIES}"  # deps
                              xcb-proto_LIBRARIES            # out_libraries
                              xcb-proto_LIBRARIES_TARGETS    # out_libraries_targets
                              ""                          # build_type
                              "xcb-proto")                                      # package_name

set(xcb-proto_LIBS ${xcb-proto_LIBRARIES})

foreach(_FRAMEWORK ${xcb-proto_FRAMEWORKS_FOUND})
    list(APPEND xcb-proto_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND xcb-proto_LIBRARIES ${_FRAMEWORK})
endforeach()

foreach(_SYSTEM_LIB ${xcb-proto_SYSTEM_LIBS})
    list(APPEND xcb-proto_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND xcb-proto_LIBRARIES ${_SYSTEM_LIB})
endforeach()

# We need to add our requirements too
set(xcb-proto_LIBRARIES_TARGETS "${xcb-proto_LIBRARIES_TARGETS};")
set(xcb-proto_LIBRARIES "${xcb-proto_LIBRARIES};")

set(CMAKE_MODULE_PATH "/home/pierre/.conan/data/xcb-proto/1.13/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"/home/pierre/.conan/data/xcb-proto/1.13/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/lib/pkgconfig" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/home/pierre/.conan/data/xcb-proto/1.13/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"/home/pierre/.conan/data/xcb-proto/1.13/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/lib/pkgconfig" ${CMAKE_PREFIX_PATH})

foreach(_BUILD_MODULE_PATH ${xcb-proto_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET xcb-proto::xcb-proto)
        add_library(xcb-proto::xcb-proto INTERFACE IMPORTED)
        if(xcb-proto_INCLUDE_DIRS)
            set_target_properties(xcb-proto::xcb-proto PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                  "${xcb-proto_INCLUDE_DIRS}")
        endif()
        set_property(TARGET xcb-proto::xcb-proto PROPERTY INTERFACE_LINK_LIBRARIES
                     "${xcb-proto_LIBRARIES_TARGETS};${xcb-proto_LINKER_FLAGS_LIST}")
        set_property(TARGET xcb-proto::xcb-proto PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     ${xcb-proto_COMPILE_DEFINITIONS})
        set_property(TARGET xcb-proto::xcb-proto PROPERTY INTERFACE_COMPILE_OPTIONS
                     "${xcb-proto_COMPILE_OPTIONS_LIST}")
        
    endif()
endif()
