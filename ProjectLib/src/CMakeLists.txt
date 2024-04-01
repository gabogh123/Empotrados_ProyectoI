project(SmartHomeControlSrc)

# Añade la biblioteca "biblioteca"
add_library(biblioteca STATIC biblioteca.c)

# Ajusta esta línea para incluir correctamente el directorio de encabezados
target_include_directories(biblioteca PUBLIC ../include)

# Añade el ejecutable del proyecto
add_executable(SmartHomeControl main.c)

# Enlaza la biblioteca WiringPi y "biblioteca" con el ejecutable
target_link_libraries(SmartHomeControl biblioteca wiringPi)

# Asegúrate de que SmartHomeControl también conozca el directorio de los encabezados
target_include_directories(SmartHomeControl PUBLIC ../include)

