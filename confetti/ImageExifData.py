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
	TargetDirectory = sys.argv[1]
	assert TargetDirectory
except:
	print("Please specify a folder")
	sys.exit(1)
	
AcceptedFiles = '.psd', '.cr2', '.jpg', '.jpeg', '.dng'

# Initialize and create new .csv
with open('output.csv', 'w') as csvfile: 		
	header = ['Filename', 'Camera Model', 'Focal length']
	csvOutput = csv.DictWriter(csvfile, fieldnames=header, lineterminator='\n', delimiter=',')
	csvOutput.writeheader()
	print("")
	
	for item in os.listdir(TargetDirectory):
		if item.endswith(AcceptedFiles):
			# Open the image and create a dict from the exif
			OpenedImage = PIL.Image.open(TargetDirectory + "\\" + item)
			ExifDict = OpenedImage._getexif()
			
			# Read the exif data and pick out these things:
			# Filename, Camera Model, Focal Length
			FileName = os.path.basename(item)
			CameraModel = ExifDict.get(0x0110)
			FocalLengthRaw = ExifDict.get(0x920a)
			
			# Convert raw values to string and get the important characters
			FocalLength = "{0[0]}".format(FocalLengthRaw) + "mm"
			
			# Print output for debugging
			print(FileName)
			print(CameraModel)
			print(FocalLength)
			print("")
			
			#Write the row in the csv
			csvOutput.writerow({'Filename': FileName, 'Camera Model': CameraModel, 'Focal length': FocalLength})
