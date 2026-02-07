cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_PACKAGE_BUILDENV_INSTALL_FOLDER}/cmake/build_environment.cmake)
project(ArieoEngine)

arieo_engine_project(
    arieo_scripting_interface
    ALIAS arieo::interface::script
    ROOT_NAMESPACE Arieo::Interface::Script
    SCRIPT_PACKAGE_NAME arieo:script
    PROJECT_TYPE interface
    PUBLIC_INCLUDE_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/public/include
    INTERFACES
        arieo::interface::main
    AST_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/ast
    NATIVE_CODE_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/native
    WASM_WIT_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/wasm/wit
    WASM_CXX_SCRIPT_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/wasm/cxx
    WASM_CSHARP_SCRIPT_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/wasm/csharp
    WASM_RUST_SCRIPT_GENERATE_FOLDER
        ${CMAKE_CURRENT_SOURCE_DIR}/_generated/wasm/rust
)