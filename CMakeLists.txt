cmake_minimum_required(VERSION 3.19)
project(minitalk C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(ft_printf)

add_executable(client client.c includes/client.h)
add_executable(server server.c includes/server.h)
add_executable(client_bonus client_bonus.c includes/client.h)
add_executable(server_bonus server_bonus.c includes/server.h)
add_executable(test main.c)
target_link_libraries(client ft_printf)
target_link_libraries(server ft_printf)
target_link_libraries(client_bonus ft_printf)
target_link_libraries(server_bonus ft_printf)