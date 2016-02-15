cmake_minimum_required(VERSION 2.6)

# Parameters
# ==========

set(project_name "LibRAG")      					## change project name here
set(library_name "rag")  
set(CECI OFF)
   			
set(install_path_linux "/home/josmalskyj/libs/rag")
set(install_path_osx "/Users/osmju/libs/rag")

if (CECI)
    message("CECI Cluster")    
    set(BOOST_ROOT              "/home/ulg/INTELSIG/osmju/lib/boost/")
    set(BOOST_INCLUDEDIR        "/home/ulg/INTELSIG/osmju/lib/boost/include/")    
    set(install_path_linux      "/home/ulg/INTELSIG/osmju/lib/rag")
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

# Uncomment the following bloc if you need to link external libraries.

# Libraries
# =========

#link_directories(${PROJECT_SOURCE_DIR}/lib)

#if (APPLE)
#    link_directories(${PROJECT_SOURCE_DIR}/lib/osx)
#elseif (UNIX)
#    link_directories(${PROJECT_SOURCE_DIR}/lib/linux)
#endif ()

# Packages
# ========

find_package(Boost REQUIRED)
find_package(Boost COMPONENTS system filesystem iostreams program_options thread REQUIRED)
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

if (APPLE)
	INSTALL(DIRECTORY include DESTINATION ${install_path_osx})
	INSTALL(FILES build/librag.dylib DESTINATION ${install_path_osx}/lib)
elseif (UNIX)
	INSTALL(DIRECTORY include DESTINATION ${install_path_linux})
	INSTALL(FILES build/librag.so DESTINATION ${install_path_linux}/lib)
endif ()

