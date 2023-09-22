//24Bit BMP

// Azaye gorooh:
/*
Reyhane Esmaili 810800004
Shahin Shahnavaz 810800013
Aida Nozari 810800028
*/


#include <bits/stdc++.h>
using namespace std;

struct Color{
	int red;
	int green;
	int blue;
};

ifstream file1;// akse voroodi dar in file rikhte mishe
ofstream file2;// akse khorooji dar in file zakhire mishe
bool e=false , is_rotate=false; // is_rotate baraye taghire abaad be kar mire (agar charkhesh 90 daraje ya 270 daraje bashe)   
// age aks mojood bashe e true mishe dar gheir in soorat false mimoone
const int MaxN=5000; // maximum abaade aks haye voroodi khorooji MaxN*MaxN ast (by default= 5000*5000)
int width , height , mod;
//width= tedade sotoon    , height= tedade satr   ,   mod= oon char haye ezafe i ke akhare har satr gerefte mishe baraye moshakhas shodane etmame satr
string name1 , name2;// name1= esme file voroodi(image)     name2= esme file khorooji(rotate90 - rotate180- rotate270- hollow- contrast)
unsigned char  A[54]; // char haye header aks bmp
unsigned char B[3*(MaxN+3)*MaxN] , C[3*(MaxN+3)*MaxN]; // B= char haye moshakhas konande rgb pixel be pixel aks voroodi
//C= char haye moshakhas konande rgb pixel be pixel aks khorooji
Color pixels1[MaxN][MaxN] , pixels2[MaxN][MaxN];
//pixels1[][]= pixel haye akse voroodi    pixels2[][]= pixel haye aks khorooji



bool is_ready(){ // check mikone ke aslan aya akse voroodi dar folder mojood hast ya na
	if (file1.is_open()){
    	cout<<"BMP is Open."<<'\n';
    	e=true;
    	return true;
	}
	else{
    	cout<<"BMP is not Open!"<<'\n';
    	return false;
  	}
}

void fileReciever(string name){ // aks ba formate bmp migire va dar yek matrice pixeli zakhire mikone
	name+=".bmp";
	file1.open(name.c_str());
	if (is_ready()){
    	for (int i=0; i<54; i++)
        	file1 >> A[i];
    	width= *(int *)&A[18];
		height= *(int *)&A[22];
    
    	if (width<0)
			width+=256;

    	if (height<0) 
			height+=256;
			
    	mod=(4-(width*3)%4)%4;
    	for (int i=0 ; i<(3*width+mod)*height ; i++)
        	file1>>B[i];
    	for (int i=0 ; i<height ; i++)
        	for (int j=0 ; j<width ; j++){
            	pixels1[height-i-1][j].blue=(int)B[(i*(3*width+mod)+3*j)];
           		pixels1[height-i-1][j].red=(int)B[(i*(3*width+mod)+3*j)+1];
            	pixels1[height-i-1][j].green=(int)B[(i*(3*width+mod)+3*j)+2];
        	}
    }
}

void fileMaker(string name){ // file khorooji ro misaze 
	name+=".bmp";
    file2.open(name.c_str());
    for (int i=0 ; i<54 ; i++){
    	if (i==2)
        	file2<<(char) (54+(height*(3*width+mod)));
    	else if (i>=18 && is_rotate && i<=21)
        	file2<<A[i+4];
    	else if (i>=22 && is_rotate && i<=25)
        	file2<<A[i-4];
    	else
        	file2<<A[i];
    }
	for (int i=0; i<(3*width+mod)*(height); i++)
    	file2<<C[i];
    cout<<'\n'<<name2<<".bmp has been created.";
}

void changeArray(){ // character hayi ke gharare be file khorooji bede ro misaze
	mod=(4-(width*3)%4)%4;
	for (int i=0 ; i<height ; i++){
    	for (int j=0 ; j<width ; j++){
        	C[((height-1-i)*(3*width+mod)+3*j)]=(char)pixels2[i][j].blue;
        	C[((height-1-i)*(3*width+mod)+3*j)+1]=(char)pixels2[i][j].red;
        	C[((height-1-i)*(3*width+mod)+3*j)+2]=(char)pixels2[i][j].green;
    	}
    	int address=((height-1-i)*(3*width+mod)+3*(width));
    	for (int j=0 ; j<mod ; j++){
        	C[address]=(char) 0;
        	address++;
    	}
	}
}

void rotate_90(){// 90 daraje rotate
	is_rotate=true;
	for (int i=0 ; i<height ; i++)
    	for (int j=0 ; j<width ; j++)
        	pixels2[j][height-i-1]=pixels1[i][j];
	swap(height,width);
	changeArray();
	name2="rotate90";
}


void rotate_180(){ // 180 daraje rotate
	for (int i=0 ; i<height ; i++)
    	for (int j=0 ; j<width ; j++)
        	pixels2[height-1-i][width-1-j]=pixels1[i][j];
	changeArray();
	name2="rotate180";
}

