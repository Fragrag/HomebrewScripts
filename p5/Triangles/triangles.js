class equilateralTriangle
{
	constructor(px, py, r)
	{
		this.circleOriginX = px;
		this.circleOriginY = py;
		this.circleRadius = r;
		
		float x2 = (circleRadius * Math.Cos(120 * PI / 180)) + circleOriginX;
		float y2 = (circleRadius * Math.Cos(120 * PI / 180)) + circleOriginY;

		float x3 = (circleRadius * Math.Cos(240 * PI / 180)) + circleOriginX;
		float y3 = (circleRadius * Math.Cos(240 * PI / 180)) + circleOriginY;
		
		this.triangle(px, py+r, x2, y2, x3, y3);
	}
}