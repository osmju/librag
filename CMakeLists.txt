cmake_minimum_required(VERSION 2.6)

# Parameters
# ==========

set(project_name "LibRAG")      					## change project name here
set(library_name "rag")  
set(CECI OFF)   			

#set(INSTALL_PATH_INCLUDE "/home/josmalskyj/libs/rag")
#set(INSTALL_PATH_LIB "/home/josmalskyj/libs/rag/lib")

#set(INSTALL_PATH_INCLUDE "/home/josmalskyj/libs/rag" CACHE STRING "Set the include install path" FORCE)
#set(INSTALL_PATH_LIB "/home/josmalskyj/libs/rag/lib" CACHE STRING "Set the library .so or .dylib install path" FORCE)

set(INSTALL_PATH_INCLUDE "/Users/osmju/libs/rag" CACHE STRING "Set the include install path" FORCE)
set(INSTALL_PATH_LIB "/Users/osmju/libs/rag/lib" CACHE STRING "Set the library .so or .dylib install path" FORCE)

if (CECI)
    message("CECI Cluster")    
    set(BOOST_ROOT              "/home/ulg/INTELSIG/osmju/lib/boost/")
    set(BOOST_INCLUDEDIR        "/home/ulg/INTELSIG/osmju/lib/boost/include/")    
    set(INSTALL_PATH_INCLUDE    "/home/ulg/INTELSIG/osmju/lib/rag")
    set(INSTALL_PATH_LIB       "/home/ulg/INTELSIG/osmju/lib/rag/lib")
endif()



# Project name
# ============

project(${project_name})

# Settings
# ========

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
set(EXECUTABLE_OUTPUT_PATH bin)

if (APPLE)
    add_definitions(-DSYSTEM_OSX)
endif (APPLE)

# Packages
# ========

find_package(Boost REQUIRED)
find_package(LibXml2 REQUIRED)

add_definitions(${LIBXML2_DEFINITIONS})

# Files
# =====

include_directories(   
	SYSTEM
	${Boost_INCLUDE_DIRS}    
    ${LIBXML2_INCLUDE_DIR}	
)

include_directories(
	include
)

file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/src/*.cpp)   # sources are in src/
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)         # includes are in include/
file(GLOB mains ${PROJECT_SOURCE_DIR}/src_mains/*.cpp)       # main files are in src_mains/
file(GLOB tests ${PROJECT_SOURCE_DIR}/tests/*.cpp)           # test src files are in tests/

# Libraries
# =========

# This creates a library with the compiled sources. The library can next be linked to the
# executables binaries.

add_library(
    ${library_name}
    SHARED
    ${sources}
)

# This sets libraries to be used to compile the executable binaries.

target_link_libraries(
    ${library_name}  
    ${Boost_LIBRARIES}  
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}      
    ${LIBXML2_LIBRARIES}
)  

# Executables mains
# =================

foreach (EXE ${mains})
    string(FIND ${EXE} "/" EXE_SUB_START REVERSE)
    string(FIND ${EXE} ".cpp" EXE_SUB_STOP REVERSE)
    math(EXPR EXE_SUB_START ${EXE_SUB_START}+1)
    math(EXPR EXE_SUB_LENGTH ${EXE_SUB_STOP}-${EXE_SUB_START})
    string(SUBSTRING ${EXE} ${EXE_SUB_START} ${EXE_SUB_LENGTH} EXE_NAME)    
    
    add_executable(
    	${EXE_NAME}
    	${EXE}	
    	${headers}
    )

    target_link_libraries(
       	${EXE_NAME}
        ${library_name}              
    )
endforeach (EXE ${mains})

# Executables tests
# =================

foreach (EXE ${tests})
    string(FIND ${EXE} "/" EXE_SUB_START REVERSE)
    string(FIND ${EXE} ".cpp" EXE_SUB_STOP REVERSE)
    math(EXPR EXE_SUB_START ${EXE_SUB_START}+1)
    math(EXPR EXE_SUB_LENGTH ${EXE_SUB_STOP}-${EXE_SUB_START})
    string(SUBSTRING ${EXE} ${EXE_SUB_START} ${EXE_SUB_LENGTH} EXE_NAME)
    
    add_executable(
    	${EXE_NAME}
    	${EXE}	
    	${headers}
    )
    
    target_link_libraries(
       	${EXE_NAME}
        ${library_name}          
    )
endforeach (EXE ${mains})

# Compiler flags
# ==============

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()    


if (CMAKE_COMPILER_IS_GNUCXX)
    # Flags for debug
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg")
	list(APPEND CMAKE_CXX_FLAGS "-std=c++0x -fPIC ${CMAKE_CXX_FLAGS}")
endif()

# Installation
# ============

INSTALL(DIRECTORY include DESTINATION ${INSTALL_PATH_INCLUDE})

if (APPLE)	
	INSTALL(FILES build/librag.dylib DESTINATION ${INSTALL_PATH_LIB})
elseif (UNIX)
	INSTALL(FILES build/librag.so DESTINATION ${INSTALL_PATH_LIB})
endif ()

