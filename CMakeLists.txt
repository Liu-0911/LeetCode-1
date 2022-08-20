cmake_minimum_required(VERSION 3.21)
project(Leetcode)

set(CMAKE_CXX_STANDARD 20)


# 将指定目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径。
include_directories("${PROJECT_BINARY_DIR}")

# GLOB 会产生一个由所有匹配globbingexpressions的文件组成的列表，并将其保存到变量中
# file(GLOB_RECURSE variable [RELATIVE path] [FOLLOW_SYMLINKS] [globbingexpressions]...)
# GLOB_RECURSE 与GLOB类似，区别在于它会遍历匹配目录的所有文件以及子目录下面的文件。对于属于符号链接的子目录，只有FOLLOW_SYMLINKS指定一或者cmake策略CMP0009没有设置为NEW时，才会遍历这些目录。
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/editor/cn/*.cpp")
file(GLOB mains2 "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
# foreach相当于python的for(a in b)
# foreach(<loop_var> IN [LISTS [<lists>]] [ITEMS [<items>]])
# LISTS可以认为是一个有名的集合，如set(A B C D) 会将ABCD都当成单独的集合
# ITEMS可以认为是一个匿名的集合，如a b c  会将abd作为一个整体当作一个集合（此时abd分别是一个变量，而不是集合）
foreach(mainfile IN LISTS mains mains2)
    # Get file name without directory
    # 1.get filename component(<var> <FileName> <mode> [CACHE])
    #<var>:保存获取部分的变量
    #<FileName>:壳整的文件名
    #<mode>：要获取文件名的哪个部分。包括
    #       DIRECTORY:文件所在目录
    #       NAME:没有目录的反件名
    #       EXT:最因的扩展名，即第一个.开始
    #       NAME_WE:没有目录和扩展名的文件名
    #       LAST_EXT:最后一个扩展名
    #       NAME_WLE:没有目录和最后一个扩展名的文件名
    #       PATH:同DIRECTORY,已过时，用于<=2.8.11版本
    #       CACHE:如指定，则获取得到的结果变量会放到缓存中
    get_filename_component(mainname ${mainfile} NAME_WE)
    message("${mainname} ${mainfile}")
    add_executable(${mainname} ${mainfile})
endforeach()
message("-----------------------------")
