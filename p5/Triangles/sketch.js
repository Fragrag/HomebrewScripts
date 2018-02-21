let triangles = [];

function setup() {
	createCanvas(400, 300);
  
}

function draw() {
	// arc(200, 150, 75, 75, 0, 90);
	background(192);

	for (let x = 0; x < PI; x += PI/10){
		triangles.push(new equilateralTriangle(200, 150, 150, x));
	}
}
