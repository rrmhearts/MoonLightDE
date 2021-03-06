#    Copyright (C) 2014 Moonlight Desktop Environment Team
#    Authors:
#       Alexis López Zubieta
#    This file is part of the Moonlight Desktop Environment
#
#    Moonlight Desktop Environment is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Moonlight Desktop Environment is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Moonlight Desktop Environment.  If not, see <http://www.gnu.org/licenses/>.
#
project(core)

## --------------------------------------------------------------
## Sources
## --------------------------------------------------------------

file(GLOB ${PROJECT_NAME}_PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include/core/*.h)

file(GLOB ${PROJECT_NAME}_SOURCES c++/*.cpp)

file(GLOB ${PROJECT_NAME}_UIS ui/*.ui)

file(GLOB ${PROJECT_NAME}_RESOURCES res/*)


## --------------------------------------------------------------
## Dependencies
## --------------------------------------------------------------

## QT 5
find_package(Qt5Core    REQUIRED)
find_package(Qt5Gui     REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

QT5_WRAP_UI(${PROJEC_NAME}_UI_HEADERS ${${PROJECT_NAME}_UIS})
QT5_ADD_RESOURCES(${PROJEC_NAME}_QRC_SOURCES ${${PROJEC_NAME}_RESOURCES})

#CppMicroServices
find_package(CppMicroServices NO_MODULE REQUIRED)
include_directories(${CppMicroServices_INCLUDE_DIRS})

include_directories(${CMAKE_BINARY_DIR})

## QT5XDG
find_package(QT5XDG REQUIRED)
include(${QTXDG_USE_FILE})  

## LXQT -- depends on QT5XDG
find_package(LXQT-QT5 REQUIRED )
include(${LXQT_USE_FILE})

## --------------------------------------------------------------
## Build Rules
## --------------------------------------------------------------

usFunctionGenerateExecutableInit(${PROJECT_NAME}_SOURCES
                                 IDENTIFIER "Core"
                                 )

configure_file( c++/MoonLightDECoreConfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/MoonLightDECoreConfig.h)

add_executable(${CMAKE_PROJECT_NAME}-${PROJECT_NAME} 
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
    ${${PROJEC_NAME}_UI_HEADERS}
    ${${PROJEC_NAME}_QRC_SOURCES}
)

qt5_use_modules(${CMAKE_PROJECT_NAME}-${PROJECT_NAME} Core Gui Widgets)

# Link the CppMicroServices library
target_link_libraries(${CMAKE_PROJECT_NAME}-${PROJECT_NAME} 
    CppMicroServices
    ${LXQT_LIBRARIES}
    ${QTXDG_LIBRARIES}
)

## --------------------------------------------------------------
## Install
## --------------------------------------------------------------


INSTALL(TARGETS ${CMAKE_PROJECT_NAME}-${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION MODULES_OUTPUT_DIR
    ARCHIVE DESTINATION lib/static)

INSTALL(FILES ${${PROJECT_NAME}_PUBLIC_HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME}/${PROJECT_NAME})