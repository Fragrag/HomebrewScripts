# https://stackoverflow.com/questions/4764932/in-python-how-do-i-read-the-exif-data-for-an-image
# https://www.sno.phy.queensu.ca/~phil/exiftool/TagNames/EXIF.html
# Filename = 
# Camera model = 0xc614
# Focal length = 0x920a
# Aperture = 0x9202

# Dependencies
# csv, os, Pillow, sys

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


with open('output.csv', 'w') as csvfile: 		# Initialize and create new .csv
	header = ['Filename', 'Camera Model', 'Focal length', 'Aperture size']
	csvOutput = csv.DictWriter(csvfile, fieldnames=header, lineterminator='\n', delimiter=',')
	csvOutput.writeheader()
	print("")
	
	for item in os.listdir(TargetDirectory):	# Go through every .psd in folder
		if item.endswith(AcceptedFiles):
			# Open the image and create a dict
			OpenedImage = PIL.Image.open(TargetDirectory + "\\" + item)
			ExifDict = OpenedImage._getexif()
			
			# Read the exif data and pick out these things:
			# Filename, Camera Model, Focal Length, Aperture Size
			FileName = os.path.basename(item)
			CameraModel = ExifDict.get(0x0110)
			FocalLengthRaw = ExifDict.get(0x920a)
			ApertureSizeRaw = ExifDict.get(0x829d)
			
			# Convert to str and get the important strings
			FocalLength = str(FocalLengthRaw)[1:3] + "mm"
			ApertureSize = "f/" + str(ApertureSizeRaw)[1:4] 
			
			print(FileName)
			print(CameraModel)
			print(FocalLength)
			print(ApertureSize)
			print("")
			
			csvOutput.writerow({'Filename': FileName, 'Camera Model': CameraModel, 'Focal length': FocalLength, 'Aperture size': ApertureSize})
