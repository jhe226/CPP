#include<iostream>

// 부분적 디폴트 값 설정
// 매개변수의 일부에만 디폴트 값을 지정하고
// 채워지지 않은 매개변수에만 인자를 전달하는 것이 가능하다

// 전달되는 인자가 왼쪽에서부터 채워지므로, 디폴트 값은 오른쪽에서부터 채워져야 한다. (혼합 사용 X)

int BoxVolume(int length, int width = 1, int height = 1);

int main()
{
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, 0] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, 0, 0] : " << BoxVolume(7) << std::endl;

	// 에러 -> int length는 디폴트 값이 없다.
	// std::cout << "[0, 0, 0]" << BoxVolume() << std::endl;

	return 0;

}

int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}