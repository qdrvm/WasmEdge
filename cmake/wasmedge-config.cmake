
set(WASMEDGE_SHARED_LIB "${WASMEDGE_ROOT}/lib/libwasmedge.${CMAKE_SHARED_LIBRARY_SUFFIX}")
set(WASMEDGE_STATIC_LIB "${WASMEDGE_ROOT}/lib/libwasmedge.${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(WASMEDGE_STATIC_LIB_DEBUG "${WASMEDGE_ROOT}/lib/libwasmedged.${CMAKE_STATIC_LIBRARY_SUFFIX}")

if (EXISTS "${WASMEDGE_SHARED_LIB}")
  add_library(WasmEdge::WasmEdge SHARED IMPORTED)
  set_property(TARGET WasmEdge::WasmEdge PROPERTY IMPORTED_LOCATION "${WASMEDGE_SHARED_LIB}")

elseif(EXISTS "${WASMEDGE_STATIC_LIB_DEBUG}" AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  add_library(WasmEdge::WasmEdge STATIC IMPORTED)
  set_property(TARGET WasmEdge::WasmEdge PROPERTY IMPORTED_LOCATION "${WASMEDGE_STATIC_LIB_DEBUG}")
    
elseif(EXISTS "${WASMEDGE_STATIC_LIB}")
  add_library(WasmEdge::WasmEdge STATIC IMPORTED)
  set_property(TARGET WasmEdge::WasmEdge PROPERTY IMPORTED_LOCATION "${WASMEDGE_STATIC_LIB}")
  
else()
  message(FATAL_ERROR "WasmEdge not found in ${WASMEDGE_ROOT}!")
  message(FATAL_ERROR "Tried:")
  message(FATAL_ERROR " - ${WASMEDGE_SHARED_LIB}")
  message(FATAL_ERROR " - ${WASMEDGE_STATIC_LIB}")
  message(FATAL_ERROR " - ${WASMEDGE_STATIC_LIB_DEBUG}")
endif()

target_include_directories(WasmEdge::WasmEdge INTERFACE "${WASMEDGE_ROOT}/include")
target_link_libraries(WasmEdge::WasmEdge INTERFACE curses)
if(APPLE)
  target_link_libraries(WasmEdge::WasmEdge INTERFACE xar)
endif()
