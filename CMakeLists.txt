cmake_minimum_required(VERSION 3.10)
project(c-strict-fibonacci-heaps VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------------------
# Options
# ------------------------------------------------------------------------------
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(USE_STATIC_CRT "Use static CRT (/MT, /MTd)" OFF)
option(USE_UNICODE "Use Unicode charset" OFF)
option(USE_LTO "Enable Link-Time Optimization" OFF)
option(MSVC_RTC "Enable MSVC Runtime Checks (/RTC1)" OFF)

if(USE_UNICODE)
    add_compile_definitions(UNICODE _UNICODE)
endif()

if(MSVC)
    if(USE_STATIC_CRT)
        if(POLICY CMP0091)
            cmake_policy(SET CMP0091 NEW)
            set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        else()
            foreach(flag_var
                CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
                CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
                if(${flag_var} MATCHES "/MD")
                    string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
                endif()
            endforeach()
        endif()
    endif()
    if(MSVC_RTC)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /RTC1")
    endif()
    # Provide safe CRT warnings disabling if desired, but we will use safe CRT.
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
endif()

if(USE_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT lto_supported OUTPUT lto_output)
    if(lto_supported)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(WARNING "LTO is not supported: ${lto_output}")
    endif()
endif()

# ------------------------------------------------------------------------------
# Type Definitions
# ------------------------------------------------------------------------------
set(SFH_KEY_TYPES_DEFAULT
    "int8_t;int16_t;int32_t;int64_t;uint8_t;uint16_t;uint32_t;uint64_t;float;double"
)
set(SFH_KEY_TYPES "${SFH_KEY_TYPES_DEFAULT}" CACHE STRING "Semicolon-separated list of types for keys")

set(SFH_VAL_TYPES_DEFAULT
    "int8_t;int16_t;int32_t;int64_t;uint8_t;uint16_t;uint32_t;uint64_t;float;double;char*"
)
set(SFH_VAL_TYPES "${SFH_VAL_TYPES_DEFAULT}" CACHE STRING "Semicolon-separated list of types for values")

set(GENERATED_HEADERS "")
set(GENERATED_SOURCES "")

set(COMPOSITE_HEADER "${CMAKE_CURRENT_BINARY_DIR}/c-strict-fibonacci-heaps.h")
file(WRITE ${COMPOSITE_HEADER} "/* clang-format off */
#ifndef STRICT_FIBONACCI_HEAPS_H
#define STRICT_FIBONACCI_HEAPS_H

#include \"c_strict_fibonacci_heaps_export.h\"

")

foreach(KEY_TYPE IN LISTS SFH_KEY_TYPES)
    foreach(VAL_TYPE IN LISTS SFH_VAL_TYPES)

        string(REPLACE "*" "ptr" PREFIX_KEY "${KEY_TYPE}")
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" PREFIX_KEY "${PREFIX_KEY}")

        string(REPLACE "*" "ptr" PREFIX_VAL "${VAL_TYPE}")
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" PREFIX_VAL "${PREFIX_VAL}")

        set(PREFIX "sfh_${PREFIX_KEY}_${PREFIX_VAL}")

        set(OUT_HEADER "${CMAKE_CURRENT_BINARY_DIR}/${PREFIX}.h")
        set(OUT_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/${PREFIX}.c")

        configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/src/c-strict-fibonacci-heaps.h.in"
            "${OUT_HEADER}"
            @ONLY
        )

        configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/src/c-strict-fibonacci-heaps.c.in"
            "${OUT_SOURCE}"
            @ONLY
        )

        list(APPEND GENERATED_HEADERS "${OUT_HEADER}")
        list(APPEND GENERATED_SOURCES "${OUT_SOURCE}")

        file(APPEND ${COMPOSITE_HEADER} "#include \"${PREFIX}.h\"\n")

    endforeach()
endforeach()

file(APPEND ${COMPOSITE_HEADER} "\n#endif /* STRICT_FIBONACCI_HEAPS_H */\n/* clang-format on */\n")

# ------------------------------------------------------------------------------
# Targets
# ------------------------------------------------------------------------------
add_library(c-strict-fibonacci-heaps ${GENERATED_SOURCES})

include(GenerateExportHeader)
generate_export_header(c-strict-fibonacci-heaps
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/c_strict_fibonacci_heaps_export.h
)

target_include_directories(c-strict-fibonacci-heaps PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")

include(CTest)
if(BUILD_TESTING AND PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        greatest
        GIT_REPOSITORY https://github.com/SamuelMarks/greatest.git
        GIT_TAG        master
        PATCH_COMMAND bash -c "sed -i \'s/CMAKE_SOURCE_DIR/CMAKE_CURRENT_SOURCE_DIR/g\' CMakeLists.txt && sed -i \'s/add_subdirectory(/\#add_subdirectory(/g\' CMakeLists.txt && sed -i \'s/include(CPack)/\#include(CPack)/g\' CMakeLists.txt"
    )
    FetchContent_MakeAvailable(greatest)

    add_executable(test_basic tests/test_basic.c)
    target_link_libraries(test_basic c-strict-fibonacci-heaps)
    target_include_directories(test_basic PRIVATE ${greatest_SOURCE_DIR})
    add_test(NAME test_basic COMMAND test_basic)
endif()

# ------------------------------------------------------------------------------
# Install & CPack
# ------------------------------------------------------------------------------
include(GNUInstallDirs)
install(TARGETS c-strict-fibonacci-heaps
        EXPORT c-strict-fibonacci-heaps-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(FILES ${GENERATED_HEADERS} ${COMPOSITE_HEADER} ${CMAKE_CURRENT_BINARY_DIR}/c_strict_fibonacci_heaps_export.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/c-strict-fibonacci-heaps
)

set(CPACK_PACKAGE_NAME "c-strict-fibonacci-heaps")
set(CPACK_PACKAGE_VENDOR "SamuelMarks")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Strict Fibonacci Heaps in C89")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
include(CPack)
