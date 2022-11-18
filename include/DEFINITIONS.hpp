#pragma once
#include <string>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <iomanip>

#define LFC1_LOG_TRACE(logger)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define LOG                                                                        \
  BOOST_LOG_TRIVIAL(info) << "[" << __FILENAME__ << " | Line: " << __LINE__ << "]" \
                          << std::setw(30) << std::left

#define VIDEOMODE_WIDTH 800
#define VIDEOMODE_HEIGHT 600
#define HALF_WIN_SIZE 2

#define GRAVITY 4.f
#define MOVE_RIGHT 0.1f
#define MOVE_LEFT 0.1f
#define JUMP 2.f
#define MOVE_DOWN 0.1f
#define MOVE_SPEED_ALL 15.f

#define PLAYER_SIZE 60.f
#define WIDTH_OFFSET 10