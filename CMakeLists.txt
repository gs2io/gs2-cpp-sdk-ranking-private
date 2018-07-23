# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

cmake_minimum_required(VERSION 3.10)
project(gs2-cpp-sdk-ranking-private)

set(CMAKE_CXX_STANDARD 11)

include_directories(../src)
include_directories(../gs2-cpp-sdk-core/src)
include_directories(../gs2-cpp-sdk-ranking/src)
include_directories(src)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES
        src/*.cpp)

#add_library(${PROJECT_NAME}
#        ${${PROJECT_NAME}_SOURCE_FILES})
#
#target_link_libraries(${PROJECT_NAME}
#        gs2_cpp_sdk_ranking)

# add_subdirectory(test)
