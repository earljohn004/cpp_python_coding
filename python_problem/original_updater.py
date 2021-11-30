#
# Refactored original source code
# --------------------------------------------------------
# Created November 2021,
# @author Earl John Abaquita (earl.abaquita@outlook.com)
# 
# Description:
#    Contains the refactored original source code to modify SConstruct file
#    and VERSION file
#    SConstruct value, get from BuildNum global variable
#    VERSION value, get from BuildNum global variable
# 

import os
import re

# get the SourcePath environment variable
# chmod 775 ${SourcePath}/develop/global/src/SContruct 
def updateSconstruct():
    "Update the build number in the SConstruct file"
    os.chmod(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"), 775)     # change permission of SConstructFile 
    fin = open(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"), 'r')   # open file for read
    fout = open(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct1"), 'w') # create SConstruct1 file for write

    #Traverse file and search for the string example point=1234
    for line in fin:
       line=re.sub("point\=[\d]+","point="+os.environ["BuildNum"],line)
       fout.write(line)

    fin.close()
    fout.close()
    os.remove(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct")) # Remove SConstruct file
    os.rename(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct1"), 
            os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"))   # Rename SConstruct1 to SConstruct


# VERSION file interesting line
# ADLMSDK_VERSION_POINT=6 
def updateVersion():
    "Update the build number in the VERSION file"
    os.chmod(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"), 775)     # Change permission of VERSION file 
    fin = open(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"), 'r')   # open VERSION file for read
    fout = open(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION1"), 'w') # create VERSION1 file as output

    #Traverse file and search for the string example ADLMSDK_VERSION_POINT=12345
    for line in fin:
        line=re.sub("ADLMSDK_VERSION_POINT\=[\d]+","ADLMSDK_VERSION_POINT="+os.environ["BuildNum"],line) #Change the ADLMSDK_VERSION_POINT value with ENV Variable BuildNum value
        fout.write(line)

    fin.close()
    fout.close()
    os.remove(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"))  # Remove VERSION file
    os.rename(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION1"), # Rename VERSION1 file to VERSION
        os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"))


def main():
    updateSconstruct()
    updateVersion()


main()
