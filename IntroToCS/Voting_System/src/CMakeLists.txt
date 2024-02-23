set(EXE_SOURCES
    "main.c"
    )

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

#Exe Options
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/app/)
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/)
target_link_libraries(${EXECUTABLE_NAME} ${CANDIDATE_LIB})