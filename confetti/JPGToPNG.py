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

AcceptedFiles = '.jpg', '.jpeg'

for item in os.listdir(InputDirectory):
	if item.endswith(AcceptedFiles):

		OpenedImage = PIL.Image.open(InputDirectory + "\\" + item)
		OpenedImageFilename, OpenedImageFileExtension = os.path.splitext(InputDirectory + "\\" + item)
		OpenedImage.save(OpenedImageFilename + ".png", 'png', optimize=True)
		OpenedImage.close()
		print(OpenedImageFilename + " has been converted!")