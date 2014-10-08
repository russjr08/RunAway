cmake_minimum_required(VERSION 2.8.4)
project(RunAway)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_NAME "RunAway")

include_directories("/usr/local/include/")

set(SOURCE_FILES
    src/Component/Component.hpp
    src/Component/GravityComponent.cpp
    src/Component/GravityComponent.hpp
    src/Component/HealthBarComponent.cpp
    src/Component/HealthBarComponent.hpp
    src/Entity/Entity.hpp
    src/Entity/Player.cpp
    src/Entity/Player.hpp
    src/Level/Level.cpp
    src/Level/Level.hpp
    src/Level/Tile.cpp
    src/Level/Tile.hpp
    src/FPS.hpp
    src/Game.cpp
    src/Game.hpp
    src/ImageManager.cpp
    src/ImageManager.hpp
    src/SoundManager.cpp
    src/SoundManager.hpp)

#foreach(asset ${ASSETS})
# file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
#endforeach(asset)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets"
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/assets)


find_package(SFML 2.0 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)





