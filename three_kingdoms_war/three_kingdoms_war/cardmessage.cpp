#include "cardmessage.h"
#include "allcardheader.h"
#include "player.h"
chopEffectClass::chopEffectClass():chop(NULL),Qinggang(false),Cixiong(false),Fangtian(false),Zhangba(false),from(NULL),to(NULL)
{
}
Classtype chopEffectClass::getClasstype()
{
	return chopEffectClassCL;
}
TrickEffectClass::TrickEffectClass():card(NULL),from(NULL),to(NULL)
{
}
Classtype TrickEffectClass::getClasstype()
{
	return trickEffectClassCL;
}
JudgeResult::JudgeResult()
{
	suit=nosuit;
	num=0;
}
CardUseClass::CardUseClass():card(NULL),from(NULL),to(NULL)
{
}
Classtype CardUseClass::getClasstype()
{
	return cardUseClassCL;
}
DamageClass::DamageClass():from(NULL),to(NULL),card(NULL),damage(1)
{
}
DyingClass::DyingClass():who(NULL)
{
}
RecoverClass::RecoverClass():recover(1),who(NULL)
{
}