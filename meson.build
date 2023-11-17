project('bbexample', 'cpp',
        version : '0.0.1')

# Include Directories

incdir = include_directories(
  'inc'
)

srcfiles = files(
  #'bbfunction1.c',
  #'bbfunction2.c',
  #'bbfunction3.c',
  #'bbfunction4.c',
  #'bbfunction5.c',
  #'bbfunction6.c',
  #'bbfunction7.c',
  #'bbfunction8.c',
  #'bbfunction9.c',
  #'bbfunction10.c',
)

# 副程式庫
bblib = static_library(
    'bblib',
    srcfiles,
    include_directories : incdir,)

executable(
  'bbexample1',
  'bbexample.cpp',
  include_directories : incdir,
  link_with: bblib,
)
