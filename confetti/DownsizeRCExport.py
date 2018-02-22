##########################################################################
#                                                                        #
# DownsizeRCExport.py                                                    #
#                                                                        #
# This script goes through images in a folder	          				 #
# and downscales them to 20% of the original image size  				 #
# And overwrites the original file in the same location					 #    
# To repeat for clarity:												 #
# THIS WILL OVERWRITE THE ORIGINAL FILE									 #
#                                                                        #
# Usage:																 #
# python DownsizeRCExport.py "<FOLDER>"									 #
##########################################################################
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

	
AcceptedFiles = '.jpg', '.jpeg', '.png'

for item in os.listdir(InputDirectory):
	if item.endswith(AcceptedFiles):
		OpenedImage = PIL.Image.open(InputDirectory + "\\" + item)
		
		OpenedImageWidth, OpenedImageHeight = OpenedImage.size
		OpenedImageFilename, OpenedImageFileExtension = os.path.splitext(InputDirectory + "\\" + item)
		
		OpenedImage.thumbnail([OpenedImageWidth/5, OpenedImageHeight/5])
		
		if OpenedImageFileExtension == '.png':
			OpenedImage.save(OpenedImageFilename + OpenedImageFileExtension, 'png', optimize=True)
			
		elif OpenedImageFileExtension == '.jpeg' or OpenedImageFileExtension == '.jpg':
			OpenedImage.save(OpenedImageFilename + OpenedImageFileExtension)
			
		else:
			print("Not .png or .jpeg")
		
		OpenedImage.close()
		print(item + " has been downsized!")
		
	else:
		print("Not an image!")

print(" ")
print("All files in " + InputDirectory + " have been downsized")