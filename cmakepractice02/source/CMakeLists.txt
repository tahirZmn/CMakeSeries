cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD_REQUIRED ON)                                     #Making sure the required standard is provided for every target (global declaration)
set(CMAKE_CXX_STANDARD 20)
set(GTEST_DIR path/to/googletest)


enable_testing()


project(HelloApp
        VERSION 0.0.1
        DESCRIPTION  "The leading Hello World App"
        LANGUAGES CXX)

        #alternative way for building executalbes -> ( DISCOURAGE by CMake designers)
        #file(GLOB_RECURSE SRC_FILES src/*.cpp)
        #add_executable(HelloBinary main.cpp ${SRC_FILES})

# TARGET _ 1

include_directories(${GTEST_SOURCE_DIR}/googletest)
add_subdirectory(${GTEST_SOURCE_DIR}/Googletest)


#target_compile_features(operations PUBLIC cxx_std_20)           #setting up the C++ standard for this particuler target(NOT nedded anymore(globally declared))
add_library(operations STATIC src/operations.cpp)                #creating a static library from operations.cpp file. name of the library: operations
target_include_directories(operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)   #providing the address of the header files to be included


#TARGET _ 2

#target_compile_features(logger PUBLIC cxx_std_20)              #setting up the C++ standard for this particuler target (NOT nedded anymore(globally declared))
add_library(logger STATIC logger/src/log.cpp)                   #creating a static library -> logger
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger/include)  # including heading files for this library


#TARGET _ 3

add_executable(HelloAppBinary 
                main.cpp 
                src/dog.cpp
                #src/log.cpp         ->Not needed anymore here , static library is made 
                #src/operations.cpp  -> becuase we make static library  of this file 
                )

#target_compile_features(HelloAppBinary PRIVATE cxx_std_20)     #setting up the C++ standard for this particuler target (NOT nedded anymore(globally declared))
target_include_directories(HelloAppBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(HelloAppBinary PUBLIC operations logger) #including the libraries ->HelloAppBinary will 
                                                               #PUBLICALLY depend on operations and logger libraries. (DEPENDENCIES)


add_executable(my_tests test/test_example.cpp)  
target_link_libraries(my_tests PRIVATE gtest gmock)                                                                 

        