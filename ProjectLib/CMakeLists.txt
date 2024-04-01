cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto y la versión
project(SmartHomeControl VERSION 1.0)

# Especifica el estándar de C++ requerido
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Opciones para la cross-compilación, ajustar según sea necesario
# set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_PROCESSOR arm)
# set(CMAKE_C_COMPILER /path/to/arm-none-linux-gnueabihf-gcc)

# Añade el directorio src al build
add_subdirectory(src)

# Especifica dónde se instalarán los archivos. Puede ser necesario ajustar
install(TARGETS SmartHomeControl DESTINATION bin)

