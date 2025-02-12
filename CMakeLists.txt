cmake_minimum_required(VERSION 3.6)
project(RECUPERACION_PROGRAMACION)

set(SOURCES
    main.cpp
    medico.cpp
    paciente.cpp
    persona.cpp
    fecha.cpp
    registroClinico.cpp
    citaMedica.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-pedantic -Wall -W -Wconversion -O0 -ggdb -std=gnu++17")