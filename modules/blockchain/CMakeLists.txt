cmake_minimum_required(VERSION 3.5)
project(mcb)


set(PROJECT_SRCS
  ${PROJECT_SOURCE_DIR}/src/block.cpp        
  ${PROJECT_SOURCE_DIR}/src/block_chain.cpp        
)

find_package(spdlog REQUIRED)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
                          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

target_link_libraries(${PROJECT_NAME}
                      spdlog::spdlog)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        ARCHIVE DESTINATION lib COMPONENT install-app
        LIBRARY DESTINATION lib COMPONENT install-app
        RUNTIME DESTINATION bin COMPONENT install-app)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/mcb
        DESTINATION include/mcb
        FILES_MATCHING PATTERN "*.h")

export(TARGETS ${PROJECT_NAME} NAMESPACE mcb::
      APPEND FILE ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Targets.cmake)

file(APPEND
    ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
"set(ROOM_RGBDSLAM_LIBRARIES \${ROOM_RGBDSLAM_LIBRARIES} ${PROJECT_NAME})\n")
