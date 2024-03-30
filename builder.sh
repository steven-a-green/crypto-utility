#!/bin/bash

set -e

# Read the ID from /etc/os-release and print OS info
get_os_info() {
    OS=$(grep -oP '(?<=^ID=).+' /etc/os-release | tr -d '"')}

    case $OS in
    'rhel')
        echo "This is a RHEL machine."
        ;;
    'ubuntu')
        echo "This is an Ubuntu machine."
        ;;
    *)
        echo "This machine is running an operating system I don't recognize."
        ;;
    esac
}
#TODO: will make a debian/rpm file if one of these platforms and then tarball the package

# Color your script output
colorize_output() {
    local txtund=$(tput sgr 0 1) # Underline
    local txtbld=$(tput bold)    # Bold
    local txtred=$(tput setaf 1) # Red
    local txtgrn=$(tput setaf 2) # Green
    local txtylw=$(tput setaf 3) # Yellow
    local txtblu=$(tput setaf 4) # Blue
    local txtpur=$(tput setaf 5) # Purple
    local txtcyn=$(tput setaf 6) # Cyan
    local txtwht=$(tput setaf 7) # White
    local txtrst=$(tput sgr0)    # Text reset
}

#make the functions to funnel in the varibales in front of function arguements
red() {
    echo "${txtred}$1${txtrst}"
}
green() {
    echo "${txtgrn}$1${txtrst}"
}
blue() {
    echo "${txtblu}$1${txtrst}"
}

cyan() {
    echo "${txtcyn}$1${txtrst}"
}

yellow() {
    echo "${txtylw}$1${txtrst}"
}

purp() {
    echo "${txtpur}$1${txtrst}"
}

# Command line arguments parsing examples
get_user_input() {
    menu() {
        echo "
        1) option1              3) option3
        2) option2              4) option4"
    }

    PS3='Please enter the number of your choice: '
    options=("single user add" "bulk add" "delete user" "print list of user UIDs" "print ldap search" "exit")
    select opt in "${options[@]}"
    do
    case $opt in
        "option1"|"option2"|"option3"|"option4")
        menu
        ;;
        "exit")
        exit
        ;;
        *)
        echo "Invalid option $REPLY"
        menu
        ;;
    esac
    done

    # Verify previous command was successful
    if [ $? -ne 0 ]; then
    echo "The command was not successful."
    # Handle failure
    fi
}

cd src
make clean
make
