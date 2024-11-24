# CMakeList.txt : CMake project for in-memory-db, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (in-memory-db "in-memory-db.cpp"  "src/Db.cpp" "src/QueryProcessor.cpp" "src/Storage.cpp"  "src/Logger.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET in-memory-db PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_include_directories(in-memory-db PUBLIC ${PROJECT_SOURCE_DIR}/includes)

# Define paths for libraries based on the platform
if(WIN32)
    # Specify the paths to the libraries and includes for Windows
    set(LIB_PATH "C:/Users/chris/vcpkg/installed/x64-windows/lib")
    set(INCLUDE_PATH "C:/Users/chris/vcpkg/installed/x64-windows/include")
    set(BIN_PATH "C:/Users/chris/vcpkg/installed/x64-windows/bin")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.lib")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/iconv.lib")
    set(GTEST_LIB_PATH "${LIB_PATH}/gtest.lib")
    set(ZLIB_LIB_PATH "${LIB_PATH}/zlib.lib")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/boost_filesystem-vc143-mt-x64-1_85.lib")
    set(BOOST_MOVE_LIB_PATH "${LIB_PATH}/boost_move-vc143-mt-x64-1_85.lib") 

    # Link against Windows libraries
    target_link_libraries(in-memory-db PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
    )

    # Copy necessary files to the output directory
    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/in-memory-db/input" 
        $<TARGET_FILE_DIR:in-memory-db>/input
    )

    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/libxml2.dll" $<TARGET_FILE_DIR:in-memory-db>
    )
    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/liblzma.dll" $<TARGET_FILE_DIR:in-memory-db>
    )
    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/iconv-2.dll" $<TARGET_FILE_DIR:in-memory-db>
    )
    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Boost_LIBRARY_DIRS}/*.dll" $<TARGET_FILE_DIR:in-memory-db>
    )

    # Enable Google Test
    enable_testing()

elseif(UNIX)  # This will match Linux/Unix systems
    # Specify the paths to the libraries and includes for UNIX
    set(LIB_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/lib")
    set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/include")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.so")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/libiconv.so")
    set(FMT_LIB_PATH "${LIB_PATH}/libfmt.so")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/libboost_filesystem.so")

    # Link against UNIX libraries
    target_link_libraries(in-memory-db PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
    )

    # Copy data.xml to the output directory
    add_custom_command(TARGET in-memory-db POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/in-memory-db/input" 
        $<TARGET_FILE_DIR:in-memory-db>/input
    )
endif()
