#ifndef COMMAND_H
#define COMMAND_H
#include <memory>
#include "Shape.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
  virtual void unexecute() = 0;
};

class TranslateCommand: public Command {
public:
  explicit TranslateCommand(std::shared_ptr<Shape> s = nullptr, 
                            const Point& delta = Point())
    : shape_(s), delta_(delta) {}
  virtual void execute() override;
  virtual void unexecute() override;
private:
  std::shared_ptr<Shape>  shape_;
  Point  delta_;
};

class XReflectCommand: public Command {
public:
  explicit XReflectCommand(std::shared_ptr<Shape> s = nullptr): shape_(s) {}
  virtual void execute() override; // reflect shape_ about x-axis
  virtual void unexecute() override; // undo reflection
private: 
  std::shared_ptr<Shape>  shape_; // receiver
};

class YReflectCommand: public Command {
public:
  explicit YReflectCommand(std::shared_ptr<Shape> s = nullptr): shape_(s) {}
  virtual void execute() override;
  virtual void unexecute() override;
private:
  std::shared_ptr<Shape>  shape_;
};
#endif
