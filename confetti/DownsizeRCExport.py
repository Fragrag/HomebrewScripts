# DownsizeRCExport.py                                                    
#
# This script goes through images in a folder
# and downscales them to 20% of the original image size
# And overwrites the original file in the same location
# To repeat for clarity:
# THIS WILL OVERWRITE THE ORIGINAL FILE
# 
# Usage:																 
# python DownsizeRCExport.py "<FOLDER>"
# Dependencies: os, sys, Pillow

import os
import sys
import PIL.Image

# Parse commandline argument
try:
	InputDirectory = sys.argv[1]
	assert InputDirectory
except:
	print("Please specify an input folder")
	sys.exit(1)

	
AcceptedFiles = '.jpg', '.jpeg', '.png'

for item in os.listdir(InputDirectory):
	if item.endswith(AcceptedFiles):
		# Load image with Pillow
		OpenedImage = PIL.Image.open(InputDirectory + "\\" + item)
		
		# Set variables
		OpenedImageWidth, OpenedImageHeight = OpenedImage.size 
		OpenedImageFilename, OpenedImageFileExtension = os.path.splitext(InputDirectory + "\\" + item)
		
		# Resize the image to 20% original size
		OpenedImage.thumbnail([OpenedImageWidth/5, OpenedImageHeight/5]) 
		
		# If image is png, save it with optimisation to push the size down further
		if OpenedImageFileExtension == '.png': 
			OpenedImage.save(OpenedImageFilename + OpenedImageFileExtension, 'png', optimize=True)
			
		# If image is jpg/jpeg, save it as is
		elif OpenedImageFileExtension == '.jpeg' or OpenedImageFileExtension == '.jpg':
			OpenedImage.save(OpenedImageFilename + OpenedImageFileExtension)
		# Error catching
		else:
			print("Not .png or .jpeg")
		
		# Close the image, clear it from the buffer and return a success message
		OpenedImage.close()
		print(item + " has been downsized!")
		
	# Error catching
	else:
		print("Not an image!")

# Print message the job is finished once the "for loop" is finished
print(" ")
print("All files in " + InputDirectory + " have been downsized")