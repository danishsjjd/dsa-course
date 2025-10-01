add_library(dsa_core STATIC
  Array.cpp
)

target_include_directories(dsa_core PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

# Consumers link both header-only 'dsa' (for includes) and 'dsa_core' (for compiled sources).
