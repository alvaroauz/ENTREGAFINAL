cmake_minimum_required(VERSION 3.6)
project(RECUPERACIONPROGRAMACION)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RECUPERACIONPROGRAMACION
    main.cpp
    medico.cpp
    paciente.cpp
    persona.cpp
    fecha.cpp
    registroClinico.cpp
    citamedica.cpp
)

if(MSVC)
    add_compile_options(/W4 /utf-8)
    target_compile_definitions(RECUPERACIONPROGRAMACION PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

target_include_directories(RECUPERACIONPROGRAMACION PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})