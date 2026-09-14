cmake_minimum_required(VERSION 3.16)
project(contro-qt6 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

# Qt6Keychain
find_library(QT6KEYCHAIN_LIB qt6keychain PATHS /usr/lib /usr/local/lib)
if(NOT QT6KEYCHAIN_LIB)
    message(WARNING "Qt6Keychain not found, building without keychain support")
endif()

set(SOURCES
    src/main.cpp
    src/ui/mainwindow.cpp
    src/core/pocketbaseclient.cpp
    src/ui/contractdialog.cpp
    src/core/sessionmanager.cpp
    src/ui/entidaddialog.cpp
    src/ui/logindialog.cpp
)

set(HEADERS
    src/ui/mainwindow.h
    src/core/pocketbaseclient.h
    src/ui/contractdialog.h
    src/core/sessionmanager.h
    src/ui/entidaddialog.h
    src/ui/logindialog.h
)

set(FORMS
    src/ui/mainwindow.ui
    src/ui/contractdialog.ui
    src/ui/entidaddialog.ui
    src/ui/logindialog.ui
)

qt6_wrap_cpp(MOC_SOURCES ${HEADERS})
qt6_wrap_ui(UI_HEADERS ${FORMS})

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${MOC_SOURCES}
    ${UI_HEADERS}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)

if(QT6KEYCHAIN_LIB)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${QT6KEYCHAIN_LIB})
    target_include_directories(${PROJECT_NAME} PRIVATE /usr/include/qt6keychain)
endif()
