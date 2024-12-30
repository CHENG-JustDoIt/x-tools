﻿set(X_TOOLS_THIRD_PARTY_DIR ${CMAKE_CURRENT_LIST_DIR}/../thirdparty)
# --------------------------------------------------------------------------------------------------
# Qt-Advanced-Stylesheets-main：https://github.com/githubuser0xFFFF/Qt-Advanced-Stylesheets
set(X_TOOLS_STYLES_DIR_NAME "Qt-Advanced-Stylesheets-main")
if(ANDROID OR IOS)
  option(X_TOOLS_ENABLE_MODULE_STYLE_SHEET "Enable Qt advanced stylesheet" OFF)
else()
  option(X_TOOLS_ENABLE_MODULE_STYLE_SHEET "Enable Qt advanced stylesheet" ON)
endif()
if(X_TOOLS_ENABLE_MODULE_STYLE_SHEET)
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${X_TOOLS_STYLES_DIR_NAME}.zip
                  WORKING_DIRECTORY ${X_TOOLS_THIRD_PARTY_DIR})
  include_directories(${X_TOOLS_THIRD_PARTY_DIR}/${X_TOOLS_STYLES_DIR_NAME}/src)
  add_compile_definitions(ACSS_STATIC)
  add_compile_definitions(X_TOOLS_ENABLE_MODULE_STYLE_SHEET)
endif()

function(x_tools_add_style_sheet_resources target)
  add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND
      ${CMAKE_COMMAND} -E copy_directory_if_different
      "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../thirdparty/${X_TOOLS_STYLES_DIR_NAME}/styles"
      "$<TARGET_FILE_DIR:${target}>/3rd_styles" "||" ${CMAKE_COMMAND} -E true
    COMMENT "Copy style resources for ${target}...")
endfunction()

function(x_tools_add_stylesheet_sources target)
  if(NOT X_TOOLS_ENABLE_MODULE_STYLE_SHEET)
    return()
  endif()
  set(SOURCE_PATH ${X_TOOLS_THIRD_PARTY_DIR}/${X_TOOLS_STYLES_DIR_NAME}/src)
  list(APPEND STYLESHEET_SOURCE ${SOURCE_PATH}/acss_globals.h)
  list(APPEND STYLESHEET_SOURCE ${SOURCE_PATH}/QtAdvancedStylesheet.h)
  list(APPEND STYLESHEET_SOURCE ${SOURCE_PATH}/QtAdvancedStylesheet.cpp)
  target_sources(${target} PRIVATE ${STYLESHEET_SOURCE})
endfunction()

function(x_tools_setup_stylesheet target)
  if(NOT X_TOOLS_ENABLE_MODULE_STYLE_SHEET)
    return()
  endif()

  x_tools_add_style_sheet_resources(${target})
  x_tools_add_stylesheet_sources(${target})
endfunction()

function(x_tools_add_xlsx)
  set(xlsx "QXlsx-1.4.7")
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${xlsx}.zip
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/${xlsx}/QXlsx/header)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/${xlsx}/QXlsx)
endfunction()
