#pragma once

#include "public.h"

#ifdef __cplusplus
extern "C" {
#endif

	/*
	@brief: �ж������ܲ��ܺ��ƣ�����3+3+3+3+2����ƣ�����������(����)��
	@param aucHandCards[in]: 14�����ƣ�uint8_t���������顣
	@return bool: 
		true: ���Ժ��ơ�
		false: �����Ժ��ơ�
	*/
	bool bHu(Card aucHandCards[MAX_HANDCARD_NUM]);


#ifdef __cplusplus
}
#endif

/*
����˼·��

��ַ�(�������ӣ�

1���ռ�����������������Ϊ����A���Ż��ֶΣ��ƶ�Ϊ3*n+2���Ʋ��ܲ�������

2������ÿ�����������ƣ��۳����ж�ʣ�����Ƿ��ܺ�

�жϷ���������ÿ�ֻ�ɫ����1��9�����¹�����
a���������������Ϊ0��continue
b������Ϊ1���ж��Է�۳�һ���ƣ�������һ��2���ж��Ƿ������2��3��4��������ܣ���֤��ѡ������齫���ܺ��ƣ�break
c������Ϊ2���ж��Ƿ��ܿ۳������ƣ�������2��6���ж��Ƿ���7���������������������ܣ���֤��ѡ������齫���ܺ��� break
d������Ϊ3��ֱ�ӿ۳�һ������
e������Ϊ4���۳�һ�����Ӻ��ж��Ƿ������һ���ƣ�
����4��5���ȿ۳�3��5��
Ȼ���ж��Ƿ���5��6���һ�ţ�����У�
���������������4��5��6���������ƣ�
������ܣ���֤��ѡ������齫���ܺ��� break

ʾ����

1112345678999�����������ͣ��ж��Ƿ��ܺ�5��
1����5���������, 11123455678999
2��ѡ��: 1��5��9��(���ڵ���2�ŵ��Ʋ���������

3��ѡ��1������,ʣ�� 123455678999
a��123455678999, �ײ���1��1�򣬿۳�123��ʣ��455678999
b��455678999���ײ���1��4�򣬿۳�456��ʣ��578999
c��578999���ײ���1��5���޷��۳�567��break

4��ѡ��5��������ʣ��111234678999
a��111234678999���ײ���3��1��ֱ�ӿ۳���ʣ��234678999
b��234678999���ײ���1��2�򣬿۳�234��ʣ��678999
c��678999���ײ���1��6�򣬿۳�678��ʣ��999
d��999, �ײ���3��9��ֱ�ӿ۳����������ܲ��꣬����
*/