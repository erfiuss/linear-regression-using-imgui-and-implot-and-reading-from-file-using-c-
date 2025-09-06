cmake_minimum_required(VERSION 3.10)
project(ImGui_LinearRegression)

set(CMAKE_CXX_STANDARD 17)

# GLAD
include(FetchContent)
FetchContent_Declare(
glad
GIT_REPOSITORY https://github.com/Dav1dde/glad.git
GIT_TAG v0.1.36
)
FetchContent_MakeAvailable(glad)

# ImGui / ImPlot
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
set(IMPLOT_DIR ${CMAKE_SOURCE_DIR}/implot)

set(IMGUI_SRC
${IMGUI_DIR}/imgui.cpp
${IMGUI_DIR}/imgui_draw.cpp
${IMGUI_DIR}/imgui_widgets.cpp
${IMGUI_DIR}/imgui_tables.cpp
${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(IMPLOT_SRC
${IMPLOT_DIR}/implot.cpp
${IMPLOT_DIR}/implot_items.cpp
)

add_executable(${PROJECT_NAME}
main.cpp
${IMGUI_SRC}
${IMPLOT_SRC}
)

target_include_directories(${PROJECT_NAME} PRIVATE
${IMGUI_DIR}
${IMGUI_DIR}/backends
${IMPLOT_DIR}
)

# OpenGL
find_package(OpenGL REQUIRED)
#include_directories(ImGui_LinearRegression /usr/local/include)
# GLFW via pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES} glad OpenGL::GL)
# cmake_minimum_required(VERSION 3.10)
# project(ImGui_LinearRegression)

# set(CMAKE_CXX_STANDARD 17)

# # -----------------------
# # GLAD (auto fetch)
# # -----------------------
# include(FetchContent)
# FetchContent_Declare(
# glad
# GIT_REPOSITORY https://github.com/Dav1dde/glad.git
# GIT_TAG v0.1.36
# )
# FetchContent_MakeAvailable(glad)

# # -----------------------
# # ImGui / ImPlot
# # -----------------------
# set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
# set(IMPLOT_DIR ${CMAKE_SOURCE_DIR}/implot)

# set(IMGUI_SRC
# ${IMGUI_DIR}/imgui.cpp
# ${IMGUI_DIR}/imgui_draw.cpp
# ${IMGUI_DIR}/imgui_widgets.cpp
# ${IMGUI_DIR}/imgui_tables.cpp
# ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
# ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
# )

# set(IMPLOT_SRC
# ${IMPLOT_DIR}/implot.cpp
# ${IMPLOT_DIR}/implot_items.cpp
# )

# # -----------------------
# # Executable
# # -----------------------
# add_executable(${PROJECT_NAME}
# main.cpp
# ${IMGUI_SRC}
# ${IMPLOT_SRC}
# )

# # -----------------------
# # Include directories
# # -----------------------
# target_include_directories(${PROJECT_NAME} PRIVATE
# ${IMGUI_DIR}
# ${IMGUI_DIR}/backends
# ${IMPLOT_DIR}
# ${glad_SOURCE_DIR}/include
# /usr/include/GLFW # System GLFW
# )

# # -----------------------
# # Link libraries
# # -----------------------
# find_package(OpenGL REQUIRED)
# target_link_libraries(${PROJECT_NAME}
# glad
# glfw
# OpenGL::GL
# )
