# Install script for directory: /home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/algorithms" TYPE FILE FILES
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/node.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/search.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/list.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/sort.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/tree.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/link_list.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/queue.h"
    "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/vector_op.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ubuntu/suliang_git/deep_learning_inference/test_algorithm/algorithms/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
