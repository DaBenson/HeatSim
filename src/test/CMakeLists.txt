find_package(GTest QUIET)

if(GTEST_FOUND)
  message("GTEST found, unit testing is enabled") 
  set(EXECUTABLE_OUTPUT_PATH ${HEATSIM_BINARY_DIR}/test)
  include_directories(${GTEST_INCLUDE_DIRS})

FIND_LIBRARY(GMOCK_LIBRARIES gmock
    HINTS
        $ENV{GMOCK_ROOT}
        ${GMOCK_ROOT}
		$ENV{GMOCK_ROOT}/make
        ${GMOCK_ROOT}/make
)
if(NOT DEFINED GMOCK_LIBRARIES)
	MESSAGE(SEND_ERROR "Google mock library path not Set to GMOCK_LIBRARIES")
endif()

find_path(GMOCK_INCLUDE_DIR gmock/gmock.h
    HINTS
        $ENV{GMOCK_ROOT}/include
        ${GMOCK_ROOT}/include
)
if(NOT DEFINED GMOCK_INCLUDE_DIR)
	MESSAGE(SEND_ERROR "Google mock include path not Set to GMOCK_INCLUDE_DIR")	
endif()	

  set(SRC_DIR ${HEATSIM_SOURCE_DIR}/src)
  include_directories(${SRC_DIR})

  add_executable(heatSimTest
      TersoffPotentialTest.cpp
      ${SRC_DIR}/TersoffPotential.cpp
      DispersionCurveWriterTest.cpp
      ${SRC_DIR}/DispersionCurveWriter.cpp
      DynamicalMatrixTest.cpp
      ${SRC_DIR}/DynamicalMatrix.cpp
      CoordinatesTest.cpp
      ${SRC_DIR}/Coordinates.cpp
      MatrixTest.cpp
      ${SRC_DIR}/Matrix.cpp
      ${SRC_DIR}/EigenvalueSolution.cpp  
  )
  target_link_libraries(heatSimTest ${GTEST_BOTH_LIBRARIES})
  target_link_libraries(heatSimTest ${LAPACK_LIBRARIES})
  

else()
  message(AUTHOR_WARNING "GTEST not found, unit testing not enabled") 
endif()
