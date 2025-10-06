# Definir a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Definir o compilador C (clang)
set(CMAKE_C_COMPILER "clang")

# Adicionar opção para depuração
set(CMAKE_C_FLAGS_DEBUG "-g")

# Nome do projeto
project(GenericProject VERSION 1.0 LANGUAGES C)

# Ativar geração do compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Definir os diretórios
set(SRC_DIR "src")
set(INC_DIR "inc")
set(BUILD_DIR "build")

# Configurar os arquivos fonte
file(GLOB SOURCES "${SRC_DIR}/*.c")

# Buscar a biblioteca SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Definir o executável
add_executable(project_bin ${SOURCES})

# Associar os arquivos de cabeçalho à build do executável
target_include_directories(project_bin PRIVATE ${INC_DIR})

# Vincular a SDL2 ao executável
target_link_libraries(project_bin PRIVATE ${SDL2_LIBRARIES} m)

# Adicionar as flags de warning
#target_compile_options(project_bin PRIVATE
#    -Wall
#    -Wextra
#    -Wpedantic
#    -Werror      # Opcional: Tratar avisos como erros
#    -Wshadow     # Avisos sobre variáveis com o mesmo nome em diferentes escopos
#    -Wconversion # Avisos sobre conversões implícitas de tipos
#)

# Configurar o diretório de saída dos binários
set_target_properties(project_bin PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR})
