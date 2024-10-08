# ==============================================================================
# @file examples/CMakeLists.txt
# ==============================================================================

find_package(spdlog REQUIRED PATHS ${SPDLOG_HOME})

link_libraries(Yutils::Yutils)

# ==============================================================================
# ArgParser Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME ArgParserExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
yutils_log_info("${YUTILS_LOG_CYAN_CAT} Target: ${EXAMPLE_NAME}")
# ==============================================================================

# ==============================================================================
# Serializer Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME SerializerExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
# ==============================================================================

# ==============================================================================
# SimpleCSV Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME SimpleCSVExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
# ==============================================================================

# ==============================================================================
# Random Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME RandomExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
# ==============================================================================

# ==============================================================================
# Factory Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME FactoryExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
# ==============================================================================

# ==============================================================================
# ThreadPool Example
# ------------------------------------------------------------------------------
set(EXAMPLE_NAME ThreadPoolExample)
add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)
# ==============================================================================