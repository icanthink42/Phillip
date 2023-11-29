#! /bin/sh

arduino-cli compile --fqbn arduino:samd:mkrzero --upload -p /dev/ttyACM0
