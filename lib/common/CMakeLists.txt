# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2019-2022 Second State INC

hunter_add_package(fmt)
hunter_add_package(spdlog)

find_package(spdlog CONFIG REQUIRED)

wasmedge_add_library(wasmedgeCommon
  hexstr.cpp
  spdlog.cpp
  errinfo.cpp
  int128.cpp
)

target_link_libraries(wasmedgeCommon
  PUBLIC
  spdlog::spdlog
)

target_include_directories(wasmedgeCommon
  PUBLIC
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/include
)
