#include<iostream>

// �κ��� ����Ʈ �� ����
// �Ű������� �Ϻο��� ����Ʈ ���� �����ϰ�
// ä������ ���� �Ű��������� ���ڸ� �����ϴ� ���� �����ϴ�

// ���޵Ǵ� ���ڰ� ���ʿ������� ä�����Ƿ�, ����Ʈ ���� �����ʿ������� ä������ �Ѵ�. (ȥ�� ��� X)

int BoxVolume(int length, int width = 1, int height = 1);

int main()
{
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, 0] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, 0, 0] : " << BoxVolume(7) << std::endl;

	// ���� -> int length�� ����Ʈ ���� ����.
	// std::cout << "[0, 0, 0]" << BoxVolume() << std::endl;

	return 0;

}

int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}