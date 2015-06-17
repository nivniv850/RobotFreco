/*
 * pngUtil.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: colman
 */
#include "pngUtil.h"
#include "lodepng.h"
#include <iostream>


//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char> image,
		unsigned width, unsigned height) {
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
	if (error)
		std::cout << "encoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;
}

void decodeOneStep(const char* filename) {
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;

	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}
void ConvertMapBlackToWhiteAndWhiteToBlack(const char* filename) {
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	unsigned int x, y;
	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	char** map = initializeMatrix(height + 6,width + 6);

	unsigned char color;
	for (y = 0; y < height; y++)
		for (x = 0; x < width; x++) {
			if (image[y * width * 4 + x * 4 + 0]
					|| image[y * width * 4 + x * 4 + 1]
					|| image[y * width * 4 + x * 4 + 2])
				// There is an obstacle in the map
				color = '0';
			else
				// There is no obstacle
				color = '1';
			map[y + 3][x + 3] = color;

		}

	printMap(map, height + 6, width + 6);

	char** mapBlow = initializeMatrix(height/4, width/4);

	unsigned i,j;
	int mapBlowY = 0, mapBlowX = 0;
	bool hasObstacle = false;

	for (y = 3; y < height; y+=4) {
		for (x = 3; x < width; x+=4) {
			for (i = 0; i<4 && !hasObstacle; i++) {
				for (j = 0; j<4 && !hasObstacle; j++) {
					if (map[y + i][x + j] == '1')
					{
						hasObstacle = true;
					}
				}
			}

			if (hasObstacle) {
				mapBlow[mapBlowY][mapBlowX] = '1';
			}

			hasObstacle = false;
			mapBlowX++;
		}

		mapBlowX = 0;
		mapBlowY++;
	}

	printMap(mapBlow, height/4, width/4);

	//encodeOneStep("newMap.png", navImage, width, height);
}

void printMap(char** map, unsigned int height, unsigned int width) {

	unsigned x, y;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			std::cout << map[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << "----------------------------" << std::endl;
}

char** initializeMatrix(unsigned int height,unsigned int width) {

	unsigned x, y;

	char** map = new char*[height];

		for (y=0; y<height; y++) {
			map[y] = new char[width];
		}

		for (y = 0; y < height; y++)
			for (x = 0; x < width; x++) {
				map[y][x] = '0';
			}

		return map;
}
