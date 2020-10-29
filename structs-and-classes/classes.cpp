#include <iostream>
#include <cmath>

// with a class, by default all things are private:
//  that is, only visible from withing the class (or attached methods)
class Position {
  float x = 0;
  float y = 0;

  // make all things below this public
  public:
    // method signatures
    // methods = a function for use only within a class.
    // functions = a function inddementent from a class.
    Position();
    Position(float, float);
    float get_x();
    float get_y();
    void set_x(float);
    void set_y(float);
    void set_xy(float, float);
    Position get_diff(Position);
    // this last one allows us to use operators (-, +, *, <<, etc)
    // too change or return new values
    // eg pos1 - pos2 = diff_between_posses
    Position operator -(Position);
};

/* 
 * if I make a new Position without providing arguments
 * default values to zero
 * This is called a constructor. You will see how to use it later.
 */
Position::Position(){
  x = 0;
  y = 0;
}

/* if I want to set the values right off the bat by passing them in, do so
 * This is a second constructor.
 *
 * Anytime you have two functions/methods named the same but with different arguments, it is called "overloading".
 * So this is an overlaoded constructor.
 */
Position::Position(float new_x, float new_y){
  x = new_x;
  y = new_y;
}

// set the x value
void Position::set_x(float new_x){
  x = new_x;
}
// set the y value
void Position::set_y(float new_y){
  y = new_y;
}
// set both values, use alreday created functions to do so
void Position::set_xy(float new_x, float new_y){
  set_x(new_x);
  set_y(new_y);
}

float Position::get_x(){
  return x;
}
float Position::get_y(){
  return y;
}

// generate a new position based on the difference between the two
Position Position::get_diff(Position pos2){
  Position diff(std::abs(x - pos2.get_x()),
                std::abs(y - pos2.get_y()));
  return diff;
}
// generate a new position, etc.
// but do it with pos1 - pos2
// using the minus sign on an object of this type will now run this method.
Position Position::operator -(Position pos2){
  return get_diff(pos2);
}

// same as structs.cpp, but using the get_ methods instead of referencing directly
void print_pos(Position pos){
  std::cout << pos.get_x() << ", " << pos.get_y() << std::endl;
}


/*
 * Important note.
 * Classes are the template; the function prototypes, the implementions, etc.
 * Objects are one "instance" of the class, which contains its own values.
 * So the Position is the class. playerpos, enemypos1, enemypos2 are objects, or more formally "instatiations of the class" (nobody calls it that).
 *
 * If more explaination needed, let me know.
 */
int main(void){
  Position playerpos;
  print_pos(playerpos);

  std::cout << "Player pos: ";
  // use the set_ methods to set variables inside the object.
  playerpos.set_x(22.2);
  print_pos(playerpos);

  std::cout << "Player pos: ";
  playerpos.set_y(420.69);
  print_pos(playerpos);

  // to use the constructor from ealier, simply use paranthasies after the name of the object.
  Position enemypos1(77, 88);
  Position enemypos2(77, 88);
  enemypos1.set_xy(15, 25);
  std::cout << "Player pos: ";
  print_pos(playerpos);
  std::cout << "Enemy pos: ";
  print_pos(enemypos1);
  std::cout << "Enemy pos2: ";
  print_pos(enemypos2);

  // You can also print the values manually
  std::cout << "Manual enemypos 2: ";
  std::cout << enemypos2.get_x() << ", " << enemypos2.get_y() << std::endl;

  std::cout << "Difference btween two pos: ";
  Position diff = playerpos.get_diff(enemypos1);
  print_pos(diff);

  // this is how you can use the operators I showed you.
  // It can be done with any of the operators :O
  std::cout << "Difference between player and enemy one, using operators: ";
  Position diff2 = playerpos - enemypos1;
  print_pos(diff2);
  // you will notice the values of diff and diff2 are the same.

  return 0;
}
