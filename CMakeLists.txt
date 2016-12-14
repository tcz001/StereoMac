cmake_minimum_required(VERSION 2.8)
project( Stereo )
find_package( OpenCV REQUIRED )
# Apple framework
IF(APPLE)
   #SET(GUI_TYPE MACOSX_BUNDLE)
   INCLUDE_DIRECTORIES ( /Developer/Headers/FlatCarbon )
   FIND_LIBRARY(CARBON_LIBRARY Carbon)
   FIND_LIBRARY(QUICKTIME_LIBRARY QuickTime )
   FIND_LIBRARY(APP_SERVICES_LIBRARY ApplicationServices )
   MARK_AS_ADVANCED (CARBON_LIBRARY
                     QUICKTIME_LIBRARY
                     APP_SERVICES_LIBRARY)
   SET(EXTRA_LIBS ${CARBON_LIBRARY} ${QUICKTIME_LIBRARY} ${APP_SERVICES_LIBRARY})
ENDIF (APPLE)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp barrel_dist.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} ${EXTRA_LIBS} )
