/*
 * Database.h
 *
 * Created: 6/18/2023 11:59:35 AM
 *  Author: 123
 */ 


#ifndef DATABASE_H_
#define DATABASE_H_

struct product {
	char name[20];
	//char barcode [8];
	int barcode;
	unsigned int price;
	float offer;
	};

/*
struct product products[]={{"tea","ABC123456",50},
{"eggs","CDG55564",100},
{"Apples","GYU26648",100},
{"Rice","HYI89754",25},
{"Bananas","FJU56478",20},
{"classic coffee","OIU71458",85},
{"Watermelon","ADS73156",30},
{"Milk", "09854321", 50},
{"Bread", "ABCD34EF", 35},
{"Chicken", "GHIJ58KL", 200},
{"Pasta", "MNO34PQ", 150},
{"Orange", "09876522", 120},
{"Cheese", "KLMN58OP", 300},
{"Salmon", "VWX456YZ", 800},
{"ice cream", "ABC134DE", 90},
{"Yogurt", "FGHI58JK", 120},
{"Beef", "LMNO34PQ", 700},
{"Tomato", "RS5678VW", 70},
{"Potato", "XZ1264AB", 50},
{"Soda", "CDE564FG", 90},
{"Water", "HIJ134KL", 60},
{"Juice", "PQR578ST", 150},
{"Cookies", "UVW134XY", 120},
{"Chips", "ZAB568CD", 100}};
*/

struct product products[]={
	{"tea",200,50,0.2},
	{"eggs",201,100,0.2},
	{"Apples",202,100,0.2},
	{"Rice",203,25,0.1},
};



#endif /* DATABASE_H_ */