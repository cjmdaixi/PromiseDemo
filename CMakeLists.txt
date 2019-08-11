cmake_minimum_required(VERSION 3.1)

project(PromiseDemo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick ConCurrent REQUIRED)
link_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" asyncactions.h asyncactions.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick Qt5::Concurrent)

install(DIRECTORY QuickPromise DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(DIRECTORY QuickFuture DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
