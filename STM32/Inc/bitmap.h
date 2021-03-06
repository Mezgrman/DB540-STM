/*
 * bitmap.h
 *
 *  Created on: 08.09.2018
 *      Author: Julian Metzler
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <stdint.h>
#include "matrix.h"

#define BITMAP_WIDTH 3000 // Must be divisible by 8
#define BITMAP_HEIGHT NUM_LINES * MATRIX_HEIGHT
#define BITMAP_WIDTH_BYTES BITMAP_WIDTH / 8
#define BITMAP_SIZE BITMAP_WIDTH * BITMAP_HEIGHT / 8

#define MAX_FRAME_COUNTER (uint16_t)-1

uint8_t BITMAP[BITMAP_SIZE];
uint8_t staticData[FB_SIZE];
uint8_t staticMask[FB_SIZE];
int16_t scrollOffsetsX[NUM_LINES];
int16_t scrollStopPositionsX[NUM_LINES];
uint8_t autoScrollEnabledX[NUM_LINES];
uint8_t autoScrollResetEnabledX[NUM_LINES];
uint8_t scrollEnabledX[NUM_LINES];
uint8_t scrollStopEnabledX[NUM_LINES];
int16_t userScrollWidths[NUM_LINES];
int16_t scrollWidths[NUM_LINES];
uint16_t lineWidths[NUM_LINES];
volatile uint8_t parameterUpdatePending;

uint16_t frameCounter;
int16_t scrollStepsX[NUM_LINES];
uint16_t scrollIntervalsX[NUM_LINES];
uint16_t lastScrollFrameCountsX[NUM_LINES];

uint16_t blinkIntervalsOn[NUM_LINES];
uint16_t blinkIntervalsOff[NUM_LINES];
uint8_t blinkStates[NUM_LINES];
uint16_t lastBlinkFrameCounts[NUM_LINES];

void initBitmap();
void scrollX(uint8_t, int16_t);
void setScrollStepX(uint8_t, int16_t);
void setScrollIntervalX(uint8_t, uint16_t);
void setScrollWidth(uint8_t, int16_t);
void setScrollPositionX(uint8_t, int16_t);
void setAutoScrollEnabledX(uint8_t, uint8_t);
void setAutoScrollResetEnabledX(uint8_t, uint8_t);
void setScrollEnabledX(uint8_t, uint8_t);
void setScrollStopPositionX(uint8_t, int16_t);
void setBlinkInterval(uint8_t, uint16_t);
void setBlinkIntervalOn(uint8_t, uint16_t);
void setBlinkIntervalOff(uint8_t, uint16_t);
void calculateScrollParameters();
void updateParameters();
void writeFrameBuffer(uint8_t*);
void handleScrolling();
void handleBlinking();

#endif /* BITMAP_H_ */
