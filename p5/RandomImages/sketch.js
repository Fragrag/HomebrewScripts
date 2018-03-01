var LoadedDigits;

function preload(){
	LoadedDigits = loadStrings('digits.txt');
}

function setup() {
	createCanvas(500, 500);
	frameRate(12);
	print(LoadedDigits);
}

function draw(){
	CreateImage(LoadedDigits, 50, 50);
}

function CreateImage(NumberArray, height, width) {
	var columns = 10;
	var rows = 10;
	var rectHeight = height;
	var rectWidth = width;

	for (var i = 0; i <= columns; i++){
		for (var j = 0; j <= rows; j++){
			
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
			
			fill(R, G, B);
			noStroke();
			rect(i*rectHeight, j*rectWidth, rectHeight, rectWidth);
		}
	}
}





