#ifndef MOVIEPLAITER_PUZZLEGRID_H
#define MOVIEPLAITER_PUZZLEGRID_H

#include <FL/Fl_Button.H>
#include <Fl/Fl.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Export.H>
#include <string>

#define PUZZLE_ROWS 8
#define PUZZLE_COLS 8

#define BUTTON_WIDTH 55
#define BUTTON_HEIGHT 55
#define BUTTON_PADDING 10

#include "../Controller/GameManager.h"
using namespace controller;

#include "ButtonValueWindow.h"
#include "PuzzleGridButton.h"
using namespace view;

#include <unistd.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

namespace view
{

/// A puzzle grid widget whose labels can be arbitrarily set and react to click events.
//
class PuzzleGrid
{

public:
    PuzzleGrid(int, int, GameManager* gameManager);
    ~PuzzleGrid();

    void resetColors();
    void resetBoard(GameManager*);
    void colorEvaluationPath(GameManager*);
    void colorPeekPath(GameManager* gameManager);
    void deactivate();
    void activate();

private:
    Fl_Group *gridGroup;
    vector<PuzzleGridButton*> gridButtons;

    int xLocation;
    int yLocation;

    Fl_Color* validNodeColor;
    Fl_Color* invalidNodeColor;
    Fl_Color* defaultEvaluationTextColor;
    Fl_Color defaultBackgroundColor;
    Fl_Color defaultLabelColor;

    void updatePuzzleNode(int, GameManager*);
    void evaluate(int, GameManager*);
    void drawPuzzleGrid(int, int, GameManager*);
    static void cbButtonSelected(Fl_Widget*, void*);

    void setDefaultColorValues(GameManager*);

};
}


#endif //MOVIEPLAITER_PUZZLEGRID_H
