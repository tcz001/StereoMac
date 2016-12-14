cmake_minimum_required(VERSION 2.8)
project( StereoMac )

# Barrel Distortion
add_subdirectory ( Barrel )

# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Apple framework
IF(APPLE)
   FIND_LIBRARY(APP_SERVICES_LIBRARY ApplicationServices )
   SET(EXTRA_LIBS ${APP_SERVICES_LIBRARY})
ENDIF (APPLE)

add_executable( DisplayStereo DisplayStereo.cpp )
target_link_libraries( DisplayStereo Barrel ${OpenCV_LIBS} ${EXTRA_LIBS} )
