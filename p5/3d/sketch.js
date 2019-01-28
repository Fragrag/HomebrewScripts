
// function setup() {
	// fill(0,0,0);
	// createCanvas(1000, 1000, WEBGL);
	// ac1 = new AircraftVector(1, 0, 0, 0);
	// ac1.DrawVector;
	// camera(0,-500,0, 0,0,0, 0,1,0);
	
	

// }

// function draw(){
	
// }

function setup(){
  createCanvas(500,500,WEBGL);

}
function draw(){
  box(30);
  translate(100,100,-100);
  rotate(PI/4, [1,1,0]);
  box(30);
}


class AircraftVector {
	
	constructor(_scale, _posx, _posy, _posz, _aircraftstrokecolor = color(0, 0, 0)) {
		// Assigning constructor variables to input arguments
		this.scale = _scale; // TODO: implement scale
		this.posx = _posx;
		this.posy = _posy;
		this.posz = _posz;
		this.aircraftstrokecolor = _aircraftstrokecolor;
		
		this.vert1 = (0 + this.posx, 0 + this.posy, 0 + this.posz);
		this.vert2 = (0 + this.posx, 0 + this.posy, 20 + this.posz);
		this.vert3 = (0 + this.posx, 20 + this.posy, 0 + this.posz);
		this.vert4 = (0 + this.posx, -20 + this.posy, 0 + this.posz);
		this.vert5 = (30 + this.posx, 0 + this.posy, 0 + this.posz);
	}
	
	DrawVector() {
		strokeWeight(5);
		stroke(this.aircraftstrokecolor);
		
		line(0,0,0, 30,0,0);
		line(0,0,0, 0,0,20);
		line(0,0,0, 0,20,0);
		line(0,0,0, 0,-20,0);
	}
}