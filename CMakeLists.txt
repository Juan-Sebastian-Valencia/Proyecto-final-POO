cmake_minimum_required(VERSION 3.10)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    controlador
    modelo
    vista
)


set(SOURCES
    main.cpp

    controlador/ControladorConsola.cpp

    modelo/Baraja.cpp
    modelo/Carta.cpp
    modelo/Crupier.cpp
    modelo/Jugador.cpp

    vista/VistaConsola.cpp
)


add_executable(ProyectoFinal ${SOURCES})


enable_testing()
add_subdirectory(tests)
