function setup() {
	createCanvas(400, 300);
  
}

function draw() {
	// arc(200, 150, 75, 75, 0, 90);
	background(192);
	DrawTriangle(200, 150, 75);
	ellipse(200, 150, 75, 75);
	
	
}

function DrawTriangle(px, py, r)
{
	OriginX = px;
	OriginY = py;
	Radius = r;
	Xoffset = cos(PI) * Radius;
	Yoffset = sin(PI) * Radius;
	
	x1 = OriginX;
	y1 = OriginY - r;
	
	x2 = OriginX + Xoffset;
	y2 = OriginY + Yoffset;

	x3 = OriginX - Xoffset;
	y3 = OriginY - Yoffset;
	
	triangle(x1, y1, x2, y2, x3, y3);
}