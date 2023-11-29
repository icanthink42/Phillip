#! /bin/sh

arduino-cli compile --fqbn arduino:samd:mkrzero --upload -p /dev/ttyACM0 && arduino-cli monitor -p /dev/ttyACM0
