/* Creating the class QuadElement which willl be the building block of Torsion.

 The QuadElement will be defined by the following elements:
	width, height
	A drawn quad
	FillColor,
	StrokeThickness
	
	TODO: Define quad formula 
	quad(
	0,0, 
	width,0, 
	(height+width),(height), 
	(width-height),(height)
	);
 
*/

class QuadElement {

	constructor(_width, _height, _x, _y) {

		this.width = _width;
		this.height = _height;
		this.x = _x;
		this.y = _y;
	}
	
	DrawQuad() {
		var originX = this.x * this.width;
		var originY = this.y * this.height;
		
		quad(
			originX, originY,
			originX+this.width, originY,
			originX + (this.width + this.height), (originY + this.height),
			originX + this.height, (originY + this.height)
		);
	}
}