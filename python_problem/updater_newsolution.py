#
# Modified solution
# --------------------------------------------------------
# Created November 2021,
# @author Earl John Abaquita (earl.abaquita@outlook.com)
# 
# Description:
#    Contains my new solution to the problem 
#    SConstruct value, get from BuildNum global variable
#    VERSION value, get from BuildNum global variable
# 

import os
import subprocess
import re

#Set here the SConstruct Filename
sconstruct_filename = "SConstruct"

#Set here the VERSION filename
version_filename = "VERSION"

#Dynamic location to be search for these files
parent_directory = "."

def updateSconstruct():
    location = subprocess.run(['find', parent_directory, '-name', sconstruct_filename, '-type', 'f'], capture_output=True, text=True) #Locate the filename from the directory specified above
    build_num = os.environ['BuildNum'].rstrip('\n')         #Get the version number from ENV variables
    newstring = 's/point\=[0-9]*/point='+build_num+'/g'

    # sed command in macOS needs extra parameter after -i flag
    process = subprocess.run(['sed','-i','',newstring, location.stdout.rstrip("\n")], capture_output=True, text=True)
    if process.returncode==0:
        print("Successfully updated " + location.stdout.rstrip("\n") + " to version " + build_num)
    else:
        print(process.stderr)


def updateVersion():
    location = subprocess.run(['find', parent_directory, '-name', version_filename, '-type', 'f'], capture_output=True, text=True)
    build_num = os.environ['BuildNum'].rstrip('\n')         #Get the version number from ENV variables
    newstring = 's/ADLMSDK_VERSION_POINT\=[0-9]*/ADLMSDK_VERSION_POINT='+build_num+'/g'

    # sed command in macOS needs extra parameter after -i flag
    process = subprocess.run(['sed','-i','',newstring, location.stdout.rstrip("\n")], capture_output=True, text=True)
    if process.returncode==0:
        print("Successfully updated " + location.stdout.rstrip("\n") + " to version " + build_num)
    else:
        print(process.stderr)

def main():
    updateSconstruct()
    updateVersion()

main()
