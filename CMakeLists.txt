cmake_minimum_required(VERSION 3.16)
project(aurora-terminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar los módulos de Qt necesarios
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)

# Verificar la presencia de script
find_program(SCRIPT_EXECUTABLE script)
if(NOT SCRIPT_EXECUTABLE)
    message(FATAL_ERROR "The script program is necessary to run aurora-terminal. Install util-linux in your host distribution")
endif()

# Configuración del ejecutable
add_executable(aurora-terminal
    src/main.cpp
    src/mainwindow.cpp
    src/include/mainwindow.h
    src/shortcuts.cpp
    src/include/shortcuts.h
    src/terminalwidget.cpp
    src/include/terminalwidget.h
    src/about.cpp
    src/include/about.h
)

# Vincular bibliotecas de Qt
target_link_libraries(aurora-terminal Qt6::Core Qt6::Gui Qt6::Widgets)

# Definir directorios de instalación
include(GNUInstallDirs)

# Instalar el ejecutable en el directorio bin
install(TARGETS aurora-terminal
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Instalar recursos adicionales (iconos, archivos de configuración, etc.)
install(FILES
    resources/icon.png  # Reemplaza con tus recursos reales
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/aurora-terminal
)

# Instalar el archivo de escritorio en Linux (opcional)
install(FILES
    resources/aurora-terminal.desktop  # Reemplaza con tu archivo .desktop real
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications
)

