set(CANDIDATE_LIB_SOURCES
    "candidate.c"
    )

set(CANDIDATE_LIB_HEADERS
    "candidate.h"
    )

add_library(${CANDIDATE_LIB}
            ${CANDIDATE_LIB_SOURCES}
            ${CANDIDATE_LIB_HEADERS})

target_include_directories(${CANDIDATE_LIB} PUBLIC 
                            "./"
                            )                           