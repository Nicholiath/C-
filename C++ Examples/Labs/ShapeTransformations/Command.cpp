#include "Command.h"

using namespace std;

void XReflectCommand::execute() {
	shape_ -> xreflect();
}

void XReflectCommand::unexecute() {
	shape_ -> xreflect();
}

void YReflectCommand::execute() {
	shape_ -> yreflect();
}

void YReflectCommand::unexecute() {
	shape_ -> yreflect();
}

void TranslateCommand::execute() {
	shape_ -> translate(delta_);
}
/// invert_translate: changes eg (1,2) to (-1,-2) then translates (reverses)
void TranslateCommand::unexecute() {
	shape_ -> invert_translate(delta_);
}