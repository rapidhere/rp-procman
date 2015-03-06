PROJECT(rp-procman)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

# compile WITH `qt-widget` or `qt-qml`
SET(RPM_CompileWith qt-widget)

# set debug or not
SET(RPM_Debug True)

# set the version
SET(RPM_VersionMajor 0)
SET(RPM_VersionMinor 1)

# Don't change these
# complie as qt-widget version
IF(${RPM_CompileWith} STREQUAL qt-widget)
    EXECUTE_PROCESS(COMMAND echo "## Compile with qt-widget")

    # set debug in defines
    IF(${RPM_Debug})
        EXECUTE_PROCESS(COMMAND echo "## Debug flag on")
        ADD_DEFINITIONS(-D_DEBUG)
    ELSE()
        EXECUTE_PROCESS(COMMAND echo "## Debug flag off")
    ENDIF()

    # tell to source code to use qt-widgets part
    ADD_DEFINITIONS(-D_RPM_QT_WIDGET_VERSION)

    # include qt widget cmake package
    SET(Qt5Widgets_DIR /usr/local/Qt-5.3.1/lib/cmake/Qt5Widgets)
    FIND_PACKAGE(Qt5Widgets)

    # set the include dirs and definitions, add compile flag for qt5
    INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
    ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

    # configure version in ./src/defs.h
    CONFIGURE_FILE(./src/defs.h ./src/defs.h)

	# load
	INCLUDE_DIRECTORIES(./src)

    # compile ./src/widgets
    AUX_SOURCE_DIRECTORY(./src/widgets RPM_Sources)

    # add moc files
    FILE(GLOB RPM_WidgetHeaders ./src/widgets/*.h)
    QT_WRAP_CPP(rp-procman RPM_Sources ${RPM_WidgetHeaders})

    # compile ./src/proc
    AUX_SOURCE_DIRECTORY(./src/proc RPM_Sources)

    # add main.cpp to sources
    SET(RPM_Sources ${RPM_Sources} ./src/main.cpp)

    ADD_EXECUTABLE(rp-procman ${RPM_Sources})

	# link
	TARGET_LINK_LIBRARIES(rp-procman Qt5::Widgets)
# compile as qt-qml version
ELSEIF(${RPM_CompileWith} STREQUAL qt-qml)
    EXECUTE_PROCESS(COMMAND echo "## Compile with qt-qml")
    EXECUTE_PROCESS(COMMAND echo "## Currently simply do nothing")
    # Do nothing
# error
ELSE()
    EXECUTE_PROCESS(COMMAND echo "## Wrong value with RP_PROCMAN_COMPILE_WITH: ${RP_PROCMAN_COMPILE_WITH}")
ENDIF()
