// Fill out your copyright notice in the Description page of Project Settings.


#include "TFT_StoreUI.h"

#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"

#include "TFT_Player.h"
#include "TFT_InvenComponent.h"
#include "TFT_Item.h"


bool UTFT_StoreUI::Initialize()
{
	bool abc = Super::Initialize();

	auto array = Store_UniformGrid->GetAllChildren();
	int32 slotIndex = 0;

	for (auto slot : array)
	{
		auto btn = Cast<UButton>(slot);
		if (btn)
		{
			_slotBtns.Add(btn);


			switch (slotIndex)
			{
			case 0:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView0);
				break;
			}
			case 1:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView1);
				break;
			}
			case 2:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView2);
				break;
			}
			case 3:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView3);
				break;
			}
			case 4:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView4);
				break;
			}
			case 5:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView5);
				break;
			}
			case 6:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView6);
				break;
			}
			case 7:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView7);
				break;
			}
			case 8:
			{
				btn->OnClicked.AddDynamic(this, &UTFT_StoreUI::SetToDetailView8);
				break;
			}
			default:
				break;
			}
		}
		slotIndex++;
	}

	Exit_Button->OnClicked.AddDynamic(this, &UTFT_StoreUI::StoreOpenClose);

	Purchase_Button->OnClicked.AddDynamic(this, &UTFT_StoreUI::PurchaseItem);

	_Storesaveiteminfo.SetNum(9);

	_emptySlot = LoadObject<UTexture2D>
		(nullptr, TEXT("/Script/Engine.Texture2D'/Game/ParagonSparrow/Characters/Global/MaterialLayers/Fabric/T_ML_Fabric_Shiny_Gray.T_ML_Fabric_Shiny_Gray'"));


	SetVisibility(ESlateVisibility::Collapsed);

	SetToDetailView8();

	return abc;
}

void UTFT_StoreUI::StoreOpenClose()
{
	if (bIsOpen == true)
	{
		UE_LOG(LogTemp, Log, TEXT("Store Close!!"));
		SetVisibility(ESlateVisibility::Collapsed);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
		bIsOpen = false;
		return;
	}
	else if(bIsOpen == false)
	{
		UE_LOG(LogTemp, Log, TEXT("Store Open!!"));
		SetVisibility(ESlateVisibility::Visible);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		bIsOpen = true;
		return;
	}
}

void UTFT_StoreUI::PurchaseItem()
{
	//_purchaseDelegateOneParam.Broadcast(_itemSlot);

	if (this_Index == -1)
	{
		UE_LOG(LogTemp, Log, TEXT("Your Not Choice Item"));
		return;
	}
	else
	{
		_ItemBuy.Broadcast(_this_Item, this_Index);

	}
}

void UTFT_StoreUI::SelectSlotStoreItem(int32 index)
{
	if (_Storesaveiteminfo[index] != nullptr)
	{
		_this_Item = _Storesaveiteminfo[index];
		this_Index = index;
		UISetItemName(index);
		UISetItemMiniInfo(index);
		UISetItemPrice(index);
		DetailViewImg->SetBrushFromTexture(_this_Item->GetMyTexture());
	}
	else
	{
		DetailViewImg->SetBrushFromTexture(_emptySlot);
		Item_Information->SetText(_nullText);
		Item_miniInfo->SetText(_nullText);
		Item_Price->SetText(_nullText);
		_this_Item = nullptr;
		this_Index = -1;
	}
}

void UTFT_StoreUI::SetItemSlot(UTexture2D* texture, int32 slotIndex)
{
	_slotBtns[slotIndex]->WidgetStyle.Normal.SetResourceObject(texture);
}

void UTFT_StoreUI::SetStoreItem(ATFT_Item* items, int32 index)
{
	_Storesaveiteminfo[index] = items;

	SetItemSlot(items->GetMyTexture(), index);
}

void UTFT_StoreUI::SetToDetailView0()
{
	/*UObject* image = _slotBtns[0]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Red Gem. Increase Attack Damage 50p.");
	FText price = FText::FromString("1,000");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(0);
}

void UTFT_StoreUI::SetToDetailView1()
{
	/*UObject* image = _slotBtns[1]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Blue Gem. Increase Max Mana 100p.");
	FText price = FText::FromString("1,000");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(1);
}

void UTFT_StoreUI::SetToDetailView2()
{
	/*UObject* image = _slotBtns[2]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Emerald Gem. Increase M/Health 100p & M/M 100p.");
	FText price = FText::FromString("2,000");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(2);
}

void UTFT_StoreUI::SetToDetailView3()
{
	/*UObject* image = _slotBtns[3]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Purple Potion. Get 1,000 EXP.");
	FText price = FText::FromString("2,500");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(3);
}

void UTFT_StoreUI::SetToDetailView4()
{
	/*UObject* image = _slotBtns[4]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("100 years old Wild Ginseng. Increase M/H 5,000p.");
	FText price = FText::FromString("80,000");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(4);
}

void UTFT_StoreUI::SetToDetailView5()
{
	/*UObject* image = _slotBtns[5]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Green Soup. Decrease M/H 1,000p & Increase A/D 300p");
	FText price = FText::FromString("3,000");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(5);
}

void UTFT_StoreUI::SetToDetailView6()
{
	//UObject* image = _slotBtns[6]->WidgetStyle.Normal.GetResourceObject();
	//FText text = FText::FromString("Shield. Save your life once. Knight only.");
	//FText price = FText::FromString("30,000");

	//DetailViewImg->SetBrushResourceObject(image);
	//Item_Information->SetText(text);
	//Item_Price->SetText(price);
	//_itemSlot = 0;

	SelectSlotStoreItem(6);
}

void UTFT_StoreUI::SetToDetailView7()
{
	/*UObject* image = _slotBtns[7]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Arrow Head. Increase Attack Damage 20p. Archer only.");
	FText price = FText::FromString("300");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(7);
}

void UTFT_StoreUI::SetToDetailView8()
{
	/*UObject* image = _slotBtns[8]->WidgetStyle.Normal.GetResourceObject();
	FText text = FText::FromString("Close...");
	FText price = FText::FromString("-");

	DetailViewImg->SetBrushResourceObject(image);
	Item_Information->SetText(text);
	Item_Price->SetText(price);
	_itemSlot = 0;*/

	SelectSlotStoreItem(8);
}

void UTFT_StoreUI::UISetItemName(int32 index)
{
	FString ItemString = FString::Printf(TEXT("%s"), *_Storesaveiteminfo[index]->GetItemName());
	FText ItemName = FText::FromString(ItemString);

	Item_Information->SetText(ItemName);
}

void UTFT_StoreUI::UISetItemMiniInfo(int32 index)
{
	FString ItemMiniString = FString::Printf(TEXT("%s"), *_Storesaveiteminfo[index]->GetItemMiniInfo());
	FText ItemMiniInfo = FText::FromString(ItemMiniString);

	Item_miniInfo->SetText(ItemMiniInfo);
}

void UTFT_StoreUI::UISetItemPrice(int32 index)
{
	FString itemPriceString = FString::Printf(TEXT("Price : %d Gold"), _Storesaveiteminfo[index]->GetItemGold());
	FText itemPrice = FText::FromString(itemPriceString);

	Item_Price->SetText(itemPrice);
}

