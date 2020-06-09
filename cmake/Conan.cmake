macro(run_conan)

  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
         "${CMAKE_BINARY_DIR}/conan/conan.cmake")
  endif()

  include(${CMAKE_BINARY_DIR}/conan/conan.cmake)

  set(_GLIBCXX_USE_CXX11_ABI)

  conan_add_remote(NAME bincrafters URL https://api.bintray.com/conan/bincrafters/public-conan)

  conan_cmake_run(
    # options
    BASIC_SETUP
    NO_OUTPUT_DIRS
    CMAKE_TARGETS
    TARGETS
    # oneValueArgs
    INSTALL_FOLDER
    ${CMAKE_BINARY_DIR}/conan
    CONANFILE
    conanfile.txt
    # multiValueArgs
    BUILD
    missing
    INSTALL_ARGS
    -s
    build_type=${CMAKE_BUILD_TYPE}
    REQUIRES
    ${CONAN_EXTRA_REQUIRES}
    OPTIONS
    ${CONAN_EXTRA_OPTIONS})

endmacro()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_BINARY_DIR}/conan")
