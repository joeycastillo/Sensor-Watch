/*
 * Partial C port of Greg Miller's public domain astro library (gmiller@gregmiller.net) 2019
 * https://github.com/gmiller123456/astrogreg
 */


static astrolib_get_body_ra_dec(double jd, int bodyNum, double lat, double lon, double precess) {
    double jdTT = convertUTCtoTT(jd);
    double t = convertJDToJulianMilleniaSinceJ2000(jdTT);
    
    //Get current position of Earth
    double earth[3];
    vsop87a_micro_getEarth(t, earth);

    let body=astrolib.getBodyLightTimeAdjusted(t, earth, bodyNum);

    //Convert to Geocrntric position
    body = astrolib.sub(body, earth);
    
    //Rotate ecliptic coordinates to J2000 coordinates
    body = astrolib.rotvsop2J2000(body);

    //TODO: rotate body for precession, nutation and bias
    let precession;
    if(precess==true){
        precession=astrolib.getPrecessionMatrix(jdTT);
        body=astrolib.vecMatrixMul(body,precession);
    }

    //Convert to topocentric
    let observerXYZ=astrolib.getObserverGeocentric(jdTT,lat,lon);

    if(precess==true){
        //TODO: rotate observerXYZ for precession, nutation and bias
        const precessionInv=astrolib.transpose(precession);
        observerXYZ=astrolib.vecMatrixMul(observerXYZ,precessionInv);
    }

    body = astrolib.sub(body,observerXYZ);

    //Convert to topocentric RA DEC by converting from cartesian coordinates to polar coordinates
    let RaDec = astrolib.toPolar(body);
    
    RaDec[1]=Math.PI/2.0-RaDec[1];  //Dec.  Offset to make 0 the equator, and the poles +/-90 deg
    if(RaDec[2]<0){RaDec[2]+=2*Math.PI;} //Ensure RA is positive
    
    return(RaDec);
}

class astrolib{

	//Returns an array containing the distance, declination, and right ascension (in that order) in radians.
	//BodyNum is passed to getBody() function below, see it for which body number to supply.  Constants appear at the end of this file
	//The positions are adjusted for the parallax of the Earth, and the offset of the observer from the Earth's center
	//All input and output angles are in radians!

	static getBodyLightTimeAdjusted(t,origin,bodyNum){
		//Get current position of body
		let body = astrolib.getBody(bodyNum,t);

		let newT=t;

		for(let i=0;i<2;i++){
			//Calculate light time to body
			body = astrolib.sub(body, origin);
			let distance = Math.sqrt(body[0] * body[0] + body[1] * body[1] + body[2] * body[2]);
			distance*=1.496e+11; //Convert from AU to meters
			const lightTime=distance/299792458.0;

			//Convert light time to Julian Millenia, and subtract it from the original value of t
			newT-=lightTime / 24.0 / 60.0 / 60.0 / 365250.0;  
			//Recalculate body position adjusted for light time
			body = astrolib.getBody(bodyNum,newT);
		}

		return body;
	}

	//Returns a body's cartesian coordinates centered on the Sun.
	//Requires vsop87a_full.js, if you wish to use a different version of VSOP87, replace the class name vsop87a_full below
	static getBody(bodyNum,et){
		switch(bodyNum){
			case 0: 
				return [0,0,0]; //Sun is at the center for vsop87a
				//return vsop87e_full.getSun(et);  // "E" is the only version the Sun is not always at [0,0,0]
			case 1:
				return vsop87a_full.getMercury(et);
			case 2:
				return vsop87a_full.getVenus(et);
			case 3:
				return vsop87a_full.getEarth(et);
			case 4:
				return vsop87a_full.getMars(et);
			case 5:
				return vsop87a_full.getJupiter(et);
			case 6:
				return vsop87a_full.getSaturn(et);
			case 7:
				return vsop87a_full.getUranus(et);
			case 8:
				return vsop87a_full.getNeptune(et);
			case 9:
				//return [0,0,0]; //Vsop87a is the only version which can compute the moon
				return vsop87a_full.getEmb(et);
			case 10:
				//return [0,0,0]; //Vsop87a is the only version which can compute the moon
				return vsop87a_full.getMoon(vsop87a_full.getEarth(et), vsop87a_full.getEmb(et));
		}
	}

