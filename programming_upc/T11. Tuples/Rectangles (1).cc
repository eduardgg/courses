#include <iostream>
 
using namespace std;

struct Rectangle {
	int x_left, x_right, y_down, y_up;
};

void read(Rectangle& r){
	cin >> r.x_left >> r.x_right >> r.y_down >> r.y_up;
}

int relationship(const Rectangle& r1, const Rectangle& r2){
	if (r1.x_left == r2.x_left and r1.x_right == r2.x_right and r1.y_down == r2.y_down and r1.y_up == r2.y_up) return 4;
	if (r1.x_left <= r2.x_left and r1.x_right >= r2.x_right and r1.y_down <= r2.y_down and r1.y_up >= r2.y_up) return 2;
	if (r1.x_left >= r2.x_left and r1.x_right <= r2.x_right and r1.y_down >= r2.y_down and r1.y_up <= r2.y_up) return 1;
	if (r1.x_left <= r2.x_right and r2.x_left <= r1.x_right and r1.y_down <= r2.y_up and r2.y_down <= r1.y_up) return 3;
	return 0;
}

int main(){
	int pene, poya;
	cin >> pene;
	Rectangle vagina, chocho;
	while (pene > 0){
		read (vagina);
		read (chocho);
		poya = relationship (vagina, chocho);
		if (poya == 0) cout << "rectangles do not intersect\n";
		if (poya == 1) cout << "the first rectangle is inside the second one\n";
		if (poya == 2) cout << "the second rectangle is inside the first one\n";
		if (poya == 3) cout << "rectangles intersect\n";
		if (poya == 4) cout << "rectangles are identical\n";
		pene --;
	}
}
