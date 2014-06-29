cmake_minimum_required(VERSION 2.8)

if(FLTK_FOUND)
    add_subdirectory(fltk)
endif()

if(QT_FOUND)
    add_subdirectory(MyQt)
endif()