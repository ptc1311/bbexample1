project('bbexample1', 'cpp',
        version : '0.0.1',
        meson_version: '>=0.63.0',
        default_options: [
            'cpp_std=c++20',
            ]
        )

# Validate the c++ Standard

# Get compiler and default build type

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

sdbusplus = dependency('sdbusplus', required : false, include_type: 'system')
sdbusplus = dependency('sdbusplus', required : true, include_type: 'system', fallback: ['sdbusplus', 'sdbusplus_dep'])
if not sdbusplus.found()
  sdbusplus_proj = subproject('sdbusplus', required: true)
  sdbusplus = sdbusplus_proj.get_variable('sdbusplus_dep')
  sdbusplus = sdbusplus.as_system('system')
endif
_dependencies += sdbusplus

#ERROR: Dependency lookup for systemd with method 'pkgconfig' failed: Pkg-config binary for machine 1 not found. Giving up.
systemd = dependency('systemd')
#zlib = dependency('zlib')
_dependencies += systemd


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
    include_directories : incdir,
    dependencies: _dependencies,
)

executable(
  'bbexample1',
  'bbexample.cpp',
  include_directories : incdir,
  link_with: bblib,
  dependencies: _dependencies,
  install: true,
  install_dir: '/usr/bin'
)
