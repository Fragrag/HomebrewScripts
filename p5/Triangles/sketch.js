function setup() {
  createCanvas(400, 300);
}

function draw() {
	// arc(200, 150, 75, 75, 0, 90);
	Drawtriangle(200, 150, 75);
	
}

function Drawtriangle(px, py, r)
{
	circleOriginX = px;
	circleOriginY = py;
	circleRadius = r;
	
	x2 = (circleRadius * cos(120 * PI / 180)) + circleOriginX;
	y2 = (circleRadius * cos(120 * PI / 180)) + circleOriginY;

	x3 = (circleRadius * cos(240 * PI / 180)) + circleOriginX;
	y3 = (circleRadius * cos(240 * PI / 180)) + circleOriginY;
	
	triangle(px, py+r, x2, y2, x3, y3);
}