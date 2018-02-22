class equilateralTriangle
{
	constructor(px, py, radius, angle)
	{	
		this.x1 = px + radius * cos(angle + 0 * 2 * (PI/3));
		this.y1 = py + radius * sin(angle + 0 * 2 * (PI/3));
		
		this.x2 = px + radius * cos(angle + 1 * 2 * (PI/3));
		this.y2 = py + radius * sin(angle + 1 * 2 * (PI/3));
		
		this.x3 = px + radius * cos(angle + 2 * 2 * (PI/3));
		this.y3 = py + radius * sin(angle + 2 * 2 * (PI/3));
		
		triangle(this.x1, this.y1, this.x2, this.y2, this.x3, this.y3);
	}
	
	update() {
		
	}
}
	