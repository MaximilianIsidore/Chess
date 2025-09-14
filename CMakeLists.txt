cmake_minimum_required(VERSION 3.16)
project(Chess)

#set c++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-3.0.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)

add_executable(Chess main.cpp)

set_target_properties(Chess PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        board.ixx
        game.ixx
)

target_link_libraries(Chess PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)