project('bbexample', 'cpp',
        version : '0.0.1')

# Include Directories

incdir = include_directories(
  'inc'
)

srcfiles = files(
  #'bbfunction1.cpp',
  #'bbfunction2.cpp',
  #'bbfunction3.cpp',
  #'bbfunction4.cpp',
  #'bbfunction5.cpp',
  #'bbfunction6.cpp',
  #'bbfunction7.cpp',
  #'bbfunction8.cpp',
  #'bbfunction9.cpp',
  #'bbfunction10.cpp',
)

# Find the dependency modules, if not found use meson wrap to get them
# automatically during the configure step
_dependencies = []

nlohmann_json = dependency('nlohmann_json', version: '>=3.9.2', required: false, include_type: 'system')
if not nlohmann_json.found()
    nlohmann_json_proj = subproject('nlohmann_json', required: true)
    nlohmann_json = nlohmann_json_proj.get_variable('nlohmann_json_dep')
    nlohmann_json = nlohmann_json.as_system('system')
endif
_dependencies += nlohmann_json

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
  dependencies: _dependencies,
)
