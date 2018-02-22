let triangles = [];

function setup() {
	createCanvas(400, 300);
  
}

function draw() {
	// arc(200, 150, 75, 75, 0, 90);
	background(192);
	FillColour = 250;

	for (let x = 0; x < 48; x += 2){

		fill(FillColour);
		triangles.push(new equilateralTriangle(200, 150, 150, x));
		FillColour = FillColour - 25;
	}
}