	static transpose(m){
		let t=new Array();
		for(let i=0;i<m.length;i++){
			t[i]=new Array();
			for(let j=0;j<m[i].length;j++){
				t[i][j]=m[j][i];
			}
		}
		return t;
	}

	static vecMatrixMul(v,m){
		let t=new Array();
		t[0]=v[0]*m[0][0]+v[1]*m[0][1]+v[2]*m[0][2];
		t[1]=v[0]*m[1][0]+v[1]*m[1][1]+v[2]*m[1][2];
		t[2]=v[0]*m[2][0]+v[1]*m[2][1]+v[2]*m[2][2];

		return t;
	}

	//Subtracts two arrays (vectors), a-b
	static sub(a, b){
		let t = new Array();
		t[0] = a[0] - b[0];
		t[1] = a[1] - b[1];
		t[2] = a[2] - b[2];
		return t;
	}

	//Gets a rotation matrix about the x axis.  Angle R is in radians
	static getXRotationMatrix(r){
		let t=new Array();
		t[0]=new Array();
		t[1]=new Array();
		t[2]=new Array();

		t[0][0]=1;
		t[0][1]=0;
		t[0][2]=0;
		t[1][0]=0;
		t[1][1]=Math.cos(r);
		t[1][2]=Math.sin(r);
		t[2][0]=0;
		t[2][1]=-Math.sin(r);
		t[2][2]=Math.cos(r);

		return t;
	}

	//Gets a rotation matrix about the y axis.  Angle R is in radians
	static getYRotationMatrix(r){
		let t=new Array();
		t[0]=new Array();
		t[1]=new Array();
		t[2]=new Array();

		t[0][0]=Math.cos(r);
		t[0][1]=0;
		t[0][2]=-Math.sin(r);
		t[1][0]=0;
		t[1][1]=1;
		t[1][2]=0;
		t[2][0]=Math.sin(r);
		t[2][1]=0;
		t[2][2]=Math.cos(r);

		return t;
	}

	//Gets a rotation matrix about the z axis.  Angle R is in radians
	static getZRotationMatrix(r){
		let t=new Array();
		t[0]=new Array();
		t[1]=new Array();
		t[2]=new Array();

		t[0][0]=Math.cos(r);
		t[0][1]=Math.sin(r);
		t[0][2]=0;
		t[1][0]=-Math.sin(r);
		t[1][1]=Math.cos(r);
		t[1][2]=0;
		t[2][0]=0;
		t[2][1]=0;
		t[2][2]=1;

		return t;
	}

	//Matrix dot product
	static dot(a,b){
		let m=new Array();
		for(let i=0;i<a.length;i++){
			m[i]=new Array();
			for(let j=0;j<b[0].length;j++){
				let temp=0;
				for(let k=0;k<b.length;k++){
					temp+=a[i][k]*b[k][j];
				}
				m[i][j]=temp;
			}
		}
		return m;
	}

	//Special "Math.floor()" function used by convertDateToJulianDate()
	static INT(d){
		if(d>0){
			return Math.floor(d);
		}
		return Math.floor(d)-1;
	}

	//Converts a JavaScript Date object into a Julian Date
	//From Meeus p61 (7.1)
	static convertDateToJulianDate(date){
		let year=date.getUTCFullYear();
		let month=date.getUTCMonth()+1;
		let day=date.getUTCDate();
		let hour=date.getUTCHours();
		let min=date.getUTCMinutes();
		let sec=date.getUTCSeconds();

		if (month < 3){
			year = year - 1;
			month = month + 12;
		}

		let b = 0;
		if (!(year<1582 || (year == 1582 && (month < 10 || (month==10 && day < 5))))){
			let a = astrolib.INT(year / 100.0);
			b = 2 - a + astrolib.INT(a / 4.0);
		}

		let jd=astrolib.INT(365.25 * (year + 4716)) + astrolib.INT(30.6001 * (month + 1)) + day + b - 1524.5;
		jd+=hour/24.0;
		jd+=min/24.0/60.0;
		jd+=sec/24.0/60.0/60.0;
		return jd;
	}

