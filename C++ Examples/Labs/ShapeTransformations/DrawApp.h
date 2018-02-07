#ifndef DRAWAPP_H
#define DRAWAPP_H
#include <iostream>
#include <sstream>
#include <vector>
#include <memory> 
#include <string>
#include "Command.h"
#include "Shape.h"

// may need to include additional headers
using namespace std;

class DrawApp {
public:
  DrawApp();
  void run();        // loop to get user commands & execute them
  void addShape(std::shared_ptr<Shape> s);
  bool undo();       // undo 
  bool redo();       // redo
  /// 
  void historyPos(std::shared_ptr<Command>& p);

private:
  void draw() const;                           // draw all shapes
  vector<std::shared_ptr<Shape>>    shapes_;
  vector<std::shared_ptr<Command>>  history_;  // history list
  // additional data members if necessary
  int pos_= -1;
};
#endif

