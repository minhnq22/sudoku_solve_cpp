#include <iostream>
#include <fstream>
using namespace std;
void read_matrix(short matrix[][9]) {
	fstream file_data;
	file_data.open("sudoku.txt");
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) file_data >> matrix[i][j];
	file_data.close();
}
void show_matrix(short matrix[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cout << matrix[i][j] << " ";
		cout << "\n";
	}
	cout << "-----------------\n";
}
bool check(short matrix[][9], short x, short y, short k) {
	for (int i = 0; i < 9; i++)
		if (k == matrix[y][i] || k == matrix[i][x]) return false;
	short x1 = (x / 3) * 3, x2 = x1 + 3;
	short y1 = (y / 3) * 3, y2 = y1 + 3;
	for (short i = y1; i < y2; i++)
		for (short j = x1; j < x2; j++)
			if (k == matrix[i][j]) return false;
	return true;
}
bool choose(short matrix[][9]) {
	for (short i = 0; i < 9; i++)
		for (short j = 0; j < 9; j++)
			if (!matrix[i][j]) { // tìm số 0
				short number = 1;
				while (number <= 9) { //vòng lặp này để thử các giá trị từ 1 đến 9 vào vị trí tìm được
					if (check(matrix, j, i, number)) { //thỏa mãn hàm check thì gán giá trị vào
						matrix[i][j] = number;
						if (choose(matrix)) return true; //lặp lại hàm choose với số 0 tìm được tiếp theo
					}
					number++;
				} //thoát khỏi vòng lặp khi number > 9, trả lại giá trị 0 cho vị trí đang xét và return false do không thỏa mãn
				matrix[i][j] = 0;
				return false;
			}
}
int main() {
	short matrix[9][9];
	read_matrix(matrix);
	show_matrix(matrix);
	(choose(matrix))? cout << "DONE!\n" : cout << "FALSE!\n";
	show_matrix(matrix);
}