	//Converts a Julan Date to Julian Millenia since J2000, which is what VSOP87 expects as input
	static convertJDToJulianMilleniaSinceJ2000(jd){
		return (jd - 2451545.0) / 365250.0;
	}

	//Converts cartesian XYZ coordinates to polar (e.g. J2000 xyz to Right Accention and Declication)
	static toPolar(xyz){
		let t = new Array();
		t[0] = Math.sqrt(xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2]);
		t[1] = Math.acos(xyz[2] / t[0]);
		t[2] = Math.atan2(xyz[1], xyz[0]);

		if(t[1]<0){t[1]+=2*Math.PI;}
		if(t[2]<0){t[2]+=2*Math.PI;}

		return t;
	}

	static toDmsString(d){
		let t = d * 180 / Math.PI;
		let deg = Math.trunc(t);
		t = Math.abs(t) - Math.abs(deg);
		t *= 60;
		let min = Math.trunc(t);
		t -= min;
		let sec = t * 60;
		return(deg + "d " + min + "' " + sec + "\"\r\n");
	}

	static toHmsString(h){
		let t = h * 180 / Math.PI;
		if(t<0)t+=360;
		t /= 15.0;
		let hours = Math.trunc(t);
		t = Math.abs(t) - Math.abs(hours);
		t *= 60;
		let min = Math.trunc(t);
		t -= min;
		let sec = t * 60;
		return(hours + "h " + min + "m " + sec + "s\r\n");
	}

	//Performs the rotation from ecliptic coordinates to J2000 coordinates for the given vector x
	static rotvsop2J2000(x){
		/* From VSOP87.doc
		  X        +1.000000000000  +0.000000440360  -0.000000190919   X
		  Y     =  -0.000000479966  +0.917482137087  -0.397776982902   Y
		  Z FK5     0.000000000000  +0.397776982902  +0.917482137087   Z VSOP87A
		*/
		let t = new Array();
		t[0] = x[0] + x[1] * 0.000000440360 + x[2] * -0.000000190919;
		t[1] = x[0] * -0.000000479966 + x[1] * 0.917482137087 + x[2] * -0.397776982902;
		t[2] = x[1] * 0.397776982902 + x[2] * 0.917482137087;

		return t;
	}

	//Converts a Julian Date in UTC to Terrestrial Time (TT)
	static convertUTCtoTT(jd){
		//Leap seconds are hard coded, should be updated from the IERS website for other times
		
		//TAI = UTC + leap seconds (e.g. 32)
		//TT=TAI + 32.184

		//return jd + (32.0 + 32.184) / 24.0 / 60.0 / 60.0;
		return jd + (37.0 + 32.184) / 24.0 / 60.0 / 60.0;

		/*
		https://data.iana.org/time-zones/tzdb-2018a/leap-seconds.list
		2272060800	10	# 1 Jan 1972
		2287785600	11	# 1 Jul 1972
		2303683200	12	# 1 Jan 1973
		2335219200	13	# 1 Jan 1974
		2366755200	14	# 1 Jan 1975
		2398291200	15	# 1 Jan 1976
		2429913600	16	# 1 Jan 1977
		2461449600	17	# 1 Jan 1978
		2492985600	18	# 1 Jan 1979
		2524521600	19	# 1 Jan 1980
		2571782400	20	# 1 Jul 1981
		2603318400	21	# 1 Jul 1982
		2634854400	22	# 1 Jul 1983
		2698012800	23	# 1 Jul 1985
		2776982400	24	# 1 Jan 1988
		2840140800	25	# 1 Jan 1990
		2871676800	26	# 1 Jan 1991
		2918937600	27	# 1 Jul 1992
		2950473600	28	# 1 Jul 1993
		2982009600	29	# 1 Jul 1994
		3029443200	30	# 1 Jan 1996
		3076704000	31	# 1 Jul 1997
		3124137600	32	# 1 Jan 1999
		3345062400	33	# 1 Jan 2006
		3439756800	34	# 1 Jan 2009
		3550089600	35	# 1 Jul 2012
		3644697600	36	# 1 Jul 2015
		3692217600	37	# 1 Jan 2017
		*/
	}

	//Convert Geodedic Lat Lon to geocentric XYZ position vector
	//All angles are input as radians
	static convertGeodedicLatLonToITRFXYZ(lat,lon,height){
		//Algorithm from Explanatory Supplement to the Astronomical Almanac 3rd ed. P294
		const a=6378136.6;
		const f=1/298.25642;

		const C=Math.sqrt(((Math.cos(lat)*Math.cos(lat)) + (1.0-f)*(1.0-f) * (Math.sin(lat)*Math.sin(lat))));

		const S=(1-f)*(1-f)*C;
		
		const h=height;

		let r=new Array();
		r[0]=(a*C+h) * Math.cos(lat) * Math.cos(lon);
		r[1]=(a*C+h) * Math.cos(lat) * Math.sin(lon);
		r[2]=(a*S+h) * Math.sin(lat);
		
		return r;
	}


	static getGMST(ut1){
		const D=ut1 - 2451545.0;
		const T = D/36525.0;
		let gmst = (280.46061837 + 360.98564736629*D + 0.000387933*T*T - T*T*T/38710000.0) %360.0;
		if(gmst<0){gmst+=360;}
		return gmst/15;

	}

	//Convert position vector to celestial "of date" system.
	//g(t)=R3(-GAST) r
	//(Remember to use UT1 for GAST, not ET)
	//All angles are input and output as radians
	static convertITRFToGCRS(r,ut1){
		//This is a simple rotation matrix implemenation about the Z axis, rotation angle is -GMST

		let GMST=astrolib.getGMST(ut1);
		GMST=-GMST*15.0*Math.PI/180.0;

		let m=astrolib.getZRotationMatrix(GMST);
		let t=astrolib.vecMatrixMul(r,m);

		/*
		let t=new Array();
		t[0]=r[0]*Math.cos(GMST) + r[1]*(Math.sin(GMST));
		t[1]=r[0]*(-Math.sin(GMST)) + r[1]*Math.cos(GMST);
		t[2]=r[2];
		*/

		return t;
	}

	//Convert from meters to AU
	//Multiply g(t) by 1.49597870691E+11
	static convertFromMetersToAU(r){
		let t=new Array();
		
		t[0]=r[0]/1.49597870691E+11;
		t[1]=r[1]/1.49597870691E+11;
		t[2]=r[2]/1.49597870691E+11;
		
		return t;
	}

	//Returns an observer's position in GCRS/J2000 cartesian coordinates in astronomical units
	//All angles are input and output as radians
	static getObserverGeocentric(jd,lat,lon){
		let r=astrolib.convertGeodedicLatLonToITRFXYZ(lat, lon,0);
		r=astrolib.convertITRFToGCRS(r,jd);
		r=astrolib.convertFromMetersToAU(r);
		
		return r;
	}

	//Returns the Alt/Az polar coordinates based on RA/Dec coordinates for a given location on Earth's surface.
	//All angles are input and output as radians
	static convertRaDecToAltAz(jd,lat,lon,ra,dec){
		const GMST=astrolib.getGMST(jd)*Math.PI/180.0*15.0;
		let h=GMST + lon - ra;
		
		const sina=Math.sin(dec)*Math.sin(lat)+Math.cos(dec)*Math.cos(h)*Math.cos(lat);
		const a=Math.asin(sina);

		//const cosAz=(Math.sin(dec)-Math.sin(a)*Math.sin(lat))/(Math.cos(a)*Math.cos(lat));
		const cosAz=(Math.sin(dec)*Math.cos(lat)-Math.cos(dec)*Math.cos(h)*Math.sin(lat))/Math.cos(a);
		let Az=Math.acos(cosAz);

		if(Math.sin(h)>0){Az=2.0*Math.PI-Az;}

		let t=new Array();
		t[0]=Az;
		t[1]=a;
		
		return t;
	}

	static printmat(m){
		for(let i=0;i<m.length;i++){
			let s="";
			for(let j=0;j<m[i].length;j++){
				s=s+""+m[i][j]+"\t";
			}
			console.log(s);
		}
		console.log("");
	}

	static getPrecessionMatrix(jd){
		//2006 IAU Precession.  Implemented from IERS Technical Note No 36 ch5.
		//https://www.iers.org/SharedDocs/Publikationen/EN/IERS/Publications/tn/TechnNote36/tn36_043.pdf?__blob=publicationFile&v=1

		const t =(jd - 2451545.0)/36525.0;  //5.2
		const Arcsec2Radians=Math.PI/180.0/60.0/60.0; //Converts arc seconds used in equations below to radians

		const e0 = 84381.406 * Arcsec2Radians; //5.6.4
		const omegaA = e0 + ((-0.025754 + (0.0512623 +	(-0.00772503 + (-0.000000467 + 0.0000003337*t) * t) * t) * t) * t) * Arcsec2Radians; //5.39
		const psiA = ((5038.481507 +	(-1.0790069 + (-0.00114045 + (0.000132851 - 0.0000000951*t) * t) * t) * t) * t) * Arcsec2Radians; //5.39
		const chiA = ((10.556403 + (-2.3814292 + (-0.00121197 + (0.000170663 - 0.0000000560*t) * t) * t) * t) * t) * Arcsec2Radians; //5.40


//console.log(dpsi+"\t"+deps);

		const epsA=e0 - ((46.83676900 - (0.0001831 + (0.0020034 - (0.000000576 - 0.000000043400*t) *t) *t) *t) *t) * Arcsec2Radians; //5.40
		//const dpsi1=(dpsi*Math.sin(eA)*Math.cos(chiA)-deps*Math.sin(chiA))/Math.sin(omegaA); //5.24
		//const deps1=dpsi*Math.sin(eA)*Math.sin(chiA)+deps*Math.cos(chiA);


		//Rotation matrix from 5.4.5
		//(R1(−e0) · R3(psiA) · R1(omegaA) · R3(−chiA))
		//Above eq rotates from "of date" to J2000, so we reverse the signs to go from J2000 to "of date"
		const m1=astrolib.getXRotationMatrix(e0);
		const m2=astrolib.getZRotationMatrix(-psiA);
		const m3=astrolib.getXRotationMatrix(-omegaA);
		const m4=astrolib.getZRotationMatrix(chiA);

		const m5=astrolib.dot(m4,m3);
		const m6=astrolib.dot(m5,m2);
		const precessionMatrix=astrolib.dot(m6,m1);

		/*
		//Compute nutation
		const nut=eraNut00a(0,jd);
		const dpsi=nut[0];
		const deps=nut[1];

		const m7=astrolib.getXRotationMatrix(-epsA);
		const m8=astrolib.getZRotationMatrix(dpsi);
		const m9=astrolib.getXRotationMatrix((epsA+deps));

		const m10=astrolib.dot(m7,m8);
		const m11=astrolib.dot(m10,m9);
		const nutationMatrix=astrolib.dot(precessionMatrix,m11);

		return nutationMatrix;
		*/
		return precessionMatrix;
	}

}

astrolib.SUN=0;
astrolib.MERCURY=1;
astrolib.VENUS=2;
astrolib.EARTH=3;
astrolib.MARS=4;
astrolib.JUPITER=5;
astrolib.SATURN=6;
astrolib.URANUS=7;
astrolib.NEPTUNE=8;
astrolib.EMB=9;
astrolib.MOON=10;

astrolib.bodies=["Sun","Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Earth-Moon Barrycenter","Moon"];