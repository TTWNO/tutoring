#include <iostream>
#include <cmath>

struct position {
  float x = 0;
  float y = 0;
};
/* You do not *need* to initialize the values x and y,
 * but if you don't, you can expect to find memory garbage in them.*/

/* using the reference (&) opoerator to automaticall use a pointer
 * wihtout needing to remember to pass the memory location manutally
 */
void print_pos(struct position& pos){
  std::cout << pos.x << ", " << pos.y << std::endl;
}

int main(void){
  position playerpos;
  print_pos(playerpos);

  std::cout << "Player pos: ";
  playerpos.x = 22.2;
  print_pos(playerpos);

  std::cout << "Player pos: ";
  playerpos.y = 420.69;
  print_pos(playerpos);


  position enemypos1, enemypos2 = {77, 88};
  enemypos1 = {15, 26};
  std::cout << "Player pos: ";
  print_pos(playerpos);
  std::cout << "Enemy pos: ";
  print_pos(enemypos1);
  std::cout << "Enemy pos2: ";
  print_pos(enemypos2);

  // You can also print the values manually
  std::cout << "Manual enemypos 2: ";
  std::cout << enemypos2.x << ", " << enemypos2.y << std::endl;

  std::cout << "Difference btween two pos: ";
  position diff = {std::abs(playerpos.x - enemypos1.x),
                    std::abs(playerpos.y - enemypos1.y)};
  print_pos(diff);
  return 0;
}
