PROJECT(rp-procman)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

# compile WITH `qt-widget` or `qt-qml`
SET(RP_PROCMAN_COMPILE_WITH qt-widget)

# Don't change these
# complie as qt-widget version
IF(${RP_PROCMAN_COMPILE_WITH} STREQUAL qt-widget)
    EXECUTE_PROCESS(COMMAND echo "## Compile with qt-widget")

    # tell to source code to use qt-widgets part
    ADD_DEFINITIONS(-D_RPM_QT_WIDGET_VERSION)

    # include qt widget cmake package
    SET(Qt5Widgets_DIR /usr/local/Qt-5.3.1/lib/cmake/Qt5Widgets)
    FIND_PACKAGE(Qt5Widgets)

    # set the include dirs and definitions, add compile flag for qt5
    INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
    ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

	# load
	INCLUDE_DIRECTORIES(./src)
	INCLUDE_DIRECTORIES(./src/widgets)

	ADD_EXECUTABLE(rp-procman ./src/main.cpp ./src/widgets/Application.cpp)

	# link
	TARGET_LINK_LIBRARIES(rp-procman Qt5::Widgets)
# compile as qt-qml version
ELSEIF(${RP_PROCMAN_COMPILE_WITH} STREQUAL qt-qml)
    EXECUTE_PROCESS(COMMAND echo "## Compile with qt-qml")
    EXECUTE_PROCESS(COMMAND echo "## Currently simply do nothing")
    # Do nothing
# error
ELSE()
    EXECUTE_PROCESS(COMMAND echo "## Wrong value with RP_PROCMAN_COMPILE_WITH: ${RP_PROCMAN_COMPILE_WITH}")
ENDIF()
