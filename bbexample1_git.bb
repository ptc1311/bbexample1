# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=96af5705d6f64a88e035781ef00e98a8 \
                    file://subprojects/nlohmann_json-3.11.2/LICENSE.MIT;md5=f969127d7b7ed0a8a63c2bbeae002588"

DEPENDS = " \
    sdbusplus \
    nlohmann-json \
"


SRC_URI = "git://github.com/ptc1311/bbexample1.git;protocol=https;branch=master"

# Modify these as desired
PV = "1.0+git"
SRCREV = "948945601ef59ca53ea4d32c7c1977f28b66f597"

S = "${WORKDIR}/git"

# NOTE: no Makefile found, unable to determine what needs to be done

inherit systemd
inherit pkgconfig meson
