cmake_minimum_required(VERSION 3.26)
project(qtpro VERSION 1.0.0 DESCRIPTION "Data Structure Visualizer")

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt Configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64")
set(Qt6_DIR "C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6")

# Output Directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Include Directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find Qt6
find_package(Qt6 COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

# Source Files
set(SOURCE_FILES
    src/CircleNode.cpp
    src/Layout.cpp
    src/TreeNode.cpp
    src/mainWindow.cpp
    src/Line.cpp
    src/Graph.cpp
    src/LinkedListViz.cpp
    src/MenuWindow.cpp
)

# Header Files
set(HEADER_FILES
    include/CircleNode.h
    include/Layout.h
    include/TreeNode.h
    include/mainWindow.h
    include/Line.h
    include/Graph.h
    include/LinkedListViz.h
    include/MenuWindow.h
)

# Create Library
add_library(DSVisualizer STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(DSVisualizer 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Create Executable
add_executable(qtpro src/main.cpp)
target_link_libraries(qtpro DSVisualizer)

# Windows Qt Plugin Deployment
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()
    
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif()
    endif()
    
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    
    foreach(QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach()
endif()

# Installation Rules
install(TARGETS qtpro DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/docs/ DESTINATION docs)