void rotate_270(){ // 270 daraje rotate mikone
	is_rotate=true;
	for (int i=0 ; i<height ; i++)
    	for (int j=0 ; j<width ; j++)
        	pixels2[width-j-1][i]=pixels1[i][j];
	swap(height,width);
	changeArray();
	name2="rotate270";
}


bool is_equal(Color c1, Color c2){ // check mikone ke aya 2 ta Color barabaran ya na?
	if (c1.blue!=c2.blue)
		return false;
	if (c1.red!=c2.red)
		return false;
	if (c1.green!=c2.green)
		return false;
	return true;
}

bool checker(int i, int j){
	if ( ! is_equal(pixels1[i][j-1],pixels1[i][j+1]) )
		return false;
	if ( ! is_equal(pixels1[i-1][j],pixels1[i+1][j]) ) 
		return false;
	if ( ! is_equal(pixels1[i-1][j-1],pixels1[i-1][j+1]) )
		return false;
	if ( ! is_equal(pixels1[i+1][j-1],pixels1[i+1][j+1]) )
		return false;
	if ( ! is_equal(pixels1[i][j-1],pixels1[i-1][j]) )
		return false;
	if ( ! is_equal(pixels1[i-1][j-1],pixels1[i+1][j-1]) )
		return false;
	if ( ! is_equal(pixels1[i][j-1],pixels1[i-1][j-1]) )
		return false;
	if (pixels1[i][j-1].blue==0 && pixels1[i][j-1].red==0 && pixels1[i][j-1].green==0)
		return true;
	return false;
}

void hollow(){ // bevasile tabe checker check mikone ke age be ezaye pixeli khas pixelaye mojaveresh hame siah boodan oon pixelo sefid mikone
	for (int i=0 ; i<height ; i++)
		for (int j=0 ; j<width ; j++)
			pixels2[i][j]=pixels1[i][j];
	for (int i=1 ; i<height-1 ; i++)
		for (int j=1 ; j<width-1 ; j++)
	 		if (checker(i,j)){
				pixels2[i][j].blue=255;
				pixels2[i][j].green=255;
				pixels2[i][j].red=255;
			}
	changeArray();
	name2="hollow";
}

void contrast(){ // contrast ro ziad mikone   :    127 hamoon mimoone ,  balaye 127 ba 255 miangin gerefte mishe , payin 127 ba 0 miangin gerefte mishe
	int b , g , r;
	for(int i=0 ; i<height ; i++)
		for(int j=0 ; j<width ; j++){
			b=pixels1[i][j].blue;
			g=pixels1[i][j].green;
			r=pixels1[i][j].red;
			
			if(b<127) 
				pixels2[i][j].blue=b/2;
			else if(b>127)
				pixels2[i][j].blue=(b+255)/2;
			else 
				pixels2[i][j].blue=b;
			
			if(g<127) 
				pixels2[i][j].green=g/2;
			else if(g>127) 
				pixels2[i][j].green=(g+255)/2;
			else 
				pixels2[i][j].green=g;
			
			if(r<127) 
				pixels2[i][j].red=r/2;
			else if(r>127) 
				pixels2[i][j].red=(r+255)/2;	
			else 
				pixels2[i][j].red=r;	
		}
	changeArray();
	name2="contrast";
}

void printValues(Color pixels[MaxN][MaxN]){	// RGB har pixel ro chap mikone
    for (int i=0; i<height; i++){
    	for (int j=0 ; j<width ; j++)
           	cout<<'('<<pixels[i][j].red<<','<<pixels[i][j].green<<','<<pixels[i][j].blue<<") ";
        cout<<'\n'<<'\n';
    }
    cout<<'\n';
}

int main(){
	name1="image";
	fileReciever(name1);
	cout<<name1<<".bmp has been recieved.";
	file1.close();
	
	if(e){
    	bool temp;
    	int func;
    	cout<<'\n'<<"The size of image: "<<'\n'<<"    Width: "<<width<<'\n'<<"    Height: "<<height<<'\n';
    	
    	cout<<'\n'<<"Old Pixel values? (0: nope)(1: yeah)   ";
    	cin>>temp;
    	if (temp)	
			printValues(pixels1);
			
    	cout<<'\n'<<"Put 1 for rotation , 2 for hollow , 3 for contrast :	";
    	cin>>func;
    	
    	if(func==1){
    		cout<<'\n'<<"Put 1 for 90 degree rotation , 2 for 180 degree rotation , 3 for 270 degree rotation :   ";
    		cin>>func;
    		if(func==2)
    			func=4;
    		else if(func==3)
    			func=5;
		}
		
    	switch(func){
        	case 1: rotate_90();
            		break;
        	case 2: hollow();
            		break;
        	case 3: contrast();
            		break;
            case 4: rotate_180();
            		break;
            case 5: rotate_270();
            		break;
        	default:
            		break;
    	}
    	
    	cout<<'\n'<<"New Pixel values? (0: nope)(1: yeah)   ";
    	cin>>temp;
    	if (temp)	
			printValues(pixels2);
			
    	fileMaker(name2);
	}
  
	return 0;
}
