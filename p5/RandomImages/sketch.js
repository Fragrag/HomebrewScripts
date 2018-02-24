var LoadedDigits;

function preload(){
	LoadedDigits = loadStrings('digits.txt');
}

function setup() {
	createCanvas(300, 300);
	frameRate(1/5);
	print(LoadedDigits);
}

function draw(){
	CreateImage(LoadedDigits);
}

function CreateImage(NumberArray) {
	var img = createImage(100, 100);
	img.loadPixels();
	for (var i = 0; i < img.width; i++){
		for (var j = 0; j < img.height; j++){
			
			var RRand = abs(round(random(NumberArray.length -1)));
			var GRand = abs(round(random(NumberArray.length -1)));
			var BRand = abs(round(random(NumberArray.length -1)));
			
			var R = map(NumberArray[RRand], 0, 99999, 0, 256);
			var G = map(NumberArray[GRand], 0, 99999, 0, 256);
			var B = map(NumberArray[BRand], 0, 99999, 0, 256);
			
			print(RRand);
			print(GRand);
			print(BRand);
			
			print(R);
			print(G);
			print(B);
			
			img.set(i, j, color(R, G, B));
		}
	}
	img.updatePixels();
	image(img, 150, 150);
}





