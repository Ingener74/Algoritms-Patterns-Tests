cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME MyQt)
project(${PROJECT_NAME})

include_directories(
    ${CMAKE_BINARY_DIR}/apps/MyQt
)

file(GLOB SOURCES src/*.cpp)
file(GLOB UIS     ui/*.ui)

QT4_WRAP_UI(UI_SOURCES ${UIS})
QT4_WRAP_CPP(MOC_SOURCES src/MyQtMainWindow.h)
QT4_ADD_RESOURCES(RES_SOURCES res/myqtres.qrc)

add_executable(${PROJECT_NAME} 
    ${SOURCES} 
    ${UI_SOURCES} 
    ${MOC_SOURCES} 
    ${RES_SOURCES}
)

set(LIBS
    ${QT_LIBRARIES}
    ${Boost_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME} ${LIBS})