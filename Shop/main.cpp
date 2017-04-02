#include "BL\BL.h"
#include "../Shop/Utils/MenuClothes.h"

int main()
{
	createNewUser();
	MenuClothes menuClothes;
	menuClothes.clothesMenu();
	system("pause");
	return 0;
}