cmake_minimum_required(VERSION 3.15)
project(easily)

set(CMAKE_CXX_STANDARD 17)

add_executable(easily main.cpp CommandLine.cpp CommandLine.h WebServer.cpp WebServer.h BlockingListener.cpp BlockingListener.h BlockingChannel.cpp BlockingChannel.h SystemError.cpp SystemError.h Request.cpp Request.h RequestHandler.cpp RequestHandler.h Response.cpp Response.h Logger.cpp Logger.h)