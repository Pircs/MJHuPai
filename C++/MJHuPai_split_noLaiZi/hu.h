#pragma once

#include "public.h"

#ifdef __cplusplus
extern "C" {
#endif

	/*
	@brief: 判断手牌能不能胡牌，符合3+3+3+3+2则胡牌，不包含赖子(鬼牌)。
	@param aucHandCards[in]: 14张手牌，uint8_t类型在数组。
	@return bool: 
		true: 可以胡牌。
		false: 不可以胡牌。
	*/
	bool bHu(Card aucHandCards[MAX_HANDCARD_NUM]);


#ifdef __cplusplus
}
#endif

/*
具体思路：

拆分法(不带赖子）

1、收集能做将的所有牌作为集合A（优化手段，牌堆为3*n+2的牌才能产生将）

2、遍历每种能做将的牌，扣除后，判断剩余牌是否能胡

判断方法：遍历每种花色，从1到9按以下规则处理
a、如果遇到牌张数为0，continue
b、张数为1，判断以否扣除一坎牌，比如有一个2万，判断是否能组成2，3，4万，如果不能，则证明选择的这组将不能胡牌，break
c、张数为2，判断是否能扣除二坎牌，比如有2个6万，判断是否有7个七万和两个八万，如果不能，则证明选择的这组将不能胡牌 break
d、张数为3，直接扣除一个刻子
e、张数为4，扣除一个刻子后，判断是否能组成一坎牌，
比如4个5万，先扣除3个5万，
然后判断是否有5，6万各一张，如果有，
则能组成三个四万，4，5，6万这两组牌，
如果不能，则证明选择的这组将不能胡牌 break

示例：

1112345678999九莲宝灯牌型，判断是否能胡5万
1、将5万加入牌中, 11123455678999
2、选择将: 1万，5万，9万(大于等于2张的牌才能做将）

3、选择1万做将,剩余 123455678999
a、123455678999, 首部是1张1万，扣除123万，剩余455678999
b、455678999，首部是1张4万，扣除456万，剩余578999
c、578999，首部是1张5万，无法扣除567万，break

4、选择5万做将，剩余111234678999
a、111234678999，首部是3张1万，直接扣除，剩余234678999
b、234678999，首部是1张2万，扣除234，剩余678999
c、678999，首部是1张6万，扣除678，剩余999
d、999, 首部是3张9万，直接扣除，所有牌能拆完，胡牌
*/
