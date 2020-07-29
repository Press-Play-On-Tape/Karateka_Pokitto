const fs = require("fs");
const Canvas = require('canvas');
const Image = Canvas.Image;

const palette = [
0,63488,32768,2047,2016,1024,1039,31744,65504,16,32784,63519,31759,48663,65535,65535,
].map( c => [
    (c>>>11)/0x1F*0xFF,
    ((c>>>5)&0x3F)/0x3F*0xFF,
    ((c&0x1F)/0x1F*0xFF)
]);

let file = process.argv[2];
w = parseInt(process.argv[3]);
h = parseInt(process.argv[4]);

    console.log(w);
    console.log(h);


if( !file ){
    console.log("Usage: node gfx.js file.png w h");
}else{
    fs.writeFileSync(
        `${file.replace(/\..*$/, '')}.gfx`,
        Buffer.from( img4bpp( file, w, h ) )    
    );
}

function img4bpp( path, w, h ){
    const canvas = Canvas.createCanvas(w, h);
    const ctx = canvas.getContext('2d');
    const image = new Image();
    image.src = fs.readFileSync( path );
    
    ctx.drawImage( image, 0, 0, w, h );
    const buf = canvas.toBuffer('raw');
    const nerr = [0,0,0];
    const pixel = [0,0,0];
    const error = [0,0,0];
    const infl = [];


	infl.push( w / 16 );
	infl.push( w % 16 );
	infl.push( h / 16 );
	infl.push( h % 16 );


    let line = '';

    for( let i=0; i<buf.length; ++i ){
	let j;

	nerr[2] = buf[i++];
	nerr[1] = buf[i++];
	nerr[0] = buf[i++];

	pixel[0] = nerr[0] + error[0];
	pixel[1] = nerr[1] + error[1];
	pixel[2] = nerr[2] + error[2];

	let minind = 0;
	let mindist = (pixel[0]-palette[0][0])*(pixel[0]-palette[0][0]) +
	    (pixel[1]-palette[0][1])*(pixel[1]-palette[0][1]) +
	    (pixel[2]-palette[0][2])*(pixel[2]-palette[0][2]);

	for( j=1; j<palette.length; ++j ){
	    let dist = (pixel[0]-palette[j][0])*(pixel[0]-palette[j][0]) +
		(pixel[1]-palette[j][1])*(pixel[1]-palette[j][1]) +
		(pixel[2]-palette[j][2])*(pixel[2]-palette[j][2]);

	    if( dist < mindist ){
		minind = j;
		mindist = dist;
		if( dist == 0 )
		    break;
	    }
	}
/*
	error[0] = nerr[0] - palette[minind][0];
	error[1] = nerr[1] - palette[minind][1];
	error[2] = nerr[2] - palette[minind][2];
*/
	infl.push( minind );

	line += minind.toString(16);
	if( line.length == w ){
            if (w % 2 == 1) {

		infl.push( 0 );
            }
 
	    // console.log(line);
	    line = '';
	}

    }

    const out = [];

    for( let i=0; i<infl.length; ){
	let hi = infl[i++];
	let lo = infl[i++];
	out.push( (hi<<4) | lo );
    }
    
    return out;
}
