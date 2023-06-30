cmake_minimum_required(VERSION 3.5)
project(HelloApp
        VERSION 0.0.1
        DESCRIPTION  "The leading Hello World App"
        LANGUAGES CXX)

        #alternative way for building executalbes -> ( DISCOURAGE by CMake designers)
        #file(GLOB_RECURSE SRC_FILES src/*.cpp)
        #add_executable(HelloBinary main.cpp ${SRC_FILES})

include(FetchContent)        
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)



add_executable(HelloAppBinary 
                main.cpp 
                src/dog.cpp 
                src/operations.cpp)

                
add_executable(my_tests test/test_example.cpp)  
target_link_libraries(my_tests PRIVATE gtest_main)   

#set_target_properties(my_tests PROPERTIES LINK_FLAGS "/NODEFAULTLIB:libcmtd.lib")
#set_target_properties(my_tests PROPERTIES LINK_FLAGS "/NODEFAULTLIB:libcpmtd.lib")
#set_target_properties(my_tests PROPERTIES LINK_FLAGS "/NODEFAULTLIB:msvcprtd.lib")





target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
target_include_directories(HelloAppBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include) 

        