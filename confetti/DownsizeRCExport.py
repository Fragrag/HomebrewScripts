##########################################################################
#                                                                        #
# ImageExifData.py                                                       #
#                                                                        #
# This script goes through images in a folder	          				 #
# and returns the file's location, model and focal length to output.csv  #      
#                                                                        #
##########################################################################
# EXIF Tags reference: https://www.sno.phy.queensu.ca/~phil/exiftool/TagNames/EXIF.html
# Dependencies: csv, os, sys, Pillow

import csv
import os
import sys
import PIL.Image

try:
	InputDirectory = sys.argv[1]
	assert InputDirectory
except:
	print("Please specify an input folder")
	sys.exit(1)

	
AcceptedFiles = '.psd', '.cr2', '.jpg', '.jpeg', '.dng', '.png'

for item in os.listdir(InputDirectory):
	if item.endswith(AcceptedFiles):
		# Open the image and create a dict from the exif
		OpenedImage = PIL.Image.open(InputDirectory + "\\" + item)
		PIL.Image.save( "C:\\Users\\User\\Desktop\\RCDownSize\\" + OpenedImage, 'jpeg', quality=50)
		PIL.Image.close(OpenedImage)