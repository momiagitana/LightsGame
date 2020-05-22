cmake_minimum_required (VERSION 3.14)

project (oop2_ex04)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()
# macOS specific options
#if(SFML_OS_MACOSX)
    # add an option to build frameworks instead of dylibs (release only)
#    sfml_set_option(SFML_BUILD_FRAMEWORKS FALSE BOOL "TRUE to build SFML as frameworks libraries (release only), FALSE to build according to BUILD_SHARED_LIBS")

    # add an option to automatically install Xcode templates
    #sfml_set_option(SFML_INSTALL_XCODE_TEMPLATES FALSE BOOL "TRUE to automatically install the Xcode templates, FALSE to do nothing about it. The templates are compatible with Xcode 4 and 5.")
#endif()

add_executable (oop2_ex04 MACOSX_BUNDLE "")

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

set (SFML_STATIC_LIBRARIES FALSE)
set (SFML_DIR "/usr/local/Cellar/sfml/2.5.1")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)

set_target_properties ( PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (oop2_ex04 sfml-graphics)
