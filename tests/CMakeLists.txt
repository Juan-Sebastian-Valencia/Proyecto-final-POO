# Descarga GoogleTest automáticamente
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)


set(PROYECTO_SOURCES
    ../modelo/Baraja.cpp
    ../modelo/Carta.cpp
    ../modelo/Crupier.cpp
    ../modelo/Jugador.cpp
)


add_executable(test_baraja test_baraja.cpp ${PROYECTO_SOURCES})
target_include_directories(test_baraja PUBLIC ..)
target_link_libraries(test_baraja gtest gtest_main)


add_executable(test_jugador test_jugador.cpp ${PROYECTO_SOURCES})
target_include_directories(test_jugador PUBLIC ..)
target_link_libraries(test_jugador gtest gtest_main)


enable_testing()
add_test(NAME PruebaBaraja COMMAND test_baraja)
add_test(NAME PruebaJugador COMMAND test_jugador)
