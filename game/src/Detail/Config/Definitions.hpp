/**
 * @file src/Detail/Config/Definitions.hpp
 * @brief Data receive from cmake settings
 * @note Do not use clang-format here (@ broke it)
 *
 */

// @formatter:off

#pragma once

#include "Config/Macro.hpp"

#define PROJECT_NAME    "EpiGame"    /*!< @brief Name of the project */
#define PROJECT_VERSION "1.0.0" /*!< @brief Full Version as string */

#define PROJECT_VERSION_MAJOR 1 /*!< @brief Version Major */
#define PROJECT_VERSION_MINOR 0 /*!< @brief Version Minor */
#define PROJECT_VERSION_PATCH 0 /*!< @brief Version Patch */
#define PROJECT_VERSION_TWEAK  /*!< @brief Version Tweak */

#define PROJECT_BUILD_TYPE           RelWithDebInfo            /*!< @brief Build Type used */
#define PROJECT_BUILD_TYPE_AS_STRING AS_STRING(PROJECT_BUILD_TYPE) /*!< @brief Build Type as string */

// @formatter:on
