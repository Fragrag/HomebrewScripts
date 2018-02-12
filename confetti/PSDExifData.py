# https://stackoverflow.com/questions/4764932/in-python-how-do-i-read-the-exif-data-for-an-image
# https://www.sno.phy.queensu.ca/~phil/exiftool/TagNames/EXIF.html
# Filename = 
# Camera model = 0xc614
# Focal length = 0x920a
# Aperture = 0x9202

import csv
import os
import sys
from PIL import Image
from PIL.ExifTags import TAGS

TargetDirectory = sys.argv[1]

# Pseudocode:

with open('output.csv', 'w') as csvfile: 		# Initialize and create new .csv
	# Define and create headers
	header = ['Filename', 'Camera Model', 'Focal length', 'Aperture size']
	csvOutput = csv.DictWriter(csvfile, fieldnames=header, lineterminator='\n', delimiter=',')
	csvOutput.writeheader()
	
	for item in os.listdir(TargetDirectory):	# Go through every .psd in folder
		if item.endswith('.psd'):
			# Read the exif data and pick out these things:
			# Filename, Camera Model, Focal Length, Aperture Size
			FileName = os.path.basename(item)
			CameraModel = TAGS[0xc614]
			FocalLength = TAGS[0x920a]
			ApertureSize = TAGS[0x9202]
			
			print(FileName)
			print(CameraModel)
			print(FocalLength)
			print(ApertureSize)
			
			csvOutput.writerow({'Filename': FileName, 'Camera Model': CameraModel, 'Focal length': FocalLength, 'Aperture size': ApertureSize})
