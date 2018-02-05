import csv, os

ItemExtensions = '.mp4', '.avi', '.mkv'
TargetDirectory = 'D:\Videos'

for item in os.listdir(TargetDirectory):	
	if item.endswith(ItemExtensions):
		itemLocation = os.path.join(TargetDirectory, item)
		print(os.path.join(TargetDirectory, item))
		
		os.system("ffmpeg -i \"" + os.path.join(TargetDirectory, item) + "\" -f ffmetadata metadata.txt")
	else:
		print("does not end in " + itemExtensions)
