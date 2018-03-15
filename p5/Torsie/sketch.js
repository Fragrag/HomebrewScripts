var quadArray = [];

function setup() {
	var quadHeight = 50;
	var quadWidth = 25;
	var rows = 10;
	var columns = 12;
	
	background(128);
	createCanvas(500, 500);
	translate(-(quadWidth/2), 0);
	
	Draw2DQuadArray(rows, columns, quadHeight, quadWidth, quadArray);
	
}

function Draw2DQuadArray(_rows, _columns, _quadHeight, _quadWidth, _arrayVariable) {
		for (var i = 0; i < _rows; i++) {
			_arrayVariable.push([0]);
			for (var j = 0; j < _columns; j++) {
				_arrayVariable[i][j] = new QuadElement(_quadHeight, _quadWidth, i, j);
				_arrayVariable[i][j].DrawQuad();
		}
	}
}

// function draw() {
	
// }


