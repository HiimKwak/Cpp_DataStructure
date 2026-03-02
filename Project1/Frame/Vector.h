#pragma once

template<typename T>
class Vector
{
public:
	Vector();
	~Vector();

	// 생성 후에 필요한 메시지: 아이템 추가&삭제
	void Add(const T& item);
	void Delete(const T& item);

private:
	// 메시지 공통 메소드: 사이즈와 한계 비교 후 동적으로 용량 늘리거나 줄여주기. 최소한의 공통부분만 추출

private:
	// 필요한 것: 벡터의 현재 사이즈, 한계(캐퍼시티), 포인터(=실제 저장공간)
	int size, capacity;
	Vector* ptr = nullptr;
};

